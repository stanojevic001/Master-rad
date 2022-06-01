///
///  Copyright (c) 2008 - 2021 Advanced Micro Devices, Inc.
 
///  THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
///  EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
///  WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.

/// \file amd_lnx.h
/// \brief Contains internal and hidden Linux-related functions \LNX platforms.
///
/// This file contains internal Linux-related ADL function exposed by ADL for Linux platforms.
/// All functions in this file can be used as a reference to ensure the
/// specific function pointers can be used by the appropriate runtime
/// dynamic library loaders.

#ifndef __AMD_LNX_H__
#define __AMD_LNX_H__

#ifndef ADL_EXTERNC
#ifdef __cplusplus
#define ADL_EXTERNC extern "C"
#else
#define ADL_EXTERNC
#endif
#endif

/// internal define for disabled adapter X Screen number
#define ADAPTER_DISABLED	-1

///
/// \brief Linux hidden function to check whether an adapter is active or not.
/// 
/// This function checks whether a specified adapter is currently active. An adapter is active if its X Screen number is valid. A disabled adapter returns a value of -1 for ADAPTER_DISABLED.
/// \platform
/// \LNX
/// \param[in]  iAdapterIndex The ADL index handle of the desired graphics adapter.
/// \param[out] lpActive The pointer to the return value indicating whether or not the desired adapter is active. 1: active; 0: inactive.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
int HIDDEN Lnx_Adapter_Active_Get ( int iAdapterIndex, int* lpActive );

/// \addtogroup LINUX
/// @{
///
/// \brief AMD Private interface. Function to retrieve OD5 clock information.
/// 
/// This function retrieves core and memory clock information of a specified graphics adapter.
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in]  iAdapterIndex ADL index handle of the desired adapter.
/// \param[out]  clockInfoOut The pointer to the structure storing the retrieved clock information.
/// \param[in]  bdf The bus number, device number, and function number of the specified adapter.
/// \platform 
/// \\LNX
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
ADL_EXTERNC int EXPOSED ADL2_OD_Clocks_Get(ADL_CONTEXT_HANDLE context,int iAdapterIndex, ADLGetClocksOUT *clockInfoOut, int bdf);

///
/// \brief AMD Private interface. Function to retrieve OD5 clock information.
/// 
/// This function retrieves core and memory clock information of a specified graphics adapter.
/// \param[in]  iAdapterIndex ADL index handle of the desired adapter.
/// \param[out]  clockInfoOut The pointer to the structure storing the retrieved clock information.
/// \param[in]  bdf The bus number, device number, and function number of the specified adapter.
/// \platform 
/// \\LNX
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
ADL_EXTERNC int EXPOSED ADL_OD_Clocks_Get(int iAdapterIndex, ADLGetClocksOUT *clockInfoOut, int bdf);

///
/// \brief AMD Private interface. Function to set OD5 clocks to the specified values.
/// 
/// This function sets the OD5 performance level to specific clock, voltage, and BDF values for a specified graphics adapter.
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[in]  HighCoreClock The desired core clock value in Mhz.
/// \param[in]  HighMemoryClock The desired memory clock value in Mhz.
/// \param[in]  HighVddc The core voltage value.
/// \param[in]  bdf The bus number, device number, and function number of the specified adapter.
/// \platform 
/// \\LNX
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results 
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
ADL_EXTERNC int EXPOSED ADL2_OD_Clocks_Set(ADL_CONTEXT_HANDLE context,int iAdapterIndex, int HighCoreClock, int HighMemoryClock, float HighVddc, int bdf);

///
/// \brief AMD Private interface. Function to set OD5 clocks to the specified values.
/// 
/// This function sets the OD5 performance level to specific clock, voltage, and BDF values for a specified graphics adapter.
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[in]  HighCoreClock The desired core clock value in Mhz.
/// \param[in]  HighMemoryClock The desired memory clock value in Mhz.
/// \param[in]  HighVddc The core voltage value.
/// \param[in]  bdf The bus number, device number, and function number of the specified adapter.
/// \platform 
/// \\LNX
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results 
ADL_EXTERNC int EXPOSED ADL_OD_Clocks_Set(int iAdapterIndex, int HighCoreClock, int HighMemoryClock, float HighVddc, int bdf);

///
/// \brief AMD Private interface. Function to retrieve the temperature readings of an adapter.
/// 
/// This function retrieves all temperature readings of a specified graphics adapter.
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[out]  temperature The pointer to the array storing the retrieved temperature readings.
/// \param[out]  thermalSensorCount The pointer to the number of thermal sensors on the specified adapter.
/// \param[in]  bdf The bus number, device number, and function number of the specified adapter.
/// \platform 
/// \\LNX
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results 
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
ADL_EXTERNC int EXPOSED ADL2_OD_Temperature_Get(ADL_CONTEXT_HANDLE context,int iAdapterIndex, long *temperature, int *thermalSensorCount, int bdf);

///
/// \brief AMD Private interface. Function to retrieve the temperature readings of an adapter.
/// 
/// This function retrieves all temperature readings of a specified graphics adapter.
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[out]  temperature The pointer to the array storing the retrieved temperature readings.
/// \param[out]  thermalSensorCount The pointer to the number of thermal sensors on the specified adapter.
/// \param[in]  bdf The bus number, device number, and function number of the specified adapter.
/// \platform 
/// \\LNX
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results 
ADL_EXTERNC int EXPOSED ADL_OD_Temperature_Get(int iAdapterIndex, long *temperature, int *thermalSensorCount, int bdf);

///
/// \brief ADL local interface. Function to retrieve the XScreenInfo structure.
/// 
/// This function retrieves the XScreenInfo structure based on a specified input buffer size.
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[out]  lpScreenInfo The pointer to the retrieved XScreenInfo buffer.
/// \param[in]  iInputSize The size of the input buffer.
/// \platform 
/// \LNX
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results 
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
ADL_EXTERNC int EXPOSED ADL2_Adapter_ScreenInfo_Get(ADL_CONTEXT_HANDLE context,LPXScreenInfo *lpScreenInfo, int iInputSize);

///
/// \brief ADL local interface. Function to retrieve the XScreenInfo structure.
/// 
/// This function retrieves the XScreenInfo structure based on a specified input buffer size.
/// \param[out]  lpScreenInfo The pointer to the retrieved XScreenInfo buffer.
/// \param[in]  iInputSize The size of the input buffer.
/// \platform 
/// \LNX
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results 
ADL_EXTERNC int EXPOSED ADL_Adapter_ScreenInfo_Get(LPXScreenInfo *lpScreenInfo, int iInputSize);

///
/// \brief ADL local interface. Function to retrieve the number of X Screens in the system.
/// 
/// This function retrives the number of X Screens in the system.
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[out]  lpNumberOfScreens The pointer to the retrieved number of X Screens.
/// \platform 
/// \LNX
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results 
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
ADL_EXTERNC int EXPOSED ADL2_NumberOfScreens_Get(ADL_CONTEXT_HANDLE context,int* lpNumberOfScreens);

///
/// \brief ADL local interface. Function to retrieve the number of X Screens in the system.
/// 
/// This function retrives the number of X Screens in the system.
/// \param[out]  lpNumberOfScreens The pointer to the retrieved number of X Screens.
/// \platform 
/// \LNX
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results 
ADL_EXTERNC int EXPOSED ADL_NumberOfScreens_Get(int* lpNumberOfScreens);

///\brief Get ADL AdapterIndex from BDF
///
/// Retrieve iAdapterIndex from ADL AdapterInfo structure for
/// adapter with specified Bus: Device: Function and PCI domain.
/// \platform 
/// \LNX
///
/// \param[in] lpinfo     pointer of LPAdapterInfo array
/// \param[in] AdapterNum ADLs number of adapters
/// \param[in] iBus       adapter Bus number
/// \param[in] iDev       adapter Device number
/// \param[in] iFunc      adapter Function number
/// \param[in] PCIDomain  adapter PCI domain number (currently not used)
///
/// \return iAdapterIndex if successful, ADL_ERR (-1) on error

int ADL_Get_AdapterIndex_FromBDF(LPAdapterInfo lpinfo,int AdapterNum, int iBus, int iDev, int iFunc, int PCIDomain);

// Make it Public after ADL public release!!!
///
/// \brief Function to retrieve X Server Information specific to driver
/// 
/// Possible values include Xinerama Active in X-server, RandR 1.2 supported by driver
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[out]  lpValidBits - indicates which values in lpMaskBits are valid \ref define_xserverinfo
/// \param[out]  lpMaskBits - indicates values that mask to \ref define_xserverinfo to be supported or true
/// \param[out]  lpXInfoData - other X related information
/// \platform 
/// \LNX
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code \ ref define_adl_results
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
ADL_EXTERNC int EXPOSED ADL2_XServerInfo_Get(ADL_CONTEXT_HANDLE context,int *lpValidBits, int *lpMaskBits, ADLXInfoData* lpXInfoData);

///
/// \brief Function to retrieve X Server Information specific to driver
/// 
/// Possible values include Xinerama Active in X-server, RandR 1.2 supported by driver
/// \param[out]  lpValidBits - indicates which values in lpMaskBits are valid \ref define_xserverinfo
/// \param[out]  lpMaskBits - indicates values that mask to \ref define_xserverinfo to be supported or true
/// \param[out]  lpXInfoData - other X related information
/// \platform 
/// \LNX
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code \ ref define_adl_results
ADL_EXTERNC int EXPOSED ADL_XServerInfo_Get(int *lpValidBits, int *lpMaskBits, ADLXInfoData* lpXInfoData);

///
/// \brief Function to retrieve all X Screen information for all OS-known adapters.
///
/// This function retrieves the X Screen information of all OS-known adapters on a Linux system. OS-known adapters can include adapters that currently exist in the system (logical adapters)
/// as well as ones that no longer exist in the system but are still recognized by the OS.
///
/// \platform
/// \LNX
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[out] lppXScreenInfo Pointer to a list for storing the retrieved X Screen information. This list will be allocated by this function.
///								The size of the list equals the number of adapters returned by \ref ADL_Adapter_NumberOfAdapters_Get.
///								The list is sorted in the same order as the adapters returned by \ref ADL_Adapter_AdapterInfo_Get. This means
///								that the first XScreen info is for the first indexed adapter, the second XScreen matching the second and so on.
///								NOTE: The caller must free this list once they are done with it.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
ADL_EXTERNC int EXPOSED ADL2_Adapter_XScreenInfo_GetR2(ADL_CONTEXT_HANDLE context,LPXScreenInfoR2 *lppXScreenInfo);

///
/// \brief Function to retrieve all X Screen information for all OS-known adapters.
///
/// This function retrieves the X Screen information of all OS-known adapters on a Linux system. OS-known adapters can include adapters that currently exist in the system (logical adapters)
/// as well as ones that no longer exist in the system but are still recognized by the OS.
///
/// \platform
/// \LNX
/// \param[out] lppXScreenInfo Pointer to a list for storing the retrieved X Screen information. This list will be allocated by this function.
///								The size of the list equals the number of adapters returned by \ref ADL_Adapter_NumberOfAdapters_Get.
///								The list is sorted in the same order as the adapters returned by \ref ADL_Adapter_AdapterInfo_Get. This means
///								that the first XScreen info is for the first indexed adapter, the second XScreen matching the second and so on.
///								NOTE: The caller must free this list once they are done with it.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
ADL_EXTERNC int EXPOSED ADL_Adapter_XScreenInfo_GetR2(LPXScreenInfoR2 *lppXScreenInfo);

// \brief Set Display handle which can communicate with XServer, so no XOpenDisplay required within ADL_Main_Control_Create, the provided display handle will be used.
/// Note:  One reason to use this function is that one X window manager: compiz uses XGrabServer & XUngrabServer to call first OpenGL function, and XOpenDisplay is not
/// allowed between XGrabServer/XUngrabServer which will cause soft hang. one solution is to use the Display handle passed from OpenGL (actually from application).
/// Call this function before calling ADL_Main_Control_Create, it is the caller's responsibility to close the X display handle but not before calling ADL_Main_Control_Destroy,
/// and it is also the caller's responsibility to update the X display handle if the old one is freed and a new is used.
///
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in] dpy pointer to XServer Display handle (returned by XOpenDisplay)
/// \platform
/// \LNX
///
/// \return ADL_OK on success, else return ADL_ERR
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
ADL_EXTERNC int EXPOSED ADL2_XServerInfo_DisplayHandle_Set(ADL_CONTEXT_HANDLE context,Display* dpy);

/// Note:  One reason to use this function is that one X window manager: compiz uses XGrabServer & XUngrabServer to call first OpenGL function, and XOpenDisplay is not
/// allowed between XGrabServer/XUngrabServer which will cause soft hang. one solution is to use the Display handle passed from OpenGL (actually from application).
/// Call this function before calling ADL_Main_Control_Create, it is the caller's responsibility to close the X display handle but not before calling ADL_Main_Control_Destroy,
/// and it is also the caller's responsibility to update the X display handle if the old one is freed and a new is used.
///
/// \param[in] dpy pointer to XServer Display handle (returned by XOpenDisplay)
/// \platform
/// \LNX
///
/// \return ADL_OK on success, else return ADL_ERR
ADL_EXTERNC int EXPOSED ADL_XServerInfo_DisplayHandle_Set(Display* dpy);

///
/// \brief Set the window maximize size to a display or an entire desktop area.
///
/// The driver will override the Xinerama setting used by the window manager to determine the size and
/// position of maximized window. Since the Xinerama extension setting is used by other applications,
/// using this setting can affect more than the maximize behavior, for example it may affect the taskbar.
/// An X restart may be required after using this function.
/// This is a global setting for all desktops and adapters.
/// This feature is supported distributions supporting RandR 1.2 and above.
/// \platform
/// \LNX
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in] iMode The desired maximize window mode. See \ref define_maximizewindowmode for values.
/// \return If the function succeeds, the return value is \ref ADL_OK_RESTART or \ref ADL_OK . Otherwise the return value is an ADL error code. \ref define_adl_results
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
ADL_EXTERNC int EXPOSED ADL2_MaximizeWindowMode_Set (ADL_CONTEXT_HANDLE context,int iMode);

///
/// \brief Set the window maximize size to a display or an entire desktop area.
///
/// The driver will override the Xinerama setting used by the window manager to determine the size and
/// position of maximized window. Since the Xinerama extension setting is used by other applications,
/// using this setting can affect more than the maximize behavior, for example it may affect the taskbar.
/// An X restart may be required after using this function.
/// This is a global setting for all desktops and adapters.
/// This feature is supported distributions supporting RandR 1.2 and above.
/// \platform
/// \LNX
/// \param[in] iMode The desired maximize window mode. See \ref define_maximizewindowmode for values.
/// \return If the function succeeds, the return value is \ref ADL_OK_RESTART or \ref ADL_OK . Otherwise the return value is an ADL error code. \ref define_adl_results
ADL_EXTERNC int EXPOSED ADL_MaximizeWindowMode_Set (int iMode);

///
/// \brief Get the current and/or default window maximize size setting
///
/// The function will return the current and/or default window maximize size setting current used
/// by the driver to override the Xinarama settings.
/// This feature is supported distributions supporting RandR 1.2 and above.
/// \platform
/// \LNX
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[out] pCurMode The current maximize window mode. See \ref define_maximizewindowmode for values.
/// \param[out] pDefMode The default maximize window mode. See \ref define_maximizewindowmode for values.
/// \return If the fuction succeeds, the return value is \ref ADL_OK. Otherwize the return value is an ADL error code. \ref define_adl_results
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
ADL_EXTERNC int EXPOSED ADL2_MaximizeWindowMode_Get (ADL_CONTEXT_HANDLE context,int *pCurMode, int *pDefMode);

///
/// \brief Get the current and/or default window maximize size setting
///
/// The function will return the current and/or default window maximize size setting current used
/// by the driver to override the Xinarama settings.
/// This feature is supported distributions supporting RandR 1.2 and above.
/// \platform
/// \LNX
/// \param[out] pCurMode The current maximize window mode. See \ref define_maximizewindowmode for values.
/// \param[out] pDefMode The default maximize window mode. See \ref define_maximizewindowmode for values.
/// \return If the fuction succeeds, the return value is \ref ADL_OK. Otherwize the return value is an ADL error code. \ref define_adl_results
ADL_EXTERNC int EXPOSED ADL_MaximizeWindowMode_Get (int *pCurMode, int *pDefMode);

/// \brief Set the file descriptor which can communicate with the console driver
///
/// This function sets ADL to console mode. In this mode, ADL will not use XServer to communicate
/// with the driver, but IOCTL.
/// An optional file descriptor ay be passed in ADL to use instead of letting it determine a
/// file descriptor automatically. This file descriptor must point to an open AMD GPU device.
/// The file descriptor can be generated by using the ukiOpen function provided by the ATIUKI shared library.
/// This is an AMD provided library, and the Linux Base driver team can offer more information on how to use ukiOpen.
/// If the file descriptor is not set, ADL will determine the file descriptor automatically.
/// This must be called before \ref ADL_Main_Control_Create. If this function is called afterwards,
/// the function will fail.
/// \platform
/// \LNX
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in] fileDescriptor an open file descriptor to an AMD GPU device. If ADL_UNSET is used, then
/// ADL will use it's own file descriptor.
/// \return ADL_OK if ADLis set to the new mode and uses the new file descriptor, else an ADL error code \ref define_adl_result
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
ADL_EXTERNC int EXPOSED ADL2_ConsoleMode_FileDescriptor_Set(ADL_CONTEXT_HANDLE context,int fileDescriptor);

/// \brief Set the file descriptor which can communicate with the console driver
///
/// This function sets ADL to console mode. In this mode, ADL will not use XServer to communicate
/// with the driver, but IOCTL.
/// An optional file descriptor ay be passed in ADL to use instead of letting it determine a
/// file descriptor automatically. This file descriptor must point to an open AMD GPU device.
/// The file descriptor can be generated by using the ukiOpen function provided by the ATIUKI shared library.
/// This is an AMD provided library, and the Linux Base driver team can offer more information on how to use ukiOpen.
/// If the file descriptor is not set, ADL will determine the file descriptor automatically.
/// This must be called before \ref ADL_Main_Control_Create. If this function is called afterwards,
/// the function will fail.
/// \platform
/// \LNX
/// \param[in] fileDescriptor an open file descriptor to an AMD GPU device. If ADL_UNSET is used, then
/// ADL will use it's own file descriptor.
/// \return ADL_OK if ADLis set to the new mode and uses the new file descriptor, else an ADL error code \ref define_adl_result
ADL_EXTERNC int EXPOSED ADL_ConsoleMode_FileDescriptor_Set(int fileDescriptor);

/// \brief Shows an identifying watermark, or a number, on a particular display
///
/// This function is used to show an identifying watermark, or a number, on a particular display.
/// This watermark, or number, will only be shown on the target display; and, if that display is a
/// clone to another display, this identifier will only show on the target display and not on any
/// of the cloned displays.
/// Valid numbers that can be shown range from 1 to 99/
/// In addition, an '!' and checkmark can be shown. Note that you can only show a number,
/// exclamation mark, or the checkmark; you cannot show a combination of the three.
///
/// \platform
/// \LNX
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in] iAdapterIndex The ADL adapter index of the display to show the watermark on
/// \param[in] displayID The ADL display index of the display to show the watermark on
/// \param[in] WatermarkInfo The watermark information to show. Refer to \ref ADLIdentifyDisplay for more information.
///
/// \return ADL_OK if the watermark information has been properly set on the display, else ADL error code \ref define_adl_results
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
ADL_EXTERNC int EXPOSED ADL2_Display_IdentifyDisplay_Set (ADL_CONTEXT_HANDLE context,int iAdapterIndex, ADLDisplayID displayID, ADLIdentifyDisplay WatermarkInfo);

/// \brief Shows an identifying watermark, or a number, on a particular display
///
/// This function is used to show an identifying watermark, or a number, on a particular display.
/// This watermark, or number, will only be shown on the target display; and, if that display is a
/// clone to another display, this identifier will only show on the target display and not on any
/// of the cloned displays.
/// Valid numbers that can be shown range from 1 to 99/
/// In addition, an '!' and checkmark can be shown. Note that you can only show a number,
/// exclamation mark, or the checkmark; you cannot show a combination of the three.
///
/// \platform
/// \LNX
/// \param[in] iAdapterIndex The ADL adapter index of the display to show the watermark on
/// \param[in] displayID The ADL display index of the display to show the watermark on
/// \param[in] WatermarkInfo The watermark information to show. Refer to \ref ADLIdentifyDisplay for more information.
///
/// \return ADL_OK if the watermark information has been properly set on the display, else ADL error code \ref define_adl_results
ADL_EXTERNC int EXPOSED ADL_Display_IdentifyDisplay_Set (int iAdapterIndex, ADLDisplayID displayID, ADLIdentifyDisplay WatermarkInfo);

/// \brief Retrieves the identifying watermark state on a particular display
///
/// This function is used to retrieve the current identifying watermark state on a particular display.
///
/// \platform
/// \LNX
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in] iAdapterIndex The ADL adapter index of the display to query the watermark state
/// \param[in] displayID The ADL display index of the display to query the watermark state
/// \param[out] lpWatermarkInfo The watermark information currently being used on the target display.
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
ADL_EXTERNC int EXPOSED ADL2_Display_IdentifyDisplay_Get(ADL_CONTEXT_HANDLE context,int iAdapterIndex, ADLDisplayID displayID, ADLIdentifyDisplay *lpWatermarkInfo);

/// \brief Retrieves the identifying watermark state on a particular display
///
/// This function is used to retrieve the current identifying watermark state on a particular display.
///
/// \platform
/// \LNX
/// \param[in] iAdapterIndex The ADL adapter index of the display to query the watermark state
/// \param[in] displayID The ADL display index of the display to query the watermark state
/// \param[out] lpWatermarkInfo The watermark information currently being used on the target display.
ADL_EXTERNC int EXPOSED ADL_Display_IdentifyDisplay_Get(int iAdapterIndex, ADLDisplayID displayID, ADLIdentifyDisplay *lpWatermarkInfo);

/// \brief Retrieves the identify display capabilities
///
/// This function is used to retrieve the identify display capabilities supported by a particular graphics adapter.
/// It will return one or more of the following capabilities \ref define_identifydisplay_cap bits
///
/// \platform
/// \LNX
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in] iAdapterIndex The ADL adapter index of the graphics adapter to query identify display capabilities
/// \param[out] lpIdentifyDisplayCaps The identify display capabilities supported by the graphics adapter. It will contain one
///								or more bots from \ref define_identify_caps .
/// \param[out] lpIdentifyValidBits The identify display capabilities that this ADL driver si currently aware of.
///								pIdentifyDisplayCaps will contain a subset of the bits in this parameter. It will contain
///								one or more bits from \ref define_identify_caps .
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
ADL_EXTERNC int EXPOSED ADL2_Display_IdentifyDisplay_Cap(ADL_CONTEXT_HANDLE context,int iAdapterIndex, int *lpIdentifyDisplayCaps, int *lpIdentifyValidBits);

/// \brief Retrieves the identify display capabilities
///
/// This function is used to retrieve the identify display capabilities supported by a particular graphics adapter.
/// It will return one or more of the following capabilities \ref define_identifydisplay_cap bits
///
/// \platform
/// \LNX
/// \param[in] iAdapterIndex The ADL adapter index of the graphics adapter to query identify display capabilities
/// \param[out] lpIdentifyDisplayCaps The identify display capabilities supported by the graphics adapter. It will contain one
///								or more bots from \ref define_identify_caps .
/// \param[out] lpIdentifyValidBits The identify display capabilities that this ADL driver si currently aware of.
///								pIdentifyDisplayCaps will contain a subset of the bits in this parameter. It will contain
///								one or more bits from \ref define_identify_caps .
ADL_EXTERNC int EXPOSED ADL_Display_IdentifyDisplay_Cap(int iAdapterIndex, int *lpIdentifyDisplayCaps, int *lpIdentifyValidBits);

///
/// \brief Function to retrieve whether the system has memory management feature capabilities
/// 
/// This function is used to identify whether the current system is able to use the memory management feature, "ADL_FEATURE_TYPE_MEMORYMAN".
///
/// \platform
/// \LNX
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in] iAdapterIndex The ADL adapter index of the graphics adapter to query the memory management capabilities.
/// \param[out] lpCfgMemCap The integer that specified whether the memory management feature is supported or not. It returns either ADL_TRUE or ADL_FALSE.
ADL_EXTERNC int EXPOSED ADL2_Adapter_ConfigMemory_Cap (ADL_CONTEXT_HANDLE context, int iAdapterIndex, int * lpCfgMemCap);
/// @}
#endif /*__AMD_LNX_H__ */
