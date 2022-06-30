from common_api import StatusCode
from output_templates import *

class Request():

    def __init__(self, command) -> None:
        self.commandObj = command
    
    def process_command_full(self) -> str:
        output = ""

    def process_command_versions(self) -> str:
        output = ""
        device_count = self.commandObj.apiObject.get_number_of_devices()
        output += OutputTemplates.catalog_console_device_num.format(device_num=device_count)
        i = 0
        for i in range(0, device_count):
            handle = self.commandObj.apiObject.get_device_handle_by_index(i)
            output += OutputTemplates.catalog_console_device.format(index=i)

            name = self.commandObj.apiObject.get_device_name_by_handle(handle)
            if name is not None:
                output += OutputTemplates.catalog_elem_output.format(name="Name", value=name)        
            
            versions_info: dict = self.commandObj.apiObject.get_device_versions_info(handle)
            for key in versions_info.keys():
                output += OutputTemplates.catalog_elem_output.format(name=str(key), value=versions_info[key])
            output += "\n"
        return output
    
    def process_command_catalog(self) -> str:
        output = ""
        device_count = self.commandObj.apiObject.get_number_of_devices()
        output += OutputTemplates.catalog_console_device_num.format(device_num=device_count)
        i = 0
        for i in range(0, device_count):
            handle = self.commandObj.apiObject.get_device_handle_by_index(i)
            output += OutputTemplates.catalog_console_device.format(index=i)

            name = self.commandObj.apiObject.get_device_name_by_handle(handle)
            if name is not None:
                output += OutputTemplates.catalog_elem_output.format(name="Name", value=name)

            serial_number = self.commandObj.apiObject.get_device_serial_by_handle(handle)
            if serial_number is not None:
                output += OutputTemplates.catalog_elem_output.format(name="Serial Number", value=serial_number)

            uuid = self.commandObj.apiObject.get_device_uuid_by_handle(handle)
            if uuid is not None:
                output += OutputTemplates.catalog_elem_output.format(name="Universally Unique Identifier(UUID)", value=uuid)

            board_id = self.commandObj.apiObject.get_device_board_id(handle)
            if board_id is not None:
                output += OutputTemplates.catalog_elem_output.format(name="Board ID", value=board_id)

            brand_name = self.commandObj.apiObject.get_device_brand(handle)
            if brand_name is not None:
                output += OutputTemplates.catalog_elem_output.format(name="Brand", value=brand_name)

            minor_number = self.commandObj.apiObject.get_device_minor_number(handle)
            if minor_number is not None:
                output += OutputTemplates.catalog_elem_output.format(name="Minor number", value=str(minor_number))

            num_gpu_cores = self.commandObj.apiObject.get_device_num_of_gpu_cores(handle)
            if num_gpu_cores is not None:
                output += OutputTemplates.catalog_elem_output.format(name="Shading units(GPU cores)", value=str(num_gpu_cores))        
            
            deviceArchitecture = self.commandObj.apiObject.get_device_architecture(handle)
            if deviceArchitecture is not None:
                output += OutputTemplates.catalog_elem_output.format(name="Architecture", value=str(deviceArchitecture))

            #print(self.commandObj.apiObject.get_device_attributes(handle))
            
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

    def process_command_clocks(self) -> str:
        output = ""
        device_count = self.commandObj.apiObject.get_number_of_devices()
        output += OutputTemplates.catalog_console_device_num.format(device_num=device_count)
        i = 0
        for i in range(0, device_count):
            handle = self.commandObj.apiObject.get_device_handle_by_index(i)
            output += OutputTemplates.catalog_console_device.format(index=i)

            name = self.commandObj.apiObject.get_device_name_by_handle(handle)
            if name is not None:
                output += OutputTemplates.catalog_elem_output.format(name="Name", value=name)        
            
            clocks_info: dict = self.commandObj.apiObject.get_device_clocks_info(handle)
            for key in clocks_info.keys():
                output += OutputTemplates.catalog_elem_output.format(name=str(key), value=clocks_info[key])
            output += "\n"
        return output
    
    def process_command_memory(self) -> str:
        output = ""
        device_count = self.commandObj.apiObject.get_number_of_devices()
        output += OutputTemplates.catalog_console_device_num.format(device_num=device_count)
        i = 0
        for i in range(0, device_count):
            handle = self.commandObj.apiObject.get_device_handle_by_index(i)
            output += OutputTemplates.catalog_console_device.format(index=i)

            name = self.commandObj.apiObject.get_device_name_by_handle(handle)
            if name is not None:
                output += OutputTemplates.catalog_elem_output.format(name="Name", value=name)        
            memory_info: dict = self.commandObj.apiObject.get_device_memory_info(handle)
            for key in memory_info.keys():
                output += OutputTemplates.catalog_elem_output.format(name=str(key), value=memory_info[key])
            output += "\n"
        return output

    def process_command_bus(self) -> str:
        output = ""
        device_count = self.commandObj.apiObject.get_number_of_devices()
        output += OutputTemplates.catalog_console_device_num.format(device_num=device_count)
        i = 0
        for i in range(0, device_count):
            handle = self.commandObj.apiObject.get_device_handle_by_index(i)
            output += OutputTemplates.catalog_console_device.format(index=i)

            name = self.commandObj.apiObject.get_device_name_by_handle(handle)
            if name is not None:
                output += OutputTemplates.catalog_elem_output.format(name="Name", value=name) 
   
            bus_info: dict = self.commandObj.apiObject.get_device_bus_info(handle)
            for key in bus_info.keys():
                output += OutputTemplates.catalog_elem_output.format(name=str(key), value=bus_info[key])
            output += "\n"
        return output

    def process_command_ecc(self) -> str:
        pass

    def process_command_performance(self) -> str:
        pass

    def process_command_modes(self) -> str:
        pass
    

    def process_command_help(self) -> str:
        output = ""
        output += OutputTemplates.help_console_output
        return output
    
    def process_command_processes(self) -> str:
        pass

    def process_request(self) -> StatusCode:
        try:
            #IDEJA: da moze vise stvari da se zajedno stampaju!!!
            self.commandObj.apiObject.initialize()
            if self.commandObj.called_command_name == "full":
                print(self.process_command_full())
            elif self.commandObj.called_command_name == "versions":
                print(self.process_command_versions())
            elif self.commandObj.called_command_name == "catalog":
                print(self.process_command_catalog())
            elif self.commandObj.called_command_name == "temperature":
                print(self.process_command_temperature())
            elif self.commandObj.called_command_name == "clocks":
                print(self.process_command_clocks())
            elif self.commandObj.called_command_name == "help":
                print(self.process_command_help())
            elif self.commandObj.called_command_name == "memory":
                print(self.process_command_memory())
            elif self.commandObj.called_command_name == "bus":
                print(self.process_command_bus())
            elif self.commandObj.called_command_name == "ecc":
                print(self.process_command_ecc())
            elif self.commandObj.called_command_name == "performance":
                print(self.process_command_performance())
            elif self.commandObj.called_command_name == "modes":
                print(self.process_command_modes())
            elif self.commandObj.called_command_name == "processes":
                print(self.process_command_processes())
            else:
                print("Invalid command '{}' invoked. Try command 'help' for futher information.".format(self.commandObj.called_command_name))
                return StatusCode.INVALID_REQUEST

            return StatusCode.SUCCESS
        except Exception as e:
            raise(e)
        finally:
            self.commandObj.apiObject.finish()