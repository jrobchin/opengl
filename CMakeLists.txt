cmake_minimum_required(VERSION 3.16 FATAL_ERROR)

project(learnopengl)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

#GLFW additions
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

set(SOURCE_FILES 
    src/main.cpp
    src/utils.cpp
    src/exercises/exercise.cpp
    src/exercises/triangle.cpp
    src/exercises/square.cpp
)

find_package(OpenGL REQUIRED)

add_executable(learnopengl ${SOURCE_FILES})
target_compile_options(learnopengl PRIVATE -Wall -Wextra -Wpedantic)

target_include_directories(learnopengl PRIVATE include)

add_subdirectory(libs/glad)
target_link_libraries(learnopengl glad)

add_subdirectory(libs/glfw)
target_link_libraries(learnopengl glfw ${GLFW_LIBRARIES})

target_link_libraries(learnopengl OpenGL::GL)

# Copy Shaders
file(COPY src/shaders DESTINATION .)
