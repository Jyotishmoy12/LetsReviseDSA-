Problem: Sort a Linked List
The goal is to sort a singly linked list in O(n log n) time complexity and O(1) space complexity. The most efficient way to achieve this is by using the Merge Sort algorithm, which naturally fits the linked list data structure due to its ability to operate with O(1) auxiliary space.

Approach: Merge Sort for Linked List
Merge Sort works by dividing the list into two halves, recursively sorting each half, and then merging the two sorted halves together. The process is repeated until the entire list is sorted.

Steps:
Find the Middle of the List: Use the slow and fast pointer technique to find the middle of the linked list.
Split the List: Split the list into two halves.
Recursively Sort Both Halves: Recursively apply the same process to each half.
Merge the Two Halves: Merge the two sorted halves to form the final sorted list.
C++ Code Implementation
cpp
Copy code
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Function to merge two sorted linked lists
ListNode* merge(ListNode* l1, ListNode* l2) {
    ListNode dummy(0);
    ListNode* current = &dummy;

    while (l1 != nullptr && l2 != nullptr) {
        if (l1->val <= l2->val) {
            current->next = l1;
            l1 = l1->next;
        } else {
            current->next = l2;
            l2 = l2->next;
        }
        current = current->next;
    }

    current->next = (l1 != nullptr) ? l1 : l2;
    return dummy.next;
}

// Function to find the middle of the linked list
ListNode* findMiddle(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head->next;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

// Function to sort the linked list using merge sort
ListNode* sortList(ListNode* head) {
    if (head == nullptr || head->next == nullptr) {
        return head;
    }

    // Find the middle of the list
    ListNode* middle = findMiddle(head);
    ListNode* rightHead = middle->next;
    middle->next = nullptr; // Split the list into two halves

    // Recursively sort both halves
    ListNode* left = sortList(head);
    ListNode* right = sortList(rightHead);

    // Merge the sorted halves
    return merge(left, right);
}


Example Test Case
Input:

head: 7 -> 2 -> 6 -> 3 -> 5 -> 1 -> 4
Expected Output:

Sorted List: 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7
Detailed Dry Run
Initial List
head: 7 -> 2 -> 6 -> 3 -> 5 -> 1 -> 4
Step 1: Find the Middle of the List
Initial Pointers:

slow = 7
fast = 2 (fast starts one step ahead)
First Iteration:

Move slow to 2
Move fast to 6 (fast moves two steps)
Second Iteration:

Move slow to 6
Move fast to 5
Third Iteration:

Move slow to 3
Move fast to 4
Fourth Iteration:

Move slow to 5
Move fast to nullptr (end of the list)
Middle Node: 5 (split point)
List Split:

Left Half: 7 -> 2 -> 6 -> 3 -> 5
Right Half: 1 -> 4
Step 2: Recursively Sort Both Halves
Sort Left Half: 7 -> 2 -> 6 -> 3 -> 5

Find Middle:

Initial: slow = 7, fast = 2
Iteration 1: slow = 2, fast = 6
Iteration 2: slow = 6, fast = nullptr
Middle Node: 6
Split:

Left Half: 7 -> 2 -> 6
Right Half: 3 -> 5
Sort Left Half: 7 -> 2 -> 6

Find Middle:

Initial: slow = 7, fast = 2
Iteration 1: slow = 2, fast = nullptr
Middle Node: 2
Split:

Left Half: 7 -> 2
Right Half: 6
Sort Left Half: 7 -> 2

Find Middle:

Initial: slow = 7, fast = 2
Fast moves to nullptr
Middle Node: 7
Split:

Left Half: 7
Right Half: 2
Sort Both Halves:

7 and 2 are already sorted.
Merge:

Compare 7 and 2: 2 is smaller.
Remaining 7 is added.
Result: 2 -> 7
Sort Right Half: 6

6 is already sorted.
Merge:

Merge 2 -> 7 and 6:
Compare 2 and 6: 2 is smaller.
Compare 7 and 6: 6 is smaller.
Remaining 7 is added.
Result: 2 -> 6 -> 7
Sort Right Half: 3 -> 5

Find Middle:

Initial: slow = 3, fast = 5
Fast moves to nullptr
Middle Node: 3
Split:

Left Half: 3
Right Half: 5
Sort Both Halves:

3 and 5 are already sorted.
Merge:

Merge 3 and 5:
Result: 3 -> 5
Merge:

Merge 2 -> 6 -> 7 and 3 -> 5:
Compare 2 and 3: 2 is smaller.
Compare 6 and 3: 3 is smaller.
Compare 6 and 5: 5 is smaller.
Remaining 6 and 7 are added.
Result: 2 -> 3 -> 5 -> 6 -> 7
Sort Right Half: 1 -> 4

Find Middle:

Initial: slow = 1, fast = 4
Fast moves to nullptr
Middle Node: 1
Split:

Left Half: 1
Right Half: 4
Sort Both Halves:

1 and 4 are already sorted.
Merge:

Merge 1 and 4:
Result: 1 -> 4
Merge Left Half (2 -> 3 -> 5 -> 6 -> 7) and Right Half (1 -> 4)

Compare 2 and 1: 1 is smaller.
Compare 2 and 4: 2 is smaller.
Compare 3 and 4: 3 is smaller.
Compare 5 and 4: 4 is smaller.
Remaining 5, 6, and 7 are added.
Result: 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7
