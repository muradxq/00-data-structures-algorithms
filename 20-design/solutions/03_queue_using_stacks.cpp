/**
 * Problem: Implement Queue using Stacks
 * LeetCode #232
 * Difficulty: Easy
 * Pattern: Queue
 *
 * Implement FIFO queue using two stacks.
 *
 * Example:
 *   push(1), push(2), peek() -> 1, pop() -> 1, empty() -> false
 */

#include <gtest/gtest.h>
#include <stack>

using namespace std;

// ============================================================================
// TODO: Implement your solution here
// ============================================================================
class MyQueue {
public:
    MyQueue() {
        // Your implementation here
    }
    
    void push(int x) {
        // Your implementation here
    }
    
    int pop() {
        // Your implementation here
        return 0;
    }
    
    int peek() {
        // Your implementation here
        return 0;
    }
    
    bool empty() {
        // Your implementation here
        return true;
    }
    
private:
    // Use two stacks: in_stack and out_stack
};

// ============================================================================
// Tests - DO NOT MODIFY
// ============================================================================
TEST(MyQueue, Example1) {
    MyQueue q;
    q.push(1);
    q.push(2);
    EXPECT_EQ(q.peek(), 1);
    EXPECT_EQ(q.pop(), 1);
    EXPECT_FALSE(q.empty());
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
