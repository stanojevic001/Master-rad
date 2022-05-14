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
        self.adl_lib = ctypes.CDLL("atiadlxx.dll")

        self.adl_lib.ADL_Main_Control_Create.argtypes = [ctypes.c_uint64]
        self.adl_lib.ADL_Main_Control_Create.restype = ctypes.c_int
        self.functions["adl_initialize"] = self.adl_lib.ADL_Main_Control_Create

        self.adl_lib.ADL_Main_Control_Destroy.argtypes = []
        self.adl_lib.ADL_Main_Control_Destroy.restype = ctypes.c_int
        self.functions["adl_finish"] = self.adl_lib.ADL_Main_Control_Destroy

        self.adl_lib.ADL_Adapter_NumberOfAdapters_Get.argtypes = [ctypes.POINTER(ctypes.c_uint32)]
        self.adl_lib.ADL_Adapter_NumberOfAdapters_Get.restype = ctypes.c_int
        self.functions["adl_get_number_of_devices"] = self.adl_lib.ADL_Adapter_NumberOfAdapters_Get

        self.adl_lib.ADL2_Graphics_VersionsX2_Get.argtypes = [ctypes.c_int, ctypes.POINTER(ctypes.c_char), ctypes.c_uint32]
        self.adl_lib.ADL2_Graphics_VersionsX2_Get.restype = ctypes.c_int
        self.functions["adl_get_driver_version"] = self.adl_lib.ADL2_Graphics_VersionsX2_Get