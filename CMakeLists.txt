cmake_minimum_required(VERSION 3.10)

project(pda VERSION 1.0)

# Allow using other scripts to help us find toolchain stuff
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Find SDL2 packages (base, ttf, image)
find_package(SDL2 REQUIRED)
find_package(SDL2_ttf REQUIRED)
find_package(jsoncpp REQUIRED)
find_package(X11 REQUIRED)

include_directories(${SDL2_INCLUDE_DIRS} ${SDL2_TTF_INCLUDE_DIRS} ${X11_INCLUDE_DIR} include)

#All sources for executable
file(GLOB_RECURSE SOURCES "src/*.cpp")
add_executable(pda ${SOURCES})

# Move src/resources to our target dir
add_custom_command(TARGET pda POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_SOURCE_DIR}/src/resources $<TARGET_FILE_DIR:pda>)

# Debug mode check
if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    target_compile_definitions(pda PRIVATE PDA_DEBUG)
endif()

target_link_libraries(pda SDL2::SDL2 SDL2::SDL2_ttf ${X11_LIBRARIES} ${JSONCPP_LIBS})
