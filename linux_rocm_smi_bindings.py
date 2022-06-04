import ctypes

class Ctypes_ROCm():
    rocm_lib = None
    functions = {
        "rocm_initialize": None,
        "rocm_finish": None,
        "rocm_get_number_of_devices": None,
        "rocm_get_driver_version": None,
        "rocm_get_device_name_by_handle": None
    }
    def __init__(self) -> None:
        self.rocm_lib = ctypes.CDLL("amd_package/linux/librocm_smi64.so")

        self.rocm_lib.rsmi_init.argtypes = [ctypes.c_uint64]
        self.rocm_lib.rsmi_init.restype = ctypes.c_int
        self.functions["rocm_initialize"] = self.rocm_lib.rsmi_init

        self.rocm_lib.rsmi_shut_down.argtypes = []
        self.rocm_lib.rsmi_shut_down.restype = ctypes.c_int
        self.functions["rocm_finish"] = self.rocm_lib.rsmi_shut_down

        self.rocm_lib.rsmi_num_monitor_devices.argtypes = [ctypes.POINTER(ctypes.c_uint32)]
        self.rocm_lib.rsmi_num_monitor_devices.restype = ctypes.c_int
        self.functions["rocm_get_number_of_devices"] = self.rocm_lib.rsmi_num_monitor_devices

        self.rocm_lib.rsmi_version_str_get.argtypes = [ctypes.c_int, ctypes.POINTER(ctypes.c_char), ctypes.c_uint32]
        self.rocm_lib.rsmi_version_str_get.restype = ctypes.c_int
        self.functions["rocm_get_driver_version"] = self.rocm_lib.rsmi_version_str_get

        self.rocm_lib.rsmi_dev_name_get.argtypes = [ctypes.c_uint32, ctypes.POINTER(ctypes.c_char), ctypes.c_size_t]
        self.rocm_lib.rsmi_dev_name_get.restype = ctypes.c_int
        self.functions["rocm_get_device_name_by_handle"] = self.rocm_lib.rsmi_dev_name_get