Problem Statement
Given two arrays:

levelOrder[]: Represents the level-order traversal of a binary tree.
inorder[]: Represents the in-order traversal of the same binary tree.
You need to construct the binary tree from these arrays.

Intuition
The level-order traversal gives the order in which nodes appear level by level (top-down, left-to-right).
The in-order traversal allows us to determine the left and right subtrees of a node since:
The nodes to the left of a root in inorder form the left subtree.
The nodes to the right of a root in inorder form the right subtree.
To reconstruct the tree:

Use the level-order traversal to determine the root of the current subtree (the first element in levelOrder is always the root).
Use the inorder traversal to split the nodes into left and right subtrees.
Recursively construct the left and right subtrees by filtering the nodes in levelOrder to ensure the correct order for each subtree.
Approach
Find the Root:

The first element in levelOrder is always the root of the tree.
Divide the Tree:

Locate the root's position in the inorder array.
The elements to the left of the root in inorder form the left subtree.
The elements to the right of the root in inorder form the right subtree.
Filter Nodes:

Use the levelOrder array to preserve the correct order of nodes for the left and right subtrees.
Filter the levelOrder array to include only the nodes present in the left or right subtree, based on the inorder split.
Recursive Construction:

Recursively construct the left and right subtrees using the filtered levelOrder and the respective portions of inorder.
Base Case:

If inorder is empty, return nullptr because there are no nodes left to construct.
Dry Run
Test Case:
levelOrder = [3, 9, 20, 15, 7]
inorder = [9, 3, 15, 20, 7]
Step-by-Step Execution:
Initial Call:

Root = levelOrder[0] = 3.
Split inorder at 3:
Left subtree: [9]
Right subtree: [15, 20, 7].
Filter Left Subtree from Level Order:

From levelOrder, only nodes in [9] are valid → Filtered Left = [9].
Filter Right Subtree from Level Order:

From levelOrder, only nodes in [15, 20, 7] are valid → Filtered Right = [20, 15, 7].
Recursive Calls:

Left Subtree:

levelOrder = [9]
inorder = [9]
Root = 9, and no further nodes → Return the node 9.
Right Subtree:

levelOrder = [20, 15, 7]
inorder = [15, 20, 7]
Root = 20, split inorder:
Left subtree: [15]
Right subtree: [7].
Filtered Left = [15], Filtered Right = [7].
Recursive Calls for Right Subtree:

Left Subtree of 20:

levelOrder = [15]
inorder = [15]
Root = 15, and no further nodes → Return the node 15.
Right Subtree of 20:

levelOrder = [7]
inorder = [7]
Root = 7, and no further nodes → Return the node 7.
Code (C++ in LeetCode Style)
cpp
Copy code
#include <unordered_map>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* buildTree(vector<int>& levelOrder, vector<int>& inorder) {
        unordered_map<int, int> inorderIndexMap;
        for (int i = 0; i < inorder.size(); i++) {
            inorderIndexMap[inorder[i]] = i;  // Map value to index for quick lookup
        }
        return build(levelOrder, inorder, inorderIndexMap);
    }

private:
    TreeNode* build(vector<int>& levelOrder, vector<int>& inorder, unordered_map<int, int>& inorderIndexMap) {
        if (inorder.empty() || levelOrder.empty()) return nullptr;

        // First element in levelOrder is the root
        TreeNode* root = new TreeNode(levelOrder[0]);

        // Find root position in inorder
        int rootIndex = inorderIndexMap[root->val];

        // Divide inorder into left and right subtrees
        vector<int> leftInorder(inorder.begin(), inorder.begin() + rootIndex);
        vector<int> rightInorder(inorder.begin() + rootIndex + 1, inorder.end());

        // Filter levelOrder for left and right subtrees
        vector<int> leftLevelOrder, rightLevelOrder;
        for (int val : levelOrder) {
            if (inorderIndexMap[val] < rootIndex) {
                leftLevelOrder.push_back(val);
            } else if (inorderIndexMap[val] > rootIndex) {
                rightLevelOrder.push_back(val);
            }
        }

        // Recursive calls
        root->left = build(leftLevelOrder, leftInorder, inorderIndexMap);
        root->right = build(rightLevelOrder, rightInorder, inorderIndexMap);

        return root;
    }
};
Time and Space Complexity Analysis
Time Complexity:

Constructing the tree involves:
Splitting the inorder array: O(N) for each recursive call.
Filtering the levelOrder array: O(N) for each recursive call.
Since there are O(N) recursive calls, the overall complexity is O(N²).
Optimization with a queue is possible, but not included here for simplicity.

Space Complexity:

Auxiliary space for recursion: O(H), where H is the height of the tree (worst-case O(N)).
Space for filtered arrays: O(N) for each call.
Overall: O(N²) in the worst case.
