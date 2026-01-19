# 🎯 Greedy Pattern

## Overview

**Greedy** algorithms make locally optimal choices at each step, hoping to find the global optimum. Unlike DP which considers all possibilities, greedy commits to one choice and never looks back.

---

## 🧠 When to Use Greedy

Use this pattern when:
- Problem has **optimal substructure**
- **Greedy choice property** holds (local optimal → global optimal)
- Keywords: "minimum/maximum", "optimization", "schedule", "interval"
- Can prove that greedy choice never leads to worse outcome

---

## 🎯 Common Greedy Patterns

### 1. Interval Scheduling
Sort by end time, greedily select non-overlapping intervals.

### 2. Fractional Knapsack
Take items with best value/weight ratio first.

### 3. Activity Selection
Choose activities that leave maximum room for others.

### 4. Huffman Coding
Always combine two smallest frequencies.

---

## 📐 Templates

### Interval Scheduling (Maximum Non-overlapping)
```cpp
int maxNonOverlapping(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end(), 
         [](auto& a, auto& b) { return a[1] < b[1]; });  // Sort by end
    
    int count = 0;
    int end = INT_MIN;
    
    for (auto& interval : intervals) {
        if (interval[0] >= end) {
            count++;
            end = interval[1];
        }
    }
    
    return count;
}
```

### Jump Game
```cpp
bool canJump(vector<int>& nums) {
    int maxReach = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (i > maxReach) {
            return false;
        }
        maxReach = max(maxReach, i + nums[i]);
    }
    return true;
}
```

---

## 💡 Key Insights

### Greedy vs DP
| Greedy | DP |
|--------|---|
| Makes one choice | Explores all choices |
| No backtracking | Builds on subproblems |
| O(n) or O(n log n) | Often O(n²) or more |
| Must prove correctness | Always finds optimum |

### Proving Greedy Works
1. **Exchange argument:** Show that swapping to greedy choice doesn't worsen solution
2. **Greedy stays ahead:** Show greedy is always at least as good as alternatives

---

*Next: [See Practice Questions →](./questions.md)*
