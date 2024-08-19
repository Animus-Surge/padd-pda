cmake_minimum_required(VERSION 3.10)

project(pda VERSION 1.0)

# Allow using other scripts to help us find toolchain stuff
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Find SDL2 packages (base, ttf, image)
find_package(SDL2 REQUIRED)
find_package(SDL2_ttf REQUIRED)

include_directories(${SDL2_INCLUDE_DIRS} ${SDL2_TTF_INCLUDE_DIRS} include)

file(GLOB_RECURSE SOURCES "src/*.cpp")

add_executable(pda ${SOURCES})

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    target_compile_definitions(pda PRIVATE PDA_DEBUG)
endif()

target_link_libraries(pda SDL2::SDL2 SDL2::SDL2_ttf)