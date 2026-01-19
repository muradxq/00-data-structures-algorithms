/**
 * Problem: Design HashMap
 * LeetCode #706
 * Difficulty: Easy
 * Pattern: Hash
 *
 * Design HashMap without built-in hash table libraries.
 *
 * Example:
 *   put(1, 1), put(2, 2), get(1) -> 1
 *   get(3) -> -1, put(2, 1), get(2) -> 1
 */

#include <gtest/gtest.h>
#include <vector>
#include <list>

using namespace std;

// ============================================================================
// TODO: Implement your solution here
// ============================================================================
class MyHashMap {
public:
    MyHashMap() {
        // Your implementation here
    }
    
    void put(int key, int value) {
        // Your implementation here
    }
    
    int get(int key) {
        // Your implementation here
        return -1;
    }
    
    void remove(int key) {
        // Your implementation here
    }
    
private:
    // Use array of buckets with chaining
};

// ============================================================================
// Tests - DO NOT MODIFY
// ============================================================================
TEST(MyHashMap, Example1) {
    MyHashMap map;
    map.put(1, 1);
    map.put(2, 2);
    EXPECT_EQ(map.get(1), 1);
    EXPECT_EQ(map.get(3), -1);
    map.put(2, 1);
    EXPECT_EQ(map.get(2), 1);
    map.remove(2);
    EXPECT_EQ(map.get(2), -1);
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
