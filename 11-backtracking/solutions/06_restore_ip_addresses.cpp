/**
 * Problem: Restore IP Addresses
 * LeetCode #93
 * Difficulty: Medium
 * Pattern: String
 *
 * Return all valid IP addresses from digit string.
 *
 * Example:
 *   Input: s = "25525511135"
 *   Output: ["255.255.11.135","255.255.111.35"]
 */

#include <gtest/gtest.h>
#include <vector>
#include <string>

using namespace std;

// ============================================================================
// TODO: Implement your solution here
// ============================================================================
vector<string> restoreIpAddresses(string s) {
    // Your implementation here
    
    return {};
}

// ============================================================================
// Tests - DO NOT MODIFY
// ============================================================================
TEST(RestoreIP, Example1) {
    auto result = restoreIpAddresses("25525511135");
    EXPECT_EQ(result.size(), 2);
}

TEST(RestoreIP, Example2) {
    auto result = restoreIpAddresses("0000");
    EXPECT_EQ(result.size(), 1);
}

TEST(RestoreIP, TooShort) {
    auto result = restoreIpAddresses("123");
    EXPECT_TRUE(result.empty());
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
