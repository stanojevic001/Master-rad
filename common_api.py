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

    def get_device_handle_by_index(self, index) -> Any:
        ''' Get device handle by index '''
        pass
    
    def get_device_serial_by_handle(self, handle) -> Any:
        ''' Get device serial number by handle '''
        pass

    def get_device_uuid_by_handle(self, handle) -> Any:
        ''' Get device UUID by handle '''
        pass

    def get_device_name_by_handle(self, handle) -> Any:
        ''' Get device name by handle '''
        pass

    def get_device_temperature_info(self, handle) -> Any:
        ''' Get device temperature information '''
        pass