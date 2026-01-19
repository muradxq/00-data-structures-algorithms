cmake_minimum_required(VERSION 3.14)
project(SlidingWindowSolutions)

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
    01_max_average_subarray
    02_minimum_recolors
    03_longest_substring_without_repeating
    04_longest_repeating_char_replacement
    05_permutation_in_string
    06_find_all_anagrams
    07_max_consecutive_ones_iii
    08_fruit_into_baskets
    09_subarray_product_less_than_k
    10_minimum_size_subarray_sum
    11_minimum_window_substring
    12_sliding_window_maximum
    13_substring_concatenation
)

foreach(solution ${SOLUTIONS})
    add_executable(${solution} ${solution}.cpp)
    target_link_libraries(${solution} GTest::gtest_main)
    add_test(NAME ${solution} COMMAND ${solution})
endforeach()
