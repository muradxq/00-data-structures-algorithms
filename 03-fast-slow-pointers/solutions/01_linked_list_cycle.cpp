/**
 * Problem: Linked List Cycle
 * LeetCode #141
 * Difficulty: Easy
 * Pattern: Cycle Detection
 *
 * Determine if linked list has a cycle.
 *
 * Example:
 *   Input: 3 → 2 → 0 → -4 → (back to 2)
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
bool hasCycle(ListNode* head) {
    // Your implementation here
    
    return false;
}

// ============================================================================
// Tests - DO NOT MODIFY
// ============================================================================
TEST(LinkedListCycle, HasCycle) {
    ListNode* head = new ListNode(3);
    head->next = new ListNode(2);
    head->next->next = new ListNode(0);
    head->next->next->next = new ListNode(-4);
    head->next->next->next->next = head->next; // cycle
    EXPECT_TRUE(hasCycle(head));
}

TEST(LinkedListCycle, NoCycle) {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    EXPECT_FALSE(hasCycle(head));
}

TEST(LinkedListCycle, SingleNodeNoCycle) {
    ListNode* head = new ListNode(1);
    EXPECT_FALSE(hasCycle(head));
}

TEST(LinkedListCycle, SingleNodeWithCycle) {
    ListNode* head = new ListNode(1);
    head->next = head;
    EXPECT_TRUE(hasCycle(head));
}

TEST(LinkedListCycle, EmptyList) {
    EXPECT_FALSE(hasCycle(nullptr));
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
