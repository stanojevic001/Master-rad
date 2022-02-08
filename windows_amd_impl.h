#include "adl_sdk.h"
#include <Windows.h>

extern HINSTANCE AdlDll;

typedef int ( *ADL_Main_Control_Create_Func )(ADL_MAIN_MALLOC_CALLBACK, int );
typedef int ( *ADL_Main_Control_Destroy_Func )();
typedef void* ( *ADL_Main_Memory_Alloc_Func ) ( int iSize);
typedef void  ( *ADL_Main_Memory_Free_Func ) ( void** lpBuffer);
typedef int ( *ADL2_Adapter_Accessibility_Get_Func )	(ADL_CONTEXT_HANDLE context, int iAdapterIndex, int *lpAccessibility);
typedef int ( *ADL_Adapter_NumberOfAdapters_Get_Func ) (int *lpNumAdapters);
typedef int ( *ADL2_Adapter_ID_Get_Func ) (ADL_CONTEXT_HANDLE context, int iAdapterIndex, int *lpAdapterID);
typedef int ( *ADL2_Adapter_VerndorID_Int_get_Func )	(ADL_CONTEXT_HANDLE context, int iAdapterIndex);
typedef int ( *ADL_Adapter_Active_Get_Func )	(int iAdapterIndex, int *lpStatus);
typedef int ( *ADL2_Adapter_MemoryInfo2_Get_Func )	(ADL_CONTEXT_HANDLE context, int iAdapterIndex, ADLMemoryInfo2 *lpMemoryInfo2);
typedef int ( *ADL_Adapter_MemoryInfo2_Get_Func )	(int iAdapterIndex, ADLMemoryInfo2 *lpMemoryInfo2);
typedef int ( *ADL_Adapter_VideoBiosInfo_Get_Func )	(int iAdapterIndex, ADLBiosInfo *lpBiosInfo);	


extern ADL_Main_Control_Create_Func Smi_Adl_Main_Control_Create;
extern ADL_Main_Control_Destroy_Func Smi_Adl_Main_Control_Destroy;
extern ADL_Main_Memory_Alloc_Func Smi_Adl_Main_Memory_Alloc; 
extern ADL_Main_Memory_Free_Func Smi_Adl_Main_Memory_Free;
extern ADL2_Adapter_Accessibility_Get_Func Smi_Adl2_Adapter_Accessibility_Get;
extern ADL_Adapter_NumberOfAdapters_Get_Func Smi_ADL_Adapter_NumberOfAdapters_Get;
extern ADL2_Adapter_ID_Get_Func Smi_ADL2_Adapter_ID_Get;
extern ADL2_Adapter_VerndorID_Int_get_Func Smi_ADL2_Adapter_VerndorID_Int_get;
extern ADL_Adapter_Active_Get_Func Smi_ADL_Adapter_Active_Get;
extern ADL2_Adapter_MemoryInfo2_Get_Func Smi_ADL2_Adapter_MemoryInfo2_Get;
extern ADL_Adapter_MemoryInfo2_Get_Func Smi_ADL_Adapter_MemoryInfo2_Get;
extern ADL_Adapter_VideoBiosInfo_Get_Func Smi_ADL_Adapter_VideoBiosInfo_Get;