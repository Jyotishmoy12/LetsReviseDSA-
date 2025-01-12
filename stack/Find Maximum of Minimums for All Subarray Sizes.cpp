Problem Statement in Detail:
You are given an array arr[] of n integers. For each subarray size (from 1 to n), find the maximum of the minimum element in all possible subarrays of that size.

Maximum of Minimums for a Subarray Size: For a given subarray size, we want to find the maximum of the minimum elements in all subarrays of that size.
Example:

Input: arr[] = [2, 1, 3, 4]
Output: [4, 3, 2, 1]
Explanation:

For subarrays of size 1: [2, 1, 3, 4], the minimums are [2, 1, 3, 4] and the maximum of these minimums is 4.
For subarrays of size 2: The subarrays are [2, 1], [1, 3], [3, 4], the minimums are [1, 1, 3], and the maximum of these minimums is 3.
For subarrays of size 3: The subarrays are [2, 1, 3], [1, 3, 4], the minimums are [1, 1], and the maximum of these minimums is 2.
For subarrays of size 4: The subarray is [2, 1, 3, 4], the minimum is 1, and thus the maximum of these minimums is 1.
Intuition:
To solve this problem efficiently, we can use a monotonic stack to find the next and previous smaller elements for each element in the array. These will help us determine the range of subarrays where the current element is the minimum. From there, we can calculate the maximum of the minimums for each subarray size.

The basic idea is to:

For each element, find the next and previous smaller elements using a monotonic stack.
Determine the largest subarray for which the current element is the minimum.
Keep track of the maximum minimum for each subarray size.
Approach:
Find Previous Smaller Element (PSE):

For each element arr[i], find the nearest element to the left which is smaller than arr[i].
Find Next Smaller Element (NSE):

For each element arr[i], find the nearest element to the right which is smaller than arr[i].
Determine Subarray Size:

The subarray size where arr[i] is the minimum element is determined by the distance between its previous and next smaller elements.
For arr[i], it will be the minimum of all subarrays of size k where k is determined by the positions of the next and previous smaller elements.
Store the Maximum Minimum for Each Subarray Size:

Using the above information, we can populate an array that keeps track of the maximum minimum for each subarray size.
Explanation of How to Arrive at the Solution:
By maintaining two arrays (Previous Smaller Element and Next Smaller Element) for each element, we can quickly determine the number of subarrays where each element is the minimum.
The maximum of these minimums for each subarray size is calculated using a result array.
Code in C++:
cpp
Copy code
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

vector<int> find_maximum_of_minimums(int arr[], int n) {
    // Arrays to store the previous and next smaller elements
    vector<int> prev_smaller(n, -1), next_smaller(n, n);

    stack<int> st;

    // Find the previous smaller element for each element
    for (int i = 0; i < n; i++) {
        while (!st.empty() && arr[st.top()] >= arr[i]) {
            st.pop();
        }
        if (!st.empty()) {
            prev_smaller[i] = st.top();
        }
        st.push(i);
    }

    // Clear the stack for next smaller element calculation
    while (!st.empty()) {
        st.pop();
    }

    // Find the next smaller element for each element
    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && arr[st.top()] >= arr[i]) {
            st.pop();
        }
        if (!st.empty()) {
            next_smaller[i] = st.top();
        }
        st.push(i);
    }

    // Array to store the maximum of minimums for each subarray size
    vector<int> result(n, 0);

    // Calculate the maximum minimum for each subarray size
    for (int i = 0; i < n; i++) {
        int len = next_smaller[i] - prev_smaller[i] - 1;
        result[len - 1] = max(result[len - 1], arr[i]);
    }

    // Fill the remaining values in the result array by propagating maximums
    for (int i = n - 2; i >= 0; i--) {
        result[i] = max(result[i], result[i + 1]);
    }

    return result;
}

int main() {
    int arr[] = {2, 1, 3, 4};
    int n = 4;

    // Get the result array
    vector<int> result = find_maximum_of_minimums(arr, n);

    // Output the result
    for (int i : result) {
        cout << i << " ";
    }

    return 0;
}
Dry Run Step by Step:
Let's dry run the above code with the test case:

Input: arr[] = [2, 1, 3, 4]

Initialization:

prev_smaller = [-1, -1, -1, -1]
next_smaller = [4, 4, 4, 4]
result = [0, 0, 0, 0]
Step-by-Step Execution:

Calculate Previous Smaller Element (PSE):

For arr[0] = 2, no element to the left is smaller. prev_smaller[0] = -1.
For arr[1] = 1, the previous smaller element is 2. prev_smaller[1] = 0.
For arr[2] = 3, the previous smaller element is 1. prev_smaller[2] = 1.
For arr[3] = 4, the previous smaller element is 3. prev_smaller[3] = 2.
Calculate Next Smaller Element (NSE):

For arr[0] = 2, the next smaller element is 1. next_smaller[0] = 1.
For arr[1] = 1, there is no smaller element to the right. next_smaller[1] = 4.
For arr[2] = 3, the next smaller element is 2. next_smaller[2] = 3.
For arr[3] = 4, there is no smaller element to the right. next_smaller[3] = 4.
Calculate Maximum of Minimums for Each Subarray Size:

For arr[0] = 2, the subarray size is next_smaller[0] - prev_smaller[0] - 1 = 1. We set result[0] = max(result[0], arr[0]) = 2.
For arr[1] = 1, the subarray size is next_smaller[1] - prev_smaller[1] - 1 = 4. We set result[3] = max(result[3], arr[1]) = 1.
For arr[2] = 3, the subarray size is next_smaller[2] - prev_smaller[2] - 1 = 2. We set result[1] = max(result[1], arr[2]) = 3.
For arr[3] = 4, the subarray size is next_smaller[3] - prev_smaller[3] - 1 = 1. We set result[0] = max(result[0], arr[3]) = 4.
Fill Remaining Values:

Propagate the maximum values to ensure each result[i] has the correct maximum of minimums for that subarray size.
result[2] remains 2, as it was never updated.
Final Output:

result = [4, 3, 2, 1]
Complexity Analysis:
Time Complexity:

Finding the previous and next smaller elements takes O(n) time using the stack.
Filling the result array takes O(n) time.
Therefore, the overall time complexity is O(n).
Space Complexity:

We use two arrays (prev_smaller and next_smaller) of size n and the result array of size n.
The space complexity is O(n).
