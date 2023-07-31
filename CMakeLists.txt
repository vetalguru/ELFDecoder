cmake_minimum_required(VERSION 3.5)

project(ELFDecoder VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(ELFDECODER_LIBRARY_DIR ${CMAKE_SOURCE_DIR}/lib)
set(TESTS_DIR ${PROJECT_SOURCE_DIR}/tests)

set(SOURCES_LIST ${CMAKE_SOURCE_DIR}/main.cpp)

include_directories(${ELFDECODER_LIBRARY_DIR}/inc)

add_executable(
    ${PROJECT_NAME}
    ${SOURCES_LIST}
)

add_subdirectory(${ELFDECODER_LIBRARY_DIR})
add_subdirectory(${TESTS_DIR})

target_link_libraries(${PROJECT_NAME} elfdecoder)

message("Copy samples to build directory...")
add_custom_command(
    TARGET ${PROJECT_NAME} PRE_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${CMAKE_SOURCE_DIR}/samples/
    ${CMAKE_CURRENT_BINARY_DIR}/samples
)
message("Done")
