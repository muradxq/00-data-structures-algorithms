/**
 * Problem: Substring with Concatenation of All Words
 * LeetCode #30
 * Difficulty: Hard
 * Pattern: Fixed Window
 *
 * Find all starting indices of substrings that are concatenation of all words.
 * Each word has same length, and each word must be used exactly once.
 *
 * Example:
 *   Input: s = "barfoothefoobarman", words = ["foo","bar"]
 *   Output: [0,9]
 *   Explanation: "barfoo" starts at 0, "foobar" starts at 9
 *
 *   Input: s = "wordgoodgoodgoodbestword", words = ["word","good","best","word"]
 *   Output: []
 *
 * Approach:
 *   - Window size = word_length * number_of_words
 *   - For each starting position (0 to word_length-1), slide word by word
 *   - Use hashmap to track word frequencies
 *
 * Constraints:
 *   - 1 <= s.length <= 10^4
 *   - 1 <= words.length <= 5000
 *   - 1 <= words[i].length <= 30
 *   - All words have same length
 */

#include <gtest/gtest.h>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

// ============================================================================
// TODO: Implement your solution here
// ============================================================================
vector<int> findSubstring(string s, vector<string>& words) {
    // Your implementation here
    // Key: All words have same length
    // Window size = word_length * num_words
    
    return {};
}

// ============================================================================
// Tests - DO NOT MODIFY
// ============================================================================
TEST(SubstringConcat, Example1) {
    vector<string> words = {"foo", "bar"};
    vector<int> expected = {0, 9};
    auto result = findSubstring("barfoothefoobarman", words);
    sort(result.begin(), result.end());
    EXPECT_EQ(result, expected);
}

TEST(SubstringConcat, Example2) {
    vector<string> words = {"word", "good", "best", "word"};
    vector<int> expected = {};
    EXPECT_EQ(findSubstring("wordgoodgoodgoodbestword", words), expected);
}

TEST(SubstringConcat, Example3) {
    vector<string> words = {"bar", "foo", "the"};
    vector<int> expected = {6, 9, 12};
    auto result = findSubstring("barfoofoobarthefoobarman", words);
    sort(result.begin(), result.end());
    EXPECT_EQ(result, expected);
}

TEST(SubstringConcat, SingleWord) {
    vector<string> words = {"ab"};
    vector<int> expected = {0, 3};
    auto result = findSubstring("ababab", words);
    sort(result.begin(), result.end());
    EXPECT_EQ(result, expected);
}

TEST(SubstringConcat, NoMatch) {
    vector<string> words = {"xyz"};
    vector<int> expected = {};
    EXPECT_EQ(findSubstring("abcdef", words), expected);
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
