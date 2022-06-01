///
///  Copyright (c) 2008 - 2021 Advanced Micro Devices, Inc.
 
///  THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
///  EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
///  WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.

/// \file graphics.h
/// \brief Contains all graphics-related functions exposed by ADL for \ALL platforms.
///
/// This file contains all graphics-related functions exposed by ADL for \ALL platforms.
/// All functions found in this file can be used as a reference when creating
/// specific function pointers to be used by the appropriate runtime
/// dynamic library loaders.

#ifndef GRAPHICS_H_
#define GRAPHICS_H_

#ifndef ADL_EXTERNC
#ifdef __cplusplus
#define ADL_EXTERNC extern "C"
#else
#define ADL_EXTERNC
#endif
#endif

/// \ingroup ADAPTERAPI
/// \defgroup GRAPHICSAPI Graphics Related APIs
/// This group outlines Graphics version and architechture specific APIs.


/// \addtogroup GRAPHICSAPI
/// @{
///
/// \brief Function to retrieve version information.
/// 
/// This function retrieves software version information and a web link to an XML file with information about the latest web-posted Catalyst drivers
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[out]  lpVersionsInfo The pointer to ADLVersionsInfo structure with the retrieved version information.
/// \platform 
/// \ALL
/// \return The function returns \ref ADL_OK or \ref ADL_OK_WARNING (if any of the version strings could not be retrieved from the system, for example "Catalyst Version"). If ADL is not initialized properly the function will return \ref ADL_ERR_DISABLED_ADAPTER
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
ADL_EXTERNC int EXPOSED ADL2_Graphics_Versions_Get(ADL_CONTEXT_HANDLE context, ADLVersionsInfo * lpVersionsInfo);

///
/// \brief Function to retrieve version information.
/// 
/// This function retrieves software version information and a web link to an XML file with information about the latest web-posted Catalyst drivers
/// \param[out]  lpVersionsInfo The pointer to ADLVersionsInfo structure with the retrieved version information.
/// \platform 
/// \ALL
/// \return The function returns \ref ADL_OK or \ref ADL_OK_WARNING (if any of the version strings could not be retrieved from the system, for example "Catalyst Version"). If ADL is not initialized properly the function will return \ref ADL_ERR_DISABLED_ADAPTER
ADL_EXTERNC int EXPOSED ADL_Graphics_Versions_Get(ADLVersionsInfo * lpVersionsInfo);

///
/// \brief Function to retrieve s version information.
/// 
/// This function retrieves software version information and a web link to an XML file with information about the latest web-posted Catalyst drivers
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[out]  lpVersionsInfo The pointer to ADLVersionsInfoX2 structure with the retrieved version information.
/// \platform 
/// \WIN
/// \return The function returns \ref ADL_OK or \ref ADL_OK_WARNING (if any of the version strings could not be retrieved from the system, for example "Catalyst Version"). If ADL is not initialized properly the function will return \ref ADL_ERR_DISABLED_ADAPTER
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
ADL_EXTERNC int EXPOSED ADL2_Graphics_VersionsX2_Get(ADL_CONTEXT_HANDLE context, ADLVersionsInfoX2 * lpVersionsInfo);

///
/// \brief \newAPI16 Function to retrieve version information for graphics driver installed on specific GPU.
/// 
/// This function retrieves software version information and a web link to an XML file with information about the latest web-posted Catalyst drivers
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in] iAdapterIndex: Adapter index that belongs to the GPU.
/// \param[out]  lpVersionsInfo The pointer to ADLVersionsInfo2 structure with the retrieved version information.
/// \platform 
/// \ALL
/// \return The function returns \ref ADL_OK or \ref ADL_OK_WARNING (if any of the version strings could not be retrieved from the system, for example "Catalyst Version"). If ADL is not initialized properly the function will return \ref ADL_ERR_DISABLED_ADAPTER
/// \remarks On hybrid system with multiple GPUs (A+A) each GPU has different driver version installed. This call will allow the application to discover driver version for each GPU.
ADL_EXTERNC int EXPOSED ADL2_Graphics_VersionsX3_Get(ADL_CONTEXT_HANDLE context, int iAdapterIndex, ADLVersionsInfoX2 * lpVersionsInfo);

///
/// \brief \newAPI15 Function to discover if the current platform is a detachable graphics one or not.
/// 
/// This function determines whether the current graphics platform is detachable graphics one or not.
/// \platform 
/// \WIN
/// \param[in]  context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[out] lpStatus The pointer to the retrieved graphics platform for the system. \n
///             lpStatus will be either 1 (for detachable graphics platforms) or 0 (for non-detachable graphics platforms)
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results 
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process. Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
ADL_EXTERNC int EXPOSED ADL2_Graphics_IsDetachableGraphicsPlatform_Get(ADL_CONTEXT_HANDLE context, int* lpStatus);

///
/// \brief \newAPI15 Function to retrieve the Family ID of a GPU.
/// 
/// This function determines what is the Family ID of a GPU and based on that, find if it is Gfx9 and above GPU or not.
/// \platform 
/// \WIN
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \return TRUE: if Family ID is Gfx9 or above; FALSE: otherwise.
ADL_EXTERNC int EXPOSED ADL2_Graphics_IsGfx9AndAbove(ADL_CONTEXT_HANDLE context);

/// 
/// \brief \newAPI15 Function to get mantle versions.
///
/// This function gets mantle versions.
/// \platform
/// \WIN
/// \param[in] context			: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in] mantleAppInfo    : The ADLMantleAppInfo structure.
ADL_EXTERNC int EXPOSED ADL2_Graphics_MantleVersion_Get(ADL_CONTEXT_HANDLE context, ADLMantleAppInfo *mantleAppInfo);

/// 
/// \brief Function to get Vulkan versions.
///
/// This function gets Vulkan versions. No longer used by RSX, but kept to preserve third party vendor support.
/// \platform
/// \WIN
/// \param[in] context			: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in] vulkanAppInfo    : The ADLAppVersionInfo structure.
ADL_EXTERNC int EXPOSED ADL2_Graphics_VulkanVersion_Get(ADL_CONTEXT_HANDLE context, ADLVulkanAppInfo *vulkanAppInfo);

/// 
/// \brief Function to get Vulkan versions.
///
/// SWDEV-261137 - This X2 function gets the Vulkan version of the currently connected display devices instead of all previously connected display devices. This X2 version is used by RSX currently, however the original function is kept to preserve third party vendor support.
/// \platform
/// \WIN
/// \param[in] context			: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in] vulkanAppInfo    : The ADLAppVersionInfo structure.
ADL_EXTERNC int EXPOSED ADL2_Graphics_VulkanVersionX2_Get(ADL_CONTEXT_HANDLE context, ADLVulkanAppInfo *vulkanAppInfo);

/// 
/// \brief Function to get Vulkan versions of different GPUs.
///
/// Side-by-side allows system to install 2 different drivers at the same time. This function will get the Vulkan version of the GPU passed in via adapter index. 
/// \platform
/// \WIN
/// \param[in] context			: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in] vulkanAppInfo    : The ADLAppVersionInfo structure.
/// \param[in] iAdapterIndex    : The adapter index of the GPU 
ADL_EXTERNC int EXPOSED ADL2_Graphics_VulkanVersionX3_Get(ADL_CONTEXT_HANDLE context, ADLVulkanAppInfo *vulkanAppInfo, int iAdapterIndex);



///
/// \brief Function to retrieve the type of graphics platform the system is currently running.
/// 
/// This function determines whether the current graphics platform is a mobile, desktop.
/// \platform 
/// \WIN
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[out] lpPlatForm The pointer to the retrieved graphics platform for the system. \n
///  lpPlatForm will be either GRAPHICS_PLATFORM_DESKTOP (for desktop platforms) or GRAPHICS_PLATFORM_MOBILE (for mobile platforms)
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results 
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
ADL_EXTERNC int EXPOSED ADL2_Graphics_Platform_Get(ADL_CONTEXT_HANDLE context,int *lpPlatForm);

///
/// \brief Function to retrieve the type of graphics platform the system is currently running.
/// 
/// This function determines whether the current graphics platform is a mobile, desktop.
/// \platform 
/// \WIN
/// \param[out] lpPlatForm The pointer to the retrieved graphics platform for the system. \n
///  lpPlatForm will be either GRAPHICS_PLATFORM_DESKTOP (for desktop platforms) or GRAPHICS_PLATFORM_MOBILE (for mobile platforms)
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results 
ADL_EXTERNC int EXPOSED ADL_Graphics_Platform_Get(int *lpPlatForm);

/// \brief Function to retrieve Graphic Core Info.
/// 
/// This function implements a call to retrieve Graphic Core Info.
/// \platform
/// \VISTAWIN7
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[out] pGraphicCoreInfo The pointer to Graphic Core Info
/// \return If the function succeeds, the return value is \ref ADL_OK, or an ADL error code otherwise. \ref define_adl_results
ADL_EXTERNC int EXPOSED ADL2_Adapter_Graphic_Core_Info_Get(ADL_CONTEXT_HANDLE context, int iAdapterIndex, ADLGraphicCoreInfo* pGraphicCoreInfo);

///
/// \brief \newAPI16 Function to retrieve SmartDC capabilities information.
/// 
/// This function retrieves SmartDC capabilities information from Driver.
/// \platform
/// \WIN10
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[out] lpSupported The int pointer to whether SmartDC is supported on current system.
///             If SmartDC is supported, the value is 1, otherwise it is 0.
/// \param[out] lpDefault The int pointer to whether SmartDC is enable or disabled by default.
///             If SmartDC is by default enabled, the value is 1, otherwise it is 0.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
ADL_EXTERNC int EXPOSED ADL2_SmartDC_Caps(ADL_CONTEXT_HANDLE context, int *lpSupported, int *lpDefault);

///
/// \brief \newAPI16 Function to retrieve the SmartDC status information.
/// 
/// This function retrieves SmartDC current status information from Driver.
/// \platform
/// \WIN10
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[out] lpSmartDCState The pointer to the integer of SmartDC current state flag.
///             If SmartDC currently is enabled , the value is 1, otherwise it is 0.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
ADL_EXTERNC int EXPOSED ADL2_SmartDC_Status_Get(ADL_CONTEXT_HANDLE context, int *lpSmartDCState);

///
/// \brief \newAPI16 Function to set SmartDC status.
/// 
/// This function enable/disable SmartDC from Driver.
/// \platform
/// \WIN10
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in] enable:  The integer of SmartDC state to be set to driver. 1: Reuqest to enable SmartDC; 0: Request to disable SmartDC.
/// \param[out] lpSmartDCState The pointer to the integer of SmartDC setted state flag. If SmartDC is enabled , the value is 1, otherwise it is 0.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
ADL_EXTERNC int EXPOSED ADL2_SmartDC_Status_Set(ADL_CONTEXT_HANDLE context, int enable, int *lpSmartDCState);

///
/// \brief \newAPI16 Function to retrieve the SmartDC active state information.
///
/// This function retrieves SmartDC current active stats information from Driver.
/// \platform
/// \WIN10
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[out] lpSmartDCState The pointer to the integer of SmartDC current state flag.
///             If SmartDC currently is enabled , the value is 1, otherwise it is 0.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
ADL_EXTERNC int EXPOSED ADL2_SmartDC_Active_State_Get(ADL_CONTEXT_HANDLE context, int* lpSmartDCActiveState);

///
/// \brief \newAPI16 return disk location of graphics driver that corresponds to given adapter index.
/// 
/// On the Windows 10 system with multiple GPUs it is possible to have different driver versions installed on for each GPU. 
/// Each GPU’s driver binaries will be located in dedicated disk location inside system’s driver store. 
/// This function can be used to find location of the driver for given GPU designated by its adapter index. 
/// \platform
/// \WIN10
/// \param[in]  context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in]  iAdapterIndex: The ADL index handle of the desired adapter.
/// \param[in]  iSize: size of lpDriverPath output buffer in the single byte characters.
/// \param[out] iSize: size of lpDriverPath output buffer in the single byte characters.
/// \return If the function succeeds, the return value is \ref ADL_OK, or an ADL error code otherwise. \ref define_adl_results
ADL_EXTERNC int EXPOSED ADL2_Driver_Path_Get(ADL_CONTEXT_HANDLE context, int iAdapterIndex, int iSize, char* lpDriverPath);
/// @}


#endif /* GRAPHICS_H_ */

