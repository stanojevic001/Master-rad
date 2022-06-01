//
// Copyright (c) 2016 Advanced Micro Devices, Inc. All rights reserved.
//
// MIT LICENSE:
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

/// \file sony_display.h
/// \brief Contains Sony display-related functions exposed by ADL for \ALL platforms.
///
/// This file contains Sony specific LCD Refresh display-related functions exposed by ADL for \ALL platforms.
/// All functions found in this file can be used as a reference to ensure
/// the specified function pointers can be used by the appropriate runtime
/// dynamic library loaders. This header file not for public release

#ifndef SONY_DISPLAY_H_
#define SONY_DISPLAY_H_

#ifndef ADL_EXTERNC
#ifdef __cplusplus
#define ADL_EXTERNC extern "C"
#else
#define ADL_EXTERNC
#endif
#endif
///\ingroup DISPLAYAPI
///\defgroup LCDAPI LCD related APIs
/// This group describes the LCD APIs.

/// \addtogroup LCDAPI
/// @{
///
///\brief Function to get the LCD refresh rate capability. Not a Public API
/// 
/// This function retrieves the LCD refresh rate capability. ASIC Specific API
/// \platform
/// \ALL
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in]   iAdapterIndex The ADL index handle of the desired adapter.
/// \param[out]  lpLcdRefreshRateCap The pointer to the retrieved LCD refresh rate capability.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
ADL_EXTERNC int EXPOSED ADL2_Display_LCDRefreshRateCapability_Get(ADL_CONTEXT_HANDLE context,int iAdapterIndex, ADLLcdRefreshRateCap *lpLcdRefreshRateCap);

///
///\brief Function to get the LCD refresh rate capability. Not a Public API
/// 
/// This function retrieves the LCD refresh rate capability. ASIC Specific API
/// \platform
/// \ALL
/// \param[in]   iAdapterIndex The ADL index handle of the desired adapter.
/// \param[out]  lpLcdRefreshRateCap The pointer to the retrieved LCD refresh rate capability.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
ADL_EXTERNC int EXPOSED ADL_Display_LCDRefreshRateCapability_Get(int iAdapterIndex, ADLLcdRefreshRateCap *lpLcdRefreshRateCap);

///
///\brief Function to get the LCD refresh rate. Not a Public API
/// 
/// This function retrieves the LCD refresh rate. ASIC Specific API
/// \platform
/// \ALL
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in]   iAdapterIndex The ADL index handle of the desired adapter.
/// \param[out]  lpADLMode The pointer to the retrieved LCD refresh rate. Only ADLMode.iRefreshRate is used.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
ADL_EXTERNC int EXPOSED ADL2_Display_LCDRefreshRate_Get(ADL_CONTEXT_HANDLE context,int iAdapterIndex, ADLMode * lpADLMode);   

///
///\brief Function to get the LCD refresh rate. Not a Public API
/// 
/// This function retrieves the LCD refresh rate. ASIC Specific API
/// \platform
/// \ALL
/// \param[in]   iAdapterIndex The ADL index handle of the desired adapter.
/// \param[out]  lpADLMode The pointer to the retrieved LCD refresh rate. Only ADLMode.iRefreshRate is used.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
ADL_EXTERNC int EXPOSED ADL_Display_LCDRefreshRate_Get(int iAdapterIndex, ADLMode * lpADLMode);   

///
///\brief Function to set LCD refresh rate. Not a Public API
/// 
/// This function sets LCD refresh rate. ASIC Specific API
/// \platform
/// \ALL
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in]   iAdapterIndex The ADL index handle of the desired adapter.
/// \param[in]  lpADLMode The pointer to the LCD refresh rate. Only ADLMode.iRefreshRate is used.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
/// 
/// \remarks Call ADL_Flush_Driver_Data() after to persist settings on reboot.
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
ADL_EXTERNC int EXPOSED ADL2_Display_LCDRefreshRate_Set(ADL_CONTEXT_HANDLE context,int iAdapterIndex, ADLMode * lpADLMode);

///
///\brief Function to set LCD refresh rate. Not a Public API
/// 
/// This function sets LCD refresh rate. ASIC Specific API
/// \platform
/// \ALL
/// \param[in]   iAdapterIndex The ADL index handle of the desired adapter.
/// \param[in]  lpADLMode The pointer to the LCD refresh rate. Only ADLMode.iRefreshRate is used.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
/// 
/// \remarks Call ADL_Flush_Driver_Data() after to persist settings on reboot.
ADL_EXTERNC int EXPOSED ADL_Display_LCDRefreshRate_Set(int iAdapterIndex, ADLMode * lpADLMode);

///
///\brief Function to retrieve LCD refresh rate options. Not a Public API
/// 
/// This function retrieves LCD refresh rate options. ASIC Specific API
/// \platform
/// \ALL
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in]   iAdapterIndex The ADL index handle of the desired adapter.
/// \param[out]  lpLcdRefreshRateOptions The pointer to the LCD refresh rate options.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
ADL_EXTERNC int EXPOSED ADL2_Display_LCDRefreshRateOptions_Get(ADL_CONTEXT_HANDLE context,int iAdapterIndex, ADLLcdRefreshRateOptions* lpLcdRefreshRateOptions); 

///
///\brief Function to retrieve LCD refresh rate options. Not a Public API
/// 
/// This function retrieves LCD refresh rate options. ASIC Specific API
/// \platform
/// \ALL
/// \param[in]   iAdapterIndex The ADL index handle of the desired adapter.
/// \param[out]  lpLcdRefreshRateOptions The pointer to the LCD refresh rate options.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
ADL_EXTERNC int EXPOSED ADL_Display_LCDRefreshRateOptions_Get(int iAdapterIndex, ADLLcdRefreshRateOptions* lpLcdRefreshRateOptions); 

///
///\brief Function to set LCD refresh rate options. Not a Public API
/// 
/// This function sets LCD refresh rate options. ASIC Specific API
/// \platform
/// \ALL
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in]   iAdapterIndex The ADL index handle of the desired adapter.
/// \param[in]  lpLcdRefreshRateOptions The pointer to the LCD refresh rate options.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
/// 
/// \remarks Call ADL_Flush_Driver_Data() after to persist settings on reboot.
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
ADL_EXTERNC int EXPOSED ADL2_Display_LCDRefreshRateOptions_Set(ADL_CONTEXT_HANDLE context,int iAdapterIndex, ADLLcdRefreshRateOptions* lpLcdRefreshRateOptions);

///
///\brief Function to set LCD refresh rate options. Not a Public API
/// 
/// This function sets LCD refresh rate options. ASIC Specific API
/// \platform
/// \ALL
/// \param[in]   iAdapterIndex The ADL index handle of the desired adapter.
/// \param[in]  lpLcdRefreshRateOptions The pointer to the LCD refresh rate options.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
/// 
/// \remarks Call ADL_Flush_Driver_Data() after to persist settings on reboot.
ADL_EXTERNC int EXPOSED ADL_Display_LCDRefreshRateOptions_Set(int iAdapterIndex, ADLLcdRefreshRateOptions* lpLcdRefreshRateOptions);

/// @}

#endif /* SONY_DISPLAY_H_ */
