///
///  Copyright (c) 2008 - 2021 Advanced Micro Devices, Inc.

///  THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
///  EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
///  WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.

/// \file amd_desktop.h
/// \brief Contains AMD internal dopp-related definitions and functions for \ALL platforms.
///
///
/// This file contains all AMD internal desktop-related functions exposed by ADL for \ALL platforms.
/// All functions found in this file can be used as a reference to ensure
/// the specified function pointers can be used by the appropriate runtime
/// dynamic library loaders. This header file is for AMD internal use only.

#ifndef AMD_DESKTOP_H_
#define AMD_DESKTOP_H_


#ifndef ADL_EXTERNC
#ifdef __cplusplus
#define ADL_EXTERNC extern "C"
#else
#define ADL_EXTERNC
#endif
#endif

///
///\brief This function create the device.
/// 
/// \platform
/// \ALL
/// \param[in]   context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in]   iAdapterIndex The ADL index handle of the desired desktop.
/// \param[out]  pDevice The pointer to the device handle.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
ADL_EXTERNC int EXPOSED ADL2_Desktop_Device_Create(ADL_CONTEXT_HANDLE context, int iAdapterIndex, ADL_D3DKMT_HANDLE *pDevice);

///
///\brief This function destroy the device.
/// 
/// \platform
/// \ALL
/// \param[in]  context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in]  hDevice The device handle.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
ADL_EXTERNC int EXPOSED ADL2_Desktop_Device_Destroy(ADL_CONTEXT_HANDLE context, ADL_D3DKMT_HANDLE hDevice);

///
///\brief This function set the PFPA complete flag.
/// 
/// \platform
/// \ALL
/// \param[in]  context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in]  hDevice The device handle.
/// \param[in]   iAdapterIndex The ADL index handle of the desired desktop.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
ADL_EXTERNC int EXPOSED ADL2_Desktop_PFPAComplete_Set(ADL_CONTEXT_HANDLE context, ADL_D3DKMT_HANDLE hDevice, int iAdapterIndex);

///
///\brief This function get the PFPA status.
/// 
/// \platform
/// \ALL
/// \param[in]  context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in]  hDevice The device handle.
/// \param[in]   iAdapterIndex The ADL index handle of the desired desktop.
/// \param[out]  lpState The pointer to the PFPA state.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
ADL_EXTERNC int EXPOSED ADL2_Desktop_PFPAState_Get(ADL_CONTEXT_HANDLE context, ADL_D3DKMT_HANDLE hDevice, int iAdapterIndex, ADL_DOPP_PFPA_STATE *lpState);

///
///\brief This function get the DOPP Primary info.
/// 
/// \platform
/// \ALL
/// \param[in]  context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in]  hDevice The device handle.
/// \param[in]   iAdapterIndex The ADL index handle of the desired desktop.
/// \param[out]  lpPrimaryInfo The pointer to the DOPP Primary info.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
ADL_EXTERNC int EXPOSED ADL2_Desktop_PrimaryInfo_Get(ADL_CONTEXT_HANDLE context, ADL_D3DKMT_HANDLE hDevice, int iAdapterIndex, ADL_DOPP_PRIMARY_SURFACE_INFO *lpPrimaryInfo);

///
///\brief This function is to enable DOPP.
/// 
/// \platform
/// \ALL
/// \param[in]  context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in]  hDevice The device handle.
/// \param[in]   iAdapterIndex The ADL index handle of the desired desktop.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
ADL_EXTERNC int EXPOSED ADL2_Desktop_DOPP_Enable(ADL_CONTEXT_HANDLE context, ADL_D3DKMT_HANDLE hDevice, int iAdapterIndex);

///
///\brief This function is to enable DOPP.
/// 
/// \platform
/// \ALL
/// \param[in]  context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in]  hDevice The device handle.
/// \param[in]  iAdapterIndex The ADL index handle of the desired desktop.
/// \param[in]  iBlockDesktopRecording 0: desktop recording is allowed; 1: desktop recording is blocked  
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
ADL_EXTERNC int EXPOSED ADL2_Desktop_DOPP_EnableX2(ADL_CONTEXT_HANDLE context, ADL_D3DKMT_HANDLE hDevice, int iAdapterIndex, int iBlockDesktopRecording);

///
///\brief Function to get the PFPA status.
/// 
/// \platform
/// \ALL
/// \param[in]  context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in]  hDevice The device handle.
/// \param[in]   iAdapterIndex The ADL index handle of the desired desktop.
/// \param[out]  lpState The pointer to the DOPP state.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
ADL_EXTERNC int EXPOSED ADL2_Desktop_TextureState_Get(ADL_CONTEXT_HANDLE context, ADL_D3DKMT_HANDLE hDevice, int iAdapterIndex, ADL_DOPP_STATE *lpState);

///
///\brief Function to get the PFPA status.
/// 
/// \platform
/// \ALL
/// \param[in]  context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in]  hDevice The device handle.
/// \param[in]   iAdapterIndex The ADL index handle of the desired desktop.
/// \param[in]  enabled The texture status to set.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
ADL_EXTERNC int EXPOSED ADL2_Desktop_Texture_Enable(ADL_CONTEXT_HANDLE context, ADL_D3DKMT_HANDLE hDevice, int iAdapterIndex, int enabled);

///
///\brief Function to get desktop's fullscreen status.
/// 
/// \platform
/// \ALL
/// \param[in]  context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in]  hDevice The device handle.
/// \param[in]   iAdapterIndex The ADL index handle of the desired desktop.
/// \param[out]  exclusiveFlags The pointer to the fullscreen state.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
ADL_EXTERNC int EXPOSED ADL2_Desktop_ExclusiveModeX2_Get(ADL_CONTEXT_HANDLE context, ADL_D3DKMT_HANDLE hDevice, int iAdapterIndex, ADL_FULLSCREEN_STATUS_FLAGS* exclusiveFlags);

///
///\brief Function to enable the hardware cursor.
/// 
/// \platform
/// \ALL
/// \param[in]  context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in]  iAdapterIndex The ADL index handle of the desired desktop.
/// \param[in]  enabled The hardware cursor status to set.
/// \param[out] maxCursorWidth, maximum width of cursor
/// \param[out] maxCursorHeight, maximum height of cursor
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
ADL_EXTERNC int EXPOSED ADL2_Desktop_HardwareCursor_Toggle(ADL_CONTEXT_HANDLE context, int iAdapterIndex, int enabled, int *maxCursorWidth, int *maxCursorHeight);

///
///\brief Function to set the hardware cursor bitmap
/// 
/// \platform
/// \ALL
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in] iAdapterIndex The ADL index handle of the desired desktop.
/// \param[in] width, cursor bitmap width
/// \param[in] height, cursor bitmap height
/// \param[in] xHot, cursor hotspot location x
/// \param[in] yHot, cursor hotspot location y
/// \param[in] pixels, RGBA pixels, array size must be width*height*4
ADL_EXTERNC int EXPOSED ADL2_Desktop_HardwareCursor_SetBitmap(ADL_CONTEXT_HANDLE context, int iAdapterIndex, int width, int height, int xHot, int yHot, unsigned char* pixels);

///
///\brief Function to set the position of hardware cursor.
/// 
/// \platform
/// \ALL
/// \param[in]  context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in]   iAdapterIndex The ADL index handle of the desired desktop.
/// \param[in]  cursorX The X position os teh cursor.
/// \param[in]  cursorY The Y position os teh cursor.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
ADL_EXTERNC int EXPOSED ADL2_Desktop_HardwareCursor_SetPosition(ADL_CONTEXT_HANDLE context, int iAdapterIndex, int cursorX, int cursorY);

///
///\brief Function to get desktop's srcRect
/// 
/// \platform
/// \WIN10
/// \param[in]  context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in]  iAdapterIndex: The ADL index handle of the desired desktop.
/// \param[in]  iSourceId: The VidPnSourceId of the desktop to query
/// \param[out] pSrcRect: The pointer to the srcRect structure
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
ADL_EXTERNC int EXPOSED ADL2_Desktop_SrcRect_Get(ADL_CONTEXT_HANDLE context, int iAdapterIndex, int iSourceId, LPADLRect pSrcRect);

///
/// \brief Function to get the protected content status.
///
/// This function get the protected content status for a specified adapter and desktop.
/// \platform
/// \WIN
/// \param[in]  context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in] iAdapterIndex The ADL index handle of the desired adapter.
/// \param[in] iSourceId The VidPnSourceId of the desktop to query
/// \param[out] iProtected Protected content is active or not on the desktop
/// \param[out] iDisabled Protected content has been disabled by KMD on the desktop
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process .
/// Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
ADL_EXTERNC int EXPOSED ADL2_Desktop_ProtectedContent_Info_Get(ADL_CONTEXT_HANDLE context, int iAdapterIndex, int iSourceId, int* iProtected, int* iDisabled);

#endif /* AMD_DESKTOP_H_ */

