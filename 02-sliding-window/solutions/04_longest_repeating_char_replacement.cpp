/**
 * Problem: Longest Repeating Character Replacement
 * LeetCode #424
 * Difficulty: Medium
 * Pattern: Variable Window
 *
 * Find longest substring with same letter after replacing at most k characters.
 *
 * Example:
 *   Input: s = "AABABBA", k = 1
 *   Output: 4 (Replace one 'A' in "AABA" to get "AAAA")
 */

#include <gtest/gtest.h>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

// ============================================================================
// TODO: Implement your solution here
// ============================================================================
int characterReplacement(string s, int k) {
    // Your implementation here
    // Key insight: window is valid if (window_length - max_freq) <= k
    
    return 0;
}

// ============================================================================
// Tests - DO NOT MODIFY
// ============================================================================
TEST(CharReplacement, Example1) {
    EXPECT_EQ(characterReplacement("ABAB", 2), 4);
}

TEST(CharReplacement, Example2) {
    EXPECT_EQ(characterReplacement("AABABBA", 1), 4);
}

TEST(CharReplacement, AllSame) {
    EXPECT_EQ(characterReplacement("AAAA", 2), 4);
}

TEST(CharReplacement, NoReplacement) {
    EXPECT_EQ(characterReplacement("ABCD", 0), 1);
}

TEST(CharReplacement, SingleChar) {
    EXPECT_EQ(characterReplacement("A", 0), 1);
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
