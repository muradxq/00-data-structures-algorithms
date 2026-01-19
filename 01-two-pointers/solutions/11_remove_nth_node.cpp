/**
 * Problem: Remove Nth Node From End of List
 * LeetCode #19
 * Difficulty: Medium
 * Pattern: Two Pointers (Fast-Slow with Gap)
 *
 * Remove the nth node from the end of a linked list and return its head.
 *
 * Example:
 *   Input: head = [1,2,3,4,5], n = 2
 *   Output: [1,2,3,5]
 *   Explanation: Remove the 2nd node from end (value 4)
 *
 * Approach:
 *   - Use two pointers with a gap of n nodes
 *   - Move fast pointer n steps ahead first
 *   - Then move both pointers until fast reaches end
 *   - Slow pointer will be at the node before the one to remove
 *
 * Constraints:
 *   - 1 <= sz <= 30
 *   - 0 <= Node.val <= 100
 *   - 1 <= n <= sz
 */

#include <gtest/gtest.h>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

// ============================================================================
// TODO: Implement your solution here
// ============================================================================
ListNode* removeNthFromEnd(ListNode* head, int n) {
    // Your implementation here
    // Hint: Use dummy node to handle edge case of removing head
    // Move fast pointer n steps ahead, then move both until fast->next is null
    
    return nullptr;
}

// ============================================================================
// Helper functions for tests
// ============================================================================
ListNode* createList(vector<int>& vals) {
    if (vals.empty()) return nullptr;
    ListNode* head = new ListNode(vals[0]);
    ListNode* curr = head;
    for (int i = 1; i < vals.size(); i++) {
        curr->next = new ListNode(vals[i]);
        curr = curr->next;
    }
    return head;
}

vector<int> toVector(ListNode* head) {
    vector<int> result;
    while (head) {
        result.push_back(head->val);
        head = head->next;
    }
    return result;
}

// ============================================================================
// Tests - DO NOT MODIFY
// ============================================================================
TEST(RemoveNthNode, Example1) {
    vector<int> vals = {1, 2, 3, 4, 5};
    ListNode* head = createList(vals);
    ListNode* result = removeNthFromEnd(head, 2);
    vector<int> expected = {1, 2, 3, 5};
    EXPECT_EQ(toVector(result), expected);
}

TEST(RemoveNthNode, Example2) {
    vector<int> vals = {1};
    ListNode* head = createList(vals);
    ListNode* result = removeNthFromEnd(head, 1);
    vector<int> expected = {};
    EXPECT_EQ(toVector(result), expected);
}

TEST(RemoveNthNode, Example3) {
    vector<int> vals = {1, 2};
    ListNode* head = createList(vals);
    ListNode* result = removeNthFromEnd(head, 1);
    vector<int> expected = {1};
    EXPECT_EQ(toVector(result), expected);
}

TEST(RemoveNthNode, RemoveHead) {
    vector<int> vals = {1, 2};
    ListNode* head = createList(vals);
    ListNode* result = removeNthFromEnd(head, 2);
    vector<int> expected = {2};
    EXPECT_EQ(toVector(result), expected);
}

TEST(RemoveNthNode, RemoveMiddle) {
    vector<int> vals = {1, 2, 3};
    ListNode* head = createList(vals);
    ListNode* result = removeNthFromEnd(head, 2);
    vector<int> expected = {1, 3};
    EXPECT_EQ(toVector(result), expected);
}

TEST(RemoveNthNode, LongerList) {
    vector<int> vals = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    ListNode* head = createList(vals);
    ListNode* result = removeNthFromEnd(head, 5);
    vector<int> expected = {1, 2, 3, 4, 5, 7, 8, 9, 10};
    EXPECT_EQ(toVector(result), expected);
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
