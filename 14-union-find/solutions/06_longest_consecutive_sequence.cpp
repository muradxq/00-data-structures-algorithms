/**
 * Problem: Longest Consecutive Sequence
 * LeetCode #128
 * Difficulty: Medium
 * Pattern: Consecutive
 *
 * Find longest consecutive elements sequence.
 *
 * Example:
 *   Input: nums = [100,4,200,1,3,2]
 *   Output: 4 ([1,2,3,4])
 */

#include <gtest/gtest.h>
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;

// ============================================================================
// TODO: Implement your solution here
// ============================================================================
int longestConsecutive(vector<int>& nums) {
    // Your implementation here
    // Can use Union Find or HashSet approach
    
    return 0;
}

// ============================================================================
// Tests - DO NOT MODIFY
// ============================================================================
TEST(LongestConsecutive, Example1) {
    vector<int> nums = {100, 4, 200, 1, 3, 2};
    EXPECT_EQ(longestConsecutive(nums), 4);
}

TEST(LongestConsecutive, Example2) {
    vector<int> nums = {0, 3, 7, 2, 5, 8, 4, 6, 0, 1};
    EXPECT_EQ(longestConsecutive(nums), 9);
}

TEST(LongestConsecutive, Empty) {
    vector<int> nums;
    EXPECT_EQ(longestConsecutive(nums), 0);
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
