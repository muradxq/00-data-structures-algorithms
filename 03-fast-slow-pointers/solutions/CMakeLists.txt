cmake_minimum_required(VERSION 3.14)
project(FastSlowPointersSolutions)

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
    01_linked_list_cycle
    02_middle_of_linked_list
    03_happy_number
    04_linked_list_cycle_ii
    05_palindrome_linked_list
    06_reorder_list
    07_find_duplicate_number
    08_circular_array_loop
)

foreach(solution ${SOLUTIONS})
    add_executable(${solution} ${solution}.cpp)
    target_link_libraries(${solution} GTest::gtest_main)
    add_test(NAME ${solution} COMMAND ${solution})
endforeach()
