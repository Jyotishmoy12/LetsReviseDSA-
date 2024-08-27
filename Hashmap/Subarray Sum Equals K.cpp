Problem: Subarray Sum Equals K
Objective:
Given an integer array nums and an integer k, find the number of continuous subarrays whose sum equals k.

Approach
To solve this problem efficiently, we can use a hash map (or unordered map in C++) to keep track of the cumulative sum of elements as we iterate through the array. This approach allows us to check for subarrays with the target sum in constant time.

Steps
Initialize Variables:

cumulativeSum: To store the sum of elements from the start up to the current index.
count: To keep track of the number of subarrays that sum up to k.
sumMap: A hash map to store the frequency of cumulative sums. Initialize it with {0: 1} to handle the case where a subarray starting from index 0 directly sums to k.
Iterate Through the Array:

Update the cumulativeSum with each element.
Compute the difference between cumulativeSum and k, and check if this difference exists in sumMap.
If it does, it means there are one or more subarrays ending at the current index that sum to k. Add the frequency of this difference to the count.
Update the hash map with the current cumulativeSum.

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int subarraySum(vector<int>& nums, int k) {
    unordered_map<int, int> mp;
    mp[0]=1; // for starting from 1
    int cummulativeSum=0;
    int cnt=0;
    for(int i=0; i<nums.size(); i++) {
        cummulativeSum+=nums[i];
        int remaining=cummulativeSum-k;
        if(mp.find(remaining)!=mp.end()){
             cnt+=mp[remaining];
        }
        mp[cummulativeSum]++;
        
    }
    return cnt;
}

int main() {
    vector<int> nums = {3, 4, 7, 2, -3, 1, 4, 2};
    int k = 7;

    cout << "Number of subarrays with sum " << k << " is: " << subarraySum(nums, k) << endl;

    return 0;
}



Test Case
Input:
nums = {3, 4, 7, 2, -3, 1, 4, 2}
k = 7

Objective:
Find the number of continuous subarrays that sum up to 7.

Step-by-Step Execution
Initialization:

cumulativeSum = 0
count = 0
sumMap = {0: 1}
Iteration Through Array:

For num = 3:

cumulativeSum = 0 + 3 = 3
complement = 3 - 7 = -4
-4 is not in sumMap, so no update to count.
Update sumMap with cumulativeSum:
sumMap = {0: 1, 3: 1}
For num = 4:

cumulativeSum = 3 + 4 = 7
complement = 7 - 7 = 0
0 is in sumMap with a count of 1, so add 1 to count.
count = 1
Update sumMap with cumulativeSum:
sumMap = {0: 1, 3: 1, 7: 1}
For num = 7:

cumulativeSum = 7 + 7 = 14
complement = 14 - 7 = 7
7 is in sumMap with a count of 1, so add 1 to count.
count = 2
Update sumMap with cumulativeSum:
sumMap = {0: 1, 3: 1, 7: 1, 14: 1}
For num = 2:

cumulativeSum = 14 + 2 = 16
complement = 16 - 7 = 9
9 is not in sumMap, so no update to count.
Update sumMap with cumulativeSum:
sumMap = {0: 1, 3: 1, 7: 1, 14: 1, 16: 1}
For num = -3:

cumulativeSum = 16 - 3 = 13
complement = 13 - 7 = 6
6 is not in sumMap, so no update to count.
Update sumMap with cumulativeSum:
sumMap = {0: 1, 3: 1, 7: 1, 14: 1, 16: 1, 13: 1}
For num = 1:

cumulativeSum = 13 + 1 = 14
complement = 14 - 7 = 7
7 is in sumMap with a count of 1, so add 1 to count.
count = 3
Update sumMap with cumulativeSum:
sumMap = {0: 1, 3: 1, 7: 1, 14: 2, 16: 1, 13: 1}
For num = 4:

cumulativeSum = 14 + 4 = 18
complement = 18 - 7 = 11
11 is not in sumMap, so no update to count.
Update sumMap with cumulativeSum:
sumMap = {0: 1, 3: 1, 7: 1, 14: 2, 16: 1, 13: 1, 18: 1}
For num = 2:

cumulativeSum = 18 + 2 = 20
complement = 20 - 7 = 13
13 is in sumMap with a count of 1, so add 1 to count.
count = 4
Update sumMap with cumulativeSum:
sumMap = {0: 1, 3: 1, 7: 1, 14: 2, 16: 1, 13: 1, 18: 1, 20: 1}
Final Result
Number of subarrays with sum 7 is 4.

Complexity Analysis
Time Complexity: O(n), where n is the number of elements in the array. Each element is processed once, and hash map operations are average-case constant time.

Space Complexity: O(n), where n is the number of unique cumulative sums stored in the hash map.


