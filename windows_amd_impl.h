#include "adl_sdk.h"
#include <Windows.h>

extern HINSTANCE AdlDll;

typedef int ( *ADL_MAIN_CONTROL_CREATE_FUNC )(ADL_MAIN_MALLOC_CALLBACK, int );
typedef int ( *ADL_MAIN_CONTROL_DESTROY_FUNC )();
typedef void* ( *ADL_MAIN_MEMORY_ALLOC_FUNC ) ( int iSize);
typedef void  ( *ADL_MAIN_MEMORY_FREE_FUNC ) ( void** lpBuffer);

extern ADL_MAIN_CONTROL_CREATE_FUNC Smi_Adl_Main_Control_Create;
extern ADL_MAIN_CONTROL_DESTROY_FUNC Smi_Adl_Main_Control_Destroy;
extern ADL_MAIN_MEMORY_ALLOC_FUNC Smi_Adl_Main_Memory_Alloc; 
extern ADL_MAIN_MEMORY_FREE_FUNC Smi_Adl_Main_Memory_Free;

