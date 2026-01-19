/**
 * Problem: Combination Sum II
 * LeetCode #40
 * Difficulty: Medium
 * Pattern: Limited Use
 *
 * Find combinations that sum to target. Each number used at most once.
 *
 * Example:
 *   Input: candidates = [10,1,2,7,6,1,5], target = 8
 *   Output: [[1,1,6],[1,2,5],[1,7],[2,6]]
 */

#include <gtest/gtest.h>
#include <vector>
#include <algorithm>

using namespace std;

// ============================================================================
// TODO: Implement your solution here
// ============================================================================
vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    // Your implementation here
    // Sort first, skip duplicates
    
    return {};
}

// ============================================================================
// Tests - DO NOT MODIFY
// ============================================================================
TEST(CombinationSumII, Example1) {
    vector<int> candidates = {10,1,2,7,6,1,5};
    auto result = combinationSum2(candidates, 8);
    EXPECT_EQ(result.size(), 4);
}

TEST(CombinationSumII, Example2) {
    vector<int> candidates = {2, 5, 2, 1, 2};
    auto result = combinationSum2(candidates, 5);
    EXPECT_EQ(result.size(), 2);
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
