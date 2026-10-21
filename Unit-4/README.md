# Unit 4 Case Study: Dictionary Application Using Hash Tables

## Aim
To implement a dictionary that stores and retrieves words and meanings using a hash table with collision resolution.

## Objectives
- Understand hashing and hash-table indexing.
- Store word–meaning pairs.
- Search, add, update, and delete dictionary entries.
- Handle collisions using **separate chaining**.

## Problem description
A dictionary application must quickly find a word's meaning. A hash function maps each word to an index in a table. Different words can map to the same index; this is called a collision.

This C++ program resolves collisions using **separate chaining**: each table index contains a linked list of entries. The program also supports case-insensitive word matching.

## Operations
1. Add a word and meaning.
2. Search for a word.
3. Delete a word.
4. Display stored entries and the hash-table chains.
5. Update the meaning if the word already exists.

## Algorithm summary
- **Hashing:** Convert the word to lowercase, calculate its string hash, then take the remainder after dividing by table capacity.
- **Insert:** Go to the calculated index. Update the entry if the word already exists; otherwise append it to that index's chain.
- **Search:** Visit the chain at the calculated index and compare words.
- **Delete:** Find the word in its chain and remove it.
- **Display:** Print each non-empty index and its entries.

## Complexity
Let `n` be the number of stored words and `m` the table capacity.
- Average insert/search/delete: approximately **O(1)** when words are distributed well.
- Worst-case insert/search/delete: **O(n)** if many words collide into one chain.
- Display: **O(m + n)**.

## Compile and run
### Windows with g++
Open this folder in VS Code and run in the terminal:
```bash
g++ main.cpp -o dictionary
.\dictionary.exe
```

### Linux / macOS
```bash
g++ main.cpp -o dictionary
./dictionary
```

## Sample run idea
1. Choose `1`; enter `apple` and `A fruit`.
2. Add `book` and `A set of written or printed pages`.
3. Choose `2`; search for `APPLE`. The word is found without regard to letter case.
4. Choose `4` to view the entries and their hash-table indices.
5. Choose `3` to delete `apple`.

The exact hash index depends on the C++ standard-library hash implementation.

## Conclusion
The dictionary uses a hash table to locate words efficiently. Separate chaining handles collisions by storing multiple entries in a list at the same index. This makes the application useful for demonstrating hashing and basic dictionary operations.

## Viva questions
1. What is hashing?
2. What is a hash function?
3. What is a collision?
4. What is separate chaining?
5. How does separate chaining differ from linear probing?
6. What is the average time complexity of searching in a hash table?
7. Why can worst-case search take O(n)?
8. What happens when the same word is added again?
