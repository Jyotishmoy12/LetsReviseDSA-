Problem: Minimum Depth of a Binary Tree
Problem Description:
The minimum depth of a binary tree is defined as the number of nodes along the shortest path from the root node to the nearest leaf node. A leaf node is a node with no children (i.e., no left or right child).

Given the root of a binary tree, you need to return its minimum depth.

Example:
Consider the following binary tree:

markdown
Copy code
        1
       / \
      2   3
     /   / \
    4   5   6
   /
  7
In this tree:

The minimum depth is 2, because the shortest path from the root node (1) to a leaf node is 1 -> 3, which is 2 nodes long.
Intuition Behind the Solution:
Understanding Depth:

The depth of a node is defined as the number of edges or nodes from the root to that node.
We are interested in finding the shortest path to a leaf. A leaf node is defined as a node that has no children (both left and right children are nullptr).
Breadth-First Search (BFS) vs Depth-First Search (DFS):

A BFS is more suited to this problem. This is because BFS explores all nodes at a given depth before moving to nodes at the next level. Therefore, the first time BFS encounters a leaf node, it will be the shortest path to a leaf, and we can stop the traversal.
DFS would traverse the tree fully, but we'd have to track the depths manually. BFS provides a more direct approach to solving the problem with minimum depth since we can terminate early upon finding a leaf node.
Thought Process:

We perform a level-order traversal (BFS) starting from the root.
As we explore each node, we check if it's a leaf. If it is, we return the current depth.
This ensures that we find the minimum depth efficiently.
Approach Using BFS:
Start at the root.
Traverse each level of the tree.
As soon as we reach the first leaf node, return the depth of that node.
C++ Code for Minimum Depth of a Binary Tree:
cpp
Copy code
#include <iostream>
#include <queue>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int minDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0; // If the tree is empty, depth is 0
        }

        // Queue for level-order traversal (BFS)
        queue<pair<TreeNode*, int>> q;
        q.push({root, 1}); // Start with the root node and depth 1

        while (!q.empty()) {
            TreeNode* current = q.front().first;
            int depth = q.front().second;
            q.pop();

            // Check if we have encountered a leaf node
            if (current->left == nullptr && current->right == nullptr) {
                return depth;
            }

            // Add the left child to the queue if it exists
            if (current->left != nullptr) {
                q.push({current->left, depth + 1});
            }

            // Add the right child to the queue if it exists
            if (current->right != nullptr) {
                q.push({current->right, depth + 1});
            }
        }
        return 0; // This return statement is unreachable, but it's required to satisfy the compiler
    }
};

// Helper function to create a simple test case
TreeNode* createTestTree() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(6);
    root->left->left->left = new TreeNode(7);
    return root;
}

int main() {
    Solution sol;
    TreeNode* root = createTestTree();
    cout << "Minimum Depth: " << sol.minDepth(root) << endl;
    return 0;
}
Dry Run:
Let's walk through the code with a test case:

Test Tree:
markdown
Copy code
        1
       / \
      2   3
     /   / \
    4   5   6
   /
  7
Initial Setup: Start BFS from the root node (1), initialize the queue with (1, 1) (node, depth). The queue will now be: [(1, 1)].

First Iteration:

Dequeue (1, 1).
Check if node 1 is a leaf node. It isn't.
Enqueue its children (2, 2) and (3, 2). Queue becomes: [(2, 2), (3, 2)].
Second Iteration:

Dequeue (2, 2).
Node 2 is not a leaf.
Enqueue its left child (4, 3). Queue becomes: [(3, 2), (4, 3)].
Third Iteration:

Dequeue (3, 2).
Node 3 is not a leaf.
Enqueue its children (5, 3) and (6, 3). Queue becomes: [(4, 3), (5, 3), (6, 3)].
Fourth Iteration:

Dequeue (4, 3).
Node 4 is not a leaf.
Enqueue its left child (7, 4). Queue becomes: [(5, 3), (6, 3), (7, 4)].
Fifth Iteration:

Dequeue (5, 3).
Node 5 is a leaf! Return the current depth, which is 3.
Thus, the minimum depth is 2, as node 3 is the closest leaf.

Time and Space Complexity Analysis:
Time Complexity:
In the worst case, we visit all nodes in the tree. Therefore, the time complexity is O(N), where N is the number of nodes in the tree.
Space Complexity:
The space complexity is determined by the queue used in BFS. In the worst case, the queue can hold nodes at the deepest level, which is proportional to the maximum width of the tree. The space complexity is O(N) in the worst case.
This provides an efficient solution for finding the minimum depth of a binary tree using BFS.
