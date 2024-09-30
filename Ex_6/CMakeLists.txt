cmake_minimum_required(VERSION 3.12)

# Include build functions from Pico SDK
include($ENV{PICO_SDK_PATH}/external/pico_sdk_import.cmake)

# Set project name and C/C++ standards
project(Blinky C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

# Initialize the Pico SDK
pico_sdk_init()

# Automatically detect all .c source files in the src directory
file(GLOB PROJECT_SOURCES ${CMAKE_SOURCE_DIR}/src/*.c)

# Add the executable using the detected source files
add_executable(${PROJECT_NAME} ${PROJECT_SOURCES})

# Link the executable with Pico standard libraries
target_link_libraries(${PROJECT_NAME} pico_stdlib)

# Enable USB output and disable UART output
pico_enable_stdio_usb(${PROJECT_NAME} 0)
pico_enable_stdio_uart(${PROJECT_NAME} 1)

# Create map, bin, hex, and uf2 files
pico_add_extra_outputs(${PROJECT_NAME})
