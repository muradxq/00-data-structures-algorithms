/**
 * Problem: Candy
 * LeetCode #135
 * Difficulty: Hard
 * Pattern: Constraints
 *
 * Distribute minimum candies with constraints.
 *
 * Example:
 *   Input: ratings = [1,0,2]
 *   Output: 5 (candies: [2,1,2])
 */

#include <gtest/gtest.h>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

// ============================================================================
// TODO: Implement your solution here
// ============================================================================
int candy(vector<int>& ratings) {
    // Your implementation here
    // Two passes: left-to-right and right-to-left
    
    return 0;
}

// ============================================================================
// Tests - DO NOT MODIFY
// ============================================================================
TEST(Candy, Example1) {
    vector<int> ratings = {1, 0, 2};
    EXPECT_EQ(candy(ratings), 5);
}

TEST(Candy, Example2) {
    vector<int> ratings = {1, 2, 2};
    EXPECT_EQ(candy(ratings), 4);
}

TEST(Candy, AllSame) {
    vector<int> ratings = {1, 1, 1};
    EXPECT_EQ(candy(ratings), 3);
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
