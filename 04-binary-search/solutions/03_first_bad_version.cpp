/**
 * Problem: First Bad Version
 * LeetCode #278
 * Difficulty: Easy
 * Pattern: Boundary
 *
 * Find first bad version given isBadVersion(n) API.
 *
 * Example:
 *   Input: n = 5, bad = 4
 *   Versions: [1, 2, 3, 4, 5] → [G, G, G, B, B]
 *   Output: 4
 */

#include <gtest/gtest.h>

using namespace std;

// Global variable to simulate bad version
int badVersion = 0;

bool isBadVersion(int version) {
    return version >= badVersion;
}

// ============================================================================
// TODO: Implement your solution here
// ============================================================================
int firstBadVersion(int n) {
    // Your implementation here
    int l = 1;
    int r = n;

    while(l <= r) {
        int mid = l + (r-l)/2;
        if(isBadVersion(mid)) {
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    return l;
}

// ============================================================================
// Tests - DO NOT MODIFY
// ============================================================================
TEST(FirstBadVersion, Example1) {
    badVersion = 4;
    EXPECT_EQ(firstBadVersion(5), 4);
}

TEST(FirstBadVersion, Example2) {
    badVersion = 1;
    EXPECT_EQ(firstBadVersion(1), 1);
}

TEST(FirstBadVersion, AllBad) {
    badVersion = 1;
    EXPECT_EQ(firstBadVersion(5), 1);
}

TEST(FirstBadVersion, LastBad) {
    badVersion = 5;
    EXPECT_EQ(firstBadVersion(5), 5);
}

TEST(FirstBadVersion, MiddleBad) {
    badVersion = 3;
    EXPECT_EQ(firstBadVersion(5), 3);
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
