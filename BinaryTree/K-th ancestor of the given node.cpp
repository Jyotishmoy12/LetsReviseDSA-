Problem Description
Given a binary tree, a target node, and an integer 
𝐾
K, you need to find the 
𝐾
K-th ancestor of the given node. An ancestor of a node is any node that lies on the path from the root to that node. The root is considered the top-most ancestor.

Constraints:
If 
𝐾
K exceeds the height of the tree or the node doesn't have a 
𝐾
K-th ancestor, return 
−
1
−1.
You can assume the binary tree does not contain duplicate values.
Example
Input:
Tree:

markdown
Copy code
        1
       / \
      2   3
     / \   \
    4   5   6
Node: 
5
5
𝐾
=
2
K=2
Output:
1

Explanation:
Ancestors of 
5
5: 
2
→
1
2→1
𝐾
=
2
K=2, so the 2nd ancestor of 
5
5 is 
1
1.
Approach
This can be solved using a DFS (Depth First Search) approach. As we traverse the tree, we check if the current node is the target node or contains the target node in one of its subtrees. While backtracking from the recursive calls, we decrement 
𝐾
K and keep track of how far we’ve moved up the tree.

Steps
Perform a recursive DFS traversal:

Check if the current node is the target node.
Recursively search for the target in the left and right subtrees.
During the backtracking phase:

Decrement 
𝐾
K for each level up the tree.
When 
𝐾
=
0
K=0, the current node is the 
𝐾
K-th ancestor.
If 
𝐾
>
0
K>0 after reaching the root, the 
𝐾
K-th ancestor doesn’t exist.

Code in C++
cpp
Copy code
#include <iostream>
using namespace std;

// Definition for a binary tree node
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
    Node* findKthAncestor(Node* root, int& K, int target) {
        // Base case: if the tree is empty, return nullptr
        if (root == nullptr) {
            return nullptr;
        }

        // If the current node is the target, return the node
        if (root->data == target) {
            return root;
        }

        // Search in the left and right subtrees
        Node* leftAncestor = findKthAncestor(root->left, K, target);
        Node* rightAncestor = findKthAncestor(root->right, K, target);

        // If the target is found in either subtree
        if (leftAncestor != nullptr || rightAncestor != nullptr) {
            K--;  // Decrement K as we move up the tree

            // If K becomes 0, the current node is the K-th ancestor
            if (K == 0) {
                cout << "Kth Ancestor is: " << root->data << endl;
                return nullptr;  // Stop further backtracking
            }

            // Return the node found in the subtree to continue backtracking
            return leftAncestor != nullptr ? leftAncestor : rightAncestor;
        }

        // If the target is not found in either subtree, return nullptr
        return nullptr;
    }

    int kthAncestor(Node* root, int K, int target) {
        Node* result = findKthAncestor(root, K, target);

        // If K is still greater than 0, the K-th ancestor doesn't exist
        return (result == nullptr && K > 0) ? -1 : -1;
    }
};

int main() {
    // Construct the binary tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);

    Solution solution;

    // Example test case
    int K = 2;
    int target = 5;
    int ancestor = solution.kthAncestor(root, K, target);
    cout << "The " << K << "-th ancestor of node " << target << " is: " << ancestor << endl;

    return 0;
}
Dry Run
Input:
Tree:

markdown
Copy code
        1
       / \
      2   3
     / \   \
    4   5   6
Target Node: 
5
5, 
𝐾
=
2
K=2

Execution:
Start DFS from the root 
1
1:

𝐾
=
2
K=2
Traverse left subtree (node 
2
2).
At node 
2
2:

Traverse left subtree (node 
4
4).
4
4 does not match the target. Backtrack.
Traverse right subtree (node 
5
5).
At node 
5
5:

Target node found.
Return node 
5
5 to its parent (node 
2
2).
Backtracking at node 
2
2:

𝐾
=
1
K=1 (decrement 
𝐾
K).
𝐾
≠
0
K

=0, continue backtracking to parent (node 
1
1).
Backtracking at node 
1
1:

𝐾
=
0
K=0 (decrement 
𝐾
K).
Node 
1
1 is the 
𝐾
K-th ancestor.
Return result.
Output:
The 2nd ancestor of node 
5
5 is 
1
1.

Complexity Analysis:
Time Complexity: 
𝑂
(
𝑁
)
O(N), where 
𝑁
N is the number of nodes in the tree. Each node is visited once during the DFS.
Space Complexity: 
𝑂
(
𝐻
)
O(H), where 
𝐻
H is the height of the tree. This is due to the recursive call stack.
