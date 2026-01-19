cmake_minimum_required(VERSION 3.14)
project(DynamicProgrammingSolutions)

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
    01_climbing_stairs
    02_house_robber
    03_house_robber_ii
    04_min_cost_climbing_stairs
    05_coin_change
    06_coin_change_ii
    07_longest_increasing_subsequence
    08_longest_common_subsequence
    09_unique_paths
    10_unique_paths_ii
    11_minimum_path_sum
    12_word_break
    13_palindromic_substrings
    14_longest_palindromic_substring
    15_edit_distance
    16_partition_equal_subset_sum
    17_target_sum
    18_decode_ways
    19_maximal_square
    20_burst_balloons
)

foreach(solution ${SOLUTIONS})
    add_executable(${solution} ${solution}.cpp)
    target_link_libraries(${solution} GTest::gtest_main)
    add_test(NAME ${solution} COMMAND ${solution})
endforeach()
