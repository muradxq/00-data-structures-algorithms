/**
 * Problem: N-Queens II
 * LeetCode #52
 * Difficulty: Hard
 * Pattern: Count
 *
 * Count distinct solutions to N-Queens.
 *
 * Example:
 *   Input: n = 4
 *   Output: 2
 */

#include <gtest/gtest.h>

using namespace std;

// ============================================================================
// TODO: Implement your solution here
// ============================================================================
int totalNQueens(int n) {
    // Your implementation here
    
    return 0;
}

// ============================================================================
// Tests - DO NOT MODIFY
// ============================================================================
TEST(NQueensII, N4) {
    EXPECT_EQ(totalNQueens(4), 2);
}

TEST(NQueensII, N1) {
    EXPECT_EQ(totalNQueens(1), 1);
}

TEST(NQueensII, N8) {
    EXPECT_EQ(totalNQueens(8), 92);
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
