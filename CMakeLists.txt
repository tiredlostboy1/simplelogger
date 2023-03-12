cmake_minimum_required(VERSION 3.5)
set(CMAKE_CXX_STANDARD 11)

project(Logger)

find_program(CMAKE_CXX_CLANG_TIDY_EXECUTABLE NAMES clang-tidy)
if (NOT CMAKE_CXX_CLANG_TIDY_EXECUTABLE)
  message("clang-tidy not found")
else()
  message("clang-tidy found")
  set(CMAKE_CXX_CLANG_TIDY ${CMAKE_CXX_CLANG_TIDY_EXECUTABLE})
endif()

include_directories(include)
add_executable(logger src/main.cpp src/logger.cpp)

set(EXECUTABLE_OUTPUT_PATH "${CMAKE_SOURCE_DIR}")
