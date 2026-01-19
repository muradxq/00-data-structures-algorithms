# Two Pointers - Solutions

This folder contains C++ solution files with GoogleTest for each problem.

## Problems

| # | File | Problem | Difficulty | LeetCode |
|---|------|---------|------------|----------|
| 1 | `01_two_sum_ii.cpp` | Two Sum II | Easy | #167 |
| 2 | `02_valid_palindrome.cpp` | Valid Palindrome | Easy | #125 |
| 3 | `03_remove_duplicates.cpp` | Remove Duplicates from Sorted Array | Easy | #26 |
| 4 | `04_move_zeroes.cpp` | Move Zeroes | Easy | #283 |
| 5 | `05_squares_sorted_array.cpp` | Squares of a Sorted Array | Easy | #977 |
| 6 | `06_three_sum.cpp` | 3Sum | Medium | #15 |
| 7 | `07_three_sum_closest.cpp` | 3Sum Closest | Medium | #16 |
| 8 | `08_container_with_most_water.cpp` | Container With Most Water | Medium | #11 |
| 9 | `09_sort_colors.cpp` | Sort Colors | Medium | #75 |
| 10 | `10_four_sum.cpp` | 4Sum | Medium | #18 |
| 11 | `11_remove_nth_node.cpp` | Remove Nth Node From End | Medium | #19 |
| 12 | `12_trapping_rain_water.cpp` | Trapping Rain Water | Hard | #42 |

## How to Build and Test

### Build All Solutions

```bash
mkdir build && cd build
cmake ..
make
```

### Run All Tests

```bash
cd build
ctest --output-on-failure
```

### Run a Specific Test

```bash
cd build
./01_two_sum_ii
```

### Quick Build & Test (Single Command)

```bash
mkdir -p build && cd build && cmake .. && make && ctest --output-on-failure
```

## Workflow

1. **Read the problem** - Each `.cpp` file has the problem description at the top
2. **Implement your solution** - Fill in the empty function marked with `TODO`
3. **Run the tests** - Build and run to check if your solution passes
4. **Debug if needed** - The test output shows which cases failed

## Example

Open `01_two_sum_ii.cpp`, implement the `twoSum` function:

```cpp
vector<int> twoSum(vector<int>& numbers, int target) {
    int left = 0, right = numbers.size() - 1;
    
    while (left < right) {
        int sum = numbers[left] + numbers[right];
        if (sum == target) {
            return {left + 1, right + 1};
        } else if (sum < target) {
            left++;
        } else {
            right--;
        }
    }
    return {};
}
```

Then build and run:

```bash
cd build
make 01_two_sum_ii
./01_two_sum_ii
```

---

*[← Back to Pattern](../README.md)*
