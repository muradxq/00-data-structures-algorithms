# 📝 Monotonic Stack - Practice Questions

## Question Checklist

| # | Problem | Difficulty | Type | Status |
|---|---------|------------|------|--------|
| 1 | Daily Temperatures | Medium | Next Greater | ⬜ |
| 2 | Next Greater Element I | Easy | Next Greater | ⬜ |
| 3 | Next Greater Element II | Medium | Circular | ⬜ |
| 4 | Largest Rectangle in Histogram | Hard | Area | ⬜ |
| 5 | Trapping Rain Water | Hard | Two Pass | ⬜ |
| 6 | Online Stock Span | Medium | Span | ⬜ |

---

## 🟢 Easy Problems

### 2. Next Greater Element I
**LeetCode #496**

Find next greater element from nums2 for each element in nums1.

```
Input: nums1 = [4,1,2], nums2 = [1,3,4,2]
Output: [-1,3,-1]
```

**Approach:**
- Precompute next greater for all elements in nums2
- Monotonic decreasing stack - pop when finding greater element

**Solution:**
```cpp
vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    unordered_map<int, int> nextGreater;
    stack<int> st;
    
    for (int num : nums2) {
        while (!st.empty() && num > st.top()) {
            nextGreater[st.top()] = num;
            st.pop();
        }
        st.push(num);
    }
    
    vector<int> result;
    for (int num : nums1) {
        result.push_back(nextGreater.count(num) ? nextGreater[num] : -1);
    }
    return result;
}
```
**Complexity:** Time O(m + n), Space O(n)

---

## 🟡 Medium Problems

### 1. Daily Temperatures
**LeetCode #739**

Days until warmer temperature.

```
Input: temperatures = [73,74,75,71,69,72,76,73]
Output: [1,1,4,2,1,1,0,0]
```

**Approach:**
- Stack stores indices of temperatures waiting for warmer day
- When finding warmer temp, pop and calculate days difference

**Solution:**
```cpp
vector<int> dailyTemperatures(vector<int>& temperatures) {
    int n = temperatures.size();
    vector<int> result(n, 0);
    stack<int> st;
    
    for (int i = 0; i < n; i++) {
        while (!st.empty() && temperatures[i] > temperatures[st.top()]) {
            int idx = st.top();
            st.pop();
            result[idx] = i - idx;
        }
        st.push(i);
    }
    
    return result;
}
```
**Complexity:** Time O(n), Space O(n)

---

### 3. Next Greater Element II
**LeetCode #503**

Circular array - next greater element.

```
Input: nums = [1,2,1]
Output: [2,-1,2]
```

**Approach:**
- Process array twice to handle circular nature
- Only add to stack on first pass

**Solution:**
```cpp
vector<int> nextGreaterElements(vector<int>& nums) {
    int n = nums.size();
    vector<int> result(n, -1);
    stack<int> st;
    
    // Process twice for circular
    for (int i = 0; i < 2 * n; i++) {
        int idx = i % n;
        while (!st.empty() && nums[idx] > nums[st.top()]) {
            result[st.top()] = nums[idx];
            st.pop();
        }
        if (i < n) {
            st.push(i);
        }
    }
    
    return result;
}
```
**Complexity:** Time O(n), Space O(n)

---

### 6. Online Stock Span
**LeetCode #901**

Find span of stock prices (consecutive days with price ≤ today).

**Approach:**
- Stack stores pairs of (price, span)
- Combine spans when current price is higher

**Solution:**
```cpp
class StockSpanner {
    stack<pair<int, int>> st;  // {price, span}
    
public:
    int next(int price) {
        int span = 1;
        while (!st.empty() && st.top().first <= price) {
            span += st.top().second;
            st.pop();
        }
        st.push({price, span});
        return span;
    }
};
```
**Complexity:** O(1) amortized per call

---

## 🔴 Hard Problems

### 4. Largest Rectangle in Histogram
**LeetCode #84**

Find largest rectangle area in histogram.

```
Input: heights = [2,1,5,6,2,3]
Output: 10
```

**Approach:**
- Stack stores indices of increasing heights
- When decreasing height found, calculate area for popped bars
- Use sentinel value 0 at end to empty stack

**Solution:**
```cpp
int largestRectangleArea(vector<int>& heights) {
    heights.push_back(0);  // Sentinel
    stack<int> st;
    int maxArea = 0;
    
    for (int i = 0; i < heights.size(); i++) {
        while (!st.empty() && heights[st.top()] > heights[i]) {
            int height = heights[st.top()];
            st.pop();
            int width = st.empty() ? i : i - st.top() - 1;
            maxArea = max(maxArea, height * width);
        }
        st.push(i);
    }
    
    heights.pop_back();  // Remove sentinel
    return maxArea;
}
```
**Complexity:** Time O(n), Space O(n)

---

### 5. Trapping Rain Water
**LeetCode #42**

Calculate trapped water after rain.

```
Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
```

**Approach:**
- Two pointers from both ends
- Water at position depends on min of max heights from both sides

**Solution:**
```cpp
int trap(vector<int>& height) {
    if (height.empty()) return 0;
    
    int left = 0, right = height.size() - 1;
    int leftMax = height[left], rightMax = height[right];
    int water = 0;
    
    while (left < right) {
        if (leftMax < rightMax) {
            left++;
            leftMax = max(leftMax, height[left]);
            water += leftMax - height[left];
        } else {
            right--;
            rightMax = max(rightMax, height[right]);
            water += rightMax - height[right];
        }
    }
    
    return water;
}
```
**Complexity:** Time O(n), Space O(1)

---

## 📚 Study Tips for Monotonic Stack

1. **Store indices:** Usually more useful than values
2. **Direction matters:** Increasing vs decreasing stack
3. **Handle remaining:** Elements left in stack after processing
4. **Circular arrays:** Process twice or use modulo

---

*[← Back to Pattern](./README.md) | [Next Pattern: Trie →](../17-trie/README.md)*
