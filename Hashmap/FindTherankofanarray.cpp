Problem: Find the Rank of Each Element in the Array
Objective: For each element in the array, determine its rank if the array were sorted in ascending order. The rank of an element is its position in the sorted array, where the smallest element has rank 1, the second smallest element has rank 2, and so on. If multiple elements have the same value, they should receive the same rank.

Intuition:
Sorting and Mapping: The idea is to first sort the array and then map each element to its corresponding rank. Since multiple elements can have the same value, they should share the same rank.
Rank Assignment: After sorting, we assign ranks to each unique element based on their position in the sorted array. Then, we map these ranks back to the original array.
Detailed Explanation:
Input: An array of integers.
Output: An array of integers where each element is replaced by its rank.
Steps to Solve:
Copy the Array: Create a copy of the original array to sort.
Sort the Array: Sort the copied array in ascending order.
Assign Ranks: Traverse the sorted array and assign ranks to the elements, considering that equal elements get the same rank.
Map Ranks Back: Use a hash map (or unordered_map in C++) to store the ranks of each element. Then, map these ranks back to the original array.
Example:
Input: [40, 10, 20, 30, 20]

Output: [4, 1, 2, 3, 2]

Explanation:

Sorted array: [10, 20, 20, 30, 40]
Ranks: 10 -> 1, 20 -> 2, 30 -> 3, 40 -> 4
Mapping ranks back: [4, 1, 2, 3, 2]



#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

vector<int> findRanks(vector<int>& nums) {
    int n = nums.size();
    
    // Step 1: Copy the original array
    vector<int> sortedNums = nums;
    
    // Step 2: Sort the copied array
    sort(sortedNums.begin(), sortedNums.end());
    
    // Step 3: Assign ranks to each element
    unordered_map<int, int> rankMap;
    int rank = 1;
    
    for (int i = 0; i < n; i++) {
        if (rankMap.find(sortedNums[i]) == rankMap.end()) {
            rankMap[sortedNums[i]] = rank;
            rank++;
        }
    }
    
    // Step 4: Map ranks back to the original array
    vector<int> result(n);
    for (int i = 0; i < n; i++) {
        result[i] = rankMap[nums[i]];
    }
    
    return result;
}

int main() {
    vector<int> nums = {40, 10, 20, 30, 20};
    vector<int> ranks = findRanks(nums);
    
    for (int rank : ranks) {
        cout << rank << " ";
    }
    
    return 0;
}
