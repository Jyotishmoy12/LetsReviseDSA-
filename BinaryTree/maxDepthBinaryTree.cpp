Problem: Maximum Depth of a Binary Tree
Question Explanation:
In this problem, you are given a binary tree, and you need to determine its maximum depth. The maximum depth (or height) of a binary tree is defined as the number of nodes along the longest path from the root node down to the deepest leaf node. A leaf node is one that has no children (both left and right are NULL).

Intuition:
The depth of a tree is simply the number of levels from the root to the deepest leaf. If we think about the binary tree as a recursive structure, we can say that:

The depth of a node is 1 + the maximum depth of its left and right subtrees.
If the node has no children (i.e., it's a leaf node), the depth is 1.
If the tree is empty (root == NULL), the depth is 0.
Thought Process:
We can solve this using a recursive Depth-First Search (DFS) approach. We start from the root and for each node, we recursively calculate the depth of the left and right subtrees. The maximum depth at each node is simply 1 + the maximum of the depths of its left and right children.
Alternatively, we can use BFS to solve this iteratively by level-order traversal. For each level we process, we increment the depth.
Approach:
Base Case: If the root is NULL, the depth is 0 (an empty tree).
Recursive Case: For each node, calculate the depth of the left and right subtrees, and the maximum depth will be the larger of the two, plus one for the current node.
Code Implementation (Recursive DFS):
cpp
Copy code
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxDepth(TreeNode* root) {
        // Base case: if the tree is empty, return depth 0
        if (root == nullptr) {
            return 0;
        }

        // Recursive case: calculate the max depth of the left and right subtrees
        int leftDepth = maxDepth(root->left);
        int rightDepth = maxDepth(root->right);

        // Return the maximum of the two, plus 1 for the current node
        return 1 + max(leftDepth, rightDepth);
    }
};
Dry Run Example:
Consider the binary tree:

markdown
Copy code
       3
      / \
     9  20
       /  \
      15   7
Start from the root (node 3):
Calculate the depth of the left subtree of node 3 (rooted at node 9).
Node 9 is a leaf, so its depth is 1.
Calculate the depth of the right subtree of node 3 (rooted at node 20).
Go to node 20.
Calculate the depth of the left subtree of node 20 (rooted at node 15).
Node 15 is a leaf, so its depth is 1.
Calculate the depth of the right subtree of node 20 (rooted at node 7).
Node 7 is a leaf, so its depth is 1.
The maximum depth at node 20 is 1 + max(1, 1) = 2.
The maximum depth at node 3 is 1 + max(1, 2) = 3.
Thus, the maximum depth of the binary tree is 3.

Time Complexity:
Time Complexity: O(n) where n is the number of nodes in the tree. We visit each node exactly once to calculate the depth.
Space Complexity:
Recursive Call Stack: In the worst case (a skewed tree), the recursion depth will be O(n). In the best case (a balanced tree), the depth of the recursion will be O(log n).
Test Case:
Input:

cpp
Copy code
TreeNode* root = new TreeNode(3);
root->left = new TreeNode(9);
root->right = new TreeNode(20);
root->right->left = new TreeNode(15);
root->right->right = new TreeNode(7);

Solution sol;
cout << sol.maxDepth(root); // Output: 3
Output:

Copy code
3
Conclusion:
The recursive DFS solution provides an elegant way to calculate the maximum depth by utilizing the natural structure of the binary tree. 
  It efficiently computes the depth in O(n) time by visiting each node once, making it optimal for this problem.
