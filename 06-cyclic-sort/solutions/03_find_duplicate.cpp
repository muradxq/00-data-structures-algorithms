/**
 * Problem: Find the Duplicate Number
 * LeetCode #287
 * Difficulty: Medium
 * Pattern: Find Duplicate
 *
 * Array of n+1 integers in [1, n]. Find the one duplicate.
 *
 * Example:
 *   Input: nums = [1,3,4,2,2]
 *   Output: 2
 */

#include <gtest/gtest.h>
#include <vector>

using namespace std;

// ============================================================================
// TODO: Implement your solution here
// ============================================================================
int findDuplicate(vector<int>& nums) {
    // Your implementation here
    // Can use cyclic sort or Floyd's cycle detection
    
    return 0;
}

// ============================================================================
// Tests - DO NOT MODIFY
// ============================================================================
TEST(FindDuplicate, Example1) {
    vector<int> nums = {1, 3, 4, 2, 2};
    EXPECT_EQ(findDuplicate(nums), 2);
}

TEST(FindDuplicate, Example2) {
    vector<int> nums = {3, 1, 3, 4, 2};
    EXPECT_EQ(findDuplicate(nums), 3);
}

TEST(FindDuplicate, AllSame) {
    vector<int> nums = {2, 2, 2, 2, 2};
    EXPECT_EQ(findDuplicate(nums), 2);
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
