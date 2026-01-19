/**
 * Problem: Trapping Rain Water
 * LeetCode #42
 * Difficulty: Hard
 * Pattern: Opposite Direction
 *
 * Calculate how much water can be trapped after rain.
 *
 * Example:
 *   Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
 *   Output: 6
 *
 * Constraints:
 *   - n == height.length
 *   - 1 <= n <= 2 * 10^4
 *   - 0 <= height[i] <= 10^5
 */

#include <gtest/gtest.h>
#include <vector>

using namespace std;

// ============================================================================
// TODO: Implement your solution here
// ============================================================================
int trap(vector<int>& height) {
    // Your implementation here
    // Hint: Water at position = min(maxLeft, maxRight) - height[i]
    // Use two pointers to track max heights from both sides
    
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
    vector<int> height = {1, 2, 3, 4, 5};
    EXPECT_EQ(trap(height), 0);
}

TEST(TrappingRainWater, SingleElement) {
    vector<int> height = {5};
    EXPECT_EQ(trap(height), 0);
}

TEST(TrappingRainWater, TwoElements) {
    vector<int> height = {5, 3};
    EXPECT_EQ(trap(height), 0);
}

TEST(TrappingRainWater, Valley) {
    vector<int> height = {5, 0, 5};
    EXPECT_EQ(trap(height), 5);
}

TEST(TrappingRainWater, FlatSurface) {
    vector<int> height = {3, 3, 3, 3};
    EXPECT_EQ(trap(height), 0);
}

TEST(TrappingRainWater, DeepValley) {
    vector<int> height = {5, 2, 1, 2, 1, 5};
    EXPECT_EQ(trap(height), 14);
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
