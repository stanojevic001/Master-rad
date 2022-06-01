///
///  Copyright (c) 2008 - 2021 Advanced Micro Devices, Inc.
 
///  THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
///  EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
///  WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.

/// \file amd_remotedisplay.h
/// \brief Contains all AMD remote display functions exposed by ADL for \WIN7 and \WIN8 platforms.
///
/// This file contains all AMD internal remote display-related functions exposed by ADL for \WIN7 and \Win8 platforms.
/// All functions found in this file can be used as a reference to ensure
/// the specified function pointers can be used by the appropriate runtime
/// dynamic library loaders. This header file is for AMD internal use only.

#ifndef AMD_REMOTEDISPLAY_H_
#define AMD_REMOTEDISPLAY_H_

#include "adl_defines.h"
#include "adl_structures.h"
#include "amd_structures.h"

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

/// \Message ID Definitions for MessageID in data structure \ref ADLWDNotificationData, which is used by \ref ADL_WD_CALLBACK
/// @{

/// When wireless adapter is enabled/disabled, driver installed/un-installed
#define ADL_WFD_WirelessAdapter_Refresh_Required         1

/// When the radio is switched ON to OFF or OFF to ON
#define ADL_WFD_WirelessAdapter_Radio_Refresh_Required   2

/// When WFD devices found
#define ADL_WFD_PeerDevice_Refresh_Required              3

/// When WFD discovering is completed
#define ADL_WFD_Discover_Complete			             4

/// When WFD discovering failed
#define ADL_WFD_Discover_Fail                            5

/// When a wifi direct link is created successfully
#define ADL_WFD_Link_Created	                         6

/// When a wifi direct link created failed
#define ADL_WFD_Link_Created_Fail	                     7

///When push button is needed during wifi direct link creating
#define ADL_WFD_Link_Create_WPS_PBC_Required             8

///When PIN is needed during wifi direct link creating
#define ADL_WFD_Link_Create_WPS_PIN_Required             9

/// When a wifi direct link is disconnected
#define ADL_WFD_Link_Disconnected                        10

/// When WPS process finish, let user accept the connection
#define ADL_WFD_Link_Create_Accept                        11
 
/// @} 
 

/// \Reason ID Definitions for ReasonID in data structure \ref ADLWDNotificationData, which is used by\ref ADL_WD_CALLBACK
/// @{

///Wifi direct connection creation failed because of GO negotiation
#define ADL_WFD_Negotiation_Failed         1

///Wifi direct connection creation failed because of taking long time(more than 90 seconds)
#define ADL_WFD_WPS_Timeout                2

/// @}

/// \Caps bit vector definition for iOption, which is used by function \ref ADL_RemoteDisplay_Support_Caps
/// @{

/// GPU supports wireless display
#define ADL_GPU_Wireless_Suppport  0x0001

///Virtual wireless adapter availabilty
#define ADL_VirtualWirelessAdapter_Available  0x0002

///Vendor SDK availability
#define ADL_WIFIDirect_SDK_Available  0x0004

///WDST availablity
#define ADL_WDST_Available  0x0008

/// @}


/// \Caps bit vector definition for value in data structure \ref ADLWFDDeviceInfo , which is used by function \ref ADL_RemoteDisplay_WFDDeviceInfo_Get
/// @{

/// The device was paired before
#define ADL_WFD_Device_UsedToBe_Paired  0x0001

/// The device can be discovered
#define ADL_WFD_Device_Curent_In_Range  0x0002

/// @}

// \Constant is used in data structure \ref ADLWFDDeviceInfo.
/// @{

/// The string length of device name
#define ADL_WFD_DEVICE_NAME_MAX_LENGTH  64

/// @}


/// \Bit vector definition for StatusValue in data structure \ref ADLWFDDeviceStatusInfo , which is used by function \ref ADL_RemoteDisplay_WFDDevice_StatusInfo_Get
/// @{

///The device is connected to wifi direct network
#define ADL_WFD_Device_Connected  0x0001

///The device is connected to other virtual wireless adapter
#define ADL_WFD_Device_Connected_To_OtherVirtualWirelessAdapter  0x0002

///The device is connected to other system
#define ADL_WFD_Device_Connected_To_OtherSystem  0x0004
 
/// @}

///////////////////////////////////////////////////////////////////////////
// WPS method Enumeration
///////////////////////////////////////////////////////////////////////////

typedef enum _ADL_PEERNET_WFD_DISCOVERED_WPS_CONFIG_METHOD
{
	ADL_PEERNET_WFD_WPS_PIN    	= 0x0001,
	ADL_PEERNET_WFD_WPS_PUSHBUTTON 	= 0x0002,
  	 
} ADL_PEERNET_WFD_DISCOVERED_WPS_CONFIG_METHOD;


///////////////////////////////////////////////////////////////////////////
// Vendor SDK selection rule Enumeration
///////////////////////////////////////////////////////////////////////////
typedef enum _ADL_WIRELESS_VENDOR_SDK_SECTION_RULES
{
	ANYVENDOR  	= 0, // select one of available vendors by ADL
	BROADCOM    = 1, // Broadcom SDK
	RALINK      = 2, // Ralink SDK
	ATHEROS     = 3  // Atheros SDK
	 
} ADL_WIRELESS_VENDOR_SDK_SECTION_RULES;

///////////////////////////////////////////////////////////////////////////
// WI-FI device type Enumeration
///////////////////////////////////////////////////////////////////////////

typedef enum _ADL_PEERNET_WFD_DEVICE_TYPE
{
	ADL_WFD_DEVICE_TYPE_SRC=0,			// WFD source 
	ADL_WFD_DEVICE_TYPE_PRIM_SINK =1,	// WFD primary sink 
	ADL_WFD_DEVICE_TYPE_SEC_SINK =2,		// WFD second sink 
	ADL_WFD_DEVICE_TYPE_SRC_PRIM_SINK=3	// WFD srouce and primary sink 
  	 
} ADL_PEERNET_WFD_DEVICE_TYPE;

/////////////////////////////////////////////////////////////////////////////////////////////
/// \brief Structure containing information about virtual wireless adapter info.
///
/// This structure is used to store information about virtual wireless adapter.
/// This structure is used by internal ADL implementation.
/// \nosubgrouping
////////////////////////////////////////////////////////////////////////////////////////////
typedef struct ADLVirtualWirelessAdapterInfo
{
	ADLGUID virtualWirelessAdapterInfoGuid; ///< The GUID of the virtual wireless addapter 
	wchar_t strVirtualWirelessAdapterDesc[256];   ///< The description of the virtual wireless adapter
	ADLGUID physicalWirelessAdapterInfoGuid;///< The GUID of the physical wireless addapter
    wchar_t strPhysicalWirelessAdapterDesc[256];  ///< The description of the physical wireless adapter

} ADLVirtualWirelessAdapterInfo;

/////////////////////////////////////////////////////////////////////////////////////////////
/// \brief Structure containing information about connection info for WDST component.
///
/// This structure is used to store information that WDST needed in order to do socket connection with wireless display receiver box.
/// This structure is used by internal ADL implementation.
/// \nosubgrouping
////////////////////////////////////////////////////////////////////////////////////////////
typedef struct _ADLWDSTConnectionInfo
{
 	ADLBdf GPUBdf;            ///< The BDF of a GPU, which supports wireless display 
	long   lDeviceIPAddress;  ///< The IP address of wireless receiver box
	int    iPortNumber;       ///< The port number, which is used by WDST to communicate with the service in receiver box 
    int    iDisplayIndex;     ///< The wireless display index, which is generated from AMD driver
	ADLBdf DisplayGPUBdf;     ///< The GPU BDF of the wireless display will be connected. Usually, the GPUBdf and DisplayGPUBdf is the same. 
	                          ///  However, they can be different for non-local display 
	int    iConnectValue;     ///< For the future use
    int    iConnectMask;      ///< The mask value of connectValue
        
} ADLWDSTConnectionInfo;

/////////////////////////////////////////////////////////////////////////////////////////////
/// \brief Structure containing information from call back fucntion when the virtual wireless adapter status change or trigged by discovering
///         pairing/connecting/disconnecting.
///
/// This structure is used to store information about notification data.
/// This structure is used by internal ADL implementation.
/// \nosubgrouping
////////////////////////////////////////////////////////////////////////////////////////////
typedef struct _ADLWDNotificationData
{
 	ADLGUID  VirtualWirelessAdapterGuid;  ///< Specifies the vrtual adapter GUID of notification soure
    char  strPeerDeviceMacAddress[8];     ///< Specifies the MAC address of receiver box 
    int   iMessageID;                     ///< Specifies the message ID
	int   iReason;						  ///< Specifies the reason  ID to explain why the message ID was sent
	int   iValue;						  ///< For the future use	
	int   iMask;                          ///< The mask value of the Value
        
} ADLWDNotificationData;


/////////////////////////////////////////////////////////////////////////////////////////////
/// \brief Structure containing information about receiver box.
///
/// This structure is used to store information about receiver data.
/// This structure is used by internal ADL implementation.
/// \nosubgrouping
////////////////////////////////////////////////////////////////////////////////////////////
typedef struct _ADLWFDDeviceInfo
{
 char strPeerDeviceMacAddress[8];                          ///< The receiver box MAC address
	 wchar_t strPeerDeviceName[32];                            ///< The receiver box name
 int  iSupportedWPSConfigMethods;                          ///< The supported WPS methodes
 char strPeerDeviceModel[32];                              ///< The receiver box model
 int  iValue;						                       ///< For the future use	
 int  iMask;                                               ///< The mask value of the Value
 int  iSignalStrength;                                     ///< The signal strength of receiver box, detected by source device

} ADLWFDDeviceInfo;

 

/////////////////////////////////////////////////////////////////////////////////////////////
/// \brief Structure containing status information about wireless display receiver box.
///
/// This structure is used to store information about receiver data.
/// This structure is used by internal ADL implementation.
/// \nosubgrouping
////////////////////////////////////////////////////////////////////////////////////////////
typedef struct _ADLWFDDeviceStatusInfo
{
int  iDeviceIPAddress; // The IP address of receiver box
int  iStatusValue;     // The bit vector of device status 
int  iStatusMask;      // The mask bit vectors of StatusValue
} ADLWFDDeviceStatusInfo;

/////////////////////////////////////////////////////////////////////////////////////////////
/// \brief Structure containing WDSP information.
///
/// This structure is used to store information about WDSP data.
/// This structure is used by internal ADL implementation.
/// \nosubgrouping
////////////////////////////////////////////////////////////////////////////////////////////
 
typedef struct _ADLWFDWDSPSettings
{
	int		  iWFDDeviceEnabled;  // WD device enabled ot not
	ADL_PEERNET_WFD_DEVICE_TYPE	iWFDDeviceType; //WD device type
	int			iTCPPort; // RTSP TCP port
	int			iMaxTPut; // Max mbps	 
} ADLWFDWDSPSettings;


/// The call back funtion pointer for wireless display notification 
typedef void* ( __stdcall *ADL_WD_CALLBACK )( ADLWDNotificationData,void *pContext );

///
///\brief Function to initialize wireless vendor SDK 
/// 
/// This function initializes the wireless vendor SDK and WDST COM interface  
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in]  iWirelessVendorSelectRule An integer variable that indicates which wireless vendor SDK will be selected in ADL. The possible rules defined in
///             \ref ADL_WIRELESS_VENDOR_SDK_SECTION_RULES.
/// \platform
/// \WIN7 and \WIN8
/// \remark     The function should be called first before calling other ADL wireless display functions
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results 
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
ADL_EXTERNC int EXPOSED ADL2_RemoteDisplay_Initialize(ADL_CONTEXT_HANDLE context,int iWirelessVendorSelectRule);

///
///\brief Function to initialize wireless vendor SDK 
/// 
/// This function initializes the wireless vendor SDK and WDST COM interface  
/// \param[in]  iWirelessVendorSelectRule An integer variable that indicates which wireless vendor SDK will be selected in ADL. The possible rules defined in
///             \ref ADL_WIRELESS_VENDOR_SDK_SECTION_RULES.
/// \platform
/// \WIN7 and \WIN8
/// \remark     The function should be called first before calling other ADL wireless display functions
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results 
ADL_EXTERNC int EXPOSED ADL_RemoteDisplay_Initialize(int iWirelessVendorSelectRule);
 
///
///\brief Function to un-initialize wireless vendor SDK 
/// 
/// This function un-initializes the wireless vendor SDK and WDST COM interface  
/// \platform
/// \WIN7 and \WIN8
/// \remark     The function should be called when the application exits
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results 
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
ADL_EXTERNC int EXPOSED ADL2_RemoteDisplay_Destroy(ADL_CONTEXT_HANDLE context );

///
///\brief Function to un-initialize wireless vendor SDK 
/// 
/// This function un-initializes the wireless vendor SDK and WDST COM interface  
/// \platform
/// \WIN7 and \WIN8
/// \remark     The function should be called when the application exits
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results 
ADL_EXTERNC int EXPOSED ADL_RemoteDisplay_Destroy( );

///
///\brief Function to get the flag , which indicates which components in the system supports wireless display. 
/// 
/// This function detects a couple of Caps and availability: GPU wireless adapter cap, vendor wireless adapter cap, vendor SDK availablity, WDST availablity.
/// There are four kinds of caps: 
/// The GPU wireless caps: \ref ADL_GPU_Wireless_Suppport  
/// The virtual wireless adapter caps \ref ADL_VirtualWirelessAdapter_Available
/// The vendor SDK caps \ref ADL__WIFIDirect_SDK_Available
/// The WDST caps \ref ADL__WDST_Available
/// If all the above four conditions are satisfied, the wireless display functionality should be available
/// \platform
/// \WIN7 and \WIN8
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[out] lpWirelessDisplaySupportValue Pointer to an integer variable,which indicates wireless display fucntionality caps   
/// \param[out] lpWirelessDisplaySupportmask Pointer to an integer variable, which indicates which bits of
///  lpWirelessDisplaySupportValue are valid.
/// \param[in]  iOption  Integer that indicates which kinds of caps need to be checked. This function supports partial caps check. 
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results 
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
ADL_EXTERNC int EXPOSED ADL2_RemoteDisplay_Support_Caps(ADL_CONTEXT_HANDLE context,int iAdapterIndex, int *lpWirelessSupportValue,int *lpWirelessSupportMask, int iOption);

///
///\brief Function to get the flag , which indicates which components in the system supports wireless display. 
/// 
/// This function detects a couple of Caps and availability: GPU wireless adapter cap, vendor wireless adapter cap, vendor SDK availablity, WDST availablity.
/// There are four kinds of caps: 
/// The GPU wireless caps: \ref ADL_GPU_Wireless_Suppport  
/// The virtual wireless adapter caps \ref ADL_VirtualWirelessAdapter_Available
/// The vendor SDK caps \ref ADL__WIFIDirect_SDK_Available
/// The WDST caps \ref ADL__WDST_Available
/// If all the above four conditions are satisfied, the wireless display functionality should be available
/// \platform
/// \WIN7 and \WIN8
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[out] lpWirelessDisplaySupportValue Pointer to an integer variable,which indicates wireless display fucntionality caps   
/// \param[out] lpWirelessDisplaySupportmask Pointer to an integer variable, which indicates which bits of
///  lpWirelessDisplaySupportValue are valid.
/// \param[in]  iOption  Integer that indicates which kinds of caps need to be checked. This function supports partial caps check. 
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results 
ADL_EXTERNC int EXPOSED ADL_RemoteDisplay_Support_Caps(int iAdapterIndex, int *lpWirelessSupportValue,int *lpWirelessSupportMask, int iOption);
 
 ///\brief Function to get virtual wireless adapter info list  
/// 
/// This function returns the list of virtual wireless adapter info list in the system. 
/// \platform
/// \WIN7 and \WIN8
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[out] lpNumVirtualWirelessAdapter   Pointer to a variable, which indicates the number of virtual wireless adapters in the system. 
/// \param[out] lppVirtualWirelessAdapterInfoList     Pointer of a pointer to a variable with type \ref ADLVirtualWirelessAdapterInfo, 
///             which contains virtual wireless adapter info and its physical wireless adapter info. 
///             Application does not need to allocate memory, however it should free the pointer since the memory is allocated by the ADL call back function.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results 
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
ADL_EXTERNC int EXPOSED ADL2_RemoteDisplay_VirtualWirelessAdapter_Info_Get(ADL_CONTEXT_HANDLE context,int *lpNumVirtualWirelessAdapter,  ADLVirtualWirelessAdapterInfo **lppVirtualWirelessAdapterInfoList);

 ///\brief Function to get virtual wireless adapter info list  
/// 
/// This function returns the list of virtual wireless adapter info list in the system. 
/// \platform
/// \WIN7 and \WIN8
/// \param[out] lpNumVirtualWirelessAdapter   Pointer to a variable, which indicates the number of virtual wireless adapters in the system. 
/// \param[out] lppVirtualWirelessAdapterInfoList     Pointer of a pointer to a variable with type \ref ADLVirtualWirelessAdapterInfo, 
///             which contains virtual wireless adapter info and its physical wireless adapter info. 
///             Application does not need to allocate memory, however it should free the pointer since the memory is allocated by the ADL call back function.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results 
ADL_EXTERNC int EXPOSED ADL_RemoteDisplay_VirtualWirelessAdapter_Info_Get(int *lpNumVirtualWirelessAdapter,  ADLVirtualWirelessAdapterInfo **lppVirtualWirelessAdapterInfoList);
 

///\brief Function to check if the inputted virtual wireless adapter is in use 
/// 
/// This function returns whether the input wireless adapter is currently in use
/// \platform
/// \WIN7 and \WIN8
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in] virtualWirelessAdapterInfoGuid   A variable that indicates the GUID of the inputted virtual wireless adapter   
/// \param[out] lpInUse     Pointer to an integer variable, which indicates the inputted virtual wireless adapter is in use or not. 
///                         Its value is 1 if the virtual wireless adapter is in use. oterwise its value is 0. 
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results 
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
ADL_EXTERNC int EXPOSED ADL2_RemoteDisplay_VirtualWirelessAdapter_InUse_Get(ADL_CONTEXT_HANDLE context,ADLGUID virtualWirelessAdapterInfoGuid, int *lpInUse);

///\brief Function to check if the inputted virtual wireless adapter is in use 
/// 
/// This function returns whether the input wireless adapter is currently in use
/// \platform
/// \WIN7 and \WIN8
/// \param[in] virtualWirelessAdapterInfoGuid   A variable that indicates the GUID of the inputted virtual wireless adapter   
/// \param[out] lpInUse     Pointer to an integer variable, which indicates the inputted virtual wireless adapter is in use or not. 
///                         Its value is 1 if the virtual wireless adapter is in use. oterwise its value is 0. 
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results 
ADL_EXTERNC int EXPOSED ADL_RemoteDisplay_VirtualWirelessAdapter_InUse_Get(ADLGUID virtualWirelessAdapterInfoGuid, int *lpInUse);

///\brief Function to check if the radio of the physical wireless adapter that the inputted virtual wireless adapter associated is on or off 
/// 
/// This function returns the on/off state of the input wireless adapter.
/// \platform
/// \WIN7 and \WIN8
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in] virtualWirelessAdapterInfoGuid   a variable that indicates the GUID of the inputted virtual wirless adapter   
/// \param[out] lpRadioState     pointer to an integer variable, which indicates the inputted virtual wireless adapter radio is On or OFF. 1: ON; 0:OFF   
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results 
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
ADL_EXTERNC int EXPOSED ADL2_RemoteDisplay_VirtualWirelessAdapter_RadioState_Get(ADL_CONTEXT_HANDLE context,ADLGUID virtualWirelessAdapterInfoGuid, int *lpRadioState);

///\brief Function to check if the radio of the physical wireless adapter that the inputted virtual wireless adapter associated is on or off 
/// 
/// This function returns the on/off state of the input wireless adapter.
/// \platform
/// \WIN7 and \WIN8
/// \param[in] virtualWirelessAdapterInfoGuid   a variable that indicates the GUID of the inputted virtual wirless adapter   
/// \param[out] lpRadioState     pointer to an integer variable, which indicates the inputted virtual wireless adapter radio is On or OFF. 1: ON; 0:OFF   
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results 
ADL_EXTERNC int EXPOSED ADL_RemoteDisplay_VirtualWirelessAdapter_RadioState_Get(ADLGUID virtualWirelessAdapterInfoGuid, int *lpRadioState);

///\brief Function to change the WPS of virtual wireless adapter
/// 
/// This function changes the WPS method of PC. One of PC roles in WIFI direcvt network is wifi direct device. 
///
/// \platform
/// \WIN7 and \WIN8
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in] virtualWirelessAdapterInfoGuid   a variable that indicates the GUID of the inputted virtual wireless adapter   
/// \param[in] iWPSMethod  Integer variable, which indicates the WPS method will be used: PBC or PIN_Display
/// \param[in] lpWPSString Pointer to a string , which stores the WPS string. If WPS is PIN_Display, the PIN is needed. It can be null if the WPS is PBC
/// \param[in] iWPSStringlen   integer variable, which indicates the length of the WPS string.  
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results 
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
ADL_EXTERNC int EXPOSED ADL2_RemoteDisplay_VirtualWirelessAdapter_WPSSetting_Change(ADL_CONTEXT_HANDLE context,ADLGUID virtualWirelessAdapterInfoGuid, int iWPSMethod,char *lpWPSString, int iWPSStringLen );

///\brief Function to change the WPS of virtual wireless adapter
/// 
/// This function changes the WPS method of PC. One of PC roles in WIFI direcvt network is wifi direct device. 
///
/// \platform
/// \WIN7 and \WIN8
/// \param[in] virtualWirelessAdapterInfoGuid   a variable that indicates the GUID of the inputted virtual wireless adapter   
/// \param[in] iWPSMethod  Integer variable, which indicates the WPS method will be used: PBC or PIN_Display
/// \param[in] lpWPSString Pointer to a string , which stores the WPS string. If WPS is PIN_Display, the PIN is needed. It can be null if the WPS is PBC
/// \param[in] iWPSStringlen   integer variable, which indicates the length of the WPS string.  
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results 
ADL_EXTERNC int EXPOSED ADL_RemoteDisplay_VirtualWirelessAdapter_WPSSetting_Change(ADLGUID virtualWirelessAdapterInfoGuid, int iWPSMethod,char *lpWPSString, int iWPSStringLen );

///\brief Function to get current WPS method of virtual wireless adapter (PC) 
/// 
/// This function returns WPS method of the PC. If the WPS method is PIN, the PIN number will be returned as well. 
/// \platform
/// \WIN7 and \WIN8
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in] virtualWirelessAdapterInfoGuid   a variable that indicates the guid of the inputted virtual wireless adapter   
/// \param[out] lpWPSMethod  Pointer to an integer variable, which indicates the WPS method will be used: 
/// \param[out] lppWPSString  Pointer to pointer to a string , which stores the WPS string. If WPS is PBC, the string could be null. 
/// \param[out] lpWPSStringlen Pointer to an integer variable, which indicates the length of WPS string.  
/// \param[out] lpWPSTimeoutSeconds Pointer to an integer variable, which indicates the length of WPS timeout in seconds.  
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results 
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
ADL_EXTERNC int EXPOSED ADL2_RemoteDisplay_VirtualWirelessAdapter_WPSSetting_Get(ADL_CONTEXT_HANDLE context,ADLGUID virtualWirelessAdapterInfoGuid, int *lpWPSMethod,char **lppWPSString, int *lpWPSStringLen, int* lpWPSTimeoutSeconds );

///\brief Function to get current WPS method of virtual wireless adapter (PC) 
/// 
/// This function returns WPS method of the PC. If the WPS method is PIN, the PIN number will be returned as well. 
/// \platform
/// \WIN7 and \WIN8
/// \param[in] virtualWirelessAdapterInfoGuid   a variable that indicates the guid of the inputted virtual wireless adapter   
/// \param[out] lpWPSMethod  Pointer to an integer variable, which indicates the WPS method will be used: 
/// \param[out] lppWPSString  Pointer to pointer to a string , which stores the WPS string. If WPS is PBC, the string could be null. 
/// \param[out] lpWPSStringlen Pointer to an integer variable, which indicates the length of WPS string.  
/// \param[out] lpWPSTimeoutSeconds Pointer to an integer variable, which indicates the length of WPS timeout in seconds.  
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results 
ADL_EXTERNC int EXPOSED ADL_RemoteDisplay_VirtualWirelessAdapter_WPSSetting_Get(ADLGUID virtualWirelessAdapterInfoGuid, int *lpWPSMethod,char **lppWPSString, int *lpWPSStringLen, int* lpWPSTimeoutSeconds );
 
///\brief Function to change the WDSP of WFD device
/// 
/// This function changes the WDSP of WFD device. 
///
/// \platform
/// \WIN7 and \WIN8
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in] virtualWirelessAdapterInfoGuid   a variable that indicates the GUID of the inputted virtual wireless adapter   
/// \param[in] WDSPSettings  Data structurevariable, which indicates the WDSP settings
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results 
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
ADL_EXTERNC int EXPOSED ADL2_RemoteDisplay_WFDWDSPSettings_Set(ADL_CONTEXT_HANDLE context,ADLGUID virtualWirelessAdapterInfoGuid, ADLWFDWDSPSettings WDSPSettings );

///\brief Function to change the WDSP of WFD device
/// 
/// This function changes the WDSP of WFD device. 
///
/// \platform
/// \WIN7 and \WIN8
/// \param[in] virtualWirelessAdapterInfoGuid   a variable that indicates the GUID of the inputted virtual wireless adapter   
/// \param[in] WDSPSettings  Data structurevariable, which indicates the WDSP settings
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results 
ADL_EXTERNC int EXPOSED ADL_RemoteDisplay_WFDWDSPSettings_Set(ADLGUID virtualWirelessAdapterInfoGuid, ADLWFDWDSPSettings WDSPSettings );
 

///\brief Function to register virtual adapter change notification 
/// 
/// This function resgiter virtual wirless adapter change notification by passing call back function.
/// The actual sources to send notifications are: Virtual wireless adapter, WFD
/// \platform
/// \WIN7 and \WIN8
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in] lpCallback       Void pointer to a function.  
/// \param[in] lpWndHandle      A window handle,which ADL can post message using this handle. This is an optional.  
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results 
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
ADL_EXTERNC int EXPOSED ADL2_RemoteDisplay_Nofitiation_Register(ADL_CONTEXT_HANDLE context, ADL_WD_CALLBACK lpCallback,void*   lpWndHandle );

///\brief Function to register virtual adapter change notification 
/// 
/// This function resgiter virtual wirless adapter change notification by passing call back function.
/// The actual sources to send notifications are: Virtual wireless adapter, WFD
/// \platform
/// \WIN7 and \WIN8
/// \param[in] lpCallback       Void pointer to a function.  
/// \param[in] lpWndHandle      A window handle,which ADL can post message using this handle. This is an optional.  
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results 
ADL_EXTERNC int EXPOSED ADL_RemoteDisplay_Nofitiation_Register( ADL_WD_CALLBACK lpCallback,void*   lpWndHandle );

///\brief Function to un-register virtual adapter chnages notification 
/// 
/// This function un-resgiter virtual wirless adapter change notification
/// call back function 
/// \platform
/// \WIN7 and \WIN8
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results 
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
ADL_EXTERNC int EXPOSED ADL2_RemoteDisplay_Notification_UnRegister(ADL_CONTEXT_HANDLE context );

///\brief Function to un-register virtual adapter chnages notification 
/// 
/// This function un-resgiter virtual wirless adapter change notification
/// call back function 
/// \platform
/// \WIN7 and \WIN8
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results 
ADL_EXTERNC int EXPOSED ADL_RemoteDisplay_Notification_UnRegister( );
 
///\brief Function to trigger wifi direct devices discovering 
/// 
/// This function triggers the wifi device scan. The search criteria is hard coded in ADL
///  
/// \platform
/// \WIN7 and \WIN8
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in] virtualWirelessAdapterInfoGuid   A variable that indicates the GUID of the inputted virtual wirless adapter.
/// \remark   After calling the function, the application will get ADL call back if a new WFD devce found, or discovering completed or
///           discovering failed. if a new device found, the application can call \ref ADL_RemoteDisplay_WFDDeviceInfo_Get to get
///           WFD device info list.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results 
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
ADL_EXTERNC int EXPOSED ADL2_RemoteDisplay_WFDDiscover_Start(ADL_CONTEXT_HANDLE context,ADLGUID virtualWirelessAdapterInfoGuid);

///\brief Function to trigger wifi direct devices discovering 
/// 
/// This function triggers the wifi device scan. The search criteria is hard coded in ADL
///  
/// \platform
/// \WIN7 and \WIN8
/// \param[in] virtualWirelessAdapterInfoGuid   A variable that indicates the GUID of the inputted virtual wirless adapter.
/// \remark   After calling the function, the application will get ADL call back if a new WFD devce found, or discovering completed or
///           discovering failed. if a new device found, the application can call \ref ADL_RemoteDisplay_WFDDeviceInfo_Get to get
///           WFD device info list.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results 
ADL_EXTERNC int EXPOSED ADL_RemoteDisplay_WFDDiscover_Start(ADLGUID virtualWirelessAdapterInfoGuid);

///\brief Function to stop wifi direct devices discovering 
/// 
/// This function stop the wifi device scanning. 
///  
/// \platform
/// \WIN7 and \WIN8
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in] virtualWirelessAdapterInfoGuid   a variable that indicates the GUID of the inputted virtual wirless adapter   
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results 
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
ADL_EXTERNC int EXPOSED ADL2_RemoteDisplay_WFDDiscover_Stop(ADL_CONTEXT_HANDLE context,ADLGUID virtualWirelessAdapterInfoGuid);

///\brief Function to stop wifi direct devices discovering 
/// 
/// This function stop the wifi device scanning. 
///  
/// \platform
/// \WIN7 and \WIN8
/// \param[in] virtualWirelessAdapterInfoGuid   a variable that indicates the GUID of the inputted virtual wirless adapter   
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results 
ADL_EXTERNC int EXPOSED ADL_RemoteDisplay_WFDDiscover_Stop(ADLGUID virtualWirelessAdapterInfoGuid);

///\brief Function to get wireless device info list, which found by discovering
/// 
/// This function returns the wireless display info list based on discovering or history data  
/// \platform
/// \WIN7 and \WIN8
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in] virtualWirelessAdapterInfoGuid   a variable that indicates the GUID of the inputted virtual wireless adapter   
/// \param[out] lpNumberDevices    pointer to an integer variable, which indicates the number of devices found.   
/// \param[out] lppDeviceInfo      Pointer to a pointer to the first wireless display  
/// device. This pointer does not need to be initialized by the user. However, the application should free the memory
/// \param[out] lpFinal Pointer to an integer variable, which indicates the 
/// discovering is completed if it is 1. Otherwise it is 0. The vendor SDK takes about 90 seconds to complete one cycle device search.
/// \param[in] iOptions  An integer which decides device scope. From history data or form discovering. See Data type \ref ADL_WFD_Device_Usedtobe_Paired and \ref ADL_WFD_Device_Curent_In_Range
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results 
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
ADL_EXTERNC int EXPOSED ADL2_RemoteDisplay_WFDDeviceInfo_Get(ADL_CONTEXT_HANDLE context,ADLGUID virtualWirelessAdapterInfoGuid, int *lpNumberDevices, ADLWFDDeviceInfo**
lppDeviceInfo, int *lpFinal, int iOptions);

///\brief Function to get wireless device info list, which found by discovering
/// 
/// This function returns the wireless display info list based on discovering or history data  
/// \platform
/// \WIN7 and \WIN8
/// \param[in] virtualWirelessAdapterInfoGuid   a variable that indicates the GUID of the inputted virtual wireless adapter   
/// \param[out] lpNumberDevices    pointer to an integer variable, which indicates the number of devices found.   
/// \param[out] lppDeviceInfo      Pointer to a pointer to the first wireless display  
/// device. This pointer does not need to be initialized by the user. However, the application should free the memory
/// \param[out] lpFinal Pointer to an integer variable, which indicates the 
/// discovering is completed if it is 1. Otherwise it is 0. The vendor SDK takes about 90 seconds to complete one cycle device search.
/// \param[in] iOptions  An integer which decides device scope. From history data or form discovering. See Data type \ref ADL_WFD_Device_Usedtobe_Paired and \ref ADL_WFD_Device_Curent_In_Range
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results 
ADL_EXTERNC int EXPOSED ADL_RemoteDisplay_WFDDeviceInfo_Get(ADLGUID virtualWirelessAdapterInfoGuid, int *lpNumberDevices, ADLWFDDeviceInfo**
lppDeviceInfo, int *lpFinal, int iOptions);

///\brief Function to change WFD device names
/// 
/// This function is used to change the WFD device names  
/// \platform
/// \WIN7 and \WIN8
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in] virtualWirelessAdapterInfoGuid   a variable that indicates the GUID of the inputted virtual wirless adapter   
/// \param[out] iNumberDevices     An integer variable, which indicates the number of input devices.   
/// \param[out] lpDeviceInfo The pointer to the first wireless device 
 /// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results 
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
ADL_EXTERNC int EXPOSED ADL2_RemoteDisplay_WFDDeviceName_Change(ADL_CONTEXT_HANDLE context,ADLGUID virtualWirelessAdapterInfoGuid, int iNumDevices, ADLWFDDeviceInfo*
lpDeviceInfo);

///\brief Function to change WFD device names
/// 
/// This function is used to change the WFD device names  
/// \platform
/// \WIN7 and \WIN8
/// \param[in] virtualWirelessAdapterInfoGuid   a variable that indicates the GUID of the inputted virtual wirless adapter   
/// \param[out] iNumberDevices     An integer variable, which indicates the number of input devices.   
/// \param[out] lpDeviceInfo The pointer to the first wireless device 
 /// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results 
ADL_EXTERNC int EXPOSED ADL_RemoteDisplay_WFDDeviceName_Change(ADLGUID virtualWirelessAdapterInfoGuid, int iNumDevices, ADLWFDDeviceInfo*
lpDeviceInfo);

///\brief Function to start to create wifi direct network
/// 
/// This function starts to create wifi direct network. 
///  
/// \platform
/// \WIN7 and \WIN8
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in] VirtualWirelessAdapterGuid ADLGUID of wireless adapter to be used to create /// link
/// \param[in] WFDDeviceInfo   A vaiable with data type \ref ADLWFDDeviceInfo,   which indicates the device MAC address
/// \remark    After calling this function, the applcaition will get ADL call back if WPS is needed, or wifi direct link is created 
///            or wifi direct link creation failed.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results 
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
ADL_EXTERNC int EXPOSED ADL2_RemoteDisplay_WFDLink_Connect(ADL_CONTEXT_HANDLE context,ADLGUID wirelessAdapterGUID, ADLWFDDeviceInfo WFDDeviceInfo);

///\brief Function to start to create wifi direct network
/// 
/// This function starts to create wifi direct network. 
///  
/// \platform
/// \WIN7 and \WIN8
/// \param[in] VirtualWirelessAdapterGuid ADLGUID of wireless adapter to be used to create /// link
/// \param[in] WFDDeviceInfo   A vaiable with data type \ref ADLWFDDeviceInfo,   which indicates the device MAC address
/// \remark    After calling this function, the applcaition will get ADL call back if WPS is needed, or wifi direct link is created 
///            or wifi direct link creation failed.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results 
ADL_EXTERNC int EXPOSED ADL_RemoteDisplay_WFDLink_Connect(ADLGUID wirelessAdapterGUID, ADLWFDDeviceInfo WFDDeviceInfo);
 

///\brief Function to disconnect wifi direct network
/// 
/// This function to disconnect wifi dirfect network. Currently, ADL supports one to one wifi direct network only. 
///  
/// \platform
/// \WIN7 and \WIN8 
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in] wirelessAdapterGUID ADLGUID of wireless adapter to be used to stop link  
/// \param[in] WFDDeviceInfo   A vaiable with data type \ref ADLWFDDeviceInfo,   which indicates the device MAC address
/// \remark    After calling this function, the applcaition will get ADL call back if the wifi direct link is disconnected 
///            or wifi direct link disconnection failed.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results 
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
ADL_EXTERNC int EXPOSED ADL2_RemoteDisplay_WFDLink_Disconnect(ADL_CONTEXT_HANDLE context,ADLGUID wirelessAdapterGUID, ADLWFDDeviceInfo WFDDeviceInfo);

///\brief Function to disconnect wifi direct network
/// 
/// This function to disconnect wifi dirfect network. Currently, ADL supports one to one wifi direct network only. 
///  
/// \platform
/// \WIN7 and \WIN8 
/// \param[in] wirelessAdapterGUID ADLGUID of wireless adapter to be used to stop link  
/// \param[in] WFDDeviceInfo   A vaiable with data type \ref ADLWFDDeviceInfo,   which indicates the device MAC address
/// \remark    After calling this function, the applcaition will get ADL call back if the wifi direct link is disconnected 
///            or wifi direct link disconnection failed.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results 
ADL_EXTERNC int EXPOSED ADL_RemoteDisplay_WFDLink_Disconnect(ADLGUID wirelessAdapterGUID, ADLWFDDeviceInfo WFDDeviceInfo);

///\brief Function to wait for wifi direct network connection creation completed 
/// 
/// This function is waiting for connection finish. Usually, this functon needs to be called after calling \ref ADL_RemoteDisplay_WFDLink_connect 
/// when WPS persistence has not been created yet. It means the device is the first join the wifi direct network.
///  
/// \platform
/// \WIN7 and \WIN8 
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in] wirelessAdapterGUID ADLGUID of wireless adapter to be used to create link
/// \param[in] peerInfo   Data structure \ ADLWFDDeviceInfo
/// \param[in] lpWPSString Pointer to a string , which stores the WPS string 
/// \param[in] iWPSStringlen   An integer variable, which indicates the length of WPS string.  
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results 
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
ADL_EXTERNC int EXPOSED ADL2_RemoteDisplay_WFDLink_WPS_Process(ADL_CONTEXT_HANDLE context,ADLGUID wirelessAdapterGUID,ADLWFDDeviceInfo peerInfo,char *lpWPSString, int iWPSStringLen);

///\brief Function to wait for wifi direct network connection creation completed 
/// 
/// This function is waiting for connection finish. Usually, this functon needs to be called after calling \ref ADL_RemoteDisplay_WFDLink_connect 
/// when WPS persistence has not been created yet. It means the device is the first join the wifi direct network.
///  
/// \platform
/// \WIN7 and \WIN8 
/// \param[in] wirelessAdapterGUID ADLGUID of wireless adapter to be used to create link
/// \param[in] peerInfo   Data structure \ ADLWFDDeviceInfo
/// \param[in] lpWPSString Pointer to a string , which stores the WPS string 
/// \param[in] iWPSStringlen   An integer variable, which indicates the length of WPS string.  
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results 
ADL_EXTERNC int EXPOSED ADL_RemoteDisplay_WFDLink_WPS_Process(ADLGUID wirelessAdapterGUID,ADLWFDDeviceInfo peerInfo,char *lpWPSString, int iWPSStringLen);

///\brief Function to accept wifi direct network connection 
/// 
/// This function is used to accept connection from peer device. Usually, this functon needs to be called after calling \ref ADL_RemoteDisplay_WFDLink_WPS_Process 
/// when it receives the call back with message ID \ref ADL_WFD_Link_Create_Accept.
///  
/// \platform
/// \WIN7 and \WIN8 
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in] wirelessAdapterGUID ADLGUID of wireless adapter to be used to create link
/// \param[in] peerInfo   Data structure \ ADLWFDDeviceInfo
/// \param[in] lpWPSString Pointer to a string , which stores the WPS string 
/// \param[in] iWPSStringlen   An integer variable, which indicates the length of WPS string.  
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results 
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
ADL_EXTERNC int EXPOSED ADL2_RemoteDisplay_WFDLink_Creation_Accept(ADL_CONTEXT_HANDLE context,ADLGUID wirelessAdapterGUID,ADLWFDDeviceInfo peerInfo,char *lpWPSString, int iWPSStringLen);

///\brief Function to accept wifi direct network connection 
/// 
/// This function is used to accept connection from peer device. Usually, this functon needs to be called after calling \ref ADL_RemoteDisplay_WFDLink_WPS_Process 
/// when it receives the call back with message ID \ref ADL_WFD_Link_Create_Accept.
///  
/// \platform
/// \WIN7 and \WIN8 
/// \param[in] wirelessAdapterGUID ADLGUID of wireless adapter to be used to create link
/// \param[in] peerInfo   Data structure \ ADLWFDDeviceInfo
/// \param[in] lpWPSString Pointer to a string , which stores the WPS string 
/// \param[in] iWPSStringlen   An integer variable, which indicates the length of WPS string.  
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results 
ADL_EXTERNC int EXPOSED ADL_RemoteDisplay_WFDLink_Creation_Accept(ADLGUID wirelessAdapterGUID,ADLWFDDeviceInfo peerInfo,char *lpWPSString, int iWPSStringLen);
 
///\brief Function to get WFD status info
/// 
/// This function restriev WFD device status info. Such as IP addreess.
/// \platform
/// \WIN7 and \WIN8
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in] wirelessAdapterGUID ADLGUID of wireless adapter to be used to create link
/// \param[in] WFDDeviceInfo   A vaiable with data type \ref ADLWFDDeviceInfo,   which indciates the device MAC address
/// \param[out] lpWFDDeviceStatusInfo   Pointer to data type \ref ADLWFDDeviceStatusInfo,   which indciates the device status info
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results 
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
ADL_EXTERNC int EXPOSED ADL2_RemoteDisplay_WFDDevice_StatusInfo_Get(ADL_CONTEXT_HANDLE context,ADLGUID wirelessAdapterGUID, ADLWFDDeviceInfo WFDDevice, ADLWFDDeviceStatusInfo *lpWFDDeviceStatusInfo );

///\brief Function to get WFD status info
/// 
/// This function restriev WFD device status info. Such as IP addreess.
/// \platform
/// \WIN7 and \WIN8
/// \param[in] wirelessAdapterGUID ADLGUID of wireless adapter to be used to create link
/// \param[in] WFDDeviceInfo   A vaiable with data type \ref ADLWFDDeviceInfo,   which indciates the device MAC address
/// \param[out] lpWFDDeviceStatusInfo   Pointer to data type \ref ADLWFDDeviceStatusInfo,   which indciates the device status info
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results 
ADL_EXTERNC int EXPOSED ADL_RemoteDisplay_WFDDevice_StatusInfo_Get(ADLGUID wirelessAdapterGUID, ADLWFDDeviceInfo WFDDevice, ADLWFDDeviceStatusInfo *lpWFDDeviceStatusInfo );

 
///\brief Function to Notify WDST the wireless network created or disconnected 
/// 
/// This function sends the connection and GPU info to stream management component
/// \platform
/// \WIN7 and \WIN8
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in] ConnectionInfo      Data structure \ADL_RemoteDisplay_WDST_ConnectionInfo.  
/// \param[in] iConnected          Integer, which indicates wireless link status. 
/// 1: wireless link has created. 0: wirless link has been disconnected   
/// \param[in] lpWindowHandle      Pointer to an integer that represents a window handle to receive message from stream management component. 
/// \param[out] lpCommitHandle     Pointer to an integer that represents a link between the PC and a wireless display receiver box. 
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results 
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
ADL_EXTERNC int EXPOSED ADL2_RemoteDisplay_WirelessDisplayEnableDisable_Commit(ADL_CONTEXT_HANDLE context,ADLWDSTConnectionInfo ConnectionInfo,int iConnected, int *lpWindowHandle, int *lpCommitHandle);

///\brief Function to Notify WDST the wireless network created or disconnected 
/// 
/// This function sends the connection and GPU info to stream management component
/// \platform
/// \WIN7 and \WIN8
/// \param[in] ConnectionInfo      Data structure \ADL_RemoteDisplay_WDST_ConnectionInfo.  
/// \param[in] iConnected          Integer, which indicates wireless link status. 
/// 1: wireless link has created. 0: wirless link has been disconnected   
/// \param[in] lpWindowHandle      Pointer to an integer that represents a window handle to receive message from stream management component. 
/// \param[out] lpCommitHandle     Pointer to an integer that represents a link between the PC and a wireless display receiver box. 
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results 
ADL_EXTERNC int EXPOSED ADL_RemoteDisplay_WirelessDisplayEnableDisable_Commit(ADLWDSTConnectionInfo ConnectionInfo,int iConnected, int *lpWindowHandle, int *lpCommitHandle);

///\brief Function to create a new HDCP 2.x session 
/// 
/// This function that creates a new HDCP 2.x session for remote display
/// \platform
/// \WIN7 and \WIN8
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in]   iAdapterIndex The ADL index handle of the desired adapter.
/// \param[in]   displayID  The structure stores the display target information.
/// \param[in,out]  lpAdlHdcp20Create     Pointer to ADLHdcp20Create that is passed into kernel mode driver. 
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results 
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
ADL_EXTERNC int EXPOSED ADL2_RemoteDisplay_Hdcp20_Create(ADL_CONTEXT_HANDLE context,int iAdapterIndex, ADLDisplayID displayID, ADLHdcp20Create* lpAdlHdcp20Create);

///\brief Function to create a new HDCP 2.x session 
/// 
/// This function that creates a new HDCP 2.x session for remote display
/// \platform
/// \WIN7 and \WIN8
/// \param[in]   iAdapterIndex The ADL index handle of the desired adapter.
/// \param[in]   displayID  The structure stores the display target information.
/// \param[in,out]  lpAdlHdcp20Create     Pointer to ADLHdcp20Create that is passed into kernel mode driver. 
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results 
ADL_EXTERNC int EXPOSED ADL_RemoteDisplay_Hdcp20_Create(int iAdapterIndex, ADLDisplayID displayID, ADLHdcp20Create* lpAdlHdcp20Create);

///\brief Function to process HDCP 2.x messages received from receiver
/// 
/// This function notifies and passes the kernel mode driver an HDCP 2.x message received from a receiver
/// \platform
/// \WIN7 and \WIN8
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in]   iAdapterIndex The ADL index handle of the desired adapter.
/// \param[in]   displayID  The structure stores the display target information.
/// \param[in,out]  lpAdlHdcp20ProcessRx  Pointer to ADLHdcp20ProcessRx that is passed into kernel mode driver. 
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results 
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
ADL_EXTERNC int EXPOSED ADL2_RemoteDisplay_Hdcp20_Process(ADL_CONTEXT_HANDLE context,int iAdapterIndex, ADLDisplayID displayID, ADLHdcp20Process* lpAdlHdcp20ProcessRx);

///\brief Function to process HDCP 2.x messages received from receiver
/// 
/// This function notifies and passes the kernel mode driver an HDCP 2.x message received from a receiver
/// \platform
/// \WIN7 and \WIN8
/// \param[in]   iAdapterIndex The ADL index handle of the desired adapter.
/// \param[in]   displayID  The structure stores the display target information.
/// \param[in,out]  lpAdlHdcp20ProcessRx  Pointer to ADLHdcp20ProcessRx that is passed into kernel mode driver. 
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results 
ADL_EXTERNC int EXPOSED ADL_RemoteDisplay_Hdcp20_Process(int iAdapterIndex, ADLDisplayID displayID, ADLHdcp20Process* lpAdlHdcp20ProcessRx);

///\brief Function to notify kernel mode driver before sending a HDCP 2.x related message
/// 
/// This function notifies the kernel mode driver after an HDCP 2.x message has been sent.
/// \platform
/// \WIN7 and \WIN8
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in]   iAdapterIndex The ADL index handle of the desired adapter.
/// \param[in]   displayID  The structure stores the display target information.
/// \param[in]  lpAdlHdcp20NotifyTx     Pointer to ADLHdcp20NotifyTx that is passed into kernel mode driver. 
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results 
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
ADL_EXTERNC int EXPOSED ADL2_RemoteDisplay_Hdcp20_Notify(ADL_CONTEXT_HANDLE context,int iAdapterIndex, ADLDisplayID displayID, ADLHdcp20Notify* lpAdlHdcp20NotifyTx);

///\brief Function to notify kernel mode driver before sending a HDCP 2.x related message
/// 
/// This function notifies the kernel mode driver after an HDCP 2.x message has been sent.
/// \platform
/// \WIN7 and \WIN8
/// \param[in]   iAdapterIndex The ADL index handle of the desired adapter.
/// \param[in]   displayID  The structure stores the display target information.
/// \param[in]  lpAdlHdcp20NotifyTx     Pointer to ADLHdcp20NotifyTx that is passed into kernel mode driver. 
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results 
ADL_EXTERNC int EXPOSED ADL_RemoteDisplay_Hdcp20_Notify(int iAdapterIndex, ADLDisplayID displayID, ADLHdcp20Notify* lpAdlHdcp20NotifyTx);

///\brief Function to destroy an HDCP 2.x session 
/// 
/// This function destroys a previously created HDCP 2.x session for remote display
/// \platform
/// \WIN7 and \WIN8
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in]   iAdapterIndex The ADL index handle of the desired adapter.
/// \param[in]   displayID  The structure stores the display target information.
/// \param[in,out]  lpAdlHdcp20Create     Pointer to ADLHdcp20Release that is passed into kernel mode driver. 
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results 
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
ADL_EXTERNC int EXPOSED ADL2_RemoteDisplay_Hdcp20_Destroy(ADL_CONTEXT_HANDLE context,int iAdapterIndex, ADLDisplayID displayID, ADLHdcp20Destroy* lpAdlHdcp20Destroy);

///\brief Function to destroy an HDCP 2.x session 
/// 
/// This function destroys a previously created HDCP 2.x session for remote display
/// \platform
/// \WIN7 and \WIN8
/// \param[in]   iAdapterIndex The ADL index handle of the desired adapter.
/// \param[in]   displayID  The structure stores the display target information.
/// \param[in,out]  lpAdlHdcp20Create     Pointer to ADLHdcp20Release that is passed into kernel mode driver. 
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results 
ADL_EXTERNC int EXPOSED ADL_RemoteDisplay_Hdcp20_Destroy(int iAdapterIndex, ADLDisplayID displayID, ADLHdcp20Destroy* lpAdlHdcp20Destroy);

///\brief Function to set IE element
/// 
/// This function sets TCP port number      
/// \platform
/// \WIN8
///
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in]   iPort The IP port that AWD will use for RTSP communication
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results 
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
ADL_EXTERNC int EXPOSED ADL2_RemoteDisplay_IEPort_Set(ADL_CONTEXT_HANDLE context,int iPort);

///\brief Function to set IE element
/// 
/// This function sets TCP port number      
/// \platform
/// \WIN8
///
/// \param[in]   iPort The IP port that AWD will use for RTSP communication
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results 
ADL_EXTERNC int EXPOSED ADL_RemoteDisplay_IEPort_Set(int iPort);

///\brief Function to unconditionally release all remote displays.
/// 
/// \platform
/// \WIN8
///
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \return Only fails if there are no valid adapters.  Otherwise returns ADK_OK \ref define_adl_results 
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
ADL_EXTERNC int EXPOSED ADL2_RemoteDisplay_Display_Release_All(ADL_CONTEXT_HANDLE context);

///\brief Function to unconditionally release all remote displays.
/// 
/// \platform
/// \WIN8
///
/// \return Only fails if there are no valid adapters.  Otherwise returns ADK_OK \ref define_adl_results 
ADL_EXTERNC int EXPOSED ADL_RemoteDisplay_Display_Release_All();

#endif /* AMD_REMOTEDISPLAY_H_ */
