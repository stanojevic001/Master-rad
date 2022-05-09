from typing import Any
from common_api import CommonAPI, StatusCode
from ctypes import *

class WindowsAMD_API(CommonAPI):

    def initialize(self) -> StatusCode:
        pass

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