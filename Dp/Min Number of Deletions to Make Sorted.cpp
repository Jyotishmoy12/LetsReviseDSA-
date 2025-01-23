1. Problem Statement
You are given an array of integers nums. Your task is to determine the minimum number of deletions required to make the array sorted in strictly increasing order.

Input:

An integer array nums of size n.
Output:

An integer representing the minimum number of deletions required.
Constraints:

1 <= nums.length <= 1000
-10^4 <= nums[i] <= 10^4
2. Intuition
This problem can be reduced to finding the Longest Increasing Subsequence (LIS) of the array. The idea is:

If we can identify the longest subsequence of nums that is strictly increasing, then the rest of the elements (i.e., those not in the LIS) need to be deleted.
The number of deletions required = n - length_of_LIS.
This is a dynamic programming problem because:

We can break it into subproblems by finding the LIS ending at every position i.
By solving smaller subproblems (LIS for smaller arrays), we can build the solution for the entire array.
3. Approach
To solve the problem, follow these steps:

Define dp[i] as the length of the longest increasing subsequence ending at index i.
Initialize all dp[i] to 1 because the minimum LIS for any element is just the element itself.
For each pair of indices i and j where j < i:
If nums[j] < nums[i], then nums[i] can extend the LIS ending at nums[j].
Update dp[i] = max(dp[i], dp[j] + 1).
The length of the LIS is max(dp).
Compute the number of deletions as n - length_of_LIS.
4. Code (C++)
cpp
Copy
Edit
#include <bits/stdc++.h>
using namespace std;

int minDeletionsToMakeSorted(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(n, 1); // dp[i] stores LIS ending at index i

    // Compute LIS for each element
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (nums[j] < nums[i]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    // Find the length of the LIS
    int lengthOfLIS = *max_element(dp.begin(), dp.end());

    // Return the minimum deletions required
    return n - lengthOfLIS;
}

int main() {
    vector<int> nums = {5, 2, 6, 3, 4};
    cout << "Minimum deletions: " << minDeletionsToMakeSorted(nums) << endl;
    return 0;
}
5. Dry Run (Example Execution)
Input:
nums = {5, 2, 6, 3, 4}

Step-by-step explanation:

Initialization:
dp = [1, 1, 1, 1, 1] (Each element has a minimum LIS of 1)

Iterate:

For i = 1:
Compare nums[1] (2) with nums[0] (5). No update since 2 < 5.
dp = [1, 1, 1, 1, 1]

For i = 2:
Compare nums[2] (6) with:

nums[0] (5): dp[2] = max(1, 1 + 1) = 2
nums[1] (2): dp[2] = max(2, 1 + 1) = 2 dp = [1, 1, 2, 1, 1]
For i = 3:
Compare nums[3] (3) with:

nums[0] (5): No update.
nums[1] (2): dp[3] = max(1, 1 + 1) = 2
nums[2] (6): No update.
dp = [1, 1, 2, 2, 1]
For i = 4:
Compare nums[4] (4) with:

nums[0] (5): No update.
nums[1] (2): dp[4] = max(1, 1 + 1) = 2
nums[2] (6): No update.
nums[3] (3): dp[4] = max(2, 2 + 1) = 3
dp = [1, 1, 2, 2, 3]
Result:
Length of LIS = max(dp) = 3.
Minimum deletions = n - lengthOfLIS = 5 - 3 = 2.

6. Line-by-Line Explanation
Initialization: vector<int> dp(n, 1) initializes LIS for each element to 1.
Nested Loop:
Outer loop iterates through each index i.
Inner loop compares all j < i to see if nums[i] can extend LIS ending at nums[j].
Update: dp[i] = max(dp[i], dp[j] + 1) updates the LIS length if nums[j] < nums[i].
Compute LIS: max(dp) gives the length of the LIS.
Return Result: Subtract LIS length from n to get the number of deletions.
7. Complexity Analysis
Time Complexity:
The nested loop runs for all pairs (i, j) where j < i.
Total time = 
𝑂
(
𝑛
2
)
O(n 
2
 ).

Space Complexity:
The dp array requires 
𝑂
(
𝑛
)
O(n) space.
