import enum
import importlib
from typing import Any
from common_api import CommonAPI, StatusCode
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

class WindowsLinux_NVIDIA_API(CommonAPI):
    error_dict = None
    pynvml_lib = None
    def __init__(self) -> None:
        self.pynvml_lib = importlib.import_module("pynvml")
        self.error_dict = self.pynvml_lib.NVMLError._errcode_to_string
    def initialize(self) -> None:
        self.pynvml_lib.nvmlInit()

    def initialize_with_flags(self, flags: Any) -> None:
        # maybe process flags in some way
        flags_send = flags
        self.pynvml_lib.nvmlInitWithFlags(flags_send)

    def finish(self) -> None:
        self.pynvml_lib.nvmlShutdown()

    def get_number_of_devices(self) -> int:
        num_devices = self.pynvml_lib.nvmlDeviceGetCount()
        return num_devices

    def get_driver_version(self) -> str:
        driver_version = self.pynvml_lib.nvmlSystemGetDriverVersion()
        return driver_version.decode('ASCII')

    def get_library_version(self) -> str:
        lib_version = self.pynvml_lib.nvmlSystemGetNVMLVersion()
        return lib_version
    
    def get_device_handle_by_index(self, index) -> Any:
        handle = self.pynvml_lib.nvmlDeviceGetHandleByIndex(index)
        return handle

    def get_device_serial_by_handle(self, handle) -> Any:
        try:
            serial_number = self.pynvml_lib.nvmlDeviceGetSerial(handle)
            return serial_number
        except self.pynvml_lib.NVMLError as e:
            error_code = e.args[0]
            if error_code == self.pynvml_lib.NVML_ERROR_NOT_SUPPORTED:
                return e
            else:
                raise self.pynvml_lib.NVMLError(e)
    
    def get_device_uuid_by_handle(self, handle) -> Any:
        uuid = self.pynvml_lib.nvmlDeviceGetUUID(handle)
        return uuid.decode('ASCII')
    
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
        
    def get_device_power_info(self, handle) -> Any:
        return None
    
    def get_device_board_id(self, handle) -> Any:
        try:
            board_id = self.pynvml_lib.nvmlDeviceGetBoardId(handle)
            return board_id
        except self.pynvml_lib.NVMLError as e:
            error_code = e.args[0]
            if error_code == self.pynvml_lib.NVML_ERROR_NOT_SUPPORTED:
                return e
            else:
                raise self.pynvml_lib.NVMLError(e)

    def get_device_brand(self, handle) -> Any:
        try:
            brand_name = nvmlBrandType_t(self.pynvml_lib.nvmlDeviceGetBrand(handle))
            if brand_name.value in (nvmlBrandType_t.NVML_BRAND_COUNT, nvmlBrandType_t.NVML_BRAND_UNKNOWN):
                brand_name = "Unknown"
            else:
                brand_name = str(brand_name.name).replace("NVML_BRAND_","").replace("_"," ")
            return brand_name
        except self.pynvml_lib.NVMLError as e:
            error_code = e.args[0]
            if error_code == self.pynvml_lib.NVML_ERROR_NOT_SUPPORTED:
                return e
            else:
                raise self.pynvml_lib.NVMLError(e)

    def get_device_minor_number(self, handle) -> Any:
        try:
            minor_number = self.pynvml_lib.nvmlDeviceGetMinorNumber(handle)
            return minor_number
        except self.pynvml_lib.NVMLError as e:
            error_code = e.args[0]
            if error_code == self.pynvml_lib.NVML_ERROR_NOT_SUPPORTED:
                return e
            else:
                raise self.pynvml_lib.NVMLError(e)

    def get_device_num_of_gpu_cores(self, handle) -> Any:
        try:
            num_of_gpu_cores = self.pynvml_lib.nvmlDeviceGetNumGpuCores(handle)
            return num_of_gpu_cores
        except self.pynvml_lib.NVMLError as e:
            error_code = e.args[0]
            if error_code == self.pynvml_lib.NVML_ERROR_NOT_SUPPORTED:
                return e
            else:
                raise self.pynvml_lib.NVMLError(e)

    def get_device_attributes(self, handle) -> Any:
        try:
            device_attributes = self.pynvml_lib.nvmlDeviceGetAttributes_v2(handle)
            return device_attributes
        except self.pynvml_lib.NVMLError as e:
            error_code = e.args[0]
            if error_code == self.pynvml_lib.NVML_ERROR_NOT_SUPPORTED:
                return e
            else:
                raise self.pynvml_lib.NVMLError(e)

    def get_device_architecture(self, handle) -> Any:
        try:
            device_architecture = self.pynvml_lib.nvmlDeviceGetArchitecture(handle)
            return device_architecture
        except self.pynvml_lib.NVMLError as e:
            error_code = e.args[0]
            if error_code == self.pynvml_lib.NVML_ERROR_NOT_SUPPORTED:
                return e
            else:
                raise self.pynvml_lib.NVMLError(e)
    
    def get_device_clocks_info(self, handle) -> Any:
        try:
            #Commented functions return NOT SUPPORTED!
            adaptive_clock_info_status = self.pynvml_lib.nvmlDeviceGetAdaptiveClockInfoStatus(handle)
            application_clocks = list()
            for clock_type in range(0, nvmlClockType_t.NVML_CLOCK_COUNT.value):
                pass
                #application_clock_mhz = self.pynvml_lib.nvmlDeviceGetApplicationsClock(handle, clock_type)
                #application_clocks.append(application_clock_mhz)
            auto_boosted_clocks = {
                "is_enabled": None,
                "default_is_enabled": None
            }
            #(isEnabled, defaultIsEnabled) = self.pynvml_lib.nvmlDeviceGetAutoBoostedClocksEnabled(handle)
            #auto_boosted_clocks["is_enabled"] = "enabled" if isEnabled == 1 else "disabled"
            #auto_boosted_clocks["default_is_enabled"] = "enabled" if defaultIsEnabled == 1 else "disabled"
            #self.pynvml_lib.nvmlDeviceGetClock()
            for clock_type in range(0, nvmlClockType_t.NVML_CLOCK_COUNT.value):
                clock_info = self.pynvml_lib.nvmlDeviceGetClockInfo(handle, clock_type)
                print(clock_info)
            current_clocks_throttle_reasons = self.pynvml_lib.nvmlDeviceGetCurrentClocksThrottleReasons(handle)
            print(current_clocks_throttle_reasons)
            for clock_type in range(0, nvmlClockType_t.NVML_CLOCK_COUNT.value):
                pass
                #default_application_clock = self.pynvml_lib.nvmlDeviceGetDefaultApplicationsClock(handle, clock_type)
                #print(default_application_clock)
            for clock_type in range(0, nvmlClockType_t.NVML_CLOCK_COUNT.value):
                max_clock_info = self.pynvml_lib.nvmlDeviceGetMaxClockInfo(handle, clock_type)
                print(max_clock_info)
            for clock_type in range(0, nvmlClockType_t.NVML_CLOCK_COUNT.value):
                pass
                #max_customer_boost_clock = self.pynvml_lib.nvmlDeviceGetMaxCustomerBoostClock(handle, clock_type)
                #print(max_customer_boost_clock)
            supported_clocks_throttle_reasons = self.pynvml_lib.nvmlDeviceGetSupportedClocksThrottleReasons(handle)
            print("supported", supported_clocks_throttle_reasons)
            #supported_graphics_clocks = self.pynvml_lib.nvmlDeviceGetSupportedGraphicsClocks(handle, 1)
            #print("supported graphics", supported_graphics_clocks)
            supported_memory_clocks = self.pynvml_lib.nvmlDeviceGetSupportedMemoryClocks(handle)
            print(supported_memory_clocks)
            violation_status = self.pynvml_lib.nvmlDeviceGetViolationStatus(handle, 1)
            print(violation_status)
            return {
                "adaptive_clock_status": adaptive_clock_info_status,
                "application_clocks_mhz": application_clocks,
                "auto_boost_clocks_enabled_info": auto_boosted_clocks
            }
        except self.pynvml_lib.NVMLError as e:
            error_code = e.args[0]
            if error_code == self.pynvml_lib.NVML_ERROR_NOT_SUPPORTED:
                return e
            else:
                raise self.pynvml_lib.NVMLError(e)

    def get_device_memory_info(self, handle) -> Any:
        try:
            bar1_memory_info = self.pynvml_lib.nvmlDeviceGetBAR1MemoryInfo(handle)
            print(bar1_memory_info)
            memory_info = self.pynvml_lib.nvmlDeviceGetMemoryInfo(handle)
            print(memory_info)
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
            curr_pcie_link_gen = self.pynvml_lib.nvmlDeviceGetCurrPcieLinkGeneration(handle)
            curr_pcie_link_width = self.pynvml_lib.nvmlDeviceGetCurrPcieLinkWidth(handle)
            max_pcie_link_gen = self.pynvml_lib.nvmlDeviceGetMaxPcieLinkGeneration(handle)
            max_pcie_link_width = self.pynvml_lib.nvmlDeviceGetMaxPcieLinkWidth(handle)
            memory_bus_width = self.pynvml_lib.nvmlDeviceGetMemoryBusWidth(handle)
            pci_info = self.pynvml_lib.nvmlDeviceGetPciInfo_v3(handle)
            pcie_link_max_speed = self.pynvml_lib.nvmlDeviceGetPcieLinkMaxSpeed(handle)
            pcie_replay_counter = self.pynvml_lib.nvmlDeviceGetPcieReplayCounter(handle)
            result = {
                "curr_pcie_link_gen": curr_pcie_link_gen,
                "curr_pcie_link_width": curr_pcie_link_width,
                "max_pcie_link_gen": max_pcie_link_gen,
                "max_pcie_link_width": max_pcie_link_width,
                "memory_bus_width": memory_bus_width,
                "pci_info": pci_info,
                "pcie_link_max_speed": pcie_link_max_speed,
                "pcie_replay_counter": pcie_replay_counter,
            }
            print(result)
            return result
        except self.pynvml_lib.NVMLError as e:
            error_code = e.args[0]
            if error_code == self.pynvml_lib.NVML_ERROR_NOT_SUPPORTED:
                return e
            else:
                raise self.pynvml_lib.NVMLError(e)