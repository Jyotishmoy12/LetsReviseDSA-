Problem Statement
Given an array arr[] of integers and three integers l, r, and x, the goal is to count how many elements in the subarray arr[l...r] are smaller than x.

Steps to Solve the Problem
Input:

An array arr[] of size n.
Two indices l and r, which define the range of the subarray.
An integer x, the value against which the elements will be compared.
Output:

The number of elements between indices l and r in the array that are smaller than x.
Approach:

Iterate through the array from index l to r.
For each element in this subarray, check if it is smaller than x.
If it is, increment a counter.
Finally, return the counter as the result.



#include <iostream>
#include <vector>
using namespace std;

// Function to count elements smaller than x in the subarray arr[l...r]
int countElementsSmallerThanX(const vector<int>& arr, int l, int r, int x) {
    int count = 0;

    // Iterate through the subarray arr[l...r]
    for (int i = l; i <= r; ++i) {
        if (arr[i] < x) {
            count++; // Increment the count if arr[i] is smaller than x
        }
    }

    return count;
}

int main() {
    // Example array
    vector<int> arr = {10, 5, 20, 15, 25, 7, 30};

    // Define the indices l, r, and the value x
    int l = 1;
    int r = 4;
    int x = 18;

    // Call the function and print the result
    int result = countElementsSmallerThanX(arr, l, r, x);
    cout << "Number of elements smaller than " << x << " between indices " << l << " and " << r << " is: " << result << endl;

    return 0;
}
