/**
 * Problem: Combinations
 * LeetCode #77
 * Difficulty: Medium
 * Pattern: Choose k
 *
 * Find all combinations of k numbers from [1, n].
 *
 * Example:
 *   Input: n = 4, k = 2
 *   Output: [[1,2],[1,3],[1,4],[2,3],[2,4],[3,4]]
 */

#include <gtest/gtest.h>
#include <vector>

using namespace std;

// ============================================================================
// TODO: Implement your solution here
// ============================================================================
vector<vector<int>> combine(int n, int k) {
    // Your implementation here
    
    return {};
}

// ============================================================================
// Tests - DO NOT MODIFY
// ============================================================================
TEST(Combinations, Example1) {
    auto result = combine(4, 2);
    EXPECT_EQ(result.size(), 6);
}

TEST(Combinations, ChooseAll) {
    auto result = combine(3, 3);
    EXPECT_EQ(result.size(), 1);
}

TEST(Combinations, ChooseOne) {
    auto result = combine(4, 1);
    EXPECT_EQ(result.size(), 4);
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
