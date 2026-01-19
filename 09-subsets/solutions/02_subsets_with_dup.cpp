/**
 * Problem: Subsets II
 * LeetCode #90
 * Difficulty: Medium
 * Pattern: With Duplicates
 *
 * Generate subsets when input may have duplicates.
 *
 * Example:
 *   Input: nums = [1,2,2]
 *   Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]
 */

#include <gtest/gtest.h>
#include <vector>
#include <algorithm>

using namespace std;

// ============================================================================
// TODO: Implement your solution here
// ============================================================================
vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    // Your implementation here
    // Hint: Sort first, skip duplicates
    
    return {};
}

// ============================================================================
// Tests - DO NOT MODIFY
// ============================================================================
TEST(SubsetsII, Example1) {
    vector<int> nums = {1, 2, 2};
    auto result = subsetsWithDup(nums);
    EXPECT_EQ(result.size(), 6);
}

TEST(SubsetsII, AllSame) {
    vector<int> nums = {1, 1, 1};
    auto result = subsetsWithDup(nums);
    EXPECT_EQ(result.size(), 4);
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
