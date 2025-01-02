Problem Statement
You are given an array of integers. A prefix sum of a subarray is the sum of all elements from the start of the array up to a given index. The goal is to find the subarray (contiguous elements) whose prefix sum is the smallest.

Intuition
The prefix sum at any index gives the cumulative sum of the elements up to that point.
To find the subarray with the minimum prefix sum, we don't need to store all prefix sums. Instead, we can compute them on the fly while keeping track of the minimum prefix sum encountered so far.
We only need to keep a running total (prefix_sum) and compare it with the current minimum.
Approach
Initialize Variables:

prefix_sum: Keeps track of the running sum of elements.
min_prefix_sum: Stores the smallest prefix sum encountered so far.
start and end: Track the indices of the subarray corresponding to min_prefix_sum.
temp_start: Temporary start index for the current subarray being evaluated.
Iterate Through the Array:

For each element:
Add it to prefix_sum.
If prefix_sum becomes smaller than min_prefix_sum, update min_prefix_sum and set start and end to the current subarray indices.
Reset the temp_start when starting a new subarray.
Return the Result:

Return the subarray [start, end] with the minimum prefix sum and its value.
Dry Run
Input:
arr = [3, -4, 2, -1, -5, 4]

Step-by-Step Execution:
Initialize:

prefix_sum = 0, min_prefix_sum = ∞, start = 0, end = 0, temp_start = 0.
Iteration 1 (i = 0, arr[i] = 3):

prefix_sum = 0 + 3 = 3.
prefix_sum (3) < min_prefix_sum (∞):
Update: min_prefix_sum = 3, start = 0, end = 0.
Iteration 2 (i = 1, arr[i] = -4):

prefix_sum = 3 + (-4) = -1.
prefix_sum (-1) < min_prefix_sum (3):
Update: min_prefix_sum = -1, start = 0, end = 1.
Iteration 3 (i = 2, arr[i] = 2):

prefix_sum = -1 + 2 = 1.
prefix_sum (1) is not smaller than min_prefix_sum (-1).
Iteration 4 (i = 3, arr[i] = -1):

prefix_sum = 1 + (-1) = 0.
prefix_sum (0) is not smaller than min_prefix_sum (-1).
Iteration 5 (i = 4, arr[i] = -5):

prefix_sum = 0 + (-5) = -5.
prefix_sum (-5) < min_prefix_sum (-1):
Update: min_prefix_sum = -5, start = 0, end = 4.
Iteration 6 (i = 5, arr[i] = 4):

prefix_sum = -5 + 4 = -1.
prefix_sum (-1) is not smaller than min_prefix_sum (-5).
Code (C++)
cpp
Copy code
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

pair<int, pair<int, int>> minPrefixSumSubarray(vector<int>& arr) {
    int prefix_sum = 0, min_prefix_sum = INT_MAX;
    int start = 0, end = 0, temp_start = 0;

    for (int i = 0; i < arr.size(); i++) {
        prefix_sum += arr[i];

        if (prefix_sum < min_prefix_sum) {
            min_prefix_sum = prefix_sum;
            start = temp_start;
            end = i;
        }

        // Reset prefix_sum and temp_start if prefix_sum is positive
        if (prefix_sum > 0) {
            prefix_sum = 0;
            temp_start = i + 1;
        }
    }

    return {min_prefix_sum, {start, end}};
}

int main() {
    vector<int> arr = {3, -4, 2, -1, -5, 4};
    auto result = minPrefixSumSubarray(arr);
    cout << "Minimum Prefix Sum: " << result.first << endl;
    cout << "Subarray Indices: [" << result.second.first << ", " << result.second.second << "]" << endl;
    return 0;
}
Time and Space Complexity
Time Complexity:

𝑂
(
𝑛
)
O(n): Single pass through the array.
Space Complexity:

𝑂
(
1
)
O(1): No extra space is used apart from variables.
Final Output for Input [3, -4, 2, -1, -5, 4]
Minimum Prefix Sum: -5
Subarray Indices: [0, 4]
