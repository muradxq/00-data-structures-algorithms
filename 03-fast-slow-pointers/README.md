# 🐢🐇 Fast & Slow Pointers Pattern

## Overview

The **Fast & Slow Pointers** pattern (also known as **Floyd's Tortoise and Hare** algorithm) uses two pointers moving at different speeds to solve problems involving cycles, middle elements, or specific positions in linked lists and arrays.

---

## 🧠 When to Use Fast & Slow Pointers

Use this pattern when:
- **Cycle detection** in linked lists or arrays
- Finding the **middle** of a linked list
- Finding the **start of a cycle**
- Determining if a linked list is a **palindrome**
- Problems with numbers involving **cycle patterns** (like happy numbers)

---

## 🎯 Core Concept

```
Linked List: 1 → 2 → 3 → 4 → 5 → 6

Step 0: slow=1, fast=1
Step 1: slow=2, fast=3  (slow moves 1, fast moves 2)
Step 2: slow=3, fast=5
Step 3: slow=4, fast=null (or beyond)

When fast reaches end, slow is at middle!
```

---

## 📐 General Templates

### Find Middle of Linked List
```cpp
ListNode* findMiddle(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;
    
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    
    return slow;  // slow is at middle
}
```

### Detect Cycle in Linked List
```cpp
bool hasCycle(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;
    
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        
        if (slow == fast) {
            return true;  // Cycle found
        }
    }
    
    return false;  // No cycle
}
```

### Find Cycle Start
```cpp
ListNode* findCycleStart(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;
    
    // Phase 1: Detect cycle
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        
        if (slow == fast) {
            break;
        }
    }
    
    // No cycle
    if (!fast || !fast->next) {
        return nullptr;
    }
    
    // Phase 2: Find start
    // Move slow to head, keep fast at meeting point
    // Move both at same speed - they'll meet at cycle start
    slow = head;
    while (slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }
    
    return slow;  // Cycle start
}
```

---

## 🔬 Why Does Finding Cycle Start Work?

```
Let's say:
- Distance from head to cycle start = a
- Distance from cycle start to meeting point = b
- Cycle length = c

When they meet:
- Slow traveled: a + b
- Fast traveled: a + b + n*c (fast completed n cycles)

Since fast travels 2x speed:
2(a + b) = a + b + n*c
a + b = n*c
a = n*c - b
a = (n-1)*c + (c - b)

This means: distance from head to cycle start equals
            distance from meeting point to cycle start (going forward)
```

---

## 💡 Key Insights

### 1. Meeting Point Mathematics
- In a cycle of length `L`, fast pointer gains 1 step per iteration
- They'll always meet within `L` iterations after slow enters the cycle

### 2. Middle Element Variations
```cpp
// For even length lists:
// 1 → 2 → 3 → 4 → null
// Standard approach gives 3 (second middle)

// To get first middle (2):
while (fast->next && fast->next->next) {
    slow = slow->next;
    fast = fast->next->next;
}
```

### 3. Linked List vs Array
- **Linked List:** Move by following `next` pointers
- **Array:** Treat values as next indices

---

## 📊 Complexity Analysis

| Operation | Time | Space |
|-----------|------|-------|
| Find Middle | O(n) | O(1) |
| Detect Cycle | O(n) | O(1) |
| Find Cycle Start | O(n) | O(1) |

---

## 🎓 Example Walkthrough: Happy Number

**Problem:** A happy number eventually reaches 1 when you repeatedly replace it with sum of squares of its digits. Detect if a number is happy.

**Example:** 
```
19 → 1² + 9² = 82
82 → 8² + 2² = 68
68 → 6² + 8² = 100
100 → 1² + 0² + 0² = 1 ✓ Happy!
```

**Unhappy numbers form a cycle that doesn't include 1:**
```
2 → 4 → 16 → 37 → 58 → 89 → 145 → 42 → 20 → 4 (cycle!)
```

**Solution:**
```cpp
class Solution {
public:
    int getNext(int num) {
        int total = 0;
        while (num > 0) {
            int digit = num % 10;
            total += digit * digit;
            num /= 10;
        }
        return total;
    }
    
    bool isHappy(int n) {
        int slow = n;
        int fast = getNext(n);
        
        while (fast != 1 && slow != fast) {
            slow = getNext(slow);
            fast = getNext(getNext(fast));
        }
        
        return fast == 1;
    }
};
```

---

## 🔗 Related Patterns

- **Two Pointers:** Fast & Slow is a specialized two-pointer technique
- **Linked List Reversal:** Often combined with fast/slow to check palindromes

---

## 🚨 Common Mistakes

1. **Null pointer check:** Always check `fast` AND `fast->next` before moving fast
2. **Off-by-one in middle:** Know whether you want first or second middle
3. **Forgetting Phase 2:** Finding cycle start requires two phases

---

*Next: [See Practice Questions →](./questions.md)*
