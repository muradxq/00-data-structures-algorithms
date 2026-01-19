/**
 * Problem: Design Circular Queue
 * LeetCode #622
 * Difficulty: Medium
 * Pattern: Queue
 *
 * Design circular queue with fixed size.
 *
 * Example:
 *   MyCircularQueue(3), enQueue(1), enQueue(2), enQueue(3)
 *   enQueue(4) -> false, Rear() -> 3, isFull() -> true
 */

#include <gtest/gtest.h>
#include <vector>

using namespace std;

// ============================================================================
// TODO: Implement your solution here
// ============================================================================
class MyCircularQueue {
public:
    MyCircularQueue(int k) {
        // Your implementation here
    }
    
    bool enQueue(int value) {
        // Your implementation here
        return false;
    }
    
    bool deQueue() {
        // Your implementation here
        return false;
    }
    
    int Front() {
        // Your implementation here
        return -1;
    }
    
    int Rear() {
        // Your implementation here
        return -1;
    }
    
    bool isEmpty() {
        // Your implementation here
        return true;
    }
    
    bool isFull() {
        // Your implementation here
        return false;
    }
    
private:
    // Use array with front/rear pointers
};

// ============================================================================
// Tests - DO NOT MODIFY
// ============================================================================
TEST(CircularQueue, Example1) {
    MyCircularQueue q(3);
    EXPECT_TRUE(q.enQueue(1));
    EXPECT_TRUE(q.enQueue(2));
    EXPECT_TRUE(q.enQueue(3));
    EXPECT_FALSE(q.enQueue(4));
    EXPECT_EQ(q.Rear(), 3);
    EXPECT_TRUE(q.isFull());
    EXPECT_TRUE(q.deQueue());
    EXPECT_TRUE(q.enQueue(4));
    EXPECT_EQ(q.Rear(), 4);
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
