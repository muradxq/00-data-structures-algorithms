/**
 * Problem: Find All Duplicates in an Array
 * LeetCode #442
 * Difficulty: Medium
 * Pattern: Find All Duplicates
 *
 * Find all elements appearing twice in array of [1, n].
 *
 * Example:
 *   Input: nums = [4,3,2,7,8,2,3,1]
 *   Output: [2,3]
 */

#include <gtest/gtest.h>
#include <vector>
#include <algorithm>

using namespace std;

// ============================================================================
// TODO: Implement your solution here
// ============================================================================
vector<int> findDuplicates(vector<int>& nums) {
    // Your implementation here
    
    return {};
}

// ============================================================================
// Tests - DO NOT MODIFY
// ============================================================================
TEST(FindAllDuplicates, Example1) {
    vector<int> nums = {4,3,2,7,8,2,3,1};
    vector<int> result = findDuplicates(nums);
    sort(result.begin(), result.end());
    vector<int> expected = {2, 3};
    EXPECT_EQ(result, expected);
}

TEST(FindAllDuplicates, Example2) {
    vector<int> nums = {1, 1, 2};
    vector<int> expected = {1};
    EXPECT_EQ(findDuplicates(nums), expected);
}

TEST(FindAllDuplicates, NoDuplicates) {
    vector<int> nums = {1};
    vector<int> expected = {};
    EXPECT_EQ(findDuplicates(nums), expected);
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
