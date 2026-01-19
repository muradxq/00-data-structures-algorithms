# ⛰️ Heaps / Top K Pattern

## Overview

A **Heap** (Priority Queue) is a specialized tree-based data structure that satisfies the heap property. **Min-heap:** parent ≤ children, **Max-heap:** parent ≥ children. Heaps excel at problems involving finding the K largest/smallest elements.

---

## 🧠 When to Use Heaps

Use this pattern when:
- Find the **K largest/smallest** elements
- Need to repeatedly access **min/max** element
- **Merge K sorted** lists/arrays
- Find **median** in a stream
- Keywords: "top K", "Kth largest/smallest", "merge sorted", "median"

---

## 🎯 Types of Heap Problems

### 1. Top K Elements
Use a heap of size K to track K largest/smallest.

### 2. K-way Merge
Use heap to efficiently merge K sorted sequences.

### 3. Two Heaps
Use min-heap and max-heap together (e.g., median finding).

---

## 📐 C++ Heap Operations

```cpp
#include <queue>

// Min-heap (default in C++ with greater<>)
priority_queue<int, vector<int>, greater<int>> minHeap;
minHeap.push(value);       // O(log n)
int minVal = minHeap.top(); // O(1)
minHeap.pop();             // O(log n)

// Max-heap (default in C++)
priority_queue<int> maxHeap;
maxHeap.push(value);
int maxVal = maxHeap.top();
maxHeap.pop();

// Custom comparator
auto cmp = [](pair<int,int>& a, pair<int,int>& b) {
    return a.first > b.first;  // Min-heap by first element
};
priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(cmp)> pq(cmp);
```

---

## 📐 Common Templates

### Top K Smallest (Min-heap approach)
```cpp
vector<int> topKSmallest(vector<int>& nums, int k) {
    priority_queue<int, vector<int>, greater<int>> minHeap(nums.begin(), nums.end());
    
    vector<int> result;
    for (int i = 0; i < k; i++) {
        result.push_back(minHeap.top());
        minHeap.pop();
    }
    return result;
}
```

### Top K Largest (Max-heap of size K)
```cpp
vector<int> topKLargest(vector<int>& nums, int k) {
    // Use min-heap of size k
    priority_queue<int, vector<int>, greater<int>> minHeap;
    
    for (int num : nums) {
        minHeap.push(num);
        if (minHeap.size() > k) {
            minHeap.pop();  // Remove smallest
        }
    }
    
    vector<int> result;
    while (!minHeap.empty()) {
        result.push_back(minHeap.top());
        minHeap.pop();
    }
    return result;  // Contains k largest
}
```

### Kth Largest Element
```cpp
int kthLargest(vector<int>& nums, int k) {
    priority_queue<int, vector<int>, greater<int>> minHeap;
    
    for (int num : nums) {
        minHeap.push(num);
        if (minHeap.size() > k) {
            minHeap.pop();
        }
    }
    
    return minHeap.top();  // Kth largest
}
```

### Two Heaps (Median)
```cpp
class MedianFinder {
    priority_queue<int> small;  // Max-heap
    priority_queue<int, vector<int>, greater<int>> large;  // Min-heap
    
public:
    void addNum(int num) {
        // Add to max-heap
        small.push(num);
        
        // Balance: move max of small to large
        large.push(small.top());
        small.pop();
        
        // Maintain size: small >= large
        if (large.size() > small.size()) {
            small.push(large.top());
            large.pop();
        }
    }
    
    double findMedian() {
        if (small.size() > large.size()) {
            return small.top();
        }
        return (small.top() + large.top()) / 2.0;
    }
};
```

---

## 💡 Key Insights

### 1. K Largest vs K Smallest
| Goal | Heap Type | Size |
|------|-----------|------|
| K largest | Min-heap | K |
| K smallest | Max-heap | K |

**Why?** Keep the K largest by removing smallest when size > K.

### 2. Custom Comparison
```cpp
// Heap by specific attribute
auto cmp = [](ListNode* a, ListNode* b) {
    return a->val > b->val;  // Min-heap by val
};
priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> pq(cmp);
```

### 3. Lazy Deletion
When you can't easily remove specific elements:
```cpp
// Mark as deleted, skip during pop
unordered_set<int> deleted;
while (!heap.empty() && deleted.count(heap.top())) {
    heap.pop();
}
```

---

## 📊 Complexity Analysis

| Operation | Time |
|-----------|------|
| Push | O(log n) |
| Pop | O(log n) |
| Top | O(1) |
| Build heap | O(n) |
| Top K | O(n log k) |

---

## 🎓 Example: Merge K Sorted Lists

**Problem:** Merge k sorted linked lists into one sorted list.

**Solution:**
```cpp
ListNode* mergeKLists(vector<ListNode*>& lists) {
    auto cmp = [](ListNode* a, ListNode* b) {
        return a->val > b->val;  // Min-heap
    };
    priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> pq(cmp);
    
    // Add first node from each list
    for (ListNode* list : lists) {
        if (list) {
            pq.push(list);
        }
    }
    
    ListNode dummy(0);
    ListNode* curr = &dummy;
    
    while (!pq.empty()) {
        ListNode* node = pq.top();
        pq.pop();
        
        curr->next = node;
        curr = curr->next;
        
        if (node->next) {
            pq.push(node->next);
        }
    }
    
    return dummy.next;
}
```

---

## 🔗 Related Patterns

- **Binary Search:** Alternative for Kth element
- **Sorting:** Heap sort
- **Greedy:** Often uses heaps for selection

---

*Next: [See Practice Questions →](./questions.md)*
