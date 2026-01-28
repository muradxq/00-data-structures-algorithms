/**
 * Problem: Koko Eating Bananas
 * LeetCode #875
 * Difficulty: Medium
 * Pattern: Answer Space Binary Search
 *
 * Find minimum eating speed to finish all bananas in h hours.
 *
 * Example:
 *   Input: piles = [3,6,7,11], h = 8
 *   Output: 4
 */

#include <gtest/gtest.h>
#include <vector>
#include <algorithm>

using namespace std;

// ============================================================================
// TODO: Implement your solution here
// ============================================================================
int minEatingSpeed(vector<int>& piles, int h) {
    // Your implementation here
    // Hint: Binary search on answer space [1, max(piles)]
    int l = 1;
    int r = *max_element(piles.begin(), piles.end());
    while (l < r) {
        int mid = l + (r-l) / 2;
        int hours = 0;
        for (int i=0; i< piles.size(); i++) {
            hours += (piles[i] + mid - 1) / mid;
        }
        if (hours <= h) {
            r = mid;
        } else {
            l = mid+1;
        }
    }
    return l;
}

// ============================================================================
// Tests - DO NOT MODIFY
// ============================================================================
TEST(KokoEatingBananas, Example1) {
    vector<int> piles = {3, 6, 7, 11};
    EXPECT_EQ(minEatingSpeed(piles, 8), 4);
}

TEST(KokoEatingBananas, Example2) {
    vector<int> piles = {30, 11, 23, 4, 20};
    EXPECT_EQ(minEatingSpeed(piles, 5), 30);
}

TEST(KokoEatingBananas, Example3) {
    vector<int> piles = {30, 11, 23, 4, 20};
    EXPECT_EQ(minEatingSpeed(piles, 6), 23);
}

TEST(KokoEatingBananas, SinglePile) {
    vector<int> piles = {10};
    EXPECT_EQ(minEatingSpeed(piles, 5), 2);
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
