#pragma once
///
///  Copyright (c) 2018 - 2021 Advanced Micro Devices, Inc.

///  THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
///  EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
///  WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.

/// \file overdrive8.h
/// \brief Contains all OverdriveN-related functions exposed by ADL for \ALL platforms.
///
/// This file contains all OverdriveN-related functions exposed by ADL for \ALL platforms.
/// All functions found in this file can be used as a reference to ensure
/// the specified function pointers can be used by the appropriate runtime
/// dynamic library loaders.

#ifndef OVERDRIVE8_H_
#define OVERDRIVE8_H_

#include "..\adl_structures.h"

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
///\ingroup WATTMANAPI
///\defgroup OVERDRIVE8API Wattman (OD 8) related APIs
/// This group describes the Wattman APIs.

/// \addtogroup OVERDRIVE8API
/// @{
///
///
/// \brief Function to retrieve the Overdrive8 initial settings.
/// 
/// This function retrieves the Overdrive8 initial settings for a specified adapter.
/// \platform
/// \WIN
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[out] lpInitSetting The pointer to the \ref initial settings structure storing the retrieved Overdrive8 parameters. 
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results 
/// \deprecated This API has been deprecated.
ADL_EXTERNC int EXPOSED ADL2_Overdrive8_Init_Setting_Get(ADL_CONTEXT_HANDLE context, int iAdapterIndex, ADLOD8InitSetting *lpInitSetting);

///
///
/// \brief Function to retrieve the Overdrive8 current settings.
/// 
/// This function retrieves the Overdrive8 current settings for a specified adapter.
/// \platform
/// \WIN
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[out] lpCurrentSetting The pointer to the \ref current settings structure storing the retrieved Overdrive parameters. 
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results 
ADL_EXTERNC int EXPOSED ADL2_Overdrive8_Current_Setting_Get(ADL_CONTEXT_HANDLE context, int iAdapterIndex, ADLOD8CurrentSetting *lpCurrentSetting);

///
///
/// \brief Function to set the Overdrive8 settings.
/// 
/// This function set the Overdrive8 settings for a specified adapter.
/// \platform
/// \WIN
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[in] lpSetSetting The pointer to the \ref current settings structure set by user 
/// \param[out] lpCurrentSetting The pointer to the \ref current settings structure storing the retrieved Overdrive parameters.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results 
ADL_EXTERNC int EXPOSED ADL2_Overdrive8_Setting_Set(ADL_CONTEXT_HANDLE context, int iAdapterIndex, ADLOD8SetSetting *lpSetSetting, ADLOD8CurrentSetting *lpCurrentSetting);


///
///
/// \brief Function to retrieve the Overdrive8 current settings.
/// 
/// This function retrieves the Overdrive8 current settings for a specified adapter.
/// \platform
/// \WIN
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[out] lpDataOutput The pointer to the \ref ADLPMLogDataOutput structure storing the retrieved performance metrics parameters. 
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results 
/// \deprecated This API has been deprecated.
ADL_EXTERNC int EXPOSED ADL2_New_QueryPMLogData_Get(ADL_CONTEXT_HANDLE context, int iAdapterIndex, ADLPMLogDataOutput* lpDataOutput);

///
///
/// \brief Function to retrieve the Overdrive8 current range settings. This is new version of ADL2_Overdrive8_Init_Setting_Get. It supports new features and does not need to change the API
/// 
/// This function retrieves the Overdrive8 current range settings for a specified adapter.
/// \platform
/// \WIN
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[out] lpOverdrive8Capabilities  the pointer to the bit-vector which indicates which OD8 feature is supported. 
/// \param[in/out] lpNumberOfFeatures  the pointer to an integer which indicates the number of OD8 features. The callee should input the expected number of features. Then ADL can use this input to support compatiable.
///                When returning, the number is actual number of currently supported features by the driver 
/// \param[out] lppInitSettingList  the pointer to the list of current OD8 range of settings. 
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results 
ADL_EXTERNC int EXPOSED ADL2_Overdrive8_Init_SettingX2_Get(ADL_CONTEXT_HANDLE context, int iAdapterIndex, int* lpOverdrive8Capabilities, int *lpNumberOfFeatures, ADLOD8SingleInitSetting** lppInitSettingList);

///
///
/// \brief Function to retrieve the Overdrive8 current settings. This is new version of ADL2_Overdrive8_Current_SettingX2_Get. It supports new features and does not need to change the API
/// 
/// This function retrieves the Overdrive8 current settings for a specified adapter.
/// \platform
/// \WIN
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in]  iAdapterIndex the ADL index handle of the desired adapter.
/// \param[in/out] lpNumberOfFeaturet  the pointer to an integer which indicates the number of OD8 features. The callee should input the expected number of features. Then ADL can use this input to support compatible.
///                When returning, the number is actual number of currently supported features by the driver
/// \param[out] lpInitSettingList  the pointer to the list of current OD8 settings. 
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results 
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process. Such clients have to call \ref ADL2_Main_Control_Create first to obtain \ref ADL_CONTEXT_HANDLE instance that has to be passed to each subsequent ADL2 call and finally destroyed using \ref ADL2_Main_Control_Destroy.
ADL_EXTERNC int EXPOSED ADL2_Overdrive8_Current_SettingX2_Get(ADL_CONTEXT_HANDLE context, int iAdapterIndex, int *lpNumberOfFeatures, int** lppCurrentSettingList);

///
///
/// \brief Function to retrieve the current auto tuning state
/// 
/// This function retrieves the Overdrive8 auto tuning settings for a specified adapter.
/// \platform
/// \WIN
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[out] lpDataOutput The pointer to an bool which indicates the auto tuning state
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results 
ADL_EXTERNC int EXPOSED ADL2_AutoTuningResult_Get(ADL_CONTEXT_HANDLE context, int iAdapterIndex, bool* lpDataOutput);

///
///
/// \brief Function to retrieve the PMLog sensor range value if the driver supports the sensor
/// 
/// This function retrieves the supported sensors’ range value
/// \platform
/// \WIN
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[out] lpNumberOfSupportedSensorRange  The pointer to the number of sensors' rang supported. The sensor types defined \ref ADLSensorType
/// \param[out] lppSenorRangeCapsList   The pointer to the pointer to the first range supported  sensor address. This pointer does not need to be initialized by the user.
///              However, the client needs to free the pointer after.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results 
ADL_EXTERNC int EXPOSED ADL2_Overdrive8_PMLogSenorRange_Caps(ADL_CONTEXT_HANDLE context, int iAdapterIndex, int *lpNumberOfSupportedSensorRange, ADLOD8SingleInitSetting** lppSenorRangeCapsList);

///
///
/// \brief Function to retrieve the PMLog sensor real value reading support flag from the driver
/// 
/// This function retrieves the supported sensor list, which value can be reading from the driver
/// \platform
/// \WIN
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[out] lpNumOfSupportedSensorType The pointer to the number of sensors' rang supported. The sensor types defined \ref ADLSensorType
/// \param[out] lppSenroTypesList  The pointer to the pointer to the first value-reading supported  sensor address. This pointer does not need to be initialized by the user.
///              However, the client needs to free the pointer after.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results 
ADL_EXTERNC int EXPOSED ADL2_Overdrive8_PMLogSenorType_Support_Get(ADL_CONTEXT_HANDLE context, int iAdapterIndex, int *lpNumOfSupportedSensorType, int** lppSenroTypesList);

///
///
/// \brief Function to retrieve the support flag, which indicates if the shared memory way is available or not
/// 
/// This function retrieves the supporting flag of shared memory way is supported by the driver to read sensor's real value
/// \platform
/// \WIN
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[out]  lpSupported The pointer to an int variable which indicates if shared memory reading feature is supported ( \ref ADL_TRUE : supported, \ref ADL_FALSE : not supported)
/// \param[in]  iOption Integer for extension.
/// \return If the function succeeds, the return value is \ref ADL_OK (zero). Otherwise the return value is an ADL error code (non-zero). \ref define_adl_results. If Overdrive feature is not supported, the return code is \ref ADL_ERR_NOT_SUPPORTED 
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results 
ADL_EXTERNC int EXPOSED ADL2_Overdrive8_PMLog_ShareMemory_Support(ADL_CONTEXT_HANDLE context, int iAdapterIndex, int * lpSupported, int option);

///
///
/// \brief Function to start a shared memory session
/// 
/// This function Let the driver start to create a shared memory to store the sensors real values
/// \platform
/// \WIN
/// \param[in]  context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[in]  iSampleRate An integer which indicates how many milli-seconds the driver needs to refresh the context of the shared memory. The unite is second.
/// \param[in]  iNumofPMLogSendorList An integer which indicates how many sensors need to be read.
/// \param[in]  lpPMLogSendorList  A pointer to an integer, which include of sensors need to be monitored.
/// \param[in]  lpDevice  A pointer to ADL_D3DKMT_HANDLE, which is 3D device  handle
/// \param[out] lppSharedMemory  A pointer to a pointer , which contains the address of shared memory
/// \param[in]  iOption Integer for extension.
/// \return If the function succeeds, the return value is \ref ADL_OK (zero). Otherwise the return value is an ADL error code (non-zero). \ref define_adl_results. If Overdrive feature is not supported, the returned code is \ref ADL_ERR_NOT_SUPPORTED 
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results 
ADL_EXTERNC int EXPOSED ADL2_Overdrive8_PMLog_ShareMemory_Start(ADL_CONTEXT_HANDLE context, int iAdapterIndex, int iSampleRate, int iNumofPMLogSendorList, int* lpPMLogSendorList, ADL_D3DKMT_HANDLE* lpHDevice, void** lppSharedMemory, int iOption);


///
///
/// \brief Function to start a shared memory session
/// 
/// This function Let the driver start to create a shared memory to store the sensors real values
/// \platform
/// \WIN
/// \param[in]  context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[IN]  iNumSensor,  An integer, which indicates how many sensor will be read
/// \param[IN]  lpSensorList A pointer to an integer , which contains a list of sensor's IDs
/// \param[IN] lppSharedMemory  A pointer to a pointer , which contains the address of shared memory
/// \param[out] ADLPMLogDataOutput  A pointer to data structure ADLPMLogDataOutput, which is the sensor real value in it.
/// \param[in]  iOption Integer for extension.
/// \return If the function succeeds, the return value is \ref ADL_OK (zero). Otherwise the return value is an ADL error code (non-zero). \ref define_adl_results. If Overdrive feature is not supported, the returned code is \ref ADL_ERR_NOT_SUPPORTED 
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results 
ADL_EXTERNC int EXPOSED ADL2_Overdrive8_PMLog_ShareMemory_Read(ADL_CONTEXT_HANDLE context, int iAdapterIndex, int iNumSensor, int *lpSensorList, void** lppSharedMemory, ADLPMLogDataOutput* lpDataOutput);

///
///
/// \brief Function to stop a shared memory session
/// 
/// This function let the driver stop to update shared memory with the sensors real values
/// \platform
/// \WIN
/// \param[in]  context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[in]  lpDevice  A pointer to pointer, which contains the address of shared memory
/// \return If the function succeeds, the return value is \ref ADL_OK (zero). Otherwise the return value is an ADL error code (non-zero). \ref define_adl_results. If Overdrive feature is not supported, the returned code is \ref ADL_ERR_NOT_SUPPORTED 
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results 
ADL_EXTERNC int EXPOSED ADL2_Overdrive8_PMLog_ShareMemory_Stop(ADL_CONTEXT_HANDLE context, int iAdapterIndex, ADL_D3DKMT_HANDLE *lpHDevice);


///
///\brief This function create the device. Adds MGPU support over legacy functions
/// 
/// \platform
/// \ALL
/// \param[in]   context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in]   iAdapterIndex The ADL index handle of the desired desktop.
/// \param[out]  pDevice The pointer to the device handle.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
ADL_EXTERNC int EXPOSED ADL2_Device_PMLog_Device_Create(ADL_CONTEXT_HANDLE context, int iAdapterIndex, ADL_D3DKMT_HANDLE *pDevice);

///
///\brief This function destroy the device. Adds MGPU support over legacy functions
/// 
/// \platform
/// \ALL
/// \param[in]  context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in]  hDevice The device handle.
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results
ADL_EXTERNC int EXPOSED ADL2_Device_PMLog_Device_Destroy(ADL_CONTEXT_HANDLE context, ADL_D3DKMT_HANDLE hDevice);

///
///
/// \brief Function to retrieve the Overdrive8 current settings. This is new version of ADL2_Overdrive8_Current_SettingX3_Get. It supports the availability of each item
/// 
/// This function retrieves the Overdrive8 current settings plus the availability. The availability of each item can be dynamically changed when something happens 
/// \platform
/// \WIN
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[out] lpFeatureNotAdjustableBits The pointer to an integer which's bit indicates the feature can be adjustment now. ref\ADLOD8FeatureControl
/// \param[in/out] lpNumberOfSettings The pointer to an integer which indicates the number of OD8 features. The callee should input the expected number of settings. Then ADL can use this input to support compatible.
///                When returning, the number is actual number of currently supported features by the driver
/// \param[out] lpInitSettingList The pointer to the list of current OD8 settings. 
/// \return If the function succeeds, the return value is \ref ADL_OK. Otherwise the return value is an ADL error code. \ref define_adl_results 
/// \remarks Clients can use ADL2 version of the API to assure that there is no interference with other ADL clients that are running in the same process. Such cli
ADL_EXTERNC int EXPOSED ADL2_Overdrive8_Current_SettingX3_Get(ADL_CONTEXT_HANDLE context, int iAdapterIndex, int* lpFeatureNotAdjustableBits, int *lpNumberOfSettings, int** lppCurrentSettingList, int iOption);

/// \brief Function to retrieve power management logging support
/// 
/// This function implements a call to retrieve power management logging support.
/// \platform
/// \VISTAWIN7
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[out] pPMLogSupportInfo The pointer to PMLog support info.  
/// \return If the function succeeds, the return value is \ref ADL_OK, or an ADL error code otherwise. \ref define_adl_results
ADL_EXTERNC int EXPOSED ADL2_Adapter_PMLog_Support_Get(ADL_CONTEXT_HANDLE context, int iAdapterIndex, ADLPMLogSupportInfo* pPMLogSupportInfo);

/// \brief Function to start power management logging.
/// 
/// This function implements a call to start power management logging.
/// \platform
/// \VISTAWIN7
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[in]  pPMLogStartInput The pointer to ADLPMLogStartInput describing which sensors to log
/// \param[out] ADLPMLogStartOutput The pointer to ADLPMLogStartOutput, returning an address where log data is stored
/// \param[in]  hDevice The D3D device handle associate with the logging session.
/// \return If the function succeeds, the return value is \ref ADL_OK, or an ADL error code otherwise. \ref define_adl_results
ADL_EXTERNC int EXPOSED ADL2_Adapter_PMLog_Start(ADL_CONTEXT_HANDLE context, int iAdapterIndex, ADLPMLogStartInput* pPMLogStartInput, ADLPMLogStartOutput* pPMLogStartOutput, ADL_D3DKMT_HANDLE hDevice);

/// \brief Function to stop power management logging.
/// 
/// This function implements a call to stop power management logging.
/// \platform
/// \VISTAWIN7
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[in]  hDevice The D3D device handle associate with the logging session.
/// \return If the function succeeds, the return value is \ref ADL_OK, or an ADL error code otherwise. \ref define_adl_results
ADL_EXTERNC int EXPOSED ADL2_Adapter_PMLog_Stop(ADL_CONTEXT_HANDLE context, int iAdapterIndex, ADL_D3DKMT_HANDLE hDevice);


/// \brief Function to query individual limits of power management logging
/// 
/// This function implements a call to query power management logging limits.
/// \platform
/// \VISTAWIN7
/// \param[in] context: Client's ADL context handle \ref ADL_CONTEXT_HANDLE obtained from \ref ADL2_Main_Control_Create.
/// \param[in]  iAdapterIndex The ADL index handle of the desired adapter.
/// \param[out] lpDataOutput The pointer to PMLog sensor limits ADLPMLogSensorLimits.  
/// \return If the function succeeds, the return value is \ref ADL_OK, or an ADL error code otherwise. \ref define_adl_results
ADL_EXTERNC int EXPOSED ADL2_Adapter_PMLog_SensorLimits_Get(ADL_CONTEXT_HANDLE context, int iAdapterIndex, ADLPMLogSensorLimits* lpDataOutput);

/// @}

#endif /* OVERDRIVE8_H_ */
