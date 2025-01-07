Problem Statement: Find the Depth of the Deepest Leaf Node
The depth of the deepest leaf node in a binary tree is the maximum distance from the root to any leaf. The root of the tree is at depth 0, and every level increases the depth by 1.

Given the root of a binary tree, your task is to find the depth of the deepest leaf node.

Intuition
The depth of a node is determined by the number of edges in the path from the root to the node.
A leaf node is a node with no children (both left and right child are NULL).
To find the depth of the deepest leaf:
We need to traverse the entire tree (to ensure we check every leaf node).
At each node, we calculate its depth and propagate the maximum depth seen so far.
Approach
We will solve this problem using a recursive Depth-First Search (DFS) approach.

Steps:
Start from the root of the tree with an initial depth of 0.
Use recursion to traverse the left and right subtrees, increasing the depth as we go deeper into the tree.
At each node:
If it's a leaf node, return its depth.
Otherwise, recursively calculate the depths of the left and right subtrees and return the maximum of the two.
The base case is when the node is NULL, in which case we return -1 since it does not contribute to the depth.
Dry Run
Example Tree:
markdown
Copy code
          1
         / \
        2   3
       / \
      4   5
           \
            6
Start at root = 1, depth = 0. Traverse both left and right subtrees.
Move to node = 2, depth = 1.
Traverse node = 4 (left) → depth = 2 (leaf, return 2).
Traverse node = 5 (right) → depth = 2.
Traverse node = 6 → depth = 3 (leaf, return 3).
Max depth of node = 2 is max(2, 3) = 3.
Move to node = 3, depth = 1 (leaf, return 1).
Max depth of root = 1 is max(3, 1) = 3.
The deepest leaf node is at depth 3.

Code (C++ - LeetCode Style)
cpp
Copy code
class Solution {
public:
    int findDeepestLeaf(TreeNode* root, int depth) {
        // Base case: Null node
        if (root == nullptr) return -1;

        // If the current node is a leaf, return its depth
        if (root->left == nullptr && root->right == nullptr) return depth;

        // Recursive calls for left and right subtrees
        int leftDepth = findDeepestLeaf(root->left, depth + 1);
        int rightDepth = findDeepestLeaf(root->right, depth + 1);

        // Return the maximum depth
        return max(leftDepth, rightDepth);
    }

    int deepestLeavesDepth(TreeNode* root) {
        // Start from depth 0
        return findDeepestLeaf(root, 0);
    }
};
Dry Run of the Code
Example Tree:
markdown
Copy code
          1
         / \
        2   3
       / \
      4   5
           \
            6
Call deepestLeavesDepth(1) → starts with depth = 0.
Call findDeepestLeaf(1, 0):
For node = 2 → depth = 1.
For node = 4 → depth = 2 (leaf, return 2).
For node = 5 → depth = 2.
For node = 6 → depth = 3 (leaf, return 3).
leftDepth = 2, rightDepth = 3 → max(2, 3) = 3.
For node = 3 → depth = 1 (leaf, return 1).
leftDepth = 3, rightDepth = 1 → max(3, 1) = 3.
The result is 3.
Time and Space Complexity Analysis
Time Complexity:
O(n), where n is the number of nodes in the tree.
We visit each node exactly once during the DFS traversal.
Space Complexity:
O(h), where h is the height of the tree.
This is the maximum depth of the recursion stack.
