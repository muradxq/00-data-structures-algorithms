/**
 * Problem: Find Median from Data Stream
 * LeetCode #295
 * Difficulty: Hard
 * Pattern: Two Heaps
 *
 * Design data structure to find median efficiently.
 *
 * Example:
 *   addNum(1), addNum(2), findMedian() -> 1.5
 *   addNum(3), findMedian() -> 2.0
 */

#include <gtest/gtest.h>
#include <queue>

using namespace std;

// ============================================================================
// TODO: Implement your solution here
// ============================================================================
class MedianFinder {
public:
    MedianFinder() {
        // Your implementation here
    }
    
    void addNum(int num) {
        // Your implementation here
    }
    
    double findMedian() {
        // Your implementation here
        return 0.0;
    }
    
private:
    // Use two heaps: max-heap for left half, min-heap for right half
};

// ============================================================================
// Tests - DO NOT MODIFY
// ============================================================================
TEST(MedianFinder, Example1) {
    MedianFinder mf;
    mf.addNum(1);
    mf.addNum(2);
    EXPECT_DOUBLE_EQ(mf.findMedian(), 1.5);
    mf.addNum(3);
    EXPECT_DOUBLE_EQ(mf.findMedian(), 2.0);
}

TEST(MedianFinder, SingleElement) {
    MedianFinder mf;
    mf.addNum(5);
    EXPECT_DOUBLE_EQ(mf.findMedian(), 5.0);
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
