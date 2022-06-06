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
        return -1

    def initialize_with_flags(self, flags: Any) -> None:
        pass

    def get_driver_version(self) -> str:
        versionsInfo = C_ADLVersionsInfo()
        self.adl_clib.functions["adl_get_driver_version"](ctypes.byref(versionsInfo))
        return bytes(versionsInfo.strDriverVer).decode('ASCII')

    def get_library_version(self) -> str:
        return ""

    def get_device_handle_by_index(self, index) -> Any:
        return ""
    
    def get_device_serial_by_handle(self, handle) -> Any:
        return ""

    def get_device_uuid_by_handle(self, handle) -> Any:
        return ""

    def get_device_name_by_handle(self, handle) -> Any:
        return ""

    def get_device_temperature_info(self, handle) -> Any:
        return ""

    def get_device_power_info(self, handle) -> Any:
        return ""