from common_api import StatusCode
from output_templates import *

class Request():

    def __init__(self, command) -> None:
        self.commandObj = command
    
    def process_command_full(self) -> str:
        output = ""

    def process_command_driver(self) -> str:
        output = ""
        driver_version = self.commandObj.apiObject.get_driver_version()
        current_driver_model = "/"
        pending_driver_model = "/"
        output += OutputTemplates.driver_info_console.format(version=driver_version, current_model=current_driver_model, pending_model = pending_driver_model)
        return output
    
    def process_command_catalog(self) -> str:
        output = ""
        device_count = self.commandObj.apiObject.get_number_of_devices()
        output += OutputTemplates.catalog_console_device_num.format(device_num=device_count)
        i = 0
        for i in range(0, device_count):
            handle = self.commandObj.apiObject.get_device_handle_by_index(i)
            name = self.commandObj.apiObject.get_device_name_by_handle(handle)
            if name is None:
                name = "Not supported"
            serial_number = self.commandObj.apiObject.get_device_serial_by_handle(handle)
            if serial_number is None:
                serial_number = "Not supported"
            uuid = self.commandObj.apiObject.get_device_uuid_by_handle(handle)
            if uuid is None:
                uuid = "Not supported"
            output += OutputTemplates.catalog_console_device.format(index=i, name=name, serial_num=serial_number, uuid=uuid)
            output += "\n"
        return output
    
    def process_command_temperature(self) -> str:
        output = ""
        device_count = self.commandObj.apiObject.get_number_of_devices()
        i = 0
        output += OutputTemplates.temperature_console_header
        for i in range(0, device_count):
            output += OutputTemplates.device_console_index.format(index=i)
            handle = self.commandObj.apiObject.get_device_handle_by_index(i)
            temperature_info = self.commandObj.apiObject.get_device_temperature_info(handle)
            output += OutputTemplates.temperature_console_readings_title
            if temperature_info is None:
                return StatusCode.NOT_SUPPORTED_FEATURE
            for j in range(0, len(temperature_info["temp_readings_values"])):
                name = temperature_info["temp_readings_sensor_types"][j]
                value = temperature_info["temp_readings_values"][j]
                output += OutputTemplates.temperature_console_element.format(name=name, value=value)
            
            output += OutputTemplates.temperature_console_thresholds_title
            for k in range(0, len(temperature_info["temp_thresholds_values"])):
                name = temperature_info["temp_thresholds_types"][k]
                value = temperature_info["temp_thresholds_values"][k]
                output += OutputTemplates.temperature_console_element.format(name=name, value=value)
        return output

    def process_command_power(self) -> str:
        pass

    def process_command_help(self) -> str:
        output = ""
        output += OutputTemplates.help_console_output
        return output

    def process_request(self) -> StatusCode:
        try:
            #IDEJA: da moze vise stvari da se zajedno stampaju!!!
            self.commandObj.apiObject.initialize()
            if self.commandObj.called_command_name == "full":
                print(self.process_command_full())
            elif self.commandObj.called_command_name == "driver":
                print(self.process_command_driver())
            elif self.commandObj.called_command_name == "catalog":
                print(self.process_command_catalog())
            elif self.commandObj.called_command_name == "temperature":
                print(self.process_command_temperature())
            elif self.commandObj.called_command_name == "power":
                print(self.process_command_power())
            elif self.commandObj.called_command_name == "help":
                print(self.process_command_help())
            else:
                print("Invalid command {} invoked. Try command 'help' for futher information.".format(self.commandObj.called_command_name))
                return StatusCode.INVALID_REQUEST

            return StatusCode.SUCCESS
        except Exception as e:
            raise(e)
        finally:
            self.commandObj.apiObject.finish()