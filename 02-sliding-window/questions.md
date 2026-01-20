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

**Approach:**
- Use fixed-size sliding window
- Calculate initial window sum, then slide by adding new and removing old element

**Solution:**
```cpp
double findMaxAverage(vector<int>& nums, int k) {
    double windowSum = 0;
    for (int i = 0; i < k; i++) {
        windowSum += nums[i];
    }
    double maxSum = windowSum;
    
    for (int i = k; i < nums.size(); i++) {
        windowSum += nums[i] - nums[i - k];
        maxSum = max(maxSum, windowSum);
    }
    
    return maxSum / k;
}
```
**Complexity:** Time O(n), Space O(1)

---

### 2. Minimum Recolors to Get K Consecutive Black
**LeetCode #2379**

Find minimum number of white blocks ('W') to recolor to get k consecutive black blocks ('B').

```
Input: blocks = "WBBWWBBWBW", k = 7
Output: 3
```

**Approach:**
- Fixed window of size k, count white blocks in each window
- Track minimum whites across all windows

**Solution:**
```cpp
int minimumRecolors(string blocks, int k) {
    int whites = 0;
    for (int i = 0; i < k; i++) {
        if (blocks[i] == 'W') whites++;
    }
    int minWhites = whites;
    
    for (int i = k; i < blocks.size(); i++) {
        if (blocks[i] == 'W') whites++;
        if (blocks[i - k] == 'W') whites--;
        minWhites = min(minWhites, whites);
    }
    
    return minWhites;
}
```
**Complexity:** Time O(n), Space O(1)

---

## 🟡 Medium Problems

### 3. Longest Substring Without Repeating Characters
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
```cpp
int lengthOfLongestSubstring(string s) {
    unordered_map<char, int> charIndex;
    int maxLength = 0;
    int start = 0;
    
    for (int end = 0; end < s.size(); end++) {
        if (charIndex.count(s[end]) && charIndex[s[end]] >= start) {
            start = charIndex[s[end]] + 1;
        }
        charIndex[s[end]] = end;
        maxLength = max(maxLength, end - start + 1);
    }
    
    return maxLength;
}
```
**Complexity:** Time O(n), Space O(min(n, alphabet_size))

---

### 4. Longest Repeating Character Replacement
**LeetCode #424**

Find longest substring with same letter after replacing at most k characters.

```
Input: s = "AABABBA", k = 1
Output: 4 (Replace one 'A' in "AABA" to get "AAAA")
```

**Approach:**
- Window is valid if: `window_length - max_freq <= k`
- We can replace all non-majority characters

**Solution:**
```cpp
int characterReplacement(string s, int k) {
    unordered_map<char, int> count;
    int maxFreq = 0;
    int maxLength = 0;
    int start = 0;
    
    for (int end = 0; end < s.size(); end++) {
        count[s[end]]++;
        maxFreq = max(maxFreq, count[s[end]]);
        
        // Window invalid: more chars to replace than k allows
        while ((end - start + 1) - maxFreq > k) {
            count[s[start]]--;
            start++;
        }
        
        maxLength = max(maxLength, end - start + 1);
    }
    
    return maxLength;
}
```
**Complexity:** Time O(n), Space O(26) = O(1)

---

### 5. Permutation in String
**LeetCode #567**

Check if s2 contains any permutation of s1.

```
Input: s1 = "ab", s2 = "eidbaooo"
Output: true ("ba" is a permutation of "ab")
```

**Approach:**
- Fixed window of size len(s1)
- Compare character frequencies using array

**Solution:**
```cpp
bool checkInclusion(string s1, string s2) {
    if (s1.size() > s2.size()) return false;
    
    vector<int> s1Count(26, 0), windowCount(26, 0);
    for (int i = 0; i < s1.size(); i++) {
        s1Count[s1[i] - 'a']++;
        windowCount[s2[i] - 'a']++;
    }
    
    if (s1Count == windowCount) return true;
    
    for (int i = s1.size(); i < s2.size(); i++) {
        windowCount[s2[i] - 'a']++;
        windowCount[s2[i - s1.size()] - 'a']--;
        if (s1Count == windowCount) return true;
    }
    
    return false;
}
```
**Complexity:** Time O(n), Space O(26) = O(1)

---

### 6. Find All Anagrams in a String
**LeetCode #438**

Find all start indices of p's anagrams in s.

```
Input: s = "cbaebabacd", p = "abc"
Output: [0, 6]
```

**Approach:**
- Same as Permutation in String, but collect all matching indices

**Solution:**
```cpp
vector<int> findAnagrams(string s, string p) {
    vector<int> result;
    if (p.size() > s.size()) return result;
    
    vector<int> pCount(26, 0), windowCount(26, 0);
    for (int i = 0; i < p.size(); i++) {
        pCount[p[i] - 'a']++;
        windowCount[s[i] - 'a']++;
    }
    
    if (pCount == windowCount) result.push_back(0);
    
    for (int i = p.size(); i < s.size(); i++) {
        windowCount[s[i] - 'a']++;
        windowCount[s[i - p.size()] - 'a']--;
        if (pCount == windowCount) {
            result.push_back(i - p.size() + 1);
        }
    }
    
    return result;
}
```
**Complexity:** Time O(n), Space O(26) = O(1)

---

### 7. Max Consecutive Ones III
**LeetCode #1004**

Find longest subarray of 1s after flipping at most k 0s.

```
Input: nums = [1,1,1,0,0,0,1,1,1,1,0], k = 2
Output: 6
```

**Approach:**
- Variable window tracking count of zeros
- Shrink when zeros exceed k

**Solution:**
```cpp
int longestOnes(vector<int>& nums, int k) {
    int start = 0;
    int zeros = 0;
    int maxLength = 0;
    
    for (int end = 0; end < nums.size(); end++) {
        if (nums[end] == 0) zeros++;
        
        while (zeros > k) {
            if (nums[start] == 0) zeros--;
            start++;
        }
        
        maxLength = max(maxLength, end - start + 1);
    }
    
    return maxLength;
}
```
**Complexity:** Time O(n), Space O(1)

---

### 8. Fruit Into Baskets
**LeetCode #904**

Find longest subarray with at most 2 distinct elements.

```
Input: fruits = [1,2,3,2,2]
Output: 4 ([2,3,2,2])
```

**Approach:**
- Variable window with map tracking fruit counts
- Shrink when more than 2 distinct fruits

**Solution:**
```cpp
int totalFruit(vector<int>& fruits) {
    unordered_map<int, int> basket;
    int start = 0;
    int maxFruits = 0;
    
    for (int end = 0; end < fruits.size(); end++) {
        basket[fruits[end]]++;
        
        while (basket.size() > 2) {
            basket[fruits[start]]--;
            if (basket[fruits[start]] == 0) {
                basket.erase(fruits[start]);
            }
            start++;
        }
        
        maxFruits = max(maxFruits, end - start + 1);
    }
    
    return maxFruits;
}
```
**Complexity:** Time O(n), Space O(1)

---

### 9. Subarray Product Less Than K
**LeetCode #713**

Count subarrays where product of elements < k.

```
Input: nums = [10,5,2,6], k = 100
Output: 8
```

**Approach:**
- For each ending position, count new valid subarrays
- New subarrays ending at `end` = `end - start + 1`

**Solution:**
```cpp
int numSubarrayProductLessThanK(vector<int>& nums, int k) {
    if (k <= 1) return 0;
    
    int product = 1;
    int start = 0;
    int count = 0;
    
    for (int end = 0; end < nums.size(); end++) {
        product *= nums[end];
        
        while (product >= k) {
            product /= nums[start];
            start++;
        }
        
        // All subarrays ending at 'end' with start from 'start' to 'end'
        count += end - start + 1;
    }
    
    return count;
}
```
**Complexity:** Time O(n), Space O(1)

---

### 10. Minimum Size Subarray Sum
**LeetCode #209**

Find minimal length subarray with sum >= target.

```
Input: target = 7, nums = [2,3,1,2,4,3]
Output: 2 ([4,3])
```

**Approach:**
- Variable window, shrink while sum >= target to find minimum

**Solution:**
```cpp
int minSubArrayLen(int target, vector<int>& nums) {
    int minLength = INT_MAX;
    int currentSum = 0;
    int start = 0;
    
    for (int end = 0; end < nums.size(); end++) {
        currentSum += nums[end];
        
        while (currentSum >= target) {
            minLength = min(minLength, end - start + 1);
            currentSum -= nums[start];
            start++;
        }
    }
    
    return minLength == INT_MAX ? 0 : minLength;
}
```
**Complexity:** Time O(n), Space O(1)

---

## 🔴 Hard Problems

### 11. Minimum Window Substring
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
```cpp
string minWindow(string s, string t) {
    if (t.empty() || s.empty()) return "";
    
    unordered_map<char, int> tCount, windowCount;
    for (char c : t) tCount[c]++;
    
    int required = tCount.size();
    int formed = 0;
    int minLen = INT_MAX, minLeft = 0;
    int left = 0;
    
    for (int right = 0; right < s.size(); right++) {
        char c = s[right];
        windowCount[c]++;
        
        if (tCount.count(c) && windowCount[c] == tCount[c]) {
            formed++;
        }
        
        while (formed == required) {
            if (right - left + 1 < minLen) {
                minLen = right - left + 1;
                minLeft = left;
            }
            
            char leftChar = s[left];
            windowCount[leftChar]--;
            if (tCount.count(leftChar) && windowCount[leftChar] < tCount[leftChar]) {
                formed--;
            }
            left++;
        }
    }
    
    return minLen == INT_MAX ? "" : s.substr(minLeft, minLen);
}
```
**Complexity:** Time O(n + m), Space O(n + m)

---

### 12. Sliding Window Maximum
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
```cpp
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    deque<int> dq;  // Store indices
    vector<int> result;
    
    for (int i = 0; i < nums.size(); i++) {
        // Remove indices outside window
        while (!dq.empty() && dq.front() < i - k + 1) {
            dq.pop_front();
        }
        
        // Remove smaller elements (maintain decreasing order)
        while (!dq.empty() && nums[dq.back()] < nums[i]) {
            dq.pop_back();
        }
        
        dq.push_back(i);
        
        // Start adding to result when first window is complete
        if (i >= k - 1) {
            result.push_back(nums[dq.front()]);
        }
    }
    
    return result;
}
```
**Complexity:** Time O(n), Space O(k)

---

### 13. Substring with Concatenation of All Words
**LeetCode #30**

Find all starting indices of substrings that are concatenation of all words.

```
Input: s = "barfoothefoobarman", words = ["foo","bar"]
Output: [0,9]
```

**Approach:**
- Fixed window of size words.size() * word_length
- Check all starting positions within one word length

**Solution:**
```cpp
vector<int> findSubstring(string s, vector<string>& words) {
    vector<int> result;
    if (s.empty() || words.empty()) return result;
    
    int wordLen = words[0].size();
    int wordCount = words.size();
    int totalLen = wordLen * wordCount;
    
    if (s.size() < totalLen) return result;
    
    unordered_map<string, int> wordMap;
    for (const string& word : words) {
        wordMap[word]++;
    }
    
    for (int i = 0; i < wordLen; i++) {
        int left = i, count = 0;
        unordered_map<string, int> seen;
        
        for (int j = i; j + wordLen <= s.size(); j += wordLen) {
            string word = s.substr(j, wordLen);
            
            if (wordMap.count(word)) {
                seen[word]++;
                count++;
                
                while (seen[word] > wordMap[word]) {
                    string leftWord = s.substr(left, wordLen);
                    seen[leftWord]--;
                    count--;
                    left += wordLen;
                }
                
                if (count == wordCount) {
                    result.push_back(left);
                }
            } else {
                seen.clear();
                count = 0;
                left = j + wordLen;
            }
        }
    }
    
    return result;
}
```
**Complexity:** Time O(n * wordLen), Space O(m) where m = number of words

---

## 📚 Study Tips for Sliding Window

1. **Fixed vs Variable:** Know when to use each type
2. **Window State:** Choose the right data structure (map, set, deque)
3. **Shrink Condition:** Max problems shrink when invalid, min problems shrink while valid
4. **Count vs Index:** Decide whether to track frequency or last index

---

*[← Back to Pattern](./README.md) | [Next Pattern: Fast & Slow Pointers →](../03-fast-slow-pointers/README.md)*
