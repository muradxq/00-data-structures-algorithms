/**
 * Problem: Valid Palindrome
 * LeetCode #125
 * Difficulty: Easy
 * Pattern: Opposite Direction
 *
 * Check if a string is a palindrome, considering only alphanumeric characters
 * and ignoring case.
 *
 * Example:
 *   Input: "A man, a plan, a canal: Panama"
 *   Output: true
 *   Explanation: "amanaplanacanalpanama" is a palindrome
 *
 * Constraints:
 *   - 1 <= s.length <= 2 * 10^5
 *   - s consists only of printable ASCII characters
 */

#include <gtest/gtest.h>
#include <string>

using namespace std;

// ============================================================================
// TODO: Implement your solution here
// ============================================================================
bool isPalindrome(string s) {
    // Your implementation here
    
    return false;
}

// ============================================================================
// Tests - DO NOT MODIFY
// ============================================================================
TEST(ValidPalindrome, Example1) {
    EXPECT_TRUE(isPalindrome("A man, a plan, a canal: Panama"));
}

TEST(ValidPalindrome, Example2) {
    EXPECT_FALSE(isPalindrome("race a car"));
}

TEST(ValidPalindrome, EmptyString) {
    EXPECT_TRUE(isPalindrome(" "));
}

TEST(ValidPalindrome, SingleChar) {
    EXPECT_TRUE(isPalindrome("a"));
}

TEST(ValidPalindrome, OnlySpecialChars) {
    EXPECT_TRUE(isPalindrome(".,!@#$%"));
}

TEST(ValidPalindrome, Numbers) {
    EXPECT_TRUE(isPalindrome("12321"));
}

TEST(ValidPalindrome, MixedAlphanumeric) {
    EXPECT_TRUE(isPalindrome("A1b2B1a"));
}

TEST(ValidPalindrome, NotPalindrome) {
    EXPECT_FALSE(isPalindrome("hello"));
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
