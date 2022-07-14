import enum
import importlib
from typing import Any
from common_api import CommonAPI, StatusCode
from utils import bytes_to_megabytes
# Library is called pynvml!
class nvmlBrandType_t(enum.IntEnum):
    NVML_BRAND_UNKNOWN = 0
    NVML_BRAND_QUADRO = 1
    NVML_BRAND_TESLA = 2
    NVML_BRAND_NVS = 3
    NVML_BRAND_GRID = 4
    NVML_BRAND_GEFORCE = 5
    NVML_BRAND_TITAN = 6
    NVML_BRAND_NVIDIA_VAPPS = 7
    NVML_BRAND_NVIDIA_VPC = 8
    NVML_BRAND_NVIDIA_VCS = 9
    NVML_BRAND_NVIDIA_VWS = 10
    NVML_BRAND_NVIDIA_CLOUD_GAMING = 11
    NVML_BRAND_NVIDIA_VGAMING = NVML_BRAND_NVIDIA_CLOUD_GAMING
    NVML_BRAND_QUADRO_RTX = 12
    NVML_BRAND_NVIDIA_RTX = 13
    NVML_BRAND_NVIDIA = 14
    NVML_BRAND_GEFORCE_RTX = 15
    NVML_BRAND_TITAN_RTX = 16
    NVML_BRAND_COUNT = enum.auto()

class nvmlClockType_t(enum.IntEnum):
    NVML_CLOCK_GRAPHICS = 0
    NVML_CLOCK_SM = 1
    NVML_CLOCK_MEM = 2
    NVML_CLOCK_VIDEO = 3
    NVML_CLOCK_COUNT = enum.auto()

class nvmlClockId_t(enum.IntEnum):
    NVML_CLOCK_ID_CURRENT = 0
    NVML_CLOCK_ID_APP_CLOCK_TARGET = 1
    NVML_CLOCK_ID_APP_CLOCK_DEFAULT = 2
    NVML_CLOCK_ID_CUSTOMER_BOOST_MAX = 3
    NVML_CLOCK_ID_COUNT = enum.auto()

class nvmlInforomObject_t(enum.IntEnum):
    NVML_INFOROM_OEM = 0
    NVML_INFOROM_ECC = 1
    NVML_INFOROM_POWER = 2
    NVML_INFOROM_COUNT = enum.auto()

class nvmlDeviceArchitecture_t(enum.IntEnum):
    NVML_DEVICE_ARCH_KEPLER   = 2
    NVML_DEVICE_ARCH_MAXWELL  = 3
    NVML_DEVICE_ARCH_PASCAL   = 4
    NVML_DEVICE_ARCH_VOLTA    = 5
    NVML_DEVICE_ARCH_TURING   = 6
    NVML_DEVICE_ARCH_AMPERE   = 7
    NVML_DEVICE_ARCH_UNKNOWN  = 0xffffffff

class nvmlPcieLinkMaxSpeed_t(enum.IntEnum):
    NVML_PCIE_LINK_MAX_SPEED_INVALID   = 0x00000000
    NVML_PCIE_LINK_MAX_SPEED_2500MBPS  = 0x00000001
    NVML_PCIE_LINK_MAX_SPEED_5000MBPS  = 0x00000002
    NVML_PCIE_LINK_MAX_SPEED_8000MBPS  = 0x00000003
    NVML_PCIE_LINK_MAX_SPEED_16000MBPS = 0x00000004
    NVML_PCIE_LINK_MAX_SPEED_32000MBPS = 0x00000005

class WindowsLinux_NVIDIA_API(CommonAPI):
    error_dict = None
    pynvml_lib = None
    def __init__(self) -> None:
        self.pynvml_lib = importlib.import_module("pynvml")
        self.error_dict = self.pynvml_lib.NVMLError._errcode_to_string
    def initialize(self) -> None:
        self.pynvml_lib.nvmlInit()

    def finish(self) -> None:
        self.pynvml_lib.nvmlShutdown()

    def get_number_of_devices(self) -> int:
        num_devices = self.pynvml_lib.nvmlDeviceGetCount()
        return num_devices
    
    def get_device_handle_by_index(self, index) -> Any:
        handle = self.pynvml_lib.nvmlDeviceGetHandleByIndex(index)
        return handle
   
    def get_device_name_by_handle(self, handle) -> Any:
        try:
            result = self.pynvml_lib.nvmlDeviceGetName(handle)
            return result.decode('ASCII')
        except self.pynvml_lib.NVMLError as e:
            error_code = e.args[0]
            if error_code == self.pynvml_lib.NVML_ERROR_NOT_SUPPORTED:
                return e
            else:
                raise self.pynvml_lib.NVMLError(e)
    
    def get_device_temperature_info(self, handle) -> Any:
        try:
            temp_readings_count = self.pynvml_lib.NVML_TEMPERATURE_COUNT
            temp_thresholds_count = self.pynvml_lib.NVML_TEMPERATURE_THRESHOLD_COUNT
            temp_readings = []
            temp_thresholds = []

            for i in range(0,temp_readings_count):
                try:
                    reading = self.pynvml_lib.nvmlDeviceGetTemperature(handle, i)
                    temp_readings.append(reading)
                except self.pynvml_lib.NVMLError as e:
                    error_code = e.args[0]
                    if error_code in (self.pynvml_lib.NVML_ERROR_NOT_SUPPORTED, self.pynvml_lib.NVML_ERROR_INVALID_ARGUMENT):
                        temp_readings.append("Not supported")
                        continue
            
            for j in range(0, temp_thresholds_count):
                try:
                    threshold = self.pynvml_lib.nvmlDeviceGetTemperatureThreshold(handle, j)
                    temp_thresholds.append(threshold)
                except self.pynvml_lib.NVMLError as e:
                    error_code = e.args[0]
                    if error_code in (self.pynvml_lib.NVML_ERROR_NOT_SUPPORTED, self.pynvml_lib.NVML_ERROR_INVALID_ARGUMENT):
                        temp_thresholds.append("Not supported")
                        continue

            return {
                "temp_readings_sensor_types": ["GPU"],
                "temp_readings_values": temp_readings,
                "temp_thresholds_types": ["Shutdown", "Slowdown", "Mem Max", "GPU Max", "Acoustic Min", "Acoustic Curr", "Acoustic Max"],
                "temp_thresholds_values": temp_thresholds
            }
        except self.pynvml_lib.NVMLError as e:
            error_code = e.args[0]
            if error_code == self.pynvml_lib.NVML_ERROR_NOT_SUPPORTED:
                return e
            else:
                raise self.pynvml_lib.NVMLError(e)
        
    def get_device_clocks_info(self, handle) -> Any:
        try:
            #Unsupported functions throw NOT SUPPORTED exception, they don't return error code!
            try:
                adaptive_clock_info_status = self.pynvml_lib.nvmlDeviceGetAdaptiveClockInfoStatus(handle)
                if adaptive_clock_info_status == 0:
                    adaptive_clock_info_status = "DISABLED"
                elif adaptive_clock_info_status == 1:
                    adaptive_clock_info_status = "ENABLED"
                else:
                    adaptive_clock_info_status = "UNKNOWN"
            except Exception as e:
                adaptive_clock_info_status = "Not supported"

            application_clocks = list()
            for clock_type in range(0, nvmlClockType_t.NVML_CLOCK_COUNT.value):
                try:
                    application_clock_mhz = self.pynvml_lib.nvmlDeviceGetApplicationsClock(handle, clock_type)
                    application_clocks.append({
                        nvmlClockType_t(clock_type).name.replace("NVML_CLOCK_", ""): application_clock_mhz
                        })
                except Exception as e:
                    application_clock_mhz = "Not supported"
                    application_clocks.append({
                        nvmlClockType_t(clock_type).name.replace("NVML_CLOCK_", ""): application_clock_mhz
                        })

            auto_boosted_clocks = {
                "is_enabled": None,
                "default_is_enabled": None
            }
            try:
                (isEnabled, defaultIsEnabled) = self.pynvml_lib.nvmlDeviceGetAutoBoostedClocksEnabled(handle)
            except Exception as e:
                (isEnabled, defaultIsEnabled) = ("Not supported", "Not supported")
            auto_boosted_clocks["is_enabled"] = "ENABLED" if isEnabled == 1 else "DISABLED"
            auto_boosted_clocks["default_is_enabled"] = "ENABLED" if defaultIsEnabled == 1 else "DISABLED"
            
            clocks_mhz = dict()
            for clock_type in range(0, nvmlClockType_t.NVML_CLOCK_COUNT.value):
                clocks_mhz[nvmlClockType_t(clock_type).name.replace("NVML_CLOCK_", "")] = list()
                for clock_id in range(0, nvmlClockId_t.NVML_CLOCK_ID_COUNT.value):
                    try:
                        clock_mhz = self.pynvml_lib.nvmlDeviceGetClock(handle, clock_type, clock_id)
                        clocks_mhz[nvmlClockType_t(clock_type).name.replace("NVML_CLOCK_", "")].append({
                                nvmlClockId_t(clock_id).name.replace("NVML_CLOCK_ID_", ""): clock_mhz
                        })
                    except Exception as e:
                        clock_mhz = "Not supported"
                        clocks_mhz[nvmlClockType_t(clock_type).name.replace("NVML_CLOCK_", "")].append({
                                nvmlClockId_t(clock_id).name.replace("NVML_CLOCK_ID_", ""): clock_mhz
                        })

            clocks_info = list()
            for clock_type in range(0, nvmlClockType_t.NVML_CLOCK_COUNT.value):
                try:
                    clock_info = self.pynvml_lib.nvmlDeviceGetClockInfo(handle, clock_type)
                    clocks_info.append({
                        nvmlClockType_t(clock_type).name.replace("NVML_CLOCK_", ""): clock_info
                    })
                except Exception as e:
                    clock_info = "Not supported"
                    clocks_info.append({
                        nvmlClockType_t(clock_type).name.replace("NVML_CLOCK_", ""): clock_info
                    })

            try:
                current_clocks_throttle_reasons = self.pynvml_lib.nvmlDeviceGetCurrentClocksThrottleReasons(handle)
                throttle_reasons_bitmasks = {
                    "GPU Idle": self.pynvml_lib.nvmlClocksThrottleReasonGpuIdle,
                    "Applications Clocks Setting": self.pynvml_lib.nvmlClocksThrottleReasonApplicationsClocksSetting, 
                    "Sw Power Cap": self.pynvml_lib.nvmlClocksThrottleReasonSwPowerCap,
                    "Hw Slowdown": self.pynvml_lib.nvmlClocksThrottleReasonHwSlowdown,
                    "Sync Boost": self.pynvml_lib.nvmlClocksThrottleReasonSyncBoost,
                    "Sw Thermal Slowdown": self.pynvml_lib.nvmlClocksThrottleReasonSwThermalSlowdown,
                    "Hw Thermal Slowdown": self.pynvml_lib.nvmlClocksThrottleReasonHwThermalSlowdown,
                    "Hw Power Brake Slowdown": self.pynvml_lib.nvmlClocksThrottleReasonHwPowerBrakeSlowdown,
                    "Display Clock Setting": self.pynvml_lib.nvmlClocksThrottleReasonDisplayClockSetting,
                    "No throttling": self.pynvml_lib.nvmlClocksThrottleReasonNone,
                    "All throttling reasons": self.pynvml_lib.nvmlClocksThrottleReasonAll 
                }
                result_throttle_reasons = {
                    "Reasons": list()
                }
                if (current_clocks_throttle_reasons & throttle_reasons_bitmasks["All throttling reasons"]) > 0:
                    found_throttle_reason = False
                    
                    for key in throttle_reasons_bitmasks.keys():
                        if key == "All throttling reasons":
                            continue
                        if (current_clocks_throttle_reasons & throttle_reasons_bitmasks[key]) > 0:
                            found_throttle_reason = True
                            result_throttle_reasons["Reasons"].append(str(key))
                    if not found_throttle_reason:
                        result_throttle_reasons["Reasons"].append("Unknown")
                else:
                    result_throttle_reasons["Reasons"].append("No throttling")

            except Exception as e:
                result_throttle_reasons["Reasons"].append("Not supported")

            default_application_clocks = list()
            for clock_type in range(0, nvmlClockType_t.NVML_CLOCK_COUNT.value):
                try:
                    default_application_clock = self.pynvml_lib.nvmlDeviceGetDefaultApplicationsClock(handle, clock_type)
                    default_application_clocks.append(default_application_clock)
                except Exception as e:
                    default_application_clock = "Not supported"
                    default_application_clocks.append(default_application_clock)

            max_clocks_info = list()
            for clock_type in range(0, nvmlClockType_t.NVML_CLOCK_COUNT.value):
                try:
                    max_clock_info = self.pynvml_lib.nvmlDeviceGetMaxClockInfo(handle, clock_type)
                    max_clocks_info.append({
                        nvmlClockType_t(clock_type).name.replace("NVML_CLOCK_", ""): max_clock_info
                    })
                except Exception as e:
                    max_clock_info = "Not supported"
                    max_clocks_info.append({
                        nvmlClockType_t(clock_type).name.replace("NVML_CLOCK_", ""): max_clock_info
                    })
            
            max_customer_boost_clocks = list()
            for clock_type in range(0, nvmlClockType_t.NVML_CLOCK_COUNT.value):
                try:
                    max_customer_boost_clock = self.pynvml_lib.nvmlDeviceGetMaxCustomerBoostClock(handle, clock_type)
                    max_customer_boost_clocks.append({
                        nvmlClockType_t(clock_type).name.replace("NVML_CLOCK_", ""): max_customer_boost_clock
                    })
                except Exception as e:
                    max_customer_boost_clock = "Not supported"
                    max_customer_boost_clocks.append({
                        nvmlClockType_t(clock_type).name.replace("NVML_CLOCK_", ""): max_customer_boost_clock
                    })

            try:
                supported_clocks_throttle_reasons = self.pynvml_lib.nvmlDeviceGetSupportedClocksThrottleReasons(handle)
                throttle_reasons_bitmasks = {
                    "GPU Idle": self.pynvml_lib.nvmlClocksThrottleReasonGpuIdle,
                    "Applications Clocks Setting": self.pynvml_lib.nvmlClocksThrottleReasonApplicationsClocksSetting, 
                    "Sw Power Cap": self.pynvml_lib.nvmlClocksThrottleReasonSwPowerCap,
                    "Hw Slowdown": self.pynvml_lib.nvmlClocksThrottleReasonHwSlowdown,
                    "Sync Boost": self.pynvml_lib.nvmlClocksThrottleReasonSyncBoost,
                    "Sw Thermal Slowdown": self.pynvml_lib.nvmlClocksThrottleReasonSwThermalSlowdown,
                    "Hw Thermal Slowdown": self.pynvml_lib.nvmlClocksThrottleReasonHwThermalSlowdown,
                    "Hw Power Brake Slowdown": self.pynvml_lib.nvmlClocksThrottleReasonHwPowerBrakeSlowdown,
                    "Display Clock Setting": self.pynvml_lib.nvmlClocksThrottleReasonDisplayClockSetting,
                    "No throttling": self.pynvml_lib.nvmlClocksThrottleReasonNone,
                    "All throttling reasons": self.pynvml_lib.nvmlClocksThrottleReasonAll 
                }
                result_supported_throttle_reasons = list()
                if (supported_clocks_throttle_reasons & throttle_reasons_bitmasks["All throttling reasons"]) > 0:
                    found_throttle_reason = False
                    
                    for key in throttle_reasons_bitmasks.keys():
                        if key == "All throttling reasons":
                            continue
                        if (supported_clocks_throttle_reasons & throttle_reasons_bitmasks[key]) > 0:
                            found_throttle_reason = True
                            result_supported_throttle_reasons.append(str(key))
                    if not found_throttle_reason:
                        result_supported_throttle_reasons.append("Unknown")
                else:
                    result_supported_throttle_reasons.append("No throttling")
            except Exception as e:
                supported_clocks_throttle_reasons = "Not supported"
            
            supported_memory_clocks = None
            try:
                supported_memory_clocks = self.pynvml_lib.nvmlDeviceGetSupportedMemoryClocks(handle)
            except Exception as e:
                supported_memory_clocks = "Not supported"

            supported_graphics_clocks = None
            try:
                if (supported_memory_clocks is None) or (supported_memory_clocks == "Not supported"):
                    supported_graphics_clocks = "Not supported"
                else:
                    supported_graphics_clocks = dict()
                    for supported_memory_clock in supported_memory_clocks:
                        supported_graphics_clocks[str(supported_memory_clock)] = list()
                        supported_graphics_clocks_for_mem_clk = self.pynvml_lib.nvmlDeviceGetSupportedGraphicsClocks(handle, supported_memory_clock)
                        supported_graphics_clocks[str(supported_memory_clock)].append(supported_graphics_clocks_for_mem_clk)
            except Exception as e:
                supported_graphics_clocks = "Not supported"

            violation_statuses = dict()
            possible_violation_statuses = {
                "Power": self.pynvml_lib.NVML_PERF_POLICY_POWER,
                "Thermal": self.pynvml_lib.NVML_PERF_POLICY_THERMAL,
                "Sync boost": self.pynvml_lib.NVML_PERF_POLICY_SYNC_BOOST,
                "Board limit": self.pynvml_lib.NVML_PERF_POLICY_BOARD_LIMIT,
                "Low utilization": self.pynvml_lib.NVML_PERF_POLICY_LOW_UTILIZATION,
                "Reliability": self.pynvml_lib.NVML_PERF_POLICY_RELIABILITY,
                "App clocks": self.pynvml_lib.NVML_PERF_POLICY_TOTAL_APP_CLOCKS,
                "Base clocks": self.pynvml_lib.NVML_PERF_POLICY_TOTAL_BASE_CLOCKS
            }
            for policyType in possible_violation_statuses.keys():
                try:
                    violation_status = self.pynvml_lib.nvmlDeviceGetViolationStatus(handle, possible_violation_statuses[policyType])
                    violation_statuses[policyType] = {"Reference time": violation_status.referenceTime, "Violation time": violation_status.violationTime}
                except Exception as e:
                    violation_statuses[policyType] = "Not supported" 

            return {
                "Adaptive clocking status": adaptive_clock_info_status,
                "Application clocks (MHz)": application_clocks,
                "Current auto boost clocks status": auto_boosted_clocks["is_enabled"],
                "Default auto boost clocks status": auto_boosted_clocks["default_is_enabled"],
                "Clocks by type and id (MHz)": clocks_mhz,
                "Clocks by type (MHz)": clocks_info,
                "Current clocks throttle reasons": result_throttle_reasons,
                "Default application clocks": default_application_clock,
                "Max clock info (MHz)": max_clocks_info,
                "Max customer boost clock (MHz)": max_customer_boost_clocks,
                "Supported clocks throttle reasons": result_supported_throttle_reasons,
                "Supported memory clocks (Mhz)": supported_memory_clocks,
                "Supported pairs of memory and graphics clocks (Mem: Graphics) (MHz)": supported_graphics_clocks,
                "Violation status": violation_statuses
            }
        except self.pynvml_lib.NVMLError as e:
            error_code = e.args[0]
            if error_code == self.pynvml_lib.NVML_ERROR_NOT_SUPPORTED:
                return e
            else:
                raise self.pynvml_lib.NVMLError(e)

    def get_device_memory_info(self, handle) -> Any:
        try:
            try:
                bar1_memory_info = self.pynvml_lib.nvmlDeviceGetBAR1MemoryInfo(handle)
            except Exception as e:
                bar1_memory_info = "Not supported"
            
            try:
                memory_info = self.pynvml_lib.nvmlDeviceGetMemoryInfo(handle)
            except Exception as e:
                memory_info = "Not supported"
            
            try:
                inforom_checksum = self.pynvml_lib.nvmlDeviceGetInforomConfigurationChecksum(handle) 
            except Exception as e:
                inforom_checksum = "Not supported"
            
            return {
                "BAR1 Total Memory (MB)": bytes_to_megabytes(bar1_memory_info.bar1Total),
                "BAR1 Used Memory (MB)": bytes_to_megabytes(bar1_memory_info.bar1Used),
                "BAR1 Free Memory (MB)": bytes_to_megabytes(bar1_memory_info.bar1Free),
                "GPU Total Memory (MB)": bytes_to_megabytes(memory_info.total),
                "GPU Used Memory (MB)": bytes_to_megabytes(memory_info.used),
                "GPU Free Memory (MB)": bytes_to_megabytes(memory_info.free),
                "InfoROM Checksum": inforom_checksum,
            }
        except self.pynvml_lib.NVMLError as e:
            error_code = e.args[0]
            if error_code == self.pynvml_lib.NVML_ERROR_NOT_SUPPORTED:
                return e
            else:
                raise self.pynvml_lib.NVMLError(e)
    
    def get_device_bus_info(self, handle) -> Any:
        try:
            # MORA DA SE VIDI KAKO CE DA SE KAD BACI EXCEPTION
            # ZA NOT SUPPORTED DA URADI!!
            try:
                curr_pcie_link_gen = self.pynvml_lib.nvmlDeviceGetCurrPcieLinkGeneration(handle)
            except Exception as e:
                curr_pcie_link_gen = "Not supported"
            
            try:
                curr_pcie_link_width = self.pynvml_lib.nvmlDeviceGetCurrPcieLinkWidth(handle)
            except Exception as e:
                curr_pcie_link_width = "Not supported"
            
            try:
                max_pcie_link_gen = self.pynvml_lib.nvmlDeviceGetMaxPcieLinkGeneration(handle)
            except Exception as e:
                max_pcie_link_gen = "Not supported"

            try:
                max_pcie_link_width = self.pynvml_lib.nvmlDeviceGetMaxPcieLinkWidth(handle)
            except Exception as e:
                max_pcie_link_width = "Not supported"
               
            try:
                memory_bus_width = self.pynvml_lib.nvmlDeviceGetMemoryBusWidth(handle)
            except Exception as e:
                memory_bus_width = "Not supported"
              
            try:
                pci_info = self.pynvml_lib.nvmlDeviceGetPciInfo_v3(handle)
            except Exception as e:
                pci_info = "Not supported"

            try:
                pcie_link_max_speed = self.pynvml_lib.nvmlDeviceGetPcieLinkMaxSpeed(handle)
                pcie_link_max_speed = nvmlPcieLinkMaxSpeed_t(pcie_link_max_speed).name.replace("NVML_PCIE_LINK_MAX_SPEED_", "").replace("MBPS","")
            except Exception as e:
                pcie_link_max_speed = "Not supported"
                
            try:
                pcie_replay_counter = self.pynvml_lib.nvmlDeviceGetPcieReplayCounter(handle)
            except Exception as e:
                curr_pcie_link_width = "Not supported"

            result = {
                "Current PCIe Link Generation": curr_pcie_link_gen,
                "Current PCIe Link Width (Lanes)": curr_pcie_link_width,
                "Maximum PCIe Link Generation": max_pcie_link_gen,
                "Maximum PCIe Link Width (Lanes)": max_pcie_link_width,
                "Memory Bus Width (Bits)": memory_bus_width,
                "PCI Bus Id Legacy": pci_info.busIdLegacy.decode('ASCII'),
                "PCI Domain Number": "{0:#0{1}x}".format(pci_info.domain, 10),
                "PCI Bus Number": "{0:#0{1}x}".format(pci_info.bus, 4),
                "PCI Device Number": "{0:#0{1}x}".format(pci_info.device, 4),
                "PCI Device Id": "{0:#0{1}x}".format(pci_info.pciDeviceId, 10),
                "PCI Subsystem Id": "{0:#0{1}x}".format(pci_info.pciSubSystemId, 10),
                "PCI Bus Id": pci_info.busId.decode('ASCII'),
                "Maximum PCIe Link Speed (MB per second)": pcie_link_max_speed,
                "PCIe Replay Counter": pcie_replay_counter,
            }
            return result
        except self.pynvml_lib.NVMLError as e:
            error_code = e.args[0]
            if error_code == self.pynvml_lib.NVML_ERROR_NOT_SUPPORTED:
                return e
            else:
                raise self.pynvml_lib.NVMLError(e)

    def get_device_versions_info(self, handle) -> Any:
        try:
            cuda_driver_version = self.pynvml_lib.nvmlSystemGetCudaDriverVersion()
        except Exception as e:
            cuda_driver_version = "Not supported"

        try:
            cuda_driver_version_v2 = self.pynvml_lib.nvmlSystemGetCudaDriverVersion_v2()
        except Exception as e:
            cuda_driver_version_v2 = "Not supported"

        try:
            driver_version = self.pynvml_lib.nvmlSystemGetDriverVersion().decode('ASCII')
        except Exception as e:
            driver_version = "Not supported"

        try:
            nvml_version = self.pynvml_lib.nvmlSystemGetNVMLVersion().decode('ASCII')
        except Exception as e:
            nvml_version = "Not supported"

        try:
            driver_model = self.pynvml_lib.nvmlDeviceGetDriverModel(handle)
            if len(driver_model) > 0:
                current_driver_model = "WDDM" if driver_model[0] == 0 else "WDM"
            if len(driver_model) > 1:
                pending_driver_model = "WDDM" if driver_model[1] == 0 else "WDM"
        except Exception as e:
            driver_model = "Not supported"
            current_driver_model = pending_driver_model = driver_model

        try:
            inforom_image_version = self.pynvml_lib.nvmlDeviceGetInforomImageVersion(handle).decode('ASCII')
        except Exception as e:
            inforom_image_version = "Not supported"

        inforom_versions = list()
        for inforom_obj_type_dict_key, inforom_obj_dict_enum in nvmlInforomObject_t.__members__.items():
            if inforom_obj_type_dict_key == "NVML_INFOROM_COUNT":
                continue
            inforom_obj_type = inforom_obj_dict_enum
            try:
                inforom_version = self.pynvml_lib.nvmlDeviceGetInforomVersion(handle, inforom_obj_type).decode('ASCII')
                inforom_versions.append({
                    nvmlInforomObject_t(inforom_obj_type).name.replace("NVML_INFOROM_", ""): inforom_version
                })
            except Exception as e:
                inforom_version = "Not supported"
                inforom_versions.append({
                    nvmlInforomObject_t(inforom_obj_type).name.replace("NVML_INFOROM_", ""): inforom_version
                })

        try:
            vbios_version = self.pynvml_lib.nvmlDeviceGetVbiosVersion(handle).decode('ASCII')
        except Exception as e:
            vbios_version = "Not supported"

        return {
            "CUDA Driver Version": cuda_driver_version_v2,
            "Driver Version": driver_version,
            "NVML Version": nvml_version,
            "Current Driver Model": current_driver_model,
            "Pending Driver Model": pending_driver_model,
            "InfoROM Image Version": inforom_image_version,
            "InfoROM Version": inforom_versions,
            "VBIOS Version": vbios_version
        }
    
    def get_device_catalog_info(self, handle) -> Any:
        try:
            serial_number = self.pynvml_lib.nvmlDeviceGetSerial(handle)
        except self.pynvml_lib.NVMLError as e:
            serial_number = "Not supported"

        try:
            uuid = self.pynvml_lib.nvmlDeviceGetUUID(handle).decode('ASCII')
        except:
            uuid = "Not supported"

        try:
            board_id = self.pynvml_lib.nvmlDeviceGetBoardId(handle)
        except self.pynvml_lib.NVMLError as e:
            board_id = "Not supported"

        try:
            brand_name = nvmlBrandType_t(self.pynvml_lib.nvmlDeviceGetBrand(handle))
            if brand_name.value in (nvmlBrandType_t.NVML_BRAND_COUNT, nvmlBrandType_t.NVML_BRAND_UNKNOWN):
                brand_name = "Unknown"
            else:
                brand_name = str(brand_name.name).replace("NVML_BRAND_","").replace("_"," ")
        except self.pynvml_lib.NVMLError as e:
            brand_name = "Not supported"

        try:
            minor_number = self.pynvml_lib.nvmlDeviceGetMinorNumber(handle)
        except self.pynvml_lib.NVMLError as e:
            minor_number = "Not supported"
        try:
            num_of_gpu_cores = self.pynvml_lib.nvmlDeviceGetNumGpuCores(handle)
        except self.pynvml_lib.NVMLError as e:
            num_of_gpu_cores = "Not supported"  
        
        try:
            device_architecture = self.pynvml_lib.nvmlDeviceGetArchitecture(handle)
            device_architecture = nvmlDeviceArchitecture_t(device_architecture).name.replace("NVML_DEVICE_ARCH_", "")
        except self.pynvml_lib.NVMLError as e:
            device_architecture = "Not supported"
        
        try:
            device_attributes = self.pynvml_lib.nvmlDeviceGetAttributes_v2(handle)
        except self.pynvml_lib.NVMLError as e:
            device_attributes = "Not supported"
        
        return {
            "Serial Number": serial_number,
            "Universally Unique Identifier(UUID)": uuid,
            "Board ID": board_id,
            "Brand": brand_name,
            "Minor number": str(minor_number),
            "Shading units(GPU cores)": str(num_of_gpu_cores),
            "Architecture": str(device_architecture)
        }