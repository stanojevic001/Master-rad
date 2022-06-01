///
///  Copyright (c) 2008 - 2021 Advanced Micro Devices, Inc.
 
///  THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
///  EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
///  WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.

/// \file amd_adapter.h
/// \brief Contains all AMD internal graphics-related functions exposed by ADL for \ALL platforms.
///
/// This file contains all AMD internal graphics-related functions exposed by ADL for \ALL platforms.
/// All functions found in this file can be used as a reference when creating
/// specific function pointers to be used by the appropriate runtime
/// dynamic library loaders.

#ifndef AMD_GRAPHICS_H_
#define AMD_GRAPHICS_H_

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


///
/// \brief For given ASIC returns GPU firmware version information.
/// \platform 
/// \WIN
/// \param[in]  context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter. The adapter identifies the ASIC that the information will be returned for.
/// \param[out]  gpuVerInfo The ADL structure that contains information about GPU firmware version information.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results 
ADL_EXTERNC int EXPOSED ADL2_GPUVerInfo_Get(ADL_CONTEXT_HANDLE context, int iAdapterIndex, ADLGPUVerInfo* gpuVerInfo);

#endif /* AMD_GRAPHICS_H_ */

