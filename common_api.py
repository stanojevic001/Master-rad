from defines import StatusCode

class CommonAPI():

    def initialize(self) -> StatusCode:
        ''' Initialize driver of the GPU '''
        pass

    def finish(self) -> StatusCode:
        ''' Cleanup and finish using driver of the GPU '''
        pass

    def get_number_of_devices(self) -> StatusCode:
        ''' Get number of devices '''
        pass