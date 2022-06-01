/*********************************************************************************************************************\
*  Module Name    amd_xeclient.h
*  Project        XInput Emulator
*  Device
*
*  Description    The service class.  All of the service code is here.  Also the WTS message processing occurs here.
*
*  Copyright (c) 2019 Advanced Micro Devices, Inc. (unpublished)
*
*  All rights reserved.  This notice is intended as a precaution against inadvertent publication and does not imply
*  publication or any waiver of confidentiality.  The year included in the foregoing notice is the year of creation
*  of the work.
*
\*********************************************************************************************************************/

#ifndef AMD_XECLIENTCOMM_H_
#define AMD_XECLIENTCOMM_H_

enum amdxe_status
{
    amdxe_status__success                     = 0,
    amdxe_status__bus_not_found               = 1,
    amdxe_status__no_free_slot                = 2,
    amdxe_status__invalid_controller          = 3,
    amdxe_status__removal_failed              = 4,
    amdxe_status__already_connected           = 5,
    amdxe_status__controller_not_initialized  = 6,
    amdxe_status__controller_not_plugged_in   = 7,
    amdxe_status__bus_version_mismatch        = 8,
    amdxe_status__bus_access_failed           = 9,
    amdxe_status__callback_already_registered = 10,
    amdxe_status__controller_access_failed    = 11,
    amdxe_status__bus_invalid_handle          = 12,
    amdxe_status__user_indexout_of_range      = 13,
    amdxe_status__invalid_parameter           = 14,
};


// XUSB report format.
typedef struct ADLAmdxeXusbReport_
{
    unsigned short	iButtons;
    unsigned char	cLeftTrigger;
    unsigned char	cRightTrigger;
    short			iThumbLX;
    short			iThumbLY;
    short			iThumbRX;
    short			iThumbRY;
}ADLAmdxeXusbReport;

typedef struct ADLAmdxeVibration_
{
    unsigned char cLeft;
    unsigned char cRight;
} ADLAmdxeVibration;

enum ADL_AMDXE_CONTROLLER_TYPE
{
    ADL_XBOX360,
};

typedef void* ADL_AMDXE_CONTROLLER_HANDLE;

#endif // AMDXEClient_h__
