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
        self.adl_lib._func_restype_
        self.adl_lib.initialize.argtypes = []
        self.adl_lib.initialize.restype = ctypes.c_int
        self.functions["adl_initialize"] = self.adl_lib.initialize
        '''
        self.adl_lib.ADL_Main_Control_Destroy.argtypes = []
        self.adl_lib.ADL_Main_Control_Destroy.restype = ctypes.c_int
        self.functions["adl_finish"] = self.adl_lib.ADL_Main_Control_Destroy

        self.adl_lib.ADL_Adapter_NumberOfAdapters_Get.argtypes = [ctypes.POINTER(ctypes.c_uint32)]
        self.adl_lib.ADL_Adapter_NumberOfAdapters_Get.restype = ctypes.c_int
        self.functions["adl_get_number_of_devices"] = self.adl_lib.ADL_Adapter_NumberOfAdapters_Get

        self.adl_lib.ADL2_Graphics_VersionsX2_Get.argtypes = [ctypes.c_int, ctypes.POINTER(ctypes.c_char), ctypes.c_uint32]
        self.adl_lib.ADL2_Graphics_VersionsX2_Get.restype = ctypes.c_int
        self.functions["adl_get_driver_version"] = self.adl_lib.ADL2_Graphics_VersionsX2_Get
        '''
obj = Ctypes_ADL()