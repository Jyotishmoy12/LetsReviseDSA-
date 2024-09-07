Longest Subarray with Sum ≤ K problem using the sliding window technique, keeping the structure similar to the previous examples.

Problem:
Given an array of integers and an integer k, find the length of the longest subarray where the sum of elements is less than or equal to k.

Intuition:
The idea is to use a sliding window to maintain a sum of the current subarray.
Start with two pointers, i and j, where i is the start of the subarray and j is the end.
Keep expanding the window by increasing j and adding nums[j] to the sum.
If the sum exceeds k, shrink the window by moving i and subtracting nums[i] from the sum.
Track the length of the longest valid subarray where the sum is ≤ k.
Code (following the sliding window structure with if-else conditions):
cpp
Copy code
class Solution {
public:
    int longestSubarraySumK(vector<int>& nums, int k) {
        int i = 0, j = 0; // Sliding window pointers
        int sum = 0; // Current sum of the window
        int maxLen = 0; // Maximum length of the subarray with sum ≤ k
        int n = nums.size(); // Size of the array
        
        while (j < n) {
            // Add the current element to the sum
            sum += nums[j];
            
            // If the sum exceeds k, shrink the window from the left
            if (sum > k) {
                while (sum > k && i <= j) {
                    sum -= nums[i]; // Subtract the element at the start of the window
                    i++; // Move the start of the window to the right
                }
            }
            
            // Update the maximum length if the current window sum is ≤ k
            if (sum <= k) {
                maxLen = max(maxLen, j - i + 1);
            }
            
            // Expand the window by moving the end pointer `j`
            j++;
        }
        
        return maxLen;
    }
};
Dry Run:
Let's run through an example:

Example:
nums = [1, 2, 3, 4, 5], k = 7

i	j	nums[j]	sum	maxLen	Action
0	0	1	1	1	Expand j, valid subarray [1]
0	1	2	3	2	Expand j, valid subarray [1, 2]
0	2	3	6	3	Expand j, valid subarray [1, 2, 3]
0	3	4	10	3	Shrink, move i to 1, sum = 9
1	3		9	3	Shrink, move i to 2, sum = 7
2	3		7	3	Valid subarray [3, 4], update maxLen
2	4	5	12	3	Shrink, move i to 3, sum = 9
3	4		9	3	Shrink, move i to 4, sum = 5
4	4		5	3	Valid subarray [5], no update
Result: maxLen = 3

In this case, the longest subarray where the sum is ≤ 7 is [1, 2, 3] with length 3.

Complexity Analysis:
Time Complexity: O(n), where n is the size of the array. Each element is processed at most twice (once when expanding the window and once when shrinking).
Space Complexity: O(1), as we are using only a few variables to keep track of the sum and window size.
