import ctypes
from typing import Any
from common_api import CommonAPI
from defines import *
import linux_rocm_smi_bindings

class Linux_ROCm_SMI_Wrapper(CommonAPI):

    def initialize(self) -> None:
        
        linux_rocm_smi_bindings.rocm_initialize()

    def finish(self) -> None:
        
        linux_rocm_smi_bindings.rocm_finish()

    def get_number_of_devices(self) -> int:
        
        number_of_devices = ctypes.c_uint32
        linux_rocm_smi_bindings.rocm_get_number_of_devices(ctypes.POINTER(number_of_devices))
        ret_value = number_of_devices.value

        return ret_value

    def initialize_with_flags(self, flags: Any) -> None:
        pass

    def get_driver_version(self) -> str:
        
        drv_version = ctypes.c_char * 200
        linux_rocm_smi_bindings.rocm_get_driver_version(ctypes.POINTER(drv_version))
        return (str(drv_version)).decode('ASCII')

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