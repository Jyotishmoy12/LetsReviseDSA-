Problem: Find Minimum in Rotated Sorted Array
Given a rotated sorted array, find the minimum element in the array. A rotated array means that some initial segment of the array is shifted to the end, making the array partially sorted. The array has no duplicates.

Example 1:

vbnet
Copy code
Input: nums = [3, 4, 5, 1, 2]
Output: 1
Explanation: The minimum value is 1.
Example 2:

vbnet
Copy code
Input: nums = [4, 5, 6, 7, 0, 1, 2]
Output: 0
Explanation: The minimum value is 0.
Example 3:

vbnet
Copy code
Input: nums = [11, 13, 15, 17]
Output: 11
Explanation: The array is not rotated, so the first element is the minimum.
Intuition & Approach:
The array is sorted but rotated, so the key insight is to utilize binary search to minimize time complexity. The minimum element will be the pivot point where the rotation happened.

Key Observations:
If the array is not rotated, the minimum element is simply the first element.
In a rotated array, at least one half (left or right) of the array remains sorted.
We can use the sorted half to reduce our search space.
Steps:
Use two pointers, left and right, initialized to the start and end of the array.
Compute the middle index mid.
Compare the middle element with the element at the right pointer:
If nums[mid] > nums[right]: The minimum must lie in the unsorted right half, so move left = mid + 1.
Otherwise, the minimum is in the left half (including mid), so move right = mid.
The loop ends when left equals right, and this position holds the minimum element.
Code Implementation (C++):
cpp
Copy code
#include <iostream>
#include <vector>

using namespace std;

int findMin(vector<int>& nums) {
    int left = 0, right = nums.size() - 1;
    
    while (left < right) {
        int mid = left + (right - left) / 2;
        
        // Check if mid is greater than the rightmost element
        if (nums[mid] > nums[right]) {
            // The minimum is in the right part
            left = mid + 1;
        } else {
            // The minimum is in the left part, including mid
            right = mid;
        }
    }
    
    // Left should be pointing to the minimum element
    return nums[left];
}

int main() {
    vector<int> nums1 = {3, 4, 5, 1, 2};
    vector<int> nums2 = {4, 5, 6, 7, 0, 1, 2};
    vector<int> nums3 = {11, 13, 15, 17};
    
    cout << "Minimum in nums1: " << findMin(nums1) << endl; // Output: 1
    cout << "Minimum in nums2: " << findMin(nums2) << endl; // Output: 0
    cout << "Minimum in nums3: " << findMin(nums3) << endl; // Output: 11
    
    return 0;
}
Dry Run:
Test Case 1:
Input: nums = [4, 5, 6, 7, 0, 1, 2]
Initial State: left = 0, right = 6
mid = (0 + 6) / 2 = 3 → nums[mid] = 7
Since nums[mid] > nums[right] (7 > 2), search the right half → left = mid + 1 = 4
Second Iteration: left = 4, right = 6
mid = (4 + 6) / 2 = 5 → nums[mid] = 1
Since nums[mid] < nums[right] (1 < 2), search the left half → right = mid = 5
Third Iteration: left = 4, right = 5
mid = (4 + 5) / 2 = 4 → nums[mid] = 0
Since nums[mid] < nums[right] (0 < 1), search the left half → right = mid = 4
Termination: left = right = 4, the minimum is nums[left] = 0.
Output: 0

Time and Space Complexity Analysis:
Time Complexity:

Each iteration reduces the search space by half, so the time complexity is O(log n) where n is the length of the array.
Space Complexity:

The algorithm uses constant space, so the space complexity is O(1).
