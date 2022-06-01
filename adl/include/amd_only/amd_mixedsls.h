///  Copyright (c) 2008 - 2021 Advanced Micro Devices, Inc.

///  THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
///  EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
///  WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.

/// \file amd_adapter.h
/// \brief Contains all AMD internal adapter-related functions exposed by ADL for \ALL platforms.
///
/// This file contains all AMD internal adapter-related functions exposed by ADL for \ALL platforms.
/// All functions in this file can be used as a reference to ensure
/// the specified function pointers can be used by the appropriate runtime
/// dynamic library loaders. This header file is for AMD internal use only.

#ifndef AMD_MIXEDSLS_H_
#define AMD_MIXEDSLS_H_

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
///\brief Get the Supported SLS LS Layout image crop type
/// 
/// Get the Supported SLS LS Layout image crop type
/// \platform
/// \WIN7 and Above
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in] iAdapterIndex - Input adapter Index. This function does not support -1 as adapter index.
/// \param[in] iSLSMapIndex - SLS Map Index
/// \param[out] lpSupportedSLSLSLayoutImageCropType - SLS layout image mode. Bit vector \re ADL_DISPLAY_SLSMAP_SLSLAYOUTMODE_FIT \ref ADL_DISPLAY_SLSMAP_SLSLAYOUTMODE_FILL \ref ADL_DISPLAY_SLSMAP_SLSLAYOUTMODE_EXPAND
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
ADL_EXTERNC int EXPOSED ADL2_Display_SLSMapConfig_SupportedImageCropType_Get(ADL_CONTEXT_HANDLE context,
                                                                             int iAdapterIndex, 
                                                                             int iSLSMapIndex, 
                                                                             int *lpSupportedSLSLSLayoutImageCropType);

///
///\brief Set the SLS LS Layout image crop type
/// 
/// Set the SLS LS Layout image crop type
/// \platform
/// \WIN7 and Above
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in] iAdapterIndex - Input adapter Index. This function does not support -1 as adapter index.
/// \param[in] iSLSMapIndex - SLS Map Index
/// \param[in] iSLSLSLayoutImageCropType - SLS layout image mode. Bit vector \re ADL_DISPLAY_SLSMAP_SLSLAYOUTMODE_FIT \ref ADL_DISPLAY_SLSMAP_SLSLAYOUTMODE_FILL \ref ADL_DISPLAY_SLSMAP_SLSLAYOUTMODE_EXPAND
ADL_EXTERNC int EXPOSED ADL2_Display_SLSMapConfig_ImageCropType_Set(ADL_CONTEXT_HANDLE context,
                                                                    int iAdapterIndex, 
                                                                    int iSLSMapIndex, 
                                                                    int iSLSLSLayoutImageCropType);

///
///\brief Get whether the candidate display is selectable in the SLS builder
/// 
/// Get whether the candidate display is selectable in the SLS builder
/// \platform
/// \WIN7 and Above
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in] iAdapterIndex - Input adapter Index. This function does not support -1 as adapter index.
/// \param[in] slsGridType - The grid type
/// \param[in] iNumOfDisplaysMustBeInSLS - The number of displays must be used to create SLS
/// \param[in] lpDisplaysMustBeInSLS - The displays must be used to create SLS. The first one muse be anchor display
/// \param[in] iNumOfDisplayCandidates - The number of displays possible be used to create SLS
/// \param[in] lpDisplayCandidates - The displays possible are used to create SLS
/// \param[out] lpDisplayPropertyList - Candidate display property list , each display property (bit vector)includes supported SLS image types. Same mode, mix mode and display rotation.
/// \param[in] iOption - Bit vector, specifies the layout type of SLS grid data and portrait flag. There are two types of SLS layouts: relative to landscape (ref \ADL_DISPLAY_SLSGRID_CAP_OPTION_RELATIVETO_LANDSCAPE) and relative to current angle (ref \ADL_DISPLAY_SLSGRID_CAP_OPTION_RELATIVETO_CURRENTANGLE). If the current desktop associated with the input adapter is rotated to 90 or 270 degree, set bit ref \ADL_DISPLAY_SLSGRID_PORTAIT_MODE to 1
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
ADL_EXTERNC int EXPOSED ADL2_Display_SLSBuilder_DisplaysCanBeNextCandidateInSLS_Get(ADL_CONTEXT_HANDLE context,
                                                                                    int  iAdapterIndex,
                                                                                    ADLSLSGrid  slsGridType,
                                                                                    int  iNumOfDisplaysMustBeInSLS,
                                                                                    ADLDisplayTarget* lpDisplaysMustBeInSLS,
                                                                                    int  iNumOfDisplayCandidates,
                                                                                    ADLDisplayTarget* lpDisplayCandidates,
                                                                                    int *lpDisplayPropertyList,
                                                                                    int iOption);

///
///\brief Get whether the candidate display is selectable in the SLS builder
/// 
/// Get whether the candidate display is selectable in the SLS builder
/// \platform
/// \WIN7 and Above
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in] iAdapterIndex - Input adapter Index. This function does not support -1 as adapter index.
/// \param[in] SLSMapIndex - SLS Map Index
/// \param[in] iNumOfDisplaysCurrentEnabled - The number of displays current that are enabled in the Virtual Topology
/// \param[in] ADLDisplayTarget* lpDisplaysCurrentEnabled - The displays current that are enabled in the Virtual Topology
/// \param[in] iNumOfDisplaysMustBeEnabled - The number of displays must be enabled next in the Virtual Topology
/// \param[in] lpDisplayMustBeEabled - Whether the displays must be enabled next in the Virtual Topology
/// \param[in] iUnusedField - Unused parameter, leave at 0
/// \param[in] lpUnusedField - Unused parameter, leave at NULL
/// \param[in] iNumOfDisplaysCandidates - The number of display candidates to be checked
/// \param[in] lpDisplayTargetCandidates - The display candidateto be checked
/// \param[out] lpNativeModeSupported - Native mode supported flag for each candidate display. The array length is iNumOfDisplayTargetsCandidates
/// \param[out] lpCanBeEnableFlag - Can be enable flag for each candidate display. The array length is iNumOfDisplayTargetsCandidates
/// \param[out] lpShouldBeDisabledFlag - When one of display candidate will be enabled in the VT, which of current enabled displays should be disabled. It is an integer array The length is iNumOfDisplayTargetsCurrentEnabled * iNumOfDisplayTargetsCandidates
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
ADL_EXTERNC int EXPOSED ADL2_Display_SLSBuilder_DisplaysCanBeNextCandidateToEnabled_Get(ADL_CONTEXT_HANDLE context,
                                                                                        int iAdapterIndex,
                                                                                        int SLSMapIndex,
                                                                                        int iNumOfDisplaysCurrentEnabled,
                                                                                        ADLDisplayTarget* lpDisplaysCurrentEnabled,
                                                                                        int iNumOfDisplaysMustBeEnabled,
                                                                                        ADLDisplayTarget* lpDisplayMustBeEabled,
                                                                                        int iUnusedField,
                                                                                        ADLDisplayTarget* lpUnusedField,
                                                                                        int iNumOfDisplaysCandidates,
                                                                                        ADLDisplayTarget*lpDisplayTargetCandidates,
                                                                                        int *lpNativeModeSupported,
                                                                                        int *lpCanBeEnableFlag,
                                                                                        int *lpShouldBeDisabledFlag);

///
///\brief Create a SLS Builder
/// 
/// Create a SLS Builder
/// \platform
/// \WIN7 and Above
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in] iAdapterIndex - Input adapter Index. This function does not support -1 as adapter index.
/// \param[in] slsMap - SLS map information, refer to \ref ADLSLSMapstruct
/// \param[in] iNumDisplayTarget - the input size of SLS Target configurations array
/// \param[in] lpSLSTarget - a list of SLS Target to set, refer to \ref ADLSLSTargetstruct
/// \param[out] lpSLSMapIndex - SLS map index
/// \param[in] iOption
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
ADL_EXTERNC int EXPOSED ADL2_Display_SLSBuilder_Create(ADL_CONTEXT_HANDLE context,
                                                       int  iAdapterIndex,
                                                       ADLSLSMap  slsMap, 
                                                       int  iNumDisplayTarget,
                                                       ADLSLSTarget* lpSLSTarget, 
                                                       int* lpSLSMapIndex, 
                                                       int iOption);

///
///\brief Retrieves the SLSBuilder time out
/// 
/// Retrieves the SLSBuilder time out
/// \platform
/// \WIN7 and Above
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in] iAdapterIndex - Input adapter Index. This function does not support -1 as adapter index.
/// \param[out] lpTimeOutSeconds - The timeout period to call ADL2_Display_SLSBuilder_IsActive_Notify after creating SLS builder
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
ADL_EXTERNC int EXPOSED ADL2_Display_SLSBuilder_TimeOut_Get(ADL_CONTEXT_HANDLE context,
                                                            int iAdapterIndex, 
                                                            int *lpTimeOutSeconds);

///
///\brief Notify SLS Builder is active
///
/// SLS Builder will time out unless this is called within time out period.
/// The driver will exit the SLS Builder UI, unless a ping is received. Application crash protection is disabled when this is set to 0
/// \platform
/// \WIN7 and Above
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in] iAdapterIndex - Input adapter Index. This function does not support -1 as adapter index.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
ADL_EXTERNC int EXPOSED ADL2_Display_SLSBuilder_IsActive_Notify(ADL_CONTEXT_HANDLE context,
                                                                int  iAdapterIndex);

///
///\brief Update SLS Builder
///
/// Update SLS Builder with new SLS map and targets
/// \platform
/// \WIN7 and Above
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in] iAdapterIndex - Input adapter Index. This function does not support -1 as adapter index.
/// \param[in] iSLSMapIndex - SLS map index
/// \param[in] slsMap - SLS map information, refer to \ref ADLSLSMapstruct
/// \param[in] iNumDisplayTarget - the input size of SLS Target configurations array
/// \param[in] lpSLSTarget - a list of SLS Target to set, refer to \ref ADLSLSTargetstruct
/// \param[in] iOption - Bit vector, specifies the layout type of SLS grid data and portrait flag. There are two types of SLS layouts: relative to landscape (ref \ADL_DISPLAY_SLSGRID_CAP_OPTION_RELATIVETO_LANDSCAPE) and relative to current angle (ref \ADL_DISPLAY_SLSGRID_CAP_OPTION_RELATIVETO_CURRENTANGLE). If the current desktop associated with the input adapter is rotated to 90 or 270 degree, set bit ref \ADL_DISPLAY_SLSGRID_PORTAIT_MODE to 1
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
ADL_EXTERNC int EXPOSED ADL2_Display_SLSBuilder_Update(ADL_CONTEXT_HANDLE context, 
                                                       int  iAdapterIndex, 
                                                       int  iSLSMapIndex,
                                                       ADLSLSMap  slsMap, 
                                                       int  iNumDisplayTarget,
                                                       ADLSLSTarget* lpSLSTarget, 
                                                       int iOption);

///
///\brief Get SLS Builder
///
/// Get SLS Builder
/// \platform
/// \WIN7 and Above
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in] iAdapterIndex - Input adapter Index. This function does not support -1 as adapter index.
/// \param[out] lpSLSMapIndex - SLS map index
/// \param[out] lpSLSMap - SLS map information, refer to \ref ADLSLSMapstruct
/// \param[out] lpNumDisplayTarget - the input size of SLS Target configurations array
/// \param[out] lppSLSTarget - a list of SLS Target to set, refer to \ref ADLSLSTargetstruct
/// \param[out] lpTotalWidth - Virtual topology view size width
/// \param[out] lpTotalHeight - Virtual topoplogy view size height
/// \param[in] iOption - Bit vector, specifies the layout type of SLS grid data and portrait flag. There are two types of SLS layouts: relative to landscape (ref \ADL_DISPLAY_SLSGRID_CAP_OPTION_RELATIVETO_LANDSCAPE) and relative to current angle (ref \ADL_DISPLAY_SLSGRID_CAP_OPTION_RELATIVETO_CURRENTANGLE). If the current desktop associated with the input adapter is rotated to 90 or 270 degree, set bit ref \ADL_DISPLAY_SLSGRID_PORTAIT_MODE to 1
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
ADL_EXTERNC int EXPOSED ADL2_Display_SLSBuilder_Get(ADL_CONTEXT_HANDLE context, 
                                                    int iAdapterIndex, 
                                                    int *lpSLSMapIndex,
                                                    ADLSLSMap *lpSLSMap, 
                                                    int *lpNumDisplayTarget, 
                                                    ADLSLSTarget** lppSLSTarget,
                                                    int *lpTotalWidth,
                                                    int *lpTotalHeight,
                                                    int iOption);

///
///\brief Get SLS builder max layout size
///
/// Get SLS builder max layout size
/// \platform
/// \WIN7 and Above
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in] iAdapterIndex - Input adapter Index. This function does not support -1 as adapter index.
/// \param[in] iSLSMapIndex - SLS map index
/// \param[out] lpTotalMaxWidth - Virtual topology view size max width
/// \param[out] lpTotalMaxHeight - Virtual topoplogy view size max height
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
ADL_EXTERNC int EXPOSED ADL2_Display_SLSBuilder_MaxSLSLayoutSize_Get(ADL_CONTEXT_HANDLE context, 
                                                                     int  iAdapterIndex, 
                                                                     int  iSLSMapIndex,
                                                                     int  *lpTotalMaxWidth,
                                                                     int  *lpTotalMaxHeight);

///
///\brief Extends SLS display if it is cloned with intel display 
///
/// with the latest PX 8.0 changes, while createing SLS, SLS desktop may clone with intel display. This method applies WA in this scenarios.
/// \platform
/// \WIN7 and Above
/// \param[in] iTargetHandle - Target handle of SLS display.
ADL_EXTERNC void HIDDEN Pri_Apply_SLSWA_ExtendSLSDesktop(int  iTargetHandle);

///
///\brief Enables SLS Desktop, if it is disabled by any chance
///
/// with the latest PX 8.0 changes, new SLS desktop may disabled due to the OS limitation. This method applies WA in this scenarios.
/// \platform
/// \WIN7 and Above
/// \param[in] iAdapterIndex - Input adapter Index.
/// \param[in] iSLSDisplayLogicalIndex - Input SLS prefered display index.
ADL_EXTERNC void HIDDEN Pri_Apply_SLSWA_EnableSLSDesktop(int iAdapterIndex, int iSLSDisplayLogicalIndex);

#if defined (_WIN32) || defined(_WIN64)
///
///\brief Enables previous SLS desktops if they are disabled while creating second & thired SLS. 
///
/// with the latest PX 8.0 changes, while creating Second & third SLS, previous SLS desktops may dsiable due to the OS limitation.  This method applies WA in this scenarios.
/// \platform
/// \WIN7 and Above
/// \param[in] iAdapterIndex - Input adapter Index.
/// \param[in] iNumActivePaths - Input number of active paths before calling CWDDEDI_AddSlsBuilderLayout
/// \param[in] lpPathArrayActive - Input active paths before calling CWDDEDI_AddSlsBuilderLayout
ADL_EXTERNC void HIDDEN Pri_Apply_SLSWA_EnablePreviousSLSDesktops(int iAdapterIndex, int iNumActivePaths, DISPLAYCONFIG_PATH_INFO* lpPathArrayActive);
#endif
#endif /* AMD_MIXEDSLS_H_ */
