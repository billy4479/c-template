cmake_minimum_required(VERSION 3.18)

project(
  c-template # Change this
  VERSION 0.0.1
  LANGUAGES C CXX)

set(CMAKE_C_STANDARD 11)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)
include(Cache)
include(Sanitizers)
include(Warnings)

file(GLOB_RECURSE ${PROJECT_NAME}_SRC include/*.h src/*.c src/*.h)

add_executable(${PROJECT_NAME} ${${PROJECT_NAME}_SRC})
target_include_directories(${PROJECT_NAME} PRIVATE include)
target_precompile_headers(${PROJECT_NAME} PRIVATE "include/Precompiled.h")

enable_sanitizers(${PROJECT_NAME})
set_project_warnings(${PROJECT_NAME})
