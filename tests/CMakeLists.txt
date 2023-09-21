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

add_executable(test_elfdecoder test_elfdecoder.cpp)
add_executable(test_utilities test_utilities.cpp)

target_link_libraries(test_elfdecoder GTest::GTest elfdecoder)
target_link_libraries(test_utilities GTest::GTest elfdecoder)

add_test(NAME test_elfdecoder COMMAND test_elfdecoder)
add_test(NAME test_utilities COMMAND test_utilities)
