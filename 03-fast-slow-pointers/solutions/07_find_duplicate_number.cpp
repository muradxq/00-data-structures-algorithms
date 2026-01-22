/**
 * Problem: Find the Duplicate Number
 * LeetCode #287
 * Difficulty: Medium
 * Pattern: Cycle Detection
 *
 * Array of n+1 integers where each integer is in [1, n]. Find the duplicate.
 * Must not modify array and use O(1) space.
 *
 * Example:
 *   Input: nums = [1,3,4,2,2]
 *   Output: 2
 *
 * Key Insight:
 *   - Treat array as linked list where value points to next index
 *   - nums[i] = j means node i points to node j
 *   - Duplicate creates a cycle!
 *
 * Constraints:
 *   - 1 <= n <= 10^5
 *   - nums.length == n + 1
 *   - 1 <= nums[i] <= n
 */

#include <gtest/gtest.h>
#include <vector>

using namespace std;

// ============================================================================
// TODO: Implement your solution here
// ============================================================================
int findDuplicate(vector<int>& nums) {
    // Phase 1: Find intersection point using Floyd's algorithm
    // Treat array as linked list: nums[i] points to nums[nums[i]]
    int slow = nums[0];
    int fast = nums[0];
    
    // Move slow one step, fast two steps until they meet
    do {
        slow = nums[slow];
        fast = nums[nums[fast]];
    } while (slow != fast);
    
    // Phase 2: Find cycle entrance (the duplicate)
    // Reset slow to start, move both one step at a time
    slow = nums[0];
    while (slow != fast) {
        slow = nums[slow];
        fast = nums[fast];
    }
    
    return slow;
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

TEST(FindDuplicate, DuplicateAtEnd) {
    vector<int> nums = {1, 2, 3, 4, 4};
    EXPECT_EQ(findDuplicate(nums), 4);
}

TEST(FindDuplicate, DuplicateAtStart) {
    vector<int> nums = {1, 1, 2, 3, 4};
    EXPECT_EQ(findDuplicate(nums), 1);
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
