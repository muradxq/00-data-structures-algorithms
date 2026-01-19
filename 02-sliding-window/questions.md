# 📝 Sliding Window - Practice Questions

## Question Checklist

| # | Problem | Difficulty | Window Type | Status |
|---|---------|------------|-------------|--------|
| 1 | Maximum Average Subarray I | Easy | Fixed | ⬜ |
| 2 | Minimum Recolors to Get K Consecutive Black | Easy | Fixed | ⬜ |
| 3 | Longest Substring Without Repeating Characters | Medium | Variable | ⬜ |
| 4 | Longest Repeating Character Replacement | Medium | Variable | ⬜ |
| 5 | Permutation in String | Medium | Fixed | ⬜ |
| 6 | Find All Anagrams in a String | Medium | Fixed | ⬜ |
| 7 | Max Consecutive Ones III | Medium | Variable | ⬜ |
| 8 | Fruit Into Baskets | Medium | Variable | ⬜ |
| 9 | Subarray Product Less Than K | Medium | Variable | ⬜ |
| 10 | Minimum Size Subarray Sum | Medium | Variable | ⬜ |
| 11 | Minimum Window Substring | Hard | Variable | ⬜ |
| 12 | Sliding Window Maximum | Hard | Fixed + Deque | ⬜ |
| 13 | Substring with Concatenation of All Words | Hard | Fixed | ⬜ |

---

## 🟢 Easy Problems

### 1. Maximum Average Subarray I
**LeetCode #643**

Find contiguous subarray of length k with maximum average.

```
Input: nums = [1,12,-5,-6,50,3], k = 4
Output: 12.75 (subarray [12,-5,-6,50])
```

**Solution:**
```python
def findMaxAverage(nums, k):
    window_sum = sum(nums[:k])
    max_sum = window_sum
    
    for i in range(k, len(nums)):
        window_sum += nums[i] - nums[i - k]
        max_sum = max(max_sum, window_sum)
    
    return max_sum / k
```
**Complexity:** Time O(n), Space O(1)

---

## 🟡 Medium Problems

### 2. Longest Substring Without Repeating Characters
**LeetCode #3**

Find length of longest substring without repeating characters.

```
Input: s = "abcabcbb"
Output: 3 ("abc")
```

**Approach:**
- Variable window with character index tracking
- When duplicate found, jump start to after previous occurrence

**Solution:**
```python
def lengthOfLongestSubstring(s):
    char_index = {}
    max_length = 0
    start = 0
    
    for end in range(len(s)):
        if s[end] in char_index and char_index[s[end]] >= start:
            start = char_index[s[end]] + 1
        
        char_index[s[end]] = end
        max_length = max(max_length, end - start + 1)
    
    return max_length
```
**Complexity:** Time O(n), Space O(min(n, alphabet_size))

---

### 3. Longest Repeating Character Replacement
**LeetCode #424**

Find longest substring with same letter after replacing at most k characters.

```
Input: s = "AABABBA", k = 1
Output: 4 (Replace one 'A' in "AABA" to get "AAAA")
```

**Key Insight:**
- Window is valid if: `window_length - max_freq <= k`
- We can replace all non-majority characters

**Solution:**
```python
def characterReplacement(s, k):
    count = {}
    max_freq = 0
    max_length = 0
    start = 0
    
    for end in range(len(s)):
        count[s[end]] = count.get(s[end], 0) + 1
        max_freq = max(max_freq, count[s[end]])
        
        # Window invalid: more chars to replace than k allows
        while (end - start + 1) - max_freq > k:
            count[s[start]] -= 1
            start += 1
        
        max_length = max(max_length, end - start + 1)
    
    return max_length
```
**Complexity:** Time O(n), Space O(26) = O(1)

---

### 4. Permutation in String
**LeetCode #567**

Check if s2 contains any permutation of s1.

```
Input: s1 = "ab", s2 = "eidbaooo"
Output: true ("ba" is a permutation of "ab")
```

**Approach:**
- Fixed window of size len(s1)
- Compare character frequencies

**Solution:**
```python
from collections import Counter

def checkInclusion(s1, s2):
    if len(s1) > len(s2):
        return False
    
    s1_count = Counter(s1)
    window_count = Counter(s2[:len(s1)])
    
    if s1_count == window_count:
        return True
    
    for i in range(len(s1), len(s2)):
        # Add new char
        window_count[s2[i]] += 1
        
        # Remove old char
        old_char = s2[i - len(s1)]
        window_count[old_char] -= 1
        if window_count[old_char] == 0:
            del window_count[old_char]
        
        if s1_count == window_count:
            return True
    
    return False
```
**Complexity:** Time O(n), Space O(26) = O(1)

---

### 5. Find All Anagrams in a String
**LeetCode #438**

Find all start indices of p's anagrams in s.

```
Input: s = "cbaebabacd", p = "abc"
Output: [0, 6]
```

**Solution:**
```python
from collections import Counter

def findAnagrams(s, p):
    if len(p) > len(s):
        return []
    
    p_count = Counter(p)
    window_count = Counter(s[:len(p)])
    result = []
    
    if p_count == window_count:
        result.append(0)
    
    for i in range(len(p), len(s)):
        # Add new char
        window_count[s[i]] += 1
        
        # Remove old char
        old_char = s[i - len(p)]
        window_count[old_char] -= 1
        if window_count[old_char] == 0:
            del window_count[old_char]
        
        if p_count == window_count:
            result.append(i - len(p) + 1)
    
    return result
```
**Complexity:** Time O(n), Space O(26) = O(1)

---

### 6. Max Consecutive Ones III
**LeetCode #1004**

Find longest subarray of 1s after flipping at most k 0s.

```
Input: nums = [1,1,1,0,0,0,1,1,1,1,0], k = 2
Output: 6 (Flip 0s at indices 5,10 → [1,1,1,0,0,1,1,1,1,1,1])
```

**Solution:**
```python
def longestOnes(nums, k):
    start = 0
    zeros = 0
    max_length = 0
    
    for end in range(len(nums)):
        if nums[end] == 0:
            zeros += 1
        
        while zeros > k:
            if nums[start] == 0:
                zeros -= 1
            start += 1
        
        max_length = max(max_length, end - start + 1)
    
    return max_length
```
**Complexity:** Time O(n), Space O(1)

---

### 7. Fruit Into Baskets
**LeetCode #904**

Find longest subarray with at most 2 distinct elements.

```
Input: fruits = [1,2,3,2,2]
Output: 4 ([2,3,2,2])
```

**Solution:**
```python
def totalFruit(fruits):
    basket = {}
    start = 0
    max_fruits = 0
    
    for end in range(len(fruits)):
        basket[fruits[end]] = basket.get(fruits[end], 0) + 1
        
        while len(basket) > 2:
            basket[fruits[start]] -= 1
            if basket[fruits[start]] == 0:
                del basket[fruits[start]]
            start += 1
        
        max_fruits = max(max_fruits, end - start + 1)
    
    return max_fruits
```
**Complexity:** Time O(n), Space O(1)

---

### 8. Subarray Product Less Than K
**LeetCode #713**

Count subarrays where product of elements < k.

```
Input: nums = [10,5,2,6], k = 100
Output: 8 (Subarrays: [10], [5], [2], [6], [10,5], [5,2], [2,6], [5,2,6])
```

**Key Insight:**
- For each ending position, count new valid subarrays
- New subarrays ending at `end` = `end - start + 1`

**Solution:**
```python
def numSubarrayProductLessThanK(nums, k):
    if k <= 1:
        return 0
    
    product = 1
    start = 0
    count = 0
    
    for end in range(len(nums)):
        product *= nums[end]
        
        while product >= k:
            product //= nums[start]
            start += 1
        
        # All subarrays ending at 'end' with start points from 'start' to 'end'
        count += end - start + 1
    
    return count
```
**Complexity:** Time O(n), Space O(1)

---

### 9. Minimum Size Subarray Sum
**LeetCode #209**

Find minimal length subarray with sum >= target.

```
Input: target = 7, nums = [2,3,1,2,4,3]
Output: 2 ([4,3])
```

**Solution:**
```python
def minSubArrayLen(target, nums):
    min_length = float('inf')
    current_sum = 0
    start = 0
    
    for end in range(len(nums)):
        current_sum += nums[end]
        
        while current_sum >= target:
            min_length = min(min_length, end - start + 1)
            current_sum -= nums[start]
            start += 1
    
    return min_length if min_length != float('inf') else 0
```
**Complexity:** Time O(n), Space O(1)

---

## 🔴 Hard Problems

### 10. Minimum Window Substring
**LeetCode #76**

Find minimum window in s containing all characters of t.

```
Input: s = "ADOBECODEBANC", t = "ABC"
Output: "BANC"
```

**Approach:**
- Track required characters and their counts
- Expand until all required found, then shrink to find minimum

**Solution:**
```python
from collections import Counter

def minWindow(s, t):
    if not t or not s:
        return ""
    
    t_count = Counter(t)
    required = len(t_count)
    
    formed = 0
    window_counts = {}
    
    # (window_length, left, right)
    ans = float('inf'), None, None
    
    left = 0
    for right in range(len(s)):
        char = s[right]
        window_counts[char] = window_counts.get(char, 0) + 1
        
        if char in t_count and window_counts[char] == t_count[char]:
            formed += 1
        
        while formed == required:
            # Update answer
            if right - left + 1 < ans[0]:
                ans = (right - left + 1, left, right)
            
            # Shrink window
            char = s[left]
            window_counts[char] -= 1
            if char in t_count and window_counts[char] < t_count[char]:
                formed -= 1
            left += 1
    
    return "" if ans[0] == float('inf') else s[ans[1]:ans[2] + 1]
```
**Complexity:** Time O(n + m), Space O(n + m)

---

### 11. Sliding Window Maximum
**LeetCode #239**

Return max element for each window of size k.

```
Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
Output: [3,3,5,5,6,7]
```

**Approach:**
- Use monotonic deque to maintain indices of potential maximums
- Deque stores indices in decreasing order of values

**Solution:**
```python
from collections import deque

def maxSlidingWindow(nums, k):
    dq = deque()  # Store indices
    result = []
    
    for i in range(len(nums)):
        # Remove indices outside window
        while dq and dq[0] < i - k + 1:
            dq.popleft()
        
        # Remove smaller elements (maintain decreasing order)
        while dq and nums[dq[-1]] < nums[i]:
            dq.pop()
        
        dq.append(i)
        
        # Start adding to result when first window is complete
        if i >= k - 1:
            result.append(nums[dq[0]])
    
    return result
```
**Complexity:** Time O(n), Space O(k)

---

## 📚 Study Tips for Sliding Window

1. **Fixed vs Variable:** Know when to use each type
2. **Window State:** Choose the right data structure (Counter, set, deque)
3. **Shrink Condition:** Max problems shrink when invalid, min problems shrink while valid
4. **Count vs Index:** Decide whether to track frequency or last index

---

*[← Back to Pattern](./README.md) | [Next Pattern: Fast & Slow Pointers →](../03-fast-slow-pointers/README.md)*
