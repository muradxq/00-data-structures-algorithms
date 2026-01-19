cmake_minimum_required(VERSION 3.14)
project(TreeBFSSolutions)

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
    01_level_order_traversal
    02_level_order_traversal_ii
    03_zigzag_level_order
    04_average_of_levels
    05_min_depth
    06_right_side_view
    07_populating_next_right_pointers
    08_cousins_in_binary_tree
)

foreach(solution ${SOLUTIONS})
    add_executable(${solution} ${solution}.cpp)
    target_link_libraries(${solution} GTest::gtest_main)
    add_test(NAME ${solution} COMMAND ${solution})
endforeach()
