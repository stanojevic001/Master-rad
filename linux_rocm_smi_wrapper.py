from typing import Any
from common_api import CommonAPI
from defines import *
import rocm_smi

class Linux_ROCm_SMI_Wrapper(CommonAPI):

    def initialize() -> StatusCode:
        rocm_smi.initializeRsmi()
        return StatusCode.SUCCESS

    def finish() -> StatusCode:
        pass

    def get_number_of_devices() -> int:
        return len(rocm_smi.listDevices())

    def initialize_with_flags(self, flags: Any) -> StatusCode:
        pass

    def get_driver_version(self) -> str:
        rocm_smi.getVersion()

    def get_library_version(self) -> str:
        pass