cmake_minimum_required(VERSION 3.0)
project(CPP_TP4)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED YES)

file(MAKE_DIRECTORY output) # Create directory for outputs

# ========== Sources ==========

set(sources
    ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
    # ${CMAKE_CURRENT_SOURCE_DIR}/src/_.cpp
)

set(testSources
    ${CMAKE_CURRENT_SOURCE_DIR}/mainTest.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/test/FichierTest.cpp
    # ${CMAKE_CURRENT_SOURCE_DIR}/test/_Test.cpp
)

# ========== Includes Directories ==========

include_directories(${CMAKE_CURRENT_SOURCE_DIR})
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src)

# ========== Projet definitions ==========

add_compile_definitions(PROJECT_PATH="${CMAKE_CURRENT_SOURCE_DIR}") # Use for code

# ========== Default Executable ==========

add_executable(CPP_TP4 ${sources})

# ========== Test Executable ==========

# Specific include for tests
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/test)

add_executable(CPP_TP4_Test ${testSources})