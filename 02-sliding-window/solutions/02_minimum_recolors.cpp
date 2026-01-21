/**
 * Problem: Minimum Recolors to Get K Consecutive Black Blocks
 * LeetCode #2379
 * Difficulty: Easy
 * Pattern: Fixed Window
 *
 * Find minimum recolors needed to get k consecutive 'B' blocks.
 *
 * Example:
 *   Input: blocks = "WBBWWBBWBW", k = 7
 *   Output: 3
 *   Explanation: Recolor 3 'W' blocks to get "WBBBBBBBWW"
 *
 * Approach:
 *   - Fixed window of size k
 *   - Count 'W' in each window (minimum 'W' = minimum recolors needed)
 *
 * Constraints:
 *   - n == blocks.length
 *   - 1 <= n <= 100
 *   - blocks[i] is 'W' or 'B'
 *   - 1 <= k <= n
 */

#include <gtest/gtest.h>
#include <string>
#include <algorithm>

using namespace std;

// ============================================================================
// TODO: Implement your solution here
// ============================================================================
int minimumRecolors(string blocks, int k) {
    // Your implementation here
    // Count 'W' in first window, then slide and track minimum
    //[1] first window
    int numW = 0;
    for (int i =0; i <k; i++) {
        if (blocks[i] == 'W') 
            numW++;
    }
    int minNum = numW;
    for (int i = k; i< blocks.size(); i++) {
        if (blocks[i] == 'W')
            numW++;
        if (blocks[i-k] == 'W')
            numW--;
        minNum =min(minNum, numW);
    }
    return minNum;
}

// ============================================================================
// Tests - DO NOT MODIFY
// ============================================================================
TEST(MinimumRecolors, Example1) {
    EXPECT_EQ(minimumRecolors("WBBWWBBWBW", 7), 3);
}

TEST(MinimumRecolors, Example2) {
    EXPECT_EQ(minimumRecolors("WBWBBBW", 2), 0);
}

TEST(MinimumRecolors, AllWhite) {
    EXPECT_EQ(minimumRecolors("WWWW", 3), 3);
}

TEST(MinimumRecolors, AllBlack) {
    EXPECT_EQ(minimumRecolors("BBBB", 2), 0);
}

TEST(MinimumRecolors, SingleChar) {
    EXPECT_EQ(minimumRecolors("W", 1), 1);
    EXPECT_EQ(minimumRecolors("B", 1), 0);
}

TEST(MinimumRecolors, FullLength) {
    EXPECT_EQ(minimumRecolors("WBWB", 4), 2);
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
