/**
 * Problem: Partition Labels
 * LeetCode #763
 * Difficulty: Medium
 * Pattern: Intervals
 *
 * Partition string so each letter appears in at most one part.
 *
 * Example:
 *   Input: s = "ababcbacadefegdehijhklij"
 *   Output: [9,7,8]
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
vector<int> partitionLabels(string s) {
    // Your implementation here
    // Track last occurrence of each char
    
    return {};
}

// ============================================================================
// Tests - DO NOT MODIFY
// ============================================================================
TEST(PartitionLabels, Example1) {
    vector<int> expected = {9, 7, 8};
    EXPECT_EQ(partitionLabels("ababcbacadefegdehijhklij"), expected);
}

TEST(PartitionLabels, SinglePart) {
    vector<int> expected = {10};
    EXPECT_EQ(partitionLabels("eccbbbbdec"), expected);
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
