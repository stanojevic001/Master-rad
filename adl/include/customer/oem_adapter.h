///
///  Copyright (c) 2008 - 2021 Advanced Micro Devices, Inc.
 
///  THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
///  EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
///  WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.

/// \file oem_adapter.h
/// \brief Contains all customer display-related functions exposed by ADL for \ALL platforms.
///
/// This file contains all OEM or other customer adapter-related functions exposed by ADL for \ALL platforms.
/// All functions found in this file can be used as a reference to ensure
/// the specified function pointers can be used by the appropriate runtime
/// dynamic library loaders. This header file not for public release.


/// \example Freesync
/// \htmlinclude Freesync\freesyncSample.html

/// \example PXRunningApps
/// \htmlinclude PXRunningApps\PXRunningAppsSample.html

#ifndef OEM_ADAPTER_H_
#define OEM_ADAPTER_H_

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

#if defined(_WIN32) || defined(_WIN64)
ADL_EXTERNC
{
	__declspec(dllexport) int AmdPowerXpressRequestHighPerformance;
}
#define HIDDEN
#endif

/// \addtogroup ADAPTERMAINAPI
/// @{

///
/// \brief Function to sets a GPU as preferred GPU to OS on HG.
/// 
/// This function sets a GPU as preferred GPU to OS based on the input. If true, sets HighPerf GPU.
/// \platform
/// \WIN
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in]  forceHighPerfGPU: identifies if high performance GPU will be preferred GPU or not. 
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results 
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
ADL_EXTERNC int EXPOSED ADL2_HybridGraphicsGPU_Set(ADL_CONTEXT_HANDLE context, bool forceHighPerfGPU = true);

/// \brief Function to send LUT buffer Index to driver
/// 
/// This function implements a call to send LUT buffer Index to driver
/// \platform
/// \WIN
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[in]  Index of LUT buffer 
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
ADL_EXTERNC int EXPOSED ADL2_Adapter_PreFlipPostProcessing_Select_LUT_Buffer(ADL_CONTEXT_HANDLE context, int iAdapterIndex, int LUTIndex);

/// \brief Function to enable
/// 
/// \platform
/// \WIN
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
ADL_EXTERNC int EXPOSED ADL2_Adapter_PreFlipPostProcessing_Enable(ADL_CONTEXT_HANDLE context, int iAdapterIndex);

/// \brief Function to disable
/// 
/// \platform
/// \WIN
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
ADL_EXTERNC int EXPOSED ADL2_Adapter_PreFlipPostProcessing_Disable(ADL_CONTEXT_HANDLE context, int iAdapterIndex);

/// \brief Function to get current status
/// 
/// \platform
/// \WIN
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[out] pInfo: pointer to structure to save output.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
ADL_EXTERNC int EXPOSED ADL2_Adapter_PreFlipPostProcessing_Get_Status(ADL_CONTEXT_HANDLE context, int iAdapterIndex, ADLPreFlipPostProcessingInfo* pInfo);

/// \brief Function to clear selected LUT buffer
/// 
/// \platform
/// \WIN
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
ADL_EXTERNC int EXPOSED ADL2_Adapter_PreFlipPostProcessing_Unselect_LUT_Buffer(ADL_CONTEXT_HANDLE context, int iAdapterIndex);

/// \brief Function to select desired LUT algorithm defined in adl_structures.h
/// 
/// \platform
/// \WIN
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[in] algorithm: number corresponding to ADLPreFlipPostProcessingLUTAlgorithm enum.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
ADL_EXTERNC int EXPOSED ADL2_Adapter_PreFlipPostProcessing_Select_LUT_Algorithm(ADL_CONTEXT_HANDLE context, int iAdapterIndex, ADLPreFlipPostProcessingLUTAlgorithm algorithm);


///
/// \brief Function to retrieve memory information from the adapter. Version 3
///
/// This function retrieves the memory information for a specified graphics adapter.
/// \platform
/// \LNX
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[out] lpMemoryInfo3 The pointer to the structure storing the retrieved memory information.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
ADL_EXTERNC int EXPOSED ADL2_Adapter_MemoryInfo3_Get(ADL_CONTEXT_HANDLE context, int iAdapterIndex, ADLMemoryInfo3 *lpMemoryInfo3);
///
/// \brief Function to retrieve memory information from the adapter. Version 3
///
/// This function retrieves the memory information for a specified graphics adapter.
/// \platform
/// \LNX
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[out] lpMemoryInfo3 The pointer to the structure storing the retrieved memory information.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
ADL_EXTERNC int EXPOSED ADL_Adapter_MemoryInfo3_Get(int iAdapterIndex, ADLMemoryInfo3 *lpMemoryInfo3);


///\brief Function to get the VariBright capabilities
/// This function retrieves the VariBright capabilities for a specified display adapter.
/// \platform
/// \ALL
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in]  iAdapterIndex The index of the desired adapter.
/// \param[in]  iSupported The pointer to an int variable which indicates if VariBright is supported ( \ref ADL_TRUE : supported, \ref ADL_FALSE : not supported)
/// \param[in]  iEnabled The pointer to an int variable which indicates if VariBright is enabled ( \ref ADL_TRUE : enabled, \ref ADL_FALSE : disabled)
/// \param[in]  iVersion The pointer to an int variable receiving the VariBright version.
/// \param[in]  iDeffEnabled The pointer to an int variable which indicates if default  VariBright is enabled ( \ref ADL_TRUE : enabled, \ref ADL_FALSE : disabled).
/// \return If the function succeeds, the return value is \ref ADL_OK (zero). Otherwise the return value is an ADL error code (non-zero). \ref define_adl_results 
///
/// \remarks Call this API first. Only if VariBright feature is supported and enabled call ADL_Adapter_VariBrightLevel_Get() or ADL_Adapter_VariBrightLevel_Set()
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
ADL_EXTERNC int EXPOSED ADL2_Adapter_VariBright_CapsX2(ADL_CONTEXT_HANDLE context, int iAdapterIndex, int * iSupported, int * iEnabled, int * iVersion, int * iDeffEnabled);

///\brief Function to get the VariBright capabilities
/// This function retrieves the VariBright capabilities for a specified display adapter.
/// \platform
/// \ALL
/// \param[in]  iAdapterIndex The index of the desired adapter.
/// \param[in]  iSupported The pointer to an int variable which indicates if VariBright is supported ( \ref ADL_TRUE : supported, \ref ADL_FALSE : not supported)
/// \param[in]  iEnabled The pointer to an int variable which indicates if VariBright is enabled ( \ref ADL_TRUE : enabled, \ref ADL_FALSE : disabled)
/// \param[in]  iVersion The pointer to an int variable receiving the VariBright version.
/// \param[in]  iDeffEnabled The pointer to an int variable which indicates if default  VariBright is enabled ( \ref ADL_TRUE : enabled, \ref ADL_FALSE : disabled).
/// \return If the function succeeds, the return value is \ref ADL_OK (zero). Otherwise the return value is an ADL error code (non-zero). \ref define_adl_results 
///
/// \remarks Call this API first. Only if VariBright feature is supported and enabled call ADL_Adapter_VariBrightLevel_Get() or ADL_Adapter_VariBrightLevel_Set()
ADL_EXTERNC int EXPOSED ADL_Adapter_VariBright_CapsX2(int iAdapterIndex, int * iSupported, int * iEnabled, int * iVersion, int * iDeffEnabled);

///
/// \brief ADL local interface. Function to query a registry value by driver.
/// 
/// This function query a registry value by driver for a specified adapter.
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[in]  szDriverSettings The name of registry value to be got.
/// \param[in]  iDriverPathOption The option of the driver path. See \ref Definitions for driver path options for values.
/// \param[in]  iType The type of registry value to be got. See \ref Definitions for registry value types for values
/// \param[in]  iSize The size of registry value to be got.
/// \param[out] lpSetting The pointer to registry value to be got.
/// \platform 
/// \WIN
/// \return If the function valid, the return value is 1. Otherwise it is 0. 
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
ADL_EXTERNC int EXPOSED ADL2_Adapter_DriverSettings_Get(ADL_CONTEXT_HANDLE context, int iAdapterIndex, char *szDriverSettings, int iDriverPathOption, int iType, int iSize, char *lpSetting);

///
/// \brief ADL local interface. Function to query a registry value by driver.
/// 
/// This function query a registry value by driver for a specified adapter.
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[in]  szDriverSettings The name of registry value to be got.
/// \param[in]  iDriverPathOption The option of the driver path. See \ref Definitions for driver path options for values.
/// \param[in]  iType The type of registry value to be got. See \ref Definitions for registry value types for values
/// \param[in]  iSize The size of registry value to be got.
/// \param[out] lpSetting The pointer to registry value to be got.
/// \platform 
/// \WIN
/// \return If the function valid, the return value is 1. Otherwise it is 0. 
ADL_EXTERNC int EXPOSED ADL_Adapter_DriverSettings_Get( int iAdapterIndex, char *szDriverSettings, int iDriverPathOption, int iType, int iSize, char *lpSetting);

///
/// \brief ADL local interface. Function to set a registry value by driver.
/// 
/// This function set a registry value by driver for a specified adapter.
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[in]  szDriverSettings The name of registry value to be set.
/// \param[in]  iDriverPathOption The option of the driver path. See \ref Definitions for driver path options for values.
/// \param[in]  iType The type of registry value to be got. See \ref Definitions for registry value types for values
/// \param[in]  iSize The size of registry value to be set.
/// \param[out] lpSetting The pointer to registry value to be set.
/// \platform 
/// \WIN
/// \return If the function valid, the return value is 1. Otherwise it is 0. 
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
ADL_EXTERNC int EXPOSED ADL2_Adapter_DriverSettings_Set(ADL_CONTEXT_HANDLE context, int iAdapterIndex, char *szDriverSettings, int iDriverPathOption, int iType, int iSize, char *lpSetting);

///
/// \brief ADL local interface. Function to set a registry value by driver.
/// 
/// This function set a registry value by driver for a specified adapter.
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[in]  szDriverSettings The name of registry value to be set.
/// \param[in]  iDriverPathOption The option of the driver path. See \ref Definitions for driver path options for values.
/// \param[in]  iType The type of registry value to be got. See \ref Definitions for registry value types for values
/// \param[in]  iSize The size of registry value to be set.
/// \param[out] lpSetting The pointer to registry value to be set.
/// \platform 
/// \WIN
/// \return If the function valid, the return value is 1. Otherwise it is 0. 
ADL_EXTERNC int EXPOSED ADL_Adapter_DriverSettings_Set( int iAdapterIndex, char *szDriverSettings, int iDriverPathOption, int iType, int iSize, char *lpSetting);

///
/// \brief Function to retrieve encrypted Device ID based on the input random number.
/// 
/// This function implements a lhEscape call to retrieve Device ID from hardware .
/// \platform
/// \ALL
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[in]  iRNDBufferSize size of the input random number buffer size
/// \param[in]  lpRNDBuffer the pointer where input random number is stored
/// \param[in]  iDeviceIDBufferSize size of the out deviceID buffer size
/// \param[out] lpDeviceIDBuffer The pointer where Device ID value is stored, buffer should be allocated at client side
/// \param[out] iDeviceIDSize size of the device ID
/// \return If the function succeeds, the return value is \ref ADL_OK, or an ADL error code otherwise. \ref define_adl_results
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
ADL_EXTERNC int EXPOSED ADL2_Adapter_DeviceID_Get(ADL_CONTEXT_HANDLE context,int iAdapterIndex,  int iRNDBufferSize,  char *lpRNDBuffer,  int iDeviceIDBufferSize, char *lpDeviceIDBuffer , int *iDeviceIDSize);

/// @}




/// \addtogroup VIDEOAPI
/// @{

/// \brief Function to obtain the list of Multi-Media features
/// 
/// The function is used to obtain the list of Multi-Media feature names for a specific display adapter.
/// \platform
/// \VISTAWIN7
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[out]  lppName is pointer to the pointer of ADLFeatureName array. Initialize to NULL before  calling this API. ADL will allocate the necessary memory, using the user provided callback function.
/// \param[out]  lpFeatureCount The number of all available features.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
///
/// \remarks This API uses the memory allocation callback function provided by the user.
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
ADL_EXTERNC int EXPOSED ADL2_MMD_FeatureList_Get(ADL_CONTEXT_HANDLE context, int iAdapterIndex, ADLFeatureName ** lppName, int * lpFeatureCount );

/// \brief Function to obtain the list of Multi-Media features
/// 
/// The function is used to obtain the list of Multi-Media feature names for a specific display adapter.
/// \platform
/// \VISTAWIN7
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[out]  lppName is pointer to the pointer of ADLFeatureName array. Initialize to NULL before  calling this API. ADL will allocate the necessary memory, using the user provided callback function.
/// \param[out]  lpFeatureCount The number of all available features.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
///
/// \remarks This API uses the memory allocation callback function provided by the user.
ADL_EXTERNC int EXPOSED ADL_MMD_FeatureList_Get( int iAdapterIndex, ADLFeatureName ** lppName, int * lpFeatureCount );



/// \brief Function to get MM video adjust info
///
/// The function is used to get multi-media video adjustment information.
/// 
/// \platform
/// \VISTAWIN7
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in]  iAdapterIndex			The ADL index handle of the desired adapter.
/// \param[out] lppMMVideoData			The pointer to the pointer to the retrieved MM Video data structure.
/// \param[out]	lpCount					The number of returned video data structure.
/// \param[out] lpLetApplicationDecide	If it is true, disable the all settings and let application make decision. Otherwise, using driver settings.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
ADL_EXTERNC int EXPOSED ADL2_MMD_VideoAdjustInfo_Get(ADL_CONTEXT_HANDLE context, int iAdapterIndex, ADLMMVideoData** lppMMVideoData, int* lpCount, int* lpLetApplicationDecide );

/// \brief Function to get MM video adjust info
///
/// The function is used to get multi-media video adjustment information.
/// 
/// \platform
/// \VISTAWIN7
/// \param[in]  iAdapterIndex			The ADL index handle of the desired adapter.
/// \param[out] lppMMVideoData			The pointer to the pointer to the retrieved MM Video data structure.
/// \param[out]	lpCount					The number of returned video data structure.
/// \param[out] lpLetApplicationDecide	If it is true, disable the all settings and let application make decision. Otherwise, using driver settings.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
ADL_EXTERNC int EXPOSED ADL_MMD_VideoAdjustInfo_Get( int iAdapterIndex, ADLMMVideoData** lppMMVideoData, int* lpCount, int* lpLetApplicationDecide );

/// \brief Function to set MM video adjust info
///
/// The function is used to set multi-media video adjustment information.
/// 
/// \platform
/// \VISTAWIN7
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in]  iAdapterIndex			The ADL index handle of the desired adapter.
/// \param[in]	lpMMVideoSetData		The pointer to the pointer to the MM Video data structure to be set.
/// \param[in]	iCount					The number of video data structure to be set.
/// \param[in]	iCommittedFlag			Committed flag, the value can be ADL_TURE or ADL_FALSE. ( \ref ADL_TRUE : committed, \ref ADL_FALSE : uncommitted)
/// \param[in]	iLetApplicationDecide	If it is \ref ADL_TRUE, disable all the settings and let application make decision. Otherwise(\ref ADL_FALSE), using driver settings.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
ADL_EXTERNC int EXPOSED ADL2_MMD_VideoAdjustInfo_Set(ADL_CONTEXT_HANDLE context, int iAdapterIndex, ADLMMVideoSetData* lpMMVideoSetData, int iCount, int iCommittedFlag, int iLetApplicationDecide );

/// \brief Function to set MM video adjust info
///
/// The function is used to set multi-media video adjustment information.
/// 
/// \platform
/// \VISTAWIN7
/// \param[in]  iAdapterIndex			The ADL index handle of the desired adapter.
/// \param[in]	lpMMVideoSetData		The pointer to the pointer to the MM Video data structure to be set.
/// \param[in]	iCount					The number of video data structure to be set.
/// \param[in]	iCommittedFlag			Committed flag, the value can be ADL_TURE or ADL_FALSE. ( \ref ADL_TRUE : committed, \ref ADL_FALSE : uncommitted)
/// \param[in]	iLetApplicationDecide	If it is \ref ADL_TRUE, disable all the settings and let application make decision. Otherwise(\ref ADL_FALSE), using driver settings.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
ADL_EXTERNC int EXPOSED ADL_MMD_VideoAdjustInfo_Set( int iAdapterIndex, ADLMMVideoSetData* lpMMVideoSetData, int iCount, int iCommittedFlag, int iLetApplicationDecide );

/// \brief Function to get MM video capabilities
///
/// The function is used to get current multi-media video capabilities.
/// 
/// \platform
/// \VISTAWIN7
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in]  iAdapterIndex			The ADL index handle of the desired adapter.
/// \param[in]	iVAControllerIndex		Controller index.
/// \param[in]	iVADisplayIndex			Display index.
/// \param[out] lpStandardVideoCaps		Standard video caps
/// \param[out]	lpHDVideoCaps			High-Definition Video caps
/// \param[out] lpGenericCaps			Generic Video caps
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
ADL_EXTERNC int EXPOSED ADL2_MMD_Video_Caps(ADL_CONTEXT_HANDLE context, int iAdapterIndex, int iVAControllerIndex, int iVADisplayIndex,
							   LPADLMMVideoCaps lpStandardVideoCaps, LPADLMMVideoCaps lpHDVideoCaps, LPADLMMVideoGenericCaps lpGenericCaps );

/// \brief Function to get MM video capabilities
///
/// The function is used to get current multi-media video capabilities.
/// 
/// \platform
/// \VISTAWIN7
/// \param[in]  iAdapterIndex			The ADL index handle of the desired adapter.
/// \param[in]	iVAControllerIndex		Controller index.
/// \param[in]	iVADisplayIndex			Display index.
/// \param[out] lpStandardVideoCaps		Standard video caps
/// \param[out]	lpHDVideoCaps			High-Definition Video caps
/// \param[out] lpGenericCaps			Generic Video caps
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
ADL_EXTERNC int EXPOSED ADL_MMD_Video_Caps( int iAdapterIndex, int iVAControllerIndex, int iVADisplayIndex,
							   LPADLMMVideoCaps lpStandardVideoCaps, LPADLMMVideoCaps lpHDVideoCaps, LPADLMMVideoGenericCaps lpGenericCaps );

///  \brief Retrieves capabilities of specific Video Color Feature.
///
///	 Use the call to determine if given Video color feature is supported by the driver, is it currently enabled, what are range, step , and default values of the feature. 
/// \platform
/// \VISTAWIN7
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter 
/// \param[in]  iFeature contains \ref ADLVideoColorFeature value. Id of Video Color feature.
/// \param[out]  lpCaps is reference to instance of \ref ADLVideoColorCaps structure that contains current capabilities of the feature.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error  code. 
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
ADL_EXTERNC int EXPOSED ADL2_MMD_VideoColor_Caps(ADL_CONTEXT_HANDLE context,int iAdapterIndex, ADLVideoColorFeature iFeature, LPADLVideoColorCaps lpCaps);

///  \brief Retrieves capabilities of specific Video Color Feature.
///
///	 Use the call to determine if given Video color feature is supported by the driver, is it currently enabled, what are range, step , and default values of the feature. 
/// \platform
/// \VISTAWIN7
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter 
/// \param[in]  iFeature contains \ref ADLVideoColorFeature value. Id of Video Color feature.
/// \param[out]  lpCaps is reference to instance of \ref ADLVideoColorCaps structure that contains current capabilities of the feature.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error  code. 
ADL_EXTERNC int EXPOSED ADL_MMD_VideoColor_Caps(int iAdapterIndex, ADLVideoColorFeature iFeature, LPADLVideoColorCaps lpCaps);

///  \brief Sends new value of Video Color feature to the driver.
///
///	 The function allows changing value of such Avivo Video color features as tint, brightness, saturation, contrast, color vibrance, gamma, skin tone correction strength.
/// \platform
/// \VISTAWIN7
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter 
/// \param[in]  iFeature contains \ref ADLVideoColorFeature value. Id of Video Color feature.
/// \param[in]  iValue new value of the feature.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error  code. 
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
ADL_EXTERNC int EXPOSED ADL2_MMD_VideoColor_Set(ADL_CONTEXT_HANDLE context,int iAdapterIndex, ADLVideoColorFeature iFeature, float iValue);

///  \brief Sends new value of Video Color feature to the driver.
///
///	 The function allows changing value of such Avivo Video color features as tint, brightness, saturation, contrast, color vibrance, gamma, skin tone correction strength.
/// \platform
/// \VISTAWIN7
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter 
/// \param[in]  iFeature contains \ref ADLVideoColorFeature value. Id of Video Color feature.
/// \param[in]  iValue new value of the feature.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error  code. 
ADL_EXTERNC int EXPOSED ADL_MMD_VideoColor_Set(int iAdapterIndex, ADLVideoColorFeature iFeature, float iValue);

///  \brief Gets current value of Video Color feature from the driver.
///
///	 The function reads current value of such features as tint, brightness, saturation, contrast, color vibrance, gamma, skin tone correction strength.
/// \platform
/// \VISTAWIN7
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter 
/// \param[in]  iFeature contains \ref ADLVideoColorFeature value. Id of Video Color feature.
/// \param[out]  iValue current value of the feature.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error  code. 
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
ADL_EXTERNC int EXPOSED ADL2_MMD_VideoColor_Get(ADL_CONTEXT_HANDLE context,int iAdapterIndex, ADLVideoColorFeature iFeature, float* iValue);

///  \brief Gets current value of Video Color feature from the driver.
///
///	 The function reads current value of such features as tint, brightness, saturation, contrast, color vibrance, gamma, skin tone correction strength.
/// \platform
/// \VISTAWIN7
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter 
/// \param[in]  iFeature contains \ref ADLVideoColorFeature value. Id of Video Color feature.
/// \param[out]  iValue current value of the feature.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error  code. 
ADL_EXTERNC int EXPOSED ADL_MMD_VideoColor_Get(int iAdapterIndex, ADLVideoColorFeature iFeature, float* iValue);

/// @}


/// \addtogroup OVERDRIVE5API
/// @{

///  \brief Function to check for Power Control (long run GPU power limit) capabilities
///
/// The output parameter of the function lets the caller know about whether or not Power Control (long run GPU power limit) feature is available.  Supported only on GPUs with PowerTune Technology.
/// \platform
/// \ALL
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[out] lpSupported is ADL_TRUE if feature is supported, otherwise it is ADL_FALSE.
/// \return If the function succeeds, the return value is \ref ADL_OK (zero). Otherwise the return value is an ADL error code (non-zero). \ref define_adl_results 
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
ADL_EXTERNC int EXPOSED ADL2_Overdrive5_PowerControlAbsValue_Caps(ADL_CONTEXT_HANDLE context,int iAdapterIndex,  int *lpSupported);

///  \brief Function to check for Power Control (long run GPU power limit) capabilities
///
/// The output parameter of the function lets the caller know about whether or not Power Control (long run GPU power limit) feature is available.  Supported only on GPUs with PowerTune Technology.
/// \platform
/// \ALL
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[out] lpSupported is ADL_TRUE if feature is supported, otherwise it is ADL_FALSE.
/// \return If the function succeeds, the return value is \ref ADL_OK (zero). Otherwise the return value is an ADL error code (non-zero). \ref define_adl_results 

ADL_EXTERNC int EXPOSED ADL_Overdrive5_PowerControlAbsValue_Caps(int iAdapterIndex,  int *lpSupported);

///  \brief Function to get absolute values of Power Control (GPU power limit)
///
/// The parameters of the function allow the caller to obtain absolute value of the long run GPU power limit.  Supported only on GPUs with PowerTune Technology.
/// \platform
/// \ALL
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in]  iAdapterIndex The ADL index handle  of the desired adapter 
/// \param[out]  lpCurrentValue pointer to the current value of long run GPU power limit 
/// \param[out]  lpDefaultValue pointer to the Default value of long run GPU power limit 
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error  code. 
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
ADL_EXTERNC int EXPOSED ADL2_Overdrive5_PowerControlAbsValue_Get(ADL_CONTEXT_HANDLE context,int iAdapterIndex, int *lpCurrentValue, int *lpDefaultValue);

///  \brief Function to get absolute values of Power Control (GPU power limit)
///
/// The parameters of the function allow the caller to obtain absolute value of the long run GPU power limit.  Supported only on GPUs with PowerTune Technology.
/// \platform
/// \ALL
/// \param[in]  iAdapterIndex The ADL index handle  of the desired adapter 
/// \param[out]  lpCurrentValue pointer to the current value of long run GPU power limit 
/// \param[out]  lpDefaultValue pointer to the Default value of long run GPU power limit 
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error  code. 

ADL_EXTERNC int EXPOSED ADL_Overdrive5_PowerControlAbsValue_Get(int iAdapterIndex, int *lpCurrentValue, int *lpDefaultValue);

///  \brief Function to set absolute value of Power Control (long run GPU power limit)
///
/// The parameters of the function allow the caller to set absolute value of the long run GPU power limit, extends existing ADL_Overdrive5_PowerControl_Set API.  Supported only on GPUs with PowerTune Technology.
/// \platform
/// \ALL
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter 
/// \param[in]  iValue New value of long run GPU power limit  
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error  code. 
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
ADL_EXTERNC int EXPOSED ADL2_Overdrive5_PowerControlAbsValue_Set(ADL_CONTEXT_HANDLE context,int iAdapterIndex, int iValue);

///  \brief Function to set absolute value of Power Control (long run GPU power limit)
///
/// The parameters of the function allow the caller to set absolute value of the long run GPU power limit, extends existing ADL_Overdrive5_PowerControl_Set API.  Supported only on GPUs with PowerTune Technology.
/// \platform
/// \ALL
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter 
/// \param[in]  iValue New value of long run GPU power limit  
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error  code. 

ADL_EXTERNC int EXPOSED ADL_Overdrive5_PowerControlAbsValue_Set(int iAdapterIndex, int iValue);


typedef enum TEMPERATURE_TYPE
{
    TEMPERATURE_TYPE_INVALID    = 0,
    TEMPERATURE_TYPE_EDGE       = 1,
    TEMPERATURE_TYPE_HBM        = 2,
    TEMPERATURE_TYPE_VRVDDC     = 3,
    TEMPERATURE_TYPE_VRMVDD     = 4,
    TEMPERATURE_TYPE_LIQUID     = 5,
    TEMPERATURE_TYPE_PLX        = 6,
    TEMPERATURE_TYPE_MAXTYPES   = 6
} TEMPERATURE_TYPE;

/// @}

/// \addtogroup OVERDRIVE6API
/// @{

///  \brief Function returns the temperature of the specified adapter, depending on the temperature typer requested.
/// \platform
/// \ALL
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[in]  eTemperatureType The enum for TEMPERATURE_TYPE to specify the power type.
/// \param[out] iTemperature The int pointer containing the temperature.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error  code.
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process and to assure that ADL API are thread-safe. Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
ADL_EXTERNC int EXPOSED ADL2_Overdrive6_TemperatureEx_Get(ADL_CONTEXT_HANDLE context, int iAdapterIndex, TEMPERATURE_TYPE eTemperatureType, int *iTemperature);


/// @}


///\brief \newAPI16 Function to set Camera GUIDs for DMFT  settings
/// This function sets the  input GuidPath to DMFT 
/// \platform
/// \WIN
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create. 
/// \param[in]  szDMFTGuidPath \ref  DMFT Guid Path  
/// \return If the function succeeds, the return value is \ref ADL_OK (zero). Otherwise the return value is an ADL error code (non-zero). \ref define_adl_results 
///
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
///
ADL_EXTERNC int EXPOSED ADL2_CVML_Camera_DMFT_Set(ADL_CONTEXT_HANDLE context, const char* szDMFTGuidPath);

/// \brief Function to do RAS Error Injection .
/// 
 /// This function implements a call to inject RAS Error.
 /// \platform
 /// \VISTAWIN7
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[in] pErrorInjection The pointer to error injection
/// \return If the function succeeds, the return value is \ref ADL_OK, or an ADL error code otherwise. \ref define_adl_results
ADL_EXTERNC int EXPOSED ADL2_Adapter_RAS_ErrorInjection_SetX2(ADL_CONTEXT_HANDLE context, int iAdapterIndex, ADLRASErrorInjection * pErrorInjection);

/// @}
#endif /* OEM_ADAPTER_H_ */
