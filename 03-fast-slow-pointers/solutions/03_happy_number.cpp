/**
 * Problem: Happy Number
 * LeetCode #202
 * Difficulty: Easy
 * Pattern: Cycle in Numbers
 *
 * Check if a number is happy (sum of squares of digits eventually reaches 1).
 *
 * Example:
 *   Input: n = 19
 *   Output: true (19 → 82 → 68 → 100 → 1)
 */

#include <gtest/gtest.h>

using namespace std;

// ============================================================================
// TODO: Implement your solution here
// ============================================================================
int getNext(int n) {
    int next = 0;
    while (n) {
        int f = n % 10;
        next += f * f;
        n = n /10;
    }
    return next;
}
bool isHappy(int n) {
    // Your implementation here
    int slow = n;
    int fast = n;
    while (fast != 1) {
        slow = getNext(slow);
        fast = getNext(getNext(fast));
        if (fast == slow)
            break;
    }
    
    return fast == 1;
}

// ============================================================================
// Tests - DO NOT MODIFY
// ============================================================================
TEST(HappyNumber, Example1) {
    EXPECT_TRUE(isHappy(19));
}

TEST(HappyNumber, Example2) {
    EXPECT_FALSE(isHappy(2));
}

TEST(HappyNumber, One) {
    EXPECT_TRUE(isHappy(1));
}

TEST(HappyNumber, Seven) {
    EXPECT_TRUE(isHappy(7));
}

TEST(HappyNumber, Four) {
    EXPECT_FALSE(isHappy(4));
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
