cmake_minimum_required(VERSION 3.5)
set(CMAKE_CXX_STANDARD 11)

project(Logger)

include_directories(include)
add_executable(logger main.cpp logger.cpp)

set(EXECUTABLE_OUTPUT_PATH "${CMAKE_SOURCE_DIR}")