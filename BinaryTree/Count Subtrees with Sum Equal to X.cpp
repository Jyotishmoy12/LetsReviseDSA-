Problem Statement: Count Subtrees with Sum Equal to X
Given a binary tree, we need to count how many subtrees have a sum equal to a given value X. A subtree is defined as a node and all its descendants, including the node itself.

Intuition:
To solve this problem, we need to traverse the binary tree and, for each node, calculate the sum of the subtree rooted at that node. If the sum equals X, we increase our count.

We can achieve this with a post-order traversal. The reason for using post-order is that we need the sums of the left and right subtrees to compute the sum of the current subtree. In post-order traversal, we first visit the left and right subtrees and then process the node itself.

Approach:
Recursive approach: We define a recursive function that calculates the sum of the subtree rooted at each node.

For each node:
Recursively calculate the sum of its left and right subtrees.
Add the node's value to this sum.
If the sum equals X, increase the count.
Post-order traversal: We process the left subtree, the right subtree, and then the node. This ensures we have the sum of the children before computing the sum for the current node.

Global variable for count: Use a global or class variable to track the count of subtrees whose sum equals X.

Dry Run:
Let's take an example to dry-run the approach. Consider the following binary tree:

markdown
Copy code
          5
         / \
        2   -3
       / \    \
      3   4    7
Given that X = 7, we will count how many subtrees have a sum of 7.

Initialization: Set the count to 0.

Post-order traversal:

Start at the root node 5:
Traverse the left subtree rooted at 2:
Traverse the left subtree rooted at 3:
Its sum is 3 (no match).
Traverse the right subtree rooted at 4:
Its sum is 4 (no match).
The sum for node 2 is 2 + 3 + 4 = 9 (no match).
Traverse the right subtree rooted at -3:
Traverse the right subtree rooted at 7:
Its sum is 7 (match!).
The sum for node -3 is -3 + 7 = 4 (no match).
The sum for node 5 is 5 + 9 + 4 = 18 (no match).
The count is 1, as only the subtree rooted at 7 has a sum of 7.
Final Output:
The final count of subtrees whose sum is 7 is 1.

Code in C++:
cpp
Copy code
#include <iostream>
using namespace std;

// Define the structure for tree nodes
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int x) : data(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int count = 0;

    // Helper function to calculate the sum of the subtree
    int countSubtreesWithSumX(Node* root, int X) {
        if (root == nullptr) {
            return 0;
        }

        // Recursively find the sum of the left and right subtrees
        int leftSum = countSubtreesWithSumX(root->left, X);
        int rightSum = countSubtreesWithSumX(root->right, X);

        // Total sum of the current subtree
        int totalSum = root->data + leftSum + rightSum;

        // If the total sum equals X, increment the count
        if (totalSum == X) {
            count++;
        }

        return totalSum;
    }

    // Function to return the number of subtrees with sum equal to X
    int countSubtrees(Node* root, int X) {
        // Call the helper function to start the traversal
        countSubtreesWithSumX(root, X);
        return count;
    }
};

int main() {
    // Create the binary tree
    Node* root = new Node(5);
    root->left = new Node(2);
    root->right = new Node(-3);
    root->left->left = new Node(3);
    root->left->right = new Node(4);
    root->right->right = new Node(7);

    // Create an instance of Solution and call the function
    Solution solution;
    int X = 7;
    cout << "Number of subtrees with sum " << X << " is: " << solution.countSubtrees(root, X) << endl;

    return 0;
}
Time and Space Complexity Analysis:
Time Complexity: O(N), where N is the number of nodes in the binary tree. We visit each node once and compute its subtree sum during the post-order traversal.

Space Complexity: O(H), where H is the height of the binary tree. The space complexity is dominated by the recursion stack, which can go as deep as the height of the tree. In the worst case, for a skewed tree, the height could be O(N).
