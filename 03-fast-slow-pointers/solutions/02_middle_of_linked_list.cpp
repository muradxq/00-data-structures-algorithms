/**
 * Problem: Middle of the Linked List
 * LeetCode #876
 * Difficulty: Easy
 * Pattern: Find Middle
 *
 * Return the middle node (second middle if two middles).
 *
 * Example:
 *   Input: 1 → 2 → 3 → 4 → 5
 *   Output: Node 3
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
ListNode* middleNode(ListNode* head) {
    // Your implementation here
    
    return nullptr;
}

// ============================================================================
// Tests - DO NOT MODIFY
// ============================================================================
TEST(MiddleOfList, OddLength) {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    EXPECT_EQ(middleNode(head)->val, 3);
}

TEST(MiddleOfList, EvenLength) {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = new ListNode(6);
    EXPECT_EQ(middleNode(head)->val, 4);
}

TEST(MiddleOfList, SingleNode) {
    ListNode* head = new ListNode(1);
    EXPECT_EQ(middleNode(head)->val, 1);
}

TEST(MiddleOfList, TwoNodes) {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    EXPECT_EQ(middleNode(head)->val, 2);
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
