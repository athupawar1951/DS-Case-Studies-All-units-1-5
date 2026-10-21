# Unit 5 Case Studies: Graph Navigation and Huffman Compression

This folder contains two separate C++ programs for Unit 5.

## Project A — GPS / Navigation System using a Weighted Graph
**File:** `navigation.cpp`

### Aim
Model a city map as a weighted graph and find the shortest route between places.

### Concepts
- Vertices represent places in the city.
- Weighted edges represent roads and their distances.
- An adjacency list stores road connections.
- Dijkstra's algorithm finds the shortest path for non-negative edge weights.

### Features
- Display all places.
- Display roads and weights.
- Find the shortest route and total distance between two places.
- Demonstrates a sample city with six places.

### Compile and run
Windows (g++):
```bash
g++ navigation.cpp -o navigation
.\navigation.exe
```
Linux/macOS:
```bash
g++ navigation.cpp -o navigation
./navigation
```

### Complexity
With an adjacency list and priority queue, Dijkstra's algorithm runs in approximately `O((V + E) log V)`.

## Project B — Huffman Frequency-Based Text Encoding
**File:** `huffman.cpp`

### Aim
Demonstrate frequency-based encoding using a Huffman tree, a foundational idea used in compression systems.

### Concepts
- Count how often each character occurs.
- Repeatedly combine the two least-frequent tree nodes.
- Assign 0 to a left edge and 1 to a right edge.
- Encode text using the generated prefix codes and decode it again.

### Features
- Builds a Huffman tree based on input text.
- Prints each character's frequency and code.
- Encodes and decodes the text.
- Compares original 8-bit character size with encoded bit count.

### Compile and run
Windows (g++):
```bash
g++ huffman.cpp -o huffman
.\huffman.exe
```
Linux/macOS:
```bash
g++ huffman.cpp -o huffman
./huffman
```

**Important:** `huffman.cpp` is an educational Huffman encoding demonstration. It does not create a standards-compliant `.zip` or `.gz` archive. Real ZIP/GZIP formats include headers and metadata and typically use DEFLATE, which combines LZ77 and Huffman coding.

## Sample tests
### Navigation
Select option `3`, enter source `0` (College) and destination `4` (Bus Station). The program prints a shortest route and distance.

### Huffman
Enter a sample line such as `this is a huffman example`. The program prints the character codes, encoded bits, and decoded text.

## Conclusion
The navigation program demonstrates weighted graphs and Dijkstra's shortest-path algorithm. The compression program demonstrates Huffman trees and frequency-based prefix encoding, showing how frequently occurring characters can receive shorter codes.

## Viva questions
1. What is a graph?
2. What are vertices and weighted edges?
3. What is Dijkstra's algorithm used for?
4. Why must Dijkstra's algorithm use non-negative edge weights?
5. What is an adjacency list?
6. What is data compression?
7. What is a Huffman tree?
8. Why do frequent characters usually receive shorter Huffman codes?
9. What is a prefix code?
10. Does this demo create an actual ZIP/GZIP archive?
