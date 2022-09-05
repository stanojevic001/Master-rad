import ctypes
from typing import Any
from common_api import CommonAPI
from defines import *
from linux_rocm_smi_bindings import Ctypes_ROCm as crocm, rsmi_clk_type_t, rsmi_frequencies_t, rsmi_fw_block_t, rsmi_memory_type_t, rsmi_retired_page_record_t, rsmi_pcie_bandwidth_t, rsmi_temperature_metric_t, rsmi_temperature_type_t, rsmi_version_t
from utils import bytes_to_megabytes, hz_to_megahz_int

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
        
        elif type(enum_type) == rsmi_temperature_type_t:
            if "RSMI_TEMP_TYPE_EDGE" == enum_name:
                result = "Edge GPU temperature"
            elif "RSMI_TEMP_TYPE_JUNCTION" == enum_name:
                result = "Junction/Hotspot temperature"
            elif "RSMI_TEMP_TYPE_MEMORY" == enum_name:
                result = "Video RAM (VRAM) temperature"
            elif "RSMI_TEMP_TYPE_HBM_0" == enum_name:
                result = "HBM temperature instance 0"
            elif "RSMI_TEMP_TYPE_HBM_1" == enum_name:
                result = "HBM temperature instance 1"
            elif "RSMI_TEMP_TYPE_HBM_2" == enum_name:
                result = "HBM temperature instance 2"
            elif "RSMI_TEMP_TYPE_HBM_3" == enum_name:
                result = "HBM temperature instance 3"
            result += " (degrees Celsius)"

        elif type(enum_type) == rsmi_temperature_metric_t:
            if "RSMI_TEMP_CURRENT" == enum_name:
                result = "Current"
            elif "RSMI_TEMP_MAX" == enum_name:
                result = "Max"
            elif "RSMI_TEMP_MIN" == enum_name:
                result = "Min"
            elif "RSMI_TEMP_MAX_HYST" == enum_name:
                result = "Max limit hysteresis"
            elif "RSMI_TEMP_MIN_HYST" == enum_name:
                result = "Min limit hysteresis"
            elif "RSMI_TEMP_CRITICAL" == enum_name:
                result = "Critical max"
            elif "RSMI_TEMP_CRITICAL_HYST" == enum_name:
                result = "Critical max limit hysteresis"
            elif "RSMI_TEMP_EMERGENCY" == enum_name:
                result = "Emergency max"
            elif "RSMI_TEMP_EMERGENCY_HYST" == enum_name:
                result = "Emergency max limit hysteresis"
            elif "RSMI_TEMP_CRIT_MIN" == enum_name:
                result = "Critical min"
            elif "RSMI_TEMP_CRIT_MIN_HYST" == enum_name:
                result = "Critical min limit hysteresis"
            elif "RSMI_TEMP_OFFSET" == enum_name:
                result = "Offset (added to the temperature reading by the chip)"
            elif "RSMI_TEMP_LOWEST" == enum_name:
                result = "Historical min temperature"
            elif "RSMI_TEMP_HIGHEST" == enum_name:
                result = "Historical max temperature"
            result += " value"
        return result

    def initialize(self) -> None:
        flag = ctypes.c_uint64(0)
        if self.rocm_clib.functions["rocm_initialize"] is not None:
            status = self.rocm_clib.functions["rocm_initialize"](flag)
            if status != 0:
                raise Exception("Calling init function failed! Library initialization failed.")
        else:
            raise Exception("Library init function does not exist! Cannot load library properly!")

    def finish(self) -> None:
        if self.rocm_clib.functions["rocm_finish"] is not None:
            status = self.rocm_clib.functions["rocm_finish"]()
            if status != 0:
                raise Exception("Calling finish function failed! Library cleanup failed.")
        else:
            raise Exception("Library finish function does not exist! Cannot unload library properly!")

    def get_number_of_devices(self) -> int:
        ret_value = 0
        number_of_devices = ctypes.c_uint32()
        if self.rocm_clib.functions["rocm_get_number_of_devices"] is not None:
            status = self.rocm_clib.functions["rocm_get_number_of_devices"](ctypes.byref(number_of_devices))
            if status != 0:
                ret_value = 0
            else:
                ret_value = number_of_devices.value
        else:
            ret_value = 0

        return ret_value

    def get_device_name_by_handle(self, handle) -> Any:
        
        index = ctypes.c_uint32(handle)
        name = (ctypes.c_char * 500)()
        len = ctypes.c_size_t(500)
        name_output = ""

        if self.rocm_clib.functions["rocm_get_device_name_by_handle"] is not None:
            status = self.rocm_clib.functions["rocm_get_device_name_by_handle"](index, name, len)
            if status != 0:
                name_output = "Not supported"
            else:
                name_output = bytes(name.value).decode('ASCII')
        else:
            name_output = "N/A"

        return name_output

    def get_device_handle_by_index(self, index) -> Any:
        return index

    def get_device_temperature_info(self, handle) -> Any:
        device_index = ctypes.c_uint32(handle)
        temperatures = {}
        is_supported_temperature = False
        if self.rocm_clib.functions["rocm_get_device_temperature"] is not None:
            for temp_type_dict_key, temp_type_dict_enum in rsmi_temperature_type_t.__members__.items():
                if temp_type_dict_key in ("RSMI_TEMP_TYPE_FIRST", "RSMI_TEMP_TYPE_LAST", "RSMI_TEMP_TYPE_INVALID"):
                    continue
                temp_type_name =self.convert_enum_name_to_readable_string(temp_type_dict_key, temp_type_dict_enum)
                temperatures[temp_type_name] = {}
                is_supported_temperature_type = False
                for temp_metric_dict_key, temp_metric_dict_enum in rsmi_temperature_metric_t.__members__.items():
                    if temp_metric_dict_key in ("RSMI_TEMP_FIRST", "RSMI_TEMP_LAST"):
                        continue
                    temp_metric_name = self.convert_enum_name_to_readable_string(temp_metric_dict_key, temp_metric_dict_enum)
                    temp = ctypes.c_int64(0)
                    status = self.rocm_clib.functions["rocm_get_device_temperature"](device_index, temp_type_dict_enum, temp_metric_dict_enum, ctypes.byref(temp))
                    if status != 0:
                        temp = "Not supported"
                    else:
                        temp = temp.value/1000.00
                        is_supported_temperature = True
                        is_supported_temperature_type = True
                    temperatures[temp_type_name][temp_metric_name] = temp
                if not is_supported_temperature_type:
                    temperatures[temp_type_name] = "Not supported"
            if not is_supported_temperature:
                temperatures = "Not supported"
        else:
            temperatures = "N/A"
        
        all_not_supported = 0
        result_final_output = {
            "Temperature info": temperatures
        }
        for key in result_final_output.keys():
            if (type(result_final_output[key]) == str) and result_final_output[key] in ("Not supported", "N/A"):
                all_not_supported += 1
        
        if all_not_supported >= len(result_final_output.keys()):
            result_final_output = "Not supported"

        return result_final_output
    
    def get_device_clocks_info(self, handle) -> Any:
        device_index = ctypes.c_uint32(handle)
        clock_frequencies_info = {}
        if self.rocm_clib.functions["rocm_get_clock_frequencies_info"] is not None:
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
                                current_freq_output = hz_to_megahz_int(frequency[j])
                            frequency_output.append(hz_to_megahz_int(frequency[j]))
                    num_supported_freq_output = num_supported_freq
                    clock_frequencies_info[clock_type_name] = {
                        "Num of supported clock frequencies": num_supported_freq_output,
                        "Supported clock frequencies (MHz)": frequency_output,
                        "Current clock frequency (MHz)": current_freq_output
                    }
        else:
            clock_frequencies_info = "N/A"
        
        all_not_supported = 0
        result_final_output = {
            "Clock frequencies info": clock_frequencies_info
        }
        for key in result_final_output.keys():
            if (type(result_final_output[key]) == str) and result_final_output[key] in ("Not supported", "N/A"):
                all_not_supported += 1
        
        if all_not_supported >= len(result_final_output.keys()):
            result_final_output = "Not supported"
                
        return result_final_output
    
    def get_device_memory_info(self, handle) -> Any:
        device_index = ctypes.c_uint32(handle)

        total_memories_by_type = dict()
        if self.rocm_clib.functions["rocm_get_device_memory_total"] is not None:
            for memory_type_dict_key, memory_type_dict_enum in rsmi_memory_type_t.__members__.items():
                if memory_type_dict_key in ("RSMI_MEM_TYPE_FIRST", "RSMI_MEM_TYPE_LAST"):
                    continue
                memory_type_name = self.convert_enum_name_to_readable_string(memory_type_dict_key, memory_type_dict_enum)
                total_mem_by_type = ctypes.c_uint64(0)
                status = self.rocm_clib.functions["rocm_get_device_memory_total"](device_index, memory_type_dict_enum, ctypes.byref(total_mem_by_type))
                if status != 0:
                    total_memories_by_type[memory_type_name] = "Not supported"
                else:
                    total_memories_by_type[memory_type_name] = bytes_to_megabytes(total_mem_by_type.value)
        else:
            total_memories_by_type = "N/A"


        total_memory_usages_by_type = dict()
        if self.rocm_clib.functions["rocm_get_device_memory_usage"] is not None:
            for memory_usage_type_dict_key, memory_usage_type_dict_enum in rsmi_memory_type_t.__members__.items():
                if memory_usage_type_dict_key in ("RSMI_MEM_TYPE_FIRST", "RSMI_MEM_TYPE_LAST"):
                    continue
                total_mem_usage_by_type = ctypes.c_uint64(0)
                memory_usage_type_name = self.convert_enum_name_to_readable_string(memory_usage_type_dict_key, memory_usage_type_dict_enum)
                status = self.rocm_clib.functions["rocm_get_device_memory_usage"](device_index, memory_usage_type_dict_enum, ctypes.byref(total_mem_usage_by_type))
                if status != 0:
                    total_memory_usages_by_type[memory_usage_type_name] = "Not supported"
                else:
                    total_memory_usages_by_type[memory_usage_type_name] = bytes_to_megabytes(total_mem_usage_by_type.value)
        else:
            total_memory_usages_by_type = "N/A"


        busy_percent = ctypes.c_uint32(0)
        if self.rocm_clib.functions["rocm_get_device_memory_busy_percent"] is not None:
            status = self.rocm_clib.functions["rocm_get_device_memory_busy_percent"](device_index, ctypes.byref(busy_percent))
            if status != 0:
                busy_percent = "Not supported"
            else:
                busy_percent = busy_percent.value
        else:
            busy_percent = "N/A"

        num_pages = ctypes.c_uint32()
        records = ctypes.pointer(rsmi_retired_page_record_t())
        records_output = []
        if self.rocm_clib.functions["rocm_get_device_memory_reserved_pages"] is not None:
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
        else:
            num_pages = "N/A"
            records_output = "N/A"

        all_not_supported = 0
        result_final_output = {
            "Total memory amount by type (MB)": total_memories_by_type,
            "Total memory usages by type (MB)": total_memory_usages_by_type,
            "Busy percent": busy_percent,
            "Retired pages number": num_pages,
            "Retired pages records": records_output
        }
        for key in result_final_output.keys():
            if (type(result_final_output[key]) == str) and result_final_output[key] in ("Not supported", "N/A"):
                all_not_supported += 1
        
        if all_not_supported >= len(result_final_output.keys()):
            result_final_output = "Not supported"

        return result_final_output

    def get_device_bus_info(self, handle) -> Any:
        device_index = ctypes.c_uint32(handle)
        
        pcie_bandwidth = rsmi_pcie_bandwidth_t()
        pcie_bandwidth_transfer_rate_output_num_supported = None
        pcie_bandwidth_transfer_rate_output_current = ""
        pcie_bandwidth_lanes_output_current = ""
        pcie_bandwidth_transfer_rate_output_frequency = []
        pcie_bandwidth_lanes_output = []
        if self.rocm_clib.functions["rocm_get_device_pci_bandwidth"] is not None:
            status = self.rocm_clib.functions["rocm_get_device_pci_bandwidth"](device_index, ctypes.byref(pcie_bandwidth))
            pcie_bandwidth_transfer_rate = None
            pcie_bandwidth_transfer_rate_num_supported = None
            pcie_bandwidth_transfer_rate_current = None
            pcie_bandwidth_transfer_rate_frequency = []
            pcie_bandwidth_lanes = None
            if status != 0:
                pcie_bandwidth_transfer_rate_output_num_supported = "Not supported"
                pcie_bandwidth_transfer_rate_output_current = "Not supported"
                pcie_bandwidth_lanes_output_current = "Not supported"
                pcie_bandwidth_transfer_rate_output_frequency = "Not supported"
                pcie_bandwidth_lanes_output = "Not supported"
            else:
                pcie_bandwidth_transfer_rate = pcie_bandwidth.transfer_rate
                pcie_bandwidth_transfer_rate_num_supported = pcie_bandwidth_transfer_rate.num_supported
                pcie_bandwidth_transfer_rate_current = pcie_bandwidth_transfer_rate.current
                pcie_bandwidth_transfer_rate_frequency = pcie_bandwidth_transfer_rate.frequency
                pcie_bandwidth_transfer_rate_output_num_supported = pcie_bandwidth_transfer_rate_num_supported
                pcie_bandwidth_lanes = pcie_bandwidth.lanes
                if len(pcie_bandwidth_transfer_rate_frequency) <= 0:
                    pcie_bandwidth_transfer_rate_output_frequency = ""
                    pcie_bandwidth_transfer_rate_output_current = ""
                else:
                    for j in range(0, pcie_bandwidth_transfer_rate_num_supported):
                        if j == pcie_bandwidth_transfer_rate_current:
                            pcie_bandwidth_transfer_rate_output_current = hz_to_megahz_int(pcie_bandwidth_transfer_rate_frequency[j])
                        pcie_bandwidth_transfer_rate_output_frequency.append(hz_to_megahz_int(pcie_bandwidth_transfer_rate_frequency[j]))

                if len(pcie_bandwidth_lanes) <= 0:
                    pcie_bandwidth_lanes_output = ""
                else:
                    for i in range(0, pcie_bandwidth_transfer_rate_num_supported):
                        if j == pcie_bandwidth_transfer_rate_current:
                            pcie_bandwidth_lanes_output_current = pcie_bandwidth_lanes[j]
                        pcie_bandwidth_lanes_output.append(pcie_bandwidth_lanes[i])
        else:
            pcie_bandwidth_transfer_rate_output_num_supported = "N/A"
            pcie_bandwidth_transfer_rate_output_current = "N/A"
            pcie_bandwidth_lanes_output_current = "N/A"
            pcie_bandwidth_transfer_rate_output_frequency = "N/A"
            pcie_bandwidth_lanes_output = "N/A"
        
        bdfid = ctypes.c_uint64()
        if self.rocm_clib.functions["rocm_get_device_pci_id"] is not None:
            status = self.rocm_clib.functions["rocm_get_device_pci_id"](device_index, ctypes.byref(bdfid))
            if status != 0:
                bdfid = "Not supported"
            else:
                bdfid = bdfid.value
                bdfid = '{0:064b}'.format(bdfid)
                domain_bdf = '{0:08x}'.format(int(bdfid[0:32], base=2))
                bus_bdf = '{0:02x}'.format(int(bdfid[48:56], base=2))
                device_bdf = '{0:02x}'.format(int(bdfid[56:61], base=2))
                function_bdf = '{0:01x}'.format(int(bdfid[61:63], base=2))
                bdfid = domain_bdf + ":" + bus_bdf + ":" + device_bdf + "." + function_bdf
                
        else:
            bdfid = "N/A"
        
        sent = ctypes.c_uint64()
        received = ctypes.c_uint64()
        max_pkt_sz = ctypes.c_uint64()
        if self.rocm_clib.functions["rocm_get_device_pci_throughput"] is not None:
            status = self.rocm_clib.functions["rocm_get_device_pci_throughput"](device_index, ctypes.byref(sent), ctypes.byref(received), ctypes.byref(max_pkt_sz))
            if status != 0:
                sent = "Not supported"
                received = "Not supported"
                sent = "Not supported"
            else:
                sent = sent.value
                received = received.value
                max_pkt_sz = max_pkt_sz.value
        else:
            sent = "N/A"
            received = "N/A"
            max_pkt_sz = "N/A"
        
        counter = ctypes.c_uint64()
        if self.rocm_clib.functions["rocm_get_device_pci_replay_counter"] is not None:
            status = self.rocm_clib.functions["rocm_get_device_pci_replay_counter"](device_index, ctypes.byref(counter))
            if status != 0:
                counter = "Not supported"
            else:
                counter = counter.value
        else:
            counter = "N/A"

        all_not_supported = 0
        result_final_output = {
            "PCIe Number of supported frequencies": pcie_bandwidth_transfer_rate_output_num_supported,
            "PCIe Supported frequencies (MHz)": pcie_bandwidth_transfer_rate_output_frequency,
            "PCIe Current frequency (MHz)": pcie_bandwidth_transfer_rate_output_current,
            "PCIe Supported lane numbers": pcie_bandwidth_lanes_output,
            "PCIe Current lane number": pcie_bandwidth_lanes_output_current,
            "PCIe BDF number (Bus, Device, Function)": bdfid,
            "PCIe Throughput - Sent packets": sent,
            "PCIe Throughput - Received packets": received,
            "PCIe Throughput - Max packet size": max_pkt_sz,
            "PCIe Replay Counter": counter
        }
        for key in result_final_output.keys():
            if (type(result_final_output[key]) == str) and result_final_output[key] in ("Not supported", "N/A"):
                all_not_supported += 1
        
        if all_not_supported >= len(result_final_output.keys()):
            result_final_output = "Not supported"

        return result_final_output
    
    def get_device_catalog_info(self, handle) -> Any:
        device_index = ctypes.c_uint32(handle)
        status = ctypes.c_int()

        device_id = ctypes.c_uint16()
        if self.rocm_clib.functions["rocm_get_device_id"] is not None:
            status = self.rocm_clib.functions["rocm_get_device_id"](device_index, ctypes.byref(device_id))
            if status != 0:
                device_id = "Not supported"
            else:
                device_id = hex(device_id.value)
        else:
            device_id = "N/A"

        device_sku = ctypes.c_uint16()
        if self.rocm_clib.functions["rocm_get_device_sku"] is not None:
            status = self.rocm_clib.functions["rocm_get_device_sku"](device_index, ctypes.byref(device_sku))
            if status != 0:
                device_sku = "Not supported"
            else:
                device_sku = bytes(device_sku.value).decode('ASCII')
        else:
            device_sku = "N/A"

        vendor_id = ctypes.c_uint16()
        if self.rocm_clib.functions["rocm_get_device_vendor_id"] is not None:
            status = self.rocm_clib.functions["rocm_get_device_vendor_id"](device_index, ctypes.byref(vendor_id))
            if status != 0:
                vendor_id = "Not supported"
            else:
                vendor_id = hex(vendor_id.value)
        else:
            vendor_id = "N/A"

        brand_name = (ctypes.c_char * 200)()
        brand_len = ctypes.c_uint32(200)
        if self.rocm_clib.functions["rocm_get_device_brand"] is not None:
            status = self.rocm_clib.functions["rocm_get_device_brand"](device_index, brand_name, brand_len)
            if status != 0:
                brand_name = "Not supported"
            else:
                brand_name = bytes(brand_name.value).decode('ASCII')
        else:
            brand_name = "N/A"

        vendor_name = (ctypes.c_char * 200)()
        vendor_name_len = ctypes.c_size_t(200)
        if self.rocm_clib.functions["rocm_get_device_vendor_name"] is not None:
            status = self.rocm_clib.functions["rocm_get_device_vendor_name"](device_index, vendor_name, vendor_name_len)
            if status != 0:
                vendor_name = "Not supported"
            else:
                vendor_name = bytes(vendor_name.value).decode('ASCII')
        else:
            vendor_name = "N/A"

        vram_vendor_name = (ctypes.c_char * 200)()
        vram_vendor_len = ctypes.c_uint32(200)
        if self.rocm_clib.functions["rocm_get_device_vram_vendor"] is not None:
            status = self.rocm_clib.functions["rocm_get_device_vram_vendor"](device_index, vram_vendor_name, vram_vendor_len)
            if status != 0:
                vram_vendor_name = "Not supported"
            else:
                vram_vendor_name = bytes(vram_vendor_name.value).decode('ASCII').upper()
        else:
            vram_vendor_name = "N/A"

        serial_number = (ctypes.c_char * 200)()
        serial_num_len = ctypes.c_uint32(200)
        if self.rocm_clib.functions["rocm_get_device_serial_number"] is not None:
            status = self.rocm_clib.functions["rocm_get_device_serial_number"](device_index, serial_number, serial_num_len)
            if status != 0:
                serial_number = "Not supported"
            else:
                serial_number = bytes(serial_number.value).decode('ASCII')
        else:
            serial_number = "N/A"

        device_subsystem_id = ctypes.c_uint16()
        if self.rocm_clib.functions["rocm_get_device_subsystem_id"] is not None:
            status = self.rocm_clib.functions["rocm_get_device_subsystem_id"](device_index, ctypes.byref(device_subsystem_id))
            if status != 0:
                device_subsystem_id = "Not supported"
            else:
                device_subsystem_id = hex(device_subsystem_id.value)
        else:
            device_subsystem_id = "N/A"

        device_subsystem_name = (ctypes.c_char * 200)()
        device_subsystem_name_len = ctypes.c_size_t(200)
        if self.rocm_clib.functions["rocm_get_device_subsystem_name"] is not None:
            status = self.rocm_clib.functions["rocm_get_device_subsystem_name"](device_index, device_subsystem_name, device_subsystem_name_len)
            if status != 0:
                device_subsystem_name = "Not supported"
            else:
                device_subsystem_name = bytes(device_subsystem_name.value).decode('ASCII')
        else:
            device_subsystem_name = "N/A"

        minor_number = ctypes.c_uint32()
        if self.rocm_clib.functions["rocm_get_device_drm_render_minor"] is not None:
            status = self.rocm_clib.functions["rocm_get_device_drm_render_minor"](device_index, ctypes.byref(minor_number))
            if status != 0:
                minor_number = "Not supported"
            else:
                minor_number = minor_number.value
        else:
            minor_number = "N/A"

        subsystem_vendor_id = ctypes.c_uint16()
        if self.rocm_clib.functions["rocm_get_device_subsystem_vendor_id"] is not None:
            status = self.rocm_clib.functions["rocm_get_device_subsystem_vendor_id"](device_index, ctypes.byref(subsystem_vendor_id))
            if status != 0:
                subsystem_vendor_id = "Not supported"
            else:
                subsystem_vendor_id = hex(subsystem_vendor_id.value)
        else:
            subsystem_vendor_id = "N/A"

        unique_id = ctypes.c_uint64()
        if self.rocm_clib.functions["rocm_get_device_unique_id"] is not None:
            status = self.rocm_clib.functions["rocm_get_device_unique_id"](device_index, ctypes.byref(unique_id))
            if status != 0:
                unique_id = "Not supported"
            else:
                unique_id = unique_id.value
        else:
            unique_id = "N/A"
        
        all_not_supported = 0
        result_final_output = {
            "Device ID": device_id,
            "Brand name": brand_name,
            "Device SKU (Stock Keeping Unit)": device_sku,
            "Vendor ID": vendor_id,
            "Vendor name": vendor_name,
            "Video RAM (VRAM) vendor name": vram_vendor_name,
            "Serial number": serial_number,
            "Subsystem ID": device_subsystem_id,
            "Subsystem name": device_subsystem_name,
            "Subsystem vendor ID": subsystem_vendor_id,
            "Minor number": minor_number,
            "Unique ID": unique_id
        }
        for key in result_final_output.keys():
            if (type(result_final_output[key]) == str) and result_final_output[key] in ("Not supported", "N/A"):
                all_not_supported += 1
        
        if all_not_supported >= len(result_final_output.keys()):
            result_final_output = "Not supported"

        return result_final_output
    
    def get_device_versions_info(self, handle) -> Any:
        device_index = ctypes.c_uint32(handle)
 
        rsmi_version = rsmi_version_t()
        rsmi_version_major = ""
        rsmi_version_minor = ""
        rsmi_version_patch = ""
        rsmi_version_build = ""
        if self.rocm_clib.functions["rocm_get_rsmi_version"] is not None:
            status = self.rocm_clib.functions["rocm_get_rsmi_version"](ctypes.byref(rsmi_version))
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
        else:
            rsmi_version_major = "N/A"
            rsmi_version_minor = "N/A"
            rsmi_version_patch = "N/A"
            rsmi_version_build = "N/A"

        sw_component = ctypes.c_int(0)
        driver_version = (ctypes.c_char * 200)()
        version_len = ctypes.c_uint32(200)
        if self.rocm_clib.functions["rocm_get_driver_version"] is not None:
            status = self.rocm_clib.functions["rocm_get_driver_version"](sw_component, driver_version, version_len)
            if status != 0:
                driver_version = "Not supported"
            else:
                driver_version = bytes(driver_version.value).decode('ASCII')
        else:
            driver_version = "N/A"

        vbios_version = (ctypes.c_char * 200)()
        vbios_len = ctypes.c_uint32(200)
        if self.rocm_clib.functions["rocm_get_device_vbios_version"] is not None:
            status = self.rocm_clib.functions["rocm_get_device_vbios_version"](device_index, vbios_version, vbios_len)
            if status != 0:
                vbios_version = "Not supported"
            else:
                vbios_version = bytes(vbios_version.value).decode('ASCII')
        else:
            vbios_version = "N/A"

        fw_versions = {}
        if self.rocm_clib.functions["rocm_get_device_firmware_version"] is not None:
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
        else:
            fw_versions = "N/A"

        all_not_supported = 0
        result_final_output = {
            "ROCm SMI library version - major": rsmi_version_major,
            "ROCm SMI library version - minor": rsmi_version_minor,
            "ROCm SMI library version - patch": rsmi_version_patch,
            "ROCm SMI library version - build": rsmi_version_build,
            "Driver version": driver_version,
            "VBIOS version": vbios_version,
            "Firmware versions": fw_versions
        }
        for key in result_final_output.keys():
            if (type(result_final_output[key]) == str) and result_final_output[key] in ("Not supported", "N/A"):
                all_not_supported += 1
        
        if all_not_supported >= len(result_final_output.keys()):
            result_final_output = "Not supported"

        return result_final_output

