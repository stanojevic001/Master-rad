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

#ifndef AMD_XECLIENT_H_
#define AMD_XECLIENT_H_

#include "amd_xeClient_comm.h"

// Version 1
// Used by ReLive Remote Play only - to be deprecated

// acquire AMDXE bus access
// the client handle allows client to access the bus later on
ADL_EXTERNC int EXPOSED ADL2_Xe_Bus_Access_Acquire(unsigned long long* lpClientHandle);

// release AMDXE bus access
ADL_EXTERNC int EXPOSED ADL2_Xe_Bus_Access_Release(unsigned long long hClientHandle);

// allocate/disgard a controller
ADL_EXTERNC int EXPOSED  ADL2_Xe_Controller_Allocate(ADL_AMDXE_CONTROLLER_TYPE xEControlType, unsigned long long  *controller);

ADL_EXTERNC int EXPOSED  ADL2_Xe_Controller_Free(unsigned long long controller);

// request plug in or unplug a controller
ADL_EXTERNC int EXPOSED ADL2_Xe_Controller_Plugin(unsigned long long hClientHandle, unsigned long long controller);

ADL_EXTERNC int EXPOSED ADL2_Xe_Controller_Unplug(unsigned long long hClientHandle, unsigned long long controller);

// Send the updated report to bus driver for further processing.
ADL_EXTERNC int EXPOSED ADL2_Xe_Controller_Update(unsigned long long hClientHandle, unsigned long long controller, ADLAmdxeXusbReport xEControlReport);




// Version 2
// Simplified APIs, bus acquire/release and controller allocate/free will be handled by ADL internally

///
/// \brief Create a new controller and plug in
/// 
/// \platform 
/// \Windows 10
/// \param[in] context: ADL context
/// \param[in] type: type of controller. only supported value is xbox360
/// \param[out] controller: a handle to the controller created
/// \return int, refer to amdxe_status
ADL_EXTERNC int EXPOSED ADL2_Xe_ControllerX2_Plugin(ADL_CONTEXT_HANDLE context, ADL_AMDXE_CONTROLLER_TYPE type, ADL_AMDXE_CONTROLLER_HANDLE *controller);

///
/// \brief Unplug and remove the controller
/// 
/// \platform 
/// \Windows 10
/// \param[in] context: ADL context
/// \param[in] controller: a handle to the controller
/// \return int, refer to amdxe_status
ADL_EXTERNC int EXPOSED ADL2_Xe_ControllerX2_Unplug(ADL_CONTEXT_HANDLE context, ADL_AMDXE_CONTROLLER_HANDLE controller);

///
/// \brief Unplug and remove the controller
/// 
/// \platform 
/// \Windows 10
/// \param[in] context: ADL context
/// \param[in] controller: a handle to the controller
/// \param[in] report: button and axis states of the controller
/// \return int, refer to amdxe_status
ADL_EXTERNC int EXPOSED ADL2_Xe_ControllerX2_Update(ADL_CONTEXT_HANDLE context, ADL_AMDXE_CONTROLLER_HANDLE controller, ADLAmdxeXusbReport report);

///
/// \brief Function to get the vibration states of a controller
/// 
/// \platform 
/// \Windows 10
/// \param[in] context: ADL context
/// \param[in] controller: a handle to the controller
/// \param[in] timeout: timeout for the get call, in milliseconds
/// \param[out] vibration: left and right motor speed of the controller
/// \return int, refer to amdxe_status
ADL_EXTERNC int EXPOSED ADL2_Xe_Controller_Vibration_Get(ADL_CONTEXT_HANDLE context, ADL_AMDXE_CONTROLLER_HANDLE controller, DWORD timeout, ADLAmdxeVibration* vibration);


#endif // AMDXEClient_h__
