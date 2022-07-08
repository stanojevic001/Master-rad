import ctypes
from typing import Any
from common_api import CommonAPI, StatusCode
from ctypes import *
from windows_amd_bindings import ADLChipSetInfo, AdapterInfoX2, Ctypes_ADL as cadl_win, ADLVersionsInfo

class WindowsAMD_API(CommonAPI):

    adl_clib = None

    def __init__(self) -> None:
        self.adl_clib = cadl_win()

    def initialize(self) -> None:
        self.adl_clib.functions["adl_initialize"]()

    def finish(self) -> None:
        self.adl_clib.functions["adl_finish"]()

    def get_number_of_devices(self) -> int:
        numAdapters = ctypes.c_int()
        self.adl_clib.functions["adl_get_number_of_devices"](ctypes.byref(numAdapters))
        return numAdapters.value

    def get_device_handle_by_index(self, index) -> Any:
        return index

    def get_device_name_by_handle(self, handle) -> Any:
        return ""

    def get_device_temperature_info(self, handle) -> Any:
        return ""
    
    def get_device_catalog_info(self, handle) -> Any:
        device_index = ctypes.c_int(handle)

        numAdapters = ctypes.c_int()

        #lppAdapterInfoX2 = ctypes.POINTER(AdapterInfoX2)()
        #status = self.adl_clib.functions["adl_get_device_adapter_info"](device_index, ctypes.byref(numAdapters), ctypes.byref(lppAdapterInfoX2))
        #if status not in (self.adl_clib.ADL_OK, self.adl_clib.ADL_OK_WARNING):
        #    lppAdapterInfoX2 = "Not supported"
        #else:
        #    pass

        lpAsicTypes = ctypes.c_int()
        lpValids = ctypes.c_int()        
        status = self.adl_clib.functions["adl_get_device_asic_family_type"](device_index, ctypes.byref(lpAsicTypes), ctypes.byref(lpValids))
        if status not in (self.adl_clib.ADL_OK, self.adl_clib.ADL_OK_WARNING):
            lpAsicTypes = "Not supported"
            lpValids = "Not supported"
        else:
            lpAsicTypes = lpAsicTypes.value
            lpValids = lpValids.value
        
        return {
            "LP ASIC types": lpAsicTypes,
            "LP Valids": lpValids
        }
    
    def get_device_memory_info(self, handle) -> Any:
        return super().get_device_memory_info(handle)
    
    def get_device_clocks_info(self, handle) -> Any:
        return super().get_device_clocks_info(handle)
    
    def get_device_bus_info(self, handle) -> Any:
        device_index = ctypes.c_int(handle)

        lpChipSetInfo = ADLChipSetInfo()
        status = self.adl_clib.functions["adl_get_device_chipset_info"](device_index, ctypes.byref(lpChipSetInfo))
        lpChipSetInfo_busType = None
        lpChipSetInfo_BusSpeedType = None
        lpChipSetInfo_MaxPCIELaneWidth = None
        lpChipSetInfo_CurrentPCIELaneWidth = None
        lpChipSetInfo_iSupportedAGPSpeeds = None
        lpChipSetInfo_CurrentAGPSpeed = None

        if status not in (0, 1):
            lpChipSetInfo_busType = "Not supported"
            lpChipSetInfo_BusSpeedType = "Not supported"
            lpChipSetInfo_MaxPCIELaneWidth = "Not supported"
            lpChipSetInfo_CurrentPCIELaneWidth = "Not supported"
            lpChipSetInfo_iSupportedAGPSpeeds = "Not supported"
            lpChipSetInfo_CurrentAGPSpeed = "Not supported"
        else:
            lpChipSetInfo_busType = lpChipSetInfo.iBusType
            lpChipSetInfo_BusSpeedType = lpChipSetInfo.iBusSpeedType
            lpChipSetInfo_MaxPCIELaneWidth = lpChipSetInfo.iMaxPCIELaneWidth
            lpChipSetInfo_CurrentPCIELaneWidth = lpChipSetInfo.iCurrentPCIELaneWidth
            lpChipSetInfo_iSupportedAGPSpeeds = lpChipSetInfo.iSupportedAGPSpeeds
            lpChipSetInfo_CurrentAGPSpeed = lpChipSetInfo.iCurrentAGPSpeed

        return {
           "Bus type": lpChipSetInfo_busType,
           "Bus speed type": lpChipSetInfo_BusSpeedType,
           "Max PCIe Lane Width": lpChipSetInfo_MaxPCIELaneWidth,
           "Current PCIe Lane Width": lpChipSetInfo_CurrentPCIELaneWidth,
           "Supported AGP speeds": lpChipSetInfo_iSupportedAGPSpeeds,
           "Current AGP Speed": lpChipSetInfo_CurrentAGPSpeed
        }
    
    def get_device_versions_info(self, handle) -> Any:
        versionsInfo = ADLVersionsInfo()
        self.adl_clib.functions["adl_get_driver_version"](ctypes.byref(versionsInfo))
        driver_version =  bytes(versionsInfo.strDriverVer).decode('ASCII')

        return {
            "Driver version": driver_version
        }
