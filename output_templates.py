class OutputTemplates:

  console_device_num = "\n\
  Number of devices: {device_num}\n\
  "

  console_device = "\n\
  Device {index}:\n\
"

  console_elem_output ="\
  {nesting}{name}: {value}\n"

  console_complex_elem_variable_nesting = "\
  {nesting}{name}: {value}\n"

  console_simple_elem_variable_nesting = "\
  {nesting}{value}\n"
  
  console_help_command_output = "\n\
  This tool is a multi-platform (Windows and Linux currently supported)\n\
  tool that is used to obtain information about (NVIDIA and\n\
  AMD currently supported) graphics cards. \n\n\
  Usage format: \n\
          gpuinfo [<command>] [-gpu=<device_index>] \n\
                                                            \n\
          Notes: Name of the program (in our case gpuinfo) should be as\n\
                 the name of the runnable provided for a specific system,\n\
                 and if needed to be run with some program\n\
                 (for example python), then name of the supporting program\n\
                 (python for instance) should go before\n\
                 the name of the tool file.\n\
                 Both command and -gpu arguments are optional, and if\n\
                 command argument is \n\
                 not provided, then 'help' command is called, and\n\
                 if -gpu argument is not provided, then GPU information\n\
                 for all devices on \n\
                 the system is given, instead for only one device\n\
                 with certain device index.\n\
                 Also, on the contary, if command argument is provided,\n\
                 then if valid, given command is executed,\n\
                 otherwise error will be returned.\n\
                 If -gpu argument is provided,\n\
                 information will be displayed only for\n\
                 GPU device with a given device index\n\
                 (<device_index> value can be any integer\n\
                 value from 0 to number_of_devices-1),\n\
                 and if it is given an invalid <device_index> or\n\
                 is left out or format of input value\n\
                 is not correct, for example if a string value is\n\
                 provided instead of an integer, errror will be returned.\n\
          IMPORTANT: Some information that is displayed could vary from\n\
                     OS to OS and from GPU card to GPU card.\n\
                     That could happen because on different OS's and\n\
                     on different GPU cards, some\n\
                     information is not supported or is not there\n\
                     because of library version on the system etc.\n\n\
  Commands: \n\
          help - Displays manual for correct usage of the tool and all\n\
                 possible options user has to use with the tool\n\
          catalog - Displays identification and descriptive information\n\
                    for a given GPU device and for\n\
                    its' subsystems (if that is supported on the\n\
                    current system). For example, it will \n\
                    return information about device's serial number, UUID\n\
                    (Universally Unique Identification),\n\
                    if device is currently present or active in the system,\n\
                    device ID, vendor ID, vendor name etc. and also some of\n\
                    this information, where it is supported, will be\n\
                    given about device's subsystem(s).\n\
          memory - Displays memory information about device, for example\n\
                   memory usages, memory sizes for different types of memories\n\
                   that GPU uses, memory checksums etc. \n\
          bus - Displays bus information about device, for example current\n\
                generation of the bus GPU is on (mostly PCIe, but there\n\
                are exceptions), current link speed, supported\n\
                link speeds and generation, current and\n\
                supported number of lanes etc.\n\
          clocks - Displays clock information about device, for different\n\
                   types of clocks, for example\n\
                   supported type of clock frequencies,\n\
                   current clock frequencies, supported clock modes etc.\n\
          versions - Displays versions information about device and\n\
                     in some cases, its' subsystems, for example VBIOS\n\
                     version, driver version, driver models,\n\
                     driver path, library version, firmware versions etc.\n\
          temperature - Displays temperature information for a given device,\n\
                        measured from different types of sensors,\n\
                        for example current GPU temperature, shutdown and\n\
                        slowdown threshold temperature, max temperature etc.\n\
          full - Runs all commands from above (except for help command) and\n\
                 displays all available information for a given GPU device\n\n\
  Device index filter: -gpu=<device_index>, where <device_index> is an integer\n\
                        value that can be any integer number from\n\
                        0 to number_of_devices-1 value, where\n\
                        number_of_devices value will be displayed when running\n\
                        any command (except for help) without specifying\n\
                        gpu index. If format of input device index value,\n\
                        or format of a whole device\n\
                        index filter argument is invalid,\n\
                        error will be returned.\n\
  "
