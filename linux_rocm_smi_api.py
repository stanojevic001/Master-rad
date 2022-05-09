from typing import Any
from common_api import CommonAPI
from defines import *
import ctypes

rocm_lib = ctypes.CDLL("rocm_out.so")

class Linux_ROCm_SMI_Wrapper(CommonAPI):

    def initialize(self) -> StatusCode:
        ret_status = StatusCode.SUCCESS

        rocm_lib.initialize.argtypes = []
        rocm_lib.initialize.restype = ctypes.c_int
        universal_initialize = rocm_lib.initialize
        universal_initialize()

    def finish(self) -> StatusCode:
        pass

    def get_number_of_devices(self) -> int:
        pass

    def initialize_with_flags(self, flags: Any) -> StatusCode:
        pass

    def get_driver_version(self) -> str:
        pass

    def get_library_version(self) -> str:
        pass

    def get_device_handle_by_index(self, index) -> Any:
        pass
    
    def get_device_serial_by_handle(self, handle) -> Any:
        pass

    def get_device_uuid_by_handle(self, handle) -> Any:
        pass

    def get_device_name_by_handle(self, handle) -> Any:
        pass

    def get_device_temperature_info(self, handle) -> Any:
        pass

    def get_device_power_info(self, handle) -> Any:
        pass