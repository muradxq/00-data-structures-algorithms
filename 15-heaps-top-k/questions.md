# 📝 Heaps / Top K - Practice Questions

## Question Checklist

| # | Problem | Difficulty | Type | Status |
|---|---------|------------|------|--------|
| 1 | Kth Largest Element in Array | Medium | Top K | ⬜ |
| 2 | Top K Frequent Elements | Medium | Top K | ⬜ |
| 3 | K Closest Points to Origin | Medium | Top K | ⬜ |
| 4 | Merge K Sorted Lists | Hard | K-way Merge | ⬜ |
| 5 | Find Median from Data Stream | Hard | Two Heaps | ⬜ |
| 6 | Task Scheduler | Medium | Greedy + Heap | ⬜ |
| 7 | Reorganize String | Medium | Greedy + Heap | ⬜ |

---

## 🟡 Medium Problems

### 1. Kth Largest Element in an Array
**LeetCode #215**

Find kth largest element.

```
Input: nums = [3,2,1,5,6,4], k = 2
Output: 5
```

**Approach:**
- Min-heap of size k keeps k largest elements
- Top of heap is kth largest

**Solution:**
```cpp
int findKthLargest(vector<int>& nums, int k) {
    priority_queue<int, vector<int>, greater<int>> minHeap;
    
    for (int num : nums) {
        minHeap.push(num);
        if (minHeap.size() > k) {
            minHeap.pop();
        }
    }
    
    return minHeap.top();
}
```
**Complexity:** Time O(n log k), Space O(k)

---

### 2. Top K Frequent Elements
**LeetCode #347**

Find k most frequent elements.

```
Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]
```

**Approach:**
- Count frequencies
- Use min-heap of size k to keep top k frequent

**Solution:**
```cpp
vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> count;
    for (int num : nums) count[num]++;
    
    // Min-heap: {frequency, number}
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
    
    for (auto& [num, freq] : count) {
        minHeap.push({freq, num});
        if (minHeap.size() > k) {
            minHeap.pop();
        }
    }
    
    vector<int> result;
    while (!minHeap.empty()) {
        result.push_back(minHeap.top().second);
        minHeap.pop();
    }
    return result;
}
```
**Complexity:** Time O(n log k), Space O(n)

---

### 3. K Closest Points to Origin
**LeetCode #973**

Find k closest points to origin.

```
Input: points = [[1,3],[-2,2]], k = 1
Output: [[-2,2]]
```

**Approach:**
- Max-heap of size k (negate distance for max behavior)
- Keep k smallest distances

**Solution:**
```cpp
vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
    // Max-heap: {distance, {x, y}}
    priority_queue<pair<int, pair<int, int>>> maxHeap;
    
    for (auto& point : points) {
        int dist = point[0] * point[0] + point[1] * point[1];
        
        if (maxHeap.size() < k) {
            maxHeap.push({dist, {point[0], point[1]}});
        } else if (dist < maxHeap.top().first) {
            maxHeap.pop();
            maxHeap.push({dist, {point[0], point[1]}});
        }
    }
    
    vector<vector<int>> result;
    while (!maxHeap.empty()) {
        auto [dist, point] = maxHeap.top();
        maxHeap.pop();
        result.push_back({point.first, point.second});
    }
    return result;
}
```
**Complexity:** Time O(n log k), Space O(k)

---

### 6. Task Scheduler
**LeetCode #621**

Find minimum intervals to execute all tasks with cooldown.

```
Input: tasks = ["A","A","A","B","B","B"], n = 2
Output: 8 (A -> B -> idle -> A -> B -> idle -> A -> B)
```

**Approach:**
- Use max-heap to always pick most frequent task
- Track when tasks become available again

**Solution:**
```cpp
int leastInterval(vector<char>& tasks, int n) {
    vector<int> count(26, 0);
    for (char task : tasks) count[task - 'A']++;
    
    priority_queue<int> maxHeap;
    for (int c : count) {
        if (c > 0) maxHeap.push(c);
    }
    
    int time = 0;
    while (!maxHeap.empty()) {
        vector<int> temp;
        
        for (int i = 0; i <= n; i++) {
            if (!maxHeap.empty()) {
                int cnt = maxHeap.top();
                maxHeap.pop();
                if (cnt - 1 > 0) {
                    temp.push_back(cnt - 1);
                }
            }
            time++;
            
            if (maxHeap.empty() && temp.empty()) break;
        }
        
        for (int cnt : temp) {
            maxHeap.push(cnt);
        }
    }
    
    return time;
}
```
**Complexity:** Time O(n log 26), Space O(26)

---

### 7. Reorganize String
**LeetCode #767**

Rearrange string so no two adjacent characters are same.

```
Input: s = "aab"
Output: "aba"
```

**Approach:**
- Use max-heap to always pick most frequent character
- Alternate between most frequent characters

**Solution:**
```cpp
string reorganizeString(string s) {
    vector<int> count(26, 0);
    for (char c : s) count[c - 'a']++;
    
    // Max-heap: {count, character}
    priority_queue<pair<int, char>> maxHeap;
    for (int i = 0; i < 26; i++) {
        if (count[i] > 0) {
            maxHeap.push({count[i], 'a' + i});
        }
    }
    
    string result;
    while (!maxHeap.empty()) {
        auto [cnt1, ch1] = maxHeap.top();
        maxHeap.pop();
        
        if (result.empty() || result.back() != ch1) {
            result += ch1;
            if (cnt1 - 1 > 0) {
                maxHeap.push({cnt1 - 1, ch1});
            }
        } else {
            if (maxHeap.empty()) return "";  // Can't reorganize
            
            auto [cnt2, ch2] = maxHeap.top();
            maxHeap.pop();
            
            result += ch2;
            if (cnt2 - 1 > 0) {
                maxHeap.push({cnt2 - 1, ch2});
            }
            maxHeap.push({cnt1, ch1});  // Put back first character
        }
    }
    
    return result;
}
```
**Complexity:** Time O(n log 26), Space O(26)

---

## 🔴 Hard Problems

### 4. Merge K Sorted Lists
**LeetCode #23**

Merge k sorted linked lists.

```
Input: lists = [[1,4,5],[1,3,4],[2,6]]
Output: [1,1,2,3,4,4,5,6]
```

**Approach:**
- Min-heap to always get smallest current element
- Push next element from same list after popping

**Solution:**
```cpp
ListNode* mergeKLists(vector<ListNode*>& lists) {
    auto compare = [](ListNode* a, ListNode* b) {
        return a->val > b->val;  // Min-heap
    };
    priority_queue<ListNode*, vector<ListNode*>, decltype(compare)> minHeap(compare);
    
    for (ListNode* list : lists) {
        if (list) minHeap.push(list);
    }
    
    ListNode dummy(0);
    ListNode* curr = &dummy;
    
    while (!minHeap.empty()) {
        ListNode* node = minHeap.top();
        minHeap.pop();
        
        curr->next = node;
        curr = curr->next;
        
        if (node->next) {
            minHeap.push(node->next);
        }
    }
    
    return dummy.next;
}
```
**Complexity:** Time O(n log k), Space O(k)

---

### 5. Find Median from Data Stream
**LeetCode #295**

Design data structure to find median efficiently.

```
Example:
addNum(1)
addNum(2)
findMedian() -> 1.5
addNum(3)
findMedian() -> 2.0
```

**Approach:**
- Two heaps: max-heap for smaller half, min-heap for larger half
- Balance heaps so sizes differ by at most 1

**Solution:**
```cpp
class MedianFinder {
    priority_queue<int> small;  // Max-heap for smaller half
    priority_queue<int, vector<int>, greater<int>> large;  // Min-heap for larger half
    
public:
    void addNum(int num) {
        small.push(num);
        large.push(small.top());
        small.pop();
        
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
**Complexity:** addNum O(log n), findMedian O(1), Space O(n)

---

## 📚 Study Tips for Heaps

1. **Know heap size:** K largest = min-heap of size K
2. **Use pairs:** For custom ordering `{priority, value}`
3. **Max-heap in C++:** Default `priority_queue` is max-heap
4. **Two heaps:** For median or balanced problems

---

*[← Back to Pattern](./README.md) | [Next Pattern: Monotonic Stack →](../16-monotonic-stack/README.md)*
