Problem Statement: Left View of a Binary Tree
The Left View of a binary tree is the set of nodes visible when the tree is viewed from the left side. Specifically:

For each level of the tree, the first node encountered from the left is included in the left view.
Intuition
To capture the left view:

We need to traverse the binary tree level by level (like in a level-order traversal).
For each level, the first node encountered is part of the left view.
This can be achieved using either recursion (DFS) or an iterative approach (BFS). We will use DFS to solve the problem.

Approach
Use a helper function to traverse the binary tree depth-first (DFS).
Keep track of the current level of the node being processed.
Use a variable (or list) to remember the maximum level visited so far:
If the current node's level is greater than the maximum level visited so far, this node is part of the left view.
Recursively visit the left subtree first and then the right subtree:
Visiting the left subtree first ensures that nodes on the left are processed before those on the right.
Steps
Define a recursive helper function that:
Takes the current node, its level, and a reference to the left view result list.
Adds the node to the result if it’s the first node of a new level.
Traverses the left and right children.
Initialize the process starting from the root at level 0.
Return the result list.
Dry Run
Example Tree:
markdown
Copy code
          1
         / \
        2   3
       / \   \
      4   5   6
Start from root = 1, level = 0, and maxLevel = -1.
Process node 1:
Add 1 to the left view since level > maxLevel.
Update maxLevel = 0.
Move to the left child node = 2, level = 1.
Add 2 to the left view since level > maxLevel.
Update maxLevel = 1.
Move to the left child node = 4, level = 2.
Add 4 to the left view since level > maxLevel.
Update maxLevel = 2.
Return to node = 2 and process the right child node = 5, but level = 2 is not greater than maxLevel, so it’s ignored.
Return to root = 1 and process the right child node = 3, level = 1 is not greater than maxLevel, so it’s ignored.
Move to the right child of node = 3 → node = 6, level = 2, also ignored.
Result: [1, 2, 4].

Code (C++ - LeetCode Style)
cpp
Copy code
class Solution {
public:
    void leftViewHelper(TreeNode* root, int level, int& maxLevel, vector<int>& result) {
        // Base case: if node is null, return
        if (root == nullptr) return;

        // If this is the first node of the current level
        if (level > maxLevel) {
            result.push_back(root->val);
            maxLevel = level;
        }

        // Recur for left and right subtrees
        leftViewHelper(root->left, level + 1, maxLevel, result);
        leftViewHelper(root->right, level + 1, maxLevel, result);
    }

    vector<int> leftSideView(TreeNode* root) {
        vector<int> result;
        int maxLevel = -1;  // Tracks the max level processed so far
        leftViewHelper(root, 0, maxLevel, result);
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
Steps:

Call leftSideView(root = 1):
result = [], maxLevel = -1.
Call leftViewHelper(1, 0):
Add 1 to result → result = [1], maxLevel = 0.
Call leftViewHelper(2, 1):
Add 2 to result → result = [1, 2], maxLevel = 1.
Call leftViewHelper(4, 2):
Add 4 to result → result = [1, 2, 4], maxLevel = 2.
Call leftViewHelper(5, 2):
level = 2 is not greater than maxLevel = 2, so do nothing.
Call leftViewHelper(3, 1):
level = 1 is not greater than maxLevel = 2, so do nothing.
Call leftViewHelper(6, 2):
level = 2 is not greater than maxLevel = 2, so do nothing.
Output:

text
Copy code
[1, 2, 4]
Time and Space Complexity Analysis
Time Complexity:
O(n), where n is the number of nodes in the binary tree.
Every node is visited exactly once.
Space Complexity:
O(h), where h is the height of the binary tree.
This is the maximum depth of the recursion stack
