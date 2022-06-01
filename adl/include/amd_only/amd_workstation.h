///
///  Copyright (c) 2008 - 2021 Advanced Micro Devices, Inc.
 
///  THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
///  EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
///  WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.

/// \file amd_workstation.h
/// \brief This file contains the workstation method declarations used by the internal AMD Driver Library interfaces for \ALL platforms.
///

#ifndef __AMD_WORKSTATION_H__
#define __AMD_WORKSTATION_H__

#ifndef ADL_EXTERNC
#ifdef __cplusplus
#define ADL_EXTERNC extern "C"
#else
#define ADL_EXTERNC
#endif
#endif
/// \addtogroup WORKSTATIONAPI
/// @{

///
/// \brief Function to retreive the worstation 8-bit Grayscale mode.
/// 
/// This function retrieves the current and default workstation 8-bit Grayscale mode.
/// \platform
/// \XP
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[out] lpDefState The pointer to the default 8-bit Grayscale mode. \ref ADL_FALSE 
/// \param[out] lpCurState The pointer to the current 8-bit Grayscale mode. \ref ADL_TRUE/ADL_FALSE 
/// \return If the function is successful, \ref ADL_OK is returned. If lpDefState and/or lpCurState are NULL, \ref ADL_ERR_NULL_POINTER is returned.\n
/// If iAdapterIndex is an invalid adapter index, \ref ADL_ERR_INVALID_ADL_IDX is returned. If the function is not supported, \ref ADL_ERR_NOT_SUPPORTED is returned. For all other errors, \ref ADL_ERR is returned.
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
ADL_EXTERNC int EXPOSED ADL2_Workstation_8BitGrayscale_Get (ADL_CONTEXT_HANDLE context, int iAdapterIndex, int *lpDefState, int *lpCurState);

///
/// \brief Function to retreive the worstation 8-bit Grayscale mode.
/// 
/// This function retrieves the current and default workstation 8-bit Grayscale mode.
/// \platform
/// \XP
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[out] lpDefState The pointer to the default 8-bit Grayscale mode. \ref ADL_FALSE 
/// \param[out] lpCurState The pointer to the current 8-bit Grayscale mode. \ref ADL_TRUE/ADL_FALSE 
/// \return If the function is successful, \ref ADL_OK is returned. If lpDefState and/or lpCurState are NULL, \ref ADL_ERR_NULL_POINTER is returned.\n
/// If iAdapterIndex is an invalid adapter index, \ref ADL_ERR_INVALID_ADL_IDX is returned. If the function is not supported, \ref ADL_ERR_NOT_SUPPORTED is returned. For all other errors, \ref ADL_ERR is returned.
ADL_EXTERNC int EXPOSED ADL_Workstation_8BitGrayscale_Get ( int iAdapterIndex, int *lpDefState, int *lpCurState);

///
/// \brief Function to set the workstation 8-bit Grayscale mode.
/// 
/// This function sets the current workstation 8-bit Grayscale mode mode.
/// \platform
/// \XP
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[in] iCurState The desired workstation 8-bit Grayscale mode. \ref ADL_TRUE/ADL_FALSE 
/// \return If the function is successful, \ref ADL_OK is returned. If iAdapterIndex is an invalid adapter index, \ref ADL_ERR_INVALID_ADL_IDX is returned.\n
/// If the function is not supported, \ref ADL_ERR_NOT_SUPPORTED is returned. For all other errors, \ref ADL_ERR is returned.
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
ADL_EXTERNC int EXPOSED ADL2_Workstation_8BitGrayscale_Set(ADL_CONTEXT_HANDLE context, int iAdapterIndex, int iCurState);

///
/// \brief Function to set the workstation 8-bit Grayscale mode.
/// 
/// This function sets the current workstation 8-bit Grayscale mode mode.
/// \platform
/// \XP
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[in] iCurState The desired workstation 8-bit Grayscale mode. \ref ADL_TRUE/ADL_FALSE 
/// \return If the function is successful, \ref ADL_OK is returned. If iAdapterIndex is an invalid adapter index, \ref ADL_ERR_INVALID_ADL_IDX is returned.\n
/// If the function is not supported, \ref ADL_ERR_NOT_SUPPORTED is returned. For all other errors, \ref ADL_ERR is returned.
ADL_EXTERNC int EXPOSED ADL_Workstation_8BitGrayscale_Set( int iAdapterIndex, int iCurState);

/// \brief Function to retrieve RAS Error Log.
/// 
 /// This function implements a call to retrieve RAS Error Logs.
 /// \platform
 /// \VISTAWIN7
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[out] pCorrectedErrors The pointer to the number of corrected errors
/// \param[out] pUnCorrectedErrors The pointer to the number of uncorreted errors
/// \return If the function succeeds, the return value is \ref ADL_OK, or an ADL error code otherwise. \ref define_adl_results
ADL_EXTERNC int EXPOSED ADL2_Workstation_RAS_ErrorCounts_Get (ADL_CONTEXT_HANDLE context,int iAdapterIndex, int* pCorrectedErrors, int* pUnCorrectedErrors);

/// \brief Function to reset RAS Error Count
/// 
 /// This function implements a call to retrieve RAS Error Logs.
 /// \platform
 /// \VISTAWIN7
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \return If the function succeeds, the return value is \ref ADL_OK, or an ADL error code otherwise. \ref define_adl_results
ADL_EXTERNC int EXPOSED ADL2_Workstation_RAS_ErrorCounts_Reset (ADL_CONTEXT_HANDLE context,int iAdapterIndex); 

/// @}
#endif //__AMD_WORKSTATION_H__
