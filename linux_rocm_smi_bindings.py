import ctypes
import enum

RSMI_MAX_NUM_FREQUENCIES = 32
class rsmi_frequencies_t(ctypes.Structure):
    _fields_ = [
        ('num_supported', ctypes.c_uint32),
        ('current', ctypes.c_uint32),
        ('frequency', ctypes.c_uint64 * RSMI_MAX_NUM_FREQUENCIES)
    ]

class rsmi_pcie_bandwidth_t(ctypes.Structure):
    _fields_ = [
        ('transfer_rate', rsmi_frequencies_t),
        ('lanes', ctypes.c_uint32 * RSMI_MAX_NUM_FREQUENCIES)
    ]

class rsmi_memory_type_t(enum.IntEnum):
    RSMI_MEM_TYPE_FIRST = 0
    RSMI_MEM_TYPE_VRAM = RSMI_MEM_TYPE_FIRST
    RSMI_MEM_TYPE_VIS_VRAM = 1
    RSMI_MEM_TYPE_GTT = 2
    RSMI_MEM_TYPE_LAST = RSMI_MEM_TYPE_GTT

class rsmi_memory_page_status_t(enum.IntEnum):
    RSMI_MEM_PAGE_STATUS_RESERVED = 0
    RSMI_MEM_PAGE_STATUS_PENDING = 1
    RSMI_MEM_PAGE_STATUS_UNRESERVABLE = enum.auto()

class rsmi_retired_page_record_t(ctypes.Structure):
    _fields_ = [
        ('page_address', ctypes.c_uint64),
        ('page_size', ctypes.c_uint64),
        ('status', ctypes.c_int)
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
    _fields_ = [
        ('major', ctypes.c_uint32),
        ('minor', ctypes.c_uint32),
        ('patch', ctypes.c_uint32),
        ('build', ctypes.c_char_p)
    ]

class rsmi_clk_type_t(enum.IntEnum):
    RSMI_CLK_TYPE_SYS = 0
    RSMI_CLK_TYPE_FIRST = RSMI_CLK_TYPE_SYS
    RSMI_CLK_TYPE_DF = 1                                               
    RSMI_CLK_TYPE_DCEF = 2                
    RSMI_CLK_TYPE_SOC = 3                 
    RSMI_CLK_TYPE_MEM = 4                  
    RSMI_CLK_TYPE_LAST = RSMI_CLK_TYPE_MEM
    RSMI_CLK_INVALID = 0xFFFFFFFF

class rsmi_range_t(ctypes.Structure):
    _fields_ = [
        ('lower_bound', ctypes.c_uint64),
        ('upper_bound', ctypes.c_uint64)
    ]

class rsmi_od_vddc_point_t(ctypes.Structure):
    _fields_ = [
        ('frequency', ctypes.c_uint64),
        ('voltage', ctypes.c_uint64)
    ]

RSMI_NUM_VOLTAGE_CURVE_POINTS = 3
class rsmi_od_volt_curve_t(ctypes.Structure):
    _fields_ = [
        ('vc_points', rsmi_od_vddc_point_t * RSMI_NUM_VOLTAGE_CURVE_POINTS)
    ]

class rsmi_od_volt_freq_data_t(ctypes.Structure):
    _fields_ = [
        ('curr_sclk_range', rsmi_range_t),
        ('curr_mclk_range', rsmi_range_t),
        ('sclk_freq_limits', rsmi_range_t),
        ('mclk_freq_limits', rsmi_range_t),
        ('curve', rsmi_od_volt_curve_t),
        ('num_regions', ctypes.c_uint32)

    ]

class rsmi_temperature_metric_t(enum.IntEnum):
  RSMI_TEMP_CURRENT = 0x0
  RSMI_TEMP_FIRST = RSMI_TEMP_CURRENT
  RSMI_TEMP_MAX = 1
  RSMI_TEMP_MIN = 2
  RSMI_TEMP_MAX_HYST = 3
  RSMI_TEMP_MIN_HYST = 4
  RSMI_TEMP_CRITICAL = 5
  RSMI_TEMP_CRITICAL_HYST = 6
  RSMI_TEMP_EMERGENCY = 7
  RSMI_TEMP_EMERGENCY_HYST = 8
  RSMI_TEMP_CRIT_MIN = 9
  RSMI_TEMP_CRIT_MIN_HYST = 10
  RSMI_TEMP_OFFSET = 11
  RSMI_TEMP_LOWEST = 12
  RSMI_TEMP_HIGHEST = 13
  RSMI_TEMP_LAST = RSMI_TEMP_HIGHEST

class rsmi_temperature_type_t(enum.IntEnum):
  RSMI_TEMP_TYPE_FIRST = 0
  RSMI_TEMP_TYPE_EDGE = RSMI_TEMP_TYPE_FIRST
  RSMI_TEMP_TYPE_JUNCTION = 1
  RSMI_TEMP_TYPE_MEMORY = 2
  RSMI_TEMP_TYPE_HBM_0 = 3
  RSMI_TEMP_TYPE_HBM_1 = 4
  RSMI_TEMP_TYPE_HBM_2 = 5
  RSMI_TEMP_TYPE_HBM_3 = 6
  RSMI_TEMP_TYPE_LAST = RSMI_TEMP_TYPE_HBM_3,
  RSMI_TEMP_TYPE_INVALID = 0xFFFFFFFF

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
        "rocm_get_device_od_volt_info": None,
        "rocm_get_device_temperature": None
    }
    def __init__(self) -> None:
        self.rocm_lib = ctypes.CDLL("amd_package/linux/librocm_smi64.so")

        try:
            getattr(self.rocm_lib, "rsmi_init")
            self.rocm_lib.rsmi_init.argtypes = [ctypes.c_uint64]
            self.rocm_lib.rsmi_init.restype = ctypes.c_int
            self.functions["rocm_initialize"] = self.rocm_lib.rsmi_init
        except Exception as e:
            self.functions["rocm_initialize"] = None

        try:
            getattr(self.rocm_lib, "rsmi_shut_down")
            self.rocm_lib.rsmi_shut_down.argtypes = []
            self.rocm_lib.rsmi_shut_down.restype = ctypes.c_int
            self.functions["rocm_finish"] = self.rocm_lib.rsmi_shut_down
        except Exception as e:
            self.functions["rocm_finish"] = None
        

        try:
            getattr(self.rocm_lib, "rsmi_num_monitor_devices")
            self.rocm_lib.rsmi_num_monitor_devices.argtypes = [ctypes.POINTER(ctypes.c_uint32)]
            self.rocm_lib.rsmi_num_monitor_devices.restype = ctypes.c_int
            self.functions["rocm_get_number_of_devices"] = self.rocm_lib.rsmi_num_monitor_devices
        except Exception as e:
            self.functions["rocm_get_number_of_devices"] = None
        

        try:
            getattr(self.rocm_lib, "rsmi_dev_name_get")
            self.rocm_lib.rsmi_dev_name_get.argtypes = [ctypes.c_uint32, ctypes.POINTER(ctypes.c_char), ctypes.c_size_t]
            self.rocm_lib.rsmi_dev_name_get.restype = ctypes.c_int
            self.functions["rocm_get_device_name_by_handle"] = self.rocm_lib.rsmi_dev_name_get
        except Exception as e:
            self.functions["rocm_get_device_name_by_handle"] = None


        #Identifier queries
        try:
            getattr(self.rocm_lib, "rsmi_dev_id_get")
            self.rocm_lib.rsmi_dev_id_get.argtypes = [ctypes.c_uint32, ctypes.POINTER(ctypes.c_uint16)]
            self.rocm_lib.rsmi_dev_id_get.restype = ctypes.c_int
            self.functions["rocm_get_device_id"] =self.rocm_lib.rsmi_dev_id_get
        except Exception as e:
            self.functions["rocm_get_device_id"] = None


        try:
            getattr(self.rocm_lib, "rsmi_dev_sku_get")
            self.rocm_lib.rsmi_dev_sku_get.argtypes = [ctypes.c_uint32, ctypes.POINTER(ctypes.c_uint16)]
            self.rocm_lib.rsmi_dev_sku_get.restype = ctypes.c_int
            self.functions["rocm_get_device_sku"] =self.rocm_lib.rsmi_dev_sku_get
        except Exception as e:
            self.functions["rocm_get_device_sku"] = None

        try:
            getattr(self.rocm_lib, "rsmi_dev_vendor_id_get")
            self.rocm_lib.rsmi_dev_vendor_id_get.argtypes = [ctypes.c_uint32, ctypes.POINTER(ctypes.c_uint16)]
            self.rocm_lib.rsmi_dev_vendor_id_get.restype = ctypes.c_int
            self.functions["rocm_get_device_vendor_id"] =self.rocm_lib.rsmi_dev_vendor_id_get
        except Exception as e:
            self.functions["rocm_get_device_vendor_id"] = None

        try:
            getattr(self.rocm_lib, "rsmi_dev_brand_get")
            self.rocm_lib.rsmi_dev_brand_get.argtypes = [ctypes.c_uint32, ctypes.POINTER(ctypes.c_char), ctypes.c_uint32]
            self.rocm_lib.rsmi_dev_brand_get.restype = ctypes.c_int
            self.functions["rocm_get_device_brand"] =self.rocm_lib.rsmi_dev_brand_get
        except Exception as e:
            self.functions["rocm_get_device_brand"] = None
        

        try:
            getattr(self.rocm_lib, "rsmi_dev_vendor_name_get")
            self.rocm_lib.rsmi_dev_vendor_name_get.argtypes = [ctypes.c_uint32, ctypes.POINTER(ctypes.c_char), ctypes.c_size_t]
            self.rocm_lib.rsmi_dev_vendor_name_get.restype = ctypes.c_int
            self.functions["rocm_get_device_vendor_name"] =self.rocm_lib.rsmi_dev_vendor_name_get
        except Exception as e:
            self.functions["rocm_get_device_vendor_name"] = None
        

        try:
            getattr(self.rocm_lib, "rsmi_dev_vram_vendor_get")
            self.rocm_lib.rsmi_dev_vram_vendor_get.argtypes = [ctypes.c_uint32, ctypes.POINTER(ctypes.c_char), ctypes.c_uint32]
            self.rocm_lib.rsmi_dev_vram_vendor_get.restype = ctypes.c_int
            self.functions["rocm_get_device_vram_vendor"] =self.rocm_lib.rsmi_dev_vram_vendor_get
        except Exception as e:
            self.functions["rocm_get_device_vram_vendor"] = None
        

        try:
            getattr(self.rocm_lib, "rsmi_dev_serial_number_get")
            self.rocm_lib.rsmi_dev_serial_number_get.argtypes = [ctypes.c_uint32, ctypes.POINTER(ctypes.c_char), ctypes.c_uint32]
            self.rocm_lib.rsmi_dev_serial_number_get.restype = ctypes.c_int
            self.functions["rocm_get_device_serial_number"] =self.rocm_lib.rsmi_dev_serial_number_get
        except Exception as e:
            self.functions["rocm_get_device_serial_number"] = None
        

        try:
            getattr(self.rocm_lib, "rsmi_dev_subsystem_id_get")
            self.rocm_lib.rsmi_dev_subsystem_id_get.argtypes = [ctypes.c_uint32, ctypes.POINTER(ctypes.c_uint16)]
            self.rocm_lib.rsmi_dev_subsystem_id_get.restype = ctypes.c_int
            self.functions["rocm_get_device_subsystem_id"] =self.rocm_lib.rsmi_dev_subsystem_id_get
        except Exception as e:
            self.functions["rocm_get_device_subsystem_id"] = None
        

        try:
            getattr(self.rocm_lib, "rsmi_dev_subsystem_name_get")
            self.rocm_lib.rsmi_dev_subsystem_name_get.argtypes = [ctypes.c_uint32, ctypes.POINTER(ctypes.c_char), ctypes.c_size_t]
            self.rocm_lib.rsmi_dev_subsystem_name_get.restype = ctypes.c_int
            self.functions["rocm_get_device_subsystem_name"] =self.rocm_lib.rsmi_dev_subsystem_name_get
        except Exception as e:
            self.functions["rocm_get_device_subsystem_name"] = None
        

        try:
            getattr(self.rocm_lib, "rsmi_dev_drm_render_minor_get")
            self.rocm_lib.rsmi_dev_drm_render_minor_get.argtypes = [ctypes.c_uint32, ctypes.POINTER(ctypes.c_uint32)]
            self.rocm_lib.rsmi_dev_drm_render_minor_get.restype = ctypes.c_int
            self.functions["rocm_get_device_drm_render_minor"] =self.rocm_lib.rsmi_dev_drm_render_minor_get
        except Exception as e:
            self.functions["rocm_get_device_drm_render_minor"] = None
        

        try:
            getattr(self.rocm_lib, "rsmi_dev_subsystem_vendor_id_get")
            self.rocm_lib.rsmi_dev_subsystem_vendor_id_get.argtypes = [ctypes.c_uint32, ctypes.POINTER(ctypes.c_uint16)]
            self.rocm_lib.rsmi_dev_subsystem_vendor_id_get.restype = ctypes.c_int
            self.functions["rocm_get_device_subsystem_vendor_id"] =self.rocm_lib.rsmi_dev_subsystem_vendor_id_get
        except Exception as e:
            self.functions["rocm_get_device_subsystem_vendor_id"] = None
        

        try:
            getattr(self.rocm_lib, "rsmi_dev_unique_id_get")
            self.rocm_lib.rsmi_dev_unique_id_get.argtypes = [ctypes.c_uint32, ctypes.POINTER(ctypes.c_uint64)]
            self.rocm_lib.rsmi_dev_unique_id_get.restype = ctypes.c_int
            self.functions["rocm_get_device_unique_id"] =self.rocm_lib.rsmi_dev_unique_id_get
        except Exception as e:
            self.functions["rocm_get_device_unique_id"] = None
        

        #Bus queries
        try:
            getattr(self.rocm_lib, "rsmi_dev_pci_bandwidth_get")
            self.rocm_lib.rsmi_dev_pci_bandwidth_get.argtypes = [ctypes.c_uint32, ctypes.POINTER(rsmi_pcie_bandwidth_t)]
            self.rocm_lib.rsmi_dev_pci_bandwidth_get.restype = ctypes.c_int
            self.functions["rocm_get_device_pci_bandwidth"] =self.rocm_lib.rsmi_dev_pci_bandwidth_get
        except Exception as e:
            self.functions["rocm_get_device_pci_bandwidth"] = None


        try:
            getattr(self.rocm_lib, "rsmi_dev_pci_id_get")
            self.rocm_lib.rsmi_dev_pci_id_get.argtypes = [ctypes.c_uint32, ctypes.POINTER(ctypes.c_uint64)]
            self.rocm_lib.rsmi_dev_pci_id_get.restype = ctypes.c_int
            self.functions["rocm_get_device_pci_id"] =self.rocm_lib.rsmi_dev_pci_id_get
        except Exception as e:
            self.functions["rocm_get_device_pci_id"] = None
        

        try:
            getattr(self.rocm_lib, "rsmi_dev_pci_throughput_get")
            self.rocm_lib.rsmi_dev_pci_throughput_get.argtypes = [ctypes.c_uint32, ctypes.POINTER(ctypes.c_uint64), ctypes.POINTER(ctypes.c_uint64), ctypes.POINTER(ctypes.c_uint64)]
            self.rocm_lib.rsmi_dev_pci_throughput_get.restype = ctypes.c_int
            self.functions["rocm_get_device_pci_throughput"] =self.rocm_lib.rsmi_dev_pci_throughput_get
        except Exception as e:
            self.functions["rocm_get_device_pci_throughput"] = None
        

        try:
            getattr(self.rocm_lib, "rsmi_dev_pci_replay_counter_get")
            self.rocm_lib.rsmi_dev_pci_replay_counter_get.argtypes = [ctypes.c_uint32, ctypes.POINTER(ctypes.c_uint64)]
            self.rocm_lib.rsmi_dev_pci_replay_counter_get.restype = ctypes.c_int
            self.functions["rocm_get_device_pci_replay_counter"] =self.rocm_lib.rsmi_dev_pci_replay_counter_get
        except Exception as e:
            self.functions["rocm_get_device_pci_replay_counter"] = None
        

        #Memory queries
        try:
            getattr(self.rocm_lib, "rsmi_dev_memory_total_get")
            self.rocm_lib.rsmi_dev_memory_total_get.argtypes = [ctypes.c_uint32, ctypes.c_uint, ctypes.POINTER(ctypes.c_uint64)]
            self.rocm_lib.rsmi_dev_memory_total_get.restype = ctypes.c_int
            self.functions["rocm_get_device_memory_total"] =self.rocm_lib.rsmi_dev_memory_total_get
        except Exception as e:
            self.functions["rocm_get_device_memory_total"] = None
        

        try:
            getattr(self.rocm_lib, "rsmi_dev_memory_usage_get")
            self.rocm_lib.rsmi_dev_memory_usage_get.argtypes = [ctypes.c_uint32, ctypes.c_uint, ctypes.POINTER(ctypes.c_uint64)]
            self.rocm_lib.rsmi_dev_memory_usage_get.restype = ctypes.c_int
            self.functions["rocm_get_device_memory_usage"] =self.rocm_lib.rsmi_dev_memory_usage_get
        except Exception as e:
            self.functions["rocm_get_device_memory_usage"] = None
        

        try:
            getattr(self.rocm_lib, "rsmi_dev_memory_busy_percent_get")
            self.rocm_lib.rsmi_dev_memory_busy_percent_get.argtypes = [ctypes.c_uint32, ctypes.POINTER(ctypes.c_uint32)]
            self.rocm_lib.rsmi_dev_memory_busy_percent_get.restype = ctypes.c_int
            self.functions["rocm_get_device_memory_busy_percent"] =self.rocm_lib.rsmi_dev_memory_busy_percent_get
        except Exception as e:
            self.functions["rocm_get_device_memory_busy_percent"] = None
        

        try:
            getattr(self.rocm_lib, "rsmi_dev_memory_reserved_pages_get")
            self.rocm_lib.rsmi_dev_memory_reserved_pages_get.argtypes = [ctypes.c_uint32, ctypes.POINTER(ctypes.c_uint32), ctypes.POINTER(rsmi_retired_page_record_t)]
            self.rocm_lib.rsmi_dev_memory_reserved_pages_get.restype = ctypes.c_int
            self.functions["rocm_get_device_memory_reserved_pages"] =self.rocm_lib.rsmi_dev_memory_reserved_pages_get
        except Exception as e:
            self.functions["rocm_get_device_memory_reserved_pages"] = None
        

        #Version queries
        try:
            getattr(self.rocm_lib, "rsmi_version_get")
            self.rocm_lib.rsmi_version_get.argtypes = [ctypes.POINTER(rsmi_version_t)]
            self.rocm_lib.rsmi_version_get.restype = ctypes.c_int
            self.functions["rocm_get_rsmi_version"] =self.rocm_lib.rsmi_version_get
        except Exception as e:
            self.functions["rocm_get_rsmi_version"] = None
        

        try:
            getattr(self.rocm_lib, "rsmi_version_str_get")
            self.rocm_lib.rsmi_version_str_get.argtypes = [ctypes.c_int, ctypes.POINTER(ctypes.c_char), ctypes.c_uint32]
            self.rocm_lib.rsmi_version_str_get.restype = ctypes.c_int
            self.functions["rocm_get_driver_version"] = self.rocm_lib.rsmi_version_str_get
        except Exception as e:
            self.functions["rocm_get_driver_version"] = None
        

        try:
            getattr(self.rocm_lib, "rsmi_dev_vbios_version_get")
            self.rocm_lib.rsmi_dev_vbios_version_get.argtypes = [ctypes.c_uint32, ctypes.POINTER(ctypes.c_char), ctypes.c_uint32]
            self.rocm_lib.rsmi_dev_vbios_version_get.restype = ctypes.c_int
            self.functions["rocm_get_device_vbios_version"] =self.rocm_lib.rsmi_dev_vbios_version_get
        except Exception as e:
            self.functions["rocm_get_device_vbios_version"] = None
        

        try:
            getattr(self.rocm_lib, "rsmi_dev_firmware_version_get")
            self.rocm_lib.rsmi_dev_firmware_version_get.argtypes = [ctypes.c_uint32, ctypes.c_uint, ctypes.POINTER(ctypes.c_uint64)]
            self.rocm_lib.rsmi_dev_firmware_version_get.restype = ctypes.c_int
            self.functions["rocm_get_device_firmware_version"] =self.rocm_lib.rsmi_dev_firmware_version_get
        except Exception as e:
            self.functions["rocm_get_device_firmware_version"] = None
        

        #Clock info
        try:
            getattr(self.rocm_lib, "rsmi_dev_gpu_clk_freq_get")
            self.rocm_lib.rsmi_dev_gpu_clk_freq_get.argtypes = [ctypes.c_uint32, ctypes.c_uint, ctypes.POINTER(rsmi_frequencies_t)]
            self.rocm_lib.rsmi_dev_gpu_clk_freq_get.restype = ctypes.c_int
            self.functions["rocm_get_clock_frequencies_info"] =self.rocm_lib.rsmi_dev_gpu_clk_freq_get
        except Exception as e:
            self.functions["rocm_get_clock_frequencies_info"] = None
        

        try:
            getattr(self.rocm_lib, "rsmi_dev_od_volt_info_get")
            self.rocm_lib.rsmi_dev_od_volt_info_get.argtypes = [ctypes.c_uint32, ctypes.POINTER(rsmi_od_volt_freq_data_t)]
            self.rocm_lib.rsmi_dev_od_volt_info_get.restype = ctypes.c_int
            self.functions["rocm_get_device_od_volt_info"] =self.rocm_lib.rsmi_dev_od_volt_info_get
        except Exception as e:
            self.functions["rocm_get_device_od_volt_info"] = None
        

        try:
            getattr(self.rocm_lib, "rsmi_dev_temp_metric_get")
            self.rocm_lib.rsmi_dev_temp_metric_get.argtypes = [ctypes.c_uint32, ctypes.c_uint32, ctypes.c_int, ctypes.POINTER(ctypes.c_int64)]
            self.rocm_lib.rsmi_dev_temp_metric_get.restype = ctypes.c_int
            self.functions["rocm_get_device_temperature"] = self.rocm_lib.rsmi_dev_temp_metric_get
        except Exception as e:
            self.functions["rocm_get_device_temperature"] = None
        