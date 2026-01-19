/**
 * Problem: Jump Game II
 * LeetCode #45
 * Difficulty: Medium
 * Pattern: Min Jumps
 *
 * Minimum jumps to reach end.
 *
 * Example:
 *   Input: nums = [2,3,1,1,4]
 *   Output: 2 (0→1→4)
 */

#include <gtest/gtest.h>
#include <vector>
#include <algorithm>

using namespace std;

// ============================================================================
// TODO: Implement your solution here
// ============================================================================
int jump(vector<int>& nums) {
    // Your implementation here
    // Greedy: jump when you reach current end
    
    return 0;
}

// ============================================================================
// Tests - DO NOT MODIFY
// ============================================================================
TEST(JumpGameII, Example1) {
    vector<int> nums = {2, 3, 1, 1, 4};
    EXPECT_EQ(jump(nums), 2);
}

TEST(JumpGameII, Example2) {
    vector<int> nums = {2, 3, 0, 1, 4};
    EXPECT_EQ(jump(nums), 2);
}

TEST(JumpGameII, SingleElement) {
    vector<int> nums = {0};
    EXPECT_EQ(jump(nums), 0);
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
