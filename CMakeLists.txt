cmake_minimum_required(VERSION 3.10)

set(CMAKE_C_COMPILER "C:\\MinGW\\bin\\gcc.exe")
set(CMAKE_CXX_COMPILER "C:\\MinGW\\bin\\g++.exe")
set(CMAKE_MAKE_PROGRAM "C:\\MinGW\\msys\\1.0\\bin\\make.exe")

project(Master-rad)

add_library(
        adl_out.dll SHARED
        C:\Windows\System32\atiadlxx.dll
        windows_amd_impl.h
        windows_amd_impl.c
        )
    