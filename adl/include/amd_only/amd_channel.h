///
///  Copyright (c) 2008 - 2021 Advanced Micro Devices, Inc.

///  THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
///  EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
///  WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.

/// \file amd_channel.h
/// \brief Contains AMD internal channel-related definitions and functions for \ALL platforms.
///
/// This file contains AMD internal functions, variables, and definitions which are common to both
/// channels of Windows and Linux platforms. These functions, variables, and definitions 
/// are not to be seen or exported outside of the ADL scope.
///

#ifndef AMD_CHANNEL_H_
#define AMD_CHANNEL_H_

#ifndef ADL_EXTERNC
#ifdef __cplusplus
#define ADL_EXTERNC extern "C"
#else
#define ADL_EXTERNC
#endif
#endif

#ifndef EXPOSED
#define EXPOSED
#endif /* EXPOSED */

/////////////////////////////////////////////////////////////////////////////////////////////
/// \brief Structure containing information about channel that is used as input/output of driver calls.
///
/// This structure is used to store input and/or output information about a driver call. This structure is used by all OS platforms and driver calls.
/// The information can not be returned to the user.  
/// \nosubgrouping
////////////////////////////////////////////////////////////////////////////////////////////

typedef unsigned int D3DDDI_VIDEO_PRESENT_SOURCE_ID;

typedef unsigned int D3DKMT_HANDLE;

typedef struct _ChannelPacket
{
	int iAdapterIndex;  ///< The Adapter index representing an active driver.
	int iInputSize; ///< The input buffer size. If the input data buffer is NULL, the size is 0.
	void *lpInputData; ///< The input data buffer, which can be NULL.
	int iOutputSize;   ///< The output buffer size. If the output buffer is NULL, the size is 0. 
	void *lpOutputData; ///< The output data buffer, which can be NULL.
	int iCWDDECode;	///< If 1, the Send function returns the actual CWDDE error code instead of the ADL mapped one.
	D3DKMT_HANDLE hDevice; ///< The Adapter device handle, which is optional and can be NULL.

} ChannelPacket, *LPChannelPacket;

typedef struct _ChannelPacketX2
{
	int iAdapterIndex;  ///< The Adapter index representing an active driver.
	int iBus;   ///< The BDF that's to be passed as an escape parameter.
	int iDevice;   ///< The BDF that's to be passed as an escape parameter.
	int iFunction;   ///< The BDF that's to be passed as an escape parameter.
	int iInputSize; ///< The input buffer size. If the input data buffer is NULL, the size is 0.
	void *lpInputData; ///< The input data buffer, which can be NULL.
	int iOutputSize;   ///< The output buffer size. If the output buffer is NULL, the size is 0. 
	void *lpOutputData; ///< The output data buffer, which can be NULL.
	int iCWDDECode;	///< If 1, the Send function returns the actual CWDDE error code instead of the ADL mapped one.
	D3DKMT_HANDLE hDevice; ///< The Adapter device handle, which is optional and can be NULL.

} ChannelPacketX2, *LPChannelPacketX2;

///
/// \brief Function to send a driver call package to the channel.
/// 
/// This function will be implemented in each channel to accomplish escape calls.
///
/// \platform
/// \ALL
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in] cpInfo The driver call package.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise, the return value is an ADL error code. \ref define_adl_results
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
ADL_EXTERNC int EXPOSED ADL2_Send (ADL_CONTEXT_HANDLE context, ChannelPacket* cpInfo );

///
/// \brief Function to send a driver call package to the channel.
/// 
/// This function will be implemented in each channel to accomplish escape calls.
///
/// \platform
/// \ALL
/// \param[in] cpInfo The driver call package.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise, the return value is an ADL error code. \ref define_adl_results
ADL_EXTERNC int EXPOSED Send ( ChannelPacket* cpInfo );

///
/// \brief Function to send a driver call package to the channel.
/// 
/// This function will be implemented in each channel to accomplish escape calls.
///
/// \platform
/// \ALL
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in] cpInfo The driver call package.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise, the return value is an ADL error code. \ref define_adl_results
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
ADL_EXTERNC int EXPOSED ADL2_SendX2 (ADL_CONTEXT_HANDLE context, ChannelPacketX2* cpInfo );

///
/// \brief Function to send a driver call package to the channel.
/// 
/// This function will be implemented in each channel to accomplish escape calls.
///
/// \platform
/// \ALL
/// \param[in] cpInfo The driver call package.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise, the return value is an ADL error code. \ref define_adl_results
ADL_EXTERNC int EXPOSED SendX2 ( ChannelPacketX2* cpInfo );

#if defined (LINUX)
///
/// \brief Function to send BDF information to ADL.
/// 
/// This function is a temporary workaround to allow aticonfig to directly pass BDF (bus number, device number, and function number) information of a specified adapter to ADL.
///
/// \platform
/// \ALL
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in] cpInfo The driver call package.
/// \param[in] bdf The desired bus number, device number, and function number.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise, the return value is an ADL error code. \ref define_adl_results 
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
ADL_EXTERNC int EXPOSED ADL2_SendBDF (ADL_CONTEXT_HANDLE context, ChannelPacket* cpInfo, int bdf);

///
/// \brief Function to send BDF information to ADL.
/// 
/// This function is a temporary workaround to allow aticonfig to directly pass BDF (bus number, device number, and function number) information of a specified adapter to ADL.
///
/// \platform
/// \ALL
/// \param[in] cpInfo The driver call package.
/// \param[in] bdf The desired bus number, device number, and function number.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise, the return value is an ADL error code. \ref define_adl_results 
ADL_EXTERNC int EXPOSED SendBDF ( ChannelPacket* cpInfo, int bdf);
#endif /* (LINUX) */

#endif /* AMD_CHANNEL_H_ */

