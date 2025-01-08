Problem Statement:
Serialization is the process of converting a binary tree into a string representation that can be easily stored or transmitted. Deserialization is the reverse process of reconstructing the binary tree from its string representation.

Your task is to implement functions to serialize and deserialize a binary tree.

Example:
Input Binary Tree:

markdown
Copy code
       1
      / \
     2   3
        / \
       4   5
Serialized String:
"1,2,N,N,3,4,N,N,5,N,N"

Output After Deserialization:
A reconstructed binary tree identical to the input tree.

Intuition:
Serialization: Use a pre-order traversal (root-left-right) to record each node's value. For null nodes, use a placeholder like 'N'.
Deserialization: Use the serialized string to reconstruct the binary tree in the same order it was traversed during serialization.
Approach:
Serialization:
Traverse the tree using pre-order traversal.
For each node:
Append its value to the result string.
If the node is null, append 'N'.
Return the serialized string, with values separated by commas.
Deserialization:
Split the serialized string into a list of values.
Use recursion to rebuild the tree:
Take the next value in the list.
If it's 'N', return nullptr (null node).
Otherwise, create a new node and recursively build its left and right children.
Code (C++):
cpp
Copy code
#include <iostream>
#include <sstream>
#include <string>
#include <queue>
using namespace std;

// Definition of a TreeNode
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:
    // Serialize the tree into a string
    string serialize(TreeNode* root) {
        if (!root) return "N";
        return to_string(root->val) + "," + serialize(root->left) + "," + serialize(root->right);
    }

    // Deserialize the string into a tree
    TreeNode* deserialize(string data) {
        queue<string> nodes;
        stringstream ss(data);
        string val;
        while (getline(ss, val, ',')) {
            nodes.push(val);
        }
        return buildTree(nodes);
    }

private:
    TreeNode* buildTree(queue<string>& nodes) {
        string val = nodes.front();
        nodes.pop();
        if (val == "N") return NULL;
        TreeNode* node = new TreeNode(stoi(val));
        node->left = buildTree(nodes);
        node->right = buildTree(nodes);
        return node;
    }
};

void printTree(TreeNode* root) {
    if (!root) {
        cout << "N ";
        return;
    }
    cout << root->val << " ";
    printTree(root->left);
    printTree(root->right);
}

int main() {
    // Create a sample tree: 1, 2, 3, null, null, 4, 5
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(5);

    Codec codec;
    string serialized = codec.serialize(root);
    cout << "Serialized: " << serialized << endl;

    TreeNode* deserializedRoot = codec.deserialize(serialized);
    cout << "Deserialized Tree: ";
    printTree(deserializedRoot);
    cout << endl;

    return 0;
}
Dry Run:
Input Tree:
markdown
Copy code
       1
      / \
     2   3
        / \
       4   5
Serialization:

Start pre-order traversal from the root:
Visit 1: Add "1,".
Traverse left:
Visit 2: Add "2,".
Traverse left: Add "N,".
Traverse right: Add "N,".
Traverse right:
Visit 3: Add "3,".
Traverse left:
Visit 4: Add "4,".
Traverse left: Add "N,".
Traverse right: Add "N,".
Traverse right:
Visit 5: Add "5,".
Traverse left: Add "N,".
Traverse right: Add "N,".
Serialized String:
"1,2,N,N,3,4,N,N,5,N,N"

Deserialization:

Split the string into nodes:
["1", "2", "N", "N", "3", "4", "N", "N", "5", "N", "N"].

Reconstruct the tree:

Take "1", create root node 1.
Recursively build left subtree:
Take "2", create left child of 1.
Take "N", left child of 2 is nullptr.
Take "N", right child of 2 is nullptr.
Recursively build right subtree:
Take "3", create right child of 1.
Recursively build left subtree of 3:
Take "4", create left child of 3.
Take "N", left child of 4 is nullptr.
Take "N", right child of 4 is nullptr.
Recursively build right subtree of 3:
Take "5", create right child of 3.
Take "N", left child of 5 is nullptr.
Take "N", right child of 5 is nullptr.
Complexity Analysis:
Time Complexity:

Serialization: O(N) where N is the number of nodes (visit each node once).
Deserialization: O(N) (process each node once).
Space Complexity:

Serialization: O(N) (result string size).
Deserialization: O(N) (queue size for nodes).
