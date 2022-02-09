from defines import *
from os import system as runCmd
import subprocess


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

