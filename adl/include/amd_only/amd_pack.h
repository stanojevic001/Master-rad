///
///  Copyright (c) 2008 - 2021 Advanced Micro Devices, Inc.

///  THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
///  EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
///  WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.

/// \file amd_pack.h
/// \brief Contains all pack-specific functions in ADL for \ALL platforms.
///
/// This file contains all pack-specific functions for \ALL platforms.
/// This include file is extended when new functions need
/// to be added. All functions for CI,DI,VA,PM calls are defined in this header file.
/// This header file is for AMD internal use only.

#ifndef AMD_PACK_H_
#define AMD_PACK_H_

/*
// To enable FID10247 TODO++
#ifndef FID10247_
#define FID10247_
#endif
// To enable FID10247
*/

#include "adl_defines.h"
#include "adl_structures.h"
#include "oem_structures.h"
#include "amd_structures.h"
#include "amd_channel.h"

#if defined (_WIN32) || defined(_WIN64)
#include <winsock2.h>
#include <windows.h>
#endif

#if defined(LINUX)
#include "component_types.h"
typedef uint8_t  *LPBYTE;
#endif

#include "cwddedi.h"
#include "cwddeci.h"
#include "cwddepm.h"
#include "cwddemm.h"
#include "cwddeth.h"
#include "cwddepx.h"
#include "lhescape.h"
#if defined (_WIN32) || defined(_WIN64)
#include "cwddeva.h"
#include "kdx_umd.h"
#endif

#include "ati_format.h"
#include "shared_escape.h"

#define FORCE_PHYSICAL_DETECTION    2
#define MAX_NUM_MVPUCOMB            7
#define MAX_GPUS_IN_CHAIN           4
#define MAX_NUM_POSSIBLEMODES       1000

typedef struct DI_POSSIBLEMODES_TMP
{
    ULONG         ulSize;
    ULONG         ulNumberOfModes;
    ULONG         ulReserved;
    DI_DRIVERMODE sPreferredMode;
    DI_DRIVERMODE sModes[MAX_NUM_POSSIBLEMODES];
} DI_POSSIBLEMODES_TMP;

// For Linux build only, copy some kdx_umd.h definitions over here
#if defined(LINUX)
typedef enum _DISPLAY_DEVICE_STATE

{
    Display_Device_State_Off               = 0, // turn display off
    Display_Device_State_On                = 1, // turn display on
    Display_Device_State_Invalid           = 0xFFFFFFFF

} DISPLAY_DEVICE_STATE;

typedef struct _DISPLAY_DEVICE_STATE_INPUT
{
    DISPLAY_DEVICE_STATE                  DisplayDeviceState;
    unsigned int                          TargetHandle;
    unsigned int                          Reserved[14];
} DISPLAY_DEVICE_STATE_INPUT;

typedef struct _DISPLAY_DEVICE_STATE_OUTPUT
{
    UINT Reserved[16];
} DISPLAY_DEVICE_STATE_OUTPUT;

/// [William Zhao Oct 25, 2010] end temporary definition

/// Start: tempory definition for SDI to resolve the dependency between kdx_umd.h on vcam.h
/// the definition should be removed once kdx_umd.h can be included by ADL

typedef enum _UMDKMDIF_SDI_STATE_OP
{
    SDI_STATE_OP__ENABLE,                          //Enable SDI
    SDI_STATE_OP__DISABLE,                         //Disbale SDI
    SDI_STATE_OP__QUERY,                           //Query current SDI state
    SDI_STATE_OP__QUERY_CURRENT_STATE              //This is the alias for SDI_STATE_OP__QUERY
    = SDI_STATE_OP__QUERY,                     // just to make the meaning is more clear.
    // For new code we should use
    //    SDI_STATE_OP__QUERY_CURRENT.
    // The old operation code
    //    SDI_STATE_OP__QUERY
    // is kept for backward compatibility.
    SDI_STATE_OP__QUERY_DEFAULT_STATE,             //Query default SDI state
    SDI_STATE_OP__QUERY_LAST_USER_REQUESTED_STATE, //Query SDI state last user set
    SDI_STATE_OP__QUERY_NUM_VALID_SEG_SIZE,        //Query number of valid SDI aperture size user can set
    SDI_STATE_OP__QUERY_VALID_SEG_SIZES            //Query valid SDI apertures size user can set

} UMDKMDIF_SDI_STATE_OP;

typedef struct _UMDKMDIF_SDI_STATE_INPUT
{
    unsigned  int         Size;
    UMDKMDIF_SDI_STATE_OP SDIStateOp;            //Operation for SDI state escape call
    unsigned int          SizeOfSDISegmentInMB;  //This value is only needed for enable call.
    unsigned int          Reserved[13];
} UMDKMDIF_SDI_STATE_INPUT;

typedef struct _UMDKMDIF_SDI_STATE_OUTPUT
{
    unsigned int          Size;
    union {

        //Escape output for all query operations
        struct
        {
            unsigned int          IsSDIEnabled;         //Boolean to indicate if SDI is enabled or not.
            unsigned int          SizeOfSDISegmentInMB; //This value will be set only for query call.
            unsigned int          Reserved[13];
        };

        //Escape output for SDI_STATE_OP__QUERY_NUM_VALID_SEG_SIZE
        struct
        {
            unsigned int          NumOfValidSizeOfSDISegment;    //Number of valid size of SDI segment
            unsigned int          Reserved1[14];
        };

        //Escape output for SDI_STATE_OP__QUERY_VALID_SEG_SIZES.
        //The size of the output is varying and is determined by the output of
        //SDI_STATE_OP__QUERY_NUM_VALID_SEG_SIZE
        struct
        {
            unsigned int          ValidSizeOfSDISegmentInMB[1];  //Array of valid size of SDI segment in MB
        };
    };
} UMDKMDIF_SDI_STATE_OUTPUT;

/// End: tempory definition for SDI

/// [David Rokhvarg April 17, 2012] this is a temporary workaround for header file dependency issues.
/// Temporary definitions for S3D (copied from kdx_umd.h)
#define MAX_STEREO3D_MODES 256

typedef union _UMDKMDIF_STEREO3D_MODE_LIST_FLAGS
{
    UINT dwSize;
    UINT dwModeCount;
    struct
    {
        // query only stereo modes associated with a specific source
        unsigned int UseVidPnSourceId                                 : 1; // bit 0

        // filter mode set to include selected scanline techniques only
        unsigned int IncludeScanlineOrderingProgressive               : 1; // bit 1
        unsigned int IncludeScanlineOrderingInterlacedUpperFieldFirst : 1; // bit 2
        unsigned int IncludeScanlineOrderingInterlacedLowerFieldFirst : 1; // bit 3
        unsigned int IncludeScanlineOrderingReserved                  : 1; // bit 4

        // filter mode set to include selected scaling techniques only
        unsigned int IncludeScalingIdentity                           : 1; // bit 5
        unsigned int IncludeScalingCentered                           : 1; // bit 6
        unsigned int IncludeScalingStretched                          : 1; // bit 7
        unsigned int IncludeScalingReserved                           : 3; // bits 8,9,10

        // filter mode set to include selected 3D formats (FrameSequential selected by default)
        unsigned int Exclude3DFormatFrameSeq                          : 1; // bit 11
        unsigned int Include3DFormatSideBySide                        : 1; // bit 12
        unsigned int Include3DFormatTopBottom                         : 1; // bit 13

        // reserved for future use
        unsigned int Reserved : 18;
    };
    unsigned int u32All;
} UMDKMDIF_STEREO3D_MODE_LIST_FLAGS;

typedef union _UMDKMDIF_STEREO_INFO_FLAGS
{
    struct
    {
        unsigned int Stereo3DDevicePresent : 1;
        unsigned int CurrentModeFrameSeqSupported : 1;
        unsigned int CurrentModeSideBySideSupported : 1;
        unsigned int CurrentModeTopBottomSupported : 1;
        unsigned int Stereo3DCursorSupported : 1;
    };
    unsigned int u32All;
} UMDKMDIF_STEREO_INFO_FLAGS;

typedef struct _UMDKMDIF_GET_STEREO3D_INFO_INPUT // Structure defining input for KMD_ESUBFUNC_GET_STEREO3D_INFO escape call.
{
    unsigned int dwSize;
    unsigned int dwVidPnSourceId;
    unsigned int Reserved[6]; // Currently containing only VidPn SourceID. 8-DWORD-aligned
} UMDKMDIF_GET_STEREO3D_INFO_INPUT;

typedef struct _UMDKMDIF_GET_STEREO3D_INFO_OUTPUT // Structure defining output for KMD_ESUBFUNC_GET_STEREO3D_INFO escape call.
{
    unsigned int              dwSize;
    UMDKMDIF_STEREO_INFO_FLAGS Flags;
    unsigned int              Reserved[6]; // 8-DWORD-aligned
} UMDKMDIF_GET_STEREO3D_INFO_OUTPUT;



typedef enum _UMDKMDIF_STEREO_MODE
{
    UMDKMDIF_STEREO_MODE_HW_ALIGNED_VIEWS = 0,
    UMDKMDIF_STEREO_MODE_SW_PACKED_VIEWS = 1,
    UMDKMDIF_STEREO_MODE_NOT_SUPPORTED = 2,
    UMDKMDIF_STEREO_MODE_SIDE_BY_SIDE = 3,
    UMDKMDIF_STEREO_MODE_TOP_BOTTOM = 4
} UMDKMDIF_STEREO_MODE;

typedef struct _VIDEO_REFRESH_RATE {
    UINT  Numerator;
    UINT  Denominator;
} VIDEO_REFRESH_RATE;

typedef enum _UMDKMDIF_VIDEO_SCANLINE_ORDERING
{
    UMDKMDIF_VIDEO_SCANLINE_ORDERING_UNSPECIFIED = 0, // scanline ordering is unknown
    UMDKMDIF_VIDEO_SCANLINE_ORDERING_PROGRESSIVE = 1, // scanline ordering is progressive
    UMDKMDIF_VIDEO_SCANLINE_ORDERING_INTERLACED_UPPERFIELDFIRST = 2, // interlaced, upper-field first
    UMDKMDIF_VIDEO_SCANLINE_ORDERING_INTERLACED_LOWERFIELDFIRST = 3  // interlaced, lower-field first
} UMDKMDIF_VIDEO_SCANLINE_ORDERING;

typedef enum _UMDKMDIF_VIDEO_SCALING
{
    UMDKMDIF_VIDEO_SCALING_UNSPECIFIED = 0,    // Scaling not specified
    UMDKMDIF_VIDEO_SCALING_IDENTITY = 1,    // Content is displayed without change
    UMDKMDIF_VIDEO_SCALING_CENTERED = 2,    // Content is centered with respect to target mode
    UMDKMDIF_VIDEO_SCALING_STRETCHED = 3     // Content is stretched to target resolution
} UMDKMDIF_VIDEO_SCALING;

typedef struct _UMDKMDIF_SET_STEREO3D_2DPACKED_MODE_INPUT // Structure defining input for KMD_ESUBFUNC_SET_STEREO3D_2DPACKED_MODE escape call.
{
    unsigned int         dwSize;
    unsigned int         dwVidPnSourceId; //  Currently containing source ID
    UMDKMDIF_STEREO_MODE StereoMode;      //  and requested Stereo3D format.
    unsigned int         Reserved[5];     // 8-DWORD-aligned
} UMDKMDIF_SET_STEREO3D_2DPACKED_MODE_INPUT;

typedef struct _UMDKMDIF_GET_CURRENT_STEREO3D_FORMAT_INPUT // Structure defining input for KMD_ESUBFUNC_GET_CURRENT_STEREO3D_FORMAT escape call.
{
    unsigned int dwSize;
    unsigned int dwVidPnSourceId; // Currently containing only VidPn SourceID
    unsigned int Reserved[6];     // 8-DWORD-aligned
} UMDKMDIF_GET_CURRENT_STEREO3D_FORMAT_INPUT;

typedef struct _UMDKMDIF_GET_CURRENT_STEREO3D_FORMAT_OUTPUT // Structure defining output for KMD_ESUBFUNC_GET_CURRENT_STEREO3D_FORMAT escape call.
{
    unsigned int dwSize;
    UMDKMDIF_STEREO_MODE ActiveStereoMode;
    unsigned int Reserved[6]; // 8-DWORD-aligned
} UMDKMDIF_GET_CURRENT_STEREO3D_FORMAT_OUTPUT;

// Structure for KMD_ESUBFUNC_GET_ACPI_TRANSLATION_TABLE
typedef struct _UMDKMDIF_GET_ACPI_TRANSLATION_TABLE_INPUT
{
    unsigned int TargetCount;  // The number of targets on the adapter
    unsigned int Reserved[15]; // New fields in this structure must come before this reserved field.
} UMDKMDIF_GET_ACPI_TRANSLATION_TABLE_INPUT, *PUMDKMDIF_GET_ACPI_TRANSLATION_TABLE_INPUT;

typedef struct _ACPI_TRANSLATION
{
    unsigned int TargetId;     // A target ID uniquely identifies a display target.
    unsigned int AcpiId;       // The ACPI ID assigned to a target by SBIOS
    unsigned int Reserved[14]; // New fields in this structure must come before this reserved field.
} ACPI_TRANSLATION;

typedef struct _UMDKMDIF_GET_ACPI_TRANSLATION_TABLE_OUTPUT
{
    unsigned int Reserved[15];                // New fields in this structure must come before this reserved field.
    unsigned int NumEntries;                  // NumEntries goes hand-in-hand with the AcpiTranslationTable. As such, it is placed after the reserved field.
    ACPI_TRANSLATION AcpiTranslationTable[1]; // This element actually points to a dynamic caller-allocated array
} UMDKMDIF_GET_ACPI_TRANSLATION_TABLE_OUTPUT, *PUMDKMDIF_GET_ACPI_TRANSLATION_TABLE_OUTPUT;

typedef struct _VIDEOMODEINFO
{
    UINT                             dwSize;
    UINT                             Width;
    UINT                             Height;
    UINT                             Rotation;   // CIROTATION_ANGLExx defines
    ATI_FORMAT                       Format;     // Pixel format
    VIDEO_REFRESH_RATE               RefreshRate;
    UMDKMDIF_VIDEO_SCANLINE_ORDERING ScanlineOrdering;
    UMDKMDIF_VIDEO_SCALING           Scaling;
    UMDKMDIF_STEREO_MODE             StereoMode;
    UINT                             Reserved[6];
} VIDEOMODEINFO, *PVIDEOMODEINFO;

typedef struct _UMDKMDIF_GET_STEREO3D_MODE_LIST_INPUT
{
    UINT dwSize;
    UINT dwModeCount;
    UINT dwModeOffset;
    UMDKMDIF_STEREO3D_MODE_LIST_FLAGS ModeFlags;
    UINT dwVidPnSourceId;
    UINT Reserved[11];
} UMDKMDIF_GET_STEREO3D_MODE_LIST_INPUT;

typedef struct _UMDKMDIF_GET_STEREO3D_MODE_LIST_OUTPUT
{
    UINT dwSize;
    UINT dwModeCount;
    UINT Reserved[14];
    VIDEOMODEINFO ModeInfo[1];
} UMDKMDIF_GET_STEREO3D_MODE_LIST_OUTPUT;

// Get Max HW cursor size
typedef struct _UMDKMDIF_GET_HWCURSOR_SIZE_INPUT
{
    unsigned int VidPnSourceId;
    unsigned int Reserved[7];
} UMDKMDIF_GET_HWCURSOR_SIZE_INPUT;

typedef struct _UMDKMDIF_GET_HWCURSOR_SIZE_OUTPUT
{
    unsigned int cursorWidth;
    unsigned int cursorHeight;
    unsigned int Reserved[6];
} UMDKMDIF_GET_HWCURSOR_SIZE_OUTPUT;

// Get 3D Cursor Offset
typedef struct _UMDKMDIF_GET_3DCURSOR_OFFSET_INPUT
{
    unsigned int VidPnSourceId;
    unsigned int Reserved[7];
}UMDKMDIF_GET_3DCURSOR_OFFSET_INPUT;

typedef struct _UMDKMDIF_GET_3DCURSOR_OFFSET_OUTPUT
{
    unsigned int leftCursorOffset;
    unsigned int rightCursorOffset;
    unsigned int Reserved[6];
}UMDKMDIF_GET_3DCURSOR_OFFSET_OUTPUT;

//Set 3D Cursor Offset
typedef struct _UMDKMDIF_SET_3DCURSOR_OFFSET_INPUT
{
    unsigned int VidPnSourceId;
    unsigned int leftCursorOffset;
    unsigned int rightCursorOffset;
    unsigned int Reserved[5];
}UMDKMDIF_SET_3DCURSOR_OFFSET_INPUT;

typedef struct _UMDKMDIF_SET_3DCURSOR_OFFSET_OUTPUT
{
    unsigned int Reserved[8];
}UMDKMDIF_SET_3DCURSOR_OFFSET_OUTPUT;

/// End-of Temporary definitions for S3D

/// [Manohar  May 10, 2012] this is a temporary workaround for header file dependency issues.
/// Temporary definitions for S3D & 10 bit (copied from kdx_umd.h)
// Interface to query current state of 10 bit output
typedef enum _DISPLAY_10BIT_MODE_STATE
{
    Display_10Bit_Mode_Enable = 1,
    Display_10Bit_Mode_Disable = 2,
} DISPLAY_10BIT_MODE_STATE;

typedef struct _UMDKMDIF_DISPLAY_QUERY_10BIT_MODE_INPUT {
    UINT                            Size;
    UINT                            Reserved[15];
} UMDKMDIF_DISPLAY_QUERY_10BIT_MODE_INPUT, *PUMDKMDIF_DISPLAY_QUERY_10BIT_MODE_INPUT;


typedef struct _UMDKMDIF_DISPLAY_QUERY_10BIT_MODE_OUTPUT {
    UINT                                       Size;
    DISPLAY_10BIT_MODE_STATE                   CurrentMode;       // Returned value for enable state of 10bit
    ATI_PACKED_PIXEL_FORMAT                    PackedPixelMode;   // if Packed Pixel mode has been activated, contains the
    // mode the surfaces need to be rendered in
    UINT                                       Reserved[13];
} UMDKMDIF_DISPLAY_QUERY_10BIT_MODE_OUTPUT, *PUMDKMDIF_DISPLAY_QUERY_10BIT_MODE_OUTPUT;


typedef struct _UMDKMDIF_DISPLAY_QUERY_10BIT_MODE {
    ATI_LHESCAPE_HDR                           Header;
    unsigned int                               InputSize;
    UMDKMDIF_DISPLAY_QUERY_10BIT_MODE_INPUT    Input;
    unsigned int                               OutputSize;
    UMDKMDIF_DISPLAY_QUERY_10BIT_MODE_OUTPUT   Output;
} UMDKMDIF_DISPLAY_QUERY_10BIT_MODE, *PUMDKMDIF_DISPLAY_QUERY_10BIT_MODE;


// Interface to enable/disable 10 bit output support

typedef struct _UMDKMDIF_DISPLAY_SET_10BIT_MODE_INPUT {
    UINT                            Size;
    DISPLAY_10BIT_MODE_STATE        ModeToSet;                 // Enable/disable flag for the mode
    UINT                            Reserved[14];
} UMDKMDIF_DISPLAY_SET_10BIT_MODE_INPUT, *PUMDKMDIF_DISPLAY_SET_10BIT_MODE_INPUT;

typedef struct _UMDKMDIF_DISPLAY_SET_10BIT_MODE_OUTPUT {
    UINT                               Size;
    UINT                               Reserved[15];
} UMDKMDIF_DISPLAY_SET_10BIT_MODE_OUTPUT, *PUMDKMDIF_DISPLAY_SET_10BIT_MODE_OUTPUT;

typedef struct _UMDKMDIF_DISPLAY_SET_10BIT_MODE {
    ATI_LHESCAPE_HDR                            Header;
    unsigned int                                InputSize;
    UMDKMDIF_DISPLAY_SET_10BIT_MODE_INPUT    Input;
    unsigned int                                OutputSize;
    UMDKMDIF_DISPLAY_SET_10BIT_MODE_OUTPUT   Output;
} UMDKMDIF_DISPLAY_SET_10BIT_MODE, *PUMDKMDIF_DISPLAY_SET_10BIT_MODE;
/// End-of Temporary definitions for S3D & 10 Bit

// Interface to query current state of Workstation Stereo3D output
typedef enum _DISPLAY_WS_STEREO_3D_MODE
{
    WS_S3D_Mode_No_Stereo = 0,
    WS_S3D_Mode_ViaConnector = 1,
    WS_S3D_Mode_ViaBlueline = 2,
    WS_S3D_Mode_Passive = 3,
    WS_S3D_Mode_Passive_InvertRightHoriz = 4,
    WS_S3D_Mode_Passive_InvertRightVert = 5,
    WS_S3D_Mode_Auto = 6,
    WS_S3D_Mode_Auto_Horiz = 7,
    WS_S3D_Mode_Auto_Samsung = 8, // auto-stereo monitor for Samsung checkerboard
    WS_S3D_Mode_Auto_TSL = 9, // auto-stereo monitor for TSL interleaved
    WS_S3D_Mode_Max = 9
} DISPLAY_WS_STEREO_3D_MODE;

typedef struct _UMDKMDIF_DISPLAY_QUERY_WS_STEREO_3D_MODE_INPUT {
    UINT                            Size;
    UINT                            Reserved[15];
} UMDKMDIF_DISPLAY_QUERY_WS_STEREO_3D_MODE_INPUT, *PUMDKMDIF_DISPLAY_QUERY_WS_STEREO_3D_MODE_INPUT;

typedef struct _UMDKMDIF_DISPLAY_QUERY_WS_STEREO_3D_MODE_OUTPUT {
    UINT                                   Size;
    DISPLAY_WS_STEREO_3D_MODE              CurrentMode;   // Returns the current mode WS Stereo is operating in.
    UINT                                   Reserved[14];
} UMDKMDIF_DISPLAY_QUERY_WS_STEREO_3D_MODE_OUTPUT, *PUMDKMDIF_DISPLAY_QUERY_WS_STEREO_3D_MODE_OUTPUT;

typedef struct _UMDKMDIF_DISPLAY_QUERY_WS_STEREO_3D_MODE {
    ATI_LHESCAPE_HDR                           Header;
    unsigned int                               InputSize;
    UMDKMDIF_DISPLAY_QUERY_WS_STEREO_3D_MODE_INPUT    Input;
    unsigned int                               OutputSize;
    UMDKMDIF_DISPLAY_QUERY_WS_STEREO_3D_MODE_OUTPUT   Output;
} UMDKMDIF_DISPLAY_QUERY_WS_STEREO_3D_MODE, *PUMDKMDIF_DISPLAY_QUERY_WS_STEREO_3D_MODE;

// Interface to enable/disable Workstation Stereo3D output support

typedef struct _UMDKMDIF_DISPLAY_SET_WS_STEREO_3D_MODE_INPUT {
    UINT                                   Size;
    DISPLAY_WS_STEREO_3D_MODE              ModeToSet;     // Contains the Stereo 3D mode to set
    UINT                                   Reserved[14];
} UMDKMDIF_DISPLAY_SET_WS_STEREO_3D_MODE_INPUT, *PUMDKMDIF_DISPLAY_SET_WS_STEREO_3D_MODE_INPUT;

typedef struct _UMDKMDIF_DISPLAY_SET_WS_STEREO_3D_MODE_OUTPUT {
    UINT                               Size;
    UINT                               Reserved[15];
} UMDKMDIF_DISPLAY_SET_WS_STEREO_3D_MODE_OUTPUT, *PUMDKMDIF_DISPLAY_SET_WS_STEREO_3D_MODE_OUTPUT;

typedef struct _UMDKMDIF_DISPLAY_SET_WS_STEREO_3D_MODE {
    ATI_LHESCAPE_HDR                                Header;
    unsigned int                                    InputSize;
    UMDKMDIF_DISPLAY_SET_WS_STEREO_3D_MODE_INPUT    Input;
    unsigned int                                    OutputSize;
    UMDKMDIF_DISPLAY_SET_WS_STEREO_3D_MODE_OUTPUT   Output;
} UMDKMDIF_DISPLAY_SET_WS_STEREO_3D_MODE, *PUMDKMDIF_DISPLAY_SET_WS_STEREO_3D_MODE;


#define MAX_NUM_MVPUCOMB 3
#define MAX_NUM_POSSIBLEMODES 1000
#define FORCE_PHYSICAL_DETECTION 2

#define MAX_GPUS_IN_CHAIN	4
typedef struct _UMDKMDIF_BDF
{
    UINT bus;
    UINT device;
    UINT function;
} UMDKMDIF_BDF;

typedef struct _UMDKMDIF_GET_LOCAL_DISPLAY_CONFIG_INPUT
{
    UINT			Size;
    UINT			numSlaves;
    UMDKMDIF_BDF	slaveBDFs[MAX_GPUS_IN_CHAIN - 1];
    UINT			Reserved[5];
} UMDKMDIF_GET_LOCAL_DISPLAY_CONFIG_INPUT, *PUMDKMDIF_GET_LOCAL_DISPLAY_CONFIG_INPUT;

typedef struct _UMDKMDIF_GET_LOCAL_DISPLAY_CONFIG_OUTPUT
{
    UINT	Size;
    UINT	minNumSupportedDisplays;
    UINT	maxNumSupportedDisplays[MAX_GPUS_IN_CHAIN - 1];
    UINT	defaultNumSupportedDisplays;
    UINT	currentNumSupportedDisplays;
    UINT	Reserved[9];
} UMDKMDIF_GET_LOCAL_DISPLAY_CONFIG_OUTPUT, *PUMDKMDIF_GET_LOCAL_DISPLAY_CONFIG_OUTPUT;

typedef struct _UMDKMDIF_GET_LOCAL_DISPLAY_CONFIG
{
    ATI_LHESCAPE_HDR                            Header;
    unsigned int								InputSize;
    UMDKMDIF_GET_LOCAL_DISPLAY_CONFIG_INPUT		Input;
    unsigned int								OutputSize;
    UMDKMDIF_GET_LOCAL_DISPLAY_CONFIG_OUTPUT	Output;
} UMDKMDIF_GET_LOCAL_DISPLAY_CONFIG, *PUMDKMDIF_GET_LOCAL_DISPLAY_CONFIG;

typedef union _UMDKMDIF_SET_LOCAL_DISPLAY_CONFIG_FLAGS
{
    struct
    {
        UINT doPnp : 1;
        UINT reserved : 31;
    };
    UINT u32All;
} UMDKMDIF_SET_LOCAL_DISPLAY_CONFIG_FLAGS;

typedef struct _UMDKMDIF_SET_LOCAL_DISPLAY_CONFIG_INPUT
{
    UINT									Size;
    UINT									numSupportedDisplays;
    UMDKMDIF_SET_LOCAL_DISPLAY_CONFIG_FLAGS	flags;
    UINT									Reserved[13];
} UMDKMDIF_SET_LOCAL_DISPLAY_CONFIG_INPUT, *PUMDKMDIF_SET_LOCAL_DISPLAY_CONFIG_INPUT;

typedef struct _UMDKMDIF_SET_LOCAL_DISPLAY_CONFIG_OUTPUT
{
    UINT	Size;
    UINT	Reserved[15];
} UMDKMDIF_SET_LOCAL_DISPLAY_CONFIG_OUTPUT, *PUMDKMDIF_SET_LOCAL_DISPLAY_CONFIG_OUTPUT;

typedef struct _UMDKMDIF_SET_LOCAL_DISPLAY_CONFIG
{
    ATI_LHESCAPE_HDR                            Header;
    unsigned int								InputSize;
    UMDKMDIF_SET_LOCAL_DISPLAY_CONFIG_INPUT		Input;
    unsigned int								OutputSize;
    UMDKMDIF_SET_LOCAL_DISPLAY_CONFIG_OUTPUT	Output;
} UMDKMDIF_SET_LOCAL_DISPLAY_CONFIG, *PUMDKMDIF_SET_LOCAL_DISPLAY_CONFIG;


// ADL provides the size of the true random number that will be generated by the CPLib hardware of embedded ASICs.
// ADL allocates enough memory for the true random number and passes its pointer in the input structure to KMD.
// It also provides the size of the output buffer.
#pragma pack(push, amd_pack_h, 4)
typedef struct _UMDKMDIF_GET_TRUE_RANDOM_NUMBER_INPUT
{
    ULONG     TRNBufferSize;    //size of the output buffer
    union
    {
        VOID*   pTRNGBuffer;    // pointer to the memory where the TRN will be stored
        UINT64  p_TRNGBuffer;   // to make the size of the pointer fixed in 32 bit and 64 bit systems
    };
    ULONG     TRNSize;          //size of TRN needed, up to 128 bytes
    ULONG     padding[4];
} UMDKMDIF_GET_TRUE_RANDOM_NUMBER_INPUT;
#pragma pack(pop, amd_pack_h)
typedef struct _UMDKMDIF_GET_TRUE_RANDOM_NUMBER_OUTPUT
{
    ULONG   padding[8];
} UMDKMDIF_GET_TRUE_RANDOM_NUMBER_OUTPUT;

typedef struct _UMDKMDIF_GET_TRUE_RANDOM_NUMBER
{
    ATI_LHESCAPE_HDR                            Header;
    unsigned int                                InputSize;
    UMDKMDIF_GET_TRUE_RANDOM_NUMBER_INPUT       Input;
    unsigned int                                OutputSize;
    UMDKMDIF_GET_TRUE_RANDOM_NUMBER_OUTPUT      Output;
} UMDKMDIF_GET_TRUE_RANDOM_NUMBER, *PUMDKMDIF_GET_TRUE_RANDOM_NUMBER;

//ADL provides a 16-byte random number at input to get an 16-byte encrypted device ID as output
//ADL allocate enough memory for both input random number and encrypted output device id and passes
//their pointer to KMD in input structure. KMD passes these pointers to CPLib.
#pragma pack(push, amd_pack_h, 4)
typedef struct _UMDKMDIF_GET_UNIQUE_DEVICE_ID_INPUT
{
    ULONG   inputRandSize;        //size of input random number
    union
    {
        VOID*   pInputRand;       //pointer to 16 byte random number
        UINT64  p_InputRand;      //to make the size of the pointer fixed in 32 bit and 64 bit systems
    };
    union
    {
        VOID*   pDeviceID;        //pointer to 16 byte Device ID
        UINT64  p_DeviceID;       //to make the size of the pointer fixed in 32 bit and 64 bit systems
    };
    ULONG   deviceIDBufferSize;   //size of output device ID buffer
    ULONG   padding[2];
} UMDKMDIF_GET_UNIQUE_DEVICE_ID_INPUT;
#pragma pack(pop, amd_pack_h)

typedef struct _UMDKMDIF_GET_UNIQUE_DEVICE_ID_OUTPUT
{
    ULONG   deviceIDSize;       //size of encrypted Device ID
    ULONG   padding[7];
} UMDKMDIF_GET_UNIQUE_DEVICE_ID_OUTPUT;

typedef struct _UMDKMDIF_GET_UNIQUE_DEVICE_ID
{
    ATI_LHESCAPE_HDR                            Header;
    unsigned int                                InputSize;
    UMDKMDIF_GET_UNIQUE_DEVICE_ID_INPUT         Input;
    unsigned int                                OutputSize;
    UMDKMDIF_GET_UNIQUE_DEVICE_ID_OUTPUT        Output;
} UMDKMDIF_GET_UNIQUE_DEVICE_ID, *PUMDKMDIF_GET_UNIQUE_DEVICE_ID;

#define MAX_NUM_ERROR_RECORDS 256


typedef struct _ERROR_RECORD {

    // Severity of error
    ADL_ERROR_RECORD_SEVERITY Severity;

    // Is the counter valid?
    BOOLEAN countValid;

    // Counter value, if valid
    UINT count;

    // Is the location information valid?
    BOOLEAN LocationValid;

    // Physical location of error
    UINT CU; // CU number on which error occurred, if known
    CHAR StructureName[32]; // e.g. LDS, TCC, etc.

    // Time of error record creation (e.g. time of query, or time of poison interrupt)
    CHAR timestamp[32];

    UINT padding[3];
}ERROR_RECORD;

typedef struct _UMDKMDIF_GET_EDC_ERROR_RECORDS_INPUT
{
    ADL_ECC_EDC_FLAG eccEdcFlag;
    UINT padding[15]; //reserved for future use
} UMDKMDIF_GET_EDC_ERROR_RECORDS_INPUT;

typedef struct _UMDKMDIF_GET_EDC_ERROR_RECORDS_OUTPUT
{
    unsigned long long pErrorRecord;
    UINT errorRecordCount;
    UINT errorCount;
    BOOLEAN isOverflow;
    UINT padding[11];
} UMDKMDIF_GET_EDC_ERROR_RECORDS_OUTPUT;

typedef struct _UMDKMDIF_EDC_ERROR_INJECTION_INPUT
{
    ADL_EDC_BLOCK_ID blockId;
    ADL_ERROR_INJECTION_MODE errorInjectionMode;
    ADL_ERROR_INJECTION_DATA errorInjectionData;
    ADL_ECC_EDC_FLAG eccEdcFlag;
    UINT padding[1];
} UMDKMDIF_EDC_ERROR_INJECTION_INPUT;

typedef struct _UMDKMDIF_EDC_ERROR_INJECTION_OUTPUT
{
    BOOLEAN isAccessible;
    UINT padding[15];
} UMDKMDIF_EDC_ERROR_INJECTION_OUTPUT;

//Check if uncorrectable error happened on Vega10 HBM ECC
typedef struct _UMDKMDIF_CHECK_HBM_ECC_UC_INPUT
{
    UINT padding[16];
} UMDKMDIF_CHECK_HBM_ECC_UC_INPUT;

typedef struct _UMDKMDIF_CHECK_HBM_ECC_UC_OUTPUT
{
    BOOLEAN isUCHappened;
    UINT padding[15];
} UMDKMDIF_CHECK_HBM_ECC_UC_OUTPUT;


//=======================================================================================
// ************************************************************************************ \\
// RAS support
typedef struct _UMDKMDIF_RAS_GET_ERROR_COUNTS_INPUT
{
	unsigned int                Reserved[16];
} UMDKMDIF_RAS_GET_ERROR_COUNTS_INPUT;

typedef struct _UMDKMDIF_RAS_GET_ERROR_COUNTS_OUTPUT
{
	unsigned int                CorrectedErrors;    // includes both DRAM and SRAM ECC
	unsigned int                UnCorrectedErrors;  // includes both DRAM and SRAM ECC
	unsigned int                Reserved[14];
} UMDKMDIF_RAS_GET_ERROR_COUNTS_OUTPUT;

typedef struct _UMDKMDIF_RAS_GET_ERROR_COUNTS
{
	ATI_LHESCAPE_HDR                        Header;
	unsigned int                            InputSize;
	UMDKMDIF_RAS_GET_ERROR_COUNTS_INPUT     Input;
	unsigned int                            OutputSize;
	UMDKMDIF_RAS_GET_ERROR_COUNTS_OUTPUT     Output;
} UMDKMDIF_RAS_GET_ERROR_COUNTS;


typedef struct _UMDKMDIF_RAS_RESET_ERROR_COUNTS_INPUT
{
	unsigned int                Reserved[8];
} UMDKMDIF_RAS_RESET_ERROR_COUNTS_INPUT;

typedef struct _UMDKMDIF_RAS_RESET_ERROR_COUNTS_OUTPUT
{
	unsigned int                Reserved[8];
} UMDKMDIF_RAS_RESET_ERROR_COUNTS_OUTPUT;

typedef struct _UMDKMDIF_RAS_RESET_ERROR_COUNTS
{
	ATI_LHESCAPE_HDR                        Header;
	unsigned int                            InputSize;
	UMDKMDIF_RAS_RESET_ERROR_COUNTS_INPUT   Input;
	unsigned int                            OutputSize;
	UMDKMDIF_RAS_RESET_ERROR_COUNTS_OUTPUT  Output;
} UMDKMDIF_RAS_RESET_ERROR_COUNTS;

typedef struct _UMDKMDIF_RAS_ERROR_INJECTION_INPUT
{
	UINT64 Address;
	UINT64 Value;
	UINT BlockId;
	UINT InjectErrorType;
	UINT SubBlockIndex;
	UINT padding[9];
} UMDKMDIF_RAS_ERROR_INJECTION_INPUT;

typedef struct _UMDKMDIF_RAS_ERROR_INJECTION_OUTPUT
{
	UINT Status;
	UINT padding[15];
} UMDKMDIF_RAS_ERROR_INJECTION_OUTPUT;

typedef struct _UMDKMDIF_RAS_ERROR_INJECTION
{
	ATI_LHESCAPE_HDR                       Header;
	unsigned int                           InputSize;
	UMDKMDIF_RAS_ERROR_INJECTION_INPUT     Input;
	unsigned int                           OutputSize;
	UMDKMDIF_RAS_ERROR_INJECTION_OUTPUT    Output;
} UMDKMDIF_RAS_ERROR_INJECTION;


#define MAX_POWER_POLICY    6

typedef enum _KMD_WINDOWS_POWER_STATE
{
    KMD_WINDOWS_POWER_STATE_MAX_BATTERY = 1,
    KMD_WINDOWS_POWER_STATE_HIGH_BATTERY = 2,
    KMD_WINDOWS_POWER_STATE_BALANCED = 3,
    KMD_WINDOWS_POWER_STATE_HIGH_PERFORMANCE = 4,
    KMD_WINDOWS_POWER_STATE_MAX_PERFORMANCE = 5
} KMD_WINDOWS_POWER_STATE;

typedef enum _KMD_WINDOWS_POWER_SOURCE
{
    KMD_WINDOWS_POWER_SOURCE_AC = 0,
    KMD_WINDOWS_POWER_SOURCE_DC = 1,
    KMD_WINDOWS_POWER_SOURCE_BOTH = 2
} KMD_WINDOWS_POWER_SOURCE;

typedef enum _POWER_STATE_NAME_VERSION
{
    POWER_STATE_NAME_VERSION_1 = 1,
    POWER_STATE_NAME_VERSION_2 = 2,
} POWER_STATE_NAME_VERSION;

typedef struct _UMDKMDIF_QUERY_DEFAULT_POWER_STATES_INPUT
{
    KMD_WINDOWS_POWER_SOURCE    PowerSource;                       // Which Power Source we are querying
    unsigned int                Reserved[15];
} UMDKMDIF_QUERY_DEFAULT_POWER_STATES_INPUT;

typedef struct _UMDKMDIF_QUERY_DEFAULT_POWER_STATES_OUTPUT
{
    unsigned int                NumberOfPolicyAC;                    // Number of Policy returned by KMD for AC
    unsigned int                NumberOfPolicyDC;                    // Number of Policy returned by KMD for DC
    KMD_WINDOWS_POWER_STATE     PowerStatesAC[MAX_POWER_POLICY];     // List of default AC Power States for each Power Policy
    KMD_WINDOWS_POWER_STATE     PowerStatesDC[MAX_POWER_POLICY];     // List of default DC Power States for each Power Policy
    POWER_STATE_NAME_VERSION    NamingVersion;                       // Indicates which naming version should be used
    unsigned int                Reserved[17];
} UMDKMDIF_QUERY_DEFAULT_POWER_STATES_OUTPUT;

typedef struct _UMDKMDIF_QUERY_DEFAULT_POWER_STATES
{
    ATI_LHESCAPE_HDR                               Header;
    unsigned int                                   InputSize;
    UMDKMDIF_QUERY_DEFAULT_POWER_STATES_INPUT      Input;
    unsigned int                                   OutputSize;
    UMDKMDIF_QUERY_DEFAULT_POWER_STATES_OUTPUT     Output;
} UMDKMDIF_QUERY_DEFAULT_POWER_STATES;

typedef enum _UMD_EVENT_RETCODE
{
    UMD_EVENT_RETCODE_SUCCESS               = 0,
    UMD_EVENT_RETCODE_ERR_NOT_SUPPORTED     = 1,
    UMD_EVENT_RETCODE_ERR_BAD_EVENT_HANDLE  = 2
} UMD_EVENT_RETCODE;

typedef enum _UMDKMDIF_EVENT_TRACKING_TYPE
{
    DXUMD_EVENT_TRACKING_PREEMPTION                     = 0,
    DOPP_EVENT_TRACKING_MODESET                         = 1,
    DOPP_EVENT_TRACKING_POINTERSHAPESET                 = 2,
    DOPP_EVENT_TRACKING_DESKTOPCHANGED                  = 3,
    DXUMD_CUSTOM_DISPLAY_EVENT_ENUMERATION              = 4,
    UMD_EVENT_ID_GAMMARAMP                              = 5,
    UMD_EVENT_ID_POWERPLAY                              = 6,
    UMD_EVENT_ID_OVERDRIVE                              = 7,
    UMD_EVENT_ID_OTM                                    = 8,
    UMD_EVENT_ID_VIDEOMODE                              = 9,
    UMD_EVENT_ID_HOTPLUG                                = 10,
    UMD_EVENT_ID_MVPU                                   = 11,
    UMD_EVENT_ID_QUEYVIDEOCAPS                          = 12,
    UMD_EVENT_ID_GLSYNC                                 = 13,
    UMD_EVENT_ID_QUERYVIDEOVALUES                       = 14,
    UMD_EVENT_ID_GAMEMANAGER_APP_LAUNCH                 = 15,
    UMD_EVENT_ID_GAMEMANAGER_APP_TERMINATE              = 16,
    DSE_EVENT_TRACKING_MODESET                          = 17,
    ADL_EVENT_TRACKING_VSYNCINTERRUPT                   = 18,
    DXUMD_EVENT_TRACKING_MAX                            = 19
} UMDKMDIF_EVENT_TRACKING_TYPE;

typedef enum _UMD_EVENT_CLIENT
{
    UMD_EVENT_CLIENT_UNKNOWN                = 0,
    UMD_EVENT_CLIENT_CCC                    = 1,
    UMD_EVENT_CLIENT_CCC_NEXT               = 2,
    UMD_EVENT_CLIENT_PIXEL_SHARP            = 3,
    UMD_EVENT_CLIENT_ADL                    = 4,
    MAX_UMD_EVENT_CLIENT                    = 5
} UMD_EVENT_CLIENT;

typedef enum _UMD_EVENT_LEVEL
{
    UMD_EVENT_PER_GPU        = 0,
    UMD_EVENT_SYSTEM_LEVEL   = 1
} UMD_EVENT_LEVEL;

#pragma pack(push, amd_pack_h, 4)

typedef struct _UMDKMDIF_USERMODE_EVENT_OUTPUT {
    unsigned int                 reserved[8];
}UMDKMDIF_USERMODE_EVENT_OUTPUT;

typedef struct _UMDKMDIF_USERMODE_EVENT_INPUT {
    UMDKMDIF_EVENT_TRACKING_TYPE eventType;
    ULONGLONG                    eventHandle;
    ULONG                        eventParameter;
    UMD_EVENT_CLIENT             clientId;
    UMD_EVENT_LEVEL              eventLevel;
    unsigned int                 reserved[10];
}UMDKMDIF_USERMODE_EVENT_INPUT;

typedef struct _UMDKMDIF_USERMODE_EVENT_REQUEST {
    ATI_LHESCAPE_HDR               header;
    unsigned int                   InputSize;
    UMDKMDIF_USERMODE_EVENT_INPUT  Input;
    unsigned int                   OutputSize;
    UMDKMDIF_USERMODE_EVENT_OUTPUT Output;
}UMDKMDIF_USERMODE_EVENT_REQUEST;

typedef struct _UMDKMDIF_UNREGISTER_USERMODE_EVENT_INPUT
{
    UMDKMDIF_EVENT_TRACKING_TYPE eventType;
    UMD_EVENT_CLIENT             clientId;
    ULONGLONG                    eventHandle;
    UMD_EVENT_LEVEL              eventLevel;
    unsigned int                 reserved[11];
} UMDKMDIF_UNREGISTER_USERMODE_EVENT_INPUT;

typedef struct _UMDKMDIF_UNREGISTER_USERMODE_EVENT_OUTPUT
{
    UMD_EVENT_RETCODE   RetCode;
    unsigned int        Reserved[7];
} UMDKMDIF_UNREGISTER_USERMODE_EVENT_OUTPUT;

#pragma pack(pop, amd_pack_h)

#endif


///
/// \brief Function to retrieve ATI driver adapter information.
///
/// This function implements a DI call to retrieve ATI adapter information.
/// \platform
/// \ALL
/// \param[in]  iAdapterIndex  The ADL index handle of the desired adapter.
/// \param[in]  doDetection    Indicates to the driver whether physical detection is required before the adapter information is returned. 1: do detection; 0: no detection.
/// \param[out]  adapterInfo   The pointer to the structure storing the retrieved ATI adapter information.
/// \return If the function succeeds, the return value is \ref ADL_OK, or an ADL error code otherwise. \ref define_adl_results
int HIDDEN Pack_DI_AdapterInfo_Get(int iAdapterIndex,  int doDetection, ADAPTERINFO *adapterInfo);

///
/// \brief Function to retrieve adapter caps information.
///
/// This function implements a DI call to retrieve adapter capability information .
/// \platform
/// \ALL
/// \param[in]  iAdapterIndex   The ADL index handle of the desired adapter.
/// \param[out]  adapterCaps    The pointer to the structure storing the retrieved adapter capability information.
/// \return If the function succeeds, the return value is \ref ADL_OK, or an ADL error code otherwise. \ref define_adl_results
int HIDDEN Pack_DI_AdapterCaps_Get(int iAdapterIndex,  ADAPTERCAPS *adapterCaps);

///
/// \brief Function to retrieve adapter audio channel split configuration.
///
/// This function implements a DI call to retrieve adapter audio channel split configuration.
/// \platform
/// \ALL
/// \param[in]  iAdapterIndex   The ADL index handle of the desired adapter per physical GPU.
/// \param[out] pAdapterAudioChannelSplitConfig  The pointer to the structure storing the retrieved adapter audio channel split configuration.
/// \return If the function succeeds, the return value is \ref ADL_OK, or an ADL error code otherwise. \ref define_adl_results
int HIDDEN Pack_DI_AdapterAudioChannelSplitConfiguration_Get(int iAdapterIndex,  DI_ADAPTER_AUDIOCHANNEL_SPLIT_SETTING_EX *pAdapterAudioChannelSplitConfig);

///
/// \brief Function to enable multichannel splitting on a given adapter with enable only and save profile only options.
///
/// This function implements a DI call to enable multichannel splitting on a given adapter with enable only and save profile only options.
/// \platform
/// \ALL
/// \param[in]  iAdapterIndex   The ADL index handle of the desired adapter per physical GPU.
/// \param[out] pAdapterAudioChannelSplitRequest  The pointer to the structure storing the request for enabling multi channel splitting.
/// \return If the function succeeds, the return value is \ref ADL_OK, or an ADL error code otherwise. \ref define_adl_results
int HIDDEN Pack_DI_AdapterAudioChannelSplit_Enable(int iAdapterIndex,  DI_ADAPTER_AUDIOCHANNEL_SPLIT_SETTING_EX *pAdapterAudioChannelSplitRequest);

///
/// \brief Function to disables multichannel splitting on a given adapter.
///
/// This function implements a DI call to disable multichannel splitting on a given adapter.
/// \platform
/// \ALL
/// \param[in]  iAdapterIndex   The ADL index handle of the desired adapter per physical GPU.
/// \return If the function succeeds, the return value is \ref ADL_OK, or an ADL error code otherwise. \ref define_adl_results
int HIDDEN Pack_DI_AdapterAudioChannelSplit_Disable(int iAdapterIndex);

///
/// \brief Function to get audio information and speaker allocation from a display's EDID.
///
/// This function implements a DI call to get audio information and speaker allocation from a display's EDID.
/// \platform
/// \ALL
/// \param[in]  iAdapterIndex   The ADL index handle of the desired adapter per physical GPU.
/// \param[in] displayIdentifier The display identifier
/// \param[out] pAudioInfo The pointer to the structure containing audio capability from display EDID
/// \return If the function succeeds, the return value is \ref ADL_OK, or an ADL error code otherwise. \ref define_adl_results
int HIDDEN Pack_DI_AdapterDisplayAudioInfo_Get(int iAdapterIndex, ADLDisplayIdentifier displayIdentifier, DI_DISPLAY_AUDIO_INFO *pAudioInfo);

///
///\brief Function to enable Azalia audio end point on a given display
///
/// This function implements a DI call to enable Azalia audio end point on a given display
/// \platform
/// \WIN
/// \param[in] iAdapterIndex The ADL index handle of the desired adapter per physical GPU.
/// \param[in] displayIdentifier The display identifier
/// \param[in] bEnable Set to true if audio end point is to be enabled. Set to false if audio end point is to be disabled
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
int HIDDEN Pack_DI_AdapterDisplayAudioEndpoint_Enable(int iAdapterIndex, ADLDisplayIdentifier displayIdentifier, BOOL bEnable);

///
///\brief Function to mute Azalia audio end point on a given display
///
/// This function implements a DI call to mute Azalia audio endpoint on a given display
/// \platform
/// \WIN
/// \param[in] iAdapterIndex The ADL index handle of the desired adapter per physical GPU.
/// \param[in] displayIdentifier The display identifier
/// \param[in] bMute Set to true if audio end point is to be muted. Set to false if audio end point is to be unmuted
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
int HIDDEN Pack_DI_AdapterDisplayAudioEndpoint_Mute(int iAdapterIndex, ADLDisplayIdentifier displayIdentifier, BOOL bMute);

///
/// \brief Function to retrieve a display output descriptor.
///
/// This function implements a DI call to retrieve display output descriptor information.
/// \platform
/// \ALL
/// \param[in]  iAdapterIndex              The ADL index handle of the desired adapter.
/// \param[in]  iDisplayIndex              The desired display index.
/// \param[out]  displayOutputDescriptor   The pointer to the structure storing the retrieved display output descriptor information.
/// \return If the function succeeds, the return value is \ref ADL_OK, or an ADL error code otherwise. \ref define_adl_results
int HIDDEN Pack_DI_DisplayOutputDescriptor_Get(int iAdapterIndex,  int iDisplayIndex,DI_DISPLAYOUTPUTDESCRIPTOR *displayOutputDescriptor);

///
/// \brief Function to retrieve display device information.
///
/// This function implements a DI call to retrieve display device information
/// \platform
/// \ALL
/// \param[in]  iAdapterIndex        The ADL index handle of the desired adapter.
/// \param[in]  iDisplayIndex        The desired display index.
/// \param[out]  displayDeviceInfo   The pointer to the structure storing the retrieved display device information.
/// \return If the function succeeds, the return value is \ref ADL_OK, or an ADL error code otherwise. \ref define_adl_results
int HIDDEN Pack_DI_DisplayDeviceInfo_Get(int iAdapterIndex,  int iDisplayIndex,DISPLAYDEVICEINFO *displayDeviceInfo);

///
/// \brief Function to retrieve display and controller mapping information.
///
/// This function implements a DI call to retrieve display and controller mapping information
/// \platform
/// \ALL
/// \param[in]  iAdapterIndex       The ADL index handle of the desired adapter.
/// \param[out]  displayCrtcOwner   The pointer to the structure storing the retrieved display and controller mapping information.
/// \return If the function succeeds, the return value is \ref ADL_OK, or an ADL error code otherwise. \ref define_adl_results
int HIDDEN Pack_DI_DisplayCrtcOwner_Get(int iAdapterIndex, CRTCOWNED *displayCrtcOwner);

///
/// \brief Function to retrieve display capability information.
///
/// This function implements a DI call to retrieve display capability information.
/// \platform
/// \ALL
/// \param[in]  iAdapterIndex   The ADL index handle of the desired adapter.
/// \param[in]  iDisplayIndex   The desired display index.
/// \param[out]  displayCaps    The pointer to the structure storing the retrieved display capability information.
/// \return If the function succeeds, the return value is \ref ADL_OK, or an ADL error code otherwise. \ref define_adl_results
int HIDDEN Pack_DI_DisplayCaps_Get(int iAdapterIndex, int iDisplayIndex,  DISPLAYCAPS *displayCaps);

///
/// \brief Function to retrieve display option information.
///
/// This function implements a DI call to retrieve display option information.
/// \platform
/// \ALL
/// \param[in]  iAdapterIndex   The ADL index handle of the desired adapter.
/// \param[in]  iDisplayIndex   The desired display index.
/// \param[out]  displayOption  The pointer to the structure storing the retrieved display option information.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
int HIDDEN Pack_DI_DisplayOption_Get(int iAdapterIndex, int displayIndex,  DI_DISPLAYOPTION *lpDisplayOption);

///
/// \brief Function to sets the display.
///
/// This function implements a DI call to set the display.
/// \platform
/// \ALL
/// \param[in]  iAdapterIndex    The ADL index handle of the desired adapter.
/// \param[in]  iDisplayIndex    The desired display index.
/// \param[in]  displayOption    The desired preset display option.
/// \return If the function succeeds, the return value is \ref ADL_OK, or an ADL error code otherwise. \ref define_adl_results
int HIDDEN Pack_DI_DisplayOption_Set(int iAdapterIndex, int iDisplayIndex,  DI_DISPLAYOPTION displayOption);


///
/// \brief Function to retrieve the controller configuration.
///
/// This function implements a DI call to retrieve the configuration of the controller, dedicated to ASICs below R520.
/// \platform
/// \ALL
/// \param[in]  iAdapterIndex       The ADL index handle of the desired adapter.
/// \param[in]  controllerIndex     The desired controller index.
/// \param[out] controllerConfig    The The pointer to the structure storing the retrieved configuration of the controller.
/// \return If the function succeeds, the return value is \ref ADL_OK, or an ADL error code otherwise. \ref define_adl_results
int HIDDEN Pack_DI_ControllerConfig_Get(int iAdapterIndex, int controllerIndex, CONTROLLERCONFIG *controllerConfig);

///
/// \brief Function to retrieve the controller mode.
///
/// This function implements a DI call to retrieve the mode of the controller, dedicated to R520 or ASICs above.
/// \platform
/// \ALL
/// \param[in]  iAdapterIndex     The ADL index handle of the desired adapter.
/// \param[in]  controllerIndex   The desired controller index.
/// \param[out] controllerMode    The pointer to the structure storing the retrieved mode of the controller.
/// \return If the function succeeds, the return value is \ref ADL_OK, or an ADL error code otherwise. \ref define_adl_results
int HIDDEN Pack_DI_ControllerMode_Get(int iAdapterIndex, int controllerIndex,  CONTROLLERMODE *controllerMode);

//
/// \brief Function to se the controller configuration.
///
/// This function implements a DI call to configure the controller, dedicated to R520 or ASICs above.
/// \platform
/// \ALL
/// \param[in]  iAdapterIndex      The ADL index handle of the desired adapter.
/// \param[in]  controllerIndex    The desired controller index.
/// \param[in] controllerConfig    The desired preset configuration of the controller.
/// \return If the function succeeds, the return value is \ref ADL_OK, or an ADL error code otherwise. \ref define_adl_results
int HIDDEN Pack_DI_ControllerConfig_Set(int iAdapterIndex, int controllerIndex, CONTROLLERCONFIG controllerConfig);

///
/// \brief Function to set the controller mode.
///
/// This function implements a DI call to set controller mode, dedicated to R520 or ASICs above .
/// \platform
/// \ALL
/// \param[in]  iAdapterIndex    The ADL index handle of the desired adapter.
/// \param[in]  controllerIndex  The desired controller index.
/// \param[in]  controllerMode   The desired preset mode of the controller.
/// \return If the function succeeds, the return value is \ref ADL_OK, or an ADL error code otherwise. \ref define_adl_results
int HIDDEN Pack_DI_ControllerMode_Set(int iAdapterIndex, int controllerIndex, CONTROLLERMODE controllerMode);

///
/// \brief Function to retrieve DDC block access.
///
/// This function implements a DI call to retrieve DDC block access.
/// \platform
/// \ALL
/// \param[in]  iAdapterIndex   The ADL index handle of the desired adapter.
/// \param[in]  iDisplayIndex   The desired display index.
/// \param[in]  DDCInput        The desired DDC input buffer.
/// \param[out] DDCOutput       The pointer to the DDC output buffer.
/// \return If the function succeeds, the return value is \ref ADL_OK, or an ADL error code otherwise.  \ref define_adl_results
int HIDDEN Pack_DI_DisplayDDCBlockAccess_Get(int iAdapterIndex, int iDisplayIndex, DISPLAYACCESSDDCINPUTDATA &DDCInput,DISPLAYACCESSDDCOUTPUTDATA *DDCOutput) ;

/// \brief Function to Access DDC for Read/Write Data up to 512 Bytes.
///
/// This function implements DI call (CWDDEDI_DisplayAccessDDCLineLarge) to retrieve DDC block access.
/// \platform
/// \ALL
/// \param[in]  iAdapterIndex   The ADL index handle of the desired adapter.
/// \param[in]  iDisplayIndex   The desired display index.
/// \param[in]  iInputDataSize  The input data size.
/// \param[in]  DDCInput        The desired DDC input buffer for Write Data up to 512 Bytes
/// \param[in]  iOutputDataSize  The outputDataSize
/// \param[out] DDCOutput       The pointer to the DDC output buffer for Read Data up to 512 Bytes
/// \return If the function succeeds, the return value is \ref ADL_OK, or an ADL error code otherwise.  \ref define_adl_results
int HIDDEN Pack_DI_DisplayDDCBlockAccessEx_Get(int iAdapterIndex, int iDisplayIndex, int iInputDataSize, DI_ACCESSDDCEX_IN *lpDDCInput,int iOutputDataSize,DI_ACCESSDDCEX_OUT *lpDDCOutput) ;

///
/// \brief Function to retrieve the adapter driver configuration.
///
/// This function implements a DI call to retrieve adapter driver configuration information.
/// \platform
/// \ALL
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[out] adapterDriverConfig The pointer to the structure storing the retrieved adapter driver configuration information.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
int HIDDEN Pack_DI_AdapterDriverConfiguration_Get(int iAdapterIndex,  DI_ADAPTERDRIVERCONFIG *adapterDriverConfig);

///
/// \brief Function to set the adapter driver configuration.
///
/// This function implements a DI call to set adapter driver configuration information.
/// \platform
/// \ALL
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[in] diAdapterDriverConfig The desired adapter driver configuration information.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
int HIDDEN Pack_DI_AdapterDriverConfiguration_Set(int iAdapterIndex,  const DI_ADAPTERDRIVERCONFIG &diAdapterDriverConfig);

///
/// \brief Function to retrieve DDC information.
///
/// This function implements a DI call to retrieve DDC infromation.
/// \platform
/// \ALL
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[in]  iDisplayIndex The desired display index.
/// \param[out] displayDDCInfo The pointer to the buffer storing the retrieved display information.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
int HIDDEN Pack_DI_DisplayDDCInfo_Get(int iAdapterIndex,  int iDisplayIndex,DISPLAYDDCINFO *displayDDCInfo);

///
/// \brief A function to retrieve UNDERSCANDESC information
///
/// This function implements a DI call to retrieve UNDERSCANDESC information.
/// \platform
/// \ALL
/// \param[in]  iADLHandle The desired ADL handle.
/// \param[in]  iDisplayIndex The desired display index.
/// \param[out] underScanDesc The pointer to the buffer storing the retrieved underscan description information.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
int HIDDEN Pack_DI_DisplayGetUnderscanMode(int iADLHandle, int iDisplayIndex, UNDERSCANDESC* underScanDesc);

///
/// \brief Function to set UNDERSCANDESC information
///
/// This function implements a DI call to set UNDERSCANDESC information.
/// \platform
/// \ALL
/// \param[in]  iADLHandle is an ADL handle.
/// \param[in]  iDisplayIndex The desired display index.
/// \param[in] underScanDesc The pointer to the buffer storing the retrieved underscan description information data.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
int HIDDEN Pack_DI_DisplaySetUnderscanMode(int iADLHandle, int iDisplayIndex, UNDERSCANDESC underScanDesc);

///
/// \brief Function to retrieve UNDERSCANINFO information
///
/// This function implements a DI call to retrieve UNDERSCANINFO information.
/// \platform
/// \ALL
/// \param[in]  iADLHandle The desired ADL handle.
/// \param[in]  iDisplayIndex The desired display index.
/// \param[in] underScanInfo The pointer to the buffer storing the retrieved underscan description information data.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
int HIDDEN Pack_DI_DisplayGetUnderscanInfo(int iADLHandle, int iDisplayIndex, UNDERSCANINFO* underScanInfo);


///
/// \brief Function to retrieve DDC information Ex.
///
/// This function implements a DI call to retrieve DDC infromation Ex.
/// \platform
/// \ALL
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[in]  iDisplayIndex The desired display index.
/// \param[out] displayDDCInfoEx The pointer to the buffer storing the retrieved display information Ex data.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
int HIDDEN Pack_DI_DisplayDDCInfo_Get_Ex(int iAdapterIndex,  int iDisplayIndex,DISPLAYDDCINFOEX *displayDDCInfoEx);


///
/// \brief Function to retrieve DDC information Ex2.
///
/// This function implements a DI call to retrieve DDC infromation Ex.
/// \platform
/// \ALL
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[in]  iDisplayIndex The desired display index.
/// \param[out] displayDDCInfoEx The pointer to the buffer storing the retrieved display information Ex data.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
int HIDDEN Pack_DI_DisplayDDCInfo_Get_Ex2(int iAdapterIndex,  int iDisplayIndex,DISPLAYDDCINFOEX2 *displayDDCInfoEx);

///
/// \brief Function to retrieve display device configuration.
///
/// This function implements a DI call to retrieve display device configuration.
/// \platform
/// \ALL
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[in]  iDisplayIndex The desired display index.
/// \param[out] displayGetDeviceConfig The pointer to the buffer storing the retrieved display device configuration data buffer.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
int HIDDEN Pack_DI_DisplayDeviceConfig_Get(int iAdapterIndex,  int iDisplayIndex, DISPLAYGETDEVICECONFIG* displayGetDeviceConfig);

///
/// \brief Function to retrieve display adjustment information.
///
/// This function implements a DI call to retrieve display adjustment infomation.
/// \platform
/// \ALL
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[in]  displayIndex The desired display index.
/// \param[in] di_DisplayAdjustmentInput The desired display adjustment input data.
/// \param[out] di_DisplayAdjustmentInfoEx The pointer to the structure storing the retrieved display adjustment information.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
int HIDDEN Pack_DI_DisplayGetAdjustmentInfoEx(int iAdapterIndex, int displayIndex, DI_DISPLAYADJUSTMENTINPUT di_DisplayAdjustmentInput, DI_DISPLAYADJUSTMENTINFOEX* di_DisplayAdjustmentInfoEx);

///
/// \brief A function to set display adjustment.
///
/// This function implements a DI call to set display adjustment.
/// \platform
/// \ALL
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[in]  displayIndex The desired display index.
/// \param[in] di_displayAdjustmentInput The desired display adjustment input data.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
int HIDDEN Pack_DI_DisplaySetAdjustmentData(int iAdapterIndex, int displayIndex, DISPLAYADJUSTMENTINPUT di_displayAdjustmentInput);

///
/// \brief Function to retrieve the display DP Link setting.
///
/// This function implements a TH call to retrieve the display dp Link settings.
/// \platform
/// \ALL
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[in]  displayIndex The desired display index.
/// \param[out] dt_DPLinkInfo The pointer to a CWDDETH_LINKINFO structure
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code.
int HIDDEN Pack_TH_DisplayLinkInfo(int iAdapterIndex, int displayIndex, CWDDETH_LINKINFO* dt_DPLinkInfo);


///
/// \brief Function to retrieve the display adjustment setting.
///
/// This function implements a DI call to retrieve the display adjustment value.
/// \platform
/// \ALL
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[in]  displayIndex The desired display index.
/// \param[in] di_displayAdjustmentInput The desired display adjustment input data.
/// \param[out] lpCurrent The pointer to the current value of the adjustment type.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
int HIDDEN Pack_DI_DisplayGetAdjustmentData(int iAdapterIndex, int displayIndex, DISPLAYADJUSTMENTINPUT di_displayAdjustmentInput, int *lpCurrent);


///
/// \brief Function to retrieve display configuration.
///
/// This function implements a DI call to retrieve display configuration.
/// \platform
/// \ALL
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[in]  displayIndex The desired display index.
/// \param[out] displayConfig The pointer to the retrieved display configuration information.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
int HIDDEN Pack_DI_DisplayGetConfig(int iAdapterIndex, int displayIndex, DISPLAYCONFIG* displayConfig);

///
/// \brief Function to set display device configuration.
///
/// This function implements a DI call to set display configuration.
/// \platform
/// \ALL
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[in]  displayIndex The desired display index.
/// \param[in] displayConfig The desired display configuration.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
int HIDDEN Pack_DI_DisplaySetConfig(int iAdapterIndex, int displayIndex, DISPLAYCONFIG displayConfig);

///
/// \brief Function to set the gamma 16 information.
///
/// This function implements a DI call to set gamma 16 information for a controller.
/// \platform
/// \ALL
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[in]  iControllerIndex The desired controller index.
/// \param[in] controllerGamma16 The desired gamma structure.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
int HIDDEN Pack_DI_ControllerSetGamma16(int iAdapterIndex, int iControllerIndex,const CONTROLLERGAMMA16 &controllerGamma16);

///
/// \brief Function to retrieve gamma 16 information.
///
/// This function implements a DI call to retrieve gamma 16 information for a controller.
/// \platform
/// \ALL
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[in]  iControllerIndex The desired controller index.
/// \param[out] lpControllerGamma16 The pointer to the structure storing the retrieved gamma information.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
int HIDDEN Pack_DI_ControllerGetGamma16(int iAdapterIndex, int iControllerIndex, CONTROLLERGAMMA16 *lpControllerGamma16);

///
/// \brief Function to retrieve display regamma information
///
/// This function implements a DI call to get the current regamma for the given display.
/// \platform
/// \ALL
/// \param[in ]  iAdapterIndex The index of the desired adapter.
/// \param[in ]  iDisplayIndex The index of the desired display.
/// \param[out]  lpRegammaEx The gamma curve; where the curve either came directly from the display or built by coefficients.
/// \return If the function succeeds, the return value is ADL_OK (zero). Otherwise the return value is an ADL error code (non-zero). \ref define_adl_results
int HIDDEN Pack_DI_Display_RegammaR1_Get(int iAdapterIndex, int iDisplayIndex, ADLRegammaEx *lpRegammaEx);

///
/// \brief
///
/// This function implements a DI call to set regamma for the given display.
/// \platform
/// \ALL
/// \param[in ]  iAdapterIndex The index of the desired adapter.
/// \param[in ]  iDisplayIndex The index of the desired display.
/// \param[in ]  lpRegammaEx The gamma curve; where the curve is either, direct from display information or will be built by coefficients.
/// \return If the function succeeds, the return value is ADL_OK (zero). Otherwise the return value is an ADL error code (non-zero). \ref define_adl_results
int HIDDEN Pack_DI_Display_RegammaR1_Set (int iAdapterIndex, int iDisplayIndex, const ADLRegammaEx *lpRegammaEx);


///
/// \brief
///
/// This function implements a DI call to set source content info for HDR on the given display.
/// \platform
/// \ALL
/// \param[in ]  iAdapterIndex The index of the desired adapter.
/// \param[in ]  iDisplayIndex The index of the desired display.
/// \param[in ]  lpHdrContentInfo The source content information from the user side
/// \return If the function succeeds, the return value is ADL_OK (zero). Otherwise the return value is an ADL error code (non-zero). \ref define_adl_results
int HIDDEN Pack_DI_Display_SourceContent_Set(int iAdapterIndex, int iDisplayIndex, const ADLHDRContentInfo *lpHdrContentInfo);


///
/// \brief
///
/// This function implements a DI call to get source content info for HDR on the given display.
/// \platform
/// \ALL
/// \param[in ]  iAdapterIndex The index of the desired adapter.
/// \param[in ]  iDisplayIndex The index of the desired display.
/// \param[in ]  lpHdrContentInfo The source content information
/// \return If the function succeeds, the return value is ADL_OK (zero). Otherwise the return value is an ADL error code (non-zero). \ref define_adl_results
int HIDDEN Pack_DI_Display_SourceContent_Get(int iAdapterIndex, int iDisplayIndex, ADLHDRContentInfo *lpHdrContentInfo);

/// \brief Function to retrieve display device configuration.
///
/// This function implements a DI call to retrieve DISPLAY DEVICE CONFIG.
/// \platform
/// \ALL
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[in]  iDisplayIndex The desired display index.
/// \param[out] lpDisplayGetDeviceConfig The pointer to the structure storing the retrieved configuration.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
int HIDDEN Pack_DI_DisplayGetDeviceConfig(int iAdapterIndex, int iDisplayIndex, DISPLAYGETDEVICECONFIG *lpDisplayGetDeviceConfig);

///
/// \brief Function to set display device configuration.
///
/// This function implements a DI call to set DISPLAY DEVICE CONFIG.
/// \platform
/// \ALL
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[in]	iDisplayIndex The desired display index.
/// \param[in]  di_DisplaySetDeviceConfig The desired display device configuration.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
int HIDDEN Pack_DI_DisplaySetDeviceConfig(int iAdapterIndex, int iDisplayIndex, DISPLAYSETDEVICECONFIG di_DisplaySetDeviceConfig);

///
/// \brief Function to create or obtain a virtual display 
/// 
/// This function implements a DI call to set LHESCAPE_UMDKMDIF_ACQUIRE_VIRTUAL_DISPLAY. 
/// \platform
/// \ALL
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[in]  pInCallerBuffer     The desired input buffer.
/// \param[out] pOutCallerBuffer    The pointer to the output buffer.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
int HIDDEN Pack_DI_Display_Virtual_Acquire (int iAdapterIndex, UMDKMDIF_ACQUIRE_VIRTUAL_DISPLAY_INPUT* pInCallerBuffer, UMDKMDIF_ACQUIRE_VIRTUAL_DISPLAY_OUTPUT* pOutCallerBuffer);

///
/// \brief Function to destroy a virtual display 
/// 
/// This function implements a DI call to set LHESCAPE_UMDKMDIF_ACQUIRE_VIRTUAL_DISPLAY. 
/// \platform
/// \ALL
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[in]  pInCallerBuffer     The desired input buffer.
/// \param[out] pOutCallerBuffer    The pointer to the output buffer.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
int HIDDEN Pack_DI_Display_Virtual_Release (int iAdapterIndex, UMDKMDIF_RELEASE_VIRTUAL_DISPLAY_INPUT* pInCallerBuffer, UMDKMDIF_RELEASE_VIRTUAL_DISPLAY_OUTPUT* pLOutCallerBuffer);


///
/// \brief Function to retrieve driver returned aspects.
///
/// This function implements a CI call to retrieve the driver aspect list.
/// \platform
/// \ALL
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[out] lpAspects The pointer to the buffer storing the retrieved aspect list.
/// \param[in]  iSize The size of the lpAspects buffer.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
int HIDDEN Pack_CI_Adapter_Aspects_Get( int iAdapterIndex, char* lpAspects, int iSize );

///
/// \brief Function to restore all the ACE's INF registry defaults.
///
/// This function implements a CI call to restore the ACE INF registry defaults.
/// \platform
/// \ALL
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
int HIDDEN Pack_CI_Adapter_AceDefaults_Restore (int iAdapterIndex);


///
/// \brief Function to retrieve the driver registery key value.
///
/// This function implements a CI call to retrieve the driver regsitry key value.
/// \platform
/// \ALL
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[in]  iDriverPathOption The desired driver registry key path option.  0: Current ; 1: function1; 2: function2.
/// \param[in]  lpSubKey The pointer to the buffer storing the address of the sub key name under the driver path (applicable to Vista and above). The address can be null.
/// \param[in]  lpRegistryKey The pointer to the buffer storing the address of the registry key name.
/// \param[out]  lpRegistryValue The pointer to the address of the regsitry key value.
///
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
int HIDDEN Pack_CI_RegistryDWordValue_Get(int iAdapterIndex, int iDriverPathOption, char* lpSubKey, char* lpRegistryKey, int* lpRegistryValue);


///
/// \brief Function to retrieve the customized mode.
///
/// This function implements a DI call to retrieve the customized mode.
/// \platform
/// \ALL
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[in]  iDisplayIndex The desired display index.
/// \param[in]  iModeIndex The customized mode index.
/// \param[out] di_DisplayCustomizedMode The pointer to the retrieved customized mode.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
int HIDDEN Pack_DI_DisplayGetCustomizedMode(int iAdapterIndex, int iDisplayIndex, int iModeIndex, DISPLAYCUSTOMIZEDMODE *di_DisplayCustomizedMode);

///
/// \brief Function to add a customized mode.
///
/// This function implements a DI call to add a customized mode.
/// \platform
/// \ALL
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[in]  iDisplayIndex The desired display index.
/// \param[in]  diDisplayCustomizedMode The customized mode to be added.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
int HIDDEN Pack_DI_DisplayAddCustomizedMode(int iAdapterIndex, int iDisplayIndex, DISPLAYCUSTOMIZEDMODE diDisplayCustomizedMode);

///
/// \brief A function to delete a customized mode.
///
/// This function implements a DI call to delete a customized mode.
/// \platform
/// \ALL
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[in]  iDisplayIndex The desired display index.
/// \param[in]  iIndex The customized mode index to be deleted.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
int HIDDEN Pack_DI_DisplayDeleteCustomizedMode(int iAdapterIndex, int iDisplayIndex, int iDeletableIndex);

///
/// \brief A function to validate a customized mode.
///
/// This function implements a DI call to validate a customized mode.
/// \platform
/// \ALL
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[in]  iDisplayIndex The desired display index.
/// \param[in]  diDisplayCustomizedMode The customized mode index to be validated.
/// \param[out] lpValid The pointer to the value indicating whether the mode is valid.
int HIDDEN Pack_DI_DisplayValidateCustomizedMode(int iAdapterIndex, int iDisplayIndex, DISPLAYCUSTOMIZEDMODE diDisplayCustomizedMode, int *lpValid);

///
/// \brief A function to Get the limits of the display
///
/// This function implements a DI call to get the display limits
/// \platform
/// \ALL
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[in]  iDisplayIndex The desired display index.
/// \param[out] displayLimits The pointer to the structure storing the retrieved limits.
int HIDDEN Pack_DI_DisplayGetLimits(int iAdapterIndex, int iDisplayIndex, DISPLAYLIMITS *displayLimits);

///
/// \brief Function to Get the device profile
///
/// Purpose: Calls CWDDEDI_AdapterGetDeviceProfileEx
///
/// \param[in] iAdapterIndex      The ADL index handle of the desired adapter.
/// \param[out]      pstDeviceProfile  The pointer to the device profile to be returned.
/// \param[out]       pstProfileConfig   The pointer to the profile structure to be used.
///
/// \return: iRet (could be either ADL_ERR_NULL_POINTER or ADL_OK).
int HIDDEN Pack_DI_Adapter_DeviceProfileEx_Get(int iAdapterIndex, DI_DEVICEPROFILECONFIG_EX *pstProfileConfig,
                                               DI_DEVICE_PROFILE_EX *pstDeviceProfile);

///
/// \brief Function to get the system info
///
/// Purpose: Calls CWDDEDI_AdapterQuerySystemInfo
///
/// \param[in]       iAdapterIndex      The ADL index handle of the desired adapter.
/// \param[in]       pSysInfoInput      The pointer to the input structure storing the selected type.
/// \param[out]      pOutput            The pointer to the output buffer storing the retrieved adapter information function. The size of the buffer depends on the type selected in the input structure.
/// \param[out]      iSize              The size of the output buffer.
///
/// \return: iRet (could be either ADL_ERR_NULL_POINTER or ADL_OK).
int HIDDEN Pack_DI_Adapter_QuerySystemInfo_Get(int iAdapterIndex, DI_ADAPTERQUERYSYSTEMINFO_INPUT *pSysInfoInput,
                                               char *pOutput, int iSize);


///
/// \brief Function to get the timing override values
///
/// Purpose: Calls CWDDEDI_DisplayGetSetModeTimingOverride
///
/// \param[in]       iAdapterIndex      The ADL index handle of the desired adapter.
/// \param[in]       iDisplayIndex      The desired display index.
/// \param[in]       pDisplayModeTiming - the input display mode timing struct
/// \param[out]      pDisplayModeList   - the output diplay mode list struct
/// \param[out]      iSizeModeList      - the size of output diplay mode list struct
///
/// \return: iRet (could be either ADL_ERR_NULL_POINTER or ADL_OK).
int HIDDEN Pack_DI_Display_ModeTimingOverride_GetSet(int iAdapterIndex, int iDisplayIndex,
                                                     DI_DISPLAYMODETIMING *pDisplayModeTiming,
                                                     DI_DISPLAYMODELIST *pDisplayModeList, int iSizeModeList);
///
/// \brief Function to get the timing override values
///
/// Purpose: Calls CWDDEDI_DisplayGetCurrentTiming
///
/// \param[in]       iAdapterIndex      The ADL index handle of the desired adapter.
/// \param[in]       iDisplayIndex      The desired display index.
/// \param[out]      di_ModeInfo		The mode info struct
///
/// \return: iRet (could be either ADL_ERR_NULL_POINTER or ADL_OK).
int HIDDEN Pack_DI_Display_TargetTiming_Get(int iAdapterIndex, int iDisplayIndex, DI_MODEINFO *di_ModeInfo);

///
/// \brief Function to access the I2C bus
///
/// Purpose: Calls CWDDEDI_AdapterI2cBlockAccess
///
/// \param[in]       iAdapterIndex      The ADL index handle of the desired adapter.
/// \param[in]       pI2CInput          The pointer to the input I2C information structure.
/// \param[out]      pI2COutput        The pointer to the output I2C information structure.
///
/// \return: iRet (could be either ADL_ERR_NULL_POINTER or ADL_OK).
int HIDDEN Pack_DI_Adapter_I2cBlockAccess(int iAdapterIndex,
                                          DI_ADAPTERI2CBLOCKACCESSINPUTDATA *pI2CInput,
                                          DI_ADAPTERI2CBLOCKACCESSOUTPUTDATA *pI2COutput);

///
/// \brief Function to call
///
/// Purpose: Calls CWDDEDI_RCDisplayAdjustment
///
/// \param[in]       iAdapterIndex      The ADL index handle of the desired adapter.
/// \param[in]       iDisplayIndex      The desired display index.
/// \param[in]       pInfo              The pointer to the input information structure.
///
/// \return: iRet (could be either ADL_ERR_NULL_POINTER or ADL_OK).
int HIDDEN Pack_DI_Display_RcDisplayAdjustment(int iAdapterIndex,
                                               int iDisplayIndex,
                                               ADLRcCommand* pInfo);

///
/// \brief Function to get the refresh rate caps
///
/// Purpose: Calls CWDDEDI_DisplayGetRefreshRateCaps
///
/// \param[in]       iAdapterIndex      The ADL index handle of the desired adapter.
/// \param[in]       iDisplayIndex      The desired display index.
/// \param[out]      pRefreshRateCaps   The pointer to the structure storing the retrieved display refresh rate capability.
///
/// \return: iRet (could be either ADL_ERR_NULL_POINTER or ADL_OK).
int HIDDEN Pack_DI_Display_RefreshRateCaps_Get(int iAdapterIndex, int iDisplayIndex,
                                               DISPLAYREFRESHRATECAPS *pRefreshRateCaps);

///
/// \brief Function to get the refresh rate values
///
/// Purpose: Calls CWDDEDI_DisplayGetRefreshRate
///
/// \param[in]       iAdapterIndex      The ADL index handle of the desired adapter.
/// \param[in]       iDisplayIndex      The desired display index.
/// \param[out]      pRefreshRate       The pointer to the structure storing the retrieved display refresh rate.
///
/// \return: iRet (could be either ADL_ERR_NULL_POINTER or ADL_OK).
int HIDDEN Pack_DI_Display_RefreshRate_Get(int iAdapterIndex, int iDisplayIndex,
                                           DISPLAYREFRESHRATE *pRefreshRate);

///
/// \brief Function to set the refresh rate
///
/// Purpose: Calls CWDDEDI_DisplaySetRefreshRate
///
/// \param[in]       iAdapterIndex      The ADL index handle of the desired adapter.
/// \param[in]       iDisplayIndex      The desired display index.
/// \param[in]       pRefreshRate       The pointer to the structure storing the desired display refresh rate.
///
/// \return: iRet (could be either ADL_ERR_NULL_POINTER or ADL_OK).
int HIDDEN Pack_DI_Display_RefreshRate_Set(int iAdapterIndex, int iDisplayIndex,
                                           DISPLAYREFRESHRATE *pRefreshRate);

///
/// \brief Function to get the refresh rate options
///
/// Purpose: Calls CWDDEDI_DisplayGetRefreshRateOptions
///
/// \param[in]       iAdapterIndex      The ADL index handle of the desired adapter.
/// \param[in]       iDisplayIndex      The desired display index.
/// \param[in]       pRefreshRate       The pointer to the structure storing the retrieved display refresh rate options.
///
/// \return: iRet (could be either ADL_ERR_NULL_POINTER or ADL_OK).
int HIDDEN Pack_DI_Display_RefreshRateOptions_Get(int iAdapterIndex, int iDisplayIndex,
                                                  DISPLAYREFRESHRATE *pRefreshRate);

///
/// \brief Function to set the refresh rate options
///
/// Purpose: Calls CWDDEDI_DisplaySetRefreshRateOptions
///
/// \param[in]       iAdapterIndex      The ADL index handle of the desired adapter.
/// \param[in]       iDisplayIndex      The desired display index.
/// \param[in]       pRefreshRate       The pointer to the structure storing the desired display refresh rate options.
///
/// \return: iRet (could be either ADL_ERR_NULL_POINTER or ADL_OK)
int HIDDEN Pack_DI_Display_RefreshRateOptions_Set(int iAdapterIndex, int iDisplayIndex,
                                                  DISPLAYREFRESHRATE *pRefreshRate);

///
/// \brief Function to get EDID data
///
/// Purpose: Calls CWDDEDI_DisplayGetEDIDData
///
/// \param[in]       iAdapterIndex      The ADL index handle of the desired adapter.
/// \param[in]       iDisplayIndex      The desired display index.
/// \param[in]       pinputEDIDData     The pointer to the structure storing the EDID data.
/// \param[out]      poutputEDIDData    The pointer to the structure storing the retrieved EDID data.
///
/// \return: iRet (could be either ADL_ERR_NULL_POINTER or ADL_OK).
int HIDDEN Pack_DI_Display_EDIDData_Get(int iAdapterIndex, int iDisplayIndex,
                                        DISPLAYEDIDDATAINPUT *pinputEDIDData, DISPLAYEDIDDATA *poutputEDIDData);

///
/// \brief Function to override EDID data
///
/// Purpose: Calls CWDDEDI_DisplayOverrideEDID
///
/// \param[in]       iAdapterIndex      The ADL index handle of the desired adapter.
/// \param[in]       iDisplayIndex      The desired display index.
/// \param[in]       pinputEDIDData     The pointer to the structure storing the EDID data.
///
/// \return: iRet (could be either ADL_ERR_NULL_POINTER or ADL_OK).
int HIDDEN Pack_DI_Display_EDIDData_Set(int iAdapterIndex, int iDisplayIndex,
                                        DISPLAYOVERRIDEEDID *pinputEDIDData);

///
/// \brief Function to get the Overlay adjustment info data
///
/// Purpose: Calls CWDDEDI_ControllerGetOverlayAdjustmentInfo
///
/// \param[in]       iAdapterIndex      The ADL index handle of the desired adapter.
/// \param[in]       pinputData         The pointer to the structure storing the overlay adjustment information.
/// \param[out]      poutputInfo        The pointer to the structure storing the retrieved overlay adjustment information.
///
/// \return: iRet (could be either ADL_ERR_NULL_POINTER or ADL_OK).
int HIDDEN Pack_DI_Display_ControllerOverlayAdjustmentInfo_Get(int iAdapterIndex,
                                                               CONTROLLEROVERLAYINPUT *pinputData, CONTROLLEROVERLAYINFO *poutputInfo);

///
/// \brief Function to get the info packet settings
///
/// Purpose: Calls CWDDEDI_DisplayGetInfoPacketSettings
///
/// \param[in]       iAdapterIndex      The ADL index handle of the desired adapter.
/// \param[in]       iDisplayIndex      The desired display index.
/// \param[in]       pinputInfo         The pointer to the structure storing the packet data.
/// \param[out]      poutputData        The pointer to the structure storing the retrieved packet data.
///
/// \return: iRet (could be either ADL_ERR_NULL_POINTER or ADL_OK).
int HIDDEN Pack_DI_Display_InfoPacketSettings_Get(int iAdapterIndex, int iDisplayIndex,
                                                  DI_GET_INFO_PACKET *pinputInfo, DI_DISPLAY_DATA_PACKET *poutputData);

///
/// \brief Function to set the info packet settings
///
/// Purpose: Calls CWDDEDI_DisplaySendInfoPackets
///
/// \param[in]       iAdapterIndex      The ADL index handle of the desired adapter.
/// \param[in]       iDisplayIndex      The desired display index.
/// \param[in]       pinputData         The pointer to the structure storing the packet data.
///
/// \return: iRet (could be either ADL_ERR_NULL_POINTER or ADL_OK).
int HIDDEN Pack_DI_Display_InfoPackets_Set(int iAdapterIndex, int iDisplayIndex, DI_DISPLAY_DATA_PACKET *pinputData);

///
/// \brief Function to get the overlay adjustment data of the controller
///
/// Purpose: Calls CWDDEDI_ControllerGetOverlayAdjustmentData
///
/// \param[in]       iAdapterIndex      The ADL index handle of the desired adapter.
/// \param[in]       pinputData         The pointer to the structure storing the overlay adjustment information.
/// \param[out]      pulOverlayData     The pointer to the structure storing the retrieved overlay adjustment information.
///
/// \return: iRet (could be either ADL_ERR_NULL_POINTER or ADL_OK).
int HIDDEN Pack_DI_Display_ControllerOverlayAdjustmentData_Get(int iAdapterIndex,
                                                               CONTROLLEROVERLAYINPUT *pinputData, ULONG *pulOverlayData);

///
/// \brief Function to set the overlay adjustment data of the controller
///
/// Purpose: Calls CWDDEDI_ControllerSetOverlayAdjustmentData
///
/// \param[in]       iAdapterIndex      The ADL index handle of the desired adapter.
/// \param[in]       pinputData         The pointer to the structure storing the overlay adjustment.
///
/// \return: iRet (could be either ADL_ERR_NULL_POINTER or ADL_OK).
int HIDDEN Pack_DI_Display_ControllerOverlayAdjustmentData_Set(int iAdapterIndex,
                                                               CONTROLLEROVERLAYINPUT *pinputData);

///
/// \brief Function to flush the adapter's saved data
///
/// Purpose: Calls CWDDEDI_AdapterFlushSaveData
///
/// \param[in]        iAdapterIndex The ADL index handle of the desired adapter.
/// \param[out]       lpSaveData    The pointer to the structure that is to be returned.
///
/// \return: iRet (could be either ADL_ERR_NULL_POINTER or ADL_OK).
int HIDDEN Pack_DI_AdapterFlushSaveData(int iAdapterIndex, SAVEDATA *lpSaveData);

///
/// \brief Function to get the adapter's possible modes
///
/// Purpose: Calls CWDDEDI_AdapterGetNumOfPossibleModes2
///
/// \param[in]  iAdapterIndex      The ADL index handle of the desired adapter.
/// \param[in]	di_PossibleModeRequest_Info2 DI_POSSIBLEMODEREQUEST_INFO2.
/// \param[out] lpOutputLong The pointer to the OUTPUTULONG structure that is to be returned.
///
/// \return: iRet (could be either ADL_ERR_NULL_POINTER or ADL_OK).
int HIDDEN Pack_DI_AdapterNumOfPossibleModes2_Get(int iAdapterIndex, DI_POSSIBLEMODEREQUEST_INFO2 di_PossibleModeRequest_Info2, OUTPUTULONG *lpOutputLong);

///
/// \brief Function to get the number of adapter's possible modes
///
/// Purpose: Calls CWDDEDI_AdapterGetPossibleModes2
///
/// \param[in]  iAdapterIndex      The ADL index handle of the desired adapter.
/// \param[in]	di_PossibleModeRequest_Info2 DI_POSSIBLEMODEREQUEST_INFO2
/// \param[out] lpDi_PossibleModes The pointer to the DI_POSSIBLEMODES_TMP structure that is to be returned.
///
/// \return: iRet (could be either ADL_ERR_NULL_POINTER or ADL_OK).
int HIDDEN Pack_DI_AdapterPossibleModes2_Get(int iAdapterIndex, DI_POSSIBLEMODEREQUEST_INFO2 di_PossibleModeRequest_Info2, DI_POSSIBLEMODES_TMP *lpDi_PossibleModes);

int HIDDEN Pack_DI_AdapterPossibleModes_Get(int iAdapterIndex, DI_POSSIBLEMODEREQUEST_INFO di_PossibleModeRequest_Info, DI_POSSIBLEMODES_TMP *lpDi_PossibleModes);


///
/// \brief Function that retrieves the driver capabilities.
///
/// This function implements the CI calls to retrieve the workstation driver capabilities.
///
/// \platform
/// \ALL
///
/// \param[in] iAdapterIndex      The ADL index handle of the desired adapter.
/// \param[out] lpCaps   The pointer to the bit-or'd value indicating the capabilities of the workstation card.
///
/// \return If the capabilities were retrieved correctly, ADL_OK is returned. If lpCaps is NULL, ADL_ERR_NULL_POINTER is returned. Otherwise, ADL_ERR is returned.
int HIDDEN Pack_CI_Driver_Caps_Get(int iAdapterIndex, int *lpCaps);

///
/// \brief Function that retrieves a driver registry value.
///
/// This function implements the CI calls to retrieve a driver registry value.
///
/// \platform
/// \WIN
///
/// \param[in] iAdapterIndex      The ADL index handle of the desired adapter.
/// \param[in] szKey The pointer to the driver registry key name for which to retrieve the registry value.
/// \param[in] ulType	The registry type of the key.
/// \param[in] usDevice  The Device Function ID which owns the registry key.
/// \param[in] ulDataSize The size (in bytes) of the pData buffer.
/// \param[out] pData The pointer to the buffer storing the retrieved registry value.
///
/// \return ADL_OK if the capabilities were fetched correctly,  ADL_ERR_NULL_POINTER if lpCaps is NULL, else ADL_ERR.
int HIDDEN Pack_CI_RegValue_Get(int iAdapterIndex, void *szKey, ULONG ulType, USHORT usDevice, ULONG ulDataSize, void *pData);

///
/// \brief Function that retrieves a driver registry value.
///
/// This function implements the CI calls to retrieve a driver registry value by specifying the subkey and keyname.
///
/// \platform
/// \WIN
///
/// \param[in] iAdapterIndex      The ADL index handle of the desired adapter.
/// \param[in] szSubKey		The pointer to the driver registry subkey path.
/// \param[in] szKeyName	The pointer to the driver registry key name for which to retrieve the registry value.
/// \param[in] ulType		The registry type of the key.
/// \param[in] usDevice		The Device Function ID which owns the registry key.
/// \param[in] ulDataSize	The size (in bytes) of the pData buffer.
/// \param[out] pData		The pointer to the buffer storing the retrieved registry value.
///
/// \return ADL_OK if the capabilities were fetched correctly,  ADL_ERR_NULL_POINTER if lpCaps is NULL, else ADL_ERR.
int HIDDEN Pack_CI_RegValueEx_Get(int iAdapterIndex, void *szSubKey, void *szKeyName, ULONG ulType, USHORT usDevice, ULONG ulDataSize, void *pData);

///
/// \brief Function that sets a driver registry value.
///
/// This function implements the CI calls to set a driver registry value.
///
/// \platform
/// \WIN
///
/// \param[in] iAdapterIndex      The ADL index handle of the desired adapter.
/// \param[in] szKey	The driver registry key name for which to set the registry value.
/// \param[in] ulType	The registry type of the key.
/// \param[in] usDevice The Device Function ID which owns the registry key.
/// \param[in] ulDataSize The size (in bytes) of the pData buffer.
/// \param[in] pData The pointer to the buffer storing the new registry value.
///
/// \return ADL_OK if the capabilities were fetched correctly,  ADL_ERR_NULL_POINTER if lpCaps is NULL, else ADL_ERR.
int HIDDEN Pack_CI_RegValue_Set(int iAdapterIndex, void *szKey, ULONG ulType, USHORT usDevice, ULONG ulDataSize, void *pData);

///
/// \brief Function that sets a driver registry value.
///
/// This function implements the CI calls to set a driver registry value by specifying the subkey and keyname.
///
/// \platform
/// \WIN
///
/// \param[in] iAdapterIndex      The ADL index handle of the desired adapter.
/// \param[in] szSubKey		The pointer to the driver registry subkey path.
/// \param[in] szKeyName	The pointer to the driver registry key name for which to retrieve the registry value.
/// \param[in] ulType		The registry type of the key.
/// \param[in] usDevice		The Device Function ID which owns the registry key.
/// \param[in] ulDataSize	The size (in bytes) of the pData buffer.
/// \param[out] pData		The pointer to the buffer storing the new registry value.
///
/// \return ADL_OK if the capabilities were fetched correctly,  ADL_ERR_NULL_POINTER if lpCaps is NULL, else ADL_ERR.
int HIDDEN Pack_CI_RegValueEx_Set(int iAdapterIndex, void *szSubKey, void *szKeyName, ULONG ulType, USHORT usDevice, ULONG ulDataSize, void *pData);

///
/// \brief Function to retrieve video theater mode info.
///
/// This function implements the CI calls to retrieve video overlay theater mode information.
///
/// \platform
/// \WIN
///
/// \param[in]	iAdapterIndex			The ADL index handle of the desired adapter.
/// \param[out] lpOverlayTheaterMode	The pointer to the overlay theater mode structure.
///
/// \return ADL_OK if the capabilities were fetched correctly,  ADL_ERR_NULL_POINTER if lpCaps is NULL, else ADL_ERR.
int HIDDEN Pack_CI_VideoTheaterModeInfo_Get(int iAdapterIndex, CIOVLTHEATERMODE* lpOverlayTheaterMode);

///
/// \brief Function to set video theater mode info.
///
/// This function implements the CI calls to set video overlay theater mode information.
///
/// \platform
/// \WIN
///
/// \param[in]	iAdapterIndex			The ADL index handle of the desired adapter.
/// \param[in]	lpOverlayTheaterMode	The pointer to the overlay theater mode structure.
///
/// \return ADL_OK if the capabilities were fetched correctly,  ADL_ERR_NULL_POINTER if lpCaps is NULL, else ADL_ERR.
int HIDDEN Pack_CI_VideoTheaterModeInfo_Set(int iAdapterIndex, CIOVLTHEATERMODE* lpOverlayTheaterMode);


///
/// \brief Function to retrieve VBIOS information.
///
/// This function implements the CI calls to retrieve video BIOS information.
///
/// \platform
/// \ALL
///
/// \param[in] iAdapterIndex      The ADL index handle of the desired adapter.
/// \param[out] lpVideoBiosInfo  The pointer to the buffer storing the retrieved VBIOS information.
///
/// \return ADL_OK if the capabilities were fetched correctly,  ADL_ERR_NULL_POINTER if lpCaps is NULL, else ADL_ERR.
int HIDDEN Pack_CI_Video_Bios_Info_Query(int iAdapterIndex, CIVIDEOBIOSINFO * lpVideoBiosInfo);

///
/// \brief Function to retrieve a chipset identification value.
///
/// This function implements the CI calls to retrieve a chipset identification value.
///
/// \platform
/// \ALL
///
/// \param[in] iAdapterIndex      The ADL index handle of the desired adapter.
/// \param[out] lpChipsetID The pointer to the buffer storing the retrieved chipset information.
///
/// \return ADL_OK if the capabilities were fetched correctly,  ADL_ERR_NULL_POINTER if lpCaps is NULL, else ADL_ERR.
int HIDDEN Pack_CI_Chipset_Identification(int iAdapterIndex, CICHIPSETID * lpChipsetID);

///
/// \brief Function to retrieve ASIC ID information.
///
/// This function implements the CI calls to retrieve ASIC ID information.
///
/// \platform
/// \ALL
///
/// \param[in] iAdapterIndex    The ADL index handle of the desired adapter.
/// \param[out] lpASICID The pointer to the buffer storing the retrieved ASIC ID information.
///
/// \return ADL_OK if the capabilities were fetched correctly,  ADL_ERR_NULL_POINTER if lpCaps is NULL, else ADL_ERR.
int HIDDEN Pack_CI_Get_Asic_ID(int iAdapterIndex, CIASICID *lpASICID);

///
/// \brief Function to retrieve extended ASIC ID information.
///
/// This function implements the CI calls to retrieve extended ASIC ID information.
///
/// \platform
/// \ALL
///
/// \param[in] iAdapterIndex      The ADL index handle of the desired adapter.
/// \param[out] lpASICID_EXT The pointer to the buffer storing the retrieved ASIC ID extended information.
///
/// \return ADL_OK if the capabilities were fetched correctly,  ADL_ERR_NULL_POINTER if lpCaps is NULL, else ADL_ERR.
int HIDDEN Pack_CI_Get_Asic_ID_EXT(int iAdapterIndex, CIASICID_EXT *lpASICID_EXT);

//RAS support start
int HIDDEN Pack_CI_RAS_Features_Get(int IAdapterIndex, UMDKMDIF_RAS_GET_FEATURES_INPUT *input, UMDKMDIF_RAS_GET_FEATURES_OUTPUT *iADLRasFeaturesOutput);
int HIDDEN Pack_CI_RAS_Features_Set(int IAdapterIndex, UMDKMDIF_RAS_SET_FEATURES_INPUT *iADLRasFeaturesInput, UMDKMDIF_RAS_SET_FEATURES_OUTPUT *iADLRasFeaturesOutput);
int HIDDEN Pack_CI_RAS_Errors_Count_Get(int IAdapterIndex, UMDKMDIF_RAS_GET_ERROR_COUNTS_INPUT *input, UMDKMDIF_RAS_GET_ERROR_COUNTS_OUTPUT *output);
int HIDDEN Pack_CI_RAS_Reset_Error_Counts(int IAdapterIndex, UMDKMDIF_RAS_RESET_ERROR_COUNTS_INPUT *input, UMDKMDIF_RAS_RESET_ERROR_COUNTS_OUTPUT *output);
//RAS support end

///
/// \brief Function to retrieve Overdrive clock information.
///
/// This function implements the CI calls to retrieve Overdrive clock information.
///
/// \platform
/// \ALL
///
/// \param[in] iAdapterIndex      The ADL index handle of the desired adapter.
/// \param[in] iLevels performance levels
/// \param[out] lpPmOdGetClocksOutput The pointer to the retrieved OD clock information.
///
/// \return ADL_OK if the capabilities were fetched correctly,  ADL_ERR_NULL_POINTER if lpCaps is NULL, else ADL_ERR.
int HIDDEN Pack_PM_GetODDefaultPerformanceLevels(int iAdapterIndex, int iLevels, CWDDEPM_ODGETCLOCKSOUTPUT * lpPmOdGetClocksOutput) ;
//int HIDDEN Pack_PM_GetODDefaultPerformanceLevels(int iAdapterIndex, int iLevels, CWDDEPM_ODGETCLOCKSOUTPUT **lpPmOdGetClocksOutput) ;

/*
///
/// \brief Function to retrieve Over Driver clocks information
///
/// This function implements the CI calls to retrieve the extended ASIC ID information
///
/// \platform
/// \ALL
///
/// \param[in] iAdapterIndex      The ADL index handle of the desired adapter.
/// \param[out] lpPmOdGetClocksOutput - OD Clock information
///
/// \return ADL_OK if the capabilities were fetched correctly,  ADL_ERR_NULL_POINTER if lpCaps is NULL, else ADL_ERR.
int HIDDEN Pack_DI_AdapterGetDisplayMapping(int iAdapterIndex, int iControllerIndex, int iDeviceSelection, OUTPUTLONG *lpOutput);*/

///
/// \brief Function to retrieve possible mappings information.
///
/// This function implements the DI calls to retrieve possible mapping information.
///
/// \platform
/// \ALL
///
/// \param[in] iAdapterIndex      The ADL index handle of the desired adapter.
/// \param[in] iControllerIndex      The desired controller index.
/// \param[in] iDisplayMapped		The bit-vector of displays already mapped or requested to be mapped to another CRTC.
/// \param[out] lpDiPossibleDisplayMappings The pointer to the retrieved possible mappings information.
///
/// \return ADL_OK if the capabilities were fetched correctly,  ADL_ERR_NULL_POINTER if lpCaps is NULL, else ADL_ERR.
int HIDDEN Pack_DI_AdapterGetPossibleDisplayMappings(int iAdapterIndex, int iControllerIndex, int iDisplayMapped, DI_POSSIBLEDISPLAYMAPPINGS *lpDiPossibleDisplayMappings);

///
/// \brief Function to gets the CWDDECI version.
///
/// This function implements the CI calls to retrieve the CWDDECI version.
///
/// \platform
/// \ALL
///
/// \param[in]  iAdapterIndex      The ADL index handle of the desired adapter.
/// \param[out] pulVersion          The pointer to the buffer storing the retrieved CWDDECI version.
///
/// \return ADL_OK if the capabilities were fetched correctly,  ADL_ERR_NULL_POINTER if lpCaps is NULL, else ADL_ERR.
int HIDDEN Pack_CI_Version_Get(int iAdapterIndex, ULONG *pulVersion);

///
/// \brief Function to determines if a CWDDECI sub escape is supported.
///
/// This function implements the CI calls to determine if a CWDDECI sub escape is supported.
///
/// \platform
/// \ALL
///
/// \param[in]  iAdapterIndex      The ADL index handle of the desired adapter.
/// \param[in]  ulEscape32         The desired escape value.
/// \param[out] piSupport          The pointer to the buffer storing the retrieved support information. 1: supported; 0: not supported.
///
/// \return ADL_OK if the capabilities were fetched correctly,  ADL_ERR_NULL_POINTER if lpCaps is NULL, else ADL_ERR.
int HIDDEN Pack_CI_Supported_Get(int iAdapterIndex, ULONG ulEscape32, int *piSupport);


///
/// \brief Function to allow access to the I2C bus.
///
/// This function implements the CI calls to allow access to the I2C bus.
///
/// \platform
/// \ALL
///
/// \param[in]  iAdapterIndex      The ADL index handle of the desired adapter.
/// \param[in]  pI2CInput          The pointer to the I2C input buffer.
/// \param[out] pI2COutput         The pointer to the I2C output buffer.
///
/// \return ADL_OK if the capabilities were fetched correctly,  ADL_ERR_NULL_POINTER if lpCaps is NULL, else ADL_ERR.
int HIDDEN Pack_CI_I2CACCESS(int iAdapterIndex, CII2CACCESSINPUT * pI2CInput, CII2CACCESSOUTPUT *pI2COutput);

///
/// \brief Function for GL-Sync modules detection.
///
/// This function implements the DI calls to detect the GL-Sync modules attached to an adapter.
///
/// \platform
/// \ALL
///
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[in]  iGlSyncConnector	The desired GL-Sync index on the specified adapter.
/// \param[out] lpGlSyncModuleID	The pointer to the retrieved DI_GLSYNC_MODULE_ID structure.
///
/// \return ADL_OK if the capabilities were fetched correctly,  ADL_ERR_NULL_POINTER if lpGSyncModuleID is NULL, else ADL_ERR.
int HIDDEN Pack_DI_GLSyncModuleDetect_Get (int iAdapterIndex, int iGlSyncConnector, DI_GLSYNC_MODULE_ID* lpGlSyncModuleID);


///
/// \brief A function to retrieve GL-Sync module hardware capabilities.
///
/// This function implements the DI calls to retrieve hardware capabilities for the GL-Sync modules attached to an adapter.
///
/// \platform
/// \ALL
///
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[in]  iGlSyncConnector	The desired GL-Sync index on the specified adapter.
/// \param[out] lpGlSyncModuleCaps	The pointer to the retrieved DI_GLSYNC_MODULE_CAPS structure.
///
/// \return ADL_OK if the capabilities were fetched correctly,  ADL_ERR_NULL_POINTER if lpGlSyncModuleCaps is NULL, else ADL_ERR.
int HIDDEN Pack_DI_GLSyncModuleCaps_Get (int iAdapterIndex, int iGlSyncConnector, DI_GLSYNC_MODULE_CAPS* lpGlSyncModuleCaps);


///
/// \brief Function to retrieve GL-Sync GPU port Genlock configuration settings.
///
/// This function implements the DI call to retrieve Genlock configuration settings for the GL-Sync GPU port on the GL-Sync module attached to an adapter.
///
/// \platform
/// \ALL
///
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[in]  iGlSyncConnector	The desired GL-Sync index on the specified adapter.
/// \param[in]  iGlValidMask		The bitfield mask specifying which Genlock settings are requested.
/// \param[out] lpGlSyncGenlockConfig		The pointer to the DI_GLSYNC_GENLOCK_CONFIG structure storing the retrieved settings as per requested by iGlValidMask.
///
/// \return ADL_OK if the capabilities were fetched correctly,  ADL_ERR_NULL_POINTER if lpGlSyncGenlockConfig is NULL, else ADL_ERR.
int HIDDEN Pack_DI_GLSyncGenlockConfig_Get (int iAdapterIndex, int iGlSyncConnector, int iGlValidMask, DI_GLSYNC_GENLOCK_CONFIG* lpGlSyncGenlockConfig);


///
/// \brief Function to set GL-Sync GPU port Genlock configuration.
///
/// This function implements the DI call to set Genlock configuration data for the GL-Sync GPU port on the GL-Sync module attached to an adapter.
///
/// \platform
/// \ALL
///
/// \param[in] iAdapterIndex The ADL index handle of the desired adapter.
/// \param[in] iGlSyncConnector		The desired GL-Sync index on the specified adapter.
/// \param[in] glSyncGenlockConfig	The DI_GLSYNC_GENLOCK_CONFIG structure to be set.
///
/// \return ADL_OK if the capabilities were fetched correctly, else ADL_ERR.
int HIDDEN Pack_DI_GLSyncGenlockConfig_Set (int iAdapterIndex, int iGlSyncConnector, DI_GLSYNC_GENLOCK_CONFIG glSyncGenlockConfig);


///
/// \brief Function to retrieve GL-Sync port state.
///
/// This function implements the DI call to retrieve port state for the GL-Sync port on the GL-Sync module attached to an adapter.
///
/// \platform
/// \ALL
///
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[in]  iGlSyncConnector		The desired GL-Sync index on the specified adapter.
/// \param[in]  iGlSyncPortType			The GL_Sync port type to inquire about (CWDDEDI_GLSYNC_PORT_*).
/// \param[in]  iNumLEDs				The number of LEDs for the port. This number must be 0 if number of LEDs is unknown.
/// \param[out] lpGlSyncPortInfo	The pointer to the DI_GLSYNC_PORT_INFO structure describing the inquired port.
/// \param[out] lpglSyncLEDs			The pointer to the pointer storing the retrieved information about the LEDs associated to the GL-Sync connector. The user must deallocate the memory once done with this pointer.
///
/// \return ADL_OK if the capabilities were fetched correctly,  ADL_ERR_NULL_POINTER if lpGlSyncPortInfo is NULL, else ADL_ERR.
int HIDDEN Pack_DI_GLSyncPortState_Get (int iAdapterIndex, int iGlSyncConnector, int iGlSyncPortType, int iNumLEDs, DI_GLSYNC_PORT_INFO* lpGlSyncPortInfo, ULONG** lpglSyncLEDs);


///
/// \brief Function for performing GL-Sync port control.
///
/// This function implements the DI call to enable/disable an output signal on the RJ-45 ports of the GL-Sync module attached to an adapter.
///
/// \platform
/// \ALL
///
/// \param[in]  iAdapterIndex		The ADL index handle of the desired adapter.
/// \param[in]  iGlSyncConnector	The desired GL-Sync index on the specified adapter.
/// \param[out] glSyncPortControl	The retrieved DI_GLSYNC_PORT_CONTROL structure for the respective GL-Sync port.
///
/// \return ADL_OK if the capabilities were fetched correctly, else ADL_ERR.
int HIDDEN Pack_DI_GLSyncPortState_Set (int iAdapterIndex, int iGlSyncConnector, DI_GLSYNC_PORT_CONTROL glSyncPortControl);


///
/// \brief Function to retrieve GL-Sync mode for a display.
///
/// This function implements the DI call to retrieve the GL-Sync mode for a specific display.
///
/// \platform
/// \ALL
///
/// \param[in]  iAdapterIndex	The ADL index handle of the desired adapter.
/// \param[in]  iDisplayIndex	The desired display index.
/// \param[out] lpGlSyncMode	The pointer to the DI_GLSYNC_MODE structure describing the GL-Sync mode of the inquired display.
///
/// \return ADL_OK if the capabilities were fetched correctly,  ADL_ERR_NULL_POINTER if lpGlSyncMode is NULL, else ADL_ERR.
int HIDDEN Pack_DI_DisplayGLSyncMode_Get (int iAdapterIndex, int iDisplayIndex, DI_GLSYNC_MODE* lpGlSyncMode);

///
/// \brief Function to set the GL-Sync mode for a display.
///
/// This function implements the DI call to set the GL-Sync mode for a specific display.
///
/// \platform
/// \ALL
///
/// \param[in] iAdapterIndex	The ADL index handle of the desired adapter.
/// \param[in] iDisplayIndex The desired display index.
/// \param[in] glSyncMode		The DI_GLSYNC_MODE structure describing the GL-Sync mode for the display.
///
/// \return ADL_OK if the capabilities were fetched correctly, else ADL_ERR.
int HIDDEN Pack_DI_DisplayGLSyncMode_Set(int iAdapterIndex, int iDisplayIndex, DI_GLSYNC_MODE glSyncMode);


int HIDDEN Pack_DI_GLSyncCounters_Get(int iAdapterIndex, int iGLSyncConnector, int iWantCounters, DI_GLSYNC_COUNTERS* lpGLSyncCounters, unsigned long long** lpGLSyncExtraCounters);


///
/// \brief Function to set the GL-Sync mode for a display.
///
/// This function implements the DI call to set the GL-Sync mode for a specific display.
///
/// \platform
/// \ALL
///
/// \param[in] iAdapterIndex	The ADL index handle of the desired adapter.
/// \param[in] iInSize
/// \param[in] di_glSyncTopologyIn
/// \param[in] iOutSize
/// \param[out] di_glSyncTopologyOut
///
/// \return ADL_OK if the capabilities were fetched correctly, else ADL_ERR.
int HIDDEN Pack_DI_GLSyncSupportedTopology_Get(int iAdapterIndex, int iInSize, DI_GLSYNC_TOPOLOGY *di_glSyncTopologyIn, int iOutSize, DI_GLSYNC_TOPOLOGY *di_glSyncTopologyOut );


///
/// \brief Function to get the OverDrive Cclock info
///
/// This function implements the DI call CWDDEDI_AdapterGetODClockInfo
///
/// \platform
/// \ALL
///
/// \param[in]  iAdapterIndex	The ADL index handle of the desired adapter.
/// \param[out] lpColockInfo    The pointer to structure storing the retrieved OD clock information.
///
/// \return ADL_OK if the capabilities were fetched correctly, else ADL_ERR.
int HIDDEN Pack_DI_AdapterODClockInfo_Get(int iAdapterIndex, DI_ADAPTERCLOCK_INFO *lpColockInfo);


///
/// \brief Function to set the OverDrive Cclock info
///
/// This function implements the DI call CWDDEDI_AdapterSetODClockConfig
///
/// \platform
/// \ALL
///
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[in] lpColockConfig The pointer to the OD clock configuration structure to be set.
///
/// \return ADL_OK if the capabilities were fetched correctly, else ADL_ERR.
int HIDDEN Pack_DI_AdapterODClockConfig_Set(int iAdapterIndex, DI_ADAPTERCLOCK_CONFIG *lpColockConfig);


///
/// \brief Function to get / set  the native AUXChannel info
///
/// This function implements the DI call CWDDEDI_DisplayAccessNativeAUXChannel
///
/// \platform
/// \ALL
///
/// \param[in]  iAdapterIndex	The ADL index handle of the desired adapter.
/// \param[in]  iDisplayIndex	The desired display index.
/// \param[in]  lpinputdata		The pointer to structure storing how to get / set data.
/// \param[out] lpoutputdata		The pointer to structure storing the retrieved native AUXChannel information.
///
/// \return ADL_OK if the information were fetched correctly, else ADL_ERR.
int HIDDEN Pack_DI_DisplayAccessNativeAUXChannel(int iAdapterIndex, int iDisplayIndex,
                                                 DISPLAYACCESSNATIVEAUXCHANNELINPUTDATA *lpinputdata,
                                                 DISPLAYACCESSNATIVEAUXCHANNELOUTPUTDATA *lpoutputdata);


///
/// \brief Function to get the overlay matrix
///
/// This function implements a MM call CWDDEMM_GetOverlayMatrix.
/// \platform
/// \ALL
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[in]  iDisplayIndex The desired display index.
/// \param[in]  ulMatrixType The desired matrix type.
/// \param[out] lpMatrix The pointer to the retrieved overlay matrix.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
int HIDDEN Pack_MM_OverlayMatrix_Get(int iAdapterIndex, int iDisplayIndex, ULONG ulMatrixType, MM_COLOR_MATRIX *lpMatrix);

///
/// \brief Function to set the overlay matrix
///
/// This function implements a MM call CWDDEMM_SendOverlayMatrix.
/// \platform
/// \ALL
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[in]  iDisplayIndex The desired display index.
/// \param[in]  lpMatrix The pointer to the overlay matrix to be set.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
int HIDDEN Pack_MM_OverlayMatrix_Set(int iAdapterIndex, int iDisplayIndex, MM_COLOR_MATRIX *lpMatrix);


///
/// \brief Function to reset the overlay matrix
///
/// This function implements a MM call CWDDEMM_ResetOverlayMatrix.
/// \platform
/// \ALL
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[in]  iDisplayIndex The desired display index.
/// \param[in]  ulMatrixType The desired matrix type.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
int HIDDEN Pack_MM_OverlayMatrix_Reset(int iAdapterIndex, int iDisplayIndex, ULONG ulMatrixType);


#if defined (_WIN32) || defined(_WIN64)

/// \brief Function to get MM video adjust info
///
/// The function is used to get multi-media video adjustment information.
///
/// \platform
/// \Win
/// \param[in]  iAdapterIndex			The ADL index handle of the desired adapter.
/// \param[out] lpAdjustInfo			The pointer to the retrieved adjust info data structure.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
int HIDDEN Pack_MM_AdjustInfo_Get(int iAdapterIndex, ADJUSTINFO* lpAdjustInfo);

/// \brief Function to set MM video adjust info
///
/// The function is used to set multi-media video adjustment information.
///
/// \platform
/// \Win
/// \param[in]  iAdapterIndex			The ADL index handle of the desired adapter.
/// \param[in]	lpAdjustInfo			The pointer to the data structure of adjust info to be set.
/// \param[in]	iCount					The number of video data structure to be set.
/// \param[in]	iAppDecideVideoColor	If it is true, disable all the settings and let application make decision. Otherwise, using driver settings.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
int HIDDEN Pack_MM_AdjustInput_Set(int iAdapterIndex, ADJUSTINPUT* lpAdjustInput, int iCount, int iAppDecideVideoColor);

/// \brief Function to get MM video capabilities
///
/// The function is used to get current multi-media video capabilities.
///
/// \platform
/// \Win
/// \param[in]  iAdapterIndex			The ADL index handle of the desired adapter.
/// \param[out] lpVideoCaps				The pointer to the data structure of Video caps.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
int HIDDEN Pack_MM_VideoCaps_Get(int iAdapterIndex, VIDEO_CAPS* lpVideoCaps);

#endif

///
/// \brief Function to get the power management version
///
/// This function implements a PM call CWDDEPM_GetVersion.
/// \platform
/// \ALL
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[out] lpVersion The pointer to the structure storing the retrieved version.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
int HIDDEN Pack_PM_Version_Get(int iAdapterIndex, CWDDEPM_VERSION *lpVersion);

///
/// \brief Function to get the user state
///
/// This function implements a PM call CWDDEPM_GetUserState
/// \platform
/// \ALL
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[in]  lpInputState The pointer to the structure storing the user state.
/// \param[out] lpOutputParameters The pointer to the structure storing the retrieved user state.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
int HIDDEN Pack_PM_UserState_Get(int iAdapterIndex, CWDDEPM_USERSTATE *lpInputState, CWDDEPM_USERSTATEPARAMETERS *lpOutputParameters);

///
/// \brief Function to set the user state
///
/// This function implements a PM call CWDDEPM_SetUserState
/// \platform
/// \ALL
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[in]  lpInputState The pointer to the user state structure to be set.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
int HIDDEN Pack_PM_UserState_Set(int iAdapterIndex, CWDDEPM_SETUSERSTATE *lpInputState);

///
/// \brief  Function to get the current clock settings
///
/// This function implements a PM call CWDDEPM_GetCurrentClocks
/// \platform
/// \ALL
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[out] lpClockInfo The pointer to the structure storing the retrieved clock ranges for the current power state.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
int HIDDEN Pack_PM_CurrentClock_Get(int iAdapterIndex, CWDDEPM_CLOCKINFO *lpClockInfo);

///
/// \brief Function to get the current PowerXpress adapter
///
/// This function implements a PM call CWDDEPM_GetActivePowerXpressAdapter
/// \platform
/// \ALL
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[out] lpActiveAdapter The pointer to the structure storing the active adapter
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
int HIDDEN Pack_PM_ActivePowerXpressAdapter_Get(int iAdapterIndex, CWDDEPM_POWERXPRESS_GETACTIVEADAPTER *lpActiveAdapter);

///
/// \brief Function to notify the power management event
///
/// This function implements a PM call CWDDEPM_NotifyEvent
/// \platform
/// \ALL
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[in]  lpEvent The pointer to the structure used to notify the event.
/// \param[out] lpOperationResult The pointer the structure storing the result of the operation.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
int HIDDEN Pack_PM_Event_Notify(int iAdapterIndex, CWDDEPM_EVENT *lpEvent, CWDDEPM_EVENT_POWERXPRESS_SWITCH_RESULT *lpOperationResult);

///
/// \brief int Function to get the power management user preferences
///
/// This function implements a PM call CWDDEPM_GetPXUserPreference
/// \platform
/// \ALL
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[in]  lpPowerSource The pointer to the structure storing the power source.
/// \param[out] lpMapping The pointer to the structure storing the retrieved PX preference.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
int HIDDEN Pack_PM_PXUserPreference_Get(int iAdapterIndex, CWDDEPM_POWERSOURCE *lpPowerSource, CWDDEPM_POWERXPRESSPOWERSOURCEMAPPING *lpMapping);

///
/// \brief int Function to set the power management user preferences
///
/// This function implements a PM call CWDDEPM_SetPXUserPreference
/// \platform
/// \ALL
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[in]  lpMapping The pointer to PX perference structure to be set.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
int HIDDEN Pack_PM_PXUserPreference_Set(int iAdapterIndex, CWDDEPM_POWERXPRESSPOWERSOURCEMAPPING *lpMapping);

///
/// \brief Function to retrieve the MultiGPU capability of an adapter.
///
/// This function implements the CI calls to retrieve the MultiGPU capability of an adapter.
///
/// \platform
/// \ALL
/// \param[in] iAdapterIndex     The ADL index handle of the MultiGPU master adapter.
/// \param[in] iMVPUState		The flag specifying Crossfire or MGPUSLS polling.
/// \param[out] iState      	The pointer to the MultiGPU state. CIMVPUSTATE_SLD_ONLY for MGPUSLS otherwise Crossfire.
/// \param[in,out] iNumComb     The pointer to the number of MVPUComb structures in lpCombList.  When calling this function, iNumComb should be set to the number of structures passed to it.  When the function is returned, iNumComb is set to the number of valid MVPUComb structures in lpCombList.
/// \param[out] lpCombList     The pointer to the buffer storing the MVPUComb list. This buffer should be allocated by the user and be large enough to handle a minimum of three MVPUComb structures.
/// \return ADL_OK if the capabilities were fetched correctly,  ADL_ERR_NULL_POINTER if iState,iNumComb or lpCombList are NULL, ADL_ERR_INVALID_PARAM_SIZE if iNumComb is less than three, else ADL_ERR.
int HIDDEN Pack_CI_MultiGPUCaps2_Get (int iAdapterIndex, int iMVPUState, int *iState, int *iNumComb, MVPUComb *lpCombList);

///
/// \brief Function to retrieve the Quad CrossFire capability of an adapter.
///
/// This function implements the CI calls to retrieve the Quad CrossFire capability of an adapter.
///
/// \platform
/// \ALL
/// \param[in] iAdapterIndex     The ADL index handle of the CrossFire master adapter.
/// \param[out] iState      	The pointer to the CrossFire state.
/// \param[in,out] iNumComb     The pointer to the number of ADLCrossfireComb structures in lpCombList.  When calling this function, iNumComb should be set to the number of structures passed to it.  When the function is returned, iNumComb is set to the number of valid ADLCrossfireComb structures in lpCombList.
/// \param[out] lpCombList     The pointer to the buffer storing the MVPUComb list. This buffer should be allocated by the user and be large enough to handle a minimum of three MVPUComb structures.
/// \return ADL_OK if the capabilities were fetched correctly,  ADL_ERR_NULL_POINTER if iState,iNumComb or lpCombList are NULL, ADL_ERR_INVALID_PARAM_SIZE if iNumComb is less than three, else ADL_ERR.
int HIDDEN Pack_CI_MULTIVPUCaps2_Get (int iAdapterIndex, int *iState, int *iNumComb, MVPUComb *lpCombList);

#if defined (LINUX)
///
/// \brief Function to retrieve the Quad MGPU-SLS capability of an adapter.
///
/// This function implements the CI calls to retrieve the Quad MGPU-SLS capability of an adapter.
///
/// \platform
/// \LNX
/// \param[in] iAdapterIndex     The ADL index handle of the MGPU-SLS master adapter.
/// \param[out] iState      	The pointer to the MGPU-SLS state.
/// \param[in,out] iNumComb     The pointer to the number of ADLMultiGPUComb structures in lpCombList.  When calling this function, iNumComb should be set to the number of structures passed to it.  When the function is returned, iNumComb is set to the number of valid ADLMultiGPUComb structures in lpCombList.
/// \param[out] lpCombList     The pointer to the buffer storing the MVPUComb list. This buffer should be allocated by the user and be large enough to handle a minimum of three MVPUComb structures.
/// \return ADL_OK if the capabilities were fetched correctly,  ADL_ERR_NULL_POINTER if iState,iNumComb or lpCombList are NULL, ADL_ERR_INVALID_PARAM_SIZE if iNumComb is less than three, else ADL_ERR.
int HIDDEN Pack_CI_MultiVPUCaps2_MGPUSLS_Get (int iAdapterIndex, int *iState, int *iNumComb, MVPUComb *lpCombList);
#endif

///
/// \brief Function to retrieve and set Quad Crossfire settings for an adapter.
///
/// This function implements the CI calls to retrieve and set current quad Crossfire or MGPUSLS settings to an adapter.
///
/// \platform
/// \ALL
/// \param[in] iAdapter      The ADL index handle of the CrossFire master adapter.
/// \param[in] pMVPU2      	The pointer to the structure storing the CrossFire information to be retrieved or set. Set ulCombState field in Combination member to CIMVPUSTATE_MVPUACTIVE for Crossfire or CIMVPUSTATE_SLD_ONLY for MGPUSLS.
/// \param[out] pStatus     The pointer to the stucture storing the status information of the CrossFire combination in question, or the new CrossFire status.
/// \return ADL_OK if the crossfire information was retrieved or set correctly,  ADL_ERR_NULL_POINTER if pMVPU2, pStatus are NULL, else ADL_ERR.
int HIDDEN Pack_CI_MultiVPU2_GetSet(int iAdapter, CIMULTIVPU2 *pMVPU2, CIMULTIVPUSTATUS2 *pStatus);

///
/// \brief Function to retrieve MultiVPU capability
///
/// This function implements the CI calls to retrieve MultiVPU capability.
///
/// \platform
/// \ALL
/// \param[in]  iAdapterIndex     The ADL index handle of the desired adapter.
/// \param[out] lpMultiVPUCaps    The pointer to the stucture storing the retrieved MultiVPU capability.
/// \return ADL_OK if the crossfire information was retrieved or set correctly,  ADL_ERR_NULL_POINTER if lpMultiVPUCaps is NULL, else ADL_ERR.
int HIDDEN Pack_CI_MULTIVPUCAPS_Get(int iAdapterIndex, CIMULTIVPUCAPS *lpMultiVPUCaps);


///
/// \brief Function to retrieve the software CrossFire capability of an adapter.
///
/// This function implements the CI calls to retrieve the software CrossFire capability of an adapter.
///
/// \platform
/// \ALL
/// \param[in] iAdapterIndex     The ADL index handle of the CrossFire master adapter.
/// \param[out] iState      	The pointer to the CrossFire state.
/// \param[in,out] iNumComb     The pointer to the number of ADLCrossfireComb structures in lpCombList.  When calling this function, iNumComb should be set to the number of structures passed to it.  When the function is returned, iNumComb is set to the number of valid ADLCrossfireComb structures in lpCombList.
/// \param[out] lpCombList     The pointer to the buffer storing the MVPUComb list. This buffer should be allocated by the user and be large enough to handle a minimum of three MVPUComb structures.
/// \return ADL_OK if the capabilities were fetched correctly,  ADL_ERR_NULL_POINTER if iState,iNumComb or lpCombList are NULL, ADL_ERR_INVALID_PARAM_SIZE if iNumComb is less than three, else ADL_ERR.
int HIDDEN Pack_CI_MULTIVPUCAPSX2_Get(int iAdapterIndex, int *iState, int *iNumComb, MVPUComb *lpCombList);

///
/// \brief Function to retrieve and set MultiVPU status.
///
/// This function implements the CI calls to retrieve and set MultiVPU status.
///
/// \platform
/// \ALL
/// \param[in]  iAdapterIndex     The ADL index handle of the desired adapter.
/// \param[out] lpMultiVPU        The pointer to the stucture for which to retrieve and set the MultiVPU status.
/// \param[out] lpMultiVPUStatus  The pointer to the stucture storing the retrieved MultiVPU status.
/// \return ADL_OK if the crossfire information was retrieved or set correctly,  ADL_ERR_NULL_POINTER if lpMultiVPU, lpMultiVPUStatus are NULL, else ADL_ERR.
int HIDDEN Pack_CI_MULTIVPU_GetSet(int iAdapterIndex, CIMULTIVPU *lpMultiVPU, CIMULTIVPUSTATUS *lpMultiVPUStatus);

///
/// \brief Function to get the power management feature status
///
/// This function implements a PM call CWDDEPM_GetFeatureStatus.
/// \platform
/// \ALL
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[in]  lpFeature The pointer to the structure for which to retrieve feature status.
/// \param[out] lpFeatureStatus The pointer to the structure storing the retrieved PM feature status.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
int HIDDEN Pack_PM_FeatureStatus_Get(int iAdapterIndex, CWDDEPM_FEATURE *lpFeature, CWDDEPM_GETFEATURESTATUS * lpFeatureStatus);

///
/// \brief Function to Enable or Disable a power management feature
///
/// This function implements a PM call CWDDEPM_SetFeatureStatus.
/// \platform
/// \ALL
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[out] lpSetFeatureStatus The pointer to the structure to set the PM feature status.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
int HIDDEN Pack_PM_FeatureStatus_Set(int iAdapterIndex, CWDDEPM_SETFEATURESTATUS * lpSetFeatureStatus);

///
/// \brief Function to Gets the event counts
///
/// This function implements a PM call CWDDEPM_GetEventCounter.
/// \platform
/// \ALL
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[in] lpInEventCounter The pointer to the CWDDEPM_EVENTCOUNTER which holds requested event details
/// \param[out] lpOutEventCount The pointer to the CWDDEPM_EVENTCOUNT which holds event count.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
int HIDDEN Pack_PM_CountOfEvents_Get(int iAdapterIndex, CWDDEPM_EVENTCOUNTER *lpInEventCounter, CWDDEPM_EVENTCOUNT * lpOutEventCount);

///
/// \brief Function to get the current power management activity
///
/// This function implements a PM call CWDDEPM_GetCurrentActivity.
/// \platform
/// \ALL
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[out] lpActivity The pointer to the structure storing the retrieved information about current power management activity.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
int HIDDEN Pack_PM_CurrentActivity_Get(int iAdapterIndex, CWDDEPM_ACTIVITY *lpActivity);

///
/// \brief Function to Get the Smart shift settings
///
/// This function implements a PM call CWDDEPM_SmartShift_GetCurrentSettings.
/// \platform
/// \ALL
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[out] lpSettings The pointer to the CWDDEPM_SmartShift_GetCurrentSettings_Output which holds SS settings.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
int HIDDEN Pack_PM_SmartShift_Get(int iAdapterIndex, CWDDEPM_SmartShift_GetCurrentSettings_Output *lpSettings);

///
/// \brief Function to Set the smart shift delta gain 
///
/// This function implements a PM call CWDDEPM_SmartShift_SetDeltaGainControl.
/// \platform
/// \ALL
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[in] lpSettings The pointer to the CWDDEPM_SmartShift_SetDeltaGain_Input which holds requested SS settings details
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
int HIDDEN Pack_PM_SmartShift_Set(int iAdapterIndex, CWDDEPM_SmartShift_SetDeltaGain_Input *lpSettings);

///
/// \brief Function to enumerate the power management thermal devices
///
/// This function implements a PM call CWDDEPM_EnumerateThermalDevices
/// \platform
/// \ALL
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[in]  lpThermalController The pointer to the structure to which to retrieve thermal controller information.
/// \param[out] lpThermalControllerInfo The pointer to the structure storing the retrieved thermal device information.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
int HIDDEN Pack_PM_ThermalDevices_Enum(int iAdapterIndex, CWDDEPM_THERMALCONTROLLER *lpThermalController, CWDDEPM_THERMALCONTROLLERINFO *lpThermalControllerInfo);

///
/// \brief int Function to get temperature from ASICs with OD5 support
///
/// This function implements a PM call CWDDEPM_GetTemperature
/// \platform
/// \ALL
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[in]  lpThermalController The pointer to the structure to which to retrieve thermal controller information.
/// \param[out] lpTemperature The pointer to the structure storing the retrieved temperature information.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
int HIDDEN Pack_PM_Temperature_Get(int iAdapterIndex, CWDDEPM_THERMALCONTROLLER *lpThermalController, CWDDEPM_TEMPERATURE *lpTemperature);

///
/// \brief int Function to get temperature from ASICs with OD6 support
///
/// This function implements a PM call CWDDEPM_OD6_GetTemperature
/// \platform
/// \ALL
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[in]  lpThermalController The pointer to the structure to which to retrieve thermal controller information.
/// \param[out] lpTemperature The pointer to the structure storing the retrieved temperature information.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
int HIDDEN Pack_PM_OD6_Temperature_Get(int iAdapterIndex, CWDDEPM_THERMALCONTROLLER *lpThermalController, CWDDEPM_TEMPERATURE *lpTemperature);

///
/// \brief Function to get information about the fan speed
///
/// This function implements a PM call CWDDEPM_GetFanSpeedInfo
/// \platform
/// \ALL
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[in]  lpThermalController The pointer to the structure to which to retrieve thermal controller information.
/// \param[out] lpFanSpeedInfo The pointer to the structure storing the retrieved fan speed information.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
int HIDDEN Pack_PM_FanSpeedInfo_Get(int iAdapterIndex, CWDDEPM_THERMALCONTROLLER *lpThermalController, CWDDEPM_FANSPEEDINFO *lpFanSpeedInfo);

///
/// \brief Function to get the fan speed
///
/// This function implements a PM call CWDDEPM_GetFanSpeed
/// \platform
/// \ALL
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[in]  lpFanSpeedQuery The pointer to the structure for which to retrieve fan speed.
/// \param[out] lpFanSpeedValue The pointer to the structure storing the retrieved fan speed.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
int HIDDEN Pack_PM_FanSpeed_Get(int iAdapterIndex, CWDDEPM_FANSPEEDQUERY *lpFanSpeedQuery, CWDDEPM_FANSPEEDVALUE *lpFanSpeedValue);

///
/// \brief Function to set the fan speed
///
/// This function implements a PM call CWDDEPM_SetFanSpeed
/// \platform
/// \ALL
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[in]  lpFanSpeedSetting The pointer to the structure with fan speed settings
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
int HIDDEN Pack_PM_FanSpeed_Set(int iAdapterIndex, CWDDEPM_FANSPEEDSETTING *lpFanSpeedSetting);

///
/// \brief Function to reset the fan speed
///
/// This function implements a PM call CWDDEPM_ResetFanSpeedToDefault
/// \platform
/// \ALL
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[in]  lpThermalController The pointer to the structure with data for the thermal controller.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
int HIDDEN Pack_PM_FanSpeedToDefault_Reset(int iAdapterIndex, CWDDEPM_THERMALCONTROLLER *lpThermalController);

///
/// \brief Function to get the Overdrive parameters
///
/// This function implements a PM call CWDDEPM_GetODParameters
/// \platform
/// \ALL
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[out] lpODParameters The pointer to the structure storing the retrieved OD parameters.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
int HIDDEN Pack_PM_ODParameters_Get(int iAdapterIndex, CWDDEPM_ODPARAMETERS *lpODParameters);

///
/// \brief Function to get the Overdrive performance levels
///
/// This function implements a PM call CWDDEPM_GetODPerformanceLevels
/// \platform
/// \ALL
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[in]  lpODGetClocksInput The pointer to the structure storing the desired performance levels.
/// \param[out] lpODGetClocksOutput The pointer to the structure storing the retrieved performance levels.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
int HIDDEN Pack_PM_ODPerformanceLevels_Get(int iAdapterIndex, CWDDEPM_ODGETCLOCKSINPUT *lpODGetClocksInput, CWDDEPM_ODGETCLOCKSOUTPUT *lpODGetClocksOutput);

///
/// \brief Function to get the Overdrive default performance levels
///
/// This function implements a PM call CWDDEPM_GetODDefaultPerformanceLevels
/// \platform
/// \ALL
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[in]  lpODGetClocksInput The pointer to the structure storing the default performance levels.
/// \param[out] lpODGetClocksOutput The pointer to the structure storing the retrieved default performance levels.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
int HIDDEN Pack_PM_ODDefaultPerformanceLevels_Get(int iAdapterIndex, CWDDEPM_ODGETCLOCKSINPUT *lpODGetClocksInput, CWDDEPM_ODGETCLOCKSOUTPUT *lpODGetClocksOutput);

///
/// \brief Function to set the Overdrive performance levels
///
/// This function implements a PM call CWDDEPM_SetODPerformanceLevels
/// \platform
/// \ALL
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[in]  lpODSetClocks The pointer to the structure to set OD performance level information.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
int HIDDEN Pack_PM_ODPerformanceLevels_Set(int iAdapterIndex, CWDDEPM_ODSETCLOCKS *lpODSetClocks);

///
/// \brief Function to get the Power Control parameters
///
/// This function implements a PM call CWDDEPM_GetPowerControlSetting
/// \platform
/// \ALL
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[out] lpPCParameters The pointer to the structure storing the retrieved OD parameters.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
int HIDDEN Pack_PM_ODPowerControlParameters_Get(int iAdapterIndex, CWDDEPM_POWERCONTROLPARAMETERS *lpPCParameters);

///
/// \brief Function to get the Power Control parameters
///
/// This function implements a PM call CWDDEPM_GetPowerControlSetting
/// \platform
/// \ALL
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[out] lpPCLevel The pointer to the structure storing the retrieved OD parameters.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
int HIDDEN Pack_PM_ODPowerControl_Get(int iAdapterIndex, CWDDEPM_POWERCONTROLLEVEL *lpPCLevel);

///
/// \brief Function to get the Power Control Default parameters
///
/// This function implements a PM call CWDDEPM_GetPowerControlDefaultSetting
/// \platform
/// \ALL
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[out] lpPCLevel The pointer to the structure storing the retrieved OD parameters.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
int HIDDEN Pack_PM_ODPowerControl_Default_Get(int iAdapterIndex, CWDDEPM_POWERCONTROLLEVEL *lpPCLevel);

///
/// \brief Function to set the Overdrive Power Control levels
///
/// This function implements a PM call CWDDEPM_SetPowerControlSetting
/// \platform
/// \ALL
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[in]  lpPCLevel The structure to set OD Power Control level information.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
int HIDDEN Pack_PM_ODPowerControl_Set(int iAdapterIndex, CWDDEPM_POWERCONTROLLEVEL lpPCLevel);

///
/// \brief Function to get the Power Control parameters
///
/// This function implements a PM call CWDDEPM_GetPowerControlSetting_2
/// \platform
/// \ALL
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[out] lpPCLevel The pointer to the structure storing the retrieved OD parameters.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
int HIDDEN Pack_PM_ODPowerControl_Get_2(int iAdapterIndex, CWDDEPM_POWERLIMIT *lpPCLimit);

///
/// \brief Function to get the Power Control Default parameters
///
/// This function implements a PM call CWDDEPM_GetPowerControlDefaultSetting_2
/// \platform
/// \ALL
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[out] lpPCLevel The pointer to the structure storing the retrieved OD parameters.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
int HIDDEN Pack_PM_ODPowerControl_Default_Get_2(int iAdapterIndex, CWDDEPM_POWERLIMIT *lpPCLimit);

///
/// \brief Function to set the Overdrive Power Control levels
///
/// This function implements a PM call CWDDEPM_SetPowerControlSetting_2
/// \platform
/// \ALL
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[in]  lpPCLevel The structure to set OD Power Control level information.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
int HIDDEN Pack_PM_ODPowerControl_Set_2(int iAdapterIndex, CWDDEPM_POWERLIMIT lpPCLimit);

///
/// \brief Function to get adapter information
///
/// This function implements a DI call CWDDEDI_AdapterGetDriverInfo
/// \platform
/// \ALL
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[out] lpAdapterDriverInfo The pointer to the structure storing the retrieved driver information.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
int HIDDEN Pack_DI_AdapterDriverInfo_Get(int iAdapterIndex, DRIVERINFO *lpAdapterDriverInfo);

///
/// \brief Function to get adapter configuration
///
/// This function implements a DI call CWDDEDI_AdapterGetConfig
/// \platform
/// \ALL
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[in]  ulConfigType The configuration type for the adapter configuration being retrieved.
/// \param[out] lpAdapterConfig The pointer to the structure storing the retrieved adapter configuration information.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
int HIDDEN Pack_DI_AdapterConfig_Get(int iAdapterIndex, ULONG ulConfigType, ADAPTERCONFIG *lpAdapterConfig);

///
/// \brief Function to set adapter configuration
///
/// This function implements a DI call CWDDEDI_AdapterSetConfig
/// \platform
/// \ALL
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[in]  lpAdapterConfig The pointer to the structure to set adapter configuration information.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
int HIDDEN Pack_DI_AdapterConfig_Set(int iAdapterIndex, ADAPTERCONFIG *lpAdapterConfig);


///
/// \brief Function to set dynamic prunning
///
/// This function implements a DI call CWDDEDI_ADAPTER_CONFIG_DISABLEDYNAMICMODEPRUNING
/// \platform
/// \ALL
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[in]  disablePrunning The boolean variable indicating whether or not to disable prunning. TRUE: disable Prunning; FALSE: enable Prunning.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
int HIDDEN  Pack_DI_DALDyanmicPrunning_Set(int iAdapterIndex, BOOL disablePrunning);

///
/// \brief Function to validate rotation
///
/// This function implements a CI call CWDDECI_VALIDATEROTATION
/// \platform
/// \ALL
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[in]  rotation The rotation to be validated.
/// \param[out]  lpRotationSupport The pointer to the structure storing the retrieved rotation support information.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
int HIDDEN Pack_CI_ValidationRotation(int iAdapterIndex, CIROTATION rotation, CIULONG *lpRotationSupport);

///
/// \brief Function to get rotation
///
/// This function implements a CI call CWDDECI_GETROTATION
/// \platform
/// \ALL
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[out]  lpRotation The pointer to the structure storing the retrieved CIROTATION information.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
int HIDDEN Pack_CI_Rotation_Get(int iAdapterIndex, CIROTATION *lpRotation);

///
/// \brief Function to set rotation
///
/// This function implements a CI call CWDDECI_SETROTATION
/// \platform
/// \ALL
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[in]  rotation The CIROTATION information to be set.
/// \param[out]  lprotationSupport The pointer to the structure storing the retrieved CIULONG rotation support information.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
int HIDDEN Pack_CI_Rotation_Set(int iAdapterIndex, CIROTATION rotation, CIULONG *lprotationSupport);

///
/// \brief Function to set adapter speed
///
/// This function implements a CI call CWDDECI_SETADAPTERSPEED
/// \platform
/// \ALL
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[in]  speedInput The input structure that contains the speed setting to set
/// \param[out] lpSpeedOUtput The output structure (reserved)
int HIDDEN Pack_CI_AdapterSpeed_Set (int iAdapterIndex, SHARED_SET_CONTEXT_SPEED_INPUT speedInput, SHARED_SET_CONTEXT_SPEED_OUTPUT* lpSpeedOutput);

///
/// \brief Function to get adapter speed
///
/// This function is currently NOT SUPPORTED
/// \platform
/// \ALL
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[out] lpSpeedOutput The output structure that contains the speed setting
int HIDDEN Pack_CI_AdapterSpeed_Get (int iAdapterIndex, SHARED_GET_CONTEXT_SPEED_OUTPUT* lpSpeedOutput);

///
/// \brief Function to hide mode change
///
/// This function implements a CI call CWDDECI_HIDDENMODESET
/// \platform
/// \ALL
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[in]  bHidden Set to true to hide flickering during mode change
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
int HIDDEN Pack_CI_HideModeChange (int iAdapterIndex, BOOL bHidden);

///
/// \brief Function to get Workstation informaiton
///
/// This function implements a CI call CWDDECI_GETWSINFO
/// \platform
/// \ALL
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[out]  lpCSWSINFO - returned CIWSINFO structure
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
int HIDDEN Pack_CI_Get_Ws_Info(int iAdapterIndex, CIWSINFO *lpCSWSINFO);

///
/// \brief Function to get Big Software Release Version informaiton
///
/// This function implements a KMD Escape call LHESCAPE_UMDKMDIF_GET_BIGSW_RELEASE_VERSION
/// \platform
/// \ALL
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[out]  lpBIGSWINFO - returned UMDKMDIF_GET_BIGSW_RELEASE_VERSION_OUTPUT structure
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
int HIDDEN Pack_KMD_Get_BigSw_Info(int iAdapterIndex, UMDKMDIF_GET_BIGSW_RELEASE_VERSION_OUTPUT *lpBIGSWINFO);

///
/// \brief Function to get CWG and IsGamingDriver informaiton
///
/// This function implements a CI call to retrieve IsGamingDriver info.
/// \platform
/// \ALL
/// \param[in]  iAdapterIndex       The ADL index handle of the desired adapter.
/// \param[in]  pInCallerBuffer     The desired input buffer.
/// \param[out] pOutCallerBuffer    The pointer to the output buffer.
/// \return If the function succeeds, the return value is \ref ADL_OK, or an ADL error code otherwise.  \ref define_adl_results
int HIDDEN Pack_CI_IsGamingDriverInfo_Get(int iAdapterIndex, UMDKMDIF_IS_GAMING_DRIVER_INPUT *pInCallerBuffer, UMDKMDIF_IS_GAMING_DRIVER_OUTPUT *pOutCallerBuffer);

///
/// \brief Function to notify KMD that Chill settings have changed.
///
/// This function communicates KMD via "LHESCAPE_UMDKMDIF_NOTIFY_CHILL_CHANGE" that user changed chill settings.
/// \platform
/// \WIN
/// \param[in]  iAdapterIndex The index of the desired adapter.
/// \param[in]  iChanged \ref ADL_TRUE   \ref ADL_FALSE
/// \return If the function succeeds, the return value is \ref ADL_OK (zero). Otherwise the return value is an ADL error code (non-zero). \ref define_adl_results
int HIDDEN Pack_Chill_Settings_Notify(int iAdapterIndex, int iChanged);

///
/// \brief Function to set MGPU SLS feature Toggle On/OFF by calling driver function
///
/// This function communicates KMD via "LHESCAPE_UMDKMDIF_TOGGLE_MGPUSLS_FEATURE" that user toggled MGPU SLS.
/// \platform
/// \Win
/// \param[in]  AdapterIndex The ADL index handle of the desired adapter.
/// \param[out] iCurrentAction, MGPU SLS feature Toggle On/OFF of the specified adapter
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code.   \ref define_adl_results
int HIDDEN Pack_MGPUSLS_Status_Set(int iAdapterIndex, UMDKMDIF_TOGGLE_ACTION iCurrentAction);

///
/// \brief Function to determine if specific CWDDEDI escape is supported.
///
/// This function implements the DI call to determine if specific CWDDEDI escape and sub-function is supported.
///
/// \platform
/// \ALL
///
/// \param[in]  iAdapterIndex		The ADL index handle of the desired adapter.
/// \param[in]  ulEscapeID			The escape function number to check.
/// \param[in]  ulSubFunctionID		The escape sub-function to check.
/// \param[out] piSupport			1 if function and subfuncton is supported, 0 otherwise.
///
/// \return ADL_OK if the capabilities were fetched correctly, else ADL_ERR.
int HIDDEN Pack_DI_EscapeSupport_Get (int iAdapterIndex, ULONG ulEscapeID, ULONG ulSubFunctionID, int* piSupport);

///
/// \brief Function to check if the GPU is accessible or not at the time of this call.
///
/// Some GPUs enter into various power savings mode when not in use, and during this time, direct access to the GPU can result in failures.
/// Access through proper channels (such as via ADL) always works because the software accounts for the GPU's accessibility.
/// However, direct access outside of authorised mechanisms may fail.
/// Use this API to find out if the GPU is currently is accessible or not.
///  If API returns GPU accessible, this status will be maintained for 2 seconds.
///
/// \platform
/// \ALL
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[out] lpAccessibility The pointer to CWDDEPM_ISGPUACCESSIBLE structure which has fields to indicate if the adapter is accessible or not (\ref ADL_TRUE : accessible, \ref ADL_FALSE : not accessible
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
int HIDDEN Pack_PM_GPUAccessibility_Get(int iAdapterIndex, CWDDEPM_ISGPUACCESSIBLE *lpAccessible);

///
/// This function implements the DI call to obtain the adapter  grid info.
///
/// \platform
/// \ALL
///
/// \param[in]  iAdapterIndex		The ADL index handle of the desired adapter.
/// \param[out] lpAdapterSlsInfo	The pointer to the adapter SLS grid info
///
/// \return \ref ADL_OK if the call succeeded, else error.
int HIDDEN Pack_DI_AdapterGridInfo_Get (int iAdapterIndex, DI_AdapterSlsInfo* lpAdapterSlsInfo);

///
/// This function implements the DI call to obtain the adapter  grid info.
///
/// \platform
/// \ALL
///
/// \param[in]  iAdapterIndex		The ADL index handle of the desired adapter.
/// \param[in]  lpTargetInfoRequest	The pointer Target to query
/// \param[out] lpTargetInfo		The pointer to the target info
///
/// \return \ref ADL_OK if the call succeeded, else error.
int HIDDEN Pack_DI_TargetInfo_Get (int iAdapterIndex, DI_CWDDE_GetTargetInfoRequest* lpTargetInfoRequest, DI_TargetInfo* lpTargetInfo);

///
/// This function implements the DI call to obtain the Targets translation table for the GPU of this adapter.
///
/// \platform
/// \ALL
///
/// \param[in]  iAdapterIndex		The ADL index handle of the desired adapter.
/// \param[out] lpNumTargets		The number of targets in the returned target translation table.
/// \param[out] lppTranslationTable	The pointer to the pointer to the target translation table. The user must free the *lppTranslationTable memory once done with this pointer
///
/// \return \ref ADL_OK if the call succeeded, else error.
int HIDDEN Pack_DI_TargetHandleTranslationTable_Get (int iAdapterIndex, int* lpNumTargets, DI_TargetTranslateEntry** lppTranslationTable);

///
/// This function implements the DI call to list all Targets for the GPU of this adapter.
///
/// \platform
/// \ALL
///
/// \param[in]  iAdapterIndex		The ADL index handle of the desired adapter.
/// \param[in]  doDetection			1 if the the driver must do detection or 0 to return the driver chached info.
/// \param[in]  connectedOnly		1 if asking only connected targets or zero if asking all the targets.
/// \param[out] lpNumTargets		The number of targets in the returned target infos array. If positive the function asks driver for that many targets, else makes DI call to find out how many targets.
/// \param[out] lppTargets			The pointer to the array of target infos. The user must free the *lppTargets memory once done with this pointer
///
/// \return \ref ADL_OK if the call succeeded, else error.
int HIDDEN Pack_DI_AllTargets_Get (int iAdapterIndex, int doDetection, int connectedOnly, int* lpNumTargets, DI_TargetInfo** lppTargets);

///
/// This function implements the DI call to determine summary information about the topology of this adapter.
///
/// \platform
/// \ALL
///
/// \param[in]  iAdapterIndex		The ADL index handle of the desired adapter.
/// \param[out] lpNumMaps			Pointer to the number of maps within this topology
/// \param[out] lpNumTargets		Pointer to the number of targets within this topology.
///
/// \return \ref ADL_OK if the call succeeded, else error.
int HIDDEN Pack_DI_TopologySummary_Get (int iAdapterIndex, int* lpNumMaps, int* lpNumTargets);

///
/// This function implements the DI call to return the current topology of targets configured on an adapter.
/// If caller knows the number of maps and targets should pass them into the respective parameters. In this case
/// this function trusts them and won't call the topology summary to find the numbers.
/// If these passed (positive) numbers are not correct the function will fail.
///
/// \platform
/// \ALL
///
/// \param[in]  iAdapterIndex		The ADL index handle of the desired adapter.
/// \param[out] lpNumMaps			The number of TargetMaps comprising this topology
/// \param[out] lppDITargetMaps		The pointer to the pointer storing the target maps for this adapter. The user must free the *lppDITargetMaps memory once done with it.
/// \param[out] lpNumTargets		The number of Targets comprising this topology
/// \param[out] lppDITargets		The pointer to the pointer storing the targets for this adapter. The user must free the *lppDITargets memory once done with it.
///
/// \return \ref ADL_OK if the call succeeded, else error.
int HIDDEN Pack_DI_Topology_Get (int iAdapterIndex,
                                 int* lpNumMaps, DI_TargetMap** lppDITargetMaps,
                                 int* lpNumTargets, DI_TargetSpecifier** lppDITargets);

///
/// This function implements the DI call to set or validate a topology of targets on an adapter.
///
/// \platform
/// \ALL
///
/// \param[in]  iAdapterIndex		The ADL index handle of the desired adapter.
/// \param[in]  ulEscapeID			Either CWDDEDI_ValidateDriverTopology (to validate a topology) or CWDDEDI_SetDriverTopology (to set a topology)
/// \param[in]  numMaps				The number of TargetMaps comprising this topology
/// \param[in]  lpDIMaps			The TargetMaps comprising this topology
/// \param[in]  numTargets			The number of Targets comprising this topology
/// \param[in]  lpDITargets			The Targets comprising this topology
///
/// \return \ref ADL_OK if the call succeeded, else error.
int HIDDEN Pack_DI_Topology_SetValidate (int iAdapterIndex, ULONG ulEscapeID,
                                         int numMaps, DI_TargetMap* lpDIMaps,
                                         int numTargets, DI_TargetSpecifier* lpDITargets);

///
/// This function implements the DI call to obtain the array of display targets that can be added or removed to the given topology of targets on an adapter.
///
/// \platform
/// \ALL
///
/// \param[in]  iAdapterIndex		The ADL index handle of the desired adapter.
/// \param[in]  numAllTargets		The total number of targets supported by this GPU
/// \param[in]  numMaps				The number of TargetMaps comprising this topology
/// \param[in]  lpDITargetMaps		The TargetMaps comprising this topology
/// \param[in]  numTargets			The number of Targets comprising this topology
/// \param[in]  lpDITargets			The Targets comprising this topology
/// \param[out] lpNumPossibleAddTargets		The pointer to the number of Targets that can be added to this topology
/// \param[out] lppDIPossibleAddTargets		The pointer to the array of TargetHandles for the Targets that can be added to this topology. Caller must free the memory when no longer needed.
/// \param[out] lpNumPossibleRemoveTargets	The pointer to the number of Targets that can be removed from this topology
/// \param[out] lppDIPossibleRemoveTargets	The pointer to the array of TargetHandles for the Targets that can be removed from this topology. Caller must free the memory when no longer needed.
///
/// \return \ref ADL_OK if the call succeeded, else error.
int HIDDEN Pack_DI_Topology_GetPossibleTargets (int iAdapterIndex,
                                                int numAllTargets,
                                                int numMaps, DI_TargetMap* lpDIMaps,
                                                int numTargets, DI_TargetSpecifier* lpDITargets,
                                                int* lpNumPossibleAddTargets, int** lppDIPossibleAddTargets,
                                                int* lpNumPossibleRemoveTargets, int** lppDIPossibleRemoveTargets);

///
/// This function reads data from the output data returned by a topology call.
///
/// \platform
/// \ALL
///
/// \param[in]  lpOutBuffer			The DI output buffer to read
/// \param[in]  outputSize			The size of the DI output buffer
/// \param[out] lpNumMaps			The number of TargetMaps comprising this topology
/// \param[out] lppDITargetMaps		The pointer to the pointer storing the target maps for this adapter. The user must free the *lppDITargetMaps memory once done with it.
/// \param[out] lpNumTargets		The number of Targets comprising this topology
/// \param[out] lppDITargets		The pointer to the pointer storing the targets for this adapter. The user must free the *lppDITargets memory once done with it.
///
/// \return \ref ADL_OK if the buffer was successfully allocated and filled, else error.
int HIDDEN Pack_DI_Topology_ReadOutput (LPBYTE lpOutBuffer, int outputSize,
                                        int* lpNumMaps, DI_TargetMap** lppDITargetMaps,
                                        int* lpNumTargets, DI_TargetSpecifier** lppDITargets);

///
/// This function prepares the DI input buffer suitable for a topology call.
///
/// \platform
/// \ALL
///
/// \param[in]  ulEscapeID			The EscapeId to pack into the CWDDECMD parameter.
/// \param[in]  numMaps				The number of TargetMaps comprising this topology
/// \param[in]  lpDITargetMaps		The TargetMaps comprising this topology
/// \param[in]  numTargets			The number of Targets comprising this topology
/// \param[in]  lpDITargets			The Targets comprising this topology
/// \param[out] lppInBuffer			Pointer to the DI input buffer prepared. Caller is responsible to deallocate when no longer needed
/// \param[out] lpInputSize			Size of the allocated buffer
///
/// \return \ref ADL_OK if the buffer was successfully allocated and filled, else error.
int HIDDEN Pack_DI_Topology_SetInput (ULONG ulEscapeID,
                                      int numMaps, DI_TargetMap* pDITargetMaps,
                                      int numTargets, DI_TargetSpecifier* pDITargets,
                                      LPBYTE* lppInBuffer, int* lpInputSize);

///
/// This function checks if two topologies are the same in terms of Maps and Targets (but not the mode).
/// The Maps in the 1st topology can have SourceIDs equal to -1; in this case it will match it with
/// any Map from the 2nd topology with the same no of targets and the exact same targets.
///
/// \platform
/// \ALL
///
/// \param[in]  numMaps				The number of TargetMaps comprising this topology
/// \param[in]  lpDIMaps1			The TargetMaps comprising the 1st topology
/// \param[in]  lpDIMaps2			The TargetMaps comprising the 2nd topology
/// \param[in]  numTargets			The number of Targets comprising this topology
/// \param[in]  lpDITargets1		The Targets comprising the 1st topology
/// \param[in]  lpDITargets2		The Targets comprising the 2nd topology
///
/// \return \ref ADL_TRUE if the two topologies match, or other value if they not match
int HIDDEN Pack_DI_Topologies_Match (int numMaps, DI_TargetMap* lpDIMaps1, DI_TargetMap* lpDIMaps2,
                                     int numTargets, DI_TargetSpecifier* lpDITargets1, DI_TargetSpecifier* lpDITargets2);

///
/// This function checks if two sets of targets are the same.
///
/// \platform
/// \ALL
///
/// \param[in]  numTargets			The number of Targets comprising this topology
/// \param[in]  lpDITargets1		The Targets comprising the 1st topology
/// \param[in]  firstIndexTargets1	The index of the first target to check in the 1st topology
/// \param[in]  numTargets1			The number of targets to check in the 1st topology
/// \param[in]  lpDITargets2		The Targets comprising the 2nd topology
/// \param[in]  firstIndexTargets2	The index of the first target to check in the 2nd topology
/// \param[in]  numTargets2			The number of targets to check in the 2nd topology
///
/// \return \ref ADL_TRUE if the two topologies match, or other value if they not match
int HIDDEN Pack_DI_Targets_Match (int numTargets,
                                  DI_TargetSpecifier* lpDITargets1, int firstIndexTargets1, int numTargets1,
                                  DI_TargetSpecifier* lpDITargets2, int firstIndexTargets2, int numTargets2);

///
/// This function implements the DI call to get the number of posisble SLS grid for a given GPU
///
/// \platform
/// \ALL
///
/// \param[in]  iAdapterIndex		The ADL index handle of the desired adapter.
///
/// \return the number of possible SLS grid

int HIDDEN Pri_ADL_Display_NumberOfPosisbleGrids_Get(int iAdapterIndex);


///
/// This function implements the DI call to get the number of active or achieved SLS grids for a given GPU
///
/// \platform
/// \ALL
///
/// \param[in]  iAdapterIndex		The ADL index handle of the desired adapter.
/// \param[in]  iActiveSLS		    if it is 1, the output is only for active SLS grids. Otherwise the output conatins achieved grids
///
/// \return the number of active or acheieved SLS grids based on request.
int HIDDEN Pri_ADL_Display_NumberOfActiveOrAchievedGrids_Get(int iAdapterIndex,

                                                             int iAcitveSLS);
///
/// This function implements the DI call to get the posisble SLS grid for a given GPU
///
/// \platform
/// \ALL
///
/// \param[in]  iAdapterIndex		The ADL index handle of the desired adapter.
/// \param[in]  iNumberPossibleGrid	The number of possible grid
/// \param[out] lpPossibleGrid		The pointer of possible grid.
///
/// \return ADL_OK if the call succeeded, else error.

int HIDDEN Pack_DI_PossibleGrid_Cap(int iAdapterIndex,
                                    int iNumberPossibleGrid,
                                    DI_ListPossibleGridsResponse* lpPossibleGrid);


///
/// This function implements the DI call to get active SLS grids for given GPU
///
/// \platform
/// \ALL
///
/// \param[in]  iAdapterIndex		The ADL index handle of the desired adapter.
/// \param[in]  iNumberActiveGrid	The number of active SLS grid
/// \param[out] llpActiveGrid		The pointer of active grid.
///
/// \return ADL_OK if the call succeeded, else error.
int HIDDEN Pack_DI_ActiveGrid_Get(int iAdapterIndex,
                                  int iNumberActiveGrid,
                                  DI_ListActiveGridsResponse* lpActiveGrid);


///
/// This function implements the DI call to delete SLS grids
///
/// \platform
/// \ALL
///
/// \param[in]  iAdapterIndex		The ADL index handle of the desired adapter.
/// \param[in]  SLSMapRequest	    The grid map index that will be deleted
///
/// \return ADL_OK if the call succeeded, else error.
int HIDDEN Pack_DI_Display_SLSMapConfig_Delete(int iAdapterIndex,
                                               DI_CWDDE_DisplayGridRequest SLSMapRequest);

///
/// This function implements the DI call to get SLS grids id list
///
/// \platform
/// \ALL
///
/// \param[in]  iAdapterIndex		The ADL index handle of the desired adapter.
/// \param[in]  iDisplayIndex		The ADL index handle of the desired display.
/// \param[in]  iSizeList			Output structure size.
/// \param[out] SLSGridIdList	    SLS GridId Index List
///
/// \return ADL_OK if the call succeeded, else error.
int HIDDEN Pack_DI_Display_SLSRecords_Get(int iAdapterIndex, int dispIDHandle, int iSizeList, DI_CWDDE_GetGridsContainingGivenTargetOutput* SLSGridIdList);

///
/// This function implements the DI call to get SLS gridid list count
///
/// \platform
/// \ALL
///
/// \param[in]  iAdapterIndex		The ADL index handle of the desired adapter.
/// \param[in]  displayID		The ADL index handle of the desired display.
/// \param[out] SLSGridIdListCount	SLS Grid ID list Count
///
/// \return ADL_OK if the call succeeded, else error.
int HIDDEN Pack_DI_Display_SLSRecordsCount_Get(int iAdapterIndex, int dispIDHandle, int *SLSGridIdListCount);

///
/// This function implements the DI call to enable a SLS grid
///
/// \platform
/// \ALL
///
/// \param[in]  iAdapterIndex		The ADL index handle of the desired adapter.
/// \param[in]  SLSMapRequest	    The grid map index that will be enaled
///
/// \return ADL_OK if the call succeeded, else error.
int HIDDEN Pack_DI_Display_SLSMapConfig_Enable(int iAdapterIndex,
                                               DI_CWDDE_DisplayGridRequest SLSMapRequest);


///
/// This function implements the DI call to disable a SLS grid
///
/// \platform
/// \ALL
///
/// \param[in]  iAdapterIndex		The ADL index handle of the desired adapter.
/// \param[in]  SLSMapRequest	    The grid map index that will be disaled
///
/// \return ADL_OK if the call succeeded, else error.
int HIDDEN Pack_DI_Display_SLSMapConfig_Disable(int iAdapterIndex,
                                                DI_CWDDE_DisplayGridRequest SLSMapRequest);

///
/// Validate the list of the SLS display configurations to determine if Bezel is supported or not.
///
/// \platform
/// \ALL
///
/// \param[in]  iAdapterIndex		 The ADL index handle of the desired adapter.
/// \param[in]  iNumberOfTarget	     The number of targets in the grid
/// \param[in]  lpBezelRequest		 The target list
/// \param[out] lpBezelSupport	     The npointer indicating whether Bezel is supported for this target list
/// \param[out] lpOverlapSupport	 The npointer indicating whether Overlap is supported for this target list
///
/// \return ADL_OK if the call succeeded, else error.
int HIDDEN Pack_DI_Display_BezelSupported_Validate(int iAdapterIndex,
                                                   int iNumberOfTarget,
                                                   DI_CWDDE_BezelRequest* lpBezelRequest,
                                                   int* lpBezelSupport,
                                                   int* lpOverlapSupport);

///
/// Set SLS Bezel Offsets for each display index and corresponding controller which is being mapped to the indicated
///
/// \platform
/// \ALL
///
/// \param[in]  iAdapterIndex		 The ADL index handle of the desired adapter.
/// \param[in]  iNumberOfTarget	     The number of targets in the grid
/// \param[in]  lpBezelRequest		 The target list
/// \param[out] lpBezelSupport	     The npointer indicating whether Bezel is supported for this target list
///
/// \return ADL_OK if the call succeeded, else error.
int HIDDEN Pack_DI_Display_BezelOffset_Set(int iAdapterIndex,
                                           int iNumberOfTarget,
                                           DI_CWDDE_SetBezelRequest* lpSetBezelRequest );

///
/// Set SLS Overlap Offsets for each display index and corresponding controller which is being mapped to the indicated
///
/// \platform
/// \ALL
///
/// \param[in]  iAdapterIndex		  The ADL index handle of the desired adapter.
/// \param[in]  iNumOverlappedModes   The no. of overlapped modes defined. Each such mode refers to a set of targets in the array of targets
/// \param[in]  iNumTargetOffsets	  The no. of targets in the list of targets
/// \param[in]  lpSetOverlapRequest	  The target list
///
/// \return ADL_OK if the call succeeded, else error.
int HIDDEN Pack_DI_Display_OverlapOffset_Set(int iAdapterIndex,
                                             int iNumOverlappedModes,
                                             int iNumTargetOffsets,
                                             DI_CWDDE_SetOverlapRequest* lpSetOverlapRequest );

///
/// Sets the flag in overlap request to inform the driver whether overlap adjustment has begun or done.
///
/// \platform
/// \ALL
///
/// \param[in]  iAdapterIndex		  The ADL index handle of the desired adapter.
/// \param[in]  lpSetOverlapRequest	  Pointer indicating the adjustment flag for overlap
///
/// \return ADL_OK if the call succeeded, else error.
int HIDDEN Pack_DI_Display_Overlap_NotifyAdjustment(int iAdapterIndex,
                                            DI_CWDDE_SetOverlapRequest* lpSetOverlapRequest);

///
/// Modify SLS Bezel Offsets for each display index and corresponding controller which is being mapped to the indicated
///
/// \platform
/// \ALL
///
/// \param[in]  iAdapterIndex		 The ADL index handle of the desired adapter.
/// \param[in]  iNumberOfTarget	     The number of targets in the grid
/// \param[in]  lpBezelRequest		 The target list
/// \param[out] lpBezelSupport	     The npointer indicating whether Bezel is supported for this target list
///
/// \return ADL_OK if the call succeeded, else error.
int HIDDEN Pack_DI_Display_BezelOffset_Modify(int iAdapterIndex,
                                              int iNumberOfTarget,
                                              DI_CWDDE_ModifyBezelRequest* lpModifyBezelRequest );

///
/// This function implements the DI call to get a SLS grid index based on a list of targets
///
/// \platform
/// \ALL
///
/// \param[in]  iAdapterIndex		 The ADL index handle of the desired adapter.
/// \param[in]  iNumberOfTarget	     The number of targets in the grid
/// \param[in]  displayGridIdRequest The target list
/// \param[out] lpSLSMapGridID	     The npointer of grid index
///
/// \return ADL_OK if the call succeeded, else error.
int HIDDEN Pack_DI_Display_SLSMapIndex_Get(int iAdapterIndex,
                                           int iNumberOfTarget,
                                           DI_CWDDE_DisplayGridIdRequest*  lpDisplayGridIdRequest,
                                           int* lpSLSMapGridID);


///
/// This function implements the DI call to get a SLS grid index based on a list of targets
///
/// \platform
/// \ALL
///
/// \param[in]  iAdapterIndex		 The ADL index handle of the desired adapter.
/// \param[in]  iNumberOfTarget	     The number of targets in the grid
/// \param[in]  lpDisplayTargetRequest The target list
/// \param[out] lpPreferredMode	     The pointer of preferred mode
///
/// \return ADL_OK if the call succeeded, else error.
int HIDDEN Pack_DI_Display_PreferredMode_Get(int iAdapterIndex, int iNumberOfTarget, DI_CWDDE_PreferredModeRequest*  lpDisplayTargetRequest, DI_PreferredMode* lpPreferredMode);

///
/// This function implements the DI call to rearrange the targets in the SLS grid
///
/// \platform
/// \ALL
///
/// \param[in]  iAdapterIndex		       The ADL index handle of the desired adapter.
/// \param[in]  iNumberOfTarget	           The number of targets in the grid
/// \param[in]  rearrangeDisplayGridReques The target list in the grid
///
/// \return ADL_OK if the call succeeded, else error.
int HIDDEN Pack_DI_Display_SLSMapRearrangeDisplay_Set(int iAdapterIndex,
                                                      int iNumberOfTarget,
                                                      DI_CWDDE_RearrangeDisplayGridRequest*  lpRearrangeDisplayGridRequest );

///
/// This function implements the CI call to upadet vire port afer SLS arrangement
///
/// \platform
/// \ALL
///
/// \param[in]  iAdapterIndex		       The ADL index handle of the desired adapter.
/// \param[in]  iSourceId		           The source ID of the desired adapter.
///
/// \return ADL_OK if the call succeeded, else error.
int HIDDEN Pack_CI_ViewPort_Update(int iAdapterIndex, int iSourceId);

///
/// This function implements the CI call to retrieve FireStreamInfo
///
/// \platform
/// \ALL
///
/// \param[in]  iAdapterIndex		       The ADL index handle of the desired adapter.
///
/// \return ADL_OK if the call succeeded, else error.
int HIDDEN Pack_CI_FireStream_Info_Query(int iAdapter, FIRESTREAM_QUERY *firestreamQuery);


///
/// This function implements the DI call to rearrange the targets in the SLS grid
///
/// \platform
/// \ALL
///
/// \param[in]  iAdapterIndex		    The ADL index handle of the desired adapter.
/// \param[in]  iNumberOfTarget	        The number of targets in the grid
/// \param[in]  lpAddDisplayGridRequest  The pointer of the target list in the grid
/// \param[out] lpDisplayGridOutput     The poiter of new created grid index
///
/// \return ADL_OK if the call succeeded, else error.
int HIDDEN Pack_DI_Display_SLSMap_Create(int iAdapterIndex,
                                         int iNumberOfTarget,
                                         DI_CWDDE_AddDisplayGridRequest*  lpAddDisplayGridRequest,
                                         DI_DisplayGridOutput* lpDisplayGridOutput);



///
/// This function implements the DI call to get target list for given grid index
///
/// \platform
/// \ALL
///
/// \param[in]  iAdapterIndex		The ADL index handle of the desired adapter.
/// \param[in]  displayGridRequest	The grid index
/// \param[out] lpDisplayGrid       The pointer of display grid
///
/// \return ADL_OK if the call succeeded, else error.
int HIDDEN Pack_DI_Display_SLSMapGridInfo_Get(int iAdapterIndex,
                                              DI_CWDDE_DisplayGridRequest displayGridRequest,
                                              DI_DisplayGrid * lpDisplayGrid);



///
/// This function implements the DI call to get an SLS tahet view and mode view info
///
/// \platform
/// \ALL
///
/// \param[in]  iAdapterIndex		The ADL index handle of the desired adapter.
/// \param[in]  displayGridRequest	A data structure contains grid index
/// \param[in]  iNumTargets         The number of targets
/// \param[in]  iNumStandardMode    The number of standard mode
/// \param[in]  iNumBezelMode       The number of bezel mode
/// \param[in]  iNumTransientMode   The number of transient mode
/// \param[out] lpGridTargetInfo    The poidter of the grid target info
/// \param[out] lpTargetView        The pointer of target view
/// \param[out] lpNativeMod         The pointer of native mode
/// \param[out] lpBezelMode,        The pointer of bezel mode
/// \param[out] lpTransientMode     The pointer of transient mode
///
/// \return ADL_OK if the call succeeded, else error.
int HIDDEN Pack_DI_Display_SLSMapGridTargetInfoInfo_Get(int iAdapterIndex,
                                                        DI_CWDDE_DisplayGridRequest displayGridRequest,
                                                        int iNumTargets,
                                                        int iNumStandardMode,
                                                        int iNumBezelMode,
                                                        int iNumTransientMode,
                                                        DI_GridTargetInfo* lpGridTargetInfo,
                                                        DI_TargetView*	lpTargetView,
                                                        DI_ModeViews*	lpNativeMode,
                                                        DI_ModeViews*	lpBezelMode,
                                                        DI_ModeViews*	lpTransientMode);



///
/// \brief Function to get Pixel Clock Capabilities info
///
/// This function implements the DI call CWDDEDI_DisplayGetPixelClockCap
///
/// \platform
/// \ALL
///
/// \param[in]  iAdapterIndex	The ADL index handle of the desired adapter.
/// \param[in]  iDisplayIndex		The desired display index.
/// \param[out] lpoutputdata		The pointer to structure storing the retrieved Pixel Clock Capabilities information.
///
/// \return ADL_OK if the information were fetched correctly, else ADL_ERR.
int HIDDEN Pack_DI_Display_PixelClockCaps_Get( int iAdapterIndex, int iDisplayIndex,
                                              DI_PIXEL_CLOCK_CAP_OUT *lpoutputdata );

///
/// \brief Function to get the Current Pixel Clock
///
/// This function implements the DI call CWDDEDI_DisplayGetCurrentPixelClock
///
/// \platform
/// \ALL
///
/// \param[in]  iAdapterIndex	The ADL index handle of the desired adapter.
/// \param[in]  iDisplayIndex		The desired display index.
/// \param[out] lpoutputdata		The pointer to structure storing the Current Pixel Clock information.
///
/// \return ADL_OK if the information were fetched correctly, else ADL_ERR.
int HIDDEN Pack_DI_Display_CurrentPixelClock_Get( int iAdapterIndex, int iDisplayIndex,
                                                 DI_CURRENT_PIXEL_CLOCK_OUT *lpoutputdata );

///
/// \brief Function to set  the Pixel Clock Allowable Range
///
/// This function implements the DI call CWDDEDI_DisplaySetPixelClockAllowableRange
///
/// \platform
/// \ALL
///
/// \param[in]  iAdapterIndex	The ADL index handle of the desired adapter.
/// \param[in]  iDisplayIndex		The desired display index.
/// \param[out] lpinputdata		The pointer to structure with Pixel Clock Allowable Range Info.
///
/// \return ADL_OK if the information were fetched correctly, else ADL_ERR.
int HIDDEN Pack_DI_Display_PixelClockAllowableRange_Set( int iAdapterIndex, int iDisplayIndex,
                                                        DI_PIXEL_CLOCK_ALLOWABLE_RANGE_IN *lpinputdata );

///
/// \brief Function to query display target is local or remote display target
///
/// This function implements the DI call CWDDEDI_AdapterQueryCrossDisplayTarget
///
/// \platform
/// \Win7 only
///
/// \param[in]  displayTarget	The input display target.
/// \param[out] lpOutputData	The pointer to structure with CROSSDISPLAY target Info.
///
/// \return ADL_OK if the information were fetched correctly, else ADL_ERR.
int HIDDEN Pack_DI_AdapterQueryCrossDisplayTarget(int iAdapterIndex, DI_QUERY_CROSSDISPLAYTARGET_IN displayTarget, DI_QUERY_CROSSDISPLAYTARGET_OUT *lpOutputData);

///
/// \brief Function to get the graphics platform device information of of an adapter.
///
/// This function implements the KMD Escape call LHESCAPE_UMDKMDIF_COMMAND_GETPLATFORMGRAPHICSDEVICECONFIGURATION
///
/// \platform
/// \Win7
///
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[out]  lpGraphicsPlatformDeviceConfigInfo The KMD_GET_PLATFORM_GRAPHICS_DEVICE_CONFIGURATION_OUTPUT of the desired adapter.
///
/// \return ADL_OK if the information was set correctly, else ADL_ERR.
int HIDDEN Pack_KMD_CrossDisplay_GraphicsPlatformDeviceConfigInfo_Get(int iAdapterIndex, KMD_GET_PLATFORM_GRAPHICS_DEVICE_CONFIGURATION_OUTPUT *lpGraphicsPlatformDeviceConfigInfo);


///
/// \brief Function to query display MST info
///
/// This function implements the DI call CWDDEDI_DisplayGetMstSinkInfo
///
/// \platform
/// \ALL
///
/// \param[in]  iAdapterIndex	The Adapter Index.
/// \param[in]  iDisplayIndex	The Display Index.
/// \param[out] di_MstSinkInfo	The pointer to structure with retrieved DI_MST_SINK_INFO Info.
///
/// \return ADL_OK if the information were fetched correctly, else ADL_ERR.
int HIDDEN Pack_DI_DisplayGetMstSinkInfo_Get(int iAdapterIndex, int iDisplayIndex, DI_MST_SINK_INFO *di_MstSinkInfo );

///
/// \brief Function to obtain the VariBright values from the driver
///
/// This function implements the PM call CWDDEPM_GetVBLevel
///
/// \platform
/// \ALL
///
/// \param[in]  The ADL index handle of the desired adapter.
/// \param[out] VBLevel	The pointer to ADLVariBrightLevel structure
///
/// \return ADL_OK if the information were fetched correctly, else ADL_ERR.
int HIDDEN Pack_PM_VaryBright_Get( int iAdapterIndex, CWDDEPM_GETVARIBRIGHTLEVEL * lpVBLevel );


///
/// \brief Function to set the VariBright values from the driver
///
/// This function implements the PM call CWDDEPM_SetVBLevel
///
/// \platform
/// \ALL
///
/// \param[in]  The ADL index handle of the desired adapter.
/// \param[out] VBLevel	The pointer to ADLVariBrightLevel structure
///
/// \return ADL_OK if the information was set correctly, else ADL_ERR.
int HIDDEN Pack_PM_VaryBright_Set( int iAdapterIndex,  CWDDEPM_SETVARIBRIGHTLEVEL * lpVBLevel );

///
/// \brief Function to Get the Display SplitDisplay Mode from the driver
///
/// This function implements the KMD Escape call LHESCAPE_UMDKMDIF_GET_SPLITDISPLAY_MODE
///
/// \platform
/// \Win7
///
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[in]  splitDisplayIn The SHARED_GET_SPLIT_DISPLAY_MODE_INPUT of the desired adapter.
/// \param[out] lpOutputData The pointer to SHARED_GET_SPLIT_DISPLAY_MODE_OUTPUT structure
///
/// \return ADL_OK if the information was set correctly, else ADL_ERR.
int HIDDEN Pack_KMD_Display_SplitDisplay_Mode_Get(int iAdapterIndex, SHARED_GET_SPLIT_DISPLAY_MODE_INPUT splitDisplayIn, SHARED_GET_SPLIT_DISPLAY_MODE_OUTPUT *lpOutputData);

///
/// \brief Function to Set the Display SplitDisplay Mode to the driver
///
/// This function implements the KMD Escape call LHESCAPE_UMDKMDIF_SET_SPLITDISPLAY_MODE
///
/// \platform
/// \Win7
///
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[in]  splitDisplayIn The SHARED_SET_SPLIT_DISPLAY_MODE_INPUT of the desired adapter.
///
/// \return ADL_OK if the information was set correctly, else ADL_ERR.
int HIDDEN Pack_KMD_Display_SplitDisplay_Mode_Set(int iAdapterIndex, SHARED_SET_SPLIT_DISPLAY_MODE_INPUT splitDisplayIn);


#ifdef FID10247_
///
/// This function implements the DI call CWDDEDI_GetAdapterPathInfo to obtain the adapter Path info.
///
/// \platform
/// \ALL
///
/// \param[in]  iAdapterIndex		The ADL index handle of the desired adapter.
/// \param[out] lpAdapterPathInfo	The pointer to the adapter Path info
///
/// \return \ref ADL_OK if the call succeeded, else error.
int HIDDEN Pack_DI_AdapterPathInfo_Get (int iAdapterIndex, DI_AdapterPathInfo* lpAdapterPathInfo);

///
/// This function implements the DI call CWDDEDI_GetAdapterSlsPathInfo to obtain the adapter SLS Path info.
///
/// \platform
/// \ALL
///
/// \param[in]  iAdapterIndex		The ADL index handle of the desired adapter.
/// \param[out] lpAdapterSlsPathInfo	The pointer to the adapter SLS Path info
///
/// \return \ref ADL_OK if the call succeeded, else error.
int HIDDEN Pack_DI_AdapterSlsPathInfo_Get (int iAdapterIndex, DI_AdapterSlsPathInfo* lpAdapterSlsPathInfo);

#endif // #ifdef FID10247_


///
/// \brief Function to get power express config caps and state
///
/// This function uses a PX escape call CWDDEPX_PXGetConfig to get PowerExpress config info
/// \platform
/// \Win7
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[out] lpPXConfig The pointer to the PX config output.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
int HIDDEN Pack_PowerXpress_Config_Get(int iAdapterIndex, CWDDEPX_GET_CONFIG_OUTPUT *lpPXConfig);


///
/// \brief Function to set power express scheme
///
/// This function uses a PX escape call CWDDEPX_PXSetScheme to set the PowerExpress scheme
/// \platform
/// \Win7
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[in]  newScheme The new scheme to be set
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
int HIDDEN Pack_PowerXpress_Config_Set(int iAdapterIndex, PX_SCHEME newScheme);


///
/// \brief Function to get current extended battery mode state
///
/// This function uses a PX escape call CWDDEPX_PXControl to get current Extended Battery Mode state
/// \platform
/// \Win7
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[out] lpbEnable The current extended battery mode state to be get
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
int HIDDEN Pack_PowerXpress_ExtendedBatteryMode_Get(int iAdapterIndex, int *lpbEnable);


///
/// \brief Function to set extended battery mode state
///
/// This function uses a PX escape call CWDDEPX_PXControl to set the Extended Battery Mode state
/// \platform
/// \Win7
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[in]  bEnable The extended battery mode state to be set
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
int HIDDEN Pack_PowerXpress_ExtendedBatteryMode_Set(int iAdapterIndex, int bEnable);


///
/// \brief Function to get the list of currently running applications
///
/// This function uses a PX escape call CWDDEPX_PXGetRunningAppList to get the list of currently running apps.
/// \platform
/// \Win7
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[out]  lpAppList The pointer to the running app list output.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
int HIDDEN Pack_PowerXpress_RunningAppList_Get(int iAdapterIndex, CWDDEPX_GET_RUNNING_APP_LIST_OUTPUT *lpAppList);

///
/// \brief Function to get the list of currently running applications and websites that display video using MMD GPU and have MMD application profile assigned
///
/// This function uses a PX escape call CWDDEPX_PXGetRunningAppListEx to get the list of applications and web sites.
/// \platform
/// \Win7
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[out]  lpAppList List of currently running applications and websites that display video using MMD GPU and have MMD application profile assigned. Note the buffer has to be freed.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
int HIDDEN Pack_PowerXpress_MMDProfiledAppList_Get(int iAdapterIndex, CWDDEPX_GET_RUNNING_APP_LIST_EX_OUTPUT **lpAppList);

///
/// \brief Function to get PX removable devices
///
/// This function uses a PX escape call CWDDEPX_PXGetRemovableDeviceList to get removable devices
/// \platform
/// \Win7
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[out] lpRemovableDeviceList The pointer to a variable that contains removable device info
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
int HIDDEN Pack_PowerXpress_RemovableDevice_Get(int iAdapterIndex, CWDDEPX_GET_REMOVABLE_DEVICE_LIST_OUTPUT *lpRemovableDeviceList);


///
/// \brief Function to get SLS Middle mode support info
///
/// This function uses a SLS Middle mode escape call CWDDE_QueryMiddleModeSupport to get SLS Middle mode support info
/// \platform
/// \Win7
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[in]  displayGridRequest A data structure contains grid index
/// \param[out] lpDIQueryMiddleModeSupport The pointer to the DI_CWDDE_QueryMiddleModeSupport output
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
int HIDDEN Pack_DI_Display_SLSMiddleModeSupport_Get (int iAdapterIndex, DI_CWDDE_DisplayGridRequest displayGridRequest, DI_CWDDE_QueryMiddleModeSupport *lpDIQueryMiddleModeSupport);

///
/// \brief Function to get SLS default, current and support middle modes
///
/// This function uses a SLS Middle mode escape call CWDDE_GetMiddleMode to get SLS default, current and support middle modes
/// \platform
/// \Win7
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[in]  displayGridRequest A data structure contains grid index
/// \param[in]  iNumMiddleModes The number of Middle modes
/// \param[out] lpDIGetMiddleModes The pointer to the DI_CWDDE_MiddleModes output
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
int HIDDEN Pack_DI_Display_SLSMiddleMode_Get (int iAdapterIndex, DI_CWDDE_DisplayGridRequest displayGridRequest, int iNumMiddleModes, DI_CWDDE_MiddleModes *lpDIGetMiddleModes);

///
/// \brief Function to set SLS current middle mode
///
/// This function uses a SLS Middle mode escape call CWDDE_SetMiddleMode to set SLS current middle mode
/// \platform
/// \Win7
/// \param[in] iAdapterIndex The ADL index handle of the desired adapter.
/// \param[in] diSetMiddleMode The DI_CWDDE_SetMiddleMode input
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
/// \remarks if the return value is CWDDE_OK_MODE_SET_NEEDED, ADL needs to set mode and re-enumerate.
int HIDDEN Pack_DI_Display_SLSMiddleMode_Set(int iAdapterIndex, DI_CWDDE_SetMiddleMode diSetMiddleMode);

///
/// \brief Function to get Overdrive 6 capabilities
///
/// This function implements a PM call CWDDEPM_OD6_GetCapabilities
/// \platform
/// \ALL
/// \param[in] iAdapterIndex The ADL index handle of the desired adapter.
/// \param[out] pCapabilities Pointer to the Overdrive 6 capabilities structure.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
int HIDDEN Pack_PM_OD6_Capabilities_Get(int iAdapterIndex, CWDDEPM_OD6_CAPABILITIES *pCapabilities);

///
/// \brief Function to get Overdrive 6 performance level
///
/// This function implements a PM call CWDDEPM_OD6_GetStateInfo
/// \platform
/// \ALL
/// \param[in] iAdapterIndex The ADL index handle of the desired adapter.
/// \param[out] lpStateInfo Pointer to the Overdrive 6 state info structure.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
int HIDDEN Pack_PM_OD6_StateInfo_Get(int iAdapterIndex, CWDDEPM_OD6_GETSTATEINFO *lpGetState, CWDDEPM_OD6_STATEINFO *lpStateInfo);

///
/// \brief Function to set Overdrive 6 performance level
///
/// This function implements a PM call CWDDEPM_OD6_SetState
/// \platform
/// \ALL
/// \param[in] iAdapterIndex The ADL index handle of the desired adapter.
/// \param[in] lpState Pointer to the Overdrive 6 performance level to be set.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
int HIDDEN Pack_PM_OD6_State_Set(int iAdapterIndex, CWDDEPM_OD6_SETSTATE *lpState);

///
/// \brief Function to reset Overdrive 6 performance level back to default
///
/// This function implements a PM call CWDDEPM_OD6_ResetState
/// \platform
/// \ALL
/// \param[in] iAdapterIndex The ADL index handle of the desired adapter.
/// \param[in] lpState Pointer to the state to be reset.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
int HIDDEN Pack_PM_OD6_State_Reset(int iAdapterIndex, CWDDEPM_OD6_RESETSTATE *lpState);

///
/// \brief Function to get current Overdrive 6 status
///
/// This function implements a PM call CWDDEPM_OD6_GetCurrentStatus
/// \platform
/// \ALL
/// \param[in] iAdapterIndex The ADL index handle of the desired adapter.
/// \param[out] lpStatus Pointer to the retrieved status information.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
int HIDDEN Pack_PM_OD6_CurrentStatus_Get(int iAdapterIndex, CWDDEPM_OD6_CURRENTSTATUS *lpStatus);

///
/// \brief Function to get Overdrive 6 thermal controller capabilities
///
/// This function implements a PM call CWDDEPM_OD6_GetThermalControllerCaps
/// \platform
/// \ALL
/// \param[in] iAdapterIndex The ADL index handle of the desired adapter.
/// \param[out] lpThermalControllerInfo Pointer to the retrieved capabilities information.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
int HIDDEN Pack_PM_OD6_ThermalControllerCaps_Get(int iAdapterIndex, CWDDEPM_OD6_THERMALCONTROLLERCAPS *lpThermalControllerInfo);

///
/// \brief int Function to get Overdrive 6 temperature
///
/// This function implements a PM call CWDDEPM_OD6_GetTemperature
/// \platform
/// \ALL
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[out] lpTemperature The pointer to the structure storing the retrieved temperature information.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
int HIDDEN Pack_PM_OD6_Temperature_Get(int iAdapterIndex, CWDDEPM_OD6_TEMPERATURE *lpTemperature);

///
/// \brief Function to get the fan speed for Overdrive 6
///
/// This function implements a PM call CWDDEPM_OD6_GetFanSpeed
/// \platform
/// \ALL
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[out] lpFanSpeedValue The pointer to the structure storing the retrieved fan speed information.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
int HIDDEN Pack_PM_OD6_FanSpeed_Get(int iAdapterIndex, CWDDEPM_OD6_FANSPEED *lpFanSpeedValue);

///
/// \brief Function to set the fan speed for Overdrive 6
///
/// This function implements a PM call CWDDEPM_OD6_SetFanSpeed
/// \platform
/// \ALL
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[in]  lpFanSpeedSetting The pointer to the structure with fan speed settings
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
int HIDDEN Pack_PM_OD6_FanSpeed_Set(int iAdapterIndex, CWDDEPM_OD6_SETFANSPEED *lpFanSpeedSetting);

///
/// \brief Function to reset the fan speed for Overdrive 6
///
/// This function implements a PM call CWDDEPM_OD6_ResetFanSpeed
/// \platform
/// \ALL
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
int HIDDEN Pack_PM_OD6_FanSpeed_Reset(int iAdapterIndex);

///
/// \brief Function to get the Power Control parameters for Overdrive 6
///
/// This function implements a PM call CWDDEPM_OD6_GetPowerControlParameters
/// \platform
/// \ALL
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[out] lpPCParameters The pointer to the structure storing the retrieved OD parameters.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
int HIDDEN Pack_PM_OD6_PowerControlParameters_Get( int iAdapterIndex,  CWDDEPM_OD6_POWERCONTROLPARAMETERS *lpPCParameters );

///
/// \brief Function to get the current Power Control value for Overdrive 6
///
/// This function implements a PM call CWDDEPM_OD6_GetPowerControlSetting
/// \platform
/// \ALL
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[out] lpPCLevel The pointer to the structure storing the retrieved OD parameters.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
int HIDDEN Pack_PM_OD6_PowerControl_Get( int iAdapterIndex,  CWDDEPM_OD6_POWERCONTROLSETTING *lpPCLevel );

///
/// \brief Function to set the Power Control value for Overdrive 6
///
/// This function implements a PM call CWDDEPM_OD6_SetPowerControlSetting
/// \platform
/// \ALL
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[in]  lpPCLevel The structure to set OD Power Control level information.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
int HIDDEN Pack_PM_OD6_PowerControl_Set( int iAdapterIndex,  CWDDEPM_OD6_POWERCONTROLSETTING *lpPCLevel );

///
/// \brief Function to query if the virtual topology setting has been done
///
/// This function implements a DI call CWDDEDI_QueryDisplayReenumStatus
/// \platform
/// \ALL
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[in]  lpRenumCompleted Pointer to an integer that indicate if the virtual topology has been completed.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
int HIDDEN Pack_DI_Display_DisplayReenumStatus_Query(int iAdapterIndex, int* lpRenumCompleted);

///
/// \brief Function to set FreeSync related setting
///
/// This function implements a DI call CWDDEDI_DisplayFreeSyncSet
/// \platform
/// \ALL
/// \param[in]  iAdapterIndex       The ADL index handle of the desired adapter.
/// \param[in]  iDisplayIndex       The desired display index.
/// \param[in]  di_FreeSyncSetData  Pointer to a data structure that contains the new FreeSync setting.
/// \return If the function succeeds, the return value is \ref ADL_OK, or an ADL error code otherwise. \ref define_adl_results
int HIDDEN Pack_DI_Display_FreeSync_Set(int iAdapterIndex, int iDisplayIndex, DI_DISPLAYFREESYNC_SET_DATA *di_FreeSyncSetData);

///
/// \brief Function to query if the virtual topology setting has been done
///
/// This function implements a DI call CWDDEDI_DisplayFreeSyncGetCaps
/// \platform
/// \ALL
/// \param[in]  iAdapterIndex       The ADL index handle of the desired adapter.
/// \param[in]  iDisplayIndex       The desired display index.
/// \param[out] di_FreeSyncCaps     The pointer to the structure storing the retrieved FreeSync capabilities of the displa requested.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
int HIDDEN Pack_DI_Display_FreeSync_Cap(int iAdapterIndex, int iDisplayIndex, DI_DISPLAYFREESYNC_CAPS *di_FreeSyncCaps);

/// \brief  This function gets information related to PowerXpress Long Idle Detect feature.
///
/// Retrieves info about support, default value, current state of PowerXpress Long Idle Detect feature using KMD LHESCAPE_UMDKMDIF_GET_SET_PX_FEATURES escape.
/// \platform
/// \WIN7 and \WIN8
/// \param[in]   iAdapterIndex The ADL index handle of the desired adapter.
/// \param[out]  lpSupported Returns driver support for PowerXpress Long Idle Detect feature. Not-zero value indicates that the driver supports the feature. 0  driver does not support the feature. Client can pass NULL to indicate that it is not interested in the supported value.
/// \param[out]  lpDefault Returns default state of PowerXpress Long Idle Detect feature. Not-zero value indicates that the driver enables the Long Idle Detect by default. 0 indicates that the feature is disabled by the driver by default. Client can pass NULL to indicate that it is not interested in the default value.
/// \param[out]  lpEnabled Returns current state of PowerXpress Long Idle Detect feature. Not-zero value indicates that Long Idle Detect is currently enabled in the driver. 0 indicates that it is disabled. Not NULL pointer must be passed by client.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
int HIDDEN Pack_PowerXpress_LongIdleDetect_Get(int iAdapterIndex, int* lpSupported, int* lpDefault, int* lpEnabled);

/// \brief  This function enables / disables PowerXpress Long Idle Detect feature.
///
/// Sets current states of PowerXpress Long Idle Detect feature. It is assumed that the client first calls to ADL_PowerXpress_LongIdleDetect_Get to verify that the feature is supportd.
/// \platform
/// \WIN7 and \WIN8
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[in]  iEnabled New state of PowerXpress Long Idle Detect feature. Pass not-zero value to enable the feature. Pass 0 to disable the feature.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
int HIDDEN Pack_PowerXpress_LongIdleDetect_Set(int iAdapterIndex, int iEnabled);

///
/// \brief Function to retrieve LocalDisplay support settings.
///
/// This function implements a DI call to retrieve LocalDisplay support settings.
/// \platform
/// \ALL
/// \param[in]  iAdapterIndex   The ADL index handle of the desired adapter.
/// \param[in]  ldaInput        The desired input buffer.
/// \param[out] ldaOutput       The pointer to the output buffer.
/// \return If the function succeeds, the return value is \ref ADL_OK, or an ADL error code otherwise.  \ref define_adl_results
int HIDDEN Pack_DI_LocalDisplayConfig_Get(int iAdapterIndex, UMDKMDIF_GET_LOCAL_DISPLAY_CONFIG_INPUT *ldaInput, UMDKMDIF_GET_LOCAL_DISPLAY_CONFIG_OUTPUT *ldaOutput);

///
/// \brief Function to set LocalDisplay support settings.
///
/// This function implements a DI call to set LocalDisplay support settings.
/// \platform
/// \ALL
/// \param[in]  iAdapterIndex   The ADL index handle of the desired adapter.
/// \param[in]  ldaInput        The desired input buffer.
/// \param[out] ldaOutput       The pointer to the output buffer.
/// \return If the function succeeds, the return value is \ref ADL_OK, or an ADL error code otherwise.  \ref define_adl_results
int HIDDEN Pack_DI_LocalDisplayConfig_Set(int iAdapterIndex, UMDKMDIF_SET_LOCAL_DISPLAY_CONFIG_INPUT *ldaInput, UMDKMDIF_SET_LOCAL_DISPLAY_CONFIG_OUTPUT *ldaOutput);

/// \brief  This function retrieves display connection data
///
/// This function retrieve display connection data from a device port of a GPU.  Data can be emulated, real or current.  Used for EDID emulation.
/// \platform
/// \ALL
/// \param[in]  iAdapter 				The ADL index handle of the desired adapter.
/// \param[in]  diConnectionDataQuery 	Input data for display connection data query, emulated, real or current data can be quried
/// \param[out] lpDiConnectionData    	Returned display connection data
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
int HIDDEN Pack_DI_ConnectionData_Get(int iAdapter, DI_CONNECTION_DATA_QUERY diConnectionDataQuery, DI_CONNECTION_DATA *lpDiConnectionData);

/// \brief  This function set display connection data
///
/// This function emulated connection data on a device port of a GPU. Used for EDID emulation.
/// \platform
/// \ALL
/// \param[in]  iAdapter 		The ADL index handle of the desired adapter.
/// \param[in]  emulatedData 	Emulated data to be applied
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
int HIDDEN Pack_DI_EmulatedData_Set(int iAdapter,const DI_SET_EMULATION_DATA &emulatedData);

/// \brief  This function remove emulated data from a device port
///
/// Remove connection emulation from a device port of a GPU. Used for EDID emulation.
/// \platform
/// \ALL
/// \param[in]  iAdapter The ADL index handle of the desired adapter.
/// \param[in]  devicePort information identifying device port to remove emulated data
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
int HIDDEN Pack_DI_EmulatedData_Remove(int iAdapter, DI_DEVICE_PORT devicePort);

/// \brief  This function gets the board layout information
///
/// gets board layout information including slot information & connectors information
/// \platform
/// \ALL
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[OUT]  lpDiBoardLayoutInfo The pointer to the DI_BOARD_LAYOUT_INFO output
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
int HIDDEN Pack_DI_Adapter_BoardLayout_Get(int iAdapterIndex, DI_BOARD_LAYOUT_INFO *lpDiBoardLayoutInfo);

/// \brief  This function gets the Emulation status to the given port
///
/// gets current states of EDID Emulation for specified port
/// \platform
/// \ALL
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[in]  diDevicePort device port information.
/// \param[OUT]  lpDISupportedConncetions The pointer to the DI_SUPPORTED_CONNECTIONS output
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
int HIDDEN Pack_DI_Adapter_SupportedConnections_Get(int iAdapterIndex, DI_DEVICE_PORT diDevicePort, DI_SUPPORTED_CONNECTIONS *lpDISupportedConncetions);

/// \brief  This function gets the Connection status of the given port
///
/// gets current states of Connection for specified port
/// \platform
/// \ALL
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[in]  diDevicePort device port information.
/// \param[OUT]  lpDIConnectionState The pointer to the DI_CONNECTION_STATE output
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
int HIDDEN Pack_DI_Adapter_ConnectionState_Get(int iAdapterIndex, DI_DEVICE_PORT diDevicePort, DI_CONNECTION_STATE *lpDIConnectionState);

/// \brief  This function sets the Emulation mode to the given port
///
/// Sets current states of EDID Emulation for specified port
/// \platform
/// \ALL
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[in]  diSetEDIDEmulationMode current mode and device port information.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
int HIDDEN Pack_DI_Adapter_EmulationMode_Set(int iAdapterIndex, DI_SET_EDID_EMULATION_MODE diSetEDIDEmulationMode);

///
/// \brief Function to get current Power Control Mode state
///
/// This function uses a PX escape call CWDDEPX_PXControl to get current Power Control Mode state
/// \platform
/// \Win7 and Above
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.It accepts only DGPU adapter index as we need to make this GPU to power up or power down. Else, the call will fail.
/// \param[out] lpPowerControlState The current power state of the DGPU. 1 implies Power On and 0 implies Power Off
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
int HIDDEN Pack_PowerXpress_PowerControlMode_Get(int iAdapterIndex, int *lpPowerControlState);

///
/// \brief Function to set Power Control Mode state
///
/// This function uses a PX escape call CWDDEPX_PXControl to set the Power Control Mode state
/// \platform
/// \Win7 and Above
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.It accepts only DGPU adapter index as we need to make this GPU to power up or power down. Else, the call will fail.
/// \param[in]  powerControlState The Power state of the DGPU to set. 1 implies Power On and 0 implies Power Off
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
int HIDDEN Pack_PowerXpress_PowerControlMode_Set(int iAdapterIndex, int powerControlState);

/// \brief  This function gets voltage control parameters for SVI2 control feature
///
/// This function implements a PM call CWDDEPM_OD6_VOLTAGECONTROLPARAMETERS
/// \platform
/// \ALL
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[in]  lpVCParameters voltage control parameters information.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
int HIDDEN Pack_PM_OD6_VoltageControlParameters_Get(int iAdapterIndex, CWDDEPM_OD6_VOLTAGECONTROLPARAMETERS *lpVCParameters);

/// \brief  This function gets voltage control setting for SVI2 control feature
///
/// This function implements a PM call CWDDEPM_OD6_VOLTAGECONTROLSETTING
/// \platform
/// \ALL
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[in]  lpVCSetting voltage control settings information.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
int HIDDEN Pack_PM_OD6_VoltageControlSetting_Get(int iAdapterIndex, CWDDEPM_OD6_VOLTAGECONTROLSETTING *lpVCSetting);

/// \brief  This function sets voltage control parameters for SVI2 control feature
///
/// This function implements a PM call CWDDEPM_OD6_VOLTAGECONTROLSETTING
/// \platform
/// \ALL
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[in]  lpVCSetting voltage control setting to apply.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
int HIDDEN Pack_PM_OD6_VoltageControlSetting_Set(int iAdapterIndex, CWDDEPM_OD6_VOLTAGECONTROLSETTING *lpVCSetting);

///
/// \brief Function to get Overdrive 6 capabilities extension
///
/// This function implements a PM call CWDDEPM_OD6_GetCapabilitiesEx
/// \platform
/// \ALL
/// \param[in] iAdapterIndex The ADL index handle of the desired adapter.
/// \param[out] pCapabilities Pointer to the Overdrive 6 capabilities extension structure.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
int HIDDEN Pack_PM_OD6_CapabilitiesEx_Get(int iAdapterIndex, CWDDEPM_OD6_CAPABILITIES_EX *pCapabilities);

///
/// \brief Function to get Overdrive 6 performance level extension
///
/// This function implements a PM call CWDDEPM_OD6_GetStateEx
/// \platform
/// \ALL
/// \param[in] iAdapterIndex The ADL index handle of the desired adapter.
/// \param[in] lpGetState Pointer to the Overdrive 6 get state extension structure.
/// \param[out] lpStateInfo Pointer to the Overdrive 6 state extension info structure.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
int HIDDEN Pack_PM_OD6_StateEx_Get(int iAdapterIndex, CWDDEPM_OD6_GETSTATE_EX *lpGetState, CWDDEPM_OD6_STATE_EX *lpStateInfo);

///
/// \brief Function to set Overdrive 6 performance level extension
///
/// This function implements a PM call CWDDEPM_OD6_SetStateEx
/// \platform
/// \ALL
/// \param[in] iAdapterIndex The ADL index handle of the desired adapter.
/// \param[in] lpState Pointer to the Overdrive 6 performance level extension to be set.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
int HIDDEN Pack_PM_OD6_StateEx_Set(int iAdapterIndex, CWDDEPM_OD6_SETSTATE_EX *lpState);

///
/// \brief Function to get Overdrive 6 maximum recommended clock adjustment
///
/// This function implements a PM call CWDDEPM_OD6_GetMaxClockAdjust
/// \platform
/// \ALL
/// \param[in] iAdapterIndex The ADL index handle of the desired adapter.
/// \param[in] lpGetMaxClockAdjust Pointer to the Overdrive 6 get max clock adjust structure to be set.
/// \param[out] lpMaxClockAdjust Pointer to the Overdrive 6 max clock adjust structure.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
int HIDDEN Pack_PM_OD6_MaxClockAdjust_Get(int iAdapterIndex, CWDDEPM_OD6_GETMAXCLOCKADJUST *lpGetMaxClockAdjust, CWDDEPM_OD6_MAXCLOCKADJUST *lpMaxClockAdjust);

/// \brief  This function sets parameters for Thermal Limit Unlock control feature
///
/// This function implements a PM call CWDDEPM_OD6_SETTHERMLIMITUNLOCK
/// \platform
/// \ALL
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[in]  lpTLUSetting TLU setting to apply.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
int HIDDEN Pack_PM_OD6_ThermalLimitUnlock_Set(int iAdapterIndex, CWDDEPM_OD6_SETTHERMLIMITUNLOCK *lpTLUSetting);

/// \brief  This function sets parameters for Thermal Limit Unlock control feature
///
/// This function implements a PM call CWDDEPM_OD6_SETTHERMLIMITUNLOCK
/// \platform
/// \ALL
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[in]  lpTLUGetInput pointer to CWDDEPM_OD6_GETTHERMLIMITUNLOCK input data
/// \param[in]  lpTLUGetOutput pointer to CWDDEPM_OD6_THERMLIMITUNLOCK output data
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
int HIDDEN Pack_PM_OD6_ThermalLimitUnlock_Get(int iAdapterIndex, CWDDEPM_OD6_GETTHERMLIMITUNLOCK *lpTLUGetInput, CWDDEPM_OD6_THERMLIMITUNLOCK *lpTLUGetOutput);

/// \brief  This function gets temperature parameters for Fuzzy Fun Control feature
///
/// This function implements a PM call CWDDEPM_OD6_GetFFCTemperatureParameters
/// \platform
/// \ALL
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[in]  lpFFCTempParams pointer to CWDDEPM_OD6_FFCTEMPERATUREPARAMETERS
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
int HIDDEN Pack_PM_OD6_TargetOperatingTemperatureParameters_Get(int iAdapterIndex,  CWDDEPM_OD6_TARGETOPERATINGTEMPERATUREPARAMETERS *lpTargetOperatingTemperatureParams);

/// \brief  This function gets temperature settings for Fuzzy Fun Control feature
///
/// This function implements a PM call CWDDEPM_OD6_GetFFCTemperatureSetting
/// \platform
/// \ALL
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[in]  lpFFCTempParams pointer to CWDDEPM_OD6_FFCTEMPERATURESETTING
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
int HIDDEN Pack_PM_OD6_TargetOperatingTemperatureSetting_Get(int iAdapterIndex,  CWDDEPM_OD6_TARGETOPERATINGTEMPERATURESETTING *lpTargetOperatingTemperatureSetting);

/// \brief  This function sets new temperature settings(value) for Fuzzy Fun Control feature
///
/// This function implements a PM call CWDDEPM_OD6_SetFFCTemperatureSetting
/// \platform
/// \ALL
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[in]  lpFFCTempParams pointer to CWDDEPM_OD6_FFCTEMPERATURESETTING
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
int HIDDEN Pack_PM_OD6_TargetOperatingTemperatureSetting_Set(int iAdapterIndex,  CWDDEPM_OD6_TARGETOPERATINGTEMPERATURESETTING *lpTargetOperatingTemperatureSetting);

/// \brief  This function gets Fan PWM parameters for Fuzzy Fun Control feature
///
/// This function implements a PM call CWDDEPM_OD6_GetFFCFanPWMParameters
/// \platform
/// \ALL
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[in]  lpFFCFanPWMParams pointer to CWDDEPM_OD6_FFCFANPWMPARAMETERS
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
int HIDDEN Pack_PM_OD6_MaxFanPWMOutputParameters_Get(int iAdapterIndex,  CWDDEPM_OD6_MAXFANPWMOUTPUTPARAMETERS *lpMaxFanPwmOutputParams);

/// \brief  This function gets Fan PWM settings for Fuzzy Fun Control feature
///
/// This function implements a PM call CWDDEPM_OD6_GetFFCFanPWMSetting
/// \platform
/// \ALL
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[in]  lpFFCTempParams pointer to CWDDEPM_OD6_FFCFANPWMSETTING
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
int HIDDEN Pack_PM_OD6_MaxFanPWMOutputSetting_Get(int iAdapterIndex,  CWDDEPM_OD6_MAXFANPWMOUTPUTSETTING *lpMaxFanPwmOutputSetting);

/// \brief  This function sets new Fan PWM settings for Fuzzy Fun Control feature
///
/// This function implements a PM call CWDDEPM_OD6_SetFFCFanPWMSetting
/// \platform
/// \ALL
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[in]  lpFFCTempParams pointer to CWDDEPM_OD6_FFCFANPWMSETTING
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
int HIDDEN Pack_PM_OD6_MaxFanPWMOutputSetting_Set(int iAdapterIndex,  CWDDEPM_OD6_MAXFANPWMOUTPUTSETTING *lpMaxFanPwmOutputSetting);

///
/// \brief Function to Get FPS(Frames Per Second) Settings.
///
/// This function implements a PM call CWDDEPM_FPS_GetMonitorParameter.
/// \platform
/// \WIN
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[out] lpFPSSettingsStruct The pointer to the structure to get the PM FPS Feature Settings.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
int HIDDEN Pack_PM_FPS_Settings_Get(int iAdapterIndex, CWDDEPM_GETFPSMONITORPARAMETER_OUTPUT *lpFPSSettingsStruct);


///
/// \brief Function to Set FPS(Frames Per Second) Settings.
///
/// This function implements a PM call CWDDEPM_FPS_SetMonitorParameter.
/// \platform
/// \WIN
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[in]  lpFPSSettingsStruct The pointer to the structure to set the PM FPS Feature Settings.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
int HIDDEN Pack_PM_FPS_Settings_Set(int iAdapterIndex, CWDDEPM_SETFPSMONITORPARAMETER_INPUT *lpFPSSettingsStruct);

///
/// This function implements the DI call to if the virtual topology is needed based on a list of targets
///
/// \platform
/// \ALL
///
/// \param[in]  iAdapterIndex		 The ADL index handle of the desired adapter.
/// \param[in]  iNumberOfTarget	     The number of targets in the grid
/// \param[in]  lpSLSLayoutDescription The target list
/// \param[out] lpVirtualIsNeeded	     The pointer of the flag , which indicates if virtual topology is needed
///
/// \return ADL_OK if the call succeeded, else error.
int HIDDEN Pack_DI_Display_VirtualTopologyIsNeeded_Get(int iAdapterIndex, int iNumberOfTarget, DI_IsVirtualTopologyRequiredRequest*  lpSLSLayoutDescription, int* lpVirtualIsNeeded);

int HIDDEN Pack_DI_SourceSlsSupport_Get(int iAdapterIndex, DI_GetSlsSupportForSourceRequest request, DI_SOURCE_SLS_SUPPORT_FLAGS *sourceSlsSupportFlags);
int HIDDEN Pack_DI_NumAvailableSlsLayoutTypes_Get(int iAdapterIndex, int extraInputSize, DI_GetAvailableSlsLayoutTypesRequest *request, DI_GetNumAvailableSlsLayoutTypesResponse *response);
int HIDDEN Pack_DI_AvailableSlsLayoutTypes_Get(int iAdapterIndex, int extraInputSize, DI_GetAvailableSlsLayoutTypesRequest *request, DI_GetAvailableSlsLayoutTypesResponse *layouts);
int HIDDEN Pack_DI_ValidateSlsLayout(int iAdapterIndex, int extraInputSize, DI_ValidateSlsLayoutRequest *request, DI_SLS_LAYOUT_VALIDATION_FLAGS *flags);
int HIDDEN Pack_DI_PossibleSlsLayoutModes_Get(int iAdapterIndex, DI_GetPossibleSlsLayoutModesRequest request, DI_GetPossibleSlsLayoutModesResponse *response);
int HIDDEN Pack_DI_PossibleSlsLayoutModes_Set(int iAdapterIndex, DI_SetPossibleSlsLayoutModesRequest request);
int HIDDEN Pack_DI_CompatibleTargetsForSLS_Get(int iAdapterIndex, int extraInputSize, DI_GetCompatibleTargetsForSlsRequest *request, DI_GetCompatibleTargetsForSlsResponse *response);
int HIDDEN Pack_DI_RecommendSLSVtConfig(int iAdapterIndex, int extraInputSize, DI_RecommendSlsVtConfigRequest *request, DI_RecommendSlsVtConfigResponse *response);
int HIDDEN Pack_DI_SLSBuilderLayout_Add(int iAdapterIndex, int extraInputSize, DI_AddSlsBuilderLayoutRequest *request, unsigned int *LayoutID);
int HIDDEN Pack_DI_SLSBuilderActive_Notify(int iAdapterIndex);
int HIDDEN Pack_DI_SLSBuilderLayout_Update(int iAdapterIndex, int extraInputSize, DI_SetSlsCompositionRequest *request);
int HIDDEN Pack_DI_SLSBuilderLayout_Get(int iAdapterIndex, DI_GetSlsCompositionRequest request, DI_GetSlsCompositionResponse *response, int ouputSize);
int HIDDEN Pack_DI_MaxSlsLayoutSize_Get(int iAdapterIndex, DI_GetMaxSlsLayoutSizeRequest request, DI_GetMaxSlsLayoutSizeResponse *response);
int HIDDEN Pack_DI_CommonMode_Get(int iAdapterIndex, int extraInputSize, DI_GetCommonModeRequest *request, DI_GetCommonModeResponse *response);
int HIDDEN Pack_DI_SLSDisplayLayout_Add(int iAdapterIndex, int extraInputSize, DI_AddSlsDisplayLayoutRequest *request, unsigned int *LayoutID);

///
/// \brief Function to Get Mantle version details.
/// .
/// \platform
/// \WIN
/// \param[in]  mantleAppInfoStruct The pointer to the structure to set the Mantle details.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
int HIDDEN Pack_Graphics_MantleVersion_Get(ADLMantleAppInfo *mantleAppInfo);

///
/// \brief Function to Get Vulkan version details.
/// No longer used by RSX, kept for third party vendor support.
/// \platform
/// \WIN
/// \param[in]  vulkanAppInfo The pointer to the structure to set the Vulkan details.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
int HIDDEN Pack_Graphics_VulkanVersion_Get(ADLVulkanAppInfo *vulkanAppInfo);

///
/// \brief Function to Get Vulkan version details of currently connected display device.
/// SWDEV-261137 - This X2 function gets the Vulkan version of the currently connected display devices instead of all previously connected display devices. This X2 version is used by RSX currently, however the original function is kept to preserve third party vendor support.
/// \platform
/// \WIN
/// \param[in]  vulkanAppInfo The pointer to the structure to set the Vulkan details.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
int HIDDEN Pack_Graphics_VulkanVersionX2_Get(ADLVulkanAppInfo *vulkanAppInfo);

///
/// \brief Function to Get Vulkan version details of the passed in GPU via adapterindex
/// Side-by-side will allow system to support 2 different driver versions at the same time. This function will return the Vulkan version details of the passed in GPU.
/// \platform
/// \WIN
/// \param[in]  context			Client's ADL context handle
/// \param[in]  vulkanAppInfo	The pointer to the structure to set the Vulkan details.
/// \param[in]  iAdapterIndex	The adapter index of the GPU
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
int HIDDEN Pack_Graphics_VulkanVersionX3_Get(ADL_CONTEXT_HANDLE context, ADLVulkanAppInfo *vulkanAppInfo, int iAdapterIndex);


///
/// \brief Function to retrieve TRNG Value.
///
/// This function implements a lhEscape call to retrieve TRNG value.
/// \platform
/// \ALL
/// \param[in]  iAdapterIndex   The ADL index handle of the desired adapter.
/// \param[in]  iTRNGSize        The size of TRNG.
/// \param[in]  iTRNGBufferSize    size of the lpTRNGBuffer.
/// \param[out] lpTRNGBuffer       The pointer to the TRNG buffer.
/// \return If the function succeeds, the return value is \ref ADL_OK, or an ADL error code otherwise.  \ref define_adl_results
int HIDDEN Pack_CI_TRNG_Get(int iAdapterIndex, int iTRNGSize, int iTRNGBufferSize, char *lpTRNGBuffer);

///
/// \brief Function to retrieve Device ID Value.
///
/// This function implements a lhEscape call to retrieve TRNG value.
/// \platform
/// \ALL
/// \param[in]  iAdapterIndex   The ADL index handle of the desired adapter.
/// \param[in]  iRNDBufferSize    size of the input random number buffer.
/// \param[in]  lpRNDBuffer    the pointer to the inout random number buffer
/// \param[in]  iDeviceIDBufferSize     size of the output device ID buffer.
/// \param[out] lpDeviceIDBuffer       The pointer to the Device ID buffer.
/// \param[out] iDeviceIDSize       size of the Device ID.
/// \return If the function succeeds, the return value is \ref ADL_OK, or an ADL error code otherwise.  \ref define_adl_results
int HIDDEN Pack_CI_DeviceID_Get(int iAdapterIndex, int iRNDBufferSize,  char *lpRNDBuffer,  int iDeviceIDBufferSize, char *lpDeviceIDBuffer , int *iDeviceIDSize);

int HIDDEN Pack_DI_MST_DpMstAuxMsg_Get( int iAdapterIndex, int iDisplayIndex, int iAuxMsgInfolen, char *lpAuxMsgInfo, int iReplyDatalen,  char *lpReplyData);

///
/// \brief Function to retrieve the supported power states in AC or DC.
///
/// This function retrieves the supported power states for a given power source.
/// \platform
/// \WIN
/// \param[in]  iAdapterIndex   The ADL index handle of the desired adapter.
/// \param[in]   iInputPowerSource pointer to the input buffer that contains the power source.
/// \param[out]  lpSupportedPowerStates The pointer to the structure storing the supported power states for the provided power source.
/// \return If the function succeeds, the return value is \ref ADL_OK, or an ADL error code otherwise.  \ref define_adl_results
int HIDDEN Pack_System_PowerStates_Get(int iAdapterIndex, UMDKMDIF_QUERY_DEFAULT_POWER_STATES_INPUT* iInputPowerSource, UMDKMDIF_QUERY_DEFAULT_POWER_STATES_OUTPUT* lpSupportedPowerStates);

///
/// \brief  This function gets the current power
///
/// This function implements a PM call CWDDEPM_OD6_GetCurrentPower
/// \platform
/// \ALL
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[out]  lpCurrentPowerStruct pointer to CWDDEPM_CURRENTPOWERPARAMETERS
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
int HIDDEN Pack_PM_OD6_CurrentPower_Get(int iAdapterIndex, CWDDEPM_CURRENTPOWERPARAMETERS *lpCurrentPowerStruct);

///
/// \brief  This function gets the ASIC's TDP
///
/// This function implements a PM call CWDDEPM_OD6_GetASICTDP
/// \platform
/// \ALL
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[in]  lpInput pointer to CWDDEPM_OD6_TEMPERATURE_EX_INPUT
/// \param[out] lpOutput pointer to CWDDEPM_OD6_TEMPERATURE_EX_OUTPUT
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
int HIDDEN Pack_PM_OD6_TemperatureEx_Get(int iAdapterIndex, CWDDEPM_OD6_TEMPERATURE_EX_INPUT *lpTemperatureInput, CWDDEPM_OD6_TEMPERATURE_EX_OUTPUT *lpTemperatureOutput);

///
/// \brief  This function to allow access to the I2C bus
///
/// This function implements a PM call CWDDEPM_OD6_GetASICTDP
/// \platform
/// \ALL
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[in] lpI2CInput pointer to CWDDEPM_OD6_CONTROLI2C_INPUT
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
int HIDDEN Pack_PM_OD6_ControlI2C(int iAdapterIndex, CWDDEPM_OD6_CONTROLI2C_INPUT *lpI2CInput);

///
/// \brief  This function to allow access to the I2C bus
///
/// This function implements a PM call CWDDEPM_ControlI2C
/// \platform
/// \ALL
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[in] pI2CInput pointer to CWDDEPM_CONTROLI2C_INPUT
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
int HIDDEN Pack_PM_ControlI2C(int iAdapterIndex, CWDDEPM_CONTROLI2C_INPUT *pI2CInput, CWDDEPM_CONTROLI2C_OUTPUT *pI2COutput);

///
/// \brief Function to get the Power Control parameters for Overdrive 6 V2
///
/// This function implements a PM call CWDDEPM_OD6_GetPowerControlParameters_V2
/// \platform
/// \ALL
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[out] lpPCParameters The pointer to the structure storing the retrieved OD parameters.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
int HIDDEN Pack_PM_OD6_PowerControlParameters_Get_X2( int iAdapterIndex,  CWDDEPM_OD6_POWERCONTROLPARAMETERS_V2 *lpPCParameters );

/// \brief  This function gets ODN Capabilities
///
/// This function implements a PM call CWDDEPM_ODN_GetParameters
/// \platform
/// \WIN
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[out]  pCapabilities pointer to CWDDEPM_ODN_PARAMETERS
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
int HIDDEN Pack_PM_ODN_Capabilities_Get(int iAdapterIndex, CWDDEPM_ODN_PARAMETERS *pCapabilities);


/// \brief  This function gets System clock settings
///
/// This function implements a PM call CWDDEPM_ODN_GetSystemClockLevels
/// \platform
/// \WIN
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[in]  lpInSClocks pointer to CWDDEPM_ODN_GETCLOCKLEVELS_INPUT
/// \param[out]  lpOutSClocks pointer to CWDDEPM_ODN_GETSYSTEMCLOCKLEVELS_OUTPUT
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
int HIDDEN Pack_PM_ODN_SystemClocks_Get(int iAdapterIndex, CWDDEPM_ODN_GETCLOCKLEVELS_INPUT *lpInSClocks, CWDDEPM_ODN_GETSYSTEMCLOCKLEVELS_OUTPUT *lpOutSClocks);

/// \brief  This function set system clock settings
///
/// This function implements a PM call CWDDEPM_ODN_SetSystemClockLevels
/// \platform
/// \WIN
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[in]  lpInSClocks pointer to CWDDEPM_ODN_SETSYSTEMCLOCKLEVELS_INPUT
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
int HIDDEN Pack_PM_ODN_SystemClocks_Set(int iAdapterIndex, CWDDEPM_ODN_SETSYSTEMCLOCKLEVELS_INPUT *lpInSClocks);

/// \brief  This function gets Memory clock settings
///
/// This function implements a PM call CWDDEPM_ODN_GetMemoryClockLevels
/// \platform
/// \WIN
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[in]  lpInMClocks pointer to CWDDEPM_ODN_GETCLOCKLEVELS_INPUT
/// \param[out]  lpOutMClocks pointer to GetMemoryClockLevels
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
int HIDDEN Pack_PM_ODN_MemoryClocks_Get(int iAdapterIndex, CWDDEPM_ODN_GETCLOCKLEVELS_INPUT *lpInMClocks, CWDDEPM_ODN_GETMEMORYCLOCKLEVELS_OUTPUT *lpOutMClocks);

/// \brief  This function set Memory clock settings
///
/// This function implements a PM call CWDDEPM_ODN_SetMemoryClockLevels
/// \platform
/// \WIN
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[in]  lpInMClocks pointer to CWDDEPM_ODN_SETMEMORYCLOCKLEVELS_INPUT
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
int HIDDEN Pack_PM_ODN_MemoryClocks_Set(int iAdapterIndex, CWDDEPM_ODN_SETMEMORYCLOCKLEVELS_INPUT *lpInMClocks);

/// \brief  This function gets ODN Fan control
///
/// This function implements a PM call CWDDEPM_ODN_GetFanControl
/// \platform
/// \WIN
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[out]  lpOutFanControl pointer to CWDDEPM_ODN_GETFANCONTROL_OUTPUT
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
int HIDDEN Pack_PM_ODN_FanControl_Get(int iAdapterIndex, CWDDEPM_ODN_GETFANCONTROL_OUTPUT *lpOutFanControl);

/// \brief  This function gets ODN Fan control
///
/// This function implements a PM call CWDDEPM_ODN_SetFanControl
/// \platform
/// \WIN
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[out]  lpOutFanControl pointer to CWDDEPM_ODN_SETFANCONTROL_INPUT
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
int HIDDEN Pack_PM_ODN_FanControl_Set(int iAdapterIndex, CWDDEPM_ODN_SETFANCONTROL_INPUT *lpInFanCongrol);

/// \brief  This function gets Custom Fan control for WS
///
/// This function implements a PM call CWDDEPM_GetCustomFanControl
/// \platform
/// \WIN
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[out]  lpOutFanControl pointer to CWDDEPM_ODN_GETFANCONTROL_OUTPUT
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
int HIDDEN Pack_PM_ODN_CustomFanControl_Get(int iAdapterIndex, CWDDEPM_ODN_GETFANCONTROL_OUTPUT *lpOutFanControl);

/// \brief  This function gets Custom Fan control for WS
///
/// This function implements a PM call CWDDEPM_SetCustomFanControl
/// \platform
/// \WIN
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[out]  lpOutFanControl pointer to CWDDEPM_ODN_SETFANCONTROL_INPUT
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
int HIDDEN Pack_PM_ODN_CustomFanControl_Set(int iAdapterIndex, CWDDEPM_ODN_SETFANCONTROL_INPUT *lpInFanCongrol);

/// \brief  This function gets ODN power limit settings
///
/// This function implements a PM call CWDDEPM_ODN_GetPowerLimit
/// \platform
/// \WIN
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[out]  lpOutFanControl pointer to CWDDEPM_ODN_POWERLIMITSETTING_OUTPUT
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
int HIDDEN Pack_PM_ODN_PowerLimitSettings_Get(int iAdapterIndex, CWDDEPM_ODN_POWERLIMITSETTING_OUTPUT *lpOutPowerLimit);

/// \brief  This function gets ODN power limit settings
///
/// This function implements a PM call CWDDEPM_ODN_SetPowerLimit
/// \platform
/// \WIN
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[out]  lpOutFanControl pointer to CWDDEPM_ODN_POWERLIMITSETTING_INPUT
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
int HIDDEN Pack_PM_ODN_PowerLimitSettings_Set(int iAdapterIndex, CWDDEPM_ODN_POWERLIMITSETTING_INPUT *lpInPowerLimit);

/// \brief  This function gets ODN power limit settings
///
/// This function implements a PM call CWDDEPM_ODN_GetTemperature
/// \platform
/// \WIN
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[in]  lpInTemperature pointer to CWDDEPM_ODN_TEMPERATURE_INPUT
/// \param[out]  lpOutTemperature pointer to CWDDEPM_ODN_TEMPERATURE_OUTPUT
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
int HIDDEN Pack_PM_ODN_Temperature_Get(int iAdapterIndex, CWDDEPM_ODN_TEMPERATURE_INPUT *lpInTemperature, CWDDEPM_ODN_TEMPERATURE_OUTPUT *lpOutTemperature);

/// \brief  This function gets ODN performance levels
///
/// This function implements a PM call CWDDEPM_ODN_GetCurrentGPUPerformanceStatus
/// \platform
/// \WIN
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[out]  lpOutPerformanceStatus pointer to CWDDEPM_ODN_GPU_PERFORMANCE_STATUS
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
int HIDDEN Pack_PM_ODN_PerformanceStatus_Get(int iAdapterIndex, CWDDEPM_ODN_GPU_PERFORMANCE_STATUS *lpOutPerformanceStatus);

/// \brief  This function gets OD8 initial settings
///
/// This function implements a PM call CWDDEPM_OD8_GetInitialParameter
/// \platform
/// \WIN
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[out]  lpInitSetting pointer to CWDDEPM_OD8_INIT_SETTING
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
int HIDDEN Pack_PM_OD8_InitSetting_Get(int iAdapterIndex, CWDDEPM_OD8_INIT_SETTING *lpInitSetting);

/// \brief  This function gets OD8 current settings
///
/// This function implements a PM call CWDDEPM_OD8_GetCurrentSetting
/// \platform
/// \WIN
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[out]  lpCurrentSetting pointer to CWDDEPM_OD8_GET_CURRENT_SETTING
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
int HIDDEN Pack_PM_OD8_CurrentSetting_Get(int iAdapterIndex, CWDDEPM_OD8_GET_CURRENT_SETTING *lpCurrentSetting);

/// \brief  This function sets OD8 settings
///
/// This function implements a PM call CWDDEPM_OD8_SetSetting
/// \platform
/// \WIN
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[in]  lpSetSetting pointer to CWDDEPM_OD8_SetSetting
/// \param[out]  lpCurrentSetting pointer to CWDDEPM_OD8_GET_CURRENT_SETTING
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
int HIDDEN Pack_PM_OD8_SetSetting_Set(int iAdapterIndex, CWDDEPM_OD8_SET_SETTING *lpSetSetting, CWDDEPM_OD8_GET_CURRENT_SETTING *lpCurrentSetting);


/// \brief  This function gets PM Settings
///
/// This function implements a PM call CWDDEPM_QueryPMLogData
/// \platform
/// \WIN
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[in]  lpSetSetting pointer to CWDDEPM_QueryPMLogData
/// \param[out]  lpDataOutput pointer to CWDDEPM_QUERY_PMLOG_DATA_OUTPUT
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results

int HIDDEN Pack_PM_New_QueryPMLogData_Get(int iAdapterIndex, CWDDEPM_QUERY_PMLOG_DATA_OUTPUT *lpDataOutput);

int HIDDEN Pack_AutoTuningResult_Get(int iAdapterIndex, CWDDEPM_QUERY_AUTO_FEATURE_STATUS_OUTPUT *lpDataOutput);

int HIDDEN Pack_PM_New_PMLogCapabilities_Get(int iAdapterIndex, CWDDEPM_PMLOG_CLIENT_ID *lpSetClientID, ULONGLONG *lpDataOutput);

int HIDDEN Pack_PM_PMLogSensorLimits_Get(int iAdapterIndex, CWDDEPM_QUERY_PMLOG_SENSOR_LIMITS *lpDataOutput);

/// \brief  This function gets Clock limits Settings
///
/// This function implements a PM call CWDDEPM_GetAllClockLimits
/// \platform
/// \WIN
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[out]  lpDataOutput pointer to CWDDEPM_CLOCKLIMITS_OUTPUT
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results

int HIDDEN Pack_PM_New_AllClockLimits_Get(int iAdapterIndex, CWDDEPM_CLOCKLIMITS_OUTPUT *lpDataOutput);

///
/// \brief Function to Get PPW(Performance Per Watt) Status.
///
/// This function implements a PM call CWDDEPM_GetPerfPerWattControl.
/// \platform
/// \WIN
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[out] lpPPWControlStruct The pointer to the structure to get the PM PPW status.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
int HIDDEN Pack_PM_PPW_Status_Get(int iAdapterIndex, CWDDEPM_PERFPERWATT_CONTROL *lpPPWControlStruct);

///
/// \brief Function to Set PPW(Performance Per Watt) Status.
///
/// This function implements a PM call CWDDEPM_SetPerfPerWattControl.
/// \platform
/// \WIN
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[in]  lpPPWControlStruct The pointer to the structure to set the PM PPW status.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
int HIDDEN Pack_PM_PPW_Settings_Set(int iAdapterIndex, CWDDEPM_PERFPERWATT_CONTROL *lpPPWControlStruct);

///
/// \brief Function to Get performance UI tunning Status.
///
/// This function implements a PM call CWDDEPM_GetPerfUITuningControl.
/// \platform
/// \WIN
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[out] lpPTuningControlStruct The pointer to the structure to get the PM performance tuning status.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
int HIDDEN Pack_PM_PerfTuning_Status_Get(int iAdapterIndex, CWDDEPM_PERFPERWATT_CONTROL *lpPTuningControlStruct);

///
/// \brief Function to Set performance UI tunning Status.
///
/// This function implements a PM call CWDDEPM_SetPerfUITuningControl.
/// \platform
/// \WIN
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[in]  lpPTuningControlStruct The pointer to the structure to set the PM performance tuning status.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
int HIDDEN Pack_PM_PerfTuning_Settings_Set(int iAdapterIndex, CWDDEPM_PERFPERWATT_CONTROL *lpPTuningControlStruct);

///
/// \brief Function to Get Compatibility Mode(Ellesmere) Status.
///
/// This function implements a PM call CWDDEPM_GetCompatibilityModeControl.
/// \platform
/// \WIN
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[out] lpPPWControlStruct The pointer to the structure to get the PM PPW status.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
int HIDDEN Pack_PM_ElmCompatibilityMode_Status_Get(int iAdapterIndex, CWDDEPM_COMPATIBILITYMODE_CONTROL *lpPPWControlStruct);

///
/// \brief Function to Set Compatibility Mode(Ellesmere) Status.
///
/// This function implements a PM call CWDDEPM_SetCompatibilityModeControl.
/// \platform
/// \WIN
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[in]  lpPPWControlStruct The pointer to the structure to set the PM PPW status.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
int HIDDEN Pack_PM_ElmCompatibilityMode_Settings_Set(int iAdapterIndex, CWDDEPM_COMPATIBILITYMODE_CONTROL *lpPPWControlStruct);


///
/// \brief Function to Get PPLog Settings.
///
/// This function implements a PM call CWDDEPM_GetPPLogSettings.
/// \platform
/// \WIN
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[out] lpPPLogSettings The pointer to the structure to get the PPLog Settings.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
int HIDDEN Pack_PM_PPLogSettings_Get(int iAdapterIndex, CWDDEPM_PPLOGSETTINGS *lpPPLogSettings);

///
/// \brief Function to Set Compatibility Mode(Ellesmere) Status.
///
/// This function implements a PM call CWDDEPM_SetCompatibilityModeControl.
/// \platform
/// \WIN
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[in]  lpPPLogSettings The pointer to the structure to set the PPLog Settings.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
int HIDDEN Pack_PM_PPLogSettings_Set(int iAdapterIndex, CWDDEPM_PPLOGSETTINGS *lpPPLogSettings);

///
/// \brief Function to Get Auto wattman settings.
///
/// This function implements a PM call CWDDEPM_GetAutoWattmanControl.
/// \platform
/// \WIN
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[out] lpOutAutoWattmanSettings The pointer to the structure to get the Auto wattman Settings.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
int HIDDEN Pack_PM_AutoWattman_Get(int iAdapterIndex, CWDDEPM_AUTOWATTMAN_CONTROL *lpOutAutoWattmanSettings);

///
/// \brief Function to Set Auto wattman Status.
///
/// This function implements a PM call CWDDEPM_SetAutoWattmanControl.
/// \platform
/// \WIN
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[in]  lpInAutoWattmanSettings The pointer to the structure to set the Auto wattman Settings.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
int HIDDEN Pack_PM_AutoWattman_Set(int iAdapterIndex, CWDDEPM_AUTOWATTMAN_CONTROL *lpInAutoWattmanSettings);

///
/// \brief Function to retrieve LocalMemory info.
///
/// This function implements a CI call to retrieve LocalMemory info.
/// \platform
/// \ALL
/// \param[in]  iAdapterIndex       The ADL index handle of the desired adapter.
/// \param[in]  pInCallerBuffer     The desired input buffer.
/// \param[out] pOutCallerBuffer    The pointer to the output buffer.
/// \return If the function succeeds, the return value is \ref ADL_OK, or an ADL error code otherwise.  \ref define_adl_results
int HIDDEN Pack_CI_LocalMemoryInfo_Get(int iAdapterIndex, UMDKMDIF_GET_LOCAL_MEM_INFO_INPUT *pInCallerBuffer, UMDKMDIF_GET_LOCAL_MEM_INFO_OUTPUT *pOutCallerBuffer);

///
/// \brief Function to operate PageMigration.
///
/// This function implements a CI call to operate PageMigration.
/// \platform
/// \ALL
/// \param[in]  iAdapterIndex       The ADL index handle of the desired adapter.
/// \param[in]  pInCallerBuffer     The desired input buffer.
/// \param[out] pOutCallerBuffer    The pointer to the output buffer.
/// \return If the function succeeds, the return value is \ref ADL_OK, or an ADL error code otherwise.  \ref define_adl_results
int HIDDEN Pack_CI_PageMigration_Operation(int iAdapterIndex, UMDKMDIF_PAGEMIGRATION_OPERATION_INPUT *pInCallerBuffer, UMDKMDIF_PAGEMIGRATION_OPERATION_OUTPUT *pOutCallerBuffer);

///
/// \brief Function to operate VM Page Size.
///
/// This function implements a CI call to operate VM Page Size.
/// \platform
/// \ALL
/// \param[in]  iAdapterIndex       The ADL index handle of the desired adapter.
/// \param[in]  pInCallerBuffer     The desired input buffer.
/// \param[out] pOutCallerBuffer    The pointer to the output buffer.
/// \return If the function succeeds, the return value is \ref ADL_OK, or an ADL error code otherwise.  \ref define_adl_results
int HIDDEN Pack_CI_VMPageSize_Operation(int iAdapterIndex, UMDKMDIF_VM_PAGE_SIZE_INPUT *pInCallerBuffer, UMDKMDIF_VM_PAGE_SIZE_OUTPUT *pOutCallerBuffer);

///
/// \brief Function to Get no. of recently ran and currently running applications.
///
/// This function is implemented via the LHESCAPE/CWDDECI Escape call LHESCAPE_UMDKMDIF_GET_APPLICATION_LIST.
///
/// \platform
/// \VISTAWIN7
/// \param[in]  iAdapterIndex	 The ADL index handle corresponding to Logical Adapter/Display Device
/// \param[in]  iListType		 The type of applications to be retrieved. It can be either 1(currently running applications) or 2(recently ran applications)
/// \param[out]	NumApps		The number of application that were currently running or recently ran
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
int HIDDEN Pack_SGRunningApps_Count_Get(int iAdapterIndex, int iListType, int* NumApps);

///
/// \brief Function to Get all the recently ran and currently running applications.
///
/// This function is implemented via the LHESCAPE/CWDDECI Escape call LHESCAPE_UMDKMDIF_GET_APPLICATION_LIST.
///
/// \platform
/// \VISTAWIN7
/// \param[in]  iAdapterIndex		The ADL index handle corresponding to Logical Adapter/Display Device
/// \param[in]  iListType			The type of applications to be retrieved. It can be either 1(currently running applications) or 2(recently ran applications)
/// \param[in]	NumApps				The number of application that were currently running or recently ran
/// \param[out]	lpOutCallerBuffer   Output buffer for UMDKMDIF_GET_APPLICATION_LIST_OUTPUT
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
int HIDDEN Pack_SGRunningApps_Get(int iAdapterIndex, int iListType, int NumApps, UMDKMDIF_GET_APPLICATION_LIST_OUTPUT* lpOutCallerBuffer);

/// \brief Function to GetThrottleNotification settings.
///
/// This function implements a PM call CWDDEPM_ODN_GetThrottleNotification.
/// \platform
/// \WIN
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[out] lpOutThrottleNotificationSettings The pointer to the structure to get the Throttle Notification Settings.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
int HIDDEN Pack_PM_ThrottleNotification_Get(int iAdapterIndex, CWDDEPM_ODN_GETTHROTTLENOTIFICATION_OUTPUT *lpOutThrottleNotificationSettings);
/*
///
/// \brief Function to Set throttle Notification Status.
///
/// This function implements a PM call CWDDEPM_ODN_SetThrottleNotification.
/// \platform
/// \WIN
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[in]  lpInThrottleNotificationSettings The pointer to the structure to set the Throttle settings.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
int HIDDEN Pack_PM_ThrottleNotification_Set(int iAdapterIndex, CWDDEPM_ODN_SETTHROTTLENOTIFICATION_INPUT *lpInThrottleNotificationSettings);*/

///
/// \brief Function to GetThrottleNotification settings.
///
/// This function implements a PM call CWDDEPM_ODN_GetAutoSystemClockLevels.
/// \platform
/// \WIN
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[out] lpOutThrottleNotificationSettings The pointer to the structure to get the Throttle Notification Settings.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
int HIDDEN Pack_PM_SCLKAutoOverClock_Get(int iAdapterIndex, CWDDEPM_ODN_AUTOSYSTEMCLOCKLEVELS *lpOutAutoClockSettings);

///
/// \brief Function to Set throttle Notification Status.
///
/// This function implements a PM call CWDDEPM_ODN_SetAutoSystemClockLevels.
/// \platform
/// \WIN
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[in]  lpInThrottleNotificationSettings The pointer to the structure to set the Throttle settings.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
int HIDDEN Pack_PM_SCLKAutoOverClock_Set(int iAdapterIndex, CWDDEPM_ODN_AUTOSYSTEMCLOCKLEVELS *lpInAutoClockSettings, int *iRebootFlags);

///
/// \brief Function to operate Chill Settings.
///
/// This function implements a CI call to operate Global Chill Settings.
/// \platform
/// \ALL
/// \param[in]  iAdapterIndex       The ADL index handle of the desired adapter.
/// \param[in]  pInCallerBuffer     The desired input buffer.
/// \param[out] pOutCallerBuffer    The pointer to the output buffer.
/// \return If the function succeeds, the return value is \ref ADL_OK, or an ADL error code otherwise.  \ref define_adl_results
int HIDDEN Pack_CI_ChillSettings_Operation(int iAdapterIndex, UMDKMDIF_NOTIFY_CHILL_CHANGE_INPUT *pInCallerBuffer, UMDKMDIF_NOTIFY_CHILL_CHANGE_OUTPUT *pOutCallerBuffer);

///
/// \brief No longer used by RSX, kept for third party vendor support.
///
///Get registry path HKLM\SYSTEM\CurrentControlSet\Services\amdkmdag\ImagePath.
///This key will point directly to KMD.This key will have a value similar to
///\SystemRoot\System32\DriverStore\FileRepository\c0305072.inf_amd64_bd7907b4c643e12e\atikmdag.sys
///By using  GetSystemDirectory, we can get physical driver binary path
///
/// \platform
/// \WIN
/// \param[in]  fileName     driver binaries like mantle64.dll.
/// \param[out] pathName     The pointer to the output path.
void HIDDEN Pack_DriverStoreFilePath_Get(char *fileName, char *pathName);

///
/// \brief Function To locate driver binaries in driver store path and get complete path. This function calls GetPresentDisplayDeviceServiceName instead of GetTheDisplayServiceName.
///
///Get registry path HKLM\SYSTEM\CurrentControlSet\Services\amdkmdag\ImagePath.
///This key will point directly to KMD.This key will have a value similar to
///\SystemRoot\System32\DriverStore\FileRepository\c0305072.inf_amd64_bd7907b4c643e12e\atikmdag.sys
///By using  GetSystemDirectory, we can get physical driver binary path
///
/// \platform
/// \WIN
/// \param[in]  fileName     driver binaries like mantle64.dll.
/// \param[out] pathName     The pointer to the output path.
void HIDDEN Pack_DriverStoreFilePathX2_Get(char *fileName, char *pathName);

///
/// \brief Function to set the remote play control flags 
/// 
/// This function implements a DI call to set LHESCAPE_UMDKMDIF_REMOTE_PLAY_CONTROL. 
/// \brief Function to set the remote play control flags
///
/// This function implements a DI call to set LHESCAPE_UMDKMDIF_REMOTE_PLAY_CONTROL.
/// \platform
/// \ALL
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[in]  pInCallerBuffer     The desired input buffer.
/// \param[out] pOutCallerBuffer    The pointer to the output buffer.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
int HIDDEN Pack_DI_RemotePlay_ControlState_Set(int iAdapterIndex, UMDKMDIF_REMOTE_PLAY_CONTROL_INPUT* pInCallerBuffer, UMDKMDIF_REMOTE_PLAY_CONTROL_OUTPUT* pLOutCallerBuffer, D3DKMT_HANDLE hDevice);

int HIDDEN Pack_PM_ODN_CapabilitiesX2_Get(int iAdapterIndex, CWDDEPM_ODN_PARAMETERS_EX *pCapabilities);

int HIDDEN Pack_PM_ODN_SettingX2_Get(int iAdapterIndex, CWDDEPM_ODN_FEATURE_SETTINGS_OUTPUT_EX *pOutSettingEx);

int HIDDEN Pack_PM_ODN_SettingX2_Set(int iAdapterIndex, const CWDDEPM_ODN_FEATURE_SETTINGS_INPUT_EX *pInSettingEx);

/// \brief Function to retrieve RAS error counts.
/// 
/// This function implements a call to retrieve RAS error counts.
/// \platform
/// \VISTAWIN7
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[in]  input buffer of LHESCAPE_UMDKMDIF_RAS_GET_ERROR_COUNTS.
/// \param[out]  output buffer of LHESCAPE_UMDKMDIF_RAS_GET_ERROR_COUNTS.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results

int HIDDEN Pack_WorkStation_RAS_ErrorCounts_Get(int iAdapterIndex, UMDKMDIF_RAS_GET_ERROR_COUNTS_INPUT* pInCallerBuffer, UMDKMDIF_RAS_GET_ERROR_COUNTS_OUTPUT * pOutCallerBuffer);

/// \brief Function to reset RAS error records.
/// 
/// This function implements a call to reset RAS error records.
/// \platform
/// \VISTAWIN7
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[in]  input buffer of LHESCAPE_UMDKMDIF_RAS_RESET_ERROR_COUNTS.
/// \param[out]  output buffer of LHESCAPE_UMDKMDIF_RAS_RESET_ERROR_COUNTS.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results

int HIDDEN Pack_WorkStation_RAS_ErrorCounts_Reset(int iAdapterIndex, UMDKMDIF_RAS_RESET_ERROR_COUNTS_INPUT* pInCallerBuffer, UMDKMDIF_RAS_RESET_ERROR_COUNTS_OUTPUT* pOutCallerBuffer);

///
/// \brief Function to retrieve current workattaion overdrive support capabilities
/// 
/// This function retrieves current workattaion overdrivecapabilities for a specified adapter.
/// \platform
/// \ALL
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[in]  iSupported The pointer to an int variable which indicates if Overdrive feature is supported ( \ref ADL_TRUE : supported, \ref ADL_FALSE : not supported)
/// \param[in]  iEnabled The pointer to an int variable which indicates if Overdrive feature is enabled ( \ref ADL_TRUE : enabled, \ref ADL_FALSE : disabled)
/// \param[in]  iVersion The pointer to an int variable receiving the Overdrive feature version.
/// \return If the function succeeds, the return value is \ref ADL_OK (zero). Otherwise the return value is an ADL error code (non-zero). \ref define_adl_results. If Overdrive feature is not supported the return code is \ref ADL_ERR_NOT_SUPPORTED 
int HIDDEN Pack_Overdrive_Caps(int iAdapterIndex, unsigned long pmFeatureID, int * iSupported, int * iEnabled, int * iVersion);

/// \brief Function to Get RAS error records.
/// 
/// This function implements a call to reset RAS error records.
/// \platform
/// \VISTAWIN7
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[in]  input buffer of UMDKMDIF_GET_FEATURE_SETTINGS_INPUT.
/// \param[out]  output buffer of UMDKMDIF_GET_FEATURE_SETTINGS_OUTPUT.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
int HIDDEN Pack_Features_Get(int IAdapterIndex, UMDKMDIF_GET_FEATURE_SETTINGS_INPUT *input, UMDKMDIF_GET_FEATURE_SETTINGS_OUTPUT *iADLRasFeaturesOutput);

/// \brief Function to reset RAS error records.
/// 
/// This function implements a call to reset RAS error records.
/// \platform
/// \VISTAWIN7
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[in]  input buffer of UMDKMDIF_SET_FEATURE_SETTINGS_INPUT.
/// \param[out]  output buffer of UMDKMDIF_SET_FEATURE_SETTINGS_OUTPUT.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
int HIDDEN Pack_Features_Set(int IAdapterIndex, UMDKMDIF_SET_FEATURE_SETTINGS_INPUT *iInput, UMDKMDIF_SET_FEATURE_SETTINGS_OUTPUT *iOutput);

int HIDDEN pri_ADL2_New_PMLogSensorLimits_Get(ADL_CONTEXT_HANDLE context, int iAdapterIndex, ADLPMLogSensorLimits* lpDataOutput);

int HIDDEN pri_ADL2_New_PMLogCapabilities_Get(ADL_CONTEXT_HANDLE context, int iAdapterIndex, ULONGLONG* lpDataOutput);

///
/// \brief Function to write/read to/from the I2C bus
/// 
/// This function writes or reads I2C.
/// \platform
/// \ALL
/// \param[in]      iAdapterIndex The ADL index handle of the desired adapter.
/// \param[in,out]  plI2C A pointer to the ADLI2CLargePayload structure.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
int HIDDEN pri_ADL2_PM_ControlI2C_WriteOrRead(int iAdapterIndex, ADLI2CLargePayload *plI2C, unsigned int iMaxReadSize, unsigned int iMaxWriteSize);

///
/// \brief Function to get frame metadata shared memory for querying SrcRect
///
/// This function implements to the LHESCAPE/CWDDECI Escape call LHESCAPE_UMDKMDIF_GET_SHARED_MEMORY.
/// \platform
/// \WIN
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[in]  hDevice The device handle.
/// \param[in]  input buffer of UMDKMDIF_GET_SHARED_MEM_INPUT.
/// \param[out] output buffer of UMDKMDIF_GET_SHARED_MEM_OUTPUT
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code.   \ref define_adl_results
int HIDDEN Pack_CI_FrameMetaData_Get(int iAdapterIndex, D3DKMT_HANDLE hDevice, UMDKMDIF_GET_SHARED_MEM_INPUT* pInCallerBuffer, UMDKMDIF_GET_SHARED_MEM_OUTPUT* pOutCallerBuffer);

///
/// \brief Function to retrieve the XGMI hive ID.
///
/// This function implements the CI calls to retrieve the XGMI hive ID of a XGMI supported adapter.
///
/// \platform
/// \ALL
/// \param[in] iAdapterIndex     The ADL index handle of the GPU adapter.
/// \param[out] iState      	The pointer to the XGMI hive ID. 
/// \return ADL_OK if the hive ID is retrieved correctly, else ADL_ERR.
int HIDDEN Pack_CI_XGMIHiveID_Get(int iAdapterIndex, int* iHiveID);

///
/// \brief
///
/// This function implements a DI call to set PSR control settings on the given display.
/// \platform
/// \ALL
/// \param[in ]  iAdapterIndex The index of the desired adapter.
/// \param[in ]  iDisplayIndex The index of the desired display.
/// \param[in ]  psrControl The PSR control settings information from the user side
/// \return If the function succeeds, the return value is ADL_OK (zero). Otherwise the return value is an ADL error code (non-zero). \ref define_adl_results
int HIDDEN Pack_DI_Display_PsrControl(int iAdapterIndex, int iDisplayIndex, DI_PSRCONTROLINPUTDATA* pInputData, DI_PSRCONTROLOUTPUTDATA* pOutputData);

///
/// \brief
///
/// This function implements a DI call to get DSC related settings on the given display.
/// \platform
/// \ALL
/// \param[in ]  iAdapterIndex The index of the desired adapter.
/// \param[in ]  iDisplayIndex The index of the desired display.
/// \param[in ]  pDSCInfo The DSC related settings information from driver.
/// \return If the function succeeds, the return value is ADL_OK (zero). Otherwise the return value is an ADL error code (non-zero). \ref define_adl_results
int HIDDEN Pack_DI_Display_GetDSCInfo(int iAdapterIndex, int iDisplayIndex, ADLDSCInfo* pDSCInfo);

///
/// \brief
///
/// This function implements a DI call to set PSR control settings on the given display.
/// \platform
/// \ALL
/// \param[in ]  iAdapterIndex The index of the desired adapter.
/// \param[in ]  iDisplayIndex The index of the desired display.
/// \param[in ]  pDSCAdjust The DSC adjustment settings information from the user side.
/// \return If the function succeeds, the return value is ADL_OK (zero). Otherwise the return value is an ADL error code (non-zero). \ref define_adl_results
int HIDDEN Pack_DI_Display_SetDSCAdjustment(int iAdapterIndex, int iDisplayIndex, ADLDSCAdjustment* pDSCAdjust);

///
/// \brief
///
/// This function implements a DI call to get SMA control settings on the given gpu.
/// \platform
/// \ALL
/// \param[in ]  IAdapterIndex The index of the desired adapter.
/// \param[in ]  input none.
/// \param[out ]  output Smart Access Memory state
/// \return If the function succeeds, the return value is ADL_OK (zero). Otherwise the return value is an ADL error code (non-zero). \ref define_adl_results
int HIDDEN Pack_SMA_Mode_Get(int IAdapterIndex, UMDKMDIF_SMARTACCESSMEMORY_GET_MODE_INPUT *input, UMDKMDIF_SMARTACCESSMEMORY_GET_MODE_OUTPUT *output);

///
/// \brief
///
/// This function implements a DI call to set SMA control settings on the given gpu.
/// \platform
/// \ALL
/// \param[in ]  IAdapterIndex The index of the desired adapter.
/// \param[in ]  input The value Smart Access Memory mode.
/// \param[out ]  output none.
/// \return If the function succeeds, the return value is ADL_OK (zero). Otherwise the return value is an ADL error code (non-zero). \ref define_adl_results
int HIDDEN Pack_SMA_Mode_Set(int IAdapterIndex, UMDKMDIF_SMARTACCESSMEMORY_SET_MODE_INPUT *input, UMDKMDIF_SMARTACCESSMEMORY_SET_MODE_OUTPUT *output);

///
/// \brief
///
/// This function implements a CI call to get UMA caps on the given gpu.
/// \platform
/// \ALL
/// \param[in ]  IAdapterIndex The index of the desired adapter.
/// \param[in ]  input The value is empty
/// \param[out ] output is data structure /ref UMDKMDIF_UMA_SIZE_CONTROL_GET_INFO_OUTPUT.
/// \return If the function succeeds, the return value is ADL_OK (zero). Otherwise the return value is an ADL error code (non-zero). \ref define_adl_results
int HIDDEN Pack_UMA_Info_Get(int IAdapterIndex, UMDKMDIF_UMA_SIZE_CONTROL_GET_INFO_INPUT *input, UMDKMDIF_UMA_SIZE_CONTROL_GET_INFO_OUTPUT *output);
///
/// \brief
///
/// This function implements a CI call to get UMA caps and current value, default value and possible value on the given gpu.
/// \platform
/// \ALL
/// \param[in ]  IAdapterIndex The index of the desired adapter.
/// \param[in ]  input The value is empty
/// \param[out ] output is data structure /ref UMDKMDIF_UMA_SIZE_CONTROL_GET_MODE_OUTPUT.
/// \return If the function succeeds, the return value is ADL_OK (zero). Otherwise the return value is an ADL error code (non-zero). \ref define_adl_results
int HIDDEN Pack_UMA_Size_Get(int IAdapterIndex, UMDKMDIF_UMA_SIZE_CONTROL_GET_MODE_INPUT *input, UMDKMDIF_UMA_SIZE_CONTROL_GET_MODE_OUTPUT *output, int outputSize);

///
/// \brief
///
/// This function implements a CI call to set UMA mode
/// \platform
/// \ALL
/// \param[in ]  IAdapterIndex The index of the desired adapter.
/// \param[in ]  input is data structure  /ref UMDKMDIF_UMA_SIZE_CONTROL_SET_MODE_INPUT
/// \param[out ] output is data structure /ref UMDKMDIF_UMA_SIZE_CONTROL_SET_MODE_OUTPUT.
/// \return If the function succeeds, the return value is ADL_OK (zero). Otherwise the return value is an ADL error code (non-zero). \ref define_adl_results
int HIDDEN Pack_UMA_Size_Set(int IAdapterIndex, UMDKMDIF_UMA_SIZE_CONTROL_SET_MODE_INPUT *input, UMDKMDIF_UMA_SIZE_CONTROL_SET_MODE_OUTPUT *output);

// Message sent to check if SmartDC is supported or not by the platform.
#define WM_SDC_QUERY_SUPPORT            WM_USER + 252

// Message sent to check if SmartDC is enabled or not.
#define WM_SDC_QUERY_STATUS             WM_USER + 253

// Message sent to request SmartDC to be enabled.
#define WM_SDC_ENABLE_REQUEST           WM_USER + 254

// Message sent to request SmartDC to be disabled.
#define WM_SDC_DISABLE_REQUEST          WM_USER + 255

///
/// \brief
///
/// This function sends message to SmartDC window
/// \platform
/// \ALL
/// \param[in ]  messag The message to be sent.
/// \param[in ]  wParam The WParam of the sendMessage.
/// \param[out ]  iResponse The response value of the sendMessage.
/// \return If the function succeeds, the return value is ADL_OK (zero). Otherwise the return value is an ADL error code (non-zero). \ref define_adl_results
int HIDDEN Pri_SendMessageToSmartDC(int messag, WPARAM wParam, int* iResponse);

///
/// \brief
///
/// This function implements a CI call to set SmartMux control mode to enabled/disabled
/// \platform
/// \WIN
/// \param[in ]  IAdapterIndex The index of the desired adapter.
/// \param[in ]  input is data structure  /ref UMDKMDIF_SMART_MUX_SET_CONTROL_INPUT
/// \param[out ] output is data structure /ref UUMDKMDIF_SMART_MUX_SET_CONTROL_OUTPUT.
/// \return If the function succeeds, the return value is ADL_OK (zero). Otherwise the return value is an ADL error code (non-zero). \ref define_adl_results
int HIDDEN Pack_SmartMux_Control_Set(int IAdapterIndex, UMDKMDIF_SMART_MUX_SET_CONTROL_INPUT *input, UMDKMDIF_SMART_MUX_SET_CONTROL_OUTPUT *output);

///
/// \brief
///
/// This function implements a CI call to get SmartMux control mode
/// \platform
/// \WIN
/// \param[in ]  IAdapterIndex The index of the desired adapter.
/// \param[in ]  input is data structure  /ref UMDKMDIF_SMART_MUX_GET_CONTROL_INPUT
/// \param[out ] output is data structure /ref UUMDKMDIF_SMART_MUX_GET_CONTROL_OUTPUT.
/// \return If the function succeeds, the return value is ADL_OK (zero). Otherwise the return value is an ADL error code (non-zero). \ref define_adl_results
int HIDDEN Pack_SmartMux_Control_Get(int IAdapterIndex, UMDKMDIF_SMART_MUX_GET_CONTROL_INPUT *input, UMDKMDIF_SMART_MUX_GET_CONTROL_OUTPUT *output);

///
/// \brief
///
/// This function implements a CI call to get SmartMux current switch state (APU / dGPU)
/// \platform
/// \WIN
/// \param[in ]  IAdapterIndex The index of the desired adapter.
/// \param[in ]  input is data structure  /ref UMDKMDIF_SMART_MUX_GET_STATE_INPUT
/// \param[out ] output is data structure /ref UUMDKMDIF_SMART_MUX_GET_STATE_OUTPUT.
/// \return If the function succeeds, the return value is ADL_OK (zero). Otherwise the return value is an ADL error code (non-zero). \ref define_adl_results
int HIDDEN Pack_SmartMux_State_Get(int IAdapterIndex, UMDKMDIF_SMART_MUX_GET_STATE_INPUT *input, UMDKMDIF_SMART_MUX_GET_STATE_OUTPUT *output);

///
/// \brief
///
/// This function implements a CI call to get SmartMux feature support status
/// \platform
/// \WIN
/// \param[in ]  IAdapterIndex The index of the desired adapter.
/// \param[in ]  input is data structure  /ref UMDKMDIF_SMART_MUX_GET_SUPPORT_INPUT
/// \param[out ] output is data structure /ref UUMDKMDIF_SMART_MUX_GET_SUPPORT_OUTPUT.
/// \return If the function succeeds, the return value is ADL_OK (zero). Otherwise the return value is an ADL error code (non-zero). \ref define_adl_results
int HIDDEN Pack_SmartMux_Support_Get(int IAdapterIndex, UMDKMDIF_SMART_MUX_GET_SUPPORT_INPUT *input, UMDKMDIF_SMART_MUX_GET_SUPPORT_OUTPUT *output);

///
/// \brief
///
/// This function implements a CI call to get SmartMux cause for the mux switch failure
/// \platform
/// \WIN
/// \param[in ]  IAdapterIndex The index of the desired adapter.
/// \param[in ]  input is data structure  /ref UMDKMDIF_SMART_MUX_GET_SWITCH_FAILURE_INPUT
/// \param[out ] output is data structure /ref UUMDKMDIF_SMART_MUX_GET_SWITCH_FAILURE_OUTPUT.
/// \return If the function succeeds, the return value is ADL_OK (zero). Otherwise the return value is an ADL error code (non-zero). \ref define_adl_results
int HIDDEN Pack_SmartMux_Switch_Failure_Get(int IAdapterIndex, UMDKMDIF_SMART_MUX_GET_SWITCH_FAILURE_INPUT *input, UMDKMDIF_SMART_MUX_GET_SWITCH_FAILURE_OUTPUT *output);
#endif /* AMD_PACK_H_ */

