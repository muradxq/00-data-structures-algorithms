/**
 * Problem: Capacity To Ship Packages Within D Days
 * LeetCode #1011
 * Difficulty: Medium
 * Pattern: Answer Space Binary Search
 *
 * Find minimum ship capacity to ship all packages in days days.
 *
 * Example:
 *   Input: weights = [1,2,3,4,5,6,7,8,9,10], days = 5
 *   Output: 15
 */

#include <gtest/gtest.h>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

// ============================================================================
// TODO: Implement your solution here
// ============================================================================
int shipWithinDays(vector<int>& weights, int days) {
    // Your implementation here
    // Hint: Binary search on [max(weights), sum(weights)]
    int l = *max_element(weights.begin(), weights.end());
    int r = accumulate(weights.begin(), weights.end(), 0);
    while (l < r) {
        int mid = l + (r - l) / 2;
        
        // Can we ship with capacity mid?
        int daysNeeded = 1;
        int currentLoad = 0;
        for (int w : weights) {
            if (currentLoad + w > mid) {
                daysNeeded++;
                currentLoad = 0;
            }
            currentLoad += w;
        }
        
        if (daysNeeded <= days) {
            r = mid;      // Can do it, try smaller capacity
        } else {
            l = mid + 1;  // Need more capacity
        }
    }
    
    return l;
    return 0;
}

// ============================================================================
// Tests - DO NOT MODIFY
// ============================================================================
TEST(ShipPackages, Example1) {
    vector<int> weights = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    EXPECT_EQ(shipWithinDays(weights, 5), 15);
}

TEST(ShipPackages, Example2) {
    vector<int> weights = {3, 2, 2, 4, 1, 4};
    EXPECT_EQ(shipWithinDays(weights, 3), 6);
}

TEST(ShipPackages, Example3) {
    vector<int> weights = {1, 2, 3, 1, 1};
    EXPECT_EQ(shipWithinDays(weights, 4), 3);
}

TEST(ShipPackages, SingleDay) {
    vector<int> weights = {1, 2, 3};
    EXPECT_EQ(shipWithinDays(weights, 1), 6);
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
