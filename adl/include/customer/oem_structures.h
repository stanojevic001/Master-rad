//
// Copyright (c) 2016 Advanced Micro Devices, Inc. All rights reserved.
//
// MIT LICENSE:
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

/// \file oem_structures.h
/// \brief Contains all OEM or other customer structure declarations for \ALL platforms.
///
/// All data structures used in AMD Display Library (ADL) OEM interfaces should be defined in this header file.
///

#ifndef OEM_STRUCTURES_H_
#define OEM_STRUCTURES_H_

// Place OEM/Partner constants and structure definitions here to be properly picked by Doxygen
/// \addtogroup DEFINES
/// @{

/// \defgroup define_oem_constants Non-public Constants for Partners APIs
/// This group of definitions are used by the Partners APIs and are not exposed for public use.
/// @{

/// \name Definitions used with
/// ADLDisplayNativeAUXChannelData structure
#define ADL_MAX_ACCESSAUXDATA_SIZE                          (16)		// number of char

/// \name ADLDisplayNativeAUXChannelData.iAuxStatus
#define  ADL_DISPLAY_AUX_STATUS_UNKNOWN                     (0)
#define  ADL_DISPLAY_AUX_STATUS_SUCESSFUL                   (1)
#define  ADL_DISPLAY_AUX_STATUS_FAILED_CHANNEL_BUSY         (2)
#define  ADL_DISPLAY_AUX_STATUS_FAILED_TIMEOUT              (3)
#define  ADL_DISPLAY_AUX_STATUS_FAILED_PROTOCOL_ERROR       (4)
#define  ADL_DISPLAY_AUX_STATUS_FAILED_NACK                 (5)
#define  ADL_DISPLAY_AUX_STATUS_FAILED_INCOMPLETE           (6)
#define  ADL_DISPLAY_AUX_STATUS_FAILED_OPERATION            (7)
#define  ADL_DISPLAY_AUX_STATUS_FAILED_INVALID_OPERATION    (8)
#define  ADL_DISPLAY_AUX_STATUS_FAILED_TIMEOUT_DEFER        (9)

/// \name ADLDisplayNativeAUXChannelData.iCommand

// Read from the end node sink.
#define  ADL_AUX_CHANNEL_READ                               (0)
// Write to the end node sink.
#define  ADL_AUX_CHANNEL_WRITE                              (1)
// Read from immediate device connected to the graphics card.
// In MST case the command will be sent to the first branch.
#define  ADL_AUX_CHANNEL_IMMEDIATEDEVICE_READ              	(2)
// Write to immediate device connected to the graphics card.
// In MST case the command will be sent to the first branch.
#define  ADL_AUX_CHANNEL_IMMEDIATEDEVICE_WRITE              (3)


/// \name Definitions for DDC VCP code for the backlight brightness of monitor
#define ADL_DDC_VCP_CODE_BACKLIGHT              (0x6b)

// For DDC VCP code buffer size
#define ADL_DDC_SETWRITESIZE                     (8)
#define ADL_DDC_GETRQWRITESIZE                   (6)
#define ADL_DDC_GETREPLYWRITESIZE                (1)
#define ADL_DDC_GETREPLYREADSIZE                 (11)
#define ADL_DDC_MAXREADSIZE                      (131)

// For DDC VCP code buffer offset
#define ADL_DDC_GETRQ_VCPCODE_OFFSET             (4)
#define ADL_DDC_GETRQ_CHK_OFFSET                 (5)

#define ADL_DDC_GETRP_RETURNCODE_OFFSET          (3)
#define ADL_DDC_GETRP_MAXHIGH_OFFSET             (6)
#define ADL_DDC_GETRP_MAXLOW_OFFSET              (7)
#define ADL_DDC_GETRP_CURHIGH_OFFSET             (8)
#define ADL_DDC_GETRP_CURLOW_OFFSET              (9)

#define ADL_DDC_SET_VCPCODE_OFFSET               (4)
#define ADL_DDC_SET_HIGH_OFFSET                  (5)
#define ADL_DDC_SET_LOW_OFFSET                   (6)
#define ADL_DDC_SET_CHK_OFFSET                   (7)


/// \name Definitions for Split display

// ADLSplitDisplayCaps
#define ADL_DISPLAY_SPLITDISPLAY_CAPS_STATE_SUPPORTED			0x00000001
#define ADL_DISPLAY_SPLITDISPLAY_CAPS_STATE_AVAILABLE			0x00000002
#define ADL_DISPLAY_SPLITDISPLAY_CAPS_MODE_LEFT_4_3_SUPPORTED	0x00000004

// ADLSplitDisplayState
#define ADL_DISPLAY_SPLITDISPLAY_STATE_DISABLED		0x00000000
#define ADL_DISPLAY_SPLITDISPLAY_STATE_ENABLED		0x00000001
// Transition state is used to force extended mode during enable Split display in ADL_Display_SplitDisplay_RestoreDesktopConfiguration
#define ADL_DISPLAY_SPLITDISPLAY_STATE_INTRANSITION	0x00000002

// ADLSplitDisplayMode
#define ADL_DISPLAY_SPLITDISPLAY_MODE_NONE			0x00000000
#define ADL_DISPLAY_SPLITDISPLAY_MODE_LEFT_4_3		0x00000001

// ADLSplitDisplayType
#define ADL_DISPLAY_SPLITDISPLAY_TYPE_DISABLED		0x00000000
#define ADL_DISPLAY_SPLITDISPLAY_TYPE_MAIN			0x00000001
#define ADL_DISPLAY_SPLITDISPLAY_TYPE_SHADOW		0x00000002

// Flags for ADL_Display_SplitDisplay_RestoreDesktopConfiguration
#define ADL_DISPLAY_SPLITDISPLAY_DESKTOPCONFIGURATION_VALID						0x00000001
#define ADL_DISPLAY_SPLITDISPLAY_DESKTOPCONFIGURATION_INVALID_PRIMARY_RESTORED	0x00000002
#define ADL_DISPLAY_SPLITDISPLAY_DESKTOPCONFIGURATION_INVALID_POSITION_RESTORED	0x00000004
#define ADL_DISPLAY_SPLITDISPLAY_DESKTOPCONFIGURATION_INTRANSITION_EXTENDED_RESTORED	0x00000008
#define ADL_DISPLAY_SPLITDISPLAY_DESKTOPCONFIGURATION_FAILED	0x00000010 // need to restore, but failed.

// Flags for ADL_Display_SplitDisplay_Caps
#define ADL_DISPLAY_SPLITDISPLAY_CAPS_SUPPORTED		0x00000001

#define ADL_VARIBRIGHT_ENABLED			( 1 << 0 )
#define ADL_VARIBRIGHT_DEFAULTENABLED		( 1 << 1 )

/// \name Definitions for ADL_Display_WriteAndReadI2CLargePayload

// Maximum payload size supported by ADL_Display_WriteAndReadI2CLargePayload
#define ADL_DL_I2C_MAXLARGEPAYLOADSIZE	144

/// \name Definitions for AVIVO color adjustment type
#define ADL_AVIVO_ADJUSTMENT_BRIGHTNESS            0x00000001
#define ADL_AVIVO_ADJUSTMENT_COLOR_VIBRANCE        0x00000002
#define ADL_AVIVO_ADJUSTMENT_CONTRAST              0x00000003
#define ADL_AVIVO_ADJUSTMENT_FLESH_TONE_CORRECTION 0x00000004
#define ADL_AVIVO_ADJUSTMENT_GAMMA_RED             0x00000005
#define ADL_AVIVO_ADJUSTMENT_GAMMA_GREEN           0x00000006
#define ADL_AVIVO_ADJUSTMENT_GAMMA_BLUE            0x00000007
#define ADL_AVIVO_ADJUSTMENT_HUE                   0x00000008
#define ADL_AVIVO_ADJUSTMENT_SATURATION            0x00000009
#define ADL_AVIVO_ADJUSTMENT_TINT                  0x0000000A

// \name Constant values for AVIVO brightness
#define ADL_AVIVO_BRIGHTNESS_DEFAULT                        0

/// \name Constant values for AVIVO color vibrance
#define ADL_AVIVO_COLOR_VIBRANCE_ENABLE                     0
#define ADL_AVIVO_COLOR_VIBRANCE_ENABLE_DEFAULT             0
#define ADL_AVIVO_COLOR_VIBRANCE_DEFAULT                    0
#define ADL_AVIVO_COLOR_VIBRANCE_STEP                       1
#define ADL_AVIVO_COLOR_VIBRANCE_MIN                        1
#define ADL_AVIVO_COLOR_VIBRANCE_MAX                      100

// \name Constant values for AVIVO contrast
#define ADL_AVIVO_CONTRAST_DEFAULT                        100

/// \name Constant values for AVIVO flesh tone
#define ADL_AVIVO_FLESH_TONE_ENABLE                         0
#define ADL_AVIVO_FLESH_TONE_ENABLE_DEFAULT                 0
#define ADL_AVIVO_FLESH_TONE_DEFAULT                        0
#define ADL_AVIVO_FLESH_TONE_STEP                           1
#define ADL_AVIVO_FLESH_TONE_MIN                            1
#define ADL_AVIVO_FLESH_TONE_MAX                          100

// \name Constant values for AVIVO gamma
#define ADL_AVIVO_GAMMA_DEFAULT                             0

// \name Constant values for AVIVO hue/tint
#define ADL_AVIVO_HUE_DEFAULT                               0

// \name Constant values for AVIVO saturation
#define ADL_AVIVO_SATURATION_DEFAULT                        0

/// \name ADLI2CLargePayload Flags for ADLI2CLargePayload structure
/// This group of definitions define the flags for the \ref ADLI2CLargePayload structure which is passed
/// into the \ref ADL_Display_WriteAndReadI2CLargePayload function.
/// @{
/// Skip the segment offset on I2C transactions when segment is zero
#define ADL_DL_I2C_FLAG_SKIPEMBEDDEDOFFSET          0x00000001
/// Combines the read and write transaction for multiple read addresses; Multiple Offsets should be sent in the write data buffer; iOffset itself will be ignored when this flag is used
#define ADL_DL_I2C_FLAG_COMBINEWRITEREAD            0x00000002
/// @}

/// \name Definitions for registry value types
/// Used by \ref ADL_Adapter_DriverSettings_Get and \ref ADL_Adapter_DriverSettings_Set functions
/// @{
#define ADL_REG_SZ                           0x00000001 // Unicode nul terminated string
#define ADL_REG_BINARY                       0x00000003 // Free form binary
#define ADL_REG_DWORD                        0x00000004 // 32-bit number
/// @}

/// \name Definitions for driver path options
/// Used by \ref ADL_Adapter_DriverSettings_Get and \ref ADL_Adapter_DriverSettings_Set functions
/// @{
#define ADL_REG_CURRENT_DEVICE               0x00000000
#define ADL_REG_DEVICE_FUNCTION_2            0x00000002
#define ADL_REG_ALL_MVPUDEVICES              0x00000004
#define ADL_REG_ALL_DEVICES                  0x0000FFFF
/// @}

/// @}



/// @}

/////////////////////////////////////////////////////////////////////////////////////////////
///\brief Structure containing data of native aux channel of DisplayPort display.
///
/// This structure is used to read or write native aux channel of DP display.
/// This structure is used by the ADL_Display_NativeAUXChannel_Access() function.
/// \nosubgrouping
////////////////////////////////////////////////////////////////////////////////////////////
typedef struct ADLDisplayNativeAUXChannelData
{

/// Size of this struct. The caller should set the size.
  int  iSize;
/// The result status of the function
  int  iAuxStatus;
/// Command. Currently only Read and Write are supported
  int  iCommand;
/// Address of native AUX channel
  int  iAddress;
/// Size of buffer, holds the number of valid bytes in cData.
  int  iDataSize;
/// Data buffer
  char cData[ADL_MAX_ACCESSAUXDATA_SIZE];
} ADLDisplayNativeAUXChannelData;

/////////////////////////////////////////////////////////////////////////////////////////////
/// \brief Structure containing the gamut matrix.
///
/// This structure is used to get and set the gamut matrix.
/// This structure is used by the ADL_Display_GamutMapping_Get/Set functions.
/// \nosubgrouping
////////////////////////////////////////////////////////////////////////////////////////////
typedef struct  ADLDisplayGamutMatrix
{
   int  iSize;			            // Size of the structure.
   int  iMatrixSettings[3][3];		// The 3*3 Gamut Matrix.
   int  iOffsets[3];			    // The offset.
} ADLDisplayGamutMatrix;


/////////////////////////////////////////////////////////////////////////////////////////////
/// \brief Structure containing the CurrentPixelClock
///
/// This structure is used to get the Current Pixel Clock.
/// This structure is used by the ADL_Display_CurrentPixelClock_Get() API
/// \nosubgrouping
////////////////////////////////////////////////////////////////////////////////////////////
typedef struct ADLCurrentPixelClock
{
/// Size of this struct. The caller should set the size.
	long iSize;
/// Center Frequency
    long iCenterFrequency;
/// Frequency Spread
    long iFrequencySpread;
/// Frequency Spread Type
    long iFrequencySpreadType;
/// Padding
    long iPadding[12];
} ADLCurrentPixelClock;

/////////////////////////////////////////////////////////////////////////////////////////////
/// \brief Structure containing the Pixel Clock Capabilities
///
/// This structure is used to get the Pixel Clock Caps
/// This structure is used by the ADL_Display_PixelClockCaps_Get() API
/// \nosubgrouping
////////////////////////////////////////////////////////////////////////////////////////////
typedef struct ADLPixelClockCaps
{
/// Size of this struct. The caller should set the size.
    long iSize;
/// Minimal Frequency
    long iMinFrequency;
/// Maximum Frequency
    long iMaxFrequency;
/// Padding
    long iPadding[13];
} ADLPixelClockCaps;

/////////////////////////////////////////////////////////////////////////////////////////////
/// \brief Structure containing the Pixel Clock Allowable Range
///
/// This structure is used to set the Pixel Clock Allowable Range
/// This structure is used by the ADL_Display_PixelClockAllowableRange_Set() API
/// \nosubgrouping
////////////////////////////////////////////////////////////////////////////////////////////
typedef struct ADLPixelClockRange
{
/// Size of this struct. The caller should set the size.
    long iSize;
/// Minimal Frequency
    long iMinFrequency;
/// Maximum Frequency
    long iMaxFrequency;
/// Padding
    long iPadding[13];
} ADLPixelClockRange;


/////////////////////////////////////////////////////////////////////////////////////////////
///\brief Structure containing information about the Split Display feature.
///
/// This structure is used to store the Split Display Caps information.
/// \nosubgrouping
////////////////////////////////////////////////////////////////////////////////////////////
typedef struct tagADLSplitDisplayCaps
{
	/// The logic adapter index for the current Split Display.
   	int iAdapterIndex;

	/// The displayID for the current Split Display.
    ADLDisplayID displayID;

	/// The bit mask identifies the bits this structure is currently using. Refer to ADL_DISPLAY_SPLITDISPLAY_CAPS_XXX
    int  iSplitDisplayCapsMask;

	/// The bit mask identifies the caps status. Refer to ADL_DISPLAY_SPLITDISPLAY_CAPS_XXX
    int  iSplitDisplayCapsValue;
} ADLSplitDisplayCaps, *LPADLSplitDisplayCaps;


/////////////////////////////////////////////////////////////////////////////////////////////
///\brief Structure containing information about the Split Display feature.
///
/// This structure is used to store the Split Display State information.
/// \nosubgrouping
////////////////////////////////////////////////////////////////////////////////////////////
typedef struct tagADLSplitDisplayState
{
	/// The adapter index for the current Split Display.
   	int iAdapterIndex;

	/// The displayID for the current Split Display.
    ADLDisplayID displayID;

	/// The bit mask identifies the bits this structure is currently using. Refer to ADL_DISPLAY_SPLITDISPLAY_STATE_XXX
    int  iSplitDisplayStateMask;

	/// The bit mask identifies the state status. Refer to ADL_DISPLAY_SPLITDISPLAY_STATE_XXX
	int  iSplitDisplayStateValue;

} ADLSplitDisplayState, *LPADLSplitDisplayState;


/////////////////////////////////////////////////////////////////////////////////////////////
///\brief Structure containing information about the Split Display feature.
///
/// This structure is used to store the Split Display Mode information.
/// \nosubgrouping
////////////////////////////////////////////////////////////////////////////////////////////
typedef struct tagADLSplitDisplayMode
{
	/// The adapter index for the current Split Display.
   	int iAdapterIndex;

	/// The displayID for the current Split Display.
	ADLDisplayID displayID;

	/// The bit mask identifies the bits this structure is currently using. Refer to ADL_DISPLAY_SPLITDISPLAY_MODE_XXX
	int  iSplitDisplayModeMask;

	///< The bit mask identifies the mode status. Refer to ADL_DISPLAY_SPLITDISPLAY_MODE_XXX
	int  iSplitDisplayModeValue;

} ADLSplitDisplayMode, *LPADLSplitDisplayMode;


/////////////////////////////////////////////////////////////////////////////////////////////
///\brief Structure containing information about the Split Display feature.
///
/// This structure is used to store the Split Display Type information.
/// \nosubgrouping
////////////////////////////////////////////////////////////////////////////////////////////
typedef struct tagADLSplitDisplayType
{
	/// The adapter index for the Split Display.
	int iAdapterIndex;

	/// The displayID for the Split Display.
    ADLDisplayID displayID;

	/// The bit mask identifies the bits this structure is currently using. Refer to ADL_DISPLAY_SPLITDISPLAY_TYPE_XXX
	int  iSplitDisplayTypeMask;

	/// The bit mask identifies the type status. Refer to ADL_DISPLAY_SPLITDISPLAY_TYPE_XXX
	int  iSplitDisplayTypeValue;
} ADLSplitDisplayType, *LPADLSplitDisplayType;




/////////////////////////////////////////////////////////////////////////////////////////////
///\brief Structure containing the data packet of a display.
///
/// This structure is used to get and set the data packet of a display.
/// This structure is used by the ADL_Display_InfoPacket_Get() and ADL_Display_InfoPacket_Set() functions.
/// \nosubgrouping
////////////////////////////////////////////////////////////////////////////////////////////
typedef struct  ADLDisplayDataPacket
{
/// Size of the structure
	int iSize;
/// One of these values:\n \ref ADL_DL_DISPLAY_DATA_PACKET__INFO_PACKET_RESET or \ref ADL_DL_DISPLAY_DATA_PACKET__INFO_PACKET_SET
	int iFlags;
/// Data Packet Type \ref define_display_packet
	int iPacketType;
///  Structure containing the packet info of a display.
	ADLInfoPacket sInfoPacket;
/// Structure containing the AVI packet info of a display
	ADLAVIInfoPacket sAviInfoPacket;
// Reserved
	char aucReserved[3];
}ADLDisplayDataPacket;



/////////////////////////////////////////////////////////////////////////////////////////////
///\brief Structures containing information about customer API.
////////////////////////////////////////////////////////////////////////////////////////////

enum ADL_RC_REQUEST
{
    ADL_GET_DETAILED_VIDEO_TIMING = 0,
    ADL_SET_DETAILED_VIDEO_TIMING = 1,
    ADL_RESET_CONTROLLER          = 2,
    ADL_WRITE_TMDS_BITS           = 3,
    ADL_SET_VSYNC_EVENT           = 4
};

/// \name Flags to set various TMDS bits
#define ADL_WRITE_TMDS_BITS__BIT0     0x00000001
#define ADL_WRITE_TMDS_BITS__BIT1     0x00000002
#define ADL_WRITE_TMDS_BITS__BIT2     0x00000004
#define ADL_WRITE_TMDS_BITS__BIT3     0x00000008

/// \name Mask to specify which TMDS bits to modify
#define ADL_TMDS_UPDATEMASK__BIT0     0x00000001
#define ADL_TMDS_UPDATEMASK__BIT1     0x00000002
#define ADL_TMDS_UPDATEMASK__BIT2     0x00000004
#define ADL_TMDS_UPDATEMASK__BIT3     0x00000008

// set 4 byte alignment
#pragma pack(push, 4)

// structure for:
//       ADLRCBase
// NOTE: each structure will have to start with the
//          ADL_RC_REQUEST  request;
//          unsigned int          size;
//       so we know the request type, and also we
//       can validate the size of the structure
//       from the request type...
// NOTE: the size of the structure passed in will be used to
//       validate that the request has passed in a structure
//       that can fulfill the demand as we need to statically
//       typecast internally to the appropriate structure since
//       we're using a C (not C++) interface so we can't derive
//       from the firstr structure, but we have to maintain the
//       same layout in memory to allow for appropriate typecast
// NOTE: for CRTC controllers, we need to be careful internally
//       when we do blender downscaling wiht 2 controllers, we
//       need to reset both of them...
//
typedef struct ADLRcCommand
{
    ADL_RC_REQUEST  request;
    unsigned int    size;
} ADLRcCommand;


// structure for:
//      Get/Set Detailed Video Timing
// NOTE: each structure will have to start with the
//          ADL_RC_REQUEST  request;
//          unsigned int          size;
//       so we know the request type, and also we
//       can validate the size of the structure
//       from the request type...
typedef struct ADLDetailedTimingInfo
{
    ADL_RC_REQUEST request;
    unsigned int   size;

    unsigned int  horizontalTotal;
    unsigned int  horizontalBorderLeft;
    unsigned int  horizontalAddressable;
    unsigned int  horizontalBorderRight;
    unsigned int  horizontalFrontPorch;
    unsigned int  horizontalSyncWidth;
    bool          hsyncPolarity;

    unsigned int  verticalTotal;
    unsigned int  verticalBorderTop;
    unsigned int  verticalAddressable;
    unsigned int  verticalBorderBottom;
    unsigned int  verticalFrontPorch;
    unsigned int  verticalSyncWidth;
    bool          vsyncPolarity;

    unsigned int  pixelClockInHz;
} ADLDetailedTimingInfo;

// structure for:
//      Write TMDS bits
// NOTE: each structure will have to start with the
//          ADL_RC_REQUEST  request;
//          unsigned int          size;
//       so we know the request type, and also we
//       can validate the size of the structure
//       from the request type...
typedef struct ADLWriteTMDSData
{
    ADL_RC_REQUEST  request;
    unsigned int    size;
    unsigned int    data;
    unsigned int    bitmask;
} ADLWriteTMDSData;

typedef struct ADLSetVSyncEvent
{
    ADL_RC_REQUEST  request;
    unsigned int    size;
    void*           hVSyncEvent;
    bool            enableEvent;
	unsigned int 	iDisplayIndex;
} ADLSetVSyncEvent;

#pragma pack(pop)
// restore previous byte alignment

/*
ADLGamutData gamut;
if( ADL_Display_Gamut_Get (... &gamut ) == ADL_OK )
{
    ADLGamutReference   ref;

    Following bits are valid for iGamutRef when set operation is executed:
    00 and 10 produce same result destination gamut is applied to graphics and overlay
        01 gamut source for graphics only
        11 gamut source for overlay only

        reg.iGamutRef =0;
    reg.iGamutRef = ADL_GAMUT_REFERENCE_SOURCE|ADL_GAMUT_GAMUT_VIDEO_CONTENT;
    get reference source for overlay;

    reg.iGamutRef = ADL_GAMUT_REFERENCE_SOURCE;
    get reference source for overlay;

    reg.iGamutRef = ADL_GAMUT_GAMUT_VIDEO_CONTENT;
    get reference destination for overlay;

    if( ADL_Display_Gamut_Get (..,reg &gamut ) == ADL_OK )
    {

        int                  iPredefinedGamut;
        int                  iPredefinedWhitePoint;
        ADLPoint             CustomWhitePoint;
        ADLGamutCoordinates  CustomGamut;

        the rule how to read the  gamut using  iFeature
            and assigned variables are valid.

            if( gamut.iFeature & ADL_CUSTOM_WHITE_POINT )
            {
                CustomWhitePoint      = gamut.CustomWhitePoint;
            }
            else
            {
                iPredefinedWhitePoint = gamut.iPredefinedWhitePoint;
            }

            if( gamut.iFeature & ADL_CUSTOM_GAMUT )
            {
                CustomGamut       = gamut.CustomGamut;
            }
            else
            {
                iPredefinedGamut = gamut.iPredefinedGamut;
            }
    }
}


*/



/*
ADLGamutInfo info;
ADLGamutReference   ref;

reg.iGamutRef =0;
reg.iGamutRef = ADL_GAMUT_REFERENCE_SOURCE|ADL_GAMUT_GAMUT_VIDEO_CONTENT;

get capabilities for reference source and overlay
if( ADL_Display_Gamut_GetCapabilities (...ref,  &info ) == ADL_OK )
{

    the rule how to use the  gamut info
        string localization for gamut names and white points are omitted.

        external CComboBox * pGamutCb ;
    external CComboBox * pWhitePontCb ;

    int iSelected ;

    if( info.SupportedGamutSpace & ADL_GAMUT_SPACE_CCIR_709 )
    {
        iSelected = pGamutCb->AddString( L"GAMUT_SPACE_CCIR_709" );
        pGamutCb->SetItemData(iSelected, ADL_GAMUT_SPACE_CCIR_709 );
    }
    //etc check all available declared flags
    if( info.SupportedWhitePoint & ADL_WHITE_POINT_5000K )
    {
        iSelected = pWhitePontCb->AddString( L"ADL_WHITE_POINT_5000K" );
        pWhitePontCb->SetItemData(iSelected, ADL_WHITE_POINT_5000K );
    }


    if( !info.SupportedGamutSpace & ADL_GAMUT_SPACE_CUSTOM )
    {
        //application should disable to allow user to use custom gamut
    }

    if( !info.SupportedGamutSpace & ADL_WHITE_POINT_CUSTOM )
    {
        //application should disable to allow user to use custom white point
    }
}

         driver uses following tables and the values would be divided by 10000
         const  GamutSpaceEntry GamutSpace::gamutArray [] =
                  {
                  primary name               index x_red  y_red  x_gr  y_gr  x_blue y_blue
                  { "sRgb HDTV, CCIR709",     1,   6400, 3300,  3000, 6000, 1500,  600 } ,
                  { "NTSC(1953)m, CCIR601-1", 2,   6700, 3300,  2100, 7100, 1400,  800 } ,
                  { "Adobe Rgb(1988)"       , 4,   6400, 3300,  2100, 7100, 1500,  600 } ,
                  { "CIE Rgb"               , 8,   7350, 2650,  2740, 7170, 1670,  90  }

                  } ;

           using CIE 1964
           const  WhitePointCoodinatesEntry GamutSpace::whitePointArray [] =
                      {
                      primary name   index x_white  y_white
                      { "5000K Horizon Light. ICC profile PCS"              1,   3477, 3595,   } ,
                      { "6500K Noon Daylight: Television, sRGB color space" 2,   3127, 3310,   } ,
                      { "7500K North sky Daylight "                         4,   2996, 3174,   } ,
                      { "9300K"                                             8,   2866, 2950,   }

                      } ;

*/

/////////////////////////////////////////////////////////////////////////////////////////////
/// TO BE REMOVED - Replaced by ADL_Display_RegammaCoeffEx
///\brief Structure containing information about driver supported re gamma coefficients used to build re gamma curve
///
/// This structure is used to get/set driver re gamma coefficients used to build ideal re gamma curve
/// \nosubgrouping
////////////////////////////////////////////////////////////////////////////////////////////
typedef struct ADLReGammaCoefficients
{
    /// flag ADL_EDID_REGAMMA_COEFFICIENTS set or not
    int     Feature;
    /// uses divider ADL_REGAMMA_COEFFICIENT_A0_DIVIDER
    int     CoefficientA0;
    /// uses divider ADL_REGAMMA_COEFFICIENT_A1A2A3_DIVIDER
    int     CoefficientA1;
    /// uses divider ADL_REGAMMA_COEFFICIENT_A1A2A3_DIVIDER
    int     CoefficientA2;
    /// uses divider ADL_REGAMMA_COEFFICIENT_A1A2A3_DIVIDER
    int     CoefficientA3;

}ADLReGammaCoefficients;

///////////////////////////////////////////////////////////////////////////////////////////////////////////
///\brief display gamma RAMP about gamma to programm the regamma  LUT.
/// \nosubgrouping
///////////////////////////////////////////////////////////////////////////////////////////////////////////
typedef struct ADL_Display_GammaRamp
{
   //For gamma ramp we use ushort intentionally    because the range of the values are 0-FFFF & we packed
   //the array in same way as OS Windows API Set/GetGammaRamp
   //256 ushorts for red, 256 ushorts for green & 256 ushorts for blue
   unsigned short  gamma[256*3];

} ADL_Display_GammaRamp;

///////////////////////////////////////////////////////////////////////////////////////////////////////////
/// TO BE REMOVED - Replaced by ADL_Display_RegammaCoeffEx
///\brief Structure containing information about driver supported re gamma coefficients used to build re gamma curve
/// This structure is used to get/set driver re gamma coefficients used to build ideal re gamma curve
/// \nosubgrouping
///////////////////////////////////////////////////////////////////////////////////////////////////////////
typedef struct ADL_Display_RegammaCoeff
{
    /// uses divider ADL_REGAMMA_COEFFICIENT_A0_DIVIDER
    int     CoefficientA0[3];
    /// uses divider ADL_REGAMMA_COEFFICIENT_A1A2A3_DIVIDER
    int     CoefficientA1[3];
    /// uses divider ADL_REGAMMA_COEFFICIENT_A1A2A3_DIVIDER
    int     CoefficientA2[3];
    /// uses divider ADL_REGAMMA_COEFFICIENT_A1A2A3_DIVIDER
    int     CoefficientA3[3];

} ADL_Display_RegammaCoeff;

///////////////////////////////////////////////////////////////////////////////////////////////////////////
///\brief Structure containing information about driver supported re-gamma coefficients used to build re-gamma curve
/// This structure is used to get/set driver re-gamma coefficients that are used to build an ideal re-gamma curve
/// \nosubgrouping
///////////////////////////////////////////////////////////////////////////////////////////////////////////
typedef struct ADL_Display_RegammaCoeffEx
{
    /// uses divider defined in adl_defines.h: ADL_REGAMMA_COEFFICIENT_A0_DIVIDER
    int     CoefficientA0[3];
    /// uses divider defined in adl_defines.h: ADL_REGAMMA_COEFFICIENT_A1A2A3_DIVIDER
    int     CoefficientA1[3];
    /// uses divider defined in adl_defines.h: ADL_REGAMMA_COEFFICIENT_A1A2A3_DIVIDER
    int     CoefficientA2[3];
    /// uses divider defined in adl_defines.h: ADL_REGAMMA_COEFFICIENT_A1A2A3_DIVIDER
    int     CoefficientA3[3];
	/// uses divider defined in adl_defines.h: ADL_REGAMMA_COEFFICIENT_A1A2A3_DIVIDER
	int		Gamma[3];

} ADL_Display_RegammaCoeffEx;

/////////////////////////////////////////////////////////////////////////////////////////////
/// TO BE REMOVED - Replaced by ADLRegammaEx
///\brief Structure containing information about driver supported re gamma coefficients used to build re gamma curve
///
/// This structure is used to get/set driver re gamma coefficients used to build ideal re gamma curve
/// \nosubgrouping
////////////////////////////////////////////////////////////////////////////////////////////
typedef struct ADLRegamma
{
    int     Feature;                         //flag ADL_USE_GAMMA_RAMP
	ADL_Display_GammaRamp    gamma;          //use when ADL_USE_GAMMA_RAMP is set
	ADL_Display_RegammaCoeff coefficients;   //use when ADL_USE_GAMMA_RAMP is not set

}ADLRegamma;

/////////////////////////////////////////////////////////////////////////////////////////////
///\brief Structure containing information about driver supported re-gamma coefficients used to build re-gamma curve
///
/// This structure is used to get/set driver re-gamma coefficients used to build ideal re-gamma curve
/// \nosubgrouping
////////////////////////////////////////////////////////////////////////////////////////////
typedef struct ADLRegammaEx
{
    int                      	Feature;        	//flag ADL_USE_GAMMA_RAMP
	ADL_Display_GammaRamp		gamma;				//use when ADL_USE_GAMMA_RAMP is set
	ADL_Display_RegammaCoeffEx 	coefficientsEx;   	//use when ADL_USE_GAMMA_RAMP is not set

}ADLRegammaEx;


/////////////////////////////////////////////////////////////////////////////////////////////
///\brief Structure containing information about source content color attributes
///
/// This structure is used to get/set color attributes via AVI/HDR info frame
/// \nosubgrouping
////////////////////////////////////////////////////////////////////////////////////////////
typedef struct ADLHDRContentInfo
{
    /// API version, set to 2
    int iVersion;
    /// transfer function specified with \ref define_source_content_TF
    int iTransferFunction;
    /// transfer function specified with \ref define_source_content_CS
    int iColorSpace;

    /// Display Green Chromaticity X coordinate
    double dChromaticityGreenX;
    /// Display Green Chromaticity Y coordinate
    double dChromaticityGreenY;
    /// Display Blue Chromaticity X coordinate
    double dChromaticityBlueX;
    /// Display Blue Chromaticity Y coordinate
    double dChromaticityBlueY;
    /// Display Red Chromaticity X coordinate
    double dChromaticityRedX;
    /// Display Red Chromaticity Y coordinate
    double dChromaticityRedY;
    /// Display White Point X coordinate
    double dChromaticityWhitePointX;
    /// Display White Point Y coordinate
    double dChromaticityWhitePointY;

    /// Minimum luminance in units of 1 Cd/m2 (nits)
    double dMinLuminance;
    /// Maximum luminance in units of 1 Cd/m2 (nits)
    double dMaxLuminance;
    /// Minimum content light level in units of 1 Cd/m2 (nits)
    double dMaximumContentLightLevel;
    /// Maximum frame average light level in units of 1 Cd/m2 (nits)
    double dMaximumFrameAverageLightLevel;

    /// Content info flags with \ref define_source_content_flags
    int iFlags;
} ADLHDRContentInfo, *LPADLHDRContentInfo;


///////////////////////////////////////////////////////////////////////////////////////////////////////////
///\brief Enum containing information about Display Monitor Power State.
///
/// This enum is used to set Display Monitor Power State on given adapter.
/// This enum is used by \ref ADL_Display_MonitorPowerState_Set
/// \nosubgrouping
///////////////////////////////////////////////////////////////////////////////////////////////////////////
typedef enum ADL_Display_MonitorPowerState
{
    /// Power Off State
    ADL_Display_MonitorPowerState_OFF  = 3,
    /// Power On State
    ADL_Display_MonitorPowerState_ON   = 0,

} ADL_Display_MonitorPowerState;


/////////////////////////////////////////////////////////////////////////////////////////////
/// \brief Structure containing MM video data information.
///
/// This structure is used to store the MM video data information.
/// \nosubgrouping
////////////////////////////////////////////////////////////////////////////////////////////
typedef struct ADLMMVideoData
{
	/// Video item index
	int iVideoItemIndex;
	/// Min value from controller video info
	float fMinValue;
	/// Max value from controller video info
	float fMaxValue;
	/// Default value from controller video info
	float fDefaultValue;
	/// Step
	float fStep;
	/// Current value from controller video info
	float fCurrentValue;
	/// Temporary value
	float fTemporaryValue;
	/// Video adjustable boolean value
	int bVideoAdjustable;
	/// Enable and enableDefault: ENABLE_DEFAULT_MASK = 0x01, ENABLE_CURRENT_MASK = 0x02
	unsigned iEnable;
} ADLMMVideoData, *LPADLMMVideoData;

/////////////////////////////////////////////////////////////////////////////////////////////
/// \brief Structure containing MM video set data information.
///
/// This structure is used to set MM video data.
/// \nosubgrouping
////////////////////////////////////////////////////////////////////////////////////////////
typedef struct ADLMMVideoSetData
{
	/// Video item index
	int iVideoItemIndex;
	/// Current value from controller video data </remarks>
	float fCurrentValue;
	/// Boolean value. If it is true, it is final setting, otherwise, it is temporary setting
	int bCommited;
	/// Boolean value. If it is true, it is currently enabled, otherwise, it is disabled
	int bEnabled;
}ADLMMVideoSetData, *LPADLMMVideoSetData;

/////////////////////////////////////////////////////////////////////////////////////////////
/// \brief Structure containing MM video capability data
///
/// Video Capability Data Structure, result provided by MM video driver
/// \nosubgrouping
/////////////////////////////////////////////////////////////////////////////////////////////
typedef struct ADLMMVideoCaps
{
	/// Validate fields
	int iValidFields;
	/// DeinterlaceCaps IDs
	int iDeinterlaceCaps;
	/// PostProcessingCaps IDs
	int iPostProcessingCaps;
	/// ColorManagementCaps IDs, such as MMCAPS_COLOR_VIBRANCE/FLESHTONE/TRUEWHITE
	int iColorManagementCaps;
	/// CSCCaps IDs
	int iCSCCaps;
	/// OTMCaps IDs, such as MMCAPS_OTM_OVERLAY/VMR
	int iOTMCaps;
}ADLMMVideoCaps, *LPADLMMVideoCaps;

/////////////////////////////////////////////////////////////////////////////////////////////
/// \brief Structure containing MM video generic capability data
///
/// Video Capability Data Structure, result provided by MM video driver
/// \nosubgrouping
/////////////////////////////////////////////////////////////////////////////////////////////
typedef struct ADLMMVideoGenericCaps
{
	/// Validate fields
	int iValidFields;
	/// GenericCaps IDs
	int iGenericCaps;
}ADLMMVideoGenericCaps, *LPADLMMVideoGenericCaps;

/////////////////////////////////////////////////////////////////////////////////////////////
/// Structures and definitions for the Multi-Media Re-architecture
/////////////////////////////////////////////////////////////////////////////////////////////


/// Definitions for ClientID

typedef enum ADL_FEATURE_CLIENT_ID
{
    ADL_FEATURE_CLIENT_ID_ADL = 0,
    ADL_FEATURE_CLIENT_ID_CCC = 1,
    ADL_FEATURE_CLIENT_ID_MMD = 2,
    ADL_FEATURE_CLIENT_ID_INVALID = 0xffffffff
} ADL_FEATURE_CLIENT_ID;



/// Definitions for ADLFeatureCaps.iFeatureProperties

/// Feature is SUPPORTED on this Adapter
#define ADL_FEATURE_PROPERTIES_SUPPORTED (1 << 0)

/// Feature's STATE. If not set, feature should be GRAYED OUT
#define ADL_FEATURE_PROPERTIES_STATE (1 << 1)

/// Feature is available for Advanced users
#define ADL_FEATURE_PROPERTIES_ADVANCED (1 << 2)

/// Feature is available for Standard users
#define ADL_FEATURE_PROPERTIES_STANDARD (1 << 3)

/// Feature has User-Controlled Boolean
#define ADL_FEATURE_PROPERTIES_TOGGLE (1 << 4)

/// Toggle Boolean Grays/Un-grays Adjustment
#define ADL_FEATURE_PROPERTIES_OVERRIDE (1 << 5)

/// Display related feature. If  0: Render related feature
#define ADL_FEATURE_PROPERTIES_ISDISPLAY (1 << 6)

/// 0: Nothing, 1: int range, 2: float range, 3: ENUM
#define ADL_FEATURE_PROPERTIES_ADJUSTMASK ((1 << 7) | (1 << 8))

/// int range
#define ADL_FEATURE_PROPERTIES_INT_RANGE   (1 << 7)

/// float range
#define ADL_FEATURE_PROPERTIES_FLOAT_RANGE (2 << 7)

/// ENUM
#define ADL_FEATURE_PROPERTIES_ENUM        (3 << 7)

/// Definitions for ADLFeatureCaps.iControlType
/// CheckBox
#define ADL_FEATURE_CONTROL_TYPE_CHECKBOX 0

/// Radio button
#define ADL_FEATURE_CONTROL_TYPE_RBUTTON  1

/// Definitions for ADLFeatureCaps.iControlStyle and ADLFeatureCaps.iAdjustmentStyle

/// Plain style
#define ADL_FEATURE_STYLE_PLAIN 0

/// Stylized
#define ADL_FEATURE_STYLE_STYLIZED 1

/// Definitions for ADLFeatureCaps.iAdjustmentType

/// Slider
#define ADL_FEATURE_ADJUSTMENT_TYPE_SLIDER 0

/// Spin Box
#define ADL_FEATURE_ADJUSTMENT_TYPE_SPINBOX 1

/// Slider + Spin Box
#define ADL_FEATURE_ADJUSTMENT_TYPE_SLIDER_SBOX 2

/// Text entry box
#define ADL_FEATURE_ADJUSTMENT_TYPE_TEXT 3




/////////////////////////////////////////////////////////////////////////////////////////////
///\brief Structure containing information about Remote Display caps.
///
/// This structure is used to store the information about remote display capabilities
/// This structure is used by the ADL_RemoteDisplay_Display_Acquire() function.
/// \nosubgrouping
////////////////////////////////////////////////////////////////////////////////////////////
typedef struct ADLRemoteDisplayCaps
{
/// Size of the structure
    int iSize;
/// Size of EDID data
    int iEdidSize;
/// EDID data
    char cEDIDData[ADL_MAX_OVERRIDEEDID_SIZE];
/// Reserved, Remote display capabilities, fill with 0xFF
    char cReserved[512];
} ADLRemoteDisplayCaps;


/////////////////////////////////////////////////////////////////////////////////////////////
///\brief Define Remote Display handle
///
/// This handle is used by the ADL_RemoteDisplay_Display_Acquire() and ADL_RemoteDisplay_Display_Release() functions.
/// \nosubgrouping
////////////////////////////////////////////////////////////////////////////////////////////
typedef int ADLRemoteDisplayHandle;


/////////////////////////////////////////////////////////////////////////////////////////////
///\brief Contains information about capabilities of specific Video color feature.
///
/// The structure is used with ADL_MMD_VideoColor_Caps call
/// \nosubgrouping
////////////////////////////////////////////////////////////////////////////////////////////
typedef struct ADLVideoColorCaps
{
	/// Will be set to 0 if the Video color feature is not supported. Will be set to "Not zero" value otherwise
	int iSupported;
	/// Will be set to 0 if the Video color feature is not enabled. Will be set to "Not zero" value otherwise
	int iEnabled;
	/// Minimum valid value of the Video Color feature
	float fMinValue;
	/// Maximum valid value of the Video Color feature
	float fMaxValue;
	/// Default factory value of the Video Color feature
	float fDefaultValue;
	///	Increment step of the Video Color Feature
	float fStep;
} ADLVideoColorCaps, *LPADLVideoColorCaps;

///////////////////////////////////////////////////////////////////////////////////////////////////////////
///\brief Enum defines numeric id for Video Color features such as brightness, contrast, hue �
///
/// This enum is used to identify Avivo video feature to get or set the value or to retrieve the feature capabilities.
/// This enum is used by \ref ADL_MMD_VideoColor_Caps, \ref ADL_MMD_VideoColor_Set, \ref ADL_MMD_VideoColor_Get
/// \nosubgrouping
///////////////////////////////////////////////////////////////////////////////////////////////////////////
typedef enum ADLVideoColorFeature
{
	ADL_VIDEO_COLOR_FEATURE_BRIGHTNESS			    =0,
	ADL_VIDEO_COLOR_PROPERTY_CONTRAST				=1,
	ADL_VIDEO_COLOR_PROPERTY_HUE					=2,
	ADL_VIDEO_COLOR_PROPERTY_SATURATION				=3,
	ADL_VIDEO_COLOR_PROPERTY_COLORVIBRANCE			=10,
	ADL_VIDEO_COLOR_PROPERTY_FLESHTONE				=11,
	ADL_VIDEO_COLOR_PROPERTY_GAMMA					=16,
} ADLVideoColorFeature;


///////////////////////////////////////////////////////////////////////////////////////////////////////////
///\brief Enum defines a command to execute using PsrControl API
///
/// This enum is used by \ref ADL2_Display_PsrControl
/// \nosubgrouping
///////////////////////////////////////////////////////////////////////////////////////////////////////////
typedef enum _ADL_PSRCONTROL_CMD{
    ADL_PSRCONTROL_CMD_SET_PSR_STATE,
    ADL_PSRCONTROL_CMD_QUERY_MUX_SUPPORT,
} ADL_PSRCONTROL_CMD;


///////////////////////////////////////////////////////////////////////////////////////////////////////////
///\brief Enum defines a PSR state to set using PsrControl API for ADL_PSRCONTROL_CMD_SET_PSR_STATE
/// command
///
/// This enum is used in \ref ADL2_Display_PsrControl
/// \nosubgrouping
///////////////////////////////////////////////////////////////////////////////////////////////////////////
typedef enum _ADL_PSRCONTROL_STATE {
    ADL_PSRCONTROL_PSR_STATE_0_DISABLED = 0,
    ADL_PSRCONTROL_PSR_STATE_3_ACTIVE = 3,
} ADL_PSRCONTROL_STATE;


/////////////////////////////////////////////////////////////////////////////////////////////
///\brief Structure containing data to configure and query PSR control settings
///
/// This structure is used to store and query the PSR control settings of an eDP
/// display
/// \nosubgrouping
////////////////////////////////////////////////////////////////////////////////////////////
typedef struct _ADLPsrControlSettings
{
    /// Command to execute
    ADL_PSRCONTROL_CMD cmd;

    /// Union of data structures for holding input/output data per command
    union {
        ADL_PSRCONTROL_STATE psrState;  // input for ADL_PSRCONTROL_CMD_SET_PSR_STATE cmd
        bool  muxSupported;             // output for ADL_PSRCONTROL_CMD_QUERY_MUX_SUPPORT cmd
    } data;
} ADLPsrControlSettings;

/////////////////////////////////////////////////////////////////////////////////////////////
///\brief Structure containing data to query DSC settings
///
/// This structure is used to query DSC settings of display
/// display
/// \nosubgrouping
////////////////////////////////////////////////////////////////////////////////////////////
typedef struct _ADLDSCInfo
{
	unsigned int version;
	// version >= 1
	unsigned int minTargetBitRateX16; // min bitrate in 1/16 of bpp
	unsigned int maxTargetBitRateX16; // max bitrate in 1/16 of bpp
	unsigned int maxBppIncreamentDivX16; // bpp increment divisor
	bool isDSCSupported;
	unsigned int pixClkKhz;
	unsigned int pixWidth;
	unsigned int pixHeight;
	bool isPassThroughSupported;

	bool isEnabled;
	unsigned int currentBitRateX16; // current bitrate in 1/16 of bpp
} ADLDSCInfo;

/////////////////////////////////////////////////////////////////////////////////////////////
///\brief Structure containing data to adjust DSC settings
///
/// This structure is used to adjust DSC settings of display
/// display
/// \nosubgrouping
////////////////////////////////////////////////////////////////////////////////////////////
typedef struct _ADLDSCAdjustment
{
	unsigned int version;
	// version >= 1
	bool DSCon;
	unsigned int targetBitRateX16; // target bitrate, unit in 1/16 of bpp
} ADLDSCAdjustment;

#endif /* OEM_STRUCTURES_H_ */
