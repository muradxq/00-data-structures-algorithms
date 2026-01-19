/**
 * Problem: Word Break
 * LeetCode #139
 * Difficulty: Medium
 * Pattern: String
 *
 * Check if string can be segmented into dictionary words.
 *
 * Example:
 *   Input: s = "leetcode", wordDict = ["leet","code"]
 *   Output: true
 */

#include <gtest/gtest.h>
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

// ============================================================================
// TODO: Implement your solution here
// ============================================================================
bool wordBreak(string s, vector<string>& wordDict) {
    // Your implementation here
    
    return false;
}

// ============================================================================
// Tests - DO NOT MODIFY
// ============================================================================
TEST(WordBreak, Example1) {
    vector<string> dict = {"leet", "code"};
    EXPECT_TRUE(wordBreak("leetcode", dict));
}

TEST(WordBreak, Example2) {
    vector<string> dict = {"apple", "pen"};
    EXPECT_TRUE(wordBreak("applepenapple", dict));
}

TEST(WordBreak, Impossible) {
    vector<string> dict = {"cats", "dog", "sand", "and", "cat"};
    EXPECT_FALSE(wordBreak("catsandog", dict));
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
