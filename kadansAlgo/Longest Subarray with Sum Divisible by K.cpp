Problem Explanation
You are given an array of integers nums and a number k. The task is to find the length of the longest subarray whose sum is divisible by k.

A subarray is a contiguous part of the array.
A subarray's sum is divisible by k if sum % k == 0.
Intuition
The key idea here is:

When the cumulative sum of the array is divided by k, the remainder (sum % k) determines whether the sum is divisible by k.
If two cumulative sums at different indices leave the same remainder when divided by k, the sum of the subarray between those two indices is divisible by k.
Approach (Using Hash Map)
Cumulative Sum and Modulo:

Compute the cumulative sum of the array as you iterate.
Calculate the remainder when the cumulative sum is divided by k (cumulative_sum % k).
Hash Map to Store First Occurrences:

Use a hash map (mod_map) to store the first index where a particular remainder occurs.
If a remainder is found again later in the iteration, it means the subarray between these two indices has a sum divisible by k.
Steps:

Initialize mod_map with {0: -1} because a subarray starting from the beginning can also be valid if cumulative_sum % k == 0.
Keep a max_length variable to track the length of the longest subarray.
Check Conditions:

If a negative remainder is obtained, normalize it to a positive remainder by adding k (to handle negative sums).
If the current remainder already exists in mod_map, calculate the subarray length and update max_length.
Otherwise, store the remainder and its index in mod_map.
Dry Run (Step-by-Step Example)
Input:
nums = [23, 2, 4, 6, 7], k = 6

Initialization:
mod_map = {0: -1} (to handle cases where the entire sum is divisible by k)
cumulative_sum = 0, max_length = 0
Iteration:
Index 0 (nums[0] = 23):

cumulative_sum = 0 + 23 = 23
remainder = 23 % 6 = 5
mod_map does not contain 5, so add it: mod_map = {0: -1, 5: 0}
Index 1 (nums[1] = 2):

cumulative_sum = 23 + 2 = 25
remainder = 25 % 6 = 1
mod_map does not contain 1, so add it: mod_map = {0: -1, 5: 0, 1: 1}
Index 2 (nums[2] = 4):

cumulative_sum = 25 + 4 = 29
remainder = 29 % 6 = 5
mod_map contains 5 (first seen at index 0).
Subarray length = 2 - 0 = 2.
Update max_length = max(0, 2) = 2.
Index 3 (nums[3] = 6):

cumulative_sum = 29 + 6 = 35
remainder = 35 % 6 = 5
mod_map contains 5 (first seen at index 0).
Subarray length = 3 - 0 = 3.
Update max_length = max(2, 3) = 3.
Index 4 (nums[4] = 7):

cumulative_sum = 35 + 7 = 42
remainder = 42 % 6 = 0
mod_map contains 0 (first seen at index -1).
Subarray length = 4 - (-1) = 5.
Update max_length = max(3, 5) = 5.
Final Result:
The longest subarray length is 5.

Code Implementation (C++)
cpp
Copy code
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int longestSubarrayWithSumDivisibleByK(vector<int>& nums, int k) {
    unordered_map<int, int> mod_map; // To store the first occurrence of remainders
    mod_map[0] = -1; // Initialize with remainder 0 at index -1
    int cumulative_sum = 0, max_length = 0;

    for (int i = 0; i < nums.size(); ++i) {
        cumulative_sum += nums[i]; // Update cumulative sum
        int remainder = cumulative_sum % k;

        // Normalize negative remainders
        if (remainder < 0) remainder += k;

        // Check if remainder exists in mod_map
        if (mod_map.find(remainder) != mod_map.end()) {
            int length = i - mod_map[remainder];
            max_length = max(max_length, length);
        } else {
            // Store the first occurrence of the remainder
            mod_map[remainder] = i;
        }
    }

    return max_length;
}

int main() {
    vector<int> nums = {23, 2, 4, 6, 7};
    int k = 6;
    cout << "Longest subarray length: " << longestSubarrayWithSumDivisibleByK(nums, k) << endl;
    return 0;
}
Edge Cases
All elements are divisible by k:

Input: nums = [6, 12, 18], k = 6
Output: Length of the entire array.
No subarray is divisible by k:

Input: nums = [1, 2, 3], k = 5
Output: 0.
Negative numbers:

Input: nums = [-1, -2, 3, 1], k = 3
Output: Correct handling of negative remainders.
Empty array:

Input: nums = []
Output: 0.
Complexity Analysis
Time Complexity: 
𝑂
(
𝑛
)
O(n)

We traverse the array once, and hash map operations (insert/find) are 
𝑂
(
1
)
O(1) on average.
Space Complexity: 
𝑂
(
𝑘
)
O(k)

In the worst case, the hash map stores up to 
𝑘
k remainders.
