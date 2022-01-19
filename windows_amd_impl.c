#include "windows_amd_impl.h"

HINSTANCE AdlDll = NULL;

ADL_Main_Control_Create_Func Smi_Adl_Main_Control_Create = NULL;
ADL_Main_Control_Destroy_Func Smi_Adl_Main_Control_Destroy = NULL;
ADL_Main_Memory_Alloc_Func Smi_Adl_Main_Memory_Alloc = NULL;
ADL_Main_Memory_Free_Func Smi_Adl_Main_Memory_Free = NULL;
ADL2_Adapter_Accessibility_Get_Func Smi_Adl2_Adapter_Accessibility_Get = NULL;
ADL_Adapter_NumberOfAdapters_Get_Func Smi_ADL_Adapter_NumberOfAdapters_Get = NULL;
ADL2_Adapter_ID_Get_Func Smi_ADL2_Adapter_ID_Get = NULL;
ADL2_Adapter_VerndorID_Int_get_Func Smi_ADL2_Adapter_VerndorID_Int_get = NULL;
ADL_Adapter_Active_Get_Func Smi_ADL_Adapter_Active_Get = NULL;
ADL2_Adapter_MemoryInfo2_Get_Func Smi_ADL2_Adapter_MemoryInfo2_Get = NULL;
ADL_Adapter_MemoryInfo2_Get_Func Smi_ADL_Adapter_MemoryInfo2_Get = NULL;
ADL_Adapter_VideoBiosInfo_Get_Func Smi_ADL_Adapter_VideoBiosInfo_Get = NULL;


int initialize(){
    AdlDll = LoadLibrary(TEXT("atiadlxx.dll"));
    if (AdlDll == NULL){
        // A 32 bit calling application on 64 bit OS will fail to LoadLIbrary.
        // Try to load the 32 bit library (atiadlxy.dll) instead
        AdlDll = LoadLibrary(TEXT("atiadlxy.dll"));
        if (AdlDll == NULL) {
            printf("Dynamically loading ADL library failed! Return code %d", -1);
            return -1;
        }
    }

    Smi_Adl_Main_Control_Create = (ADL_Main_Control_Create_Func) GetProcAddress(AdlDll, "ADL_Main_Control_Create");
    Smi_Adl_Main_Control_Destroy = (ADL_Main_Control_Destroy_Func) GetProcAddress(AdlDll, "ADL_Main_Control_Destroy");
    Smi_Adl_Main_Memory_Alloc = (ADL_Main_Memory_Alloc_Func) GetProcAddress(AdlDll, "ADL_Main_Memory_Alloc");
    Smi_Adl_Main_Memory_Free = (ADL_Main_Memory_Free_Func) GetProcAddress(AdlDll, "ADL_Main_Memory_Free");
    Smi_Adl2_Adapter_Accessibility_Get = (ADL2_Adapter_Accessibility_Get_Func) GetProcAddress(AdlDll, "ADL2_Adapter_Accessibility_Get");
    Smi_ADL_Adapter_NumberOfAdapters_Get = (ADL_Adapter_NumberOfAdapters_Get_Func) GetProcAddress(AdlDll, "ADL2_Adapter_Accessibility_Get");
    Smi_ADL2_Adapter_ID_Get = (ADL2_Adapter_ID_Get_Func) GetProcAddress(AdlDll, "ADL2_Adapter_Accessibility_Get");
    Smi_ADL2_Adapter_VerndorID_Int_get = (ADL2_Adapter_VerndorID_Int_get_Func) GetProcAddress(AdlDll, "ADL2_Adapter_VerndorID_Int_get");
    Smi_ADL_Adapter_Active_Get = (ADL_Adapter_Active_Get_Func) GetProcAddress(AdlDll, "ADL_Adapter_Active_Get");
    Smi_ADL2_Adapter_MemoryInfo2_Get = (ADL2_Adapter_MemoryInfo2_Get_Func) GetProcAddress(AdlDll, "ADL2_Adapter_MemoryInfo2_Get");
    Smi_ADL_Adapter_MemoryInfo2_Get = (ADL_Adapter_MemoryInfo2_Get_Func) GetProcAddress(AdlDll, "ADL_Adapter_MemoryInfo2_Get");
    Smi_ADL_Adapter_VideoBiosInfo_Get = (ADL_Adapter_VideoBiosInfo_Get_Func) GetProcAddress(AdlDll, "ADL_Adapter_VideoBiosInfo_Get");

    if( Smi_Adl_Main_Control_Create == NULL ||
        Smi_Adl_Main_Control_Destroy == NULL ||
        Smi_Adl_Main_Memory_Alloc == NULL ||
        Smi_Adl_Main_Memory_Free == NULL ||
        Smi_Adl2_Adapter_Accessibility_Get == NULL ||
        Smi_ADL_Adapter_NumberOfAdapters_Get == NULL ||
        Smi_ADL2_Adapter_ID_Get == NULL ||
        Smi_ADL2_Adapter_VerndorID_Int_get == NULL ||
        Smi_ADL_Adapter_Active_Get == NULL ||
        Smi_ADL2_Adapter_MemoryInfo2_Get == NULL ||
        Smi_ADL_Adapter_MemoryInfo2_Get == NULL ||
        Smi_ADL_Adapter_VideoBiosInfo_Get == NULL
        ) {
        printf("Dynamically loading ADL procedure(s) failed. Return code %d", -1);
        return -1;
    }

    if (ADL_OK != Smi_Adl_Main_Control_Create(Smi_Adl_Main_Memory_Alloc, 1)){
        printf("Smi_Adl_Main_Control_Create call failed. Return code %d", -1);
        return -1;
    }

    return 0;
}


int finish(){
    if (ADL_OK != Smi_Adl_Main_Control_Destroy()){
        printf("Smi_Adl_Main_Control_Destroy call failed. Return code %d", -1);
        return -1;
    }
    if (FreeLibrary(AdlDll) == 0){
        printf("Freeing dynamically loaded ADL library failed. Return code %d", -1);
        return -1;
    }
    return 0;
}

int get_device_accessibility() {
    return 0;
}

int get_number_of_devices() {
    return 0;
}

int get_device_id_from_index() {
    return 0;
}

int get_device_memory_info() {
    return 0;
}

int get_device_vbios_info() {
    return 0;
}