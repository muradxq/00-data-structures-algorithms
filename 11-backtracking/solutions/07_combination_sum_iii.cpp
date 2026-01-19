/**
 * Problem: Combination Sum III
 * LeetCode #216
 * Difficulty: Medium
 * Pattern: Numbers
 *
 * Find combinations of k numbers (1-9) that sum to n. Each number used once.
 *
 * Example:
 *   Input: k = 3, n = 7
 *   Output: [[1,2,4]]
 */

#include <gtest/gtest.h>
#include <vector>

using namespace std;

// ============================================================================
// TODO: Implement your solution here
// ============================================================================
vector<vector<int>> combinationSum3(int k, int n) {
    // Your implementation here
    
    return {};
}

// ============================================================================
// Tests - DO NOT MODIFY
// ============================================================================
TEST(CombinationSumIII, Example1) {
    auto result = combinationSum3(3, 7);
    EXPECT_EQ(result.size(), 1);
}

TEST(CombinationSumIII, Example2) {
    auto result = combinationSum3(3, 9);
    EXPECT_EQ(result.size(), 3);
}

TEST(CombinationSumIII, NoSolution) {
    auto result = combinationSum3(4, 1);
    EXPECT_TRUE(result.empty());
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
