/**
 * Problem: LRU Cache
 * LeetCode #146
 * Difficulty: Medium
 * Pattern: Cache
 *
 * Least Recently Used cache with O(1) operations.
 *
 * Example:
 *   LRUCache(2), put(1,1), put(2,2), get(1) -> 1
 *   put(3,3), get(2) -> -1 (evicted)
 */

#include <gtest/gtest.h>
#include <unordered_map>
#include <list>

using namespace std;

// ============================================================================
// TODO: Implement your solution here
// ============================================================================
class LRUCache {
public:
    LRUCache(int capacity) {
        // Your implementation here
    }
    
    int get(int key) {
        // Your implementation here
        return -1;
    }
    
    void put(int key, int value) {
        // Your implementation here
    }
    
private:
    // Use HashMap + Doubly Linked List
};

// ============================================================================
// Tests - DO NOT MODIFY
// ============================================================================
TEST(LRUCache, Example1) {
    LRUCache cache(2);
    cache.put(1, 1);
    cache.put(2, 2);
    EXPECT_EQ(cache.get(1), 1);
    cache.put(3, 3);  // Evicts key 2
    EXPECT_EQ(cache.get(2), -1);
    cache.put(4, 4);  // Evicts key 1
    EXPECT_EQ(cache.get(1), -1);
    EXPECT_EQ(cache.get(3), 3);
    EXPECT_EQ(cache.get(4), 4);
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
