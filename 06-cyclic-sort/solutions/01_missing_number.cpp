/**
 * Problem: Missing Number
 * LeetCode #268
 * Difficulty: Easy
 * Pattern: Find Missing
 *
 * Find missing number in array of [0, n].
 *
 * Example:
 *   Input: nums = [3,0,1]
 *   Output: 2
 */

#include <gtest/gtest.h>
#include <vector>

using namespace std;

// ============================================================================
// TODO: Implement your solution here
// ============================================================================
int missingNumber(vector<int>& nums) {
    // Your implementation here
    // Can use cyclic sort or XOR approach
    int i = 0;
    int n = nums.size();
    while (i < n) {
        int correctIdx = nums[i];
        if(correctIdx < n && nums[i] != nums[correctIdx]) {
            swap(nums[i], nums[correctIdx]);
        } else {
            i++;
        }
    }
    for (int i =0; i < n; i++) {
        if(nums[i] != i) 
            return i;
    }
    
    return n;
}

// ============================================================================
// Tests - DO NOT MODIFY
// ============================================================================
TEST(MissingNumber, Example1) {
    vector<int> nums = {3, 0, 1};
    EXPECT_EQ(missingNumber(nums), 2);
}

TEST(MissingNumber, Example2) {
    vector<int> nums = {0, 1};
    EXPECT_EQ(missingNumber(nums), 2);
}

TEST(MissingNumber, Example3) {
    vector<int> nums = {9,6,4,2,3,5,7,0,1};
    EXPECT_EQ(missingNumber(nums), 8);
}

TEST(MissingNumber, MissingZero) {
    vector<int> nums = {1};
    EXPECT_EQ(missingNumber(nums), 0);
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
