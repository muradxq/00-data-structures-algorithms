# 📝 Bit Manipulation - Practice Questions

## Question Checklist

| # | Problem | Difficulty | Type | Status |
|---|---------|------------|------|--------|
| 1 | Single Number | Easy | XOR | ⬜ |
| 2 | Number of 1 Bits | Easy | Count | ⬜ |
| 3 | Counting Bits | Easy | DP + Bits | ⬜ |
| 4 | Reverse Bits | Easy | Manipulation | ⬜ |
| 5 | Missing Number | Easy | XOR | ⬜ |
| 6 | Sum of Two Integers | Medium | No arithmetic | ⬜ |
| 7 | Single Number II | Medium | Bit Count | ⬜ |
| 8 | Single Number III | Medium | XOR + Partition | ⬜ |

---

## 🟢 Easy Problems

### 1. Single Number
**LeetCode #136**

Find element that appears once (others appear twice).

```
Input: nums = [2,2,1]
Output: 1
```

**Solution:**
```python
def singleNumber(nums):
    result = 0
    for num in nums:
        result ^= num
    return result
```
**Complexity:** Time O(n), Space O(1)

---

### 2. Number of 1 Bits
**LeetCode #191**

Count set bits (Hamming weight).

```
Input: n = 11 (binary: 1011)
Output: 3
```

**Solution:**
```python
def hammingWeight(n):
    count = 0
    while n:
        n &= n - 1
        count += 1
    return count
```
**Complexity:** Time O(log n), Space O(1)

---

### 3. Counting Bits
**LeetCode #338**

Count bits for all numbers from 0 to n.

```
Input: n = 5
Output: [0,1,1,2,1,2]
```

**Solution:**
```python
def countBits(n):
    dp = [0] * (n + 1)
    for i in range(1, n + 1):
        dp[i] = dp[i >> 1] + (i & 1)
    return dp
```
**Complexity:** Time O(n), Space O(n)

---

### 4. Missing Number
**LeetCode #268**

Find missing number in [0, n].

```
Input: nums = [3,0,1]
Output: 2
```

**Solution:**
```python
def missingNumber(nums):
    result = len(nums)
    for i, num in enumerate(nums):
        result ^= i ^ num
    return result
```
**Complexity:** Time O(n), Space O(1)

---

## 🟡 Medium Problems

### 5. Sum of Two Integers
**LeetCode #371**

Sum without + or - operators.

**Solution:**
```python
def getSum(a, b):
    mask = 0xFFFFFFFF
    
    while b & mask:
        carry = (a & b) << 1
        a = a ^ b
        b = carry
    
    return a if b == 0 else ~(a ^ mask)
```
**Complexity:** Time O(1), Space O(1)

---

### 6. Single Number III
**LeetCode #260**

Find two elements that appear once (others appear twice).

```
Input: nums = [1,2,1,3,2,5]
Output: [3,5]
```

**Solution:**
```python
def singleNumber(nums):
    xor = 0
    for num in nums:
        xor ^= num
    
    # Find rightmost set bit
    diff_bit = xor & (-xor)
    
    # Partition and XOR
    a = 0
    for num in nums:
        if num & diff_bit:
            a ^= num
    
    return [a, xor ^ a]
```
**Complexity:** Time O(n), Space O(1)

---

## 📚 Study Tips for Bit Manipulation

1. **Know XOR properties:** Self-cancellation is key
2. **Practice binary:** Visualize operations mentally
3. **Common tricks:** `n & (n-1)`, `n & (-n)`
4. **Watch for overflow:** Use masks in Python

---

*[← Back to Pattern](./README.md) | [Next Pattern: Greedy →](../19-greedy/README.md)*
