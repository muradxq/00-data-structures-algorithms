/**
 * Problem: 3Sum Closest
 * LeetCode #16
 * Difficulty: Medium
 * Pattern: Opposite Direction + Loop
 *
 * Find triplet with sum closest to target. Return the sum.
 *
 * Example:
 *   Input: nums = [-1,2,1,-4], target = 1
 *   Output: 2
 *   Explanation: The sum that is closest to target is 2 (-1 + 2 + 1 = 2)
 *
 * Constraints:
 *   - 3 <= nums.length <= 500
 *   - -1000 <= nums[i] <= 1000
 *   - -10^4 <= target <= 10^4
 */

#include <gtest/gtest.h>
#include <vector>
#include <climits>

using namespace std;

// ============================================================================
// TODO: Implement your solution here
// ============================================================================
int threeSumClosest(vector<int>& nums, int target) {
    // Your implementation here
    std::sort(nums.begin(), nums.end());
    int closest = nums[0] + nums[1] + nums[2];

    for (int i = 0; i < nums.size(); i++) {
        int l = i + 1;
        int r = nums.size()-1;
        while (l < r) {
            int sum = nums[i] + nums[l] + nums[r];
            
            if (abs(sum - target) < abs(closest - target)) {
                closest = sum;
            }
            
            if (sum == target) {
                return target;
            } else if (sum > target) {
                r--;
            } else {
                l++;
            }
        }
    }
    return closest;
}

// ============================================================================
// Tests - DO NOT MODIFY
// ============================================================================
TEST(ThreeSumClosest, Example1) {
    vector<int> nums = {-1, 2, 1, -4};
    EXPECT_EQ(threeSumClosest(nums, 1), 2);
}

TEST(ThreeSumClosest, Example2) {
    vector<int> nums = {0, 0, 0};
    EXPECT_EQ(threeSumClosest(nums, 1), 0);
}

TEST(ThreeSumClosest, ExactMatch) {
    vector<int> nums = {1, 1, 1, 1};
    EXPECT_EQ(threeSumClosest(nums, 3), 3);
}

TEST(ThreeSumClosest, NegativeTarget) {
    vector<int> nums = {-3, -2, -5, 3, -4};
    EXPECT_EQ(threeSumClosest(nums, -1), -2);
}

TEST(ThreeSumClosest, LargerArray) {
    vector<int> nums = {1, 2, 3, 4, 5, 6};
    EXPECT_EQ(threeSumClosest(nums, 10), 10);
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
