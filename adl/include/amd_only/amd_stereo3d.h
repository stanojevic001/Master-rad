///
///  Copyright (c) 2008 - 2021 Advanced Micro Devices, Inc.
 
///  THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
///  EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
///  WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.

/// \file amd_stereo3d.h
/// \brief This file contains the Stereo 3D method declarations used by the internal AMD Driver Library interfaces for \ALL platforms.
///

#ifndef __AMD_STEREO3D_H__
#define __AMD_STEREO3D_H__

#ifndef ADL_EXTERNC
#ifdef __cplusplus
#define ADL_EXTERNC extern "C"
#else
#define ADL_EXTERNC
#endif
#endif

/// \defgroup STEREO3D Constants and Definitions for Stereo3D
/// @{

/// \defgroup define_adl_stereo3dflag Definitions for Stereo3D: Bitvector of Stereo 3D Properties/Capabilities 
/// @{
/// 3D Sink mapped to given Logical Adapter
#define ADL_STEREO3DFLAG_3D_DEVICE_PRESENT                0x00000001
/// Frame Sequential 3D format supported in current mode
#define ADL_STEREO3DFLAG_CURRENTMODE_FRAMESEQ_SUPPORTED   0x00000002
/// Side-by-Side 3D format supported in current mode
#define ADL_STEREO3DFLAG_CURRENTMODE_SIDEBYSIDE_SUPPORTED 0x00000004
/// Top-and-Bottom 3D format supported in current mode
#define ADL_STEREO3DFLAG_CURRENTMODE_TOPBOTTOM_SUPPORTED  0x00000008
/// 3D Cusor supported 
#define ADL_STEREO3DFLAG_3D_CURSOR_SUPPORTED              0x00000010
/// @}

/// \defgroup define_adl_display_3dmode Definitions for Stereo3D: Bitvector of filtering modifiers (which type of modes to include) 
/// @{
/// Scanline 
#define ADL_DISPLAY_3DMODE_ENUMFLAG_PROGRESSIVE         0x00000001
/// Scanline 
#define ADL_DISPLAY_3DMODE_ENUMFLAG_INTERLACED          0x00000002 
/// Scaling Transformation
#define ADL_DISPLAY_3DMODE_ENUMFLAG_NOT_SCALED          0x00000004 
/// Scaling Transformation
#define ADL_DISPLAY_3DMODE_ENUMFLAG_CENTER_SCALED       0x00000008 
/// Scaling Transformation
#define ADL_DISPLAY_3DMODE_ENUMFLAG_ASPECTRATIO_SCALED  0x00000010 
/// Scaling Transformation
#define ADL_DISPLAY_3DMODE_ENUMFLAG_FULLSCREEN_SCALED   0x00000020 
/// Stereo 3D Format
#define ADL_DISPLAY_3DMODE_ENUMFLAG_3DFORMAT_FRAMESEQ   0x00000040 
/// Stereo 3D Format
#define ADL_DISPLAY_3DMODE_ENUMFLAG_3DFORMAT_SIDEBYSIDE 0x00000080 
/// Stereo 3D Format
#define ADL_DISPLAY_3DMODE_ENUMFLAG_3DFORMAT_TOPBOTTOM  0x00000100 
/// Orientation
#define ADL_DISPLAY_3DMODE_ENUMFLAG_ORIENTATION_0       0x00000200 
/// Orientation
#define ADL_DISPLAY_3DMODE_ENUMFLAG_ORIENTATION_90      0x00000400 
/// Orientation
#define ADL_DISPLAY_3DMODE_ENUMFLAG_ORIENTATION_180     0x00000800 
/// Orientation
#define ADL_DISPLAY_3DMODE_ENUMFLAG_ORIENTATION_270     0x00001000 
/// Color (pixel) format. 
/// If set:
///  1. All modes which differ only in color format, will be considered as the same mode, with a generic color format.
///  2. All returned modes will have color format set to \ref ADL_COLORFORMAT_GENERIC.
#define ADL_DISPLAY_3DMODE_ENUMFLAG_GENERIC_COLOR_FMT   0x00002000 
/// @}

/// \defgroup define_ADLColorFormat Definitions for Stereo3D: Dx/GDI color format. Part of ADL3DMode structure
/// @{
enum ADLColorFormat
{
    ADL_COLORFORMAT_UNKNOWN = 0,
    ADL_COLORFORMAT_R5G6B5,
    ADL_COLORFORMAT_A2B10G10R10_XR_BIAS,
    ADL_COLORFORMAT_A16B16G16R16F,
    ADL_COLORFORMAT_P8,
    ADL_COLORFORMAT_A8R8G8B8,
    ADL_COLORFORMAT_X8R8G8B8,
    ADL_COLORFORMAT_A8B8G8R8,
    ADL_COLORFORMAT_X8B8G8R8,
    ADL_COLORFORMAT_A2B10G10R10,
    ADL_COLORFORMAT_A2R10G10B10,
    ADL_COLORFORMAT_GENERIC     
};
/// @}

/// \defgroup define_ADLScaling Definitions for Stereo3D: Scaling transformation. Part of ADL3DMode structure
/// @{
enum ADLScaling
{
    ADL_SCALING_UNKNOWN = 0,
    ADL_SCALING_IDENTITY,
    ADL_SCALING_CENTERED,
    ADL_SCALING_ASPECTRATIO,
    ADL_SCALING_FULLSCREEN
};
/// @}

/// \defgroup define_ADLStereo3DFormat Definitions for Stereo3D: Stereo 3D format. Part of ADL3DMode structure
/// @{
enum ADLStereo3DFormat
{
    ADL_STEREO3DFORMAT_2D = 0,
    ADL_STEREO3DFORMAT_FRAMESEQ,
    ADL_STEREO3DFORMAT_SIDEBYSIDE,
    ADL_STEREO3DFORMAT_TOPBOTTOM
};
/// @}

/// \name ADL3DMode Structure containing information about display mode including Stereo 3D information
/// This structure is used to enumerated Stereo3D modes
/// This structure is used by the ADL_Stereo3D_Modes_Get() API
/// @{
typedef struct ADL3DMode
{
    /// Screen resolution Width.
    int   iXRes;
    /// Screen resolution Height.
    int   iYRes;
    /// Screen refresh rate. Could be fractional E.g. 59.97
    float fRefreshRate;
    /// 0=Progressive, 1=Interlaced
    int   iInterlaced;
    /// Screen orientation (e.g. 0, 90, 180, 270). Enum ADLAngle 
    int iOrientation;    
    /// Color Format. Enum ADLColorFormat 
    int   iColorFormat;
    /// Scaling Transformation. Enum ADLScaling 
    int   iScaling;
    /// Stereo 3D Format. Enum ADLStereo3DFormat 
    int   i3DFormat;
} ADL3DMode;
/// @}

/// @{
/// \brief Function to retrieve Stereo 3D properties
///
/// The function is used to retrieve Stereo 3D properties. 
/// These properties are dynamic and valid only in context of current logical adapter/display device
/// 
/// \platform
/// \VISTAWIN7
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in]  iAdapterIndex			The ADL index handle corresponding to Logical Adapter/Display Device
/// \param[out]	lpStereo3DFlags   		Bitvector definitions of Stereo 3D Properties/Capabilities. \ref define_adl_stereo3dflag
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
ADL_EXTERNC int EXPOSED ADL2_Stereo3D_Info_Get(ADL_CONTEXT_HANDLE context, int iAdapterIndex, int* lpStereo3DFlags );

/// \brief Function to retrieve Stereo 3D properties
///
/// The function is used to retrieve Stereo 3D properties. 
/// These properties are dynamic and valid only in context of current logical adapter/display device
/// 
/// \platform
/// \VISTAWIN7
/// \param[in]  iAdapterIndex			The ADL index handle corresponding to Logical Adapter/Display Device
/// \param[out]	lpStereo3DFlags   		Bitvector definitions of Stereo 3D Properties/Capabilities. \ref define_adl_stereo3dflag
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
ADL_EXTERNC int EXPOSED ADL_Stereo3D_Info_Get( int iAdapterIndex, int* lpStereo3DFlags );

/// \brief Function to enumerate Stereo 3D modes
///
/// The function is used to enumerate Stereo 3D modes. Stereo 3D Mode will include details relevant to DX and GDI32 applications.
/// This function will allocate required memory and assign *lppModes to point to this memory. It is caller responsibility to de-allocate the memory, 
/// if after function returns, *lppModes is not NULL, even if the function returned an error.
/// 
/// \platform
/// \VISTAWIN7
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in]  iAdapterIndex			The ADL index handle corresponding to Logical Adapter/Display Device
/// \param[in]  iEnumFlags   			Bitvector of filtering modifiers (which type of modes to include). \ref define_adl_display_3dmode
/// \param[out]	lpNumModes      		Pointer to the number of modes retrieved
/// \param[out]	lppModes          		Pointer to dynamically allocated array containing retrieved display modes with stereo3D info. Must be initialized to NULL.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
ADL_EXTERNC int EXPOSED ADL2_Stereo3D_Modes_Get(ADL_CONTEXT_HANDLE context, int iAdapterIndex, int iEnumFlags, int* lpNumModes, ADL3DMode** lppModes );

/// \brief Function to enumerate Stereo 3D modes
///
/// The function is used to enumerate Stereo 3D modes. Stereo 3D Mode will include details relevant to DX and GDI32 applications.
/// This function will allocate required memory and assign *lppModes to point to this memory. It is caller responsibility to de-allocate the memory, 
/// if after function returns, *lppModes is not NULL, even if the function returned an error.
/// 
/// \platform
/// \VISTAWIN7
/// \param[in]  iAdapterIndex			The ADL index handle corresponding to Logical Adapter/Display Device
/// \param[in]  iEnumFlags   			Bitvector of filtering modifiers (which type of modes to include). \ref define_adl_display_3dmode
/// \param[out]	lpNumModes      		Pointer to the number of modes retrieved
/// \param[out]	lppModes          		Pointer to dynamically allocated array containing retrieved display modes with stereo3D info. Must be initialized to NULL.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
ADL_EXTERNC int EXPOSED ADL_Stereo3D_Modes_Get( int iAdapterIndex, int iEnumFlags, int* lpNumModes, ADL3DMode** lppModes );

/// \brief Function to enable/disable Stereo 3D certain formats 
///
/// The function is used to enable/disable Stereo 3D certain formats. This interface can be used only for 3D formats which are packed by caller into single 2D frame. To disable Stereo 3D, ADL_3DFORMAT_2D should be passed as parameter. 
/// This is "set" interface complimented by ADL_Stereo3D_CurrentFormat_Get as "get" interface. However only 2D-packed format can be enabled using this interface, while the complimentary "get" will return information about current 3D format enabled (not necessary 2D-packed).
/// These properties are dynamic and valid only in context of current logical adapter/display device
/// 
/// \platform
/// \VISTAWIN7
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in]  iAdapterIndex			The ADL index handle corresponding to Logical Adapter/Display Device
/// \param[in]	iStereo3DFormat   		Requested Stereo 3D/2D format. \ref define_ADLStereo3DFormat
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
ADL_EXTERNC int EXPOSED ADL2_Stereo3D_2DPackedFormat_Set(ADL_CONTEXT_HANDLE context, int iAdapterIndex, int iStereo3DFormat );

/// \brief Function to enable/disable Stereo 3D certain formats 
///
/// The function is used to enable/disable Stereo 3D certain formats. This interface can be used only for 3D formats which are packed by caller into single 2D frame. To disable Stereo 3D, ADL_3DFORMAT_2D should be passed as parameter. 
/// This is "set" interface complimented by ADL_Stereo3D_CurrentFormat_Get as "get" interface. However only 2D-packed format can be enabled using this interface, while the complimentary "get" will return information about current 3D format enabled (not necessary 2D-packed).
/// These properties are dynamic and valid only in context of current logical adapter/display device
/// 
/// \platform
/// \VISTAWIN7
/// \param[in]  iAdapterIndex			The ADL index handle corresponding to Logical Adapter/Display Device
/// \param[in]	iStereo3DFormat   		Requested Stereo 3D/2D format. \ref define_ADLStereo3DFormat
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
ADL_EXTERNC int EXPOSED ADL_Stereo3D_2DPackedFormat_Set( int iAdapterIndex, int iStereo3DFormat );

/// \brief Function to retrieve currently enabled 3D format 
///
/// The function is used to retrieve currently enabled 3D format. 
/// These properties are dynamic and valid only in context of current logical adapter/display device
/// This is "get" interface is complimented by ADL_Stereo3D_2DPackedFormat_Set as "set" interface. However only 2D-packed format can be enabled using ADL_Stereo3D_2DPackedFormat_Set interface, while this function will return information about current 3D format enabled (not necessary 2D-packed). 
/// 
/// \platform
/// \VISTAWIN7
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in]  iAdapterIndex			The ADL index handle corresponding to Logical Adapter/Display Device
/// \param[out]	lpEnabledStereo3DFormat	Pointer to the currently enabled Stereo 3D format. \ref define_adl_stereo3dflag
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
ADL_EXTERNC int EXPOSED ADL2_Stereo3D_CurrentFormat_Get(ADL_CONTEXT_HANDLE context, int iAdapterIndex, int* lpEnabledStereo3DFormat );

/// \brief Function to retrieve currently enabled 3D format 
///
/// The function is used to retrieve currently enabled 3D format. 
/// These properties are dynamic and valid only in context of current logical adapter/display device
/// This is "get" interface is complimented by ADL_Stereo3D_2DPackedFormat_Set as "set" interface. However only 2D-packed format can be enabled using ADL_Stereo3D_2DPackedFormat_Set interface, while this function will return information about current 3D format enabled (not necessary 2D-packed). 
/// 
/// \platform
/// \VISTAWIN7
/// \param[in]  iAdapterIndex			The ADL index handle corresponding to Logical Adapter/Display Device
/// \param[out]	lpEnabledStereo3DFormat	Pointer to the currently enabled Stereo 3D format. \ref define_adl_stereo3dflag
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
ADL_EXTERNC int EXPOSED ADL_Stereo3D_CurrentFormat_Get( int iAdapterIndex, int* lpEnabledStereo3DFormat );
/// @}

/// @{
/// \brief Function to set stereo 3D cursor offset 
///
/// The function is used to set the 3D cursor's offset, 3D cursor will be enabled by setting non-zero offset. left offset means how much 
/// left the cursor shifted for the left frame while the right offset means how much right the cursor shifted for the right frame. 
/// if both left offset and right offset are zero, this means to disable 3D cursor.
/// 
/// \platform
/// \VISTAWIN7
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in]  iAdapterIndex			The ADL index handle corresponding to Logical Adapter/Display Device
/// \param[in]  iLeftOffset   			The left offset for the left frame, positive value, means how much left the cursor shifted for the left frame
/// \param[in]	iRightOffset      		The right offset for the right eye frame, positive value, means how much right the cursor shifted for the right frame.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
ADL_EXTERNC int EXPOSED ADL2_Stereo3D_3DCursorOffset_Set(ADL_CONTEXT_HANDLE context, int iAdapterIndex, int iLeftOffset, int iRightOffset);

/// \brief Function to set stereo 3D cursor offset 
///
/// The function is used to set the 3D cursor's offset, 3D cursor will be enabled by setting non-zero offset. left offset means how much 
/// left the cursor shifted for the left frame while the right offset means how much right the cursor shifted for the right frame. 
/// if both left offset and right offset are zero, this means to disable 3D cursor.
/// 
/// \platform
/// \VISTAWIN7
/// \param[in]  iAdapterIndex			The ADL index handle corresponding to Logical Adapter/Display Device
/// \param[in]  iLeftOffset   			The left offset for the left frame, positive value, means how much left the cursor shifted for the left frame
/// \param[in]	iRightOffset      		The right offset for the right eye frame, positive value, means how much right the cursor shifted for the right frame.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
ADL_EXTERNC int EXPOSED ADL_Stereo3D_3DCursorOffset_Set( int iAdapterIndex, int iLeftOffset, int iRightOffset);

/// \brief Function to get stereo 3D cursor offset. 
///
/// The function is used to get the current 3D cursor's offset. if the return left offset and right offset are both zero, this means
/// 3D cursor is disabled at current time.
/// 
/// \platform
/// \VISTAWIN7
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in]  iAdapterIndex			The ADL index handle corresponding to Logical Adapter/Display Device
/// \param[out]	pLeftOffset   		    Pointer to the left offset to get.
/// \param[out]	pRightOffset   		    Pointer to the right offset to get. 
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
ADL_EXTERNC int EXPOSED ADL2_Stereo3D_3DCursorOffset_Get(ADL_CONTEXT_HANDLE context, int iAdapterIndex, int* pLeftOffset, int* pRightOffset);

/// \brief Function to get stereo 3D cursor offset. 
///
/// The function is used to get the current 3D cursor's offset. if the return left offset and right offset are both zero, this means
/// 3D cursor is disabled at current time.
/// 
/// \platform
/// \VISTAWIN7
/// \param[in]  iAdapterIndex			The ADL index handle corresponding to Logical Adapter/Display Device
/// \param[out]	pLeftOffset   		    Pointer to the left offset to get.
/// \param[out]	pRightOffset   		    Pointer to the right offset to get. 
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
ADL_EXTERNC int EXPOSED ADL_Stereo3D_3DCursorOffset_Get( int iAdapterIndex, int* pLeftOffset, int* pRightOffset);
/// @}

#endif /* __AMD_STEREO3D_H__ */
