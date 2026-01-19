/**
 * Problem: Find All Anagrams in a String
 * LeetCode #438
 * Difficulty: Medium
 * Pattern: Fixed Window
 *
 * Find all start indices of p's anagrams in s.
 *
 * Example:
 *   Input: s = "cbaebabacd", p = "abc"
 *   Output: [0, 6]
 */

#include <gtest/gtest.h>
#include <string>
#include <vector>

using namespace std;

// ============================================================================
// TODO: Implement your solution here
// ============================================================================
vector<int> findAnagrams(string s, string p) {
    // Your implementation here
    
    return {};
}

// ============================================================================
// Tests - DO NOT MODIFY
// ============================================================================
TEST(FindAnagrams, Example1) {
    vector<int> expected = {0, 6};
    EXPECT_EQ(findAnagrams("cbaebabacd", "abc"), expected);
}

TEST(FindAnagrams, Example2) {
    vector<int> expected = {0, 1, 2};
    EXPECT_EQ(findAnagrams("abab", "ab"), expected);
}

TEST(FindAnagrams, NoMatch) {
    vector<int> expected = {};
    EXPECT_EQ(findAnagrams("xyz", "abc"), expected);
}

TEST(FindAnagrams, PLongerThanS) {
    vector<int> expected = {};
    EXPECT_EQ(findAnagrams("ab", "abc"), expected);
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
