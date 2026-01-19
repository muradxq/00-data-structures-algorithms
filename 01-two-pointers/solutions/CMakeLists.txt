cmake_minimum_required(VERSION 3.14)
project(TwoPointersSolutions)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Fetch GoogleTest
include(FetchContent)
FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG v1.14.0
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

# List of all solution files
set(SOLUTIONS
    01_two_sum_ii
    02_valid_palindrome
    03_remove_duplicates
    04_move_zeroes
    05_squares_sorted_array
    06_three_sum
    07_three_sum_closest
    08_container_with_most_water
    09_sort_colors
    10_four_sum
    11_remove_nth_node
    12_trapping_rain_water
)

# Create executable for each solution
foreach(solution ${SOLUTIONS})
    add_executable(${solution} ${solution}.cpp)
    target_link_libraries(${solution} GTest::gtest_main)
    add_test(NAME ${solution} COMMAND ${solution})
endforeach()

# Add a target to run all tests
add_custom_target(run_all
    COMMAND ${CMAKE_CTEST_COMMAND} --output-on-failure
    DEPENDS ${SOLUTIONS}
    COMMENT "Running all tests..."
)
