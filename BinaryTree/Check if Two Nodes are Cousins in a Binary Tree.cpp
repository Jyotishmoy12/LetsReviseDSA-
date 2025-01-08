Let's solve the problem "Check if Two Nodes are Cousins in a Binary Tree" using the requested structured template.

Problem Statement
Two nodes of a binary tree are considered cousins if:

They are at the same level in the tree.
They have different parents.
Given the root of a binary tree and two node values x and y, write a function to determine whether these two nodes are cousins.

Intuition
Level-wise Traversal: Nodes that are cousins must exist on the same level. This can be determined using level-order traversal (BFS).
Parent Check: Nodes that are cousins must have different parents. We can track each node's parent during traversal.
Approach
Use BFS (Breadth-First Search) to traverse the tree level by level.
During the traversal, keep track of:
Each node's parent.
The level at which each node exists.
If both x and y are found on the same level but have different parents, they are cousins.
If the traversal completes without finding both nodes or if the above condition isn't met, they are not cousins.
Code (C++)
cpp
Copy code
#include <iostream>
#include <queue>
using namespace std;

// Definition for a binary tree node.
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

class Solution {
  public:
    bool isCousins(Node* root, int x, int y) {
        if (!root) return false;

        queue<pair<Node*, Node*>> q; // Pair of node and its parent
        q.push({root, nullptr}); // Root has no parent

        while (!q.empty()) {
            int size = q.size();
            Node* xParent = nullptr;
            Node* yParent = nullptr;

            for (int i = 0; i < size; i++) {
                auto [node, parent] = q.front();
                q.pop();

                // Check if the current node is x or y and store its parent
                if (node->data == x) xParent = parent;
                if (node->data == y) yParent = parent;

                // Add left and right children to the queue
                if (node->left) q.push({node->left, node});
                if (node->right) q.push({node->right, node});
            }

            // After processing a level, check the cousin condition
            if (xParent && yParent) {
                return xParent != yParent; // Different parents
            }

            // If one of the nodes is found but not the other, they can't be cousins
            if (xParent || yParent) return false;
        }

        return false; // Both nodes not found
    }
};
Dry Run
Input Tree:
markdown
Copy code
       1
      / \
     2   3
    /     \
   4       5
Example 1:
Input: x = 4, y = 5
Output: true (Same level, different parents)
Step-by-Step Dry Run:
Initialization:

Queue: [{1, nullptr}]
Level 1:

Node: 1, Parent: nullptr
Add children to the queue:
Left child: 2, Parent: 1
Right child: 3, Parent: 1
Queue after Level 1: [{2, 1}, {3, 1}]
Level 2:

Node: 2, Parent: 1
Add left child: 4, Parent: 2
Node: 3, Parent: 1
Add right child: 5, Parent: 3
Queue after Level 2: [{4, 2}, {5, 3}]
Level 3:

Node: 4, Parent: 2
xParent = 2
Node: 5, Parent: 3
yParent = 3
xParent != yParent, so return true.
Complexity Analysis
Time Complexity:

O(N): Each node is visited once during level-order traversal, where N is the number of nodes.
Space Complexity:

O(W): The maximum size of the queue depends on the width of the tree (maximum number of nodes at any level). For a balanced binary tree, W = O(N / 2).
Example Runs
Example 1:
Input:
Tree:

markdown
Copy code
       1
      / \
     2   3
    /     \
   4       5
x = 4, y = 5

Output: true
(Same level, different parents)

Example 2:
Input:
Tree:

markdown
Copy code
       1
      / \
     2   3
    /
   4
x = 4, y = 3

Output: false
(Different levels)

