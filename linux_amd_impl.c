#include "rocm_smi/rocm_smi.h"

int initialize() {


    rsmi_status_t ret_status;

    ret_status = rsmi_init(0);

    if (ret_status != RSMI_STATUS_SUCCESS) {
        printf("Initialization of ROCm SMI failed. Return code %d", ret_status);
        return ret_status;
    }
    
}

int finish() {

    rsmi_status_t ret_status;

    ret_status = rsmi_shut_down();

    if (ret_status != RSMI_STATUS_SUCCESS) {
        printf("Shutdown of ROCm SMI api failed. Return code %d", ret_status);
        return ret_status;
    }
}

int get_number_of_devices(uint32_t* device_num) {

    rsmi_status_t ret_status;
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
}

int main() {
    initialize();
    uint32_t size;
    get_number_of_devices(&size);
    printf("Size: %u", size);
    finish();
}