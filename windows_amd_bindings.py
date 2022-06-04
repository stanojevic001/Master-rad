import ctypes


class Ctypes_ADL():
    adl_lib = None
    functions = {
        "adl_initialize": None,
        "adl_finish": None,
        "adl_get_number_of_devices": None,
        "adl_get_driver_version": None
    }
    def __init__(self) -> None:
        self.adl_lib: ctypes.WinDLL = ctypes.windll.LoadLibrary("amd_package\\windows\\windows_adl.dll")

        self.adl_lib.initialize.argtypes = []
        self.adl_lib.initialize.restype = ctypes.c_int
        self.functions["adl_initialize"] = self.adl_lib.initialize
        
        self.adl_lib.get_driver_version.argtypes = []
        self.adl_lib.get_driver_version.restype = ctypes.c_int
        self.functions["adl_get_driver_version"] = self.adl_lib.get_driver_version

        self.adl_lib.finish.argtypes = []
        self.adl_lib.finish.restype = ctypes.c_int
        self.functions["adl_finish"] = self.adl_lib.finish
