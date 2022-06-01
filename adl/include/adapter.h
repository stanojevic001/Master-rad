///
///  Copyright (c) 2008 - 2021 Advanced Micro Devices, Inc.
 
///  THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
///  EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
///  WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.

/// \file adapter.h
/// \brief Contains all adapter-related functions exposed by ADL for \ALL platforms.
///
/// This file contains all adapter-related functions exposed by ADL for \ALL platforms.
/// All functions in this file can be used as a reference to ensure
/// the appropriate function pointers can be used by the appropriate runtime
/// dynamic library loaders.

#ifndef ADAPTER_H_
#define ADAPTER_H_

#include "adl_structures.h"

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

/// \ingroup ADAPTERAPI
/// \defgroup ADAPTERMAINAPI Adapter Related APIs
/// This group outlines Graphics version and architechture specific APIs.

///\addtogroup ADAPTERMAINAPI 
/// @{

///
/// \brief \newAPI16 Function to get the Smart shift support.
/// 
/// This function retrieves the smart shift support for a specified adapter.
/// \platform
/// \WIN
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[out] lpSupported Smart shift supported state 
/// \param[out] lpVersion Smart shift supported version 
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results 
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
ADL_EXTERNC int EXPOSED ADL2_SmartShift_Support(ADL_CONTEXT_HANDLE context, int iAdapterIndex, int* lpSupported, int* lpVersion);


///
/// \brief \newAPI16 Function to get the Smart shift Settings.
/// 
/// This function retrieves the smart shift settings for a specified adapter.
/// \platform
/// \WIN
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[out] lpCurrent Smart shift settings  
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results 
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
ADL_EXTERNC int EXPOSED ADL2_SmartShift_Settings_Get(ADL_CONTEXT_HANDLE context, int iAdapterIndex, ADLSmartShiftSettings* lpCurrent);


///
/// \brief \newAPI16 Function to set the Smart shift Delta gain settings.
/// 
/// This function set the smart shift Delta gain settings for a specified adapter.
/// \platform
/// \WIN
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[in] iMode Smart shift Mode 
/// \param[in] iValue Smart shift value  
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results 
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
ADL_EXTERNC int EXPOSED ADL2_SmartShift_DeltaGain_Set(ADL_CONTEXT_HANDLE context, int iAdapterIndex, int iMode, int iValue);


///\brief Function to get the core and memory clock info of an adapter.  This is the clock displayed on CCC information center.
/// Specific logic is used to select appropriate clock for display in current configuration.
///
/// This function retrieves the core and memory clock of an adapter.
/// \platform
/// \ALL
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[out] lpCoreClock The pointer to the core clock retrieved from the driver in Mhz.
/// \param[out] lpMemoryClock The pointer to the memory clock retrieved from the driver in Mhz.
/// \return If the function succeeds, the return value is \ref ADL_OK (zero). Otherwise the return value is an ADL error code (non-zero). \ref define_adl_results
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
ADL_EXTERNC int EXPOSED ADL2_Adapter_ObservedClockInfo_Get(ADL_CONTEXT_HANDLE context, int iAdapterIndex, int* lpCoreClock, int* lpMemoryClock);

///
///\brief Function to get the core and memory clock info of an adapter.  This is the clock displayed on CCC information center.
///         Specific logic is used to select appropriate clock for display in current configuration.
///
/// This function retrieves the core and memory clock of an adapter.
/// \platform
/// \ALL
/// \param[in] iAdapterIndex The ADL index handle of the desired adapter.
/// \param[out] lpCoreClock The pointer to the core clock retrieved from the driver in Mhz.
/// \param[out] lpMemoryClock The pointer to the memory clock retrieved from the driver in Mhz.
/// \return If the function succeeds, the return value is \ref ADL_OK (zero). Otherwise the return value is an ADL error code (non-zero). \ref define_adl_results
ADL_EXTERNC int EXPOSED ADL_Adapter_ObservedClockInfo_Get(int iAdapterIndex, int* lpCoreClock, int* lpMemoryClock);

///
///\brief Function to get the base, game, boost and memory clock info of an adapter.
///         Specific logic is used to select appropriate clock for display in current configuration.
///
/// This function retrieves the game, base, boost and memory clock of an adapter.
/// \platform
/// \ALL
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[out] lpBaseClock The pointer to the base clock retrieved from the driver in Mhz.
/// \param[out] lpGameClock The pointer to the game clock retrieved from the driver in Mhz.
/// \param[out] lpBoostClock The pointer to the boost clock retrieved from the driver in Mhz.
/// \param[out] lpMemoryClock The pointer to the memory clock retrieved from the driver in Mhz.
/// \return If the function succeeds, the return value is \ref ADL_OK (zero). Otherwise the return value is an ADL error code (non-zero). \ref define_adl_results
/// \remarks Clients can use ADL version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
ADL_EXTERNC int EXPOSED ADL_Adapter_ObservedGameClockInfo_Get(ADL_CONTEXT_HANDLE context, int iAdapterIndex, int* lpBaseClock, int* lpGameClock, int* lpBoostClock, int* lpMemoryClock);

///
/// \brief Function to set the current extended desktop mode status for a display.
/// 
/// This function enables or disables extended desktop mode for a specified display. 
/// \platform
/// \WIN
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in] iAdapterIndex The ADL index handle of the desired adapter.
/// \param[in] iStatus The desired display extended desktop mode status. \ref ADL_TRUE : extended desktop mode; \ref ADL_FALSE : otherwise.
/// \param[out] lpNewlyActivate The pointer to the retrieved adapter activation information. \ref ADL_TRUE : the adapter is activated for the first time; \ref ADL_FALSE : otherwise.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
ADL_EXTERNC int EXPOSED ADL2_Adapter_Active_Set(ADL_CONTEXT_HANDLE context, int iAdapterIndex,
	int iStatus,
	int* lpNewlyActivate);

///
/// \brief Function to set the current extended desktop mode status for a display.
/// 
/// This function enables or disables extended desktop mode for a specified display. 
/// \platform
/// \WIN
/// \param[in] iAdapterIndex The ADL index handle of the desired adapter.
/// \param[in] iStatus The desired display extended desktop mode status. \ref ADL_TRUE : extended desktop mode; \ref ADL_FALSE : otherwise.
/// \param[out] lpNewlyActivate The pointer to the retrieved adapter activation information. \ref ADL_TRUE : the adapter is activated for the first time; \ref ADL_FALSE : otherwise.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
ADL_EXTERNC int EXPOSED ADL_Adapter_Active_Set(int iAdapterIndex,
	int iStatus,
	int* lpNewlyActivate);

///
/// \brief Function to set the current extended desktop mode status for the display.
/// 
/// This function enables or disables the input adapter for a specified display. 
/// In addition, this function allows the user to enable the input adapter and pass in the preferred targets.
/// \platform
/// \WIN
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in] iAdapterIndex The ADL index handle of the desired adapter.
/// \param[in] iStatus The desired display extended desktop mode status. \ref ADL_TRUE : extended desktop mode; \ref ADL_FALSE : otherwise.
/// \param[in] iNumPreferTarget If iStatus is TRUE, the user can pass the size of preferred Display Targets array.
/// \param[in] lpPreferTarget If iStatus is TRUE, the user can pass the preferred Display Targets array to be enabled (with targets cloned).
/// \param[out] lpNewlyActivate The pointer to the retrieved adapter activation information. \ref ADL_TRUE : the adapter is activated for the first time; \ref ADL_FALSE : otherwise.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
ADL_EXTERNC int EXPOSED ADL2_Adapter_Active_SetPrefer(ADL_CONTEXT_HANDLE context, int iAdapterIndex,
	int iStatus,
	int iNumPreferTarget,
	ADLDisplayTarget* lpPreferTarget,
	int* lpNewlyActivate);

///
/// \brief Function to set the current extended desktop mode status for the display.
/// 
/// This function enables or disables the input adapter for a specified display. 
/// In addition, this function allows the user to enable the input adapter and pass in the preferred targets.
/// \platform
/// \WIN
/// \param[in] iAdapterIndex The ADL index handle of the desired adapter.
/// \param[in] iStatus The desired display extended desktop mode status. \ref ADL_TRUE : extended desktop mode; \ref ADL_FALSE : otherwise.
/// \param[in] iNumPreferTarget If iStatus is TRUE, the user can pass the size of preferred Display Targets array.
/// \param[in] lpPreferTarget If iStatus is TRUE, the user can pass the preferred Display Targets array to be enabled (with targets cloned).
/// \param[out] lpNewlyActivate The pointer to the retrieved adapter activation information. \ref ADL_TRUE : the adapter is activated for the first time; \ref ADL_FALSE : otherwise.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
ADL_EXTERNC int EXPOSED ADL_Adapter_Active_SetPrefer(int iAdapterIndex,
	int iStatus,
	int iNumPreferTarget,
	ADLDisplayTarget* lpPreferTarget,
	int* lpNewlyActivate);

///
/// \brief Function to retrieve the primary display adapter index.
/// 
/// This function retrieves the adapter index for the primary display adapter. 
/// \platform
/// \WIN
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[out] lpPrimaryAdapterIndex The pointer to the ADL index handle of the primary adapter. 
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
ADL_EXTERNC int EXPOSED ADL2_Adapter_Primary_Get(ADL_CONTEXT_HANDLE context, int* lpPrimaryAdapterIndex);

///
/// \brief Function to retrieve the primary display adapter index.
/// 
/// This function retrieves the adapter index for the primary display adapter. 
/// \platform
/// \WIN
/// \param[out] lpPrimaryAdapterIndex The pointer to the ADL index handle of the primary adapter. 
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
ADL_EXTERNC int EXPOSED ADL_Adapter_Primary_Get(int* lpPrimaryAdapterIndex);

///
/// \brief Function to set the primary display adapter index.
/// 
/// This function sets the adapter index for a specified primary display adapter. 
/// \platform
/// \WIN
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in] iAdapterIndex The ADL index handle of the desired adapter.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
ADL_EXTERNC int EXPOSED ADL2_Adapter_Primary_Set(ADL_CONTEXT_HANDLE context, int iAdapterIndex);

///
/// \brief Function to set the primary display adapter index.
/// 
/// This function sets the adapter index for a specified primary display adapter. 
/// \platform
/// \WIN
/// \param[in] iAdapterIndex The ADL index handle of the desired adapter.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
ADL_EXTERNC int EXPOSED ADL_Adapter_Primary_Set(int iAdapterIndex);

///
/// \brief Function to perform a mode switch for an adapter.
/// 
/// This function performs a mode switch for a specified adapter.
/// \platform
/// \WIN
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
ADL_EXTERNC int EXPOSED ADL2_Adapter_ModeSwitch(ADL_CONTEXT_HANDLE context, int iAdapterIndex);

///
/// \brief Function to perform a mode switch for an adapter.
/// 
/// This function performs a mode switch for a specified adapter.
/// \platform
/// \WIN
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
ADL_EXTERNC int EXPOSED ADL_Adapter_ModeSwitch(int iAdapterIndex);

///
/// \brief Function to determine if the adapter is active or not.
/// 
/// The function is used to check if the adapter associated with iAdapterIndex is active. Logic is different for Windows and Linux!
/// \platform
/// \ALL
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[out] lpStatus The pointer to the retrieved status. \ref ADL_TRUE : Active; \ref ADL_FALSE : Disabled.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
ADL_EXTERNC  int EXPOSED ADL2_Adapter_Active_Get (ADL_CONTEXT_HANDLE context, int iAdapterIndex, int* lpStatus);

///
/// \brief Function to determine if the adapter is active or not.
/// 
/// The function is used to check if the adapter associated with iAdapterIndex is active. Logic is different for Windows and Linux!
/// \platform
/// \ALL
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[out] lpStatus The pointer to the retrieved status. \ref ADL_TRUE : Active; \ref ADL_FALSE : Disabled.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
ADL_EXTERNC  int EXPOSED ADL_Adapter_Active_Get ( int iAdapterIndex, int* lpStatus);


/// \brief ADL local interface. Function to retrieve the supported aspects list.
/// 
/// This function retrieves the list of supported aspects for a specified adapter.
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[out]  lpAspects The pointer to the buffer storing the list of aspects supported for the specified adapter.
/// \param[in] iSize The size of the lpAspects buffer.
/// \platform 
/// \ALL
/// \return If the function valid, the return value is 1. Otherwise it is 0. 
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
ADL_EXTERNC int EXPOSED ADL2_Adapter_Aspects_Get(ADL_CONTEXT_HANDLE context, int iAdapterIndex, char* lpAspects, int iSize );

/// \brief ADL local interface. Function to retrieve the supported aspects list.
/// 
/// This function retrieves the list of supported aspects for a specified adapter.
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[out]  lpAspects The pointer to the buffer storing the list of aspects supported for the specified adapter.
/// \param[in] iSize The size of the lpAspects buffer.
/// \platform 
/// \ALL
/// \return If the function valid, the return value is 1. Otherwise it is 0. 
ADL_EXTERNC int EXPOSED ADL_Adapter_Aspects_Get( int iAdapterIndex, char* lpAspects, int iSize );

///
/// \brief Function to retrieve the number of OS-known adapters.
/// 
/// This function retrieves the number of graphics adapters recognized by the OS (OS-known adapters). OS-known adapters can include adapters that are physically present in the system (logical adapters)    
/// as well as ones that no longer present in the system but are still recognized by the OS.
/// \platform
/// \ALL
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[out] lpNumAdapters The pointer to the number of OS-known adapters.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results 
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
ADL_EXTERNC int EXPOSED ADL2_Adapter_NumberOfAdapters_Get (ADL_CONTEXT_HANDLE context,  int* lpNumAdapters );

///
/// \brief Function to retrieve the number of OS-known adapters.
/// 
/// This function retrieves the number of graphics adapters recognized by the OS (OS-known adapters). OS-known adapters can include adapters that are physically present in the system (logical adapters)    
/// as well as ones that no longer present in the system but are still recognized by the OS.
/// \platform
/// \ALL
/// \param[out] lpNumAdapters The pointer to the number of OS-known adapters.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results 
ADL_EXTERNC int EXPOSED ADL_Adapter_NumberOfAdapters_Get (  int* lpNumAdapters );

///
/// \brief Function to save driver data
/// 
/// This function saves all required data from driver to persist updated settings
/// \platform
/// \ALL
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in]  iAdapterIndex The adapter index to be flushed.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results 
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
ADL_EXTERNC int EXPOSED ADL2_Flush_Driver_Data(ADL_CONTEXT_HANDLE context,int iAdapterIndex);

///
/// \brief Function to save driver data
/// 
/// This function saves all required data from driver to persist updated settings
/// \platform
/// \ALL
/// \param[in]  iAdapterIndex The adapter index to be flushed.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results 
ADL_EXTERNC int EXPOSED ADL_Flush_Driver_Data(int iAdapterIndex);

///
/// \brief Retrieves all OS-known adapter information.
/// 
/// This function retrieves the adapter information of all OS-known adapters in the system. OS-known adapters can include adapters that are physically present in the system (logical adapters)    
/// as well as ones that are no longer present in the system but are still recognized by the OS.
/// \platform
/// \ALL
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in]  iInputSize The size of the lpInfo buffer.
/// \param[out] lpInfo The pointer to the buffer containing the retrieved adapter information.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results  
///
/// \remarks This API take a fixed-size output array. For dynamic-size output, use \ref ADL_Adapter_AdapterInfoX2_Get function.
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
ADL_EXTERNC int EXPOSED ADL2_Adapter_AdapterInfo_Get (ADL_CONTEXT_HANDLE context,LPAdapterInfo lpInfo, int iInputSize);


///
/// \brief Retrieves adapter vendor id.
/// 
/// This function retrieves the parsed hex vendor id
/// \platform
/// \ALL
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results  
ADL_EXTERNC int EXPOSED ADL2_Adapter_VerndorID_Int_get(ADL_CONTEXT_HANDLE context, int iAdapterIndex);

///
/// \brief Retrieves all OS-known adapter information.
/// 
/// This function retrieves the adapter information of all OS-known adapters in the system. OS-known adapters can include adapters that are physically present in the system (logical adapters)    
/// as well as ones that are no longer present in the system but are still recognized by the OS.
/// \platform
/// \ALL
/// \param[in]  iInputSize The size of the lpInfo buffer.
/// \param[out] lpInfo The pointer to the buffer containing the retrieved adapter information.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results  
///
/// \remarks This API take a fixed-size output array. For dynamic-size output, use \ref ADL_Adapter_AdapterInfoX2_Get function.
ADL_EXTERNC int EXPOSED ADL_Adapter_AdapterInfo_Get (LPAdapterInfo lpInfo, int iInputSize);

///
/// \brief Retrieves all OS-known adapter information.
/// 
/// This function retrieves the adapter information of all OS-known adapters in the system. OS-known adapters can include adapters that are physically present in the system (logical adapters)    
/// as well as ones that are no longer present in the system but are still recognized by the OS.
/// \platform
/// \ALL
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[out] lppAdapterInfo is pointer to the pointer of AdapterInfo array. Initialize to NULL before calling this API. ADL will allocate the necessary memory, using the user provided callback function.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
/// 
/// \remarks This API uses the memory allocation callback function provided by the user.
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
ADL_EXTERNC int EXPOSED ADL2_Adapter_AdapterInfoX2_Get (ADL_CONTEXT_HANDLE context,AdapterInfo **lppAdapterInfo);

///
/// \brief Retrieves all OS-known adapter information.
/// 
/// This function retrieves the adapter information of all OS-known adapters in the system. OS-known adapters can include adapters that are physically present in the system (logical adapters)    
/// as well as ones that are no longer present in the system but are still recognized by the OS.
/// \platform
/// \ALL
/// \param[out] lppAdapterInfo is pointer to the pointer of AdapterInfo array. Initialize to NULL before calling this API. ADL will allocate the necessary memory, using the user provided callback function.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
/// 
/// \remarks This API uses the memory allocation callback function provided by the user.
ADL_EXTERNC int EXPOSED ADL_Adapter_AdapterInfoX2_Get (AdapterInfo **lppAdapterInfo);

///
/// \brief ADL local interface. Function to query a string registry value set by driver.
/// 
/// This function queries a driver registry string value for a specified adapter by specifying the subkey path and key name.
/// \param[in]  iAdapterIndex		The ADL index handle of the desired adapter.
/// \param[in]  iDriverPathOption	The option of the driver path. 0: Current; 1: function1; 2: function2; 0xFFFF for all device.
/// \param[in]  szSubKey			The path of registry sub key to be accessed. This is a null terminated string and the parameter can be NULL.
/// \param[in]  szKeyName			The name of registry value to be got. This is a null terminated string.
/// \param[in]  iSize				The size of registry value to be got.
/// \param[out] lpKeyValue			The pointer to registry value to be got.
/// \platform 
/// \WIN
/// \return If the function valid, the return value is 1. Otherwise it is 0. 
ADL_EXTERNC int EXPOSED ADL_Adapter_RegValueString_Get(int iAdapterIndex, int iDriverPathOption, char* szSubKey, char *szKeyName, int iSize, char *lpKeyValue);

///
/// \brief ADL local interface. Function to set a driver registry string value.
/// 
/// This function sets a driver registry string value for a specified adapter by specifying the subkey path and key name.
/// \param[in]  iAdapterIndex		The ADL index handle of the desired adapter.
/// \param[in]  iDriverPathOption	The option of the driver path. 0: Current; 1: function1; 2: function2; 0xFFFF for all device.
/// \param[in]  szSubKey			The path of registry sub key to be accessed. This is a null terminated string and the parameter can be NULL.
/// \param[in]  szKeyName			The name of registry value to be set. This is a null terminated string.
/// \param[in]  iSize				The size of registry value to be set.
/// \param[in]	lpKeyValue			The pointer to registry value to be set.
/// \platform 
/// \WIN
/// \return If the function valid, the return value is 1. Otherwise it is 0. 
ADL_EXTERNC int EXPOSED ADL_Adapter_RegValueString_Set(int iAdapterIndex, int iDriverPathOption, char* szSubKey, char *szKeyName, int iSize, char *lpKeyValue);

/// \brief ADL local interface. Function to set a driver registry string value.
/// 
/// This function sets a driver registry string value for a specified adapter by specifying the subkey path and key name.
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in]  iAdapterIndex		The ADL index handle of the desired adapter.
/// \param[in]  iDriverPathOption	The option of the driver path. 0: Current; 1: function1; 2: function2; 0xFFFF for all device.
/// \param[in]  szSubKey			The path of registry sub key to be accessed. This is a null terminated string and the parameter can be NULL.
/// \param[in]  szKeyName			The name of registry value to be set. This is a null terminated string.
/// \param[in]  iSize				The size of registry value to be set.
/// \param[in]	lpKeyValue			The pointer to registry value to be set.
/// \platform 
/// \WIN
/// \return If the function valid, the return value is 1. Otherwise it is 0. 
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
ADL_EXTERNC int EXPOSED ADL2_Adapter_RegValueString_Set(ADL_CONTEXT_HANDLE context, int iAdapterIndex, int iDriverPathOption, char* szSubKey, char *szKeyName, int iSize, char *lpKeyValue);

///
/// \brief ADL local interface. Function to query a string registry value set by driver.
/// 
/// This function queries a driver registry string value for a specified adapter by specifying the subkey path and key name.
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in]  iAdapterIndex		The ADL index handle of the desired adapter.
/// \param[in]  iDriverPathOption	The option of the driver path. 0: Current; 1: function1; 2: function2; 0xFFFF for all device.
/// \param[in]  szSubKey			The path of registry sub key to be accessed. This is a null terminated string and the parameter can be NULL.
/// \param[in]  szKeyName			The name of registry value to be got. This is a null terminated string.
/// \param[in]  iSize				The size of registry value to be got.
/// \param[out] lpKeyValue			The pointer to registry value to be got.
/// \platform 
/// \WIN
/// \return If the function valid, the return value is 1. Otherwise it is 0. 
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
ADL_EXTERNC int EXPOSED ADL2_Adapter_RegValueString_Get(ADL_CONTEXT_HANDLE context, int iAdapterIndex, int iDriverPathOption, char* szSubKey, char *szKeyName, int iSize, char *lpKeyValue);

///
/// \brief ADL local interface. Function to query a integer registry value set by driver.
/// 
/// This function queries a driver registry integer value for a specified adapter by specifying the subkey path and key name.
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in]  iAdapterIndex		The ADL index handle of the desired adapter.
/// \param[in]  iDriverPathOption	The option of the driver path. 0: Current; 1: function1; 2: function2; 0xFFFF for all device.
/// \param[in]  szSubKey			The path of registry subkey to be accessed. This is a null terminated string and the parameter can be NULL.
/// \param[in]  szKeyName			The name of registry value to be got. This is a null terminated string.
/// \param[out] lpKeyValue			The pointer to registry value to be got.
/// \platform 
/// \WIN
/// \return If the function valid, the return value is 1. Otherwise it is 0. 
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
ADL_EXTERNC int EXPOSED ADL2_Adapter_RegValueInt_Get(ADL_CONTEXT_HANDLE context, int iAdapterIndex, int iDriverPathOption, char* szSubKey, char *szKeyName, int *lpKeyValue);

///
/// \brief ADL local interface. Function to query a integer registry value set by driver.
/// 
/// This function queries a driver registry integer value for a specified adapter by specifying the subkey path and key name.
/// \param[in]  iAdapterIndex		The ADL index handle of the desired adapter.
/// \param[in]  iDriverPathOption	The option of the driver path. 0: Current; 1: function1; 2: function2; 0xFFFF for all device.
/// \param[in]  szSubKey			The path of registry subkey to be accessed. This is a null terminated string and the parameter can be NULL.
/// \param[in]  szKeyName			The name of registry value to be got. This is a null terminated string.
/// \param[out] lpKeyValue			The pointer to registry value to be got.
/// \platform 
/// \WIN
/// \return If the function valid, the return value is 1. Otherwise it is 0. 
ADL_EXTERNC int EXPOSED ADL_Adapter_RegValueInt_Get(int iAdapterIndex, int iDriverPathOption, char* szSubKey, char *szKeyName, int *lpKeyValue);

///
/// \brief ADL local interface. Function to set a driver registry integer value.
/// 
/// This function sets a driver registry integer value for a specified adapter by specifying the subkey path and key name.
/// \param[in]  iAdapterIndex		The ADL index handle of the desired adapter.
/// \param[in]  iDriverPathOption	The option of the driver path. 0: Current; 1: function1; 2: function2; 0xFFFF for all device.
/// \param[in]  szSubKey			The path of registry subkey to be accessed. This is a null terminated string and the parameter can be NULL.
/// \param[in]  szKeyName			The name of registry value to be set. This is a null terminated string.
/// \param[in]  iKeyValue			The integer registry value to be set.
/// \platform 
/// \WIN
/// \return If the function valid, the return value is 1. Otherwise it is 0. 
ADL_EXTERNC int EXPOSED ADL_Adapter_RegValueInt_Set(int iAdapterIndex, int iDriverPathOption, char *szSubKey, char *szKeyName, int iKeyValue);

///
/// \brief ADL local interface. Function to set a driver registry integer value.
/// 
/// This function sets a driver registry integer value for a specified adapter by specifying the subkey path and key name.
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in]  iAdapterIndex		The ADL index handle of the desired adapter.
/// \param[in]  iDriverPathOption	The option of the driver path. 0: Current; 1: function1; 2: function2; 0xFFFF for all device.
/// \param[in]  szSubKey			The path of registry subkey to be accessed. This is a null terminated string and the parameter can be NULL.
/// \param[in]  szKeyName			The name of registry value to be set. This is a null terminated string.
/// \param[in]  iKeyValue			The integer registry value to be set.
/// \platform 
/// \WIN
/// \return If the function valid, the return value is 1. Otherwise it is 0. 
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
ADL_EXTERNC int EXPOSED ADL2_Adapter_RegValueInt_Set(ADL_CONTEXT_HANDLE context, int iAdapterIndex, int iDriverPathOption, char *szSubKey, char *szKeyName, int iKeyValue);


///
///\brief Function to get the ASICFamilyType from the adapter. 
/// 
/// This function retrieves the ASIC family types for a specified adapter.
/// \platform
/// \ALL
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[out] lpAsicTypes The pointer to the \ref define_Asic_type information retrieved from the driver.
/// \param[out] lpValids The pointer to the bit vector indicating which bit is valid on the lpAsicTypes returned.
/// \return If the function succeeds, the return value is \ref ADL_OK (zero). Otherwise the return value is an ADL error code (non-zero). \ref define_adl_results 
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
ADL_EXTERNC int EXPOSED ADL2_Adapter_ASICFamilyType_Get (ADL_CONTEXT_HANDLE context,int iAdapterIndex, int* lpAsicTypes, int* lpValids);

///
///\brief Function to get the ASICFamilyType from the adapter. 
/// 
/// This function retrieves the ASIC family types for a specified adapter.
/// \platform
/// \ALL
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[out] lpAsicTypes The pointer to the \ref define_Asic_type information retrieved from the driver.
/// \param[out] lpValids The pointer to the bit vector indicating which bit is valid on the lpAsicTypes returned.
/// \return If the function succeeds, the return value is \ref ADL_OK (zero). Otherwise the return value is an ADL error code (non-zero). \ref define_adl_results 
ADL_EXTERNC int EXPOSED ADL_Adapter_ASICFamilyType_Get (int iAdapterIndex, int* lpAsicTypes, int* lpValids);

///
/// \brief Function to get the current Force3DClock setting from the adapter. 
///
/// This function retrieves the adapter speed information for a specified adapter.  Return valud can be \ref ADL_ADAPTER_SPEEDCAPS_SUPPORTED or “0”
/// \platform
/// \ALL
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[out] lpCaps The caps of adapter speed settings
/// \param[out] lpValid The valid bits of adapter speed settings
/// \return If the function succeeds, the return value is \ref ADL_OK (zero). Otherwise the return value is an ADL error code (non-zero). \ref define_adl_results 
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
ADL_EXTERNC int EXPOSED ADL2_Adapter_Speed_Caps (ADL_CONTEXT_HANDLE context,int iAdapterIndex, int* lpCaps, int* lpValid);

///
/// \brief Function to get the current Force3DClock setting from the adapter. 
///
/// This function retrieves the adapter speed information for a specified adapter.  Return valud can be \ref ADL_ADAPTER_SPEEDCAPS_SUPPORTED or “0”
/// \platform
/// \ALL
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[out] lpCaps The caps of adapter speed settings
/// \param[out] lpValid The valid bits of adapter speed settings
/// \return If the function succeeds, the return value is \ref ADL_OK (zero). Otherwise the return value is an ADL error code (non-zero). \ref define_adl_results 
ADL_EXTERNC int EXPOSED ADL_Adapter_Speed_Caps (int iAdapterIndex, int* lpCaps, int* lpValid);

///
/// \brief Function to get the current Speed setting from the adapter.
///
/// This function retrieves the adapter speed information for a specified adapter.  Return value is either \ref ADL_CONTEXT_SPEED_UNFORCED or \ref ADL_CONTEXT_SPEED_FORCEHIGH
/// \platform
/// \ALL
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[out] lpCurrent The current speed setting
/// \param[out] lpDefault The default speed setting
/// \return If the function succeeds, the return value is \ref ADL_OK (zero). Otherwise the return value is an ADL error code (non-zero). \ref define_adl_results 
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
ADL_EXTERNC int EXPOSED ADL2_Adapter_Speed_Get (ADL_CONTEXT_HANDLE context,int iAdapterIndex, int *lpCurrent, int *lpDefault);

///
/// \brief Function to get the current Speed setting from the adapter.
///
/// This function retrieves the adapter speed information for a specified adapter.  Return value is either \ref ADL_CONTEXT_SPEED_UNFORCED or \ref ADL_CONTEXT_SPEED_FORCEHIGH
/// \platform
/// \ALL
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[out] lpCurrent The current speed setting
/// \param[out] lpDefault The default speed setting
/// \return If the function succeeds, the return value is \ref ADL_OK (zero). Otherwise the return value is an ADL error code (non-zero). \ref define_adl_results 
ADL_EXTERNC int EXPOSED ADL_Adapter_Speed_Get (int iAdapterIndex, int *lpCurrent, int *lpDefault);

///
/// \brief Function to set the current Speed setting from the adapter.
///
/// This function set the adapter speed information for a specified adapter.  Input value is either \ref ADL_CONTEXT_SPEED_UNFORCED or \ref ADL_CONTEXT_SPEED_FORCEHIGH
/// \platform
/// \ALL
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in] iAdapterIndex The ADL index handle of the desired adapter.
/// \param[in] iSpeed The speed to set on specified adapter
/// \return If the function succeeds, the return value is \ref ADL_OK (zero). Otherwise the return value is an ADL error code (non-zero). \ref define_adl_results 
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
ADL_EXTERNC int EXPOSED ADL2_Adapter_Speed_Set (ADL_CONTEXT_HANDLE context,int iAdapterIndex, int iSpeed);

///
/// \brief Function to set the current Speed setting from the adapter.
///
/// This function set the adapter speed information for a specified adapter.  Input value is either \ref ADL_CONTEXT_SPEED_UNFORCED or \ref ADL_CONTEXT_SPEED_FORCEHIGH
/// \platform
/// \ALL
/// \param[in] iAdapterIndex The ADL index handle of the desired adapter.
/// \param[in] iSpeed The speed to set on specified adapter
/// \return If the function succeeds, the return value is \ref ADL_OK (zero). Otherwise the return value is an ADL error code (non-zero). \ref define_adl_results 
ADL_EXTERNC int EXPOSED ADL_Adapter_Speed_Set (int iAdapterIndex, int iSpeed);

///
/// \brief Function to check if the GPU is accessible or not at the time of this call.
/// 
/// Some GPUs enter into various power savings mode when not in use, and during this time, direct access to the GPU can result in failures.
/// Access through proper channels (such as via ADL) always works because the software accounts for the GPU's accessibility.
/// However, direct access outside of authorised mechanisms may fail.
/// Use this API to find out if the GPU is currently accessible or not.
///  If API returns GPU accessible, this status will be maintained for 2 seconds.
///
/// \platform
/// \ALL
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[out] lpAccessibility The pointer to an int  value which indicates if the adapter is accessible or not (\ref ADL_TRUE : Accessible, \ref ADL_FALSE : Not accessible)
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
ADL_EXTERNC int EXPOSED ADL2_Adapter_Accessibility_Get (ADL_CONTEXT_HANDLE context,int iAdapterIndex, int  *lpAccessibility); 

///
/// \brief Function to check if the GPU is accessible or not at the time of this call.
/// 
/// Some GPUs enter into various power savings mode when not in use, and during this time, direct access to the GPU can result in failures.
/// Access through proper channels (such as via ADL) always works because the software accounts for the GPU's accessibility.
/// However, direct access outside of authorised mechanisms may fail.
/// Use this API to find out if the GPU is currently accessible or not.
///  If API returns GPU accessible, this status will be maintained for 2 seconds.
///
/// \platform
/// \ALL
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[out] lpAccessibility The pointer to an int  value which indicates if the adapter is accessible or not (\ref ADL_TRUE : Accessible, \ref ADL_FALSE : Not accessible)
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
ADL_EXTERNC int EXPOSED ADL_Adapter_Accessibility_Get (int iAdapterIndex, int  *lpAccessibility); 

///
/// \brief ADL local interface. Function to retrieve BIOS information.
/// 
/// This function retrieves the BIOS information for a specified adapter.
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[out]  lpBiosInfo The pointer to the structure storing the retrieved BIOs information.
/// \platform 
/// \LNX
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
ADL_EXTERNC int EXPOSED ADL2_Adapter_VideoBiosInfo_Get(ADL_CONTEXT_HANDLE context, int iAdapterIndex, ADLBiosInfo* lpBiosInfo );

///
/// \brief ADL local interface. Function to retrieve BIOS information.
/// 
/// This function retrieves the BIOS information for a specified adapter.
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[out]  lpBiosInfo The pointer to the structure storing the retrieved BIOs information.
/// \platform 
/// \LNX
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
ADL_EXTERNC int EXPOSED ADL_Adapter_VideoBiosInfo_Get( int iAdapterIndex, ADLBiosInfo* lpBiosInfo );

///
///\brief Function to get the unique identifier of an adapter.
/// 
/// This function retrieves the unique identifier of a specified adapter.\n
/// The adapter ID is a unique value and will be used to determine what other controllers share the same adapter.\n
/// The desktop will use this to find which HDCs are associated with an adapter.
/// \platform
/// \ALL
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in]   iAdapterIndex The ADL index handle of the desired adapter.
/// \param[out]  lpAdapterID The pointer to the adapter identifier. Zero means: The adapter is not AMD.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
///
/// \remarks This API is a duplicate to ADL_Display_AdapterID_Get()
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
 ADL_EXTERNC int EXPOSED ADL2_Adapter_ID_Get(ADL_CONTEXT_HANDLE context,int iAdapterIndex, int* lpAdapterID);

///
///\brief Function to get the unique identifier of an adapter.
/// 
/// This function retrieves the unique identifier of a specified adapter.\n
/// The adapter ID is a unique value and will be used to determine what other controllers share the same adapter.\n
/// The desktop will use this to find which HDCs are associated with an adapter.
/// \platform
/// \ALL
/// \param[in]   iAdapterIndex The ADL index handle of the desired adapter.
/// \param[out]  lpAdapterID The pointer to the adapter identifier. Zero means: The adapter is not AMD.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
///
/// \remarks This API is a duplicate to ADL_Display_AdapterID_Get()
 ADL_EXTERNC int EXPOSED ADL_Adapter_ID_Get(int iAdapterIndex, int* lpAdapterID);

///
/// \brief Function to retrieve adapter caps information.
/// 
/// This function implements a DI call to retrieve adapter capability information .
/// \platform
/// \ALL
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[out] adapterCaps The pointer to the structure storing the retrieved adapter capability information.
/// \return If the function succeeds, the return value is \ref ADL_OK, or an ADL error code otherwise. \ref define_adl_results
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
ADL_EXTERNC int EXPOSED ADL2_AdapterX2_Caps(ADL_CONTEXT_HANDLE context,int iAdapterIndex,  ADLAdapterCapsX2 *adapterCaps);

///
/// \brief Function to retrieve adapter caps information.
/// 
/// This function implements a DI call to retrieve adapter capability information .
/// \platform
/// \ALL
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[out] adapterCaps The pointer to the structure storing the retrieved adapter capability information.
/// \return If the function succeeds, the return value is \ref ADL_OK, or an ADL error code otherwise. \ref define_adl_results
ADL_EXTERNC int EXPOSED ADL_AdapterX2_Caps(int iAdapterIndex,  ADLAdapterCapsX2 *adapterCaps);

///
/// \brief \newAPI15 Function to retrieve current workattaion overdrive support capabilities
/// 
/// This function retrieves current Stress Test overdrivecapabilities for a specified adapter.
/// \platform
/// \ALL
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in]  iSupported The pointer to an int variable which indicates if Overdrive feature is supported ( \ref ADL_TRUE : supported, \ref ADL_FALSE : not supported)
/// \param[in]  iEnabled The pointer to an int variable which indicates if Overdrive feature is enabled ( \ref ADL_TRUE : enabled, \ref ADL_FALSE : disabled)
/// \param[in]  iVersion The pointer to an int variable receiving the Overdrive feature version.
/// \return If the function succeeds, the return value is \ref ADL_OK (zero). Otherwise the return value is an ADL error code (non-zero). \ref define_adl_results. If Overdrive feature is not supported the return code is \ref ADL_ERR_NOT_SUPPORTED 
///
/// \remarks Call this API prior to calling any other Overdrive APIs to determine if this feature is supported and enabled.
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
ADL_EXTERNC int EXPOSED ADL2_Stress_Test_Cap(ADL_CONTEXT_HANDLE context, int iAdapterIndex, int * iSupported, int * iEnabled, int * iVersion);

///
/// \brief \newAPI15 Function to retrieve current workattaion overdrive support capabilities
/// 
/// This function retrieves current Throttle Notification overdrivecapabilities for a specified adapter.
/// \platform
/// \ALL
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in]  iSupported The pointer to an int variable which indicates if Overdrive feature is supported ( \ref ADL_TRUE : supported, \ref ADL_FALSE : not supported)
/// \param[in]  iEnabled The pointer to an int variable which indicates if Overdrive feature is enabled ( \ref ADL_TRUE : enabled, \ref ADL_FALSE : disabled)
/// \param[in]  iVersion The pointer to an int variable receiving the Overdrive feature version.
/// \return If the function succeeds, the return value is \ref ADL_OK (zero). Otherwise the return value is an ADL error code (non-zero). \ref define_adl_results. If Overdrive feature is not supported the return code is \ref ADL_ERR_NOT_SUPPORTED 
///
/// \remarks Call this API prior to calling any other Overdrive APIs to determine if this feature is supported and enabled.
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
ADL_EXTERNC int EXPOSED ADL2_Throttle_Notification_Cap(ADL_CONTEXT_HANDLE context, int iAdapterIndex, int * iSupported, int * iEnabled, int * iVersion);

///
/// \brief \newAPI15 ADL local interface Function to restore all the ACE's INF registry defaults.
/// 
/// This function restores the ACE INF registry defaults. 
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \platform
/// \ALL
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
ADL_EXTERNC int EXPOSED ADL2_Adapter_AceDefaults_Restore(ADL_CONTEXT_HANDLE context, int iAdapterIndex);

///
/// \brief \newAPI15 ADL local interface. Retrieves extended adapter information for given adapter or all OS-known adapters.
///
/// This function retrieves information for passed adapter or if pass -1, information of all OS-known adapters in the system. OS-known adapters can include adapters that are physically present in the system (logical adapters)    
/// as well as ones that are no longer present in the system but are still recognized by the OS.
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter or -1 if all adapters are desired
/// \param[out]  number of items in the lppAdapterInfo array. Can pass NULL pointer if passing an adapter index (in which case only one AdapterInfo is returned)
/// \param[out]  lppAdapterInfoX2 pointer to the pointer of AdapterInfoX2 array. Initialize to NULL before calling this API. ADL will allocate the necessary memory, using the user provided callback function.
/// \platform 
/// \ALL
/// \return If the function valid, the return value is 1. Otherwise it is 0. 
/// \remarks This API uses the memory allocation callback function provided by the user.
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
ADL_EXTERNC int EXPOSED ADL2_Adapter_AdapterInfoX4_Get(ADL_CONTEXT_HANDLE context, int iAdapterIndex, int* numAdapters, AdapterInfoX2** lppAdapterInfoX2);

///
/// \brief \newAPI15 ADL local interface. Retrieves adapter information for given adapter or all OS-known adapters.
/// 
/// This function retrieves information for passed adapter or if pass -1, information of all OS-known adapters in the system. OS-known adapters can include adapters that are physically present in the system (logical adapters)    
/// as well as ones that are no longer present in the system but are still recognized by the OS.
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter or -1 if all adapters are desired
/// \param[out]  number of items in the lppAdapterInfo array. Can pass NULL pointer if passign an adapter index (in which case only one AdapterInfo is returned)
/// \param[out]  lppAdapterInfo pointer to the pointer of AdapterInfo array. Initialize to NULL before calling this API. ADL will allocate the necessary memory, using the user provided callback function.
/// \platform 
/// \ALL
/// \return If the function valid, the return value is 1. Otherwise it is 0. 
/// \remarks This API uses the memory allocation callback function provided by the user.
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
ADL_EXTERNC int EXPOSED ADL2_Adapter_AdapterInfoX3_Get(ADL_CONTEXT_HANDLE context, int iAdapterIndex, int* numAdapters, AdapterInfo** lppAdapterInfo);

///
/// \brief \newAPI15 Function to disable a list of logic adapters once.
/// 
/// This function disable multiple adapters in one CCD call for Win7 and later in order to improve the performace. 
/// the fucntion will fail if the current primary adapter is in the disabled adapter list
/// \platform
/// \WIN7,WIN8
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in] iNumAdapters An integer indicates the number of desktops to be disabled.
/// \param[in] lpAdapterIndexList The pointer to the integer array that contains the list of logicl adapter indexes to be disabled
/// \param[in] isSkipSaveDB A bool flag to indicate a temporary Display config setting (no SDC_SAVE_TO_DATABASE)
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
ADL_EXTERNC int EXPOSED ADL2_Adapter_AdapterList_Disable(ADL_CONTEXT_HANDLE context, int iNumAdapters, int *lpAdapterIndexList, bool isSkipSaveDB = false);

///
/// \brief \newAPI15 Function to disable a list of logic adapters once.
/// 
/// This function disable multiple adapters in one CCD call for Win7 and later in order to improve the performace. 
/// the fucntion will fail if the current primary adapter is in the disabled adapter list
/// \platform
/// \WIN7,WIN8
/// \param[in] iNumAdapters An integer indicates the number of desktops to be disabled.
/// \param[in] lpAdapterIndexList The pointer to the integer array that contains the list of logicl adapter indexes to be disabled
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
ADL_EXTERNC int EXPOSED ADL_Adapter_AdapterList_Disable(int iNumAdapters, int *lpAdapterIndexList);

///
///\brief \newAPI15 Function to get the ASICFamilyType from the adapter. 
/// 
/// This function retrieves the Big Software & Red Stone support information for a specified adapter.
/// \platform
/// \ALL
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[out] lpBigSwSupportMajor The pointer to the Big Software major version information retrieved from the driver. \ref define_Asic_type
/// \param[out] lpBigSwSupportMinor The pointer to the Big Software minor version information retrieved from the driver. \ref define_Asic_type
/// \param[out] lpRedStoneSupport The pointer to the Red Stone support information retrieved from the driver.
/// \return If the function succeeds, the return value is \ref ADL_OK (zero). Otherwise the return value is an ADL error code (non-zero). \ref define_adl_results 
ADL_EXTERNC int EXPOSED ADL_Adapter_BigSw_Info_Get(int iAdapterIndex, int* lpBigSwSupportMajor, int* lpBigSwSupportMinor, int* lpRedStoneSupport);

///
/// This \newAPI15 function retrieves the Big Software & Red Stone support information for a specified adapter.
/// \platform
/// \ALL
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[out] lpBigSwSupportMajor The pointer to the Big Software major version information retrieved from the driver. \ref define_Asic_type
/// \param[out] lpBigSwSupportMinor The pointer to the Big Software minor version information retrieved from the driver. \ref define_Asic_type
/// \param[out] lpRedStoneSupport The pointer to the Red Stone support information retrieved from the driver.
/// \return If the function succeeds, the return value is \ref ADL_OK (zero). Otherwise the return value is an ADL error code (non-zero). \ref define_adl_results 
ADL_EXTERNC int EXPOSED ADL2_Adapter_BigSw_Info_Get(ADL_CONTEXT_HANDLE context, int iAdapterIndex, int* lpBigSwSupportMajor, int* lpBigSwSupportMinor, int* lpRedStoneSupport);

///
/// \brief \newAPI15 Function to retrieve adapter caps information.
/// 
/// This function implements a DI call to retrieve adapter capability information .
/// \platform
/// \ALL
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[out] adapterCaps The pointer to the structure storing the retrieved adapter capability information.
/// \return If the function succeeds, the return value is \ref ADL_OK, or an ADL error code otherwise. \ref define_adl_results
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
ADL_EXTERNC int EXPOSED ADL2_Adapter_Caps(ADL_CONTEXT_HANDLE context, int iAdapterIndex, ADLAdapterCaps *adapterCaps);

///
/// \brief \newAPI15 Function to retrieve adapter caps information.
/// 
/// This function implements a DI call to retrieve adapter capability information .
/// \platform
/// \ALL
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[out] adapterCaps The pointer to the structure storing the retrieved adapter capability information.
/// \return If the function succeeds, the return value is \ref ADL_OK, or an ADL error code otherwise. \ref define_adl_results
ADL_EXTERNC int EXPOSED ADL_Adapter_Caps(int iAdapterIndex, ADLAdapterCaps *adapterCaps);

///
/// \brief \newAPI15 ADL local interface. Function to retrieve chipset information.
/// 
/// This function retrieves the chipset information for a specified adapter.
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[out]  lpChipSetInfo The pointer to the structure storing the retrieved chipset information.
/// \platform 
/// \ALL
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
ADL_EXTERNC int EXPOSED ADL2_Adapter_ChipSetInfo_Get(ADL_CONTEXT_HANDLE context, int iAdapterIndex, ADLChipSetInfo * lpChipSetInfo);

///
/// \brief \newAPI15 ADL local interface. Function to retrieve chipset information.
/// 
/// This function retrieves the chipset information for a specified adapter.
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[out]  lpChipSetInfo The pointer to the structure storing the retrieved chipset information.
/// \platform 
/// \ALL
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
ADL_EXTERNC int EXPOSED ADL_Adapter_ChipSetInfo_Get(int iAdapterIndex, ADLChipSetInfo * lpChipSetInfo);

///
/// \brief \newAPI15 Function to Checks the feature if given GPU (identified by adapter id) supports or not.
/// 
/// Checks if given GPU (identified by adapter id) supports feature (iFeatureID) or not.
/// \platform
/// \ALL
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in] iAdapterIndex: The ADL index handle of the desired adapter.
/// \param[in] iFeatureID: The Feature index of the desired feature. \ref ADL_UIFEATURES_GROUP
/// \param[out] iIsFeatureSupported The pointer to the structure storing the retrieved adapter capability information.
/// \return If the function succeeds, the return value is \ref ADL_OK, or an ADL error code otherwise. \ref define_adl_results
ADL_EXTERNC int EXPOSED ADL2_Adapter_Feature_Caps(ADL_CONTEXT_HANDLE context, int iAdapterIndex, ADL_UIFEATURES_GROUP iFeatureID, int *iIsFeatureSupported);

///
/// \brief \newAPI15 Function to retrieve HBC Capability.
///
/// This function retrieves the HBC Capability for a specified graphics adapter.
/// \platform
/// \ALL
/// \param[in] context          : Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in]  iAdapterIndex   : The ADL index handle of the desired adapter.
/// \param[out] lpHbcCapable    : Will be set to 1 to indicate that given GPU supports HBC.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
ADL_EXTERNC int EXPOSED ADL2_Adapter_HBC_Caps(ADL_CONTEXT_HANDLE context, int iAdapterIndex, int *lpHbcCapable);

/// 
/// \brief \newAPI15 Function to retrieve whether an adapter is Headless or not.
///
/// This function implements private adapter info to retrieve the configuration state of a specified adapter.
/// \platform
/// \WIN
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in] iAdapterIndex    The ADL index handle of the desired adapter.
/// \param[out] lpHeadless  Integer indicating the state of the adapter.
ADL_EXTERNC int EXPOSED ADL2_Adapter_Headless_Get(ADL_CONTEXT_HANDLE context, int iAdapterIndex, int *lpHeadless);

///
/// \brief \newAPI15 This function retrieves the creator who game support information for a specified adapter.
/// \platform
/// \ALL
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[out] lpCwgSupport: Will be set to 1 to indicate that given GPU supports CWG. \ref define_Asic_type
/// \param[out] lpIsGamingMode: Will be set to 1 to indicate that given GPU supports Gaming Mode. \ref define_Asic_type
/// \return If the function succeeds, the return value is \ref ADL_OK (zero). Otherwise the return value is an ADL error code (non-zero). \ref define_adl_results 
ADL_EXTERNC int EXPOSED ADL2_Adapter_IsGamingDriver_Info_Get(ADL_CONTEXT_HANDLE context, int iAdapterIndex, int* lpCwgSupport, int* lpIsGamingMode);

///
/// \brief \newAPI15 Function to retrieve memory information from the adapter. Version 2
///
/// This function retrieves the memory information for a specified graphics adapter.
/// \platform
/// \LNX
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[out] lpMemoryInfo2 The pointer to the structure storing the retrieved memory information.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
ADL_EXTERNC int EXPOSED ADL2_Adapter_MemoryInfo2_Get(ADL_CONTEXT_HANDLE context, int iAdapterIndex, ADLMemoryInfo2 *lpMemoryInfo2);

///
/// \brief \newAPI15 Function to retrieve memory information from the adapter. Version 2
///
/// This function retrieves the memory information for a specified graphics adapter.
/// \platform
/// \LNX
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[out] lpMemoryInfo2 The pointer to the structure storing the retrieved memory information.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
ADL_EXTERNC int EXPOSED ADL_Adapter_MemoryInfo2_Get(int iAdapterIndex, ADLMemoryInfo2 *lpMemoryInfo2);

///
/// \brief \newAPI15 Function to retrieve memory information from the adapter. Version 4
///
/// This function retrieves the memory information for a specified graphics adapter.
/// \platform
/// \LNX
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[out] lpMemoryInfoX4 The pointer to the structure storing the retrieved memory information.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
ADL_EXTERNC int EXPOSED ADL2_Adapter_MemoryInfoX4_Get(ADL_CONTEXT_HANDLE context, int iAdapterIndex, ADLMemoryInfoX4 *lpMemoryInfoX4);

///
/// \brief \newAPI15 Function to retrieve true Hardware generated random number.
/// 
/// This function implements a lhEscape call to retrieve TRGN from hardware .
/// \platform
/// \ALL
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[in]  iTRNGSize size of the requested TRNG
/// \param[in]  iTRNGBufferSize size of the trngBuffer
/// \param[out] trngBuffer The pointer where TRNG value is stored, buffer should be allocated at client side
/// \return If the function succeeds, the return value is \ref ADL_OK, or an ADL error code otherwise. \ref define_adl_results
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
ADL_EXTERNC int EXPOSED ADL2_Adapter_TRNG_Get(ADL_CONTEXT_HANDLE context, int iAdapterIndex, int iTRNGSize, int iTRNGBufferSize, char *lpTRNGBuffer);


///
/// \brief \newAPI15 Function to re-enumerate adapter modes. 
///
/// This function re-enumerates adapter modes
/// \platform
/// \Win7
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
/// \remarks For Win7 only. This internal AMD API is used to test driver's SLS middle mode feature.
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
ADL_EXTERNC int EXPOSED ADL2_Adapter_Modes_ReEnumerate(ADL_CONTEXT_HANDLE context);

///
/// \brief \newAPI15 Function to re-enumerate adapter modes. 
///
/// This function re-enumerates adapter modes
/// \platform
/// \Win7
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
/// \remarks For Win7 only. This internal AMD API is used to test driver's SLS middle mode feature.
ADL_EXTERNC int EXPOSED ADL_Adapter_Modes_ReEnumerate();

///
/// \brief \newAPI15 Function to retrieve the current value of given feature on a given adapter
/// 
///  provides the current value of the given feature
/// \platform
/// \ALL
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in] iAdapterIndex: The ADL index handle of the desired adapter.
/// \param[in] iFeatureID: The Feature index of the desired feature. \ref ADL_UIFEATURES_GROUP
/// \param[out] iCurrent The pointer to the structure storing the retrieved feature current value.
/// \return If the function succeeds, the return value is \ref ADL_OK, or an ADL error code otherwise. \ref define_adl_results
ADL_EXTERNC int EXPOSED ADL2_Feature_Settings_Get(ADL_CONTEXT_HANDLE context, int iAdapterIndex, ADL_UIFEATURES_GROUP iFeatureID, int *iCurrent);

///
/// \brief \newAPI15 Function sets the current value  to driver of given adapter
/// 
/// sets the current value to the given adapter
/// \platform
/// \ALL
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in] iAdapterIndex: The ADL index handle of the desired adapter.
/// \param[in] iFeatureID: The Feature index of the desired feature. \ref ADL_UIFEATURES_GROUP
/// \param[in] iCurrent The pointer to the feature current value
/// \return If the function succeeds, the return value is \ref ADL_OK, or an ADL error code otherwise. \ref define_adl_results
ADL_EXTERNC int EXPOSED ADL2_Feature_Settings_Set(ADL_CONTEXT_HANDLE context, int iAdapterIndex, ADL_UIFEATURES_GROUP iFeatureID, int iCurrent);

///
/// \brief \newAPI15 For given ASIC returns information about components of ASIC GCN architecture. Such as number of compute units, number of Tex (Texture filtering units)  , number of ROPs (render back-ends).
/// \platform 
/// \WIN
/// \param[in]  context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter. The adapter identifies the ASIC that the information will be returned for.
/// \param[out]  gcnInfo The ADL structure that contains information about  components of ASIC GCN architecture.
/// \remarks. The method is supported only for SI+ family of the ASICs and up to Carrizzo inclusive. Otherwise ADL_ERR_NOT_SUPPORTED is returned
ADL_EXTERNC int EXPOSED ADL2_GcnAsicInfo_Get(ADL_CONTEXT_HANDLE context, int iAdapterIndex, ADLGcnInfo* gcnInfo);

///
/// \brief \newAPI15 Function to gets the GPU VM PageSize info.
/// 
/// This function retrieves the GPU VM PageSize info for a specified adapter.
/// \platform
/// \WIN
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in]  iAdapterIndex: The ADL index handle of the desired adapter.
/// \param[out]  iVMPageSizeSupport: 1 for supported and 0 for unsupported
/// \param[out]  iVMPageSizeType: Type will be available only if iVMPageSizeSupport is 1. 0: Invalid; 1: Gaming; 2: Mining
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results 
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
ADL_EXTERNC int EXPOSED ADL2_GPUVMPageSize_Info_Get(ADL_CONTEXT_HANDLE context, int iAdapterIndex, int* iVMPageSizeSupport, int* iVMPageSizeType);

///
/// \brief \newAPI15 Function to sets the GPU VM PageSize info.
/// 
/// This function sets the GPU VM PageSize type for a specified adapter.
/// \platform
/// \WIN
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in]  iAdapterIndex: The ADL index handle of the desired adapter.
/// \param[in]  iVMPageSizeType: Type will be available only if iVMPageSizeSupport = 1. 
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results 
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
ADL_EXTERNC int EXPOSED ADL2_GPUVMPageSize_Info_Set(ADL_CONTEXT_HANDLE context, int iAdapterIndex, int iVMPageSizeType);

/// This \newAPI15 function retrieves the VRAM usage of given adapter
/// \platform
/// \ALL
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in]  iAdapterIndex The index of the desired adapter.
/// \param[in]  iVRAMUsageInMB The pointer to an int variable retrives the current usage of VRAM.
/// \return If the function succeeds, the return value is \ref ADL_OK (zero). Otherwise the return value is an ADL error code (non-zero). \ref define_adl_results 
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
ADL_EXTERNC int EXPOSED ADL2_Adapter_VRAMUsage_Get(ADL_CONTEXT_HANDLE context, int iAdapterIndex, int * iVRAMUsageInMB);

/// This \newAPI15 function retrieves the Dedicated VRAM usage of given adapter
///
/// The function is used to get Dedicated VRAM usge by calling MS Counter.
/// 
/// \platform
/// \ALL
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in]  iAdapterIndex The index of the desired adapter.
/// \param[in]  iVRAMUsageInMB The pointer to an int variable retrives the current usage of VRAM.
/// \return If the function succeeds, the return value is \ref ADL_OK (zero). Otherwise the return value is an ADL error code (non-zero). \ref define_adl_results 
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
ADL_EXTERNC int EXPOSED ADL2_Adapter_DedicatedVRAMUsage_Get(ADL_CONTEXT_HANDLE context, int iAdapterIndex, int * iVRAMUsageInMB);
/// @}




/// \addtogroup VIDEOAPI
/// @{

/// \brief Function to get MM video theater mode info
///
/// The function is used to get multi-media video theater mode information.
/// 
/// \platform
/// \VISTAWIN7
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in]  iAdapterIndex			The ADL index handle of the desired adapter.
/// \param[out] lpOverlayDisplayMode	The pointer to the overlay display mode.
/// \param[out]	lpSavedSettings			The pointer to the saved settings of the related mode.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
ADL_EXTERNC int EXPOSED ADL2_Adapter_VideoTheaterModeInfo_Get(ADL_CONTEXT_HANDLE context, int iAdapterIndex, int* lpOverlayDisplayMode, int* lpSavedSettings);

/// \brief Function to get MM video theater mode info
///
/// The function is used to get multi-media video theater mode information.
/// 
/// \platform
/// \VISTAWIN7
/// \param[in]  iAdapterIndex			The ADL index handle of the desired adapter.
/// \param[out] lpOverlayDisplayMode	The pointer to the overlay display mode.
/// \param[out]	lpSavedSettings			The pointer to the saved settings of the related mode.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
ADL_EXTERNC int EXPOSED ADL_Adapter_VideoTheaterModeInfo_Get(int iAdapterIndex, int* lpOverlayDisplayMode, int* lpSavedSettings);

/// \brief Function to set MM video theater mode info
///
/// The function is used to set multi-media video theater mode information.
/// 
/// \platform
/// \VISTAWIN7
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in]  iAdapterIndex			The ADL index handle of the desired adapter.
/// \param[in]	iOverlayDisplayMode		The overlay display mode to be set.
/// \param[in]	iSavedSettings			The saved settings of the related mode to be set.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
ADL_EXTERNC int EXPOSED ADL2_Adapter_VideoTheaterModeInfo_Set(ADL_CONTEXT_HANDLE context, int iAdapterIndex, int iOverlayDisplayMode, int iSavedSettings);

/// \brief Function to set MM video theater mode info
///
/// The function is used to set multi-media video theater mode information.
/// 
/// \platform
/// \VISTAWIN7
/// \param[in]  iAdapterIndex			The ADL index handle of the desired adapter.
/// \param[in]	iOverlayDisplayMode		The overlay display mode to be set.
/// \param[in]	iSavedSettings			The saved settings of the related mode to be set.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
ADL_EXTERNC int EXPOSED ADL_Adapter_VideoTheaterModeInfo_Set(int iAdapterIndex, int iOverlayDisplayMode, int iSavedSettings);

/// \brief \newAPI15 Function to obtain capabilities of Multi-Media features
/// 
/// The function is used to obtain the capabilities for a set of specific Multi-Media features for a specific display adapter.
/// \platform
/// \VISTAWIN7
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[in]  lppFeatureCaps The pointer to the pointer to the retrieved Feature Caps array. Initialize to NULL before calling this API.
/// \param[out]  lpFeatureCount The pointer to the number of ADLFeatureCaps elements in the retrieved list.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
///
/// \remarks This API uses the memory allocation callback function provided by the user.
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
ADL_EXTERNC int EXPOSED ADL2_MMD_Features_Caps(ADL_CONTEXT_HANDLE context, int iAdapterIndex, ADLFeatureCaps ** lppFeatureCaps, int * lpFeatureCount);

/// \brief \newAPI15 Function to obtain capabilities of Multi-Media features
/// 
/// The function is used to obtain the capabilities for a set of specific Multi-Media features for a specific display adapter.
/// \platform
/// \VISTAWIN7
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[in]  lppFeatureCaps The pointer to the pointer to the retrieved Feature Caps array. Initialize to NULL before calling this API.
/// \param[out]  lpFeatureCount The pointer to the number of ADLFeatureCaps elements in the retrieved list.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
///
/// \remarks This API uses the memory allocation callback function provided by the user.
ADL_EXTERNC int EXPOSED ADL_MMD_Features_Caps(int iAdapterIndex, ADLFeatureCaps ** lppFeatureCaps, int * lpFeatureCount);

/// \brief \newAPI15 Function to obtain the values and state of a Multi-Media feature
/// 
/// The function is used to obtain the values and state of a single Multi-Media feature for a specific display adapter.
/// \platform
/// \VISTAWIN7
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[out]  lppFeatureValues The pointer to the pointer to the retrieved ADLFeatureValues array. Initialize to NULL before calling this API.
/// \param[out]  lpFeatureCount The pointer to the number of ADLFeatureValues elements in the retrieved list.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
///
/// \remarks This API uses the memory allocation callback function provided by the user.
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
ADL_EXTERNC int EXPOSED ADL2_MMD_FeatureValues_Get(ADL_CONTEXT_HANDLE context, int iAdapterIndex, ADLFeatureValues ** lppFeatureValues, int * lpFeatureCount);

/// \brief \newAPI15 Function to obtain the values and state of a Multi-Media feature
/// 
/// The function is used to obtain the values and state of a single Multi-Media feature for a specific display adapter.
/// \platform
/// \VISTAWIN7
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[out]  lppFeatureValues The pointer to the pointer to the retrieved ADLFeatureValues array. Initialize to NULL before calling this API.
/// \param[out]  lpFeatureCount The pointer to the number of ADLFeatureValues elements in the retrieved list.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
///
/// \remarks This API uses the memory allocation callback function provided by the user.
ADL_EXTERNC int EXPOSED ADL_MMD_FeatureValues_Get(int iAdapterIndex, ADLFeatureValues ** lppFeatureValues, int * lpFeatureCount);

/// \brief \newAPI15 Function to set the current value of a Multi-Media feature
/// 
/// The function is used to set the current value of a single Multi-Media feature and optionally provide the handle of SetEvent object.
/// \platform
/// \VISTAWIN7
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[in]  lpFeatureValues A pointer to the ADLFeatureValues array. Refer to ADLFeatureValues structure for more information.
/// \param[in]  iFeatureCount The number of ADLFeatureValues elements in the array.
/// \param[in]  ClientID The Client ID of the caller. It is recommended to provide a valid Client ID to avoid raising caller?s event object, immediately after the current value is set.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
///
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
ADL_EXTERNC int EXPOSED ADL2_MMD_FeatureValues_Set(ADL_CONTEXT_HANDLE context, int iAdapterIndex, ADLFeatureValues * lpFeatureValues, int iFeatureCount, int ClientID);

/// \brief \newAPI15 Function to set the current value of a Multi-Media feature
/// 
/// The function is used to set the current value of a single Multi-Media feature and optionally provide the handle of SetEvent object.
/// \platform
/// \VISTAWIN7
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[in]  lpFeatureValues A pointer to the ADLFeatureValues array. Refer to ADLFeatureValues structure for more information.
/// \param[in]  iFeatureCount The number of ADLFeatureValues elements in the array.
/// \param[in]  ClientID The Client ID of the caller. It is recommended to provide a valid Client ID to avoid raising caller?s event object, immediately after the current value is set.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
///
ADL_EXTERNC int EXPOSED ADL_MMD_FeatureValues_Set(int iAdapterIndex, ADLFeatureValues * lpFeatureValues, int iFeatureCount, int ClientID);

/// @}

/// \ingroup ADAPTERAPI
/// \defgroup PAGEMIGRATIONAPI Page Migration APIs
/// This group describes the Page Migration APIs.

/// \addtogroup PAGEMIGRATIONAPI
///
/// @{
#if defined (_WIN32) || defined(_WIN64)

/// 
/// \brief \newAPI15 Function to retrieve PageMigration Global Settings.
///
/// This function retrieves PageMigration Global Settings.
/// \platform
/// \WIN
/// \param[in] context			        : Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in] iAdapterIndex            : The ADL index handle of the desired adapter.
/// \param[out] lpVirtualSegSettings	: Pointer to ADLFPSSettingsOutput struct which will load the Global FPS Settings 
ADL_EXTERNC int EXPOSED ADL2_PageMigration_Settings_Get(ADL_CONTEXT_HANDLE context, int iAdapterIndex, ADLVirtualSegmentSettingsOutput *lpVirtualSegSettings);

/// 
/// \brief \newAPI15 Function to update PageMigration Global Settings.
///
/// This function update PageMigration Global Settings.
/// \platform
/// \WIN
/// \param[in] context			: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in] iAdapterIndex    : The ADL index handle of the desired adapter.
/// \param[in] iEnabled         : Set to true if page migration is to be enabled. Set to false if page migration is to be disabled and iNewSize will be ignored.
/// \param[in] iNewSize	        : New size in MB
ADL_EXTERNC int EXPOSED ADL2_PageMigration_Settings_Set(ADL_CONTEXT_HANDLE context, int iAdapterIndex, int iEnabled, int iNewSize);

#endif /*(_WIN32) || (_WIN64)*/
/// @}



///\ingroup ADAPTERAPI
///\defgroup CROSSFIREAPI CrossFire APIs
/// This group describes the CrossFire APIs.

///\addtogroup CROSSFIREAPI
/// @{
///
/// \brief Function to retrieve CrossfireX capabilities of the system.
///
/// This function is used to determine if the system is capable of doing CrossfireX, regardless if the system is setup properly.
/// \platform
/// \ALL
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in]	iAdapterIndex The ADL index handle of the desired adapter to query CrossfireX capabilities
/// \param[out]	lpPreferred The index of the preferred CrossfireX chain. The index is a zero based index reference in the ADLCrossfireComb list.
/// \param[out]	lpNumComb The integer value indicating the number of ADLCrossfireComb structures in the lpCrossfireComb buffer
/// \param[out]	ppCrossfireComb The Pointer to an empty memory buffer(NULL).  This function will use the callback to allocate the appropriate buffer size.  This buffer will contain a list of supported CrossfireX combinations if the adapter supports CrossfireX.  If the adapter does not support CrossfireX, this memory buffer will remain empty, or NULL.
/// \return If the function succeeds, the return value is \ref ADL_OK (zero). Otherwise the return value is an ADL error code (non-zero). \ref define_adl_results
///
/// \remarks This API uses the memory allocation callback function provided by the user.
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
ADL_EXTERNC int EXPOSED ADL2_Adapter_Crossfire_Caps (ADL_CONTEXT_HANDLE context,int iAdapterIndex, int* lpPreferred, int* lpNumComb, ADLCrossfireComb **ppCrossfireComb);

///
/// \brief Function to retrieve CrossfireX capabilities of the system.
///
/// This function is used to determine if the system is capable of doing CrossfireX, regardless if the system is setup properly.
/// \platform
/// \ALL
/// \param[in]	iAdapterIndex The ADL index handle of the desired adapter to query CrossfireX capabilities
/// \param[out]	lpPreferred The index of the preferred CrossfireX chain. The index is a zero based index reference in the ADLCrossfireComb list.
/// \param[out]	lpNumComb The integer value indicating the number of ADLCrossfireComb structures in the lpCrossfireComb buffer
/// \param[out]	ppCrossfireComb The Pointer to an empty memory buffer(NULL).  This function will use the callback to allocate the appropriate buffer size.  This buffer will contain a list of supported CrossfireX combinations if the adapter supports CrossfireX.  If the adapter does not support CrossfireX, this memory buffer will remain empty, or NULL.
/// \return If the function succeeds, the return value is \ref ADL_OK (zero). Otherwise the return value is an ADL error code (non-zero). \ref define_adl_results
///
/// \remarks This API uses the memory allocation callback function provided by the user.
ADL_EXTERNC int EXPOSED ADL_Adapter_Crossfire_Caps (int iAdapterIndex, int* lpPreferred, int* lpNumComb, ADLCrossfireComb **ppCrossfireComb);

///
/// \brief \newAPI15 Function to get current CrossfireX combination settings.
///
/// This function is used to retrieve the current information about a particular CrossfireX combination.  A CrossfireX combination includes
/// the CrossfireX capable adapter and its CrossfireX chain (a list of other adapters that will work with the CrossfireX capable adapter).  The possible
/// CrossfireX chain combinations for an adapter is retrieved from the ADL_Adapter_Crossfire_Caps function.
/// \platform
/// \ALL
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in]	iAdapterIndex The ADL index of the CrossfireX capable adapter to query the CrossfireX state and current information
/// \param[in]	lpCrossfireComb The CrossfireX chain to get information about.
/// \param[out]	lpCrossfireInfo State and error information about the CrossfireX combination.
/// \return If the function succeeds, the return value is \ref ADL_OK (zero). Otherwise the return value is an ADL error code (non-zero). \ref define_adl_results
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
ADL_EXTERNC int EXPOSED ADL2_Adapter_Crossfire_Get (ADL_CONTEXT_HANDLE context,int iAdapterIndex, ADLCrossfireComb *lpCrossfireComb, ADLCrossfireInfo *lpCrossfireInfo);

///
/// \brief \newAPI15 Function to get current CrossfireX combination settings.
///
/// This function is used to retrieve the current information about a particular CrossfireX combination.  A CrossfireX combination includes
/// the CrossfireX capable adapter and its CrossfireX chain (a list of other adapters that will work with the CrossfireX capable adapter).  The possible
/// CrossfireX chain combinations for an adapter is retrieved from the ADL_Adapter_Crossfire_Caps function.
/// \platform
/// \ALL
/// \param[in]	iAdapterIndex The ADL index of the CrossfireX capable adapter to query the CrossfireX state and current information
/// \param[in]	lpCrossfireComb The CrossfireX chain to get information about.
/// \param[out]	lpCrossfireInfo State and error information about the CrossfireX combination.
/// \return If the function succeeds, the return value is \ref ADL_OK (zero). Otherwise the return value is an ADL error code (non-zero). \ref define_adl_results
ADL_EXTERNC int EXPOSED ADL_Adapter_Crossfire_Get (int iAdapterIndex, ADLCrossfireComb *lpCrossfireComb, ADLCrossfireInfo *lpCrossfireInfo);

///
/// \brief Function to set CrossfireX combination settings.
///
/// This function is used to enable or disable CrossfireX on a particular adapter (pointed to by iAdapterIndex), along with the indicated CrossfireX chain.
/// The CrossfireX chain combination for the adapter must be one returned by ADL_Adapter_Crossfire_Caps().
/// \platform
/// \ALL
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in]	iAdapterIndex The adapter in which to enable or disable CrossfireX
/// \param[in]	lpCrossfireComb the CrossfireX chain combination to enable or disable for the master adapter.  If this parameter is not NULL, it will
/// enable CrossfireX with the indicated combination.  If this parameter is NULL, it will disable CrossfireX on that particular adapter.
/// \return If the function succeeds, the return value is \ref ADL_OK (zero). Otherwise the return value is an ADL error code (non-zero). \ref define_adl_results
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
ADL_EXTERNC int EXPOSED ADL2_Adapter_Crossfire_Set (ADL_CONTEXT_HANDLE context,int iAdapterIndex, ADLCrossfireComb *lpCrossfireComb);

///
/// \brief Function to set CrossfireX combination settings.
///
/// This function is used to enable or disable CrossfireX on a particular adapter (pointed to by iAdapterIndex), along with the indicated CrossfireX chain.
/// The CrossfireX chain combination for the adapter must be one returned by ADL_Adapter_Crossfire_Caps().
/// \platform
/// \ALL
/// \param[in]	iAdapterIndex The adapter in which to enable or disable CrossfireX
/// \param[in]	lpCrossfireComb the CrossfireX chain combination to enable or disable for the master adapter.  If this parameter is not NULL, it will
/// enable CrossfireX with the indicated combination.  If this parameter is NULL, it will disable CrossfireX on that particular adapter.
/// \return If the function succeeds, the return value is \ref ADL_OK (zero). Otherwise the return value is an ADL error code (non-zero). \ref define_adl_results
ADL_EXTERNC int EXPOSED ADL_Adapter_Crossfire_Set (int iAdapterIndex, ADLCrossfireComb *lpCrossfireComb);

///
/// \brief Function to set CrossfireX status.
///
/// This function is used to enable or disable CrossfireX on a particular adapter (pointed to by iAdapterIndex).
/// \platform
/// \WIN
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in]	iAdapterIndex The adapter in which to enable or disable CrossfireX
/// \param[in]	iState the requested CrossfireX state to be set
/// \return If the function succeeds, the return value is \ref ADL_OK (zero). Otherwise the return value is an ADL error code (non-zero). \ref define_adl_results
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
ADL_EXTERNC int EXPOSED ADL2_Adapter_MVPU_Set (ADL_CONTEXT_HANDLE context,int iAdapterIndex, int iState);

///
/// \brief Function to get current CrossfireX settings for both QUAD and Software crossfire.
///
/// On QUAD Crossfire systems this function is used to retrieve the current information about a particular CrossfireX combination.  A CrossfireX combination includes
/// the CrossfireX capable adapter and its CrossfireX chain (a list of other adapters that will work with the CrossfireX capable adapter).  The possible
/// CrossfireX chain combinations for an adapter is retrieved from the ADL_Adapter_Crossfire_Caps function.
/// On Software Crossfire systems this function is used to query support and status of Crossfire. 
/// \platform
/// \ALL
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in]	iAdapterIndex The ADL index of the CrossfireX capable adapter to query the CrossfireX state and current information
/// \param[in]	lpCrossfireComb The CrossfireX chain to get information about. Ignored when called for Software crossfire
/// \param[out]	lpCrossfireInfo State and error information about the CrossfireX combination.
/// \return If the function succeeds, the return value is \ref ADL_OK (zero). Otherwise the return value is an ADL error code (non-zero). \ref define_adl_results
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
ADL_EXTERNC int EXPOSED ADL2_Adapter_CrossfireX2_Get(ADL_CONTEXT_HANDLE context, int iAdapterIndex, ADLCrossfireComb *lpCrossfireComb, ADLCrossfireInfo *lpCrossfireInfo);

///
/// \brief Function to get current CrossfireX settings for both QUAD and Software crossfire.
///
/// On QUAD Crossfire systems this function is used to retrieve the current information about a particular CrossfireX combination.  A CrossfireX combination includes
/// the CrossfireX capable adapter and its CrossfireX chain (a list of other adapters that will work with the CrossfireX capable adapter).  The possible
/// CrossfireX chain combinations for an adapter is retrieved from the ADL_Adapter_Crossfire_Caps function.
/// On Software Crossfire systems this function is used to query support and status of Crossfire. 
/// \platform
/// \ALL
/// \param[in]	iAdapterIndex The ADL index of the CrossfireX capable adapter to query the CrossfireX state and current information
/// \param[in]	lpCrossfireComb The CrossfireX chain to get information about. Ignored when called for Software crossfire
/// \param[out]	lpCrossfireInfo State and error information about the CrossfireX combination.
/// \return If the function succeeds, the return value is \ref ADL_OK (zero). Otherwise the return value is an ADL error code (non-zero). \ref define_adl_results
ADL_EXTERNC int EXPOSED ADL_Adapter_CrossfireX2_Get(int iAdapterIndex, ADLCrossfireComb *lpCrossfireComb, ADLCrossfireInfo *lpCrossfireInfo);

/// @}


///\ingroup WORKSTATIONAPI
///\defgroup EDIDAPI EDID Management APIs
/// This group describes the EDID Management APIs.

/// \addtogroup EDIDAPI
/// @{
///
///\brief Function to get the board layout information
/// 
/// This function retrieves the ASIC layout information of a specified adapter.\n
/// layout information includes number of slots, size and number of connectors and properties of connectors
/// \platform
/// \ALL
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in]   iAdapterIndex The ADL index handle of the desired adapter.
/// \param[out]  lpValidFlags The integer pointer, specifies the valid bits of the slot & connector information.
/// \param[out]  lpNumberSlots The integer pointer, specifies the number of slots
/// \param[out]  lppBracketSlot The pointer to the structure, storing the bracket slot information.
/// \param[out]  lpNumberConnector The integer pointer, specifies the number of connectors in GPU
/// \param[out]  lppConnector The pointer to the structure, storing the connectors information
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
 ADL_EXTERNC int EXPOSED ADL2_Adapter_BoardLayout_Get(ADL_CONTEXT_HANDLE context,int iAdapterIndex, int* lpValidFlags, int *lpNumberSlots, ADLBracketSlotInfo** lppBracketSlot, int* lpNumberConnector, ADLConnectorInfo** lppConnector);

///
///\brief Function to get the board layout information
/// 
/// This function retrieves the ASIC layout information of a specified adapter.\n
/// layout information includes number of slots, size and number of connectors and properties of connectors
/// \platform
/// \ALL
/// \param[in]   iAdapterIndex The ADL index handle of the desired adapter.
/// \param[out]  lpValidFlags The integer pointer, specifies the valid bits of the slot & connector information.
/// \param[out]  lpNumberSlots The integer pointer, specifies the number of slots
/// \param[out]  lppBracketSlot The pointer to the structure, storing the bracket slot information.
/// \param[out]  lpNumberConnector The integer pointer, specifies the number of connectors in GPU
/// \param[out]  lppConnector The pointer to the structure, storing the connectors information
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
 ADL_EXTERNC int EXPOSED ADL_Adapter_BoardLayout_Get(int iAdapterIndex, int* lpValidFlags, int *lpNumberSlots, ADLBracketSlotInfo** lppBracketSlot, int* lpNumberConnector, ADLConnectorInfo** lppConnector);


///
///\brief Function to get the supported connection types of given connector
/// 
/// This function retrieves the supported connection types and its properties
/// \platform
/// \ALL
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in]   iAdapterIndex The ADL index handle of the desired adapter.
/// \param[in]   devicePort specifies connector index and relative MST address.
/// \param[out]  lpADLSupportedConnections The pointer to the structure storing the retrieved information.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
 ADL_EXTERNC int EXPOSED ADL2_Adapter_SupportedConnections_Get(ADL_CONTEXT_HANDLE context,int iAdapterIndex, ADLDevicePort devicePort, ADLSupportedConnections* lpADLSupportedConnections);

///
///\brief Function to get the supported connection types of given connector
/// 
/// This function retrieves the supported connection types and its properties
/// \platform
/// \ALL
/// \param[in]   iAdapterIndex The ADL index handle of the desired adapter.
/// \param[in]   devicePort specifies connector index and relative MST address.
/// \param[out]  lpADLSupportedConnections The pointer to the structure storing the retrieved information.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
 ADL_EXTERNC int EXPOSED ADL_Adapter_SupportedConnections_Get(int iAdapterIndex, ADLDevicePort devicePort, ADLSupportedConnections* lpADLSupportedConnections);

///
///\brief Function to get the current emulation state of a given connector
/// 
/// This function retrieves the current emulation state
/// \platform
/// \ALL
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in]   iAdapterIndex The ADL index handle of the desired adapter.
/// \param[in]   devicePort specifies connector index and relative MST address.
/// \param[out]  lpADLConnectionState The pointer to the structure storing the retrieved  information.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
 ADL_EXTERNC int EXPOSED ADL2_Adapter_ConnectionState_Get(ADL_CONTEXT_HANDLE context,int iAdapterIndex, ADLDevicePort devicePort, ADLConnectionState* lpADLConnectionState);

///
///\brief Function to get the current emulation state of a given connector
/// 
/// This function retrieves the current emulation state
/// \platform
/// \ALL
/// \param[in]   iAdapterIndex The ADL index handle of the desired adapter.
/// \param[in]   devicePort specifies connector index and relative MST address.
/// \param[out]  lpADLConnectionState The pointer to the structure storing the retrieved  information.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
 ADL_EXTERNC int EXPOSED ADL_Adapter_ConnectionState_Get(int iAdapterIndex, ADLDevicePort devicePort, ADLConnectionState* lpADLConnectionState);

///
///\brief Function to sets the emulation mode of given connector
/// 
/// This function set the emulation mode to the driver
/// \platform
/// \ALL
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in]   iAdapterIndex The ADL index handle of the desired adapter.
/// \param[in]   devicePort specifies connector index and relative MST address.
/// \param[in]	 iEmulationMode selected Emulated mode. \ref define_emulation_mode
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
 ADL_EXTERNC int EXPOSED ADL2_Adapter_EmulationMode_Set(ADL_CONTEXT_HANDLE context,int iAdapterIndex, ADLDevicePort devicePort, int iEmulationMode);

///
///\brief Function to sets the emulation mode of given connector
/// 
/// This function set the emulation mode to the driver
/// \platform
/// \ALL
/// \param[in]   iAdapterIndex The ADL index handle of the desired adapter.
/// \param[in]   devicePort specifies connector index and relative MST address.
/// \param[in]	 iEmulationMode selected Emulated mode. \ref define_emulation_mode
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
 ADL_EXTERNC int EXPOSED ADL_Adapter_EmulationMode_Set(int iAdapterIndex, ADLDevicePort devicePort, int iEmulationMode);

///
///\brief Function to set the emulation data to on specified connector
/// 
/// This function sets the emulation data 
/// \platform
/// \ALL
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in]   iAdapterIndex The ADL index handle of the desired adapter.
/// \param[in]   devicePort specifies connector index and relative MST address.
/// \param[in]   ConnectionData contains connection data including the EDID data
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
 ADL_EXTERNC int EXPOSED ADL2_Adapter_ConnectionData_Set(ADL_CONTEXT_HANDLE context,int iAdapterIndex,  ADLDevicePort devicePort, ADLConnectionData ConnectionData);

///
///\brief Function to set the emulation data to on specified connector
/// 
/// This function sets the emulation data 
/// \platform
/// \ALL
/// \param[in]   iAdapterIndex The ADL index handle of the desired adapter.
/// \param[in]   devicePort specifies connector index and relative MST address.
/// \param[in]   ConnectionData contains connection data including the EDID data
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
 ADL_EXTERNC int EXPOSED ADL_Adapter_ConnectionData_Set(int iAdapterIndex,  ADLDevicePort devicePort, ADLConnectionData ConnectionData);

///
///\brief Function to gets the emulation data on specified connector
/// 
/// This function to gets the emulation data
/// \platform
/// \ALL
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in]   iAdapterIndex The ADL index handle of the desired adapter.
/// \param[in]   devicePort specifies connector index and relative MST address.
/// \param[in]   iQueryType The Specifies type of query. \ref define_emulation_query
/// \param[out]  lpConnectionData The pointer to the structure storing the retrieved information.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
 ADL_EXTERNC int EXPOSED ADL2_Adapter_ConnectionData_Get(ADL_CONTEXT_HANDLE context,int iAdapterIndex,  ADLDevicePort devicePort, int iQueryType, ADLConnectionData* lpConnectionData);

///
///\brief Function to gets the emulation data on specified connector
/// 
/// This function to gets the emulation data
/// \platform
/// \ALL
/// \param[in]   iAdapterIndex The ADL index handle of the desired adapter.
/// \param[in]   devicePort specifies connector index and relative MST address.
/// \param[in]   iQueryType The Specifies type of query. \ref define_emulation_query
/// \param[out]  lpConnectionData The pointer to the structure storing the retrieved information.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
 ADL_EXTERNC int EXPOSED ADL_Adapter_ConnectionData_Get(int iAdapterIndex,  ADLDevicePort devicePort, int iQueryType, ADLConnectionData* lpConnectionData);

///
///\brief Function to remove emulation on specified connector
/// 
/// This function removes the emulation which are emulated already
/// \platform
/// \ALL
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in]   iAdapterIndex The ADL index handle of the desired adapter.
/// \param[in]   devicePort specifies connector index and relative mst address.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
 ADL_EXTERNC int EXPOSED ADL2_Adapter_ConnectionData_Remove(ADL_CONTEXT_HANDLE context,int iAdapterIndex,  ADLDevicePort devicePort);

///
///\brief Function to remove emulation on specified connector
/// 
/// This function removes the emulation which are emulated already
/// \platform
/// \ALL
/// \param[in]   iAdapterIndex The ADL index handle of the desired adapter.
/// \param[in]   devicePort specifies connector index and relative mst address.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
 ADL_EXTERNC int EXPOSED ADL_Adapter_ConnectionData_Remove(int iAdapterIndex,  ADLDevicePort devicePort);

///
///\brief Function to retrieve EDID management feature support.
/// 
/// This function retrieves EDID Management supprot for specific adapter.
/// \platform
/// \ALL
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in]   iAdapterIndex The ADL index handle of the desired adapter.
/// \param[out]  lpSupported If the specified adapter supports EDID Management then returns \ref ADL_TRUE else \ref ADL_FALSE
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
ADL_EXTERNC int EXPOSED ADL2_Adapter_EDIDManagement_Caps(ADL_CONTEXT_HANDLE context,int iAdapterIndex, int *lpSupported);

///
///\brief Function to retrieve EDID management feature support.
/// 
/// This function retrieves EDID Management supprot for specific adapter.
/// \platform
/// \ALL
/// \param[in]   iAdapterIndex The ADL index handle of the desired adapter.
/// \param[out]  lpSupported If the specified adapter supports EDID Management then returns \ref ADL_TRUE else \ref ADL_FALSE
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
ADL_EXTERNC int EXPOSED ADL_Adapter_EDIDManagement_Caps(int iAdapterIndex, int *lpSupported);

///
/// \brief Function to get the EDID Persistence state of the system.
/// 
/// This function implements the functionality to get the EDID Persistence state of the system.
/// \platform
/// \ALL
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[out]  lpCurResultValue The int pointer to the current state
///              It can be one of \ref define_persistence_state
/// \param[out]  lpDefResultValue The int pointer to the default state
///              It can be one of \ref define_persistence_state
/// \return If the function is successful, \ref ADL_OK is returned. \ref ADL_OK_MODE_CHANGE if success but need mode change,\n
/// If the function is not supported, \ref ADL_ERR_NOT_SUPPORTED is returned. For all other errors, \ref ADL_ERR is returned.
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
ADL_EXTERNC int EXPOSED ADL2_Workstation_GlobalEDIDPersistence_Get(ADL_CONTEXT_HANDLE context,int *lpCurResultValue, int *lpDefResultValue);

///
/// \brief Function to get the EDID Persistence state of the system.
/// 
/// This function implements the functionality to get the EDID Persistence state of the system.
/// \platform
/// \ALL
/// \param[out]  lpCurResultValue The int pointer to the current state
///              It can be one of \ref define_persistence_state
/// \param[out]  lpDefResultValue The int pointer to the default state
///              It can be one of \ref define_persistence_state
/// \return If the function is successful, \ref ADL_OK is returned. \ref ADL_OK_MODE_CHANGE if success but need mode change,\n
/// If the function is not supported, \ref ADL_ERR_NOT_SUPPORTED is returned. For all other errors, \ref ADL_ERR is returned.
ADL_EXTERNC int EXPOSED ADL_Workstation_GlobalEDIDPersistence_Get(int *lpCurResultValue, int *lpDefResultValue);

///
/// \brief Function to set the EDID Persistence  state of the system.
/// 
/// This function implements the functionality to set the EDID Persistence mode for a system.
/// \platform
/// \ALL
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in]  iCurState The current state to set for the specified adapter. \ref define_persistence_state
/// \return If the function is successful, \ref ADL_OK is returned. \ref ADL_OK_MODE_CHANGE if success but need mode change,\n
/// If the function is not supported, \ref ADL_ERR_NOT_SUPPORTED is returned. For all other errors, \ref ADL_ERR is returned.
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
ADL_EXTERNC int EXPOSED ADL2_Workstation_GlobalEDIDPersistence_Set(ADL_CONTEXT_HANDLE context,int iCurState);

///
/// \brief Function to set the EDID Persistence  state of the system.
/// 
/// This function implements the functionality to set the EDID Persistence mode for a system.
/// \platform
/// \ALL
/// \param[in]  iCurState The current state to set for the specified adapter. \ref define_persistence_state 
/// \return If the function is successful, \ref ADL_OK is returned. \ref ADL_OK_MODE_CHANGE if success but need mode change,\n
/// If the function is not supported, \ref ADL_ERR_NOT_SUPPORTED is returned. For all other errors, \ref ADL_ERR is returned.
ADL_EXTERNC int EXPOSED ADL_Workstation_GlobalEDIDPersistence_Set(int iCurState);

/// @}
///\ingroup GAMINGAPI
///\defgroup POWERMANAGEMANTAPI Power Management Related of APIs
/// This group describes the Power Management Related of APIs

/// \addtogroup POWERMANAGEMANTAPI
///
/// @{

/// 
/// \brief \newAPI15 Function to retrieve Compatibility Mode setting capability.
///
/// This function retrieves the Compatibility Mode capability.
/// \platform
/// \WIN
/// \param[in] context			: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in] iAdapterIndex    : The ADL index handle of the desired adapter.
/// \param[out] lpSupported		: Integer indicating capability of the CompatibilityMode Feature Support. 
ADL_EXTERNC int EXPOSED ADL2_ElmCompatibilityMode_Caps(ADL_CONTEXT_HANDLE context, int iAdapterIndex, int *lpSupported, int *lpDefault);

/// 
/// \brief \newAPI15 Function to retrieve Compatibility Mode status whether it is On or Off.
///
/// This function retrieves Compatibility Mode status.
/// \platform
/// \WIN
/// \param[in] context			: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in] iAdapterIndex    : The ADL index handle of the desired adapter.
/// \param[out] lpCompatibilityModeValue	    : Pointer to the current CompatibilityMode status obtained 
ADL_EXTERNC int EXPOSED ADL2_ElmCompatibilityMode_Status_Get(ADL_CONTEXT_HANDLE context, int iAdapterIndex, int *lpValue);

/// 
/// \brief \newAPI15 Function to update Compatibility Mode status to either On or Off.
///
/// This function update Compatibility Mode status.
/// \platform
/// \WIN
/// \param[in] context			: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in] iAdapterIndex    : The ADL index handle of the desired adapter.
/// \param[in] iFPWValue		: CompatibilityMode status to update the current compatibility Status
ADL_EXTERNC int EXPOSED ADL2_ElmCompatibilityMode_Status_Set(ADL_CONTEXT_HANDLE context, int iAdapterIndex, int iValue);


#if defined (_WIN32) || defined(_WIN64)
/// 
/// \brief Function to retrieve FPS Global Setting Capability.
///
/// This function retrieves the Global Setting Capability.
/// \platform
/// \WIN
/// \param[in] context			: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in] iAdapterIndex    : The ADL index handle of the desired adapter.
/// \param[out] lpSupported		: Integer indicating capability of the FPS Feature Support. 
/// \param[out] lpVersion	    : Integer indicating Feature Version.
ADL_EXTERNC int EXPOSED ADL2_FPS_Caps (ADL_CONTEXT_HANDLE context,int iAdapterIndex, int *lpSupported, int *lpVersion);

/// 
/// \brief Function to retrieve FPS Global Settings.
///
/// This function retrieves FPS Global Settings.
/// \platform
/// \WIN
/// \param[in] context			: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in] iAdapterIndex    : The ADL index handle of the desired adapter.
/// \param[out] lpFPSSettings	: Pointer to ADLFPSSettingsOutput struct which will load the Global FPS Settings 
ADL_EXTERNC int EXPOSED ADL2_FPS_Settings_Get (ADL_CONTEXT_HANDLE context,int iAdapterIndex, ADLFPSSettingsOutput *lpFPSSettings);

/// 
/// \brief Function to update FPS Global Settings.
///
/// This function update FPS Global Settings.
/// \platform
/// \WIN
/// \param[in] context			: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in] iAdapterIndex    : The ADL index handle of the desired adapter.
/// \param[in] lpFPSSettings	: ADLFPSSettingsInput struct which will update the Global FPS Settings 
ADL_EXTERNC int EXPOSED ADL2_FPS_Settings_Set (ADL_CONTEXT_HANDLE context,int iAdapterIndex, ADLFPSSettingsInput lpFPSSettings);

/// 
/// \brief Function to reset FPS Global Settings.
///
/// This function reset FPS Global Settings.
/// \platform
/// \WIN
/// \param[in] context			: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in] iAdapterIndex    : The ADL index handle of the desired adapter.
ADL_EXTERNC int EXPOSED ADL2_FPS_Settings_Reset (ADL_CONTEXT_HANDLE context,int iAdapterIndex);


///\brief Function to set RIS settings
/// This function sets the user input values to RIS feature
/// \platform
/// \WIN
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in]  iAdapterIndex The index of the desired adapter.
/// \param[in]  settings \ref ADL_RIS_SETTINGS : structure with the input values
/// \param[in]  changeReason \ref ADL_RIS_NOTFICATION_REASON : structure with the changed feilds in settings parameter
/// \return If the function succeeds, the return value is \ref ADL_OK (zero). Otherwise the return value is an ADL error code (non-zero). \ref define_adl_results 
///
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
ADL_EXTERNC int EXPOSED ADL2_RIS_Settings_Set(ADL_CONTEXT_HANDLE context, int iAdapterIndex, ADL_RIS_SETTINGS settings, ADL_RIS_NOTFICATION_REASON changeReason);

///\brief Function to get the RIS settings
/// This function retrieves the RIS settings for a specified display adapter.
/// \platform
/// \WIN
/// \param[in]  context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in]  iAdapterIndex The index of the desired adapter.
/// \param[out] settings The pointer to the pointer to the RIS data structure
/// \return If the function succeeds, the return value is \ref ADL_OK (zero). Otherwise the return value is an ADL error code (non-zero). \ref define_adl_results 
///
ADL_EXTERNC int EXPOSED ADL2_RIS_Settings_Get(ADL_CONTEXT_HANDLE context, int iAdapterIndex, ADL_RIS_SETTINGS* settings);

///\brief Function to set CHILL settings
/// This function sets the user input values to CHILL feature
/// \platform
/// \WIN
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in]  iAdapterIndex The index of the desired adapter.
/// \param[in]  settings \ref ADL_CHILL_SETTINGS : structure with the input values
/// \param[in]  changeReason \ref ADL_CHILL_NOTFICATION_REASON : structure with the changed feilds in settings parameter
/// \param[out]  errorReason \ref ADL_ERROR_REASON : structure with the error feilds in settings parameter. client should refer to this feild when set call is filed.
/// \return If the function succeeds, the return value is \ref ADL_OK (zero). Otherwise the return value is an ADL error code (non-zero). \ref define_adl_results 
///
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
ADL_EXTERNC int EXPOSED ADL2_CHILL_SettingsX2_Set(ADL_CONTEXT_HANDLE context, int iAdapterIndex, ADL_CHILL_SETTINGS settings, ADL_CHILL_NOTFICATION_REASON changeReason, ADL_ERROR_REASON* errorReason);

///\brief Function to get the CHILL settings
/// This function retrieves the CHILL settings for a specified display adapter.
/// \platform
/// \WIN
/// \param[in]  context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in]  iAdapterIndex The index of the desired adapter.
/// \param[out] settings The pointer to the pointer to the CHILL data structure
/// \return If the function succeeds, the return value is \ref ADL_OK (zero). Otherwise the return value is an ADL error code (non-zero). \ref define_adl_results 
///
ADL_EXTERNC int EXPOSED ADL2_CHILL_SettingsX2_Get(ADL_CONTEXT_HANDLE context, int iAdapterIndex, ADL_CHILL_SETTINGS* settings);


///\brief Function to set DELAG settings
/// This function sets the user input values to DELAG feature
/// \platform
/// \WIN
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in]  iAdapterIndex The index of the desired adapter.
/// \param[in]  settings \ref ADL_DELAG_SETTINGS : structure with the input values
/// \param[in]  changeReason \ref ADL_DELAG_NOTFICATION_REASON : structure with the changed feilds in settings parameter
/// \param[out]  errorReason \ref ADL_ERROR_REASON : structure with the error feilds in settings parameter. client should refer to this feild when set call is filed.
/// \return If the function succeeds, the return value is \ref ADL_OK (zero). Otherwise the return value is an ADL error code (non-zero). \ref define_adl_results 
///
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
ADL_EXTERNC int EXPOSED ADL2_DELAG_Settings_Set(ADL_CONTEXT_HANDLE context, int iAdapterIndex, ADL_DELAG_SETTINGS settings, ADL_DELAG_NOTFICATION_REASON changeReason, ADL_ERROR_REASON* errorReason);

///\brief Function to get the DELAG settings
/// This function retrieves the DELAG settings for a specified display adapter.
/// \platform
/// \WIN
/// \param[in]  context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in]  iAdapterIndex The index of the desired adapter.
/// \param[out] settings The pointer to the pointer to the DEALG data structure
/// \return If the function succeeds, the return value is \ref ADL_OK (zero). Otherwise the return value is an ADL error code (non-zero). \ref define_adl_results 
///
ADL_EXTERNC int EXPOSED ADL2_DELAG_Settings_Get(ADL_CONTEXT_HANDLE context, int iAdapterIndex, ADL_DELAG_SETTINGS* settings);

///\brief Function to set BOOST settings
/// This function sets the user input values to BOOST feature
/// \platform
/// \WIN
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in]  iAdapterIndex The index of the desired adapter.
/// \param[in]  settings \ref ADL_BOOST_SETTINGS : structure with the input values
/// \param[in]  changeReason \ref ADL_BOOST_NOTFICATION_REASON : structure with the changed feilds in settings parameter
/// \param[out]  errorReason \ref ADL_ERROR_REASON : structure with the error feilds in settings parameter. client should refer to this feild when set call is filed.
/// \return If the function succeeds, the return value is \ref ADL_OK (zero). Otherwise the return value is an ADL error code (non-zero). \ref define_adl_results 
///
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
ADL_EXTERNC int EXPOSED ADL2_BOOST_Settings_Set(ADL_CONTEXT_HANDLE context, int iAdapterIndex, ADL_BOOST_SETTINGS settings, ADL_BOOST_NOTFICATION_REASON changeReason, ADL_ERROR_REASON* errorReason);

///\brief Function to get the BOOST settings
/// This function retrieves the BOOST settings for a specified display adapter.
/// \platform
/// \WIN
/// \param[in]  context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in]  iAdapterIndex The index of the desired adapter.
/// \param[out] settings The pointer to the pointer to the BOOST data structure
/// \return If the function succeeds, the return value is \ref ADL_OK (zero). Otherwise the return value is an ADL error code (non-zero). \ref define_adl_results 
///
ADL_EXTERNC int EXPOSED ADL2_BOOST_Settings_Get(ADL_CONTEXT_HANDLE context, int iAdapterIndex, ADL_BOOST_SETTINGS* settings);

///\brief Function to set Pro VSR settings
/// This function sets the user input values to VSR feature
/// \platform
/// \WIN
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in]  iAdapterIndex The index of the desired adapter.
/// \param[in]  settings \ref ADL_PROVSR_SETTINGS : structure with the input values
/// \param[in]  changeReason \ref ADL_PROVSR_SETTINGS_NOTFICATION_REASON : structure with the changed feilds in settings parameter
/// \param[out]  errorReason \ref ADL_ERROR_REASON : structure with the error feilds in settings parameter. client should refer to this feild when set call is filed.
/// \return If the function succeeds, the return value is \ref ADL_OK (zero). Otherwise the return value is an ADL error code (non-zero). \ref define_adl_results 
///
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
///
ADL_EXTERNC int EXPOSED ADL2_PROVSR_Settings_Set(ADL_CONTEXT_HANDLE context, int iAdapterIndex, ADL_PROVSR_SETTINGS settings, ADL_PROVSR_NOTFICATION_REASON changeReason, ADL_ERROR_REASON* errorReason);


///\brief Function to get the Pro VSR settings
/// This function retrieves the Pro VSR for a specified display adapter.
/// \platform
/// \WIN
/// \param[in]  context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in]  iAdapterIndex The index of the desired adapter.
/// \param[out] settings The pointer to the pointer to the VSR data structure
/// \return If the function succeeds, the return value is \ref ADL_OK (zero). Otherwise the return value is an ADL error code (non-zero). \ref define_adl_results 
///
ADL_EXTERNC int EXPOSED ADL2_PROVSR_Settings_Get(ADL_CONTEXT_HANDLE context, int iAdapterIndex, ADL_PROVSR_SETTINGS* settings);





///\brief \newAPI15 Function to notify DX via KMD that Chill settings have changed.
/// This function communicates DX via KMD that user changed chill settings.
/// \platform
/// \WIN
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in]  iAdapterIndex The index of the desired adapter.
/// \param[in]  iChanged \ref ADL_TRUE   \ref ADL_FALSE 
/// \return If the function succeeds, the return value is \ref ADL_OK (zero). Otherwise the return value is an ADL error code (non-zero). \ref define_adl_results 
///
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
ADL_EXTERNC int EXPOSED ADL2_Chill_Settings_Notify(ADL_CONTEXT_HANDLE context, int iAdapterIndex, int iChanged);

///\brief \newAPI15 Function to enable or disable Global Chill
/// This function enables or disables Global Chill for a specified display adapter.
/// \platform
/// \WIN
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in]  iAdapterIndex The index of the desired adapter.
/// \param[in]  iEnabled \ref ADL_TRUE : enables Global Chill, \ref ADL_FALSE : disables Global Chill.
/// \return If the function succeeds, the return value is \ref ADL_OK (zero). Otherwise the return value is an ADL error code (non-zero). \ref define_adl_results 
///
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
ADL_EXTERNC int EXPOSED ADL2_Chill_Settings_Set(ADL_CONTEXT_HANDLE context, int iAdapterIndex, int iEnabled);

///\brief \newAPI15 Function to get the Global Chill capabilities
/// This function retrieves the Global Chill capabilities for a specified display adapter.
/// \platform
/// \WIN
/// \param[in]  context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in]  iAdapterIndex The index of the desired adapter.
/// \param[out] lpEnabled The pointer to an int variable which indicates if Global Chill is enabled ( \ref ADL_TRUE : enabled, \ref ADL_FALSE : disabled)
/// \return If the function succeeds, the return value is \ref ADL_OK (zero). Otherwise the return value is an ADL error code (non-zero). \ref define_adl_results 
///
ADL_EXTERNC int EXPOSED ADL2_Chill_Settings_Get(ADL_CONTEXT_HANDLE context, int iAdapterIndex, int* lpEnabled);

///\brief \newAPI15 Function to get the Global Chill capabilities
/// This function retrieves the Global Chill capabilities for a specified display adapter.
/// \platform
/// \WIN
/// \param[in]  context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in]  iAdapterIndex The index of the desired adapter.
/// \param[out] iSupported The pointer to an int variable which indicates if Global Chill is supported ( \ref ADL_TRUE : enabled, \ref ADL_FALSE : disabled)
/// \param[out] iCheckCaps The pointer to an int variable which indicates if iSupported flag is to be considered from Clients ( \ref ADL_TRUE : iSupported to be considered, \ref ADL_FALSE : ignore iSupported)
/// \return If the function succeeds, the return value is \ref ADL_OK (zero). Otherwise the return value is an ADL error code (non-zero). \ref define_adl_results 
///
ADL_EXTERNC int EXPOSED ADL2_Chill_Caps_Get(ADL_CONTEXT_HANDLE context, int iAdapterIndex, int* iSupported, int* iCheckCaps);

/// 
/// \brief \newAPI15 Function to retrieve Performance Tuning capability.
///
/// This function retrieves the Performance Tuning capability.
/// \platform
/// \WIN
/// \param[in] context			: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in] iAdapterIndex    : The ADL index handle of the desired adapter.
/// \param[out] lpSupported		: Integer indicating capability of the Performance Tuning Feature Support. 
/// \param[out] lpDefault       : Integer indicating default Performance Tuning value
ADL_EXTERNC int EXPOSED ADL2_PerformanceTuning_Caps(ADL_CONTEXT_HANDLE context, int iAdapterIndex, int *lpSupported, int *lpDefault);

/// 
/// \brief \newAPI15 Function to retrieve Performance ui tunning status whether it is On or Off.
///
/// This function retrieves Performance ui tunning status.
/// \platform
/// \WIN
/// \param[in] context			: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in] iAdapterIndex    : The ADL index handle of the desired adapter.
/// \param[out] lpPTuningValue  : Pointer to the current performance tuning status obtained 
ADL_EXTERNC int EXPOSED ADL2_PerfTuning_Status_Get(ADL_CONTEXT_HANDLE context, int iAdapterIndex, int *lpPTuningValue);

/// 
/// \brief \newAPI15 Function to update Performance ui tunning status to either On or Off.
///
/// This function update FPS Performance ui tunning status.
/// \platform
/// \WIN
/// \param[in] context			: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in] iAdapterIndex    : The ADL index handle of the desired adapter.
/// \param[in] lpPTuningValue   : performance tuning status to update the current Performance Per Watt Status
ADL_EXTERNC int EXPOSED ADL2_PerfTuning_Status_Set(ADL_CONTEXT_HANDLE context, int iAdapterIndex, int lpPTuningValue);

/// 
/// \brief \newAPI15 Function to retrieve Performance Per Watt setting capability.
///
/// This function retrieves the Performance Per Watt capability.
/// \platform
/// \WIN
/// \param[in] context			: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in] iAdapterIndex    : The ADL index handle of the desired adapter.
/// \param[out] lpSupported		: Integer indicating capability of the PPW Feature Support. 
ADL_EXTERNC int EXPOSED ADL2_PPW_Caps(ADL_CONTEXT_HANDLE context, int iAdapterIndex, int *lpSupported, int *lpDefault);

/// 
/// \brief \newAPI15 Function to retrieve Performance Per Watt status whether it is On or Off.
///
/// This function retrieves Performance Per Watt status.
/// \platform
/// \WIN
/// \param[in] context			: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in] iAdapterIndex    : The ADL index handle of the desired adapter.
/// \param[out] lpPPWValue	    : Pointer to the current PPW status obtained 
ADL_EXTERNC int EXPOSED ADL2_PPW_Status_Get(ADL_CONTEXT_HANDLE context, int iAdapterIndex, int *lpFPWValue);

/// 
/// \brief \newAPI15 Function to update Performance Per Watt status to either On or Off.
///
/// This function update FPS Performance Per Watt status.
/// \platform
/// \WIN
/// \param[in] context			: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in] iAdapterIndex    : The ADL index handle of the desired adapter.
/// \param[in] iFPWValue		: PPW status to update the current Performance Per Watt Status
ADL_EXTERNC int EXPOSED ADL2_PPW_Status_Set(ADL_CONTEXT_HANDLE context, int iAdapterIndex, int iFPWValue);

#endif /*(_WIN32) || (_WIN64)*/
/// @}

///\ingroup GAMINGAPI
///\defgroup PERFORMANCEAPI Performance Related of APIs
/// This group describes the Performance Related of APIs
///\addtogroup PERFORMANCEAPI
/// @{
///
/// \brief \newAPI15 Function to Checks if given GPU (identified by adapter id) supports Frame Monitoring Metrics or not.
/// 
/// Checks if given GPU (identified by adapter id) supports Frame Monitoring Metrics or not.
/// \platform
/// \ALL
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in] iAdapterIndex: The ADL index handle of the desired adapter.
/// \param[out] iIsFrameMonitorSupported The pointer to the structure storing the retrieved adapter capability information.
/// \return If the function succeeds, the return value is \ref ADL_OK, or an ADL error code otherwise. \ref define_adl_results
ADL_EXTERNC int EXPOSED ADL2_Adapter_FrameMetrics_Caps(ADL_CONTEXT_HANDLE context, int iAdapterIndex, int *iIsFrameMonitorSupported);

///
/// \brief \newAPI15 Function to start frame metrics monitoring on GPU (identified by adapter id).
/// 
/// Start frame metrics monitoring on GPU (identified by adapter id).
/// Will detect if in crossfire and start all slaves as well.
/// \platform
/// \ALL
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in] iAdapterIndex: The ADL index handle of the desired adapter.
/// \param[in] VidPnSourceId: The Source ID of the Display FPS metrics will be started from.
/// \return If the function succeeds, the return value is \ref ADL_OK, or an ADL error code otherwise. \ref define_adl_results
ADL_EXTERNC int EXPOSED ADL2_Adapter_FrameMetrics_Start(ADL_CONTEXT_HANDLE context, int iAdapterIndex, int VidPnSourceId);

///
/// \brief \newAPI15 Function to stop frame metrics monitoring on GPU (identified by adapter id).
/// 
/// Stop frame metrics monitoring on GPU (identified by adapter id).
/// Will detect if in crossfire and stop all slaves as well.
/// \platform
/// \ALL
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in] iAdapterIndex: The ADL index handle of the desired adapter.
/// \param[in] VidPnSourceId: The Source ID of the Display FPS metrics will be stopped from.
/// \return If the function succeeds, the return value is \ref ADL_OK, or an ADL error code otherwise. \ref define_adl_results
ADL_EXTERNC int EXPOSED ADL2_Adapter_FrameMetrics_Stop(ADL_CONTEXT_HANDLE context, int iAdapterIndex, int VidPnSourceId);

///
/// \brief \newAPI15 Function to retrieve frame metrics information on GPU (identified by adapter id).
/// 
/// Get frame metrics monitoring Data on GPU (identified by adapter id).
/// Will detect if in crossfire and Get data from all slaves as well.
/// \platform
/// \ALL
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in] iAdapterIndex: The ADL index handle of the desired adapter.
/// \param[in] VidPnSourceId: The Source ID of the Display FPS metrics will be gathered from.
/// \param[out] iFramesPerSecond: The FPS presented by the GPU. This is the average of all FPS presented since the last time the function was called. 
/// \return If the function succeeds, the return value is \ref ADL_OK, or an ADL error code otherwise. \ref define_adl_results
ADL_EXTERNC int EXPOSED ADL2_Adapter_FrameMetrics_Get(ADL_CONTEXT_HANDLE context, int iAdapterIndex, int VidPnSourceId, float *iFramesPerSecond);

///
/// \brief \newAPI15 Function to Enable frame metrics time stamp recording on any GPU.
/// 
/// Will try to allocate memory required for Frame Metrics Duration recording inside supplied Handle.
/// This handle is required to start, Get and stop Frame Metrics Duration recording and must be supplied in all future calls.
/// \platform
/// \ALL
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in] frameDurationHandle: Handle containing information used inside Get calls to know how many Time stamp elements to read.
///                                 Will be allocated by the enable call within ADL and then released after Disable call.
///                                 Value must be set to null before being passed in.
/// \return If the function succeeds, the return value is \ref ADL_OK, or an ADL error code otherwise. \ref define_adl_results
ADL_EXTERNC int EXPOSED ADL2_Adapter_FrameMetrics_FrameDuration_Enable(ADL_CONTEXT_HANDLE context, int iAdapterIndex, ADL_FRAME_DURATION_HANDLE* frameDurationHandle);

///
/// \brief \newAPI15 Function to Disable frame metrics time stamp recording on any GPU.
/// 
/// Will try to deallocate memory that was previously allocated for Frame Metrics Duration recording inside supplied Handle.
/// This handle is required to start, Get and stop Frame Metrics Duration recording and must be supplied in all future calls.
/// \platform
/// \ALL
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in] frameDurationHandle: Handle containing information used inside Get calls to know how many Time stamp elements to read.
///                                 Will be allocated by the enable call within ADL and then released after Disable call.
/// \return If the function succeeds, the return value is \ref ADL_OK, or an ADL error code otherwise. \ref define_adl_results
ADL_EXTERNC int EXPOSED ADL2_Adapter_FrameMetrics_FrameDuration_Disable(ADL_CONTEXT_HANDLE context, int iAdapterIndex, ADL_FRAME_DURATION_HANDLE* frameDurationHandle);

///
/// \brief \newAPI15 Function to start frame metrics time stamp recording on GPU (identified by adapter id).
/// 
/// Start frame metrics time stamp/frame duration recording on GPU (identified by adapter id).
/// Will try to enable TimeStamp/FrameDuration recording (ADL2_Adapter_FrameMetrics_Start will be called inside and must succeed).
/// Will detect if in crossfire and start all slaves as well.
/// \platform
/// \ALL
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in] iAdapterIndex: The ADL index handle of the desired adapter.
/// \param[in] VidPnSourceId: The Source ID of the Display FPS metrics will be started from.
/// \return If the function succeeds, the return value is \ref ADL_OK, or an ADL error code otherwise. \ref define_adl_results
ADL_EXTERNC int EXPOSED ADL2_Adapter_FrameMetrics_FrameDuration_Start(ADL_CONTEXT_HANDLE context, int iAdapterIndex, int VidPnSourceId);

///
/// \brief \newAPI15 Function to stop frame metrics time stamp recording on GPU (identified by adapter id).
/// 
/// Stop frame metrics time stamp recording on GPU (identified by adapter id).
/// Will try to stop time stamp/Frame duration recording. (ADL2_Adapter_FrameMetrics_Stop will be called inside upon successful stop)
/// Will detect if in crossfire and stop all slaves as well.
/// \platform
/// \ALL
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in] iAdapterIndex: The ADL index handle of the desired adapter.
/// \param[in] VidPnSourceId: The Source ID of the Display FPS metrics will be stopped from.
/// \return If the function succeeds, the return value is \ref ADL_OK, or an ADL error code otherwise. \ref define_adl_results
ADL_EXTERNC int EXPOSED ADL2_Adapter_FrameMetrics_FrameDuration_Stop(ADL_CONTEXT_HANDLE context, int iAdapterIndex, int VidPnSourceId);

///
/// \brief \newAPI15 Function to retrieve frame metrics frame duration information on GPU (identified by adapter id).
/// 
/// Get frame metrics frame duration Data on GPU (identified by adapter id).
/// ADL2_Adapter_FrameMetrics_FrameDuration_Enable (at least once) & then ADL2_Adapter_FrameMetrics_FrameDuration_Start must be called and succeed before Get will function.
/// This function does not take adapterindex/vidPnSourceId so it will return the information on the adapter previously Started on.
/// Will detect if in crossfire and Get data from all slaves as well.
/// \platform
/// \ALL
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in] frameDurationHandle: Handle containing information used inside Get calls to know how many Time stamp elements to read.
///                                 Will be allocated by the enable call within ADL and then released after Disable call.
/// \param[out] pFrameDurationsArr: Array that will be filled with the new frame durations since the last call. Durations in Microseconds
/// \param[in]  frameDurationsArrSize: size of pFrameTimeStampsArr array to avoid overflow.
/// \param[out] elementsCopied: Number of elements copied from shared memory address to be passed into pFrameDurationsArr 
/// \return If the function succeeds, the return value is \ref ADL_OK, or an ADL error code otherwise. \ref define_adl_results
ADL_EXTERNC int EXPOSED ADL2_Adapter_FrameMetrics_FrameDuration_Get(ADL_CONTEXT_HANDLE context, ADL_FRAME_DURATION_HANDLE frameDurationHandle, unsigned long long * pFrameDurationsArr, unsigned int frameDurationsArrSize, unsigned int *elementsCopied);
/// @}

// Deprecated APIs

///
/// \brief Function to retrieve clock information for an adapter.
/// 
/// This function retrieves the clock information for a specified graphics adapter.
/// \ALL
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[out] lpClockInfo The pointer to the structure storing the retrieved core and memory clock information.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results \n
/// \deprecated This API has been deprecated because it does not provide accurate clocks when the ASIC is over-clocked. Use the OD5 set of APIs, when OverDrive5 is supported.
/// 
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
ADL_EXTERNC int EXPOSED ADL2_Adapter_ClockInfo_Get(ADL_CONTEXT_HANDLE context,int iAdapterIndex, ADLClockInfo* lpClockInfo);

///
/// \brief Function to retrieve clock information for an adapter.
/// 
/// This function retrieves the clock information for a specified graphics adapter.
/// \ALL
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[out] lpClockInfo The pointer to the structure storing the retrieved core and memory clock information.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results \n
/// \deprecated This API has been deprecated because it does not provide accurate clocks when the ASIC is over-clocked. Use the OD5 set of APIs, when OverDrive5 is supported.
ADL_EXTERNC int EXPOSED ADL_Adapter_ClockInfo_Get(int iAdapterIndex, ADLClockInfo* lpClockInfo);

///
///\brief Function to get the unique identifier of an adapter. Will be removed! Use ADL_Adapter_ID_Get()
/// 
/// This function retrieves the unique identifier of a specified adapter.\n
/// The adapter ID is a unique value and will be used to determine what other controllers share the same adapter.\n
/// The desktop will use this to find which HDCs are associated with an adapter.
/// \platform
/// \ALL
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in]   iAdapterIndex The ADL index handle of the desired adapter.
/// \param[out]  lpAdapterID The pointer to the adapter identifier. Zero means: The adapter is not AMD.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
/// \deprecated This API will be removed. Use the duplicate API ADL_Adapter_ID_Get() 
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
 ADL_EXTERNC int EXPOSED ADL2_Display_AdapterID_Get(ADL_CONTEXT_HANDLE context,int iAdapterIndex, int* lpAdapterID);

///
///\brief Function to get the unique identifier of an adapter. Will be removed! Use ADL_Adapter_ID_Get()
/// 
/// This function retrieves the unique identifier of a specified adapter.\n
/// The adapter ID is a unique value and will be used to determine what other controllers share the same adapter.\n
/// The desktop will use this to find which HDCs are associated with an adapter.
/// \platform
/// \ALL
/// \param[in]   iAdapterIndex The ADL index handle of the desired adapter.
/// \param[out]  lpAdapterID The pointer to the adapter identifier. Zero means: The adapter is not AMD.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
/// \deprecated This API will be removed. Use the duplicate API ADL_Adapter_ID_Get() 
 ADL_EXTERNC int EXPOSED ADL_Display_AdapterID_Get(int iAdapterIndex, int* lpAdapterID);

/// \brief Function to retrieve Gfx EDC Error Log.
/// 
 /// This function implements a call to retrieve Gfx EDC Error Logs.
 /// \platform
 /// \VISTAWIN7
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[out] pErrorrecordCount The pointer to the number of error records
/// \param[out] errorRecords The pointer to error records
/// \return If the function succeeds, the return value is \ref ADL_OK, or an ADL error code otherwise. \ref define_adl_results
ADL_EXTERNC int EXPOSED ADL2_Adapter_EDC_ErrorRecords_Get (ADL_CONTEXT_HANDLE context,int iAdapterIndex, int* pErrorrecordCount, ADLErrorRecord* errorRecords); 

/// \brief Function to inject Gfx EDC Error .
/// 
 /// This function implements a call to inject Gfx EDC Error.
 /// \platform
 /// \VISTAWIN7
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[in] errorInjection The pointer to error injection
/// \return If the function succeeds, the return value is \ref ADL_OK, or an ADL error code otherwise. \ref define_adl_results
ADL_EXTERNC int EXPOSED ADL2_Adapter_EDC_ErrorInjection_Set (ADL_CONTEXT_HANDLE context,int iAdapterIndex, ADLErrorInjection* errorInjection);

#endif /* ADAPTER_H_ */

