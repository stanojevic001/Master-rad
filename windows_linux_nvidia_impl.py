import enum
import importlib
from typing import Any
from common_api import CommonAPI
from defines import CURRENT_OS, SupportedOS
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

class nvmlTemperatureSensors_t(enum.IntEnum):
    NVML_TEMPERATURE_GPU     = 0
    NVML_TEMPERATURE_COUNT   = 1

class nvmlTemperatureThresholds_t(enum.IntEnum):
    NVML_TEMPERATURE_THRESHOLD_SHUTDOWN      = 0
    NVML_TEMPERATURE_THRESHOLD_SLOWDOWN      = 1
    NVML_TEMPERATURE_THRESHOLD_MEM_MAX       = 2
    NVML_TEMPERATURE_THRESHOLD_GPU_MAX       = 3
    NVML_TEMPERATURE_THRESHOLD_ACOUSTIC_MIN  = 4
    NVML_TEMPERATURE_THRESHOLD_ACOUSTIC_CURR = 5
    NVML_TEMPERATURE_THRESHOLD_ACOUSTIC_MAX  = 6
    NVML_TEMPERATURE_THRESHOLD_COUNT         = 7

class WindowsLinux_NVIDIA_API(CommonAPI):
    pynvml_lib = None
    def __init__(self) -> None:
        self.pynvml_lib = importlib.import_module("pynvml")

    def convert_enum_name_to_readable_string(self, enum_name: str, enum_type: enum.Enum) -> str:
        result = ""
        if type(enum_type) == nvmlBrandType_t:
            if "NVML_BRAND_NVIDIA_VAPPS" == enum_name:
                result = "NVIDIA Virtual Applications"
            elif "NVML_BRAND_NVIDIA_VPC" == enum_name:
                result = "NVIDIA Virtual PC"
            elif "NVML_BRAND_NVIDIA_VCS" == enum_name:
                result = "NVIDIA Virtual Compute Server"
            elif "NVML_BRAND_NVIDIA_VWS" == enum_name:
                result = "NVIDIA RTX Virtual Workstation"
            elif "NVML_BRAND_NVIDIA_VWS" == enum_name:
                result = "NVIDIA Cloud Gaming"
            else:
                result = enum_name.replace("NVML_DEVICE_ARCH_","").replace("_"," ")

        if type(enum_type) == nvmlClockType_t:
            if "NVML_CLOCK_GRAPHICS" == enum_name:
                result = "Graphics"
            elif "NVML_CLOCK_SM" == enum_name:
                result = "System management (SM)"
            elif "NVML_CLOCK_MEM" == enum_name:
                result = "Memory"
            elif "NVML_CLOCK_VIDEO" == enum_name:
                result = "Video encoder/decoder"
            result += " clock"
        if type(enum_type) == nvmlClockId_t:
            if "NVML_CLOCK_ID_CURRENT" == enum_name:
                result = "Current actual clock value"
            elif "NVML_CLOCK_ID_APP_CLOCK_TARGET" == enum_name:
                result = "Target application clock"
            elif "NVML_CLOCK_ID_APP_CLOCK_DEFAULT" == enum_name:
                result = "Default application clock target"
            elif "NVML_CLOCK_ID_CUSTOMER_BOOST_MAX" == enum_name:
                result = "Original Equipment Manufacturer(OEM)-defined maximum clock rate"
        if type(enum_type) == nvmlInforomObject_t:
            if "NVML_INFOROM_OEM" == enum_name:
                result = "Original Equipment Manufacturer (OEM)"
            elif "NVML_INFOROM_ECC" == enum_name:
                result = "Error Correcting Code (ECC)"
            elif "NVML_INFOROM_POWER" == enum_name:
                result = "Power management"
            result += " object"
        if type(enum_type) == nvmlDeviceArchitecture_t:
            result = enum_name.replace("NVML_DEVICE_ARCH_","").replace("_"," ")
        if type(enum_type) == nvmlTemperatureSensors_t:
            if "NVML_TEMPERATURE_GPU" == enum_name:
                result = "GPU sensor"
        if type(enum_type) == nvmlTemperatureThresholds_t:
            if "NVML_TEMPERATURE_THRESHOLD_SHUTDOWN" == enum_name:
                result = "Shutdown"
            elif "NVML_TEMPERATURE_THRESHOLD_SLOWDOWN" == enum_name:
                result = "Slowdown"
            elif "NVML_TEMPERATURE_THRESHOLD_MEM_MAX" == enum_name:
                result = "Memory max"
            elif "NVML_TEMPERATURE_THRESHOLD_GPU_MAX" == enum_name:
                result = "GPU max"
            elif "NVML_TEMPERATURE_THRESHOLD_ACOUSTIC_MIN" == enum_name:
                result = "Acoustic min"
            elif "NVML_TEMPERATURE_THRESHOLD_ACOUSTIC_CURR" == enum_name:
                result = "Acoustic current"
            elif "NVML_TEMPERATURE_THRESHOLD_ACOUSTIC_MAX" == enum_name:
                result = "Acoustic max"
            result += " threshold"
        return result

    def initialize(self) -> None:
        if hasattr(self.pynvml_lib, "nvmlInit") and callable(self.pynvml_lib.nvmlInit):
            try:
                self.pynvml_lib.nvmlInit()
            except Exception as e:
                raise Exception("Calling lib init function failed! Library initialization failed.")
        else:
            raise Exception("Can't find lib init function! Library initialization failed.")

    def finish(self) -> None:
        if hasattr(self.pynvml_lib, "nvmlShutdown") and callable(self.pynvml_lib.nvmlShutdown):
            try:
                self.pynvml_lib.nvmlShutdown()
            except Exception as e:
                 raise Exception("Calling lib shut down function failed! Library cleanup failed.")
        else:
            raise Exception("Can't find lib shut down function! Library cleanup failed.")

    def get_number_of_devices(self) -> int:
        num_devices =  0
        if hasattr(self.pynvml_lib, "nvmlDeviceGetCount") and callable(self.pynvml_lib.nvmlDeviceGetCount):
            try:
                num_devices = self.pynvml_lib.nvmlDeviceGetCount()
            except Exception as e:
                num_devices = 0
        else:
            num_devices = 0
        return num_devices
    
    def get_device_handle_by_index(self, index) -> Any:
        handle = None
        if hasattr(self.pynvml_lib, "nvmlDeviceGetHandleByIndex") and callable(self.pynvml_lib.nvmlDeviceGetHandleByIndex):
            try:
                handle = self.pynvml_lib.nvmlDeviceGetHandleByIndex(index)
            except Exception as e:
                handle = None
                raise Exception("Can't find device handle with a give index {i}!".format(i = str(index)))
        else:
            handle = None
            raise Exception("Can't find nvmlDeviceGetHandleByIndex function in pynvml module!")
        return handle
   
    def get_device_name_by_handle(self, handle) -> Any:
        result = ""
        if hasattr(self.pynvml_lib, "nvmlDeviceGetName") and callable(self.pynvml_lib.nvmlDeviceGetName):
            try:
                result = self.pynvml_lib.nvmlDeviceGetName(handle)
                return result.decode('ASCII')
            except Exception as e:
                result = "Not supported"
        else:
            result = "N/A"
        
        return result
    
    def get_device_temperature_info(self, handle) -> Any:
        temp_readings_sensors = list()
        if hasattr(self.pynvml_lib, "nvmlDeviceGetTemperature") and callable(self.pynvml_lib.nvmlDeviceGetTemperature):
            for temp_readings_sensor_type_key, temp_readings_sensor_type_enum in nvmlTemperatureSensors_t.__members__.items():
                if temp_readings_sensor_type_key == "NVML_TEMPERATURE_COUNT":
                    continue
                temp_sensor_type_name = self.convert_enum_name_to_readable_string(temp_readings_sensor_type_key, temp_readings_sensor_type_enum)
                temp_reading = temp_readings_sensor_type_enum
                try:
                    temp_reading_value = self.pynvml_lib.nvmlDeviceGetTemperature(handle, temp_reading.value)
                    temp_readings_sensors.append({
                        temp_sensor_type_name: temp_reading_value
                    })
                except Exception as e:
                    temp_reading_value = "Not supported"
                    temp_readings_sensors.append({
                        temp_sensor_type_name: temp_reading_value
                    })
        else:
            temp_readings_sensors = "N/A"

        temp_readings_thresholds = list()
        if hasattr(self.pynvml_lib, "nvmlDeviceGetTemperatureThreshold") and callable(self.pynvml_lib.nvmlDeviceGetTemperatureThreshold):
            for temp_readings_threshold_type_key, temp_readings_threshold_type_enum in nvmlTemperatureThresholds_t.__members__.items():
                if temp_readings_threshold_type_key == "NVML_TEMPERATURE_THRESHOLD_COUNT":
                    continue
                temp_threshold_type_name = self.convert_enum_name_to_readable_string(temp_readings_threshold_type_key, temp_readings_threshold_type_enum)
                temp_reading_threshold = temp_readings_threshold_type_enum
                try:
                    temp_reading_threshold_value = self.pynvml_lib.nvmlDeviceGetTemperatureThreshold(handle, temp_reading_threshold.value)
                    temp_readings_thresholds.append({
                        temp_threshold_type_name: temp_reading_threshold_value
                    })
                except Exception as e:
                    temp_reading_threshold_value = "Not supported"
                    temp_readings_thresholds.append({
                        temp_threshold_type_name: temp_reading_threshold_value
                    })
        else:
            temp_readings_thresholds = "N/A"

        all_not_supported = 0
        result_final_output = {
            "Temperature readings from sensors (Celsius)": temp_readings_sensors,
            "Temperature thresholds by type (Celsius)": temp_readings_thresholds
        }
        for key in result_final_output.keys():
            if (type(result_final_output[key]) == str) and result_final_output[key] in ("Not supported", "N/A"):
                all_not_supported += 1
        
        if all_not_supported >= len(result_final_output.keys()):
            result_final_output = "Not supported"

        return result_final_output
    
    def get_device_clocks_info(self, handle) -> Any:
            #Unsupported functions throw NOT SUPPORTED exception, they don't return error code!
        if hasattr(self.pynvml_lib, "nvmlDeviceGetAdaptiveClockInfoStatus") and callable(self.pynvml_lib.nvmlDeviceGetAdaptiveClockInfoStatus):
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
        else:
            adaptive_clock_info_status = "N/A"

        application_clocks = list()
        is_supported_application_clocks = False
        if hasattr(self.pynvml_lib, "nvmlDeviceGetApplicationsClock") and callable(self.pynvml_lib.nvmlDeviceGetApplicationsClock):
            for app_clock_type_dict_key, app_clock_type_dict_enum in nvmlClockType_t.__members__.items():
                if app_clock_type_dict_key in ("NVML_CLOCK_COUNT"):
                    continue
                app_clock_type_name = self.convert_enum_name_to_readable_string(app_clock_type_dict_key, app_clock_type_dict_enum)
                try:
                    application_clock_mhz = self.pynvml_lib.nvmlDeviceGetApplicationsClock(handle, app_clock_type_dict_enum)
                    application_clocks.append({
                        app_clock_type_name: application_clock_mhz
                        })
                    is_supported_application_clocks = True
                except Exception as e:
                    application_clock_mhz = "Not supported"
                    application_clocks.append({
                        app_clock_type_name: application_clock_mhz
                        })
            if not is_supported_application_clocks:
                application_clocks = "Not supported"
        else:
            application_clocks = "N/A"

        auto_boosted_clocks = {
            "is_enabled": None,
            "default_is_enabled": None
        }
        if hasattr(self.pynvml_lib, "nvmlDeviceGetAutoBoostedClocksEnabled") and callable(self.pynvml_lib.nvmlDeviceGetAutoBoostedClocksEnabled):
            try:
                (isEnabled, defaultIsEnabled) = self.pynvml_lib.nvmlDeviceGetAutoBoostedClocksEnabled(handle)
                auto_boosted_clocks["is_enabled"] = "ENABLED" if isEnabled == 1 else "DISABLED"
                auto_boosted_clocks["default_is_enabled"] = "ENABLED" if defaultIsEnabled == 1 else "DISABLED"
            except Exception as e:
                (auto_boosted_clocks["is_enabled"], auto_boosted_clocks["default_is_enabled"]) = ("Not supported", "Not supported")
        else:
            (auto_boosted_clocks["is_enabled"], auto_boosted_clocks["default_is_enabled"]) = ("N/A", "N/A")
        
        clocks_mhz = dict()
        is_supported_clocks_type_id = False
        if hasattr(self.pynvml_lib, "nvmlDeviceGetClock") and callable(self.pynvml_lib.nvmlDeviceGetClock):
            for clock_type_dict_key, clock_type_dict_enum in nvmlClockType_t.__members__.items():
                if clock_type_dict_key in ("NVML_CLOCK_COUNT"):
                    continue
                clock_type_name =self.convert_enum_name_to_readable_string(clock_type_dict_key, clock_type_dict_enum)
                clocks_mhz[clock_type_name] = list()
                for clock_id_dict_key, clock_id_dict_enum in nvmlClockId_t.__members__.items():
                    if clock_id_dict_key in ("NVML_CLOCK_ID_COUNT"):
                        continue
                    clock_id_name = self.convert_enum_name_to_readable_string(clock_id_dict_key, clock_id_dict_enum)
                    try:
                        clock_mhz = self.pynvml_lib.nvmlDeviceGetClock(handle, clock_type_dict_enum, clock_id_dict_enum)
                        clocks_mhz[clock_type_name].append({
                                clock_id_name: clock_mhz
                        })
                        is_supported_clocks_type_id = True
                    except Exception as e:
                        clock_mhz = "Not supported"
                        clocks_mhz[clock_type_name].append({
                                clock_id_name: clock_mhz
                        })
            if not is_supported_clocks_type_id:
                clocks_mhz = "Not supported"
        else:
            clocks_mhz = "N/A"

        clocks_info = list()
        is_supported_clocks_info = False
        if hasattr(self.pynvml_lib, "nvmlDeviceGetClockInfo") and callable(self.pynvml_lib.nvmlDeviceGetClockInfo):
            for clock_info_type_dict_key, clock_info_type_dict_enum in nvmlClockType_t.__members__.items():
                if clock_info_type_dict_key in ("NVML_CLOCK_COUNT"):
                    continue
                clock_info_type_name = self.convert_enum_name_to_readable_string(clock_info_type_dict_key, clock_info_type_dict_enum)
                try:
                    clock_info = self.pynvml_lib.nvmlDeviceGetClockInfo(handle, clock_info_type_dict_enum)
                    clocks_info.append({
                        clock_info_type_name: clock_info
                    })
                    is_supported_clocks_info = True
                except Exception as e:
                    clock_info = "Not supported"
                    clocks_info.append({
                        clock_info_type_name: clock_info
                    })
            if not is_supported_clocks_info:
                clocks_info = "Not supported"
        else:
            clocks_info = "N/A"

        result_throttle_reasons = {}
        if hasattr(self.pynvml_lib, "nvmlDeviceGetCurrentClocksThrottleReasons") and callable(self.pynvml_lib.nvmlDeviceGetCurrentClocksThrottleReasons):
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
                result_throttle_reasons["Reasons"] = list()
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
                result_throttle_reasons = "Not supported"
        else:
            result_throttle_reasons = "N/A"

        default_application_clocks = list()
        is_supported_default_app_clock = False
        if hasattr(self.pynvml_lib, "nvmlDeviceGetDefaultApplicationsClock") and callable(self.pynvml_lib.nvmlDeviceGetDefaultApplicationsClock):
            for default_app_clock_type_dict_key, default_app_clock_type_dict_enum in nvmlClockType_t.__members__.items():
                if default_app_clock_type_dict_key in ("NVML_CLOCK_COUNT"):
                    continue
                default_app_clock_type_name = self.convert_enum_name_to_readable_string(default_app_clock_type_dict_key, default_app_clock_type_dict_enum)
                try:
                    default_application_clock = self.pynvml_lib.nvmlDeviceGetDefaultApplicationsClock(handle, default_app_clock_type_dict_enum)
                    default_application_clocks.append({
                        default_app_clock_type_name: default_application_clock
                    })
                    is_supported_default_app_clock = True
                except Exception as e:
                    default_application_clock = "Not supported"
                    default_application_clocks.append({
                        default_app_clock_type_name: default_application_clock
                    })
            if not is_supported_default_app_clock:
                default_application_clocks = "Not supported"
        else:
            default_application_clocks = "N/A"

        max_clocks_info = list()
        is_supported_max_clock = False
        if hasattr(self.pynvml_lib, "nvmlDeviceGetMaxClockInfo") and callable(self.pynvml_lib.nvmlDeviceGetMaxClockInfo):
            for max_clock_type_dict_key, max_clock_type_dict_enum in nvmlClockType_t.__members__.items():
                if max_clock_type_dict_key in ("NVML_CLOCK_COUNT"):
                    continue
                max_clock_type_name = self.convert_enum_name_to_readable_string(max_clock_type_dict_key, max_clock_type_dict_enum)
                try:
                    max_clock_info = self.pynvml_lib.nvmlDeviceGetMaxClockInfo(handle, max_clock_type_dict_enum)
                    max_clocks_info.append({
                        max_clock_type_name: max_clock_info
                    })
                    is_supported_max_clock = True
                except Exception as e:
                    max_clock_info = "Not supported"
                    max_clocks_info.append({
                        max_clock_type_name: max_clock_info
                    })
            if not is_supported_max_clock:
                max_clocks_info = "Not supported"
        else:
            max_clocks_info = "N/A"

        max_customer_boost_clocks = list()
        is_supported_max_customer_boost_clock = False
        if hasattr(self.pynvml_lib, "nvmlDeviceGetMaxCustomerBoostClock") and callable(self.pynvml_lib.nvmlDeviceGetMaxCustomerBoostClock):
            for max_customer_boost_clock_type_dict_key, max_customer_boost_clock_type_dict_enum in nvmlClockType_t.__members__.items():
                if max_customer_boost_clock_type_dict_key in ("NVML_CLOCK_COUNT"):
                    continue
                max_customer_boost_clock_type_name = self.convert_enum_name_to_readable_string(max_customer_boost_clock_type_dict_key, max_customer_boost_clock_type_dict_enum)
                try:
                    max_customer_boost_clock = self.pynvml_lib.nvmlDeviceGetMaxCustomerBoostClock(handle, max_customer_boost_clock_type_dict_enum)
                    max_customer_boost_clocks.append({
                        max_customer_boost_clock_type_name: max_customer_boost_clock
                    })
                    is_supported_max_customer_boost_clock = True
                except Exception as e:
                    max_customer_boost_clock = "Not supported"
                    max_customer_boost_clocks.append({
                        max_customer_boost_clock_type_name: max_customer_boost_clock
                    })
            if not is_supported_max_customer_boost_clock:
                max_customer_boost_clocks = "Not supported"
        else:
            max_customer_boost_clocks = "N/A"

        if hasattr(self.pynvml_lib, "nvmlDeviceGetSupportedClocksThrottleReasons") and callable(self.pynvml_lib.nvmlDeviceGetSupportedClocksThrottleReasons):
            try:
                supported_clocks_throttle_reasons = self.pynvml_lib.nvmlDeviceGetSupportedClocksThrottleReasons(handle)
                throttle_reasons_bitmasks = {
                    "GPU Idle": self.pynvml_lib.nvmlClocksThrottleReasonGpuIdle, # vidi isto za proveru da li postoji!
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
        else:
            supported_clocks_throttle_reasons = "N/A"

        supported_memory_clocks = None
        if hasattr(self.pynvml_lib, "nvmlDeviceGetSupportedMemoryClocks") and callable(self.pynvml_lib.nvmlDeviceGetSupportedMemoryClocks):
            try:
                supported_memory_clocks = self.pynvml_lib.nvmlDeviceGetSupportedMemoryClocks(handle)
            except Exception as e:
                supported_memory_clocks = "Not supported"
        else:
            supported_memory_clocks = "N/A"

        supported_graphics_clocks = None
        if hasattr(self.pynvml_lib, "nvmlDeviceGetSupportedGraphicsClocks") and callable(self.pynvml_lib.nvmlDeviceGetSupportedGraphicsClocks):
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
        else:
            supported_graphics_clocks = "N/A"

        violation_statuses = dict()
        if hasattr(self.pynvml_lib, "nvmlDeviceGetViolationStatus") and callable(self.pynvml_lib.nvmlDeviceGetViolationStatus):
            possible_violation_statuses = {
                "Power induced": self.pynvml_lib.NVML_PERF_POLICY_POWER,
                "Thermal induced": self.pynvml_lib.NVML_PERF_POLICY_THERMAL,
                "Sync boost induced": self.pynvml_lib.NVML_PERF_POLICY_SYNC_BOOST,
                "Board limit induced": self.pynvml_lib.NVML_PERF_POLICY_BOARD_LIMIT,
                "Low utilization induced": self.pynvml_lib.NVML_PERF_POLICY_LOW_UTILIZATION,
                "Board reliability limit induced": self.pynvml_lib.NVML_PERF_POLICY_RELIABILITY,
                "Any reason above induced": self.pynvml_lib.NVML_PERF_POLICY_TOTAL_APP_CLOCKS,
                "Base clocks violation time": self.pynvml_lib.NVML_PERF_POLICY_TOTAL_BASE_CLOCKS
            }
            violation_statuses["Application clocks violations"] = {}
            violation_statuses["Base clocks violations"] = {}
            for policyType in possible_violation_statuses.keys():
                try:
                    violation_status = self.pynvml_lib.nvmlDeviceGetViolationStatus(handle, possible_violation_statuses[policyType])
                    violation_time = violation_status.violationTime if violation_status.violationTime != 0 else "No violation"
                    if possible_violation_statuses[policyType] != self.pynvml_lib.NVML_PERF_POLICY_TOTAL_BASE_CLOCKS:   
                        violation_statuses["Application clocks violations"][policyType] = {"Reference time": violation_status.referenceTime, "Violation time": violation_time}
                    else:
                        violation_statuses["Base clocks violations"] = {"Reference time": violation_status.referenceTime, "Violation time": violation_time}
                except Exception as e:
                    violation_statuses[policyType] = "Not supported" #ubaci proveru ako su svi not supported!
        else:
            violation_statuses = "N/A"

        all_not_supported = 0
        result_final_output = {
            "Adaptive clocking status": adaptive_clock_info_status,
            "Current auto boost clocks status": auto_boosted_clocks["is_enabled"],
            "Default auto boost clocks status": auto_boosted_clocks["default_is_enabled"],
            "Clocks by type and id (MHz)": clocks_mhz,
            "Clocks by type (MHz)": clocks_info,
            "Default application clocks": default_application_clock,
            "Max clock info (MHz)": max_clocks_info,
            "Supported memory clocks (Mhz)": supported_memory_clocks,
            "Supported pairs of memory and graphics clocks (Memory clock: Graphics clocks) (MHz)": supported_graphics_clocks,
            "Application clocks (MHz)": application_clocks,
            "Max customer boost clock (MHz)": max_customer_boost_clocks,
            "Current clocks throttle reasons": result_throttle_reasons,
            "Supported clocks throttle reasons": result_supported_throttle_reasons,
            "Violation status": violation_statuses
        }
        for key in result_final_output.keys():
            if (type(result_final_output[key]) == str) and result_final_output[key] in ("Not supported", "N/A"):
                all_not_supported += 1
        
        if all_not_supported >= len(result_final_output.keys()):
            result_final_output = "Not supported"

        return result_final_output

    def get_device_memory_info(self, handle) -> Any:
        if hasattr(self.pynvml_lib, "nvmlDeviceGetBAR1MemoryInfo") and callable(self.pynvml_lib.nvmlDeviceGetBAR1MemoryInfo):
            try:
                bar1_memory_info = self.pynvml_lib.nvmlDeviceGetBAR1MemoryInfo(handle)
            except Exception as e:
                bar1_memory_info = "Not supported"
        else:
            bar1_memory_info = "N/A"

        if hasattr(self.pynvml_lib, "nvmlDeviceGetMemoryInfo") and callable(self.pynvml_lib.nvmlDeviceGetMemoryInfo):
            try:
                memory_info = self.pynvml_lib.nvmlDeviceGetMemoryInfo(handle)
            except Exception as e:
                memory_info = "Not supported"
        else:
            memory_info = "N/A"

        if hasattr(self.pynvml_lib, "nvmlDeviceGetInforomConfigurationChecksum") and callable(self.pynvml_lib.nvmlDeviceGetInforomConfigurationChecksum):
            try:
                inforom_checksum = self.pynvml_lib.nvmlDeviceGetInforomConfigurationChecksum(handle) 
            except Exception as e:
                inforom_checksum = "Not supported"
        else:
            inforom_checksum = "N/A"

        all_not_supported = 0
        result_final_output = {
            "GPU Total Memory (MB)": bytes_to_megabytes(memory_info.total) if not((type(memory_info) == str) and (memory_info in ("Not supported", "N/A"))) else memory_info,
            "GPU Used Memory (MB)": bytes_to_megabytes(memory_info.used) if not((type(memory_info) == str) and (memory_info in ("Not supported", "N/A"))) else memory_info,
            "GPU Free Memory (MB)": bytes_to_megabytes(memory_info.free) if not((type(memory_info) == str) and (memory_info in ("Not supported", "N/A"))) else memory_info,
            "BAR1 Total Memory (MB)": bytes_to_megabytes(bar1_memory_info.bar1Total) if not((type(bar1_memory_info) == str) and (bar1_memory_info in ("Not supported", "N/A"))) else bar1_memory_info,
            "BAR1 Used Memory (MB)": bytes_to_megabytes(bar1_memory_info.bar1Used) if not((type(bar1_memory_info) == str) and (bar1_memory_info in ("Not supported", "N/A"))) else bar1_memory_info,
            "BAR1 Free Memory (MB)": bytes_to_megabytes(bar1_memory_info.bar1Free) if not((type(bar1_memory_info) == str) and (bar1_memory_info in ("Not supported", "N/A"))) else bar1_memory_info,
            "InfoROM Checksum": inforom_checksum,
        }
        for key in result_final_output.keys():
            if (type(result_final_output[key]) == str) and result_final_output[key] in ("Not supported", "N/A"):
                all_not_supported += 1
        
        if all_not_supported >= len(result_final_output.keys()):
            result_final_output = "Not supported"

        return result_final_output
    
    def get_device_bus_info(self, handle) -> Any:
        if hasattr(self.pynvml_lib, "nvmlDeviceGetCurrPcieLinkGeneration") and callable(self.pynvml_lib.nvmlDeviceGetCurrPcieLinkGeneration):
            try:
                curr_pcie_link_gen = self.pynvml_lib.nvmlDeviceGetCurrPcieLinkGeneration(handle)
            except Exception as e:
                curr_pcie_link_gen = "Not supported"
        else:
            curr_pcie_link_gen = "N/A"
        
        if hasattr(self.pynvml_lib, "nvmlDeviceGetCurrPcieLinkWidth") and callable(self.pynvml_lib.nvmlDeviceGetCurrPcieLinkWidth):
            try:
                curr_pcie_link_width = self.pynvml_lib.nvmlDeviceGetCurrPcieLinkWidth(handle)
            except Exception as e:
                curr_pcie_link_width = "Not supported"
        else:
            curr_pcie_link_width = "N/A"

        if hasattr(self.pynvml_lib, "nvmlDeviceGetMaxPcieLinkGeneration") and callable(self.pynvml_lib.nvmlDeviceGetMaxPcieLinkGeneration):        
            try:
                max_pcie_link_gen = self.pynvml_lib.nvmlDeviceGetMaxPcieLinkGeneration(handle)
            except Exception as e:
                max_pcie_link_gen = "Not supported"
        else:
            max_pcie_link_gen = "N/A"

        if hasattr(self.pynvml_lib, "nvmlDeviceGetMaxPcieLinkWidth") and callable(self.pynvml_lib.nvmlDeviceGetMaxPcieLinkWidth):
            try:
                max_pcie_link_width = self.pynvml_lib.nvmlDeviceGetMaxPcieLinkWidth(handle)
            except Exception as e:
                max_pcie_link_width = "Not supported"
        else:
            max_pcie_link_width = "N/A"

        if hasattr(self.pynvml_lib, "nvmlDeviceGetMemoryBusWidth") and callable(self.pynvml_lib.nvmlDeviceGetMemoryBusWidth):            
            try:
                memory_bus_width = self.pynvml_lib.nvmlDeviceGetMemoryBusWidth(handle)
            except Exception as e:
                memory_bus_width = "Not supported"
        else:
            memory_bus_width = "N/A"

        if hasattr(self.pynvml_lib, "nvmlDeviceGetPciInfo_v3") and callable(self.pynvml_lib.nvmlDeviceGetPciInfo_v3):
            try:
                pci_info = self.pynvml_lib.nvmlDeviceGetPciInfo_v3(handle)
            except Exception as e:
                pci_info = "Not supported"
        else:
            pci_info = "N/A"

        if hasattr(self.pynvml_lib, "nvmlDeviceGetPcieLinkMaxSpeed") and callable(self.pynvml_lib.nvmlDeviceGetPcieLinkMaxSpeed):
            try:
                pcie_link_max_speed = self.pynvml_lib.nvmlDeviceGetPcieLinkMaxSpeed(handle)
                pcie_link_max_speed = nvmlPcieLinkMaxSpeed_t(pcie_link_max_speed).name.replace("NVML_PCIE_LINK_MAX_SPEED_", "").replace("MBPS","")
            except Exception as e:
                pcie_link_max_speed = "Not supported"
        else:
            pcie_link_max_speed = "N/A"

        if hasattr(self.pynvml_lib, "nvmlDeviceGetPcieReplayCounter") and callable(self.pynvml_lib.nvmlDeviceGetPcieReplayCounter):            
            try:
                pcie_replay_counter = self.pynvml_lib.nvmlDeviceGetPcieReplayCounter(handle)
            except Exception as e:
                curr_pcie_link_width = "Not supported"
        else:
            curr_pcie_link_width = "N/A"

        all_not_supported = 0
        result_final_output = { # sredi za jedno polje ako nije supported da ne bude cela struktura! (ako vrati not supported cela funk, kako da znam koje polje moze?)
            "PCI bus id tuple (domain:bus:device.function)": pci_info.busId.decode('ASCII') if not((type(pci_info) == str) and (pci_info in ("Not supported", "N/A"))) else pci_info, # change to check if not supported (ako vrati not supported cela funk, kako da znam koje polje moze?)
            "PCI bus id legacy tuple (domain:bus:device.function)": pci_info.busIdLegacy.decode('ASCII') if not((type(pci_info) == str) and (pci_info in ("Not supported", "N/A"))) else pci_info,
            "PCI domain number": "{0:#0{1}x}".format(pci_info.domain, 10) if not((type(pci_info) == str) and (pci_info in ("Not supported", "N/A"))) else pci_info,
            "PCI bus number": "{0:#0{1}x}".format(pci_info.bus, 4) if not((type(pci_info) == str) and (pci_info in ("Not supported", "N/A"))) else pci_info,
            "PCI device number": "{0:#0{1}x}".format(pci_info.device, 4) if not((type(pci_info) == str) and (pci_info in ("Not supported", "N/A"))) else pci_info,
            "Maximum PCIe link generation": max_pcie_link_gen,
            "Current PCIe link generation": curr_pcie_link_gen,
            "Maximum PCIe link width (lanes)": max_pcie_link_width,
            "Current PCIe link width (lanes)": curr_pcie_link_width,
            "Maximum PCIe link speed (MB/s)": pcie_link_max_speed,
            "Memory bus width (bits)": memory_bus_width,
            "PCIe replay counter": pcie_replay_counter,
        }
        for key in result_final_output.keys():
            if (type(result_final_output[key]) == str) and result_final_output[key] in ("Not supported", "N/A"):
                all_not_supported += 1
        
        if all_not_supported >= len(result_final_output.keys()):
            result_final_output = "Not supported"

        return result_final_output

    def get_device_versions_info(self, handle) -> Any:
        if hasattr(self.pynvml_lib, "nvmlSystemGetCudaDriverVersion") and callable(self.pynvml_lib.nvmlSystemGetCudaDriverVersion):
            try:
                cuda_driver_version = self.pynvml_lib.nvmlSystemGetCudaDriverVersion()
            except Exception as e:
                cuda_driver_version = "Not supported"
        else:
            cuda_driver_version = "N/A"

        if hasattr(self.pynvml_lib, "nvmlSystemGetCudaDriverVersion_v2") and callable(self.pynvml_lib.nvmlSystemGetCudaDriverVersion_v2):
            try:
                cuda_driver_version_v2 = self.pynvml_lib.nvmlSystemGetCudaDriverVersion_v2()
            except Exception as e:
                cuda_driver_version_v2 = "Not supported"
        else:
            cuda_driver_version_v2 = "N/A"

        if hasattr(self.pynvml_lib, "nvmlSystemGetDriverVersion") and callable(self.pynvml_lib.nvmlSystemGetDriverVersion):
            try:
                driver_version = self.pynvml_lib.nvmlSystemGetDriverVersion().decode('ASCII')
            except Exception as e:
                driver_version = "Not supported"
        else:
            driver_version = "N/A"

        if hasattr(self.pynvml_lib, "nvmlSystemGetNVMLVersion") and callable(self.pynvml_lib.nvmlSystemGetNVMLVersion):
            try:
                nvml_version = self.pynvml_lib.nvmlSystemGetNVMLVersion().decode('ASCII')
            except Exception as e:
                nvml_version = "Not supported"
        else:
            nvml_version = "N/A"

        if hasattr(self.pynvml_lib, "nvmlDeviceGetDriverModel") and callable(self.pynvml_lib.nvmlDeviceGetDriverModel):
            try:
                driver_model = self.pynvml_lib.nvmlDeviceGetDriverModel(handle)
                if len(driver_model) > 0:
                    current_driver_model = "WDDM" if driver_model[0] == 0 else "WDM"
                if len(driver_model) > 1:
                    pending_driver_model = "WDDM" if driver_model[1] == 0 else "WDM"
            except Exception as e:
                driver_model = "Not supported"
                current_driver_model = pending_driver_model = driver_model
        else:
            current_driver_model = pending_driver_model = "N/A"

        if hasattr(self.pynvml_lib, "nvmlDeviceGetInforomImageVersion") and callable(self.pynvml_lib.nvmlDeviceGetInforomImageVersion):
            try:
                inforom_image_version = self.pynvml_lib.nvmlDeviceGetInforomImageVersion(handle).decode('ASCII')
            except Exception as e:
                inforom_image_version = "Not supported"
        else:
            inforom_image_version = "N/A"

        inforom_versions = list()
        if hasattr(self.pynvml_lib, "nvmlDeviceGetInforomVersion") and callable(self.pynvml_lib.nvmlDeviceGetInforomVersion):
            for inforom_obj_type_dict_key, inforom_obj_dict_enum in nvmlInforomObject_t.__members__.items():
                if inforom_obj_type_dict_key == "NVML_INFOROM_COUNT":
                    continue
                inforom_obj_type_name = self.convert_enum_name_to_readable_string(inforom_obj_type_dict_key, inforom_obj_dict_enum)
                inforom_obj_type = inforom_obj_dict_enum
                try:
                    inforom_version = self.pynvml_lib.nvmlDeviceGetInforomVersion(handle, inforom_obj_type).decode('ASCII')
                    inforom_versions.append({
                        inforom_obj_type_name: inforom_version
                    })
                except Exception as e:
                    inforom_version = "Not supported"
                    inforom_versions.append({
                        inforom_obj_type_name: inforom_version
                    })
        else:
            inforom_versions = "N/A"

        if hasattr(self.pynvml_lib, "nvmlDeviceGetVbiosVersion") and callable(self.pynvml_lib.nvmlDeviceGetVbiosVersion):
            try:
                vbios_version = self.pynvml_lib.nvmlDeviceGetVbiosVersion(handle).decode('ASCII')
            except Exception as e:
                vbios_version = "Not supported"
        else:
            vbios_version = "N/A"

        all_not_supported = 0
        result_final_output = {
            "CUDA Driver Version": cuda_driver_version_v2,
            "Driver Version": driver_version,
            "NVML Version": nvml_version,
            "Current Driver Model": current_driver_model,
            "Pending Driver Model": pending_driver_model,
            "InfoROM Image Version": inforom_image_version,
            "InfoROM Version": inforom_versions,
            "VBIOS Version": vbios_version
        }
        for key in result_final_output.keys():
            if (type(result_final_output[key]) == str) and result_final_output[key] in ("Not supported", "N/A"):
                all_not_supported += 1
        
        if all_not_supported >= len(result_final_output.keys()):
            result_final_output = "Not supported"

        return result_final_output
    
    def get_device_catalog_info(self, handle) -> Any:
        if hasattr(self.pynvml_lib, "nvmlDeviceGetSerial") and callable(self.pynvml_lib.nvmlDeviceGetSerial):
            try:
                serial_number = self.pynvml_lib.nvmlDeviceGetSerial(handle)
            except self.pynvml_lib.NVMLError as e:
                serial_number = "Not supported"
        else:
            serial_number = "N/A"

        if hasattr(self.pynvml_lib, "nvmlDeviceGetUUID") and callable(self.pynvml_lib.nvmlDeviceGetUUID):
            try:
                uuid = self.pynvml_lib.nvmlDeviceGetUUID(handle).decode('ASCII')
            except:
                uuid = "Not supported"
        else:
            uuid = "N/A"

        if hasattr(self.pynvml_lib, "nvmlDeviceGetBoardId") and callable(self.pynvml_lib.nvmlDeviceGetBoardId):
            try:
                board_id = self.pynvml_lib.nvmlDeviceGetBoardId(handle)
                board_id = hex(board_id) if board_id is not None else "Not supported"
            except self.pynvml_lib.NVMLError as e:
                board_id = "Not supported"
        else:
            board_id = "N/A"

        if hasattr(self.pynvml_lib, "nvmlDeviceGetBrand") and callable(self.pynvml_lib.nvmlDeviceGetBrand):
            try:
                brand_name = nvmlBrandType_t(self.pynvml_lib.nvmlDeviceGetBrand(handle))
                if brand_name.value in (nvmlBrandType_t.NVML_BRAND_COUNT, nvmlBrandType_t.NVML_BRAND_UNKNOWN):
                    brand_name = "Unknown"
                else:
                    brand_name = str(brand_name.name).replace("NVML_BRAND_","").replace("_"," ")
            except self.pynvml_lib.NVMLError as e:
                brand_name = "Not supported"
        else:
            brand_name = "N/A"

        if hasattr(self.pynvml_lib, "nvmlDeviceGetMinorNumber") and callable(self.pynvml_lib.nvmlDeviceGetMinorNumber):
            try:
                minor_number = self.pynvml_lib.nvmlDeviceGetMinorNumber(handle)
            except self.pynvml_lib.NVMLError as e:
                minor_number = "Not supported"
        else:
            minor_number = "N/A"

        if hasattr(self.pynvml_lib, "nvmlDeviceGetNumGpuCores") and callable(self.pynvml_lib.nvmlDeviceGetNumGpuCores):
            try:
                num_of_gpu_cores = self.pynvml_lib.nvmlDeviceGetNumGpuCores(handle)
            except self.pynvml_lib.NVMLError as e:
                num_of_gpu_cores = "Not supported"
        else:
            num_of_gpu_cores = "N/A"

        if hasattr(self.pynvml_lib, "nvmlDeviceGetArchitecture") and callable(self.pynvml_lib.nvmlDeviceGetArchitecture):
            try:
                device_architecture = self.pynvml_lib.nvmlDeviceGetArchitecture(handle)
                device_architecture = nvmlDeviceArchitecture_t(device_architecture).name.replace("NVML_DEVICE_ARCH_", "")
            except self.pynvml_lib.NVMLError as e:
                device_architecture = "Not supported"
        else:
            device_architecture = "N/A"

        if hasattr(self.pynvml_lib, "nvmlDeviceGetAttributes_v2") and callable(self.pynvml_lib.nvmlDeviceGetAttributes_v2):
            try:
                device_attributes = self.pynvml_lib.nvmlDeviceGetAttributes_v2(handle)
            except self.pynvml_lib.NVMLError as e:
                device_attributes = "Not supported"
        else:
            device_attributes = "N/A"

        if hasattr(self.pynvml_lib, "nvmlDeviceGetPciInfo_v3") and callable(self.pynvml_lib.nvmlDeviceGetPciInfo_v3):       
            try:
                pci_info = self.pynvml_lib.nvmlDeviceGetPciInfo_v3(handle)
            except Exception as e:
                    pci_info = "Not supported"
        else:
            pci_info = "Not supported"

        if hasattr(self.pynvml_lib, "nvmlDeviceGetIrqNum") and callable(self.pynvml_lib.nvmlDeviceGetIrqNum):
            try:
                device_irq_num = self.pynvml_lib.nvmlDeviceGetIrqNum(handle).value
            except Exception as e:
                device_irq_num = "Not supported"
        else:
            device_irq_num = "N/A"

        # sredi za jedno polje ako je not supported, da ne bude cela struktura? (ako vrati not supported cela funk, kako da znam koje polje moze?)
        all_not_supported = 0
        result_final_output = {
            "Serial Number": serial_number,
            "Universally Unique Identifier(UUID)": uuid,
            "PCI Device id": "{0:#0{1}x}".format(pci_info.pciDeviceId, 10) if not((type(pci_info) == str) and (pci_info in ("Not supported", "N/A"))) else pci_info, 
            "Device Id": "{0:#0{1}x}".format(pci_info.pciDeviceId, 10)[0:6] if not((type(pci_info) == str) and (pci_info in ("Not supported", "N/A"))) else pci_info,
            "Vendor Id": "0x" + "{0:#0{1}x}".format(pci_info.pciDeviceId, 10)[6:] if not((type(pci_info) == str) and (pci_info in ("Not supported", "N/A"))) else pci_info,
            "Subsystem Id": "{0:#0{1}x}".format(pci_info.pciSubSystemId, 10) if not((type(pci_info) == str) and (pci_info in ("Not supported", "N/A"))) else pci_info,
            "Board ID": board_id,
            "Brand": brand_name,
            "Minor number": str(minor_number),
            "Shading units(GPU cores)": str(num_of_gpu_cores),
            "Architecture": str(device_architecture),
            "Interrupt request (IRQ) number": device_irq_num
        }
        for key in result_final_output.keys():
            if (type(result_final_output[key]) == str) and result_final_output[key] in ("Not supported", "N/A"):
                all_not_supported += 1
        
        if all_not_supported >= len(result_final_output.keys()):
            result_final_output = "Not supported"

        return result_final_output

