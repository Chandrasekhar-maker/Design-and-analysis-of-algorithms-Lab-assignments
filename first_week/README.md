# 🔎 DAA Lab — Week 01

### Searching Algorithms | C++ Implementation

> **📅 06 August 2026** · **💻 C++** · **🧠 2 Algorithms** · **✅ Completed**

---

## 📌 Quick Navigation

**[🔍 Linear Search](#-01--linear-search)**  • 
**[⚡ Binary Search](#-02--binary-search)**  • 
**[⚖️ Comparison](#️-comparison)**  • 
**[🎯 Takeaways](#-key-takeaways)**

---

## 🧪 Lab Overview

This laboratory introduces two fundamental searching techniques:

|     #     | Algorithm         |           Implementation           | Complexity |
| :-------: | :---------------- | :--------------------------------: | :--------: |
| 🔹 **01** | **Linear Search** | [View Source](./linear_search.cpp) |   `O(n)`   |
| 🔹 **02** | **Binary Search** | [View Source](./binary_search.cpp) | `O(log n)` |

> 💡 **Main idea:** Both algorithms solve the same problem — finding a target element — but they use fundamentally different strategies.

---

# 🔍 01 — Linear Search

### What does it do?

Linear Search checks elements **one by one from left to right** until the target is found.

### 🧠 How it works

```text
Target = 42

[ 10 ][ 25 ][ 17 ][ 42 ][ 63 ]
   ↓     ↓     ↓     ↓
   ✗     ✗     ✗     ✓

              FOUND
```

### ⚙️ Approach

```text
START
  ↓
Read array
  ↓
Read target
  ↓
Start from index 0
  ↓
Compare current element
  ↓
 ┌───────────────┐
 │ Element ==    │
 │    target?    │
 └───────┬───────┘
       YES │ NO
        ↓   ↓
      Found  Next element
              ↓
         Continue search
```

If the entire array is examined without finding the target, the algorithm reports that the element is not present.

### ⏱️ Complexity

| Scenario   |  Time  | Why?                                     |
| :--------- | :----: | :--------------------------------------- |
| 🟢 Best    | `O(1)` | Target is the first element              |
| 🟡 Average | `O(n)` | Multiple elements may need to be checked |
| 🔴 Worst   | `O(n)` | Target is last or absent                 |
| 💾 Space   | `O(1)` | Constant auxiliary memory                |

### ✅ When is it useful?

* Array is **unsorted**
* Dataset is relatively small
* Simplicity is more important than search speed
* No preprocessing is desired

### 📄 Implementation

👉 **[Open `linear_search.cpp`](./linear_search.cpp)**

---

# ⚡ 02 — Binary Search

### What does it do?

Binary Search finds an element by repeatedly **cutting the search space in half**.

> ⚠️ **Requirement:** The array **must be sorted**.

### 🧠 How it works

```text
Target = 60

[10  20  30  40  50  60  70]
              ↑
             MID
              
60 > 40
      ↓
Discard left half

[50  60  70]
    ↑
   MID

60 > 50
      ↓
Discard left half

[60]
 ↑
FOUND ✓
```

Instead of checking every element, Binary Search eliminates a large portion of the search space after every comparison.

### ⚙️ Approach

```text
START
  ↓
Read sorted array
  ↓
Read target
  ↓
left = 0
right = n - 1
  ↓
Calculate MID
  ↓
Compare MID with target
  ↓
 ┌───────────────────────────┐
 │                           │
Target == MID      Target < MID      Target > MID
      ↓                 ↓                 ↓
    FOUND          Search LEFT       Search RIGHT
                        ↓                 ↓
                   Repeat process
```

The process continues until the element is found or there are no elements left to search.

### ⏱️ Complexity

| Scenario   |    Time    | Why?                              |
| :--------- | :--------: | :-------------------------------- |
| 🟢 Best    |   `O(1)`   | Target is the middle element      |
| 🟡 Average | `O(log n)` | Search space is repeatedly halved |
| 🔴 Worst   | `O(log n)` | Maximum number of divisions       |
| 💾 Space   |   `O(1)`   | Iterative implementation          |

### ✅ When is it useful?

* Array is **sorted**
* Dataset is large
* Fast searching is required
* Search operations are performed frequently

### 📄 Implementation

👉 **[Open `binary_search.cpp`](./binary_search.cpp)**

---

# ⚖️ Comparison

|                            |    🔍 Linear Search   |    ⚡ Binary Search   |
| -------------------------- | :-------------------: | :------------------: |
| **Strategy**               |       Sequential      |   Divide & Conquer   |
| **Sorted Array Required?** |          ❌ No         |         ✅ Yes        |
| **Best Case**              |         `O(1)`        |        `O(1)`        |
| **Average Case**           |         `O(n)`        |      `O(log n)`      |
| **Worst Case**             |         `O(n)`        |      `O(log n)`      |
| **Space**                  |         `O(1)`        |        `O(1)`        |
| **Search Reduction**       | One element at a time | Half of search space |
| **Best suited for**        | Unsorted / small data |  Sorted / large data |

---

## 📊 Why is Binary Search Faster?

Suppose an array contains **1,000,000 elements**.

### Linear Search

It may need to examine almost every element:

```text
1,000,000 → 999,999 → 999,998 → ... → 1
```

### Binary Search

It repeatedly halves the search space:

```text
1,000,000
    ↓
  500,000
    ↓
  250,000
    ↓
  125,000
    ↓
    ...
    ↓
      1
```

This is the fundamental reason behind:

```text
Linear Search  →  O(n)

Binary Search  →  O(log n)
```

> 🚀 **Key insight:** Better algorithmic strategy can dramatically reduce the amount of work required as the input size grows.

---

# 🎯 Key Takeaways

### 🔍 Linear Search

> **Simple and flexible** — works even when the data is unsorted.

### ⚡ Binary Search

> **Fast and efficient** — but requires sorted data.

### 🧠 Algorithm Design

The important lesson from this lab is not simply learning two search algorithms. It is understanding that **the structure of the input and the strategy used to process it directly influence algorithm efficiency**.

---

## 📂 Programs

| Program              | Description                                      |             Source            |
| :------------------- | :----------------------------------------------- | :---------------------------: |
| 🔍 **Linear Search** | Sequentially searches for the target element     | [View →](./linear_search.cpp) |
| ⚡ **Binary Search**  | Searches by repeatedly dividing the search range | [View →](./binary_search.cpp) |

---

### 🏁 Laboratory Progress

**Week 01** · **Searching Algorithms** · **Completed ✅**

---

<sub>Design and Analysis of Algorithms Laboratory • C++ • 06 August 2026</sub>
