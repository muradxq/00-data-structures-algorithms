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
bool checkEq(std::vector<int> v1, std::vector<int> v2) {
    if (v1.size() != v2.size())
        return false;
    for (int i =0; i < v1.size(); i++) {
        if (v1[i] != v2[i])
        return false;
    }
    return true;
}
vector<int> findAnagrams(string s, string p) {
    // Your implementation here
    if (p.size() > s.size()) return {};
    
    std::vector<int> count1(26, 0);  // Pattern p
    std::vector<int> count2(26, 0);  // Current window in s
    
    // Count characters in pattern p
    for (auto c : p) {
        count1[c - 'a']++;
    }
    
    int ns = s.size();
    int np = p.size();
    
    // Initialize first window in s
    for (int i = 0; i < np; i++) {
        count2[s[i] - 'a']++;
    }
    
    vector<int> res;
    if (checkEq(count1, count2))
        res.push_back(0);
    
    // Slide the window
    for (int i = np; i < ns; i++) {
        count2[s[i] - 'a']++;           // Add new character
        count2[s[i - np] - 'a']--;       // Remove old character
        if (checkEq(count1, count2))
            res.push_back(i - np + 1);    // Start index of current window
    }
    
    return res;
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
