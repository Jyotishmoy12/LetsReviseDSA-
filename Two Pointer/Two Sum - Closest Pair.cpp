Problem: Two Sum - Closest Pair
Objective:
Given an array of integers arr[] and a target integer target, find two elements in the array whose sum is closest to the target. Return the pair of elements that form this sum.

Approach
This problem is a variation of the "Two Sum" problem, but instead of finding the exact sum, we need to find the sum that is closest to the target value. The two-pointer technique is very effective for this problem, especially when the array is sorted.

Steps to Solve
Sort the Array:
First, sort the array. This will allow us to use the two-pointer technique to efficiently find the closest pair.

Initialize Pointers:

Set one pointer (left) at the beginning of the array.
Set the other pointer (right) at the end of the array.
Iterate Using Two Pointers:

Calculate the sum of the elements at left and right.
Compare this sum with the target and update the closest sum if the current sum is closer to the target than the previously stored closest sum.
If the current sum is less than the target, increment the left pointer to increase the sum.
If the current sum is greater than the target, decrement the right pointer to decrease the sum.
Continue this process until the two pointers meet.
Output the Closest Pair:

After completing the iteration, the closest pair is the one whose sum is closest to the target.


#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath> // For abs()

using namespace std;

// Function to find the pair of elements with the sum closest to the target
pair<int, int> closestPairSum(vector<int>& arr, int target) {
    // Sort the array
    sort(arr.begin(), arr.end());

    // Initialize pointers
    int left = 0, right = arr.size() - 1;

    // Initialize variables to track the closest pair and the minimum difference
    int closestSum = arr[left] + arr[right];
    pair<int, int> closestPair = {arr[left], arr[right]};

    // Iterate with two pointers
    while (left < right) {
        int currentSum = arr[left] + arr[right];

        // If the current sum is closer to the target, update the closest pair
        if (abs(currentSum - target) < abs(closestSum - target)) {
            closestSum = currentSum;
            closestPair = {arr[left], arr[right]};
        }

        // Move pointers based on the comparison with the target
        if (currentSum < target) {
            left++; // Move left pointer to increase sum
        } else {
            right--; // Move right pointer to decrease sum
        }
    }

    return closestPair;
}

int main() {
    vector<int> arr = {10, 22, 28, 29, 30, 40};
    int target = 54;

    pair<int, int> result = closestPairSum(arr, target);
    cout << "The closest pair is (" << result.first << ", " << result.second << ")"
         << " with a sum of " << result.first + result.second << endl;

    return 0;
}
