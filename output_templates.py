class OutputTemplates:

  catalog_console_device_num = "\n\
  Number of devices: {device_num}\n\
  "

  catalog_console_device = "\n\
  Device {index}:\n\
"
  #catalog_elem_output ="\
  #{nesting}{name}: {value}\n"
  catalog_elem_output ="\
    {name}: {value}\n"
  
  #catalog_elem_output_nested_level_1 ="\
  #    {name}: {value}\n"
  
  #catalog_elem_level_one_nesting = "\
  #    {name}: {value}\n"
  
  catalog_complex_elem_variable_nesting = "\
  {nesting}{name}: {value}\n"

  catalog_simple_elem_variable_nesting = "\
  {nesting}{value}\n"
  
  driver_info_console = "\n\
  Driver info:\n\
    Version: {version}\n\
    Current model: {current_model}\n\
    Pending model: {pending_model}\n\
  "

  device_console_index = "\n\
    Device {index}:\n\
  "

  temperature_console_header = "\n\
  Temperature info:\n\
  "

  clocks_header = "\n\
    Clocks info:\n"
  
  clocks_elem = "\
      {name}: {value}\n"

  temperature_console_readings_title = "\n\
      Readings(in Celsius):\n\
  "

  temperature_console_thresholds_title = "\n\
      Thresholds(in Celsius):\n\
  "

  temperature_console_element = "\
        {name}: {value}\n\
  "

  help_console_output = "\n\
  Write here help manual!\n\
  "