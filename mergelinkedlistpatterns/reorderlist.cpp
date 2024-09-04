Problem Statement
Reorder List: Given a linked list, reorder it to follow this pattern: L0 → Ln → L1 → Ln-1 → L2 → Ln-2 → ....

Intuition
To solve the problem, we can follow these steps:

Find the Middle of the List:

Use the slow and fast pointer technique to find the middle of the linked list. This will allow us to split the list into two halves.
Reverse the Second Half:

Reverse the second half of the list. This will help in merging it in the desired order.
Merge Two Halves:

Merge the two halves in the required pattern. Alternately pick nodes from the first half and the reversed second half.
Algorithm
Find the Middle:

Use a slow pointer and a fast pointer. Move the slow pointer one step at a time and the fast pointer two steps at a time. When the fast pointer reaches the end, the slow pointer will be at the middle.
Reverse the Second Half:

Starting from the middle, reverse the second half of the list.
Merge the Two Halves:

Use two pointers to alternate between nodes from the first half and the reversed second half.

ListNode* findMiddle(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

// Function to reverse a linked list
ListNode* reverseList(ListNode* head) {
    ListNode* prev = nullptr;
    ListNode* curr = head;
    while (curr != nullptr) {
        ListNode* nextTemp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextTemp;
    }
    return prev;
}

// Function to reorder the linked list
void reorderList(ListNode* head) {
    if (head == nullptr || head->next == nullptr) return;
    
    // Step 1: Find the middle of the list
    ListNode* mid = findMiddle(head);
    
    // Step 2: Reverse the second half
    ListNode* second = reverseList(mid->next);
    mid->next = nullptr; // Split the list into two halves
    
    // Step 3: Merge the two halves
    ListNode* first = head;
    while (second != nullptr) {
        ListNode* temp1 = first->next;
        ListNode* temp2 = second->next;
        
        first->next = second;
        second->next = temp1;
        
        first = temp1;
        second = temp2;
    }
}
Step 3: Merge the Two Halves
Objective: Merge the two halves in the specific order: L0 → Ln → L1 → Ln-1 → L2 → Ln-2 → ....

Approach: Use two pointers:

first pointer: Traverses the first half (1 -> 2 -> 3).
second pointer: Traverses the reversed second half (5 -> 4).
Process:

Initialize first at the start of the first half (1) and second at the start of the reversed second half (5).
Merge nodes alternately from first and second.
Execution:

Initial Pointers: first = 1, second = 5

Set first->next to 5, so now the list looks like 1 -> 5.
Set second->next to 2 (the next node in the first half).
Move first to 2, and second to 4.
Next Pointers: first = 2, second = 4

Set first->next to 4, so now the list looks like 1 -> 5 -> 2 -> 4.
Set second->next to 3 (the next node in the first half).
Move first to 3, and second to nullptr (end of the second half).
Final Pointers: first = 3, second = nullptr

Set first->next to nullptr to terminate the list.
Resulting Reordered List: 1 -> 5 -> 2 -> 4 -> 3
