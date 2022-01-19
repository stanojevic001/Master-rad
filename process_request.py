from os import umask
from defines import CURRENT_OS, SupportedGPU, SupportedOS, StatusCode, MAX_USER_INPUT_ATTEMPTS
from utils import get_current_GPU_names
from common_api import CommonAPI
from windows_linux_nvidia_impl import WindowsLinux_NVIDIA_API
from linux_amd_impl import LinuxAMD_API
from windows_amd_wrapper import WindowsAMD_API

class Request():
    current_os = CURRENT_OS
    current_GPUs = get_current_GPU_names()
    calling_args = list[str]
    apiObject = CommonAPI()

    def __init__(self, args) -> None:
        self.calling_args = args
    
    def process_request(self) -> StatusCode:

        if (SupportedGPU.NVIDIA in self.current_GPUs) and (SupportedGPU.AMD in self.current_GPUs):
            
            counter = MAX_USER_INPUT_ATTEMPTS
            while (counter > 0):
                choice = input("There are both NVIDIA and AMD graphics cards on the sytem.\n  \
                        For which one would you like to get information for? Type A or N (A=AMD, N=NVIDIA):\n")

                if choice.upper() == "A":
                    # AMD 
                    if self.current_os == SupportedOS.WINDOWS:
                        # Windows
                        self.apiObject = WindowsAMD_API()
                        break
                    elif self.current_os == SupportedOS.LINUX:
                        # Linux
                        self.apiObject = LinuxAMD_API()
                        break

                elif choice.upper() == "N":
                    # NVIDIA
                    self.apiObject = WindowsLinux_NVIDIA_API()
                    break
                else:
                    counter -= 1
                    print("Invalid choice. Try again ({} times remaining).".format(counter))

            if (counter == 0): return StatusCode.TOO_MANY_FAILED_ATTEMPTS

        elif SupportedGPU.NVIDIA in self.current_GPUs:
            # Windows and Linux NVIDIA
            self.apiObject = WindowsLinux_NVIDIA_API()

        elif SupportedGPU.AMD in self.current_GPUs:
            # AMD
            if self.current_os == SupportedOS.WINDOWS:
                # Windows
                self.apiObject = WindowsAMD_API()
            elif self.current_os == SupportedOS.LINUX:
                # Linux
                self.apiObject = LinuxAMD_API()


        self.apiObject.initialize()
        
        # Process given arguments

        # Define what functions to call from the common api


        self.apiObject.finish()

        return StatusCode.SUCCESS
