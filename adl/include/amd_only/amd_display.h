///
///  Copyright (c) 2008 - 2021 Advanced Micro Devices, Inc.

///  THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
///  EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
///  WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.

/// \file amd_display.h
/// \brief Contains all AMD internal display-related functions exposed by ADL for \ALL platforms.
///
/// This file contains all AMD internal display-related functions exposed by ADL for \ALL platforms.
/// All functions found in this file can be used as a reference to ensure
/// the specified function pointers can be used by the appropriate runtime
/// dynamic library loaders. This header file is for AMD internal use only.

#ifndef AMD_DISPLAY_H_
#define AMD_DISPLAY_H_

#ifndef ADL_EXTERNC
#ifdef __cplusplus
#define ADL_EXTERNC extern "C"
#else
#define ADL_EXTERNC
#endif
#endif


///
///\brief Function to retireve the vector of a display.
/// 
/// This function retrieves the vector of a specified display.
/// \platform
/// \ALL
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in]   iAdapterIndex The ADL index handle of the desired adapter.
/// \param[in]   iType The type of display.
/// \param[out]  lpVector The pointer to the retrieved vector of the specified display.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
ADL_EXTERNC int EXPOSED ADL2_Display_Vector_Get(ADL_CONTEXT_HANDLE context,int iAdapterIndex, int iType, int *lpVector);

///
///\brief Function to retireve the vector of a display.
/// 
/// This function retrieves the vector of a specified display.
/// \platform
/// \ALL
/// \param[in]   iAdapterIndex The ADL index handle of the desired adapter.
/// \param[in]   iType The type of display.
/// \param[out]  lpVector The pointer to the retrieved vector of the specified display.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
ADL_EXTERNC int EXPOSED ADL_Display_Vector_Get(int iAdapterIndex, int iType, int *lpVector);

///
///\brief Function to get index value of a display.
/// 
/// This function retrieves index value of a specified display.
/// \platform
/// \ALL
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in]   iAdapterIndex The ADL index handle of the desired adapter.
/// \param[in]   iDisplayIndex The desired display index. It can be retrieved from the ADLDisplayInfo data structure.
/// \param[out]  lpType The pointer to the display type.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
ADL_EXTERNC int EXPOSED ADL2_Display_EnumDisplays_Get(ADL_CONTEXT_HANDLE context,int iAdapterIndex, int iDisplayIndex, int * lpType);

///
///\brief Function to get index value of a display.
/// 
/// This function retrieves index value of a specified display.
/// \platform
/// \ALL
/// \param[in]   iAdapterIndex The ADL index handle of the desired adapter.
/// \param[in]   iDisplayIndex The desired display index. It can be retrieved from the ADLDisplayInfo data structure.
/// \param[out]  lpType The pointer to the display type.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
ADL_EXTERNC int EXPOSED ADL_Display_EnumDisplays_Get(int iAdapterIndex, int iDisplayIndex, int * lpType);

///
///\brief Function to override the EDID data for a display
/// 
/// This function overrides the EDID data for a specified display
/// \platform
/// \ALL
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in]   iAdapterIndex The ADL index handle of the desired adapter.
/// \param[in]   iDisplayIndex The desired display index. It can be retrieved from the ADLDisplayInfo data structure.
/// \param[in,out]  lpEDIDData The pointer to the ADLDisplayEDIDData structure storing the override EDID data.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
/// \remarks This API is in Prototype stage. Do not use for shipping products!
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
ADL_EXTERNC int EXPOSED ADL2_Display_EdidData_Set(ADL_CONTEXT_HANDLE context,int iAdapterIndex, int iDisplayIndex, ADLDisplayEDIDData *lpEDIDData);

///
///\brief Function to override the EDID data for a display
/// 
/// This function overrides the EDID data for a specified display
/// \platform
/// \ALL
/// \param[in]   iAdapterIndex The ADL index handle of the desired adapter.
/// \param[in]   iDisplayIndex The desired display index. It can be retrieved from the ADLDisplayInfo data structure.
/// \param[in,out]  lpEDIDData The pointer to the ADLDisplayEDIDData structure storing the override EDID data.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
/// \remarks This API is in Prototype stage. Do not use for shipping products!
ADL_EXTERNC int EXPOSED ADL_Display_EdidData_Set(int iAdapterIndex, int iDisplayIndex, ADLDisplayEDIDData *lpEDIDData);

///
///\brief Function to get audio mapping info associated with a display
/// 
/// This function retrieves audio mapping info associated with a display
/// \platform
/// \ALL
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in]   iAdapterIndex The ADL index handle of the desired adapter.
/// \param[in]   iDisplayIndex The desired display index. It can be retrieved from the ADLDisplayInfo data structure. -1 means retrieve all displays that belongs to the adapter
/// \param[in]   policy Indicate how the result AudioMappingInfo list is built. \ref define_audiomappinginfo_get_policy
/// \param[out]  lpNumAudioMappingInfos The pointer to the number of AduioMappingInfos returned
/// \param[out]  *lppAudioMappingInfos The pointer to an empty memory buffer(NULL).  This function will use the callback to allocate the appropriate buffer size.  This buffer will contain a list of AudioMappingInfos. If no AudioMappingInfos were found, this memory buffer will remain empty, or NULL.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
/// \remarks If explicit AdapterIndex and DisplayIndex are passed in (not -1), and the specific display is disabled, and the policy is AUDIO_MAPPING_INFO_GET_POLICY_NEAREST, the AudioMappingInfo for that display will be returned regardless whether the display supports audio or not.
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
ADL_EXTERNC int EXPOSED ADL2_Display_AudioMappingInfo_Get (ADL_CONTEXT_HANDLE context, int iAdapterIndex,
                                                           int iDisplayIndex,
                                                           AUDIO_MAPPING_INFO_GET_POLICY policy,
                                                           int* lpNumAudioMappingInfos,
                                                           AudioEndPointAssociationInfo** lppAudioMappingInfos);

///
///\brief Function to get audio mapping info associated with a display
/// 
/// This function retrieves audio mapping info associated with a display
/// \platform
/// \ALL
/// \param[in]   iAdapterIndex The ADL index handle of the desired adapter.
/// \param[in]   iDisplayIndex The desired display index. It can be retrieved from the ADLDisplayInfo data structure. -1 means retrieve all displays that belongs to the adapter
/// \param[in]   policy Indicate how the result AudioMappingInfo list is built. \ref define_audiomappinginfo_get_policy
/// \param[out]  lpNumAudioMappingInfos The pointer to the number of AduioMappingInfos returned
/// \param[out]  *lppAudioMappingInfos The pointer to an empty memory buffer(NULL).  This function will use the callback to allocate the appropriate buffer size.  This buffer will contain a list of AudioMappingInfos. If no AudioMappingInfos were found, this memory buffer will remain empty, or NULL.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
/// \remarks If explicit AdapterIndex and DisplayIndex are passed in (not -1), and the specific display is disabled, and the policy is AUDIO_MAPPING_INFO_GET_POLICY_NEAREST, the AudioMappingInfo for that display will be returned regardless whether the display supports audio or not.
ADL_EXTERNC int EXPOSED ADL_Display_AudioMappingInfo_Get ( int iAdapterIndex,
                                                          int iDisplayIndex,
                                                          AUDIO_MAPPING_INFO_GET_POLICY policy,
                                                          int* lpNumAudioMappingInfos,
                                                          AudioEndPointAssociationInfo** lppAudioMappingInfos);




///
///\brief Function to get audio mapping info associated with a given screen coordiante
/// 
/// This function retrieves audio mapping info associated with a given screen coordiante
/// \platform
/// \ALL
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in]   iLeft The x screen coordinate with respect to global system screen space (left top corner of primary desktop is 0,0).
/// \param[in]   iTop The y screen coordinate with respect to global system screen space (left top corner of primary desktop is 0,0).
/// \param[in]   policy Indicate how the result AudioMappingInfo list is built. \ref define_audiomappinginfo_get_policy
/// \param[out]  lpNumAudioMappingInfos The pointer to the number of AduioMappingInfos returned
/// \param[out]  *lppAudioMappingInfos The pointer to an empty memory buffer(NULL).  This function will use the callback to allocate the appropriate buffer size.  This buffer will contain a list of AudioMappingInfos. If no AudioMappingInfos were found, this memory buffer will remain empty, or NULL.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
ADL_EXTERNC int EXPOSED ADL2_ScreenPoint_AudioMappingInfo_Get (ADL_CONTEXT_HANDLE context, int iLeft,
                                                               int iTop,
                                                               AUDIO_MAPPING_INFO_GET_POLICY policy,
                                                               int* lpNumAudioMappingInfos,
                                                               AudioEndPointAssociationInfo** lppAudioMappingInfos);

///
///\brief Function to get audio mapping info associated with a given screen coordiante
/// 
/// This function retrieves audio mapping info associated with a given screen coordiante
/// \platform
/// \ALL
/// \param[in]   iLeft The x screen coordinate with respect to global system screen space (left top corner of primary desktop is 0,0).
/// \param[in]   iTop The y screen coordinate with respect to global system screen space (left top corner of primary desktop is 0,0).
/// \param[in]   policy Indicate how the result AudioMappingInfo list is built. \ref define_audiomappinginfo_get_policy
/// \param[out]  lpNumAudioMappingInfos The pointer to the number of AduioMappingInfos returned
/// \param[out]  *lppAudioMappingInfos The pointer to an empty memory buffer(NULL).  This function will use the callback to allocate the appropriate buffer size.  This buffer will contain a list of AudioMappingInfos. If no AudioMappingInfos were found, this memory buffer will remain empty, or NULL.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
ADL_EXTERNC int EXPOSED ADL_ScreenPoint_AudioMappingInfo_Get ( int iLeft,
                                                              int iTop,
                                                              AUDIO_MAPPING_INFO_GET_POLICY policy,
                                                              int* lpNumAudioMappingInfos,
                                                              AudioEndPointAssociationInfo** lppAudioMappingInfos);


///
///\brief  AMD internall call only .Function to set scaling configuration
/// 
/// This function sets an enhenced scaling configuration
/// \platform
/// \ALL
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in]   iAdapterIndex The ADL index handle of the desired adapter.
/// \param[in]   iControllerIndex 
/// \param[in]   *pScaling The pointer to an structure which describes the requested scaling configuration
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results											   
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
ADL_EXTERNC int EXPOSED ADL2_DisplayScaling_Set (ADL_CONTEXT_HANDLE context, int iAdapterIndex, int iControllerIndex, const ADLMMDisplayScaling* pScaling);

///
///\brief  AMD internall call only .Function to set scaling configuration
/// 
/// This function sets an enhenced scaling configuration
/// \platform
/// \ALL
/// \param[in]   iAdapterIndex The ADL index handle of the desired adapter.
/// \param[in]   iControllerIndex 
/// \param[in]   *pScaling The pointer to an structure which describes the requested scaling configuration
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results											   
ADL_EXTERNC int EXPOSED ADL_DisplayScaling_Set ( int iAdapterIndex, int iControllerIndex, const ADLMMDisplayScaling* pScaling);

///
///\brief Function to get Container ID per display.
/// 
/// This function retrieves Container ID for a specified display.
/// \platform
/// \WIN7 and Above
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in]   iAdapterIndex The ADL index handle of the desired adapter.
/// \param[in]   displayID The desired DisplayID structure for a  display.
/// \param[out]  lpDisplayContainerID The pointer to the retrieved containerID.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
ADL_EXTERNC int EXPOSED ADL2_Display_ContainerID_Get(ADL_CONTEXT_HANDLE context,int iAdapterIndex, ADLDisplayID displayID, ADLGUID* lpDisplayContainerID);

///
///\brief Function to get Container ID per display.
/// 
/// This function retrieves Container ID for a specified display.
/// \platform
/// \WIN7 and Above
/// \param[in]   iAdapterIndex The ADL index handle of the desired adapter.
/// \param[in]   displayID The desired DisplayID structure for a  display.
/// \param[out]  lpDisplayContainerID The pointer to the retrieved containerID.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
ADL_EXTERNC int EXPOSED ADL_Display_ContainerID_Get(int iAdapterIndex, ADLDisplayID displayID, ADLGUID* lpDisplayContainerID);

///
/// \brief Function to inform the driver that overlap adjustment will start or is done. In MGPU SLS case, driver should get this prior notification about dynamic viewports adjustments.
/// 
///
/// \platform
/// \WIN7 and above
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in] iAdapterIndex                The ADL index of the desired adapter. This function does not support -1.
/// \param[in] iOverlapAdjustmentInProgress The state of overlap adjustment. possiable values 0 or 1, 1 = Overlap adjustment started, 0 = Overlap adjusment is completed or cancelled
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
/// 
/// \remarks Call ADL_Flush_Driver_Data() after to persist settings on reboot.
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
ADL_EXTERNC int EXPOSED ADL2_Display_Overlap_NotifyAdjustment (ADL_CONTEXT_HANDLE context,int iAdapterIndex, 
									 int iOverlapAdjustmentInProgress);


///
///\brief Function to query whether a display is virtual
/// 
/// This function retrieves whether a display is virtual
/// \platform
/// \WIN7 and above
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[in]  iDisplayIndex The desired display index. 
/// \param[out] pIsVirtualDisplay The pointer to the bool whose value is set to true if the display is virtual
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results 
ADL_EXTERNC int EXPOSED ADL2_Display_IsVirtual_Get(ADL_CONTEXT_HANDLE context, int iAdapterIndex, int iDisplayIndex, bool *pIsVirtualDisplay);

///
///\brief Function to set the remote play control flags
/// 
/// This function sets the remote play control flag and display off state which is set in mobile client.
/// The function will be called whenever there is a change in remote streaming session change - i.e when the session is created or destroyed.
/// \platform
/// \Win7 and above
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in] iRemotePlayControlState The flag is set to true when remote streaming session is created. Else, it is set to false. 
/// \param[in] iDisplayOffControlState The flag is set to true when display off state is enabled by user. Else, it is set to false. 
/// \param[in] evntHandle: Reference to the event object that will be set by the driver when corresponding event occurs in the system. Client obtains the handle using Win32 CreateEvent API.
/// \param[out] iEnableDisplayEmulation Flag to inform that if display emulation is needed or not based on physical display connectivity. 
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results 
ADL_EXTERNC int EXPOSED ADL2_RemotePlay_ControlFlags_Set(ADL_CONTEXT_HANDLE context, ADL_D3DKMT_HANDLE hDevice, int iRemotePlayControlState, int iDisplayOffControlState, void* evntHandle, int* iEnableDisplayEmulation);


///
///\brief Function to query whether CVDC is supported
/// 
/// This function retrieves whether CVDC is supported by the display
/// \platform
/// \ALL
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in] iAdapterIndex The ADL index handle of the desired adapter. A value of -1 retrieves all modes for the system across multiple GPUs.
/// \param[in] iDisplayIndex The desired display index. If the index is -1, this field is ignored.
/// \param[out] lpSupported The pointer to the value indicating whether CVDC is supported. 1: CVDC is supported. 0: CVDC is not supported.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results 
ADL_EXTERNC int EXPOSED ADL2_Display_CVDC_Supported(ADL_CONTEXT_HANDLE context, int iAdapterIndex, int iDisplayIndex, int* lpSupported);

///
///\brief Function to retrieve CVDC adjustment info values
/// 
/// This function retrieves the min/max/step/default values for the provided CVDC setting
/// \platform
/// \ALL
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in] iAdapterIndex The ADL index handle of the desired adapter. A value of -1 retrieves all modes for the system across multiple GPUs.
/// \param[in] iDisplayIndex The desired display index. If the index is -1, this field is ignored.
/// \param[in] setting The CVDC info type requested.
/// \param[out] lpInfoOut The pointer to the adjustment info struct where output is received.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
ADL_EXTERNC int EXPOSED ADL2_Display_CVDC_Caps(ADL_CONTEXT_HANDLE context, int iAdapterIndex, int iDisplayIndex, ADLCVDCSetting setting, ADLAdjustmentinfo* lpInfoOut);

///
///\brief Function to get the adjustment value of a CVDC setting
/// 
/// This function retrieves the adjustment data value of the provided CVDC type.
/// \platform
/// \ALL
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in] iAdapterIndex The ADL index handle of the desired adapter. A value of -1 retrieves all modes for the system across multiple GPUs.
/// \param[in] iDisplayIndex The desired display index. If the index is -1, this field is ignored.
/// \param[in] setting The CVDC info type requested.
/// \param[out] lpValue The pointer to the adjustment value.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
ADL_EXTERNC int EXPOSED ADL2_Display_CVDC_Get(ADL_CONTEXT_HANDLE context, int iAdapterIndex, int iDisplayIndex, ADLCVDCSetting setting, int* lpValue);

///\brief Function to set the adjustment value of a CVDC setting
/// 
/// This function sets the adjustment data value of the provided CVDC type to the given value.
/// \platform
/// \ALL
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in] iAdapterIndex The ADL index handle of the desired adapter. A value of -1 retrieves all modes for the system across multiple GPUs.
/// \param[in] iDisplayIndex The desired display index. If the index is -1, this field is ignored.
/// \param[in] setting The CVDC info type requested.
/// \param[in] value The value to set the adjustment to.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
ADL_EXTERNC int EXPOSED ADL2_Display_CVDC_Set(ADL_CONTEXT_HANDLE context, int iAdapterIndex, int iDisplayIndex, ADLCVDCSetting setting, int value);

///
///\brief Function to query SCE support information
/// 
/// This function retrieves the supported SCE profiles
/// \platform
/// \ALL
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in] iAdapterIndex The ADL index handle of the desired adapter. A value of -1 retrieves all modes for the system across multiple GPUs.
/// \param[in] iDisplayIndex The desired display index. If the index is -1, this field is ignored.
/// \param[out] lpSupported The pointer to the supported profiles for SCE.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results 
ADL_EXTERNC int EXPOSED ADL2_Display_SCE_Supported(ADL_CONTEXT_HANDLE context, int iAdapterIndex, int iDisplayIndex, ADLSCEProfile* lpSupported);

///
///\brief Function to retrieve SCE state information
/// 
/// This function retrieves the current and default SCE state
/// \platform
/// \ALL
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in] iAdapterIndex The ADL index handle of the desired adapter. A value of -1 retrieves all modes for the system across multiple GPUs.
/// \param[in] iDisplayIndex The desired display index. If the index is -1, this field is ignored.
/// \param[out] lpCurrent The current per-Display setting.
/// \param[out] lpDefault The default setting that should be used in case user does factory reset.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results 
ADL_EXTERNC int EXPOSED ADL2_Display_SCE_State_Get(ADL_CONTEXT_HANDLE context, int iAdapterIndex, int iDisplayIndex, ADLSCEProfile* lpCurrent, ADLSCEProfile* lpDefault);

///
///\brief Function to set SCE state
/// 
/// This function sets SCE state to the desired value
/// \platform
/// \ALL
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in] iAdapterIndex The ADL index handle of the desired adapter. A value of -1 retrieves all modes for the system across multiple GPUs.
/// \param[in] iDisplayIndex The desired display index. If the index is -1, this field is ignored.
/// \param[out] settubg The new setting Driver needs to apply.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results 
ADL_EXTERNC int EXPOSED ADL2_Display_SCE_State_Set(ADL_CONTEXT_HANDLE context, int iAdapterIndex, int iDisplayIndex, ADLSCEProfile setting);

#endif /* AMD_DISPLAY_H_ */
