#pragma once
///
///  Copyright (c) 2021 Advanced Micro Devices, Inc.

///  THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
///  EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
///  WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.

/// \file radeonusbled.h
/// \brief Contains all radeon USB LED functions exposed by ADL for \ALL platforms.
///
/// This file contains all radeon usb led functions exposed by ADL for \ALL platforms.
/// All functions found in this file can be used as a reference to ensure
/// the specified function pointers can be used by the appropriate runtime
/// dynamic library loaders.

#ifndef RADEONUSBLED_H_
#define RADEONUSBLED_H_

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

/// \addtogroup GENARICAPI
/// @{
///
///
/// \brief Function to get LED devices presence for GPU index.
/// 
/// This interface allows ADL user to query the number of LED devices present.
/// \platform
/// \WIN
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter
/// \param[out] bLEDSupported returns true if Radeon USB LED is supported
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results 
/// \remarks
ADL_EXTERNC int EXPOSED ADL2_Adapter_Radeon_USB_LED_Support_Get (ADL_CONTEXT_HANDLE context, int iAdapterIndex, bool* bLEDSupported);

///
///
/// \brief Function to query supported LED controls.
/// 
/// This interface allows ADL user to a bitmask of supported LED patterns on the LED controllers, including OFF and custom pattern, Rainbow, etc...
/// \platform
/// \WIN
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter
/// \param[out] ControlSupport returns a bitmask of all supported LED patterns.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results 
/// \remarks
ADL_EXTERNC int EXPOSED ADL2_Adapter_Radeon_USB_LED_Supported_Controls_Get (ADL_CONTEXT_HANDLE context, int iAdapterIndex, RadeonLEDBARSupportedControl * ControlSupport);

///
///
/// \brief Function to query list of supported LED pattern control
/// 
/// This interface allows ADL user to query list of LED patterns on the LED controller. Output can be used for set functionality
/// \platform
/// \WIN
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in] iAdapterIndex The ADL index handle of the desired adapter
/// \param[in] \ref ADL_RADEON_USB_LED_BAR_CONTROLS control is a selected pattern a user intended to configure.
/// \param[out] \ref RadeonLEDBARSupportedConfig ConfigSupport returns a bit mask of supported configuration for user selected pattern, configs included speed, bightness, direction of pattern.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results 
/// \remarks
ADL_EXTERNC int EXPOSED ADL2_Adapter_Radeon_USB_LED_Pattern_Supported_Controls_Get (ADL_CONTEXT_HANDLE context, int iAdapterIndex, ADL_RADEON_USB_LED_BAR_CONTROLS control, RadeonLEDBARSupportedConfig * ConfigSupport)

///
///
/// \brief Function to set user provided LED pattern.
/// 
/// This interface allows users to set LED pattern on the LED controller.
/// \platform
/// \WIN
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in] iAdapterIndex The ADL index handle of the desired adapter
/// \param[in] \ref ADL_RADEON_LED_PATTERN_CONFIG config containing requested LED control and all LED configuration for the LED settings.
/// \param[out] \ref ADL_RADEON_LED_PATTERN_CONFIG config for Morse Code usage returns the morse code representation of the user input.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results 
/// \remarks
ADL_EXTERNC int EXPOSED ADL2_Adapter_Radeon_LED_Patten_Control_Set (ADL_CONTEXT_HANDLE context, int iAdapterIndex, ADL_RADEON_LED_PATTERN_CONFIG config);

///
///
/// \brief Function to save programmed LED configuration onto LED flash to persist on reboot and power down.
/// 
/// This interface allows ADL user to query the number of LED devices present.
/// \platform
/// \WIN
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in] iAdapterIndex The ADL index handle of the desired adapter
/// \return  If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results 
/// \remarks
ADL_EXTERNC int EXPOSED ADL2_Adapter_Radeon_Usb_Led_Flash_Save (ADL_CONTEXT_HANDLE context, int iAdapterIndex);

/// @}
#endif /* RADEONUSBLED_H_ */