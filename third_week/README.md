# 🔎 DAA Lab — Week 03

### Stack, Queue & Tower of Hanoi | C++ Implementation

> **💻 C++** · **🧠 3 Programs** · **📚 Stack, Queue & Recursion**

---

## 📌 Quick Navigation

**[🗼 Tower of Hanoi](#-01--tower-of-hanoi)** •
**[📚 Stack](#-02--stack-using-linked-list)** •
**[🚶 Queue](#-03--queue-using-linked-list)** •
**[⚖️ Comparison](#️-comparison)** •
**[🎯 Key Takeaways](#-key-takeaways)**

---

## 🧪 Lab Overview

This laboratory contains implementations of **Tower of Hanoi, Stack, and Queue** using C++.

| # | Algorithm / Program | Implementation | Approach |
| :---: | :-------------------------- | :---------------------------: | :--------------------------- |
| 🔹 **01** | **Tower of Hanoi** | [View Source](./tower_of_hanoi.cpp) | Iterative & Recursive |
| 🔹 **02** | **Stack** | [View Source](./stack.cpp) | Linked List |
| 🔹 **03** | **Queue** | [View Source](./queue.cpp) | Linked List |

> 💡 **Main idea:** The laboratory demonstrates iterative and recursive problem solving along with linked-list implementations of fundamental linear data structures.

---

# 🗼 01 — Tower of Hanoi

### What does it do?

Implements the **Tower of Hanoi** problem using both **iterative and recursive approaches**.

### 🧠 How it works

The program represents the three rods using `S`, `A`, and `D`:

    S → Source
    A → Auxiliary
    D → Destination

The iterative implementation uses stacks to represent the rods and performs the disk movements according to the number of disks.

The recursive implementation solves the problem by repeatedly reducing it into smaller subproblems.

### ⚙️ Approach

**Iterative Approach**

    START
      ↓
    Read number of disks
      ↓
    Initialize three rods
      ↓
    Push disks onto source rod
      ↓
    Calculate total moves
      ↓
    Check number of disks
      ↓
    Adjust rod order for even disks
      ↓
    Perform disk movements
      ↓
    END

The iterative implementation calculates the total number of moves as:

    Total Moves = 2ⁿ - 1

The program uses the disk number and rod arrangement to determine the valid movement for each step.

**Recursive Approach**

    START
      ↓
    Read number of disks
      ↓
    Check base condition
      ↓
    Move n-1 disks
      ↓
    Move current disk
      ↓
    Move n-1 disks
      ↓
    END

### ⏱️ Complexity

| Approach | Time | Space |
| :--- | :---: | :---: |
| 🔁 Iterative | `O(2ⁿ)` | `O(n)` |
| 🔄 Recursive | `O(2ⁿ)` | `O(n)` |

### 📄 Implementation

👉 **[Open `tower_of_hanoi.cpp`](./tower_of_hanoi.cpp)**

---

# 📚 02 — Stack Using Linked List

### What does it do?

Implements a **Stack using a linked list** with operations for `push`, `pop`, `peek`, and `display`.

### 🧠 How it works

Each stack element is represented using a dynamically allocated node.

The `top` pointer maintains the topmost element of the stack.

    TOP
     ↓
    [ Element ]
         ↓
    [ Element ]
         ↓
    [ Element ]
         ↓
       NULL

The implementation follows the **LIFO (Last In, First Out)** principle.

### ⚙️ Approach

    START
      ↓
    Initialize TOP = NULL
      ↓
    Perform Stack Operation
      ↓
    ┌───────────────┐
    │   Operation   │
    └───────┬───────┘
            │
       ┌────┼────┐
       ↓    ↓    ↓
      Push Pop  Peek
       │    │    │
       ↓    ↓    ↓
    Update TOP
       ↓
    Display Stack
       ↓
      END

**Push:** Creates a new node and places it at the top.

**Pop:** Removes the top node and updates the top pointer.

**Peek:** Displays the current top element.

**Display:** Traverses the linked list from top to bottom.

### ⏱️ Complexity

| Operation | Time | Space |
| :--- | :---: | :---: |
| ➕ Push | `O(1)` | `O(1)` |
| ➖ Pop | `O(1)` | `O(1)` |
| 👁️ Peek | `O(1)` | `O(1)` |
| 📋 Display | `O(n)` | `O(1)` |
| 💾 Overall Storage | `O(n)` | `O(n)` |

### 📄 Implementation

👉 **[Open `stack.cpp`](./stack.cpp)**

---

# 🚶 03 — Queue Using Linked List

### What does it do?

Implements a **Queue using a linked list** with operations for `enqueue`, `dequeue`, `peek`, and `display`.

### 🧠 How it works

The implementation maintains two pointers:

    FRONT                         REAR
      ↓                             ↓
    [ Element ] → [ Element ] → [ Element ]
                                      ↓
                                    NULL

The implementation follows the **FIFO (First In, First Out)** principle.

### ⚙️ Approach

    START
      ↓
    Initialize FRONT and REAR
      ↓
    Perform Queue Operation
      ↓
    ┌────────────────┐
    │   Operation    │
    └───────┬────────┘
            │
       ┌────┼─────┐
       ↓    ↓     ↓
    Enqueue Dequeue Peek
       │      │     │
       ↓      ↓     ↓
    Update FRONT / REAR
            ↓
         Display
            ↓
           END

**Enqueue:** Creates a new node and adds it at the rear.

**Dequeue:** Removes the node from the front and moves the front pointer forward.

**Peek:** Displays the front and rear elements.

**Display:** Traverses the linked list from front to rear.

### ⏱️ Complexity

| Operation | Time | Space |
| :--- | :---: | :---: |
| ➕ Enqueue | `O(1)` | `O(1)` |
| ➖ Dequeue | `O(1)` | `O(1)` |
| 👁️ Peek | `O(1)` | `O(1)` |
| 📋 Display | `O(n)` | `O(1)` |
| 💾 Overall Storage | `O(n)` | `O(n)` |

### 📄 Implementation

👉 **[Open `queue.cpp`](./queue.cpp)**

---

# ⚖️ Comparison

| | 🗼 Tower of Hanoi | 📚 Stack | 🚶 Queue |
| :--- | :---: | :---: | :---: |
| **Main Concept** | Disk Movement | LIFO | FIFO |
| **Implementation** | Iterative & Recursive | Linked List | Linked List |
| **Main Operations** | Move Disks | Push, Pop, Peek | Enqueue, Dequeue, Peek |
| **Typical Operation Time** | `O(2ⁿ)` | `O(1)` | `O(1)` |
| **Traversal / Display** | `O(2ⁿ)` | `O(n)` | `O(n)` |
| **Space** | `O(n)` | `O(n)` | `O(n)` |

---

# 🧠 Approaches Used

| Program | Approach |
| :--- | :--- |
| 🗼 **Tower of Hanoi** | Uses both iterative and recursive approaches |
| 📚 **Stack** | Uses a linked list with a `top` pointer |
| 🚶 **Queue** | Uses a linked list with `front` and `rear` pointers |

---

# 🎯 Key Takeaways

### 🗼 Tower of Hanoi

> **Iterative & Recursive Implementation** — demonstrates two approaches for solving the same disk movement problem.

### 📚 Stack

> **LIFO Data Structure** — insertion and deletion are performed from the top.

### 🚶 Queue

> **FIFO Data Structure** — insertion is performed at the rear and deletion at the front.

### 🧠 Algorithm Design

The laboratory demonstrates the use of **recursion, iteration, linked lists, pointers, and fundamental linear data structures** in C++.

---

## 📂 Programs

| Program | Description | Source |
| :--- | :--- | :---: |
| 🗼 **Tower of Hanoi** | Solves Tower of Hanoi using iterative and recursive approaches | [View →](./tower_of_hanoi.cpp) |
| 📚 **Stack** | Implements Stack using a linked list | [View →](./stack.cpp) |
| 🚶 **Queue** | Implements Queue using a linked list | [View →](./queue.cpp) |

---

### 🏁 Laboratory Progress

**Week 03** · **Stack, Queue & Tower of Hanoi** · **Completed ✅**

---

<sub>Design and Analysis of Algorithms Laboratory • C++ • Week 03</sub>
