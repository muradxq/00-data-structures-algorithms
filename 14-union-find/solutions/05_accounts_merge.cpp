/**
 * Problem: Accounts Merge
 * LeetCode #721
 * Difficulty: Medium
 * Pattern: Grouping
 *
 * Merge accounts with common emails.
 *
 * Example:
 *   Input: accounts = [["John","johnsmith@mail.com","john_newyork@mail.com"],
 *                      ["John","johnsmith@mail.com","john00@mail.com"],
 *                      ["Mary","mary@mail.com"]]
 *   Output: [["John","john00@mail.com","john_newyork@mail.com","johnsmith@mail.com"],
 *            ["Mary","mary@mail.com"]]
 */

#include <gtest/gtest.h>
#include <vector>
#include <string>
#include <unordered_map>
#include <set>
#include <algorithm>

using namespace std;

// ============================================================================
// TODO: Implement your solution here
// ============================================================================
vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
    // Your implementation here
    // Use Union Find to group emails
    
    return {};
}

// ============================================================================
// Tests - DO NOT MODIFY
// ============================================================================
TEST(AccountsMerge, Example1) {
    vector<vector<string>> accounts = {
        {"John", "johnsmith@mail.com", "john_newyork@mail.com"},
        {"John", "johnsmith@mail.com", "john00@mail.com"},
        {"Mary", "mary@mail.com"},
        {"John", "johnnybravo@mail.com"}
    };
    auto result = accountsMerge(accounts);
    EXPECT_EQ(result.size(), 3);
}

TEST(AccountsMerge, NoMerge) {
    vector<vector<string>> accounts = {
        {"John", "a@mail.com"},
        {"Mary", "b@mail.com"}
    };
    auto result = accountsMerge(accounts);
    EXPECT_EQ(result.size(), 2);
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
