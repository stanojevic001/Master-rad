from common_api import StatusCode
from output_templates import *

class Request():

    def __init__(self, command) -> None:
        self.commandObj = command
    
    def process_command_driver(self) -> StatusCode:
        output = ""
        driver_version = self.commandObj.apiObject.get_driver_version()
        current_driver_model = "/"
        pending_driver_model = "/"
        output += driver_info_console.format(version=driver_version, current_model=current_driver_model, pending_model = pending_driver_model)
        print(output)
    
    def process_command_catalog(self) -> StatusCode:
        output = ""
        device_count = self.commandObj.apiObject.get_number_of_devices()
        output += catalog_console_device_num.format(device_num=device_count)
        i = 0
        for i in range(0, device_count):
            handle = self.commandObj.apiObject.get_device_handle_by_index(i)
            name = self.commandObj.apiObject.get_device_name_by_handle(handle)
            serial_number = self.commandObj.apiObject.get_device_serial_by_handle(handle)
            uuid = self.commandObj.apiObject.get_device_uuid_by_handle(handle)
            output += catalog_console_device.format(index=i, name=name, serial_num=serial_number, uuid=uuid)
            output += "\n"
        print(output)
    
    def process_command_temperature(self) -> StatusCode:
        output = ""
        device_count = self.commandObj.apiObject.get_number_of_devices()
        i = 0
        output += temperature_console_header
        for i in range(0, device_count):
            output += device_console_index.format(index=i)
            handle = self.commandObj.apiObject.get_device_handle_by_index(i)
            temperature_info = self.commandObj.apiObject.get_device_temperature_info(handle)
            output += temperature_console_readings_title
            for j in range(0, len(temperature_info["temp_readings_values"])):
                name = temperature_info["temp_readings_sensor_types"][j]
                value = temperature_info["temp_readings_values"][j]
                output += temperature_console_element.format(name=name, value=value)
            
            output += temperature_console_thresholds_title
            for k in range(0, len(temperature_info["temp_thresholds_values"])):
                name = temperature_info["temp_thresholds_types"][k]
                value = temperature_info["temp_thresholds_values"][k]
                output += temperature_console_element.format(name=name, value=value)
            
            print(output)

    def process_command_power(self) -> StatusCode:
        pass                

    def process_request(self) -> StatusCode:
        try:
            self.commandObj.apiObject.initialize()
            if self.commandObj.called_command_name == "driver":
                self.process_command_driver()
            elif self.commandObj.called_command_name == "catalog":
                self.process_command_catalog()
            elif self.commandObj.called_command_name == "temperature":
                self.process_command_temperature()
            elif self.commandObj.called_command_name == "power":
                self.process_command_power()
            else:
                print("Invalid command " % self.commandObj.called_command_name)
                return StatusCode.INVALID_REQUEST

            return StatusCode.SUCCESS
        except Exception as e:
            raise(e)
        finally:
            self.commandObj.apiObject.finish()