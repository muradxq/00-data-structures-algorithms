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

### 3. Implement Queue using Stacks
**LeetCode #232**

Implement FIFO queue using two stacks.

**Approach:**
- Use two stacks: input and output
- Lazy transfer from input to output when needed

**Solution:**
```cpp
class MyQueue {
    stack<int> inStack, outStack;
    
    void transfer() {
        if (outStack.empty()) {
            while (!inStack.empty()) {
                outStack.push(inStack.top());
                inStack.pop();
            }
        }
    }
    
public:
    void push(int x) {
        inStack.push(x);
    }
    
    int pop() {
        transfer();
        int val = outStack.top();
        outStack.pop();
        return val;
    }
    
    int peek() {
        transfer();
        return outStack.top();
    }
    
    bool empty() {
        return inStack.empty() && outStack.empty();
    }
};
```
**Complexity:** Amortized O(1) per operation

---

### 6. Design HashMap
**LeetCode #706**

Design a HashMap without using built-in hash table libraries.

**Approach:**
- Use array of buckets with chaining for collision handling
- Simple hash function: key % bucket_count

**Solution:**
```cpp
class MyHashMap {
    static const int SIZE = 10007;
    vector<list<pair<int, int>>> buckets;
    
    int hash(int key) {
        return key % SIZE;
    }
    
public:
    MyHashMap() : buckets(SIZE) {}
    
    void put(int key, int value) {
        int idx = hash(key);
        for (auto& [k, v] : buckets[idx]) {
            if (k == key) {
                v = value;
                return;
            }
        }
        buckets[idx].push_back({key, value});
    }
    
    int get(int key) {
        int idx = hash(key);
        for (auto& [k, v] : buckets[idx]) {
            if (k == key) return v;
        }
        return -1;
    }
    
    void remove(int key) {
        int idx = hash(key);
        buckets[idx].remove_if([key](auto& p) { return p.first == key; });
    }
};
```
**Complexity:** Average O(1), Worst O(n) per operation

---

## 🟡 Medium Problems

### 1. Min Stack
**LeetCode #155**

Stack with O(1) getMin operation.

**Approach:**
- Maintain parallel stack tracking minimum at each level

**Solution:**
```cpp
class MinStack {
    stack<int> dataStack;
    stack<int> minStack;
    
public:
    void push(int val) {
        dataStack.push(val);
        if (minStack.empty() || val <= minStack.top()) {
            minStack.push(val);
        }
    }
    
    void pop() {
        if (dataStack.top() == minStack.top()) {
            minStack.pop();
        }
        dataStack.pop();
    }
    
    int top() {
        return dataStack.top();
    }
    
    int getMin() {
        return minStack.top();
    }
};
```
**Complexity:** All operations O(1)

---

### 2. LRU Cache
**LeetCode #146**

Least Recently Used cache with O(1) operations.

**Approach:**
- HashMap for O(1) key lookup
- Doubly linked list to track access order

**Solution:**
```cpp
class LRUCache {
    int capacity;
    list<pair<int, int>> cache;  // {key, value}
    unordered_map<int, list<pair<int, int>>::iterator> map;
    
public:
    LRUCache(int capacity) : capacity(capacity) {}
    
    int get(int key) {
        if (!map.count(key)) return -1;
        
        // Move to front (most recent)
        cache.splice(cache.begin(), cache, map[key]);
        return map[key]->second;
    }
    
    void put(int key, int value) {
        if (map.count(key)) {
            cache.splice(cache.begin(), cache, map[key]);
            map[key]->second = value;
            return;
        }
        
        if (cache.size() == capacity) {
            int lruKey = cache.back().first;
            map.erase(lruKey);
            cache.pop_back();
        }
        
        cache.push_front({key, value});
        map[key] = cache.begin();
    }
};
```
**Complexity:** All operations O(1)

---

### 4. Design Twitter
**LeetCode #355**

Implement Twitter with follow, unfollow, post, and news feed.

**Approach:**
- Map users to their tweets (with timestamps)
- Map users to their followed users
- Use heap to merge tweets for news feed

**Solution:**
```cpp
class Twitter {
    int timestamp = 0;
    unordered_map<int, vector<pair<int, int>>> tweets;  // userId -> {time, tweetId}
    unordered_map<int, unordered_set<int>> following;   // userId -> set of followees
    
public:
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({timestamp++, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        // Max-heap: {time, tweetId}
        priority_queue<pair<int, int>> pq;
        
        // Add user's own tweets
        for (auto& [time, id] : tweets[userId]) {
            pq.push({time, id});
        }
        
        // Add followees' tweets
        for (int followee : following[userId]) {
            for (auto& [time, id] : tweets[followee]) {
                pq.push({time, id});
            }
        }
        
        vector<int> feed;
        while (!pq.empty() && feed.size() < 10) {
            feed.push_back(pq.top().second);
            pq.pop();
        }
        return feed;
    }
    
    void follow(int followerId, int followeeId) {
        if (followerId != followeeId) {
            following[followerId].insert(followeeId);
        }
    }
    
    void unfollow(int followerId, int followeeId) {
        following[followerId].erase(followeeId);
    }
};
```
**Complexity:** postTweet O(1), getNewsFeed O(n log n), follow/unfollow O(1)

---

### 5. Design Circular Queue
**LeetCode #622**

Implement circular queue with fixed size.

**Approach:**
- Use array with front and rear pointers
- Wrap around using modulo

**Solution:**
```cpp
class MyCircularQueue {
    vector<int> data;
    int front = 0, rear = -1, size = 0, capacity;
    
public:
    MyCircularQueue(int k) : data(k), capacity(k) {}
    
    bool enQueue(int value) {
        if (isFull()) return false;
        rear = (rear + 1) % capacity;
        data[rear] = value;
        size++;
        return true;
    }
    
    bool deQueue() {
        if (isEmpty()) return false;
        front = (front + 1) % capacity;
        size--;
        return true;
    }
    
    int Front() {
        return isEmpty() ? -1 : data[front];
    }
    
    int Rear() {
        return isEmpty() ? -1 : data[rear];
    }
    
    bool isEmpty() {
        return size == 0;
    }
    
    bool isFull() {
        return size == capacity;
    }
};
```
**Complexity:** All operations O(1)

---

## 🔴 Hard Problems

### 7. LFU Cache
**LeetCode #460**

Least Frequently Used cache with O(1) operations.

**Approach:**
- HashMap for key -> {value, frequency}
- HashMap for frequency -> list of keys (in LRU order)
- Track minimum frequency

**Solution:**
```cpp
class LFUCache {
    int capacity, minFreq = 0;
    unordered_map<int, pair<int, int>> keyToValFreq;  // key -> {value, freq}
    unordered_map<int, list<int>> freqToKeys;         // freq -> list of keys
    unordered_map<int, list<int>::iterator> keyToIter; // key -> iterator in freq list
    
    void updateFreq(int key) {
        int freq = keyToValFreq[key].second;
        freqToKeys[freq].erase(keyToIter[key]);
        
        if (freqToKeys[freq].empty()) {
            freqToKeys.erase(freq);
            if (minFreq == freq) minFreq++;
        }
        
        keyToValFreq[key].second++;
        freqToKeys[freq + 1].push_back(key);
        keyToIter[key] = prev(freqToKeys[freq + 1].end());
    }
    
public:
    LFUCache(int capacity) : capacity(capacity) {}
    
    int get(int key) {
        if (!keyToValFreq.count(key)) return -1;
        updateFreq(key);
        return keyToValFreq[key].first;
    }
    
    void put(int key, int value) {
        if (capacity == 0) return;
        
        if (keyToValFreq.count(key)) {
            keyToValFreq[key].first = value;
            updateFreq(key);
            return;
        }
        
        if (keyToValFreq.size() == capacity) {
            int evictKey = freqToKeys[minFreq].front();
            freqToKeys[minFreq].pop_front();
            if (freqToKeys[minFreq].empty()) {
                freqToKeys.erase(minFreq);
            }
            keyToValFreq.erase(evictKey);
            keyToIter.erase(evictKey);
        }
        
        keyToValFreq[key] = {value, 1};
        freqToKeys[1].push_back(key);
        keyToIter[key] = prev(freqToKeys[1].end());
        minFreq = 1;
    }
};
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
