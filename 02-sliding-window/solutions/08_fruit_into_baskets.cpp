/**
 * Problem: Fruit Into Baskets
 * LeetCode #904
 * Difficulty: Medium
 * Pattern: Variable Window
 *
 * Find longest subarray with at most 2 distinct elements.
 * (You have 2 baskets, each can hold one type of fruit)
 *
 * Example:
 *   Input: fruits = [1,2,3,2,2]
 *   Output: 4 (subarray [2,3,2,2])
 *
 *   Input: fruits = [0,1,2,2]
 *   Output: 3 (subarray [1,2,2])
 *
 * Approach:
 *   - Variable sliding window
 *   - Shrink when more than 2 distinct fruits in window
 *   - Track count of each fruit type using hashmap
 *
 * Constraints:
 *   - 1 <= fruits.length <= 10^5
 *   - 0 <= fruits[i] < fruits.length
 */

#include <gtest/gtest.h>
#include <vector>
#include <unordered_map>

using namespace std;

// ============================================================================
// TODO: Implement your solution here
// ============================================================================
int totalFruit(vector<int>& fruits) {
    // Your implementation here
    // Use hashmap to track fruit counts
    // Shrink window when more than 2 types
    
    return 0;
}

// ============================================================================
// Tests - DO NOT MODIFY
// ============================================================================
TEST(FruitIntoBaskets, Example1) {
    vector<int> fruits = {1, 2, 1};
    EXPECT_EQ(totalFruit(fruits), 3);
}

TEST(FruitIntoBaskets, Example2) {
    vector<int> fruits = {0, 1, 2, 2};
    EXPECT_EQ(totalFruit(fruits), 3);
}

TEST(FruitIntoBaskets, Example3) {
    vector<int> fruits = {1, 2, 3, 2, 2};
    EXPECT_EQ(totalFruit(fruits), 4);
}

TEST(FruitIntoBaskets, SingleType) {
    vector<int> fruits = {1, 1, 1, 1};
    EXPECT_EQ(totalFruit(fruits), 4);
}

TEST(FruitIntoBaskets, TwoTypes) {
    vector<int> fruits = {1, 2, 1, 2, 1, 2};
    EXPECT_EQ(totalFruit(fruits), 6);
}

TEST(FruitIntoBaskets, ManyTypes) {
    vector<int> fruits = {3, 3, 3, 1, 2, 1, 1, 2, 3, 3, 4};
    EXPECT_EQ(totalFruit(fruits), 5);
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
