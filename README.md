# Data Structures Implementation

## Overview
This project implements four core data structures from scratch in C++:

1. Singly Linked List
2. Doubly Linked List
3. Stack
4. Queue

Each structure supports:
- Insert
- Delete
- Search
- Traversal

The implementation uses dynamic memory where required and releases allocated memory through destructors and clear functions.

## Folder Structure

```text
data_structures_implementation/
├── src/
│   ├── singly_linked_list.cpp
│   ├── doubly_linked_list.cpp
│   ├── stack.cpp
│   └── queue.cpp
├── tests/
│   └── test_data_structures.cpp
└── README.md
```

## How to Compile

Using g++:

```bash
g++ src/singly_linked_list.cpp -o singly
g++ src/doubly_linked_list.cpp -o doubly
g++ src/stack.cpp -o stack
g++ src/queue.cpp -o queue
g++ tests/test_data_structures.cpp -o tests
```

Run:

```bash
./singly
./doubly
./stack
./queue
./tests
```

For Dev-C++:
1. Open Dev-C++.
2. Select File → New → Source File.
3. Copy one source file.
4. Save it with the `.cpp` extension.
5. Press F11 or select Execute → Compile & Run.

## Time and Space Complexity

| Data Structure | Operation | Time Complexity | Extra Space |
|---|---|---:|---:|
| Singly Linked List | Insert at end | O(n) | O(1) |
| Singly Linked List | Delete by value | O(n) | O(1) |
| Singly Linked List | Search | O(n) | O(1) |
| Singly Linked List | Traversal | O(n) | O(1) |
| Doubly Linked List | Insert at end | O(n) | O(1) |
| Doubly Linked List | Delete by value | O(n) | O(1) |
| Doubly Linked List | Search | O(n) | O(1) |
| Doubly Linked List | Traversal | O(n) | O(1) |
| Stack | Push | O(1) | O(1) |
| Stack | Pop | O(1) | O(1) |
| Stack | Search | O(n) | O(1) |
| Stack | Traversal | O(n) | O(1) |
| Queue | Enqueue | O(1) | O(1) |
| Queue | Dequeue | O(1) | O(1) |
| Queue | Search | O(n) | O(1) |
| Queue | Traversal | O(n) | O(1) |

## Memory Management
- Dynamically allocated nodes are deleted.
- Destructors call `clear()`.
- Stack and queue nodes are released when removed.
- No intentionally allocated memory is left unreleased.

## Testing
The test file checks insertion, deletion, searching, traversal, stack operations, queue operations, and empty-state behavior.
