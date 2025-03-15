cmake_minimum_required(VERSION 3.28.3)

project(
    zgl
    VERSION 1.0
    DESCRIPTION "A wrapper around OpenGL/GLFW."
    LANGUAGES C CXX
)

# recursively find source files
file(GLOB_RECURSE SOURCES "src/*.cpp")

add_library(
    zgl
    ${SOURCES}
    lib/glad/src/glad.c
)

target_include_directories(
    zgl PUBLIC include
)

set_target_properties(
    zgl
    PROPERTIES
    CMAKE_CXX_STANDARD 17
)

target_include_directories(
    zgl PUBLIC lib/glfw/include
)
add_subdirectory(lib/glfw)
target_link_libraries(zgl glfw)

target_include_directories(
    zgl PUBLIC lib/glad/include
)

add_subdirectory(lib/glm)
target_include_directories(
    zgl PUBLIC lib/glm
)

target_include_directories(
    zgl PRIVATE lib/stb
)