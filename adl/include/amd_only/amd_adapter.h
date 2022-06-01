///  Copyright (c) 2008 - 2021 Advanced Micro Devices, Inc.

///  THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
///  EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
///  WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.

/// \file amd_adapter.h
/// \brief Contains all AMD internal adapter-related functions exposed by ADL for \ALL platforms.
///
/// This file contains all AMD internal adapter-related functions exposed by ADL for \ALL platforms.
/// All functions in this file can be used as a reference to ensure
/// the specified function pointers can be used by the appropriate runtime
/// dynamic library loaders. This header file is for AMD internal use only.

#ifndef AMD_ADAPTER_H_
#define AMD_ADAPTER_H_

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

///\addtogroup ADAPTERAPI
/// @{
/// \brief Function to get Black and White level
///
/// The function is used to get Black and White level of display color.
/// 
/// \platform
/// \VISTAWIN7
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in]  iAdapterIndex			The ADL index handle of the desired adapter.
/// \param[out] lpCONTROLLERGAMMA  	    The pointer to the retrieved CONTROLLERGAMMA data structure.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
ADL_EXTERNC int EXPOSED ADL2_Adapter_Gamma_Get(ADL_CONTEXT_HANDLE context, int iAdapterIndex, ADLCONTROLLERGAMMA16* lpCONTROLLERGAMMA16 );

/// \brief Function to get Black and White level
///
/// The function is used to get Black and White level of display color.
/// 
/// \platform
/// \VISTAWIN7
/// \param[in]  iAdapterIndex			The ADL index handle of the desired adapter.
/// \param[out] lpCONTROLLERGAMMA  	    The pointer to the retrieved CONTROLLERGAMMA data structure.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
ADL_EXTERNC int EXPOSED ADL_Adapter_Gamma_Get( int iAdapterIndex, ADLCONTROLLERGAMMA16* lpCONTROLLERGAMMA16 );

/// \brief Function to set Black and White level
///
/// The function is used to set Black and White level of display color.
/// 
/// \platform
/// \VISTAWIN7
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in]  iAdapterIndex			The ADL index handle of the desired adapter.
/// \param[in]	lpCONTROLLERGAMMA		The pointer to the CONTROLLERGAMMA data structure to be set.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
ADL_EXTERNC int EXPOSED ADL2_Adapter_Gamma_Set(ADL_CONTEXT_HANDLE context, int iAdapterIndex, ADLCONTROLLERGAMMA16* lpCONTROLLERGAMMA16 );

/// \brief Function to set Black and White level
///
/// The function is used to set Black and White level of display color.
/// 
/// \platform
/// \VISTAWIN7
/// \param[in]  iAdapterIndex			The ADL index handle of the desired adapter.
/// \param[in]	lpCONTROLLERGAMMA		The pointer to the CONTROLLERGAMMA data structure to be set.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
ADL_EXTERNC int EXPOSED ADL_Adapter_Gamma_Set( int iAdapterIndex, ADLCONTROLLERGAMMA16* lpCONTROLLERGAMMA16 );

/// \brief Function to check if Black and White level functionality is supported
///
/// The function is used to check if Black and White level functionality is supported.
/// 
/// \platform
/// \VISTAWIN7
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in]  iAdapterIndex			        The ADL index handle of the desired adapter.
/// \param[out] lpBlackAndWhiteLevelSupport  	The pointer to the BlackAndWhite support level. 1 for supported and 0 for unsupported
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
ADL_EXTERNC int EXPOSED ADL2_Adapter_BlackAndWhiteLevelSupport_Get(ADL_CONTEXT_HANDLE context, int iAdapterIndex, int* lpBlackAndWhiteLevelSupport);

/// \brief Function to check if Black and White level functionality is supported
///
/// The function is used to check if Black and White level functionality is supported.
/// 
/// \platform
/// \VISTAWIN7
/// \param[in]  iAdapterIndex			        The ADL index handle of the desired adapter.
/// \param[out] lpBlackAndWhiteLevelSupport  	The pointer to the BlackAndWhite support level. 1 for supported and 0 for unsupported
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
ADL_EXTERNC int EXPOSED ADL_Adapter_BlackAndWhiteLevelSupport_Get( int iAdapterIndex, int* lpBlackAndWhiteLevelSupport);

/// \brief Function to get Black and White level
///
/// The function is used to get Black and White level of display color.
/// 
/// \platform
/// \VISTAWIN7
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in]  iAdapterIndex			The ADL index handle of the desired adapter.
/// \param[out] lpBlackAndWhiteLevel  	The pointer to the BlackAndWhite level. 1 for limited range and 0 for full range
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
ADL_EXTERNC int EXPOSED ADL2_Adapter_BlackAndWhiteLevel_Get(ADL_CONTEXT_HANDLE context, int iAdapterIndex, int* lpBlackAndWhiteLevel);

/// \brief Function to get Black and White level
///
/// The function is used to get Black and White level of display color.
/// 
/// \platform
/// \VISTAWIN7
/// \param[in]  iAdapterIndex			The ADL index handle of the desired adapter.
/// \param[out] lpBlackAndWhiteLevel  	The pointer to the BlackAndWhite level. 1 for limited range and 0 for full range
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
ADL_EXTERNC int EXPOSED ADL_Adapter_BlackAndWhiteLevel_Get( int iAdapterIndex, int* lpBlackAndWhiteLevel);

/// \brief Function to set Black and White level
///
/// The function is used to set Black and White level of display color.
/// 
/// \platform
/// \VISTAWIN7
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in]  iAdapterIndex			The ADL index handle of the desired adapter.
/// \param[in]	iBlackAndWhiteLevel		The BlackAndWhite level to be set.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
ADL_EXTERNC int EXPOSED ADL2_Adapter_BlackAndWhiteLevel_Set(ADL_CONTEXT_HANDLE context, int iAdapterIndex, int iBlackAndWhiteLevel);

/// \brief Function to set Black and White level
///
/// The function is used to set Black and White level of display color.
/// 
/// \platform
/// \VISTAWIN7
/// \param[in]  iAdapterIndex			The ADL index handle of the desired adapter.
/// \param[in]	iBlackAndWhiteLevel		The BlackAndWhite level to be set.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
ADL_EXTERNC int EXPOSED ADL_Adapter_BlackAndWhiteLevel_Set( int iAdapterIndex, int iBlackAndWhiteLevel);

///
/// \brief ADL local interface. Function to retrieve ASIC information.
/// 
/// This function retrieves the ASIC information for a specified adapter.
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[out] lpAsicInfo The pointer to the structure storing the retrieved ASIC information.
/// \platform 
/// \LNX
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
ADL_EXTERNC int EXPOSED ADL2_Adapter_ASICInfo_Get(ADL_CONTEXT_HANDLE context, int iAdapterIndex, ADLASICInfo* lpAsicInfo );

///
/// \brief ADL local interface. Function to retrieve ASIC information.
/// 
/// This function retrieves the ASIC information for a specified adapter.
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[out] lpAsicInfo The pointer to the structure storing the retrieved ASIC information.
/// \platform 
/// \LNX
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
ADL_EXTERNC int EXPOSED ADL_Adapter_ASICInfo_Get( int iAdapterIndex, ADLASICInfo* lpAsicInfo );

///
/// \brief ADL local interface. Function to retrieve software information.
/// 
/// This function retrieves the software information for a specified adapter.
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[out]  lpSWInfo The pointer to the structure storing the retrieved software information.
/// \platform 
/// \LNX
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
ADL_EXTERNC int EXPOSED ADL2_Adapter_SWInfo_Get(ADL_CONTEXT_HANDLE context, int iAdapterIndex, ADLSWInfo * lpSWInfo );

///
/// \brief ADL local interface. Function to retrieve software information.
/// 
/// This function retrieves the software information for a specified adapter.
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[out]  lpSWInfo The pointer to the structure storing the retrieved software information.
/// \platform 
/// \LNX
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
ADL_EXTERNC int EXPOSED ADL_Adapter_SWInfo_Get(int iAdapterIndex, ADLSWInfo * lpSWInfo);

///
/// \brief Retrieves additional adapter information
///
/// This function retreives extended adapter information for a particular adapter
/// \platform
/// \LNX
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in] iAdapterIndex The ADL index of the desired adapter to query the extended information
/// \param[out] lpExtInfo A pointer to an empty memory buffer(NULL). This function will allocate callback function to allocate the appropriate memory size. This buffer will contain the reteieved extended adapter information.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADLerror code. \ref define_adl_results
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
ADL_EXTERNC int EXPOSED ADL2_Adapter_ExtInfo_Get(ADL_CONTEXT_HANDLE context,int iAdapterIndex, LPAdapterExtInfo *lppExtInfo);

///
/// \brief Retrieves additional adapter information
///
/// This function retreives extended adapter information for a particular adapter
/// \platform
/// \LNX
/// \param[in] iAdapterIndex The ADL index of the desired adapter to query the extended information
/// \param[out] lpExtInfo A pointer to an empty memory buffer(NULL). This function will allocate callback function to allocate the appropriate memory size. This buffer will contain the reteieved extended adapter information.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADLerror code. \ref define_adl_results
ADL_EXTERNC int EXPOSED ADL_Adapter_ExtInfo_Get(int iAdapterIndex, LPAdapterExtInfo *lppExtInfo);

///\addtogroup MULTIGPUAPI
/// @{
///
/// \brief Function to retrieve Multi GPU chain capabilities of the GPU.
/// This function is used to determine if the GPU is capable of participating in a Multi GPU chain, regardless if the system is setup properly.
/// \platform
/// \LNX
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in]          iAdapterIndex The ADL index handle of the desired adapter to query Multi GPU chain capabilities
/// \param[out]       lpValidCaps The valid bits in lpCaps
/// \param[out]       lpCaps The capabilities of adapter
/// \return If the function succeeds, the return value is \ref ADL_OK (zero). Otherwise the return value is an ADL error code (non-zero). \ref define_adl_results
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
ADL_EXTERNC int EXPOSED ADL2_Adapter_MultiGPU_Caps (ADL_CONTEXT_HANDLE context,int iAdapterIndex, int* lpValidCaps, int* lpCaps);

///
/// \brief Function to retrieve Multi GPU chain capabilities of the GPU.
/// This function is used to determine if the GPU is capable of participating in a Multi GPU chain, regardless if the system is setup properly.
/// \platform
/// \LNX
/// \param[in]          iAdapterIndex The ADL index handle of the desired adapter to query Multi GPU chain capabilities
/// \param[out]       lpValidCaps The valid bits in lpCaps
/// \param[out]       lpCaps The capabilities of adapter
/// \return If the function succeeds, the return value is \ref ADL_OK (zero). Otherwise the return value is an ADL error code (non-zero). \ref define_adl_results
ADL_EXTERNC int EXPOSED ADL_Adapter_MultiGPU_Caps (int iAdapterIndex, int* lpValidCaps, int* lpCaps);

/// \brief Function to get all supported Multi GPU chain combinations.
/// This function is used to retrieve a list of all supported Multi GPU chain combinations for an adapter.
/// \platform
/// \LNX
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in]          iAdapterIndex The ADL index handle of the desired adapter to query Multi GPU chain capabilities
/// \param[in]          iOption This option indicates which Multi GPU feature user needs to retrieve configuration for.  Input is one of the Multi GPU cap defines \ref define_multiGPU_caps
/// \param[out]       lpPreferred The index of the preferred Multi GPU chain. The index is a zero based index reference in the ppMultiGPUComb list.
/// \param[out]       lpNumComb The integer value indicating the number of ADLMultiGPUComb structures in the ppMultiGPUComb buffer
/// \param[out]       ADLMultiGPUComb ** ppMultiGPUComb The Pointer to an empty memory buffer(NULL).  This function will use the callback to allocate the appropriate buffer size.  This buffer will contain a list of supported Multi GPU chain combinations if the adapter supports Multi GPU chain.  If the adapter does not support Multi GPU chain, this memory buffer will remain empty, or NULL.
/// \return If the function succeeds, the return value is \ref ADL_OK (zero). Otherwise the return value is an ADL error code (non-zero). \ref define_adl_results
/// \remarks This API uses the memory allocation callback function provided by the user.
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
ADL_EXTERNC int EXPOSED ADL2_Adapter_MultiGPUCombList_Get (ADL_CONTEXT_HANDLE context,int iAdapterIndex, int iOption, int* lpPreferred, int* lpNumComb, ADLMultiGPUComb ** ppMultiGPUComb);

/// \brief Function to get all supported Multi GPU chain combinations.
/// This function is used to retrieve a list of all supported Multi GPU chain combinations for an adapter.
/// \platform
/// \LNX
/// \param[in]          iAdapterIndex The ADL index handle of the desired adapter to query Multi GPU chain capabilities
/// \param[in]          iOption This option indicates which Multi GPU feature user needs to retrieve configuration for.  Input is one of the Multi GPU cap defines \ref define_multiGPU_caps
/// \param[out]       lpPreferred The index of the preferred Multi GPU chain. The index is a zero based index reference in the ppMultiGPUComb list.
/// \param[out]       lpNumComb The integer value indicating the number of ADLMultiGPUComb structures in the ppMultiGPUComb buffer
/// \param[out]       ADLMultiGPUComb ** ppMultiGPUComb The Pointer to an empty memory buffer(NULL).  This function will use the callback to allocate the appropriate buffer size.  This buffer will contain a list of supported Multi GPU chain combinations if the adapter supports Multi GPU chain.  If the adapter does not support Multi GPU chain, this memory buffer will remain empty, or NULL.
/// \return If the function succeeds, the return value is \ref ADL_OK (zero). Otherwise the return value is an ADL error code (non-zero). \ref define_adl_results
/// \remarks This API uses the memory allocation callback function provided by the user.
ADL_EXTERNC int EXPOSED ADL_Adapter_MultiGPUCombList_Get (int iAdapterIndex, int iOption, int* lpPreferred, int* lpNumComb, ADLMultiGPUComb ** ppMultiGPUComb);

/// \brief Function to get current Multi GPU combination settings.
/// This function is used to retrieve the current information about a particular Multi GPU combination.  A Multi GPU combination includes
/// the Multi GPU capable adapter and its Multi GPU chain (a list of other adapters that will work with the Multi GPU capable adapter).  The possible
/// Multi GPU chain combinations for an adapter is retrieved from the ADL_Adapter_MultiGPUCombList_Get function.
/// \platform
/// \ALL
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in]          iAdapterIndex The ADL index of the Multi GPU capable adapter to query the Multi GPU state and current information
/// \param[in]          iOption This option indicates which Multi GPU feature user needs to retrieve configuration for.  Input is one of the Multi GPU cap defines \ref define_multiGPU_caps
/// \param[in]          lpMultiGPUComb The Multi GPU chains to get information about.
/// \param[out]       lpMultiGPUInfo State and error information about the Multi GPU combination.
/// \return If the function succeeds, the return value is \ref ADL_OK (zero). Otherwise the return value is an ADL error code (non-zero). \ref define_adl_results
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
ADL_EXTERNC int EXPOSED ADL2_Adapter_MultiGPU_Get (ADL_CONTEXT_HANDLE context,int iAdapterIndex, int iOption, ADLMultiGPUComb * lpMultiGPUComb, ADLMultiGPUInfo * lpMultiGPUInfo);

/// \brief Function to get current Multi GPU combination settings.
/// This function is used to retrieve the current information about a particular Multi GPU combination.  A Multi GPU combination includes
/// the Multi GPU capable adapter and its Multi GPU chain (a list of other adapters that will work with the Multi GPU capable adapter).  The possible
/// Multi GPU chain combinations for an adapter is retrieved from the ADL_Adapter_MultiGPUCombList_Get function.
/// \platform
/// \ALL
/// \param[in]          iAdapterIndex The ADL index of the Multi GPU capable adapter to query the Multi GPU state and current information
/// \param[in]          iOption This option indicates which Multi GPU feature user needs to retrieve configuration for.  Input is one of the Multi GPU cap defines \ref define_multiGPU_caps
/// \param[in]          lpMultiGPUComb The Multi GPU chains to get information about.
/// \param[out]       lpMultiGPUInfo State and error information about the Multi GPU combination.
/// \return If the function succeeds, the return value is \ref ADL_OK (zero). Otherwise the return value is an ADL error code (non-zero). \ref define_adl_results
ADL_EXTERNC int EXPOSED ADL_Adapter_MultiGPU_Get (int iAdapterIndex, int iOption, ADLMultiGPUComb * lpMultiGPUComb, ADLMultiGPUInfo * lpMultiGPUInfo);

/// \brief Function to set Multi GPU combination settings.
/// This function is used to enable or disable Multi GPU on a particular adapter (pointed to by iAdapterIndex), along with the indicated Multi GPU chain.
/// The Multi GPU chain combination for the adapter must be one returned by the ADL_Adapter_MultiGPUCombList_Get function.
/// \platform
/// \ALL
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in]          iAdapterIndex The adapter in which to enable or disable Multi GPU
/// \param[in]          iOption This option indicates which Multi GPU feature user needs to set configuration for.  Input is one of the Multi GPU cap defines \ref define_multiGPU_caps
/// \param[in]          lpMultiGPUComb the MultiGPU chain combination to enable or disable for the master adapter.  If this parameter is not NULL, it will
/// enable Multi GPU with the indicated combination.  If this parameter is NULL, it will disable Multi GPU on that particular adapter.
/// \return If the function succeeds, the return value is \ref ADL_OK (zero). Otherwise the return value is an ADL error code (non-zero). \ref define_adl_results
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
ADL_EXTERNC int EXPOSED ADL2_Adapter_MultiGPU_Set (ADL_CONTEXT_HANDLE context,int iAdapterIndex, int iOption, ADLMultiGPUComb * lpMultiGPUComb);

/// \brief Function to set Multi GPU combination settings.
/// This function is used to enable or disable Multi GPU on a particular adapter (pointed to by iAdapterIndex), along with the indicated Multi GPU chain.
/// The Multi GPU chain combination for the adapter must be one returned by the ADL_Adapter_MultiGPUCombList_Get function.
/// \platform
/// \ALL
/// \param[in]          iAdapterIndex The adapter in which to enable or disable Multi GPU
/// \param[in]          iOption This option indicates which Multi GPU feature user needs to set configuration for.  Input is one of the Multi GPU cap defines \ref define_multiGPU_caps
/// \param[in]          lpMultiGPUComb the MultiGPU chain combination to enable or disable for the master adapter.  If this parameter is not NULL, it will
/// enable Multi GPU with the indicated combination.  If this parameter is NULL, it will disable Multi GPU on that particular adapter.
/// \return If the function succeeds, the return value is \ref ADL_OK (zero). Otherwise the return value is an ADL error code (non-zero). \ref define_adl_results
ADL_EXTERNC int EXPOSED ADL_Adapter_MultiGPU_Set (int iAdapterIndex, int iOption, ADLMultiGPUComb * lpMultiGPUComb);

/// 
/// \brief Checks if given desktop (identified by adapter id) is currently in exclusive full screen mode
///
/// Checks if given desktop (identified by adapter id) is currently in exclusive full screen mode
/// \platform
/// \WIN
/// \param[in] context			: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in] iAdapterIndex    : The ADL index handle of the desired adapter.
/// \param[out]iIsExclusive		: Will be set to 1 to indicate that given desktop is currently in full screan exclusive mode
ADL_EXTERNC int EXPOSED ADL2_ExclusiveModeGet(ADL_CONTEXT_HANDLE context, int iAdapterIndex, int* iIsExclusive);
/// @}

///
/// \brief Checks if given GPU (identified by adapter id) supports DVR functionality or not
///
/// Checks if given GPU (identified by adapter id) supports DVR functionality or not
/// \platform
/// \WIN
/// \param[in] context			: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in] iAdapterIndex    : The ADL index handle of the desired adapter.
/// \param[out]iIsDVRSupported	: Will be set to 1 to indicate that given GPU supports DVR functionality
ADL_EXTERNC int EXPOSED ADL2_DVRSupport_Get(ADL_CONTEXT_HANDLE context, int iAdapterIndex, int* iIsDVRSupported);

/// @}

///
/// \brief Checks if given GPU (identified by adapter id) supports the driver upscale functionality or not
///
/// Checks if given GPU (identified by adapter id) supports driver upscale functionality or not
/// \platform
/// \WIN
/// \param[in] context			: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in] iAdapterIndex    : The ADL index handle of the desired adapter.
/// \param[out]iDriverUpscaleSupported	: Will be set to 1 to indicate that given GPU supports driver upscale functionality
ADL_EXTERNC int EXPOSED ADL2_DriverUpscaleSupport_Get(ADL_CONTEXT_HANDLE context, int iAdapterIndex, int* iDriverUpscaleSupported);

/// @}

///
/// \brief Function to retrieve adapter limitation information.
/// 
/// This function implements a DI call to retrieve adapter limitation information .
/// \platform
/// \ALL
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[out] lpAdapterLimitationCaps The pointer to the structure storing the retrieved adapter limitation information.
/// \return If the function succeeds, the return value is \ref ADL_OK, or an ADL error code otherwise. \ref define_adl_results
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
ADL_EXTERNC int EXPOSED ADL2_AdapterLimitation_Caps(ADL_CONTEXT_HANDLE context,int iAdapterIndex,  ADLAdapterLimitationCaps *lpAdapterLimitationCaps);

///
/// \brief Function to retrieve adapter limitation information.
/// 
/// This function implements a DI call to retrieve adapter limitation information .
/// \platform
/// \ALL
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[out] lpAdapterLimitationCaps The pointer to the structure storing the retrieved adapter limitation information.
/// \return If the function succeeds, the return value is \ref ADL_OK, or an ADL error code otherwise. \ref define_adl_results
ADL_EXTERNC int EXPOSED ADL_AdapterLimitation_Caps(int iAdapterIndex,  ADLAdapterLimitationCaps *lpAdapterLimitationCaps);

///
///\brief Function to retrieve the current driver audio channel splitting configuration on a given adapter
/// 
/// This function retrieves the current driver audio channel splitting configuration on a given adapter.
/// When channel splitting is disabled, the configuration comes from the EDID with the speaker allocation.
/// \platform
/// \WIN
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in]   iAdapterIndex The ADL index handle of the desired adapter per physical GPU.
/// \param[out]  *lpAudioChannelSplitConfig The pointer to the structure that contains information about audio channel split configuration.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
ADL_EXTERNC int EXPOSED ADL2_Adapter_AudioChannelSplitConfiguration_Get(ADL_CONTEXT_HANDLE context,int iAdapterIndex, ADLAudioChannelSplitSetting* lpAudioChannelSplitConfig);

///
///\brief Function to retrieve the current driver audio channel splitting configuration on a given adapter
/// 
/// This function retrieves the current driver audio channel splitting configuration on a given adapter.
/// When channel splitting is disabled, the configuration comes from the EDID with the speaker allocation.
/// \platform
/// \WIN
/// \param[in]   iAdapterIndex The ADL index handle of the desired adapter per physical GPU.
/// \param[out]  *lpAudioChannelSplitConfig The pointer to the structure that contains information about audio channel split configuration.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
ADL_EXTERNC int EXPOSED ADL_Adapter_AudioChannelSplitConfiguration_Get(int iAdapterIndex, ADLAudioChannelSplitSetting* lpAudioChannelSplitConfig);

///
///\brief Function to enable multi channel splitting on a given adapter with enable only and save profile only options
/// 
/// This function enables multi channel splitting on a given adapter with enable only and save profile only options
/// \platform
/// \WIN
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in]   iAdapterIndex The ADL index handle of the desired adapter per physical GPU.
/// \param[in]  *lpAdapterAudioChannelSplitRequest The pointer to the structure that contains information about audio channel split configuration.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
ADL_EXTERNC int EXPOSED ADL2_Adapter_AudioChannelSplit_Enable(ADL_CONTEXT_HANDLE context,int iAdapterIndex, ADLAudioChannelSplitSetting* lpAudioChannelSplitRequest);

///
///\brief Function to enable multi channel splitting on a given adapter with enable only and save profile only options
/// 
/// This function enables multi channel splitting on a given adapter with enable only and save profile only options
/// \platform
/// \WIN
/// \param[in]   iAdapterIndex The ADL index handle of the desired adapter per physical GPU.
/// \param[in]  *lpAdapterAudioChannelSplitRequest The pointer to the structure that contains information about audio channel split configuration.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
ADL_EXTERNC int EXPOSED ADL_Adapter_AudioChannelSplit_Enable(int iAdapterIndex, ADLAudioChannelSplitSetting* lpAudioChannelSplitRequest);

///
///\brief Function to disable multi channel splitting on a given adapter
/// 
/// This function disables multi channel splitting on a given adapter
/// \platform
/// \WIN
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in]   iAdapterIndex The ADL index handle of the desired adapter per physical GPU.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
ADL_EXTERNC int EXPOSED ADL2_Adapter_AudioChannelSplit_Disable(ADL_CONTEXT_HANDLE context,int iAdapterIndex);

///
///\brief Function to disable multi channel splitting on a given adapter
/// 
/// This function disables multi channel splitting on a given adapter
/// \platform
/// \WIN
/// \param[in]   iAdapterIndex The ADL index handle of the desired adapter per physical GPU.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
ADL_EXTERNC int EXPOSED ADL_Adapter_AudioChannelSplit_Disable(int iAdapterIndex);

///
///\brief Function to retrieve the audio information and speaker allocation from a display's EDID
/// 
/// This function retrieves the audio information and speaker allocation from a display's EDID.
/// \platform
/// \WIN
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in] iAdapterIndex The ADL index handle of the desired adapter per physical GPU.
/// \param[in] displayIdentifier The display identifier
/// \param[out] The pointer to the structure that contains information about audio and speaker allocation from a display's EDID
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
ADL_EXTERNC int EXPOSED ADL2_Adapter_DisplayAudioInfo_Get(ADL_CONTEXT_HANDLE context,int iAdapterIndex, ADLDisplayIdentifier displayIdentifier, ADLDisplayAudioInfo* lpDisplayAudioInfo);

///
///\brief Function to retrieve the audio information and speaker allocation from a display's EDID
/// 
/// This function retrieves the audio information and speaker allocation from a display's EDID.
/// \platform
/// \WIN
/// \param[in] iAdapterIndex The ADL index handle of the desired adapter per physical GPU.
/// \param[in] displayIdentifier The display identifier
/// \param[out] The pointer to the structure that contains information about audio and speaker allocation from a display's EDID
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
ADL_EXTERNC int EXPOSED ADL_Adapter_DisplayAudioInfo_Get(int iAdapterIndex, ADLDisplayIdentifier displayIdentifier, ADLDisplayAudioInfo* lpDisplayAudioInfo);

///
///\brief Function to enable Azalia audio end point on a given display
/// 
/// This function enables Azalia audio end point on a given display
/// \platform
/// \WIN
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in] iAdapterIndex The ADL index handle of the desired adapter per physical GPU.
/// \param[in] displayIdentifier The display identifier
/// \param[in] enable Set to true if audio end point is to be enabled. Set to false if audio end point is to be disabled
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
ADL_EXTERNC int EXPOSED ADL2_Adapter_DisplayAudioEndpoint_Enable(ADL_CONTEXT_HANDLE context,int iAdapterIndex, ADLDisplayIdentifier displayIdentifier, int enable);

///
///\brief Function to enable Azalia audio end point on a given display
/// 
/// This function enables Azalia audio end point on a given display
/// \platform
/// \WIN
/// \param[in] iAdapterIndex The ADL index handle of the desired adapter per physical GPU.
/// \param[in] displayIdentifier The display identifier
/// \param[in] enable Set to true if audio end point is to be enabled. Set to false if audio end point is to be disabled
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
ADL_EXTERNC int EXPOSED ADL_Adapter_DisplayAudioEndpoint_Enable(int iAdapterIndex, ADLDisplayIdentifier displayIdentifier, int enable);

///
///\brief Function to mute Azalia audio end point on a given display
/// 
/// This function mutes Azalia audio end point on a given display
/// \platform
/// \WIN
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in] iAdapterIndex The ADL index handle of the desired adapter per physical GPU.
/// \param[in] displayIdentifier The display identifier
/// \param[in] mute Set to true if audio end point is to be muted. Set to false if audio end point is to be unmuted
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
ADL_EXTERNC int EXPOSED ADL2_Adapter_DisplayAudioEndpoint_Mute(ADL_CONTEXT_HANDLE context,int iAdapterIndex, ADLDisplayIdentifier displayIdentifier, int mute);

///
///\brief Function to mute Azalia audio end point on a given display
/// 
/// This function mutes Azalia audio end point on a given display
/// \platform
/// \WIN
/// \param[in] iAdapterIndex The ADL index handle of the desired adapter per physical GPU.
/// \param[in] displayIdentifier The display identifier
/// \param[in] mute Set to true if audio end point is to be muted. Set to false if audio end point is to be unmuted
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
ADL_EXTERNC int EXPOSED ADL_Adapter_DisplayAudioEndpoint_Mute(int iAdapterIndex, ADLDisplayIdentifier displayIdentifier, int mute);

///
///\brief Function to check whether the Mirabilis feature is supported
/// 
/// This function checks whether the Mirabilis feature is supported
/// \platform
/// \WIN
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in] iAdapterIndex The ADL index handle of the desired adapter per physical GPU.
/// \param[out] lpSupported *lpSupported is 1 if feature is supported
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
ADL_EXTERNC int EXPOSED ADL2_Adapter_MirabilisSupport_Get(ADL_CONTEXT_HANDLE context,int iAdapterIndex, int* lpSupported);

///
///\brief Function to check whether the Mirabilis feature is supported
/// 
/// This function checks whether the Mirabilis feature is supported
/// \platform
/// \WIN
/// \param[in] iAdapterIndex The ADL index handle of the desired adapter per physical GPU.
/// \param[out] lpSupported *lpSupported is 1 if feature is supported
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
ADL_EXTERNC int EXPOSED ADL_Adapter_MirabilisSupport_Get(int iAdapterIndex, int* lpSupported);

///
///\brief Function to check for GTC capability for the displays
/// 
/// This function checks for GTC capability for the displays
/// \platform
/// \WIN
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in] iAdapterIndex The ADL index handle of the desired adapter per physical GPU.
/// \param[in] displayIdentifier The display identifier
/// \param[out] pGtcInfo The pointer to the structure that contains information about GTC capability for the displays
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
ADL_EXTERNC int EXPOSED ADL2_Adapter_DisplayGTCCaps_Get(ADL_CONTEXT_HANDLE context,int iAdapterIndex, ADLDisplayIdentifier displayIdentifier, ADLGtcInfo *pGtcInfo);

///
///\brief Function to check for GTC capability for the displays
/// 
/// This function checks for GTC capability for the displays
/// \platform
/// \WIN
/// \param[in] iAdapterIndex The ADL index handle of the desired adapter per physical GPU.
/// \param[in] displayIdentifier The display identifier
/// \param[out] pGtcInfo The pointer to the structure that contains information about GTC capability for the displays
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
ADL_EXTERNC int EXPOSED ADL_Adapter_DisplayGTCCaps_Get(int iAdapterIndex, ADLDisplayIdentifier displayIdentifier, ADLGtcInfo *pGtcInfo);

///
///\brief Function to load the default audio channel mapping based on known SLS configuration
/// 
/// This function loads the default audio channel mapping based on known SLS configuration
/// \platform
/// \WIN
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in] iAdapterIndex The ADL index handle of the desired adapter per physical GPU.
/// \param[in] iRow the number of rows in the SLS configuration. This information is used to find the default audio configuration from the table
/// \param[in] iColumn the number of columns in the SLS configuration. This information is used to find the default audio configuration from the table
/// \param[in] allowDuplicateChannelMapping true if load GTC default audio mapping. Otherwise, load non GTC default mapping
/// \param[out] lppDisplayAudioChannelMapping The pointer to a list of ADLDisplayAudioChannelMapping structure objects
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
ADL_EXTERNC int EXPOSED ADL2_Adapter_DefaultAudioChannelTable_Load(ADL_CONTEXT_HANDLE context,int iAdapterIndex, int iRow, int iColumn, int allowDuplicateChannelMapping, ADLDisplayChannelMapping **lppDisplayAudioChannelMapping);

///
///\brief Function to load the default audio channel mapping based on known SLS configuration
/// 
/// This function loads the default audio channel mapping based on known SLS configuration
/// \platform
/// \WIN
/// \param[in] iAdapterIndex The ADL index handle of the desired adapter per physical GPU.
/// \param[in] iRow the number of rows in the SLS configuration. This information is used to find the default audio configuration from the table
/// \param[in] iColumn the number of columns in the SLS configuration. This information is used to find the default audio configuration from the table
/// \param[in] allowDuplicateChannelMapping true if load GTC default audio mapping. Otherwise, load non GTC default mapping
/// \param[out] lppDisplayAudioChannelMapping The pointer to a list of ADLDisplayAudioChannelMapping structure objects
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
ADL_EXTERNC int EXPOSED ADL_Adapter_DefaultAudioChannelTable_Load(int iAdapterIndex, int iRow, int iColumn, int allowDuplicateChannelMapping, ADLDisplayChannelMapping **lppDisplayAudioChannelMapping);

///
///\brief Function to get the current audio sample rate
/// 
/// This function retrieves the current audio sample rate
/// \platform
/// \WIN
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[out] lpSampleRate The pointer to the current audio sample rate
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
ADL_EXTERNC int EXPOSED ADL2_Audio_CurrentSampleRate_Get(ADL_CONTEXT_HANDLE context,int *lpSampleRate);

///
///\brief Function to get the current audio sample rate
/// 
/// This function retrieves the current audio sample rate
/// \platform
/// \WIN
/// \param[out] lpSampleRate The pointer to the current audio sample rate
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results

ADL_EXTERNC int EXPOSED ADL_Audio_CurrentSampleRate_Get(int *lpSampleRate);

///
///\brief Function to set the audio delays for all channels for a given sample rate
/// 
/// This function sets the audio delays for all channels for a given sample rate
/// \platform
/// \WIN
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in] iAdapterIndex The ADL index handle of the desired adapter.
/// \param[in] lpAudioDelay pointer to the structure that contains the audio delays for all channels for a given sample rate
/// \param[out] none
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
ADL_EXTERNC int EXPOSED ADL2_APO_AudioDelay_Set(ADL_CONTEXT_HANDLE context,int iAdapterIndex, ADLAudioDelayPerSampleRate* lpAudioDelay);

///
///\brief Function to set the audio delays for all channels for a given sample rate
/// 
/// This function sets the audio delays for all channels for a given sample rate
/// \platform
/// \WIN
/// \param[in] iAdapterIndex The ADL index handle of the desired adapter.
/// \param[in] lpAudioDelay pointer to the structure that contains the audio delays for all channels for a given sample rate
/// \param[out] none
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
ADL_EXTERNC int EXPOSED ADL_APO_AudioDelay_Set(int iAdapterIndex, ADLAudioDelayPerSampleRate* lpAudioDelay);

///
///\brief Function to set the audio delays for all channels for the current sample rate
/// 
/// This function sets the audio delays for all channels for the current sample rate
/// \platform
/// \WIN
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[in] lpAllAudioDelays pointer to the structure that contains the audio delays for all channels for all sample rates
/// \param[out] none
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
ADL_EXTERNC int EXPOSED ADL2_APO_AudioDelay_Restore(ADL_CONTEXT_HANDLE context,int iAdapterIndex, ADLApoAudioDelay* lpAllAudioDelays);

///
///\brief Function to set the audio delays for all channels for the current sample rate
/// 
/// This function sets the audio delays for all channels for the current sample rate
/// \platform
/// \WIN
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[in] lpAllAudioDelays pointer to the structure that contains the audio delays for all channels for all sample rates
/// \param[out] none
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
ADL_EXTERNC int EXPOSED ADL_APO_AudioDelay_Restore(int iAdapterIndex, ADLApoAudioDelay* lpAllAudioDelays);

///
///\brief Function to retrieve the information about the range of audio delay adjustments
/// 
/// This function retrieves the information about the range of audio delay adjustments
/// \platform
/// \WIN
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in] none
/// \param[out] lpAudioDelayRangeInfo pointer to the structure that contains the information about the range of audio delay adjustments
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
ADL_EXTERNC int EXPOSED ADL2_APO_AudioDelayAdjustmentInfo_Get(ADL_CONTEXT_HANDLE context,ADLApoAudioDelayRangeInfo* lpAudioDelayRangeInfo);

///
///\brief Function to retrieve the information about the range of audio delay adjustments
/// 
/// This function retrieves the information about the range of audio delay adjustments
/// \platform
/// \WIN
/// \param[in] none
/// \param[out] lpAudioDelayRangeInfo pointer to the structure that contains the information about the range of audio delay adjustments
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
ADL_EXTERNC int EXPOSED ADL_APO_AudioDelayAdjustmentInfo_Get(ADLApoAudioDelayRangeInfo* lpAudioDelayRangeInfo);

/// \brief Function to retrieve max hardware cursor size.
/// 
/// This function implements a call to retrieve max hardware cursor size.
/// \platform
/// \VISTAWIN7
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[out] lpCursorWidth The pointer to width of the max hardware cursor size.
/// \param[out] lpCursorHeight The pointer to height of the max hardware cursor size.
/// \return If the function succeeds, the return value is \ref ADL_OK, or an ADL error code otherwise. \ref define_adl_results
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
ADL_EXTERNC int EXPOSED ADL2_Adapter_MaxCursorSize_Get(ADL_CONTEXT_HANDLE context,int iAdapterIndex, int *lpCursorWidth, int *lpCursorHeight); 

/// \brief Function to retrieve max hardware cursor size.
/// 
/// This function implements a call to retrieve max hardware cursor size.
/// \platform
/// \VISTAWIN7
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[out] lpCursorWidth The pointer to width of the max hardware cursor size.
/// \param[out] lpCursorHeight The pointer to height of the max hardware cursor size.
/// \return If the function succeeds, the return value is \ref ADL_OK, or an ADL error code otherwise. \ref define_adl_results
ADL_EXTERNC int EXPOSED ADL_Adapter_MaxCursorSize_Get(int iAdapterIndex, int *lpCursorWidth, int *lpCursorHeight); 

/// \brief Function to retrieve the Local Display On/Off state.
///
/// This function implements a call to retrieve the Local Display On/Off state.
/// \platform
/// \LNX
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[out] lpState The pointer to value storing the On/Off state.  ADL_TRUE if Local Display is on.  ADL_FALSE if Local Display is Off.
/// \return If the function succeeds, the return value is \ref ADL_OK, or an ADL error code otherwise. \ref define_adl_results
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
/// \deprecated This API has been deprecated.
ADL_EXTERNC int EXPOSED ADL2_Adapter_LocalDisplayState_Get(ADL_CONTEXT_HANDLE context,int iAdapterIndex, int *lpState);

/// \brief Function to retrieve the Local Display On/Off state.
///
/// This function implements a call to retrieve the Local Display On/Off state.
/// \platform
/// \LNX
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[out] lpState The pointer to value storing the On/Off state.  ADL_TRUE if Local Display is on.  ADL_FALSE if Local Display is Off.
/// \return If the function succeeds, the return value is \ref ADL_OK, or an ADL error code otherwise. \ref define_adl_results
/// \deprecated This API has been deprecated.
ADL_EXTERNC int EXPOSED ADL_Adapter_LocalDisplayState_Get(int iAdapterIndex, int *lpState);

///
/// \brief Function to retrieve LocalDisplay support settings.
/// 
/// This function implements a DI call to retrieve LocalDisplay support settings. 
/// \platform
/// \ALL
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in]  iAdapterIndex				The ADL index handle of the desired adapter.
/// \param[in]  iNumSlaves					The number of slave adapters to query local display support with (for PX system the number is 1). </param>
/// \param[in]  lpSlaveBDFList				The list of slave adapter BDFs. </param>
/// \param[out] lpMinNumLocalDisplays		Minimum number of supported local displays (per slave). </param>
/// \param[out] lppMaxNumLocalDisplaysList	Maximum number of supported local displays (per slave) in the same order as input 'slaveBDFList'. </param>
/// \param[out] lpDefaultNumLocalDisplays	Default number of supported local displays (per slave). </param>
/// \param[out] lpCurrentNumLocalDisplays	Current number of supported local displays (per slave). </param>
/// \return If the function succeeds, the return value is \ref ADL_OK, or an ADL error code otherwise.  \ref define_adl_results
/// \deprecated This API has been deprecated.
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
ADL_EXTERNC int EXPOSED ADL2_Adapter_LocalDisplayConfig_Get(ADL_CONTEXT_HANDLE context,int iAdapterIndex,
                                                            int iNumSlaves,
                                                            ADLBdf *lpSlaveBDFList,
                                                            int *lpMinNumLocalDisplays,
                                                            int **lppMaxNumLocalDisplaysList,
                                                            int *lpDefaultNumLocalDisplays,
                                                            int *lpCurrentNumLocalDisplays);

///
/// \brief Function to retrieve LocalDisplay support settings.
/// 
/// This function implements a DI call to retrieve LocalDisplay support settings. 
/// \platform
/// \ALL
/// \param[in]  iAdapterIndex				The ADL index handle of the desired adapter.
/// \param[in]  iNumSlaves					The number of slave adapters to query local display support with (for PX system the number is 1). </param>
/// \param[in]  lpSlaveBDFList				The list of slave adapter BDFs. </param>
/// \param[out] lpMinNumLocalDisplays		Minimum number of supported local displays (per slave). </param>
/// \param[out] lppMaxNumLocalDisplaysList	Maximum number of supported local displays (per slave) in the same order as input 'slaveBDFList'. </param>
/// \param[out] lpDefaultNumLocalDisplays	Default number of supported local displays (per slave). </param>
/// \param[out] lpCurrentNumLocalDisplays	Current number of supported local displays (per slave). </param>
/// \return If the function succeeds, the return value is \ref ADL_OK, or an ADL error code otherwise.  \ref define_adl_results
/// \deprecated This API has been deprecated.
ADL_EXTERNC int EXPOSED ADL_Adapter_LocalDisplayConfig_Get(int iAdapterIndex,
                                                           int iNumSlaves,
                                                           ADLBdf *lpSlaveBDFList,
                                                           int *lpMinNumLocalDisplays,
                                                           int **lppMaxNumLocalDisplaysList,
                                                           int *lpDefaultNumLocalDisplays,
                                                           int *lpCurrentNumLocalDisplays);

///
/// \brief Function to set LocalDisplay support settings.
/// 
/// This function implements a DI call to set LocalDisplay support settings. 
/// \platform
/// \ALL
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in]  iAdapterIndex		The ADL index handle of the desired adapter.
/// \param[in]  iNumLocalDisplays	The number local displays to be supported by each slave.
/// \param[in]	bDoPNP				If set to true, the driver will trigger PnP stop/start on the affected chain.
/// \return If the function succeeds, the return value is \ref ADL_OK, or an ADL error code otherwise.  \ref define_adl_results
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
/// \deprecated This API has been deprecated.
ADL_EXTERNC int EXPOSED ADL2_Adapter_LocalDisplayConfig_Set(ADL_CONTEXT_HANDLE context,int iAdapterIndex,
                                                            int iNumLocalDisplays,
                                                            int bDoPNP);

///
/// \brief Function to set LocalDisplay support settings.
/// 
/// This function implements a DI call to set LocalDisplay support settings. 
/// \platform
/// \ALL
/// \param[in]  iAdapterIndex		The ADL index handle of the desired adapter.
/// \param[in]  iNumLocalDisplays	The number local displays to be supported by each slave.
/// \param[in]	bDoPNP				If set to true, the driver will trigger PnP stop/start on the affected chain.
/// \return If the function succeeds, the return value is \ref ADL_OK, or an ADL error code otherwise.  \ref define_adl_results
/// \deprecated This API has been deprecated.
ADL_EXTERNC int EXPOSED ADL_Adapter_LocalDisplayConfig_Set(int iAdapterIndex,
                                            int iNumLocalDisplays,
                                            int bDoPNP);

///\brief Function to set Driver Upscale settings
/// This function sets the user input values to Driver Upscale feature
/// \platform
/// \WIN
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in]  iAdapterIndex The index of the desired adapter.
/// \param[in]  settings \ref ADL_DRIVERUPSCALE_SETTINGS : structure with the input values
/// \param[in]  changeReason \ref ADL_DRIVERUPSCALE_NOTFICATION_REASON : structure with the changed fields in settings parameter
/// \param[out]  errorReason \ref ADL_ERROR_REASON : structure with the error fields in settings parameter. client should refer to these fields when set call fails.
/// \return If the function succeeds, the return value is \ref ADL_OK (zero). Otherwise the return value is an ADL error code (non-zero). \ref define_adl_results
ADL_EXTERNC int EXPOSED ADL2_DriverUpscale_Settings_Set(ADL_CONTEXT_HANDLE context, int iAdapterIndex, ADL_DRIVERUPSCALE_SETTINGS settings,
    ADL_DRIVERUPSCALE_NOTFICATION_REASON changeReason,
    ADL_ERROR_REASON* errorReason);

///\brief Function to get the Driver Upscale settings
/// This function retrieves the Driver Upscale settings for a specified display adapter.
/// \platform
/// \WIN
/// \param[in]  context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in]  iAdapterIndex The index of the desired adapter.
/// \param[out] settings The pointer to the pointer to the ADL_DRIVERUPSCALE_SETTINGS data structure
/// \return If the function succeeds, the return value is \ref ADL_OK (zero). Otherwise the return value is an ADL error code (non-zero). \ref define_adl_results
ADL_EXTERNC int EXPOSED ADL2_DriverUpscale_Settings_Get(ADL_CONTEXT_HANDLE context, int iAdapterIndex, ADL_DRIVERUPSCALE_SETTINGS* settings);

/// 
/// \brief Function to retrieve the configuration state of a specified adapter.
///
/// This function implements private adapter info and private adapter capacity to retrieve the configuration state of a specified adapter.
/// \platform
/// \LNX
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in] iAdapterIndex    The ADL index handle of the desired adapter.
/// \param[out] lpAdapterState  Integer indicating the state of the adapter.
/// \param[out] lpValidMask     The mask indicating which lpAdapterState bits are valid.
ADL_EXTERNC int EXPOSED ADL2_Adapter_ConfigureState_Get (ADL_CONTEXT_HANDLE context,int iAdapterIndex, int *lpAdapterState, int *lpValidMask);

/// 
/// \brief Function to retrieve the Location paths of the all adapters.
///
/// This function retrieves DI location paths of the all adapters.
/// \platform
/// \LNX
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[out] lppAdapterLocationPath    Location paths of the adapaters.
ADL_EXTERNC int EXPOSED ADL2_Adapter_AdapterLocationPath_Get (ADL_CONTEXT_HANDLE context, ADLAdapterLocationPath **lppAdapterLocationPath);

/// \addtogroup FPSAPI
///
/// @{
#if defined (_WIN32) || defined(_WIN64)

///
/// \brief Function to retrieve the supported power states in AC or DC.
/// 
/// This function retrieves the supported power states for a given power source. 
/// \platform
/// \WIN
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in]   iAdapterIndex The ADL index handle of the desired adapter. 
/// \param[in]   iPowerSource Input power source either it is AC or DC or both.
/// \param[out]  lpADLPowerStates The pointer to the structure storing the supported power states for the provided power source.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
ADL_EXTERNC int EXPOSED ADL2_PowerStates_Get(ADL_CONTEXT_HANDLE context, int iAdapterIndex, int iPowerSource, ADLPowerStates* lpADLPowerStates);

/// \brief Function to get the state of the driver level feature support.
///
/// This function gets the state of the driver level feature support from its Services registry location.
/// \platform
/// \WIN
/// \param[in] context			: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
ADL_EXTERNC int EXPOSED ADL2_Adapter_XConnectSupport_Get(ADL_CONTEXT_HANDLE context);

/// 
/// \brief Function to retrieve PPLog settings.
///
/// This function retrieves PPLog settings.
/// \platform
/// \WIN
/// \param[in] context			: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in] iAdapterIndex    : The ADL index handle of the desired adapter.
/// \param[out] pPPLogSettings	    : Pointer to the current PPLog settings obtained 
ADL_EXTERNC int EXPOSED ADL2_PPLogSettings_Get(ADL_CONTEXT_HANDLE context, int iAdapterIndex, ADLPPLogSettings *pPPLogSettings);

/// 
/// \brief Function to update PPLog settings.
///
/// This function update PPLog settings.
/// \platform
/// \WIN
/// \param[in] context			: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in] iAdapterIndex    : The ADL index handle of the desired adapter.
/// \param[in] pPPLogSettings		: PPLog settings to update the current PPLog settings
ADL_EXTERNC int EXPOSED ADL2_PPLogSettings_Set(ADL_CONTEXT_HANDLE context, int iAdapterIndex, ADLPPLogSettings *pPPLogSettings);

#endif /*(_WIN32) || (_WIN64)*/
/// @}

/// \brief Function to retrieve Gfx EDC Error Log.
/// 
 /// This function implements a call to retrieve Gfx EDC Error Logs.
 /// \platform
 /// \VISTAWIN7
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[out] pErrorrecordCount The pointer to the number of error records
/// \param[out] pErrorCount The pointer to the number of error counts
/// \param[out] isOverflow The pointer to the overflow result
/// \param[out] errorRecords The pointer to error records
/// \return If the function succeeds, the return value is \ref ADL_OK, or an ADL error code otherwise. \ref define_adl_results
ADL_EXTERNC int EXPOSED ADL2_Adapter_ECC_ErrorRecords_Get (ADL_CONTEXT_HANDLE context,int iAdapterIndex, int* pErrorrecordCount, int* pErrorCount, int* isOverflow, ADLErrorRecord* errorRecords); 

/// \brief Function to inject Gfx EDC Error .
/// 
 /// This function implements a call to inject Gfx EDC Error.
 /// \platform
 /// \VISTAWIN7
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[in] errorInjection The pointer to error injection
/// \param[out] isAccessible The pointer to register accessible result
/// \return If the function succeeds, the return value is \ref ADL_OK, or an ADL error code otherwise. \ref define_adl_results
ADL_EXTERNC int EXPOSED ADL2_Adapter_ECC_ErrorInjection_Set (ADL_CONTEXT_HANDLE context,int iAdapterIndex, ADLErrorInjectionX2* errorInjection, int* isAccessible);

/// \brief Function to check uncorrectable error status before application exits.
/// 
 /// This function implements a call to check uncorrectable error status before application exits.
 /// \platform
 /// \VISTAWIN7
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[out] isUCHappened The pointer to UC status result
/// \return If the function succeeds, the return value is \ref ADL_OK, or an ADL error code otherwise. \ref define_adl_results
ADL_EXTERNC int EXPOSED ADL2_Adapter_HBM_ECC_UC_Check (ADL_CONTEXT_HANDLE context,int iAdapterIndex, int* isUCHappened);

/// \addtogroup OVERDRIVENAPI
/// @{
/*
///
/// \brief Function to sets the OverdriveN Throttle Notification state.
/// 
/// This function retrieves the OverdriveN Throttle Notification state for a specified adapter.
/// \platform
/// \WIN
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[in]  iStatus Throttle Notification state \ref ADL_TRUE   \ref ADL_FALSE 
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results 
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
ADL_EXTERNC int EXPOSED ADL2_OverdriveN_ThrottleNotification_Set(ADL_CONTEXT_HANDLE context, int iAdapterIndex, int iStatus);
*/

///
/// \brief Function to gets the Smart shift support.
/// 
/// This function retrieves the smart shift support for a specified adapter.
/// \platform
/// \WIN
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[out] lpSupported Smart shift supported state 
/// \deprecated This API has been deprecated.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results 
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
ADL_EXTERNC int EXPOSED ADL2_Overdrive8_SmartShift_Support(ADL_CONTEXT_HANDLE context, int iAdapterIndex, int * lpSupported);


/// \brief Function to do RAS Error Injection .
/// 
 /// This function implements a call to inject RAS Error.
 /// \platform
 /// \VISTAWIN7
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[in] pErrorInjectionInput The pointer to error injection
/// \return If the function succeeds, the return value is \ref ADL_OK, or an ADL error code otherwise. \ref define_adl_results
ADL_EXTERNC int EXPOSED ADL2_Adapter_RAS_ErrorInjection_Set (ADL_CONTEXT_HANDLE context,int iAdapterIndex, ADLRASErrorInjectonInput* pErrorInjectionInput);

/// @}

///
/// \brief Function to get the FPO (Freesync power optimization) State of the system
///
/// This function implements the functionality to get the FPO state of the system.
/// \platform
/// \ALL
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[out]  lpSupported The int pointer if the feature is currently supported on the existing configuration
///              It can be unsupported (lpSupported = 0) or supported (lpSupported = 1)
/// \param[out]  lpCurrent The int pointer to whether the feature is currently enabled or not
///              It can be disabled (lpCurrent = 0) or enabled (lpCurrent = 1)
/// \param[out]  lpDefault The int pointer to whether the feataure is enable or disabled by default
///				 It can be enabled by default (lpDefault = 1) or disabled by default (lpDefault = 0)
/// \return If the function is successful, \ref ADL_OK is returned. \ref ADL_OK_MODE_CHANGE if success but need mode change,\n
/// If the function is not supported, \ref ADL_ERR_NOT_SUPPORTED is returned. For all other errors, \ref ADL_ERR is returned.
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
ADL_EXTERNC int EXPOSED ADL2_FreeSync_PowerOptimization_Get(ADL_CONTEXT_HANDLE context,int *lpSupported, int *lpCurrent, int *lpDefault);

///
/// \brief Function to get the FPO (Freesync power optimization) State of the system
///
/// This function implements the functionality to get the FPO state of the system.
/// \platform
/// \ALL
/// \param[out]  lpSupported The int pointer if the feature is currently supported on the existing configuration
///              It can be unsupported (lpSuppo8rted = 0) or supported (lpSupported = 1)
/// \param[out]  lpCurrent The int pointer to whether the feature is currently enabled or not
///              It can be disabled (lpCurrent = 0) or enabled (lpCurrent = 1)
/// \param[out]  lpDefault The int pointer to whether the feataure is enable or disabled by default
///				 It can be enabled by default (lpDefault = 1) or disabled by default (lpDefault = 0)
/// \return If the function is successful, \ref ADL_OK is returned.
/// If the function is not supported, \ref ADL_ERR_NOT_SUPPORTED is returned. For all other errors, \ref ADL_ERR is returned.
ADL_EXTERNC int EXPOSED ADL_FreeSync_PowerOptimization_Get(int *lpSupported, int *lpCurrent, int *lpDefault);

///
/// \brief Function to set the FPO (Freesync power optimization) State of the system
///
/// This function implements the functionality to set FPO (Freesync power optimization) State of the system.
/// \platform
/// \ALL
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in]  iEnable The current enable (iEnable = 1) or disable (iEnable = 0) state to set
/// \return If the function is successful, \ref ADL_OK is returned. \ref ADL_OK_MODE_CHANGE if success but need mode change,\n
/// If the function is not supported, \ref ADL_ERR_NOT_SUPPORTED is returned. For all other errors, \ref ADL_ERR is returned.
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
ADL_EXTERNC int EXPOSED ADL2_FreeSync_PowerOptimization_Set(ADL_CONTEXT_HANDLE context,int iEnable);

///
/// \brief Function to set the EDID Persistence  state of the system.
///
/// This function implements the functionality to set the EDID Persistence mode for a system.
/// \platform
/// \ALL
/// \param[in]  iEnable The current enable (iEnable = 1) or disable (iEnable = 0) state to set
/// \return If the function is successful, \ref ADL_OK is returned.
/// If the function is not supported, \ref ADL_ERR_NOT_SUPPORTED is returned. For all other errors, \ref ADL_ERR is returned.
ADL_EXTERNC int EXPOSED ADL_FreeSync_PowerOptimization_Set(int iEnable);

/// \brief Function to retrieve XGMI hive ID of the system.
///
/// This function is used to get the hive ID if the system has XGMI multi-hive configuration.
/// \platform
/// \ALL
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in]	iAdapterIndex The ADL index handle of the desired adapter to query for hive ID
/// \param[out]	lphiveID The hive ID of the GPU in XGMI chain. The ID starts from 1.
/// \return If the function succeeds, the return value is \ref ADL_OK (zero). Otherwise the return value is an ADL error code (non-zero). \ref define_adl_results
ADL_EXTERNC int EXPOSED ADL2_Adapter_XGMIHiveID_Get(ADL_CONTEXT_HANDLE context, int iAdapterIndex, int* lphiveID);

///
/// \brief Function to get the SmartAccessMemory Settings.
/// 
/// This function retrieves the Smart Access Memory settings for a specified adapter.
/// \platform
/// \WIN
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[out] lpGetMode SmartAccessMemory settings  
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results 
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . 
/// Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
ADL_EXTERNC int EXPOSED ADL2_SmartAccessMemory_Mode_Get(ADL_CONTEXT_HANDLE context, int iAdapterIndex, ADL_SMARTACCESSMEMORY_SETTINGS *lpGetMode);

///
/// \brief Function to set the SmartAccessMemory settings.
/// 
/// This function set the Smart Access Memory settings for a specified adapter.
/// \platform
/// \WIN
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in] iAdapterIndex The ADL index handle of the desired adapter.
/// \param[in] lpSetMode SmartAccessMemory settings
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results 
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process .
/// Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
ADL_EXTERNC int EXPOSED ADL2_SmartAccessMemory_Mode_Set(ADL_CONTEXT_HANDLE context, int iAdapterIndex, ADL_SMARTACCESSMEMORY_SETTINGS lpSetMode);
    
///
/// \brief Function to get UMA support, current value, default value and number of possible UMA supported modes.
/// 
/// This function get the UMA carvout settings for a specified adapter.
/// \platform
/// \WIN
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in] iAdapterIndex The ADL index handle of the desired adapter.
/// \param[in] lppAvailableUMAModes  The pointer to the list of UMA possible modes. /ref UMACarveoutModes
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results 
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process .
/// Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
ADL_EXTERNC int EXPOSED ADL2_Adapter_GPUUMACarveout_Info_Get(ADL_CONTEXT_HANDLE context, int iAdapterIndex, UMACarveoutInfo *lpUMACarveoutInfo);

///
/// \brief Function to set UMA mode.
/// 
/// This function set the UMA carvout a new value for a specified adapter.
/// \platform
/// \WIN
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in] iAdapterIndex The ADL index handle of the desired adapter.
/// \param[in] iUMAMode   The enum type of /ref UMACarveoutModes
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results 
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process .
/// Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
/// After set call, the driver needs the app to reboot the system in order to take the new value since the  new value is set to BIOS.
ADL_EXTERNC int EXPOSED ADL2_Adapter_GPUUMACarveout_Size_Set(ADL_CONTEXT_HANDLE context, int iAdapterIndex, UMACarveoutModes iUMAMode);

///
/// \brief Function to get the SmartMux enablement state.
/// 
/// This function retrieves the SmartMux feature enablement state for a specified adapter.
/// \platform
/// \WIN
/// \param[in]  context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[out] iGetControl   The enum type of /ref ADL_SMARTMUXENABLE_STATE
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results 
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process .
/// Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
ADL_EXTERNC int EXPOSED ADL2_Adapter_SmartMux_Control_Get(ADL_CONTEXT_HANDLE context, int iAdapterIndex, ADL_SMARTMUXENABLE_STATE *iGetControl);

///
/// \brief Function to set the SmartMux enablement state.
/// 
/// This function set the SmartMux feature enablement state to enabled/disabled for a specified adapter.
/// \platform
/// \WIN
/// \param[in]  context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[in]  iSetControl   The enum type of /ref ADL_SMARTMUXENABLE_STATE
/// \param[out] iGetControl   The enum type of /ref ADL_SMARTMUXENABLE_STATE
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results 
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process .
/// Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
ADL_EXTERNC int EXPOSED ADL2_Adapter_SmartMux_Control_Set(ADL_CONTEXT_HANDLE context, int iAdapterIndex, ADL_SMARTMUXENABLE_STATE iSetControl, ADL_SMARTMUXENABLE_STATE *iGetControl);

///
/// \brief Function to get the current switch state of SmartMux.
/// 
/// This function retrieves the switch state (APU/dGPU) for the SmartMux feature for a specified adapter.
/// \platform
/// \WIN
/// \param[in]  context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[out] iGetState   The enum type of /ref ADL_SMARTMUXCONTROL_STATE
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results 
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process .
/// Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
ADL_EXTERNC int EXPOSED ADL2_Adapter_SmartMux_State_Get(ADL_CONTEXT_HANDLE context, int iAdapterIndex, ADL_SMARTMUXCONTROL_STATE *iGetState);

///
/// \brief Function to get the SmartMux feature support on the platform.
/// 
/// This function retrieves the SmartMux feature support state for a specified adapter.
/// \platform
/// \WIN
/// \param[in]  context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[out] iGetSupport   The enum type of /ref ADL_SMARTMUXSUPPORT_STATE
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results 
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process .
/// Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
ADL_EXTERNC int EXPOSED ADL2_Adapter_SmartMux_Support_Get(ADL_CONTEXT_HANDLE context, int iAdapterIndex, ADL_SMARTMUXSUPPORT_STATE *iGetSupport);

///
/// \brief Function to get the SmartMux switch failure cause.
/// 
/// This function retrieves the cause of the SmartMux switch failure for a specified adapter.
/// \platform
/// \WIN
/// \param[in]  context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[out] iGetFailure   The enum type of /ref ADL_SMARTMUXFAILURE_STATE
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results 
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process .
/// Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
ADL_EXTERNC int EXPOSED ADL2_Adapter_SmartMux_Switch_Failure_Get(ADL_CONTEXT_HANDLE context, int iAdapterIndex, ADL_SMARTMUXFAILURE_STATE *iGetFailure);

#endif /* AMD_ADAPTER_H_ */
