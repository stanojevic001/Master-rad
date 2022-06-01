///  Copyright (c) 2008 - 2021 Advanced Micro Devices, Inc.

///  THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
///  EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
///  WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.

/// \file amd_oem.h
/// \brief Contains all AMD internal definitions that are to be moved to OEM only (non-public) later
///
/// This file contains all AMD internal definitions that are to be moved to OEM only (non-public) later.
/// All functions in this file can be used as a reference to ensure
/// the specified function pointers can be used by the appropriate runtime
/// dynamic library loaders. This header file is for AMD internal use only.

#ifndef AMD_OEM_H_
#define AMD_OEM_H_

#include "oem_structures.h"

#ifndef ADL_EXTERNC
#ifdef __cplusplus
#define ADL_EXTERNC extern "C"
#else
#define ADL_EXTERNC
#endif
#endif

/// Maximum number of MMR 
#define ADL_FEATURE_MAX_NUM_CLIENTS  16

/// CCC Client ID
#define ADL_FEATURE_CLIENT_CCC 0
/// VPP Client ID
#define ADL_FEATURE_CLIENT_VPP 1

/// Feature Type - Blob
#define ADL_FEATURE_PROPERTIES_BLOB (4 << 7)

/////////////////////////////////////////////////////////////////////////////////////////////
///\brief Structure containing information about MM Feature Values.
///
////////////////////////////////////////////////////////////////////////////////////////////
typedef struct ADLFeatureValuesX2
{
	/// The Feature Name
	ADLFeatureName	Name;
	/// User controlled Boolean current value. Valid only if ADLFeatureCaps supports Boolean.
	int bCurrent;
	/// Current integer value. Valid only if ADLFeatureCaps indicates support for integers.
	int iCurrent;
	/// Current float value. Valid only if ADLFeatureCaps indicates support for floats.
	float fCurrent;
	/// The States for the available bits for enumerated values. 
	int EnumStates;
	/// Size of blob data of the feature. Valid only if the feature is of blob type.
	/// Set to -1 otherwise.
	int iDataSize;
	/// Data of blob type feature. Valid only for features of blob type.
	unsigned char uData[1];
} ADLFeatureValuesX2, *LPADLFeatureValuesX2;

/////////////////////////////////////////////////////////////////////////////////////////////
///\brief Structure containing information about MM Feature Capabilities.
///
////////////////////////////////////////////////////////////////////////////////////////////
typedef struct ADLFeatureCapsX2
{
	/// The Feature Name
	ADLFeatureName Name;
	/// Group ID. All Features in the same group are shown sequentially in the same UI Page.
	int  iGroupID;
	/// Visual ID. Places one or more features in a Group Box. If zero, no Group Box is added.
	int  iVisualID;
	/// Page ID. All Features with the same Page ID value are shown together on the same UI page.
	int iPageID[ADL_FEATURE_MAX_NUM_CLIENTS];
	/// Feature Property Mask. Indicates which are the valid bits for iFeatureProperties.
	int iFeatureMask;
	/// Feature Property Values. See definitions for ADL_FEATURE_PROPERTIES_XXX
	int  iFeatureProperties;
	/// Apperance of the User-Controlled Boolean.
	int  iControlType[ADL_FEATURE_MAX_NUM_CLIENTS];
	/// Style of the User-Controlled Boolean.
	int  iControlStyle[ADL_FEATURE_MAX_NUM_CLIENTS];
	/// Apperance of the Adjustment Controls.
	int  iAdjustmentType[ADL_FEATURE_MAX_NUM_CLIENTS];
	/// Style of the Adjustment Controls.
	int  iAdjustmentStyle[ADL_FEATURE_MAX_NUM_CLIENTS];
	/// Default user-controlled boolean value. Valid only if ADLFeatureCaps supports user-controlled boolean.
	int bDefault;
	/// Minimum integer value. Valid only if ADLFeatureCaps indicates support for integers.
	int iMin;
	/// Maximum integer value. Valid only if ADLFeatureCaps indicates support for integers.
	int iMax;
	/// Step integer value. Valid only if ADLFeatureCaps indicates support for integers.
	int iStep;
	/// Default integer value. Valid only if ADLFeatureCaps indicates support for integers.
	int iDefault;
	/// Minimum float value. Valid only if ADLFeatureCaps indicates support for floats.
	float fMin;
	/// Maximum float value. Valid only if ADLFeatureCaps indicates support for floats.
	float fMax;
	/// Step float value. Valid only if ADLFeatureCaps indicates support for floats.
	float fStep;
	/// Default float value. Valid only if ADLFeatureCaps indicates support for floats.
	float fDefault;
	/// The Mask for available bits for enumerated values.(If ADLFeatureCaps supports ENUM values)
	int EnumMask;
	/// Data of blob type feature. Valid only for features of blob type.
	int iDataSize;
} ADLFeatureCapsX2, *LPADLFeatureCapsX2;



/// \brief Function to obtain the values and state of a Multi-Media feature
/// 
/// The function is used to obtain the values and Multi-Media features for a specific display adapter.
/// This X2 version introduces support for blob data in mm features
/// \platform
/// \VISTAWIN7
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[out]  lppFeatureValues The pointer to the pointer to the retrieved ADLFeatureValuesX2. Initialize to NULL before calling this API.
/// \param[in, out] The pointer to the number of ADLFeatureValues elements in the retrieved list. (Optional) lpFeatureCount input, the number of ADLFeatureCapsX2 structures in the buffer.
/// \param[in]  (Optional) ADLFeatureCapsX2, used to simplify calculation of the buffer size. Set to NULL if no caps is to provided.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
///
/// \remarks This API uses the memory allocation callback function provided by the user.
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
ADL_EXTERNC int EXPOSED ADL2_MMD_FeatureValuesX2_Get (ADL_CONTEXT_HANDLE context, int iAdapterIndex, ADLFeatureValuesX2 ** lppFeatureValues, int * lpFeatureCount, ADLFeatureCapsX2*  lpFeatureCaps );

/// \brief Function to obtain the values and state of a Multi-Media feature
/// 
/// The function is used to obtain the values and Multi-Media features for a specific display adapter.
/// This X2 version introduces support for blob data in mm features
/// \platform
/// \VISTAWIN7
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[out]  lppFeatureValues The pointer to the pointer to the retrieved ADLFeatureValuesX2. Initialize to NULL before calling this API.
/// \param[in, out] The pointer to the number of ADLFeatureValues elements in the retrieved list. (Optional) lpFeatureCount input, the number of ADLFeatureCapsX2 structures in the buffer.
/// \param[in]  (Optional) ADLFeatureCapsX2, used to simplify calculation of the buffer size. Set to NULL if no caps is to provided.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
///
/// \remarks This API uses the memory allocation callback function provided by the user.
ADL_EXTERNC int EXPOSED ADL_MMD_FeatureValuesX2_Get ( int iAdapterIndex, ADLFeatureValuesX2 ** lppFeatureValues, int * lpFeatureCount, ADLFeatureCapsX2*  lpFeatureCaps );


/// \brief Function to set the current value of a Multi-Media feature
/// 
/// The function is used to set the current values of Multi-Media features
/// This X2 version introduces support for blob data in mm features
/// \platform
/// \VISTAWIN7
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[in]  lpFeatureValuesX2 A pointer to the ADLFeatureValuesX2 buffer. Refer to ADLFeatureValuesX2 structure for more information.
/// \param[in]  iFeatureCount The number of ADLFeatureValues elements in the array.
/// \param[in]  ClientID The Client ID of the caller. It is recommended to provide a valid Client ID to avoid raising caller event object, immediately after the current value is set.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
///
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
ADL_EXTERNC int EXPOSED ADL2_MMD_FeatureValuesX2_Set (ADL_CONTEXT_HANDLE context, int iAdapterIndex, ADLFeatureValuesX2* lpFeatureValues, int iFeatureCount, int ClientID );

/// \brief Function to set the current value of a Multi-Media feature
/// 
/// The function is used to set the current values of Multi-Media features
/// This X2 version introduces support for blob data in mm features
/// \platform
/// \VISTAWIN7
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[in]  lpFeatureValuesX2 A pointer to the ADLFeatureValuesX2 buffer. Refer to ADLFeatureValuesX2 structure for more information.
/// \param[in]  iFeatureCount The number of ADLFeatureValues elements in the array.
/// \param[in]  ClientID The Client ID of the caller. It is recommended to provide a valid Client ID to avoid raising caller event object, immediately after the current value is set.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
///
ADL_EXTERNC int EXPOSED ADL_MMD_FeatureValuesX2_Set ( int iAdapterIndex, ADLFeatureValuesX2* lpFeatureValues, int iFeatureCount, int ClientID );

/// \brief Function to obtain capabilities of Multi-Media features
/// 
/// The function is used to obtain the capabilities for a set of specific Multi-Media features for a specific display adapter.
/// This X2 version introduces support for blob data in mm feature, as well as separate PageId/Control/Adjustment for different clients
/// \platform
/// \VISTAWIN7
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[in]  lppFeatureCaps The pointer to the pointer to the retrieved Feature Caps array. Initialize to NULL before calling this API.
/// \param[out]  lpFeatureCount The pointer to the number of ADLFeatureCaps elements in the retrieved list.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
///
/// \remarks This API uses the memory allocation callback function provided by the user.
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process . Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
ADL_EXTERNC int EXPOSED ADL2_MMD_FeaturesX2_Caps(ADL_CONTEXT_HANDLE context, int iAdapterIndex, ADLFeatureCapsX2 ** lppFeatureCaps, int * lpFeatureCount );

/// \brief Function to obtain capabilities of Multi-Media features
/// 
/// The function is used to obtain the capabilities for a set of specific Multi-Media features for a specific display adapter.
/// This X2 version introduces support for blob data in mm feature, as well as separate PageId/Control/Adjustment for different clients
/// \platform
/// \VISTAWIN7
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[in]  lppFeatureCaps The pointer to the pointer to the retrieved Feature Caps array. Initialize to NULL before calling this API.
/// \param[out]  lpFeatureCount The pointer to the number of ADLFeatureCaps elements in the retrieved list.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
///
/// \remarks This API uses the memory allocation callback function provided by the user.
ADL_EXTERNC int EXPOSED ADL_MMD_FeaturesX2_Caps( int iAdapterIndex, ADLFeatureCapsX2 ** lppFeatureCaps, int * lpFeatureCount );


// ECC/RAS ADL calls
//Function to get RAS ECC info of the asic
ADL_EXTERNC int EXPOSED ADL_Workstation_RAS_Get_Features(ADL_CONTEXT_HANDLE context, int iAdapterIndex, int *lpNumOfECCFeatures, int **lppSupport, int **lppCurrentVlaue, int **lppDefaultVlaue);

//Function to set ECC info of the asic
ADL_EXTERNC int EXPOSED ADL_Workstation_RAS_Set_Features(ADL_CONTEXT_HANDLE context, int iAdapterIndex, int iNumOfECCFeatures, int* itemValueValidList, int* lpItemValueList);

//Function to get the correctable and uncorrectable errors of the asic
ADL_EXTERNC int EXPOSED ADL_Workstation_RAS_Get_Error_Counts(ADL_CONTEXT_HANDLE context, int iAdapterIndex, ADL_RAS_GET_ERROR_COUNTS *lpADLRasErrorCountOutput);

//Function to reset error counts of the asic
ADL_EXTERNC int EXPOSED ADL_Workstation_RAS_Reset_Error_Counts(ADL_CONTEXT_HANDLE context, int iAdapterIndex);

#endif /* AMD_OEM_H_ */
