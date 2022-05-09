import ctypes

rocm_lib = ctypes.CDLL("rocm_out.so")

rocm_lib.initialize.argtypes = []
rocm_lib.initialize.restype = ctypes.c_int
rocm_initialize = rocm_lib.initialize

rocm_lib.finish.argtypes = []
rocm_lib.finish.restype = ctypes.c_int
rocm_finish = rocm_lib.finish

rocm_lib.get_number_of_devices.argtypes = [ctypes.POINTER(ctypes.c_uint32)]
rocm_lib.get_number_of_devices.restype = ctypes.c_int
rocm_get_number_of_devices = rocm_lib.get_number_of_devices

rocm_lib.get_driver_version.argtypes = [ctypes.POINTER(ctypes.c_char)]
rocm_lib.get_driver_version.restype = ctypes.c_int
rocm_get_driver_version = rocm_lib.get_driver_version
