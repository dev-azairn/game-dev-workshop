cmake_minimum_required(VERSION 3.16)

project(SortVisualization)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/$<CONFIGURATION>")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/$<CONFIGURATION>")


add_subdirectory(lib)

add_executable(SortVisualization main.cpp)

target_link_libraries(SortVisualization PRIVATE Lib)