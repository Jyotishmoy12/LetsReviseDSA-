You are given an integer array nums sorted in ascending order (with distinct values) and a target value target. The array has been rotated at an unknown pivot such that the array might now appear as [4,5,6,7,0,1,2]. Your task is to search for the target in this rotated sorted array. If the target exists, return its index; otherwise, return -1.

Key Insights and Intuition:
Rotated Sorted Array:
A sorted array that has been rotated means that at some pivot, the order of elements changes, but the two subarrays on either side of the pivot remain sorted. For example, [4, 5, 6, 7, 0, 1, 2] is a rotated version of [0, 1, 2, 4, 5, 6, 7].
Binary Search Approach:
The key idea here is that although the array is rotated, at least one half of the array will still be sorted. This property allows us to apply a modified binary search.
How does it work?
Divide the array into two halves using the middle index.
Determine which half is sorted (either the left half or the right half) by comparing the elements at the low, mid, and high indices.
Once you identify the sorted half, check if the target lies within that range. If it does, reduce the search space to that half; otherwise, search the other half.
Approach:
Initial Setup:
Set low = 0 and high = nums.size() - 1.
While low <= high:
Compute the middle index mid = low + (high - low) / 2.
If nums[mid] == target, return mid (target found).
Determine which half is sorted by comparing nums[low], nums[mid], and nums[high].
If the left half is sorted (nums[low] <= nums[mid]):
Check if the target is in the range [low, mid]. If yes, search in the left half; otherwise, search in the right half.
If the right half is sorted (nums[mid] <= nums[high]):
Check if the target is in the range [mid, high]. If yes, search in the right half; otherwise, search in the left half.
If the target is not found, return -1.

#include <iostream>
#include <vector>
using namespace std;

int searchInRotatedArray(vector<int>& nums, int target) {
    int low = 0, high = nums.size() - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        // Check if the mid element is the target
        if (nums[mid] == target) {
            return mid;
        }

        // Check if the left half is sorted
        if (nums[low] <= nums[mid]) {
            // Target is within the sorted left half
            if (nums[low] <= target && target < nums[mid]) {
                high = mid - 1;
            } else { // Search in the right half
                low = mid + 1;
            }
        }
        // Otherwise, the right half must be sorted
        else {
            // Target is within the sorted right half
            if (nums[mid] < target && target <= nums[high]) {
                low = mid + 1;
            } else { // Search in the left half
                high = mid - 1;
            }
        }
    }

    // If the target is not found
    return -1;
}

int main() {
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    int target = 0;
    int result = searchInRotatedArray(nums, target);
    if (result != -1) {
        cout << "Target found at index: " << result << endl;
    } else {
        cout << "Target not found." << endl;
    }
    return 0;
}
Dry Run:
Let’s dry run this code with the following input:

Test Case 1:
Input: nums = [4, 5, 6, 7, 0, 1, 2], target = 0
Steps:
low = 0, high = 6, mid = (0 + 6) / 2 = 3 → nums[3] = 7
Left half [4, 5, 6, 7] is sorted.
Target 0 is not in the range [4, 7], so search the right half.
Update: low = 4.
low = 4, high = 6, mid = (4 + 6) / 2 = 5 → nums[5] = 1
Right half [0, 1, 2] is sorted.
Target 0 is in the range [0, 1], so search the left half.
Update: high = 4.
low = 4, high = 4, mid = (4 + 4) / 2 = 4 → nums[4] = 0
Target found at index 4.
Output: Target found at index: 4
Test Case 2:
Input: nums = [4, 5, 6, 7, 0, 1, 2], target = 3
Steps:
low = 0, high = 6, mid = 3 → nums[3] = 7
Left half [4, 5, 6, 7] is sorted.
Target 3 is not in the range [4, 7], so search the right half.
Update: low = 4.
low = 4, high = 6, mid = 5 → nums[5] = 1
Right half [0, 1, 2] is sorted.
Target 3 is not in the range [0, 2], so return -1.
Output: Target not found.
Time Complexity:
The time complexity of this approach is O(log n) because we are halving the search space at every step, similar to binary search.
Space Complexity:
The space complexity is O(1) because we only use a few extra variables for indices (low, mid, high), independent of the input size.
