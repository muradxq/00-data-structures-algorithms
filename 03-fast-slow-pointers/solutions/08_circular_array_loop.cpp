/**
 * Problem: Circular Array Loop
 * LeetCode #457
 * Difficulty: Medium
 * Pattern: Cycle Detection
 *
 * Determine if array has a cycle of length > 1 in same direction.
 * - Positive values move forward, negative move backward
 * - Cycle must be in same direction (all positive or all negative)
 * - Cycle length must be > 1 (self-loops don't count)
 *
 * Example:
 *   Input: nums = [2,-1,1,2,2]
 *   Output: true
 *   Explanation: Cycle at indices 0 → 2 → 3 → 0
 *
 *   Input: nums = [-1,2]
 *   Output: false
 *   Explanation: Movement from index 1 → 1 is a single element cycle
 *
 * Approach:
 *   - For each starting position, use fast/slow pointers
 *   - Check direction consistency throughout the cycle
 *   - Mark visited nodes to avoid rechecking
 *
 * Constraints:
 *   - 1 <= nums.length <= 5000
 *   - -1000 <= nums[i] <= 1000
 *   - nums[i] != 0
 */

#include <gtest/gtest.h>
#include <vector>

using namespace std;

// ============================================================================
// TODO: Implement your solution here
// ============================================================================
bool circularArrayLoop(vector<int>& nums) {
    // Your implementation here
    // Key: Check direction consistency and cycle length > 1
    
    return false;
}

// ============================================================================
// Tests - DO NOT MODIFY
// ============================================================================
TEST(CircularArrayLoop, Example1) {
    vector<int> nums = {2, -1, 1, 2, 2};
    EXPECT_TRUE(circularArrayLoop(nums));
}

TEST(CircularArrayLoop, Example2) {
    vector<int> nums = {-1, 2};
    EXPECT_FALSE(circularArrayLoop(nums));
}

TEST(CircularArrayLoop, Example3) {
    vector<int> nums = {-2, 1, -1, -2, -2};
    EXPECT_FALSE(circularArrayLoop(nums));
}

TEST(CircularArrayLoop, SingleElementLoop) {
    vector<int> nums = {1, 1};
    EXPECT_TRUE(circularArrayLoop(nums));
}

TEST(CircularArrayLoop, AllForward) {
    vector<int> nums = {1, 1, 1, 1};
    EXPECT_TRUE(circularArrayLoop(nums));
}

TEST(CircularArrayLoop, MixedDirectionNoCycle) {
    vector<int> nums = {1, -1, 1, -1};
    EXPECT_FALSE(circularArrayLoop(nums));
}

TEST(CircularArrayLoop, SelfLoop) {
    vector<int> nums = {-1, -1, -1};
    EXPECT_FALSE(circularArrayLoop(nums));
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
