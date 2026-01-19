/**
 * Problem: Palindrome Linked List
 * LeetCode #234
 * Difficulty: Medium
 * Pattern: Middle + Reverse
 *
 * Check if linked list is a palindrome.
 *
 * Example:
 *   Input: 1 → 2 → 2 → 1
 *   Output: true
 */

#include <gtest/gtest.h>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// ============================================================================
// TODO: Implement your solution here
// ============================================================================
bool isPalindrome(ListNode* head) {
    // Your implementation here
    // Hint: Find middle, reverse second half, compare
    
    return false;
}

// ============================================================================
// Tests - DO NOT MODIFY
// ============================================================================
TEST(PalindromeList, Example1) {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(1);
    EXPECT_TRUE(isPalindrome(head));
}

TEST(PalindromeList, Example2) {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    EXPECT_FALSE(isPalindrome(head));
}

TEST(PalindromeList, SingleNode) {
    ListNode* head = new ListNode(1);
    EXPECT_TRUE(isPalindrome(head));
}

TEST(PalindromeList, OddLength) {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(1);
    EXPECT_TRUE(isPalindrome(head));
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
