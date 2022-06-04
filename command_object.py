from email.policy import default
from defines import CURRENT_OS, SupportedGPU, SupportedOS, StatusCode, MAX_USER_INPUT_ATTEMPTS
from utils import get_current_GPU_names
from common_api import CommonAPI
from windows_linux_nvidia_impl import WindowsLinux_NVIDIA_API
from linux_rocm_smi_api import Linux_ROCm_SMI_Wrapper
from windows_amd_api import WindowsAMD_API
from output_templates import *

class CommandObject():
    current_os = CURRENT_OS
    current_GPUs = get_current_GPU_names()
    called_command_name = ""
    calling_args = []
    apiObject = CommonAPI()

    def __init__(self, args) -> None:
        self.calling_args = args

    def process_command_name(self) -> StatusCode:
        if len(self.calling_args) > 1:
            self.called_command_name = self.calling_args[1]
        else:
            self.called_command_name = "help"
    
    def prepare_command_object(self) -> StatusCode:

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
                        self.apiObject = Linux_ROCm_SMI_Wrapper()
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
                self.apiObject = Linux_ROCm_SMI_Wrapper()

        try:
            self.process_command_name()
            return StatusCode.SUCCESS
        except Exception as e:
            print(e)

        return StatusCode.SUCCESS
