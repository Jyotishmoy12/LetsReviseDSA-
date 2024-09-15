Problem Explanation: Island Perimeter
You are given a 2D grid where:

1 represents land.
0 represents water.
Your goal is to find the perimeter of the island. The island is a collection of 1s (land cells) connected horizontally or vertically, and there is exactly one island in the grid (i.e., all land cells are connected).

The perimeter of the island is defined as the total length of its edges that are adjacent to water or the boundary of the grid.

Intuition
The intuition here is straightforward: each land cell (1) contributes to the perimeter based on how many of its neighboring cells are water (0) or lie outside the grid. A land cell can have up to four neighbors: up, down, left, and right. For each direction where a neighboring cell is water or out of bounds, we increment the perimeter by 1.

If a land cell is adjacent to a water cell (or the boundary), it adds to the perimeter.
If a land cell is adjacent to another land cell, there is no contribution to the perimeter in that direction.
Why BFS/DFS?
Though BFS or DFS can be used to traverse the island, the problem can be solved more simply by iterating over each land cell and directly counting its contribution to the perimeter. Since we are just checking neighboring cells, we don't need to do a full traversal of the island with BFS/DFS.

However, DFS or BFS can be used to explore the connected landmass in a traversal-style approach if the problem required multiple islands or more complex exploration. For this specific problem, iterating through each cell and checking its neighbors is more efficient.

Approach:
Iterate over the grid:
Traverse through every cell in the grid.

Check land cells:
For each land cell (1), check its four neighbors (up, down, left, right).

Count perimeter contribution:
If a neighbor is water (0) or out of bounds (beyond grid boundaries), increment the perimeter by 1 for that side.

Example Test Case
Input:

csharp
Copy code
[
  [0, 1, 0, 0],
  [1, 1, 1, 0],
  [0, 1, 0, 0],
  [1, 1, 0, 0]
]
Output:

Copy code
16
Explanation:
The island is a connected group of 1s.
For each land cell, we check its neighbors and count how many sides are adjacent to water or out of bounds.
For example:
The top-left 1 at (0, 1) contributes 3 to the perimeter (because it is adjacent to 3 water cells or boundaries).
The central 1 at (1, 1) contributes 1 to the perimeter because it's surrounded by land on all sides except one.
C++ Code Implementation
cpp
Copy code
#include <iostream>
#include <vector>
using namespace std;

int islandPerimeter(vector<vector<int>>& grid) {
    int rows = grid.size();
    int cols = grid[0].size();
    int perimeter = 0;

    // Iterate over each cell in the grid
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (grid[i][j] == 1) {
                // Check all four possible directions
                // Check the cell above
                if (i == 0 || grid[i - 1][j] == 0) perimeter++;
                // Check the cell below
                if (i == rows - 1 || grid[i + 1][j] == 0) perimeter++;
                // Check the cell to the left
                if (j == 0 || grid[i][j - 1] == 0) perimeter++;
                // Check the cell to the right
                if (j == cols - 1 || grid[i][j + 1] == 0) perimeter++;
            }
        }
    }

    return perimeter;
}

int main() {
    vector<vector<int>> grid = {
        {0, 1, 0, 0},
        {1, 1, 1, 0},
        {0, 1, 0, 0},
        {1, 1, 0, 0}
    };

    cout << "Island Perimeter: " << islandPerimeter(grid) << endl;

    return 0;
}
Dry Run:
Given the input:

csharp
Copy code
[
  [0, 1, 0, 0],
  [1, 1, 1, 0],
  [0, 1, 0, 0],
  [1, 1, 0, 0]
]
We iterate through the grid:

At cell (0, 1) (land):

Above: Out of bounds (+1).
Below: Land (0).
Left: Water (+1).
Right: Water (+1).
Contribution to perimeter = 3.
At cell (1, 0) (land):

Above: Water (+1).
Below: Water (+1).
Left: Out of bounds (+1).
Right: Land (0).
Contribution to perimeter = 3.
At cell (1, 1) (land):

Above: Land (0).
Below: Land (0).
Left: Land (0).
Right: Land (0).
Contribution to perimeter = 0.
Continue similarly for all other land cells, summing their contributions to the perimeter.

The total perimeter is 16.

Complexity Analysis:
Time Complexity:
We traverse the grid once, visiting each cell exactly once. Checking each cell's neighbors takes constant time. Therefore, the time complexity is O(m * n), where m is the number of rows and n is the number of columns in the grid.

Space Complexity:
We use only a few extra variables (for counting the perimeter and iterating through the grid), so the space complexity is O(1), ignoring the input grid itself.

Thus, the time complexity is O(m * n), and the space complexity is O(1).






