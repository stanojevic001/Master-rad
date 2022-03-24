from typing import Any
from common_api import CommonAPI, StatusCode
# Library is called pynvml!
from pynvml import *

class WindowsLinux_NVIDIA_API(CommonAPI):
    
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
        return driver_version

    def get_library_version(self) -> str:
        lib_version = nvmlSystemGetNVMLVersion()
        return lib_version