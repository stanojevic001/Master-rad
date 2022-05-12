import ctypes

class Ctypes_ROCm():
    rocm_lib = None
    functions = {
        "rocm_initialize": None,
        "rocm_finish": None,
        "rocm_get_number_of_devices": None,
        "rocm_get_driver_version": None
    }
    def __init__(self) -> None:
        self.rocm_lib = ctypes.CDLL("librocm_smi64.so")

        self.rocm_lib.initialize.argtypes = []
        self.rocm_lib.initialize.restype = ctypes.c_int
        self.functions["rocm_initialize"] = self.rocm_lib.initialize

        self.rocm_lib.finish.argtypes = []
        self.rocm_lib.finish.restype = ctypes.c_int
        self.functions["rocm_finish"] = self.rocm_lib.finish

        self.rocm_lib.get_number_of_devices.argtypes = [ctypes.POINTER(ctypes.c_uint32)]
        self.rocm_lib.get_number_of_devices.restype = ctypes.c_int
        self.functions["rocm_get_number_of_devices"] = self.rocm_lib.get_number_of_devices

        self.rocm_lib.get_driver_version.argtypes = [ctypes.POINTER(ctypes.c_char)]
        self.rocm_lib.get_driver_version.restype = ctypes.c_int
        self.functions["rocm_get_driver_version"] = self.rocm_lib.get_driver_version
