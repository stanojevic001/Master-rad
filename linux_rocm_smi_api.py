import ctypes
from typing import Any
from common_api import CommonAPI
from defines import *
from linux_rocm_smi_bindings import Ctypes_ROCm as crocm, rsmi_memory_type_t, rsmi_retired_page_record_t, rsmi_pcie_bandwidth_t

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

    def initialize_with_flags(self, flags: Any) -> None:
        pass

    def get_driver_version(self) -> str:
        
        type_call = ctypes.c_int(0)
        drv_version = (ctypes.c_char * 200)()
        len = ctypes.c_uint32(200)
        self.rocm_clib.functions["rocm_get_driver_version"](type_call, drv_version, len)
        return bytes(drv_version.value).decode('ASCII')

    def get_library_version(self) -> str:
        return ""

    def get_device_handle_by_index(self, index) -> Any:
        return index
    
    def get_device_serial_by_handle(self, handle) -> Any:
        return ""

    def get_device_uuid_by_handle(self, handle) -> Any:
        return ""

    def get_device_name_by_handle(self, handle) -> Any:
        return ""

    def get_device_temperature_info(self, handle) -> Any:
        return ""

    def get_device_power_info(self, handle) -> Any:
        return ""

    def get_device_name_by_handle(self, handle) -> Any:
        
        index = ctypes.c_uint32(handle)
        name = (ctypes.c_char * 500)()
        len = ctypes.c_size_t(500)

        self.rocm_clib.functions["rocm_get_device_name_by_handle"](index, name, len)
        return bytes(name.value).decode('ASCII')
    
    def get_device_memory_info(self, handle) -> Any:
        device_index = ctypes.c_uint32(handle)

        total_memories_by_type = dict()
        for memory_type in range(rsmi_memory_type_t.RSMI_MEM_TYPE_FIRST, rsmi_memory_type_t.RSMI_MEM_TYPE_LAST+1):
            total_mem_by_type = ctypes.c_uint64(0)
            status = self.rocm_clib.functions["rocm_get_device_memory_total"](device_index, rsmi_memory_type_t(memory_type), ctypes.byref(total_mem_by_type))
            print(status)
            total_memories_by_type[rsmi_memory_type_t(memory_type).name.replace("RSMI_MEM_TYPE_", "")] = total_mem_by_type
        print(total_memories_by_type)

        total_memory_usages_by_type = dict()
        for memory_usage_type in range(rsmi_memory_type_t.RSMI_MEM_TYPE_FIRST, rsmi_memory_type_t.RSMI_MEM_TYPE_LAST+1):
            total_mem_usage_by_type = ctypes.c_uint64(0)
            status = self.rocm_clib.functions["rocm_get_device_memory_usage"](device_index, rsmi_memory_type_t(memory_usage_type), ctypes.byref(total_mem_usage_by_type))
            print(status)
            total_memory_usages_by_type[rsmi_memory_type_t(memory_usage_type).name.replace("RSMI_MEM_TYPE_", "")] = total_mem_usage_by_type
        print(total_memory_usages_by_type)

        busy_percent = ctypes.c_uint32(0)
        status = self.rocm_clib.functions["rocm_get_device_memory_busy_percent"](device_index, ctypes.byref(busy_percent))
        print(status)
        print(busy_percent)

        num_pages = ctypes.c_uint32()
        records = rsmi_retired_page_record_t()
        status = self.rocm_clib.functions["rocm_get_device_memory_reserved_pages"](device_index, ctypes.byref(num_pages), ctypes.byref(records))
        print(status)
        print(num_pages)
        print(records)
    
    def get_device_bus_info(self, handle) -> Any:
        device_index = ctypes.c_uin32(handle)
        
        pcie_bandwidth = rsmi_pcie_bandwidth_t()
        status = self.functions["rocm_get_device_pci_bandwidth"](device_index, ctypes.byref(pcie_bandwidth))
        print(status)
        
        bdfid = ctypes.c_uint64()
        status = self.functions["rocm_get_device_pci_id"](device_index, ctypes.byref(bdfid))
        print(status)
        
        sent = ctypes.c_uint64()
        received = ctypes.c_uint64()
        max_pkt_sz = ctypes.c_uint64()
        status = self.functions["rocm_get_device_pci_throughput"](device_index, ctypes.byref(sent), ctypes.byref(received), ctypes.byref(max_pkt_sz))
        print(status)
        
        counter = ctypes.c_uint64()
        status = self.functions["rocm_get_device_pci_replay_counter"](device_index, ctypes.byref(counter))
        print(status)

        return {
            "PCIe Bandwidth": pcie_bandwidth,
            "PCIe BDF": bdfid,
            "PCIe Throughput - Sent packets": sent,
            "PCIe Throughput - Received packets": received,
            "PCIe Throughput - Max packet size": max_pkt_sz,
            "PCIe Replay Counter": counter
        }
