/**
 * Problem: Top K Frequent Elements
 * LeetCode #347
 * Difficulty: Medium
 * Pattern: Top K
 *
 * Find k most frequent elements.
 *
 * Example:
 *   Input: nums = [1,1,1,2,2,3], k = 2
 *   Output: [1,2]
 */

#include <gtest/gtest.h>
#include <vector>
#include <unordered_map>
#include <queue>
#include <algorithm>

using namespace std;

// ============================================================================
// TODO: Implement your solution here
// ============================================================================
vector<int> topKFrequent(vector<int>& nums, int k) {
    // Your implementation here
    
    return {};
}

// ============================================================================
// Tests - DO NOT MODIFY
// ============================================================================
TEST(TopKFrequent, Example1) {
    vector<int> nums = {1,1,1,2,2,3};
    auto result = topKFrequent(nums, 2);
    sort(result.begin(), result.end());
    vector<int> expected = {1, 2};
    EXPECT_EQ(result, expected);
}

TEST(TopKFrequent, SingleElement) {
    vector<int> nums = {1};
    vector<int> expected = {1};
    EXPECT_EQ(topKFrequent(nums, 1), expected);
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
