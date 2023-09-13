cmake_minimum_required(VERSION 3.0)

set (CMAKE_CXX_STANDARD 17)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

project(HangmanGame)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/includes)

add_executable(main main.cpp)

target_include_directories(main PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src)
target_include_directories(main PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/includes)
