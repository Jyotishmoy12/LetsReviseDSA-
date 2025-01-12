Problem Overview:
We are tasked with finding the "Next Element with Greater Frequency" for each element in the array. Given an array arr[] of size n, we need to find, for each element in arr[i], the closest element to its right that has a greater frequency than arr[i]. If no such element exists, we return -1 for that element.

Key Steps to Solve:

Frequency Calculation:

The frequency of each element in the array needs to be calculated.
A frequency map will help us store the frequency count of each element in arr[].
Traverse the Array:

We need to traverse the array and, for each element, find the closest element to its right that has a greater frequency.
A stack can help us efficiently find this element as we traverse from right to left.
Stack Mechanism:

As we traverse the array from right to left, we maintain a stack that helps us track the elements for which we haven’t found the next greater frequency element yet.
If an element’s frequency is greater than the frequency of the element at the top of the stack, the top element's answer is this current element.
If not, we continue popping the stack until we find an element with a greater frequency or until the stack becomes empty.
Final Output:

If no such element is found for an element, we return -1 for that element.
Code Implementation:
cpp
Copy code
#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
using namespace std;

vector<int> print_next_greater_freq(int arr[], int n)
{
    // Vector to store the result initialized with -1
    vector<int> ans(n, -1);
    
    // Stack to store the indices of elements
    stack<int> st;
    
    // Map to store frequency of each element
    unordered_map<int, int> freq;
    
    // Step 1: Calculate frequency of each element
    for (int i = 0; i < n; i++) {
        freq[arr[i]]++;
    }
    
    // Step 2: Traverse the array from right to left
    for (int i = n - 1; i >= 0; i--) {
        // Step 3: Pop elements from the stack that have lower or equal frequency than current element
        while (!st.empty() && freq[arr[i]] >= freq[arr[st.top()]]) {
            st.pop();
        }
        
        // Step 4: If the stack is not empty, the element at the top of the stack is the answer for current element
        if (!st.empty()) {
            ans[i] = arr[st.top()];
        }
        
        // Step 5: Push the current element index onto the stack
        st.push(i);
    }
    
    return ans;
}

int main() {
    int arr1[] = {2, 1, 1, 3, 2, 1};
    int n1 = 6;
    vector<int> result1 = print_next_greater_freq(arr1, n1);
    for (int num : result1) {
        cout << num << " ";
    }
    cout << endl;
    
    int arr2[] = {5, 1, 2, 3, 2, 5, 5, 4, 5, 2};
    int n2 = 10;
    vector<int> result2 = print_next_greater_freq(arr2, n2);
    for (int num : result2) {
        cout << num << " ";
    }
    cout << endl;
    
    return 0;
}
Explanation of the Code:
Frequency Map:
We first calculate the frequency of each element in the array using an unordered_map<int, int> freq.
Traversing the Array (Right to Left):
We then iterate through the array from right to left (using a loop starting from n-1).
Stack Operations:
For each element, we pop elements from the stack that have a frequency less than or equal to the current element’s frequency.
After popping, if the stack is not empty, the element at the top of the stack is the next element with greater frequency, and we store it in ans[i].
If the stack is empty, it means no such element exists, and we leave ans[i] as -1.
Push the Current Element:
After checking the top of the stack, we push the current element's index onto the stack to check future elements against it.
Example Walkthrough:
Example 1:
Input:

makefile
Copy code
arr = {2, 1, 1, 3, 2, 1}
n = 6
Frequency Map:

rust
Copy code
2 -> 2
1 -> 3
3 -> 1
Start from the last element (1 at index 5):
No element on the right, so ans[5] = -1.
Move to the next element (2 at index 4):
The frequency of 2 (2) is greater than the frequency of 1 (3 at index 5), so ans[4] = 1.
Continue similarly for the rest of the elements.
Output:

Copy code
1 -1 -1 2 1 -1
Example 2:
Input:

makefile
Copy code
arr = {5, 1, 2, 3, 2, 5, 5, 4, 5, 2}
n = 10
Frequency Map:

rust
Copy code
5 -> 4
1 -> 1
2 -> 3
3 -> 1
4 -> 1
Output:

diff
Copy code
-1 2 5 2 5 -1 -1 5 -1 -1
Edge Cases:
All Elements with Same Frequency: If all elements in the array have the same frequency, then no element will have a greater frequency to the right, so the result will be -1 for every element.

Single Element Array: For an array with only one element, the result will always be -1 since there is no other element to the right.

Time Complexity:
Frequency Calculation: O(n) to calculate the frequency of each element.
Stack Processing: Each element is pushed and popped from the stack at most once, so the time complexity is O(n) for stack processing.
Total Time Complexity: O(n).
Space Complexity:
We use a stack to store indices and a frequency map to store the frequency of elements.
Space Complexity: O(n).
