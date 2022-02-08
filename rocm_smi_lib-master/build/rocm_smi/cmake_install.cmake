# Install script for directory: /home/stefan/Desktop/Master rad Github/Master-rad/rocm_smi_lib-master/rocm_smi

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/opt/rocm")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE FILE RENAME "librocm_smi64.so" FILES "/home/stefan/Desktop/Master rad Github/Master-rad/rocm_smi_lib-master/build/rocm_smi/so-link")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE FILE RENAME "librocm_smi64.so.1" FILES "/home/stefan/Desktop/Master rad Github/Master-rad/rocm_smi_lib-master/build/rocm_smi/so-major-link")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  foreach(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/rocm_smi/lib/librocm_smi64.so.1.0"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/rocm_smi/lib/librocm_smi64.so.1"
      )
    if(EXISTS "${file}" AND
       NOT IS_SYMLINK "${file}")
      file(RPATH_CHECK
           FILE "${file}"
           RPATH "")
    endif()
  endforeach()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/rocm_smi/lib" TYPE SHARED_LIBRARY FILES
    "/home/stefan/Desktop/Master rad Github/Master-rad/rocm_smi_lib-master/build/rocm_smi/librocm_smi64.so.1.0"
    "/home/stefan/Desktop/Master rad Github/Master-rad/rocm_smi_lib-master/build/rocm_smi/librocm_smi64.so.1"
    )
  foreach(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/rocm_smi/lib/librocm_smi64.so.1.0"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/rocm_smi/lib/librocm_smi64.so.1"
      )
    if(EXISTS "${file}" AND
       NOT IS_SYMLINK "${file}")
      if(CMAKE_INSTALL_DO_STRIP)
        execute_process(COMMAND "/usr/bin/strip" "${file}")
      endif()
    endif()
  endforeach()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/rocm_smi/lib/librocm_smi64.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/rocm_smi/lib/librocm_smi64.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/rocm_smi/lib/librocm_smi64.so"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/rocm_smi/lib" TYPE SHARED_LIBRARY FILES "/home/stefan/Desktop/Master rad Github/Master-rad/rocm_smi_lib-master/build/rocm_smi/librocm_smi64.so")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/rocm_smi/lib/librocm_smi64.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/rocm_smi/lib/librocm_smi64.so")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/rocm_smi/lib/librocm_smi64.so")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/rocm_smi/include/rocm_smi" TYPE FILE FILES "/home/stefan/Desktop/Master rad Github/Master-rad/rocm_smi_lib-master/include/rocm_smi/rocm_smi.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/rocm_smi/include/rocm_smi" TYPE FILE FILES "/home/stefan/Desktop/Master rad Github/Master-rad/rocm_smi_lib-master/include/rocm_smi/rocm_smi64Config.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/rocm_smi/include/rocm_smi" TYPE FILE FILES "/home/stefan/Desktop/Master rad Github/Master-rad/rocm_smi_lib-master/include/rocm_smi/kfd_ioctl.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/rocm_smi/bindings" TYPE FILE FILES "/home/stefan/Desktop/Master rad Github/Master-rad/rocm_smi_lib-master/python_smi_tools/rsmiBindings.py")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE FILE PERMISSIONS OWNER_READ OWNER_WRITE OWNER_EXECUTE GROUP_READ GROUP_WRITE GROUP_EXECUTE WORLD_READ WORLD_EXECUTE FILES "/home/stefan/Desktop/Master rad Github/Master-rad/rocm_smi_lib-master/python_smi_tools/rocm_smi.py")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE FILE FILES "/home/stefan/Desktop/Master rad Github/Master-rad/rocm_smi_lib-master/python_smi_tools/rocm-smi")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE FILE RENAME "rsmiBindings.py" FILES "/home/stefan/Desktop/Master rad Github/Master-rad/rocm_smi_lib-master/build/rocm_smi/bindings_link")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/rocm_smi/docs/ROCm_SMI_Manual.pdf" TYPE FILE FILES "/home/stefan/Desktop/Master rad Github/Master-rad/rocm_smi_lib-master/build/rocm_smi/latex/refman.pdf")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/rocm_smi/docs" TYPE FILE FILES "/home/stefan/Desktop/Master rad Github/Master-rad/rocm_smi_lib-master/rocm_smi/../README.md")
endif()

