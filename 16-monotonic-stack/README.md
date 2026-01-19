# 📚 Monotonic Stack Pattern

## Overview

A **Monotonic Stack** maintains elements in sorted order (either increasing or decreasing). It's powerful for finding the **next greater/smaller element** efficiently, reducing O(n²) brute force to O(n).

---

## 🧠 When to Use Monotonic Stack

Use this pattern when:
- Find **next greater/smaller** element for each element
- Find **previous greater/smaller** element
- Problems involving **spans** or **ranges**
- Keywords: "next greater", "next smaller", "span", "histogram"

---

## 🎯 Types

### Monotonic Increasing Stack
Stack maintains increasing order (smallest at bottom).
**Use for:** Next smaller element.

### Monotonic Decreasing Stack  
Stack maintains decreasing order (largest at bottom).
**Use for:** Next greater element.

---

## 📐 Templates

### Next Greater Element
```cpp
vector<int> nextGreater(vector<int>& nums) {
    int n = nums.size();
    vector<int> result(n, -1);
    stack<int> stk;  // Stores indices
    
    for (int i = 0; i < n; i++) {
        // Pop while current is greater than stack top
        while (!stk.empty() && nums[i] > nums[stk.top()]) {
            int idx = stk.top();
            stk.pop();
            result[idx] = nums[i];
        }
        stk.push(i);
    }
    
    return result;
}
```

### Next Smaller Element
```cpp
vector<int> nextSmaller(vector<int>& nums) {
    int n = nums.size();
    vector<int> result(n, -1);
    stack<int> stk;
    
    for (int i = 0; i < n; i++) {
        while (!stk.empty() && nums[i] < nums[stk.top()]) {
            int idx = stk.top();
            stk.pop();
            result[idx] = nums[i];
        }
        stk.push(i);
    }
    
    return result;
}
```

### Previous Greater Element
```cpp
vector<int> prevGreater(vector<int>& nums) {
    int n = nums.size();
    vector<int> result(n, -1);
    stack<int> stk;
    
    for (int i = 0; i < n; i++) {
        while (!stk.empty() && nums[stk.top()] <= nums[i]) {
            stk.pop();
        }
        if (!stk.empty()) {
            result[i] = nums[stk.top()];
        }
        stk.push(i);
    }
    
    return result;
}
```

---

## 💡 Key Insights

### 1. What to Store
Usually store **indices**, not values, since you often need position information.

### 2. When to Pop
| Finding | Pop When |
|---------|----------|
| Next Greater | current > stack top |
| Next Smaller | current < stack top |
| Previous Greater | current >= stack top |
| Previous Smaller | current <= stack top |

### 3. Circular Arrays
Process array twice or use modulo:
```cpp
for (int i = 0; i < 2 * n; i++) {
    int idx = i % n;
    // ... process nums[idx]
}
```

---

## 📊 Complexity

| Operation | Time | Space |
|-----------|------|-------|
| Next Greater/Smaller | O(n) | O(n) |

Each element is pushed and popped at most once.

---

## 🎓 Example: Daily Temperatures

**Problem:** For each day, find how many days until warmer temperature.

```
Input: [73,74,75,71,69,72,76,73]
Output: [1,1,4,2,1,1,0,0]
```

**Solution:**
```cpp
vector<int> dailyTemperatures(vector<int>& temperatures) {
    int n = temperatures.size();
    vector<int> result(n, 0);
    stack<int> stk;
    
    for (int i = 0; i < n; i++) {
        while (!stk.empty() && temperatures[i] > temperatures[stk.top()]) {
            int idx = stk.top();
            stk.pop();
            result[idx] = i - idx;
        }
        stk.push(i);
    }
    
    return result;
}
```

---

*Next: [See Practice Questions →](./questions.md)*
