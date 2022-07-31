import ctypes
import enum
from typing import Any
from common_api import CommonAPI
from ctypes import *
from windows_amd_bindings import ADL_BusType, ADLBiosInfo, ADLChipSetInfo, ADLMemoryInfo2, AdapterInfoX2, Ctypes_ADL as cadl_win, ADLVersionsInfo, DetailedAsicTypes
from utils import bytes_to_megabytes
class WindowsAMD_API(CommonAPI):

    adl_clib = None

    def __init__(self) -> None:
        self.adl_clib = cadl_win()

    def initialize(self) -> None:
        self.adl_clib.functions["adl_initialize"]()

    def convert_enum_name_to_readable_string(self, enum_name: str, enum_type: enum.Enum) -> str:
        pass

    def finish(self) -> None:
        self.adl_clib.functions["adl_finish"]()

    def get_number_of_devices(self) -> int:
        numAdapters = ctypes.c_int()
        self.adl_clib.functions["adl_get_number_of_devices"](ctypes.byref(numAdapters))
        return numAdapters.value

    def get_device_handle_by_index(self, index) -> Any:
        return index

    def get_device_name_by_handle(self, handle) -> Any:
        device_index = ctypes.c_int(handle)
        numOfAdapters = self.get_number_of_devices()
        adapterInfoX2_object = (AdapterInfoX2 * numOfAdapters)()
        status = self.adl_clib.functions["adl_get_device_adapter_info"](adapterInfoX2_object, numOfAdapters)
        strAdapterName = None
        if status not in (0, 1):
            strAdapterName = "Not supported"
        else:
            strAdapterName = bytes(adapterInfoX2_object[device_index.value].strAdapterName).decode('ASCII')
        
        return strAdapterName

    def get_device_temperature_info(self, handle) -> Any:
        return "Not supported"
    
    def get_device_catalog_info(self, handle) -> Any:
        device_index = ctypes.c_int(handle)

        numOfAdapters = self.get_number_of_devices()
        adapterInfoX2_object = (AdapterInfoX2 * numOfAdapters)()
        status = self.adl_clib.functions["adl_get_device_adapter_info"](adapterInfoX2_object, numOfAdapters)
        iAdapterIndex = None
        strUDID = None
        iVendorID = None
        strDisplayName = None
        iPresent = None
        iExist =  None
        strDriverPath = None
        strDriverPathExt = None
        strPNPString = None
        iOSDisplayIndex = None

        if status not in (0, 1):
            iAdapterIndex = "Not supported"
            strUDID = "Not supported"
            iVendorID = "Not supported"
            strDisplayName = "Not supported"
            iPresent = "Not supported"
            iExist =  "Not supported"
            strDriverPath = "Not supported"
            strDriverPathExt = "Not supported"
            strPNPString = "Not supported"
            iOSDisplayIndex = "Not supported"
        else:
            iAdapterIndex = adapterInfoX2_object[device_index.value].iAdapterIndex
            strUDID = bytes(adapterInfoX2_object[device_index.value].strUDID).decode('ASCII')
            iVendorID = adapterInfoX2_object[device_index.value].iVendorID
            strDisplayName = bytes(adapterInfoX2_object[device_index.value].strDisplayName).decode('ASCII')
            iPresent = "No" if adapterInfoX2_object[device_index.value].iPresent == 0 else "Yes"
            iExist =  "No" if adapterInfoX2_object[device_index.value].iExist == 0 else "Yes"
            strDriverPath = bytes(adapterInfoX2_object[device_index.value].strDriverPath).decode('ASCII')
            strDriverPathExt = bytes(adapterInfoX2_object[device_index.value].strDriverPathExt).decode('ASCII')
            strPNPString = bytes(adapterInfoX2_object[device_index.value].strPNPString).decode('ASCII')
            iOSDisplayIndex = adapterInfoX2_object[device_index.value].iOSDisplayIndex

        #device_id = ctypes.c_int()
        #status = self.adl_clib.functions["adl_get_device_id"](device_index, ctypes.byref(device_id))
        #if status not in (0, 1):
        #    device_id = "Not supported"
        #else:
        #    device_id = device_id.value


        lpAsicTypes = ctypes.c_int()
        lpValids = ctypes.c_int()    
        asicTypes = list() 
        asicValids = list() 
        status = self.adl_clib.functions["adl_get_device_asic_family_type"](device_index, ctypes.byref(lpAsicTypes), ctypes.byref(lpValids))
        if status not in (0, 1):
            asicTypes = "Not supported"
            asicValids = "Not supported"
        else:
            lpAsicTypes = lpAsicTypes.value
            lpValids = lpValids.value
            for asic_types_dict_key, asic_types_dict_enum in DetailedAsicTypes.__members__.items():
                if asic_types_dict_key == "ADL_ASIC_UNDEFINED":
                    continue
                
                if asic_types_dict_enum.value & lpAsicTypes:
                    asicTypes.append(asic_types_dict_key.replace("ADL_ASIC_", "").replace("_"," "))

            for asic_valids_dict_key, asic_valids_dict_enum in DetailedAsicTypes.__members__.items():
                if asic_valids_dict_key == "ADL_ASIC_UNDEFINED":
                    continue
                
                if asic_valids_dict_enum.value & lpValids:
                    asicValids.append(asic_valids_dict_key.replace("ADL_ASIC_", "").replace("_"," ")) 


        is_accessible_status = ctypes.c_int()
        status = self.adl_clib.functions["adl_get_device_is_accessible_status"](device_index, ctypes.byref(is_accessible_status))
        if status not in (0,1):
            is_accessible_status = "Not supported"
        else:
            if is_accessible_status.value == 0:
                #False
                is_accessible_status = "No"
            else:
                #True
                is_accessible_status = "Yes"

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
            "Adapter index": iAdapterIndex,
            "Display name": strDisplayName,
            "Display index": iOSDisplayIndex,
            "Universal Unique Device Identifier (UUID)": strUDID,
            "Vendor ID": iVendorID,
            "Valid ASIC types": asicValids,
            "Current ASIC types": asicTypes,
            "Driver Path": strDriverPath,
            "Driver Path Ext": strDriverPathExt,
            "Plug and Play (PnP) string": strPNPString,
            "Does this adapter exist": iExist,
            "Is this adapter present": iPresent,
            "Is this adapter accessible": is_accessible_status,
            "Is this adapter active": is_active_status,
            "Is this adapter primary display adapter": primary_display_adapter_index
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

        vram_usage_in_MB = ctypes.c_int()
        status = self.adl_clib.functions["adl_get_device_vram_usage_info"](device_index, ctypes.byref(vram_usage_in_MB))
        if status not in (0, 1):
            vram_usage_in_MB = "Not supported"
        else:
            vram_usage_in_MB = vram_usage_in_MB.value

        dedicated_vram_usage_in_MB = ctypes.c_int()
        status = self.adl_clib.functions["adl_get_device_dedicated_vram_usage_info"](device_index, ctypes.byref(dedicated_vram_usage_in_MB))
        if status not in (0, 1):
            dedicated_vram_usage_in_MB = "Not supported"
        else:
            dedicated_vram_usage_in_MB = dedicated_vram_usage_in_MB.value

        return {
            "GPU Memory Total Size (MB)": memorySize,
            "GPU Memory Type": strMemoryType,
            "Visible Memory Size (MB)": iVisibleMemorySize,
            "Invisible Memory Size (MB)": iInvisibleMemorySize,
            "Hyper Memory Size (MB)": iHyperMemorySize,
            "Video RAM (VRAM) Usage (MB)": vram_usage_in_MB,
            "Dedicated Video RAM (VRAM) Usage (MB)": dedicated_vram_usage_in_MB,
            "Memory Bandwidth (MB/s)": iMemoryBandwidth,
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

        baseClock = ctypes.c_int()
        gameClock = ctypes.c_int()
        boostClock = ctypes.c_int()
        memoryClock = ctypes.c_int()
        status = self.adl_clib.functions["adl_get_device_observed_game_clock_info"](device_index, ctypes.byref(baseClock), ctypes.byref(gameClock), ctypes.byref(boostClock), ctypes.byref(memoryClock))
        if status not in (0, 1):
            baseClock = "Not supported"
            gameClock = "Not supported"
            boostClock = "Not supported"
            memoryClock = "Not supported"
        else:
            baseClock = baseClock.value
            gameClock = gameClock.value
            boostClock = boostClock.value
            memoryClock = memoryClock.value

        return {
           "Graphics (Core) clock (MHz)": lpCoreClock,
           "Memory clock (MHz)": lpMemoryClock,
           "Base clock (MHz)": baseClock,
           "Game clock (MHz)": gameClock,
           "Boost clock (MHz)": boostClock,
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
            lpChipSetInfo_busType = ADL_BusType(lpChipSetInfo.iBusType).name.replace("ADL_BUSTYPE_", "").replace("_", " ")
            lpChipSetInfo_BusSpeedType = ADL_BusType(lpChipSetInfo.iBusSpeedType).name.replace("ADL_BUSTYPE_", "").replace("_", " ")
            lpChipSetInfo_MaxPCIELaneWidth = lpChipSetInfo.iMaxPCIELaneWidth
            lpChipSetInfo_CurrentPCIELaneWidth = lpChipSetInfo.iCurrentPCIELaneWidth
            lpChipSetInfo_iSupportedAGPSpeeds = "Current bus type not AGP" if ADL_BusType(lpChipSetInfo.iBusType) != ADL_BusType.ADL_BUSTYPE_AGP \
                                                                            else lpChipSetInfo.iSupportedAGPSpeeds
            lpChipSetInfo_CurrentAGPSpeed = "Current bus type not AGP" if ADL_BusType(lpChipSetInfo.iBusType) != ADL_BusType.ADL_BUSTYPE_AGP \
                                                                            else lpChipSetInfo.iCurrentAGPSpeed

        numOfAdapters = self.get_number_of_devices()
        adapterInfoX2_object = (AdapterInfoX2 * numOfAdapters)()
        status = self.adl_clib.functions["adl_get_device_adapter_info"](adapterInfoX2_object, numOfAdapters)
        iBusNumber = None
        iDeviceNumber =  None
        iFunctionNumber = None
        if status not in (0, 1):
            iBusNumber = "Not supported"
            iDeviceNumber =  "Not supported"
            iFunctionNumber = "Not supported"
        else:
            iBusNumber = adapterInfoX2_object[device_index.value].iBusNumber
            iDeviceNumber =  adapterInfoX2_object[device_index.value].iDeviceNumber
            iFunctionNumber = adapterInfoX2_object[device_index.value].iFunctionNumber

        return {
            "Bus Number": "{0:#0{1}x}".format(iBusNumber, 4),
            "Device Number": "{0:#0{1}x}".format(iDeviceNumber, 4),
            "Function Number": "{0:#0{1}x}".format(iFunctionNumber, 3),
            "Bus type": lpChipSetInfo_busType,
            "Max bus speed type": lpChipSetInfo_BusSpeedType,
            "Max PCIe Lane Width (Lanes)": lpChipSetInfo_MaxPCIELaneWidth,
            "Current PCIe Lane Width (Lanes)": lpChipSetInfo_CurrentPCIELaneWidth,
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
