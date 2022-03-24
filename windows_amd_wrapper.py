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