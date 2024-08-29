Problem Explanation: Detect Cycle in a Linked List II
Problem Statement: Given a linked list, you need to return the node where the cycle begins. If there is no cycle, return nullptr. A cycle is present in a linked list if a node’s next pointer points to one of the previous nodes in the list, thereby creating a loop.

Objective: The goal is to identify the starting node of the cycle if a cycle exists. If no cycle is present, return nullptr.

Approach to Solve the Problem
1. Floyd’s Tortoise and Hare Algorithm:
This algorithm uses two pointers, slow and fast. Both start at the head of the list:

The slow pointer moves one step at a time.
The fast pointer moves two steps at a time.
If a cycle exists, the fast pointer will eventually meet the slow pointer within the cycle.

2. Finding the Start of the Cycle:
Once a meeting point is found within the cycle:

Reset the slow pointer to the head of the list while keeping the fast pointer at the meeting point.
Move both pointers one step at a time. The point at which they meet is the start of the cycle.
Example: Dry Run
Consider the linked list: 3 -> 2 -> 0 -> -4 -> 2 (where -4 points back to 2).

Initialization:

slow and fast start at node 3.
First Movement:

slow moves to 2, fast moves to 0.
Second Movement:

slow moves to 0, fast moves to 2.
Third Movement:

slow moves to -4, fast moves to -4.
At this point, both slow and fast meet at node -4, indicating a cycle.

Cycle Start Detection:

Reset slow to the head (node 3).
Move slow and fast one step at a time.
slow moves to 2, and fast also moves to 2.
They meet at node 2, which is the start of the cycle.



#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (head == nullptr || head->next == nullptr) {
            return nullptr;  // No cycle if list is empty or has only one node.
        }

        ListNode *slow = head;
        ListNode *fast = head;

        // Phase 1: Detect if a cycle exists
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {  // Cycle detected
                // Phase 2: Find the entry point of the cycle
                slow = head;
                while (slow != fast) {
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow;  // Start of the cycle
            }
        }

        return nullptr;  // No cycle
    }
};

int main() {
    // Creating a list with a cycle
    ListNode *head = new ListNode(3);
    ListNode *second = new ListNode(2);
    ListNode *third = new ListNode(0);
    ListNode *fourth = new ListNode(-4);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = second;  // Creates a cycle

    Solution solution;
    ListNode *cycleStart = solution.detectCycle(head);

    if (cycleStart != nullptr) {
        std::cout << "Cycle starts at node with value: " << cycleStart->val << std::endl;
    } else {
        std::cout << "No cycle detected." << std::endl;
    }

    // Memory cleanup
    // Since the list contains a cycle, the cleanup needs to be handled carefully
    fourth->next = nullptr;  // Break the cycle
    delete fourth;
    delete third;
    delete second;
    delete head;

    return 0;
}



Problem Explanation: Detect Cycle in a Linked List II
Problem Statement: Given a linked list, you need to return the node where the cycle begins. If there is no cycle, return nullptr. A cycle is present in a linked list if a node’s next pointer points to one of the previous nodes in the list, thereby creating a loop.

Objective: The goal is to identify the starting node of the cycle if a cycle exists. If no cycle is present, return nullptr.

Approach to Solve the Problem
1. Floyd’s Tortoise and Hare Algorithm:
This algorithm uses two pointers, slow and fast. Both start at the head of the list:

The slow pointer moves one step at a time.
The fast pointer moves two steps at a time.
If a cycle exists, the fast pointer will eventually meet the slow pointer within the cycle.

2. Finding the Start of the Cycle:
Once a meeting point is found within the cycle:

Reset the slow pointer to the head of the list while keeping the fast pointer at the meeting point.
Move both pointers one step at a time. The point at which they meet is the start of the cycle.
Example: Dry Run
Consider the linked list: 3 -> 2 -> 0 -> -4 -> 2 (where -4 points back to 2).

Initialization:

slow and fast start at node 3.
First Movement:

slow moves to 2, fast moves to 0.
Second Movement:

slow moves to 0, fast moves to 2.
Third Movement:

slow moves to -4, fast moves to -4.
At this point, both slow and fast meet at node -4, indicating a cycle.

Cycle Start Detection:

Reset slow to the head (node 3).
Move slow and fast one step at a time.
slow moves to 2, and fast also moves to 2.
They meet at node 2, which is the start of the cycle.

C++ Code Implementation
cpp
Copy code
#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (head == nullptr || head->next == nullptr) {
            return nullptr;  // No cycle if list is empty or has only one node.
        }

        ListNode *slow = head;
        ListNode *fast = head;

        // Phase 1: Detect if a cycle exists
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {  // Cycle detected
                // Phase 2: Find the entry point of the cycle
                slow = head;
                while (slow != fast) {
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow;  // Start of the cycle
            }
        }

        return nullptr;  // No cycle
    }
};

int main() {
    // Creating a list with a cycle
    ListNode *head = new ListNode(3);
    ListNode *second = new ListNode(2);
    ListNode *third = new ListNode(0);
    ListNode *fourth = new ListNode(-4);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = second;  // Creates a cycle

    Solution solution;
    ListNode *cycleStart = solution.detectCycle(head);

    if (cycleStart != nullptr) {
        std::cout << "Cycle starts at node with value: " << cycleStart->val << std::endl;
    } else {
        std::cout << "No cycle detected." << std::endl;
    }

    // Memory cleanup
    // Since the list contains a cycle, the cleanup needs to be handled carefully
    fourth->next = nullptr;  // Break the cycle
    delete fourth;
    delete third;
    delete second;
    delete head;

    return 0;
}
Step-by-Step Dry Run with Example
Let's walk through the dry run again:

List Construction:

Nodes are created and linked to form the list: 3 -> 2 -> 0 -> -4.
The cycle is introduced by linking -4 back to 2.
Initial Pointers:

Both slow and fast start at 3.
Cycle Detection:

Move slow to 2, fast to 0.
Move slow to 0, fast to -4.
Move slow to -4, fast to -4. They meet here, indicating a cycle.
Finding Cycle Start:

Move slow back to 3.
Move slow to 2, fast to 2. They meet at 2, the start of the cycle.
This algorithm efficiently detects the start of the cycle with a time complexity of 
𝑂(𝑛)
O(n) and space complexity of 
𝑂(1)
O(1), making it optimal for this type of problem.
