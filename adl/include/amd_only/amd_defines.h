//
//  Copyright (c) 2008 - 2021 Advanced Micro Devices, Inc.
 
//  THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
//  EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
//  WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.

/// \file amd_defines.h
/// \brief Contains all definitions used by the internal AMD Driver Library interfaces for \ALL platforms.
///
/// This file contains all definitions used by internal AMD.
///

#ifndef AMD_DEFINES_H_
#define AMD_DEFINES_H_

#ifndef ADL_DEFINES_H_
#include "adl_defines.h"
#endif

/// \defgropup define_audiomappinginfo_get_policy
/// Used in ADL_Display_AudioMappingInfo_Get and ADL_ScreenPoint_AudioMappingInfo_Get
/// to indicate how the result AudioMappingInfo list is built.
/// @{
typedef enum AUDIO_MAPPING_INFO_GET_POLICY
{
    /// Audio mapping that exactly match input criteria will be returned
    AUDIO_MAPPING_INFO_GET_POLICY_EXACT		= 0,
    /// Audio mapping that is nearest in distance will be returned
    AUDIO_MAPPING_INFO_GET_POLICY_NEAREST	= 1
} AUDIO_MAPPING_INFO_GET_POLICY;
/// @}

///////////////////////////////////////////////////////////////////////////
// ADLChannelName Enumeration
// These channel names are given in OS domain
///////////////////////////////////////////////////////////////////////////
enum ADLChannelName 
{
    ADLChannel_L             = 0, 
    ADLChannel_R             = 1, 
    ADLChannel_C             = 2,			
    ADLChannel_Sub           = 3, 				
    ADLChannel_RL            = 4, 
    ADLChannel_RR            = 5, 
    ADLChannel_SL            = 6, 
    ADLChannel_SR            = 7, 
    ADLChannel_Silent        = 8, 
    ADLChannel_NoAssociation = 15
};

///////////////////////////////////////////////////////////////////////////
// ADLEncodingFormat Enumeration
///////////////////////////////////////////////////////////////////////////
enum ADLEncodingFormat
{
    ADLEncodingFormat_LPCM = 0,
    ADLEncodingFormat_AC3,
    ADLEncodingFormat_MPEG1, 
    ADLEncodingFormat_MP3, 
    ADLEncodingFormat_MPEG2, 
    ADLEncodingFormat_AAC, 
    ADLEncodingFormat_DTS, 
    ADLEncodingFormat_ATRAC, 
    ADLEncodingFormat_DOLBYDIGITALPLUS, 
    ADLEncodingFormat_DTSHD, 
    ADLEncodingFormat_DOLBYTRUEHD, 
    ADLEncodingFormat_WMAPRO
};

///////////////////////////////////////////////////////////////////////////
// ADLChannelFormat Enumeration
///////////////////////////////////////////////////////////////////////////
enum ADLChannelFormat
{
    ADLChannelFormat_2P0 = 0, 
    ADLChannelFormat_2P1, 
    ADLChannelFormat_5P1, 
    ADLChannelFormat_7P1
};

///////////////////////////////////////////////////////////////////////////
// ADLBitsPerSample Enumeration
///////////////////////////////////////////////////////////////////////////
enum ADLBitsPerSample
{
    ADLBitsPerSample_16BPS = 0,
    ADLBitsPerSample_20BPS,
    ADLBitsPerSample_24BPS 
};


// Appprofile property name defines
// This are used to fill profile property name, which is used when creating profile by function - ADL_ApplicationProfiles_Profile_Create
#define AP_Main3D          "Main3D"
#define AP_ANTIALIAS          "AntiAlias"
#define AP_ANTIALIASMPLS          "AntiAliasSmpls"		// OGL_ACEFULLSCENEAASCALE
#define AP_ANISOTYPE         "AnisoType"
#define AP_ANISODEGREE         "AnisoDegree"			// OGL_ACEMAXANISOTROPY
#define AP_AREAANISO         "AreaAniso"
#define AP_TEXTURELOD          "TextureLod"			// OGL_ACELODBIAS
#define AP_VSYNCNAME          "VSyncName"
#define AP_VSNCCONTROL          "VSyncControl"			// OGL_ACEWAITVERTICALSYNC
#define AP_ENABLETRPLBFFR          "EnableTrplBffr"
#define AP_TMPRLAAMLTPLR          "TmprlAAMltplr"
#define AP_CATALYSTAI        "CatalystAI"				// OGL_ACECATALYSTAI
#define AP_GI          "GI"
#define AP_ASTT         "ASTT"							// OGL_ACE_ADAPTIVEAA_ALPHATESTEDTEX
#define AP_ADAPTIVEAAMETH           "AdaptiveAAMeth"
#define AP_ASD           "ASD"							// OGL_ACE_ADAPTIVEAA_DIVISOR
#define AP_ATMS           "ATMS"
#define AP_AAF           "AAF"				// OGL_ACEAAFILTER
#define AP_ASE           "ASE"				// OGL_ACE_ADAPTIVEAA_SUPERSAMPLING
#define AP_MLF           "MLF"
#define AP_SRFCFRMTRPLCMNT           "SrfcFrmtRplcmnt"
#define AP_TFQ           "TFQ"
#define AP_EQAA           "EQAA"			// OGL_ACEENABLEEQAA
#define AP_TESSELLATION           "Tessellation"
#define AP_MVPU           "MVPU"			// OGL_ACE_MVPU
#define AP_DISPLAYCFLO           "DisplayCFLo"
#define AP_TESSELLATION_OP           "Tessellation_OP"
#define AP_CFM           "CFM"
#define AP_CFM_EXE           "CFM_EXE"
#define AP_ASICNAME           "ASICName"
#define AP_SMTHVISIONNAME          "SmthVisionName"
#define AP_AASET           "AASet"
#define AP_AAMAPPINGSET           "AAMappingSet"
#define AP_EQAASUPPORTED           "EQAASupported"
#define AP_EQAASET          "EQAASet"
#define AP_EQAAMAPPINGSET           "EQAAMappingSet"
#define AP_AAFMAPPINGSET           "AAFMappingSet"
#define AP_AAFVALUESET           "AAFValueSet"
#define AP_AFHQAVAILABLE           "AFHQAvailable"
#define AP_AAMODESUPPORTED           "AAModeSupported"
#define AP_AAASUPPORTED           "AAASupported"
#define AP_SSAAADEF           "SSAAADef"
#define AP_MSAAADEF           "MSAAADef"

/// The bit mask identifies SLS map is active (this should be moved to group define_eyefinity_constants)
#define ADL_DISPLAY_SLSMAP_ACTIVE	0x00000001
#define ADL_TARGETHANDLE_MASK_Win10 0X00FFFFFF
#define ADL_TARGETHANDLE_MASK_WinB 0XFFFFFFFF
// following definitions are used for SDI feature implementation
/// SDI off state
#define ADL_SDI_OFF 0
/// SDI on state
#define ADL_SDI_ON 1

#define ADL_ERR_APL_AREA_MISSING -13
#define ADL_ERR_APL_FORBIDDEN -14
#define ADL_ERR_APL_PROFILE_MISSING -15
#define ADL_ERR_APL_PROPERTY_MISSING -16
#define ADL_ERR_APL_APPLICATION_MISSING -17
#define ADL_ERR_APL_DUPLICATED_PROFILE -18
#define ADL_ERR_APL_UNEXPECTED_TYPE -19


/// \defgroup define_maximizewindowmode_values
/// Used by \ref ADL_MaximizeWindowMode_Get and \ref ADL_MaximizeWindowMode_Get functions
/// @{
/// Maximize windows to the display border in which they reside
#define ADL_MAXIMIZEWINDOWMODE_DISPLAY 0
/// Maximize windows to the entire desktop area (X Screen) even if multiple displays are configured on the desktop.
#define ADL_MAXIMIZEWINDOWMODE_DESKTOP 1
/// @}

/// \name Definitions for iFlag parameter in the \ref AdapterExtInfo structure
/// @{
/// Indicates that iMaxSurfaceWidth and iMaxSurfaceHeight contains valid information
#define ADL_EXTINFO_MAXSURFACE (1 << 0)
/// @}

/// \name Definitions for iVideoItemIndex parameter in the \ref ADLMMVideoSetData structure
/// @{
#define ADL_ADJUST_PROPERTY_Brightness				0
#define ADL_ADJUST_PROPERTY_Contrast				1
#define ADL_ADJUST_PROPERTY_Hue						2
#define ADL_ADJUST_PROPERTY_Saturation				3
#define ADL_ADJUST_PROPERTY_Gamma					4
#define ADL_ADJUST_PROPERTY_InvGamma				5
#define ADL_ADJUST_PROPERTY_PullDown				6
#define ADL_ADJUST_PROPERTY_TrueWhite				7
#define ADL_ADJUST_PROPERTY_Denoise					8
#define ADL_ADJUST_PROPERTY_Detail					9
#define ADL_ADJUST_PROPERTY_ColorVibrance			10
#define ADL_ADJUST_PROPERTY_Fleshtone				11
#define ADL_ADJUST_PROPERTY_DynamicContrast			12
#define ADL_ADJUST_PROPERTY_LRTC					13
#define ADL_ADJUST_PROPERTY_FrameRateConv			14
#define ADL_ADJUST_PROPERTY_BlueStretch				15
#define ADL_ADJUST_PROPERTY_StaticGamma				16
#define ADL_ADJUST_PROPERTY_DynamicRange			17
#define ADL_ADJUST_PROPERTY_OverridePA				18
#define ADL_ADJUST_PROPERTY_DemoMode				19
#define ADL_ADJUST_PROPERTY_Deblocking				20
#define ADL_ADJUST_PROPERTY_MosquitoNoiseRemoval	21
#define ADL_ADJUST_PROPERTY_InternetVideo			22
/// @}



/// Indicates that an actual value is not being passed in
#define ADL_UNSET -1

///////////////////////////////////////////////////////////////////////////
// ADL_ADAPTER_CAPS Definitions 
// for ADLAdapterCaps.iCapsMask and ADLAdapterCaps.iCapsValue
// (bit-vector)
///////////////////////////////////////////////////////////////////////////
/// \defgroup define_adapter_caps Adapter Caps Mask Values
/// @{
#define ADL_ADAPTERCAPS_LDADISPLAY_SUPPORT 0x0001 //LDA support(local display)
#define ADL_ADAPTERCAPS_SINGLEGPUSLS_SUPPORT 0x0002 //Single GPU SLS support
#define ADL_ADAPTERCAPS_MULTIPLEGPUSLS_SUPPORT 0x0004 //Multiple GPU SLS support
#define ADL_ADAPTERCAPS_DYMSURFRESIZE_SUPPORT 0x0008 //Dynamic surface resizing support, LINUX only
#define ADL_ADAPTERCAPS_LOCALDISPLAY_CAPABLE 0x0010 // LDA capable (local display)
// Mixed mode SLS Caps
#define ADL_ADAPTERCAPS_SLSBUILDER_SUPPORT 0x0020 // SLS Builder Support
#define ADL_ADAPTERCAPS_MIXEDMODESLS_SUPPORT 0x0040 // Mixed mode SLS Support
#define ADL_ADAPTERCAPS_DISPLAYROTATIONSLS_SUPPORT 0x0080 // Display rotation SLS Support
#define ADL_ADAPTERCAPS_DESKTOPROTATIONSLS_SUPPORT 0x0100 // Desktop rotation SLS Support
#define ADL_ADAPTERCAPS_MULTIPLEGPUSLS_CAPABLE_PLATFORM 0x0200 // Multiple GPU SLS capable platform
/// @}

///////////////////////////////////////////////////////////////////////////
// ADL_ADAPTER_INFOX2 Definitions 
// for AdapterInfoX2.iInfoMask and AdapterInfoX2.iInfoValue
// (bit-vector)
///////////////////////////////////////////////////////////////////////////
/// \defgroup define_adapter_info Adapter Info Mask Values
/// @{
#define ADL_ADAPTER_INFO_EXTERNAL	0x0001	//External GPU in a detachable graphics platform
/// @}

/// \defgroup define_identify_caps Identify Display capabilities
/// @{
/// When this is set, the watermark uses a special hardware cursor to display itself; thus allowing both the
/// hardware mouse cursor icon and the watermark to be visible at the same time. When the watermark is visible,
/// it will remain visible until \ref ADL_DisplayIdentifyDisplay_Set is called to hide it.
/// When this is net set, the watermark uses the hardware cursor icon to display itself. In this situation, only the mouse
/// cursor or the watermark can be visible at any one time. When the watermark is visible, it will remain visible until
/// \ref ADL_DisplayIdentifyDisplay_Set is called to hide it, or by moving the mouse.
#define ADL_IDENTIFYDISPLAY_CAPS_HWCURSOR (1<<0)
/// @}

/// \defgroup define_identify_watermark Special Identify Display watermark symbols
/// @{
/// Value for the identify display exclamation watermark
#define ADL_IDENTIFYDISPLAY_SHOW_EXCLAMATION 0xFFFFFFFF
/// Value for the identify display checkmark watermak
#define ADL_IDENTIFYDISPLAY_SHOW_CHECKMARK 0xFFFFFFFE
/// @}

/// \defgroup define_identify_flag ADLIdentiFyDisplay field flags
/// @{
/// Indicates that the Show field is valid in the \ref ADLIdentifyDisplay structure
#define ADL_IDENTIFY_FLAG_SHOW (1<<0)
/// Indicates that the WatermarkID field is valid in the \ref ADLIdentifyDisplay structure
#define ADL_IDENTIFY_FLAG_WATERMARKID (1<<1)
/// Indicates that the POSX field is valid in the \ref ADLIdentifyDisplay structure
#define ADL_IDENTIFY_FLAG_POSX (1<<2)
/// Indicates that the POSY field is valid in the \ref ADLIdentifyDisplay structure
#define ADL_IDENTIFY_FLAG_POSY (1<<3)
/// @}

/// \defgroup defines for Mirabilis
/// These defines are used for the Mirabilis feature
/// @{
/// Indicates the maximum number of audio configurations  
#define ADL_MAX_AUDIO_CONFIG                               16
/// Indicates an invalid audio delay
#define ADL_APO_AUDIO_DELAY_INVALID                        0

/// Indicates the encoding format capability for LPCM
#define  ADL_ENCODINGFORMAT_CAP_LPCM                       0x000000001L
/// Indicates the encoding format capability for AC3
#define  ADL_ENCODINGFORMAT_CAP_AC3                        0x000000002L
/// Indicates the encoding format capability for MPEG1
#define  ADL_ENCODINGFORMAT_CAP_MPEG1                      0x000000004L
/// Indicates the encoding format capability for MP3
#define  ADL_ENCODINGFORMAT_CAP_MP3                        0x000000008L
/// Indicates the encoding format capability for MPEG2
#define  ADL_ENCODINGFORMAT_CAP_MPEG2                      0x000000010L
/// Indicates the encoding format capability for AAC
#define  ADL_ENCODINGFORMAT_CAP_AAC                        0x000000020L
/// Indicates the encoding format capability for DTS
#define  ADL_ENCODINGFORMAT_CAP_DTS                        0x000000040L
/// Indicates the encoding format capability for ATRAC
#define  ADL_ENCODINGFORMAT_CAP_ATRAC                      0x000000080L
/// Indicates the encoding format capability for DOLBYDIGITALPLUS
#define  ADL_ENCODINGFORMAT_CAP_DOLBYDIGITALPLUS           0x000000100L
/// Indicates the encoding format capability for DTSHD
#define  ADL_ENCODINGFORMAT_CAP_DTSHD                      0x000000200L
/// Indicates the encoding format capability for DOLBYTRUEHD
#define  ADL_ENCODINGFORMAT_CAP_DOLBYTRUEHD                0x000000400L
/// Indicates the encoding format capability for WMAPRO
#define  ADL_ENCODINGFORMAT_CAP_WMAPRO                     0x000000800L

/// Indicates the audio sample rate capability for 32 kHz
#define  ADL_SAMPLERATE_CAP_32KHz                          0x000000001L
/// Indicates the audio sample rate capability for 44.1 kHz
#define  ADL_SAMPLERATE_CAP_44P1KHz                        0x000000002L
/// Indicates the audio sample rate capability for 48 kHz
#define  ADL_SAMPLERATE_CAP_48KHz                          0x000000004L
/// Indicates the audio sample rate capability for 88.2 kHz
#define  ADL_SAMPLERATE_CAP_88P2KHz                        0x000000008L
/// Indicates the audio sample rate capability for 96 kHz
#define  ADL_SAMPLERATE_CAP_96KHz                          0x000000010L
/// Indicates the audio sample rate capability for 176.4 kHz
#define  ADL_SAMPLERATE_CAP_176P4KHz                       0x000000020L
/// Indicates the audio sample rate capability for 192 kHz
#define  ADL_SAMPLERATE_CAP_192KHz                         0x000000040L
/// Indicates the audio sample rate capability for 384 kHz
#define  ADL_SAMPLERATE_CAP_384KHz                         0x000000080L

#define ADL_SAMPLERATE_CAP_MASK (ADL_SAMPLERATE_CAP_32KHz | ADL_SAMPLERATE_CAP_44P1KHz | ADL_SAMPLERATE_CAP_48KHz | ADL_SAMPLERATE_CAP_88P2KHz | ADL_SAMPLERATE_CAP_96KHz | ADL_SAMPLERATE_CAP_176P4KHz | ADL_SAMPLERATE_CAP_192KHz  | ADL_SAMPLERATE_CAP_384KHz);


/// Indicates capability for 16 bits per sample
#define ADL_BITSPERSAMPLE_CAP_16BPS                        0x00000001L
/// Indicates capability for 20 bits per sample
#define ADL_BITSPERSAMPLE_CAP_20BPS                        0x00000010L
/// Indicates capability for 24 bits per sample
#define ADL_BITSPERSAMPLE_CAP_24BPS                        0x00000100L
#define ADL_BITSPERSAMPLE_CAP_MASK  ( ADL_BITSPERSAMPLE_CAP_16BPS| ADL_BITSPERSAMPLE_CAP_20BPS| ADL_BITSPERSAMPLE_CAP_24BPS)

/// Indicates that the GTC group index is disabled
#define ADL_DISPLAY_GTC_GROUPINDEX_DISABLED                0
///@}


/// \defgroup defines for Mixed Mode SLS
/// These defines are used for the mixed mode SLS feature
/// @{
#define ADL_DESKTOPCAPS_SAMEMODESLS                                         0x0001
#define ADL_DESKTOPCAPS_MIXEDMODESLS                                        0x0002
#define ADL_DESKTOPCAPS_DISPLAYROTATIONSLS                                  0x0004
#define ADL_DESKTOPCAPS_DESKTOPROTATIONSLS                                  0x0008
#define ADL_DESKTOPCAPS_SAMEMODESLS_BYDISABLEOTHERDESKTOPS                  0x0010
#define ADL_DESKTOPCAPS_MIXEDMODESLS_BYDISABLEOTHERDESKTOPS                 0x0020
#define ADL_DESKTOPCAPS_DISPLAYROTATIONSLS_BYDISABLEOTHERDESKTOPS           0x0040
#define ADL_DESKTOPCAPS_DESKTOPROTATIONSLS_BYDISABLEOTHERDESKTOPS           0x0080
#define ADL_DESKTOPCAPS_SAMEMODESLS_BENEFIT_BYDISABLEOTHERDESKTOPS          0x0100
#define ADL_DESKTOPCAPS_MIXEDMODESLS_BENEFIT_BYDISABLEOTHERDESKTOPS         0x0200
#define ADL_DESKTOPCAPS_DISPLAYROTATIONSLS_BENEFIT_BYDISABLEOTHERDESKTOPS   0x0400
#define ADL_DESKTOPCAPS_DESKTOPROTATIONSLS_BENEFIT_BYDISABLEOTHERDESKTOPS   0x0800

#define ADL_ADLSLSTARGET_ENABLED  0x0001
#define ADL_ADLSLSTARGET_SELECTED   0x0002
/// }@

///////////////////////////////////////////////////////////////////////////
// ADL_DISPLAY_ADJUSTMENT_COLORDEPTH adjustment values
// (bit-vector)
///////////////////////////////////////////////////////////////////////////
/// \defgroup define_color_depth_bits Color depth values
/// This group defines possible color depth values that a particular digital display can support. \n
/// Since a display can support multiple values, they can be bit-or'ed to indicate the various values \n
/// @{
#define ADL_COLORDEPTH_BITS_UNKNOWN         0
/// Indicates if color depth is 666
#define ADL_COLORDEPTH_BITS_666             ( 1 << ADL_COLORDEPTH_666 )
/// Indicates if color depth is 888
#define ADL_COLORDEPTH_BITS_888             ( 1 << ADL_COLORDEPTH_888 )
/// Indicates if color depth is 101010		
#define ADL_COLORDEPTH_BITS_101010          ( 1 << ADL_COLORDEPTH_101010 )
/// Indicates if color depth is 121212       
#define ADL_COLORDEPTH_BITS_121212          ( 1 << ADL_COLORDEPTH_121212 )
/// Indicates if color depth is 141414
#define ADL_COLORDEPTH_BITS_141414          ( 1 << ADL_COLORDEPTH_141414 )
/// Indicates if color depth is 161616
#define ADL_COLORDEPTH_BITS_161616          ( 1 << ADL_COLORDEPTH_161616 )
/// Indicates default value of color depth
#define ADL_COLOR_DEPTH_BITS_DEF            ADL_COLORDEPTH_BITS_888
#define ADL_COLOR_DEPTH_BITS_MASK           ( ADL_COLORDEPTH_BITS_666 | ADL_COLORDEPTH_BITS_888 | ADL_COLORDEPTH_BITS_101010 | \
                                              ADL_COLORDEPTH_BITS_121212  | ADL_COLORDEPTH_BITS_141414 | ADL_COLORDEPTH_BITS_161616 )
/// @}

/// \defgroup FPS
/// @{
/// Value for the setting the default FPS.
#define ADL_FPS_SET_DEFAULTS 0xFFFFFFFF
/// @}

#define MANTLE_DEFINE_HANDLE(_obj) typedef void* _obj;
#define MANTLE_MAKE_VERSION(major, minor, patch) \
    ((major << 22) | (minor << 12) | patch)

#define VULKAN_MAKE_VERSION(major, minor, patch) \
    ((major << 22) | (minor << 12) | patch)

// Mantle API version supported by this file
#define MANTLE_API_VERSION MANTLE_MAKE_VERSION(0, 21, 0)
// Vulkan API version supported by this file
#define VULKAN_API_VERSION VULKAN_MAKE_VERSION(1, 0, 0)

MANTLE_DEFINE_HANDLE(PHYSICAL_GPU);
#define MAX_PHYSICAL_GPUS     16

#define VULKAN_DEFINE_HANDLE(_obj) typedef void* _obj;
MANTLE_DEFINE_HANDLE(VkInstance);
MANTLE_DEFINE_HANDLE(VkPhysicalDevice);

// Used by GetGraphicCoreInfo
#define ADL_NUM_OF_PROCESSING_ELEMENTS_PER_CU           64
#define ADL_NUM_OF_PROCESSING_ELEMENTS_PER_WGP          128
#define ADL_BITMAP_PITCH_MODIFIER	4

#if defined (LINUX)
/// \defgroup define_multi_GPU_caps_constants for ADL_Adapter_MultiGPU_Caps lpCaps and lpValidCaps
/// @{
/// Crossfire polling option
#define ADL_MULTIGPUCAPS_CROSSFIRE (1 << 0)
/// MGPU-SLS polling option
#define ADL_MULTIGPUCAPS_SLS (1 << 1)
/// @}

/// \defgroup define_mgpustate MGPU-SLS state of a particular adapter MGPU combination
/// @{
#define ADL_MGPU_STATE_SLS_ONLY                 ( 1 << 14 ) /* MGPU-SLS is enabled on current device */
/// @}

#endif // LINUX



//GetTemperature
// Temperature Type for ADLODNTemperatureType
typedef enum ADLODNTemperatureType
{
    ADL_ODN_TEMPERATURE_INVALID    = 0,
    ADL_ODN_TEMPERATURE_EDGE,
    ADL_ODN_TEMPERATURE_HBM,
    ADL_ODN_TEMPERATURE_VRVDDC,
    ADL_ODN_TEMPERATURE_VRMVDD,
    ADL_ODN_TEMPERATURE_LIQUID,
    ADL_ODN_TEMPERATURE_PLX,
    ADL_ODN_TEMPERATURE_MAXTYPES,
} ADLODNTemperatureType;


//DOPP PFPA states
typedef enum ADL_DOPP_PFPA_STATE
{
	ADL_DOPP_PFPA_STATE_UNINITIALIZED = 0, // PFPA(Pre-Flip Primary Access)Uninitialized
	ADL_DOPP_PFPA_STATE_ACTIVE = 1, // PFPA active for DOPP
	ADL_DOPP_PFPA_STATE_AVAILABLE = 2, // PFPA available for DOPP
	ADL_DOPP_PFPA_STATE_UNAVAILABLE_PROTECTED_CONTENT = 3, // PFPA not available because Protected Content
	ADL_DOPP_PFPA_STATE_UNAVAILABLE_DWM_OFF = 4, // PFPA not available because DMW is OFF
	ADL_DOPP_PFPA_STATE_UNAVAILABLE_HYBRID_GRAPHICS = 5, // PFPA not available on Hybrid Graphics systems
	ADL_DOPP_PFPA_STATE_UNAVAILABLE_APP_TIMEOUT = 6, // PFPA not available when app timeout (not used)
	ADL_DOPP_PFPA_STATE_UNAVAILABLE_UNSUPPORTED_3D_APP = 7, // 3D API of fullscreen app does not support PFPA
	ADL_DOPP_PFPA_STATE_UNAVAILABLE_POWERXPRESS = 8, // PFPA not available on PowerXpress systems
	ADL_DOPP_PFPA_STATE_UNAVAILABLE_VIRTUAL_SYSTEM = 9, // PFPA not available on virtual systems
	ADL_DOPP_PFPA_STATE_NO_FRAME_METADATA_SUPPORT = 10, // PFPA not available if frame metadata is unsupported
	ADL_DOPP_PFPA_STATE_UNAVAILABLE_INVALID_SOURCE_ID = 11, // PFPA not available for this source ID
	ADL_DOPP_PFPA_STATE_UNAVAILABLE_DOPP_IN_USE = 12, // PFPA not available because another client is using DOPP
	ADL_DOPP_PFPA_STATE_UNAVAILABLE_DOPP_NOT_SUPPORTED = 13, // PFPA not available because DOPP is not available (E.g., KMD_EnableDesktopTexture key does not exist)
	ADL_DOPP_PFPA_STATE_UNAVAILABLE_MPO_ACTIVE = 14  // PFPA is not available because the OS is in MPO flip mode

} ADL_DOPP_PFPA_STATE;

//DOPP states
typedef enum ADL_DOPP_STATE
{
	ADL_DOPP_PRESENT_SURFACE_SET = 0,         // Present surface being passed in is set for next flip
	ADL_DOPP_ACTIVE = 1,         // Call was successful, DOPP still enabled
	ADL_DOPP_PRESENT_SURFACE_LOST = 2,         // Present surface being passed in is no longer valid
	ADL_DOPP_HUNG = 3,         // GPU hung/busy
	ADL_DOPP_PRESENT_TDR = 4,         // KMD TDRed from waiting for OGL to call present
	ADL_DOPP_MODE_SET = 5,         // A mode set has occured, DOPP disabled
	ADL_DOPP_NOT_SUPPORTED = 6,         // System config does not allow for DOPP
	ADL_DOPP_SINGLETON_LOCKED_SUCCESSFUL = 7,  // KMD will allow exclusive DOPP access for calling client
	ADL_DOPP_SINGLETON_ALREADY_LOCKED = 8,  // Another DOPP client is currently active
	ADL_DOPP_DESKTOP_TEXTURE_DISABLED = 9,  // Desktop Texture Disabled
	ADL_DOPP_DESKTOP_TEXTURE_ENABLED = 10, // Desktop Texture Enabled
	ADL_DOPP_SOURCE_ID_SET_SUCCESSFUL = 11, // New Primary Source Id is set for DOPP post-processing
	ADL_DOPP_SOURCE_ID_SET_ERROR = 12, // New Primary Source Id is not set for DOPP post-processing
	ADL_DOPP_COMMAND_SUCCESSFUL = 13, // Generic successful status for DOPP Commands
	ADL_DOPP_COMMAND_ERROR = 14, // Generic error status for DOPP Commands
	ADL_DOPP_SET_DESKTOP_SIZE_ERROR = 15, // DOPP Desktop Size Error
	ADL_DOPP_NOT_ACTIVE = 16, // DOPP Not Active
	ADL_DOPP_NOT_READY = 17  // DOPP Primary buffer is not ready for UGL Query
} ADL_DOPP_STATE;

//dopp kmd device handle
typedef unsigned int ADL_D3DKMT_HANDLE;

//Throttle notification
typedef enum ADL_ODN_THROTTLE_NOTIFICATION
{
    ADL_ODN_THROTTLE_POWER         = 1 << 0,   // Power. Indicating performance is limited by total power limit. = TDP
    ADL_ODN_THROTTLE_THERMAL       = 1 << 1,   // Thermal. Indicating performance is limited by temperature limit. =  Temp Limit
    ADL_ODN_THROTTLE_GFX           = 1 << 2,   // Utilization. Indicating performance is limited by GPU utilization. = GFX busy signal
    ADL_ODN_THROTTLE_CURRENT       = 1 << 3,   // Current. Indicating performance is limited by thermal design current = TDC
    ADL_ODN_THROTTLE_FAN           = 1 << 4    // Fan. Indicating performance is limited by max fan speed = Nominal RPM

}ADL_ODN_THROTTLE_NOTIFICATION;

///////////////////////////////////////////////////////////////////////////
// ADLCVDCSetting Enumeration
///////////////////////////////////////////////////////////////////////////
/// \defgroup CVDC setting
/// Used with \ref ADL2_Display_CVDC_Caps and
/// \ref ADL2_Display_CVDC_Get and
/// \ref ADL2_Display_CVDC_Set
/// to specify which setting to adjust for.
/// \brief CVDC setting.
// @{
typedef enum ADLCVDCSetting
{
	ADL_CVDC_SETTING_CONTROL = 0,
	ADL_CVDC_SETTING_PROTANOPIA = 1,
	ADL_CVDC_SETTING_DEUTERANOPIA = 2,
	ADL_CVDC_SETTING_TRITANOPIA = 3
} ADLDisplayCVDCSetting;


///////////////////////////////////////////////////////////////////////////
// Side by side AMD GPU interpret mode definitions
///////////////////////////////////////////////////////////////////////////
/// \defgroup define GPU_Interpret
/// @{
#define ADL_CREATE_OPTIONS_DEFAULT 					0 /*!< Treat AMD incompatible GPU as non-AMD gpu by using new vendor id -1002 */
#define INTERPRET_INCOMPATIBLE_DRIVER_VERSION_AS_SUPPORTED (1 << 0) /*!< AMD incompatible GPU means the ADL version 
                                                                         from current loaded ADL and the ADL from the GPU driver store is different.
                                                                         Set this flag, Treat AMD incompatible GPU as AMD gpu.
                                                                         Applications may get unpredictable result when communicate with incompatible driver
                                                                         using incompatible ADL */
                                                                         /// @}


// ADLCVDCSetting Enumeration
///////////////////////////////////////////////////////////////////////////
/// \defgroup CVDC setting
/// Used with \ref ADL2_Display_CVDC_Caps and
/// \ref ADL2_Display_CVDC_Get and
/// \ref ADL2_Display_CVDC_Set
/// to specify which setting to adjust for.
/// \brief CVDC setting.
// @{
typedef enum _ADLDisplayDPDceSetting

{
	ADL_DISPLAY_ADJUSTMENT_VOLTAGE_SWING = 0,
	ADL_DISPLAY_ADJUSTMENT_PRE_EMPHASIS = 1,
	ADL_MAX_DCE_SETTINGS
	
} ADLDisplayDPDceSetting;

// UMA Carveout modes Enumeration
///////////////////////////////////////////////////////////////////////////
/// \defgroup UMACarveoutModes is used by
/// \ref ADL2_Adapter_GPUUMACarveout_Info_Get and
/// \ref ADL2_Adapter_GPUUMACarveout_Size_Set
// @{
typedef enum _UMACarveoutModes {
    UMACarveroutModes_Unknown,// Cumstomer mode, not in the scope of our BIOS table
    UMACarveroutModes_ProductivityMode,  //Productivity mode will use less memory, usually 512K 
	UMACarveroutModes_GameMode//Game mode will use big size of memory, usually, 2GB

} UMACarveoutModes;

///////////////////////////////////////////////////////////////////////////
// ADLSmartShiftSettings iFlag values
// (bit-vector)
///////////////////////////////////////////////////////////////////////////
/// \defgroup define_smartshift_bits flag values
/// This group defines possible Smart Shift values \n
/// @{
#define ADL_SMARTSHIFT_DISPLAYSLIDER        (1 << 0)
/// @}


#endif /* AMD_DEFINES_H_ */
