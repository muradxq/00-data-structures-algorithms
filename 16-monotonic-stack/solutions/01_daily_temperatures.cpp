/**
 * Problem: Daily Temperatures
 * LeetCode #739
 * Difficulty: Medium
 * Pattern: Next Greater
 *
 * Days until warmer temperature.
 *
 * Example:
 *   Input: temperatures = [73,74,75,71,69,72,76,73]
 *   Output: [1,1,4,2,1,1,0,0]
 */

#include <gtest/gtest.h>
#include <vector>
#include <stack>

using namespace std;

// ============================================================================
// TODO: Implement your solution here
// ============================================================================
vector<int> dailyTemperatures(vector<int>& temperatures) {
    // Your implementation here
    
    return {};
}

// ============================================================================
// Tests - DO NOT MODIFY
// ============================================================================
TEST(DailyTemperatures, Example1) {
    vector<int> temps = {73,74,75,71,69,72,76,73};
    vector<int> expected = {1,1,4,2,1,1,0,0};
    EXPECT_EQ(dailyTemperatures(temps), expected);
}

TEST(DailyTemperatures, Example2) {
    vector<int> temps = {30,40,50,60};
    vector<int> expected = {1,1,1,0};
    EXPECT_EQ(dailyTemperatures(temps), expected);
}

TEST(DailyTemperatures, Example3) {
    vector<int> temps = {30,60,90};
    vector<int> expected = {1,1,0};
    EXPECT_EQ(dailyTemperatures(temps), expected);
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
