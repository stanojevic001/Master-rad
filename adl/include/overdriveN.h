///
///  Copyright (c) 2018 - 2021 Advanced Micro Devices, Inc.
 
///  THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
///  EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
///  WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.

/// \file overdriveN.h
/// \brief Contains all OverdriveN-related functions exposed by ADL for \ALL platforms.
///
/// This file contains all OverdriveN-related functions exposed by ADL for \ALL platforms.
/// All functions found in this file can be used as a reference to ensure
/// the specified function pointers can be used by the appropriate runtime
/// dynamic library loaders.

#ifndef OVERDRIVEN_H_
#define OVERDRIVEN_H_

#include "..\adl_structures.h"

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
///\ingroup WATTMANAPI
///\defgroup OVERDRIVENAPI Wattman (OD N) related APIs
/// This group describes the Wattman APIs.

/// \addtogroup OVERDRIVENAPI
/// @{
///
/// \brief Function to retrieve the OverdriveN capabilities.
/// 
/// This function retrieves the OverdriveN capabilities for a specified adapter.
/// \platform
/// \WIN
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[out] lpODCapabilities The pointer to the \ref ADLODNCapabilities structure storing the retrieved Overdrive parameters. 
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results 
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
/// \deprecated This API has been deprecated.
ADL_EXTERNC int EXPOSED ADL2_OverdriveN_Capabilities_Get(ADL_CONTEXT_HANDLE context, int iAdapterIndex, ADLODNCapabilities *lpODCapabilities);

///
/// \brief Function to retrieve the OverdriveN capabilities.
/// 
/// This function retrieves the OverdriveN capabilities for a specified adapter.
/// \platform
/// \WIN
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[out] lpODCapabilities The pointer to the \ref ADLODNCapabilitiesX2 structure storing the retrieved Overdrive parameters. 
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results 
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
ADL_EXTERNC int EXPOSED ADL2_OverdriveN_CapabilitiesX2_Get(ADL_CONTEXT_HANDLE context, int iAdapterIndex, ADLODNCapabilitiesX2 *lpODCapabilities);

///
/// \brief Function to retrieve the current GPU clocks settings
/// 
/// This function retrieves the current GPU clocks for a specified adapter.
/// \platform
/// \WIN
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[out] lpODPerformanceLevels The pointer to the \ref ADLODNPerformanceLevels structure storing the retrieved data. 
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results 
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
/// \deprecated This API has been deprecated.
ADL_EXTERNC int EXPOSED ADL2_OverdriveN_SystemClocks_Get(ADL_CONTEXT_HANDLE context, int iAdapterIndex, ADLODNPerformanceLevels *lpODPerformanceLevels);

///
/// \brief Function to sets the current GPU clocks settings
/// 
/// This function applies the current GPU clocks for a specified adapter.
/// \platform
/// \WIN
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in] iAdapterIndex The ADL index handle of the desired adapter.
/// \param[in] lpODPerformanceLevels The pointer to the \ref ADLODNPerformanceLevels structure to set the data to driver. 
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results 
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
/// \deprecated This API has been deprecated.
ADL_EXTERNC int EXPOSED ADL2_OverdriveN_SystemClocks_Set(ADL_CONTEXT_HANDLE context, int iAdapterIndex, ADLODNPerformanceLevels *lpODPerformanceLevels);


///
/// \brief Function to retrieve the current GPU clocks settings
/// 
/// This function retrieves the current GPU clocks for a specified adapter.
/// \platform
/// \WIN
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[out] lpODPerformanceLevels The pointer to the \ref ADLODNPerformanceLevels structure storing the retrieved data. 
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results 
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
ADL_EXTERNC int EXPOSED ADL2_OverdriveN_SystemClocksX2_Get(ADL_CONTEXT_HANDLE context, int iAdapterIndex, ADLODNPerformanceLevelsX2 *lpODPerformanceLevels);

///
/// \brief Function to sets the current GPU clocks settings
/// 
/// This function applies the current GPU clocks for a specified adapter.
/// \platform
/// \WIN
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in] iAdapterIndex The ADL index handle of the desired adapter.
/// \param[in] lpODPerformanceLevels The pointer to the \ref ADLODNPerformanceLevels structure to set the data to driver. 
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results 
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
ADL_EXTERNC int EXPOSED ADL2_OverdriveN_SystemClocksX2_Set(ADL_CONTEXT_HANDLE context, int iAdapterIndex, ADLODNPerformanceLevelsX2 *lpODPerformanceLevels);

///
/// \brief Function to retrieve the current memory clocks settings
/// 
/// This function retrieves the current memory clocks for a specified adapter.
/// \platform
/// \WIN
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[out] lpODPerformanceLevels The pointer to the \ref ADLODNPerformanceLevels structure storing the retrieved Overdrive parameters. 
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results 
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
ADL_EXTERNC int EXPOSED ADL2_OverdriveN_MemoryClocksX2_Get(ADL_CONTEXT_HANDLE context, int iAdapterIndex, ADLODNPerformanceLevelsX2 *lpODPerformanceLevels);

///
/// \brief Function to sets the current memory clocks settings
/// 
/// This function applies the current memory clocks for a specified adapter.
/// \platform
/// \WIN
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in] iAdapterIndex The ADL index handle of the desired adapter.
/// \param[in] lpODPerformanceLevels The pointer to the \ref ADLODNPerformanceLevels structure to set the data to driver. 
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results 
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
ADL_EXTERNC int EXPOSED ADL2_OverdriveN_MemoryClocksX2_Set(ADL_CONTEXT_HANDLE context, int iAdapterIndex, ADLODNPerformanceLevelsX2 *lpODPerformanceLevels);

///
/// \brief Function to retrieve the current memory clocks settings
/// 
/// This function retrieves the current memory clocks for a specified adapter.
/// \platform
/// \WIN
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[out] lpODPerformanceLevels The pointer to the \ref ADLODNPerformanceLevels structure storing the retrieved Overdrive parameters. 
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results 
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
/// \deprecated This API has been deprecated.
ADL_EXTERNC int EXPOSED ADL2_OverdriveN_MemoryClocks_Get(ADL_CONTEXT_HANDLE context, int iAdapterIndex, ADLODNPerformanceLevels *lpODPerformanceLevels);

///
/// \brief Function to sets the current memory clocks settings
/// 
/// This function applies the current memory clocks for a specified adapter.
/// \platform
/// \WIN
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in] iAdapterIndex The ADL index handle of the desired adapter.
/// \param[in] lpODPerformanceLevels The pointer to the \ref ADLODNPerformanceLevels structure to set the data to driver. 
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results 
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
/// \deprecated This API has been deprecated.
ADL_EXTERNC int EXPOSED ADL2_OverdriveN_MemoryClocks_Set(ADL_CONTEXT_HANDLE context, int iAdapterIndex, ADLODNPerformanceLevels *lpODPerformanceLevels);

///
/// \brief Function to retrieve the current Fan control settings
/// 
/// This function retrieves the current fan for a specified adapter.
/// \platform
/// \WIN
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[out] lpOdFanSpeed The pointer to the \ref ADLODNFanControl structure storing the retrieved Overdrive parameters. 
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results 
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
ADL_EXTERNC int EXPOSED ADL2_OverdriveN_FanControl_Get(ADL_CONTEXT_HANDLE context, int iAdapterIndex, ADLODNFanControl *lpODFanSpeed);

///
/// \brief Function to set the current Fan controls settings
/// 
/// This function applies the current Fan control for a specified adapter.
/// \platform
/// \WIN
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[in] lpOdFanSpeed The pointer to the \ref ADLODNFanControl structure storing the retrieved Overdrive parameters. 
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results 
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
ADL_EXTERNC int EXPOSED ADL2_OverdriveN_FanControl_Set(ADL_CONTEXT_HANDLE context, int iAdapterIndex, ADLODNFanControl *lpODFanControl);

///
/// \brief Function to retrieve the current power limit settings
/// 
/// This function retrieves the current power limit for a specified adapter.
/// \platform
/// \WIN
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[out] lpOdPowerLimit The pointer to the \ref ADLODPowerLimitSetting structure storing the retrieved Overdrive parameters. 
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results 
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
ADL_EXTERNC int EXPOSED ADL2_OverdriveN_PowerLimit_Get(ADL_CONTEXT_HANDLE context, int iAdapterIndex, ADLODNPowerLimitSetting *lpODPowerLimit);

///
/// \brief Function to sets the current power limit settings
/// 
/// This function retrieves the current power limit for a specified adapter.
/// \platform
/// \WIN
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[in] lpOdPowerLimit The pointer to the \ref ADLODPowerLimitSetting structure storing the retrieved Overdrive parameters. 
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results 
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
ADL_EXTERNC int EXPOSED ADL2_OverdriveN_PowerLimit_Set(ADL_CONTEXT_HANDLE context, int iAdapterIndex, ADLODNPowerLimitSetting *lpODPowerLimit);

///
/// \brief Function to retrieve the current temperture
/// 
/// This function retrieves the current temperature for a specified adapter.
/// \platform
/// \WIN
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[in] iTemperatureType, temperature type. \ref ADLODNTemperatureType
/// \param[out] iTemperature The integer pointer, storing the retrieved Overdrive parameters. 
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results 
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
ADL_EXTERNC int EXPOSED ADL2_OverdriveN_Temperature_Get(ADL_CONTEXT_HANDLE context, int iAdapterIndex, int iTemperatureType, int *iTemperature);

///
/// \brief Function to retrieve the current OD performance status
/// 
/// This function retrieves the current OD performance for a specified adapter.
/// \platform
/// \WIN
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[out] lpOdPerformanceStatus The pointer to the \ref ADLODNPerformanceStatus structure storing the retrieved Overdrive parameters. 
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results 
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
ADL_EXTERNC int EXPOSED ADL2_OverdriveN_PerformanceStatus_Get(ADL_CONTEXT_HANDLE context, int iAdapterIndex, ADLODNPerformanceStatus *lpODPerformanceStatus);

// Custom fan for WS ODN vega 10
///
/// \brief Function to retrieve the Custom Fan support
/// 
/// This function retrieves the support of Custom Fan for a specified adapter. 
/// \platform
/// \WIN
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[out] lpSupported, if Custom Fan Supported : True else false . 
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results 
ADL_EXTERNC int EXPOSED ADL2_CustomFan_Caps(ADL_CONTEXT_HANDLE context, int iAdapterIndex, int *lpSupported);

///
/// \brief Function to retrieve the Custom Fan current status
/// 
/// This function retrieves the current status of Custom Fan for a specified adapter. 
/// \platform
/// \WIN
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[out] lpODFanControl, returns current status of the fan control. 
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results 
ADL_EXTERNC int EXPOSED ADL2_CustomFan_Get(ADL_CONTEXT_HANDLE context, int iAdapterIndex, ADLODNFanControl *lpODFanControl);

///
/// \brief Function to set the Custom Fan status
/// 
/// This function sets the current status of Custom Fan for a specified adapter. 
/// \platform
/// \WIN
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[in] iCurrent, if autowattman enabled : 1 else 0 . 
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results 
ADL_EXTERNC int EXPOSED ADL2_CustomFan_Set(ADL_CONTEXT_HANDLE context, int iAdapterIndex, ADLODNFanControl *lpODFanControl);

///
/// \brief Function to retrieve the memory timing .
/// 
/// This function enables/disables memory timing for a specified adapter. 
/// \platform
/// \ALL
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[out] lpSupport  an integer ponter of memory timing support flag. If blockchain mode supported, the value is 1, otherwise it is 0.
/// \param[out] lpCurrrentValue  an integer ponter of blockchain mode currrent state. If blockchain mode is enabled, the value is 1, otherwise it is 0.
/// \param[out] lpDfaultValue  an integer ponter of blockchain mode default state. If default blockchain mode is enabled, the value is 1, otherwise it is 0.
/// \param[out] lpNumberLevels  an integer ponter of pointer of memory  timing levels, which stores all memory levels. 
/// \param[out] lppLevelList  an integer ponter of memory  timing levels. 
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results///
ADL_EXTERNC int EXPOSED ADL2_OverdriveN_MemoryTimingLevel_Get(ADL_CONTEXT_HANDLE context, int iAdapterIndex, int *lpSupport, int *lpCurrentValue, int *lpDefaultValue, int *lpNumberLevels, int **lppLevelList);

///
/// \brief Function to change memory timing levels.
/// 
/// This function set GPU memory timing level for a specified adapter. 
/// \platform
/// \ALL
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[out] currentValue is an integer of GPU memory timing level. 
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results///

ADL_EXTERNC int EXPOSED ADL2_OverdriveN_MemoryTimingLevel_Set(ADL_CONTEXT_HANDLE context, int iAdapterIndex, int currentValue);

///
/// \brief Function to get zero RPM fan control info
/// 
/// This function to retrieve zero RPM fan control for a specified adapter. 
/// \platform
/// \ALL
/// \param[in]  context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[out] lpSupport  an integer ponter of zero RMP fan control support flag. If zero RPM fan control supported, the value is 1, otherwise it is 0.
/// \param[out] lpCurrrentValue  an integer ponter of zero RMP fan control currrent state. If zero RPM fan control is enabled, the value is 1, otherwise it is 0.
/// \param[out] lpDfaultValue  an integer ponter of zero RMP fan control default state. If zero RPM fan control is enabled, the value is 1, otherwise it is 0.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results///
ADL_EXTERNC int EXPOSED ADL2_OverdriveN_ZeroRPMFan_Get(ADL_CONTEXT_HANDLE context, int iAdapterIndex, int *lpSupport, int *lpCurrentValue, int *lpDefaultValue);

///
/// \brief Function to change Zero RPM control levels.
/// 
/// This function set GPU Zero RPM cntrol level for a specified adapter. 
/// \platform
/// \ALL
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[out] currentValue is an integer of GPU Zero RPM cntrol level. 
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results///
ADL_EXTERNC int EXPOSED ADL2_OverdriveN_ZeroRPMFan_Set(ADL_CONTEXT_HANDLE context, int iAdapterIndex, int currentValue);



///
/// \brief Function to get Fan curve  info
/// 
/// This function to retrieve Fan curve for a specified adapter. 
/// \platform
/// \ALL
/// \param[in]  context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[out] lpOverdriveNCapabilities The pointer to the bit-vector which indicates wich ODN feature is supported. /// \param[out] lpNumberPoints  an integer ponter of Fan curve points. 
/// \param[in/out] lpNumberOfODNExtFeatures The pointer to an integer which indicates the number of ODN features. The callee shold input the expected number of features. Then ADL can use this input to support comptiable.
///                When returing, the number is actual number of dricver currently supported features 
/// \param[out] lpInitSettingList The pointer to the list of current ODN Ext settingts. 
/// \param[out] lppInitSettingList The pointer to the list of current ODN Ext range of settingts. 
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
ADL_EXTERNC int EXPOSED ADL2_OverdriveN_SettingsExt_Get(ADL_CONTEXT_HANDLE context, int iAdapterIndex, int* lpOverdriveNExtCapabilities, int *lpNumberOfODNExtFeatures, ADLODNExtSingleInitSetting** lppInitSettingList, int** lppCurrentSettingList);

///
/// \brief Function to set fan curve (temperature and speed)
/// 
/// This function to for set fan curve (temperature and speed) a specified adapter. 
/// \platform
/// \ALL
/// \param[in]  context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[in]  iNumberOfODNExtFeatures  An integer which indicates the number of ODN features. 
/// \param[in]  lpItemValueValidList an integer pointer which indicates which element in lpItemValueList is valid
/// \param[in]  lpItemValueList an integer pointer which indicate the current value
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
ADL_EXTERNC int EXPOSED ADL2_OverdriveN_SettingsExt_Set(ADL_CONTEXT_HANDLE context, int iAdapterIndex, int iNumberOfODNExtFeatures,int* itemValueValidList, int* lpItemValueList);

///
/// \brief \newAPI15 Function to retrieve the Auto Wattman support
/// 
/// This function retrieves the support of Auto wattman for a specified adapter. 
/// \platform
/// \WIN
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[out] lpSupported, if autowattman Supported : True else false . 
/// \param[out] lpDefault, default autowattman value
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results 
ADL_EXTERNC int EXPOSED ADL2_OverdriveN_AutoWattman_Caps(ADL_CONTEXT_HANDLE context, int iAdapterIndex, int *lpSupported, int *lpDefault);

///
/// \brief \newAPI15 Function to retrieve the Auto Wattman current status
/// 
/// This function retrieves the current status of Auto wattman for a specified adapter. 
/// \platform
/// \WIN
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[out] lpCurrent, if autowattman enabled : 1 else 0 . 
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results 
ADL_EXTERNC int EXPOSED ADL2_OverdriveN_AutoWattman_Get(ADL_CONTEXT_HANDLE context, int iAdapterIndex, int *lpCurrent);

///
/// \brief \newAPI15 Function to set the Auto Wattman status
/// 
/// This function sets the current status of Auto wattman for a specified adapter. 
/// \platform
/// \WIN
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[in] iCurrent, if autowattman enabled : 1 else 0 . 
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results 
ADL_EXTERNC int EXPOSED ADL2_OverdriveN_AutoWattman_Set(ADL_CONTEXT_HANDLE context, int iAdapterIndex, int iCurrent);

///
/// \brief \newAPI15 Function to retrieve the Events occured
/// 
/// This function retrieves the events counts for a specified adapter. works on earlier OD versions also.
/// \platform
/// \WIN
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[in] eventcounterType Event counter type: Thermal event = 0;VPU recovery =1. 
/// \param[out] eventCount, The number of events occured. 
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results 
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
ADL_EXTERNC int EXPOSED ADL2_OverdriveN_CountOfEvents_Get(ADL_CONTEXT_HANDLE context, int iAdapterIndex, int eventcounterType, int *eventCount);

///
/// \brief \newAPI15 Function to retrieve the OverdriveN SCLK Auto overclock state.
/// 
/// This function retrieves the OverdriveN SCLK Auto overclock for a specified adapter.
/// \platform
/// \WIN
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[in]  lpStatus Auto overclock state \ref ADL_TRUE   \ref ADL_FALSE 
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results 
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
ADL_EXTERNC int EXPOSED ADL2_OverdriveN_SCLKAutoOverClock_Get(ADL_CONTEXT_HANDLE context, int iAdapterIndex, int *lpStatus);

///
/// \brief \newAPI15 Function to sets the OverdriveN SCLK Auto overclock state.
/// 
/// This function retrieves the OverdriveN SCLK Auto overclock state for a specified adapter.
/// \platform
/// \WIN
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[in]  iStatus Auto overclock state \ref ADL_TRUE   \ref ADL_FALSE 
/// \param[in/out]  iFlags. this has two meanings. input: when reseting AOC, need to ODNControlType_Default; output: Auto overclock needs reboot or not; flags \ref 0 or 1 - reboot required
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results 
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
ADL_EXTERNC int EXPOSED ADL2_OverdriveN_SCLKAutoOverClock_Set(ADL_CONTEXT_HANDLE context, int iAdapterIndex, int iStatus, int *iFlags);

///\brief \newAPI15 Function to enable or disable OVERdrive test 
/// This function enables or disables Overdrive testing status for a specified display adapter. works on earlier OD versions also.
/// \platform
/// \WIN
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in]  iAdapterIndex The index of the desired adapter.
/// \param[in]  iEnabled \ref ADL_TRUE   \ref ADL_FALSE 
/// \return If the function succeeds, the return value is \ref ADL_OK (zero). Otherwise the return value is an ADL error code (non-zero). \ref define_adl_results 
///
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
ADL_EXTERNC int EXPOSED ADL2_OverdriveN_Test_Set(ADL_CONTEXT_HANDLE context, int iAdapterIndex, int iEnabled);

///
/// \brief \newAPI15 Function to retrieve the OverdriveN Throttle Notification state and its flags.
/// 
/// This function retrieves the OverdriveN Throttle Notification for a specified adapter.
/// \platform
/// \WIN
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[in]  lpStatus Throttle Notification state \ref ADL_TRUE   \ref ADL_FALSE 
/// \param[in]  lpThrottleFlags Throttle Notification flags \ref ADL_ODN_THROTTLE_NOTIFICATION, which tells the reason for low performance
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results 
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
ADL_EXTERNC int EXPOSED ADL2_OverdriveN_ThrottleNotification_Get(ADL_CONTEXT_HANDLE context, int iAdapterIndex, int *lpStatus, int *lpThrottleFlags);

/// @}

#endif /* OVERDRIVEN_H_ */
