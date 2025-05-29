set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

add_subdirectory(GLFW)

add_library(Lib INTERFACE)

target_link_libraries(Lib INTERFACE glfw)

find_package(OpenGL REQUIRED)

target_link_libraries(Lib INTERFACE OpenGL::GL)
