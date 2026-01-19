/**
 * Problem: Reorder List
 * LeetCode #143
 * Difficulty: Medium
 * Pattern: Middle + Reverse
 *
 * Reorder list: L0 → L1 → ... → Ln-1 → Ln
 * becomes: L0 → Ln → L1 → Ln-1 → L2 → Ln-2 → ...
 *
 * Example:
 *   Input: 1 → 2 → 3 → 4
 *   Output: 1 → 4 → 2 → 3
 *
 *   Input: 1 → 2 → 3 → 4 → 5
 *   Output: 1 → 5 → 2 → 4 → 3
 *
 * Approach:
 *   1. Find middle using fast/slow pointers
 *   2. Reverse second half
 *   3. Merge two halves alternately
 *
 * Constraints:
 *   - 1 <= nodes <= 5 * 10^4
 *   - 1 <= Node.val <= 1000
 */

#include <gtest/gtest.h>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
};

// ============================================================================
// TODO: Implement your solution here
// ============================================================================
void reorderList(ListNode* head) {
    // Your implementation here
    // Step 1: Find middle
    // Step 2: Reverse second half
    // Step 3: Merge alternately
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
TEST(ReorderList, Example1) {
    vector<int> vals = {1, 2, 3, 4};
    ListNode* head = createList(vals);
    reorderList(head);
    vector<int> expected = {1, 4, 2, 3};
    EXPECT_EQ(toVector(head), expected);
}

TEST(ReorderList, Example2) {
    vector<int> vals = {1, 2, 3, 4, 5};
    ListNode* head = createList(vals);
    reorderList(head);
    vector<int> expected = {1, 5, 2, 4, 3};
    EXPECT_EQ(toVector(head), expected);
}

TEST(ReorderList, SingleNode) {
    vector<int> vals = {1};
    ListNode* head = createList(vals);
    reorderList(head);
    vector<int> expected = {1};
    EXPECT_EQ(toVector(head), expected);
}

TEST(ReorderList, TwoNodes) {
    vector<int> vals = {1, 2};
    ListNode* head = createList(vals);
    reorderList(head);
    vector<int> expected = {1, 2};
    EXPECT_EQ(toVector(head), expected);
}

TEST(ReorderList, ThreeNodes) {
    vector<int> vals = {1, 2, 3};
    ListNode* head = createList(vals);
    reorderList(head);
    vector<int> expected = {1, 3, 2};
    EXPECT_EQ(toVector(head), expected);
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
