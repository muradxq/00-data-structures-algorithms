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
    std::unordered_map<char, int> count;
    int l = 0;
    int maxFreq = 0;
    int maxLen = 0;
    for (int r = 0; r < s.size(); r++) {
        // Update max when adding a character
        count[s[r]]++;
        maxFreq = max(maxFreq, count[s[r]]);  
        // shrink window
        while (r - l + 1 - maxFreq > k) {
            count[s[l]]--;
            l++;
            if(count[s[l]] == 0)
                count.erase(s[l]); 
        }
        //valid window
        maxLen = max(maxLen, r - l + 1);
    }
    return maxLen;
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
