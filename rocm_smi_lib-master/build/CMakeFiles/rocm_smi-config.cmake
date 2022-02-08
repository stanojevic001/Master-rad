# - Config file for the rocm_smi package
# It defines the following variables
#  ROCM_SMI_INCLUDE_DIRS - include directories for rocm_smi
#  ROCM_SMI_LIBRARIES    - libraries to link against

# Compute paths
get_filename_component(ROCM_SMI_CMAKE_DIR "${CMAKE_CURRENT_LIST_FILE}" PATH)
set(ROCM_SMI_INCLUDE_DIR "/opt/rocm/rocm_smi/include")
set(ROCM_SMI_LIB_DIR "/opt/rocm/rocm_smi/lib")

# Our library dependencies (contains definitions for IMPORTED targets)
if(NOT TARGET rocm_smi AND NOT rocm_smi_BINARY_DIR)
    include("${ROCM_SMI_CMAKE_DIR}/rocm_smiTargets.cmake")
endif()

# These are IMPORTED targets created by RocmSmiTargets.cmake
set(ROCM_SMI_LIBRARIES "librocm_smi64.so")

