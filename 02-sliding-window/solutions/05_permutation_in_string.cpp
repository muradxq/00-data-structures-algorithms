/**
 * Problem: Permutation in String
 * LeetCode #567
 * Difficulty: Medium
 * Pattern: Fixed Window
 *
 * Check if s2 contains any permutation of s1.
 *
 * Example:
 *   Input: s1 = "ab", s2 = "eidbaooo"
 *   Output: true ("ba" is a permutation of "ab")
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
bool checkInclusion(string s1, string s2) {
    // Your implementation here
    if (s1.size() > s2.size()) return false;
    
    std::vector<int> count1(26, 0);
    for (auto c : s1) {
        count1[c - 'a']++;
    }
    // first window
    std::vector<int> count2(26, 0);
    for (int i = 0; i < s1.size(); i++) {
        count2[s2[i]-'a']++;
    } 
    if (checkEq(count1, count2)) 
        return true;
    
    for (int i = s1.size(); i < s2.size(); i++) {
        count2[s2[i] - 'a']++;
        count2[s2[i - s1.size()] - 'a']--;
        if (checkEq(count1, count2))
            return true;
    }

    return false;
}

// ============================================================================
// Tests - DO NOT MODIFY
// ============================================================================
TEST(PermutationInString, Example1) {
    EXPECT_TRUE(checkInclusion("ab", "eidbaooo"));
}

TEST(PermutationInString, Example2) {
    EXPECT_FALSE(checkInclusion("ab", "eidboaoo"));
}

TEST(PermutationInString, ExactMatch) {
    EXPECT_TRUE(checkInclusion("abc", "abc"));
}

TEST(PermutationInString, S1LongerThanS2) {
    EXPECT_FALSE(checkInclusion("abcd", "ab"));
}

TEST(PermutationInString, SingleChar) {
    EXPECT_TRUE(checkInclusion("a", "a"));
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
