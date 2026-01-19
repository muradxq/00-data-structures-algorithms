/**
 * Problem: Permutations II
 * LeetCode #47
 * Difficulty: Medium
 * Pattern: With Duplicates
 *
 * Generate unique permutations when input has duplicates.
 *
 * Example:
 *   Input: nums = [1,1,2]
 *   Output: [[1,1,2],[1,2,1],[2,1,1]]
 */

#include <gtest/gtest.h>
#include <vector>
#include <algorithm>

using namespace std;

// ============================================================================
// TODO: Implement your solution here
// ============================================================================
vector<vector<int>> permuteUnique(vector<int>& nums) {
    // Your implementation here
    // Sort first, use 'used' array, skip duplicates
    
    return {};
}

// ============================================================================
// Tests - DO NOT MODIFY
// ============================================================================
TEST(PermutationsII, Example1) {
    vector<int> nums = {1, 1, 2};
    auto result = permuteUnique(nums);
    EXPECT_EQ(result.size(), 3);
}

TEST(PermutationsII, AllSame) {
    vector<int> nums = {1, 1, 1};
    auto result = permuteUnique(nums);
    EXPECT_EQ(result.size(), 1);
}

TEST(PermutationsII, AllUnique) {
    vector<int> nums = {1, 2, 3};
    auto result = permuteUnique(nums);
    EXPECT_EQ(result.size(), 6);
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
