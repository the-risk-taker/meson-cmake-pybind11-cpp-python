cmake_minimum_required(VERSION 3.22)
project(cmake-cpp-pybind11)

# pybind11
add_subdirectory(pybind11)

# api
if (WIN32)
add_library(api_lib api/api.h api/api.cpp)
else()
add_library(api_lib SHARED api/api.h api/api.cpp)
endif()
target_include_directories(api_lib PUBLIC api/)

pybind11_add_module(api api/api-python.cpp)
target_link_libraries(api PUBLIC api_lib)

add_executable(cpp-client main.cpp)
target_link_libraries(cpp-client PUBLIC api_lib)

# examples
pybind11_add_module(cmake_example examples/cmake/main.cpp)
