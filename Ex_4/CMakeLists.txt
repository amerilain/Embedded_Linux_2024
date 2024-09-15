# Set the minimum CMake version required
cmake_minimum_required(VERSION 3.10)

# Set the project name and version
project(RandomGenerator VERSION 1.0 DESCRIPTION "Random number generator" LANGUAGES C)

# Set the C standard to C17
set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED True)

# Add compiler flags from previous exercises
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -Wfatal-errors -Wpedantic")

# Build Type Control (Debug/Release)
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release CACHE STRING "Choose the type of build: Debug or Release" FORCE)
endif()

# Add specific flags for Debug and Release builds
set(CMAKE_C_FLAGS_DEBUG "-g -O0")      # Debug build: Include debugging symbols, no optimization
set(CMAKE_C_FLAGS_RELEASE "-O3")       # Release build: Full optimization

# Organize Build Output Directories
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)  # Executables
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)  # Static Libraries
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)  # Shared Libraries

# Preprocessor Definitions
add_definitions(-DMY_VERSION="\"1.0\"")

# Include the header file directory
include_directories(include)

# Add the executable target with source files
add_executable(random_generator src/main.c src/random.c)
