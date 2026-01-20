/**
 * Problem: 4Sum
 * LeetCode #18
 * Difficulty: Medium
 * Pattern: Opposite Direction + 2 Loops
 *
 * Find all unique quadruplets that sum to target.
 *
 * Example:
 *   Input: nums = [1,0,-1,0,-2,2], target = 0
 *   Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
 *
 * Constraints:
 *   - 1 <= nums.length <= 200
 *   - -10^9 <= nums[i] <= 10^9
 *   - -10^9 <= target <= 10^9
 */

#include <gtest/gtest.h>
#include <vector>
#include <algorithm>

using namespace std;

// ============================================================================
// TODO: Implement your solution here
// ============================================================================
vector<vector<int>> fourSum(vector<int>& nums, int target) {
    // Your implementation here
    // Hint: Similar to 3Sum, but with one more outer loop
    std::sort(nums.begin(), nums.end());
    vector<vector<int>> res;
    int n = nums.size();
    for (int i0 = 0; i0 < n - 3; i0++) {
        // Skip duplicates for first element
        if (i0 > 0 && nums[i0] == nums[i0 - 1]) {
            continue;
        }
        for(int i1 = i0 + 1; i1 < n - 2; i1++) {
            // Skip duplicates for second element
            if (i1 > i0 + 1 && nums[i1] == nums[i1 - 1]) {
                continue;
            }
            int l = i1 + 1;
            int r = n - 1;
            while (l < r) {
                long long sum = (long long)nums[i0] + nums[i1] + nums[l] + nums[r];
                
                if (sum == target) {
                    res.push_back({nums[i0], nums[i1], nums[l], nums[r]});
                    // Skip duplicates for left pointer
                    while (l < r && nums[l] == nums[l + 1]) {
                        l++;
                    }
                    // Skip duplicates for right pointer
                    while (l < r && nums[r] == nums[r - 1]) {
                        r--;
                    }
                    l++;
                    r--;
                } else if (sum > target) {
                    r--;
                } else {
                    l++;
                }
            }
        }
    }
    return res;
}

// ============================================================================
// Tests - DO NOT MODIFY
// ============================================================================
TEST(FourSum, Example1) {
    vector<int> nums = {1, 0, -1, 0, -2, 2};
    vector<vector<int>> result = fourSum(nums, 0);
    
    for (auto& v : result) sort(v.begin(), v.end());
    sort(result.begin(), result.end());
    
    vector<vector<int>> expected = {{-2, -1, 1, 2}, {-2, 0, 0, 2}, {-1, 0, 0, 1}};
    EXPECT_EQ(result, expected);
}

TEST(FourSum, Example2) {
    vector<int> nums = {2, 2, 2, 2, 2};
    vector<vector<int>> result = fourSum(nums, 8);
    vector<vector<int>> expected = {{2, 2, 2, 2}};
    EXPECT_EQ(result, expected);
}

TEST(FourSum, NoSolution) {
    vector<int> nums = {1, 2, 3, 4};
    vector<vector<int>> result = fourSum(nums, 100);
    EXPECT_TRUE(result.empty());
}

TEST(FourSum, NegativeTarget) {
    vector<int> nums = {-3, -2, -1, 0, 0, 1, 2, 3};
    vector<vector<int>> result = fourSum(nums, 0);
    
    for (auto& v : result) sort(v.begin(), v.end());
    sort(result.begin(), result.end());
    
    // Multiple valid quadruplets sum to 0
    EXPECT_FALSE(result.empty());
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
