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

**Approach:**
- XOR of same numbers is 0
- XOR of 0 and any number is the number itself
- XOR all numbers to get the single one

**Solution:**
```cpp
int singleNumber(vector<int>& nums) {
    int result = 0;
    for (int num : nums) {
        result ^= num;
    }
    return result;
}
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

**Approach:**
- n & (n-1) removes the rightmost set bit
- Count how many times until n becomes 0

**Solution:**
```cpp
int hammingWeight(uint32_t n) {
    int count = 0;
    while (n) {
        n &= n - 1;
        count++;
    }
    return count;
}
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

**Approach:**
- dp[i] = dp[i >> 1] + (i & 1)
- Number of bits = bits in i/2 + last bit

**Solution:**
```cpp
vector<int> countBits(int n) {
    vector<int> dp(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        dp[i] = dp[i >> 1] + (i & 1);
    }
    return dp;
}
```
**Complexity:** Time O(n), Space O(n)

---

### 4. Reverse Bits
**LeetCode #190**

Reverse bits of a 32-bit unsigned integer.

```
Input: n = 43261596 (00000010100101000001111010011100)
Output: 964176192 (00111001011110000010100101000000)
```

**Approach:**
- Extract each bit from right, build result from left

**Solution:**
```cpp
uint32_t reverseBits(uint32_t n) {
    uint32_t result = 0;
    for (int i = 0; i < 32; i++) {
        result = (result << 1) | (n & 1);
        n >>= 1;
    }
    return result;
}
```
**Complexity:** Time O(1), Space O(1)

---

### 5. Missing Number
**LeetCode #268**

Find missing number in [0, n].

```
Input: nums = [3,0,1]
Output: 2
```

**Approach:**
- XOR all indices (0 to n) with all values
- Duplicates cancel out, leaving the missing number

**Solution:**
```cpp
int missingNumber(vector<int>& nums) {
    int result = nums.size();
    for (int i = 0; i < nums.size(); i++) {
        result ^= i ^ nums[i];
    }
    return result;
}
```
**Complexity:** Time O(n), Space O(1)

---

## 🟡 Medium Problems

### 6. Sum of Two Integers
**LeetCode #371**

Sum without + or - operators.

```
Input: a = 1, b = 2
Output: 3
```

**Approach:**
- XOR gives sum without carry
- AND shifted left gives carry
- Repeat until no carry

**Solution:**
```cpp
int getSum(int a, int b) {
    while (b != 0) {
        unsigned carry = (unsigned)(a & b) << 1;
        a = a ^ b;
        b = carry;
    }
    return a;
}
```
**Complexity:** Time O(1), Space O(1)

---

### 7. Single Number II
**LeetCode #137**

Find element that appears once (others appear three times).

```
Input: nums = [2,2,3,2]
Output: 3
```

**Approach:**
- Count bits at each position modulo 3
- Remaining bits form the single number

**Solution:**
```cpp
int singleNumber(vector<int>& nums) {
    int result = 0;
    for (int i = 0; i < 32; i++) {
        int sum = 0;
        for (int num : nums) {
            sum += (num >> i) & 1;
        }
        result |= (sum % 3) << i;
    }
    return result;
}
```
**Complexity:** Time O(n), Space O(1)

---

### 8. Single Number III
**LeetCode #260**

Find two elements that appear once (others appear twice).

```
Input: nums = [1,2,1,3,2,5]
Output: [3,5]
```

**Approach:**
- XOR all gets a ^ b
- Find rightmost different bit
- Partition numbers and XOR each group

**Solution:**
```cpp
vector<int> singleNumber(vector<int>& nums) {
    // Get XOR of the two single numbers
    long xorAll = 0;
    for (int num : nums) {
        xorAll ^= num;
    }
    
    // Find rightmost set bit (where a and b differ)
    long diffBit = xorAll & (-xorAll);
    
    // Partition and XOR
    int a = 0;
    for (int num : nums) {
        if (num & diffBit) {
            a ^= num;
        }
    }
    
    return {a, (int)(xorAll ^ a)};
}
```
**Complexity:** Time O(n), Space O(1)

---

## 📚 Study Tips for Bit Manipulation

1. **Know XOR properties:** a ^ a = 0, a ^ 0 = a
2. **Practice binary:** Visualize operations mentally
3. **Common tricks:** 
   - `n & (n-1)` removes rightmost set bit
   - `n & (-n)` isolates rightmost set bit
4. **Watch for overflow:** Use unsigned types when needed

---

*[← Back to Pattern](./README.md) | [Next Pattern: Greedy →](../19-greedy/README.md)*
