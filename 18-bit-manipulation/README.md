# 🔢 Bit Manipulation Pattern

## Overview

**Bit Manipulation** involves using bitwise operators to solve problems efficiently. Understanding binary representation and bit operations can lead to elegant O(1) or O(log n) solutions.

---

## 🧠 When to Use Bit Manipulation

Use this pattern when:
- Working with **binary** representations
- Need to check **powers of two**
- Finding **single/unique** elements
- Performing **operations without arithmetic**
- Keywords: "binary", "bits", "single number", "power of two"

---

## 🎯 Essential Bit Operations

```cpp
// Basic Operations
a & b   // AND: both bits are 1
a | b   // OR: either bit is 1
a ^ b   // XOR: bits are different
~a      // NOT: flip all bits
a << n  // Left shift: multiply by 2^n
a >> n  // Right shift: divide by 2^n

// Useful Tricks
x & 1           // Check if odd
x & (x - 1)     // Remove lowest set bit
x & (-x)        // Get lowest set bit
x ^ x == 0      // XOR with itself = 0
x ^ 0 == x      // XOR with 0 = x
```

---

## 📐 Common Patterns

### Check if Power of Two
```cpp
bool isPowerOfTwo(int n) {
    return n > 0 && (n & (n - 1)) == 0;
}
```

### Count Set Bits (Hamming Weight)
```cpp
int hammingWeight(uint32_t n) {
    int count = 0;
    while (n) {
        n &= n - 1;  // Remove lowest set bit
        count++;
    }
    return count;
}
```

### Single Number (XOR)
```cpp
int singleNumber(vector<int>& nums) {
    int result = 0;
    for (int num : nums) {
        result ^= num;
    }
    return result;
}
```

### Get/Set/Clear Bit
```cpp
int getBit(int n, int i) {
    return (n >> i) & 1;
}

int setBit(int n, int i) {
    return n | (1 << i);
}

int clearBit(int n, int i) {
    return n & ~(1 << i);
}
```

---

## 💡 Key Insights

### XOR Properties
- `a ^ a = 0` (same numbers cancel)
- `a ^ 0 = a` (zero is identity)
- `a ^ b ^ a = b` (cancellation)
- Commutative and associative

### Common Bit Masks
| Operation | Code |
|-----------|------|
| All 1s | `~0` |
| Lower n bits | `(1 << n) - 1` |
| Only bit i | `1 << i` |
| Clear bit i | `~(1 << i)` |

---

## 📊 Complexity

Most bit operations are O(1) or O(log n) for the number of bits.

---

*Next: [See Practice Questions →](./questions.md)*
