cmake_minimum_required(VERSION 3.5)

project(ELFDecoder VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(${PROJECT_NAME} main.cpp)

message("Copy samples to build directory...")
add_custom_command(
    TARGET ${PROJECT_NAME} PRE_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${CMAKE_SOURCE_DIR}/samples/
    ${CMAKE_CURRENT_BINARY_DIR}/samples
)
message("Done")
