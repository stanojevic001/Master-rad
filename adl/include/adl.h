///
///  Copyright (c) 2008 - 2021 Advanced Micro Devices, Inc.
 
///  THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
///  EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
///  WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.

/// \file adl.h
/// \brief Contains the main functions exposed by ADL for \ALL platforms.
///
/// This file contains the main functions exposed by ADL for \ALL platforms.
/// All functions in this file can be used as a reference when creating
/// specific function pointers to be used by the appropriate runtime
/// dynamic library loaders.
/// \mainpage
/// @{
/// This document describes the APIs (application programming interfaces) that can be used to access
/// AMD-specific display driver functionality, such as those related to specific display devices. \n\n
/// Included in this document are definitions as well as the data structures used by each API. \n
/// Public functions are prefixed with "ADL_". 
/// The majority of the APIs are supported on 32-bit and 64-bit versions of Windows (XP and Vista) and Linux platforms. \n\n
/// Working code samples and snippets of the API source code files are also provided for reference purposes.\n\n
///\note Although a number of header files are referenced in this document, only three are required and provoided with this SDK:\n
///\li \b adl_sdk.h : The ony header file to be included in a C/C++ project \n
///\li \b adl_structures.h : Definitions of all structures for public use. Included in \b adl_sdk.h \n
///\li \b adl_defines.h : Definitions of all Constants and Enumerations.  Included in \b adl_structures.h \n
///
/// The three files should be placed in the same folder.
/// @}

#ifndef ADL_H_
#define ADL_H_

// Define the API groups here so they can appear in this particular order.
// Use Doxygen command "ingroup" to add APIs to these groups from other files.

/// \example Adl2
/// \~Chinese-Traditional
/// \htmlinclude Adl2/Adl2Sample-cht.html
/// \~english
/// \htmlinclude Adl2/Adl2Sample.html

/// \example ColorCaps
/// \~english
/// \htmlinclude ColorCaps/ColorCapsSample.html

/// \example DDCBlockAccess
/// \~english
/// \htmlinclude DDCBlockAccess\DDCBlockAccessSample.html

/// \example DDCBlockAccessCL
/// \~english
/// \htmlinclude DDCBlockAccessCL\DDCBlockAccessCLSample.html

/// \example EDIDSampleTool
/// \~english
/// \htmlinclude EDIDSampleTool\edidSample.html

/// \example Eyefinity
/// \~english
/// \htmlinclude Eyefinity\eyefinitySample.html

/// \example Eyefinity2
/// \~english
/// \htmlinclude Eyefinity2\eyefinity2Sample.html

/// \example Overdrive
/// \~english
/// \htmlinclude Overdrive\overdriveSample.html

/// \example OverdriveN
/// \~english
/// \htmlinclude OverdriveN\overdriveNSample.html

/// \example Overdrive8
/// \~english
/// \htmlinclude Overdrive8\overdrive8Sample.html

/// \example PowerXPress
/// \~english
/// \htmlinclude PowerXPress\PowerXpressSample.html

/// \example PXRunningApps
/// \~english
/// \htmlinclude PXRunningApps\PXRunningAppsSample.html

/// \example Display
/// \~english
/// \htmlinclude Display\displaySample.html

/// \example AMDDisplayTool
/// \~english
/// \htmlinclude AMDDisplayTool\AMDDisplayToolSample.html

/// \example PMLog
/// \~english
/// \htmlinclude PMLog\pmlogSample.html

/// \example ServiceCallADL
/// \~english
/// \htmlinclude ServiceCallADL\ServiceCallADLSample.html

/// \example VirtualDisplay
/// \~english
/// \htmlinclude VirtualDisplay\VirtualDisplaySample.html

/// \example Power
/// \~english
/// \htmlinclude Power\PowerSample.html

/// \example EnhancedSync
/// \~english
/// \htmlinclude EnhancedSync\EnhancedSyncSample.html

/// \example RegammaAndGamut
/// \~english
/// \htmlinclude RegammaAndGamut\RegammaAndGamut.html

/// \example SmartDC
/// \~english
/// \htmlinclude SmartDC\SmartDCSample.html

/// \example SideBySide
/// \~english
/// \htmlinclude SideBySide\SideBySideSample.html

/// \example AMDGamemanagerTool
/// \~english
/// \htmlinclude AMDGamemanagerTool\AMDGamemanagerTool.html

/// \example FPSSampleTool
/// \~english
/// \htmlinclude FPSSampleTool\FPSSampleTool.html

/// \example OD8demo
/// \~english
/// \htmlinclude OD8demo\OD8demo.html

/// \example FRTCPro
/// \~english
/// \htmlinclude FRTCPro\FRTCProSample.html
/// 
/// \page LatestAPIS 16.0 APIs List
/// \page APIS15 15.0 APIs List
/// \page APIS14 14.0 APIs List


// Enable the top "API Groups" this by adding one more slash line at the beginning of line below...
//\defgroup ADL_API API Groups

///\ingroup ADL_API
///\defgroup MAINAPI Main Group of APIs
/// This group describes the APIs for initializing, refreshing and destroying ADL

///\ingroup ADL_API
///\defgroup ADAPTERAPI Adapter Related APIs
/// This group outlines all adapter related APIs.

///\ingroup ADL_API
///\defgroup DISPLAYAPI Display Related APIs
/// This group outlines all display related APIs.

///\ingroup ADL_API
///\defgroup GAMINGAPI Gaming Related APIs
/// This group outlines all Gaming related APIs.

///\ingroup ADL_API
///\defgroup VIDEOAPI Video Related APIs
/// This group outlines all Video related APIs.

///\ingroup ADL_API
///\defgroup WATTMANAPI Wattman Related APIs
/// This group outlines all OD & Wattman related APIs.
/// \remarks Use ADL2_Overdrive_Caps API to identify the Overdrive or Wattman version before using the APIs for respective functionalities. Usage of one version of APIs on unsupported HW might result in abnormal behavior.

///\ingroup ADL_API
///\defgroup WORKSTATIONAPI Workstation Related APIs
/// This group outlines all Workstation related APIs.

///\ingroup ADL_API
///\defgroup GENARICAPI General Adapter APIs
/// This group describes General adapter  APIs.




#include "adl_sdk.h"
#include "amd_only/amd_structures.h"

#include "adapter.h"
#include "display.h"
#include "workstation.h"
#include "displaysmanager.h"

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


///
/// \brief Function to initialize the ADL interface. This function should be called first.
/// 
/// This function initializes the ADL library. Allows the client to specify desired threading behavior of ADL APIs. It also initializes global pointers and, at the same time, calls the ADL_Main_Control_Refresh function.
/// \platform 
/// \ALL
/// \param[in] callback: The memory allocation function for memory buffer allocation. This must be provided by the user. This must be provided by the user. ADL internally uses this callback to allocate memory for the output parameters returned to the user and user is responsible to free the memory once used for these parameters. ADL internal takes care of allocating and de allocating the memory for its local variables.
/// \param[in] iEnumConnectedAdapters: Specify a value of 0 to retrieve adapter information for all adapters that have ever been present in the system. Specify a value of 1 to retrieve adapter information only for adapters that are physically present and enabled in the system.
/// \param[in] threadingModel: Specify ADL threading behavior.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
ADL_EXTERNC int EXPOSED ADL_Main_ControlX2_Create ( ADL_MAIN_MALLOC_CALLBACK callback, int iEnumConnectedAdapters, ADLThreadingModel threadingModel );

///
/// \brief Function to initialize the ADL2 interface and issue client's context handle. 
/// 
/// Clients can use ADL2 versions of ADL APIs to assure that there is no interference with other ADL clients that are running in the same process. 
/// Such clients have to call ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
/// ADL2_Main_ControlX2_Create allows the client to specify desired threading behavior of ADL APIs.
/// \platform 
/// \ALL
/// \param[in] callback: The memory allocation function for memory buffer allocation. This must be provided by the user. This must be provided by the user. ADL internally uses this callback to allocate memory for the output parameters returned to the user and user is responsible to free the memory once used for these parameters. ADL internal takes care of allocating and de allocating the memory for its local variables.
/// \param[in] iEnumConnectedAdapters: Specify a value of 0 to retrieve adapter information for all adapters that have ever been present in the system. Specify a value of 1 to retrieve adapter information only for adapters that are physically present and enabled in the system.
/// \param[out] context: \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
/// \param[in] threadingModel: Specify ADL threading behavior.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
ADL_EXTERNC int EXPOSED ADL2_Main_ControlX2_Create ( ADL_MAIN_MALLOC_CALLBACK callback, int iEnumConnectedAdapters, ADL_CONTEXT_HANDLE* context, ADLThreadingModel threadingModel);

///
/// \brief Function to initialize the ADL2 interface and issue client's context handle. 
/// 
/// Clients can use ADL2 versions of ADL APIs to assure that there is no interference with other ADL clients that are running in the same process. 
/// Such clients have to call ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
/// ADL2_Main_ControlX3_Create allows customizing ADL GPU behavior by allowing to caller to pass a set of 32 bits integer
/// \platform 
/// \ALL
/// \param[in] callback: The memory allocation function for memory buffer allocation. This must be provided by the user. This must be provided by the user. ADL internally uses this callback to allocate memory for the output parameters returned to the user and user is responsible to free the memory once used for these parameters. ADL internal takes care of allocating and de allocating the memory for its local variables.
/// \param[in] iEnumConnectedAdapters: Specify a value of 0 to retrieve adapter information for all adapters that have ever been present in the system. Specify a value of 1 to retrieve adapter information only for adapters that are physically present and enabled in the system.
/// \param[out] context: \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
/// \param[in] threadingModel: Specify ADL threading behavior.
/// \param[in] adlCreateOptions: it will allow customizing ADL GPU behavior by allowing to caller to pass a set of 32 bits. Each bit customizes 
///            particular behavior. First usage of the flags is to customize how ADL will report adapters that are AMD but have incompatible driver installed.
///            Setting 0 to first bit will force ADL to report such adapters as none-AMD (vendor -1002) , setting 1 to first bit will force AMD to report such adapters vendor as AMD (1002)
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
ADL_EXTERNC int EXPOSED ADL2_Main_ControlX3_Create(ADL_MAIN_MALLOC_CALLBACK callback, int iEnumConnectedAdapters, ADL_CONTEXT_HANDLE* context, ADLThreadingModel threadingModel, int adlCreateOptions);

///
/// \brief Function to initialize the ADL interface. This function should be called first.
/// 
/// This function initializes the ADL library. ADL initialized using ADL_Main_Control_Create will not enforce serialization of ADL API executions by multiple threads.  Multiple threads will be allowed to enter to ADL at the same time. 
/// Note that ADL library is not guaranteed to be thread-safe. Client that calls ADL_Main_Control_Create have to provide its own mechanism for ADL calls serialization.
/// It also initializes global pointers and, at the same time, calls the ADL_Main_Control_Refresh function.
/// \platform 
/// \ALL
/// \param[in] callback: The memory allocation function for memory buffer allocation. This must be provided by the user. ADL internally uses this callback to allocate memory for the output parameters returned to the user and user is responsible to free the memory once used for these parameters. ADL internal takes care of allocating and de allocating the memory for its local variables.
/// \param[in] iEnumConnectedAdapters: Specify a value of 0 to retrieve adapter information for all adapters that have ever been present in the system. Specify a value of 1 to retrieve adapter information only for adapters that are physically present and enabled in the system.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
ADL_EXTERNC int EXPOSED ADL_Main_Control_Create ( ADL_MAIN_MALLOC_CALLBACK callback, int iEnumConnectedAdapters );

///
/// \brief Function to initialize the ADL2 interface and to obtain client's context handle. 
/// 
/// Clients can use ADL2 versions of ADL APIs to assure that there is no interference with other ADL clients that are running in the same process.  Such clients have to call ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
/// ADL initialized using ADL2_Main_Control_Create will not enforce serialization of ADL API executions by multiple threads.  Multiple threads will be allowed to enter to ADL at the same time. 
/// Note that ADL library is not guaranteed to be thread-safe. Client that calls ADL2_Main_Control_Create have to provide its own mechanism for ADL calls serialization.
/// \platform 
/// \ALL
/// \param[in] callback: The memory allocation function for memory buffer allocation. This must be provided by the user. ADL internally uses this callback to allocate memory for the output parameters returned to the user and user is responsible to free the memory once used for these parameters. ADL internal takes care of allocating and de allocating the memory for its local variables.
/// \param[in] iEnumConnectedAdapters: Specify a value of 0 to retrieve adapter information for all adapters that have ever been present in the system. Specify a value of 1 to retrieve adapter information only for adapters that are physically present and enabled in the system.
/// \param[out] context: \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
ADL_EXTERNC int EXPOSED ADL2_Main_Control_Create ( ADL_MAIN_MALLOC_CALLBACK callback, int iEnumConnectedAdapters, ADL_CONTEXT_HANDLE* context);

///
/// \brief Function to refresh adapter information. This function generates an adapter index value for all logical adapters that have ever been present in the system.
/// 
/// This function updates the adapter information based on the logical adapters currently in the system. The adapter index and UDID mappings remain unchanged for each refresh call. 
/// \platform 
/// \ALL
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
ADL_EXTERNC int EXPOSED ADL2_Main_Control_Refresh (ADL_CONTEXT_HANDLE context);

///
/// \brief Function to refresh adapter information. This function generates an adapter index value for all logical adapters that have ever been present in the system.
/// 
/// This function updates the adapter information based on the logical adapters currently in the system. The adapter index and UDID mappings remain unchanged for each refresh call. 
/// \platform 
/// \ALL
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
ADL_EXTERNC int EXPOSED ADL_Main_Control_Refresh ();

///
/// \brief Function to destroy ADL global pointers. This function should be called last.
/// 
/// All ADL global buffers and resources are released after this function is called.
/// \platform 
/// \ALL
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
ADL_EXTERNC int EXPOSED ADL_Main_Control_Destroy ();

///
/// \brief Destroy client's ADL context.
/// 
/// Clients can use ADL2 versions of ADL APIs to assure that there is no interference with other ADL clients that are running in the same process and to assure that ADL APIs are thread-safe. 
/// Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using ADL2_Main_Control_Destroy.
/// \platform 
/// \ALL
/// \param[in] context: \ref ADL_CONTEXT_HANDLE instance to destroy.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
ADL_EXTERNC int EXPOSED ADL2_Main_Control_Destroy (ADL_CONTEXT_HANDLE context);

///
/// \brief ADL local interface. Function to determine the validity of and retrieve the function pointer (similar to the GetProcAdress API) for a specified function.
/// 
/// This function returns the function pointer of a specified function if it is valid (defined and exposed in a DLL module). Call this function to ensure that a function is valid before calling it.
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in]  lpModule The pointer to the desired handle of the DLL.
/// \param[in]  lpProcName The pointer to the desired function name.
/// \platform 
/// \ALL
/// \return If the specified function is valid, the return value is a function pointer. Otherwise it is NULL.
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
ADL_EXTERNC EXPOSED void* ADL2_Main_Control_GetProcAddress (ADL_CONTEXT_HANDLE context, void* lpModule, char* lpProcName );

///
/// \brief ADL local interface. Function to determine the validity of and retrieve the function pointer (similar to the GetProcAdress API) for a specified function.
/// 
/// This function returns the function pointer of a specified function if it is valid (defined and exposed in a DLL module). Call this function to ensure that a function is valid before calling it.
/// \param[in]  lpModule The pointer to the desired handle of the DLL.
/// \param[in]  lpProcName The pointer to the desired function name.
/// \platform 
/// \ALL
/// \return If the specified function is valid, the return value is a function pointer. Otherwise it is NULL.
ADL_EXTERNC EXPOSED void* ADL_Main_Control_GetProcAddress ( void* lpModule, char* lpProcName );

/// 
/// \brief \newAPI15 Allows the client to register to specific graphics driver event.
///
/// Client calls the function passing id of the event it listens to and handle of the event object. The graphics driver sets the event object when corresponding event occurs in the system.
/// \platform
/// \WIN
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in] eventId: Numeric value that represents the event ID the client listens to.
/// \param[in] evntHandle: Reference to the event object that will be set by the driver when corresponding event occurs in the system. Client obtains the handle using Win32 CreateEvent API. 

/// \return If the function succeeds, the return value is \ref ADL_OK, or an ADL error code otherwise.  \ref define_adl_results
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
ADL_EXTERNC int EXPOSED ADL2_RegisterEvent(ADL_CONTEXT_HANDLE context, int eventID, void* evntHandle);

/// 
/// \brief \newAPI15 Allows the client to un-register from specific graphics driver event.
///
/// Client calls the function passing id of the event it listens to and handle of the event object. The graphics driver will stop seting the event object when corresponding event occurs in the system.
/// \platform
/// \WIN
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in] eventId: Numeric value that represents the event ID the client listens to.
/// \param[in] evntHandle: Reference to the event object that will need to be unregistered. Client obtains the handle using Win32 CreateEvent API. Client has to call CloseHandle Win32 API after it unregisters the handle.
/// \return If the function succeeds, the return value is \ref ADL_OK, or an ADL error code otherwise.  \ref define_adl_results
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
ADL_EXTERNC int EXPOSED ADL2_UnRegisterEvent(ADL_CONTEXT_HANDLE context, int eventID, void* evntHandle);


/// 
/// \brief \newAPI15 Allows the client to register to specific graphics driver event.
///
/// Client calls the function passing id of the event it listens to and handle of the event object. The graphics driver sets the event object when corresponding event occurs in the system.
/// \platform
/// \WIN
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in] eventId: Numeric value that represents the event ID the client listens to.
/// \param[in] evntHandle: Reference to the event object that will be set by the driver when corresponding event occurs in the system. Client obtains the handle using Win32 CreateEvent API. 

/// \return If the function succeeds, the return value is \ref ADL_OK, or an ADL error code otherwise.  \ref define_adl_results
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
ADL_EXTERNC int EXPOSED ADL2_RegisterEventX2(ADL_CONTEXT_HANDLE context, int iAdapterIndex, int clientID, int eventID, void* evntHandle);

/// 
/// \brief \newAPI15 Allows the client to un-register from specific graphics driver event.
///
/// Client calls the function passing id of the event it listens to and handle of the event object. The graphics driver will stop seting the event object when corresponding event occurs in the system.
/// \platform
/// \WIN
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in] eventId: Numeric value that represents the event ID the client listens to.
/// \param[in] evntHandle: Reference to the event object that will need to be unregistered. Client obtains the handle using Win32 CreateEvent API. Client has to call CloseHandle Win32 API after it unregisters the handle.
/// \return If the function succeeds, the return value is \ref ADL_OK, or an ADL error code otherwise.  \ref define_adl_results
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
ADL_EXTERNC int EXPOSED ADL2_UnRegisterEventX2(ADL_CONTEXT_HANDLE context, int iAdapterIndex, int clientID, int eventID, void* evntHandle);

/// 
/// \brief \newAPI15 Allows the client to register to specific graphics driver event for given GPU for each GPU
///
/// Client calls the function passing id of the event it listens to and handle of the event object. 
/// The graphics driver sets the event object when corresponding event occurs in the system.
/// If the event is registered for a given GPU, unregister also needs for a given GPU.
/// If the event is registered for each GPU, unregister is also for each GPU.
/// \platform
/// \WIN
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in] adapterIndex: an integer indicates a GPU. If is -1, then the API will register the event to each GPU
/// \param[in] eventId: Numeric value that represents the event ID the client listens to. \ref 
/// \param[in] clientID:  An integer indicate who register the event. It is optional , for third part it is 0
/// \param[in] evntHandle: Reference to the event object that will be set by the driver when corresponding event occurs in the system. Client obtains the handle using Win32 Create event API. 
/// \return If the function succeeds, the return value is \ref ADL_OK, or an ADL error code otherwise.  \ref define_adl_results
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
ADL_EXTERNC int EXPOSED ADL2_PerGPU_GDEvent_Register(ADL_CONTEXT_HANDLE context, int iAdapterIndex, int clientID, int eventID, void* evntHandle);

/// 
/// \brief \newAPI15 Allows the client to un-register to specific graphics driver event for a given GPU or for each GPU
///
/// Client calls the function passing id of the event and un-register event. If the event is registered for a given GPU, unregister also needs for a given GPU.
/// If the event is registered for each GPU, unregister is also for each GPU.
/// \platform
/// \WIN
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in] adapterIndex: an integer indicate a GPU. If is -1, then need to unregister to each GPU. 
/// \param[in] eventId: Numeric value that represents the event ID the client listens to.
/// \param[in] clientID:  An integer indicate who register the event. It is optional , for third part it is 0
/// \param[in] evntHandle: Reference to the event object that will be set by the driver when corresponding event occurs in the system. Client obtains the handle using Win32 Create Event API. 
/// \return If the function succeeds, the return value is \ref ADL_OK, or an ADL error code otherwise.  \ref define_adl_results
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
ADL_EXTERNC int EXPOSED ADL2_PerGPU_GDEvent_UnRegister(ADL_CONTEXT_HANDLE context, int iAdapterIndex, int clientID, int eventID, void* evntHandle);
/// @}


#endif /* ADL_H_ */
