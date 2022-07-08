import ctypes
from typing import Any
from common_api import CommonAPI, StatusCode
from ctypes import *
from windows_amd_bindings import ADLBiosInfo, ADLChipSetInfo, ADLMemoryInfo2, AdapterInfoX2, Ctypes_ADL as cadl_win, ADLVersionsInfo
from utils import bytes_to_megabytes
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

        
        #numAdapters = ctypes.c_int()
        #lppAdapterInfoX2 = ctypes.POINTER(AdapterInfoX2)()
        #status = self.adl_clib.functions["adl_get_device_adapter_info"](device_index, ctypes.byref(numAdapters), ctypes.byref(lppAdapterInfoX2))
        #if status not in (self.adl_clib.ADL_OK, self.adl_clib.ADL_OK_WARNING):
        #    lppAdapterInfoX2 = "Not supported"
        #else:
        #    pass

        device_id = ctypes.c_int()
        status = self.adl_clib.functions["adl_get_device_id"](device_index, ctypes.byref(device_id))
        if status not in (0, 1):
            device_id = "Not supported"
        else:
            device_id = device_id.value


        lpAsicTypes = ctypes.c_int()
        lpValids = ctypes.c_int()        
        status = self.adl_clib.functions["adl_get_device_asic_family_type"](device_index, ctypes.byref(lpAsicTypes), ctypes.byref(lpValids))
        if status not in (0, 1):
            lpAsicTypes = "Not supported"
            lpValids = "Not supported"
        else:
            lpAsicTypes = lpAsicTypes.value
            lpValids = lpValids.value

        primary_display_adapter_index = ctypes.c_int()
        status = self.adl_clib.functions["adl_get_primary_display_adapter_index"](ctypes.byref(primary_display_adapter_index))
        if status not in (0, 1):
            primary_display_adapter_index = "Not supported"
        else:
            primary_display_adapter_index = primary_display_adapter_index.value
            if device_index.value == primary_display_adapter_index:
                primary_display_adapter_index = "Yes"
            else:
                primary_display_adapter_index = "No"
        
        is_active_status = ctypes.c_int()        
        status = self.adl_clib.functions["adl_get_device_is_active_status"](device_index, ctypes.byref(is_active_status))
        if status not in (0, 1):
            is_active_status = "Not supported"
        else:
            if is_active_status.value == 0:
                #False
                is_active_status = "No"
            else:
                #True
                is_active_status = "Yes"
        
        return {
            "Device ID": device_id,
            "LP ASIC types": lpAsicTypes,
            "LP Valids": lpValids,
            "Is primary display adapter": primary_display_adapter_index,
            "Is adapter active": is_active_status
        }
    
    def get_device_memory_info(self, handle) -> Any:
        device_index = ctypes.c_int(handle)
        memory_info2 = ADLMemoryInfo2()
        status = self.adl_clib.functions["adl_get_device_memory_info2"](device_index, ctypes.byref(memory_info2))
        memorySize = None
        strMemoryType = None
        iMemoryBandwidth = None
        iHyperMemorySize = None
        iInvisibleMemorySize = None
        iVisibleMemorySize = None
        if status not in (0, 1):
            memorySize = "Not supported"
            strMemoryType = "Not supported"
            iMemoryBandwidth = "Not supported"
            iHyperMemorySize = "Not supported"
            iInvisibleMemorySize = "Not supported"
            iVisibleMemorySize = "Not supported"
        else:
            memorySize = bytes_to_megabytes(memory_info2.iMemorySize)
            strMemoryType = bytes(memory_info2.strMemoryType).decode('ASCII')
            iMemoryBandwidth = memory_info2.iMemoryBandwidth
            iHyperMemorySize = bytes_to_megabytes(memory_info2.iHyperMemorySize)
            iInvisibleMemorySize = bytes_to_megabytes(memory_info2.iInvisibleMemorySize)
            iVisibleMemorySize = bytes_to_megabytes(memory_info2.iVisibleMemorySize)

        return {
            "Memory Size": memorySize,
            "Memory Type": strMemoryType,
            "Memory Bandwidth": iMemoryBandwidth,
            "Hyper Memory Size": iHyperMemorySize,
            "InvisibleMemory Size": iInvisibleMemorySize,
            "Visible Memory Size": iVisibleMemorySize
        }

    def get_device_clocks_info(self, handle) -> Any:
        device_index = ctypes.c_int(handle)

        lpCoreClock = ctypes.c_int()
        lpMemoryClock = ctypes.c_int()
        status = self.adl_clib.functions["adl_get_device_observed_clock_info"](device_index, ctypes.byref(lpCoreClock), ctypes.byref(lpMemoryClock))

        if status not in (0, 1):
            lpCoreClock = "Not supported"
            lpMemoryClock = "Not supported"
        else:
            lpCoreClock = lpCoreClock.value
            lpMemoryClock = lpMemoryClock.value

        return {
           "Core clock (MHz)": lpCoreClock,
           "Memory clock (MHz)": lpMemoryClock
        }
    
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
        device_index = ctypes.c_int(handle)

        versionsInfo = ADLVersionsInfo()
        self.adl_clib.functions["adl_get_driver_version"](ctypes.byref(versionsInfo))
        driver_version =  bytes(versionsInfo.strDriverVer).decode('ASCII')

        vbios_info = ADLBiosInfo()
        status = self.adl_clib.functions["adl_get_device_vbios_info"](device_index, ctypes.byref(vbios_info))
        vbios_info_strPartNumber = None
        vbios_info_strVersion = None
        vbios_info_strDate = None
        if status not in (0, 1):
            vbios_info_strPartNumber = "Not supported"
            vbios_info_strVersion = "Not supported"
            vbios_info_strDate = "Not supported"
        else:
            vbios_info_strPartNumber = bytes(vbios_info.strPartNumber).decode('ASCII')
            vbios_info_strVersion = bytes(vbios_info.strVersion).decode('ASCII')
            vbios_info_strDate = bytes(vbios_info.strDate).decode('ASCII')

        return {
            "Driver version": driver_version,
            "VBIOS part number": vbios_info_strPartNumber,
            "VBIOS version": vbios_info_strVersion,
            "VBIOS date": vbios_info_strDate
        }
