cmake_minimum_required(VERSION 3.14)
project(TreeDFSSolutions)

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
    01_max_depth
    02_same_tree
    03_invert_tree
    04_path_sum
    05_path_sum_ii
    06_sum_root_to_leaf
    07_diameter
    08_binary_tree_max_path_sum
    09_lowest_common_ancestor
    10_validate_bst
    11_serialize_deserialize
)

foreach(solution ${SOLUTIONS})
    add_executable(${solution} ${solution}.cpp)
    target_link_libraries(${solution} GTest::gtest_main)
    add_test(NAME ${solution} COMMAND ${solution})
endforeach()
