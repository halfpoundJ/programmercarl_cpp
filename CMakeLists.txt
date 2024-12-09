cmake_minimum_required(VERSION 3.26)
project(programmercarl_cpp VERSION 0.1.0 LANGUAGES C CXX) 

include(CTest)
enable_testing()

add_executable(programmercarl_cpp
        main.cpp
)

set_property(TARGET programmercarl_cpp PROPERTY CXX_STANDARD 17)
