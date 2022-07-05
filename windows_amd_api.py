import ctypes
from typing import Any
from common_api import CommonAPI, StatusCode
from ctypes import *
from windows_amd_bindings import Ctypes_ADL as cadl_win, C_ADLVersionsInfo

class WindowsAMD_API(CommonAPI):

    adl_clib = None

    def __init__(self) -> None:
        self.adl_clib = cadl_win()

    def initialize(self) -> None:
        self.adl_clib.functions["adl_initialize"]()

    def finish(self) -> None:
        self.adl_clib.functions["adl_finish"]()

    def get_number_of_devices(self) -> int:
        numAdapters = ctypes.c_int()
        self.adl_clib.functions["adl_get_number_of_devices"](ctypes.byref(numAdapters))
        return numAdapters.value

    def get_device_handle_by_index(self, index) -> Any:
        return ""

    def get_device_name_by_handle(self, handle) -> Any:
        return ""

    def get_device_temperature_info(self, handle) -> Any:
        return ""
    
    def get_device_catalog_info(self, handle) -> Any:
        return super().get_device_catalog_info(handle)
    
    def get_device_memory_info(self, handle) -> Any:
        return super().get_device_memory_info(handle)
    
    def get_device_clocks_info(self, handle) -> Any:
        return super().get_device_clocks_info(handle)
    
    def get_device_bus_info(self, handle) -> Any:
        return super().get_device_bus_info(handle)
    
    def get_device_versions_info(self, handle) -> Any:
        versionsInfo = C_ADLVersionsInfo()
        self.adl_clib.functions["adl_get_driver_version"](ctypes.byref(versionsInfo))
        driver_version =  bytes(versionsInfo.strDriverVer).decode('ASCII')

        return {
            "Driver version": driver_version
        }
