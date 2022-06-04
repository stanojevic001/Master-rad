from os import system as runCmd
from defines import *
from utils import get_current_GPU_names

current_GPUs = None

if CURRENT_OS == SupportedOS.WINDOWS:
    print("Setting up on Windows...")
    try:
        runCmd("python -m ensurepip --upgrade")
        runCmd("python -m pip install --upgrade pip")
        runCmd(".\\amd_package\\windows\\unix2dos\\bin\\unix2dos.exe * .\\amd_package\\windows\\* .\\amd_package\\windows\\unix2dos\\bin\\*")

        current_GPUs = get_current_GPU_names()

        if current_GPUs == None or len(current_GPUs) == 0:
            raise Exception("Error: This tool currently supports only NVIDIA and AMD graphics cards!")

        if SupportedGPU.NVIDIA in current_GPUs:
            print("Installing Nvidia NVML library...")
            runCmd(INSTALL_NVML)
            print("Finished loading NVML library!")
        if SupportedGPU.AMD in current_GPUs:
            print("Installing AMD ADL Display library...")
            print("Finished loading AMD ADL Display library!")

        if (SupportedGPU.NVIDIA not in current_GPUs) and (SupportedGPU.AMD not in current_GPUs):
            raise Exception("Error: This tool currently supports only NVIDIA and AMD graphics cards!")

    except Exception as e:
        raise(e)


elif CURRENT_OS == SupportedOS.LINUX:
    print("Setting up on Linux...")
    try:
        runCmd("sudo apt-get update -y && sudo apt-get upgrade -y")
        runCmd("sudo apt install -y python-pip")
        runCmd("sudo apt install -y python3-pip")
        runCmd("sudo apt-get update -y && sudo apt-get install -y gcc")
        runCmd("sudo apt-get update -y && sudo apt-get install -y g++")
        runCmd("sudo apt install dos2unix")
        runCmd("find . -type f -print0 | xargs -0 dos2unix")
        current_GPUs = get_current_GPU_names()

        if current_GPUs == None or len(current_GPUs) == 0:
            raise Exception("Error: This tool currently supports only NVIDIA and AMD graphics cards!")

        if SupportedGPU.NVIDIA in current_GPUs:
            print("Installing Nvidia NVML library...")
            runCmd(INSTALL_NVML)
            print("Finished loading NVML library!")
        if SupportedGPU.AMD in current_GPUs:
            print("Installing AMD ROCm library...")
            print("Finished installing AMD ROCm library!")

        if (SupportedGPU.NVIDIA not in current_GPUs) and (SupportedGPU.AMD not in current_GPUs):
            raise Exception("Error: This tool currently supports only NVIDIA and AMD graphics cards!")

    except Exception as e:
        raise(e)

else:
    raise Exception("Error: This tool is not currently supported on %s operating system." % CURRENT_OS.name)