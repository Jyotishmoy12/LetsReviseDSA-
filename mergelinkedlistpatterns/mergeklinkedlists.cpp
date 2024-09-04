Problem Statement
Merge K Sorted Linked Lists: Given k sorted linked lists, merge them into a single sorted linked list. Each list is sorted in ascending order.

Dry Run
Test Case:

List 1: 1 -> 4 -> 5
List 2: 1 -> 3 -> 4
List 3: 2 -> 6
Expected Output: 1 -> 1 -> 2 -> 3 -> 4 -> 4 -> 5 -> 6

Approach
To solve this problem efficiently, we can use a min-heap (priority queue) to help merge the lists. The idea is to repeatedly extract the smallest element from the heap and add it to the result list.
Each time we extract an element, we add the next element from the same list to the heap.
struct Compare {
    bool operator()(ListNode* a, ListNode* b) {
        return a->val > b->val;
    }
};

ListNode* mergeKLists(vector<ListNode*>& lists) {
    priority_queue<ListNode*, vector<ListNode*>, Compare> minHeap;

    // Initialize the heap with the head of each list
    for (ListNode* list : lists) {
        if (list) {
            minHeap.push(list);
        }
    }

    ListNode* dummy = new ListNode(0);
    ListNode* current = dummy;

    while (!minHeap.empty()) {
        ListNode* node = minHeap.top();
        minHeap.pop();
        current->next = node;
        current = current->next;

        if (node->next) {
            minHeap.push(node->next);
        }
    }

    return dummy->next;
}


dry run:

List 1: 1 -> 4 -> 5
List 2: 1 -> 3 -> 4
List 3: 2 -> 6
Dry Run of the Code
Initial Setup:

Create a priority queue (min-heap) to store nodes.
Initialize dummy and current nodes to construct the merged list.
Add the heads of all lists to the priority queue.
Initial State:

Priority Queue (min-heap): [1 (from List 1), 1 (from List 2), 2 (from List 3)]
Merged List: 0 (dummy node)
Steps:

Extract Minimum (1 from List 1):

Remove 1 from the heap.
Add 1 to the merged list.
Push the next node from List 1 (4) to the heap.
Updated Priority Queue: [1 (from List 2), 2 (from List 3), 4 (from List 1)]
Merged List: 1
Extract Minimum (1 from List 2):

Remove 1 from the heap.
Add 1 to the merged list.
Push the next node from List 2 (3) to the heap.
Updated Priority Queue: [2 (from List 3), 3 (from List 2), 4 (from List 1)]
Merged List: 1 -> 1
Extract Minimum (2 from List 3):

Remove 2 from the heap.
Add 2 to the merged list.
Push the next node from List 3 (6) to the heap.
Updated Priority Queue: [3 (from List 2), 4 (from List 1), 6 (from List 3)]
Merged List: 1 -> 1 -> 2
Extract Minimum (3 from List 2):

Remove 3 from the heap.
Add 3 to the merged list.
Push the next node from List 2 (4) to the heap.
Updated Priority Queue: [4 (from List 1), 4 (from List 2), 6 (from List 3)]
Merged List: 1 -> 1 -> 2 -> 3
Extract Minimum (4 from List 1):

Remove 4 from the heap.
Add 4 to the merged list.
Push the next node from List 1 (5) to the heap.
Updated Priority Queue: [4 (from List 2), 5 (from List 1), 6 (from List 3)]
Merged List: 1 -> 1 -> 2 -> 3 -> 4
Extract Minimum (4 from List 2):

Remove 4 from the heap.
Add 4 to the merged list.
List 2 is now exhausted.
Updated Priority Queue: [5 (from List 1), 6 (from List 3)]
Merged List: 1 -> 1 -> 2 -> 3 -> 4 -> 4
Extract Minimum (5 from List 1):

Remove 5 from the heap.
Add 5 to the merged list.
List 1 is now exhausted.
Updated Priority Queue: [6 (from List 3)]
Merged List: 1 -> 1 -> 2 -> 3 -> 4 -> 4 -> 5
Extract Minimum (6 from List 3):

Remove 6 from the heap.
Add 6 to the merged list.
List 3 is now exhausted.
Priority Queue is now empty.
Merged List: 1 -> 1 -> 2 -> 3 -> 4 -> 4 -> 5 -> 6
Final Merged List:

1 -> 1 -> 2 -> 3 -> 4 -> 4 -> 5 -> 6

  Time Complexity:

O(N log K): Here, N is the total number of nodes across all k lists, and K is the number of lists. Each insertion and extraction operation in the priority queue (min-heap) takes O(log K) time, and since we perform these operations for each node, the total time complexity is O(N log K).
Space Complexity:

O(K): The space used by the priority queue is proportional to the number of lists K, as at most K elements are stored in the heap simultaneously. Additionally, the space for the merged linked list itself is O(N).
  
