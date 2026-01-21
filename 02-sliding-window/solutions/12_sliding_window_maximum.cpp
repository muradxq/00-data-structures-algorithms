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
/*
================================================================================
COMPREHENSIVE EXAMPLE: ALL TRICKS DEMONSTRATED
================================================================================

nums = [9, 7, 5, 3, 1, 8, 6, 4, 2], k = 4

Tricks shown:
  1. Removing smaller elements from BACK
  2. Removing outdated indices from FRONT
  3. Elements staying in deque
  4. New max clearing entire deque

================================================================================

r=3: nums[3]= 3  Window[0,3] = [9, 7, 5, 3]
  → Deque: [0, 1, 2, 3] → values [9, 7, 5, 3]
  → Max = nums[0] = 9  ✓ Result: [9]

r=4: nums[4]= 1  Window[1,4] = [7, 5, 3, 1]
  → Remove OUTDATED from front: [0] (outside window)
  → Deque: [1, 2, 3, 4] → values [7, 5, 3, 1]
  → Max = nums[1] = 7  ✓ Result: [9, 7]

r=5: nums[5]= 8  Window[2,5] = [5, 3, 1, 8]
  → Remove OUTDATED from front: [1] (outside window)
  → Remove SMALLER from back: [4, 3, 2] (values [1, 3, 5] < 8)
  → Deque: [5] → values [8]
  → Max = nums[5] = 8  ✓ Result: [9, 7, 8]

r=6: nums[6]= 6  Window[3,6] = [3, 1, 8, 6]
  → Deque: [5, 6] → values [8, 6]
  → Max = nums[5] = 8  ✓ Result: [9, 7, 8, 8]

r=7: nums[7]= 4  Window[4,7] = [1, 8, 6, 4]
  → Deque: [5, 6, 7] → values [8, 6, 4]
  → Max = nums[5] = 8  ✓ Result: [9, 7, 8, 8, 8]

r=8: nums[8]= 2  Window[5,8] = [8, 6, 4, 2]
  → Deque: [5, 6, 7, 8] → values [8, 6, 4, 2]
  → Max = nums[5] = 8  ✓ Result: [9, 7, 8, 8, 8, 8]

================================================================================
FINAL RESULT: [9, 7, 8, 8, 8, 8]
================================================================================

KEY INSIGHTS:
--------------------------------------------------------------------------------
TRICK 1: Remove smaller from BACK
  At r=5: nums[5]=8 removes [4,3,2,1] because 1,3,5,7 < 8
  → These can NEVER be max while 8 exists in window

TRICK 2: Remove outdated from FRONT
  At r=4: Window is [1,4], so index 0 (outside [1,4]) is removed
  → Check: dq[0] < r-k+1  →  0 < 4-4+1  →  0 < 1  ✓

TRICK 3: Elements stay when they're still candidates
  At r=6: nums[6]=6, but 8 stays because 8 > 6
  → 8 is still the max even though 6 is newer

TRICK 4: New max clears entire deque
  At r=5: nums[5]=8 clears [4,3,2,1,0] because all < 8
  → New max becomes the only candidate
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
    // solutions:
    // two loops: O(n*k) 
    // one loop + max-heap: O(n*log(k)) -> how to remove left-most num when the windows slide?
    // one loop + maxVal: O(n) -> how to know the next largest value
    deque<int> dq;  // Store indices
    vector<int> result;
    
    for (int r = 0; r < nums.size(); r++) {
        // 1. Remove indices outside current window
        while (!dq.empty() && dq.front() < r - k + 1) {
            dq.pop_front();
        }
        
        // 2. Remove indices with smaller values (from back)
        while (!dq.empty() && nums[dq.back()] < nums[r]) {
            dq.pop_back();
        }
        
        // 3. Add current index
        dq.push_back(r);
        
        // 4. If window is complete, add max to result
        if (r >= k - 1) {
            result.push_back(nums[dq.front()]);
        }
    }
    
    return result;
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
