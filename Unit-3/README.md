# Unit 3 Case Study: Stack and Queue Using Linked Lists

## Aim
To implement and demonstrate stack and queue operations using linked lists.

## Objectives
- Understand how nodes and pointers form a linked list.
- Implement stack operations: push, pop, peek, and display.
- Implement queue operations: enqueue, dequeue, front, and display.
- Handle empty-structure conditions safely.

## Case study
A simple service desk needs two ways to manage data:
- **Stack (LIFO):** the most recently added item is processed first. Example: undo history in an editor.
- **Queue (FIFO):** the earliest added item is processed first. Example: customers waiting for service.

The program offers a menu to try both data structures interactively.

## Implementation details
Each node stores an integer and a pointer to the next node.
- The stack maintains a `topNode` pointer.
- The queue maintains `frontNode` and `rearNode` pointers.
- Nodes are allocated dynamically and deleted when removed.
- Empty pop/dequeue operations print an underflow message.

## Operations and time complexity

| Data structure | Operation | Time |
|---|---|---:|
| Stack | Push | O(1) |
| Stack | Pop | O(1) |
| Stack | Peek | O(1) |
| Stack | Display | O(n) |
| Queue | Enqueue | O(1) |
| Queue | Dequeue | O(1) |
| Queue | Front | O(1) |
| Queue | Display | O(n) |

## How to compile and run
### Windows (MinGW g++)
Open the folder in VS Code, open Terminal, and run:
```bash
g++ main.cpp -o stack_queue
.\stack_queue.exe
```

### Linux / macOS
```bash
g++ main.cpp -o stack_queue
./stack_queue
```

If `g++` is not installed, install a C++ compiler first.

## Sample test
1. Choose `1` for Stack operations.
2. Push `10`, then push `20`.
3. Display should show `20 10` (top to bottom).
4. Pop should remove `20`.
5. Go back and choose `2` for Queue operations.
6. Enqueue `10`, then `20`.
7. Display should show `10 20` (front to rear).
8. Dequeue should remove `10`.

## Conclusion
Stack and queue operations can be implemented effectively using linked lists. The stack inserts and removes at the head, while the queue inserts at the rear and removes from the front. Both can grow dynamically without requiring a fixed array size.

## Viva questions
1. What is a linked list?
2. What does LIFO mean?
3. What does FIFO mean?
4. What are stack overflow and underflow?
5. Why does a queue need both front and rear pointers?
6. What is the time complexity of push and pop in a linked-list stack?
7. What happens to the rear pointer when the last queue node is removed?
