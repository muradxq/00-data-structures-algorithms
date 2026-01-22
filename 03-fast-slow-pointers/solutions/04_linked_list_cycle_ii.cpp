/**
 * Problem: Linked List Cycle II
 * LeetCode #142
 * Difficulty: Medium
 * Pattern: Find Cycle Start
 *
 * Return the node where cycle begins (null if no cycle).
 *
 * Example:
 *   Input: 3 → 2 → 0 → -4 → (back to 2)
 *   Output: Node 2
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
ListNode* detectCycle(ListNode* head) {
    // Your implementation here
    // Hint: First detect cycle, then reset slow to head
    ListNode* slow = head;
    ListNode* fast = head;
    
    // [1] Detect the cycle
    while (fast && fast->next) {
        fast = fast->next->next;
        slow = slow->next;
        if (slow == fast)
            break;
    }
    
    // Check if no cycle exists
    if (!fast || !fast->next)
        return nullptr;
    
    // [2] Reset slow to head and find cycle start
    slow = head;
    while (slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }
    
    return slow;
}

// ============================================================================
// Tests - DO NOT MODIFY
// ============================================================================
TEST(LinkedListCycleII, CycleAtSecond) {
    ListNode* head = new ListNode(3);
    ListNode* cycleStart = new ListNode(2);
    head->next = cycleStart;
    cycleStart->next = new ListNode(0);
    cycleStart->next->next = new ListNode(-4);
    cycleStart->next->next->next = cycleStart;
    EXPECT_EQ(detectCycle(head), cycleStart);
}

TEST(LinkedListCycleII, CycleAtHead) {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = head;
    EXPECT_EQ(detectCycle(head), head);
}

TEST(LinkedListCycleII, NoCycle) {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    EXPECT_EQ(detectCycle(head), nullptr);
}

TEST(LinkedListCycleII, SingleNodeNoCycle) {
    ListNode* head = new ListNode(1);
    EXPECT_EQ(detectCycle(head), nullptr);
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
