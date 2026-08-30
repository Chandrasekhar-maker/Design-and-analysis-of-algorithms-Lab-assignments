# 🔎 DAA Lab — Week 04

### Hashing Algorithms | C++ Implementation

> **💻 C++** · **🧠 4 Programs** · **#️⃣ Hashing & Collision Resolution**

---

## 📌 Quick Navigation

**[🔗 Linear Probing](#-01--linear-probing)** •
**[🔀 Quadratic Probing](#-02--quadratic-probing)** •
**[🎯 Two Sum](#-03--two-sum)** •
**[📊 Frequency Counting](#-04--frequency-counting)** •
**[⚖️ Comparison](#️-comparison)** •
**[🎯 Key Takeaways](#-key-takeaways)**

---

## 🧪 Lab Overview

This laboratory focuses on **Hash Tables, Collision Resolution, and Applications of Hashing**.

| # | Program | Implementation | Average Complexity |
| :---: | :------------------- | :--------------------------------: | :----------------: |
| 🔹 **01** | **Linear Probing** | [View Source](./linear_probing.cpp) | `O(1)` |
| 🔹 **02** | **Quadratic Probing** | [View Source](./quadratic_probing.cpp) | `O(1)` |
| 🔹 **03** | **Two Sum** | [View Source](./two_sum.cpp) | `O(n)` |
| 🔹 **04** | **Frequency Counting** | [View Source](./frequency.cpp) | `O(n)` |

> 💡 **Main idea:** Hashing provides efficient average-case searching and insertion by mapping keys to positions in a hash table.

---

# 🔗 01 — Linear Probing

### What does it do?

Linear Probing handles **collisions in a hash table** by checking the next available position sequentially.

### 🧠 How it works

The initial position is calculated using the hash function:

    index = key % table_size

If the calculated position is occupied, the implementation checks the next positions one by one.

    Hash Index
        ↓
      [ X ]
        ↓
    Collision
        ↓
      [ X ] → [ X ] → [ Empty ]
                          ↓
                        Insert

### ⚙️ Approach

    START
      ↓
    Calculate hash index
      ↓
    Check table position
      ↓
     ┌────────────────┐
     │   Occupied?    │
     └───────┬────────┘
           YES│NO
              │
        ┌─────┴─────┐
        ↓           ↓
    Next position  Insert
        ↓
    Continue probing

The probing position used in the implementation is:

    index = (originalIndex + prob) % totalSize

The same probing sequence is used during searching.

The implementation also uses a **load factor of 0.6** and performs rehashing when the table becomes sufficiently occupied.

### ⏱️ Complexity

| Operation | Best | Average | Worst |
| :--- | :---: | :---: | :---: |
| 🟢 Insertion | `O(1)` | `O(1)` | `O(n)` |
| 🔍 Search | `O(1)` | `O(1)` | `O(n)` |
| 🔄 Rehashing | `O(n)` | `O(n)` | `O(n)` |
| 💾 Space | `O(n)` | `O(n)` | `O(n)` |

### 📄 Implementation

👉 **[Open `linear_probing.cpp`](./linear_probing.cpp)**

---

# 🔀 02 — Quadratic Probing

### What does it do?

Quadratic Probing handles **hash table collisions** by searching for an available position using quadratic increments.

### 🧠 How it works

The initial position is calculated using:

    index = key % table_size

When a collision occurs, the implementation uses the square of the probe number to calculate the next position.

    index = (originalIndex + prob²) % totalSize

    Hash Index
        ↓
      [ X ]
        ↓
    Collision
        ↓
       + 1²
        ↓
       + 2²
        ↓
       + 3²
        ↓
    [ Empty ]
        ↓
      Insert

### ⚙️ Approach

    START
      ↓
    Calculate hash index
      ↓
    Check table position
      ↓
     ┌────────────────┐
     │   Occupied?    │
     └───────┬────────┘
           YES│NO
              │
        ┌─────┴─────┐
        ↓           ↓
    Increase       Insert
    probe number
        ↓
    Calculate quadratic
    probe position
        ↓
    Continue probing

The probing position used in the implementation is:

    index = (originalIndex + prob * prob) % totalSize

The same quadratic probing sequence is followed during searching.

The implementation also performs rehashing when the load factor becomes high and uses the next prime number as the new table size.

### ⏱️ Complexity

| Operation | Best | Average | Worst |
| :--- | :---: | :---: | :---: |
| 🟢 Insertion | `O(1)` | `O(1)` | `O(n)` |
| 🔍 Search | `O(1)` | `O(1)` | `O(n)` |
| 🔄 Rehashing | `O(n)` | `O(n)` | `O(n)` |
| 💾 Space | `O(n)` | `O(n)` | `O(n)` |

### 📄 Implementation

👉 **[Open `quadratic_probing.cpp`](./quadratic_probing.cpp)**

---

# 🎯 03 — Two Sum

### What does it do?

Finds two elements in an array whose sum is equal to a given **target value** using a hash table.

### 🧠 How it works

For every current element, the required complement is calculated:

    complement = target - current_element

The complement is searched in the hash table.

    Current Element
          ↓
    Calculate Complement
          ↓
    Search Hash Table
          ↓
     ┌────────────────┐
     │  Complement?   │
     └───────┬────────┘
           YES│NO
              │
        ┌─────┴─────┐
        ↓           ↓
    Pair Found    Insert
                  Element

### ⚙️ Approach

    START
      ↓
    Read array
      ↓
    Read target
      ↓
    Create Hash Table
      ↓
    Take current element
      ↓
    Calculate complement
      ↓
    Search complement
      ↓
     ┌────────────────┐
     │    Found?      │
     └───────┬────────┘
           YES│NO
              │
        ┌─────┴─────┐
        ↓           ↓
    Store Pair    Insert
        ↓        Current Element
       STOP          ↓
                 Next Element

The implementation stores previously visited elements in the hash table.

For every current element, its complement is searched before inserting the current element.

### ⏱️ Complexity

| Scenario | Time | Space |
| :--- | :---: | :---: |
| 🟢 Best | `O(1)` | `O(n)` |
| 🟡 Average | `O(n)` | `O(n)` |
| 🔴 Worst | `O(n²)` | `O(n)` |

### 📄 Implementation

👉 **[Open `two_sum.cpp`](./two_sum.cpp)**

---

# 📊 04 — Frequency Counting

### What does it do?

Finds the frequency of each distinct element in an array using a hash table.

### 🧠 How it works

Each array element is stored as a **key**, while its frequency is stored as the corresponding **value**.

    Array Element
          ↓
    Search Hash Table
          ↓
     ┌─────────────────┐
     │ Element exists? │
     └───────┬─────────┘
           YES│NO
              │
        ┌─────┴─────┐
        ↓           ↓
    Increase       Insert
    Frequency      with 1
        ↓           ↓
        └─────┬─────┘
              ↓
         Next Element

### ⚙️ Approach

    START
      ↓
    Read array
      ↓
    Create Hash Table
      ↓
    Take current element
      ↓
    Search element
      ↓
     ┌─────────────────┐
     │     Found?      │
     └───────┬─────────┘
           YES│NO
              │
        ┌─────┴─────┐
        ↓           ↓
    Increase       Insert
    Frequency      Frequency = 1
        ↓           ↓
        └─────┬─────┘
              ↓
         Update Table
              ↓
         Next Element
              ↓
       Display Frequencies

The implementation maintains the relationship:

    Element → Frequency

If the element is already present, its frequency is increased by one.

If the element is not present, it is inserted with frequency `1`.

### ⏱️ Complexity

| Operation | Best | Average | Worst |
| :--- | :---: | :---: | :---: |
| 🔍 Search | `O(1)` | `O(1)` | `O(n)` |
| ➕ Insert / Update | `O(1)` | `O(1)` | `O(n)` |
| 📊 Frequency Calculation | `O(n)` | `O(n)` | `O(n²)` |
| 📋 Display | `O(n)` | `O(n)` | `O(n)` |
| 💾 Space | `O(n)` | `O(n)` | `O(n)` |

### 📄 Implementation

👉 **[Open `frequency.cpp`](./frequency.cpp)**

---

# ⚖️ Comparison

| | 🔗 Linear Probing | 🔀 Quadratic Probing | 🎯 Two Sum | 📊 Frequency Counting |
| :--- | :---: | :---: | :---: | :---: |
| **Main Concept** | Collision Resolution | Collision Resolution | Hash Searching | Frequency Counting |
| **Technique** | Linear Probing | Quadratic Probing | Complement Search | Key-Value Mapping |
| **Average Time** | `O(1)` | `O(1)` | `O(n)` | `O(n)` |
| **Worst Time** | `O(n)` | `O(n)` | `O(n²)` | `O(n²)` |
| **Space** | `O(n)` | `O(n)` | `O(n)` | `O(n)` |

---

# 🧠 Approaches Used

| Program | Approach |
| :--- | :--- |
| 🔗 **Linear Probing** | Uses sequential positions to resolve collisions |
| 🔀 **Quadratic Probing** | Uses quadratic offsets to resolve collisions |
| 🎯 **Two Sum** | Searches for the complement of each current element |
| 📊 **Frequency Counting** | Stores each element with its occurrence count |

---

# 🎯 Key Takeaways

### 🔗 Linear Probing

> **Sequential collision resolution** — checks consecutive positions after a collision.

### 🔀 Quadratic Probing

> **Quadratic collision resolution** — uses increasing quadratic offsets to find an available position.

### 🎯 Two Sum

> **Hash-based pair searching** — uses the required complement to find a target-sum pair efficiently.

### 📊 Frequency Counting

> **Key-value frequency mapping** — stores elements as keys and their frequencies as values.

### 🧠 Algorithm Design

The laboratory demonstrates how **hashing can be used for collision resolution, searching, and frequency-based problem solving**.

---

## 📂 Programs

| Program | Description | Source |
| :--- | :--- | :---: |
| 🔗 **Linear Probing** | Handles collisions using sequential probing | [View →](./linear_probing.cpp) |
| 🔀 **Quadratic Probing** | Handles collisions using quadratic probing | [View →](./quadratic_probing.cpp) |
| 🎯 **Two Sum** | Finds a target-sum pair using hashing | [View →](./two_sum.cpp) |
| 📊 **Frequency Counting** | Calculates element frequencies using hashing | [View →](./frequency.cpp) |

---

### 🏁 Laboratory Progress

**Week 04** · **Hashing Algorithms** · **Completed ✅**

---

<sub>Design and Analysis of Algorithms Laboratory • C++ • Hashing</sub>
