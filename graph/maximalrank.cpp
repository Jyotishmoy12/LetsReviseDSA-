Problem Statement in Detail:
You are given a graph represented by an array roads where each element roads[i] = [a, b] represents an edge between nodes a and b. The graph is undirected, and you are tasked with finding the maximum network rank.

The network rank of a graph is the total number of edges that are directly connected to any two nodes in the graph. To calculate the maximal network rank, you need to consider all pairs of nodes and compute the network rank for each pair. The maximum of these network ranks is the answer.

Intuition on How It Is a Graph Problem:
This problem is inherently a graph problem since you are given an undirected graph, and the objective is to find the maximum number of edges that can connect any two nodes. The problem focuses on the degree of nodes and the shared connections between them.

Node degree: The degree of a node is the number of edges connected to it.
Network Rank: The rank of a pair of nodes is the sum of their individual degrees minus 1 if they are directly connected (i.e., the edge between them exists).
The problem can be approached using graph traversal to determine node degrees and edge existence.

Approach to Solve it in Detail Step-by-Step with Proper Explanation:
Step 1: Degree Calculation:

Start by calculating the degree of each node. The degree of a node is simply the number of edges incident to that node.
Step 2: Edge Existence:

For any pair of nodes (i, j), check if there is a direct edge between them. If there is, subtract 1 from the sum of their degrees because that edge is counted twice.
Step 3: Iterate Over All Pairs:

Iterate over all pairs of nodes (i, j) to compute the network rank. The network rank for each pair is calculated as:
rank
(
𝑖
,
𝑗
)
=
degree
(
𝑖
)
+
degree
(
𝑗
)
−
(1 if i and j are directly connected, else 0)
rank(i,j)=degree(i)+degree(j)−(1 if i and j are directly connected, else 0)
Step 4: Maximize the Rank:

Keep track of the maximum rank encountered while iterating through all node pairs.
Code in C++:
cpp
Copy
Edit
#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        // Initialize degree array for all nodes
        vector<int> degree(n, 0);
        unordered_set<int> connected[n];  // To store direct connections
        
        // Fill in the degree and adjacency information
        for (auto& road : roads) {
            int a = road[0], b = road[1];
            degree[a]++;
            degree[b]++;
            connected[a].insert(b);
            connected[b].insert(a);
        }
        
        int maxRank = 0;

        // Iterate over all pairs of nodes (i, j)
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                // Compute the rank for the pair (i, j)
                int rank = degree[i] + degree[j];
                if (connected[i].count(j)) {
                    rank--;  // Subtract 1 if there is an edge between i and j
                }
                maxRank = max(maxRank, rank);  // Update the maximum rank
            }
        }

        return maxRank;
    }
};

int main() {
    vector<vector<int>> roads = {{0, 1}, {0, 2}, {1, 2}, {1, 3}};
    int n = 4;

    Solution solution;
    cout << "Maximal Network Rank: " << solution.maximalNetworkRank(n, roads) << endl;

    return 0;
}
Code Explanation Line by Line in Detail:
Line 1-2: #include <iostream>, #include <vector>, #include <unordered_set>:

These include necessary libraries. iostream is used for input/output, vector is for using the vector container, and unordered_set is used to store unique connections for each node.
Line 3: using namespace std;:

This statement allows us to use the standard C++ library without needing to prefix each class or function with std::.
Line 5-9: class Solution { ... };:

Declares the Solution class which contains the method to solve the problem.
Line 6-7: int maximalNetworkRank(int n, vector<vector<int>>& roads) { ... }:

This is the main function that takes n (number of nodes) and roads (list of edges) as input and returns the maximal network rank.
Line 9: vector<int> degree(n, 0);:

Creates a vector degree of size n initialized to 0. This will store the degree (number of direct connections) for each node.
Line 10: unordered_set<int> connected[n];:

Creates an array of unordered sets connected[], one for each node, to store direct connections (edges) for each node.
Line 13-16: for (auto& road : roads) { ... }:

Iterates through each road (edge) in the roads vector.
For each edge road[i] = [a, b], the degree of nodes a and b is incremented, and both nodes a and b are added to each other’s adjacency list (set).
Line 19: int maxRank = 0;:

Initializes maxRank to 0. This will store the maximum network rank found during the iteration over node pairs.
Line 22-28: for (int i = 0; i < n; ++i) { for (int j = i + 1; j < n; ++j) { ... } }:

This nested loop iterates over all unique pairs of nodes (i, j). For each pair, it calculates the network rank.
Line 25: int rank = degree[i] + degree[j];:

The rank of the pair (i, j) is initially set to the sum of their degrees.
Line 26: if (connected[i].count(j)) { rank--; }:

If there is an edge between nodes i and j (i.e., they are directly connected), we subtract 1 from the rank because that edge is counted twice in the sum of degrees.
Line 28: maxRank = max(maxRank, rank);:

Updates the maxRank to the highest value encountered so far.
Line 30: return maxRank;:

Returns the computed maximal network rank.
Line 34-37: int main() { ... }:

The main function initializes the graph with 4 nodes and some roads, creates a Solution object, and prints the maximal network rank.
Dry Run with the Code Step-by-Step:
Input:
n = 4 (Number of nodes)
roads = [[0, 1], [0, 2], [1, 2], [1, 3]] (Graph edges)
Step 1: Initialize degree array and adjacency set:
degree = [0, 0, 0, 0] (Degrees of nodes)
connected = [ {}, {}, {}, {} ] (Adjacency lists)
Step 2: Process each road:
For road [0, 1], update:
degree = [1, 1, 0, 0]
connected = [{1}, {0}, {}, {}]
For road [0, 2], update:
degree = [2, 1, 1, 0]
connected = [{1, 2}, {0}, {0}, {}]
For road [1, 2], update:
degree = [2, 2, 2, 0]
connected = [{1, 2}, {0, 2}, {0, 1}, {}]
For road [1, 3], update:
degree = [2, 3, 2, 1]
connected = [{1, 2}, {0, 2, 3}, {0, 1}, {1}]
Step 3: Compute the maximal network rank:
For pair (0, 1):
rank = degree[0] + degree[1] - 1 = 2 + 3 - 1 = 4
For pair (0, 2):
rank = degree[0] + degree[2] - 1 = 2 + 2 - 1 = 3
For pair (0, 3):
rank = degree[0] + degree[3] = 2 + 1 = 3
For pair (1, 2):
rank = degree[1] + degree[2] - 1 = 3 + 2 - 1 = 4
For pair (1, 3):
rank = degree[1] + degree[3] = 3 + 1 = 4
For pair (2, 3):
rank = degree[2] + degree[3] = 2 + 1 = 3
The maximum rank is 4.

Step 4: Return the result:
Maximal network rank = 4
Complexity Analysis:
Time Complexity:

Calculating the degree of each node and populating the adjacency list takes O(E), where E is the number of edges.
Iterating over all pairs of nodes takes O(n^2), where n is the number of nodes.
Therefore, the overall time complexity is O(n^2 + E).
Space Complexity:

We store the degree of each node (O(n) space) and the adjacency list (O(E) space).
The space complexity is O(n + E).
