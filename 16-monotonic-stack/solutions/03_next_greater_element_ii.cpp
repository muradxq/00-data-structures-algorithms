/**
 * Problem: Next Greater Element II
 * LeetCode #503
 * Difficulty: Medium
 * Pattern: Circular
 *
 * Circular array - next greater element.
 *
 * Example:
 *   Input: nums = [1,2,1]
 *   Output: [2,-1,2]
 */

#include <gtest/gtest.h>
#include <vector>
#include <stack>

using namespace std;

// ============================================================================
// TODO: Implement your solution here
// ============================================================================
vector<int> nextGreaterElements(vector<int>& nums) {
    // Your implementation here
    // Process array twice for circular behavior
    
    return {};
}

// ============================================================================
// Tests - DO NOT MODIFY
// ============================================================================
TEST(NextGreaterElementII, Example1) {
    vector<int> nums = {1, 2, 1};
    vector<int> expected = {2, -1, 2};
    EXPECT_EQ(nextGreaterElements(nums), expected);
}

TEST(NextGreaterElementII, AllSame) {
    vector<int> nums = {1, 1, 1, 1};
    vector<int> expected = {-1, -1, -1, -1};
    EXPECT_EQ(nextGreaterElements(nums), expected);
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
