# Case Study: Social Network Adjacency Matrix

**Language:** Python  
**Topic:** Graph representation using an adjacency matrix

## 1. Aim
To represent friendship connections between users of a social networking application using an adjacency matrix and use it to check whether two users are directly connected.

## 2. Problem statement
A social network contains users and friendship links. The application needs a clear way to represent which users are directly connected. In this example, each user is a graph vertex and each friendship is an edge.

## 3. Strategy used
**Graph representation — Adjacency Matrix**

- Each row and column represents a user.
- `1` means two users are directly connected.
- `0` means there is no direct friendship.
- Because the example treats friendship as mutual, the matrix is symmetric: if `matrix[i][j]` is `1`, then `matrix[j][i]` is also `1`.
- A user's diagonal entry is `0` because the sample does not represent users as their own friends.

## 4. Example
Users: `Asha, Ravi, Neha, Om, Sara`

Friendships:
- Asha — Ravi
- Asha — Neha
- Ravi — Om
- Neha — Om
- Om — Sara

The program builds and prints the matrix, checks if Asha and Ravi are friends, checks if Asha and Sara are friends, and lists Om's direct friends.

## 5. How to run
1. Install Python 3 if it is not already installed.
2. Extract this ZIP file.
3. Open a terminal or command prompt in the extracted folder.
4. Run:

   ```bash
   python main.py
   ```

   On some Windows installations, use:

   ```bash
   py main.py
   ```

## 6. Time and space complexity
Let `V` be the number of users and `E` be the number of friendship links.

| Operation | Complexity |
|---|---:|
| Create and initialize matrix | O(V²) |
| Add all friendship links after initialization | O(E) |
| Check whether two users are friends | O(1) |
| List all direct friends of one user | O(V) |
| Space used by the matrix | O(V²) |

Matrix initialization dominates the construction cost, so the total construction time is **O(V² + E)**.

## 7. Important limitation for millions of users
An adjacency matrix is easy to understand and provides very fast direct friendship checks, but it uses `V × V` entries. For 1,000,000 users, that is 1,000,000,000,000 entries (one trillion), which is usually impractical in memory. Python lists require even more memory than one byte per entry.

For a real network with relatively few friendships per user, an **adjacency list** or a graph database is generally more suitable because it stores existing connections rather than every possible pair. This case study uses a small dataset to demonstrate the required adjacency-matrix concept; it does not attempt to allocate a million-user matrix.

## 8. Conclusion
An adjacency matrix represents social-network friendships in a simple two-dimensional structure. It can check a direct connection in O(1) time, but requires O(V²) space. Therefore, it is useful for small or dense graphs, while adjacency lists are generally more practical for very large, sparse social networks.
