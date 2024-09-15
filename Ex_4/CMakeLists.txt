# Set the minimum CMake version 
cmake_minimum_required(VERSION 3.10)

# Set the project name and version
project(RandomGenerator VERSION 1.0 DESCRIPTION "Random number generator" LANGUAGES C)

# Set the C standard to C17 
set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED True)

# Default build type
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release CACHE STRING "Choose the type of build: Debug or Release" FORCE)
endif()

# Add build types and their respective flags
set(CMAKE_C_FLAGS_DEBUG "-g -O0")
set(CMAKE_C_FLAGS_RELEASE "-O3")

# Add custom option for logging
option(ENABLE_LOGGING "Enable logging in the program" ON)

if(ENABLE_LOGGING)
    add_definitions(-DENABLE_LOGGING)
endif()

# Set output directories
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

# Include the header file directory
include_directories(include)

# Add preprocessor definitions
add_definitions(-DMY_VERSION="\"1.0\"")

# Add the executable target
add_executable(random_generator src/main.c src/random.c)
