Problem Statement: Top View of a Binary Tree
The Top View of a binary tree is the set of nodes visible when the tree is viewed from the top. Specifically:

For each vertical column of the tree, we include the topmost node (the first node encountered in the vertical column from top to bottom).
Intuition
To capture the Top View:

Each node in the binary tree can be assigned a horizontal distance (HD) from the root:
The root node has an HD = 0.
For the left child of a node, HD = parent_HD - 1.
For the right child of a node, HD = parent_HD + 1.
Nodes with the same horizontal distance form a vertical column.
For each vertical column, we need the first node encountered (i.e., the node at the smallest depth) to be part of the top view.
We can use a level-order traversal (BFS) to efficiently compute the top view, while maintaining the horizontal distances of the nodes.

Approach
Use a queue to perform a level-order traversal (BFS) of the binary tree.
Maintain a map to store the first node encountered at each horizontal distance:
The key is the horizontal distance (HD).
The value is the node's value.
Traverse the tree:
Add the current node to the map only if its HD is not already present (this ensures only the topmost node is recorded for each column).
At the end, sort the map by HD (if required) and extract the node values to form the top view.
Steps
Initialize a queue for BFS that stores pairs of the current node and its horizontal distance.
Initialize an empty map to track the first node encountered at each horizontal distance.
Perform BFS:
For each node, check its horizontal distance:
If the horizontal distance is not already in the map, add it.
Add the left and right children to the queue with their respective horizontal distances.
Extract the values from the map in the order of increasing horizontal distance.
Dry Run
Example Tree:
markdown
Copy code
          1
         / \
        2   3
       / \   \
      4   5   6
               \
                7
Start BFS from the root:
Initialize queue = [(1, 0)] and map = {}.
Process node 1 (HD = 0):
Add 1 to map = {0: 1}.
Add left child 2 (HD = -1) and right child 3 (HD = 1) to the queue.
Process node 2 (HD = -1):
Add 2 to map = {-1: 2, 0: 1}.
Add left child 4 (HD = -2) and right child 5 (HD = 0) to the queue.
Process node 3 (HD = 1):
Add 3 to map = {-1: 2, 0: 1, 1: 3}.
Add right child 6 (HD = 2) to the queue.
Process node 4 (HD = -2):
Add 4 to map = {-2: 4, -1: 2, 0: 1, 1: 3}.
Process node 5 (HD = 0):
HD = 0 already exists in the map, so skip it.
Process node 6 (HD = 2):
Add 6 to map = {-2: 4, -1: 2, 0: 1, 1: 3, 2: 6}.
Add right child 7 (HD = 3) to the queue.
Process node 7 (HD = 3):
Add 7 to map = {-2: 4, -1: 2, 0: 1, 1: 3, 2: 6, 3: 7}.
Result:

text
Copy code
Extract values from `map` in increasing order of `HD` → `[4, 2, 1, 3, 6, 7]`.
Code (C++ - LeetCode Style)
cpp
Copy code
class Solution {
public:
    vector<int> topView(TreeNode* root) {
        if (!root) return {};

        // Map to store the first node at each horizontal distance
        map<int, int> topNodes;
        // Queue for BFS (stores pairs of node and horizontal distance)
        queue<pair<TreeNode*, int>> q;

        // Start BFS with the root at horizontal distance 0
        q.push({root, 0});

        while (!q.empty()) {
            auto [node, hd] = q.front();
            q.pop();

            // If this horizontal distance is not already in the map, add it
            if (topNodes.find(hd) == topNodes.end()) {
                topNodes[hd] = node->val;
            }

            // Add left and right children to the queue with updated HDs
            if (node->left) q.push({node->left, hd - 1});
            if (node->right) q.push({node->right, hd + 1});
        }

        // Extract the top view from the map (sorted by HD)
        vector<int> result;
        for (auto& [hd, value] : topNodes) {
            result.push_back(value);
        }

        return result;
    }
};
Dry Run of the Code
Input Tree:
markdown
Copy code
          1
         / \
        2   3
       / \   \
      4   5   6
               \
                7
Steps:

Start with queue = [(1, 0)] and topNodes = {}.
Process:
Node 1, HD = 0 → Add 1 to topNodes = {0: 1}.
Add 2, HD = -1 and 3, HD = 1 to the queue.
Process:
Node 2, HD = -1 → Add 2 to topNodes = {-1: 2, 0: 1}.
Add 4, HD = -2 and 5, HD = 0 to the queue.
Process:
Node 3, HD = 1 → Add 3 to topNodes = {-1: 2, 0: 1, 1: 3}.
Add 6, HD = 2 to the queue.
Continue similarly for nodes 4, 5, 6, 7.
Final Output: [4, 2, 1, 3, 6, 7].

Time and Space Complexity Analysis
Time Complexity:
O(n): Each node is processed once during BFS.
Space Complexity:
O(n):
Space for the queue is proportional to the number of nodes at the widest level of the tree.
Space for the map is proportional to the number of unique horizontal distances.
Let me know if you’d like any additional explanations! 😊






You said:
why -1 and +1 formula works?
ChatGPT said:
ChatGPT
Great question! Let’s carefully explore why -1 and +1 work when calculating the horizontal distance (HD) for the top view of a binary tree.

Horizontal Distance Intuition
Imagine the binary tree is laid out like a coordinate system, where the root is at position (0, 0), i.e., horizontal distance HD = 0.
For every node:
Moving left shifts us one step to the left on this imaginary axis, so the HD decreases by 1 → HD = parent_HD - 1.
Moving right shifts us one step to the right, so the HD increases by 1 → HD = parent_HD + 1.
Mathematical Justification
Let’s understand this using the tree structure:

markdown
Copy code
          1 (HD = 0)
         / \
        2   3
       /     \
      4       5
At each step:
Start at the root:

The root node (1) is at HD = 0.
Move to the left child (2):

From the root, we move left, so the HD = 0 - 1 = -1.
Move to the right child (3):

From the root, we move right, so the HD = 0 + 1 = +1.
Go deeper:

From 2, move left to 4: HD = -1 - 1 = -2.
From 3, move right to 5: HD = 1 + 1 = 2.
Result:
Each node's horizontal distance is calculated relative to its parent, using this -1 (left) and +1 (right) rule.

How This Helps in the Top View
The horizontal distance uniquely identifies vertical columns in the tree:

Nodes with the same HD are part of the same vertical column.
When traversing the tree, we only need to record the first node we encounter for each HD to determine the top view.
Why Does -1 and +1 Always Work?
This is because binary trees are structured hierarchically, and the -1 and +1 adjustments propagate correctly throughout the tree.

Let’s prove this by walking through the rules:

Base Case: Root Node

The root starts with HD = 0 by definition.
Left Child Rule

Moving left from a node always takes us one step closer to the left on the horizontal axis. This is why we subtract 1 from the parent’s HD.
Right Child Rule

Moving right from a node always takes us one step closer to the right on the horizontal axis. This is why we add 1 to the parent’s HD.
This pattern is consistent no matter the size or shape of the binary tree, so it works universally.

Example Tree Dry Run
Let’s test it with a more complex tree:

markdown
Copy code
          1 (HD = 0)
         / \
        2   3
       / \    \
      4   5    6
     /        /
    7        8
We’ll compute the horizontal distances step by step:

Node	Parent HD	Left Child HD	Right Child HD
1	0	-1	+1
2	-1	-2	0
3	+1	-	+2
4	-2	-3	-
5	0	-	-
6	+2	+1	-
7	-3	-	-
8	+1	-	-
Result:

The HD for each node is uniquely calculated using -1 (left) and +1 (right).
Vertical columns are identified using HD.
Visualizing Why It Works
Imagine laying out the tree horizontally:

Column HD = -3: Contains 7.
Column HD = -2: Contains 4.
Column HD = -1: Contains 2.
Column HD = 0: Contains 1, 5 (topmost is 1).
Column HD = +1: Contains 3, 8 (topmost is 3).
Column HD = +2: Contains 6.
This aligns perfectly with the top view!

Conclusion
The -1 and +1 formula works because:

It represents horizontal movement across the binary tree.
It uniquely identifies vertical columns for any binary tree structure.
It propagates consistently throughout the tree based on parent-child relationships.
