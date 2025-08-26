# Dijkstra Algorithm Implementation in C++

This repository demonstrates the implementation of Dijkstra's shortest path algorithm in C++. The program can find the shortest path between vertices in a weighted graph, either from one vertex to all others or between two specific vertices.

## Project Description

This project implements Dijkstra's algorithm for finding the shortest paths in a weighted graph. Features include:
- Reading graph data from a file or manual input
- Finding shortest paths from a source vertex to all other vertices
- Finding shortest path between two specific vertices
- Interactive menu-driven interface
- Support for graphs with up to 50 vertices

## Code Structure

The project consists of three main files:
- `Dijkstra.cpp` - Main program file containing the algorithm implementation and interface
- `Graph.txt` - Example input file containing a sample graph structure
- `README.md` - Project documentation

### Key Components in Dijkstra.cpp
- `struct Graph` - Graph representation using adjacency matrix
- `Dijkstra()` - Core algorithm implementation
- `NhapMatrix_File()` - File input handling
- `Display_ALL()` and `Display_ONE()` - Path visualization functions

## How to Run the Project

### Requirements
- C++ compiler (supporting C++11 or later)
- Basic input/output file handling support

### Installation and Running
1. Clone the repository
2. Compile the program:
   ```bash
   g++ Dijkstra.cpp -o dijkstra
   ```
3. Run the executable:
   ```bash
   ./dijkstra
   ```

### Using the Program
1. Choose option 3 to load a graph from `Graph.txt` or option 2 for manual input
2. Use option 4 to view the current graph
3. Use option 5 to find paths from one vertex to all others
4. Use option 6 to find path between two specific vertices

### Input File Format
The `Graph.txt` file should follow this format:
- First line: number of vertices (n)
- Next n lines: adjacency matrix (nxn)
Example:
```
5
0 6 0 1 0
6 0 5 2 2
0 5 0 0 5
1 2 0 0 1
0 2 5 1 0
```

## Coding Conventions

The project follows these coding conventions:
- Variable names use camelCase
- Function names use PascalCase
- Constants are defined using #define
- Comments are in Vietnamese
- Matrix indices start from 0
- INF (infinity) is represented as 999
- Maximum graph size is defined as MAX (50)

## Notes for Contributors

### Guidelines for Contributing
1. Fork the repository
2. Create a feature branch
3. Follow the existing coding style
4. Add comments for complex logic
5. Test your changes with different graph sizes
6. Submit a pull request

### Areas for Improvement
- Add input validation
- Implement better error handling
- Add support for directed graphs
- Optimize memory usage for large graphs
- Add visualization features
- Translate comments to English

## License

This project is open source and available for educational purposes.