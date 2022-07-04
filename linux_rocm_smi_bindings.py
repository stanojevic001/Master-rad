import ctypes
import enum

RSMI_MAX_NUM_FREQUENCIES = 32
class rsmi_frequencies_t(ctypes.Structure):
    __fields__ = [
        ('num_supported', ctypes.c_uint32),
        ('current', ctypes.c_uint32),
        ('frequency', ctypes.c_uint64 * RSMI_MAX_NUM_FREQUENCIES)
    ]
class rsmi_pcie_bandwidth_t(ctypes.Structure):
    __fields__ = [
        ('transfer_rate', rsmi_frequencies_t),
        ('lanes', ctypes.c_uint32 * RSMI_MAX_NUM_FREQUENCIES)
    ]

class rsmi_memory_type_t(enum.IntEnum):
  RSMI_MEM_TYPE_FIRST = 0,
  RSMI_MEM_TYPE_VRAM = RSMI_MEM_TYPE_FIRST
  RSMI_MEM_TYPE_VIS_VRAM = 1
  RSMI_MEM_TYPE_GTT = 2
  RSMI_MEM_TYPE_LAST = RSMI_MEM_TYPE_GTT

class  rsmi_memory_page_status_t(enum.IntEnum):
  RSMI_MEM_PAGE_STATUS_RESERVED = 0
  RSMI_MEM_PAGE_STATUS_PENDING = 1
  RSMI_MEM_PAGE_STATUS_UNRESERVABLE = enum.auto()

class rsmi_retired_page_record_t(ctypes.Structure):
    __fields__ = [
        ('page_address', ctypes.c_uint64),
        ('page_size', ctypes.c_uint64),
        ('status', rsmi_memory_page_status_t)
    ]

class Ctypes_ROCm():
    rocm_lib = None
    functions = {
        "rocm_initialize": None,
        "rocm_finish": None,
        "rocm_get_number_of_devices": None,
        "rocm_get_driver_version": None,
        "rocm_get_device_name_by_handle": None,
        "rocm_get_device_id": None,
        "rocm_get_device_sku": None,
        "rocm_get_device_vendor_id": None,
        "rocm_get_device_brand": None,
        "rocm_get_device_vendor_name": None,
        "rocm_get_device_vram_vendor": None,
        "rocm_get_device_serial_number": None,
        "rocm_get_device_subsystem_id": None,
        "rocm_get_device_subsystem_name": None,
        "rocm_get_device_drm_render_minor": None,
        "rocm_get_device_subsystem_vendor_id": None,
        "rocm_get_device_unique_id": None,
        "rocm_get_device_pci_bandwidth": None,
        "rocm_get_device_pci_id": None,
        "rocm_get_device_pci_throughput": None,
        "rocm_get_device_pci_replay_counter": None,
        "rocm_get_device_memory_total": None,
        "rocm_get_device_memory_usage": None,
        "rocm_get_device_memory_busy_percent": None,
        "rocm_get_device_memory_reserved_pages": None
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

        self.rocm_lib.rsmi_dev_id_get.argtypes = [ctypes.c_uint32, ctypes.POINTER(ctypes.c_uint16)]
        self.rocm_lib.rsmi_dev_id_get.restype = ctypes.c_int
        self.functions["rocm_get_device_id"] =self.rocm_lib.rsmi_dev_id_get

        self.rocm_lib.rsmi_dev_sku_get.argtypes = [ctypes.c_uint32, ctypes.POINTER(ctypes.c_uint16)]
        self.rocm_lib.rsmi_dev_sku_get.restype = ctypes.c_int
        self.functions["rocm_get_device_sku"] =self.rocm_lib.rsmi_dev_sku_get

        self.rocm_lib.rsmi_dev_vendor_id_get.argtypes = [ctypes.c_uint32, ctypes.POINTER(ctypes.c_uint16)]
        self.rocm_lib.rsmi_dev_vendor_id_get.restype = ctypes.c_int
        self.functions["rocm_get_device_vendor_id"] =self.rocm_lib.rsmi_dev_vendor_id_get

        self.rocm_lib.rsmi_dev_brand_get.argtypes = [ctypes.c_uint32, ctypes.POINTER(ctypes.c_char), ctypes.c_uint32]
        self.rocm_lib.rsmi_dev_brand_get.restype = ctypes.c_int
        self.functions["rocm_get_device_brand"] =self.rocm_lib.rsmi_dev_brand_get

        self.rocm_lib.rsmi_dev_vendor_name_get.argtypes = [ctypes.c_uint32, ctypes.POINTER(ctypes.c_char), ctypes.c_size_t]
        self.rocm_lib.rsmi_dev_vendor_name_get.restype = ctypes.c_int
        self.functions["rocm_get_device_vendor_name"] =self.rocm_lib.rsmi_dev_vendor_name_get

        self.rocm_lib.rsmi_dev_vram_vendor_get.argtypes = [ctypes.c_uint32, ctypes.POINTER(ctypes.c_char), ctypes.c_uint32]
        self.rocm_lib.rsmi_dev_vram_vendor_get.restype = ctypes.c_int
        self.functions["rocm_get_device_vram_vendor"] =self.rocm_lib.rsmi_dev_vram_vendor_get

        self.rocm_lib.rsmi_dev_serial_number_get.argtypes = [ctypes.c_uint32, ctypes.POINTER(ctypes.c_char), ctypes.c_uint32]
        self.rocm_lib.rsmi_dev_serial_number_get.restype = ctypes.c_int
        self.functions["rocm_get_device_serial_number"] =self.rocm_lib.rsmi_dev_serial_number_get
        
        self.rocm_lib.rsmi_dev_subsystem_id_get.argtypes = [ctypes.c_uint32, ctypes.POINTER(ctypes.c_uint16)]
        self.rocm_lib.rsmi_dev_subsystem_id_get.restype = ctypes.c_int
        self.functions["rocm_get_device_subsystem_id"] =self.rocm_lib.rsmi_dev_subsystem_id_get

        self.rocm_lib.rsmi_dev_subsystem_name_get.argtypes = [ctypes.c_uint32, ctypes.POINTER(ctypes.c_char), ctypes.c_size_t]
        self.rocm_lib.rsmi_dev_subsystem_name_get.restype = ctypes.c_int
        self.functions["rocm_get_device_subsystem_name"] =self.rocm_lib.rsmi_dev_subsystem_name_get

        self.rocm_lib.rsmi_dev_drm_render_minor_get.argtypes = [ctypes.c_uint32, ctypes.POINTER(ctypes.c_uint32)]
        self.rocm_lib.rsmi_dev_drm_render_minor_get.restype = ctypes.c_int
        self.functions["rocm_get_device_drm_render_minor"] =self.rocm_lib.rsmi_dev_drm_render_minor_get
        
        self.rocm_lib.rsmi_dev_subsystem_vendor_id_get.argtypes = [ctypes.c_uint32, ctypes.POINTER(ctypes.c_uint16)]
        self.rocm_lib.rsmi_dev_subsystem_vendor_id_get.restype = ctypes.c_int
        self.functions["rocm_get_device_subsystem_vendor_id"] =self.rocm_lib.rsmi_dev_subsystem_vendor_id_get
        
        self.rocm_lib.rsmi_dev_unique_id_get.argtypes = [ctypes.c_uint32, ctypes.POINTER(ctypes.c_uint64)]
        self.rocm_lib.rsmi_dev_unique_id_get.restype = ctypes.c_int
        self.functions["rocm_get_device_unique_id"] =self.rocm_lib.rsmi_dev_unique_id_get

        self.rocm_lib.rsmi_dev_pci_bandwidth_get.argtypes = [ctypes.c_uint32, ctypes.POINTER(rsmi_pcie_bandwidth_t)]
        self.rocm_lib.rsmi_dev_pci_bandwidth_get.restype = ctypes.c_int
        self.functions["rocm_get_device_pci_bandwidth"] =self.rocm_lib.rsmi_dev_pci_bandwidth_get
        
        self.rocm_lib.rsmi_dev_pci_id_get.argtypes = [ctypes.c_uint32, ctypes.POINTER(ctypes.c_uint64)]
        self.rocm_lib.rsmi_dev_pci_id_get.restype = ctypes.c_int
        self.functions["rocm_get_device_pci_id"] =self.rocm_lib.rsmi_dev_pci_id_get
        
        self.rocm_lib.rsmi_dev_pci_throughput_get.argtypes = [ctypes.c_uint32, ctypes.POINTER(ctypes.c_uint64), ctypes.POINTER(ctypes.c_uint64), ctypes.POINTER(ctypes.c_uint64)]
        self.rocm_lib.rsmi_dev_pci_throughput_get.restype = ctypes.c_int
        self.functions["rocm_get_device_pci_throughput"] =self.rocm_lib.rsmi_dev_pci_throughput_get
        
        self.rocm_lib.rsmi_dev_pci_replay_counter_get.argtypes = [ctypes.c_uint32, ctypes.POINTER(ctypes.c_uint64)]
        self.rocm_lib.rsmi_dev_pci_replay_counter_get.restype = ctypes.c_int
        self.functions["rocm_get_device_pci_replay_counter"] =self.rocm_lib.rsmi_dev_pci_replay_counter_get

        self.rocm_lib.rsmi_dev_memory_total_get.argtypes = [ctypes.c_uint32, rsmi_memory_type_t, ctypes.POINTER(ctypes.c_uint64)]
        self.rocm_lib.rsmi_dev_memory_total_get.restype = ctypes.c_int
        self.functions["rocm_get_device_memory_total"] =self.rocm_lib.rsmi_dev_memory_total_get

        self.rocm_lib.rsmi_dev_memory_usage_get.argtypes = [ctypes.c_uint32, rsmi_memory_type_t, ctypes.POINTER(ctypes.c_uint64)]
        self.rocm_lib.rsmi_dev_memory_usage_get.restype = ctypes.c_int
        self.functions["rocm_get_device_memory_usage"] =self.rocm_lib.rsmi_dev_memory_usage_get
        
        self.rocm_lib.rsmi_dev_memory_busy_percent_get.argtypes = [ctypes.c_uint32, ctypes.POINTER(ctypes.c_uint32)]
        self.rocm_lib.rsmi_dev_memory_busy_percent_get.restype = ctypes.c_int
        self.functions["rocm_get_device_memory_busy_percent"] =self.rocm_lib.rsmi_dev_memory_busy_percent_get

        self.rocm_lib.rsmi_dev_memory_reserved_pages_get.argtypes = [ctypes.c_uint32, ctypes.POINTER(ctypes.c_uint32), ctypes.POINTER(rsmi_retired_page_record_t)]
        self.rocm_lib.rsmi_dev_memory_reserved_pages_get.restype = ctypes.c_int
        self.functions["rocm_get_device_memory_reserved_pages"] =self.rocm_lib.rsmi_dev_memory_reserved_pages_get