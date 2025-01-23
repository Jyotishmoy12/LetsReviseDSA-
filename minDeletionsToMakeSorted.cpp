Optimized Approach
Key Idea:
We don't need to calculate the actual LIS values for all indices using 
𝑂
(
𝑛
2
)
O(n 
2
 ) DP. Instead:

Use a list to simulate LIS:
The list maintains elements of the current LIS being built.
For each number in the array, use binary search to determine its position in the list.
If the number can extend the LIS (greater than the last element in the list), append it to the list.
If the number can replace an existing element in the list (using binary search), replace it to ensure the list contains the smallest possible elements at each length.
The size of the list at the end will give the length of LIS. Using this length, compute the minimum deletions.

Steps
Initialization:
Create an empty list lis to simulate the LIS.
Iterate through the array:
For each number, perform a binary search to find its position in lis.
If the number is greater than all elements, append it to lis.
Otherwise, replace the element at the found position.
Result:
Length of lis = Length of LIS.
Minimum deletions = 
𝑛
−
length of LIS
n−length of LIS.
Code (C++)
Here’s how this works in code:

cpp
Copy
Edit
#include <bits/stdc++.h>
using namespace std;

int minDeletionsToMakeSorted(vector<int>& nums) {
    vector<int> lis; // To store elements of the current LIS
    
    for (int num : nums) {
        // Perform binary search to find the position of the current number
        auto it = lower_bound(lis.begin(), lis.end(), num);
        
        if (it == lis.end()) {
            // If num is greater than all elements, append it
            lis.push_back(num);
        } else {
            // Otherwise, replace the element at position it
            *it = num;
        }
    }
    
    // Length of LIS is the size of the list
    int lengthOfLIS = lis.size();
    
    // Minimum deletions required
    return nums.size() - lengthOfLIS;
}

int main() {
    vector<int> nums = {5, 2, 6, 3, 4};
    cout << "Minimum deletions: " << minDeletionsToMakeSorted(nums) << endl;
    return 0;
}
Dry Run (Step-by-Step)
Input:
nums = {5, 2, 6, 3, 4}

Initial state:
lis = []

Process:

num = 5:

lower_bound(lis, 5) returns end of lis (empty list).
Append 5.
lis = [5]
num = 2:

lower_bound(lis, 2) returns index 0 (position to replace 5).
Replace 5 with 2.
lis = [2]
num = 6:

lower_bound(lis, 6) returns end of lis.
Append 6.
lis = [2, 6]
num = 3:

lower_bound(lis, 3) returns index 1 (position to replace 6).
Replace 6 with 3.
lis = [2, 3]
num = 4:

lower_bound(lis, 4) returns end of lis.
Append 4.
lis = [2, 3, 4]
Result:

Length of LIS = lis.size() = 3
Minimum deletions = 
𝑛
−
length of LIS
=
5
−
3
=
2
n−length of LIS=5−3=2.
Line-by-Line Explanation
Initialization:

vector<int> lis; creates an empty list to simulate LIS.
Binary Search:

lower_bound(lis.begin(), lis.end(), num) finds the smallest element in lis that is greater than or equal to num.
Decision:

If no such element exists (it == lis.end()), append num to lis.
Otherwise, replace the element at position it with num.
Result Calculation:

Length of lis gives the LIS length.
Subtract this from the array size to get the number of deletions.
Complexity Analysis
Time Complexity:

For each number, lower_bound performs binary search in 
𝑂
(
log
⁡
𝑘
)
O(logk), where 
𝑘
k is the size of the list.
Since this is done for all 
𝑛
n elements, the total complexity is 
𝑂
(
𝑛
log
⁡
𝑛
)
O(nlogn).
Space Complexity:

The lis list requires 
𝑂
(
𝑛
)
O(n) space in the worst case.
