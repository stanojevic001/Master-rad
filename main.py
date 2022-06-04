from pathlib import Path
import subprocess
from defines import *
from command_object import *
from utils import get_current_GPU_names
import sys
from requests import Request


if __name__ == '__main__':
    try:
        commandObj = CommandObject(sys.argv)
        commandObj.prepare_command_object()

        request = Request(commandObj)
        request.process_request()

    except Exception as e:
        print(e)