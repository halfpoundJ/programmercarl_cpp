cmake_minimum_required(VERSION 3.16)
project(programmercarl_cpp VERSION 0.1.0 LANGUAGES CXX)

# Single-config generators (Makefiles, Ninja) have no build type by default.
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug CACHE STRING "Build type")
endif()

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include(CTest)

add_executable(programmercarl_cpp
        main.cpp
)

target_compile_features(programmercarl_cpp PRIVATE cxx_std_17)
set_target_properties(programmercarl_cpp PROPERTIES CXX_EXTENSIONS OFF)

# Some headers have UTF-8 Chinese comments; without /utf-8 MSVC reads them
# with the system codepage and warns or mangles them.
if(MSVC)
    target_compile_options(programmercarl_cpp PRIVATE /utf-8)
endif()
