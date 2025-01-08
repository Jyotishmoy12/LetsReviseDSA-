Problem Statement
We are given a binary tree, and we need to find the longest path from the root to any leaf node. The path is defined as the sequence of nodes from the root to a leaf, where a leaf is a node with no children.

Intuition
A path from the root to a leaf is the sequence of nodes from the root to a node with no children.
The longest path requires:
Exploring both left and right subtrees of each node.
Returning the path with the maximum length.
This problem can be solved using recursive depth-first traversal, where we:
Find the longest path in the left subtree.
Find the longest path in the right subtree.
Return the longer of the two paths after appending the current node.
Approach
If the tree is empty (root is NULL), return an empty path.
Recursively find the longest path in the left subtree.
Recursively find the longest path in the right subtree.
Compare the lengths of the two paths:
If the left path is longer, append the current node to the left path and return it.
Otherwise, append the current node to the right path and return it.
The result will be the longest path from the root to a leaf.
Code (C++)
cpp
Copy code
#include <iostream>
#include <vector>
using namespace std;

// Definition of a Node in the binary tree
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

// Function to find the longest path from root to leaf
vector<int> findLongestPath(Node* root) {
    // Base case: if the root is NULL, return an empty vector
    if (root == NULL) {
        return {};
    }

    // Recursive call to find the longest path in the left subtree
    vector<int> leftPath = findLongestPath(root->left);

    // Recursive call to find the longest path in the right subtree
    vector<int> rightPath = findLongestPath(root->right);

    // Compare the lengths of the two paths and choose the longer one
    if (leftPath.size() > rightPath.size()) {
        leftPath.push_back(root->data);
        return leftPath;
    } else {
        rightPath.push_back(root->data);
        return rightPath;
    }
}

// Helper function to print the longest path
void printPath(vector<int> path) {
    for (int i = path.size() - 1; i >= 0; i--) {
        cout << path[i] << " ";
    }
    cout << endl;
}

// Main function
int main() {
    // Construct the binary tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);
    root->right->right->left = new Node(7);

    // Find the longest path from root to leaf
    vector<int> longestPath = findLongestPath(root);

    // Print the longest path
    cout << "Longest Path from Root to Leaf: ";
    printPath(longestPath);

    return 0;
}
Dry Run
Input Tree
markdown
Copy code
        1
       / \
      2   3
     / \    \
    4   5    6
              /
             7
Step-by-Step Execution
At Node 1:
Call findLongestPath(root->left) for the left subtree rooted at 2.
Call findLongestPath(root->right) for the right subtree rooted at 3.
At Node 2:
Call findLongestPath(root->left) for the left subtree rooted at 4.
Call findLongestPath(root->right) for the right subtree rooted at 5.
At Node 4:

Both root->left and root->right are NULL.
Return [4] (path consisting of just the node 4).
At Node 5:

Both root->left and root->right are NULL.
Return [5] (path consisting of just the node 5).
Back at Node 2:

Left path = [4], Right path = [5].
Right path is longer (equal size here, but either can be chosen).
Append 2 to the longer path → [5, 2].
At Node 3:

Call findLongestPath(root->right) for the right subtree rooted at 6.
At Node 6:

Call findLongestPath(root->left) for the left subtree rooted at 7.
At Node 7:

Both root->left and root->right are NULL.
Return [7].
Back at Node 6:

Left path = [7], Right path = [].
Left path is longer.
Append 6 to the left path → [7, 6].
Back at Node 3:

Left path = [], Right path = [7, 6].
Right path is longer.
Append 3 to the right path → [7, 6, 3].
Back at Node 1:
Left path = [5, 2], Right path = [7, 6, 3].
Right path is longer.
Append 1 to the right path → [7, 6, 3, 1].
Final Output
The longest path from root to leaf is:

rust
Copy code
1 -> 3 -> 6 -> 7
Complexity Analysis
Time Complexity: O(N)
Every node is visited exactly once.

Space Complexity: O(H)
The height of the recursion stack is proportional to the height of the tree.
