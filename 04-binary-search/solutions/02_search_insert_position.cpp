/**
 * Problem: Search Insert Position
 * LeetCode #35
 * Difficulty: Easy
 * Pattern: Boundary
 *
 * Find index where target should be inserted in sorted array.
 *
 * Example:
 *   Input: nums = [1,3,5,6], target = 5 → Output: 2
 *   Input: nums = [1,3,5,6], target = 2 → Output: 1
 */

#include <gtest/gtest.h>
#include <vector>

using namespace std;

// ============================================================================
// TODO: Implement your solution here
// ============================================================================
int searchInsert(vector<int>& nums, int target) {
    // Your implementation here
    int l = 0;
    int r = nums.size() - 1;
    while (l <= r) {
        int mid = l + (r-l)/2;
        if(nums[mid] >= target) {
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    return l;
}

// ============================================================================
// Tests - DO NOT MODIFY
// ============================================================================
TEST(SearchInsert, Example1) {
    vector<int> nums = {1, 3, 5, 6};
    EXPECT_EQ(searchInsert(nums, 5), 2);
}

TEST(SearchInsert, Example2) {
    vector<int> nums = {1, 3, 5, 6};
    EXPECT_EQ(searchInsert(nums, 2), 1);
}

TEST(SearchInsert, Example3) {
    vector<int> nums = {1, 3, 5, 6};
    EXPECT_EQ(searchInsert(nums, 7), 4);
}

TEST(SearchInsert, InsertAtStart) {
    vector<int> nums = {1, 3, 5, 6};
    EXPECT_EQ(searchInsert(nums, 0), 0);
}

TEST(SearchInsert, SingleElement) {
    vector<int> nums = {1};
    EXPECT_EQ(searchInsert(nums, 0), 0);
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
