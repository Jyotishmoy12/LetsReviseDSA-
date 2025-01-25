Problem Statement in Detail
You are given an undirected tree with 
𝑛
n nodes labeled from 
1
1 to 
𝑛
n, and an array edges where each element is a pair of nodes 
[
𝑢
,
𝑣
]
[u,v] representing an edge between node 
𝑢
u and node 
𝑣
v. The root of the tree is always node 
1
1.

Initially, a frog is positioned at node 
1
1. At each second, the frog jumps to one of its adjacent nodes with equal probability. The frog can stay at its current position only if there are no unvisited adjacent nodes or if the time 
𝑡
t is exhausted.

Given the number of seconds 
𝑡
t, and a target node 
𝑡
𝑎
𝑟
𝑔
𝑒
𝑡
target, find the probability of the frog being at the target node after 
𝑡
t seconds.

Input:
n: Number of nodes in the tree.
edges: A list of edges where each edge connects two nodes.
t: Number of seconds available for the frog's movement.
target: The target node to check.
Output:
A floating-point value representing the probability of the frog being at the target node after 
𝑡
t seconds.
Example:
Input:

css
Copy
Edit
n = 7
edges = [[1, 2], [1, 3], [2, 4], [2, 5], [3, 6], [3, 7]]
t = 2
target = 4
Output:

Copy
Edit
0.16666666666666666
Explanation:

The tree structure:
markdown
Copy
Edit
       1
     /   \
    2     3
   / \   / \
  4   5 6   7
At 
𝑡
=
0
t=0: Frog is at node 
1
1.
At 
𝑡
=
1
t=1: Frog jumps to nodes 
2
2 or 
3
3, each with a probability of 
1
/
2
1/2.
At 
𝑡
=
2
t=2: Frog jumps to nodes 
4
4, 
5
5, 
6
6, or 
7
7. Node 
4
4 is reached via node 
2
2, with probability 
1
/
2
×
1
/
2
=
1
/
4
1/2×1/2=1/4.
Intuition - How It Is a Graph Problem
The problem can be represented as a tree traversal problem, where:

Nodes represent the positions the frog can visit.
Edges represent possible jumps between adjacent nodes.
The frog's movement follows a breadth-first search (BFS) or depth-first search (DFS), with the added constraint of equal probability distribution among all adjacent nodes.
The goal is to determine the probability of reaching the target node at exactly 
𝑡
t seconds.

Approach to Solve
Graph Representation:
Use an adjacency list to represent the tree from the edges input.
DFS Traversal:
Perform a depth-first search from the root node 
1
1.
Keep track of the current node, the remaining time 
𝑡
t, and the probability of being at the current node.
Probability Calculation:
At each node, distribute the probability equally among unvisited child nodes.
Stop traversing if:
𝑡
=
0
t=0, or
The target node is reached, and it has no unvisited children.
Edge Cases:
If 
𝑡
𝑎
𝑟
𝑔
𝑒
𝑡
target is unreachable within 
𝑡
t seconds, return 
0
0.
If 
𝑡
𝑎
𝑟
𝑔
𝑒
𝑡
target is not visited even after 
𝑡
t seconds, return 
0
0.
Code (C++)
cpp
Copy
Edit
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
        // Build the adjacency list for the tree
        unordered_map<int, vector<int>> graph;
        for (auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        // Perform DFS with probability tracking
        vector<bool> visited(n + 1, false);
        return dfs(graph, 1, target, t, visited, 1.0);
    }

private:
    double dfs(unordered_map<int, vector<int>>& graph, int node, int target, int t, vector<bool>& visited, double prob) {
        visited[node] = true;
        
        // If time runs out or we reach the target
        if (t == 0 || (node == target && graph[node].size() == (node == 1 ? 0 : 1))) {
            return node == target ? prob : 0.0;
        }
        
        // Count unvisited neighbors
        int unvisitedCount = 0;
        for (int neighbor : graph[node]) {
            if (!visited[neighbor]) {
                unvisitedCount++;
            }
        }
        
        // If no unvisited neighbors, stay at current node
        if (unvisitedCount == 0) {
            return node == target ? prob : 0.0;
        }

        // Distribute probability among unvisited neighbors
        double result = 0.0;
        for (int neighbor : graph[node]) {
            if (!visited[neighbor]) {
                result += dfs(graph, neighbor, target, t - 1, visited, prob / unvisitedCount);
            }
        }

        return result;
    }
};
Code Explanation Line by Line
Graph Construction:

cpp
Copy
Edit
unordered_map<int, vector<int>> graph;
for (auto& edge : edges) {
    graph[edge[0]].push_back(edge[1]);
    graph[edge[1]].push_back(edge[0]);
}
Build an adjacency list representation of the tree from the edges input.
DFS Function:

cpp
Copy
Edit
return dfs(graph, 1, target, t, visited, 1.0);
Start DFS traversal from the root node 
1
1 with initial probability 
1.0
1.0.
Base Case in DFS:

cpp
Copy
Edit
if (t == 0 || (node == target && graph[node].size() == (node == 1 ? 0 : 1))) {
    return node == target ? prob : 0.0;
}
If time 
𝑡
t is exhausted or the target node is reached, return the current probability.
Count Unvisited Neighbors:

cpp
Copy
Edit
int unvisitedCount = 0;
for (int neighbor : graph[node]) {
    if (!visited[neighbor]) {
        unvisitedCount++;
    }
}
Calculate how many unvisited neighbors are available for traversal.
Distribute Probability:

cpp
Copy
Edit
for (int neighbor : graph[node]) {
    if (!visited[neighbor]) {
        result += dfs(graph, neighbor, target, t - 1, visited, prob / unvisitedCount);
    }
}
Recursively call DFS for each unvisited neighbor, distributing the probability equally.
Dry Run
Input:
css
Copy
Edit
n = 7
edges = [[1, 2], [1, 3], [2, 4], [2, 5], [3, 6], [3, 7]]
t = 2
target = 4
Steps:
Graph Representation:

css
Copy
Edit
1 -> [2, 3]
2 -> [1, 4, 5]
3 -> [1, 6, 7]
4 -> [2]
5 -> [2]
6 -> [3]
7 -> [3]
Start DFS from node 
1
1:

Probability = 
1.0
1.0.
𝑡
=
2
t=2.
Neighbors: 
2
,
3
2,3.
Move to node 
2
2:

Probability = 
0.5
0.5.
𝑡
=
1
t=1.
Neighbors: 
4
,
5
4,5.
Move to node 
4
4:

Probability = 
0.5
×
0.5
=
0.25
0.5×0.5=0.25.
𝑡
=
0
t=0.
Reached target node.
Complexity Analysis
Time Complexity: 
𝑂
(
𝑉
+
𝐸
)
O(V+E) for traversing all nodes and edges in the tree.
Space Complexity: 
𝑂
(
𝑉
)
O(V) for the visited array and recursion stack.
