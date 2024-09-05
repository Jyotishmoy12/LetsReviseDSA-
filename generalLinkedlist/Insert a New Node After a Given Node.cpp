void insertAfter(ListNode* node, int newValue) {
    if (node == nullptr) return; // Check if the given node is null
    
    ListNode* newNode = new ListNode(newValue); // Create the new node with the given value
    newNode->next = node->next; // Point the new node's next to the given node's next
    node->next = newNode; // Link the new node after the given node
}
Example
Initial List:

rust
Copy code
1 -> 3 -> 7
Given Node: Node with value 3.

New Value to Insert: New value is 5.

Dry Run Steps
Initial State:

List: 1 -> 3 -> 7.
Given Node: 3 (we want to insert the new node after this node).
New Value: 5.
Check for Null Node:

Condition: Check if the given node is nullptr.
Result: The given node is not nullptr (it's 3), so continue with the insertion.
Create the New Node:

Action: Create a new node with value 5.
New Node: The node is created with value 5 and its next pointer is currently nullptr.
Adjust the next Pointer of the New Node:

Action: Set the next pointer of the new node to point to node->next (the node that comes after the given node, which is 7).
New Node After Update: The new node's next pointer now points to the node with value 7.
Current List Structure:
rust
Copy code
1 -> 3 -> 5 -> 7
Update the next Pointer of the Given Node:

Action: Set the next pointer of the given node (3) to point to the new node (5).
List Structure After Update:
rust
Copy code
1 -> 3 -> 5 -> 7
Summary of Dry Run
Initial List: 1 -> 3 -> 7.
We wanted to insert the new node (5) after the node with value 3.
Steps:

Create New Node: A new node with value 5 was created.
Adjust Pointers:
The new node's next pointer was set to point to the node after 3 (which is 7).
The next pointer of node 3 was updated to point to the new node.
Final List:


1 -> 3 -> 5 -> 7

void insertAfter(ListNode* node, int newValue) {
    if (node == nullptr) return; // If the given node is null, exit the function
    
    ListNode* newNode = new ListNode(newValue); // Create a new node with the given value
    newNode->next = node->next; // Set the new node's next to the given node's next (link to the rest of the list)
    node->next = newNode; // Insert the new node by setting the given node's next to the new node
}


Explanation of the Approach
Create the New Node: The function first creates a new node with the value newValue.

Link the New Node:

We set the next pointer of the new node to the node that comes after the given node. This ensures the new node doesn't break the chain of the list.
Insert the New Node:

Finally, we set the next pointer of the given node to the new node, completing the insertion.
This approach works in O(1) time complexity, as it only involves manipulating a few pointers, and the space complexity is also O(1) since we are only creating one additional node.
