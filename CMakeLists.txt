cmake_minimum_required(VERSION 3.29)

project(KTAudioDEV VERSION 1.0.0 LANGUAGES CXX)     # can remove version, defined in KTaudio.h

set(CMAKE_CXX_STANDARD          20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS       OFF)

set(TOOLCHAIN_NAME "${TOOLCHAIN_NAME}")
message(STATUS "Using toolchain: ${TOOLCHAIN_NAME}")

set(KT_LIB KT_Effect)         # Set audio effect static lib name
set(KT_EXE KT_Effect_test)    # Set audio effect test executable name

set(SOFTCLIP_LIB softclip_lib)    # Set audio module static lib name
set(MODULE_TESTS module_tests)

option(DELIVERY "option to add library to delivery folder" OFF)

add_subdirectory(audioDSP/src)
add_subdirectory(audioDSP/inc)
add_subdirectory(app/src)
add_subdirectory(app/inc)