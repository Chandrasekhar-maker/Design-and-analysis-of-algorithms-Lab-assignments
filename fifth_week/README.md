# 🔎 DAA Lab — Week 05

### Sorting Algorithms | C++ Implementation

> **💻 Language:** C++
> **🧠 Programs:** 3
> **📊 Topics:** Merge Sort, Quick Sort, Bucket Sort

---

## 📌 Quick Navigation

* [Lab Overview](#-lab-overview)
* [1️⃣ Merge Sort](#1️⃣-merge-sort)
* [2️⃣ Quick Sort](#2️⃣-quick-sort)
* [3️⃣ Bucket Sort](#3️⃣-bucket-sort)
* [📊 Algorithm Comparison](#-algorithm-comparison)
* [🧠 Approaches Used](#-approaches-used)
* [🎯 Key Takeaways](#-key-takeaways)
* [📁 Programs](#-programs)

---

## 📋 Lab Overview

This week's DAA laboratory focuses on **sorting algorithms** and their mathematical and algorithmic approaches.

| Algorithm       | Technique          |    Best Case | Average Case |   Worst Case |       Space |
| --------------- | ------------------ | -----------: | -----------: | -----------: | ----------: |
| **Merge Sort**  | Divide and Conquer | `O(n log n)` | `O(n log n)` | `O(n log n)` |      `O(n)` |
| **Quick Sort**  | Divide and Conquer | `O(n log n)` | `O(n log n)` |      `O(n²)` | `O(log n)`* |
| **Bucket Sort** | Distribution       |   `O(n + k)` |   `O(n + k)` |      `O(n²)` |  `O(n + k)` |

> `n` = number of elements
> `k` = number of buckets
> `*` Quick Sort can require `O(n)` auxiliary stack space in the worst case.

---

# 1️⃣ Merge Sort

## 📌 Concept

**Merge Sort** follows the **Divide and Conquer** paradigm.

The array is recursively divided into two halves until each subarray contains a single element. The sorted subarrays are then merged.

---

## 🧮 Mathematical Approach

For an array of size `n`, the problem is divided into two subproblems:

$$
T(n) = 2T(n/2) + O(n)
$$

The `O(n)` term represents the merging operation.

Using the Master Theorem:

$$
a=2,\quad b=2,\quad f(n)=O(n)
$$

$$
n^{\log_b a}=n^{\log_2 2}=n
$$

Therefore:

$$
\boxed{T(n)=O(n\log n)}
$$

### Number of Levels

The array is repeatedly divided by 2:

$$
n \rightarrow \frac{n}{2} \rightarrow \frac{n}{4}
\rightarrow \cdots \rightarrow 1
$$

The number of levels is:

$$
\log_2 n
$$

At every level, the total merging work is:

$$
O(n)
$$

Therefore:

$$
O(n)\times O(\log n)
=
\boxed{O(n\log n)}
$$

---

## ⚙️ Algorithm

```text
MergeSort(A, low, high)

if low < high
    mid = low + (high - low) / 2

    MergeSort(A, low, mid)
    MergeSort(A, mid + 1, high)

    Merge(A, low, mid, high)
```

### Merge Process

```text
Array
  ↓
Divide into two halves
  ↓
Recursively divide
  ↓
Single-element subarrays
  ↓
Merge sorted subarrays
  ↓
Sorted Array
```

---

## ⏱️ Complexity

| Case             |   Complexity |
| ---------------- | -----------: |
| Best Case        | `O(n log n)` |
| Average Case     | `O(n log n)` |
| Worst Case       | `O(n log n)` |
| Space Complexity |       `O(n)` |

---

## 📂 Implementation

[`merge_sort.cpp`](./merge_sort.cpp)

---

# 2️⃣ Quick Sort

## 📌 Concept

**Quick Sort** follows the **Divide and Conquer** paradigm.

A pivot is selected and the array is partitioned so that elements smaller than the pivot are placed on one side and larger elements are placed on the other side.

---

## 🧮 Mathematical Approach

Partitioning requires scanning the array once:

$$
O(n)
$$

The overall complexity depends on the balance of the partitions.

### Best Case

If the pivot divides the array approximately equally:

$$
T(n)=2T(n/2)+O(n)
$$

Using the Master Theorem:

$$
\boxed{T(n)=O(n\log n)}
$$

### Worst Case

If the pivot is always the smallest or largest element:

$$
T(n)=T(n-1)+O(n)
$$

Expanding:

$$
T(n)=T(n-2)+O(n-1)+O(n)
$$

Therefore:

$$
T(n)=O(1)+2+3+\cdots+n
$$

Using:

$$
1+2+3+\cdots+n=\frac{n(n+1)}{2}
$$

Hence:

$$
\boxed{T(n)=O(n^2)}
$$

### Average Case

For reasonably balanced partitions:

$$
\boxed{T(n)=O(n\log n)}
$$

---

## ⚙️ Algorithm

```text
QuickSort(A, low, high)

if low < high
    pivotIndex = Partition(A, low, high)

    QuickSort(A, low, pivotIndex - 1)
    QuickSort(A, pivotIndex + 1, high)
```

### Partition Process

```text
Array
  ↓
Choose Pivot
  ↓
Partition
  ↓
Smaller Elements | Pivot | Larger Elements
  ↓
Recursively Sort Both Parts
  ↓
Sorted Array
```

---

## ⏱️ Complexity

| Case         | Time Complexity |
| ------------ | --------------: |
| Best Case    |    `O(n log n)` |
| Average Case |    `O(n log n)` |
| Worst Case   |         `O(n²)` |

| Case           | Auxiliary Space |
| -------------- | --------------: |
| Best / Average |      `O(log n)` |
| Worst          |          `O(n)` |

---

## 📂 Implementation

[`quick_sort.cpp`](./quick_sort.cpp)

---

# 3️⃣ Bucket Sort

## 📌 Concept

**Bucket Sort** is a **distribution-based sorting algorithm**.

The input elements are distributed among multiple buckets according to their values. The elements inside the buckets are maintained in sorted order and then collected to produce the final sorted array.

---

## 🧮 Mathematical Approach

For an element `x`, the bucket is determined using a mapping function:

$$
\text{bucketIndex}=f(x)
$$

For the given implementation, the value is mapped according to its magnitude.

For example:

$$
\text{bucketIndex}=
\left\lfloor\frac{x}{1000}\right\rfloor
$$

For `n` elements and `k` buckets, the expected number of elements per bucket under approximately uniform distribution is:

$$
\frac{n}{k}
$$

The complete process is:

$$
\text{Input}
\rightarrow
\text{Distribution}
\rightarrow
\text{Bucket Processing}
\rightarrow
\text{Collection}
$$

---

## ⚙️ Algorithm

```text
BucketSort(A)

Create k buckets

for each element x in A
    index = bucketIndex(x)
    Insert x into bucket[index]

for each bucket
    Maintain elements in sorted order

Traverse all buckets
    Copy elements back into A
```

### Distribution Process

```text
Input Array
     ↓
Calculate Bucket Index
     ↓
┌─────┬─────┬─────┬─────┐
│ B0  │ B1  │ B2  │ ... │
└─────┴─────┴─────┴─────┘
     ↓
Maintain Sorted Order
     ↓
Traverse Buckets
     ↓
Sorted Array
```

---

## 🧮 Complexity Analysis

### Distribution

Each of the `n` elements is assigned to a bucket:

$$
O(n)
$$

For a suitable distribution, bucket processing is approximately:

$$
O(n+k)
$$

Therefore, the expected complexity is:

$$
\boxed{O(n+k)}
$$

In the worst case, many elements may fall into the same bucket, resulting in:

$$
\boxed{O(n^2)}
$$

---

## ⏱️ Complexity

| Case             | Time Complexity |
| ---------------- | --------------: |
| Best Case        |      `O(n + k)` |
| Average Case     |      `O(n + k)` |
| Worst Case       |         `O(n²)` |
| Space Complexity |      `O(n + k)` |

Where:

* `n` = number of input elements
* `k` = number of buckets

---

## 📂 Implementation

[`bucket_sort.cpp`](./bucket_sort.cpp)

---

# 📊 Algorithm Comparison

| Feature        | Merge Sort         | Quick Sort         | Bucket Sort  |
| -------------- | ------------------ | ------------------ | ------------ |
| Main Technique | Divide and Conquer | Divide and Conquer | Distribution |
| Best Time      | `O(n log n)`       | `O(n log n)`       | `O(n + k)`   |
| Average Time   | `O(n log n)`       | `O(n log n)`       | `O(n + k)`   |
| Worst Time     | `O(n log n)`       | `O(n²)`            | `O(n²)`      |
| Extra Space    | `O(n)`             | `O(log n)` average | `O(n + k)`   |
| Recursion      | Yes                | Yes                | No           |
| Main Operation | Merge              | Partition          | Distribution |

---

# 🧠 Approaches Used

## 1. Divide and Conquer

Used by:

* **Merge Sort**
* **Quick Sort**

General structure:

$$
\text{Divide}
\rightarrow
\text{Solve}
\rightarrow
\text{Combine}
$$

---

## 2. Distribution

Used by:

* **Bucket Sort**

General structure:

$$
\text{Distribute}
\rightarrow
\text{Process Buckets}
\rightarrow
\text{Collect}
$$

---

## 3. Recurrence Relations

The recursive algorithms can be represented using recurrence relations.

### Merge Sort

$$
T(n)=2T(n/2)+O(n)
$$

### Quick Sort — Best Case

$$
T(n)=2T(n/2)+O(n)
$$

### Quick Sort — Worst Case

$$
T(n)=T(n-1)+O(n)
$$

---

# 🎯 Key Takeaways

* **Merge Sort** divides the array and combines sorted subarrays.
* **Quick Sort** uses a pivot and partitioning.
* **Bucket Sort** distributes elements according to their values.
* Merge Sort guarantees:

$$
\boxed{O(n\log n)}
$$

* Quick Sort has average-case complexity:

$$
\boxed{O(n\log n)}
$$

and worst-case complexity:

$$
\boxed{O(n^2)}
$$

* Bucket Sort can achieve:

$$
\boxed{O(n+k)}
$$

when the input distribution is suitable.

---

# 📁 Programs

|  # | Program                                | Technique                         |
| -: | -------------------------------------- | --------------------------------- |
|  1 | [`merge_sort.cpp`](./merge_sort.cpp)   | Divide and Conquer                |
|  2 | [`quick_sort.cpp`](./quick_sort.cpp)   | Divide and Conquer + Partitioning |
|  3 | [`bucket_sort.cpp`](./bucket_sort.cpp) | Distribution / Bucketing          |

---

## 📌 Laboratory Progress

| Status      | Algorithm   |
| ----------- | ----------- |
| ✅ Completed | Merge Sort  |
| ✅ Completed | Quick Sort  |
| ✅ Completed | Bucket Sort |

---

### 🚀 DAA Lab — Week 05 Completed

**Sorting Algorithms → Mathematical Approach → Complexity Analysis**
