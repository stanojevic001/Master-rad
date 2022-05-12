import importlib
from typing import Any
from common_api import CommonAPI, StatusCode
# Library is called pynvml!

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
                    print(j)
                    threshold = self.pynvml_lib.nvmlDeviceGetTemperatureThreshold(handle, j)
                    temp_thresholds.append(threshold)
                except self.pynvml_lib.NVMLError as e:
                    print(e)
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
        pass