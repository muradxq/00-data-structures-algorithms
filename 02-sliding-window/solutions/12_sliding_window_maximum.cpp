/**
 * Problem: Sliding Window Maximum
 * LeetCode #239
 * Difficulty: Hard
 * Pattern: Fixed Window + Deque
 *
 * Return max element for each window of size k.
 *
 * Example:
 *   Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
 *   Output: [3,3,5,5,6,7]
 */

#include <gtest/gtest.h>
#include <vector>
#include <deque>

using namespace std;

// ============================================================================
// TODO: Implement your solution here
// ============================================================================
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    // Your implementation here
    // Hint: Use monotonic deque to maintain indices of potential maximums
    
    return {};
}

// ============================================================================
// Tests - DO NOT MODIFY
// ============================================================================
TEST(SlidingWindowMax, Example1) {
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    vector<int> expected = {3, 3, 5, 5, 6, 7};
    EXPECT_EQ(maxSlidingWindow(nums, 3), expected);
}

TEST(SlidingWindowMax, Example2) {
    vector<int> nums = {1};
    vector<int> expected = {1};
    EXPECT_EQ(maxSlidingWindow(nums, 1), expected);
}

TEST(SlidingWindowMax, AllSame) {
    vector<int> nums = {5, 5, 5, 5};
    vector<int> expected = {5, 5};
    EXPECT_EQ(maxSlidingWindow(nums, 3), expected);
}

TEST(SlidingWindowMax, Decreasing) {
    vector<int> nums = {5, 4, 3, 2, 1};
    vector<int> expected = {5, 4, 3};
    EXPECT_EQ(maxSlidingWindow(nums, 3), expected);
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
