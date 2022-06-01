///
///  Copyright (c) 2008 - 2021 Advanced Micro Devices, Inc.

///  THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
///  EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
///  WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.

/// \file amd_structures.h
/// \brief This file contains the structure declarations used by the internal AMD Driver Library interfaces for \ALL platforms.
///
/// All data structures used in ADL internal interfaces should be defined in this header file.
///

#ifndef AMD_STRUCTURES_H_
#define AMD_STRUCTURES_H_

#ifndef ADL_DEFINES_H_
#include "adl_defines.h"
#endif

#ifndef AMD_DEFINES_H_
#include "amd_defines.h"
#endif

/////////////////////////////////////////////////////////////////////////////////////////////
/// \brief Structure containing information about GPU.
///
/// This structure is used to store information about GPU.
/// This structure is used by internal ADL implementation.
/// \nosubgrouping
////////////////////////////////////////////////////////////////////////////////////////////
typedef struct ADLGPUInfo
{
    /// The persistent GPU Index.
    int iGPUIndex;
    /// The bus number associated with this GPU.
    int iBusNumber;
    /// The device number associated with this GPU.
    int iDeviceNumber;
    /// The function number associated with this GPU.
    int iFunctionNumber;
    /// The number of logical adapters on this GPU.
    int iNumAdapters;
    /// The logical adapters of this GPU.
    int* lpAdapterTable;
    /// driver service name, such as atikmdag. There will have multiple service names in the system if there are different driver installed for different GPUs
    char strDriverServiceName[ADL_MAX_PATH];
    // Physical driver location. such as: c:\windows\system32\DriverStore\FileRepository\c0305072.inf_amd64_bd7907b4c643e12e
    char strDriverStorePath[ADL_MAX_PATH];
    /// Driver Version
    ADLVersionsInfoX2 adlDriverVersion;

} ADLGPUInfo, *LPADLGPUInfo;


/////////////////////////////////////////////////////////////////////////////////////////////
/// \brief Structure containing information about the ASIC.
///
/// This structure is used to store various information about the ASIC.  This 
/// information can be returned to the user.
/// \nosubgrouping
////////////////////////////////////////////////////////////////////////////////////////////
typedef struct ADLASICInfo
{
    long long iMemorySize;        	///< Memory size in bytes.
    int iCoreClock;          		///< Core clock in 10 KHz.
    int iMemoryClock;        		///< Memory clock in 10 KHz.
    char strMemoryType[ADL_MAX_PATH];  	///< Memory type in string.
} ADLASICInfo, *LPADLASICInfo;



/////////////////////////////////////////////////////////////////////////////////////////////
/// \brief Structure containing information about lcd refresh rate capability.
///
/// This structure is used to store the information about LCD refresh rate capability for the adapter.
/// This structure is used by the ADL_Display_LCDRefreshRateCapability_Get() function.
/// \nosubgrouping
////////////////////////////////////////////////////////////////////////////////////////////
typedef struct ADLLcdRefreshRateCap
{
    int iSize;
    int iDefaultRefreshRate;
    int iNumLowRefreshRates;
    int iLowRefreshRate1;
    int iLowRefreshRate2;
    int iLowRefreshRate3;
    int iLowRefreshRate4;
    int iCapsFlag;
} ADLLcdRefreshRateCap;

/////////////////////////////////////////////////////////////////////////////////////////////
/// \brief Structure containing information about LCD refresh rate options.
///
/// This structure is used to store the information about LCD refresh rate options for the adapter.
/// This structure is used by the ADL_Display_LCDRefreshRateOptions_Get() and ADL_Display_LCDRefreshRateOptions_Set() functions.
/// \nosubgrouping
////////////////////////////////////////////////////////////////////////////////////////////
typedef struct ADLLcdRefreshRateOptions
{
    int iSize;
    int iOptions;
    int iReserved1;
    int iReserved2;
} ADLLcdRefreshRateOptions;



/////////////////////////////////////////////////////////////////////////////////////////////
/// \brief Structure containing information about Target Display timing information.
/// This structure is used by the ADL_Display_TargetTiming_Get() functions
/// \nosubgrouping
////////////////////////////////////////////////////////////////////////////////////////////
typedef struct ADLDisplayTargetTiming
{
    int iSize;
    unsigned int horizontalTotal;
    unsigned int verticalTotal;
    unsigned int horizontalActive;
    unsigned int verticalActive;
    unsigned int refreshRateNumerator;
    unsigned int refreshRateDenominator;
    unsigned int pixelClockInKHz;
} ADLDisplayTargetTiming;


/////////////////////////////////////////////////////////////////////////////////////////////
/// \brief Structure containing information about information required to create a HDCP 2.0 session.
/// This structure is used by the ADL_RemoteDisplay_Hdcp20_Create() function
/// \nosubgrouping
////////////////////////////////////////////////////////////////////////////////////////////
typedef struct ADLHdcp20Create
{
    /// [out] sessionId for this HDCP2.0 session	
    int iSessionId;
    /// [out] time in milliseconds of timer to be started
    int iTimerDuration;
    /// [out] number of bytes used for the transmitter message in cTxMsgBuf	
    int iTxMsgSize;
    /// [out] message buffer to transmit to the receiver; filled in by driver 
    char cTxMsgBuf[256];
} ADLHdcp20Create;

/////////////////////////////////////////////////////////////////////////////////////////////
/// \brief Structure containing information about information required to process a HDCP 2.0 message
/// This structure is used by the ADL_RemoteDisplay_Hdcp20_Process() function
/// \nosubgrouping
////////////////////////////////////////////////////////////////////////////////////////////
typedef struct ADLHdcp20Process
{
    /// [in] unique session id value as returned in \a ADLHdcp20Create
    int iSessionId;
    /// [in] UTC timestamp value of the receiver message	
    long long llRxTimestamp;
    /// [in] number of bytes used for the receiver message in \a cRxMsgBuf
    int iRxMsgSize;
    /// [in] message buffer containing data received from HDCP 2.x receiver  	
    char cRxMsgBuf[1024];
    /// [out] time in milliseconds of timer to be started
    int iTimerDuration;
    /// [out] transmitter message identifier to be used as input to \a ADLHdcp20NotifyTx
    int iTxMsgId;
    /// [out] number of bytes used for the transmitter message in \a cTxMsgBuf
    int iTxMsgSize;
    /// [out] message buffer to transmit to the receiver; filled in by driver.
    char cTxMsgBuf[256];
} ADLHdcp20Process;

/////////////////////////////////////////////////////////////////////////////////////////////
/// \brief Structure containing information about information required to notify transmitter about a HDCP 2.0 message
/// This structure is used by the ADL_RemoteDisplay_Hdcp20_Notify() function
/// \nosubgrouping
////////////////////////////////////////////////////////////////////////////////////////////
typedef struct ADLHdcp20Notify
{
    /// [in] unique session id value as returned in \a ADLHdcp20Create	
    int iSessionId;
    /// [in] transmitter message identifier
    int iTxMsgId;
    /// [in] UTC timestamp value of the transmitter message	
    long long llTxTimestamp;
} ADLHdcp20Notify;

/////////////////////////////////////////////////////////////////////////////////////////////
/// \brief Structure containing information about information required to destroy a HDCP 2.0 session.
/// This structure is used by the ADL_RemoteDisplay_Hdcp20_Destroy() function
/// \nosubgrouping
////////////////////////////////////////////////////////////////////////////////////////////
typedef struct ADLHdcp20Destroy
{
    /// [in] unique session id value as returned in \a ADLHdcp20Create
    int iSessionId;
} ADLHdcp20Destroy;

/////////////////////////////////////////////////////////////////////////////////////////////
/// \brief Structure containing information about the Chipset.
///
/// This structure is used to store various information about the Chipset.  This 
/// information can be returned to the user.
/// \nosubgrouping
////////////////////////////////////////////////////////////////////////////////////////////
typedef struct ADLSWInfo
{
    char strDrvVer[ADL_MAX_PATH]; 	 	///< Driver release version (e.g., 8.47.2).
    char strOGLVendor[ADL_MAX_PATH]; 	///< Vendor name (e.g.,. Advanced Micro Devices).
    char strOGLRenderer[ADL_MAX_PATH]; 	///< OGL renderer (e.g., AMD FirePro V7200).
    char strOGLVersion[ADL_MAX_PATH]; 	///< OGL version (e.g., 2.1.7410 FireGL Release).
} ADLSWInfo, *LPADLSWInfo;


/////////////////////////////////////////////////////////////////////////////////////////////
/// \brief Structure containing the display mode definition used per controller.
///
/// This structure is used to store the display mode definition used per controller.
/// \nosubgrouping
////////////////////////////////////////////////////////////////////////////////////////////
typedef struct ADL_DL_DISPLAY_MODE
{
    int  iPelsHeight;                      // Vertical resolution (in pixels).
    int  iPelsWidth;                       // Horizontal resolution (in pixels).
    int  iBitsPerPel;                      // Color depth.
    int  iDisplayFrequency;                // Refresh rate.
} ADL_DL_DISPLAY_MODE;

/////////////////////////////////////////////////////////////////////////////////////////////
/// \brief Structure containing detailed timing parameters.
///
/// This structure is used to store the detailed timing parameters.
/// \nosubgrouping
////////////////////////////////////////////////////////////////////////////////////////////
typedef struct ADL_DL_DETAILEDTIMING
{
    int   iSize;							/// Size of the structure.
    short sTimingFlags;				/// Timing flags. ADL_DL_TIMINGFLAG_xx.
    short sHTotal;						/// Total width (columns).
    short sHDisplay;					/// Displayed width.
    short sHSyncStart;				/// Horizontal sync signal offset.
    short sHSyncWidth;				/// Horizontal sync signal width.
    short sVTotal;						/// Total height (rows).
    short sVDisplay;					/// Displayed height.
    short sVSyncStart;				/// Vertical sync signal offset.
    short sVSyncWidth;				/// Vertical sync signal width.
    short sPixelClock;				/// Pixel clock value.
    short sHOverscanRight;		/// Overscan right.
    short sHOverscanLeft;			/// Overscan left.
    short sVOverscanBottom;	/// Overscan bottom.
    short sVOverscanTop;			/// Overscan top.
    short sOverscan8B;
    short sOverscanGR;
} ADL_DL_DETAILEDTIMING;

/////////////////////////////////////////////////////////////////////////////////////////////
/// \brief Structure containing display mode information.
///
/// This structure is used to store the display mode information.
/// \nosubgrouping
////////////////////////////////////////////////////////////////////////////////////////////
typedef struct ADL_DL_DISPLAYMODEINFO
{
    int  iTimingStandard;				/// Timing standard of the current mode.
    int  iPossibleStandard;			/// Applicable timing standards for the current mode.
    int  iRefreshRate;					/// Refresh rate factor.
    int  iPelsWidth;						/// Num of pixels in row.
    int  iPelsHeight;						/// Num of pixels in column.
    ADL_DL_DETAILEDTIMING  sDetailedTiming; // Detailed timing parameters.
} ADL_DL_DISPLAYMODEINFO;

/////////////////////////////////////////////////////////////////////////////////////////////
///\brief Structure containing information about latest driver supported Resize and Rotate release
///
/// This structure is used to store the latest driver supported Resize and Rotate release numbers
/// \nosubgrouping
////////////////////////////////////////////////////////////////////////////////////////////
typedef struct ADLXInfoData
{
    int iRandRmajor;            ///< Latest Resize and Rotate version that driver supports, Major portion
    int iRandRminor;            ///< Latest Resize and Rotate version that driver supports, Minor portion
} ADLXInfoData, *LPADLXInfoData; 

/////////////////////////////////////////////////////////////////////////////////////////////
///\brief Structure containing information about association between display and audio endpoint
///
/// This structure is used to store display and audio endpoint association information
/// \nosubgrouping
////////////////////////////////////////////////////////////////////////////////////////////
typedef struct AudioEndPointAssociationInfo
{
    /// Display Index
    unsigned long DisplayIndex;
    /// PCI Bus number
    unsigned Bus          : 8;
    /// Device number
    unsigned Device       : 5;
    /// Function number
    unsigned Function     : 3;
    /// Reserved bits for possible future use. App can ignore this field for now
    unsigned Reserved     : 15;
} AudioEndPointAssociationInfo, *LPAudioEndPointAssociationInfo;


/////////////////////////////////////////////////////////////////////////////////////////////
/// \brief Structure containing information about ADL GUID fields.
///
/// This structure is used to store information about GUID of a device.
/// This structure is used by internal ADL implementation.
/// \nosubgrouping
////////////////////////////////////////////////////////////////////////////////////////////
typedef struct ADLGUID {
    long  Data1; ///< Specifies the first 8 hexadecimal digits of the GUID
    short Data2; ///< Specifies the first group of 4 hexadecimal digits.
    short Data3; ///< Specifies the second group of 4 hexadecimal digits.
    char  Data4[8]; ///< Array of 8 bytes. The first 2 bytes contain the third group of 4 hexadecimal digits. The remaining 6 bytes contain the final 12 hexadecimal digits.
} ADLGUID;


/////////////////////////////////////////////////////////////////////////////////////////////
///\brief Structure containing information about the Linux X screen information.
///
/// This structure is used to store the current screen number, linked xscreen number and xorg.conf ID name assoicated with an adapter index.
///
/// If the current X screen number is set (not -1), then this indicates that the adapter has control over that XScreen. The adapter
/// is able to change display, desktop and OGL related settings associated with the XScreen.
///
/// If the linked X screen number is set (not -1), then this indicates that the adapter is being used in a supporting role for that XScreen.
/// In a supporting role, the current adapter only has partial control, as indicated by \ref ADL_Adapter_ConfigureState_Get
///
/// This structure is used for \ref ADL_Adapter_XScreenInfo_GetR2
///
/// Note: It is possible that an adapter can have a valid current and linked XScreen.
///
/// This structure is updated during ADL_Main_Control_Refresh or ADL_ScreenInfo_Update.
/// Note:  This structure should be used in place of iXScreenNum and strXScreenConfigName in AdapterInfo as they will be
/// deprecated.
/// \nosubgrouping
////////////////////////////////////////////////////////////////////////////////////////////
#if defined (LINUX)
typedef struct XScreenInfoR2
{
    /// Current X screen number that the adapter controls.
    int iXScreenNum;
    /// Linked X screen number that the adapter is associated with.
    int iLinkedXScreenNum;
    /// Internal x config file screen identifier name.
    char strXScreenConfigName[ADL_MAX_PATH];
} XScreenInfoR2, *LPXScreenInfoR2;
#endif /* (LINUX) */


/////////////////////////////////////////////////////////////////////////////////////////////
/// \brief ADL Structure for RGBTRPL16
///
/// ADLRGBTRPL16 structure
/// \nosubgrouping
/////////////////////////////////////////////////////////////////////////////////////////////
typedef struct ADLRGBTRPL16
{
    unsigned short rgbtRed;
    unsigned short rgbtGreen;
    unsigned short rgbtBlue;
    unsigned short reserved;
}ADLRGBTRPL16, *LPADLRGBTRPL16;

/////////////////////////////////////////////////////////////////////////////////////////////
/// \brief ADL Structure for CONTROLLERGAMMA
///
/// CONTROLLERGAMMA structure
/////////////////////////////////////////////////////////////////////////////////////////////
typedef struct ADLCONTROLLERGAMMA16
{
    unsigned long ulSize;
    ADLRGBTRPL16 triGamma[256];
    unsigned long ulFlags;
}ADLCONTROLLERGAMMA16, *LPADLCONTROLLERGAMMA16;

/////////////////////////////////////////////////////////////////////////////////////////////
/// \brief Structure containing extended information about the graphics adapter
///
/// This structure is used to store extended information about the graphics adapter, not
/// already being returned by \ref AdapterInfo
/// NOTE: This structure may be extended in future release of ADL. As such,
/// to maintain backwards compatibility, the appropriate bit must be checked in the iFlag
/// member before accessing the actual member variable. If the bit is missing then ADL
/// may not have returned a version of this structure that contains that member variable
/// (i.e. ADL installed on the system is an older version than the one the calling application
/// was compiled against).
/// \nosubgrouping
/////////////////////////////////////////////////////////////////////////////////////////////
typedef struct AdapterExtInfo
{
    /// The size of this structure, in bytes
    long long iSize;
    /// Which bits in the iFlags are valid
    long long iValidBits;
    /// Indicates which member in this structure has valid information
    long long iFlag;
    /// The maximum allowed surface width, in pixels, for this adapter
    int iMaxSurfaceWidth;
    /// The maximum allowed surface height, in pixels, for this adapter
    int iMaxSurfaceHeight;
} AdapterExtInfo, *LPAdapterExtInfo;

/////////////////////////////////////////////////////////////////////////////////////////////
///\brief Structure containing information about enhenced scaling configuration
///
/// This structure is used to set v/h taps and v/h shapness. The caller should ensure that display clock is enough for the requested configuration
/// \nosubgrouping
////////////////////////////////////////////////////////////////////////////////////////////
typedef struct ADLMMDisplayScaling
{
    /// Display image width (destination)
    int 	iWidth;
    /// Display image height (destination)
    int 	iHeight;
    /// The requested number of hor taps
    int 	ihTaps;  
    /// The requested number of vert taps
    int 	ivTaps;  
    ///horizontal sharpness
    int 	ihorSharpness;  
    ///vertical sharpness
    int 	ivertSharpness;  

} ADLMMDisplayScaling;




/////////////////////////////////////////////////////////////////////////////////////////////
///\brief Structure containing information about adapter limitation
///
/// This structure is used to store the adapter limitation. For example, the maxium number of dispalys in one clone
/// desktop
/// \nosubgrouping
////////////////////////////////////////////////////////////////////////////////////////////
typedef struct ADLAdapterLimitationCaps
{
    /// The number of activatable Sources.
    /// based on controllers and connected displays
    int iNumActivatableSources; 
    /// The number of activatable desktops in the GPU. 
    int iNumActivatableDesktops; 
    /// The number of activatable displays in one desktop.
    /// The max number of displays ine one clone.
    int iNumActivatableDisplaysInOneDesktops; 
    /// Revered 
    int iMask;
    /// Revered
    int iValue;

}ADLAdapterLimitationCaps;

/// \brief Structure containing the watermark information
/// This structure is sued for setting or getting the identifying watermark on a particular
/// display. Specifically, this is used by the \ref ADL_DisplayIdentifyDisplay_Set and
/// \ref ADL_DisplayIdentifyDisplay_Get functions.
/// \nosubgrouping
typedef struct ADLIdentifyDisplay
{
    /// Indicates which fields are valid. Only used for \ref ADL_Display_IdentifyDisplay_Get
    /// to indicate which information has been returned. This is ignored by \ref ADL_DisplayIdentifyDisplay_Set.
    /// It will contain one or more bits vrom \ref define_identify_flag
    /// For example: if Flags = ADL_IDENTIFY_FLAG_SHOW | ADL_IDENTIFY_FLAG_WATERMARKID, then
    /// only the Show and WatermarkID fields contain valid information.
    int Flags;
    /// Indicates if the watermark is shown/to be shown(ADL_TRUE), or not (ADL_FALSE)
    int Show;
    /// Stores the watermark to show. A value from 0 - 99 for showing that particular number
    /// ADL_IDENTIFYDISPLAY_SHOW_EXCLAMATION for the '!' watermark
    /// ADL_IDENTIFYDISPLAY_SHOW_CHECKMARK for the checkmark watermark
    /// Note: You can only set a number, exclamation, or the checkmark. You cannot set a combination
    /// of these options.
    int WatermarkID;
    /// The X position (in %) of the watermark on the display, from the left edge.
    int PosX;
    /// The Y position (in %) of the watermark on the display, from the top edge.
    int PosY;
} ADLIdentifyDisplay;

/////////////////////////////////////////////////////////////////////////////////////////////
///\brief Structure containing information about the proper MultiGPU chains combinations.
///
/// This structure is used to store information about the MultiGPU chains combination for a particular adapter.
/// This structure is used by the ADL_Adapter_MultiGPU_Caps(), ADL_Adapter_MultiGPU_Get(), and ADL_Adapter_MultiGPU_Set() functions.
/// \nosubgrouping
////////////////////////////////////////////////////////////////////////////////////////////
typedef struct ADLMultiGPUComb
{
    /// Number of adapters in this combination.
    int iNumLinkAdapter;
    /// A list of ADL indexes of the linked adapters in this combination.
    int iAdaptLink[3];
} ADLMultiGPUComb;

/////////////////////////////////////////////////////////////////////////////////////////////
///\brief Structure containing MultiGPU state and error information.
///
/// This structure is used to store state and error information about a particular adapter MultiGPU combination.
/// This structure is used by the ADL_Adapter_MultiGPU_Get() function.
/// \nosubgrouping
////////////////////////////////////////////////////////////////////////////////////////////
typedef struct ADLMultiGPUInfo
{
    /// Current error code of this MultiGPU combination.
    int iErrorCode;
    /// Current \ref define_MultiGPU state
    int iState;
    /// If MultiGPU is supported by this combination. The value is either \ref ADL_TRUE or \ref ADL_FALSE.
    int iSupported;
} ADLMultiGPUInfo;


/////////////////////////////////////////////////////////////////////////////////////////////
///\brief Structure containing information about Acpi ID and the Target ID for a target
///
/// This structure is used to store the Acpi ID and the Target ID for display targets
/// desktop
/// \nosubgrouping
////////////////////////////////////////////////////////////////////////////////////////////
typedef struct ADLACPITranslationEntries
{
    //The target ID of the display
    int TargetID;
    //The ACPI ID of the display
    int AcpiID;
    // New fields in this structure must come before this reserved field.
    unsigned int Reserved[14];
}ADLACPITranslationEntries, *LPADLACPITranslationEntries;

/////////////////////////////////////////////////////////////////////////////////////////////
///\brief Structure containing the channel mapping information
///
/// This structure is used to store the channel mapping information
/// \nosubgrouping
////////////////////////////////////////////////////////////////////////////////////////////
typedef struct ADLDisplayChannelMapping
{
    /// the remapped channel in OS Channel_L
    long ulOSChannelMapping_L;  

    /// the remapped channel in OS Channel_R
    long ulOSChannelMapping_R;   

    /// the remapped channel in OS Channel_C
    long ulOSChannelMapping_C; 

    /// the remapped channel in OS Channel_Sub
    long ulOSChannelMapping_Sub; 

    /// the remapped channel in OS Channel_RL
    long ulOSChannelMapping_RL; 

    /// the remapped channel in OS Channel_RR
    long ulOSChannelMapping_RR; 

    /// the remapped channel in OS Channel_SL
    long ulOSChannelMapping_SL; 

    /// the remapped channel in OS Channel_SR
    long ulOSChannelMapping_SR; 
} ADLDisplayChannelMapping;

/////////////////////////////////////////////////////////////////////////////////////////////
///\brief Structure containing information about the range of audio delays
///
/// This structure is used to store information about the range of audio 
/// delay adjustments
/// \nosubgrouping
//////////////////////////////////////////////////////////////////////////////////////////// 
typedef struct ADLApoAudioDelayRangeInfo
{
    /// minimum audio delay
    int iMinDelay;
    /// maximum audio delay
    int iMaxDelay;
    /// step size
    int iStepSize;
    /// default audio delay
    int iDefaultDelay;
} ADLApoAudioDelayRangeInfo;

/////////////////////////////////////////////////////////////////////////////////////////////
///\brief Structure containing information about audio delays
///
/// This structure is used to store information about audio delays for each
/// channel for a given sample rate
/// \nosubgrouping
////////////////////////////////////////////////////////////////////////////////////////////
typedef struct ADLAudioDelayPerSampleRate
{
    /// given sample rate
    enum ADLSampleRate sampleRate;

    /// audio delay for left channel
    int iDelayChannel_L;

    /// audio delay for right channel
    int iDelayChannel_R;

    /// audio delay for center channel
    int iDelayChannel_C;

    /// audio delay for sub channel
    int iDelayChannel_Sub;

    /// audio delay for rear left channel
    int iDelayChannel_RL;

    /// audio delay for rear right channel
    int iDelayChannel_RR;

    /// audio delay for side left channel
    int iDelayChannel_SL;

    /// audio delay for side right channel
    int iDelayChannel_SR;
} ADLAudioDelayPerSampleRate;

/////////////////////////////////////////////////////////////////////////////////////////////
///\brief Structure containing information about audio delays
///
/// This structure is used to store information about audio delays for each
/// channel and for each sample rate
/// \nosubgrouping
////////////////////////////////////////////////////////////////////////////////////////////
typedef struct ADLApoAudioDelay
{
    /// number of sample rates
    int iNumberOfSampleRates;

    /// audio delay per sample rate for coarse adjustment
    ADLAudioDelayPerSampleRate coarseAudioDelay[ADL_MAX_AUDIO_SAMPLE_RATE_COUNT];

    /// audio delay per sample rate for fine adjustment
    ADLAudioDelayPerSampleRate fineAudioDelay[ADL_MAX_AUDIO_SAMPLE_RATE_COUNT];
} ADLApoAudioDelay;

/////////////////////////////////////////////////////////////////////////////////////////////
///\brief Structure containing the channel mapping information of a display
///
/// This structure is used to store the channel mapping information of a display
/// \nosubgrouping
////////////////////////////////////////////////////////////////////////////////////////////
typedef struct ADLDisplayAudioChannelMapping
{
    /// display identifier
    ADLDisplayIdentifier displayIdentifier;

    /// channel mapping
    ADLDisplayChannelMapping channelMapping;

} ADLDisplayAudioChannelMapping;

/////////////////////////////////////////////////////////////////////////////////////////////
///\brief Structure containing information about audio channel split settings
///
/// This structure is used to store information about audio channel split configuration
/// \nosubgrouping
////////////////////////////////////////////////////////////////////////////////////////////
typedef struct ADLAudioChannelSplitSetting
{
    /// number of displays
    long                                 ulNumberOfDisplays;

    /// multichannel split state
    enum ADLMultiChannelSplitStateFlag   stateFlag;

    /// display speaker's channel mapping
    ADLDisplayAudioChannelMapping*       mappingSet;

    /// audio delay for each channel per sample rate
    ADLApoAudioDelay                     audioDelay;

} ADLAudioChannelSplitSetting;

/////////////////////////////////////////////////////////////////////////////////////////////
///\brief Structure containing information about audio capability
///
/// This structure is used to store information about audio capability
/// \nosubgrouping
////////////////////////////////////////////////////////////////////////////////////////////
typedef struct ADLAudioDataCap
{
    // bit vector of ADL_ENCODINGFORMAT_CAP_xxx
    unsigned long                         ulFormat;

    // number of channels for the given audio formats
    unsigned long                         ulNumOfChannels;

    // bit vector of ADL_SAMPLERATE_CAP_xxx
    unsigned long                         ulSampleFrequency;

    // bit vector of ADL_BITSPERSAMPLE_CAP_xxx
    unsigned long                         ulBitsPerSample;

} ADLAudioDataCap;

/////////////////////////////////////////////////////////////////////////////////////////////
///\brief Structure containing information about audio capability from display EDID
///
/// This structure is used to store information about audio capability from display EDID
/// \nosubgrouping
////////////////////////////////////////////////////////////////////////////////////////////
typedef struct ADLDisplayAudioInfo
{
    /// number of audio formats supported
    long                                  ulNumberOfAudioFormatsSupported;

    /// speaker allocation from EDID speaker allocation data block
    ADLDisplayAudioChannelMapping         speakerAllocation;

    ADLAudioDataCap*                       audioCaps;

} ADLDisplayAudioInfo;

/////////////////////////////////////////////////////////////////////////////////////////////
///\brief Structure containing information about GTC capability for the displays
///
/// This structure is used to store information about GTC capability for the displays
/// \nosubgrouping
////////////////////////////////////////////////////////////////////////////////////////////
typedef struct ADLGtcInfo
{
    /// support for GTC
    int supported;

    /// If GTC is disabled, iGtcGroupIndex = 0 
    int  iGtcGroupIndex;
} ADLGtcInfo;

typedef struct ADLSlsAudioConfig
{
    int                       iColumn;
    int                       iRow;
    ADLDisplayChannelMapping  channelMapping[6];
} ADLSlsAudioConfig;





/////////////////////////////////////////////////////////////////////////////////////////////
///\brief Structure containing Location path of the adapter
///
/// This structure is used to store location path information of the adapter
/// \nosubgrouping
////////////////////////////////////////////////////////////////////////////////////////////
typedef struct ADLAdapterLocationPath
{
    /// The ADL index handle. One GPU may be associated with one or two index handles
    int iAdapterIndex;
    /// Location path.
    char strLocationPath[ADL_MAX_PATH];

} ADLAdapterLocationPath, *LPADLAdapterLocationPath;



/////////////////////////////////////////////////////////////////////////////////////////////
///\brief Structure containing information about an mantle properties
///
/// This structure is used to store information of an mantle
/// \nosubgrouping
////////////////////////////////////////////////////////////////////////////////////////////
typedef struct Mantle_AppInfo
{
    /// mantle app name
    const char* pAppName;
    /// mantle api version
    int      appVersion;
    /// mantle eng name
    const char* pEngineName;
    ///mantle engine version
    int      engineVersion;
    /// mantle api version
    int      apiVersion;
} Mantle_AppInfo;

typedef enum ADLVkStructureType {
    VK_STRUCTURE_TYPE_APPLICATION_INFO = 0,
    VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO = 1,
    VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO = 2,
    VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO = 3,
    VK_STRUCTURE_TYPE_SUBMIT_INFO = 4,
    VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO = 5,
    VK_STRUCTURE_TYPE_MAPPED_MEMORY_RANGE = 6,
    VK_STRUCTURE_TYPE_BIND_SPARSE_INFO = 7,
    VK_STRUCTURE_TYPE_FENCE_CREATE_INFO = 8,
    VK_STRUCTURE_TYPE_SEMAPHORE_CREATE_INFO = 9,
    VK_STRUCTURE_TYPE_EVENT_CREATE_INFO = 10,
    VK_STRUCTURE_TYPE_QUERY_POOL_CREATE_INFO = 11,
    VK_STRUCTURE_TYPE_BUFFER_CREATE_INFO = 12,
    VK_STRUCTURE_TYPE_BUFFER_VIEW_CREATE_INFO = 13,
    VK_STRUCTURE_TYPE_IMAGE_CREATE_INFO = 14,
    VK_STRUCTURE_TYPE_IMAGE_VIEW_CREATE_INFO = 15,
    VK_STRUCTURE_TYPE_SHADER_MODULE_CREATE_INFO = 16,
    VK_STRUCTURE_TYPE_PIPELINE_CACHE_CREATE_INFO = 17,
    VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_CREATE_INFO = 18,
    VK_STRUCTURE_TYPE_PIPELINE_VERTEX_INPUT_STATE_CREATE_INFO = 19,
    VK_STRUCTURE_TYPE_PIPELINE_INPUT_ASSEMBLY_STATE_CREATE_INFO = 20,
    VK_STRUCTURE_TYPE_PIPELINE_TESSELLATION_STATE_CREATE_INFO = 21,
    VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_STATE_CREATE_INFO = 22,
    VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_STATE_CREATE_INFO = 23,
    VK_STRUCTURE_TYPE_PIPELINE_MULTISAMPLE_STATE_CREATE_INFO = 24,
    VK_STRUCTURE_TYPE_PIPELINE_DEPTH_STENCIL_STATE_CREATE_INFO = 25,
    VK_STRUCTURE_TYPE_PIPELINE_COLOR_BLEND_STATE_CREATE_INFO = 26,
    VK_STRUCTURE_TYPE_PIPELINE_DYNAMIC_STATE_CREATE_INFO = 27,
    VK_STRUCTURE_TYPE_GRAPHICS_PIPELINE_CREATE_INFO = 28,
    VK_STRUCTURE_TYPE_COMPUTE_PIPELINE_CREATE_INFO = 29,
    VK_STRUCTURE_TYPE_PIPELINE_LAYOUT_CREATE_INFO = 30,
    VK_STRUCTURE_TYPE_SAMPLER_CREATE_INFO = 31,
    VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_CREATE_INFO = 32,
    VK_STRUCTURE_TYPE_DESCRIPTOR_POOL_CREATE_INFO = 33,
    VK_STRUCTURE_TYPE_DESCRIPTOR_SET_ALLOCATE_INFO = 34,
    VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET = 35,
    VK_STRUCTURE_TYPE_COPY_DESCRIPTOR_SET = 36,
    VK_STRUCTURE_TYPE_FRAMEBUFFER_CREATE_INFO = 37,
    VK_STRUCTURE_TYPE_RENDER_PASS_CREATE_INFO = 38,
    VK_STRUCTURE_TYPE_COMMAND_POOL_CREATE_INFO = 39,
    VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO = 40,
    VK_STRUCTURE_TYPE_COMMAND_BUFFER_INHERITANCE_INFO = 41,
    VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO = 42,
    VK_STRUCTURE_TYPE_RENDER_PASS_BEGIN_INFO = 43,
    VK_STRUCTURE_TYPE_BUFFER_MEMORY_BARRIER = 44,
    VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER = 45,
    VK_STRUCTURE_TYPE_MEMORY_BARRIER = 46,
    VK_STRUCTURE_TYPE_LOADER_INSTANCE_CREATE_INFO = 47,
    VK_STRUCTURE_TYPE_LOADER_DEVICE_CREATE_INFO = 48,
    VK_STRUCTURE_TYPE_SWAPCHAIN_CREATE_INFO_KHR = 1000001000,
    VK_STRUCTURE_TYPE_PRESENT_INFO_KHR = 1000001001,
    VK_STRUCTURE_TYPE_DISPLAY_MODE_CREATE_INFO_KHR = 1000002000,
    VK_STRUCTURE_TYPE_DISPLAY_SURFACE_CREATE_INFO_KHR = 1000002001,
    VK_STRUCTURE_TYPE_DISPLAY_PRESENT_INFO_KHR = 1000003000,
    VK_STRUCTURE_TYPE_XLIB_SURFACE_CREATE_INFO_KHR = 1000004000,
    VK_STRUCTURE_TYPE_XCB_SURFACE_CREATE_INFO_KHR = 1000005000,
    VK_STRUCTURE_TYPE_WAYLAND_SURFACE_CREATE_INFO_KHR = 1000006000,
    VK_STRUCTURE_TYPE_MIR_SURFACE_CREATE_INFO_KHR = 1000007000,
    VK_STRUCTURE_TYPE_ANDROID_SURFACE_CREATE_INFO_KHR = 1000008000,
    VK_STRUCTURE_TYPE_WIN32_SURFACE_CREATE_INFO_KHR = 1000009000,
    VK_STRUCTURE_TYPE_DEBUG_REPORT_CALLBACK_CREATE_INFO_EXT = 1000011000,
    VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_STATE_RASTERIZATION_ORDER_AMD = 1000018000,
    VK_STRUCTURE_TYPE_DEBUG_MARKER_OBJECT_NAME_INFO_EXT = 1000022000,
    VK_STRUCTURE_TYPE_DEBUG_MARKER_OBJECT_TAG_INFO_EXT = 1000022001,
    VK_STRUCTURE_TYPE_DEBUG_MARKER_MARKER_INFO_EXT = 1000022002,
    VK_STRUCTURE_TYPE_BEGIN_RANGE = VK_STRUCTURE_TYPE_APPLICATION_INFO,
    VK_STRUCTURE_TYPE_END_RANGE = VK_STRUCTURE_TYPE_LOADER_DEVICE_CREATE_INFO,
    VK_STRUCTURE_TYPE_RANGE_SIZE = (VK_STRUCTURE_TYPE_LOADER_DEVICE_CREATE_INFO - VK_STRUCTURE_TYPE_APPLICATION_INFO + 1),
    VK_STRUCTURE_TYPE_MAX_ENUM = 0x7FFFFFFF
} ADLVkStructureType;

typedef struct ADLVkApplicationInfo {
    ADLVkStructureType    sType;
    const void*        pNext;
    const char*        pApplicationName;
    int                applicationVersion;
    const char*        pEngineName;
    int                engineVersion;
    int                apiVersion;
} ADLVkApplicationInfo;

typedef struct ADLVkInstanceCreateInfo 
{
    ADLVkStructureType             sType;
    const void*                 pNext;
    int					        flags;
    const ADLVkApplicationInfo*    pApplicationInfo;
    int                         enabledLayerCount;
    const char* const*          ppEnabledLayerNames;
    int                         enabledExtensionCount;
    const char* const*          ppEnabledExtensionNames;
} ADLVkInstanceCreateInfo;

typedef struct ADLVkPhysicalDeviceLimits
{
    unsigned int				maxImageDimension1D;
    unsigned int				maxImageDimension2D;
    unsigned int				maxImageDimension3D;
    unsigned int				maxImageDimensionCube;
    unsigned int				maxImageArrayLayers;
    unsigned int				maxTexelBufferElements;
    unsigned int				maxUniformBufferRange;
    unsigned int				maxStorageBufferRange;
    unsigned int				maxPushConstantsSize;
    unsigned int				maxMemoryAllocationCount;
    unsigned int				maxSamplerAllocationCount;
    unsigned long long          bufferImageGranularity;
    unsigned long long          sparseAddressSpaceSize;
    unsigned int				maxBoundDescriptorSets;
    unsigned int				maxPerStageDescriptorSamplers;
    unsigned int				maxPerStageDescriptorUniformBuffers;
    unsigned int				maxPerStageDescriptorStorageBuffers;
    unsigned int				maxPerStageDescriptorSampledImages;
    unsigned int				maxPerStageDescriptorStorageImages;
    unsigned int				maxPerStageDescriptorInputAttachments;
    unsigned int				maxPerStageResources;
    unsigned int				maxDescriptorSetSamplers;
    unsigned int				maxDescriptorSetUniformBuffers;
    unsigned int				maxDescriptorSetUniformBuffersDynamic;
    unsigned int				maxDescriptorSetStorageBuffers;
    unsigned int				maxDescriptorSetStorageBuffersDynamic;
    unsigned int				maxDescriptorSetSampledImages;
    unsigned int				maxDescriptorSetStorageImages;
    unsigned int				maxDescriptorSetInputAttachments;
    unsigned int				maxVertexInputAttributes;
    unsigned int				maxVertexInputBindings;
    unsigned int				maxVertexInputAttributeOffset;
    unsigned int				maxVertexInputBindingStride;
    unsigned int				maxVertexOutputComponents;
    unsigned int				maxTessellationGenerationLevel;
    unsigned int				maxTessellationPatchSize;
    unsigned int				maxTessellationControlPerVertexInputComponents;
    unsigned int				maxTessellationControlPerVertexOutputComponents;
    unsigned int				maxTessellationControlPerPatchOutputComponents;
    unsigned int				maxTessellationControlTotalOutputComponents;
    unsigned int				maxTessellationEvaluationInputComponents;
    unsigned int				maxTessellationEvaluationOutputComponents;
    unsigned int				maxGeometryShaderInvocations;
    unsigned int				maxGeometryInputComponents;
    unsigned int				maxGeometryOutputComponents;
    unsigned int				maxGeometryOutputVertices;
    unsigned int				maxGeometryTotalOutputComponents;
    unsigned int				maxFragmentInputComponents;
    unsigned int				maxFragmentOutputAttachments;
    unsigned int				maxFragmentDualSrcAttachments;
    unsigned int				maxFragmentCombinedOutputResources;
    unsigned int				maxComputeSharedMemorySize;
    unsigned int				maxComputeWorkGroupCount[3];
    unsigned int				maxComputeWorkGroupInvocations;
    unsigned int				maxComputeWorkGroupSize[3];
    unsigned int				subPixelPrecisionBits;
    unsigned int				subTexelPrecisionBits;
    unsigned int				mipmapPrecisionBits;
    unsigned int				maxDrawIndexedIndexValue;
    unsigned int				maxDrawIndirectCount;
    float						maxSamplerLodBias;
    float						maxSamplerAnisotropy;
    unsigned int				maxViewports;
    unsigned int				maxViewportDimensions[2];
    float						viewportBoundsRange[2];
    unsigned int				viewportSubPixelBits;
    unsigned long long			minMemoryMapAlignment;
    unsigned long long          minTexelBufferOffsetAlignment;
    unsigned long long          minUniformBufferOffsetAlignment;
    unsigned long long          minStorageBufferOffsetAlignment;
    int							minTexelOffset;
    unsigned int				maxTexelOffset;
    int							minTexelGatherOffset;
    unsigned int				maxTexelGatherOffset;
    float						minInterpolationOffset;
    float						maxInterpolationOffset;
    unsigned int				subPixelInterpolationOffsetBits;
    unsigned int				maxFramebufferWidth;
    unsigned int				maxFramebufferHeight;
    unsigned int				maxFramebufferLayers;
    unsigned int				framebufferColorSampleCounts;
    unsigned int				framebufferDepthSampleCounts;
    unsigned int				framebufferStencilSampleCounts;
    unsigned int				framebufferNoAttachmentsSampleCounts;
    unsigned int				maxColorAttachments;
    unsigned int				sampledImageColorSampleCounts;
    unsigned int				sampledImageIntegerSampleCounts;
    unsigned int				sampledImageDepthSampleCounts;
    unsigned int				sampledImageStencilSampleCounts;
    unsigned int				storageImageSampleCounts;
    unsigned int				maxSampleMaskWords;
    unsigned int				timestampComputeAndGraphics;
    float						timestampPeriod;
    unsigned int				maxClipDistances;
    unsigned int				maxCullDistances;
    unsigned int				maxCombinedClipAndCullDistances;
    unsigned int				discreteQueuePriorities;
    float						pointSizeRange[2];
    float						lineWidthRange[2];
    float						pointSizeGranularity;
    float						lineWidthGranularity;
    unsigned int				strictLines;
    unsigned int				standardSampleLocations;
    unsigned long long          optimalBufferCopyOffsetAlignment;
    unsigned long long          optimalBufferCopyRowPitchAlignment;
    unsigned long long          nonCoherentAtomSize;
} ADLVkPhysicalDeviceLimits, *LPADLVkPhysicalDeviceLimits;

typedef struct ADLVkPhysicalDeviceSparseProperties {
    unsigned int    residencyStandard2DBlockShape;
    unsigned int    residencyStandard2DMultisampleBlockShape;
    unsigned int    residencyStandard3DBlockShape;
    unsigned int    residencyAlignedMipSize;
    unsigned int    residencyNonResidentStrict;
} ADLVkPhysicalDeviceSparseProperties, *LPADLVkPhysicalDeviceSparseProperties;

typedef enum ADLVkPhysicalDeviceType {
    VK_PHYSICAL_DEVICE_TYPE_OTHER = 0,
    VK_PHYSICAL_DEVICE_TYPE_INTEGRATED_GPU = 1,
    VK_PHYSICAL_DEVICE_TYPE_DISCRETE_GPU = 2,
    VK_PHYSICAL_DEVICE_TYPE_VIRTUAL_GPU = 3,
    VK_PHYSICAL_DEVICE_TYPE_CPU = 4,
    VK_PHYSICAL_DEVICE_TYPE_BEGIN_RANGE = VK_PHYSICAL_DEVICE_TYPE_OTHER,
    VK_PHYSICAL_DEVICE_TYPE_END_RANGE = VK_PHYSICAL_DEVICE_TYPE_CPU,
    VK_PHYSICAL_DEVICE_TYPE_RANGE_SIZE = (VK_PHYSICAL_DEVICE_TYPE_CPU - VK_PHYSICAL_DEVICE_TYPE_OTHER + 1),
    VK_PHYSICAL_DEVICE_TYPE_MAX_ENUM = 0x7FFFFFFF
} ADLVkPhysicalDeviceType, *LPADLVkPhysicalDeviceType;

typedef struct ADLVulkanAppInfo {
    unsigned int                        apiVersion;
    unsigned int                        driverVersion;
    unsigned int                        vendorID;
    unsigned int                        deviceID;
    ADLVkPhysicalDeviceType				deviceType;
    char								deviceName[256];
    unsigned char                       pipelineCacheUUID[16];
    ADLVkPhysicalDeviceLimits              limits;
    ADLVkPhysicalDeviceSparseProperties    sparseProperties;
} ADLVulkanAppInfo, *LPADLVulkanAppInfo;

/////////////////////////////////////////////////////////////////////////////////////////
///\brief Enum containing information about Possible power states.
///
/// This enum is used to set possible power states for both AC and DC power source.
/// This enum is used by \ref ADLPowerStates 
/// \nosubgrouping
//////////////////////////////////////////////////////////////////////////////////////////
enum ADLPossiblePowerStates
{
    ADL_POWER_STATE_MAX_BATTERY      = 1,
    ADL_POWER_STATE_HIGH_BATTERY     = 2,
    ADL_POWER_STATE_BALANCED         = 3,
    ADL_POWER_STATE_HIGH_PERFORMANCE = 4,
    ADL_POWER_STATE_MAX_PERFORMANCE  = 5
};

/////////////////////////////////////////////////////////////////////////////////////////
///\brief Enum containing naming version used for battery state.
///
/// This enum is used to set naming version for optimize battery power state.
/// This enum is used by \ref ADLPowerStates 
/// \nosubgrouping
//////////////////////////////////////////////////////////////////////////////////////////
enum ADLPowerStateNameVersion
{
    Power_State_Name_Version_1     = 1,    
    Power_State_Name_Version_2     = 2,
};


/////////////////////////////////////////////////////////////////////////////////////////////
///\brief Structure containing supported power states informtation for AC and DC.
///
/// This structure is used to store information related to AC and DC power states
/// \nosubgrouping
////////////////////////////////////////////////////////////////////////////////////////////
typedef struct ADLPowerStates
{
    /// Number of Policy returned by KMD for AC
    unsigned int                NumberOfPolicyAC;    
    /// Number of Policy returned by KMD for DC
    unsigned int                NumberOfPolicyDC;       
    /// List of default AC Power States for each Power Policy
    enum ADLPossiblePowerStates      PowerStatesAC[ADL_MAX_POWER_POLICY];   
    /// List of default DC Power States for each Power Policy
    enum ADLPossiblePowerStates      PowerStatesDC[ADL_MAX_POWER_POLICY];     
    // Indicates which naming version should be used
    enum ADLPowerStateNameVersion    NamingVersion;                       
    unsigned int                Reserved[17];
} ADLPowerStates;


/////////////////////////////////////////////////////////////////////////////////////////////
///\brief Structure containing information about Overdrive 6 PowerControl settings V2.
///
/// This structure is used to store information about Overdrive 6 PowerControl settings.
/// PowerControl is the feature which allows the performance characteristics of the GPU
/// to be adjusted by changing the PowerTune power limits.
/// \nosubgrouping
////////////////////////////////////////////////////////////////////////////////////////////
typedef struct ADLOD6PowerControlInfo_X2
{
    /// The minimum PowerControl adjustment value
    int 	iMinValue;
    /// The maximum PowerControl adjustment value
    int 	iMaxValue;
    /// The minimum difference between PowerControl adjustment values
    int 	iStepValue;  

    /// Value for future extension
    int     iExtValue;
    /// Mask for future extension
    int     iExtMask;
    /// Value for ASIC TDP
    int     iTDPValue;

} ADLOD6PowerControlInfo_X2;





/////////////////////////////////////////////////////////////////////////////////////////////
///\brief Structure containing information about fullscreen descriptions
///
/// This structure is used to store flags about fullscreen.
/// \nosubgrouping
////////////////////////////////////////////////////////////////////////////////////////////
typedef struct ADL_FULLSCREEN_STATUS_FLAGS
{
    bool isFullscreen;              // 1 if current displayed primary is in fullscreen
    bool isBorderlessFullscreen;    // 1 if current displayed primary is filled with a borderless windowed app
} ADL_FULLSCREEN_STATUS_FLAGS;

/////////////////////////////////////////////////////////////////////////////////////////////
///\brief Structure containing information about DOPP primary surface descriptions
///
/// This structure is used to store information about DOPP primary surface
/// \nosubgrouping
////////////////////////////////////////////////////////////////////////////////////////////
typedef struct ADL_DOPP_PRIMARY_SURFACE_INFO
{
    unsigned int Width;
    unsigned int Height;
    unsigned int Pitch;
    unsigned int AlignedHeight;
    unsigned int BytesPP;
    int PixelFormat;
} ADL_DOPP_PRIMARY_SURFACE_INFO;









/////////////////////////////////////////////////////////////////////////////////////////////
///\brief Structure containing information about components of GPU firmware version info
///
///  Elements of GPU firmware version info.
/// \nosubgrouping
////////////////////////////////////////////////////////////////////////////////////////////

typedef struct ADLGPUVerInfo
{
    int          CpPm4UcodeVersion;
    int          UvdUcodeVersion;
    int          VceUcodeVersion;
    int          VcnUcodeVersion;
    int          SmuUcodeVersion;
    int          RlcUcodeVersion;
    int          CpMeUcodeVersion;
    int          CpMecUcodeVersion;
    int          CpPfpUcodeVersion;
    int          McUcodeVersion;
    int          PspBlUcodeVersion;
    int          PspSosUcodeVersion;
    int          PspSysUcodeVersion;
    int          DmcuUcodeVersion;
    int          SDMA0UcodeFwVersion;
    int          SDMA1UcodeFwVersion;
}ADLGPUVerInfo;


/////////////////////////////////////////////////////////////////////////////////////////////
///\brief Structure containing hashrate information
///
/// This structure is used to send hashrate data from mining application to CN via ADL.
/// \nosubgrouping
////////////////////////////////////////////////////////////////////////////////////////////
typedef struct tagHASHRATEINFO
{
    double Hashrate_;
    wchar_t ApplicationName_[260];
} HASHRATEINFO, *LPHASHRATEINFO;



enum ECC_TYPE
{
	DRAMECC = 0,
	SRAMECC,
	POSITIONING,
	ECCCOUNT
};


typedef struct ADL_RAS_GET_ERROR_COUNTS
{
	int                CorrectedErrors;    // includes both DRAM and SRAM ECC
	int                UnCorrectedErrors;  // includes both DRAM and SRAM ECC
	int  iMask;
	int  iValue;
} ADL_RAS_GET_ERROR_COUNTS;
// RAS support end

/////////////////////////////////////////////////////////////////////////////////////////////
/// \brief Structure containing information about SrcRect
///
/// This structure is used to return source rec's width, height, and left and top offset
/// \nosubgrouping
////////////////////////////////////////////////////////////////////////////////////////////
typedef struct ADLRect
{
    int iWidth;
    int iHeight;
    int iLeft;
    int iTop;
    bool bValidPlaneAttributes;
}ADLRect, *LPADLRect;

/////////////////////////////////////////////////////////////////////////////////////////////
///\brief Structure containing information related SCE profiles
///
/// This structure is used to store a bit vector of possible SCE profiles
///
/// \nosubgrouping
////////////////////////////////////////////////////////////////////////////////////////////
typedef union _ADLSCEProfile
{
	struct
	{
		unsigned int disabled : 1;
		unsigned int vividGaming : 1;
		unsigned int oledPowerSaving : 1;
		unsigned int reserved : 29;
	}bits;
	unsigned int u32All;
}ADLSCEProfile;


/////////////////////////////////////////////////////////////////////////////////////////////
///\brief Structure containing information related DCE support
///
/// This structure is used to store a bit vector of possible DCE support
///
/// \nosubgrouping
////////////////////////////////////////////////////////////////////////////////////////////
typedef union _ADLDCESupport
{
	struct
	{
		unsigned int PrePhasis : 1;
		unsigned int voltageSwing : 1;
		unsigned int reserved : 30;
	}bits;
	unsigned int u32All;
}ADLDCESupport;

/////////////////////////////////////////////////////////////////////////////////////////////
/// \brief Structure for Smart shift 2.0 settings
///
/// This structure is used to return the smart shift settings
/// \nosubgrouping
////////////////////////////////////////////////////////////////////////////////////////////
typedef struct ADLSmartShiftSettings
{
	int iMinRange;
	int iMaxRange;
	int iDefaultMode; //Refer to CWDDEPM_ODN_CONTROL_TYPE
	int iDefaultValue;
	int iCurrentMode;
	int iCurrentValue;
    int iFlags; //refer to define_smartshift_bits
}ADLSmartShiftSettings, *LPADLSmartShiftSettings;


/////////////////////////////////////////////////////////////////////////////////////////////
///\brief Structure containing information about SmartAccessMemory Settings
///
///  Elements of SmartAccessMemory settings.
/// \nosubgrouping
////////////////////////////////////////////////////////////////////////////////////////////
typedef struct ADL_SMARTACCESSMEMORY_SETTINGS
{
    bool ModeUnavailable; //Get o/p param, Tells if SMA is not available for this gpu
    bool ModeEnabled; //Get o/p & Set i/p param, Tells/Sets the current state of SAM on this gpu is/to enabled or disabled.
    int SkipPnp; //Set i/p param, Tells KMD to skip restarting driver (Pnp)
}ADL_SMARTACCESSMEMORY_SETTINGS;

/////////////////////////////////////////////////////////////////////////////////////////////
///\brief Structure containing information about UMA caps and settings Settings
///
///  The data structure is used to store UMA support, current value, default value, number of possible UMA modes
///
/// \nosubgrouping
////////////////////////////////////////////////////////////////////////////////////////////
typedef struct _UMACarveoutInfo
{
	int support; //1 support, 0: not support
	UMACarveoutModes defaultUMAMode; // default mode
    UMACarveoutModes currentUMAMode; // current mode
    int possibeUMAMode;  // bit vector, bit 0: productivity and bit 1 game mode
	int reserved[10]; // extended purpose in the future
   
}UMACarveoutInfo;

/////////////////////////////////////////////////////////////////////////////////////////////
///\brief Enum defines the causes for failure in switching the mux
///
/// This enum is used by \ref ADL2_Adapter_SmartMux_Switch_Failure_Get
/// \nosubgrouping
///////////////////////////////////////////////////////////////////////////////////////////////////////////
typedef enum _ADL_SMARTMUXFAILURE_STATE
{
    ADL_MUXCONTROL_FAILURE_DEFAULT = 0,
    ADL_MUXCONTROL_FAILURE_DX9_APP_RUNNING = 1,
    ADL_MUXCONTROL_FAILURE_EXTERNAL_DISPLAY_CONNECTED = 2,
} ADL_SMARTMUXFAILURE_STATE;

///////////////////////////////////////////////////////////////////////////////////////////////////////////
///\brief Enum defines whether the SmartMux feature is enabled/disabled
///
/// This enum is used by \ref ADL2_Adapter_SmartMux_Control_Get
/// \nosubgrouping
///////////////////////////////////////////////////////////////////////////////////////////////////////////
typedef enum _ADL_SMARTMUXENABLE_STATE
{
    ADL_MUXCONTROL_ENABLED = 0,
    ADL_MUXCONTROL_DISABLED = 1,
} ADL_SMARTMUXENABLE_STATE;

///////////////////////////////////////////////////////////////////////////////////////////////////////////
///\brief Enum defines whether the SmartMux feature is supported/not supported on the platform
///
/// This enum is used by \ref ADLDisplayMuxControl and \ref ADL2_Adapter_SmartMux_Support_Get
/// \nosubgrouping
///////////////////////////////////////////////////////////////////////////////////////////////////////////
typedef enum _ADL_SMARTMUXSUPPORT_STATE
{
    ADL_MUXCONTROL_NOT_SUPPORTED = 0,
    ADL_MUXCONTROL_SUPPORTED = 1,
} ADL_SMARTMUXSUPPORT_STATE;

///////////////////////////////////////////////////////////////////////////////////////////////////////////
///\brief Enum defines the current position of the mux (APU/dGPU)
///
/// This enum is used by \ref ADLDisplayMuxControl and \ref ADL2_Adapter_SmartMux_State_Get
/// \nosubgrouping
///////////////////////////////////////////////////////////////////////////////////////////////////////////
typedef enum _ADL_SMARTMUXCONTROL_STATE {
    ADL_MUXCONTROL_CURRENT_APU,
    ADL_MUXCONTROL_CURRENT_DGPU
} ADL_SMARTMUXCONTROL_STATE;

#endif // AMD_STRUCTURES_H_

