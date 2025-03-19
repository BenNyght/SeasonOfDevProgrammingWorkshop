
cmake_minimum_required(VERSION 3.8)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(RayLibWorkshop)

# RayLib --
# Documentation: https://www.raylib.com/index.html
# License: https://www.raylib.com/license.html
set(RAYLIB_DIR ${CMAKE_SOURCE_DIR}/thirdParty/rayLib)
include_directories(${RAYLIB_DIR}/include)
add_library(raylib STATIC IMPORTED)
if (WIN32)
    set_target_properties(raylib PROPERTIES
        IMPORTED_LOCATION ${RAYLIB_DIR}/lib/raylib.lib
        INTERFACE_INCLUDE_DIRECTORIES ${RAYLIB_DIR}/include
    )
elseif(APPLE)
    set_target_properties(raylib PROPERTIES
        IMPORTED_LOCATION ${RAYLIB_DIR}/lib/libraylib.a
        INTERFACE_INCLUDE_DIRECTORIES ${RAYLIB_DIR}/include
    )
endif()

# Workshop Executable --
file(GLOB_RECURSE SOURCES
    "${CMAKE_SOURCE_DIR}/src/*.cpp"
    "${CMAKE_SOURCE_DIR}/src/*.h"
)
add_executable(RayLibWorkshop ${SOURCES})
target_link_libraries(RayLibWorkshop PRIVATE raylib)

# Raylib dependencies per platform
if (WIN32)
    target_link_libraries(RayLibWorkshop PRIVATE opengl32 gdi32 winmm)
elseif(APPLE)
    target_link_libraries(RayLibWorkshop PRIVATE 
        "-framework OpenGL"
        "-framework Cocoa"
        "-framework IOKit"
        "-framework CoreVideo"
    )
endif()
