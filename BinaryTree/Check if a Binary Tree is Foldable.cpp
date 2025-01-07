Problem Statement:
Check if a Binary Tree is Foldable

Given a binary tree, you need to check if the tree is foldable. A binary tree is said to be foldable if its left and right subtrees are mirror images of each other. The mirror image condition means that:

The left subtree of the root should be a mirror image of the right subtree.
The structure and values of corresponding nodes should match accordingly.
Intuition:
The problem essentially checks if the left subtree and the right subtree are mirror images of each other. This can be viewed as a structural check where:

The left child of the root corresponds to the right child of the root and vice versa.
For every pair of corresponding nodes, the left subtree of one node must match the right subtree of the other node, and vice versa.
Approach:
Recursive Approach:

If the tree is foldable, the left and right subtrees must be mirror images of each other.
To check if two trees are mirror images:
The root nodes must have the same value (this is implicitly checked by the recursion).
The left child of the left subtree must be a mirror of the right child of the right subtree, and vice versa.
Base cases:

If both nodes are null, they are considered mirrors of each other (i.e., the tree is foldable at this point).
If one node is null and the other is not, they cannot be mirrors, so return false.
Recursive Function:

We write a helper function isMirror that will check whether two trees are mirror images.
Use this helper function for checking the left and right subtrees of the root.
Overall Structure:

The problem becomes recursive, and the solution is based on dividing the tree into smaller subproblems and checking if each corresponding pair of subtrees are mirrors of each other.
Dry Run:
Example 1: Tree 1
markdown
Copy code
        1
      /   \
     2     2
    / \   / \
   3   4 4   3
Check if the left subtree of root (node 1) and right subtree of root (node 1) are mirror images.
Left subtree:
markdown
Copy code
      2
     / \
    3   4
Right subtree:
markdown
Copy code
      2
     / \
    4   3
They are mirror images of each other.
Example 2: Tree 2
markdown
Copy code
        1
      /   \
     2     2
      \     \
       3     3
The left subtree has a right child, but the right subtree has no left child.
Hence, these are not mirror images.
Code in C++:
cpp
Copy code
#include <iostream>
using namespace std;

// Definition for a binary tree node
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int x) : data(x), left(NULL), right(NULL) {}
};

// Helper function to check if two trees are mirror images of each other
bool isMirror(Node* root1, Node* root2) {
    // Base cases
    if (root1 == NULL && root2 == NULL) {
        return true;
    }
    if (root1 == NULL || root2 == NULL) {
        return false;
    }

    // Check if the current nodes match and recurse for the left and right subtrees
    return (root1->data == root2->data) &&
           isMirror(root1->left, root2->right) &&
           isMirror(root1->right, root2->left);
}

// Main function to check if the binary tree is foldable
bool isFoldable(Node* root) {
    // If the tree is empty, it's considered foldable
    if (root == NULL) {
        return true;
    }

    // Check if the left and right subtrees are mirror images of each other
    return isMirror(root->left, root->right);
}

// Driver Code
int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(2);
    root->left->left = new Node(3);
    root->left->right = new Node(4);
    root->right->left = new Node(4);
    root->right->right = new Node(3);

    if (isFoldable(root)) {
        cout << "The tree is foldable" << endl;
    } else {
        cout << "The tree is not foldable" << endl;
    }

    return 0;
}
Explanation:
The function isMirror checks if two trees are mirror images. It checks:
If both trees are empty (NULL), return true (both are mirrors).
If one is empty and the other is not, return false (they cannot be mirrors).
Otherwise, check if the current nodes' data match and if the left subtree of the first tree is a mirror of the right subtree of the second tree, and vice versa.
The function isFoldable calls isMirror on the left and right subtrees of the root to check if they are mirror images of each other.
Dry Run with Code:
Let's consider the first example tree:

Tree Structure:
markdown
Copy code
        1
      /   \
     2     2
    / \   / \
   3   4 4   3
Call isFoldable(root):

Root is not NULL, so proceed to check if the left and right subtrees are mirror images.
Call isMirror(root->left, root->right):

Left subtree: 2 -> (3, 4)
Right subtree: 2 -> (4, 3)
Both subtrees have the same structure and values, so recursively check:
isMirror(3, 3) → True
isMirror(4, 4) → True
Return True since all checks passed.
Final output is "The tree is foldable".

Time and Space Complexity Analysis:
Time Complexity:

The time complexity is O(n), where n is the number of nodes in the tree. We visit each node once during the traversal.
Space Complexity:

The space complexity is O(h), where h is the height of the tree, due to the recursion stack. In the worst case, for a skewed tree, the height could be n, but for a balanced tree, the height is O(log n).
Conclusion:
To check if a binary tree is foldable, we check if the left and right subtrees of the root are mirror images. This involves recursively comparing the subtrees by ensuring that each node's left child matches the corresponding right child. The approach uses recursion, with the main challenge being verifying the mirror structure at each level of the tree.
