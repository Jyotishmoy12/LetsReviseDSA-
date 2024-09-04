Problem Statement
Merge Nodes in Between Zeros: Given a linked list where each node's value is either zero or a positive integer, merge all nodes between consecutive zeros into one node, with the sum of the values. 
For example, given the linked list 0 -> 3 -> 1 -> 0 -> 4 -> 5 -> 2 -> 0, the result should be 4 -> 11.


ListNode* mergeNodes(ListNode* head) {
    ListNode* dummy = new ListNode(0);
    ListNode* current = dummy;
    int sum = 0;

    ListNode* node = head->next; // skip the first zero node
    while (node) {
        if (node->val == 0) {
            if (sum > 0) {
                current->next = new ListNode(sum);
                current = current->next;
                sum = 0;
            }
        } else {
            sum += node->val;
        }
        node = node->next;
    }

    return dummy->next;
}

Let's dry run the code using the test case: 0 -> 3 -> 1 -> 0 -> 4 -> 5 -> 2 -> 0

Test Case: Linked List: 0 -> 3 -> 1 -> 0 -> 4 -> 5 -> 2 -> 0

Dry Run of the Code
Initial Setup:

dummy is initialized as a new ListNode with value 0 and next as nullptr.
current points to dummy.
sum is initialized to 0.
Processing:

Move to the First Node After the Initial Zero:

node points to 3 (the first node after 0).
sum = 0.
Process Node 3:

Node value is 3, so add 3 to sum.
sum = 3.
Move to the Next Node 1:

Node value is 1, so add 1 to sum.
sum = 3 + 1 = 4.
Move to the Next Node 0:

Node value is 0, which means we need to end the current segment.
sum = 4.
Create a new node with value 4 and add it to the result list.
current now points to the new node with value 4.
Reset sum to 0.
Move to the Next Node 4:

Node value is 4, so add 4 to sum.
sum = 4.
Move to the Next Node 5:

Node value is 5, so add 5 to sum.
sum = 4 + 5 = 9.
Move to the Next Node 2:

Node value is 2, so add 2 to sum.
sum = 9 + 2 = 11.
Move to the Next Node 0:

Node value is 0, which means we need to end the current segment.
sum = 11.
Create a new node with value 11 and add it to the result list.
current now points to the new node with value 11.
Reset sum to 0.
End of List:

We have reached the end of the list, and no more nodes to process.
Result:

The result list constructed is 4 -> 11.
Summary
Result Linked List: 4 -> 11
The final result matches our expected output from the dry run. 
The mergeNodes function effectively merges nodes between zeros and produces a new linked list with the sums.
