Problem: Cracking the Safe
Problem Description:
You are tasked with opening a combination lock, which consists of a sequence of digits from 0 to 
𝑘
−
1
k−1. The lock requires a sequence of 
𝑛
n digits, and your goal is to generate the shortest possible string that contains every possible combination of 
𝑛
n digits exactly once.

For example, if 
𝑛
=
2
n=2 and 
𝑘
=
2
k=2, your task is to generate a string such that every possible 2-digit combination of 
{
0
,
1
}
{0,1} appears exactly once in the string.

Unconventional Insight:
At first glance, this problem might seem like a graph traversal problem or a combinatorial optimization issue. However, it's actually best solved using DFS with backtracking. Specifically, the problem can be framed as finding an Eulerian cycle (or path) in a De Bruijn graph where the nodes are all possible combinations of 
𝑛
−
1
n−1 digits, and the edges represent possible transitions between nodes.

Key Concepts:
Eulerian Path Strategy: An Eulerian path is a path in a graph where each edge is visited exactly once. In this problem, the goal is to visit every combination exactly once, which is analogous to an Eulerian cycle in a De Bruijn graph.

Recursive DFS: We will use DFS with backtracking to explore every possible sequence of 
𝑛
n digits, ensuring that we visit every combination exactly once. This ensures that the final string is the shortest possible sequence containing all combinations.

Graph Representation: Think of each 
𝑛
−
1
n−1-digit sequence as a node in a graph, and an edge from one node to another is formed by appending a digit from 
0
0 to 
𝑘
−
1
k−1.

Example:
Input:

𝑛
=
2
n=2, 
𝑘
=
2
k=2
Output:

"00110" or "11000" (both valid answers)
The shortest string that contains all possible combinations of two digits (00, 01, 10, 11) is "00110". In this string:

00 occurs from index 0 to 1,
01 occurs from index 1 to 2,
11 occurs from index 2 to 3,
10 occurs from index 3 to 4.
Detailed Approach:
Graph Representation:

Consider each 
𝑛
−
1
n−1-digit sequence as a node.
For each node, append digits from 
0
0 to 
𝑘
−
1
k−1 to form new sequences and traverse to those new nodes.
DFS with Backtracking:

Start from an initial sequence of 
𝑛
−
1
n−1 zeros.
Use DFS to explore all possible paths by appending a digit to the current sequence.
Mark each combination as visited once we append it to the string.
Backtrack if a combination has already been visited to explore new paths.
Output the Shortest String:

Once the DFS completes and all possible combinations have been visited, the resulting string will contain all combinations exactly once, in the shortest possible length.
De Bruijn Sequence:

This approach generates a De Bruijn sequence for 
𝑛
n-length combinations of digits from 
0
0 to 
𝑘
−
1
k−1, which is the shortest sequence containing all possible combinations.
Code Implementation:
cpp
Copy code
#include <iostream>
#include <unordered_set>
#include <string>
#include <vector>

class Solution {
public:
    std::string crackSafe(int n, int k) {
        std::unordered_set<std::string> visited; // To track visited combinations
        std::string result;
        
        // Start the DFS with a string of n-1 zeros
        std::string start(n - 1, '0');
        dfs(start, k, visited, result, n);
        
        // Append the starting string to the result
        result += start;
        return result;
    }

private:
    void dfs(const std::string& node, int k, std::unordered_set<std::string>& visited, std::string& result, int n) {
        // Try all possible digits (0 to k-1)
        for (int i = 0; i < k; ++i) {
            std::string next = node + std::to_string(i);
            
            // Check if the combination is already visited
            if (visited.find(next) == visited.end()) {
                visited.insert(next);
                dfs(next.substr(1), k, visited, result, n); // Continue the DFS with the next sequence
                result += std::to_string(i); // Append the new digit to the result
            }
        }
    }
};
Code Explanation:
crackSafe Function:

Initializes the DFS with a starting sequence of 
𝑛
−
1
n−1 zeros (since we need to form 
𝑛
n-digit combinations).
Uses a set visited to keep track of the visited 
𝑛
n-digit combinations to ensure that each combination is only visited once.
Appends the starting sequence to the result once all combinations have been explored.
dfs Function:

Recursively explores all possible 
𝑛
n-digit combinations by appending digits 
0
0 to 
𝑘
−
1
k−1 to the current node.
The DFS is guided by the fact that each 
𝑛
−
1
n−1-digit sequence can be followed by any digit from 
0
0 to 
𝑘
−
1
k−1.
Once a combination is visited, it is marked in the visited set, and the corresponding digit is appended to the result string.
Dry Run with Code:
Let's dry run the example with 
𝑛
=
2
n=2 and 
𝑘
=
2
k=2.

Input: 
𝑛
=
2
n=2, 
𝑘
=
2
k=2

Initial Setup:

Start with start = "0", visited = {}, and result = "".
DFS Call 1:

node = "0", explore digits 
0
0 and 
1
1.
Append 
"
0
"
"0" to get 
"
00
"
"00".
Mark 
"
00
"
"00" as visited.
DFS to explore from 
"
0
"
"0" again (since 
"
00
"
.
𝑠
𝑢
𝑏
𝑠
𝑡
𝑟
(
1
)
=
"
0
"
"00".substr(1)="0").
DFS Call 2:

node = "0", explore 
"
01
"
"01".
Append 
"
1
"
"1" to get 
"
01
"
"01".
Mark 
"
01
"
"01" as visited.
DFS from 
"
1
"
"1" (since 
"
01
"
.
𝑠
𝑢
𝑏
𝑠
𝑡
𝑟
(
1
)
=
"
1
"
"01".substr(1)="1").
DFS Call 3:

node = "1", explore digits 
0
0 and 
1
1.
Append 
"
0
"
"0" to get 
"
10
"
"10".
Mark 
"
10
"
"10" as visited.
DFS from 
"
0
"
"0" (since 
"
10
"
.
𝑠
𝑢
𝑏
𝑠
𝑡
𝑟
(
1
)
=
"
0
"
"10".substr(1)="0").
DFS Call 4:

node = "0", explore 
"
11
"
"11".
Append 
"
1
"
"1" to get 
"
11
"
"11".
Mark 
"
11
"
"11" as visited.
DFS from 
"
1
"
"1" (since 
"
11
"
.
𝑠
𝑢
𝑏
𝑠
𝑡
𝑟
(
1
)
=
"
1
"
"11".substr(1)="1").
DFS Complete:

All combinations 
"
00
"
,
"
01
"
,
"
10
"
,
"
11
"
"00","01","10","11" have been visited.
The resulting string result will be "00110", which contains all possible 2-digit combinations of 
{
0
,
1
}
{0,1}.
Complexity Analysis:
Time Complexity:

There are 
𝑘
𝑛
k 
n
  possible combinations of 
𝑛
n-digit sequences using 
𝑘
k digits.
Each combination is visited exactly once, and for each combination, we perform constant work (inserting into the set, appending to the result).
Therefore, the time complexity is 
𝑂
(
𝑘
𝑛
)
O(k 
n
 ).
Space Complexity:

We use a set visited to store all 
𝑘
𝑛
k 
n
  combinations, which takes 
𝑂
(
𝑘
𝑛
)
O(k 
n
 ) space.
The result string will also have a length of 
𝑂
(
𝑘
𝑛
)
O(k 
n
 ).
Hence, the space complexity is 
𝑂
(
𝑘
𝑛
)
O(k 
n
 ).
