Problem: Path Sum
Question Explanation:
You are given a binary tree and a target sum. The goal is to determine if the tree has a root-to-leaf path such that the sum of all node values along that path equals the target sum. A root-to-leaf path is a path that starts at the root node and ends at a leaf node, where a leaf node is a node with no children.

Example Test Case:
Consider the following binary tree:

markdown
Copy code
      5
     / \
    4   8
   /   / \
  11  13  4
 /  \      \
7    2      1
Target Sum: 22

Path from root to leaf (5 → 4 → 11 → 2) has a sum of 5 + 4 + 11 + 2 = 22.
Since this path exists and the sum equals the target sum, the result should be true.
Intuition:
To solve this problem, the approach is to traverse the tree and keep track of the sum of the node values along the current path. As you move from the root to the leaves, you subtract the value of the current node from the target sum. When you reach a leaf node, if the remaining target sum equals the value of that leaf node, a path with the required sum exists.

The most natural way to explore all root-to-leaf paths is using Depth-First Search (DFS) (either recursively or iteratively). We will use a recursive DFS approach here:

Start at the root with the given target sum.
At each node, subtract its value from the remaining target sum.
Recursively check both the left and right subtrees.
If you reach a leaf node and the remaining sum is 0, return true.
Thought Process:
Base Case: If the node is NULL, there’s no path, so return false.
Leaf Node Check: If the current node is a leaf (both left and right are NULL) and the remaining sum equals the node's value, return true.
Recursive Case: Recursively check both the left and right subtrees with the updated sum (target sum minus the current node's value).
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
 *     TreeNode(int x) : val(x), left(nullptr, right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        // Base case: if root is null, no path exists
        if (root == nullptr) return false;

        // If it's a leaf node, check if the remaining sum equals the node's value
        if (root->left == nullptr && root->right == nullptr) {
            return targetSum == root->val;
        }

        // Recursive case: check the left and right subtrees
        int remainingSum = targetSum - root->val;
        return hasPathSum(root->left, remainingSum) || hasPathSum(root->right, remainingSum);
    }
};
Dry Run Example:
Let’s dry-run the code on the test case provided earlier:

markdown
Copy code
      5
     / \
    4   8
   /   / \
  11  13  4
 /  \      \
7    2      1
Target Sum: 22

Start at the root (node 5):

Current node value = 5
Remaining sum = 22 - 5 = 17
Explore both left and right subtrees.
Move to the left subtree (node 4):

Current node value = 4
Remaining sum = 17 - 4 = 13
Explore both left and right subtrees.
Move to the left subtree (node 11):

Current node value = 11
Remaining sum = 13 - 11 = 2
Explore both left and right subtrees.
Move to the left subtree (node 7):

Current node value = 7
Remaining sum = 2 - 7 = -5
Node 7 is a leaf node, but the remaining sum is not 0. So, return false.
Backtrack and move to the right subtree (node 2):

Current node value = 2
Remaining sum = 2 - 2 = 0
Node 2 is a leaf node, and the remaining sum is 0. So, return true.
Since we found a path (5 → 4 → 11 → 2) that sums to the target, the function returns true.

Complexity Analysis:
Time Complexity: O(n), where n is the number of nodes in the tree. In the worst case, we visit every node once, as we need to check every path.

Space Complexity:

Recursive Call Stack: In the worst case (a completely unbalanced tree), the depth of the recursion will be O(n). In the best case (a balanced tree), the depth of the recursion will be O(log n).
Test Case:
Input:

cpp
Copy code
TreeNode* root = new TreeNode(5);
root->left = new TreeNode(4);
root->right = new TreeNode(8);
root->left->left = new TreeNode(11);
root->left->left->left = new TreeNode(7);
root->left->left->right = new TreeNode(2);
root->right->left = new TreeNode(13);
root->right->right = new TreeNode(4);
root->right->right->right = new TreeNode(1);

Solution sol;
cout << sol.hasPathSum(root, 22); // Output: true
Output:

arduino
Copy code
true
Conclusion:
The recursive DFS approach allows us to explore all root-to-leaf paths efficiently, checking if any path sums up to the target value. 
This approach ensures that every possible path is examined, with the time complexity of O(n) where n is the number of nodes in the tree. 
It is an efficient solution for this problem and works well for both balanced and unbalanced trees.
