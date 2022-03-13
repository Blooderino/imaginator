# CMake minimum version required
cmake_minimum_required(VERSION 3.13.0)

# Project info
set(PROJECT_NAME Imaginator)
project(${PROJECT_NAME} VERSION 0.1.0)

# Target names
set(BUILD_TARGET ${PROJECT_NAME})

# Build game
add_executable(${BUILD_TARGET} ${SOURCES})

# Sources directories
file(GLOB_RECURSE SOURCES_FILES "sources/*.cpp")
target_sources(${BUILD_TARGET} PUBLIC ${SOURCES_FILES})

# Include directories
target_include_directories(${BUILD_TARGET} PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>/include)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)