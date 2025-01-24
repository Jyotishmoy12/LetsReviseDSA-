Problem Statement: Friend Circles
You are given an 
𝑛
×
𝑛
n×n matrix M, where 
𝑀
[
𝑖
]
[
𝑗
]
=
1
M[i][j]=1 indicates that person 
𝑖
i and person 
𝑗
j are directly friends, and 
𝑀
[
𝑖
]
[
𝑗
]
=
0
M[i][j]=0 otherwise. A "friend circle" is a group of people who are either directly or indirectly friends (e.g., a friend of a friend). Your task is to determine the total number of friend circles in the matrix.

Approach: Using Depth-First Search (DFS)
This is a graph problem where:

Each person is a node.
Friendship between two people is an edge.
A "friend circle" is simply a connected component in the graph.
To solve this, we can use DFS to explore the graph and count the number of connected components.

Steps to Solve:
Representation:
Use the given matrix M as the adjacency matrix of the graph. If 
𝑀
[
𝑖
]
[
𝑗
]
=
1
M[i][j]=1, there is an edge between node 
𝑖
i and node 
𝑗
j.

Visited Array:
Maintain an array visited to track which nodes (people) have been visited.

DFS Implementation:
For each person, if they haven't been visited, start a DFS to visit all the nodes in their connected component. This corresponds to discovering one "friend circle."

Count Circles:
Each time a DFS is initiated for an unvisited person, increment the friend circle count.

Template Code with Explanation (C++)
cpp
Copy
Edit
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // Function to perform DFS for a node
    void dfs(int person, vector<vector<int>>& M, vector<bool>& visited) {
        // Mark the current person as visited
        visited[person] = true;
        
        // Explore all friends of the current person
        for (int other = 0; other < M.size(); ++other) {
            if (M[person][other] == 1 && !visited[other]) {
                dfs(other, M, visited); // Recursive call for the friend
            }
        }
    }
    
    int findCircleNum(vector<vector<int>>& M) {
        int n = M.size(); // Number of people (nodes)
        vector<bool> visited(n, false); // Visited array
        int circleCount = 0; // Number of friend circles
        
        // Iterate through each person
        for (int person = 0; person < n; ++person) {
            if (!visited[person]) {
                // Start a DFS for the unvisited person
                dfs(person, M, visited);
                // Increment circle count
                circleCount++;
            }
        }
        
        return circleCount; // Return the total number of friend circles
    }
};

int main() {
    vector<vector<int>> M = {
        {1, 1, 0},
        {1, 1, 0},
        {0, 0, 1}
    };

    Solution solution;
    cout << "Number of Friend Circles: " << solution.findCircleNum(M) << endl;

    return 0;
}
Explanation of Each Step:
DFS Function:

Line 6-7: The dfs function marks the current person as visited.
Line 9-11: Iterates over all people. If a friendship exists and the other person is unvisited, it recursively calls dfs for that person.
Friend Circle Count:

Line 17: Initializes the visited array to keep track of which nodes (people) have already been visited.
Line 18: Initializes the circleCount to 0.
Line 21-25: Iterates over all nodes (people). If a node is unvisited, it starts a DFS, marks the connected component as visited, and increments the friend circle count.
Main Function:

Line 29-33: Defines the adjacency matrix M and calls the findCircleNum function to calculate the number of friend circles.
Dry Run Example
Input:
cpp
Copy
Edit
M = {
    {1, 1, 0},
    {1, 1, 0},
    {0, 0, 1}
};
Step-by-Step Execution:
Initialization:

visited = [false, false, false]
circleCount = 0
Outer Loop:

Person 0: Not visited, start DFS.

Mark visited[0] = true.
Explore M[0][1] = 1. Start DFS for person 1.
Mark visited[1] = true.
Person 1 has no unvisited friends. DFS ends.
Circle complete. Increment circleCount = 1.
Person 1: Already visited, skip.

Person 2: Not visited, start DFS.

Mark visited[2] = true.
No unvisited friends. DFS ends.
Circle complete. Increment circleCount = 2.
Final State:

visited = [true, true, true]
circleCount = 2
Output:
cpp
Copy
Edit
Number of Friend Circles: 2
Complexity Analysis
Time Complexity:

The outer loop runs 
𝑂
(
𝑛
)
O(n), where 
𝑛
n is the number of people.
For each person, the DFS explores 
𝑂
(
𝑛
)
O(n) nodes in the worst case.
Total complexity: 
𝑂
(
𝑛
2
)
O(n 
2
 ), which matches the size of the adjacency matrix.
Space Complexity:

The visited array requires 
𝑂
(
𝑛
)
O(n) space.
The recursion stack for DFS may also require 
𝑂
(
𝑛
)
O(n) space in the worst case.
Total space complexity: 
𝑂
(
𝑛
)
O(n).
Alternative Solutions:
Union-Find (Disjoint Set Union):
Use Union-Find to group nodes into connected components.
Faster in practice for sparse graphs.
Complexity: 
𝑂
(
𝑛
2
⋅
𝛼
(
𝑛
)
)
O(n 
2
 ⋅α(n)), where 
𝛼
(
𝑛
)
α(n) is the inverse Ackermann function.
