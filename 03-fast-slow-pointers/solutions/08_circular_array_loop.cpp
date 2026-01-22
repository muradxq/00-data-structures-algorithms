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
    int n = nums.size();
    
    // Helper function to get next index
    auto next = [&](int i) {
        return ((i + nums[i]) % n + n) % n;
    };
    
    // Try each starting position
    for (int start = 0; start < n; start++) {
        if (nums[start] == 0) continue;  // Skip if already visited/marked
        
        int slow = start;
        int fast = start;
        int direction = nums[start] > 0 ? 1 : -1;  // Track direction
        
        // Phase 1: Detect cycle using Floyd's algorithm
        do {
            slow = next(slow);
            fast = next(next(fast));
            
            // Check direction consistency
            if ((nums[slow] > 0 ? 1 : -1) != direction ||
                (nums[fast] > 0 ? 1 : -1) != direction) {
                break;  // Direction changed, invalid cycle
            }
        } while (slow != fast);
        
        // Check if we found a valid cycle
        if (slow == fast) {
            // Check if it's not a self-loop (cycle length > 1)
            // If next(slow) == slow, it's a self-loop
            int nextSlow = next(slow);
            if (nextSlow != slow) {
                // Verify all nodes in cycle have same direction
                bool validCycle = true;
                int temp = slow;
                do {
                    if ((nums[temp] > 0 ? 1 : -1) != direction) {
                        validCycle = false;
                        break;
                    }
                    temp = next(temp);
                } while (temp != slow);
                
                if (validCycle) {
                    return true;
                }
            }
        }
        
        // Mark all nodes in this path as visited to avoid rechecking
        int mark = start;
        while (nums[mark] != 0 && (nums[mark] > 0 ? 1 : -1) == direction) {
            int nextMark = next(mark);
            nums[mark] = 0;  // Mark as visited
            mark = nextMark;
        }
    }
    
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
