///  Copyright (c) 2013 Advanced Micro Devices, Inc.

///  THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
///  EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
///  WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.

/// \file amd_overdrive6.h
/// \brief Contains all AMD internal adapter-related functions exposed by ADL for \ALL platforms.
///
/// This file contains all AMD internal adapter-related functions exposed by ADL for \ALL platforms.
/// All functions in this file can be used as a reference to ensure
/// the specified function pointers can be used by the appropriate runtime
/// dynamic library loaders. This header file is for AMD internal use only.

#ifndef AMD_OVERDRIVE6_H_
#define AMD_OVERDRIVE6_H_

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

/// \addtogroup OVERDRIVE6
// @{

///
/// \brief Function to retrieve Overdrive maximum recommended clock adjustment.
/// 
/// This function retrieves the maximum recommended engine and memory clock adjustment percentages, given the power limit adjustment setting.
/// \platform
/// \ALL
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[in]  iStateType Specifies if default or current clock ranges for the power state will be retrieved.  Currently only performance state is supported.  Possible Values: \ref ADL_OD6_GETSTATEINFO_DEFAULT_PERFORMANCE, \ref ADL_OD6_GETSTATEINFO_CUSTOM_PERFORMANCE, \ref ADL_OD6_GETSTATEINFO_CURRENT
/// \param[in]  iPowerControlPercent Specifies the power control adjustment value (in +/- percent).  This value will be used to look up the recommended maximum clock adjustment values.
/// \param[in,out] lpODMaxClockAdjust Pointer to the retrieved clock adjustment info structure \ref ADLOD6MaxClockAdjust.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results 
ADL_EXTERNC int EXPOSED ADL2_Overdrive6_MaxClockAdjust_Get(ADL_CONTEXT_HANDLE context, int iAdapterIndex, int iStateType, int iPowerControlPercent, ADLOD6MaxClockAdjust *lpODMaxClockAdjust);

///
/// \brief Function to retrieve Overdrive maximum recommended clock adjustment.
/// 
/// This function retrieves the maximum recommended engine and memory clock adjustment percentages, given the power limit adjustment setting.
/// \platform
/// \ALL
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[in]  iStateType Specifies if default or current clock ranges for the power state will be retrieved.  Currently only performance state is supported.  Possible Values: \ref ADL_OD6_GETSTATEINFO_DEFAULT_PERFORMANCE, \ref ADL_OD6_GETSTATEINFO_CUSTOM_PERFORMANCE, \ref ADL_OD6_GETSTATEINFO_CURRENT
/// \param[in]  iPowerControlPercent Specifies the power control adjustment value (in +/- percent).  This value will be used to look up the recommended maximum clock adjustment values.
/// \param[in,out] lpODMaxClockAdjust Pointer to the retrieved clock adjustment info structure \ref ADLOD6MaxClockAdjust.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results 
ADL_EXTERNC int EXPOSED ADL_Overdrive6_MaxClockAdjust_Get(int iAdapterIndex, int iStateType, int iPowerControlPercent, ADLOD6MaxClockAdjust *lpODMaxClockAdjust);

///  \brief Function returns the advanced fan control capability of the specified adapter.
/// Advanced fan control is the feature which makes the fan speed is always kept to a minimum within current settings so the acoustics are also minimized.
/// The end users are able to select the target ASIC temperature and fan PWM% via the CCC or other applications.
/// \platform
/// \ALL
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[out] lpSupported: a pointer to an int containing the current advanced fan control(AFC) feature status. Possible Values: 1 - AFC Enabled, 0 - AFC Disabled.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error  code.
ADL_EXTERNC int EXPOSED ADL_Overdrive6_FuzzyController_Caps (int iAdapterIndex, int *lpSupported);

///  \brief Function returns the advanced fan control capability of the specified adapter.
/// Advanced fan control is the feature which makes the fan speed is always kept to a minimum so the acoustics are also minimized.
/// The end user will be able to select the target ASIC temperature and fan PWM% via the CCC or other applications.
/// \platform
/// \ALL
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[out]  lpSupported: a pointer to an int containing the current advanced fan control(AFC) feature status. Possible Values: 1 - AFC Enabled, 0 - AFC Disabled.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error  code.
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process and to assure that ADL API are thread-safe. Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
ADL_EXTERNC int EXPOSED ADL2_Overdrive6_FuzzyController_Caps (ADL_CONTEXT_HANDLE context, int iAdapterIndex, int *lpSupported);


/// \brief Function to get the PowerControl adjustment range.
/// 
/// This function returns the PowerControl adjustment range (in percentage) for the specified adapter.
/// \platform
/// \ALL
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in]  iAdapterIndex The ADL index handle  of the desired adapter.
/// \param[in,out]  lpPowerControlInfo The pointer to the \ref ADLOD6PowerControlInfo_V2 returning the PowerControl adjustment range. 
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. 
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
ADL_EXTERNC int EXPOSED ADL2_Overdrive6_PowerControlInfo_Get_X2(ADL_CONTEXT_HANDLE context,int iAdapterIndex, ADLOD6PowerControlInfo_V2 *lpPowerControlInfo);

// @}

#endif /* AMD_OVERDRIVE6_H_ */

