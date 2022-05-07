from typing import Any
from common_api import CommonAPI, StatusCode
# Library is called pynvml!
from pynvml import *

class WindowsLinux_NVIDIA_API(CommonAPI):
    error_dict = NVMLError._errcode_to_string
    def initialize(self) -> StatusCode:
        nvmlInit()
        return StatusCode.SUCCESS

    def initialize_with_flags(self, flags: Any) -> StatusCode:
        # maybe process flags in some way
        flags_send = flags
        nvmlInitWithFlags(flags_send)
        return StatusCode.SUCCESS

    def finish(self) -> StatusCode:
        nvmlShutdown()
        return StatusCode.SUCCESS

    def get_number_of_devices(self) -> int:
        num_devices = nvmlDeviceGetCount()
        return num_devices

    def get_driver_version(self) -> str:
        driver_version = nvmlSystemGetDriverVersion()
        return driver_version.decode('ASCII')

    def get_library_version(self) -> str:
        lib_version = nvmlSystemGetNVMLVersion()
        return lib_version
    
    def get_device_handle_by_index(self, index) -> Any:
        handle = nvmlDeviceGetHandleByIndex(index)
        return handle

    def get_device_serial_by_handle(self, handle) -> Any:
        try:
            serial_number = nvmlDeviceGetSerial(handle)
            return serial_number
        except NVMLError as e:
            error_code = e.args[0]
            if error_code == NVML_ERROR_NOT_SUPPORTED:
                return e
            else:
                raise NVMLError(e)
    
    def get_device_uuid_by_handle(self, handle) -> Any:
        uuid = nvmlDeviceGetUUID(handle)
        return uuid.decode('ASCII')
    
    def get_device_name_by_handle(self, handle) -> Any:
        try:
            result = nvmlDeviceGetName(handle)
            return result.decode('ASCII')
        except NVMLError as e:
            error_code = e.args[0]
            if error_code == NVML_ERROR_NOT_SUPPORTED:
                return e
            else:
                raise NVMLError(e)
    
    def get_device_temperature_info(self, handle) -> Any:
        try:
            temp_readings_count = NVML_TEMPERATURE_COUNT
            temp_thresholds_count = NVML_TEMPERATURE_THRESHOLD_COUNT
            temp_readings = []
            temp_thresholds = []

            for i in range(0,temp_readings_count):
                try:
                    reading = nvmlDeviceGetTemperature(handle, i)
                    temp_readings.append(reading)
                except NVMLError as e:
                    error_code = e.args[0]
                    if error_code in (NVML_ERROR_NOT_SUPPORTED, NVML_ERROR_INVALID_ARGUMENT):
                        temp_readings.append("Not supported")
                        continue
            
            for j in range(0, temp_thresholds_count):
                try:
                    print(j)
                    threshold = nvmlDeviceGetTemperatureThreshold(handle, j)
                    temp_thresholds.append(threshold)
                except NVMLError as e:
                    print(e)
                    error_code = e.args[0]
                    if error_code in (NVML_ERROR_NOT_SUPPORTED, NVML_ERROR_INVALID_ARGUMENT):
                        temp_thresholds.append("Not supported")
                        continue

            return {
                "temp_readings_sensor_types": ["GPU"],
                "temp_readings_values": temp_readings,
                "temp_thresholds_types": ["Shutdown", "Slowdown", "Mem Max", "GPU Max", "Acoustic Min", "Acoustic Curr", "Acoustic Max"],
                "temp_thresholds_values": temp_thresholds
            }
        except NVMLError as e:
            error_code = e.args[0]
            if error_code == NVML_ERROR_NOT_SUPPORTED:
                return e
            else:
                raise NVMLError(e)
        
