Problem Statement in Detail:
You are given an array arr[] of integers. For each element in the array, we need to calculate the difference between the element and its Next Smaller Element (NSE). If an element does not have a smaller element to its right, its NSE is considered -1.

Next Smaller Element (NSE): For each element in the array, the next smaller element is the first element to the right of the current element that is smaller. If no such element exists, the NSE is -1.
Example:

Input: arr[] = [4, 8, 5, 2]
Output: [2, 3, 3, -1]
Intuition:
The task requires finding the Next Smaller Element for each element in the array. Once the NSE is found, we subtract the current element from its NSE. If no smaller element is found (i.e., NSE is -1), the result will be -1.

To solve this efficiently, we can use a stack to find the next smaller elements. As we traverse the array from right to left, we use the stack to maintain elements in such a way that we can quickly find the next smaller element for each element.

Approach:
Using a Stack:

Traverse the array from right to left.
For each element arr[i], find the next smaller element:
Pop elements from the stack while they are greater than or equal to arr[i], as they cannot be the next smaller element for arr[i] or any element before it.
The element on the top of the stack, if any, is the NSE for arr[i].
If the stack is empty, the NSE is -1.
Push the current element arr[i] onto the stack.
Final Result:

For each element, subtract the NSE from the element to get the desired result.
Explanation of How to Arrive at the Solution:
We need to find the next smaller element for each array element.
By using a stack, we can keep track of elements in a way that allows us to efficiently determine the next smaller element as we move from right to left.
For each element, the stack ensures that we can find the next smaller element in constant time.
The subtraction is straightforward once the NSE is determined.
Code in C++:
cpp
Copy code
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> find_min_difference_with_next_smaller_element(int arr[], int n) {
    vector<int> result(n, -1);  // Initialize result vector with -1
    stack<int> st;

    // Traverse the array from right to left
    for (int i = n - 1; i >= 0; i--) {
        // Pop elements from the stack which are greater than or equal to arr[i]
        while (!st.empty() && st.top() >= arr[i]) {
            st.pop();
        }

        // If the stack is not empty, the top of the stack is the Next Smaller Element
        if (!st.empty()) {
            result[i] = arr[i] - st.top();
        }

        // Push the current element to the stack
        st.push(arr[i]);
    }

    return result;
}

int main() {
    int arr[] = {4, 8, 5, 2};
    int n = 4;
    
    // Get the result array
    vector<int> result = find_min_difference_with_next_smaller_element(arr, n);
    
    // Output the result
    for (int i : result) {
        cout << i << " ";
    }

    return 0;
}
Dry Run Step by Step:
Let's dry run the above code with the test case:

Input: arr = [4, 8, 5, 2]

Initialization:

result = [-1, -1, -1, -1] (This stores the final results)
st = [] (This is the stack that helps in finding the next smaller element)
Step-by-Step Execution:

Iteration 1 (i = 3): arr[3] = 2

The stack is empty, so the NSE for arr[3] is -1 (as per initialization).
Push arr[3] = 2 to the stack.
Stack: st = [2]
result = [-1, -1, -1, -1]
Iteration 2 (i = 2): arr[2] = 5

The stack top is 2, which is smaller than 5. Therefore, the next smaller element for 5 is 2.
Subtract 5 - 2 = 3 and store it in result[2].
Push arr[2] = 5 to the stack.
Stack: st = [2, 5]
result = [-1, -1, 3, -1]
Iteration 3 (i = 1): arr[1] = 8

The stack top is 5, which is smaller than 8. Therefore, the next smaller element for 8 is 5.
Subtract 8 - 5 = 3 and store it in result[1].
Push arr[1] = 8 to the stack.
Stack: st = [2, 5, 8]
result = [-1, 3, 3, -1]
Iteration 4 (i = 0): arr[0] = 4

The stack top is 8, which is greater than 4, so we pop it.
The new stack top is 5, which is greater than 4, so we pop it.
The new stack top is 2, which is smaller than 4. Therefore, the next smaller element for 4 is 2.
Subtract 4 - 2 = 2 and store it in result[0].
Push arr[0] = 4 to the stack.
Stack: st = [2, 4]
result = [2, 3, 3, -1]
Final Output:

result = [2, 3, 3, -1]
Complexity Analysis:
Time Complexity:

The algorithm iterates through the array once, and for each element, we push and pop from the stack at most once. Hence, the time complexity is O(n), where n is the number of elements in the array.
Space Complexity:

We use a stack to store elements, and the result array stores the final answer. Therefore, the space complexity is O(n), where n is the number of elements in the array.
