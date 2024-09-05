Problem Overview: "Remove N-th Node From End of List"
Given a linked list, the goal is to remove the n-th node from the end of the list and return the modified list.

Intuition:
To solve this problem, a common approach is to use two pointers (or "fast" and "slow" pointers) to efficiently locate the n-th node from the end of the list. The idea is to create a gap of n nodes between the two pointers. Once the fast pointer reaches the end of the list, the slow pointer will be at the node right before the node that needs to be removed.

By doing this, you can achieve the solution in one pass (O(n) time complexity), avoiding the need to first count the total number of nodes and then do a second traversal.

Plan:
Use a two-pointer approach:
fast pointer moves n+1 steps ahead.
slow pointer starts at the beginning and only moves when fast starts moving.
Once fast reaches the end, slow will be at the node just before the one that needs to be deleted.
Adjust the next pointer of the slow node to bypass the n-th node from the end.
Edge Cases:
The list has only one node: Removing the node should return an empty list.
n is equal to the length of the list: This means the head node needs to be removed.
n is 1: The last node needs to be removed.
General case: Removing a node somewhere in the middle.
Dry Run Example:
Consider the linked list: 1 -> 2 -> 3 -> 4 -> 5 and n = 2. We want to remove the 2nd node from the end, which is the node with value 4.

Step-by-Step Walkthrough:
Initial Setup:

We create a dummy node with value 0 and point it to the head of the list to handle edge cases easily.
Both the slow and fast pointers start at the dummy node.
The list looks like: 0(dummy) -> 1 -> 2 -> 3 -> 4 -> 5.
Move the Fast Pointer n+1 steps forward:

fast moves n+1 = 3 steps forward to create a gap of n nodes between the slow and fast pointers.
After moving 3 steps, the pointers look like this:
fast points to the node with value 3 (0 → 1 → 2 → 3 → 4 → 5).
slow is still at the dummy node (0).
Move both slow and fast together:

Now, move both slow and fast one step at a time until fast reaches the end of the list.
After one step:
fast points to 4, slow points to 1.
After two steps:
fast points to 5, slow points to 2.
After three steps:
fast reaches the end (nullptr), and slow points to 3.
Remove the Target Node:

Now, slow is just before the node to be removed (node 4).
Adjust the next pointer of slow to skip the node with value 4:
slow->next = slow->next->next (this bypasses the node with value 4).
The updated list is: 1 -> 2 -> 3 -> 5.
Code (C++):
cpp
Copy code
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* removeNthFromEnd(ListNode* head, int n) {
    // Create a dummy node and set it to point to the head of the list
    ListNode* dummy = new ListNode(0);
    dummy->next = head;
    
    // Initialize two pointers, both starting at the dummy node
    ListNode* fast = dummy;
    ListNode* slow = dummy;
    
    // Move the fast pointer `n+1` steps forward to create the gap
    for (int i = 0; i <= n; ++i) {
        fast = fast->next;
    }
    
    // Move both fast and slow pointers together until fast reaches the end
    while (fast != nullptr) {
        fast = fast->next;
        slow = slow->next;
    }
    
    // Now, slow is at the node just before the one we need to remove
    slow->next = slow->next->next;
    
    // Return the head of the modified list (dummy->next is the real head)
    return dummy->next;
}
Dry Run:
Example 1:
Input: 1 -> 2 -> 3 -> 4 -> 5, n = 2.
Output: 1 -> 2 -> 3 -> 5.
Steps:

Create dummy node: 0 -> 1 -> 2 -> 3 -> 4 -> 5.
Move fast pointer n+1 = 3 steps:
fast moves to 3, slow is still at dummy.
Move fast and slow together:
fast moves to 4, slow moves to 1.
fast moves to 5, slow moves to 2.
fast reaches the end, slow points to 3.
Remove node 4 by updating slow->next = slow->next->next.
Result: 1 -> 2 -> 3 -> 5.
Edge Case:
Input: 1, n = 1 (single node list).
Output: [] (empty list).
Steps:

Create dummy node: 0 -> 1.
Move fast pointer n+1 = 2 steps:
fast moves to nullptr (end of list).
Since fast reached the end, we remove the head node by adjusting dummy->next = dummy->next->next.
Result: [] (empty list).
Time Complexity:
O(n): The algorithm traverses the list twice. Once to move the fast pointer n+1 steps ahead, and the second time to move both slow and fast together to find the node to be removed.
Space Complexity:
O(1): We are using a constant amount of extra space (dummy node and pointers fast and slow).
