import ctypes

class C_ADLVersionsInfo(ctypes.Structure):
    _fields_ = [
        ('strDriverVer', ctypes.c_char * 256),
        ('strCatalystVersion', ctypes.c_char * 256),
        ('strCatalystWebLink', ctypes.c_char * 256)
    ]

class C_AdapterInfoX2(ctypes.Structure):
    _fields_ = [
        ('iSize', ctypes.c_int),
        ('iAdapterIndex', ctypes.c_int),
        ('strUDID', ctypes.c_char * 256),
        ('iBusNumber', ctypes.c_int),
        ('iDeviceNumber', ctypes.c_int),
        ('iFunctionNumber', ctypes.c_int),
        ('iVendorID', ctypes.c_int),
        ('strAdapterName', ctypes.c_char * 256),
        ('strDisplayName', ctypes.c_char * 256),
        ('iPresent', ctypes.c_int),
        ('iExist', ctypes.c_int),
        ('strDriverPath', ctypes.c_char * 256),
        ('strDriverPathExt', ctypes.c_char * 256),
        ('strPNPString', ctypes.c_char * 256),
        ('iOSDisplayIndex', ctypes.c_int),
        ('iInfoMask', ctypes.c_int),
        ('iInfoValue', ctypes.c_int)
    ]

class Ctypes_ADL():
    adl_lib = None
    functions = {
        "adl_initialize": None,
        "adl_finish": None,
        "adl_get_number_of_devices": None,
        "adl_get_driver_version": None,
        "adl_get_adapter_info": None
    }

    def __init__(self) -> None:
        self.adl_lib: ctypes.WinDLL = ctypes.windll.LoadLibrary("amd_package\\windows\\windows_adl.dll")

        self.adl_lib.initialize.argtypes = []
        self.adl_lib.initialize.restype = ctypes.c_int
        self.functions["adl_initialize"] = self.adl_lib.initialize
        
        self.adl_lib.get_driver_version.argtypes = [ctypes.POINTER(C_ADLVersionsInfo)]
        self.adl_lib.get_driver_version.restype = ctypes.c_int
        self.functions["adl_get_driver_version"] = self.adl_lib.get_driver_version

        self.adl_lib.get_number_of_devices.argtypes = [ctypes.POINTER(ctypes.c_int)]
        self.adl_lib.get_number_of_devices.restype = ctypes.c_int
        self.functions["adl_get_number_of_devices"] = self.adl_lib.get_number_of_devices

        self.adl_lib.get_adapter_info.argtypes = [ctypes.POINTER(ctypes.POINTER(C_AdapterInfoX2))]
        self.adl_lib.get_adapter_info.restype = ctypes.c_int
        self.functions["adl_get_adapter_info"] = self.adl_lib.get_adapter_info

        self.adl_lib.finish.argtypes = []
        self.adl_lib.finish.restype = ctypes.c_int
        self.functions["adl_finish"] = self.adl_lib.finish
