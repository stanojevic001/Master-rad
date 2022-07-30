import ctypes
from typing import Any
from common_api import CommonAPI
from defines import *
from linux_rocm_smi_bindings import Ctypes_ROCm as crocm, rsmi_clk_type_t, rsmi_frequencies_t, rsmi_fw_block_t, rsmi_memory_type_t, rsmi_retired_page_record_t, rsmi_pcie_bandwidth_t, rsmi_version_t
from utils import bytes_to_gigabytes, hz_to_gigahz_int

class Linux_ROCm_SMI_Wrapper(CommonAPI):
    rocm_clib = None

    def __init__(self) -> None:
        self.rocm_clib = crocm()

    def convert_enum_name_to_readable_string(self, enum_name: str, enum_type: Enum) -> str:
        result = ""
        if type(enum_type) == rsmi_clk_type_t:
            if "RSMI_CLK_TYPE_SYS" == enum_name:
                result = "System"
            elif "RSMI_CLK_TYPE_DF" == enum_name:
                result = "Data Fabric (DF)"
            elif "RSMI_CLK_TYPE_DCEF" == enum_name:
                result = "Display Controller Engine (DCEF)"
            elif "RSMI_CLK_TYPE_SOC" == enum_name:
                result = "SoC (System-on-a-Chip)"
            elif "RSMI_CLK_TYPE_MEM" == enum_name:
                result = "Memory"
            result += " clock"

        elif type(enum_type) == rsmi_fw_block_t:
            if "RSMI_FW_BLOCK_ASD" == enum_name:
                result = "ASD"
            elif "RSMI_FW_BLOCK_CE" == enum_name:
                result = "CE"
            elif "RSMI_FW_BLOCK_DMCU" == enum_name:
                result = "DMCU"
            elif "RSMI_FW_BLOCK_MC" == enum_name:
                result = "MC"
            elif "RSMI_FW_BLOCK_ME" == enum_name:
                result = "ME"
            elif "RSMI_FW_BLOCK_MEC" == enum_name:
                result = "MEC"
            elif "RSMI_FW_BLOCK_MEC2" == enum_name:
                result = "MEC2"
            elif "RSMI_FW_BLOCK_PFP" == enum_name:
                result = "PFP"
            elif "RSMI_FW_BLOCK_RLC" == enum_name:
                result = "RLC"
            elif "RSMI_FW_BLOCK_RLC_SRLC" == enum_name:
                result = "SRLC"
            elif "RSMI_FW_BLOCK_RLC_SRLG" == enum_name:
                result = "SRLG"
            elif "RSMI_FW_BLOCK_RLC_SRLS" == enum_name:
                result = "SRLS"
            elif "RSMI_FW_BLOCK_SDMA" == enum_name:
                result = "SDMA"
            elif "RSMI_FW_BLOCK_SDMA2" == enum_name:
                result = "SDMA2"
            elif "RSMI_FW_BLOCK_SMC" == enum_name:
                result = "SMC"
            elif "RSMI_FW_BLOCK_SOS" == enum_name:
                result = "SOS"
            elif "RSMI_FW_BLOCK_TA_RAS" == enum_name:
                result = "TA_RAS"
            elif "RSMI_FW_BLOCK_TA_XGMI" == enum_name:
                result = "TA_XGMI"
            elif "RSMI_FW_BLOCK_UVD" == enum_name:
                result = "UVD"
            elif "RSMI_FW_BLOCK_VCE" == enum_name:
                result = "VCE"
            elif "RSMI_FW_BLOCK_VCN" == enum_name:
                result = "VCN"
            result += " block"

        elif type(enum_type) == rsmi_memory_type_t:
            if "RSMI_MEM_TYPE_VRAM" == enum_name:
                result = "Video RAM (VRAM)"
            elif "RSMI_MEM_TYPE_VIS_VRAM" == enum_name:
                result = "Visible video RAM (VRAM)"
            elif "RSMI_MEM_TYPE_GTT" == enum_name:
                result = "Graphics Translation Table (GTT)"
            result += " memory"
        return result

    def initialize(self) -> None:
        flag = ctypes.c_uint64(0)
        self.rocm_clib.functions["rocm_initialize"](flag)

    def finish(self) -> None:
        
        self.rocm_clib.functions["rocm_finish"]()

    def get_number_of_devices(self) -> int:
        
        number_of_devices = ctypes.c_uint32()
        self.rocm_clib.functions["rocm_get_number_of_devices"](ctypes.byref(number_of_devices))
        ret_value = number_of_devices.value

        return ret_value

    def get_device_handle_by_index(self, index) -> Any:
        return index

    def get_device_temperature_info(self, handle) -> Any:
        return "Not supported"
    
    def get_device_clocks_info(self, handle) -> Any:
        device_index = ctypes.c_uint32(handle)
        clock_frequencies_info = {}
        for clock_type_dict_key, clock_type_dict_enum in rsmi_clk_type_t.__members__.items():
            if clock_type_dict_key in ("RSMI_CLK_TYPE_FIRST", "RSMI_CLK_TYPE_LAST", "RSMI_CLK_INVALID"):
                continue
            frequencies = rsmi_frequencies_t()
            clock_type_name = self.convert_enum_name_to_readable_string(clock_type_dict_key, clock_type_dict_enum)
            clock_frequencies_info[clock_type_name] = {}
            status = self.rocm_clib.functions["rocm_get_clock_frequencies_info"](device_index, clock_type_dict_enum, ctypes.byref(frequencies))
            num_supported_freq =  None
            current_freq = None
            frequency = None
            num_supported_freq_output =  None
            current_freq_output = None
            frequency_output = []
            if status != 0:
                clock_frequencies_info[clock_type_name] = "Not supported"
            else:
                num_supported_freq = frequencies.num_supported
                current_freq = frequencies.current
                frequency = frequencies.frequency
                if len(frequency) <= 0:
                    frequency_output = ""
                    current_freq_output = ""
                else:
                    for j in range(0, num_supported_freq):
                        if j == current_freq:
                            current_freq_output = hz_to_gigahz_int(frequency[j])
                        frequency_output.append(hz_to_gigahz_int(frequency[j]))
                num_supported_freq_output = num_supported_freq
                clock_frequencies_info[clock_type_name] = {
                    "Num of supported clock frequencies": num_supported_freq_output,
                    "Supported clock frequencies (GHz)": frequency_output,
                    "Current clock frequency (GHz)": current_freq_output
                }
            
        return {
            "Clock frequencies info": clock_frequencies_info
        }

    def get_device_name_by_handle(self, handle) -> Any:
        
        index = ctypes.c_uint32(handle)
        name = (ctypes.c_char * 500)()
        len = ctypes.c_size_t(500)

        self.rocm_clib.functions["rocm_get_device_name_by_handle"](index, name, len)
        return bytes(name.value).decode('ASCII')
    
    def get_device_memory_info(self, handle) -> Any:
        device_index = ctypes.c_uint32(handle)

        total_memories_by_type = dict()
        for memory_type_dict_key, memory_type_dict_enum in rsmi_memory_type_t.__members__.items():
            if memory_type_dict_key in ("RSMI_MEM_TYPE_FIRST", "RSMI_MEM_TYPE_LAST"):
                continue
            memory_type_name = self.convert_enum_name_to_readable_string(memory_type_dict_key, memory_type_dict_enum)
            total_mem_by_type = ctypes.c_uint64(0)
            status = self.rocm_clib.functions["rocm_get_device_memory_total"](device_index, memory_type_dict_enum, ctypes.byref(total_mem_by_type))
            if status != 0:
                total_memories_by_type[memory_type_name] = "Not supported"
            else:
                total_memories_by_type[memory_type_name] = bytes_to_gigabytes(total_mem_by_type.value)


        total_memory_usages_by_type = dict()
        for memory_usage_type_dict_key, memory_usage_type_dict_enum in rsmi_memory_type_t.__members__.items():
            if memory_usage_type_dict_key in ("RSMI_MEM_TYPE_FIRST", "RSMI_MEM_TYPE_LAST"):
                continue
            total_mem_usage_by_type = ctypes.c_uint64(0)
            memory_usage_type_name = self.convert_enum_name_to_readable_string(memory_usage_type_dict_key, memory_usage_type_dict_enum)
            status = self.rocm_clib.functions["rocm_get_device_memory_usage"](device_index, memory_usage_type_dict_enum, ctypes.byref(total_mem_usage_by_type))
            if status != 0:
                total_memory_usages_by_type[memory_usage_type_name] = "Not supported"
            else:
                total_memory_usages_by_type[memory_usage_type_name] = bytes_to_gigabytes(total_mem_usage_by_type.value)


        busy_percent = ctypes.c_uint32(0)
        status = self.rocm_clib.functions["rocm_get_device_memory_busy_percent"](device_index, ctypes.byref(busy_percent))
        if status != 0:
            busy_percent = "Not supported"
        else:
            busy_percent = busy_percent.value

        num_pages = ctypes.c_uint32()
        records = ctypes.pointer(rsmi_retired_page_record_t())
        records_output = []
        status = self.rocm_clib.functions["rocm_get_device_memory_reserved_pages"](device_index, ctypes.byref(num_pages), records)
        if status != 0:
            num_pages = "Not supported"
            records_output = "Not supported"
        else:
            num_pages = num_pages.value
            records = records[:num_pages]
            if num_pages <= 0:
                records_output = ""
            else:
                for i in range(0, num_pages):
                    records_output.append({
                    "Page address": records[i].page_address,
                    "Page size": records[i].page_size,
                    "Status": records[i].status
                    })


        return {
            "Total memory amount by type (GBs)": total_memories_by_type,
            "Total memory usages by type (GBs)": total_memory_usages_by_type,
            "Busy percent": busy_percent,
            "Retired pages number": num_pages,
            "Retired pages records": records_output
        }

    def get_device_bus_info(self, handle) -> Any:
        device_index = ctypes.c_uint32(handle)
        
        pcie_bandwidth = rsmi_pcie_bandwidth_t()
        status = self.rocm_clib.functions["rocm_get_device_pci_bandwidth"](device_index, ctypes.byref(pcie_bandwidth))
        pcie_bandwidth_transfer_rate = None
        pcie_bandwidth_transfer_rate_num_supported = None
        pcie_bandwidth_transfer_rate_output_num_supported = None
        pcie_bandwidth_transfer_rate_current = None
        pcie_bandwidth_transfer_rate_output_current = None
        pcie_bandwidth_transfer_rate_frequency = []
        pcie_bandwidth_transfer_rate_output_frequency = []
        pcie_bandwidth_lanes = None
        pcie_bandwidth_lanes_output = []
        if status != 0:
            pcie_bandwidth_transfer_rate = "Not supported"
            pcie_bandwidth_lanes = "Not supported"
        else:
            pcie_bandwidth_transfer_rate = pcie_bandwidth.transfer_rate
            pcie_bandwidth_transfer_rate_num_supported = pcie_bandwidth_transfer_rate.num_supported
            pcie_bandwidth_transfer_rate_current = pcie_bandwidth_transfer_rate.current
            pcie_bandwidth_transfer_rate_frequency = pcie_bandwidth_transfer_rate.frequency
            if len(pcie_bandwidth_transfer_rate_frequency) <= 0:
                pcie_bandwidth_transfer_rate_output_frequency = ""
                pcie_bandwidth_transfer_rate_output_current = ""
            else:
                for j in range(0, pcie_bandwidth_transfer_rate_num_supported):
                    if j == pcie_bandwidth_transfer_rate_current:
                        pcie_bandwidth_transfer_rate_output_current = hz_to_gigahz_int(pcie_bandwidth_transfer_rate_frequency[j])
                    pcie_bandwidth_transfer_rate_output_frequency.append(hz_to_gigahz_int(pcie_bandwidth_transfer_rate_frequency[j]))
            pcie_bandwidth_transfer_rate_output_num_supported = pcie_bandwidth_transfer_rate_num_supported
            pcie_bandwidth_lanes = pcie_bandwidth.lanes
            if len(pcie_bandwidth_lanes) <= 0:
                pcie_bandwidth_lanes_output = ""
            else:
                for i in range(0, pcie_bandwidth_transfer_rate_num_supported):
                    pcie_bandwidth_lanes_output.append(pcie_bandwidth_lanes[i])
        
        bdfid = ctypes.c_uint64()
        status = self.rocm_clib.functions["rocm_get_device_pci_id"](device_index, ctypes.byref(bdfid))
        if status != 0:
            bdfid = "Not supported"
        else:
            bdfid = bdfid.value
        
        sent = ctypes.c_uint64()
        received = ctypes.c_uint64()
        max_pkt_sz = ctypes.c_uint64()
        status = self.rocm_clib.functions["rocm_get_device_pci_throughput"](device_index, ctypes.byref(sent), ctypes.byref(received), ctypes.byref(max_pkt_sz))
        if status != 0:
            sent = "Not supported"
            received = "Not supported"
            sent = "Not supported"
        else:
            sent = sent.value
            received = received.value
            max_pkt_sz = max_pkt_sz.value
        
        counter = ctypes.c_uint64()
        status = self.rocm_clib.functions["rocm_get_device_pci_replay_counter"](device_index, ctypes.byref(counter))
        if status != 0:
            counter = "Not supported"
        else:
            counter = counter.value

        return {
            "PCIe Number of supported frequencies": pcie_bandwidth_transfer_rate_output_num_supported,
            "PCIe Supported frequencies (GHz)": pcie_bandwidth_transfer_rate_output_frequency,
            "PCIe Current frequency (GHz)": pcie_bandwidth_transfer_rate_output_current,
            "PCIe Supported lanes": pcie_bandwidth_lanes_output,
            "PCIe BDF number (Bus, Device, Function)": bdfid,
            "PCIe Throughput - Sent packets": sent,
            "PCIe Throughput - Received packets": received,
            "PCIe Throughput - Max packet size": max_pkt_sz,
            "PCIe Replay Counter": counter
        }
    
    def get_device_catalog_info(self, handle) -> Any:
        device_index = ctypes.c_uint32(handle)
        status = ctypes.c_int()

        device_id = ctypes.c_uint16()
        status = self.rocm_clib.functions["rocm_get_device_id"](device_index, ctypes.byref(device_id))
        if status != 0:
            device_id = "Not supported"
        else:
            device_id = device_id.value

        #device_sku = ctypes.c_uint16()
        #status = self.rocm_clib.functions["rocm_get_device_sku"](device_index, ctypes.byref(device_sku))
        #if status != 0:
        #    device_sku = "Not supported"
        #else:
        #    device_sku = bytes(device_sku.value).decode('ASCII')

        vendor_id = ctypes.c_uint16()
        status = self.rocm_clib.functions["rocm_get_device_vendor_id"](device_index, ctypes.byref(vendor_id))
        if status != 0:
            vendor_id = "Not supported"
        else:
            vendor_id = vendor_id.value

        brand_name = (ctypes.c_char * 200)()
        brand_len = ctypes.c_uint32(200)
        status = self.rocm_clib.functions["rocm_get_device_brand"](device_index, brand_name, brand_len)
        if status != 0:
            brand_name = "Not supported"
        else:
            brand_name = bytes(brand_name.value).decode('ASCII')

        vendor_name = (ctypes.c_char * 200)()
        vendor_name_len = ctypes.c_size_t(200)
        status = self.rocm_clib.functions["rocm_get_device_vendor_name"](device_index, vendor_name, vendor_name_len)
        if status != 0:
            vendor_name = "Not supported"
        else:
            vendor_name = bytes(vendor_name.value).decode('ASCII')

        vram_vendor_name = (ctypes.c_char * 200)()
        vram_vendor_len = ctypes.c_uint32(200)
        status = self.rocm_clib.functions["rocm_get_device_vram_vendor"](device_index, vram_vendor_name, vram_vendor_len)
        if status != 0:
            vram_vendor_name = "Not supported"
        else:
            vram_vendor_name = bytes(vram_vendor_name.value).decode('ASCII').upper()

        serial_number = (ctypes.c_char * 200)()
        serial_num_len = ctypes.c_uint32(200)
        status = self.rocm_clib.functions["rocm_get_device_serial_number"](device_index, serial_number, serial_num_len)
        if status != 0:
            serial_number = "Not supported"
        else:
            serial_number = bytes(serial_number.value).decode('ASCII')

        device_subsystem_id = ctypes.c_uint16()
        status = self.rocm_clib.functions["rocm_get_device_subsystem_id"](device_index, ctypes.byref(device_subsystem_id))
        if status != 0:
            device_subsystem_id = "Not supported"
        else:
            device_subsystem_id = device_subsystem_id.value

        device_subsystem_name = (ctypes.c_char * 200)()
        device_subsystem_name_len = ctypes.c_size_t(200)
        status = self.rocm_clib.functions["rocm_get_device_subsystem_name"](device_index, device_subsystem_name, device_subsystem_name_len)
        if status != 0:
            device_subsystem_name = "Not supported"
        else:
            device_subsystem_name = bytes(device_subsystem_name.value).decode('ASCII')

        minor_number = ctypes.c_uint32()
        status = self.rocm_clib.functions["rocm_get_device_drm_render_minor"](device_index, ctypes.byref(minor_number))
        if status != 0:
            minor_number = "Not supported"
        else:
            minor_number = minor_number.value

        subsystem_vendor_id = ctypes.c_uint16()
        status = self.rocm_clib.functions["rocm_get_device_subsystem_vendor_id"](device_index, ctypes.byref(subsystem_vendor_id))
        if status != 0:
            subsystem_vendor_id = "Not supported"
        else:
            subsystem_vendor_id = subsystem_vendor_id.value

        unique_id = ctypes.c_uint64()
        status = self.rocm_clib.functions["rocm_get_device_unique_id"](device_index, ctypes.byref(unique_id))
        if status != 0:
            unique_id = "Not supported"
        else:
            unique_id = unique_id.value
        

        return {
            "Device ID": device_id,
            "Brand name": brand_name,
            "Vendor ID": vendor_id,
            "Vendor name": vendor_name,
            "Video RAM (VRAM) vendor name": vram_vendor_name,
            "Serial number": serial_number,
            "Subsystem ID": device_subsystem_id,
            "Subsystem name": device_subsystem_name,
            "Subsystem vendor ID": subsystem_vendor_id,
            "Minor number": minor_number,
            "Unique ID": unique_id,
        }
    
    def get_device_versions_info(self, handle) -> Any:
        device_index = ctypes.c_uint32(handle)
 
        rsmi_version = rsmi_version_t()
        status = self.rocm_clib.functions["rocm_get_rsmi_version"](ctypes.byref(rsmi_version))
        rsmi_version_major = ""
        rsmi_version_minor = ""
        rsmi_version_patch = ""
        rsmi_version_build = ""
        if status != 0:
            rsmi_version_major = "Not supported"
            rsmi_version_minor = "Not supported"
            rsmi_version_patch = "Not supported"
            rsmi_version_build = "Not supported"
        else:
            rsmi_version_major = rsmi_version.major
            rsmi_version_minor = rsmi_version.minor
            rsmi_version_patch = rsmi_version.patch
            rsmi_version_build = bytes(rsmi_version.build).decode('ASCII')
 
        sw_component = ctypes.c_int(0)
        driver_version = (ctypes.c_char * 200)()
        version_len = ctypes.c_uint32(200)
        status = self.rocm_clib.functions["rocm_get_driver_version"](sw_component, driver_version, version_len)
        if status != 0:
            driver_version = "Not supported"
        else:
            driver_version = bytes(driver_version.value).decode('ASCII')

        vbios_version = (ctypes.c_char * 200)()
        vbios_len = ctypes.c_uint32(200)
        status = self.rocm_clib.functions["rocm_get_device_vbios_version"](device_index, vbios_version, vbios_len)
        if status != 0:
            vbios_version = "Not supported"
        else:
            vbios_version = bytes(vbios_version.value).decode('ASCII')

        fw_versions = {}
        for block_type_dict_key, block_type_dict_enum in rsmi_fw_block_t.__members__.items():
            if block_type_dict_key in ("RSMI_FW_BLOCK_FIRST", "RSMI_FW_BLOCK_LAST"):
                continue
            fw_version = ctypes.c_uint64()
            block_name = self.convert_enum_name_to_readable_string(block_type_dict_key, block_type_dict_enum)
            status = self.rocm_clib.functions["rocm_get_device_firmware_version"](device_index, block_type_dict_enum, ctypes.byref(fw_version))
            if status != 0:
                fw_version = "Not supported"
                fw_versions[block_name] = "Not supported"
            else:
                fw_version = fw_version.value
                fw_versions[block_name] = fw_version

        return {
            "ROCm SMI library version - major": rsmi_version_major,
            "ROCm SMI library version - minor": rsmi_version_minor,
            "ROCm SMI library version - patch": rsmi_version_patch,
            "ROCm SMI library version - build": rsmi_version_build,
            "Driver version": driver_version,
            "VBIOS version": vbios_version,
            "Firmware versions": fw_versions
        }