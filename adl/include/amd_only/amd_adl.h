///
///  Copyright (c) 2008 - 2021 Advanced Micro Devices, Inc.
 
///  THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
///  EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
///  WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.

/// \file amd_adl.h
/// \brief Contains all AMD internal main functions exposed by ADL for \ALL platforms.
///
/// This file contains all AMD internal main functions exposed by ADL for \ALL platforms.
/// All functions in this file can be used as a reference to ensure
/// the specified function pointers can be used by the appropriate runtime
/// dynamic library loaders. This header file is for AMD internal use only.

#ifndef AMD_ADL_H_
#define AMD_ADL_H_

#ifndef ADL_EXTERNC
#ifdef __cplusplus
#define ADL_EXTERNC extern "C"
#else
#define ADL_EXTERNC
#endif
#endif

#ifndef EXPOSED
#define EXPOSED
#endif /* EXPOSED */

#include "adl_defines.h"
#include "amd_defines.h"
#include "adl_structures.h"
#include "amd_structures.h"

#include "amd_adapter.h"
#include "amd_display.h"
#include "amd_desktop.h"
#include "amd_graphics.h"

/// Log error callback
typedef int ( __stdcall *ADL_MAIN_LOGERROR_CALLBACK )(char*, int);

/// Log debug callback
typedef int ( __stdcall *ADL_MAIN_LOGDEBUG_CALLBACK )(char*, int);

/// ADL API name callback
typedef void(__stdcall *ADL_MAIN_FUNCTIONNAME_CALLBACK)(char*);

///
/// \brief ADL local interface. Function to set the log error callback pointer.
/// 
/// This function sets the log error call function pointer. This pointer can then be used to retrieve more detailed error information.
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in]  callback The ADL_MAIN_LOGERROR_CALLBACK function pointer to be set.
/// \platform 
/// \ALL
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
ADL_EXTERNC int EXPOSED ADL2_Main_LogError_Set (ADL_CONTEXT_HANDLE context, ADL_MAIN_LOGERROR_CALLBACK callback );

///
/// \brief ADL local interface. Function to set the log error callback pointer.
/// 
/// This function sets the log error call function pointer. This pointer can then be used to retrieve more detailed error information.
/// \param[in]  callback The ADL_MAIN_LOGERROR_CALLBACK function pointer to be set.
/// \platform 
/// \ALL
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
ADL_EXTERNC int EXPOSED ADL_Main_LogError_Set ( ADL_MAIN_LOGERROR_CALLBACK callback );

///
/// \brief ADL local interface. Function to set the log debug callback pointer.
/// 
/// This function sets the log debug call function pointer. This pointer can then be used to retrieve more detailed error information.
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in]  callback The ADL_MAIN_LOGDEBUG_CALLBACK function pointer to be set.
/// \platform 
/// \ALL
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
ADL_EXTERNC int EXPOSED ADL2_Main_LogDebug_Set (ADL_CONTEXT_HANDLE context, ADL_MAIN_LOGDEBUG_CALLBACK callback );

///
/// \brief ADL local interface. Function to set the log debug callback pointer.
/// 
/// This function sets the log debug call function pointer. This pointer can then be used to retrieve more detailed error information.
/// \param[in]  callback The ADL_MAIN_LOGDEBUG_CALLBACK function pointer to be set.
/// \platform 
/// \ALL
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
ADL_EXTERNC int EXPOSED ADL_Main_LogDebug_Set ( ADL_MAIN_LOGDEBUG_CALLBACK callback );

///
/// \brief ADL local interface. Function to set the ADL API Name callback pointer.
/// 
/// This function sets the ADL API name call function pointer. This pointer can then be used to retrieve the current ADL API that is getting executed.
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in]  callback The ADL_MAIN_FUNCTIONNAME_CALLBACK function pointer to be set.
/// \platform 
/// \ALL
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
ADL_EXTERNC int EXPOSED ADL2_Main_FunctionNameCallback_Set(ADL_CONTEXT_HANDLE context, ADL_MAIN_FUNCTIONNAME_CALLBACK callback);

///
/// \brief ADL local interface. Function to determine whether a function is exposed in a DLL module.
/// 
/// This function checks whether a specified function is defined and exposed in a particular DLL module (valid). Only valid functions can be successfully called.
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in]  lpModule The pointer to the handle of the desired DLL module.
/// \param[in]  lpProcName The pointer to the name of the desired function.
/// \platform 
/// \ALL
/// \return If the specified function is valid, the return value is 1. Otherwise it is 0. 
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
ADL_EXTERNC int EXPOSED ADL2_Main_Control_IsFunctionValid (ADL_CONTEXT_HANDLE context, void* lpModule, char* lpProcName );

///
/// \brief ADL local interface. Function to determine whether a function is exposed in a DLL module.
/// 
/// This function checks whether a specified function is defined and exposed in a particular DLL module (valid). Only valid functions can be successfully called.
/// \param[in]  lpModule The pointer to the handle of the desired DLL module.
/// \param[in]  lpProcName The pointer to the name of the desired function.
/// \platform 
/// \ALL
/// \return If the specified function is valid, the return value is 1. Otherwise it is 0. 
ADL_EXTERNC int EXPOSED ADL_Main_Control_IsFunctionValid ( void* lpModule, char* lpProcName );

#endif /* AMD_ADL_H_ */
