import ctypes
from typing import Any
from common_api import CommonAPI
from defines import *
from linux_rocm_smi_bindings import Ctypes_ROCm as crocm

class Linux_ROCm_SMI_Wrapper(CommonAPI):
    rocm_clib = None

    def __init__(self) -> None:
        self.rocm_clib = crocm()
    def initialize(self) -> None:
        flag = ctypes.c_uint64(0)
        self.rocm_clib.functions["rocm_initialize"](flag)

    def finish(self) -> None:
        
        self.rocm_clib.functions["rocm_finish"]()

    def get_number_of_devices(self) -> int:
        
        number_of_devices = ctypes.c_uint32()
        self.rocm_clib.functions["rocm_get_number_of_devices"](ctypes.byref(number_of_devices))
        ret_value = number_of_devices.value

        return ret_value

    def initialize_with_flags(self, flags: Any) -> None:
        pass

    def get_driver_version(self) -> str:
        
        type_call = ctypes.c_int(0)
        drv_version = (ctypes.c_char * 200)()
        len = ctypes.c_uint32(200)
        self.rocm_clib.functions["rocm_get_driver_version"](type_call, drv_version, len)
        return bytes(drv_version.value).decode('ASCII')

    def get_library_version(self) -> str:
        return None

    def get_device_handle_by_index(self, index) -> Any:
        return index
    
    def get_device_serial_by_handle(self, handle) -> Any:
        return None

    def get_device_uuid_by_handle(self, handle) -> Any:
        return None

    def get_device_name_by_handle(self, handle) -> Any:
        return None

    def get_device_temperature_info(self, handle) -> Any:
        return None

    def get_device_power_info(self, handle) -> Any:
        return None

    def get_device_name_by_handle(self, handle) -> Any:
        
        index = ctypes.c_uint32(handle)
        name = (ctypes.c_char * 500)()
        len = ctypes.c_size_t(500)

        self.rocm_clib.functions["rocm_get_device_name_by_handle"](index, name, len)
        return bytes(name.value).decode('ASCII')