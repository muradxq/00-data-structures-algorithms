/**
 * Problem: Gas Station
 * LeetCode #134
 * Difficulty: Medium
 * Pattern: Circular
 *
 * Find starting gas station to complete circuit.
 *
 * Example:
 *   Input: gas = [1,2,3,4,5], cost = [3,4,5,1,2]
 *   Output: 3
 */

#include <gtest/gtest.h>
#include <vector>
#include <numeric>

using namespace std;

// ============================================================================
// TODO: Implement your solution here
// ============================================================================
int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    // Your implementation here
    // If total gas >= total cost, solution exists
    
    return -1;
}

// ============================================================================
// Tests - DO NOT MODIFY
// ============================================================================
TEST(GasStation, Example1) {
    vector<int> gas = {1, 2, 3, 4, 5};
    vector<int> cost = {3, 4, 5, 1, 2};
    EXPECT_EQ(canCompleteCircuit(gas, cost), 3);
}

TEST(GasStation, Impossible) {
    vector<int> gas = {2, 3, 4};
    vector<int> cost = {3, 4, 3};
    EXPECT_EQ(canCompleteCircuit(gas, cost), -1);
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
