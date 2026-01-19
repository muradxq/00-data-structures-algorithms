/**
 * Problem: Min Stack
 * LeetCode #155
 * Difficulty: Medium
 * Pattern: Stack
 *
 * Stack with O(1) getMin operation.
 *
 * Example:
 *   push(-2), push(0), push(-3), getMin() -> -3
 *   pop(), top() -> 0, getMin() -> -2
 */

#include <gtest/gtest.h>
#include <stack>
#include <climits>

using namespace std;

// ============================================================================
// TODO: Implement your solution here
// ============================================================================
class MinStack {
public:
    MinStack() {
        // Your implementation here
    }
    
    void push(int val) {
        // Your implementation here
    }
    
    void pop() {
        // Your implementation here
    }
    
    int top() {
        // Your implementation here
        return 0;
    }
    
    int getMin() {
        // Your implementation here
        return 0;
    }
    
private:
    // Use two stacks or store pairs
};

// ============================================================================
// Tests - DO NOT MODIFY
// ============================================================================
TEST(MinStack, Example1) {
    MinStack ms;
    ms.push(-2);
    ms.push(0);
    ms.push(-3);
    EXPECT_EQ(ms.getMin(), -3);
    ms.pop();
    EXPECT_EQ(ms.top(), 0);
    EXPECT_EQ(ms.getMin(), -2);
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
