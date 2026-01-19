# 🪟 Sliding Window Pattern

## Overview

The **Sliding Window** pattern is used to perform operations on a specific window size of an array or linked list, such as finding the longest subarray with a given sum. Instead of recalculating from scratch for each window position, we "slide" the window and update incrementally.

---

## 🧠 When to Use Sliding Window

Use this pattern when:
- The problem involves **contiguous subarrays/substrings**
- You need to find **max/min/count** of something in a window
- Keywords: "subarray", "substring", "window", "consecutive", "contiguous"
- The problem asks for **longest/shortest** subarray with a condition
- You need to track a running **sum/product/count**

---

## 🎯 Types of Sliding Window

### 1. Fixed Size Window
Window size is given or constant.

```
Array: [1, 3, 2, 6, -1, 4, 1, 8, 2]
Window Size: 5

Window 1: [1, 3, 2, 6, -1] = sum 11
Window 2: [3, 2, 6, -1, 4] = sum 14  (add 4, remove 1)
Window 3: [2, 6, -1, 4, 1] = sum 12  (add 1, remove 3)
...
```

**Use cases:**
- Maximum sum subarray of size K
- Average of all contiguous subarrays of size K
- Maximum of all subarrays of size K

### 2. Dynamic/Variable Size Window
Window expands or shrinks based on conditions.

```
String: "aabccbb"
Find longest substring with at most 2 distinct characters

[a]abccbb         → 1 char, expand
[aa]bccbb         → 1 char, expand
[aab]ccbb         → 2 chars, expand
[aabc]cbb         → 3 chars! shrink from left
a[abc]cbb         → 3 chars! shrink
aa[bc]cbb         → 2 chars, expand
aa[bcc]bb         → 2 chars, expand
aa[bccb]b         → 2 chars, expand
aa[bccbb]         → 2 chars ✓ longest = 5
```

**Use cases:**
- Longest substring with K distinct characters
- Minimum window substring
- Longest repeating character replacement

---

## 📐 General Templates

### Fixed Size Window Template
```cpp
int fixedWindow(vector<int>& arr, int k) {
    int windowSum = 0;
    for (int i = 0; i < k; i++) {
        windowSum += arr[i];  // First window
    }
    int maxSum = windowSum;
    
    for (int i = k; i < arr.size(); i++) {
        // Slide: add new element, remove old element
        windowSum += arr[i] - arr[i - k];
        maxSum = max(maxSum, windowSum);
    }
    
    return maxSum;
}
```

### Variable Size Window Template (Find Maximum)
```cpp
int variableWindowMax(string& s) {
    int windowStart = 0;
    int maxLength = 0;
    unordered_map<char, int> charCount;
    
    for (int windowEnd = 0; windowEnd < s.size(); windowEnd++) {
        // Expand window: add s[windowEnd] to window
        char rightChar = s[windowEnd];
        charCount[rightChar]++;
        
        // Shrink window while condition is violated
        while (windowIsInvalid(charCount)) {
            char leftChar = s[windowStart];
            charCount[leftChar]--;
            if (charCount[leftChar] == 0) {
                charCount.erase(leftChar);
            }
            windowStart++;
        }
        
        // Update result (window is now valid)
        maxLength = max(maxLength, windowEnd - windowStart + 1);
    }
    
    return maxLength;
}
```

### Variable Size Window Template (Find Minimum)
```cpp
int variableWindowMin(string& s, string& target) {
    int windowStart = 0;
    int minLength = INT_MAX;
    unordered_map<char, int> charCount;
    int matched = 0;
    
    for (int windowEnd = 0; windowEnd < s.size(); windowEnd++) {
        // Expand window
        char rightChar = s[windowEnd];
        // ... update state ...
        
        // Shrink window while condition is satisfied
        while (windowIsValid(matched, target)) {
            // Update minimum
            minLength = min(minLength, windowEnd - windowStart + 1);
            
            // Shrink from left
            char leftChar = s[windowStart];
            // ... update state ...
            windowStart++;
        }
    }
    
    return minLength != INT_MAX ? minLength : 0;
}
```

---

## 🔍 Pattern Recognition

| Problem Keywords | Window Type | Strategy |
|-----------------|-------------|----------|
| "subarray of size k" | Fixed | Slide and update |
| "longest substring with..." | Variable | Expand, shrink when invalid |
| "shortest subarray with..." | Variable | Shrink while valid |
| "at most K distinct" | Variable | Track with HashMap |
| "maximum sum subarray" | Variable | Kadane's algorithm |
| "contains all characters" | Variable | Two frequency maps |

---

## 💡 Key Insights

### 1. Why Sliding Window Works
- Avoids redundant computation
- Maintains running state as window slides
- Transforms O(n × k) to O(n)

### 2. Choosing Data Structures
- **HashMap/unordered_map:** Track frequency counts
- **Set/unordered_set:** Track unique elements
- **Deque:** Track max/min in window (monotonic deque)

### 3. Common Patterns

**Frequency Counting:**
```cpp
unordered_map<char, int> charFreq;
charFreq[c]++;           // add to window
charFreq[c]--;           // remove from window
if (charFreq[c] == 0) {
    charFreq.erase(c);   // clean up
}
```

**Two Frequency Maps (for anagram/permutation problems):**
```cpp
unordered_map<char, int> targetFreq, windowFreq;
for (char c : target) targetFreq[c]++;
int matches = 0;  // Track how many chars have matching frequencies
```

---

## 📊 Complexity Analysis

| Window Type | Time | Space |
|-------------|------|-------|
| Fixed Size | O(n) | O(1) |
| Variable Size | O(n) | O(k) where k = distinct elements |
| With HashMap | O(n) | O(min(n, alphabet_size)) |

---

## 🎓 Example Walkthrough: Longest Substring Without Repeating Characters

**Problem:** Find length of longest substring without repeating characters.

```
Input: "abcabcbb"
```

**Step-by-step:**
```
[a]bcabcbb      → {a:1}, len=1, max=1
[ab]cabcbb      → {a:1,b:1}, len=2, max=2
[abc]abcbb      → {a:1,b:1,c:1}, len=3, max=3
[abca]bcbb      → {a:2,b:1,c:1} 'a' repeats! shrink
a[bca]bcbb      → {a:1,b:1,c:1}, len=3, max=3
a[bcab]cbb      → {a:1,b:2,c:1} 'b' repeats! shrink
ab[cab]cbb      → {a:1,b:1,c:1}, len=3, max=3
...eventually:
abcab[cb]b      → {c:1,b:1}, len=2
abcabc[b]b      → {b:1}, len=1
abcabcb[b]      → {b:1}, len=1

Maximum = 3
```

**Code:**
```cpp
int lengthOfLongestSubstring(string s) {
    unordered_map<char, int> charIndex;  // char -> last seen index
    int maxLength = 0;
    int windowStart = 0;
    
    for (int windowEnd = 0; windowEnd < s.size(); windowEnd++) {
        char rightChar = s[windowEnd];
        
        // If char seen and inside current window, shrink
        if (charIndex.count(rightChar) && charIndex[rightChar] >= windowStart) {
            windowStart = charIndex[rightChar] + 1;
        }
        
        charIndex[rightChar] = windowEnd;
        maxLength = max(maxLength, windowEnd - windowStart + 1);
    }
    
    return maxLength;
}
```

---

## 🔗 Related Patterns

- **Two Pointers:** Sliding window is a specialized two-pointer technique
- **HashMap:** Often used to track window state
- **Monotonic Deque:** For sliding window max/min problems

---

## 🚨 Common Mistakes

1. **Off-by-one errors:** Window length is `end - start + 1`
2. **Forgetting to clean up:** Remove entries from HashMap when count reaches 0
3. **Wrong shrink condition:** Max problems shrink when invalid, min problems shrink while valid
4. **Not handling empty input:** Check for empty arrays/strings

---

*Next: [See Practice Questions →](./questions.md)*
