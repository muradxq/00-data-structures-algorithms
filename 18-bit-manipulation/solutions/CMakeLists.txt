cmake_minimum_required(VERSION 3.14)
project(BitManipulationSolutions)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG v1.14.0
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

set(SOLUTIONS
    01_single_number
    02_number_of_1_bits
    03_counting_bits
    04_reverse_bits
    05_missing_number
    06_sum_of_two_integers
    07_single_number_ii
    08_single_number_iii
)

foreach(solution ${SOLUTIONS})
    add_executable(${solution} ${solution}.cpp)
    target_link_libraries(${solution} GTest::gtest_main)
    add_test(NAME ${solution} COMMAND ${solution})
endforeach()
