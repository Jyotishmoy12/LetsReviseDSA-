Problem: Two Sum with Duplicates
Objective:
Given an array of integers arr[] and a target integer target, find all unique pairs of elements in the array that sum up to the target. The array may contain duplicate values, and the output should only include unique pairs.

Approach
To solve this problem, we can use a hash map (or unordered map in C++) to keep track of the elements we've seen and their counts. Here's a step-by-step approach:

Use a Hash Map:

Traverse the array and store the count of each element in a hash map.
For each element, compute the complement needed to reach the target sum.
Check if this complement exists in the hash map.
To ensure uniqueness, we need to handle duplicates carefully.
Handle Duplicates:

If the complement is the same as the current element, ensure that there are at least two occurrences of that element.
Use a set to keep track of pairs we've already added to the result to ensure each pair is unique.


#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
using namespace std;

// Function to find all unique pairs that sum up to the target
vector<pair<int, int>> findUniquePairs(vector<int>& arr, int target) {
    unordered_map<int, int> freqMap;
    set<pair<int, int>> resultSet;

    // Count the frequency of each element in the array
    for (int num : arr) {
        freqMap[num]++;
    }

    // Find pairs
    for (int num : arr) {
        int complement = target - num;

        // Check if complement exists in the map
        if (freqMap.find(complement) != freqMap.end()) {
            // If num and complement are the same, ensure there are at least two occurrences
            if (num == complement && freqMap[num] > 1) {
                resultSet.insert({num, complement});
            } else if (num != complement && freqMap[complement] > 0) {
                resultSet.insert({min(num, complement), max(num, complement)});
            }
        }
    }

    // Convert set to vector
    vector<pair<int, int>> result(resultSet.begin(), resultSet.end());
    return result;
}

int main() {
    vector<int> arr = {1, 2, 3, 2, 4, 3, 5, 6};
    int target = 6;

    vector<pair<int, int>> pairs = findUniquePairs(arr, target);

    cout << "Unique pairs that sum up to " << target << " are:" << endl;
    for (const auto& p : pairs) {
        cout << "(" << p.first << ", " << p.second << ")" << endl;
    }

    return 0;
}
Test Case
Let's go through an example to see how the code works.

Example:

Input:
arr = {1, 2, 3, 2, 4, 3, 5, 6}, target = 6
Steps:

Build Frequency Map:

{1: 1, 2: 2, 3: 2, 4: 1, 5: 1, 6: 1}
Find Unique Pairs:

For num = 1, complement is 5. Found in the map, so add pair (1, 5).
For num = 2, complement is 4. Found in the map, so add pair (2, 4).
For num = 3, complement is 3. Since 3 appears more than once, add pair (3, 3) (ensuring unique handling).
For num = 4, complement is 2. Already considered.
For num = 5, complement is 1. Already considered.
For num = 6, complement is 0. Not in the map.
Output:

Unique pairs that sum up to 6 are:
scss
Copy code
(1, 5)
(2, 4)
(3, 3)
Complexity Analysis
Time Complexity: O(n), where n is the number of elements in the array. Building the frequency map takes O(n), and finding pairs also takes O(n) on average.

Space Complexity: O(n) for storing the frequency map and unique pairs.
