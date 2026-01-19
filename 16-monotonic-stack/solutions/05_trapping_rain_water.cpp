/**
 * Problem: Trapping Rain Water
 * LeetCode #42
 * Difficulty: Hard
 * Pattern: Two Pass
 *
 * Calculate trapped rain water.
 *
 * Example:
 *   Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
 *   Output: 6
 */

#include <gtest/gtest.h>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

// ============================================================================
// TODO: Implement your solution here
// ============================================================================
int trap(vector<int>& height) {
    // Your implementation here
    // Can use monotonic stack or two pointers
    
    return 0;
}

// ============================================================================
// Tests - DO NOT MODIFY
// ============================================================================
TEST(TrappingRainWater, Example1) {
    vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    EXPECT_EQ(trap(height), 6);
}

TEST(TrappingRainWater, Example2) {
    vector<int> height = {4, 2, 0, 3, 2, 5};
    EXPECT_EQ(trap(height), 9);
}

TEST(TrappingRainWater, NoWater) {
    vector<int> height = {1, 2, 3};
    EXPECT_EQ(trap(height), 0);
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
