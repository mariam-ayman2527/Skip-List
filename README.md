# Skip List Implementation in C++17

A complete C++ implementation of the **Skip List** data structure, featuring probabilistic balancing for efficient element insertion, deletion, and search operations with $O(\log n)$ average time complexity.

##  Features

* **Probabilistic Level Generation:** Uses C++ `<random>` library (`std::mt19937`) for uniform distribution.
* **Core Operations:**
  * `insert(key, value)`: Inserts a new node or updates an existing key.
  * `remove(key)`: Deletes a node by key and cleans up memory.
  * `search(key, value)`: Finds a node by key in $O(\log n)$ average time.
* **Level Visualization:** Includes a `print()` method to display all active levels and their nodes.
* **Memory Safe:** Destructor ensures clean dynamic memory deallocation to prevent leaks.

## 📁 Project Structure
```text
.
├── SkipList.h     # SkipList & Node class declarations
├── SkipList.cpp   # Implementation of Skip List methods
├── test.h         # Test function declarations
├── test.cpp       # Unit test implementations
└── main.cpp       # Main driver file
```

## Prerequisites & Compilation

Requires a C++ compiler supporting C++17 or higher (such as g++ or clang++).

**Build Command**
Compile all .cpp files using g++:

```bash
g++ -std=c++17 main.cpp test.cpp SkipList.cpp -o main
```

## included Unit Tests

The project includes test coverage in test.cpp for:

```bash testPrint()```: Tests basic insertion and multi-level layout printing.

```bash testRandomInsert()```: Verifies behavior under randomized insertion orders.

```bash testDeleteAndLevel()```: Validates node removal and automatic dynamic level reduction


