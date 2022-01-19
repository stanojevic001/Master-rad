from os import system as runCmd
import subprocess
from defines import *
from utils import get_current_GPU_names

current_GPUs = None

if CURRENT_OS == SupportedOS.WINDOWS:
    print("Setting up on Windows...")
    try:
        runCmd("python -m ensurepip --upgrade")
        runCmd("python -m pip install --upgrade pip")
        runCmd("python -m pip install invoke")
        runCmd("python3 -m pip install invoke")

        current_GPUs = get_current_GPU_names()

        if current_GPUs == None or len(current_GPUs) == 0:
            raise Exception("Error: This tool currently supports only NVIDIA and AMD graphics cards!")

        if SupportedGPU.NVIDIA in current_GPUs:
            print("Installing Nvidia NVML library...")
            runCmd(INSTALL_NVML)
        if SupportedGPU.AMD in current_GPUs:
            print("Installing AMD ADL Display library...")
            runCmd("rmdir /Q /S \"{}\display-library-master\" > nul".format(CURRENT_FILE_DIR))
            runCmd("del /f \"{}\master.zip\" > nul".format(CURRENT_FILE_DIR))
            subprocess.run(["powershell", "-Command", WINDOWS_DOWNLOAD_ADL])
            COPY_COMMAND = "move .\master.zip \"{}\"".format(CURRENT_FILE_DIR)
            subprocess.run(["powershell", "-Command", COPY_COMMAND]) 
            subprocess.run(["powershell", "-Command", "tar -xf \"{}\master.zip\"".format(CURRENT_FILE_DIR)])
            runCmd("del /f \"{}\master.zip\" > nul".format(CURRENT_FILE_DIR))
            print("Finished loading AMD ADL Display library!")

        if (SupportedGPU.NVIDIA not in current_GPUs) and (SupportedGPU.AMD not in current_GPUs):
            raise Exception("Error: This tool currently supports only NVIDIA and AMD graphics cards!")

    except Exception as e:
        raise(e)


elif CURRENT_OS == SupportedOS.LINUX:
    print("Setting up on Linux...")
    try:
        print("Enter root password:")
        runCmd(SUDO_ROOT_LINUX)
        runCmd("apt install python-pip")
        runCmd("apt install python3-pip")
        runCmd("python3 -m pip install invoke")
        runCmd("python -m pip install invoke")

        current_GPUs = get_current_GPU_names()

        if current_GPUs == None or len(current_GPUs) == 0:
            raise Exception("Error: This tool currently supports only NVIDIA and AMD graphics cards!")

        if SupportedGPU.NVIDIA in current_GPUs:
            print("Installing Nvidia NVML library...")
            runCmd(INSTALL_NVML)
        if SupportedGPU.AMD in current_GPUs:
            print("Installing AMD ROCm library...")
            runCmd("apt-get install wget -y")
            runCmd("cd \"{}\"".format(CURRENT_FILE_DIR))
            runCmd("wget https://github.com/RadeonOpenCompute/rocm_smi_lib/archive/refs/heads/master.zip -O rocmsmi.zip")
            runCmd("apt install unzip -y")
            runCmd("unzip \"{}/rocmsmi.zip\"".format(CURRENT_FILE_DIR))
            runCmd("Finished installing AMD ROCm library!")

        if (SupportedGPU.NVIDIA not in current_GPUs) and (SupportedGPU.AMD not in current_GPUs):
            raise Exception("Error: This tool currently supports only NVIDIA and AMD graphics cards!")

    except Exception as e:
        raise(e)

else:
    raise Exception("Error: This tool is not currently supported on %s operating system." % CURRENT_OS.name)