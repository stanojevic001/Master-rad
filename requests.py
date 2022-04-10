from ensurepip import version
from common_api import StatusCode
from output_templates import *

class Request():

    def __init__(self, command) -> None:
        self.commandObj = command
    
    def process_command_driver(self) -> StatusCode:
        driver_version = self.commandObj.apiObject.get_driver_version()
        output = driver_info_console.format(version=driver_version)
        print(output)

    def process_request(self) -> StatusCode:
        try:
            self.commandObj.apiObject.initialize()
            self.process_command_driver()
            return StatusCode.SUCCESS
        except Exception as e:
            raise(e)
        finally:
            self.commandObj.apiObject.finish()