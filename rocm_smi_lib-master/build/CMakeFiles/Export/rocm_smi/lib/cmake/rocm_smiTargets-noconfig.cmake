#----------------------------------------------------------------
# Generated CMake target import file.
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "rocm_smi64" for configuration ""
set_property(TARGET rocm_smi64 APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(rocm_smi64 PROPERTIES
  IMPORTED_LOCATION_NOCONFIG "${_IMPORT_PREFIX}/rocm_smi/lib/librocm_smi64.so.1.0"
  IMPORTED_SONAME_NOCONFIG "librocm_smi64.so.1"
  )

list(APPEND _IMPORT_CHECK_TARGETS rocm_smi64 )
list(APPEND _IMPORT_CHECK_FILES_FOR_rocm_smi64 "${_IMPORT_PREFIX}/rocm_smi/lib/librocm_smi64.so.1.0" )

# Import target "oam" for configuration ""
set_property(TARGET oam APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(oam PROPERTIES
  IMPORTED_LOCATION_NOCONFIG "${_IMPORT_PREFIX}/oam/lib/liboam.so.1.0"
  IMPORTED_SONAME_NOCONFIG "liboam.so.1"
  )

list(APPEND _IMPORT_CHECK_TARGETS oam )
list(APPEND _IMPORT_CHECK_FILES_FOR_oam "${_IMPORT_PREFIX}/oam/lib/liboam.so.1.0" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
