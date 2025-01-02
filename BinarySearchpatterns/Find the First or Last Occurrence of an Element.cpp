Problem Statement in Detail:
You are given a sorted array nums and a target value target. The array is sorted in non-decreasing order. Your goal is to find either the first or last occurrence of the target in the array. If the target exists in the array multiple times, return the index of the first occurrence or last occurrence of the target. If the target does not exist in the array, return -1.

Intuition:
Since the array is sorted, we can leverage binary search to efficiently find the target value. Binary search can help us reduce the time complexity to O(log n), which is much faster than a linear scan (O(n)) when dealing with large arrays.

We need two variations of binary search:

Finding the first occurrence: In this version of binary search, we search the left half of the array if we find the target, to check if there's another occurrence earlier in the array.
Finding the last occurrence: In this version of binary search, we search the right half of the array if we find the target, to check if there's another occurrence later in the array.
Approach:
We will implement two binary search functions:

Binary search for the first occurrence:
Initialize left as 0 and right as n-1 (the bounds of the array).
While left <= right, compute the middle index mid.
If the element at index mid is the target, we check if it’s the first occurrence. If it is, return mid. Otherwise, continue searching on the left side by updating right = mid - 1.
If the element at mid is smaller than the target, move the left pointer to mid + 1 to search in the right half.
If the element at mid is greater than the target, move the right pointer to mid - 1 to search in the left half.
Binary search for the last occurrence:
Similarly, initialize left and right.
While left <= right, compute the middle index mid.
If the element at mid is the target, we check if it’s the last occurrence. If it is, return mid. Otherwise, continue searching on the right side by updating left = mid + 1.
The rest of the logic is similar to the first binary search.
Dry Run with a Proper Test Case:
Let’s dry run the problem using the test case:

nums = [1, 2, 2, 2, 3], target = 2

Step 1: Finding the First Occurrence
Initial Values: left = 0, right = 4 (size of array is 5).
First Iteration:
Calculate mid = (0 + 4) // 2 = 2.
nums[mid] = 2 which is equal to the target.
Since we are looking for the first occurrence, check if mid is 0 or if nums[mid - 1] is not equal to the target. nums[mid - 1] = nums[1] = 2, so move the right pointer to mid - 1 = 1.
Second Iteration:
Now left = 0, right = 1.
Calculate mid = (0 + 1) // 2 = 0.
nums[mid] = 1, which is less than the target.
Move left pointer to mid + 1 = 1.
Third Iteration:
Now left = 1, right = 1.
Calculate mid = (1 + 1) // 2 = 1.
nums[mid] = 2, which is equal to the target.
Since nums[mid - 1] is not equal to the target, return mid = 1.
So, the first occurrence of 2 is at index 1.

Step 2: Finding the Last Occurrence
Initial Values: left = 0, right = 4.

First Iteration:

Calculate mid = (0 + 4) // 2 = 2.
nums[mid] = 2, which is equal to the target.
Since we are looking for the last occurrence, check if mid is 4 or if nums[mid + 1] is not equal to the target. nums[mid + 1] = nums[3] = 2, so move the left pointer to mid + 1 = 3.
Second Iteration:

Now left = 3, right = 4.
Calculate mid = (3 + 4) // 2 = 3.
nums[mid] = 2, which is equal to the target.
Since nums[mid + 1] = 3 is not equal to the target, return mid = 3.
So, the last occurrence of 2 is at index 3.

Code in C++:
cpp
Copy code
#include <iostream>
#include <vector>
using namespace std;

int findFirstOccurrence(vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;
    int result = -1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (nums[mid] == target) {
            result = mid;
            right = mid - 1; // search on the left side for the first occurrence
        } else if (nums[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return result;
}

int findLastOccurrence(vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;
    int result = -1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (nums[mid] == target) {
            result = mid;
            left = mid + 1; // search on the right side for the last occurrence
        } else if (nums[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return result;
}

int main() {
    vector<int> nums = {1, 2, 2, 2, 3};
    int target = 2;
    
    int first = findFirstOccurrence(nums, target);
    int last = findLastOccurrence(nums, target);
    
    cout << "First Occurrence: " << first << endl; // Output: 1
    cout << "Last Occurrence: " << last << endl;   // Output: 3
    
    return 0;
}
Time and Space Complexity Analysis:
Time Complexity:
For both the first and last occurrence search, the time complexity is O(log n) due to the binary search approach.
Since we perform binary search twice (once for the first occurrence and once for the last occurrence), the overall time complexity is still O(log n).
Space Complexity:
The space complexity is O(1) as we are only using a few extra variables (no extra space is required for data structures).
