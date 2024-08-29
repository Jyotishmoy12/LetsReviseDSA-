Problem Explanation: Intersection of Two Linked Lists
Problem Statement: Given two singly linked lists, find the node where they intersect. If they do not intersect, return nullptr. The intersection node is where the two linked lists merge into a single list, not just sharing the same value but actually pointing to the same node in memory.

Approach to Solve the Problem
1. Calculate the Lengths:
Compute the lengths of both linked lists.
Determine the difference in lengths between the two lists.
2. Align the Start of Both Lists:
Move the pointer of the longer list forward by the difference in lengths. This aligns both pointers at the same position from the end of the lists.
3. Find the Intersection Node:
Traverse both lists simultaneously. The first node where the two pointers meet is the intersection node.
Example: Dry Run
Consider two linked lists:

List 1: A -> B -> C -> D -> E
List 2: X -> Y -> C -> D -> E
Here, the intersection starts at node C.

List Lengths Calculation:

Length of List 1: 5
Length of List 2: 5
The lengths are equal, so no need to move any pointers initially.

Align the Start of Both Lists:

Start both pointers at the heads of their respective lists.
Find the Intersection Node:

Traverse both lists:
First pointer of List 1 and List 2 point to A and X respectively. They do not match.
Move both pointers to B and Y. They do not match.
Move both pointers to C. They match here, so C is the intersection node.

class solution{
    public:
    ListNode*getIntersectionNode(ListNode*headA, ListNode*headB){
        if(headA==NULL || headB==NULL) return NULL;

        // compute the lengths
        int lenA=getLength(headA);
        int lenB=getLength(headB);
        ListNode*longList=lenA>lenB? headA:headB;
        ListNode*shortList=lenA>lenB? headB:headA;
        int diff=abs(lenA-lenB);
        for(int i=0; i<diff; i++){
            longList=longList->next;
        }
        while (longList != nullptr && shortList != nullptr) {
            if (longList == shortList) {
                return longList;  // Intersection found
            }
            longList = longList->next;
            shortList = shortList->next;
        }

        return nullptr; 
    }
}
private:
    int getLength(ListNode *head) {
        int length = 0;
        while (head != nullptr) {
            ++length;
            head = head->next;
        }
        return length;
    }
};


This algorithm efficiently finds the intersection node with a time complexity of 
𝑂(𝑛+𝑚)
O(n+m) and space complexity of 
𝑂(1)
O(1), where 
𝑛
n and 
𝑚
m are the lengths of the two linked lists.
