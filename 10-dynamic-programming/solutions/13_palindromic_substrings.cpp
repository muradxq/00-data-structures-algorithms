/**
 * Problem: Palindromic Substrings
 * LeetCode #647
 * Difficulty: Medium
 * Pattern: String
 *
 * Count palindromic substrings.
 *
 * Example:
 *   Input: s = "abc"
 *   Output: 3 ("a", "b", "c")
 */

#include <gtest/gtest.h>
#include <string>

using namespace std;

// ============================================================================
// TODO: Implement your solution here
// ============================================================================
int countSubstrings(string s) {
    // Your implementation here
    
    return 0;
}

// ============================================================================
// Tests - DO NOT MODIFY
// ============================================================================
TEST(PalindromicSubstrings, Example1) {
    EXPECT_EQ(countSubstrings("abc"), 3);
}

TEST(PalindromicSubstrings, Example2) {
    EXPECT_EQ(countSubstrings("aaa"), 6);
}

TEST(PalindromicSubstrings, SingleChar) {
    EXPECT_EQ(countSubstrings("a"), 1);
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
