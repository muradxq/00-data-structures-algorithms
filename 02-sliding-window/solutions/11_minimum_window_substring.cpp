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
    if (s.empty() || t.empty() || s.size() < t.size()) return "";
    
    vector<int> countT(128, 0), countS(128, 0);
    for (auto c : t) countT[c]++;
    
    int required = 0;
    for (int i = 0; i < 128; i++) {
        if (countT[i] > 0) required++;
    }
    
    int l = 0, formed = 0, minWin = INT_MAX, start = 0;
    
    for (int r = 0; r < s.size(); r++) {
        countS[s[r]]++;
        if (countS[s[r]] == countT[s[r]]) formed++;
        
        while (l <= r && formed == required) {
            if (r - l + 1 < minWin) {
                minWin = r - l + 1;
                start = l;
            }
            countS[s[l]]--;
            if (countS[s[l]] < countT[s[l]]) formed--;
            l++;
        }
    }
    
    return minWin == INT_MAX ? "" : s.substr(start, minWin);
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
