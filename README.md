# DSA Learning Journey

This repository contains my DSA practice, mainly focused on understanding the
thinking behind problems rather than simply memorizing solutions.

My goal is to understand:
- How to identify patterns in a problem
- How to choose the right approach
- Why a particular algorithm works
- How to improve my own approach
- How different problems are connected to the same underlying concept

---

## October 3

### Concepts Learned

On October 3, I did not commit a specific problem, but I worked on understanding
an important pattern:

- Finding patterns in a circular loop
- Understanding how indices behave when we move circularly
- Thinking about how to handle the beginning/end boundary of an array
- Recognizing that some problems can be solved by treating an array as circular

Although there was no problem committed on this day, the concept was studied
and became part of my problem-solving toolkit.

---

## 3 Sum and 4 Sum

I cleared the concepts behind **3 Sum** and **4 Sum**.

The important thing for me was not just getting the final code, but understanding
how the thinking extends from one problem to another.

### 3 Sum

The basic thought process:

1. Sort the array.
2. Fix one element.
3. Use two pointers for the remaining two elements.
4. Move the pointers based on whether the current sum is too small or too large.
5. Handle duplicate values carefully.

The important pattern I understood:

> Fix some elements → reduce the remaining problem → use two pointers.

### 4 Sum

The same idea can be extended to 4 Sum:

1. Sort the array.
2. Fix the first element.
3. Fix the second element.
4. Use two pointers for the remaining two elements.
5. Adjust the pointers according to the required sum.
6. Handle duplicates.

This helped me understand that **4 Sum is not a completely new problem**.
It is an extension of the same thinking used in 3 Sum.

---

## October 8

### Pointers - In Depth

Today I studied pointers in more depth.

I focused on understanding what is actually happening when pointers are used
instead of simply remembering:

```cpp
left++;
right--;
"""


vector<vector<int>> arr;


### One thing I would strongly recommend

For your LeetCode entries, **don't write only the final solution**. Write your *mental path*.

For example:

> **Problem:** Count zeros in a sorted binary matrix  
> **First thought:** Since the matrix is sorted, I shouldn't visit every cell.  
> **Observation:** When I encounter `1`, I can move left. When I encounter `0`, all elements to its left are also `0`.  
> **Pattern:** Staircase traversal.  
> **Key realization:** If I am at column `end` and find `0`, there are `end + 1` zeros in that row.  
> **Complexity:** `O(n + m)`.

That kind of README will show **how your thinking is developing**, which is much more valuable than a list of LeetCode solutions. 
