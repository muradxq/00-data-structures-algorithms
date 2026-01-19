# 📅 Merge Intervals Pattern

## Overview

The **Merge Intervals** pattern deals with problems involving overlapping intervals. The key insight is that sorting intervals by start time allows us to process them in order and identify overlaps efficiently.

---

## 🧠 When to Use Merge Intervals

Use this pattern when:
- Problems involve **ranges** or **intervals**
- Keywords: "merge", "overlapping", "insert interval", "schedule", "meeting rooms"
- You need to find **conflicts** between time periods
- Combining or splitting **ranges**

---

## 🎯 Core Concept

### What is an Overlap?
Two intervals [a, b] and [c, d] overlap if they share any point:
```
Overlap: a <= d AND c <= b

[a----b]
   [c----d]      ✓ Overlap

[a----b]
         [c----d]  ✗ No overlap (b < c)
```

### Merging Two Intervals
When two intervals overlap, merge them:
```
Merged: [min(a, c), max(b, d)]

[1----5]
   [3----7]
= [1-------7]
```

---

## 📐 General Templates

### Template 1: Merge Overlapping Intervals
```cpp
vector<vector<int>> mergeIntervals(vector<vector<int>>& intervals) {
    if (intervals.empty()) return {};
    
    // Sort by start time
    sort(intervals.begin(), intervals.end());
    
    vector<vector<int>> merged;
    merged.push_back(intervals[0]);
    
    for (int i = 1; i < intervals.size(); i++) {
        vector<int>& last = merged.back();
        vector<int>& current = intervals[i];
        
        // Check if overlapping
        if (current[0] <= last[1]) {
            // Merge: extend end time
            last[1] = max(last[1], current[1]);
        } else {
            // No overlap: add new interval
            merged.push_back(current);
        }
    }
    
    return merged;
}
```

### Template 2: Insert Interval
```cpp
vector<vector<int>> insertInterval(vector<vector<int>>& intervals, vector<int> newInterval) {
    vector<vector<int>> result;
    int i = 0;
    int n = intervals.size();
    
    // Add all intervals ending before new interval starts
    while (i < n && intervals[i][1] < newInterval[0]) {
        result.push_back(intervals[i]);
        i++;
    }
    
    // Merge overlapping intervals
    while (i < n && intervals[i][0] <= newInterval[1]) {
        newInterval[0] = min(newInterval[0], intervals[i][0]);
        newInterval[1] = max(newInterval[1], intervals[i][1]);
        i++;
    }
    result.push_back(newInterval);
    
    // Add remaining intervals
    while (i < n) {
        result.push_back(intervals[i]);
        i++;
    }
    
    return result;
}
```

### Template 3: Find Minimum Meeting Rooms
```cpp
int minMeetingRooms(vector<vector<int>>& intervals) {
    if (intervals.empty()) return 0;
    
    // Separate start and end times
    vector<int> starts, ends;
    for (auto& interval : intervals) {
        starts.push_back(interval[0]);
        ends.push_back(interval[1]);
    }
    
    sort(starts.begin(), starts.end());
    sort(ends.begin(), ends.end());
    
    int rooms = 0;
    int endPtr = 0;
    
    for (int start : starts) {
        if (start < ends[endPtr]) {
            rooms++;  // Need new room
        } else {
            endPtr++;  // Room freed up
        }
    }
    
    return rooms;
}
```

---

## 💡 Key Insights

### 1. Sorting is Crucial
Always sort intervals first (usually by start time).

### 2. Overlap Conditions
```cpp
// Two intervals [s1, e1] and [s2, e2] where s1 <= s2:
// Overlap:    s2 <= e1
// No overlap: s2 > e1
```

### 3. Three Cases for Two Intervals
```
Case 1: No overlap
[---A---]     [---B---]

Case 2: Partial overlap
[---A---]
    [---B---]

Case 3: Complete overlap (one contains another)
[------A------]
   [--B--]
```

### 4. Event Counting Technique
For problems like "minimum rooms needed":
- Create events: +1 for start, -1 for end
- Process events in order
- Track running count

```cpp
vector<pair<int, int>> events;
for (auto& interval : intervals) {
    events.push_back({interval[0], 1});   // Meeting starts
    events.push_back({interval[1], -1});  // Meeting ends
}

sort(events.begin(), events.end());
int maxRooms = 0, currentRooms = 0;
for (auto& event : events) {
    currentRooms += event.second;
    maxRooms = max(maxRooms, currentRooms);
}
```

---

## 📊 Complexity Analysis

| Operation | Time | Space |
|-----------|------|-------|
| Merge Intervals | O(n log n) | O(n) |
| Insert Interval | O(n) | O(n) |
| Meeting Rooms | O(n log n) | O(n) |

---

## 🎓 Example Walkthrough: Merge Intervals

**Problem:** Merge all overlapping intervals.

```
Input: [[1,3], [2,6], [8,10], [15,18]]
```

**Step-by-step:**
```
After sorting: [[1,3], [2,6], [8,10], [15,18]] (already sorted)

merged = [[1,3]]

Process [2,6]:
  - 2 <= 3? Yes, overlap!
  - Merge: [1, max(3,6)] = [1,6]
  - merged = [[1,6]]

Process [8,10]:
  - 8 <= 6? No, no overlap
  - Add new interval
  - merged = [[1,6], [8,10]]

Process [15,18]:
  - 15 <= 10? No, no overlap
  - Add new interval
  - merged = [[1,6], [8,10], [15,18]]

Output: [[1,6], [8,10], [15,18]]
```

---

## 🔗 Related Patterns

- **Sorting:** Always a prerequisite
- **Two Pointers:** Sometimes used to merge
- **Heap:** For problems requiring minimum/maximum tracking

---

## 🚨 Common Mistakes

1. **Forgetting to sort:** Always sort first!
2. **Wrong overlap check:** Remember `current[0] <= last[1]`
3. **Not updating end time:** Use `max()` when merging
4. **Off-by-one:** Be careful with inclusive vs exclusive boundaries

---

*Next: [See Practice Questions →](./questions.md)*
