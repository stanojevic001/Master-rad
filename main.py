from pathlib import Path
import subprocess
from defines import *
from process_request import *
from utils import get_current_GPU_names
import sys


if __name__ == '__main__':
    try:
        ADL_WIN_LIB = Path("{}\\display-library-master".format(CURRENT_FILE_DIR).strip())
        ROCM_LINUX_LIB = Path("{}\\rocmsmi-library-master".format(CURRENT_FILE_DIR).strip())
        NVML_LIB = subprocess.getoutput("pip freeze")
        NVML_EXISTS = NVML_LIB.find("nvidia-ml-py") != -1

        if PIP_NOT_INSTALLED:
            raise Exception("Error: Before running the tool, run the setup with command from this directory: 'python setup.py'")
        if CURRENT_OS == SupportedOS.NOT_SUPPORTED:
            raise Exception("Error: This tool is not currently supported on %s operating system." % CURRENT_OS.name)

        elif CURRENT_OS == SupportedOS.WINDOWS:
            if (SupportedGPU.AMD in get_current_GPU_names()) and (ADL_WIN_LIB.exists() is False):
                raise Exception("Before running the tool, run the setup with command from this directory: 'python setup.py'")
            elif SupportedGPU.NVIDIA in get_current_GPU_names() and NVML_EXISTS is False:
                raise Exception("Before running the tool, run the setup with command from this directory: 'python setup.py'")
            
        elif CURRENT_OS == SupportedOS.LINUX:
            if SupportedGPU.AMD in get_current_GPU_names() and ROCM_LINUX_LIB.exists() is False:
                raise Exception("Before running the tool, run the setup with command from this directory: 'python setup.py'")
            elif SupportedGPU.NVIDIA in get_current_GPU_names() and NVML_EXISTS is False:
                raise Exception("Before running the tool, run the setup with command from this directory: 'python setup.py'")

        request = Request(sys.argv)
        result = request.process_request()

        if result == StatusCode.SUCCESS:
            print("Operation executed successfully!")
        elif result == StatusCode.TOO_MANY_FAILED_ATTEMPTS:
            print("Failed! User had too many failed input attempts!")

    except Exception as e:
        raise(e)