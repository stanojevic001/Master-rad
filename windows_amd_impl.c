#include "windows_amd_impl.h"

HINSTANCE AdlDll = NULL;

ADL_MAIN_CONTROL_CREATE_FUNC Smi_Adl_Main_Control_Create = NULL;
ADL_MAIN_CONTROL_DESTROY_FUNC Smi_Adl_Main_Control_Destroy = NULL;
ADL_MAIN_MEMORY_ALLOC_FUNC Smi_Adl_Main_Memory_Alloc = NULL;
ADL_MAIN_MEMORY_FREE_FUNC Smi_Adl_Main_Memory_Free = NULL;

int initialize(){
    AdlDll = LoadLibrary(TEXT("atiadlxx.dll"));
    if (AdlDll == NULL){
        // A 32 bit calling application on 64 bit OS will fail to LoadLIbrary.
        // Try to load the 32 bit library (atiadlxy.dll) instead
        AdlDll = LoadLibrary(TEXT("atiadlxy.dll"));
        if (AdlDll == NULL) return -1;
    }

    Smi_Adl_Main_Control_Create = (ADL_MAIN_CONTROL_CREATE_FUNC) GetProcAddress(AdlDll, "ADL_Main_Control_Create");
    Smi_Adl_Main_Control_Destroy = (ADL_MAIN_CONTROL_DESTROY_FUNC) GetProcAddress(AdlDll, "ADL_Main_Control_Destroy");
    Smi_Adl_Main_Memory_Alloc = (ADL_MAIN_MEMORY_ALLOC_FUNC) GetProcAddress(AdlDll, "ADL_Main_Memory_Alloc");
    Smi_Adl_Main_Memory_Free = (ADL_MAIN_MEMORY_FREE_FUNC) GetProcAddress(AdlDll, "ADL_Main_Memory_Free");


    if(Smi_Adl_Main_Control_Create == NULL ||
        Smi_Adl_Main_Control_Destroy == NULL) {
        return -1;
    }

    Smi_Adl_Main_Control_Create(Smi_Adl_Main_Memory_Alloc, 1);
    return 0;

}


int finish(){

    Smi_Adl_Main_Control_Destroy();
    FreeLibrary(AdlDll);
    return 0;
}