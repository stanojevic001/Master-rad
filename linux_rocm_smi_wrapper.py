from typing import Any
from common_api import CommonAPI
from defines import *

class Linux_ROCm_SMI_Wrapper(CommonAPI):

    def initialize() -> StatusCode:
        pass

    def finish() -> StatusCode:
        pass

    def get_number_of_devices() -> int:
        pass

    def initialize_with_flags(self, flags: Any) -> StatusCode:
        pass

    def get_driver_version(self) -> str:
        pass

    def get_library_version(self) -> str:
        pass