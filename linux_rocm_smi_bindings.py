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

class rsmi_fw_block_t(enum.IntEnum):
  RSMI_FW_BLOCK_FIRST = 0,
  RSMI_FW_BLOCK_ASD = RSMI_FW_BLOCK_FIRST
  RSMI_FW_BLOCK_CE = 1
  RSMI_FW_BLOCK_DMCU = 2
  RSMI_FW_BLOCK_MC = 3
  RSMI_FW_BLOCK_ME = 4
  RSMI_FW_BLOCK_MEC = 5
  RSMI_FW_BLOCK_MEC2 = 6
  RSMI_FW_BLOCK_PFP = 7
  RSMI_FW_BLOCK_RLC = 8
  RSMI_FW_BLOCK_RLC_SRLC = 9
  RSMI_FW_BLOCK_RLC_SRLG = 10
  RSMI_FW_BLOCK_RLC_SRLS = 11
  RSMI_FW_BLOCK_SDMA = 12
  RSMI_FW_BLOCK_SDMA2 = 13
  RSMI_FW_BLOCK_SMC = 14
  RSMI_FW_BLOCK_SOS = 15
  RSMI_FW_BLOCK_TA_RAS = 16
  RSMI_FW_BLOCK_TA_XGMI = 17
  RSMI_FW_BLOCK_UVD = 18
  RSMI_FW_BLOCK_VCE = 19
  RSMI_FW_BLOCK_VCN = 20
  RSMI_FW_BLOCK_LAST = RSMI_FW_BLOCK_VCN

class rsmi_version_t(ctypes.Structure):
    __fields__ = [
        ('major', ctypes.c_uint32),
        ('minor', ctypes.c_uint32),
        ('patch', ctypes.c_uint32),
        ('build', ctypes.c_char_p)
    ]

class rsmi_clk_type_t(enum.IntEnum):
    RSMI_CLK_TYPE_SYS = 0,            
    RSMI_CLK_TYPE_FIRST = RSMI_CLK_TYPE_SYS,
    RSMI_CLK_TYPE_DF = 1,                                               
    RSMI_CLK_TYPE_DCEF = 2,                
    RSMI_CLK_TYPE_SOC = 3,                 
    RSMI_CLK_TYPE_MEM = 4,                  
    RSMI_CLK_TYPE_LAST = RSMI_CLK_TYPE_MEM,
    RSMI_CLK_INVALID = 0xFFFFFFFF

class rsmi_range_t(ctypes.Structure):
    __fields__ = [
        ('lower_bound', ctypes.c_uint64),
        ('upper_bound', ctypes.c_uint64)
    ]

class rsmi_od_vddc_point_t(ctypes.Structure):
    __fields__ = [
        ('frequency', ctypes.c_uint64),
        ('voltage', ctypes.c_uint64)
    ]

RSMI_NUM_VOLTAGE_CURVE_POINTS = 3
class rsmi_od_volt_curve_t(ctypes.Structure):
    __fields__ = [
        ('vc_points', rsmi_od_vddc_point_t * RSMI_NUM_VOLTAGE_CURVE_POINTS)
    ]

class rsmi_od_volt_freq_data_t(ctypes.Structure):
    __fields__ = [
        ('curr_sclk_range', rsmi_range_t),
        ('curr_mclk_range', rsmi_range_t),
        ('sclk_freq_limits', rsmi_range_t),
        ('mclk_freq_limits', rsmi_range_t),
        ('curve', rsmi_od_volt_curve_t),
        ('num_regions', ctypes.c_uint32)

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
        "rocm_get_device_memory_reserved_pages": None,
        "rocm_get_rsmi_version": None,
        "rocm_get_device_vbios_version": None,
        "rocm_get_device_firmware_version": None,
        "rocm_get_clock_frequencies_info": None,
        "rocm_get_device_od_volt_info": None
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

        self.rocm_lib.rsmi_dev_name_get.argtypes = [ctypes.c_uint32, ctypes.POINTER(ctypes.c_char), ctypes.c_size_t]
        self.rocm_lib.rsmi_dev_name_get.restype = ctypes.c_int
        self.functions["rocm_get_device_name_by_handle"] = self.rocm_lib.rsmi_dev_name_get

        #Identifier queries
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

        #Bus queries
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

        #Memory queries
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

        #Version queries
        self.rocm_lib.rsmi_version_get.argtypes = [ctypes.POINTER(rsmi_version_t)]
        self.rocm_lib.rsmi_version_get.restype = ctypes.c_int
        self.functions["rocm_get_rsmi_version"] =self.rocm_lib.rsmi_version_get

        self.rocm_lib.rsmi_version_str_get.argtypes = [ctypes.c_int, ctypes.POINTER(ctypes.c_char), ctypes.c_uint32]
        self.rocm_lib.rsmi_version_str_get.restype = ctypes.c_int
        self.functions["rocm_get_driver_version"] = self.rocm_lib.rsmi_version_str_get

        self.rocm_lib.rsmi_dev_vbios_version_get.argtypes = [ctypes.c_uint32, ctypes.POINTER(ctypes.c_char), ctypes.c_uint32]
        self.rocm_lib.rsmi_dev_vbios_version_get.restype = ctypes.c_int
        self.functions["rocm_get_device_vbios_version"] =self.rocm_lib.rsmi_dev_vbios_version_get

        self.rocm_lib.rsmi_dev_firmware_version_get.argtypes = [ctypes.c_uint32, rsmi_fw_block_t, ctypes.POINTER(ctypes.c_uint64)]
        self.rocm_lib.rsmi_dev_firmware_version_get.restype = ctypes.c_int
        self.functions["rocm_get_device_firmware_version"] =self.rocm_lib.rsmi_dev_firmware_version_get

        #Clock info
        self.rocm_lib.rsmi_dev_gpu_clk_freq_get.argtypes = [ctypes.c_uint32, rsmi_clk_type_t, ctypes.POINTER(rsmi_frequencies_t)]
        self.rocm_lib.rsmi_dev_gpu_clk_freq_get.restype = ctypes.c_int
        self.functions["rocm_get_clock_frequencies_info"] =self.rocm_lib.rsmi_dev_gpu_clk_freq_get
        
        self.rocm_lib.rsmi_dev_od_volt_info_get.argtypes = [ctypes.c_uint32, ctypes.POINTER(rsmi_od_volt_freq_data_t)]
        self.rocm_lib.rsmi_dev_od_volt_info_get.restype = ctypes.c_int
        self.functions["rocm_get_device_od_volt_info"] =self.rocm_lib.rsmi_dev_od_volt_info_get

