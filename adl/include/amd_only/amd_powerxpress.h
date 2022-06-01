///
///  Copyright (c) 2008 - 2021 Advanced Micro Devices, Inc.

///  THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
///  EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
///  WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.

/// \file amd_powerxpress.h
/// \brief Contains all AMD internal PowerExpress-related functions exposed by ADL for \ALL platforms.
///
/// This file contains all AMD internal PowerExpress-related functions exposed by ADL for \ALL platforms.
/// All functions found in this file can be used as a reference to ensure
/// the specified function pointers can be used by the appropriate runtime
/// dynamic library loaders. This header file is for AMD internal use only.

#ifndef AMD_POWERXPRESS_H_
#define AMD_POWERXPRESS_H_

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

///\brief Function to get default state of PowerXpress.
///
/// This prototype function retrieves the current and default PowerXpress state. This function should
/// only be used for fixed mode PowerXpress 3.0. This function supersedes \ref ADL_Display_PowerXpressActiveGPU_Get
///
/// \platform
/// \Linux
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
///\param[in] iAdapterIndex The ADL index handle of the desired adapter.
///\param[out] lpActiveGPU The pointer to the value storing the active GPU in PowerXpress: \ref ADL_DL_POWERXPRESS_GPU_INTEGRATED or
/// \ref ADL_DL_POWERXPRESS_GPU_DISCRETE
///\param[out] lpDeafultGPU The pointer to the value storing the default GPU in PowerXpress: \ref ADL_DL_POWERxPRESS_GPU_INTEGRATED or
/// \ref ADL_DL_POWERXPRESS_GPU_DISCRETE
///\return If the function succeeds, the return value is \ref ADL_OK. Otherwise the review value is ADL error code. \ref define_adl_results
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
ADL_EXTERNC int EXPOSED ADL2_Display_PowerXpressActvieGPUR2_Get(ADL_CONTEXT_HANDLE context,int iAdapterIndex, int *lpActiveGPU, int *lpDefaultGPU);

///\brief Function to get default state of PowerXpress.
///
/// This prototype function retrieves the current and default PowerXpress state. This function should
/// only be used for fixed mode PowerXpress 3.0. This function supersedes \ref ADL_Display_PowerXpressActiveGPU_Get
///
/// \platform
/// \Linux
///\param[in] iAdapterIndex The ADL index handle of the desired adapter.
///\param[out] lpActiveGPU The pointer to the value storing the active GPU in PowerXpress: \ref ADL_DL_POWERXPRESS_GPU_INTEGRATED or
/// \ref ADL_DL_POWERXPRESS_GPU_DISCRETE
///\param[out] lpDeafultGPU The pointer to the value storing the default GPU in PowerXpress: \ref ADL_DL_POWERxPRESS_GPU_INTEGRATED or
/// \ref ADL_DL_POWERXPRESS_GPU_DISCRETE
///\return If the function succeeds, the return value is \ref ADL_OK. Otherwise the review value is ADL error code. \ref define_adl_results
ADL_EXTERNC int EXPOSED ADL_Display_PowerXpressActvieGPUR2_Get(int iAdapterIndex, int *lpActiveGPU, int *lpDefaultGPU);

///
/// \brief  This function gets the capability of current Extended Battery Mode.
///
/// This function gets the capability of Extended Battery Mode.
/// \platform 
/// \WIN7
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in]   iAdapterIndex The ADL index handle of the desired adapter.
/// \param[out]  lpbSupprted The capability of Extended Battery Mode to be get.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
ADL_EXTERNC int EXPOSED ADL2_PowerXpress_ExtendedBatteryMode_Caps(ADL_CONTEXT_HANDLE context,int iAdapterIndex, int *lpbSupprted);

///
/// \brief  This function gets the capability of current Extended Battery Mode.
///
/// This function gets the capability of Extended Battery Mode.
/// \platform 
/// \WIN7
/// \param[in]   iAdapterIndex The ADL index handle of the desired adapter.
/// \param[out]  lpbSupprted The capability of Extended Battery Mode to be get.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
ADL_EXTERNC int EXPOSED ADL_PowerXpress_ExtendedBatteryMode_Caps(int iAdapterIndex, int *lpbSupprted);


///
/// \brief  This function gets current Extended Battery Mode state.
///
/// This function gets current Extended Battery Mode state.
/// \platform 
/// \WIN7
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in]   iAdapterIndex The ADL index handle of the desired adapter.
/// \param[out]  lpbEnable The current state of extended battery mode to be get.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
ADL_EXTERNC int EXPOSED ADL2_PowerXpress_ExtendedBatteryMode_Get(ADL_CONTEXT_HANDLE context,int iAdapterIndex, int *lpbEnable);

///
/// \brief  This function gets current Extended Battery Mode state.
///
/// This function gets current Extended Battery Mode state.
/// \platform 
/// \WIN7
/// \param[in]   iAdapterIndex The ADL index handle of the desired adapter.
/// \param[out]  lpbEnable The current state of extended battery mode to be get.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
ADL_EXTERNC int EXPOSED ADL_PowerXpress_ExtendedBatteryMode_Get(int iAdapterIndex, int *lpbEnable);


///
/// \brief  This function sets "Extended Battery Mode" state.
///
/// This function sets "Extended Battery Mode" state.
/// \platform 
/// \WIN7
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in]   iAdapterIndex The ADL index handle of the desired adapter.
/// \param[in]   bEnable The state of extended battery mode to be set.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
ADL_EXTERNC int EXPOSED ADL2_PowerXpress_ExtendedBatteryMode_Set(ADL_CONTEXT_HANDLE context,int iAdapterIndex, int bEnable);

///
/// \brief  This function sets "Extended Battery Mode" state.
///
/// This function sets "Extended Battery Mode" state.
/// \platform 
/// \WIN7
/// \param[in]   iAdapterIndex The ADL index handle of the desired adapter.
/// \param[in]   bEnable The state of extended battery mode to be set.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
ADL_EXTERNC int EXPOSED ADL_PowerXpress_ExtendedBatteryMode_Set(int iAdapterIndex, int bEnable);

/// \brief  This function gets information related to PowerXpress Long Idle Detect feature.
///
/// Retrieves info about support, default value, current state of PowerXpress Long Idle Detect feature.
/// \platform 
/// \WIN7 and \WIN8
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in]   iAdapterIndex The ADL index handle of the desired adapter.
/// \param[out]  lpSupported Returns driver support for PowerXpress Long Idle Detect feature. Not-zero value indicates that the driver supports the feature. 0 � driver does not support the feature. Client can pass NULL to indicate that it is not interested in the supported value. 
/// \param[out]  lpDefault Returns default state of PowerXpress Long Idle Detect feature. Not-zero value indicates that the driver enables the Long Idle Detect by default. 0 indicates that the feature is disabled by the driver by default. Client can pass NULL to indicate that it is not interested in the default value. 
/// \param[out]  lpEnabled Returns current state of PowerXpress Long Idle Detect feature. Not-zero value indicates that Long Idle Detect is currently enabled in the driver. 0 indicates that it is disabled. Not NULL pointer must be passed by client.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
ADL_EXTERNC int EXPOSED ADL2_PowerXpress_LongIdleDetect_Get(ADL_CONTEXT_HANDLE context,int iAdapterIndex, int* lpSupported, int* lpDefault, int* lpEnabled);

/// \brief  This function gets information related to PowerXpress Long Idle Detect feature.
///
/// Retrieves info about support, default value, current state of PowerXpress Long Idle Detect feature.
/// \platform 
/// \WIN7 and \WIN8
/// \param[in]   iAdapterIndex The ADL index handle of the desired adapter.
/// \param[out]  lpSupported Returns driver support for PowerXpress Long Idle Detect feature. Not-zero value indicates that the driver supports the feature. 0 � driver does not support the feature. Client can pass NULL to indicate that it is not interested in the supported value. 
/// \param[out]  lpDefault Returns default state of PowerXpress Long Idle Detect feature. Not-zero value indicates that the driver enables the Long Idle Detect by default. 0 indicates that the feature is disabled by the driver by default. Client can pass NULL to indicate that it is not interested in the default value. 
/// \param[out]  lpEnabled Returns current state of PowerXpress Long Idle Detect feature. Not-zero value indicates that Long Idle Detect is currently enabled in the driver. 0 indicates that it is disabled. Not NULL pointer must be passed by client.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
ADL_EXTERNC int EXPOSED ADL_PowerXpress_LongIdleDetect_Get(int iAdapterIndex, int* lpSupported, int* lpDefault, int* lpEnabled);

/// \brief  This function enables / disables PowerXpress Long Idle Detect feature.
///
/// Sets current states of PowerXpress Long Idle Detect feature. It is assumed that the client first calls to ADL_PowerXpress_LongIdleDetect_Get to verify that the feature is supportd.
/// \platform 
/// \WIN7 and \WIN8
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[in]  iEnabled New state of PowerXpress Long Idle Detect feature. Pass not-zero value to enable the feature. Pass 0 to disable the feature.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
ADL_EXTERNC int EXPOSED ADL2_PowerXpress_LongIdleDetect_Set(ADL_CONTEXT_HANDLE context,int iAdapterIndex, int iEnabled);

/// \brief  This function enables / disables PowerXpress Long Idle Detect feature.
///
/// Sets current states of PowerXpress Long Idle Detect feature. It is assumed that the client first calls to ADL_PowerXpress_LongIdleDetect_Get to verify that the feature is supportd.
/// \platform 
/// \WIN7 and \WIN8
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[in]  iEnabled New state of PowerXpress Long Idle Detect feature. Pass not-zero value to enable the feature. Pass 0 to disable the feature.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
ADL_EXTERNC int EXPOSED ADL_PowerXpress_LongIdleDetect_Set(int iAdapterIndex, int iEnabled);

///
/// \brief  This function gets "Power Control Mode" state.
///
/// This function gets " Power Control Mode " state of a DGPU whether it is currently Power On or Power Off.
/// \platform 
/// \WIN7 and Above
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in]   iAdapterIndex The ADL index handle of the desired adapter. It accepts only DGPU adapter index as we need to make this GPU to power up or power down. Else, the call will fail.
/// \param[out] lpPowerControlState The current power state of the DGPU. 1 implies Power On and 0 implies Power Off
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
ADL_EXTERNC int EXPOSED ADL2_PowerXpress_PowerControlMode_Get(ADL_CONTEXT_HANDLE context, int iAdapterIndex, int *lpPowerControlState);

///
/// \brief  This function gets "Power Control Mode" state.
///
/// This function gets " Power Control Mode " state of a DGPU whether it is currently Power On or Power Off.
/// \platform 
/// \WIN7 and Above
/// \param[in]   iAdapterIndex The ADL index handle of the desired adapter. It accepts only DGPU adapter index as we need to make this GPU to power up or power down. Else, the call will fail.
/// \param[out] lpPowerControlState The current power state of the DGPU. 1 implies Power On and 0 implies Power Off
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
ADL_EXTERNC int EXPOSED ADL_PowerXpress_PowerControlMode_Get(int iAdapterIndex, int *lpPowerControlState);

///
/// \brief  This function sets "Power Control Mode" state.
///
/// This function sets " Power Control Mode " state of a DGPU whether to Power On or Power Off.
/// \platform 
/// \WIN7 and Above
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in]   iAdapterIndex The ADL index handle of the desired adapter. It accepts only DGPU adapter index as we need to make this GPU to power up or power down. Else, the call will fail.
/// \param[in]   powerControlState The Power state of the DGPU to set. 1 implies Power On and 0 implies Power Off
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
ADL_EXTERNC int EXPOSED ADL2_PowerXpress_PowerControlMode_Set(ADL_CONTEXT_HANDLE context, int iAdapterIndex, int powerControlState);

///
/// \brief  This function sets "Power Control Mode" state.
///
/// This function sets " Power Control Mode " state of a DGPU whether to Power On or Power Off.
/// \platform 
/// \WIN7 and Above
/// \param[in]   iAdapterIndex The ADL index handle of the desired adapter. It accepts only DGPU adapter index as we need to make this GPU to power up or power down. Else, the call will fail.
/// \param[in]   powerControlState The Power state of the DGPU to set. 1 implies Power On and 0 implies Power Off
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
ADL_EXTERNC int EXPOSED ADL_PowerXpress_PowerControlMode_Set(int iAdapterIndex, int powerControlState);


///
/// \brief ADL local interface. Function to get Hybrid Discrete graphics support.
/// 
/// The function is used to get if the windows has inbuilt support for Hybrid Discrete graphics, which implies A+I
/// \platform
/// \WINBlue
/// \return TRUE: HybridDiscrete; FALSE: otherwise.
ADL_EXTERNC int EXPOSED ADL_Win_IsHybridAI();



#endif /* AMD_POWERXPRESS_H_ */
