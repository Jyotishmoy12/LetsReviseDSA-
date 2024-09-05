Swap Nodes in Pairs
You are given a singly linked list, and the task is to swap every two adjacent nodes in the list. If the number of nodes is odd, the last node should remain in its original position.

Example:
Input:
rust
Copy code
1 -> 2 -> 3 -> 4 -> 5
Output:
rust
Copy code
2 -> 1 -> 4 -> 3 -> 5
Here, every two nodes are swapped. Node 1 and 2 are swapped, then 3 and 4 are swapped, and node 5 remains in its original position since it doesn’t have a pair to swap with.

Intuition:
The problem can be broken down into simple steps:

Traverse the list and keep swapping the current pair of nodes.
After swapping, adjust the next pointers so that the order remains correct.
Continue this until the end of the list.
If the number of nodes is odd, the last node is left untouched as there will be no pair to swap it with.
Approach:
Iterative Approach:
Initialize Pointers:

Use a dummy node to simplify the process, as it allows easy manipulation of head pointers.
Use three pointers: prev (the node before the current pair), first (the first node in the pair), and second (the second node in the pair).
Swap Nodes:

Swap the two nodes by changing their next pointers.
Move the prev pointer to the end of the swapped nodes for the next iteration.
Continue until no more pairs are left.
Edge Cases:

If the list has only one node, return the head as is.
If the list has an even number of nodes, all pairs will be swapped.
If the list has an odd number of nodes, the last node will remain unswapped.

ListNode* swapPairs(ListNode* head) {
    // Dummy node to simplify edge cases
    ListNode* dummy = new ListNode(0);
    dummy->next = head;

    // Initialize pointers
    ListNode* prev = dummy;

    // Traverse the list in pairs
    while (prev->next != nullptr && prev->next->next != nullptr) {
        // Identify the nodes to be swapped
        ListNode* first = prev->next;
        ListNode* second = first->next;
        
        // Swap the nodes
        first->next = second->next;
        second->next = first;
        prev->next = second;
        
        // Move the pointer for the next pair
        prev = first;
    }

    // Return the new head (dummy->next)
    return dummy->next;
}

We'll use the example linked list: 1 -> 2 -> 3 -> 4 -> 5.

Pointers:
prev: Keeps track of the node before the pair of nodes being swapped.
first: The first node in the pair that is about to be swapped.
second: The second node in the pair that is about to be swapped.
Initial Setup:
We begin by initializing a dummy node that points to the head of the list. The purpose of the dummy node is to simplify the swapping logic, especially for the first node.

Initial State:

rust
Copy code
dummy -> 1 -> 2 -> 3 -> 4 -> 5
prev points to dummy (0).
first points to node 1.
second points to node 2.
Step-by-Step Visualization:
Step 1: Swapping First and Second Nodes (1 and 2)
Before swapping:
prev -> dummy (0)
first -> 1
second -> 2
rust
Copy code
dummy -> 1 -> 2 -> 3 -> 4 -> 5
prev      first second
Swapping nodes:
Update first->next to point to second->next (i.e., 1->3).
Update second->next to point to first (i.e., 2->1).
Update prev->next to point to second (i.e., dummy->2).
rust
Copy code
dummy -> 2 -> 1 -> 3 -> 4 -> 5
prev      second first
State after swapping:

rust
Copy code
dummy -> 2 -> 1 -> 3 -> 4 -> 5
Now prev points to first (which is 1 after the swap).
Move the prev pointer forward to the node 1, so it's ready for the next iteration.
Pointers after moving:

prev points to 1.
first will move to 3 (the next node after 1).
second will move to 4 (the next node after 3).
rust
Copy code
dummy -> 2 -> 1 -> 3 -> 4 -> 5
            prev      first second
Step 2: Swapping Next Pair (3 and 4)
Before swapping:
prev -> 1
first -> 3
second -> 4
rust
Copy code
dummy -> 2 -> 1 -> 3 -> 4 -> 5
            prev      first second
Swapping nodes:
Update first->next to point to second->next (i.e., 3->5).
Update second->next to point to first (i.e., 4->3).
Update prev->next to point to second (i.e., 1->4).
rust
Copy code
dummy -> 2 -> 1 -> 4 -> 3 -> 5
            prev      second first
State after swapping:

rust
Copy code
dummy -> 2 -> 1 -> 4 -> 3 -> 5
Now prev points to first (which is 3 after the swap).
Move the prev pointer forward to node 3 for the next iteration.
Pointers after moving:

prev points to 3.
first will move to 5 (the next node after 3).
second will move to nullptr (since there's no node after 5).
rust
Copy code
dummy -> 2 -> 1 -> 4 -> 3 -> 5
                     prev      first (second is null)
Step 3: End of the List
Stopping Condition:
Now second == nullptr, meaning there's no more pairs of nodes to swap.
The loop terminates as no further swaps can occur.
Final Result:
The final linked list is:

rust
Copy code
2 -> 1 -> 4 -> 3 -> 5
Dry Run Summary:
First Pair (1 and 2):

Swapped 1 and 2.
List becomes 2 -> 1 -> 3 -> 4 -> 5.
Second Pair (3 and 4):

Swapped 3 and 4.
List becomes 2 -> 1 -> 4 -> 3 -> 5.
Odd Node (5):

Node 5 remains unswapped.
Edge Case: Single Node List
For a single node linked list like 1, there’s no second node to swap with, so the list remains unchanged.


Input: 1
Output: 1
Time Complexity:
O(n): The algorithm traverses each node once, processing each pair of nodes, where n is the number of nodes in the linked list.
Space Complexity:
O(1): The space complexity is constant because the algorithm uses a few pointers (prev, first, second) and no additional data structures (except for the dummy node, which is a constant size node).

