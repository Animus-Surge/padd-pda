cmake_minimum_required(VERSION 3.10)

# Set the project name and version
project(soareds VERSION 1.0)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake")

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)


# Find the SDL2 package
find_package(SDL2 REQUIRED)

# Include directories
include_directories(${SDL2_INCLUDE_DIRS} include)

# Add the executable
add_executable(soareds src/main.cpp)

# Link the SDL2 library to the executable
target_link_libraries(soareds SDL2::SDL2)

add_compile_definitions(__SOAREDS_DEBUG_MODE)