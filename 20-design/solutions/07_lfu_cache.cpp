/**
 * Problem: LFU Cache
 * LeetCode #460
 * Difficulty: Hard
 * Pattern: Cache
 *
 * Least Frequently Used cache with O(1) operations.
 *
 * Example:
 *   LFUCache(2), put(1,1), put(2,2), get(1) -> 1
 *   put(3,3), get(2) -> -1 (evicted, freq 1 < freq of key 1)
 */

#include <gtest/gtest.h>
#include <unordered_map>
#include <list>
#include <climits>

using namespace std;

// ============================================================================
// TODO: Implement your solution here
// ============================================================================
class LFUCache {
public:
    LFUCache(int capacity) {
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
    // Track frequency, min frequency, and LRU within same frequency
};

// ============================================================================
// Tests - DO NOT MODIFY
// ============================================================================
TEST(LFUCache, Example1) {
    LFUCache cache(2);
    cache.put(1, 1);
    cache.put(2, 2);
    EXPECT_EQ(cache.get(1), 1);
    cache.put(3, 3);  // Evicts key 2 (freq 1 < freq of key 1)
    EXPECT_EQ(cache.get(2), -1);
    EXPECT_EQ(cache.get(3), 3);
    cache.put(4, 4);  // Evicts key 3 (both freq 1, key 3 is LRU)
    EXPECT_EQ(cache.get(1), 1);
    EXPECT_EQ(cache.get(3), -1);
    EXPECT_EQ(cache.get(4), 4);
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
