cmake_minimum_required(VERSION 3.5)

project(elfdecoder VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(HEADERS_LIST inc/elfdecoder.h)
set(SOURCES_LIST src/elfdecoder.cpp)

add_library(
    ${PROJECT_NAME}
    SHARED
    ${SOURCES_LIST}
    ${HEADERS_LIST}
)
