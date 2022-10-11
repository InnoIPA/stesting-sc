# Copyright (c) 2022 Innodisk crop.
# 
# This software is released under the MIT License.
# https://opensource.org/licenses/MIT

CMAKE_MINIMUM_REQUIRED(VERSION 3.10)
PROJECT(stesting C)

# options
OPTION(CROSSCOMPILE "Use cross compiler to build aarch64" OFF) #off for x86
OPTION(SHAREDLIB "Build bin with SHARED library" OFF) 

# augments
SET(MAINDOTC main.c)
SET(INCULDES ${CMAKE_SOURCE_DIR}/inc)
SET(TOOLPATH "${CMAKE_CURRENT_SOURCE_DIR}/gcc-linaro-7.5.0-2019.12-x86_64_aarch64-linux-gnu")

# setup options
IF (CROSSCOMPILE MATCHES "ON")
    IF (SHAREDLIB MATCHES "ON")
        SET(STESTINGSO ${CMAKE_SOURCE_DIR}/release/arm/lib_stesting.so)
    ELSE()
        SET(STESTINGSO ${CMAKE_SOURCE_DIR}/release/arm/lib_stesting.a)
    ENDIF()
ELSE()
    IF (SHAREDLIB MATCHES "ON")
	    SET(STESTINGSO ${CMAKE_SOURCE_DIR}/release/x86/lib_stesting.so)
    ELSE()
	    SET(STESTINGSO ${CMAKE_SOURCE_DIR}/release/x86/lib_stesting.a)
    ENDIF()
ENDIF()

# enable cc
IF (CROSSCOMPILE MATCHES "ON")
    MESSAGE("Building aarch64")
    SET(CMAKE_SYSTEM_NAME Linux)
    SET(CMAKE_C_FLAGS "-std=c99")
    SET(CMAKE_C_FLAGS "-std=gnu99")

    SET(CMAKE_FIND_ROOT_PATH ${TOOLPATH})

    MESSAGE("CMAKE_FIND_ROOT_PATH :")
    MESSAGE(${CMAKE_FIND_ROOT_PATH})
    SET(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
    SET(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
    SET(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)

    SET(CMAKE_C_COMPILER ${TOOLPATH}/bin/aarch64-linux-gnu-gcc)
    SET(CMAKE_CXX_COMPILER ${TOOLPATH}/bin/aarch64-linux-gnu-g++)
ENDIF ()

# core
ADD_EXECUTABLE(${PROJECT_NAME} ${MAINDOTC})
TARGET_INCLUDE_DIRECTORIES(${PROJECT_NAME} PUBLIC ${INCULDES})
TARGET_LINK_LIBRARIES(${PROJECT_NAME} ${STESTINGSO})
TARGET_LINK_LIBRARIES(${PROJECT_NAME} pthread)

# github ci
ENABLE_TESTING()
ADD_TEST(unittest stesting -g)
SET_TESTS_PROPERTIES (unittest PROPERTIES PASS_REGULAR_EXPRESSION "Unit Test PASS")
