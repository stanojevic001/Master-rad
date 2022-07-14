from common_api import StatusCode
from output_templates import *
from utils import process_complex_query_output

class Request():

    def __init__(self, command) -> None:
        self.commandObj = command
    
    def process_command_full(self, specific_device_index=None) -> str:
        output = ""
        device_count = self.commandObj.apiObject.get_number_of_devices()
        output += OutputTemplates.catalog_console_device_num.format(device_num=device_count)
        i = 0
        if specific_device_index is None:
            for i in range(0, device_count):
                handle = self.commandObj.apiObject.get_device_handle_by_index(i)
                output += OutputTemplates.catalog_console_device.format(index=i)

                name = self.commandObj.apiObject.get_device_name_by_handle(handle)
                if name is not None:
                    output += OutputTemplates.catalog_elem_output.format(name="Name", value=name)

                #Add catalog header
                output = self.add_catalog_info_output(handle, output)
                #Add versions header
                output = self.add_versions_info_output(handle, output)
                #Add bus header
                output = self.add_bus_info_output(handle, output)
                #Add memory header
                output = self.add_memory_info_output(handle, output)
                #Add clocks header
                output = self.add_clocks_info_output(handle, output)
                #Add temperature header
                output = self.add_temperature_info_output(handle, output)

        return output

    def process_command_versions(self, specific_device_index=None) -> str:
        output = ""
        device_count = self.commandObj.apiObject.get_number_of_devices()
        output += OutputTemplates.catalog_console_device_num.format(device_num=device_count)
        i = 0
        if specific_device_index is None:
            for i in range(0, device_count):
                handle = self.commandObj.apiObject.get_device_handle_by_index(i)
                output += OutputTemplates.catalog_console_device.format(index=i)

                name = self.commandObj.apiObject.get_device_name_by_handle(handle)
                if name is not None:
                    output += OutputTemplates.catalog_elem_output.format(name="Name", value=name)        
                
                output = self.add_versions_info_output(handle, output)
        return output
    
    def process_command_catalog(self, specific_device_index=None) -> str:
        output = ""
        device_count = self.commandObj.apiObject.get_number_of_devices()
        output += OutputTemplates.catalog_console_device_num.format(device_num=device_count)
        i = 0
        if specific_device_index is None:
            for i in range(0, device_count):
                handle = self.commandObj.apiObject.get_device_handle_by_index(i)
                output += OutputTemplates.catalog_console_device.format(index=i)

                name = self.commandObj.apiObject.get_device_name_by_handle(handle)
                if name is not None:
                    output += OutputTemplates.catalog_elem_output.format(name="Name", value=name)        
                
                output = self.add_catalog_info_output(handle, output)

        return output
    
    def process_command_temperature(self, specific_device_index=None) -> str:
        output = ""
        device_count = self.commandObj.apiObject.get_number_of_devices()
        output += OutputTemplates.catalog_console_device_num.format(device_num=device_count)
        i = 0
        if specific_device_index is None:
            for i in range(0, device_count):
                handle = self.commandObj.apiObject.get_device_handle_by_index(i)
                output += OutputTemplates.catalog_console_device.format(index=i)

                name = self.commandObj.apiObject.get_device_name_by_handle(handle)
                if name is not None:
                    output += OutputTemplates.catalog_elem_output.format(name="Name", value=name)

                output = self.add_temperature_info_output(handle, output) 
                
        return output

    def process_command_clocks(self, specific_device_index=None) -> str:
        output = ""
        device_count = self.commandObj.apiObject.get_number_of_devices()
        output += OutputTemplates.catalog_console_device_num.format(device_num=device_count)
        i = 0
        if specific_device_index is None:
            for i in range(0, device_count):
                handle = self.commandObj.apiObject.get_device_handle_by_index(i)
                output += OutputTemplates.catalog_console_device.format(index=i)

                name = self.commandObj.apiObject.get_device_name_by_handle(handle)
                if name is not None:
                    output += OutputTemplates.catalog_elem_output.format(name="Name", value=name)        
                
                output = self.add_clocks_info_output(handle, output)
        return output
    
    def process_command_memory(self, specific_device_index=None) -> str:
        output = ""
        device_count = self.commandObj.apiObject.get_number_of_devices()
        output += OutputTemplates.catalog_console_device_num.format(device_num=device_count)
        i = 0
        if specific_device_index is None:
            for i in range(0, device_count):
                handle = self.commandObj.apiObject.get_device_handle_by_index(i)
                output += OutputTemplates.catalog_console_device.format(index=i)

                name = self.commandObj.apiObject.get_device_name_by_handle(handle)
                if name is not None:
                    output += OutputTemplates.catalog_elem_output.format(name="Name", value=name)        

                output = self.add_memory_info_output(handle, output)

        return output

    def process_command_bus(self, specific_device_index=None) -> str:
        output = ""
        device_count = self.commandObj.apiObject.get_number_of_devices()
        output += OutputTemplates.catalog_console_device_num.format(device_num=device_count)
        i = 0
        if specific_device_index is None:
            for i in range(0, device_count):
                handle = self.commandObj.apiObject.get_device_handle_by_index(i)
                output += OutputTemplates.catalog_console_device.format(index=i)

                name = self.commandObj.apiObject.get_device_name_by_handle(handle)
                if name is not None:
                    output += OutputTemplates.catalog_elem_output.format(name="Name", value=name) 
    
                output = self.add_bus_info_output(handle, output)

        return output

    def process_command_ecc(self, specific_device_index=None) -> str:
        pass

    def process_command_performance(self, specific_device_index=None) -> str:
        pass

    def process_command_modes(self, specific_device_index=None) -> str:
        pass
    
    def process_command_help(self, specific_device_index=None) -> str:
        output = ""
        output += OutputTemplates.help_console_output
        return output
    
    def process_command_processes(self, specific_device_index=None) -> str:
        pass


    def add_versions_info_output(self, handle, output) -> str:
        versions_info: dict = self.commandObj.apiObject.get_device_versions_info(handle)
        for key in versions_info.keys():
            '''if type(versions_info[key]) == list:
                output += OutputTemplates.catalog_elem_output.format(name=str(key), value="")
                for i in range(0, len(versions_info[key])):
                    if type(versions_info[key][i]) == dict:
                        for elem_key in versions_info[key][i].keys():
                            output += OutputTemplates.catalog_elem_output_nested_level_1.format(name=str(elem_key), value=versions_info[key][i][elem_key])
                    else:
                        output += OutputTemplates.catalog_elem_output_nested_level_1.format(name=str("->"), value=versions_info[key][i])
            elif type(versions_info[key]) == dict:
                output += OutputTemplates.catalog_elem_output.format(name=str(key), value="")
                for elem_key in versions_info[key].keys():
                        output += OutputTemplates.catalog_elem_output_nested_level_1.format(name=str(elem_key), value=versions_info[key][elem_key])
            else:
                output += OutputTemplates.catalog_elem_output.format(name=str(key), value=versions_info[key])'''
            if type(versions_info[key]) == list:
                output += OutputTemplates.catalog_elem_output.format(name=str(key), value="")
                output = process_complex_query_output(versions_info[key], output, nesting_level=6)
            elif type(versions_info[key]) == dict:
                output += OutputTemplates.catalog_elem_output.format(name=str(key), value="")
                output = process_complex_query_output(versions_info[key], output, nesting_level=6)
            else:
                output += OutputTemplates.catalog_elem_output.format(name=str(key), value=versions_info[key])
        output += "\n"
        return output

    def add_catalog_info_output(self, handle, output) -> str:
        catalog_info: dict = self.commandObj.apiObject.get_device_catalog_info(handle)
        for key in catalog_info.keys():
            '''if type(catalog_info[key]) == list:
                output += OutputTemplates.catalog_elem_output.format(name=str(key), value="")
                for i in range(0, len(catalog_info[key])):
                    if type(catalog_info[key][i]) == dict:
                        for elem_key in catalog_info[key][i].keys():
                            output += OutputTemplates.catalog_elem_output_nested_level_1.format(name=str(elem_key), value=catalog_info[key][i][elem_key])
                    else:
                        output += OutputTemplates.catalog_elem_output_nested_level_1.format(name=str("->"), value=catalog_info[key][i])
            elif type(catalog_info[key]) == dict:
                output += OutputTemplates.catalog_elem_output.format(name=str(key), value="")
                for elem_key in catalog_info[key].keys():
                        output += OutputTemplates.catalog_elem_output_nested_level_1.format(name=str(elem_key), value=catalog_info[key][elem_key])
            else:
                output += OutputTemplates.catalog_elem_output.format(name=str(key), value=catalog_info[key])'''
            if type(catalog_info[key]) == list:
                output += OutputTemplates.catalog_elem_output.format(name=str(key), value="")
                output = process_complex_query_output(catalog_info[key], output, nesting_level=6)
            elif type(catalog_info[key]) == dict:
                output += OutputTemplates.catalog_elem_output.format(name=str(key), value="")
                output = process_complex_query_output(catalog_info[key], output, nesting_level=6)
            else:
                output += OutputTemplates.catalog_elem_output.format(name=str(key), value=catalog_info[key])
        output += "\n"
        return output

    def add_temperature_info_output(self, handle, output) -> str:
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

    def add_clocks_info_output(self, handle, output) -> str:
        clocks_info: dict = self.commandObj.apiObject.get_device_clocks_info(handle)
        for key in clocks_info.keys():
            '''
            if type(clocks_info[key]) == list:
                output += OutputTemplates.catalog_elem_output.format(name=str(key), value="")
                for i in range(0, len(clocks_info[key])):
                    if type(clocks_info[key][i]) == dict:
                        for elem_key in clocks_info[key][i].keys():
                            output += OutputTemplates.catalog_elem_output_nested_level_1.format(name=str(elem_key), value=clocks_info[key][i][elem_key])
                    else:
                        output += OutputTemplates.catalog_elem_output_nested_level_1.format(name=str("->"), value=clocks_info[key][i])
            elif type(clocks_info[key]) == dict:
                output += OutputTemplates.catalog_elem_output.format(name=str(key), value="")
                if type(clocks_info[key]) == dict:
                    for elem_key in clocks_info[key].keys():
                            output += OutputTemplates.catalog_elem_output_nested_level_1.format(name=str(elem_key), value=clocks_info[key][elem_key])
                
            else:
                output += OutputTemplates.catalog_elem_output.format(name=str(key), value=clocks_info[key])
            '''
            if type(clocks_info[key]) == list:
                output += OutputTemplates.catalog_elem_output.format(name=str(key), value="")
                output = process_complex_query_output(clocks_info[key], output, nesting_level=6)
            elif type(clocks_info[key]) == dict:
                output += OutputTemplates.catalog_elem_output.format(name=str(key), value="")
                output = process_complex_query_output(clocks_info[key], output, nesting_level=6)
            else:
                output += OutputTemplates.catalog_elem_output.format(name=str(key), value=clocks_info[key])
        output += "\n"
        return output

    def add_memory_info_output(self, handle, output) -> str:
        memory_info: dict = self.commandObj.apiObject.get_device_memory_info(handle)
        for key in memory_info.keys():
            '''if type(memory_info[key]) == list:
                output += OutputTemplates.catalog_elem_output.format(name=str(key), value="")
                for i in range(0, len(memory_info[key])):
                    if type(memory_info[key][i]) == dict:
                        for elem_key in memory_info[key][i].keys():
                            output += OutputTemplates.catalog_elem_output_nested_level_1.format(name=str(elem_key), value=memory_info[key][i][elem_key])
                    else:
                        output += OutputTemplates.catalog_elem_output_nested_level_1.format(name=str("->"), value=memory_info[key][i])
            elif type(memory_info[key]) == dict:
                output += OutputTemplates.catalog_elem_output.format(name=str(key), value="")
                for elem_key in memory_info[key].keys():
                        output += OutputTemplates.catalog_elem_output_nested_level_1.format(name=str(elem_key), value=memory_info[key][elem_key])
            else:
                output += OutputTemplates.catalog_elem_output.format(name=str(key), value=memory_info[key])'''
            if type(memory_info[key]) == list:
                output += OutputTemplates.catalog_elem_output.format(name=str(key), value="")
                output = process_complex_query_output(memory_info[key], output, nesting_level=6)
            elif type(memory_info[key]) == dict:
                output += OutputTemplates.catalog_elem_output.format(name=str(key), value="")
                output = process_complex_query_output(memory_info[key], output, nesting_level=6)
            else:
                output += OutputTemplates.catalog_elem_output.format(name=str(key), value=memory_info[key])
        output += "\n"
        return output

    def add_bus_info_output(self, handle, output) -> str:
        bus_info: dict = self.commandObj.apiObject.get_device_bus_info(handle)
        for key in bus_info.keys():
            '''if type(bus_info[key]) == list:
                output += OutputTemplates.catalog_elem_output.format(name=str(key), value="")
                for i in range(0, len(bus_info[key])):
                    if type(bus_info[key][i]) == dict:
                        for elem_key in bus_info[key][i].keys():
                            output += OutputTemplates.catalog_elem_output_nested_level_1.format(name=str(elem_key), value=bus_info[key][i][elem_key])
                    else:
                        output += OutputTemplates.catalog_elem_output_nested_level_1.format(name=str("->"), value=bus_info[key][i])
            elif type(bus_info[key]) == dict:
                output += OutputTemplates.catalog_elem_output.format(name=str(key), value="")
                for elem_key in bus_info[key].keys():
                        output += OutputTemplates.catalog_elem_output_nested_level_1.format(name=str(elem_key), value=bus_info[key][elem_key])
            else:
                output += OutputTemplates.catalog_elem_output.format(name=str(key), value=bus_info[key])'''
            if type(bus_info[key]) == list:
                output += OutputTemplates.catalog_elem_output.format(name=str(key), value="")
                output = process_complex_query_output(bus_info[key], output, nesting_level=6)
            elif type(bus_info[key]) == dict:
                output += OutputTemplates.catalog_elem_output.format(name=str(key), value="")
                output = process_complex_query_output(bus_info[key], output, nesting_level=6)
            else:
                output += OutputTemplates.catalog_elem_output.format(name=str(key), value=bus_info[key])
        output += "\n"
        return output

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