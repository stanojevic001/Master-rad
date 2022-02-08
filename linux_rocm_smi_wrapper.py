from common_api import CommonAPI
from defines import *

class Linux_ROCm_SMI_Wrapper(CommonAPI):

    def initialize() -> StatusCode:
        ''' Initialize driver of the GPU '''
        pass

    def finish() -> StatusCode:
        ''' Cleanup and finish using driver of the GPU '''
        pass

    def get_number_of_devices() -> StatusCode:
        ''' Get number of devices '''
        pass