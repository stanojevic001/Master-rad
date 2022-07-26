import os
from enum import Enum, IntEnum, auto
from platform import system as getOS
import subprocess


#--------SYSTEM ENUMS-------------------#
class SupportedOS(Enum):
    WINDOWS = 0
    LINUX = 1
    NOT_SUPPORTED = auto()

class SupportedGPU(Enum):
    AMD = 0
    NVIDIA = 1
    NOT_SUPPORTED = auto()
#--------SYSTEM CONSTANTS--------#
CURRENT_FILE_DIR = "{}".format(os.path.dirname(__file__))
CURRENT_OS = SupportedOS[getOS().upper()]
SUDO_ROOT_LINUX = "sudo su"
MAX_USER_INPUT_ATTEMPTS = 5

#---------STATUS CODES-----------#
class StatusCode(Enum):
    TOO_MANY_FAILED_ATTEMPTS = -1
    SUCCESS = 0
    API_FAILED = 1,
    INVALID_REQUEST =2,
    NOT_SUPPORTED_FEATURE =3

#--------COMMAND CONSTANTS-------#
INSTALL_NVML = "pip install pynvml"
#INSTALL_NVML = "pip install nvidia-ml-py"
INSTALL_IGNORE_OPTION_NVML = "pip install --ignore-installed nvidia-ml-py"
WINDOWS_GET_GPU_INFO = "wmic path win32_VideoController get name"
LINUX_GET_GPU_INFO = "lshw -numeric -C display | grep vendor"
WINDOWS_DOWNLOAD_ADL = 'Invoke-WebRequest -Uri https://github.com/GPUOpen-LibrariesAndSDKs/display-library/archive/refs/heads/master.zip -OutFile "master.zip"'
WINDOWS_DOWNLOAD_PYTHON = 'Invoke-WebRequest -Uri https://www.python.org/ftp/python/3.10.1/python-3.10.1-amd64.exe -OutFile "python.exe"'
CMAKE_INSTALL = 'Invoke-WebRequest -Uri https://github.com/Kitware/CMake/releases/download/v3.23.2/cmake-3.23.2-windows-x86_64.msi -OutFile "cmake_setup.msi"'
MINGW_INSTALL = 'Invoke-WebRequest -Uri https://downloads.sourceforge.net/project/mingw/Installer/mingw-get-setup.exe?ts=gAAAAABik91pKoDsyy3_e-DYwLM46kqJsnezAvdUydaht_8CLACuqvw0_m-qzSEsm5cTOaUJ0NtqLw9X0JlWX4WOn84hPJ1RIQ%3D%3D&r=https%3A%2F%2Fsourceforge.net%2Fprojects%2Fmingw%2Ffiles%2Flatest%2Fdownload -OutFile "mingw_setup.msi"'
PIP_NOT_INSTALLED = subprocess.getoutput("pip").upper().find("not recognized".upper()) != -1



