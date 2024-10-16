Problem: Count Complete Tree Nodes
Question Explanation:
You are given a complete binary tree, and the task is to count the total number of nodes in the tree. A complete binary tree is a binary tree where every level, except possibly the last, is fully filled, and all nodes are as far left as possible.

The goal is to determine the number of nodes efficiently, leveraging the properties of the complete binary tree. A naive solution would traverse all the nodes and count them, which would take O(n) time. However, because the tree is complete, we can optimize the process to achieve better time complexity.

Example Test Case:
Consider the following complete binary tree:

markdown
Copy code
       1
      / \
     2   3
    / \  /
   4  5 6
Total nodes: 6
Intuition:
For a complete binary tree, we know two key properties:

The leftmost path gives the height of the tree.
The rightmost path may give insight into whether the tree is perfect or if the last level is only partially filled.
To count nodes efficiently:

First, check the height of the left subtree and right subtree.
If the left and right subtree heights are the same, the left subtree is a perfect tree (all levels are filled). In this case, we can directly compute the number of nodes in the left subtree as 
2
height
−
1
2 
height
 −1.
If the heights are different, recursively count nodes in the left and right subtrees.
This approach avoids traversing all the nodes by leveraging the structure of the complete binary tree, achieving a time complexity better than O(n).

Thought Process:
Base Case: If the tree is empty (root == NULL), return 0.
Tree Height Calculation: Compute the height of the left and right subtrees.
Perfect Tree Check: If the left and right subtree heights are equal, the left subtree is perfect, and we compute its node count using the formula 
2
height
−
1
2 
height
 −1, then recursively count nodes in the right subtree.
Recursive Case: If the left and right subtree heights are not equal, recursively count nodes in both the left and right subtrees.
Return the total number of nodes.
Code Implementation:
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
    // Function to calculate the height of the tree
    int getHeight(TreeNode* node) {
        int height = 0;
        while (node != nullptr) {
            height++;
            node = node->left; // Move left to compute the height
        }
        return height;
    }
    
    int countNodes(TreeNode* root) {
        if (root == nullptr) return 0; // Base case: empty tree
        
        // Calculate left and right subtree heights
        int leftHeight = getHeight(root->left);
        int rightHeight = getHeight(root->right);
        
        if (leftHeight == rightHeight) {
            // Left subtree is perfect
            // Number of nodes in a perfect binary tree of height `h` is 2^h - 1
            return (1 << leftHeight) + countNodes(root->right);
        } else {
            // Right subtree is perfect
            return (1 << rightHeight) + countNodes(root->left);
        }
    }
};
Dry Run Example:
Let's take the example tree:

markdown
Copy code
       1
      / \
     2   3
    / \  /
   4  5 6
Start at the root (node 1):

Compute the height of the left subtree (leftHeight = 2).
Compute the height of the right subtree (rightHeight = 2).
Since leftHeight == rightHeight, the left subtree is perfect.
Use the formula 
2
2
−
1
=
3
2 
2
 −1=3 nodes in the left subtree.
Recursively count nodes in the right subtree (rooted at node 3).
For the right subtree (rooted at node 3):

Compute the height of the left subtree (leftHeight = 1).
Compute the height of the right subtree (rightHeight = 0).
Since leftHeight != rightHeight, the right subtree is not perfect.
Use the formula 
2
0
−
1
=
1
2 
0
 −1=1 for the right subtree (which only includes node 3).
Recursively count nodes in the left subtree (rooted at node 6).
For the left subtree (rooted at node 6), it's just a single node, so return 1.

Final result: 3 (left subtree of node 1) + 2 (right subtree of node 3) + 1 (node 6) = 6 nodes in total.

Complexity Analysis:
Time Complexity: O(log^2(n)), where n is the number of nodes in the binary tree. Here's why:

At each step, we calculate the height of the left and right subtrees, which takes O(log n) time.
We repeat this height calculation at most log n times (the height of the tree), so the overall complexity is O(log n) * O(log n) = O(log^2 n).
Space Complexity: O(log n) due to the recursion stack depth, which is proportional to the height of the tree.

Test Case:
Input:

cpp
Copy code
TreeNode* root = new TreeNode(1);
root->left = new TreeNode(2);
root->right = new TreeNode(3);
root->left->left = new TreeNode(4);
root->left->right = new TreeNode(5);
root->right->left = new TreeNode(6);

Solution sol;
cout << sol.countNodes(root); // Output: 6
Output:

Copy code
6
Conclusion:
This optimized solution for counting nodes in a complete binary tree makes use of the structural properties of the tree. By leveraging the fact that parts of the tree may be perfect, we can calculate the number of nodes in logarithmic time. This reduces the complexity from O(n) to O(log^2 n), making the solution more efficient, especially for larger trees.






You said:
dry run the code with an example
ChatGPT said:
ChatGPT
Let’s dry-run the code for counting the nodes of the following complete binary tree:

markdown
Copy code
       1
      / \
     2   3
    / \  /
   4  5 6
Here, the total number of nodes is 6. Now, let's walk through the code execution step by step.

Tree Structure:
markdown
Copy code
       1
      / \
     2   3
    / \  /
   4  5 6
Step 1: Start with the root (node 1)
Left Height Calculation (subtree rooted at 2):

Start from node 2, go to node 4 (height increases by 1), then to NULL (height = 2).
So, leftHeight = 2.
Right Height Calculation (subtree rooted at 3):

Start from node 3, go to node 6 (height increases by 1), then to NULL (height = 2).
So, rightHeight = 2.
Comparison:

Since leftHeight == rightHeight, the left subtree is a perfect binary tree.
The number of nodes in a perfect binary tree of height 2 is 
2
2
−
1
=
3
2 
2
 −1=3 nodes.
Recursively count nodes in the right subtree (rooted at node 3).
Step 2: Move to the right subtree (subtree rooted at node 3)
Left Height Calculation (subtree rooted at 6):

Start from node 6, go to NULL (height = 1).
So, leftHeight = 1.
Right Height Calculation (right of node 3 is NULL):

The right child is NULL, so rightHeight = 0.
Comparison:

Since leftHeight != rightHeight, the right subtree is not perfect.
The number of nodes in the right subtree is 
2
0
−
1
=
1
2 
0
 −1=1 (including node 3 itself).
Recursively count nodes in the left subtree (rooted at node 6).
Step 3: Move to the left subtree (single node 6)
Base Case:
Node 6 has no children, so it’s a leaf node.
Since it's the only node, return 1.
Backtracking and Summing Up:
For the subtree rooted at node 3:

Left subtree (node 6) contributes 1 node.
Right subtree (NULL) contributes 0 nodes.
So, the total nodes in the subtree rooted at node 3 = 1 (node 3 itself) + 1 (node 6) = 2 nodes.
For the entire tree rooted at node 1:

Left subtree (rooted at 2) contributes 3 nodes (2, 4, 5).
Right subtree (rooted at 3) contributes 2 nodes (3, 6).
Total nodes = 3 (left subtree) + 2 (right subtree) + 1 (root node) = 6 nodes.
Final Result: 6 nodes
Dry Run Summary:
At node 1:

Left height = 2, Right height = 2.
Left subtree is perfect, contributing 3 nodes.
Recursively count right subtree (rooted at 3).
At node 3:

Left height = 1, Right height = 0.
Right subtree is not perfect, contributing 1 node.
Recursively count left subtree (node 6).
At node 6:

Return 1 (base case).
Total number of nodes in the tree: 6.

Time Complexity Analysis:
Height Calculation: Each height calculation takes O(log n) time since we traverse only the left or rightmost path of the subtree.
Recursive Calls: Each level of recursion reduces the problem size by half, with at most O(log n) recursive calls.
Thus, the time complexity is O(log² n).

Space Complexity:
The space complexity is O(log n) due to the recursion stack, which is proportional to the height of the tree.
