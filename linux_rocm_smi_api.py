import ctypes
from typing import Any
from common_api import CommonAPI
from defines import *
from linux_rocm_smi_bindings import RSMI_MAX_NUM_FREQUENCIES, Ctypes_ROCm as crocm, rsmi_clk_type_t, rsmi_frequencies_t, rsmi_fw_block_t, rsmi_memory_type_t, rsmi_retired_page_record_t, rsmi_pcie_bandwidth_t, rsmi_version_t

class Linux_ROCm_SMI_Wrapper(CommonAPI):
    rocm_clib = None

    def __init__(self) -> None:
        self.rocm_clib = crocm()
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
        return ""
    
    def get_device_clocks_info(self, handle) -> Any:
        device_index = ctypes.c_uint32(handle)
        status = self.rocm_clib.rsmi_status

        clocks_info = {}
        for clock_type in range(rsmi_clk_type_t.RSMI_CLK_TYPE_FIRST, rsmi_clk_type_t.RSMI_CLK_TYPE_LAST+1)
            frequencies = rsmi_frequencies_t()
            status = self.rocm_clib.functions["rocm_get_clock_frequencies_info"](device_index, rsmi_clk_type_t(clock_type), ctypes.byref(frequencies))
            num_supported_freq =  None
            current_freq = None
            frequency = None
            if status != 0:
                num_supported_freq =  "Not supported"
                current_freq = "Not supported"
                frequency = "Not supported"
            else:
                num_supported_freq =  frequencies.num_supported
                current_freq = frequencies.current
                frequency = []
                for i in range(0, RSMI_MAX_NUM_FREQUENCIES):
                    frequency.append(frequencies.frequency[i])
            
            return {
                "Num of supported": num_supported_freq,
                "Current": current_freq,
                "Frequencies": frequency
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
        for memory_type in range(rsmi_memory_type_t.RSMI_MEM_TYPE_FIRST, rsmi_memory_type_t.RSMI_MEM_TYPE_LAST):
            total_mem_by_type = ctypes.c_uint64(0)
            status = self.rocm_clib.functions["rocm_get_device_memory_total"](device_index, rsmi_memory_type_t(memory_type), ctypes.byref(total_mem_by_type))
            print(status)
            total_memories_by_type[rsmi_memory_type_t(memory_type).name.replace("RSMI_MEM_TYPE_", "")] = total_mem_by_type


        total_memory_usages_by_type = dict()
        for memory_usage_type in range(rsmi_memory_type_t.RSMI_MEM_TYPE_FIRST, rsmi_memory_type_t.RSMI_MEM_TYPE_LAST):
            total_mem_usage_by_type = ctypes.c_uint64(0)
            status = self.rocm_clib.functions["rocm_get_device_memory_usage"](device_index, rsmi_memory_type_t(memory_usage_type), ctypes.byref(total_mem_usage_by_type))
            print(status)
            total_memory_usages_by_type[rsmi_memory_type_t(memory_usage_type).name.replace("RSMI_MEM_TYPE_", "")] = total_mem_usage_by_type


        busy_percent = ctypes.c_uint32(0)
        status = self.rocm_clib.functions["rocm_get_device_memory_busy_percent"](device_index, ctypes.byref(busy_percent))
        print(status)

        num_pages = ctypes.c_uint32()
        records = rsmi_retired_page_record_t()
        status = self.rocm_clib.functions["rocm_get_device_memory_reserved_pages"](device_index, ctypes.byref(num_pages), ctypes.byref(records))
        print(status)

        return {
            "Total memory amount by type": total_memories_by_type,
            "Total memory usages by type": total_memory_usages_by_type,
            "Busy percent": busy_percent,
            "Retired pages number": num_pages,
            "Retired pages records": records
        }

    def get_device_bus_info(self, handle) -> Any:
        device_index = ctypes.c_uin32(handle)
        
        pcie_bandwidth = rsmi_pcie_bandwidth_t()
        status = self.rocm_clib.functions["rocm_get_device_pci_bandwidth"](device_index, ctypes.byref(pcie_bandwidth))
        pcie_bandwidth_transfer_rate = None
        pcie_bandwidth_lanes = None
        if status != 0:
            pcie_bandwidth_transfer_rate = "Not supported"
            pcie_bandwidth_lanes = "Not supported"
        else:
            pcie_bandwidth_transfer_rate = pcie_bandwidth.transfer_rate
            pcie_bandwidth_lanes = pcie_bandwidth.lanes
        
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
            "PCIe Bandwidth transfer rate": pcie_bandwidth_transfer_rate,
            "PCIe bandwidth lanes number": pcie_bandwidth_lanes,
            "PCIe BDF": bdfid,
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

        device_sku = ctypes.c_uint16()
        status = self.rocm_clib.functions["rocm_get_device_sku"](device_index, ctypes.byref(device_sku))
        if status != 0:
            device_sku = "Not supported"
        else:
            device_sku = device_sku.value

        vendor_id = ctypes.c_uint16()
        status = self.rocm_clib.functions["rocm_get_device_vendor_id"](device_index, ctypes.byref(vendor_id))
        if status != 0:
            vendor_id = "Not supported"
        else:
            vendor_id = vendor_id.value

        brand_name = (ctypes.c_char * 200)()
        brand_len = ctypes.c_uint32(200)
        status = self.rocm_clib.functions["rocm_get_device_brand"](device_index, ctypes.byref(brand_name), brand_len)
        if status != 0:
            brand_name = "Not supported"
        else:
            brand_name = bytes(brand_name.value).decode('ASCII')

        vendor_name = (ctypes.c_char * 200)()
        vendor_name_len = ctypes.c_size_t(200)
        status = self.rocm_clib.functions["rocm_get_device_vendor_name"](device_index, ctypes.byref(vendor_name), vendor_name_len)
        if status != 0:
            vendor_name = "Not supported"
        else:
            vendor_name = bytes(vendor_name.value).decode('ASCII')

        vram_vendor_name = (ctypes.c_char * 200)()
        vram_vendor_len = ctypes.c_uint32(200)
        status = self.rocm_clib.functions["rocm_get_device_vram_vendor"](device_index, ctypes.byref(vram_vendor_name), vram_vendor_len)
        if status != 0:
            vram_vendor_name = "Not supported"
        else:
            vram_vendor_name = bytes(vram_vendor_name.value).decode('ASCII')

        serial_number = (ctypes.c_char * 200)()
        serial_num_len = ctypes.c_uint32(200)
        status = self.rocm_clib.functions["rocm_get_device_serial_number"](device_index, ctypes.byref(serial_number), serial_num_len)
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
        status = self.rocm_clib.functions["rocm_get_device_subsystem_name"](device_index, ctypes.byref(device_subsystem_name), device_subsystem_name_len)
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
            "Device SKU (Stock Keeping Unit)": device_sku,
            "Vendor ID": vendor_id,
            "Brand name": brand_name,
            "Vendor name": vendor_name,
            "Video RAM (VRAM) vendor name": vram_vendor_name,
            "Serial number": serial_number,
            "Subsystem ID": device_subsystem_id,
            "Subsystem name": device_subsystem_name,
            "Minor number": minor_number,
            "Subsystem vendor ID": subsystem_vendor_id,
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
            rsmi_version_build = rsmi_version.build

        sw_component = ctypes.c_int(0)
        driver_version = (ctypes.c_char * 200)()
        version_len = ctypes.c_uint32(200)
        status = self.rocm_clib.functions["rocm_get_driver_version"](sw_component, ctypes.byref(driver_version), version_len)
        if status != 0:
            driver_version = "Not supported"
        else:
            driver_version = bytes(driver_version.value).decode('ASCII')

        vbios_version = (ctypes.c_char * 200)()
        vbios_len = ctypes.c_uint32(200)
        status = self.rocm_clib.functions["rocm_get_device_vbios_version"](device_index, ctypes.byref(vbios_version), vbios_len)
        if status != 0:
            vbios_version = "Not supported"
        else:
            vbios_version = bytes(vbios_version.value).decode('ASCII')

        fw_versions = {}
        for block_type in range(rsmi_fw_block_t.RSMI_FW_BLOCK_FIRST, rsmi_fw_block_t.RSMI_FW_BLOCK_LAST+1):
            fw_version = ctypes.c_uint64()
            block = rsmi_fw_block_t(block_type)
            status = self.rocm_clib.functions["rocm_get_device_firmware_version"](device_index, block, ctypes.byref(fw_version))
            if status != 0:
                fw_version = "Not supported"
                fw_versions[block.name.replace("RSMI_FW_BLOCK_","")] = "Not supported"
            else:
                fw_version = fw_version.value
                fw_versions[block.name.replace("RSMI_FW_BLOCK_","")] = fw_version

        return {
            "ROCm SMI library version - major": rsmi_version_major,
            "ROCm SMI library version - minor": rsmi_version_minor,
            "ROCm SMI library version - patch": rsmi_version_patch,
            "ROCm SMI library version - build": rsmi_version_build,
            "Driver version": driver_version,
            "VBIOS version": vbios_version,
            "Firmware versions": fw_versions
        }