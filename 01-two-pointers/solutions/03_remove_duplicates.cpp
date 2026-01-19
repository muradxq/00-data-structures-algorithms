/**
 * Problem: Remove Duplicates from Sorted Array
 * LeetCode #26
 * Difficulty: Easy
 * Pattern: Same Direction (Fast & Slow)
 *
 * Remove duplicates in-place from sorted array. Return the new length.
 * The relative order of elements should be kept the same.
 *
 * Example:
 *   Input: nums = [1,1,2]
 *   Output: 2, nums = [1,2,_]
 *
 * Constraints:
 *   - 1 <= nums.length <= 3 * 10^4
 *   - -100 <= nums[i] <= 100
 *   - nums is sorted in non-decreasing order
 */

#include <gtest/gtest.h>
#include <vector>

using namespace std;

// ============================================================================
// TODO: Implement your solution here
// ============================================================================
int removeDuplicates(vector<int>& nums) {
    // Your implementation here
    
    return 0;
}

// ============================================================================
// Tests - DO NOT MODIFY
// ============================================================================
TEST(RemoveDuplicates, Example1) {
    vector<int> nums = {1, 1, 2};
    int k = removeDuplicates(nums);
    EXPECT_EQ(k, 2);
    EXPECT_EQ(nums[0], 1);
    EXPECT_EQ(nums[1], 2);
}

TEST(RemoveDuplicates, Example2) {
    vector<int> nums = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    int k = removeDuplicates(nums);
    EXPECT_EQ(k, 5);
    vector<int> expected = {0, 1, 2, 3, 4};
    for (int i = 0; i < k; i++) {
        EXPECT_EQ(nums[i], expected[i]);
    }
}

TEST(RemoveDuplicates, SingleElement) {
    vector<int> nums = {1};
    EXPECT_EQ(removeDuplicates(nums), 1);
}

TEST(RemoveDuplicates, NoDuplicates) {
    vector<int> nums = {1, 2, 3, 4, 5};
    EXPECT_EQ(removeDuplicates(nums), 5);
}

TEST(RemoveDuplicates, AllSame) {
    vector<int> nums = {2, 2, 2, 2, 2};
    int k = removeDuplicates(nums);
    EXPECT_EQ(k, 1);
    EXPECT_EQ(nums[0], 2);
}

TEST(RemoveDuplicates, NegativeNumbers) {
    vector<int> nums = {-3, -3, -1, 0, 0, 1};
    int k = removeDuplicates(nums);
    EXPECT_EQ(k, 4);
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
