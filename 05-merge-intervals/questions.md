# 📝 Merge Intervals - Practice Questions

## Question Checklist

| # | Problem | Difficulty | Type | Status |
|---|---------|------------|------|--------|
| 1 | Merge Intervals | Medium | Merge | ⬜ |
| 2 | Insert Interval | Medium | Insert | ⬜ |
| 3 | Non-overlapping Intervals | Medium | Remove | ⬜ |
| 4 | Meeting Rooms | Easy | Overlap Check | ⬜ |
| 5 | Meeting Rooms II | Medium | Count Rooms | ⬜ |
| 6 | Interval List Intersections | Medium | Intersection | ⬜ |
| 7 | Minimum Number of Arrows | Medium | Greedy | ⬜ |
| 8 | Employee Free Time | Hard | Merge | ⬜ |

---

## 🟢 Easy Problems

### 1. Meeting Rooms
**LeetCode #252** (Premium)

Determine if a person could attend all meetings.

```
Input: [[0,30],[5,10],[15,20]]
Output: false (meetings overlap)

Input: [[7,10],[2,4]]
Output: true
```

**Solution:**
```python
def canAttendMeetings(intervals):
    intervals.sort(key=lambda x: x[0])
    
    for i in range(1, len(intervals)):
        if intervals[i][0] < intervals[i-1][1]:
            return False
    
    return True
```
**Complexity:** Time O(n log n), Space O(1)

---

## 🟡 Medium Problems

### 2. Merge Intervals
**LeetCode #56**

Merge all overlapping intervals.

```
Input: [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
```

**Solution:**
```python
def merge(intervals):
    if not intervals:
        return []
    
    intervals.sort(key=lambda x: x[0])
    merged = [intervals[0]]
    
    for current in intervals[1:]:
        if current[0] <= merged[-1][1]:
            merged[-1][1] = max(merged[-1][1], current[1])
        else:
            merged.append(current)
    
    return merged
```
**Complexity:** Time O(n log n), Space O(n)

---

### 3. Insert Interval
**LeetCode #57**

Insert new interval into sorted non-overlapping intervals, merging if needed.

```
Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
Output: [[1,5],[6,9]]
```

**Solution:**
```python
def insert(intervals, newInterval):
    result = []
    i = 0
    n = len(intervals)
    
    # Add all intervals before newInterval
    while i < n and intervals[i][1] < newInterval[0]:
        result.append(intervals[i])
        i += 1
    
    # Merge overlapping intervals
    while i < n and intervals[i][0] <= newInterval[1]:
        newInterval[0] = min(newInterval[0], intervals[i][0])
        newInterval[1] = max(newInterval[1], intervals[i][1])
        i += 1
    result.append(newInterval)
    
    # Add remaining intervals
    while i < n:
        result.append(intervals[i])
        i += 1
    
    return result
```
**Complexity:** Time O(n), Space O(n)

---

### 4. Non-overlapping Intervals
**LeetCode #435**

Find minimum number of intervals to remove to make rest non-overlapping.

```
Input: [[1,2],[2,3],[3,4],[1,3]]
Output: 1 (Remove [1,3])
```

**Key Insight:** Greedy - always keep interval that ends earliest.

**Solution:**
```python
def eraseOverlapIntervals(intervals):
    if not intervals:
        return 0
    
    # Sort by end time
    intervals.sort(key=lambda x: x[1])
    
    count = 0
    prev_end = float('-inf')
    
    for start, end in intervals:
        if start >= prev_end:
            prev_end = end  # Keep this interval
        else:
            count += 1  # Remove this interval
    
    return count
```
**Complexity:** Time O(n log n), Space O(1)

---

### 5. Meeting Rooms II
**LeetCode #253** (Premium)

Find minimum number of conference rooms required.

```
Input: [[0,30],[5,10],[15,20]]
Output: 2
```

**Approach 1: Two Pointers**
```python
def minMeetingRooms(intervals):
    if not intervals:
        return 0
    
    starts = sorted([i[0] for i in intervals])
    ends = sorted([i[1] for i in intervals])
    
    rooms = 0
    end_ptr = 0
    
    for start in starts:
        if start < ends[end_ptr]:
            rooms += 1
        else:
            end_ptr += 1
    
    return rooms
```

**Approach 2: Min Heap**
```python
import heapq

def minMeetingRooms(intervals):
    if not intervals:
        return 0
    
    intervals.sort(key=lambda x: x[0])
    heap = []  # Track end times
    
    for start, end in intervals:
        if heap and heap[0] <= start:
            heapq.heappop(heap)  # Room freed
        heapq.heappush(heap, end)
    
    return len(heap)
```
**Complexity:** Time O(n log n), Space O(n)

---

### 6. Interval List Intersections
**LeetCode #986**

Find intersection of two lists of closed intervals.

```
Input: firstList = [[0,2],[5,10],[13,23],[24,25]]
       secondList = [[1,5],[8,12],[15,24],[25,26]]
Output: [[1,2],[5,5],[8,10],[15,23],[24,24],[25,25]]
```

**Solution:**
```python
def intervalIntersection(firstList, secondList):
    result = []
    i = j = 0
    
    while i < len(firstList) and j < len(secondList):
        # Find intersection
        start = max(firstList[i][0], secondList[j][0])
        end = min(firstList[i][1], secondList[j][1])
        
        if start <= end:
            result.append([start, end])
        
        # Move pointer with smaller end
        if firstList[i][1] < secondList[j][1]:
            i += 1
        else:
            j += 1
    
    return result
```
**Complexity:** Time O(m + n), Space O(1)

---

### 7. Minimum Number of Arrows to Burst Balloons
**LeetCode #452**

Balloons as horizontal intervals. Find minimum arrows (vertical lines) to burst all.

```
Input: [[10,16],[2,8],[1,6],[7,12]]
Output: 2
```

**Key:** Same as finding maximum non-overlapping intervals.

**Solution:**
```python
def findMinArrowPoints(points):
    if not points:
        return 0
    
    # Sort by end position
    points.sort(key=lambda x: x[1])
    
    arrows = 1
    arrow_pos = points[0][1]
    
    for start, end in points[1:]:
        if start > arrow_pos:  # Need new arrow
            arrows += 1
            arrow_pos = end
    
    return arrows
```
**Complexity:** Time O(n log n), Space O(1)

---

## 🔴 Hard Problems

### 8. Employee Free Time
**LeetCode #759** (Premium)

Find common free time across all employees.

```
Input: schedule = [[[1,2],[5,6]],[[1,3]],[[4,10]]]
Output: [[3,4]]
```

**Solution:**
```python
def employeeFreeTime(schedule):
    # Flatten all intervals
    intervals = []
    for employee in schedule:
        for interval in employee:
            intervals.append(interval)
    
    # Sort by start time
    intervals.sort(key=lambda x: x[0])
    
    # Merge to find busy times
    merged = [intervals[0]]
    for current in intervals[1:]:
        if current[0] <= merged[-1][1]:
            merged[-1][1] = max(merged[-1][1], current[1])
        else:
            merged.append(current)
    
    # Find gaps (free time)
    result = []
    for i in range(1, len(merged)):
        result.append([merged[i-1][1], merged[i][0]])
    
    return result
```
**Complexity:** Time O(n log n), Space O(n)

---

## 📚 Study Tips for Intervals

1. **Sort first:** Almost always sort by start time (or end time for greedy)
2. **Draw it out:** Visualize intervals on a number line
3. **Track the right thing:** Sometimes track end times, sometimes count rooms
4. **Consider events:** Start/end as +1/-1 events can simplify counting

---

*[← Back to Pattern](./README.md) | [Next Pattern: Cyclic Sort →](../06-cyclic-sort/README.md)*
