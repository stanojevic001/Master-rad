///
///  Copyright (c) 2008 - 2021 Advanced Micro Devices, Inc.
 
///  THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
///  EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
///  WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.

/// \file appprofiles.h
/// \brief Contains all appprofiles-related functions exposed by ADL for \ALL platforms.
///
/// This file contains all appprofiles-related functions exposed by ADL for \ALL platforms.
/// All functions in this file can be used as a reference to ensure
/// the specified function pointers can be used by the appropriate runtime
/// dynamic library loaders.

#ifndef APPPROFILES_H_
#define APPPROFILES_H_

#include "adl_structures.h"

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

/// \ingroup GAMINGAPI
///\defgroup APPPROFILESAPI Application Profiles APIs
/// This group outlines all Application Profiles APIs.

/// \addtogroup APPPROFILESAPI
/// @{

int HIDDEN GetAMDAdapterIndex(LPADLContext myContext);

///
/// \brief Function to Reload System appprofiles.
/// 
/// This function Reloads System appprofiles by reloading system profile and loading user profile.
/// \platform
/// \WIN
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code.   \ref define_adl_results
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
ADL_EXTERNC int EXPOSED ADL2_ApplicationProfiles_System_Reload(ADL_CONTEXT_HANDLE context);

///
/// \brief Function to Reload System appprofiles.
/// 
/// This function Reloads System appprofiles by reloading system profile and loading user profile.
/// \platform
/// \WIN
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code.   \ref define_adl_results
ADL_EXTERNC int EXPOSED ADL_ApplicationProfiles_System_Reload();

///
/// \brief Function to Load User appprofiles.
/// 
/// This function Loads User appprofiles by loadding system profile and user profile.
/// \platform
/// \WIN
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code.   \ref define_adl_results
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
ADL_EXTERNC int EXPOSED ADL2_ApplicationProfiles_User_Load(ADL_CONTEXT_HANDLE context);

///
/// \brief Function to Load User appprofiles.
/// 
/// This function Loads User appprofiles by loadding system profile and user profile.
/// \platform
/// \WIN
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code.   \ref define_adl_results
ADL_EXTERNC int EXPOSED ADL_ApplicationProfiles_User_Load();

///
/// \brief Function to Unload User appprofiles.
/// 
/// This function Unloads User appprofiles by unloading user profile.
/// \platform
/// \WIN
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code.   \ref define_adl_results
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
ADL_EXTERNC int EXPOSED ADL2_ApplicationProfiles_User_Unload(ADL_CONTEXT_HANDLE context);

///
/// \brief Function to Unload User appprofiles.
/// 
/// This function Unloads User appprofiles by unloading user profile.
/// \platform
/// \WIN
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code.   \ref define_adl_results
ADL_EXTERNC int EXPOSED ADL_ApplicationProfiles_User_Unload();



/* TODO++ NOT FINALIZED IN ADL

///
/// \brief Function to Get appprofiles status info.
/// 
/// This function Gets appprofiles status info such as system/user profile loaded, loaded profile valid or not.
/// \platform
/// \WIN
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code.   \ref define_adl_results
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
ADL_EXTERNC int EXPOSED ADL2_ApplicationProfiles_StatusInfo_Get(ADL_CONTEXT_HANDLE context);

///
/// \brief Function to Get appprofiles status info.
/// 
/// This function Gets appprofiles status info such as system/user profile loaded, loaded profile valid or not.
/// \platform
/// \WIN
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code.   \ref define_adl_results
ADL_EXTERNC int EXPOSED ADL_ApplicationProfiles_StatusInfo_Get();


ADL_EXTERNC int EXPOSED ADL_ApplicationProfiles_Get();
ADL_EXTERNC int EXPOSED ADL_ApplicationProfiles_Select();

*/

///
/// \brief Function to retrieve the profile of an application defined in driver.
/// 
/// This function retrieves the profile information of an application. 
/// This API uses the Caller's Memory Allocation Callback Function to allocate memory pointed by lppProfile. 
/// Caller is responsible to de-allocate the memory.
/// \platform
/// \WIN
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in]	FileName	Specifies the application file name
/// \param[in]	Path		Specifies the application file path
/// \param[in]	Version		Specifies the application version
/// \param[in]	AppProfileArea		Specifies the area the profile works on (like 'PX', 'D3D', etc. )
/// \param[out] lppProfile	The pointer to the pointer to the retrieved application profile. Set it to NULL prior to call this API.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
///
/// \remarks This API will be replaced with a new API that supports unicode. This API uses the memory allocation callback function provided by the user.
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
ADL_EXTERNC int EXPOSED ADL2_ApplicationProfiles_ProfileOfAnApplication_Search(ADL_CONTEXT_HANDLE context,const char* FileName, const char* Path, 
								const char* Version, const char* AppProfileArea, ADLApplicationProfile** lppProfile);

///
/// \brief Function to retrieve the profile of an application defined in driver.
/// 
/// This function retrieves the profile information of an application. 
/// This API uses the Caller's Memory Allocation Callback Function to allocate memory pointed by lppProfile. 
/// Caller is responsible to de-allocate the memory.
/// \platform
/// \WIN
/// \param[in]	FileName	Specifies the application file name
/// \param[in]	Path		Specifies the application file path
/// \param[in]	Version		Specifies the application version
/// \param[in]	AppProfileArea		Specifies the area the profile works on (like 'PX', 'D3D', etc. )
/// \param[out] lppProfile	The pointer to the pointer to the retrieved application profile. Set it to NULL prior to call this API.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
///
/// \remarks This API will be replaced with a new API that supports unicode. This API uses the memory allocation callback function provided by the user.
ADL_EXTERNC int EXPOSED ADL_ApplicationProfiles_ProfileOfAnApplication_Search(const char* FileName, const char* Path, 
								const char* Version, const char* AppProfileArea, ADLApplicationProfile** lppProfile);


///
/// \brief Function to retrieve the recent application list from registry.
/// 
/// This function retrieves the recent application list from registry. 
/// This API uses the Caller's Memory Allocation Callback Function to allocate memory pointed by lppAppList. 
/// Caller is responsible to de-allocate the memory.
/// \platform
/// \WIN
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in]	iListType	Specifies the type of the list to retrieve, defined in \ref ApplicationListType 
/// \param[out] lpNumApps	The pointer to the number of applications in the list. 
/// \param[out] lppAppList	The pointer to the pointer to the retrieved application list from registry. Set it to NULL prior to call this API.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
///
/// \remarks This API uses the memory allocation callback function provided by the user.
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
ADL_EXTERNC int EXPOSED ADL2_ApplicationProfiles_HitLists_Get(ADL_CONTEXT_HANDLE context, int iListType, int * lpNumApps, ADLApplicationData ** lppAppList);

///
/// \brief Function to retrieve the recent application list from registry.
/// 
/// This function retrieves the recent application list from registry. 
/// This API uses the Caller's Memory Allocation Callback Function to allocate memory pointed by lppAppList. 
/// Caller is responsible to de-allocate the memory.
/// \platform
/// \WIN
/// \param[in]	iListType	Specifies the type of the list to retrieve, defined in \ref ApplicationListType 
/// \param[out] lpNumApps	The pointer to the number of applications in the list. 
/// \param[out] lppAppList	The pointer to the pointer to the retrieved application list from registry. Set it to NULL prior to call this API.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
///
/// \remarks This API uses the memory allocation callback function provided by the user.
ADL_EXTERNC int EXPOSED ADL_ApplicationProfiles_HitLists_Get( int iListType, int * lpNumApps, ADLApplicationData ** lppAppList);


///
/// \brief Function to retrieve the recent application list from registry.
/// 
/// This function retrieves the recent application list from registry. 
/// This API uses the Caller's Memory Allocation Callback Function to allocate memory pointed by lppAppList. 
/// Caller is responsible to de-allocate the memory.
/// \platform
/// \WIN
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in]	iListType	Specifies the type of the list to retrieve, defined in \ref ApplicationListType 
/// \param[out] lpNumApps	The pointer to the number of applications in the list. 
/// \param[out] lppAppList	The pointer to the pointer to the retrieved application list from registry including process id. Set it to NULL prior to call this API.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
///
/// \remarks This API uses the memory allocation callback function provided by the user.
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
ADL_EXTERNC int EXPOSED ADL2_ApplicationProfiles_HitListsX3_Get(ADL_CONTEXT_HANDLE context, int iListType, int * lpNumApps, ADLApplicationDataX3 ** lppAppList);

///
/// \brief Function to retrieve the recent application list from registry.
/// 
/// This function retrieves the recent application list from registry. 
/// This API uses the Caller's Memory Allocation Callback Function to allocate memory pointed by lppAppList. 
/// Caller is responsible to de-allocate the memory.
/// \platform
/// \WIN
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in]	iListType	Specifies the type of the list to retrieve, defined in \ref ApplicationListType 
/// \param[out] lpNumApps	The pointer to the number of applications in the list. 
/// \param[out] lppAppList	The pointer to the pointer to the retrieved application list from registry. Set it to NULL prior to call this API.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
///
/// \remarks This API uses the memory allocation callback function provided by the user.
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
ADL_EXTERNC int EXPOSED ADL2_ApplicationProfiles_HitListsX2_Get(ADL_CONTEXT_HANDLE context, int iListType, int * lpNumApps, ADLApplicationDataX2 ** lppAppList);

///
/// \brief Function to retrieve the recent application list from registry.
/// 
/// This function retrieves the recent application list from registry. 
/// This API uses the Caller's Memory Allocation Callback Function to allocate memory pointed by lppAppList. 
/// Caller is responsible to de-allocate the memory.
/// \platform
/// \WIN
/// \param[in]	iListType	Specifies the type of the list to retrieve, defined in \ref ApplicationListType 
/// \param[out] lpNumApps	The pointer to the number of applications in the list. 
/// \param[out] lppAppList	The pointer to the pointer to the retrieved application list from registry. Set it to NULL prior to call this API.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
///
/// \remarks This API uses the memory allocation callback function provided by the user.
ADL_EXTERNC int EXPOSED ADL_ApplicationProfiles_HitListsX2_Get( int iListType, int * lpNumApps, ADLApplicationDataX2 ** lppAppList);

///
/// \brief \newAPI15 Function to enable/disable application profile KMD interception
/// 
/// The API allows an user mode process to enable/disable KMD app profile interception
///
/// \platform
/// \WIN
/// \param[in]	iAppType	Specify 1 for games
/// \param[in]  iProcId     The process id of the u ser mode process. KMD will stop interception if this process terminates for any reason.
/// \param[in]  iEnabled    1 - Enable, 0 - Disable the interception
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
ADL_EXTERNC int EXPOSED ADL2_ApplicationProfiles_AppInterception_Set(ADL_CONTEXT_HANDLE context, int iAppType, unsigned int iProcId, int iEnabled);

///
/// \brief \newAPI15 Function to set the list of application that KMD needs to intercept
/// 
/// Sets the list of application that KMD needs to intercept
///
/// \platform
/// \WIN
/// \param[in] iAppType         Specify 1 for games
/// \param[in] iNumberOfApps    Number of apps in the list
/// \param[in] lpAppInfo        Array of App info in the list
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
ADL_EXTERNC int EXPOSED ADL2_ApplicationProfiles_AppInterceptionList_Set(ADL_CONTEXT_HANDLE context, int iAppType, int iNumberOfApps, ADLAppInterceptionInfo* lpAppInfo);

///
/// \brief \newAPI15 Function to return list of applications declared in given driver area
/// 
/// This function builds and returns list of applications that exist in the given area of System, OEM and User blobs. User blob has precedence over OEM blob, OEM blob has precedence over System blob.
/// \platform
/// \WIN
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in] driverArea    	 Specifies driver area
/// \param[out] numApps 	     Returns number of application record in given driver area
/// \param[out] adlApplications  Returns the pointer to application records
/// \param[in] allowDuplication  If it's false and duplicated records of application exist (e.g. in System and User blob), then only one recored is returned, otherwise, return all same records from all blobs
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
///
/// \remarks This API builds and returns list of applications that exist in the given area of System, OEM and User blobs. User blob has precedence over OEM blob, OEM blob has precedence over System blob.
/// *** This function CANNOT be used outside of AMD because the return parameter contains structure from internal "shared_escape.h"
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
ADL_EXTERNC int EXPOSED ADL2_ApplicationProfiles_Applications_Get(ADL_CONTEXT_HANDLE context, const wchar_t * driverArea, int * numApps, ADLApplicationRecord ** adlApplications);

///
/// \brief \newAPI15 Function to return list of applications declared in given driver area
/// 
/// This function builds and returns list of applications that exist in the given area of System, OEM and User blobs. User blob has precedence over OEM blob, OEM blob has precedence over System blob.
/// \platform
/// \WIN
/// \param[in] driverArea    	 Specifies driver area
/// \param[out] numApps 	     Returns number of application record in given driver area
/// \param[out] adlApplications  Returns the pointer to application records
/// \param[in] allowDuplication  If it's false and duplicated records of application exist (e.g. in System and User blob), then only one recored is returned, otherwise, return all same records from all blobs
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
///
/// \remarks This API builds and returns list of applications that exist in the given area of System, OEM and User blobs. User blob has precedence over OEM blob, OEM blob has precedence over System blob.
/// *** This function CANNOT be used outside of AMD because the return parameter contains structure from internal "shared_escape.h"
ADL_EXTERNC int EXPOSED ADL_ApplicationProfiles_Applications_Get(const wchar_t * driverArea, int * numApps, ADLApplicationRecord ** adlApplications);

///
/// \brief \newAPI15 Function to resume a KMD suspended process
/// 
/// The API allows an user mode process to instruct KMD to resume a process that it has suspended
///
/// \platform
/// \WIN
/// \param[in] iAppType     Specify 1 for games
/// \param[in] ProcessId    The id of the process that is to be resumed
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
ADL_EXTERNC int EXPOSED ADL2_ApplicationProfiles_AppStartStop_Resume(ADL_CONTEXT_HANDLE context, int iAppType, unsigned int ProcessId);

///
/// \brief \newAPI15 Function to retrieve information about the recent App Start/Stop event
/// 
/// The API allows an user mode process to retrieve information about the recent App Start/Stop event
///
/// \platform
/// \WIN
/// \param[in, out] lpAppInfo   One ADLAppInterceptionInfo strucuture.
///                             For input, specify the app state (APP_PROC_CREATION or APP_PROC_TERMINATE).
///                             ADL will fill in other information for output.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
ADL_EXTERNC int EXPOSED ADL2_ApplicationProfiles_AppStartStopInfo_Get(ADL_CONTEXT_HANDLE context, int iAppType, ADLAppInterceptionInfo* lpAppInfo);

///
/// \brief \newAPI15 Function to convert C style structures into Compact style for writing a blob file
/// 
/// This function converts C style structures into Compact style for writing a blob file
/// \platform
/// \WIN
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in]	pCustomisation	Specifies pointer to Customization of database 
/// \param[out] outCompact	The pointer to compact structure. 
/// \param[out] outSize	    The size of compact structure
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
///
/// \remarks This API converts C style structures into Compact style for writing a blob file
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
ADL_EXTERNC int EXPOSED ADL2_ApplicationProfiles_ConvertToCompact(ADL_CONTEXT_HANDLE context, CUSTOMISATIONS * pCustomisation, BINFILE * outCompact, int * outSize);

///
/// \brief \newAPI15 Function to convert C style structures into Compact style for writing a blob file
/// 
/// This function converts C style structures into Compact style for writing a blob file
/// \platform
/// \WIN
/// \param[in]	pCustomisation	Specifies pointer to Customization of database 
/// \param[out] outCompact	The pointer to compact structure. 
/// \param[out] outSize	    The size of compact structure
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
///
/// \remarks This API converts C style structures into Compact style for writing a blob file
ADL_EXTERNC int EXPOSED ADL_ApplicationProfiles_ConvertToCompact(CUSTOMISATIONS * pCustomisation, BINFILE * outCompact, int * outSize);

///
/// \brief \newAPI15 Function to retrieve privacy type for the specified area
/// 
/// This function retrieves privacy type for the specified area
/// \platform
/// \WIN
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in]	DriverArea	Specifies driver area
/// \param[out] outDriverAreaPrivacy	The pointer to privacy for the specified area/
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
///
/// \remarks This API retrieves privacy type for the specified area
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
ADL_EXTERNC int EXPOSED ADL2_ApplicationProfiles_DriverAreaPrivacy_Get(ADL_CONTEXT_HANDLE context, const wchar_t * DriverArea, PRIVACYTYPES * outDriverAreaPrivacy);

///
/// \brief \newAPI15 Function to retrieve privacy type for the specified area
/// 
/// This function retrieves privacy type for the specified area
/// \platform
/// \WIN
/// \param[in]	DriverArea	Specifies driver area
/// \param[out] outDriverAreaPrivacy	The pointer to privacy for the specified area/
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
///
/// \remarks This API retrieves privacy type for the specified area
ADL_EXTERNC int EXPOSED ADL_ApplicationProfiles_DriverAreaPrivacy_Get(const wchar_t * DriverArea, PRIVACYTYPES * outDriverAreaPrivacy);

///
/// \brief \newAPI15 Function to retrieve the pointer to Customization structure of the specified blob file
/// 
/// This function retrieves the pointer to Customization structure of the specified blob file.
/// \platform
/// \WIN
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in]	Databaseln	Specifies the type of blob file
/// \param[out] pCustomizationOut	The pointer to Customization structure of the specified blob file
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
///
/// \remarks This API retrieves the pointer to Customization structure of the specified blob file
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
ADL_EXTERNC int EXPOSED ADL2_ApplicationProfiles_GetCustomization(ADL_CONTEXT_HANDLE context, ADL_AP_DATABASE Databaseln, CUSTOMISATIONS * pCustomizationOut);

///
/// \brief \newAPI15 Function to retrieve the pointer to Customization structure of the specified blob file
/// 
/// This function retrieves the pointer to Customization structure of the specified blob file.
/// \platform
/// \WIN
/// \param[in]	Databaseln	Specifies the type of blob file
/// \param[out] pCustomizationOut	The pointer to Customization structure of the specified blob file
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
///
/// \remarks This API retrieves the pointer to Customization structure of the specified blob file
ADL_EXTERNC int EXPOSED ADL_ApplicationProfiles_GetCustomization(ADL_AP_DATABASE Databaseln, CUSTOMISATIONS * pCustomizationOut);

///
/// \brief \newAPI15 Function to create new application profile.
/// 
/// This function creates new application based on driver area, profile name and property records.
/// \platform
/// \WIN
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in] driverArea  Specifies driver area where profile declares
/// \param[in] profileName Specifies the name of profile to be created
/// \param[in] numProperties Specifies the number of properties in the profile to be created
/// \param[in] propertyRecords  The pointer to property records in the profile to be created
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
///
/// \remarks This API add a profile to the specified Area
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
ADL_EXTERNC int EXPOSED ADL2_ApplicationProfiles_Profile_Create(ADL_CONTEXT_HANDLE context, const wchar_t * driverArea, const wchar_t * profileName, int numProperties, const ADLPropertyRecordCreate * propertyRecords);

///
/// \brief \newAPI15 Function to create new application profile.
/// 
/// This function creates new application based on driver area, profile name and property records.
/// \platform
/// \WIN
/// \param[in] driverArea  Specifies driver area where profile declares
/// \param[in] profileName Specifies the name of profile to be created
/// \param[in] numProperties Specifies the number of properties in the profile to be created
/// \param[in] propertyRecords  The pointer to property records in the profile to be created
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
///
/// \remarks This API add a profile to the specified Area
ADL_EXTERNC int EXPOSED ADL_ApplicationProfiles_Profile_Create(const wchar_t * driverArea, const wchar_t * profileName, int numProperties, const ADLPropertyRecordCreate * propertyRecords);

///
/// \brief \newAPI15 Function to check if the specified profile exist or not in system blob.
/// 
/// This function checks if the specified profile exist or not in system blob. 
/// \platform
/// \WIN
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in]	DriverArea	Specifies driver area
/// \param[in]  ProfileName	Specifies the name of profile
/// \param[out] outExists	Indicates if the specified profile exists or not
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
///
/// \remarks This API checks if the specified profile exist or not in system blob.
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
ADL_EXTERNC int EXPOSED ADL2_ApplicationProfiles_Profile_Exist(ADL_CONTEXT_HANDLE context, const wchar_t * DriverArea, const wchar_t * ProfileName, BOOL * outExists);

///
/// \brief \newAPI15 Function to check if the specified profile exist or not in system blob.
/// 
/// This function checks if the specified profile exist or not in system blob. 
/// \platform
/// \WIN
/// \param[in]	DriverArea	Specifies driver area
/// \param[in]  ProfileName	Specifies the name of profile
/// \param[out] outExists	Indicates if the specified profile exists or not
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
///
/// \remarks This API checks if the specified profile exist or not in system blob.
ADL_EXTERNC int EXPOSED ADL_ApplicationProfiles_Profile_Exist(const wchar_t * DriverArea, const wchar_t * ProfileName, BOOL * outExists);

///
/// \brief \newAPI15 Function to remove the specified profile from the User blb.
/// 
/// This function removes the specified profile from the User blb.
/// \platform
/// \WIN
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in] driverArea  Specifies driver area where profile delcares 
/// \param[in] profileName Specifies the name of profile to be removed
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
///
/// \remarks This API removes the specified profile from the User blb.
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
ADL_EXTERNC int EXPOSED ADL2_ApplicationProfiles_Profile_Remove(ADL_CONTEXT_HANDLE context, const wchar_t * driverArea, const wchar_t * profileName);

///
/// \brief \newAPI15 Function to remove the specified profile from the User blb.
/// 
/// This function removes the specified profile from the User blb.
/// \platform
/// \WIN
/// \param[in] driverArea  Specifies driver area where profile delcares 
/// \param[in] profileName Specifies the name of profile to be removed
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
///
/// \remarks This API removes the specified profile from the User blb.
ADL_EXTERNC int EXPOSED ADL_ApplicationProfiles_Profile_Remove(const wchar_t * driverArea, const wchar_t * profileName);

///
/// \brief \newAPI15 Function to assign a profile in a new or existing application record.
/// 
/// This function assigns a profile in a new or existing application record.
/// \platform
/// \WIN
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in]	FileName	Specifies the name of file
/// \param[in] Path    	Specifies the path where file locates
/// \param[in] Version 	Specifies version
/// \param[in] DriverArea  Specifies driver area where Profile exists
/// \param[in] ProfileName Specifies Profile to use
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
///
/// \remarks This API assigns a profile in a new or existing application record. If area exists, then override use record, otherwise, create a new use record
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
ADL_EXTERNC int EXPOSED ADL2_ApplicationProfiles_ProfileApplication_Assign(ADL_CONTEXT_HANDLE context, const wchar_t * FileName, const wchar_t * Path, const wchar_t * Version, const wchar_t * DriverArea, const wchar_t * ProfileName);

///
/// \brief \newAPI15 Function to assign a profile in a new or existing application record.
/// 
/// This function assigns a profile in a new or existing application record.
/// \platform
/// \WIN
/// \param[in]	FileName	Specifies the name of file
/// \param[in] Path    	Specifies the path where file locates
/// \param[in] Version 	Specifies version
/// \param[in] DriverArea  Specifies driver area where Profile exists
/// \param[in] ProfileName Specifies Profile to use
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
///
/// \remarks This API assigns a profile in a new or existing application record. If area exists, then override use record, otherwise, create a new use record
ADL_EXTERNC int EXPOSED ADL_ApplicationProfiles_ProfileApplication_Assign(const wchar_t * FileName, const wchar_t * Path, const wchar_t * Version, const wchar_t * DriverArea, const wchar_t * ProfileName);

///
/// \brief \newAPI15 Function to assign a profile in a new or existing application record.
/// 
/// This function assigns a profile in a new or existing application record.
/// \platform
/// \WIN
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in]	FileName	Specifies the name of file
/// \param[in] Path    	Specifies the path where file locates
/// \param[in] Version 	Specifies version
/// \param[in] Title 	Specifies title
/// \param[in] DriverArea  Specifies driver area where Profile exists
/// \param[in] ProfileName Specifies Profile to use
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
///
/// \remarks This API assigns a profile in a new or existing application record. If area exists, then override use record, otherwise, create a new use record
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
ADL_EXTERNC int EXPOSED ADL2_ApplicationProfiles_ProfileApplicationX2_Assign(ADL_CONTEXT_HANDLE context, const wchar_t * FileName, const wchar_t * Path, const wchar_t * Version, const wchar_t * Title, const wchar_t * DriverArea, const wchar_t * ProfileName);

///
/// \brief \newAPI15 Function to assign a profile in a new or existing application record.
/// 
/// This function assigns a profile in a new or existing application record.
/// \platform
/// \WIN
/// \param[in]	FileName	Specifies the name of file
/// \param[in] Path    	Specifies the path where file locates
/// \param[in] Version 	Specifies version
/// \param[in] Title 	Specifies title
/// \param[in] DriverArea  Specifies driver area where Profile exists
/// \param[in] ProfileName Specifies Profile to use
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
///
/// \remarks This API assigns a profile in a new or existing application record. If area exists, then override use record, otherwise, create a new use record
ADL_EXTERNC int EXPOSED ADL_ApplicationProfiles_ProfileApplicationX2_Assign(const wchar_t * FileName, const wchar_t * Path, const wchar_t * Version, const wchar_t * Title, const wchar_t * DriverArea, const wchar_t * ProfileName);

///
/// \brief \newAPI15 Function to retrieve the profile of an application defined in driver.
/// 
/// This function provides capabilities which are identical to existing ADL_ApplicationProfiles_ProfileOfAnApplication_Search. Distinct of existing 
//  ADL_ApplicationProfiles_ProfileOfAnApplication_Search the method will not issue AP_SELECT and AP_GET KMD escapes. Instead it will use in-memory 
//  instance of APL to execute its APL_SelectProfile and APL_GetProfile API.
//  expected that the method will be called by 3rd-parties applications. Internal clients will also call the method only for testing purposes. 
//  Motivation for introducing the method is to enable members of CCC team to test their changes in KMD APL application data look-up mechanism.
/// This API uses the Caller's Memory Allocation Callback Function to allocate memory pointed by lppProfile. 
/// Caller is responsible to de-allocate the memory.
/// \platform
/// \WIN
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in] fileName	Specifies the name of file
/// \param[in] path    	Specifies the path where file locates
/// \param[in] version 	Specifies version
/// \param[in] appProfileArea  Specifies driver area where Profile exists
/// \param[out] lppProfile  The pointer to the profile. Will be used to return profiles used by specific application record in the given driver area.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
///
/// \remarks This API removes the specified application record. rNote. OtNote that this function will ONLY reside in private portion of ADL for internal debug
/// only, never exposed to public.
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
ADL_EXTERNC int EXPOSED ADL2_ApplicationProfiles_ProfileOfAnApplication_InMemorySearch(ADL_CONTEXT_HANDLE context, const wchar_t* fileName, const wchar_t* path, const wchar_t* version, const wchar_t* appProfileArea,
    ADLApplicationProfile** lppProfile);

/// \brief \newAPI15 This API uses the Caller's Memory Allocation Callback Function to allocate memory pointed by lppProfile. 
/// Caller is responsible to de-allocate the memory.
/// \platform
/// \WIN
/// \param[in] fileName	Specifies the name of file
/// \param[in] path    	Specifies the path where file locates
/// \param[in] version 	Specifies version
/// \param[in] appProfileArea  Specifies driver area where Profile exists
/// \param[out] lppProfile  The pointer to the profile. Will be used to return profiles used by specific application record in the given driver area.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
///
/// \remarks This API removes the specified application record. rNote. OtNote that this function will ONLY reside in private portion of ADL for internal debug
/// only, never exposed to public.
ADL_EXTERNC int EXPOSED ADL_ApplicationProfiles_ProfileOfAnApplication_InMemorySearch(const wchar_t* fileName, const wchar_t* path, const wchar_t* version, const wchar_t* appProfileArea,
    ADLApplicationProfile** lppProfile);

///
/// \brief \newAPI15 Function to retrieve the profile of an application defined in driver.
/// 
/// This function retrieves the profile information of an application. 
/// This API uses the Caller's Memory Allocation Callback Function to allocate memory pointed by lppProfile. 
/// Caller is responsible to de-allocate the memory.
/// \platform
/// \WIN
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in]	FileName	Specifies the application file name
/// \param[in]	Path		Specifies the application file path
/// \param[in]	Version		Specifies the application version
/// \param[in]	AppProfileArea		Specifies the area the profile works on (like 'PX', 'D3D', etc. )
/// \param[out] lppProfile	The pointer to the pointer to the retrieved application profile. Set it to NULL prior to call this API.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
///
/// \remarks This API uses the memory allocation callback function provided by the user.
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
ADL_EXTERNC int EXPOSED ADL2_ApplicationProfiles_ProfileOfAnApplicationX2_Search(ADL_CONTEXT_HANDLE context, const wchar_t* FileName, const wchar_t* Path,
    const wchar_t* Version, const wchar_t* AppProfileArea, ADLApplicationProfile** lppProfile);

///
/// \brief \newAPI15 Function to retrieve the profile of an application defined in driver.
/// 
/// This function retrieves the profile information of an application. 
/// This API uses the Caller's Memory Allocation Callback Function to allocate memory pointed by lppProfile. 
/// Caller is responsible to de-allocate the memory.
/// \platform
/// \WIN
/// \param[in]	FileName	Specifies the application file name
/// \param[in]	Path		Specifies the application file path
/// \param[in]	Version		Specifies the application version
/// \param[in]	AppProfileArea		Specifies the area the profile works on (like 'PX', 'D3D', etc. )
/// \param[out] lppProfile	The pointer to the pointer to the retrieved application profile. Set it to NULL prior to call this API.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
///
/// \remarks This API uses the memory allocation callback function provided by the user.
ADL_EXTERNC int EXPOSED ADL_ApplicationProfiles_ProfileOfAnApplicationX2_Search(const wchar_t* FileName, const wchar_t* Path,
    const wchar_t* Version, const wchar_t* AppProfileArea, ADLApplicationProfile** lppProfile);

///
/// \brief \newAPI15 Function to retrieve data type for the specified property.
/// 
/// This function retrieves data type for the specified property. 
/// \platform
/// \WIN
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in]	DriverArea	 Specifies driver area where Property belong to
/// \param[in]	PropertyName Specifies name of property
/// \param[out] outType  	 The data type of property
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
///
/// \remarks This API retrieves data type for the specified property.
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
ADL_EXTERNC int EXPOSED ADL2_ApplicationProfiles_PropertyType_Get(ADL_CONTEXT_HANDLE context, const wchar_t * DriverArea, const wchar_t * PropertyName, DATATYPES * outType);

///
/// \brief \newAPI15 Function to retrieve data type for the specified property.
/// 
/// This function retrieves data type for the specified property. 
/// \platform
/// \WIN
/// \param[in]	DriverArea	 Specifies driver area where Property belong to
/// \param[in]	PropertyName Specifies name of property
/// \param[out] outType  	 The data type of property
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
///
/// \remarks This API retrieves data type for the specified property.
ADL_EXTERNC int EXPOSED ADL_ApplicationProfiles_PropertyType_Get(const wchar_t * DriverArea, const wchar_t * PropertyName, DATATYPES * outType);


///
/// \brief \newAPI15 Function to return release of installed system application profile blob file.
/// 
/// This function returns release of installed system application profile blob file.
/// \platform
/// \WIN
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[out] strRelease  The pointer to the stRelease. 
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
///
/// \remarks This API returns release of installed system application profile blob file.
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
ADL_EXTERNC int EXPOSED ADL2_ApplicationProfiles_Release_Get(ADL_CONTEXT_HANDLE context, wchar_t** strRelease);

///
/// \brief \newAPI15 Function to return release of installed system application profile blob file.
/// 
/// This function returns release of installed system application profile blob file.
/// \platform
/// \WIN
/// \param[out] strRelease  The pointer to the stRelease. 
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
///
/// \remarks This API returns release of installed system application profile blob file.
ADL_EXTERNC int EXPOSED ADL_ApplicationProfiles_Release_Get(wchar_t** strRelease);


///
/// \brief \newAPI15 Function to remove the specified application record 
/// 
/// This function removes the specified application record.
/// \platform
/// \WIN
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in]	FileName	Specifies the name of file
/// \param[in] Path    	Specifies the path where file locates
/// \param[in] Version 	Specifies version
/// \param[in] DriverArea  Specifies driver area where Profile exists
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
///
/// \remarks This API removes the specified application record.
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
ADL_EXTERNC int EXPOSED ADL2_ApplicationProfiles_RemoveApplication(ADL_CONTEXT_HANDLE context, const wchar_t* FileName, const wchar_t* Path, const wchar_t* Version, const wchar_t* DriverArea);

///
/// \brief \newAPI15 Function to remove the specified application record 
/// 
/// This function removes the specified application record.
/// \platform
/// \WIN
/// \param[in]	FileName	Specifies the name of file
/// \param[in] Path    	Specifies the path where file locates
/// \param[in] Version 	Specifies version
/// \param[in] DriverArea  Specifies driver area where Profile exists
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
///
/// \remarks This API removes the specified application record.
ADL_EXTERNC int EXPOSED ADL_ApplicationProfiles_RemoveApplication(const wchar_t* FileName, const wchar_t* Path, const wchar_t* Version, const wchar_t* DriverArea);

///
/// \brief \newAPI15 Second Version of function to set the application properties provided to KMD along with possible interception requirements
/// 
/// Sets the list of application that KMD might need to intercept, have choice to ask KMD to WaitToResume on app load or not
///
/// \platform
/// \WIN
/// \param[in] iAppType         Specify 1 for games
/// \param[in] iNumberOfApps    Number of apps in the list
/// \param[in] lpAppInfo        Array of App info in the list
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
ADL_EXTERNC int EXPOSED ADL2_ApplicationProfilesX2_AppInterceptionList_Set(ADL_CONTEXT_HANDLE context, int iAppType, int iNumberOfApps, ADLAppInterceptionInfoX2* lpAppInfo);

///
/// \brief \newAPI15 Function to retrieve information about the recent App Start/Stop event
/// 
/// The API allows an user mode process to retrieve information about the recent App Start/Stop event
///
/// \platform
/// \WIN
/// \param[in, out] lpAppInfo   One ADLAppInterceptionInfo strucuture.
///                             ADL will fill in other information for output.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
ADL_EXTERNC int EXPOSED ADL2_ApplicationProfiles_AppStartStopInfo_Get(ADL_CONTEXT_HANDLE context, int iAppType, ADLAppInterceptionInfo* lpAppInfo);

/// @}

#endif /* appprofiles_H_ */
