cmake_minimum_required(VERSION 3.22)

project(V0)

find_package(OpenMP)
if(OpenMP_CXX_FOUND)
    link_libraries(OpenMP::OpenMP_CXX)
endif()

add_compile_options("-O3" "-g" "-v" "-march=native" "-fopenmp")

set(source_files main.cpp
        util.h
        util.cpp
        v0.cpp
        v1.cpp)

add_executable("v0" ${source_files})
target_compile_definitions(v0 PUBLIC  ALGO_VER=step_v0)

add_executable("v1" ${source_files})
target_compile_definitions(v1 PUBLIC ALGO_VER=step_v1)
