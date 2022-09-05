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
CURRENT_OS = SupportedOS[getOS().upper()]
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
WINDOWS_GET_GPU_INFO = "wmic path win32_VideoController \
                        get adaptercompatibility"
LINUX_GET_GPU_INFO = "lshw -numeric -C display | grep vendor"



