from typing import Any
from defines import StatusCode

class CommonAPI():

    def initialize(self) -> None:
        ''' Initialize driver of the GPU '''
        pass

    def finish(self) -> None:
        ''' Cleanup and finish using driver of the GPU '''
        pass

    def get_number_of_devices(self) -> int:
        ''' Get number of devices '''
        pass

    def initialize_with_flags(self, flags: Any) -> None:
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

    def get_device_power_info(self, handle) -> Any:
        ''' Get device power information '''
        pass

    def get_device_board_id(self, handle) -> Any:
        ''' Get device's board id '''
        pass

    def get_device_brand(self, handle) -> Any:
        ''' Get device's brand name '''
        pass
    
    def get_device_minor_number(self, handle) -> Any:
        ''' Get device's minor number '''
        pass

    def get_device_num_of_gpu_cores(self, handle) -> Any:
        ''' Get number of GPU cores for a given GPU device '''
        pass

    def get_device_attributes(self, handle) -> Any:
        ''' Get device's attributes '''
        pass

    def get_device_architecture(self, handle) -> Any:
        ''' Get device's architecture '''
        pass

    def get_device_clocks_info(self, handle) -> Any:
        ''' Get clock info for a given GPU device '''
        pass

    def get_device_memory_info(self, handle) -> Any:
        ''' Get memory info for a given GPU device '''
        pass

    def get_device_bus_info(self, handle) -> Any:
        ''' Get bus info for a given GPU device '''
        pass
    
    def get_device_versions_info(self, handle) -> Any:
        ''' Get info about versions related to a given GPU device '''
        pass