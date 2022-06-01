///
///  Copyright (c) 2008 - 2021 Advanced Micro Devices, Inc.
 
///  THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
///  EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
///  WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.

/// \file amd_displaysmanager.h
/// \brief Contains AMD Only Displays Manager-related functions exposed by ADL for \WIN platforms.
///
/// This file contains AMD Only Displays Manager function exposed by ADL for \WIN platforms.
/// All functions found in this file can be used as a reference to ensure
/// the specified function pointers can be used by the appropriate runtime
/// dynamic library loaders.

#ifndef AMD_DISPLAYSMANAGER_H_
#define AMD_DISPLAYSMANAGER_H_



#include "adl_structures.h"
#include "amd_structures.h"

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

///\addtogroup ADL_API
///\defgroup DISPLAYMNGR Displays Manager Related APIs
/// This group outlines the Displays Manager related APIs.

/// \addtogroup DISPLAYMNGRAPI
/// @{


/////////////////////////////////////////////////////////////////////////////
// 
// These APIs will be removed after their integration into the related new ones
//
/////////////////////////////////////////////////////////////////////////////

/// \brief A hidden function to return if workaroudn is needed in Win7 when 5- or 6-clone  is set
/// 
/// \platform
/// \Win7,WIN8
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in] iAdapterIndex		is the adapter index to consider
/// \return If the function succeeds and WorkaroundFor5Clone is needed, the return value is \ref ADL_TRUE. Otherwise the return value is \ref ADL_FALSE. \ref define_adl_results
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
ADL_EXTERNC int EXPOSED ADL2_Display_NeedWorkaroundFor5Clone_Get(ADL_CONTEXT_HANDLE context,int iAdapterIndex); 

/// \brief A hidden function to return if workaroudn is needed in Win7 when 5- or 6-clone  is set
/// 
/// \platform
/// \Win7,WIN8
/// \param[in] iAdapterIndex		is the adapter index to consider
/// \return If the function succeeds and WorkaroundFor5Clone is needed, the return value is \ref ADL_TRUE. Otherwise the return value is \ref ADL_FALSE. \ref define_adl_results
ADL_EXTERNC int EXPOSED ADL_Display_NeedWorkaroundFor5Clone_Get(int iAdapterIndex); 

///
/// \brief Function to set the current display configuration for swap operation.
/// 
/// This function sets the current display configurations for each display, including the controller and adapter mapped to each display. 
/// Possible display configurations are single, clone, extended desktop, and stretch mode. 
/// If clone mode is desired and the current display configuration is extended desktop mode, the function disables extended desktop mode in order to enable clone mode. 
/// If extended display mode is desired and the current display configuration is single mode, this function enables extended desktop.
/// \platform
/// \WIN
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in] iAdapterIndex The ADL index handle of the desired adapter. A value of -1 sets the displays in the system across multiple GPUs.
/// \param[in] iNumDisplayMap The number of display maps to be set.
/// \param[in] lpDisplayMap The pointer to the retrieved display map information. Refer to the ADLDisplayMap structure for more information.
/// \param[in] iNumDisplayTarget The number of display target sets to be set.
/// \param[in] lpDisplayTarget The pointer to the display target information. Refer to the ADLDisplayTarget structure for more information.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
///
/// \remarks This API uses the memory allocation callback function provided by the user.
/// \remarks Call ADL_Flush_Driver_Data() after to persist settings on reboot.
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
ADL_EXTERNC int EXPOSED ADL2_Display_DisplayMapConfigX2_Set  (ADL_CONTEXT_HANDLE context,int iAdapterIndex, 
                                                            int iNumDisplayMap, 
                                                            ADLDisplayMap* lpDisplayMap, 
                                                            int iNumDisplayTarget,  
                                                            ADLDisplayTarget* lpDisplayTarget);

/// @}
#endif /* AMD_DISPLAYSMANAGER_H_ */

