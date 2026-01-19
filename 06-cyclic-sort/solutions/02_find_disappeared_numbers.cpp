/**
 * Problem: Find All Numbers Disappeared in an Array
 * LeetCode #448
 * Difficulty: Easy
 * Pattern: Find All Missing
 *
 * Find all missing numbers in range [1, n].
 *
 * Example:
 *   Input: nums = [4,3,2,7,8,2,3,1]
 *   Output: [5,6]
 */

#include <gtest/gtest.h>
#include <vector>

using namespace std;

// ============================================================================
// TODO: Implement your solution here
// ============================================================================
vector<int> findDisappearedNumbers(vector<int>& nums) {
    // Your implementation here
    
    return {};
}

// ============================================================================
// Tests - DO NOT MODIFY
// ============================================================================
TEST(DisappearedNumbers, Example1) {
    vector<int> nums = {4,3,2,7,8,2,3,1};
    vector<int> expected = {5, 6};
    EXPECT_EQ(findDisappearedNumbers(nums), expected);
}

TEST(DisappearedNumbers, Example2) {
    vector<int> nums = {1, 1};
    vector<int> expected = {2};
    EXPECT_EQ(findDisappearedNumbers(nums), expected);
}

TEST(DisappearedNumbers, NoMissing) {
    vector<int> nums = {1, 2, 3};
    vector<int> expected = {};
    EXPECT_EQ(findDisappearedNumbers(nums), expected);
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
