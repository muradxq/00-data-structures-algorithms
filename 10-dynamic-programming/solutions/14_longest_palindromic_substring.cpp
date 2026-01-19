/**
 * Problem: Longest Palindromic Substring
 * LeetCode #5
 * Difficulty: Medium
 * Pattern: String
 *
 * Find longest palindromic substring.
 *
 * Example:
 *   Input: s = "babad"
 *   Output: "bab" or "aba"
 */

#include <gtest/gtest.h>
#include <string>

using namespace std;

// ============================================================================
// TODO: Implement your solution here
// ============================================================================
string longestPalindrome(string s) {
    // Your implementation here
    
    return "";
}

// ============================================================================
// Tests - DO NOT MODIFY
// ============================================================================
TEST(LongestPalindrome, Example1) {
    string result = longestPalindrome("babad");
    EXPECT_TRUE(result == "bab" || result == "aba");
}

TEST(LongestPalindrome, Example2) {
    EXPECT_EQ(longestPalindrome("cbbd"), "bb");
}

TEST(LongestPalindrome, SingleChar) {
    EXPECT_EQ(longestPalindrome("a"), "a");
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
