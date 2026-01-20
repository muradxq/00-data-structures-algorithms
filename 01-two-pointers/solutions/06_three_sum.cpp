/**
 * Problem: 3Sum
 * LeetCode #15
 * Difficulty: Medium
 * Pattern: Opposite Direction + Loop
 *
 * Find all unique triplets that sum to zero.
 *
 * Example:
 *   Input: nums = [-1,0,1,2,-1,-4]
 *   Output: [[-1,-1,2],[-1,0,1]]
 *
 * Constraints:
 *   - 3 <= nums.length <= 3000
 *   - -10^5 <= nums[i] <= 10^5
 */

#include <gtest/gtest.h>
#include <vector>
#include <algorithm>

using namespace std;

// ============================================================================
// TODO: Implement your solution here
// ============================================================================
vector<vector<int>> threeSum(vector<int>& nums) {
    // Your implementation here
    // Hint: Sort first, then fix one element and use two pointers for the rest
    std::sort(nums.begin(), nums.end());
    vector<vector<int>> res;
    for (int i=0; i < nums.size(); i++) {
        if (nums[i] > 0) break;
        int l = i+1;
        int r = nums.size()-1;        // Skip duplicates for first element
        if (i > 0 && nums[i] == nums[i - 1]) {
            continue;
        }
        while(l<r) {
            int sum = nums[i] + nums[l] + nums[r];
            if (sum == 0) {
                res.push_back({nums[i], nums[l], nums[r]});
                while(l<r && nums[r]==nums[r-1]) 
                    r--;
                while(l<r && nums[l]==nums[l+1]) 
                    l++;
                l++;
                r--;
            } else if (sum > 0) {
                r--;
            } else {
                l++;
            }
        }
    }
    return res;
}

// ============================================================================
// Tests - DO NOT MODIFY
// ============================================================================
TEST(ThreeSum, Example1) {
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> result = threeSum(nums);
    
    // Sort results for comparison
    for (auto& v : result) sort(v.begin(), v.end());
    sort(result.begin(), result.end());
    
    vector<vector<int>> expected = {{-1, -1, 2}, {-1, 0, 1}};
    EXPECT_EQ(result, expected);
}

TEST(ThreeSum, Example2) {
    vector<int> nums = {0, 1, 1};
    vector<vector<int>> result = threeSum(nums);
    EXPECT_TRUE(result.empty());
}

TEST(ThreeSum, Example3) {
    vector<int> nums = {0, 0, 0};
    vector<vector<int>> result = threeSum(nums);
    vector<vector<int>> expected = {{0, 0, 0}};
    EXPECT_EQ(result, expected);
}

TEST(ThreeSum, NoDuplicates) {
    vector<int> nums = {-2, 0, 1, 1, 2};
    vector<vector<int>> result = threeSum(nums);
    
    for (auto& v : result) sort(v.begin(), v.end());
    sort(result.begin(), result.end());
    
    vector<vector<int>> expected = {{-2, 0, 2}, {-2, 1, 1}};
    EXPECT_EQ(result, expected);
}

TEST(ThreeSum, AllZeroes) {
    vector<int> nums = {0, 0, 0, 0};
    vector<vector<int>> result = threeSum(nums);
    EXPECT_EQ(result.size(), 1);
    EXPECT_EQ(result[0], (vector<int>{0, 0, 0}));
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
