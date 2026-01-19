# 🏗️ Design Pattern

## Overview

**Design** problems test your ability to create classes and data structures that meet specific requirements. They combine multiple concepts: data structures, algorithms, and object-oriented design.

---

## 🧠 When You'll See Design Problems

Design problems appear as:
- Implement a specific **data structure** (LRU Cache, Stack with Min)
- Design a **system component** (Iterator, File System)
- Create a class with specific **operations** and **complexity requirements**

---

## 🎯 Common Design Problems

### 1. LRU Cache
- OrderedDict or HashMap + Doubly Linked List
- O(1) get and put

### 2. Min Stack
- Two stacks: one for values, one for minimums

### 3. Iterator Design
- Implement next() and hasNext()

### 4. Data Stream Problems
- Online algorithms that process one element at a time

---

## 📐 Example: LRU Cache

```cpp
class LRUCache {
    int capacity;
    list<pair<int, int>> cache;  // (key, value)
    unordered_map<int, list<pair<int, int>>::iterator> map;  // key -> iterator
    
public:
    LRUCache(int capacity) : capacity(capacity) {}
    
    int get(int key) {
        if (!map.count(key)) {
            return -1;
        }
        // Move to front (most recently used)
        auto it = map[key];
        int value = it->second;
        cache.erase(it);
        cache.push_front({key, value});
        map[key] = cache.begin();
        return value;
    }
    
    void put(int key, int value) {
        if (map.count(key)) {
            cache.erase(map[key]);
        }
        cache.push_front({key, value});
        map[key] = cache.begin();
        
        if (cache.size() > capacity) {
            auto last = cache.back();
            map.erase(last.first);
            cache.pop_back();
        }
    }
};
```

### Min Stack

```cpp
class MinStack {
    stack<int> stk;
    stack<int> minStk;
    
public:
    void push(int val) {
        stk.push(val);
        if (minStk.empty() || val <= minStk.top()) {
            minStk.push(val);
        }
    }
    
    void pop() {
        if (stk.top() == minStk.top()) {
            minStk.pop();
        }
        stk.pop();
    }
    
    int top() {
        return stk.top();
    }
    
    int getMin() {
        return minStk.top();
    }
};
```

---

## 💡 Key Insights

### Design Interview Tips
1. **Clarify requirements:** Ask about constraints, expected operations
2. **Discuss trade-offs:** Time vs space, simplicity vs performance
3. **Start simple:** Get a working solution, then optimize
4. **Consider edge cases:** Empty input, capacity limits

### Common Data Structures Used
- **HashMap:** O(1) lookup
- **Doubly Linked List:** O(1) insertion/deletion with node reference
- **Heap:** O(log n) min/max access
- **Stack/Queue:** LIFO/FIFO operations

---

*Next: [See Practice Questions →](./questions.md)*
