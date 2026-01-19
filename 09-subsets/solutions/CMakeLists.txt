cmake_minimum_required(VERSION 3.14)
project(SubsetsSolutions)

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
    01_subsets
    02_subsets_with_dup
    03_permutations
    04_permutations_ii
    05_combinations
    06_combination_sum
    07_combination_sum_ii
    08_letter_combinations
    09_generate_parentheses
)

foreach(solution ${SOLUTIONS})
    add_executable(${solution} ${solution}.cpp)
    target_link_libraries(${solution} GTest::gtest_main)
    add_test(NAME ${solution} COMMAND ${solution})
endforeach()
