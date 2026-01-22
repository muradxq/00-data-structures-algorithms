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
    if (!head || !head->next) return true;
    
    // [1] Find middle using fast-slow pointers
    ListNode* slow = head;
    ListNode* fast = head;
    
    while (fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    
    // [2] Reverse the second half
    ListNode* prev = nullptr;
    ListNode* curr = slow->next;  // Start of second half
    slow->next = nullptr;  // Break the list
    
    while (curr) {
        ListNode* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    
    // [3] Compare first half and reversed second half
    ListNode* p1 = head;
    ListNode* p2 = prev;  // Head of reversed second half
    
    while (p2) {
        if (p1->val != p2->val)
            return false;
        p1 = p1->next;
        p2 = p2->next;
    }
    
    return true;
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
