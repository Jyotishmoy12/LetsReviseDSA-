Problem Statement
You need to write a function to convert a given binary tree into a Sum Tree. In a Sum Tree, every node contains the sum of the values of its left and right subtrees in the original tree. Leaf nodes in the Sum Tree are set to 0.

Approach
Use Postorder Traversal:
Visit the left subtree.
Visit the right subtree.
Compute the new value of the current node based on the sum of the left and right subtrees.
Base Case: If the node is NULL, return 0.
Recursive Step: For each node:
Recur for the left subtree to get its sum.
Recur for the right subtree to get its sum.
Store the original value of the node before updating it.
Update the node's value to the sum of the left and right subtree sums.
Return the total sum (original value + left subtree sum + right subtree sum) to the parent node.
Code (C++)
cpp
Copy code
class Solution {
  public:
    // Helper function to recursively convert the tree to a sum tree
    int convertToSumTree(Node* node) {
        // Base case: if the node is NULL, return 0
        if (node == NULL) {
            return 0;
        }

        // Recursively convert the left and right subtrees
        int leftSum = convertToSumTree(node->left);
        int rightSum = convertToSumTree(node->right);

        // Store the original value of the current node
        int originalValue = node->data;

        // Update the node's value to the sum of left and right subtree sums
        node->data = leftSum + rightSum;

        // Return the total sum including the original node's value
        return originalValue + node->data;
    }

    // Wrapper function to initiate the conversion
    void toSumTree(Node* node) {
        convertToSumTree(node);
    }
};
Dry Run
Input Tree:
markdown
Copy code
        10
       /  \
      -2    6
     / \   / \
    8  -4  7  5
Execution Steps:
At Node 8:

Left subtree sum = 0, Right subtree sum = 0.
Update node->data = 0 + 0 = 0.
Return originalValue + node->data = 8 + 0 = 8.
At Node -4:

Left subtree sum = 0, Right subtree sum = 0.
Update node->data = 0 + 0 = 0.
Return originalValue + node->data = -4 + 0 = -4.
At Node -2:

Left subtree sum = 8 (from Node 8), Right subtree sum = -4 (from Node -4).
Update node->data = 8 + (-4) = 4.
Return originalValue + node->data = -2 + 4 = 2.
At Node 7:

Left subtree sum = 0, Right subtree sum = 0.
Update node->data = 0 + 0 = 0.
Return originalValue + node->data = 7 + 0 = 7.
At Node 5:

Left subtree sum = 0, Right subtree sum = 0.
Update node->data = 0 + 0 = 0.
Return originalValue + node->data = 5 + 0 = 5.
At Node 6:

Left subtree sum = 7 (from Node 7), Right subtree sum = 5 (from Node 5).
Update node->data = 7 + 5 = 12.
Return originalValue + node->data = 6 + 12 = 18.
At Node 10:

Left subtree sum = 2 (from Node -2), Right subtree sum = 18 (from Node 6).
Update node->data = 2 + 18 = 20.
Return originalValue + node->data = 10 + 20 = 30.
Output Tree:
markdown
Copy code
        20
       /  \
      4    12
     / \   / \
    0   0  0  0
Complexity Analysis
Time Complexity: O(N)

Every node is visited exactly once during the traversal.
Space Complexity: O(H)

The recursion stack uses space proportional to the height of the binary tree, where H is the height.
