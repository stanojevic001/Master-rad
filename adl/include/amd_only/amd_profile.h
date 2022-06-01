/*********************************************************************************************************************\
*  Module Name    amd_profile.h
*  Project        ADL
*  Device         
*
*  Description    A collection of Apply profile functions used
*
*  Copyright (c) 2008 - 2021 Advanced Micro Devices, Inc. (unpublished)
*
*  All rights reserved.  This notice is intended as a precaution against inadvertent publication and does not imply 
*  publication or any waiver of confidentiality.  The year included in the foregoing notice is the year of creation 
*  of the work.
*
\*********************************************************************************************************************/
#ifndef AMD_PROFILE_H
#define AMD_PROFILE_H

#if defined (_WIN32) || defined(_WIN64)
#include <windows.h>
#endif

#include "ProfileStructure.h"

#ifndef ADL_EXTERNC
#ifdef __cplusplus
#define ADL_EXTERNC extern "C"
#else
#define ADL_EXTERNC
#endif
#endif

/// Defines for (un)setting expansion options.
#define UNSET_EXPANSION_OPTION 0
#define SET_EXPANSION_OPTION   1

/// Size of the string that contains the device name.
#define DEVICE_NAME_SIZE 32

/// 
/// \brief  Function to retrieve the expansion options for a specified display.
/// 
/// \param[in] iAdapterIndex The The ADL index handle of the desired adapter.
/// \param[in] iDisplayIndex The desired display index.
/// \param[out] piExpansion The retrieved expansion options.
void HIDDEN Display_ExpansionOptions_Get(int iAdapterIndex, int iDisplayIndex, int *piExpansion);

///
/// \brief Function to set the expansion options for a specified display, if they are different then currently set.
///
/// \param[in] iAdapterIndex  The ADL index handle of the desired adapter.
/// \param[in] iDisplayIndex  The desired display index.
/// \param[in] iValue The desired flags.
/// \param[out] piChanged Indicates whether the expansion options have changed. If options have been changed, it is set to TRUE. Otherwise it is set to FALSE.
void HIDDEN Display_ExpansionOptions_Set(int iAdapterIndex, int iDisplayIndex, int iValue, int *piChanged);

///
/// \brief Function to copy a driver profile to the adapter driver configuration.
/// 
/// \param[in] pastDrvProfile  The desired driver profile (source).
/// \param[out] pstAdapterDrvCfg  The desired adapter driver configuration (target).
void HIDDEN DrvProfileToAdapterDrvCfg_Copy(DrvProfile *pastDrvProfile, DI_ADAPTERDRIVERCONFIG *pstAdapterDrvCfg);

/// 
/// \brief Function to copy profile information retrieved from the OS to a specified driver profile.
///
/// \param[in] iAdapterIndex The ADL index handle of the adapter from which to copy (source).
/// \param[out] pastDrvProfile The desired driver profile (target).
///
/// \return If the function succeeds, the return value is is 1. Otherwise, the return value is 0.
int HIDDEN OSDataToProfile_Copy(int iAdapterIndex, DrvProfile *pastDrvProfile);

///
/// \brief Function to apply expansion if any change is required.
///  
/// \param[in] iAdapterIndex  The ADL index handle of the desired adapter.
/// \param[in] pastProfileToApply The the profile to be applied.
/// \param[out] pabExpansionApplied The set per driver (controller) if expansion is applied.
void HIDDEN Display_Expansion_Apply(int iAdapterIndex, DrvProfile *pastProfileToApply, int *pabExpansionApplied);

///
/// \brief Function to remove an extended desktop if it is not used in the profile that is to be applied.
///
/// \param[in] iAdapterIndex  The ADL index handle of the desired adapter.
/// \param[in] pastProfileToApply The profile to be applied.
/// \param[out] pastCurrentProfile The (current) profile to be replaced.
///  
/// \return If the function succeeds, ADL_OK is returned. Otherwise ADL_ERR_NULL_POINTER is returned.
int HIDDEN Display_IfRequired_RemoveDesktop(int iAdapterIndex, DrvProfile *pastProfileToApply, 
                                            DrvProfile *pastCurrentProfile);

/// 
/// \brief Function to set the mode per driver if a mode set is still required.
///  
/// \param[in] iAdapterIndex The ADL index handle of the desired adapter.
/// \param[in] pastProfileToApply The profile to be applied.
/// \param[in] pastCurrentProfile The (current) profile to be replaced.
/// \param[in] pabModeSetRequired Specifies that a mode set is still required.
/// 
/// \return If the function succeeds, ADL_OK is returned. Otherwise ADL_ERR_NULL_POINTER is returned.
int HIDDEN Display_IfRequired_SetMode(int iAdapterIndex, DrvProfile *pastProfileToApply, 
                                      DrvProfile *pastCurrentProfile, int *pabModeSetRequired);

////////////////// Functions below need to be accessible from outside ADL /////////////////////////////////////////////////////

///
/// \brief Function to apply the passed in profile.
///  
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in] iAdapterIndex  The ADL index handle of the desired adapter.
/// \param[in] pastProfileToApply  The profile to be applied.
/// \param[in] ulConnectedDisplays Currently connected displays.
/// 
/// \return If the function succeeds, ADL_OK is returned. Otherwise ADL_ERR_NULL_POINTER is returned.
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
ADL_EXTERNC int EXPOSED ADL2_ADC_Profile_Apply(ADL_CONTEXT_HANDLE context,int iAdapterIndex, DrvProfile *pastProfileToApply, ULONG ulConnectedDisplays);

///
/// \brief Function to apply the passed in profile.
///  
/// \param[in] iAdapterIndex  The ADL index handle of the desired adapter.
/// \param[in] pastProfileToApply  The profile to be applied.
/// \param[in] ulConnectedDisplays Currently connected displays.
/// 
/// \return If the function succeeds, ADL_OK is returned. Otherwise ADL_ERR_NULL_POINTER is returned.
ADL_EXTERNC int EXPOSED ADL_ADC_Profile_Apply(int iAdapterIndex, DrvProfile *pastProfileToApply, ULONG ulConnectedDisplays);

///
/// \brief Function to retrieve the currently applied profile from the driver.
///
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in] iAdapterIndex  The ADL index handle of the desired adapter.
/// \param[in] pstConnectedProfile The connected profile is saved here.
/// \param[in] pstSelectedProfile  The selected profile is saved here.
/// \param[in] ulConnectedDisplays The currently connected displays.
///
/// \return If the function succeeds, ADL_OK is returned. Otherwise ADL_ERR_NULL_POINTER is returned.
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
ADL_EXTERNC int EXPOSED ADL2_ADC_CurrentProfileFromDrv_Get(ADL_CONTEXT_HANDLE context,int iAdapterIndex, ConnectedProfile *pstConnectedProfile, 
                                              SelectedProfile *pstSelectedProfile, ULONG ulConnectedDisplays); 

///
/// \brief Function to retrieve the currently applied profile from the driver.
///
/// \param[in] iAdapterIndex  The ADL index handle of the desired adapter.
/// \param[in] pstConnectedProfile The connected profile is saved here.
/// \param[in] pstSelectedProfile  The selected profile is saved here.
/// \param[in] ulConnectedDisplays The currently connected displays.
///
/// \return If the function succeeds, ADL_OK is returned. Otherwise ADL_ERR_NULL_POINTER is returned.
ADL_EXTERNC int EXPOSED ADL_ADC_CurrentProfileFromDrv_Get(int iAdapterIndex, ConnectedProfile *pstConnectedProfile, 
                                              SelectedProfile *pstSelectedProfile, ULONG ulConnectedDisplays); 

///
/// \brief Function to copy the required profile information retrieved from the driver to a profile.  This function also
///           retrieves and saves the expansion settings from the driver.
///  
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in] iAdapterIndex  The ADL index handle of the desired adapter.
/// \param[in] pastDrvProfile The desire driver profile (target).
/// \param[in] pastDriverData The desire driver data(source).
/// 
/// \return If the function succeeds, ADL_OK is returned. Otherwise ADL_ERR_NULL_POINTER is returned.
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
 ADL_EXTERNC int EXPOSED ADL2_ADC_DrvDataToProfile_Copy(ADL_CONTEXT_HANDLE context,int iAdapterIndex, DrvProfile *pastDrvProfile, DI_DRIVER_DATA *pastDriverData);

///
/// \brief Function to copy the required profile information retrieved from the driver to a profile.  This function also
///           retrieves and saves the expansion settings from the driver.
///  
/// \param[in] iAdapterIndex  The ADL index handle of the desired adapter.
/// \param[in] pastDrvProfile The desire driver profile (target).
/// \param[in] pastDriverData The desire driver data(source).
/// 
/// \return If the function succeeds, ADL_OK is returned. Otherwise ADL_ERR_NULL_POINTER is returned.
 ADL_EXTERNC int EXPOSED ADL_ADC_DrvDataToProfile_Copy(int iAdapterIndex, DrvProfile *pastDrvProfile, DI_DRIVER_DATA *pastDriverData);

///
/// \brief Function to remap the controllers and displays based on the passed in DrvProfile.
///  
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in] iAdapterIndex  The ADL index handle of the desired adapter.
/// \param[in] pastProfileToApply The the profile to be applied.
/// \param[in] pabModeSetRequired If a mode change is occurring then set this to FALSE.
/// 
/// \return If the function succeeds, ADL_OK is returned. Otherwise ADL_ERR_NULL_POINTER is returned.
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
ADL_EXTERNC int EXPOSED ADL2_Remap(ADL_CONTEXT_HANDLE context,int iAdapterIndex, DrvProfile *pastProfileToApply, int *pabModeSetRequired);

///
/// \brief Function to remap the controllers and displays based on the passed in DrvProfile.
///  
/// \param[in] iAdapterIndex  The ADL index handle of the desired adapter.
/// \param[in] pastProfileToApply The the profile to be applied.
/// \param[in] pabModeSetRequired If a mode change is occurring then set this to FALSE.
/// 
/// \return If the function succeeds, ADL_OK is returned. Otherwise ADL_ERR_NULL_POINTER is returned.
ADL_EXTERNC int EXPOSED ADL_Remap(int iAdapterIndex, DrvProfile *pastProfileToApply, int *pabModeSetRequired);

///
/// \brief Function to retrieve the closest mode to the one passed to the function.  Only a mode with the same BPP is returned.
///
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in] pcDisplayName The name of the display on which to perform the mode search.
/// \param[out] pstDevMode The pointer to the retrieved mode.  Will be used to return the mode to be set.
///
/// \return If the function succeeds, ADL_OK is returned. Otherwise ADL_ERR is returned.
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
ADL_EXTERNC int EXPOSED ADL2_ADC_FindClosestMode_Get(ADL_CONTEXT_HANDLE context,char *pcDisplayName, DEVMODE *pstDevMode);

///
/// \brief Function to retrieve the closest mode to the one passed to the function.  Only a mode with the same BPP is returned.
///
/// \param[in] pcDisplayName The name of the display on which to perform the mode search.
/// \param[out] pstDevMode The pointer to the retrieved mode.  Will be used to return the mode to be set.
///
/// \return If the function succeeds, ADL_OK is returned. Otherwise ADL_ERR is returned.
ADL_EXTERNC int EXPOSED ADL_ADC_FindClosestMode_Get(char *pcDisplayName, DEVMODE *pstDevMode);

///
/// \brief This function checks whether a pair of modes is equivalent, including BPP, to each other.
///
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in] pstDevMode1 The mode being checked.
/// \param[in] pstDevMode2 The mode to be compared with pstDevMode1.
///
/// \return If the function succeeds, TRUE is returned. Otherwise FALSE is returned.
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
ADL_EXTERNC BOOL EXPOSED ADL2_ADC_IsDevModeEqual_Get(ADL_CONTEXT_HANDLE context,DEVMODE *pstDevMode1, DEVMODE *pstDevMode2);

///
/// \brief This function checks whether a pair of modes is equivalent, including BPP, to each other.
///
/// \param[in] pstDevMode1 The mode being checked.
/// \param[in] pstDevMode2 The mode to be compared with pstDevMode1.
///
/// \return If the function succeeds, TRUE is returned. Otherwise FALSE is returned.
ADL_EXTERNC BOOL EXPOSED ADL_ADC_IsDevModeEqual_Get(DEVMODE *pstDevMode1, DEVMODE *pstDevMode2);

#endif /// AMD_PROFILE_H_
