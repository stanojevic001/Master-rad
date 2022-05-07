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
        result = commandObj.prepare_command_object()

        if result != StatusCode.SUCCESS:
            print("Failed! User had too many failed input attempts!")

        request = Request(commandObj)
        result = request.process_request()

        if result != StatusCode.SUCCESS:
            print("Failed! User had too many failed input attempts!")

    except Exception as e:
        raise(e)