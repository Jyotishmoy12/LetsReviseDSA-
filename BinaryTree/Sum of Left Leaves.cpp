Problem: Sum of Left Leaves
Question Explanation:
You are given a binary tree, and the task is to compute the sum of all the left leaves. A left leaf is a node that is a left child of its parent and does not have any children of its own (i.e., both left and right child are NULL).

Example Test Case:
Consider the following binary tree:

markdown
Copy code
      3
     / \
    9   20
        / \
       15  7
The left leaf in this tree is 9, because:
9 is the left child of 3 and has no children (it's a leaf).
15 is a left child, but it's not a leaf as it has no children.
Sum of left leaves: 9

Intuition:
To solve this problem, we can use a DFS approach to traverse the entire tree. At each node, we check if the left child is a leaf. If the left child is a leaf, we add its value to the sum. Otherwise, we continue recursively exploring both left and right subtrees.

The basic steps are:

Traverse the binary tree using DFS.
For each node, check if its left child is a leaf (both left and right children of the left child are NULL).
If it's a left leaf, add its value to the sum.
Recursively explore both left and right subtrees.
Return the sum of all left leaves.
Thought Process:
Base Case: If the node is NULL, return 0.
Leaf Check: If the current node has a left child that is a leaf (both left and right of that child are NULL), add its value to the result.
Recursive Case: Recursively traverse the left and right subtrees and keep accumulating the sum of the left leaves.
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
    int sumOfLeftLeaves(TreeNode* root) {
        // Base case: if root is null, return 0
        if (root == nullptr) return 0;

        int sum = 0;

        // Check if the left child is a leaf
        if (root->left != nullptr && root->left->left == nullptr && root->left->right == nullptr) {
            sum += root->left->val;
        }

        // Recursively check the left and right subtrees
        sum += sumOfLeftLeaves(root->left);
        sum += sumOfLeftLeaves(root->right);

        return sum;
    }
};
Dry Run Example:
Let’s dry-run the code on the example binary tree:

markdown
Copy code
      3
     / \
    9   20
        / \
       15  7
Start at the root (node 3):

Node 3 has a left child (node 9).
Check if node 9 is a leaf (it is because both left and right of node 9 are NULL).
Add 9 to the sum.
Sum = 9.
Move to the right subtree (node 20):

Node 20 has a left child (node 15), but node 15 is not a leaf (it's a left child, but it's not a leaf because it has children).
Explore both the left and right subtrees of node 20.
The left child of node 20 (node 15) does not contribute to the sum because it's not a leaf.

Sum remains 9.
The right child of node 20 (node 7) is not a left child, so it doesn't contribute to the sum.

Sum remains 9.
Final result: The sum of the left leaves is 9.

Complexity Analysis:
Time Complexity: O(n), where n is the number of nodes in the binary tree. We need to visit each node once to check if it has a left leaf.

Space Complexity:

Recursive Call Stack: The maximum depth of recursion is the height of the tree. In the worst case (a completely unbalanced tree), the depth of recursion will be O(n). In the best case (a balanced tree), the depth of recursion will be O(log n).
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
cout << sol.sumOfLeftLeaves(root); // Output: 9
Output:

Copy code
9
Conclusion:
The recursive DFS approach ensures that we traverse every node in the binary tree and check if it has a left child that is a leaf. 
This is an efficient way to solve the problem, with a time complexity of O(n) where n is the number of nodes in the tree. 
This solution works well for both balanced and unbalanced trees and provides the correct sum of left leaves.
