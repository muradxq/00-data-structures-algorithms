/**
 * Problem: Unique Paths
 * LeetCode #62
 * Difficulty: Medium
 * Pattern: Grid
 *
 * Count paths from top-left to bottom-right (can only move right or down).
 *
 * Example:
 *   Input: m = 3, n = 7
 *   Output: 28
 */

#include <gtest/gtest.h>
#include <vector>

using namespace std;

// ============================================================================
// TODO: Implement your solution here
// ============================================================================
int uniquePaths(int m, int n) {
    // Your implementation here
    
    return 0;
}

// ============================================================================
// Tests - DO NOT MODIFY
// ============================================================================
TEST(UniquePaths, Example1) {
    EXPECT_EQ(uniquePaths(3, 7), 28);
}

TEST(UniquePaths, Example2) {
    EXPECT_EQ(uniquePaths(3, 2), 3);
}

TEST(UniquePaths, SingleCell) {
    EXPECT_EQ(uniquePaths(1, 1), 1);
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
