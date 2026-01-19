/**
 * Problem: Minimum Window Substring
 * LeetCode #76
 * Difficulty: Hard
 * Pattern: Variable Window
 *
 * Find minimum window in s containing all characters of t.
 *
 * Example:
 *   Input: s = "ADOBECODEBANC", t = "ABC"
 *   Output: "BANC"
 */

#include <gtest/gtest.h>
#include <string>
#include <unordered_map>
#include <climits>

using namespace std;

// ============================================================================
// TODO: Implement your solution here
// ============================================================================
string minWindow(string s, string t) {
    // Your implementation here
    
    return "";
}

// ============================================================================
// Tests - DO NOT MODIFY
// ============================================================================
TEST(MinWindowSubstring, Example1) {
    EXPECT_EQ(minWindow("ADOBECODEBANC", "ABC"), "BANC");
}

TEST(MinWindowSubstring, Example2) {
    EXPECT_EQ(minWindow("a", "a"), "a");
}

TEST(MinWindowSubstring, NoSolution) {
    EXPECT_EQ(minWindow("a", "aa"), "");
}

TEST(MinWindowSubstring, TLongerThanS) {
    EXPECT_EQ(minWindow("ab", "abc"), "");
}

TEST(MinWindowSubstring, ExactMatch) {
    EXPECT_EQ(minWindow("abc", "abc"), "abc");
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
