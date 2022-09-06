cmake_minimum_required(VERSION 3.7)
project(engine)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES src/engine.cpp glad/src/glad.c src/log.cpp src/shader.cpp src/window.cpp src/object.cpp)
set(HEADER_FILES src/log.hpp src/shader.hpp src/window.hpp src/object.hpp)

set(dir ${CMAKE_CURRENT_SOURCE_DIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${dir}/build)

include_directories(include)

#Include library files
include_directories(glad/include)

file(COPY src/shaders DESTINATION ${dir}/build)

add_executable(engine ${SOURCE_FILES})
target_link_libraries(engine -lglut -lglfw -lGLEW -lGL -lGLU)