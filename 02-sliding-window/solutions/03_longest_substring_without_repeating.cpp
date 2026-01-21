/**
 * Problem: Longest Substring Without Repeating Characters
 * LeetCode #3
 * Difficulty: Medium
 * Pattern: Variable Window
 *
 * Find length of longest substring without repeating characters.
 *
 * Example:
 *   Input: s = "abcabcbb"
 *   Output: 3 ("abc")
 */

#include <gtest/gtest.h>
#include <string>
#include <unordered_set>

using namespace std;

// ============================================================================
// TODO: Implement your solution here
// ============================================================================
int lengthOfLongestSubstring(string s) {
    // Your implementation here
    int l =0;
    int maxLen = 0;
    unordered_set<char> seen;
    for (int r = 0; r < s.size(); r++) {
        // shrink till its valid window
        while (seen.count(s[r])) {
            seen.erase(s[l]);
            l++;
        }
        seen.insert(s[r]);
        // valid window
        maxLen = max(maxLen, r-l+1);
    }
    return maxLen;
}

// ============================================================================
// Tests - DO NOT MODIFY
// ============================================================================
TEST(LongestSubstring, Example1) {
    EXPECT_EQ(lengthOfLongestSubstring("abcabcbb"), 3);
}

TEST(LongestSubstring, Example2) {
    EXPECT_EQ(lengthOfLongestSubstring("bbbbb"), 1);
}

TEST(LongestSubstring, Example3) {
    EXPECT_EQ(lengthOfLongestSubstring("pwwkew"), 3);
}

TEST(LongestSubstring, EmptyString) {
    EXPECT_EQ(lengthOfLongestSubstring(""), 0);
}

TEST(LongestSubstring, SingleChar) {
    EXPECT_EQ(lengthOfLongestSubstring("a"), 1);
}

TEST(LongestSubstring, AllUnique) {
    EXPECT_EQ(lengthOfLongestSubstring("abcdef"), 6);
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
