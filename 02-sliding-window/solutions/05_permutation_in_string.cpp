/**
 * Problem: Permutation in String
 * LeetCode #567
 * Difficulty: Medium
 * Pattern: Fixed Window
 *
 * Check if s2 contains any permutation of s1.
 *
 * Example:
 *   Input: s1 = "ab", s2 = "eidbaooo"
 *   Output: true ("ba" is a permutation of "ab")
 */

#include <gtest/gtest.h>
#include <string>
#include <vector>

using namespace std;

// ============================================================================
// TODO: Implement your solution here
// ============================================================================
bool checkInclusion(string s1, string s2) {
    // Your implementation here
    
    return false;
}

// ============================================================================
// Tests - DO NOT MODIFY
// ============================================================================
TEST(PermutationInString, Example1) {
    EXPECT_TRUE(checkInclusion("ab", "eidbaooo"));
}

TEST(PermutationInString, Example2) {
    EXPECT_FALSE(checkInclusion("ab", "eidboaoo"));
}

TEST(PermutationInString, ExactMatch) {
    EXPECT_TRUE(checkInclusion("abc", "abc"));
}

TEST(PermutationInString, S1LongerThanS2) {
    EXPECT_FALSE(checkInclusion("abcd", "ab"));
}

TEST(PermutationInString, SingleChar) {
    EXPECT_TRUE(checkInclusion("a", "a"));
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
