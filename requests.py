from common_api import StatusCode
from output_templates import *
from utils import process_complex_query_output

class Request():

    def __init__(self, command) -> None:
        self.commandObj = command
    
    def process_command_full(self, specific_device_index=None) -> str:
        output = ""
        device_count = self.commandObj.apiObject.get_number_of_devices()
        output += OutputTemplates.console_device_num.format(device_num=device_count)
        if specific_device_index is None:
            for i in range(0, device_count):
                handle = self.commandObj.apiObject.get_device_handle_by_index(i)
                output += OutputTemplates.console_device.format(index=i)

                name = self.commandObj.apiObject.get_device_name_by_handle(handle)
                if name is not None:
                    output += OutputTemplates.console_elem_output.format(name="Name", value=name, nesting=str(" "*2))

                result = self.add_catalog_info_output(handle, output)
                if result == "Not supported":
                    pass
                else:
                    output = result

                result = self.add_versions_info_output(handle, output)
                if result == "Not supported":
                    pass
                else:
                    output = result

                result = self.add_bus_info_output(handle, output)
                if result == "Not supported":
                    pass
                else:
                    output = result

                result = self.add_memory_info_output(handle, output)
                if result == "Not supported":
                    pass
                else:
                    output = result

                result = self.add_clocks_info_output(handle, output)
                if result == "Not supported":
                    pass
                else:
                    output = result

                result = self.add_temperature_info_output(handle, output)
                if result == "Not supported":
                    pass
                else:
                    output = result
        else:
            ind = specific_device_index
            if (ind < 0) or (ind >= device_count):
                print("Invalid gpu index {gpu} sent. Range for valid gpu indexes are from [0, number of devices - 1] \
                                                    (number of devices = {count}).".format(gpu=ind, count=device_count))
                return ""
            handle = self.commandObj.apiObject.get_device_handle_by_index(ind)
            output += OutputTemplates.console_device.format(index=ind)

            name = self.commandObj.apiObject.get_device_name_by_handle(handle)
            if name is not None:
                output += OutputTemplates.console_elem_output.format(name="Name", value=name, nesting=str(" "*2))

            result = self.add_catalog_info_output(handle, output)
            if result == "Not supported":
                pass
            else:
                output = result

            result = self.add_versions_info_output(handle, output)
            if result == "Not supported":
                pass
            else:
                output = result

            result = self.add_bus_info_output(handle, output)
            if result == "Not supported":
                pass
            else:
                output = result

            result = self.add_memory_info_output(handle, output)
            if result == "Not supported":
                pass
            else:
                output = result

            result = self.add_clocks_info_output(handle, output)
            if result == "Not supported":
                pass
            else:
                output = result

            result = self.add_temperature_info_output(handle, output)
            if result == "Not supported":
                pass
            else:
                output = result

        return output

    def process_command_versions(self, specific_device_index=None) -> str:
        output = ""
        device_count = self.commandObj.apiObject.get_number_of_devices()
        output += OutputTemplates.console_device_num.format(device_num=device_count)
        if specific_device_index is None:
            for i in range(0, device_count):
                handle = self.commandObj.apiObject.get_device_handle_by_index(i)
                output += OutputTemplates.console_device.format(index=i)

                name = self.commandObj.apiObject.get_device_name_by_handle(handle)
                if name is not None:
                    output += OutputTemplates.console_elem_output.format(name="Name", value=name, nesting=str(" "*2))        
                
                result = self.add_versions_info_output(handle, output)
                if result == "Not supported":
                    output += OutputTemplates.console_elem_output.format(name="Versions info", value="Not supported", nesting=str(" "*2))
                else:
                    output = result
        else:
            ind = specific_device_index
            if (ind < 0) or (ind >= device_count):
                print("Invalid gpu index {gpu} sent. Range for valid gpu indexes are from [0, number of devices - 1] \
                                                    (number of devices = {count}).".format(gpu=ind, count=device_count))
                return ""
            handle = self.commandObj.apiObject.get_device_handle_by_index(ind)
            output += OutputTemplates.console_device.format(index = ind)

            name = self.commandObj.apiObject.get_device_name_by_handle(handle)
            if name is not None:
                output += OutputTemplates.console_elem_output.format(name="Name", value=name, nesting=str(" "*2)) 

            result = self.add_versions_info_output(handle, output)
            if result == "Not supported":
                output += OutputTemplates.console_elem_output.format(name="Versions info", value="Not supported", nesting=str(" "*2))
            else:
                output = result
        return output
    
    def process_command_catalog(self, specific_device_index=None) -> str:
        output = ""
        device_count = self.commandObj.apiObject.get_number_of_devices()
        output += OutputTemplates.console_device_num.format(device_num=device_count)
        if specific_device_index is None:
            for i in range(0, device_count):
                handle = self.commandObj.apiObject.get_device_handle_by_index(i)
                output += OutputTemplates.console_device.format(index=i)

                name = self.commandObj.apiObject.get_device_name_by_handle(handle)
                if name is not None:
                    output += OutputTemplates.console_elem_output.format(name="Name", value=name, nesting=str(" "*2))        
                
                result = self.add_catalog_info_output(handle, output)
                if result == "Not supported":
                    output += OutputTemplates.console_elem_output.format(name="Catalog info", value="Not supported", nesting=str(" "*2))
                else:
                    output = result
        else:
            ind = specific_device_index
            if (ind < 0) or (ind >= device_count):
                print("Invalid gpu index {gpu} sent. Range for valid gpu indexes are from [0, number of devices - 1] \
                                                    (number of devices = {count}).".format(gpu=ind, count=device_count))
                return ""
            handle = self.commandObj.apiObject.get_device_handle_by_index(ind)
            output += OutputTemplates.console_device.format(index = ind)

            name = self.commandObj.apiObject.get_device_name_by_handle(handle)
            if name is not None:
                output += OutputTemplates.console_elem_output.format(name="Name", value=name, nesting=str(" "*2)) 

            result = self.add_catalog_info_output(handle, output)
            if result == "Not supported":
                output += OutputTemplates.console_elem_output.format(name="Catalog info", value="Not supported", nesting=str(" "*2))
            else:
                output = result
        return output
    
    def process_command_temperature(self, specific_device_index=None) -> str:
        output = ""
        device_count = self.commandObj.apiObject.get_number_of_devices()
        output += OutputTemplates.console_device_num.format(device_num=device_count)
        if specific_device_index is None:
            for i in range(0, device_count):
                handle = self.commandObj.apiObject.get_device_handle_by_index(i)
                output += OutputTemplates.console_device.format(index=i)

                name = self.commandObj.apiObject.get_device_name_by_handle(handle)
                if name is not None:
                    output += OutputTemplates.console_elem_output.format(name="Name", value=name, nesting=str(" "*2))

                result = self.add_temperature_info_output(handle, output) 
                if result == "Not supported":
                    output += OutputTemplates.console_elem_output.format(name="Temperature info", value="Not supported", nesting=str(" "*2))
                else:
                    output = result
        else:
            ind = specific_device_index
            if (ind < 0) or (ind >= device_count):
                print("Invalid gpu index {gpu} sent. Range for valid gpu indexes are from [0, number of devices - 1] (number of devices = {count}).".format(gpu=ind, count=device_count))
                return ""
            handle = self.commandObj.apiObject.get_device_handle_by_index(ind)
            output += OutputTemplates.console_device.format(index = ind)

            name = self.commandObj.apiObject.get_device_name_by_handle(handle)
            if name is not None:
                output += OutputTemplates.console_elem_output.format(name="Name", value=name, nesting=str(" "*2)) 

            result = self.add_temperature_info_output(handle, output)
            if result == "Not supported":
                output += OutputTemplates.console_elem_output.format(name="Temperature info", value="Not supported", nesting=str(" "*2))
            else:
                output = result
        return output

    def process_command_clocks(self, specific_device_index=None) -> str:
        output = ""
        device_count = self.commandObj.apiObject.get_number_of_devices()
        output += OutputTemplates.console_device_num.format(device_num=device_count)
        if specific_device_index is None:
            for i in range(0, device_count):
                handle = self.commandObj.apiObject.get_device_handle_by_index(i)
                output += OutputTemplates.console_device.format(index=i)

                name = self.commandObj.apiObject.get_device_name_by_handle(handle)
                if name is not None:
                    output += OutputTemplates.console_elem_output.format(name="Name", value=name, nesting=str(" "*2))        
                
                result = self.add_clocks_info_output(handle, output)
                if result == "Not supported":
                    output += OutputTemplates.console_elem_output.format(name="Clocks info", value="Not supported", nesting=str(" "*2))
                else:
                    output = result
        else:
            ind = specific_device_index
            if (ind < 0) or (ind >= device_count):
                print("Invalid gpu index {gpu} sent. Range for valid gpu indexes are from [0, number of devices - 1] (number of devices = {count}).".format(gpu=ind, count=device_count))
                return ""
            handle = self.commandObj.apiObject.get_device_handle_by_index(ind)
            output += OutputTemplates.console_device.format(index = ind)

            name = self.commandObj.apiObject.get_device_name_by_handle(handle)
            if name is not None:
                output += OutputTemplates.console_elem_output.format(name="Name", value=name, nesting=str(" "*2)) 

            result = self.add_clocks_info_output(handle, output)
            if result == "Not supported":
                output += OutputTemplates.console_elem_output.format(name="Clocks info", value="Not supported", nesting=str(" "*2))
            else:
                output = result
        return output
    
    def process_command_memory(self, specific_device_index=None) -> str:
        output = ""
        device_count = self.commandObj.apiObject.get_number_of_devices()
        output += OutputTemplates.console_device_num.format(device_num=device_count)
        if specific_device_index is None:
            for i in range(0, device_count):
                handle = self.commandObj.apiObject.get_device_handle_by_index(i)
                output += OutputTemplates.console_device.format(index=i)

                name = self.commandObj.apiObject.get_device_name_by_handle(handle)
                if name is not None:
                    output += OutputTemplates.console_elem_output.format(name="Name", value=name, nesting=str(" "*2))        

                result = self.add_memory_info_output(handle, output)
                if result == "Not supported":
                    output += OutputTemplates.console_elem_output.format(name="Memory info", value="Not supported", nesting=str(" "*2))
                else:
                    output = result
        else:
            ind = specific_device_index
            if (ind < 0) or (ind >= device_count):
                print("Invalid gpu index {gpu} sent. Range for valid gpu indexes are from [0, number of devices - 1] (number of devices = {count}).".format(gpu=ind, count=device_count))
                return ""
            handle = self.commandObj.apiObject.get_device_handle_by_index(ind)
            output += OutputTemplates.console_device.format(index = ind)

            name = self.commandObj.apiObject.get_device_name_by_handle(handle)
            if name is not None:
                output += OutputTemplates.console_elem_output.format(name="Name", value=name, nesting=str(" "*2)) 

            result = self.add_memory_info_output(handle, output)
            if result == "Not supported":
                output += OutputTemplates.console_elem_output.format(name="Memory info", value="Not supported", nesting=str(" "*2))
            else:
                output = result
        return output

    def process_command_bus(self, specific_device_index=None) -> str:
        output = ""
        device_count = self.commandObj.apiObject.get_number_of_devices()
        output += OutputTemplates.console_device_num.format(device_num=device_count)
        if specific_device_index is None:
            for i in range(0, device_count):
                handle = self.commandObj.apiObject.get_device_handle_by_index(i)
                output += OutputTemplates.console_device.format(index=i)

                name = self.commandObj.apiObject.get_device_name_by_handle(handle)
                if name is not None:
                    output += OutputTemplates.console_elem_output.format(name="Name", value=name, nesting=str(" "*2)) 
    
                result = self.add_bus_info_output(handle, output)
                if result == "Not supported":
                    output += OutputTemplates.console_elem_output.format(name="Bus info", value="Not supported", nesting=str(" "*2))
                else:
                    output = result
        else:
            ind = specific_device_index
            if (ind < 0) or (ind >= device_count):
                print("Invalid gpu index {gpu} sent. Range for valid gpu indexes are from [0, number of devices - 1] (number of devices = {count}).".format(gpu=ind, count=device_count))
                return ""
            handle = self.commandObj.apiObject.get_device_handle_by_index(ind)
            output += OutputTemplates.console_device.format(index = ind)

            name = self.commandObj.apiObject.get_device_name_by_handle(handle)
            if name is not None:
                output += OutputTemplates.console_elem_output.format(name="Name", value=name, nesting=str(" "*2)) 

            result = self.add_bus_info_output(handle, output)
            if result == "Not supported":
                output += OutputTemplates.console_elem_output.format(name="Bus info", value="Not supported", nesting=str(" "*2))
            else:
                output = result

        return output

    def process_command_performance(self, specific_device_index=None) -> str:
        pass

    def process_command_modes(self, specific_device_index=None) -> str:
        pass
    
    def process_command_help(self, specific_device_index=None) -> str:
        output = ""
        output += OutputTemplates.console_help_command_output
        return output
    
    def process_command_processes(self, specific_device_index=None) -> str:
        pass


    def add_versions_info_output(self, handle, output) -> str:
        versions_info: dict = self.commandObj.apiObject.get_device_versions_info(handle)
        if versions_info == "Not supported":
            return "Not supported"
        output += OutputTemplates.console_elem_output.format(name="Versions info", value="", nesting=str(" "*2))
        for key in versions_info.keys():
            if type(versions_info[key]) == list:
                output += OutputTemplates.console_elem_output.format(name=str(key), value="", nesting=str(" "*4))
                output = process_complex_query_output(versions_info[key], output, nesting_level=6)
            elif type(versions_info[key]) == dict:
                output += OutputTemplates.console_elem_output.format(name=str(key), value="", nesting=str(" "*4))
                output = process_complex_query_output(versions_info[key], output, nesting_level=6)
            else:
                output += OutputTemplates.console_elem_output.format(name=str(key), value=versions_info[key], nesting=str(" "*4))
        output += "\n"
        return output

    def add_catalog_info_output(self, handle, output) -> str:
        catalog_info: dict = self.commandObj.apiObject.get_device_catalog_info(handle)
        if catalog_info == "Not supported":
            return "Not supported"
        output += OutputTemplates.console_elem_output.format(name="Catalog info", value="", nesting=str(" "*2))
        for key in catalog_info.keys():
            if type(catalog_info[key]) == list:
                output += OutputTemplates.console_elem_output.format(name=str(key), value="", nesting=str(" "*4))
                output = process_complex_query_output(catalog_info[key], output, nesting_level=6)
            elif type(catalog_info[key]) == dict:
                output += OutputTemplates.console_elem_output.format(name=str(key), value="", nesting=str(" "*4))
                output = process_complex_query_output(catalog_info[key], output, nesting_level=6)
            else:
                output += OutputTemplates.console_elem_output.format(name=str(key), value=catalog_info[key], nesting=str(" "*4))
        output += "\n"
        return output

    def add_temperature_info_output(self, handle, output) -> str:
        temperature_info = self.commandObj.apiObject.get_device_temperature_info(handle)
        if temperature_info == "Not supported":
            return "Not supported"
        output += OutputTemplates.console_elem_output.format(name="Temperature info", value="", nesting=str(" "*2))
        for key in temperature_info.keys():
            if type(temperature_info[key]) == list:
                output += OutputTemplates.console_elem_output.format(name=str(key), value="", nesting=str(" "*4))
                output = process_complex_query_output(temperature_info[key], output, nesting_level=6)
            elif type(temperature_info[key]) == dict:
                output += OutputTemplates.console_elem_output.format(name=str(key), value="", nesting=str(" "*4))
                output = process_complex_query_output(temperature_info[key], output, nesting_level=6)
            else:
                output += OutputTemplates.console_elem_output.format(name=str(key), value=temperature_info[key], nesting=str(" "*4))
        output += "\n"
        return output

    def add_clocks_info_output(self, handle, output) -> str:
        clocks_info: dict = self.commandObj.apiObject.get_device_clocks_info(handle)
        if clocks_info == "Not supported":
            return "Not supported"
        output += OutputTemplates.console_elem_output.format(name="Clocks info", value="", nesting=str(" "*2))
        for key in clocks_info.keys():
            if type(clocks_info[key]) == list:
                output += OutputTemplates.console_elem_output.format(name=str(key), value="", nesting=str(" "*4))
                output = process_complex_query_output(clocks_info[key], output, nesting_level=6)
            elif type(clocks_info[key]) == dict:
                output += OutputTemplates.console_elem_output.format(name=str(key), value="", nesting=str(" "*4))
                output = process_complex_query_output(clocks_info[key], output, nesting_level=6)
            else:
                output += OutputTemplates.console_elem_output.format(name=str(key), value=clocks_info[key], nesting=str(" "*4))
        output += "\n"
        return output

    def add_memory_info_output(self, handle, output) -> str:
        memory_info: dict = self.commandObj.apiObject.get_device_memory_info(handle)
        if memory_info == "Not supported":
            return "Not supported"
        output += OutputTemplates.console_elem_output.format(name="Memory info", value="", nesting=str(" "*2))
        for key in memory_info.keys():
            if type(memory_info[key]) == list:
                output += OutputTemplates.console_elem_output.format(name=str(key), value="", nesting=str(" "*4))
                output = process_complex_query_output(memory_info[key], output, nesting_level=6)
            elif type(memory_info[key]) == dict:
                output += OutputTemplates.console_elem_output.format(name=str(key), value="", nesting=str(" "*4))
                output = process_complex_query_output(memory_info[key], output, nesting_level=6)
            else:
                output += OutputTemplates.console_elem_output.format(name=str(key), value=memory_info[key], nesting=str(" "*4))
        output += "\n"
        return output

    def add_bus_info_output(self, handle, output) -> str:
        bus_info: dict = self.commandObj.apiObject.get_device_bus_info(handle)
        if bus_info == "Not supported":
            return "Not supported"
        output += OutputTemplates.console_elem_output.format(name="Bus info", value="", nesting=str(" "*2))
        for key in bus_info.keys():
            if type(bus_info[key]) == list:
                output += OutputTemplates.console_elem_output.format(name=str(key), value="", nesting=str(" "*4))
                output = process_complex_query_output(bus_info[key], output, nesting_level=6)
            elif type(bus_info[key]) == dict:
                output += OutputTemplates.console_elem_output.format(name=str(key), value="", nesting=str(" "*4))
                output = process_complex_query_output(bus_info[key], output, nesting_level=6)
            else:
                output += OutputTemplates.console_elem_output.format(name=str(key), value=bus_info[key], nesting=str(" "*4))
        output += "\n"
        return output

    def process_request(self) -> StatusCode:
        try:
            called_device_index = None
            self.commandObj.apiObject.initialize()
            if (self.commandObj.called_gpu_index is not None) and \
                str(self.commandObj.called_gpu_index) != "All devices":
                called_device_index = self.commandObj.called_gpu_index
            if self.commandObj.called_command_name == "full":
                print(self.process_command_full(called_device_index))
            elif self.commandObj.called_command_name == "versions":
                print(self.process_command_versions(called_device_index))
            elif self.commandObj.called_command_name == "catalog":
                print(self.process_command_catalog(called_device_index))
            elif self.commandObj.called_command_name == "temperature":
                print(self.process_command_temperature(called_device_index))
            elif self.commandObj.called_command_name == "clocks":
                print(self.process_command_clocks(called_device_index))
            elif self.commandObj.called_command_name == "help":
                print(self.process_command_help(called_device_index))
            elif self.commandObj.called_command_name == "memory":
                print(self.process_command_memory(called_device_index))
            elif self.commandObj.called_command_name == "bus":
                print(self.process_command_bus(called_device_index))
            else:
                print("Invalid command '{}' invoked. Try command 'help' for \
                    futher information.".format(self.commandObj.called_command_name))
                return StatusCode.INVALID_REQUEST

            return StatusCode.SUCCESS
        except Exception as e:
            print(e)
            return StatusCode.API_FAILED
        finally:
            self.commandObj.apiObject.finish()
