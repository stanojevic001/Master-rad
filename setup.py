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
        runCmd("sudo apt-get update -y && sudo apt-get upgrade -y")
        runCmd("sudo apt install -y python-pip")
        runCmd("sudo apt install -y python3-pip")
        runCmd("sudo python3 -m pip install invoke")
        runCmd("sudo python -m pip install invoke")
        runCmd("sudo apt-get -y install cmake")
        runCmd("sudo apt-get update -y && sudo apt-get install -y gcc")
        runCmd("sudo apt-get update -y && sudo apt-get install -y g++")
        runCmd("sudo apt install -y doxygen")
        runCmd("sudo apt install -y texlive-latex-base")
        runCmd("sudo apt install -y texlive-latex-extra")
        runCmd("sudo pip3 install -y cython")

        current_GPUs = get_current_GPU_names()

        if current_GPUs == None or len(current_GPUs) == 0:
            raise Exception("Error: This tool currently supports only NVIDIA and AMD graphics cards!")

        if SupportedGPU.NVIDIA in current_GPUs:
            print("Installing Nvidia NVML library...")
            runCmd(INSTALL_NVML)
        if SupportedGPU.AMD in current_GPUs:
            print("Installing AMD ROCm library...")
            runCmd("sudo rm -r rocm_smi_lib-master")
            runCmd("sudo rm rocmsmi.zip")
            runCmd("sudo apt-get install wget -y")
            runCmd("sudo wget https://github.com/RadeonOpenCompute/rocm_smi_lib/archive/refs/heads/master.zip -O rocmsmi.zip")
            runCmd("sudo apt install unzip -y")
            runCmd("sudo unzip \"{}/rocmsmi.zip\"".format(CURRENT_FILE_DIR))
            runCmd("sudo find . -type f -exec dos2unix {} \;")
            runCmd("sudo sh linux_rocm.sh")
            runCmd("sudo chmod -R 777 ../")
            runCmd("sudo rm rocmsmi.zip")
            runCmd("sudo rm rocm_out*")
            runCmd("sudo gcc -fPIC -shared -o  rocm_out.so linux_amd_impl.c")
            print("Finished installing AMD ROCm library!")

        if (SupportedGPU.NVIDIA not in current_GPUs) and (SupportedGPU.AMD not in current_GPUs):
            raise Exception("Error: This tool currently supports only NVIDIA and AMD graphics cards!")

    except Exception as e:
        raise(e)

else:
    raise Exception("Error: This tool is not currently supported on %s operating system." % CURRENT_OS.name)