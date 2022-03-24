from typing import Any
from defines import StatusCode

class CommonAPI():

    def initialize(self) -> StatusCode:
        ''' Initialize driver of the GPU '''
        pass

    def finish(self) -> StatusCode:
        ''' Cleanup and finish using driver of the GPU '''
        pass

    def get_number_of_devices(self) -> int:
        ''' Get number of devices '''
        pass

    def initialize_with_flags(self, flags: Any) -> StatusCode:
        ''' Initialize driver of the GPU with forwarded flags '''
        pass

    def get_driver_version(self) -> str:
        ''' Get system driver version '''
        pass

    def get_library_version(self) -> str:
        ''' Get library version '''
        pass