Problem Statement in Detail
The Max Probability Path problem involves finding the maximum probability of reaching a destination node from a starting node in a weighted graph. The weights of the edges represent probabilities of success when traveling along those edges. The task is to determine the highest probability of successfully reaching the destination node.

Input:
n: Number of nodes in the graph (nodes are labeled as 
0
0 to 
𝑛
−
1
n−1).
edges: List of edges, where each edge is represented as 
[
𝑢
,
𝑣
]
[u,v] indicating an edge between node 
𝑢
u and node 
𝑣
v.
succProb: List of probabilities associated with each edge in the same order as the edges list.
start: Starting node.
end: Destination node.
Output:
The maximum probability of reaching the destination node from the starting node. If there is no valid path, return 
0.0
0.0.
Example:
Input:

lua
Copy
Edit
n = 3
edges = [[0, 1], [1, 2], [0, 2]]
succProb = [0.5, 0.5, 0.2]
start = 0
end = 2
Output:

Copy
Edit
0.25
Explanation:

Possible paths:
0
→
2
0→2 with probability 
0.2
0.2.
0
→
1
→
2
0→1→2 with probability 
0.5
×
0.5
=
0.25
0.5×0.5=0.25.
The maximum probability is 
0.25
0.25.
Intuition - How It Is a Graph Problem
This problem can be visualized as a weighted graph:

Nodes: Represent locations.
Edges: Represent direct paths between nodes, weighted by success probabilities.
The goal is to find the maximum probability path between the start and end nodes.
Approach to Solve
We can use a modified Dijkstra's algorithm to solve this problem efficiently. Instead of finding the shortest path, we calculate the path with the highest product of probabilities.

Steps:
Graph Representation:

Use an adjacency list to store the graph, where each node points to its neighbors and the respective probabilities.
Priority Queue:

Use a max-heap (priority queue) to always process the node with the highest probability first.
Relaxation:

For each node processed, update the probabilities of its neighbors if a higher probability path is found.
Terminate:

Stop when the destination node is reached, or all possible paths have been exhausted.
Code in C++
cpp
Copy
Edit
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
    // Build the graph as an adjacency list
    vector<vector<pair<int, double>>> graph(n);
    for (int i = 0; i < edges.size(); i++) {
        int u = edges[i][0], v = edges[i][1];
        double prob = succProb[i];
        graph[u].push_back({v, prob});
        graph[v].push_back({u, prob});
    }

    // Priority queue for Dijkstra's algorithm
    priority_queue<pair<double, int>> pq;
    pq.push({1.0, start}); // Start with probability 1.0 at the start node

    // Maximum probability to reach each node
    vector<double> maxProb(n, 0.0);
    maxProb[start] = 1.0;

    // Process nodes
    while (!pq.empty()) {
        auto [currProb, currNode] = pq.top();
        pq.pop();

        // If we reach the destination, return the probability
        if (currNode == end) return currProb;

        // Skip if the current probability is outdated
        if (currProb < maxProb[currNode]) continue;

        // Update neighbors
        for (auto& [nextNode, edgeProb] : graph[currNode]) {
            double newProb = currProb * edgeProb;
            if (newProb > maxProb[nextNode]) {
                maxProb[nextNode] = newProb;
                pq.push({newProb, nextNode});
            }
        }
    }

    // If the destination is not reachable
    return 0.0;
}

int main() {
    int n = 3;
    vector<vector<int>> edges = {{0, 1}, {1, 2}, {0, 2}};
    vector<double> succProb = {0.5, 0.5, 0.2};
    int start = 0, end = 2;

    cout << "Maximum Probability: " << maxProbability(n, edges, succProb, start, end) << endl;
    return 0;
}
Code Explanation Line by Line
Graph Construction:

graph[u].push_back({v, prob}): Adds an edge from 
𝑢
u to 
𝑣
v with probability 
𝑝
𝑟
𝑜
𝑏
prob. Also adds the reverse edge since the graph is undirected.
Priority Queue Initialization:

pq.push({1.0, start}): Start with the highest probability 
1.0
1.0 at the starting node.
Maximum Probability Array:

vector<double> maxProb(n, 0.0): Keeps track of the highest probability to reach each node.
Relaxation:

For each neighbor of the current node, calculate the new probability (newProb) and update if it is greater than the previously stored probability.
Termination:

If the destination node is reached, return the probability immediately. If the queue becomes empty, return 
0.0
0.0.
Dry Run
Input:
lua
Copy
Edit
n = 3, edges = [[0, 1], [1, 2], [0, 2]], succProb = [0.5, 0.5, 0.2], start = 0, end = 2
Execution:
Graph Construction:

makefile
Copy
Edit
0: [(1, 0.5), (2, 0.2)]
1: [(0, 0.5), (2, 0.5)]
2: [(0, 0.2), (1, 0.5)]
Initialization:

pq = [(1.0, 0)]
maxProb = [1.0, 0.0, 0.0]
Step 1:

Process node 
0
0 with probability 
1.0
1.0.
Update 
1
1 with probability 
0.5
0.5, 
2
2 with probability 
0.2
0.2.
pq = [(0.5, 1), (0.2, 2)]
maxProb = [1.0, 0.5, 0.2]
Step 2:

Process node 
1
1 with probability 
0.5
0.5.
Update 
2
2 with probability 
0.25
0.25 (higher than 
0.2
0.2).
pq = [(0.25, 2), (0.2, 2)]
maxProb = [1.0, 0.5, 0.25]
Step 3:

Process node 
2
2 with probability 
0.25
0.25.
Destination reached; return 
0.25
0.25.
Complexity Analysis
Time Complexity:
𝑂
(
𝐸
log
⁡
𝑉
)
O(ElogV), where:

𝐸
E: Number of edges.
𝑉
V: Number of nodes.
Each edge is processed once, and priority queue operations take 
𝑂
(
log
⁡
𝑉
)
O(logV).
Space Complexity:
𝑂
(
𝐸
+
𝑉
)
O(E+V) for storing the graph and additional data structures.

