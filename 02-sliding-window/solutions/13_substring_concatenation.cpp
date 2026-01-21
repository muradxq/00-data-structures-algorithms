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
#include <algorithm>

using namespace std;

// ============================================================================
// TODO: Implement your solution here
// ============================================================================
vector<int> findSubstring(string s, vector<string>& words) {
    if (s.empty() || words.empty()) return {};
    
    int wordLen = words[0].size();
    int wordCount = words.size();
    int totalLen = wordLen * wordCount;
    
    if (s.size() < totalLen) return {};
    
    // Count frequency of each word
    unordered_map<string, int> wordMap;
    for (const string& word : words) {
        wordMap[word]++;
    }
    
    vector<int> result;
    
    // Try each starting position (0 to wordLen-1)
    // Because words can start at different offsets
    for (int i = 0; i < wordLen; i++) {
        int left = i;
        int count = 0;
        unordered_map<string, int> seen;
        
        // Slide word by word (not character by character)
        for (int j = i; j + wordLen <= s.size(); j += wordLen) {
            string word = s.substr(j, wordLen);
            
            if (wordMap.count(word)) {
                seen[word]++;
                count++;
                
                // Shrink window if we have too many of this word
                while (seen[word] > wordMap[word]) {
                    string leftWord = s.substr(left, wordLen);
                    seen[leftWord]--;
                    count--;
                    left += wordLen;
                }
                
                // Check if we found a valid concatenation
                if (count == wordCount) {
                    result.push_back(left);
                    // Slide window forward by removing leftmost word to find overlapping matches
                    string leftWord = s.substr(left, wordLen);
                    seen[leftWord]--;
                    count--;
                    left += wordLen;
                }
            } else {
                // Invalid word found, reset window
                seen.clear();
                count = 0;
                left = j + wordLen;
            }
        }
    }
    
    return result;
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
    vector<int> expected = {0, 2, 4};
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
