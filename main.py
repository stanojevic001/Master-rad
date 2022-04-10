from pathlib import Path
import subprocess
from defines import *
from command_object import *
from utils import get_current_GPU_names
import sys
from requests import Request


if __name__ == '__main__':
    try:
        """
        NVML_LIB = subprocess.getoutput("pip list")
        NVML_EXISTS = NVML_LIB.find("nvidia-ml-py") != -1
        if PIP_NOT_INSTALLED:
            raise Exception("Error: Before running the tool, run the setup with command from this directory: 'python setup.py'")
        if CURRENT_OS == SupportedOS.NOT_SUPPORTED:
            raise Exception("Error: This tool is not currently supported on %s operating system." % CURRENT_OS.name)

        elif CURRENT_OS == SupportedOS.WINDOWS:
            ADL_WIN_LIB = Path("{}\\display-library-master".format(CURRENT_FILE_DIR).strip())
            if (SupportedGPU.AMD in get_current_GPU_names()) and (ADL_WIN_LIB.exists() is False):
                raise Exception("Before running the tool, run the setup with command from this directory: 'python setup.py'")
            elif SupportedGPU.NVIDIA in get_current_GPU_names() and NVML_EXISTS is False:
                raise Exception("Before running the tool, run the setup with command from this directory: 'python setup.py'")
            
        elif CURRENT_OS == SupportedOS.LINUX:
            ROCM_LINUX_LIB = Path("{}\\rocmsmi-library-master".format(CURRENT_FILE_DIR).strip())
            if SupportedGPU.AMD in get_current_GPU_names() and ROCM_LINUX_LIB.exists() is False:
                raise Exception("Before running the tool, run the setup with command from this directory: 'python setup.py'")
            elif SupportedGPU.NVIDIA in get_current_GPU_names() and NVML_EXISTS is False:
                raise Exception("Before running the tool, run the setup with command from this directory: 'python setup.py'")
        """
        commandObj = CommandObject(sys.argv)
        result = commandObj.prepare_command_object()

        if result != StatusCode.SUCCESS:
            print("Failed! User had too many failed input attempts!")

        request = Request(commandObj)
        result = request.process_request()

        if result != StatusCode.SUCCESS:
            print("Failed! User had too many failed input attempts!")

        print("\n*** SUCCESS ***\n")

    except Exception as e:
        raise(e)