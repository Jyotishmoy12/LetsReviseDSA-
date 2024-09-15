Problem Explanation: Walls and Gates
You are given a 2D grid where:

-1 represents a wall or an obstacle.
0 represents a gate.
INF represents an empty room (which can be an arbitrary large value like 2147483647).
Your goal is to fill each empty room with the distance to its nearest gate. If it's impossible to reach a gate from a room, it should remain as INF.

Intuition
The intuition is to think of the problem as a multi-source shortest path problem. Each gate (0) is a source, and you need to calculate the shortest distance from all the gates to all the empty rooms (INF).

A key insight is that breadth-first search (BFS) is the optimal approach here. BFS explores all neighbors at the present depth before moving on to nodes at the next depth level, ensuring that the first time you reach an empty room, it's via the shortest path. This property makes BFS ideal for shortest path problems in unweighted grids.

Why BFS/DFS?
BFS: BFS is a perfect fit because it guarantees that the first time we reach an empty room, we do so with the shortest path. BFS expands outward layer by layer, starting from all gates simultaneously.

DFS: DFS could technically work as well, but it would be inefficient for this problem. DFS would traverse deeper into the grid and might not find the shortest path first, requiring us to explore all possibilities before determining the shortest path to each empty room.

Approach:
Start BFS from all gates:
We initiate BFS from all 0s (gates). We push all gates into a queue at the start. This allows us to expand from multiple sources at once.

Explore neighbors:
For each cell, we explore its neighboring cells in four possible directions (up, down, left, right). If a neighboring cell is an empty room (INF), we update its value to the current distance from the gate and push it into the queue for further exploration.

Distance Propagation:
The distance from each gate is propagated through the grid, and since BFS explores layer by layer, the first time we reach a room, we are guaranteed to have the shortest distance.

Example Test Case
Input:

csharp
Copy code
[
  [INF, -1,  0, INF],
  [INF, INF, INF, -1],
  [INF, -1, INF, -1],
  [0, -1, INF, INF]
]
Output:

csharp
Copy code
[
  [3,  -1,  0,  1],
  [2,   2,  1, -1],
  [1,  -1,  2, -1],
  [0,  -1,  3,  4]
]
Explanation:
Start with the gates (marked 0). The gates are at positions (0, 2) and (3, 0). These are the starting points for BFS.
For each BFS level, propagate the distance to adjacent empty rooms (INF). We keep a queue of gates and their neighbors to explore, ensuring that the first time we reach an empty room, it's with the minimum distance.
After BFS completes, the grid will be updated with the shortest distance from any gate.
C++ Code Implementation
cpp
Copy code
#include <iostream>
#include <queue>
#include <vector>
#include <limits.h>
using namespace std;

void wallsAndGates(vector<vector<int>>& rooms) {
    if (rooms.empty()) return;
    
    int rows = rooms.size();
    int cols = rooms[0].size();
    queue<pair<int, int>> q;
    
    // Push all gates into the queue
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (rooms[i][j] == 0) {
                q.push({i, j});
            }
        }
    }

    // Define directions for moving up, down, left, and right
    vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    
    // Perform BFS from each gate
    while (!q.empty()) {
        auto [r, c] = q.front();
        q.pop();
        
        // Explore neighbors
        for (auto dir : directions) {
            int newRow = r + dir.first;
            int newCol = c + dir.second;
            
            // Continue if out of bounds or if it's not an empty room
            if (newRow < 0 || newRow >= rows || newCol < 0 || newCol >= cols || rooms[newRow][newCol] != INT_MAX) {
                continue;
            }
            
            // Update distance and add to the queue
            rooms[newRow][newCol] = rooms[r][c] + 1;
            q.push({newRow, newCol});
        }
    }
}

int main() {
    vector<vector<int>> rooms = {
        {INT_MAX, -1, 0, INT_MAX},
        {INT_MAX, INT_MAX, INT_MAX, -1},
        {INT_MAX, -1, INT_MAX, -1},
        {0, -1, INT_MAX, INT_MAX}
    };

    wallsAndGates(rooms);
    
    for (const auto& row : rooms) {
        for (int cell : row) {
            if (cell == INT_MAX) cout << "INF ";
            else cout << cell << " ";
        }
        cout << endl;
    }

    return 0;
}
Dry Run:
Given the input:

csharp
Copy code
[
  [INF, -1,  0, INF],
  [INF, INF, INF, -1],
  [INF, -1, INF, -1],
  [0, -1, INF, INF]
]
We start by enqueuing all gates. The initial queue is: [(0, 2), (3, 0)].
Begin BFS:
From (0, 2), we explore (1, 2) (distance 1) and (0, 3) (distance 1). Updated grid:
csharp
Copy code
[INF, -1, 0, 1],
[INF, INF, 1, -1],
[INF, -1, INF, -1],
[0, -1, INF, INF]
From (3, 0), we explore (2, 0) (distance 1). Updated grid:
csharp
Copy code
[INF, -1, 0, 1],
[INF, INF, 1, -1],
[1, -1, INF, -1],
[0, -1, INF, INF]
Continue BFS from each new cell until the queue is empty, updating the grid.
Final grid:

csharp
Copy code
[
  [3,  -1,  0,  1],
  [2,   2,  1, -1],
  [1,  -1,  2, -1],
  [0,  -1,  3,  4]
]
Complexity Analysis:
Time Complexity:
Each cell is processed at most once, and there are O(m * n) cells in total (where m is the number of rows and n is the number of columns). For each cell, we check its four neighbors, making the overall time complexity O(m * n).

Space Complexity:
The space complexity is also O(m * n) due to the space used by the queue. Each cell can be enqueued once, resulting in O(m * n) space for the queue.

Thus, the time and space complexity is both O(m * n).
