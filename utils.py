from defines import *
from os import system as runCmd
import subprocess

from output_templates import OutputTemplates
from datetime import datetime

def get_current_GPU_names():
    try:
        current_GPUs = list()
        if CURRENT_OS == SupportedOS.WINDOWS:
            result = subprocess.getoutput(WINDOWS_GET_GPU_INFO)
        elif CURRENT_OS == SupportedOS.LINUX:
            result = subprocess.getoutput(LINUX_GET_GPU_INFO)
        else:
            raise Exception("Error: Only NVIDIA and AMD are currently supported GPUs for the tool!")
        if result.find("AMD") != -1:
            current_GPUs.append(SupportedGPU.AMD)
        elif result.find("NVIDIA") != -1:
            current_GPUs.append(SupportedGPU.NVIDIA)

        return current_GPUs

    except Exception as e:
        raise(e)

def bytes_to_megabytes(bytes):
    return round(float(bytes)/pow(pow(2, 10), 2), 2)

def bytes_to_gigabytes(bytes):
    return round(float(bytes)/pow(pow(2, 10), 3), 2)

def hz_to_gigahz_int(hz):
    return round(float(hz)/pow(10, 9), 2)

def process_complex_query_output(object, output, nesting_level=4):
    if type(object) == dict:
        for key in object.keys():
            if type(object[key]) not in (dict, list):
                output += OutputTemplates.catalog_complex_elem_variable_nesting.format(nesting=str(" " * nesting_level), name = str(key), value=object[key])
            else:
                output += OutputTemplates.catalog_complex_elem_variable_nesting.format(nesting=str(" " * nesting_level), name=str(key), value="")
                output = process_complex_query_output(object[key], output, nesting_level+4)
    elif type(object) == list:
        if len(object) > 0 and (type(object[0]) not in (dict, list)):
                output += OutputTemplates.catalog_simple_elem_variable_nesting.format(nesting=str(" " * nesting_level), value=object)
        else:
            for i in range(0, len(object)):
                #output += OutputTemplates.catalog_elem_output.format(nesting = str(" " * nesting_level), name = str("No. ") + str(i) , value = "")
                output = process_complex_query_output(object[i], output, nesting_level+2)
        '''
        for i in range(0, len(object)):
            output = process_complex_query_output(object[i], output, nesting_level)
        '''
    else:
        output += OutputTemplates.catalog_simple_elem_variable_nesting.format(nesting=str(" " * nesting_level), value=object)
    
    return output
