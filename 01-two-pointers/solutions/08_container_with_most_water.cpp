/**
 * Problem: Container With Most Water
 * LeetCode #11
 * Difficulty: Medium
 * Pattern: Opposite Direction
 *
 * Find two lines that together with x-axis forms container with most water.
 *
 * Example:
 *   Input: height = [1,8,6,2,5,4,8,3,7]
 *   Output: 49
 *   Explanation: Lines at index 1 and 8 form container with area = 7 * 7 = 49
 *
 * Constraints:
 *   - n == height.length
 *   - 2 <= n <= 10^5
 *   - 0 <= height[i] <= 10^4
 */

#include <gtest/gtest.h>
#include <vector>
#include <climits>

using namespace std;

// ============================================================================
// TODO: Implement your solution here
// ============================================================================
int maxArea(vector<int>& height) {
    // Your implementation here
    // Hint: Start with widest container, move the shorter line inward
    int l = 0;
    int r = height.size()-1;
    int maxArea = INT_MIN;
    while (l < r) {
        int area = (r-l) * min(height[l],height[r]);
        maxArea = max(maxArea, area);
        if (height[l] < height[r]) {
            l++;
        } else {
            r--;
        }
    }
    return maxArea;
}

// ============================================================================
// Tests - DO NOT MODIFY
// ============================================================================
TEST(ContainerMostWater, Example1) {
    vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    EXPECT_EQ(maxArea(height), 49);
}

TEST(ContainerMostWater, Example2) {
    vector<int> height = {1, 1};
    EXPECT_EQ(maxArea(height), 1);
}

TEST(ContainerMostWater, IncreasingHeights) {
    vector<int> height = {1, 2, 3, 4, 5};
    EXPECT_EQ(maxArea(height), 6);  // index 0 and 4: min(1,5) * 4 = 4, or 1,3: min(2,4)*2=4, etc
}

TEST(ContainerMostWater, DecreasingHeights) {
    vector<int> height = {5, 4, 3, 2, 1};
    EXPECT_EQ(maxArea(height), 6);
}

TEST(ContainerMostWater, SameHeights) {
    vector<int> height = {4, 4, 4, 4};
    EXPECT_EQ(maxArea(height), 12);  // 4 * 3
}

TEST(ContainerMostWater, TallEnds) {
    vector<int> height = {10, 1, 1, 1, 10};
    EXPECT_EQ(maxArea(height), 40);  // 10 * 4
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
