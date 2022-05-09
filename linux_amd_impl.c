#include "rocm_smi/rocm_smi.h"

int initialize() {


    rsmi_status_t ret_status = RSMI_STATUS_SUCCESS;

    ret_status = rsmi_init(0);

    if (ret_status != RSMI_STATUS_SUCCESS) {
        printf("Initialization of ROCm SMI failed. Return code %d", ret_status);
        return ret_status;
    }
    
    return ret_status;
}

int finish() {

    rsmi_status_t ret_status = RSMI_STATUS_SUCCESS;

    ret_status = rsmi_shut_down();

    if (ret_status != RSMI_STATUS_SUCCESS) {
        printf("Shutdown of ROCm SMI api failed. Return code %d", ret_status);
        return ret_status;
    }

    return ret_status;
}

int get_number_of_devices(uint32_t* device_num) {

    rsmi_status_t ret_status = RSMI_STATUS_SUCCESS;
    uint32_t number_of_devices;

    if (device_num == NULL) {
        printf("Passed NULL pointer as device_num param. Return code %d", -RSMI_STATUS_INVALID_ARGS);
        return -RSMI_STATUS_INVALID_ARGS;
    }

    ret_status = rsmi_num_monitor_devices(&number_of_devices);

    if (ret_status != RSMI_STATUS_SUCCESS) {
        printf("Getting number of monitor devices failed. Return code %d", ret_status);
        return ret_status;
    }

    return ret_status;
}

int initialize_with_flags(uint64_t flags) {
    rsmi_status_t ret_status = RSMI_STATUS_SUCCESS;

    ret_status = rsmi_init(flags);
    if (ret_status != RSMI_STATUS_SUCCESS) {
        printf("Initialization of ROCm SMI using flags failed. Return code %d", ret_status);
        return ret_status;
    }

    return ret_status;
}

int get_driver_version() {
    rsmi_status_t ret_status = RSMI_STATUS_SUCCESS;
    char name_buffer[200] = ""; 
    ret_status = rsmi_version_str_get(RSMI_SW_COMP_DRIVER, &name_buffer, 200);
    if (ret_status != RSMI_STATUS_SUCCESS){
        printf("Get driver version API failed. Return code %d", ret_status);
        return ret_status;
    }
    return ret_status;
}

int get_library_version() {
    rsmi_status_t ret_status = RSMI_STATUS_SUCCESS;

    return ret_status;
}

int get_device_handle_by_index(int index) {
    rsmi_status_t ret_status = RSMI_STATUS_SUCCESS;

    return ret_status;
}

int get_device_serial_by_handle(uint32_t handle) {
    rsmi_status_t ret_status = RSMI_STATUS_SUCCESS;

    return ret_status;
}

int get_device_uuid_by_handle(uint32_t handle) {
    rsmi_status_t ret_status = RSMI_STATUS_SUCCESS;

    return ret_status;
}

int get_device_name_by_handle(uint32_t handle) {
    rsmi_status_t ret_status = RSMI_STATUS_SUCCESS;

    return ret_status;
}

int get_device_temperature_info(uint32_t handle) {
    rsmi_status_t ret_status = RSMI_STATUS_SUCCESS;

    return ret_status;
}

int get_device_power_info(uint32_t handle) {
    rsmi_status_t ret_status = RSMI_STATUS_SUCCESS;

    return ret_status;
}