Problem: Rearrange a Linked List with Cycle
Description: Given a linked list that contains a cycle, rearrange the nodes so that the cycle is removed, and the list is ordered in the original sequence (before the cycle was formed).

Approach
To solve this problem, we need to:

Detect the Cycle: Use Floyd’s Cycle-Finding Algorithm (Tortoise and Hare algorithm) to detect the presence of a cycle.
Find the Start of the Cycle: Once the cycle is detected, determine the node where the cycle begins.
Break the Cycle: Rearrange the linked list to remove the cycle by setting the next pointer of the node just before the start of the cycle to nullptr.
Rearrange the Linked List: If needed, rearrange the list nodes to maintain their original order without any cycle.
Steps
Cycle Detection:

Initialize two pointers, slow and fast.
Move slow one step at a time and fast two steps at a time.
If slow and fast meet, a cycle is detected.
Find the Start of the Cycle:

Move slow to the head of the list while keeping fast at the meeting point.
Move both pointers one step at a time until they meet again. This point is the start of the cycle.
Break the Cycle:

Once the start of the cycle is identified, traverse the cycle to find the node just before the start node.
Set the next pointer of this node to nullptr, effectively breaking the cycle.
Rearrange the Linked List:

If the original order of nodes needs to be maintained, ensure the list remains ordered.
Dry Run Example
Test Case:

Linked List: 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7
Cycle: Node 7 points back to node 4, creating a cycle (4 -> 5 -> 6 -> 7 -> 4).
After removing the cycle, the linked list should be rearranged as: 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7.



  Initialization:

slow starts at A1 (node 1).
fast starts at A1 (node 1).
Iteration 1:

slow moves to A2 (node 2).
fast moves to A3 (node 3).
Iteration 2:

slow moves to A3 (node 3).
fast moves to A5 (node 5).
Iteration 3:

slow moves to A4 (node 4).
fast moves to A7 (node 7).
Iteration 4:

slow moves to A5 (node 5).
fast moves to A4 (node 4) (they meet here).
Cycle Detected.

3. Find the Start of the Cycle
Move slow to A1 (node 1), while keeping fast at A4 (node 4).
Move both pointers one step at a time until they meet again.
Step 1:

slow moves to A2 (node 2).
fast moves to A5 (node 5).
Step 2:

slow moves to A3 (node 3).
fast moves to A6 (node 6).
Step 3:

slow moves to A4 (node 4).
fast moves to A7 (node 7).
Step 4:

slow moves to A5 (node 5).
fast moves to A4 (node 4) (they meet again).
Start of Cycle Found: Node 4.

4. Break the Cycle
Traverse the cycle starting from A4 (node 4) to find the node just before A4.
Step 1:

Move temp to A5 (node 5).
Step 2:

Move temp to A6 (node 6).
Step 3:

Move temp to A7 (node 7), which points back to A4 (node 4).

Set A7->next to nullptr.

Cycle Removed.

5. Rearrange the Linked List
The linked list is now: 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7.
No further rearrangement is needed as the nodes are already in the original order.
C++ Code
cpp
Copy code
void removeCycle(ListNode *head) {
    if (!head || !head->next) return;

    ListNode *slow = head, *fast = head;

    // Step 1: Detect the cycle
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            // Step 2: Find the start of the cycle
            slow = head;
            while (slow != fast) {
                slow = slow->next;
                fast = fast->next;
            }

            // Step 3: Break the cycle
            ListNode *start = slow;
            ListNode *temp = start;
            while (temp->next != start) {
                temp = temp->next;
            }
            temp->next = nullptr;  // Remove the cycle

            return;
        }
    }
}
Complexity Analysis
Time Complexity: O(N), where N is the number of nodes in the linked list.
Cycle detection runs in O(N) time.
Finding the start of the cycle and breaking it runs in O(N) time.
Space Complexity: O(1)
Only a constant amount of extra space is used for the two pointers.


  Suppose the cycle in the linked list is as follows: 9 -> 12 -> 7 -> 3 -> 4 -> 9.
When start is at 9, temp will traverse 12, 7, 3, and 4.
When temp is at 4, temp->next will be 9 (which is start), so the loop will stop.
3. Removing the Cycle
cpp
Copy code
temp->next = nullptr;
At this point, temp is pointing to the last node in the cycle (in our example, this is node 4).
temp->next is currently pointing to the node at the start of the cycle (start, which is node 9).
By setting temp->next = nullptr, the cycle is broken, and the linked list is made linear again.
The nullptr assignment means that the last node in the cycle now points to nothing, effectively removing the loop.
Visual Representation
Before the loop is removed:

rust
Copy code
8 -> 2 -> 5 -> 9 -> 12 -> 7 -> 3 -> 4 -> (back to 9, forming the cycle)
After removing the cycle:

rust
Copy code
8 -> 2 -> 5 -> 9 -> 12 -> 7 -> 3 -> 4 -> nullptr
Summary
start is the node where the cycle begins.
temp traverses the cycle until it reaches the node just before start.
Setting temp->next = nullptr breaks the cycle by ensuring that the last node no longer points back to the start of the cycle.
