Problem: Linked List Cycle Length
Description: Given a linked list with a cycle, determine the length of the cycle.

Approach
Detect the Cycle: Use Floyd’s Cycle-Finding Algorithm (Tortoise and Hare algorithm) to detect the presence of a cycle.
Determine the Cycle Length: Once the cycle is detected, keep one pointer fixed and move the other pointer until it returns to the starting point, counting the number of steps taken. 
This count will give the length of the cycle.

Cycle Detection:

Initialize two pointers, slow and fast.
Move slow one step at a time and fast two steps at a time.
If slow and fast meet, a cycle is detected.
Find the Cycle Length:

Once a cycle is detected (i.e., slow and fast meet), keep one pointer at the meeting point.
Move the other pointer around the cycle, counting the number of steps until it returns to the meeting point.
The count gives the length of the cycle.


2. Cycle Detection
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
fast moves to A4 (node 4).
Iteration 5:

slow moves to A6 (node 6).
fast moves to A6 (node 6) (they meet here).
Cycle Detected.

3. Determine the Cycle Length
Keep slow at A6 and move fast one step at a time, counting the steps.
Step 1:

fast moves to A7 (node 7).
Count = 1.
Step 2:

fast moves to A3 (node 3).
Count = 2.
Step 3:

fast moves to A4 (node 4).
Count = 3.
Step 4:

fast moves to A5 (node 5).
Count = 4.
Step 5:

fast moves to A6 (node 6), meeting the slow pointer again.
Count = 5.
Cycle Length = 5.


int cycleLength(ListNode*head){
    ListNode*slow=head;
    ListNode*fast=head;
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
        if(slow=fast){
            int length=0;
            do{
                fast=fast->next;
                length++;
            }while(fast!=slow)
            return length;
        }
    }
    return 0;
}

Time Complexity: O(N), where N is the number of nodes in the linked list.
The detection phase runs in O(N) time because each pointer traverses the list at most once.
The cycle length determination phase also runs in O(K) time, where K is the length of the cycle.
Space Complexity: O(1)
Only a constant amount of extra space is used for the two pointers.

