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
    def get_device_handle_by_index(self, index) -> Any:
        ''' Get device handle by index '''
        pass
    def get_device_name_by_handle(self, handle) -> Any:
        ''' Get device name by handle '''
        pass
    def get_device_temperature_info(self, handle) -> Any:
        ''' Get device temperature information '''
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
    def get_device_catalog_info(self, handle) -> Any:
        ''' Get catalog info for a given GPU device '''
        pass
    def get_device_ecc_info(self, handle) -> Any:
        ''' Get ECC (Error Correction Code) memory info for a given GPU device '''
        pass