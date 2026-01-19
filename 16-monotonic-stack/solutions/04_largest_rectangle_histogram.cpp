/**
 * Problem: Largest Rectangle in Histogram
 * LeetCode #84
 * Difficulty: Hard
 * Pattern: Area
 *
 * Find largest rectangle area in histogram.
 *
 * Example:
 *   Input: heights = [2,1,5,6,2,3]
 *   Output: 10
 */

#include <gtest/gtest.h>
#include <vector>
#include <stack>

using namespace std;

// ============================================================================
// TODO: Implement your solution here
// ============================================================================
int largestRectangleArea(vector<int>& heights) {
    // Your implementation here
    
    return 0;
}

// ============================================================================
// Tests - DO NOT MODIFY
// ============================================================================
TEST(LargestRectangleHistogram, Example1) {
    vector<int> heights = {2, 1, 5, 6, 2, 3};
    EXPECT_EQ(largestRectangleArea(heights), 10);
}

TEST(LargestRectangleHistogram, AllSame) {
    vector<int> heights = {2, 2, 2, 2};
    EXPECT_EQ(largestRectangleArea(heights), 8);
}

TEST(LargestRectangleHistogram, Single) {
    vector<int> heights = {5};
    EXPECT_EQ(largestRectangleArea(heights), 5);
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
