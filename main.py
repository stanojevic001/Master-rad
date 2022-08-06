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
        status = commandObj.prepare_command_object()
        if status != StatusCode.SUCCESS:
            raise Exception("Command input not processed correctly. See error output in console for more details!")

        request = Request(commandObj)
        status = request.process_request()
        if status != StatusCode.SUCCESS:
            raise Exception("Request not processed correctly. See error output in console for more details!")

    except Exception as e:
        print(e)