cmake_minimum_required(VERSION 3.14)
project(BinarySearchSolutions)

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
    01_binary_search
    02_search_insert_position
    03_first_bad_version
    04_sqrt
    05_search_rotated_sorted_array
    06_find_first_and_last_position
    07_find_peak_element
    08_search_2d_matrix
    09_find_min_rotated_sorted_array
    10_koko_eating_bananas
    11_capacity_to_ship_packages
    12_median_of_two_sorted_arrays
    13_split_array_largest_sum
)

foreach(solution ${SOLUTIONS})
    add_executable(${solution} ${solution}.cpp)
    target_link_libraries(${solution} GTest::gtest_main)
    add_test(NAME ${solution} COMMAND ${solution})
endforeach()
