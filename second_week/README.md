# 📘 DAA Lab — Week 02

### Design and Analysis of Algorithms Laboratory

> **📅 13 August 2026** · **💻 C++** · **🧠 3 Programs** ·

---

## 📌 Lab Overview

This week's laboratory focuses on **sorting techniques, heap data structures, Binary Search Trees, and iterative problem solving**.

The implementations demonstrate different approaches to solving algorithmic problems along with their **time and space complexity analysis**.

| # | Program | Source File | Algorithms / Concepts |
|:---:|:---|:---|:---|
| **01** | 🔢 Kth Smallest Element | `kth_smallest.cpp` | Merge Sort, Min Heap |
| **02** | 🌳 Binary Search Tree | `bst.cpp` | Insertion, Inorder Traversal, Minimum, Deletion |
| **03** | 📐 Geometric Series | `geometric_series.cpp` | Formula Method, Iterative Method |

---

# 🔢 01 — Kth Smallest Element

## 📌 Problem

Find the **kth smallest element** in an array using two different approaches.

---
               Kth Smallest Element
                       │
              ┌────────┴────────┐
              ↓                 ↓
        Sorting Method      Min Heap Method
              │                 │
          Merge Sort          Min Heap
              │                 │
              └────────┬────────┘
                       ↓
                kth Smallest
                
## 🔀 Approach 1 — Merge Sort

### 🧠 Approach

The array is completely sorted using the **Merge Sort** algorithm.

The implementation follows the **divide-and-conquer** technique:

1. Divide the array into two halves.
2. Recursively sort both halves.
3. Merge the sorted halves.
4. After the complete array is sorted, the kth smallest element is obtained from index `k - 1`.

### ⏱️ Time Complexity

| Case | Complexity |
|:---|:---:|
| Best Case | `O(n log n)` |
| Average Case | `O(n log n)` |
| Worst Case | `O(n log n)` |

### 💾 Space Complexity

`O(n)`

Additional space is required for the temporary array used during merging.

---

## ⚡ Approach 2 — Min Heap

### 🧠 Approach

A **Min Heap** is used to maintain the smallest element at the root.

1. Insert all array elements into the Min Heap.
2. Delete the minimum element `k - 1` times.
3. After these deletions, the root contains the kth smallest element.
4. `restoreup()` maintains the heap property after insertion.
5. `heapfiy()` restores the heap property after deletion.

### ⏱️ Time Complexity

| Operation | Complexity |
|:---|:---:|
| Single Insertion | `O(log n)` |
| Insert `n` Elements | `O(n log n)` |
| Single Deletion | `O(log n)` |
| `k - 1` Deletions | `O(k log n)` |
| **Overall** | **`O(n log n + k log n)`** |

### 💾 Space Complexity

`O(n)`

The Min Heap stores all `n` elements.

---

## ⚖️ Kth Smallest — Comparison

| Feature | Merge Sort | Min Heap |
|:---|:---:|:---:|
| Approach | Divide and Conquer | Heap-based |
| Time Complexity | `O(n log n)` | `O(n log n + k log n)` |
| Space Complexity | `O(n)` | `O(n)` |
| Main Operation | Complete sorting | Repeated minimum deletion |

---

# 🌳 02 — Binary Search Tree

## 📌 Problem

Implement a **Binary Search Tree** and perform insertion, inorder traversal, minimum-element search, and deletion.

The BST maintains the property:

**Left Subtree < Root < Right Subtree**

---

## ➕ Approach — Insertion

### 🧠 Approach

The implementation uses an **iterative insertion technique**.

1. Start from the root.
2. Compare the new value with the current node.
3. If the new value is smaller, move to the left subtree.
4. Otherwise, move to the right subtree.
5. Continue until an empty position is found.
6. Create the new node at that position.

### ⏱️ Time Complexity

| Case | Complexity |
|:---|:---:|
| Average / Balanced Tree | `O(log n)` |
| Worst / Skewed Tree | `O(n)` |

### 💾 Space Complexity

`O(1)` auxiliary space because insertion is performed iteratively.

---

## 🔄 Approach — Inorder Traversal

### 🧠 Approach

The implementation uses recursive **inorder traversal**:

**Left → Root → Right**

For a valid BST, inorder traversal visits elements in **ascending order**.

### ⏱️ Time Complexity

`O(n)`

Every node is visited exactly once.

### 💾 Space Complexity

`O(h)`

The recursive call stack depends on the height `h` of the tree.

---

## 🔎 Approach — Finding Minimum

### 🧠 Approach

The minimum element in a BST is always the **leftmost node**.

The implementation recursively moves to the left child until a node with no left child is reached.

### ⏱️ Time Complexity

`O(h)`

Where `h` is the height of the BST.

### 💾 Space Complexity

`O(h)`

The recursive implementation uses the call stack.

---

## 🗑️ Approach — Deletion

### 🧠 Approach

The implementation searches for the node to be deleted and handles the standard BST deletion cases.

### Case 1 — No Child

The node is a leaf node and can be removed directly.

### Case 2 — One Child

The node is replaced by its existing child.

### Case 3 — Two Children

1. Find the minimum element in the right subtree.
2. Replace the node's value with that minimum value.
3. Delete the replacement node from the right subtree.

This maintains the BST ordering property.

### ⏱️ Time Complexity

| Case | Complexity |
|:---|:---:|
| Average / Balanced Tree | `O(log n)` |
| Worst / Skewed Tree | `O(n)` |

### 💾 Space Complexity

`O(h)`

The deletion implementation uses recursion.

---

# 📐 03 — Geometric Series

## 📌 Problem

Calculate the sum of the first `n` terms of a **Geometric Progression** using two different approaches.

The progression is represented by:

**a, ar, ar², ar³, ...**

where:

- `a` = first term
- `r` = common ratio
- `n` = number of terms

---

## 🧮 Approach 1 — Formula Method

### 🧠 Approach

The implementation calculates the sum directly using the standard geometric-series formula:

**Sₙ = a(rⁿ - 1) / (r - 1)**

The `pow()` function is used to calculate `rⁿ`.

### ⏱️ Time Complexity

Depends on the internal implementation of `pow()`.

For an efficient exponentiation approach:

`O(log n)`

### 💾 Space Complexity

`O(1)`

Only a constant amount of additional memory is used.

---

## 🔁 Approach 2 — Iterative Method

### 🧠 Approach

The implementation calculates the sum by generating each term iteratively.

1. Start with the first term `a`.
2. Add the current term to the sum.
3. Multiply the current term by `r` to obtain the next term.
4. Repeat the process for `n` terms.

### ⏱️ Time Complexity

`O(n)`

The loop executes once for each term.

### 💾 Space Complexity

`O(1)`

Only a constant number of variables are used.

---

## ⚖️ Geometric Series — Comparison

| Feature | Formula Method | Iterative Method |
|:---|:---:|:---:|
| Approach | Mathematical Formula | Sequential Calculation |
| Time Complexity | Depends on `pow()` | `O(n)` |
| Space Complexity | `O(1)` | `O(1)` |
| Explicit Loop | No | Yes |

---

# ⚙️ Overall Complexity Analysis

| Program | Approach | Time Complexity | Space Complexity |
|:---|:---|:---:|:---:|
| 🔢 Kth Smallest | Merge Sort | `O(n log n)` | `O(n)` |
| 🔢 Kth Smallest | Min Heap | `O(n log n + k log n)` | `O(n)` |
| 🌳 BST | Insertion | `O(h)` | `O(1)` |
| 🌳 BST | Inorder Traversal | `O(n)` | `O(h)` |
| 🌳 BST | Find Minimum | `O(h)` | `O(h)` |
| 🌳 BST | Deletion | `O(h)` | `O(h)` |
| 📐 Geometric Series | Formula | Depends on `pow()` | `O(1)` |
| 📐 Geometric Series | Iterative | `O(n)` | `O(1)` |

> **Note:** `h` represents the height of the Binary Search Tree.  
> For a balanced BST, `h = O(log n)`.  
> For a skewed BST, `h = O(n)`.

---

# 🧠 Concepts Covered
 
- 🔀 Divide and Conquer
- 🏗️ Min Heap
- 🌳 Binary Search Tree
- ➕ BST Insertion
- 🔄 Tree Traversal
- 🔎 Minimum Element
- 🗑️ BST Deletion
- 🧮 Mathematical Formula
- 🔁 Iterative Computation
- ⏱️ Time Complexity
- 💾 Space Complexity
- ⚖️ Algorithm Comparison

---

# 📂 Source Files

| # | Program | File |
|:---:|:---|:---:|
| **01** | 🔢 Kth Smallest Element | [`kth_smallest.cpp`](./kth_smallest.cpp) |
| **02** | 🌳 Binary Search Tree | [`bst.cpp`](./bst.cpp) |
| **03** | 📐 Geometric Series | [`geometric_series.cpp`](./geometric_series.cpp) |

---

## 🏁 Laboratory Status

**Week 02 — 

**Language:** C++  
**Course:** Design and Analysis of Algorithms  
**Lab Date:** 13 August 2026

---

<sub>Design and Analysis of Algorithms Laboratory · Week 02</sub>
