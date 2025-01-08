Problem Statement in Detail:
You are given a binary tree, a target node, and an integer K. The task is to find all nodes in the binary tree that are exactly K distance away from the target node.

Distance between two nodes is defined as the number of edges in the shortest path connecting them. If a node is the target node itself and K=0, then the node is part of the answer. For K>0, you need to consider nodes in all directions (up the tree, left, or right).

Intuition:
Tree Representation as a Graph: A binary tree can be visualized as a graph where each edge connects a parent to its child. To find nodes at a distance K, you need to think of the problem in terms of graph traversal starting from the target node.

Two Steps to Solve the Problem:

Convert the tree into a graph-like structure using parent pointers so you can traverse the tree both upward (towards the parent) and downward (towards the children).
Perform a Breadth-First Search (BFS) starting from the target node to find nodes at distance K.
Approach:
Step 1: Mark Parent Nodes
Traverse the binary tree using a DFS or BFS, and for each node, store its parent in a map. This helps you traverse the tree upward (to the parent).
Step 2: Perform BFS from Target Node
Use a queue to traverse the tree in all directions (up to the parent, left child, right child).
Keep track of visited nodes to avoid processing the same node multiple times.
Stop the BFS when you reach nodes at distance K.
Key Insights:
At each BFS level, the distance from the target node increases by 1.
Once you reach distance K, all nodes in the current level of the BFS traversal are part of the result.
Code in C++:
cpp
Copy code
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) : data(val), left(NULL), right(NULL) {}
};

class Solution {
public:
    void markParents(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& parentMap) {
        // Perform DFS or BFS to mark parent nodes
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* current = q.front();
            q.pop();

            if (current->left) {
                parentMap[current->left] = current;
                q.push(current->left);
            }
            if (current->right) {
                parentMap[current->right] = current;
                q.push(current->right);
            }
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        // Step 1: Create a map to store parent pointers
        unordered_map<TreeNode*, TreeNode*> parentMap;
        markParents(root, parentMap);

        // Step 2: Perform BFS from the target node
        unordered_set<TreeNode*> visited;
        queue<TreeNode*> q;
        q.push(target);
        visited.insert(target);

        int currentDistance = 0;
        while (!q.empty()) {
            int size = q.size();
            if (currentDistance == K) break;

            for (int i = 0; i < size; i++) {
                TreeNode* currentNode = q.front();
                q.pop();

                // Add left child to the queue
                if (currentNode->left && visited.find(currentNode->left) == visited.end()) {
                    q.push(currentNode->left);
                    visited.insert(currentNode->left);
                }
                // Add right child to the queue
                if (currentNode->right && visited.find(currentNode->right) == visited.end()) {
                    q.push(currentNode->right);
                    visited.insert(currentNode->right);
                }
                // Add parent to the queue
                if (parentMap[currentNode] && visited.find(parentMap[currentNode]) == visited.end()) {
                    q.push(parentMap[currentNode]);
                    visited.insert(parentMap[currentNode]);
                }
            }
            currentDistance++;
        }

        // Collect all nodes at distance K
        vector<int> result;
        while (!q.empty()) {
            result.push_back(q.front()->data);
            q.pop();
        }
        return result;
    }
};

int main() {
    // Create the binary tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(6);

    Solution obj;
    vector<int> result = obj.distanceK(root, root->left, 2);  // Target node is 2, K = 2

    for (int node : result) {
        cout << node << " ";
    }
    // Output: 1 4 5
    return 0;
}
Dry Run in Detail:
Consider the binary tree:

markdown
Copy code
        1
       / \
      2   3
     / \    \
    4   5    6
Input:

Target node = 2
Distance K = 2
Step 1: Mark Parents

Traverse the tree and store parent pointers:
parentMap[2] = 1
parentMap[3] = 1
parentMap[4] = 2
parentMap[5] = 2
parentMap[6] = 3
Step 2: Perform BFS

Start BFS from the target node 2:
Distance = 0: Queue = {2}
Add children of 2: {4, 5}.
Add parent of 2: {1}.
Distance = 1: Queue = {4, 5, 1}
Add children of 4 and 5 (none).
Add parent of 1: {3}.
Distance = 2: Queue = {1, 3}.
Step 3: Collect Nodes

Nodes at distance K = 2 are {1, 4, 5}.
Output: 1 4 5.

Complexity Analysis:
Time Complexity:

Marking parents: O(N) (where N is the number of nodes in the tree).
BFS traversal: O(N) (each node is visited once).
Overall: O(N).
Space Complexity:

Parent map: O(N).
Visited set: O(N).
Queue: O(N) (in the worst case).
Overall: O(N).
Final Notes:
This approach is efficient and works for any binary tree. It leverages BFS and parent pointers to effectively find nodes at a given distance K from the target node.






You said:
dry run more clearly bro
ChatGPT said:
ChatGPT
Sure, let me break down the dry run even more clearly for you with step-by-step execution of the code and explanations for every operation.

Binary Tree Example:
We’ll use the following binary tree for the dry run:

markdown
Copy code
        1
       / \
      2   3
     / \    \
    4   5    6
Input:

Target Node = 2
Distance K = 2
Step 1: Mark Parent Nodes (markParents() function)
We traverse the tree and record each node’s parent in the parentMap:

Queue during traversal:
Start with queue = {1}.

Node 1 has children 2 and 3.
parentMap[2] = 1 and parentMap[3] = 1.
Enqueue {2, 3}.
Process queue = {2, 3}:

For node 2:

Node 2 has children 4 and 5.
parentMap[4] = 2 and parentMap[5] = 2.
Enqueue {3, 4, 5}.
For node 3:

Node 3 has child 6.
parentMap[6] = 3.
Enqueue {4, 5, 6}.
Process queue = {4, 5, 6}:

Nodes 4, 5, and 6 have no children, so traversal ends.
Parent Map:

rust
Copy code
parentMap:
  2 -> 1
  3 -> 1
  4 -> 2
  5 -> 2
  6 -> 3
Step 2: Perform BFS (distanceK() function)
We now perform BFS starting from the target node (2). The goal is to explore all directions (left, right, and parent) until we reach distance K = 2.

BFS Initialization:
Start with queue = {2}.
visited = {2}.
currentDistance = 0.
BFS Execution:
Level 0 (currentDistance = 0):

Queue: {2}.

Dequeue 2 and process its neighbors:

Left child of 2 → 4: Not visited → Add to queue and visited.
Right child of 2 → 5: Not visited → Add to queue and visited.
Parent of 2 → 1: Not visited → Add to queue and visited.
Queue after processing: {4, 5, 1}.

Increment currentDistance = 1.

Level 1 (currentDistance = 1):

Queue: {4, 5, 1}.

Dequeue and process nodes in the queue:

For 4: No unvisited children or parent.
For 5: No unvisited children or parent.
For 1:
Left child of 1 → 2: Already visited → Skip.
Right child of 1 → 3: Not visited → Add to queue and visited.
Queue after processing: {3}.

Increment currentDistance = 2.

Level 2 (currentDistance = 2):

Queue: {3}.

Dequeue and process nodes in the queue:

For 3:
Left child of 3: None → Skip.
Right child of 3 → 6: Not visited → Add to queue and visited.
Queue after processing: {6}.

We have now reached currentDistance = 2.

Nodes at Distance K:

The nodes in the queue at this point ({6}) are at distance K = 2 from the target node 2.
Output: [6].

Dry Run Summary Table
Step	Queue	Visited Nodes	Nodes Added to Queue	Distance
Init	{2}	{2}		0
Level 0	{4, 5, 1}	{2, 4, 5, 1}	4, 5, 1	1
Level 1	{3}	{2, 4, 5, 1, 3}	3	2
Level 2	{6}	{2, 4, 5, 1, 3, 6}	6	2
Complexity Analysis:
Time Complexity:

Building the parentMap: O(N) (where N is the number of nodes in the tree).
BFS traversal: O(N) (each node is visited at most once).
Total: O(N).
Space Complexity:

parentMap: O(N) for storing parent pointers.
queue and visited: O(N) in the worst case.
Total: O(N).
