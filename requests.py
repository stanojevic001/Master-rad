from common_api import StatusCode
from output_templates import *
from universal_output_structures import *

class Request():

    def __init__(self, command) -> None:
        self.commandObj = command
    
    def process_command_driver(self) -> StatusCode:
        driver_version = self.commandObj.apiObject.get_driver_version()
        current_driver_model = "/"
        pending_driver_model = "/"

        output = driver_info_console.format(version=driver_version)
        print(output)

    def process_request(self) -> StatusCode:
        try:
            self.commandObj.apiObject.initialize()
            if self.commandObj.called_command_name == "driver":
                self.process_command_driver()
            elif self.commandObj.called_command_name == "2":
                pass
            elif self.commandObj.called_command_name == "3":
                pass
            elif self.commandObj.called_command_name == "4":
                pass
            elif self.commandObj.called_command_name == "5":
                pass

            return StatusCode.SUCCESS
        except Exception as e:
            raise(e)
        finally:
            self.commandObj.apiObject.finish()