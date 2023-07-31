enable_testing()

include(FetchContent)

FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG release-1.12.1
)

FetchContent_MakeAvailable(googletest)

add_library(GTest::GTest INTERFACE IMPORTED)
target_link_libraries(GTest::GTest INTERFACE gtest_main)

add_executable(simple_unittest simple_unittest.cpp)

target_link_libraries(simple_unittest
    GTest::GTest
)

add_test(
    NAME simple_unittest
    COMMAND simple_unittest
)

