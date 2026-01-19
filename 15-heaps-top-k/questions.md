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

**Heap Solution:**
```python
import heapq

def findKthLargest(nums, k):
    heap = []
    for num in nums:
        heapq.heappush(heap, num)
        if len(heap) > k:
            heapq.heappop(heap)
    return heap[0]
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

**Solution:**
```python
from collections import Counter
import heapq

def topKFrequent(nums, k):
    count = Counter(nums)
    return heapq.nlargest(k, count.keys(), key=count.get)
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

**Solution:**
```python
import heapq

def kClosest(points, k):
    # Max-heap of size k (negate distance)
    heap = []
    
    for x, y in points:
        dist = -(x*x + y*y)
        if len(heap) < k:
            heapq.heappush(heap, (dist, x, y))
        elif dist > heap[0][0]:
            heapq.heapreplace(heap, (dist, x, y))
    
    return [[x, y] for (dist, x, y) in heap]
```
**Complexity:** Time O(n log k), Space O(k)

---

### 4. Task Scheduler
**LeetCode #621**

Find minimum intervals to execute all tasks with cooldown.

```
Input: tasks = ["A","A","A","B","B","B"], n = 2
Output: 8 (A -> B -> idle -> A -> B -> idle -> A -> B)
```

**Solution:**
```python
from collections import Counter
import heapq

def leastInterval(tasks, n):
    count = Counter(tasks)
    heap = [-c for c in count.values()]
    heapq.heapify(heap)
    
    time = 0
    while heap:
        cycle = []
        
        for _ in range(n + 1):
            if heap:
                cycle.append(heapq.heappop(heap))
        
        for cnt in cycle:
            if cnt + 1 < 0:
                heapq.heappush(heap, cnt + 1)
        
        time += len(cycle) if not heap else n + 1
    
    return time
```
**Complexity:** Time O(n log 26), Space O(26)

---

## 🔴 Hard Problems

### 5. Merge K Sorted Lists
**LeetCode #23**

Merge k sorted linked lists.

**Solution:**
```python
import heapq

def mergeKLists(lists):
    heap = []
    
    for i, lst in enumerate(lists):
        if lst:
            heapq.heappush(heap, (lst.val, i, lst))
    
    dummy = ListNode()
    curr = dummy
    
    while heap:
        val, i, node = heapq.heappop(heap)
        curr.next = node
        curr = curr.next
        
        if node.next:
            heapq.heappush(heap, (node.next.val, i, node.next))
    
    return dummy.next
```
**Complexity:** Time O(n log k), Space O(k)

---

### 6. Find Median from Data Stream
**LeetCode #295**

Design data structure to find median efficiently.

**Solution:**
```python
import heapq

class MedianFinder:
    def __init__(self):
        self.small = []  # Max-heap (negated)
        self.large = []  # Min-heap
    
    def addNum(self, num):
        heapq.heappush(self.small, -num)
        heapq.heappush(self.large, -heapq.heappop(self.small))
        
        if len(self.large) > len(self.small):
            heapq.heappush(self.small, -heapq.heappop(self.large))
    
    def findMedian(self):
        if len(self.small) > len(self.large):
            return -self.small[0]
        return (-self.small[0] + self.large[0]) / 2
```
**Complexity:** addNum O(log n), findMedian O(1), Space O(n)

---

## 📚 Study Tips for Heaps

1. **Know heap size:** K largest = min-heap of size K
2. **Use tuples:** For custom ordering `(priority, value)`
3. **Max-heap trick:** Negate values in Python
4. **Two heaps:** For median or balanced problems

---

*[← Back to Pattern](./README.md) | [Next Pattern: Monotonic Stack →](../16-monotonic-stack/README.md)*
