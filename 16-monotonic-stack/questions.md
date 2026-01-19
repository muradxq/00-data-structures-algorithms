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

### 1. Next Greater Element I
**LeetCode #496**

Find next greater element from nums2 for each element in nums1.

```
Input: nums1 = [4,1,2], nums2 = [1,3,4,2]
Output: [-1,3,-1]
```

**Solution:**
```python
def nextGreaterElement(nums1, nums2):
    next_greater = {}
    stack = []
    
    for num in nums2:
        while stack and num > stack[-1]:
            next_greater[stack.pop()] = num
        stack.append(num)
    
    return [next_greater.get(num, -1) for num in nums1]
```
**Complexity:** Time O(m + n), Space O(n)

---

## 🟡 Medium Problems

### 2. Daily Temperatures
**LeetCode #739**

Days until warmer temperature.

```
Input: temperatures = [73,74,75,71,69,72,76,73]
Output: [1,1,4,2,1,1,0,0]
```

**Solution:**
```python
def dailyTemperatures(temperatures):
    n = len(temperatures)
    result = [0] * n
    stack = []
    
    for i in range(n):
        while stack and temperatures[i] > temperatures[stack[-1]]:
            idx = stack.pop()
            result[idx] = i - idx
        stack.append(i)
    
    return result
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

**Solution:**
```python
def nextGreaterElements(nums):
    n = len(nums)
    result = [-1] * n
    stack = []
    
    # Process twice for circular
    for i in range(2 * n):
        idx = i % n
        while stack and nums[idx] > nums[stack[-1]]:
            result[stack.pop()] = nums[idx]
        if i < n:
            stack.append(i)
    
    return result
```
**Complexity:** Time O(n), Space O(n)

---

### 4. Online Stock Span
**LeetCode #901**

Find span of stock prices (consecutive days with price ≤ today).

**Solution:**
```python
class StockSpanner:
    def __init__(self):
        self.stack = []  # (price, span)
    
    def next(self, price):
        span = 1
        while self.stack and self.stack[-1][0] <= price:
            span += self.stack.pop()[1]
        self.stack.append((price, span))
        return span
```
**Complexity:** O(1) amortized per call

---

## 🔴 Hard Problems

### 5. Largest Rectangle in Histogram
**LeetCode #84**

Find largest rectangle area in histogram.

```
Input: heights = [2,1,5,6,2,3]
Output: 10
```

**Solution:**
```python
def largestRectangleArea(heights):
    stack = []
    max_area = 0
    heights.append(0)  # Sentinel
    
    for i, h in enumerate(heights):
        while stack and heights[stack[-1]] > h:
            height = heights[stack.pop()]
            width = i if not stack else i - stack[-1] - 1
            max_area = max(max_area, height * width)
        stack.append(i)
    
    return max_area
```
**Complexity:** Time O(n), Space O(n)

---

## 📚 Study Tips for Monotonic Stack

1. **Store indices:** Usually more useful than values
2. **Direction matters:** Increasing vs decreasing stack
3. **Handle remaining:** Elements left in stack after processing
4. **Circular arrays:** Process twice or use modulo

---

*[← Back to Pattern](./README.md) | [Next Pattern: Trie →](../17-trie/README.md)*
