cmake_minimum_required(VERSION 3.15)

project(Tester)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)



add_subdirectory(TesterLib)

add_executable(Tester tester.cpp)

target_link_libraries(Tester PUBLIC TesterLib)

target_include_directories(Tester PUBLIC "${PROJECT_BINARY_DIR}")
target_include_directories(Tester PUBLIC "${PROJECT_BINARY_DIR}" 
                                        "${PROJECT_SOURCE_DIR}/TesterLib")