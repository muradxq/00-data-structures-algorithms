/**
 * Problem: Longest Common Subsequence
 * LeetCode #1143
 * Difficulty: Medium
 * Pattern: 2D
 *
 * Find length of longest common subsequence.
 *
 * Example:
 *   Input: text1 = "abcde", text2 = "ace"
 *   Output: 3 ("ace")
 */

#include <gtest/gtest.h>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// ============================================================================
// TODO: Implement your solution here
// ============================================================================
int longestCommonSubsequence(string text1, string text2) {
    // Your implementation here
    
    return 0;
}

// ============================================================================
// Tests - DO NOT MODIFY
// ============================================================================
TEST(LCS, Example1) {
    EXPECT_EQ(longestCommonSubsequence("abcde", "ace"), 3);
}

TEST(LCS, Example2) {
    EXPECT_EQ(longestCommonSubsequence("abc", "abc"), 3);
}

TEST(LCS, NoCommon) {
    EXPECT_EQ(longestCommonSubsequence("abc", "def"), 0);
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
