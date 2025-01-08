Problem Statement in Detail
Given a binary tree and a target sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum. A leaf is a node with no children.

Example:
Input:
Binary Tree:

markdown
Copy code
       5
      / \
     4   8
    /   / \
   11  13  4
  /  \
 7    2
Target Sum: 22

Output:
Yes
Explanation: The root-to-leaf path 5 → 4 → 11 → 2 equals 22.

Intuition
The problem is a classic recursion problem where we explore each path from the root to the leaves. At each step:

Subtract the current node’s value from the target sum.
Check if we’ve reached a leaf node with the remaining sum equal to zero.
Recursively check the left and right subtrees.
Approach
Base Case:

If the node is null, return false because no path exists.
If the node is a leaf (both left and right children are null), check if its value matches the target sum.
Recursive Step:

Subtract the current node’s value from the target sum.
Recursively call the function on the left and right child with the updated sum.
If any of the recursive calls return true, return true.
Result:

If a path with the desired sum exists, return true; otherwise, return false.
Code (C++)
cpp
Copy code
class Solution {
public:
    bool hasPathSum(Node* root, int targetSum) {
        // Base case: If the tree is empty
        if (root == nullptr) {
            return false;
        }

        // Check if we reached a leaf node
        if (root->left == nullptr && root->right == nullptr) {
            return (targetSum == root->data);
        }

        // Recursive step: Subtract the current node's value from the target sum
        int remainingSum = targetSum - root->data;

        // Check the left and right subtrees
        return hasPathSum(root->left, remainingSum) || hasPathSum(root->right, remainingSum);
    }
};
Dry Run (Step-by-Step)
Input:
Binary Tree:

markdown
Copy code
       5
      / \
     4   8
    /   / \
   11  13  4
  /  \
 7    2
Target Sum: 22

Start at root (5), target sum = 22.
Remaining sum = 22 - 5 = 17.
Check left subtree (4) and right subtree (8).
At node 4, target sum = 17.
Remaining sum = 17 - 4 = 13.
Check left subtree (11) (right subtree is null).
At node 11, target sum = 13.
Remaining sum = 13 - 11 = 2.
Check left subtree (7) and right subtree (2).
At node 7, target sum = 2.

Remaining sum = 2 - 7 = -5.
Node is a leaf, but the remaining sum is not 0.
Return false.
At node 2, target sum = 2.

Remaining sum = 2 - 2 = 0.
Node is a leaf, and the remaining sum is 0.
Return true.
Back at node 11:

Left subtree returned false, right subtree returned true.
Return true.
Back at node 4:

Left subtree returned true.
Return true.
Back at root (5):

Left subtree returned true.
Explore the right subtree (8) if necessary, but since the left subtree already returned true, we terminate early.
Output: Yes

Complexity Analysis
Time Complexity:

Each node is visited once.
O(N), where N is the number of nodes in the tree.
Space Complexity:

The recursion stack depends on the height of the tree.
For a balanced tree, O(log N); for a skewed tree, O(N).
