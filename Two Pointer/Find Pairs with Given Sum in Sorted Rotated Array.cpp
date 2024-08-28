Problem:
Given a sorted and rotated array, find if there exists a pair of elements in the array that sum up to a given target value.

Intuition:
Since the array is sorted but rotated, it has two parts: one that is in increasing order and another that wraps around. We can utilize two pointers:

Left pointer (i): Starts from the smallest element in the array.
Right pointer (j): Starts from the largest element in the array.
We can then adjust the pointers:

If the sum of the elements at the two pointers equals the target sum, we have found the pair.
If the sum is less than the target, move the left pointer forward (as we need a larger sum).
If the sum is greater than the target, move the right pointer backward (as we need a smaller sum).
Approach
Identify the pivot point:
The smallest element in the rotated array is at the index just after the largest element. This element divides the array into two sorted parts.

Initialize two pointers:

left points to the smallest element (pivot).
right points to the largest element (pivot - 1).
Check the sum:

If the sum of elements at left and right equals the target, return the pair.
If the sum is less than the target, increment the left pointer.
If the sum is greater than the target, decrement the right pointer.
Loop until the pointers cross each other.

Example
Input:
arr = [11, 15, 6, 8, 9, 10]
target_sum = 16

Expected Output:
Pair found: (6, 10)

Dry Run
Step 1: Identify the Pivot

The smallest element is 6 (at index 2), so:
left = 2
right = 1 (index of the largest element, 15)
Step 2: First Iteration

arr[left] = 6, arr[right] = 15
Sum: 6 + 15 = 21
Since 21 > 16, move right backward.
Step 3: Second Iteration

left = 2, right = 0
(arr[right] = 11)
Sum: 6 + 11 = 17
Since 17 > 16, move right backward.
Step 4: Third Iteration

left = 2, right = 5
(arr[right] = 10)
Sum: 6 + 10 = 16
We have found the pair (6, 10).
Final Output:
Pair found: (6, 10)



  Rotation and Array Structure:

In a sorted and rotated array, the smallest element marks the point of rotation. Everything before it (from the start of the array to the element just before the smallest) is greater, and everything after it (from the smallest element to the end of the array) is smaller.
For example, in the array [11, 15, 6, 8, 9, 10], 6 is the smallest element. The array can be thought of as being "rotated" at this point.
Two Pointers Setup:

Left Pointer (i): Starts from the smallest element (pivot), which is the smallest value in the array.
Right Pointer (j): Starts from the largest element (just before the smallest element).
By setting the left pointer at the smallest element and the right pointer at the largest element, you ensure that one pointer is at the start of the ascending order and the other is at the end, covering the entire array.
Why This Setup Works:

In a standard sorted array, you might set one pointer at the beginning and one at the end. But in a rotated sorted array, the largest value might not be at the end of the array; instead, it's just before the smallest element.
This setup allows you to traverse the array efficiently, moving towards each other from the "smallest-large" and "largest-small" parts of the array.



  #include <iostream>
#include <vector>

using namespace std;

bool findPairWithSum(const vector<int>& arr, int target_sum) {
    int n = arr.size();

    // Step 1: Find the pivot where the smallest element is
    int left, right;
    for (int i = 0; i < n; i++) {
        if (arr[i] > arr[(i + 1) % n]) {
            left = (i + 1) % n; // Index of smallest element
            right = i;          // Index of largest element
            break;
        }
    }

    // Step 2: Use two pointers to find the pair
    while (left != right) {
        int current_sum = arr[left] + arr[right];

        if (current_sum == target_sum) {
            cout << "Pair found: (" << arr[left] << ", " << arr[right] << ")" << endl;
            return true;
        }

        // Move left pointer to the next element if the current sum is less than the target
        if (current_sum < target_sum) {
            left = (left + 1) % n;
        }
        // Move right pointer to the previous element if the current sum is greater than the target
        else {
            right = (right - 1 + n) % n;
        }
    }

    cout << "No pair found." << endl;
    return false;
}

int main() {
    vector<int> arr = {11, 15, 6, 8, 9, 10};
    int target_sum = 16;

    findPairWithSum(arr, target_sum);

    return 0;
}
