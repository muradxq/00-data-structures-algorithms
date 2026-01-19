/**
 * Problem: Permutations
 * LeetCode #46
 * Difficulty: Medium
 * Pattern: All Arrangements
 *
 * Generate all permutations of distinct integers.
 *
 * Example:
 *   Input: nums = [1,2,3]
 *   Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
 */

#include <gtest/gtest.h>
#include <vector>

using namespace std;

// ============================================================================
// TODO: Implement your solution here
// ============================================================================
vector<vector<int>> permute(vector<int>& nums) {
    // Your implementation here
    
    return {};
}

// ============================================================================
// Tests - DO NOT MODIFY
// ============================================================================
TEST(Permutations, Example1) {
    vector<int> nums = {1, 2, 3};
    auto result = permute(nums);
    EXPECT_EQ(result.size(), 6);
}

TEST(Permutations, TwoElements) {
    vector<int> nums = {0, 1};
    auto result = permute(nums);
    EXPECT_EQ(result.size(), 2);
}

TEST(Permutations, SingleElement) {
    vector<int> nums = {1};
    auto result = permute(nums);
    EXPECT_EQ(result.size(), 1);
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
