/**
 * Problem: Search in Rotated Sorted Array
 * LeetCode #33
 * Difficulty: Medium
 * Pattern: Modified Binary Search
 *
 * Search in array that was sorted then rotated.
 *
 * Example:
 *   Input: nums = [4,5,6,7,0,1,2], target = 0
 *   Output: 4
 */

#include <gtest/gtest.h>
#include <vector>

using namespace std;

// ============================================================================
// TODO: Implement your solution here
// ============================================================================
int search(vector<int>& nums, int target) {
    // Key: One half is always sorted
    int l = 0; 
    int r = nums.size() - 1;

    while (l <= r) {
        int mid = l + (r - l) / 2;
        
        if (nums[mid] == target) {
            return mid;
        }
        
        if (nums[l] <= nums[mid]) {
            // Left half is sorted
            if (target >= nums[l] && target < nums[mid]) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        } else {
            // Right half is sorted
            if (target > nums[mid] && target <= nums[r]) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
    }
    return -1;
}

// ============================================================================
// Tests - DO NOT MODIFY
// ============================================================================
TEST(SearchRotated, Example1) {
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    EXPECT_EQ(search(nums, 0), 4);
}

TEST(SearchRotated, Example2) {
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    EXPECT_EQ(search(nums, 3), -1);
}

TEST(SearchRotated, Example3) {
    vector<int> nums = {1};
    EXPECT_EQ(search(nums, 0), -1);
}

TEST(SearchRotated, NotRotated) {
    vector<int> nums = {1, 2, 3, 4, 5};
    EXPECT_EQ(search(nums, 3), 2);
}

TEST(SearchRotated, RotatedOnce) {
    vector<int> nums = {2, 3, 4, 5, 1};
    EXPECT_EQ(search(nums, 1), 4);
}

TEST(SearchRotated, FindFirst) {
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    EXPECT_EQ(search(nums, 4), 0);
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
