import ctypes
import enum

class ADLVersionsInfo(ctypes.Structure):
    _fields_ = [
        ('strDriverVer', ctypes.c_char * 256),
        ('strCatalystVersion', ctypes.c_char * 256),
        ('strCatalystWebLink', ctypes.c_char * 256)
    ]

class AdapterInfoX2(ctypes.Structure):
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

class ADLChipSetInfo(ctypes.Structure):
    _fields_ = [
        ('iBusType', ctypes.c_int),
        ('iBusSpeedType', ctypes.c_int),
        ('iMaxPCIELaneWidth', ctypes.c_int),
        ('iCurrentPCIELaneWidth', ctypes.c_int),
        ('iSupportedAGPSpeeds', ctypes.c_int),
        ('iCurrentAGPSpeed', ctypes.c_int)
    ]

class ADLMemoryInfo2(ctypes.Structure):
    _fields_ = [
        ('iMemorySize', ctypes.c_longlong),
        ('strMemoryType', ctypes.c_char * 256),
        ('iMemoryBandwidth', ctypes.c_longlong),
        ('iHyperMemorySize', ctypes.c_longlong),
        ('iInvisibleMemorySize', ctypes.c_longlong),
        ('iVisibleMemorySize', ctypes.c_longlong)
    ]

class ADLBiosInfo(ctypes.Structure):
    _fields_ = [
        ('strPartNumber', ctypes.c_char * 256),
        ('strVersion', ctypes.c_char * 256),
        ('strDate', ctypes.c_char * 256)
    ]

class ADLGcnInfo(ctypes.Structure):
	_fields_= [
        ('CuCount', ctypes.c_int),
        ('TexCount', ctypes.c_int),
        ('RopCount', ctypes.c_int),
        ('ASICFamilyId', ctypes.c_int),
        ('ASICRevisionId', ctypes.c_int)
    ]

class ADLVersionsInfoX2(ctypes.Structure):
    _fields_ = [
        ('strDriverVer', ctypes.c_char * 256),
        ('strCatalystVersion', ctypes.c_char * 256),
        ('strCrimsonVersion', ctypes.c_char * 256),
        ('strCatalystWebLink', ctypes.c_char * 256)
    ]

class ADLMemoryInfo3(ctypes.Structure):
    _fields_ = [
        ('iMemorySize', ctypes.c_longlong),
        ('strMemoryType', ctypes.c_char * 256),
        ('iMemoryBandwidth', ctypes.c_longlong),
        ('iHyperMemorySize', ctypes.c_longlong),
        ('iInvisibleMemorySize', ctypes.c_longlong),
        ('iVisibleMemorySize', ctypes.c_longlong),
        ('iVramVendorRevId', ctypes.c_longlong)
    ]

class ADLTemperature(ctypes.Structure):
  _fields_ = [
    ('iSize', ctypes.c_int),
    ('iTemperature', ctypes.c_int)
  ]

class DetailedAsicTypes(enum.IntEnum):
    ADL_ASIC_UNDEFINED    =  0
    ADL_ASIC_DISCRETE      = (1 << 0)
    ADL_ASIC_INTEGRATED    = (1 << 1)
    ADL_ASIC_WORKSTATION  =  (1 << 2)
    ADL_ASIC_FIREMV        = (1 << 3)
    ADL_ASIC_XGP           = (1 << 4)
    ADL_ASIC_FUSION        = (1 << 5)
    ADL_ASIC_FIRESTREAM    = (1 << 6)
    ADL_ASIC_EMBEDDED      = (1 << 7)
    ADL_ASIC_FIREGL = ADL_ASIC_WORKSTATION

class ADL_BusType(enum.IntEnum):
    ADL_BUSTYPE_PCI          = 0       # PCI bus                          
    ADL_BUSTYPE_AGP          = 1       # AGP bus                  
    ADL_BUSTYPE_PCIE         = 2       # PCI Express bus       
    ADL_BUSTYPE_PCIE_GEN2    = 3       # PCI Express 2nd generation bus
    ADL_BUSTYPE_PCIE_GEN3    = 4       # PCI Express 3rd generation bus
    ADL_BUSTYPE_PCIE_GEN4    = 5       # PCI Express 4th generation bus

class Ctypes_ADL():
    adl_lib = None
    functions = {
        "adl_initialize": None,
        "adl_finish": None,
        "adl_get_number_of_devices": None,
        "adl_get_driver_version": None,
        "adl_get_device_adapter_info": None,
        "adl_get_device_asic_family_type": None,
        "adl_get_device_chipset_info": None,
        "adl_get_device_id": None,
        "adl_get_device_memory_info2": None,
        "adl_get_device_vbios_info": None,
        "adl_get_device_observed_clock_info": None,
        "adl_get_primary_display_adapter_index": None,
        "adl_get_device_is_active_status": None,
        "adl_get_device_is_accessible_status": None,
        "adl_get_device_vram_usage_info": None,
        "adl_get_device_dedicated_vram_usage_info": None,
        "adl_get_device_observed_game_clock_info": None,
        "adl_get_device_gcn_asic_info": None,
        "adl_get_device_vm_page_size_info": None,
        "adl_get_driver_versionX3": None,
        "adl_get_device_memory_info3": None,
        "adl_get_device_overdrive5_temperature": None,
        "adl_get_device_aspects": None
    }

    def __init__(self) -> None:
        self.adl_lib: ctypes.WinDLL = ctypes.windll.LoadLibrary("amd_package\\windows\\windows_adl.dll")

        try:
            getattr(self.adl_lib, "initialize")
            self.adl_lib.initialize.argtypes = []
            self.adl_lib.initialize.restype = ctypes.c_int
            self.functions["adl_initialize"] = self.adl_lib.initialize
        except Exception as e:
            self.functions["adl_initialize"] = None

        try:
            getattr(self.adl_lib, "finish")
            self.adl_lib.finish.argtypes = []
            self.adl_lib.finish.restype = ctypes.c_int
            self.functions["adl_finish"] = self.adl_lib.finish
        except Exception as e:
            self.functions["adl_finish"] = None

        try:
            getattr(self.adl_lib, "get_driver_version")
            self.adl_lib.get_driver_version.argtypes = [ctypes.POINTER(ADLVersionsInfo)]
            self.adl_lib.get_driver_version.restype = ctypes.c_int
            self.functions["adl_get_driver_version"] = self.adl_lib.get_driver_version
        except Exception as e:
            self.functions["adl_get_driver_version"] = None

        try:
            getattr(self.adl_lib, "get_number_of_devices")
            self.adl_lib.get_number_of_devices.argtypes = [ctypes.POINTER(ctypes.c_int)]
            self.adl_lib.get_number_of_devices.restype = ctypes.c_int
            self.functions["adl_get_number_of_devices"] = self.adl_lib.get_number_of_devices
        except Exception as e:
            self.functions["adl_get_number_of_devices"] = None

        try:
            getattr(self.adl_lib, "get_device_adapter_info")
            self.adl_lib.get_device_adapter_info.argtypes = [ctypes.POINTER(AdapterInfoX2), ctypes.c_int]
            self.adl_lib.get_device_adapter_info.restype = ctypes.c_int
            self.functions["adl_get_device_adapter_info"] = self.adl_lib.get_device_adapter_info
        except Exception as e:
            self.functions["adl_get_device_adapter_info"] = None

        try:
            getattr(self.adl_lib, "get_device_asic_family_type")
            self.adl_lib.get_device_asic_family_type.argtypes = [ctypes.c_int, ctypes.POINTER(ctypes.c_int), ctypes.POINTER(ctypes.c_int)]
            self.adl_lib.get_device_asic_family_type.restype = ctypes.c_int
            self.functions["adl_get_device_asic_family_type"] = self.adl_lib.get_device_asic_family_type
        except Exception as e:
            self.functions["adl_get_device_asic_family_type"] = None


        try:
            getattr(self.adl_lib, "get_device_chipset_info")
            self.adl_lib.get_device_chipset_info.argtypes = [ctypes.c_int, ctypes.POINTER(ADLChipSetInfo)]
            self.adl_lib.get_device_chipset_info.restype = ctypes.c_int
            self.functions["adl_get_device_chipset_info"] = self.adl_lib.get_device_chipset_info
        except Exception as e:
            self.functions["adl_get_device_chipset_info"] = None

        try:
            getattr(self.adl_lib, "get_device_id")
            self.adl_lib.get_device_id.argtypes = [ctypes.c_int, ctypes.POINTER(ctypes.c_int)]
            self.adl_lib.get_device_id.restype = ctypes.c_int
            self.functions["adl_get_device_id"] = self.adl_lib.get_device_id
        except Exception as e:
            self.functions["adl_get_device_id"] = None

        try:
            getattr(self.adl_lib, "get_device_memory_info2")
            self.adl_lib.get_device_memory_info2.argtypes = [ctypes.c_int, ctypes.POINTER(ADLMemoryInfo2)]
            self.adl_lib.get_device_memory_info2.restype = ctypes.c_int
            self.functions["adl_get_device_memory_info2"] = self.adl_lib.get_device_memory_info2
        except Exception as e:
            self.functions["adl_get_device_memory_info2"] = None

        try:
            getattr(self.adl_lib, "get_device_vbios_info")
            self.adl_lib.get_device_vbios_info.argtypes = [ctypes.c_int, ctypes.POINTER(ADLBiosInfo)]
            self.adl_lib.get_device_vbios_info.restype = ctypes.c_int
            self.functions["adl_get_device_vbios_info"] = self.adl_lib.get_device_vbios_info
        except Exception as e:
            self.functions["adl_get_device_vbios_info"] = None

        try:
            getattr(self.adl_lib, "get_device_observed_clock_info")
            self.adl_lib.get_device_observed_clock_info.argtypes = [ctypes.c_int, ctypes.POINTER(ctypes.c_int), ctypes.POINTER(ctypes.c_int)]
            self.adl_lib.get_device_observed_clock_info.restype = ctypes.c_int
            self.functions["adl_get_device_observed_clock_info"] = self.adl_lib.get_device_observed_clock_info
        except Exception as e:
            self.functions["adl_get_device_observed_clock_info"] = None

        try:
            getattr(self.adl_lib, "get_primary_display_adapter_index")
            self.adl_lib.get_primary_display_adapter_index.argtypes = [ctypes.POINTER(ctypes.c_int)]
            self.adl_lib.get_primary_display_adapter_index.restype = ctypes.c_int
            self.functions["adl_get_primary_display_adapter_index"] = self.adl_lib.get_primary_display_adapter_index
        except Exception as e:
            self.functions["adl_get_primary_display_adapter_index"] = None

        try:
            getattr(self.adl_lib, "get_device_is_active_status")
            self.adl_lib.get_device_is_active_status.argtypes = [ctypes.c_int, ctypes.POINTER(ctypes.c_int)]
            self.adl_lib.get_device_is_active_status.restype = ctypes.c_int
            self.functions["adl_get_device_is_active_status"] = self.adl_lib.get_device_is_active_status
        except Exception as e:
            self.functions["adl_get_device_is_active_status"] = None

        try:
            getattr(self.adl_lib, "get_device_is_accessible_status")
            self.adl_lib.get_device_is_accessible_status.argtypes = [ctypes.c_int, ctypes.POINTER(ctypes.c_int)]
            self.adl_lib.get_device_is_accessible_status.restype = ctypes.c_int
            self.functions["adl_get_device_is_accessible_status"] = self.adl_lib.get_device_is_accessible_status
        except Exception as e:
            self.functions["adl_get_device_is_accessible_status"] = None

        try:
            getattr(self.adl_lib, "get_device_vram_usage_info")
            self.adl_lib.get_device_vram_usage_info.argtypes = [ctypes.c_int, ctypes.POINTER(ctypes.c_int)]
            self.adl_lib.get_device_vram_usage_info.restype = ctypes.c_int
            self.functions["adl_get_device_vram_usage_info"] = self.adl_lib.get_device_vram_usage_info
        except Exception as e:
            self.functions["adl_get_device_vram_usage_info"] = None

        try:
            getattr(self.adl_lib, "get_device_dedicated_vram_usage_info")
            self.adl_lib.get_device_dedicated_vram_usage_info.argtypes = [ctypes.c_int, ctypes.POINTER(ctypes.c_int)]
            self.adl_lib.get_device_dedicated_vram_usage_info.restype = ctypes.c_int
            self.functions["adl_get_device_dedicated_vram_usage_info"] = self.adl_lib.get_device_dedicated_vram_usage_info
        except Exception as e:
            self.functions["adl_get_device_dedicated_vram_usage_info"] = None

        try:
            getattr(self.adl_lib, "get_device_observed_game_clock_info")
            self.adl_lib.get_device_observed_game_clock_info.argtypes = [ctypes.c_int, ctypes.POINTER(ctypes.c_int), ctypes.POINTER(ctypes.c_int), ctypes.POINTER(ctypes.c_int), ctypes.POINTER(ctypes.c_int)]
            self.adl_lib.get_device_observed_game_clock_info.restype = ctypes.c_int
            self.functions["adl_get_device_observed_game_clock_info"] = self.adl_lib.get_device_observed_game_clock_info
        except Exception as e:
            self.functions["adl_get_device_observed_game_clock_info"] = None

        try:
            getattr(self.adl_lib, "get_device_gcn_asic_info")
            self.adl_lib.get_device_gcn_asic_info.argtypes = [ctypes.c_int, ctypes.POINTER(ADLGcnInfo)]
            self.adl_lib.get_device_gcn_asic_info.restype = ctypes.c_int
            self.functions["adl_get_device_gcn_asic_info"] = self.adl_lib.get_device_gcn_asic_info
        except Exception as e:
            self.functions["adl_get_device_gcn_asic_info"] = None

        try:
            getattr(self.adl_lib, "get_driver_versionX3")
            self.adl_lib.get_driver_versionX3.argtypes = [ctypes.c_int, ctypes.POINTER(ADLVersionsInfoX2)]
            self.adl_lib.get_driver_versionX3.restype = ctypes.c_int
            self.functions["adl_get_driver_versionX3"] = self.adl_lib.get_driver_versionX3
        except Exception as e:
            self.functions["adl_get_driver_versionX3"] = None

        try:
            getattr(self.adl_lib, "get_device_memory_info3")
            self.adl_lib.get_device_memory_info3.argtypes = [ctypes.c_int, ctypes.POINTER(ADLMemoryInfo3)]
            self.adl_lib.get_device_memory_info3.restype = ctypes.c_int
            self.functions["adl_get_device_memory_info3"] = self.adl_lib.get_device_memory_info3
        except Exception as e:
            self.functions["adl_get_device_memory_info3"] = None

        try:
            getattr(self.adl_lib, "get_device_overdrive5_temperature")
            self.adl_lib.get_device_overdrive5_temperature.argtypes = [ctypes.c_int, ctypes.c_int, ctypes.POINTER(ADLTemperature)]
            self.adl_lib.get_device_overdrive5_temperature.restype = ctypes.c_int
            self.functions["adl_get_device_overdrive5_temperature"] = self.adl_lib.get_device_overdrive5_temperature
        except Exception as e:
            self.functions["adl_get_device_overdrive5_temperature"] = None

        try:
            getattr(self.adl_lib, "get_device_aspects")
            self.adl_lib.get_device_aspects.argtypes = [ctypes.c_int, ctypes.POINTER(ctypes.c_char), ctypes.c_int]
            self.adl_lib.get_device_aspects.restype = ctypes.c_int
            self.functions["adl_get_device_aspects"] = self.adl_lib.get_device_aspects
        except Exception as e:
            self.functions["adl_get_device_aspects"] = None