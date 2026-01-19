/**
 * Problem: Merge K Sorted Lists
 * LeetCode #23
 * Difficulty: Hard
 * Pattern: K-way Merge
 *
 * Merge k sorted linked lists.
 *
 * Example:
 *   Input: lists = [[1,4,5],[1,3,4],[2,6]]
 *   Output: [1,1,2,3,4,4,5,6]
 */

#include <gtest/gtest.h>
#include <vector>
#include <queue>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// ============================================================================
// TODO: Implement your solution here
// ============================================================================
ListNode* mergeKLists(vector<ListNode*>& lists) {
    // Your implementation here
    // Use min-heap to always get smallest element
    
    return nullptr;
}

// Helper to create list
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

// Helper to get list values
vector<int> getValues(ListNode* head) {
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
TEST(MergeKSortedLists, Example1) {
    vector<int> v1 = {1, 4, 5};
    vector<int> v2 = {1, 3, 4};
    vector<int> v3 = {2, 6};
    vector<ListNode*> lists = {createList(v1), createList(v2), createList(v3)};
    
    auto result = mergeKLists(lists);
    auto values = getValues(result);
    
    vector<int> expected = {1, 1, 2, 3, 4, 4, 5, 6};
    EXPECT_EQ(values, expected);
}

TEST(MergeKSortedLists, Empty) {
    vector<ListNode*> lists;
    auto result = mergeKLists(lists);
    EXPECT_EQ(result, nullptr);
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
