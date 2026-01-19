/**
 * Problem: Subsets
 * LeetCode #78
 * Difficulty: Medium
 * Pattern: Power Set
 *
 * Generate all subsets of distinct integers.
 *
 * Example:
 *   Input: nums = [1,2,3]
 *   Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
 */

#include <gtest/gtest.h>
#include <vector>
#include <algorithm>

using namespace std;

// ============================================================================
// TODO: Implement your solution here
// ============================================================================
vector<vector<int>> subsets(vector<int>& nums) {
    // Your implementation here
    
    return {};
}

// ============================================================================
// Tests - DO NOT MODIFY
// ============================================================================
TEST(Subsets, Example1) {
    vector<int> nums = {1, 2, 3};
    auto result = subsets(nums);
    EXPECT_EQ(result.size(), 8);
}

TEST(Subsets, SingleElement) {
    vector<int> nums = {0};
    auto result = subsets(nums);
    EXPECT_EQ(result.size(), 2);
}

TEST(Subsets, Empty) {
    vector<int> nums = {};
    auto result = subsets(nums);
    EXPECT_EQ(result.size(), 1);
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
