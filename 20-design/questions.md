# 📝 Design - Practice Questions

## Question Checklist

| # | Problem | Difficulty | Type | Status |
|---|---------|------------|------|--------|
| 1 | Min Stack | Medium | Stack | ⬜ |
| 2 | LRU Cache | Medium | Cache | ⬜ |
| 3 | Implement Queue using Stacks | Easy | Queue | ⬜ |
| 4 | Design Twitter | Medium | System | ⬜ |
| 5 | Design Circular Queue | Medium | Queue | ⬜ |
| 6 | Design HashMap | Easy | Hash | ⬜ |
| 7 | LFU Cache | Hard | Cache | ⬜ |

---

## 🟢 Easy Problems

### 1. Implement Queue using Stacks
**LeetCode #232**

Implement FIFO queue using two stacks.

**Solution:**
```python
class MyQueue:
    def __init__(self):
        self.in_stack = []
        self.out_stack = []
    
    def push(self, x):
        self.in_stack.append(x)
    
    def pop(self):
        self._move()
        return self.out_stack.pop()
    
    def peek(self):
        self._move()
        return self.out_stack[-1]
    
    def empty(self):
        return not self.in_stack and not self.out_stack
    
    def _move(self):
        if not self.out_stack:
            while self.in_stack:
                self.out_stack.append(self.in_stack.pop())
```
**Complexity:** Amortized O(1) per operation

---

## 🟡 Medium Problems

### 2. Min Stack
**LeetCode #155**

Stack with O(1) getMin operation.

**Solution:**
```python
class MinStack:
    def __init__(self):
        self.stack = []
        self.min_stack = []
    
    def push(self, val):
        self.stack.append(val)
        if not self.min_stack or val <= self.min_stack[-1]:
            self.min_stack.append(val)
    
    def pop(self):
        if self.stack.pop() == self.min_stack[-1]:
            self.min_stack.pop()
    
    def top(self):
        return self.stack[-1]
    
    def getMin(self):
        return self.min_stack[-1]
```
**Complexity:** All operations O(1)

---

### 3. LRU Cache
**LeetCode #146**

Least Recently Used cache with O(1) operations.

**Solution:**
```python
from collections import OrderedDict

class LRUCache:
    def __init__(self, capacity):
        self.cache = OrderedDict()
        self.capacity = capacity
    
    def get(self, key):
        if key not in self.cache:
            return -1
        self.cache.move_to_end(key)
        return self.cache[key]
    
    def put(self, key, value):
        if key in self.cache:
            self.cache.move_to_end(key)
        self.cache[key] = value
        if len(self.cache) > self.capacity:
            self.cache.popitem(last=False)
```
**Complexity:** All operations O(1)

---

### 4. Design Twitter
**LeetCode #355**

Implement Twitter with follow, unfollow, post, and news feed.

**Solution:**
```python
from collections import defaultdict
import heapq

class Twitter:
    def __init__(self):
        self.time = 0
        self.tweets = defaultdict(list)  # userId -> [(time, tweetId)]
        self.following = defaultdict(set)  # userId -> set of userIds
    
    def postTweet(self, userId, tweetId):
        self.tweets[userId].append((self.time, tweetId))
        self.time += 1
    
    def getNewsFeed(self, userId):
        # Get tweets from user and following
        users = self.following[userId] | {userId}
        heap = []
        
        for user in users:
            for tweet in self.tweets[user][-10:]:
                heapq.heappush(heap, tweet)
                if len(heap) > 10:
                    heapq.heappop(heap)
        
        return [t[1] for t in sorted(heap, reverse=True)]
    
    def follow(self, followerId, followeeId):
        if followerId != followeeId:
            self.following[followerId].add(followeeId)
    
    def unfollow(self, followerId, followeeId):
        self.following[followerId].discard(followeeId)
```
**Complexity:** postTweet O(1), getNewsFeed O(n log 10), follow/unfollow O(1)

---

## 🔴 Hard Problems

### 5. LFU Cache
**LeetCode #460**

Least Frequently Used cache with O(1) operations.

**Solution:**
```python
from collections import defaultdict

class LFUCache:
    def __init__(self, capacity):
        self.capacity = capacity
        self.cache = {}  # key -> (value, freq)
        self.freq_map = defaultdict(dict)  # freq -> {key: None}
        self.min_freq = 0
    
    def get(self, key):
        if key not in self.cache:
            return -1
        
        value, freq = self.cache[key]
        self._update_freq(key, freq)
        return value
    
    def put(self, key, value):
        if self.capacity == 0:
            return
        
        if key in self.cache:
            _, freq = self.cache[key]
            self.cache[key] = (value, freq)
            self._update_freq(key, freq)
        else:
            if len(self.cache) >= self.capacity:
                # Remove LFU item
                lfu_key = next(iter(self.freq_map[self.min_freq]))
                del self.freq_map[self.min_freq][lfu_key]
                del self.cache[lfu_key]
            
            self.cache[key] = (value, 1)
            self.freq_map[1][key] = None
            self.min_freq = 1
    
    def _update_freq(self, key, freq):
        del self.freq_map[freq][key]
        if not self.freq_map[freq] and self.min_freq == freq:
            self.min_freq += 1
        
        self.freq_map[freq + 1][key] = None
        value, _ = self.cache[key]
        self.cache[key] = (value, freq + 1)
```
**Complexity:** All operations O(1)

---

## 📚 Study Tips for Design

1. **Clarify requirements:** Operations, complexity, constraints
2. **Choose data structures wisely:** HashMap + LinkedList is common
3. **Handle edge cases:** Empty cache, capacity 0
4. **Think about concurrency:** Mention if relevant

---

*[← Back to Pattern](./README.md) | [Back to Main Guide →](../README.md)*
