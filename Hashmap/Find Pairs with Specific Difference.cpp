Problem: Find Pairs with Specific Difference
Objective: Given an array of integers arr and an integer k, find all unique pairs (a, b) in the array such that a - b = k.

Approach
To solve this problem efficiently, we can use a hash map (or unordered map in C++) to keep track of the elements we have seen as we iterate through the array. The key idea is to look for the complement values a = b + k or b = a + k in the array.

Steps
Initialize Variables:

resultPairs: A set to store unique pairs (a, b) that satisfy the condition a - b = k.
seen: A hash map to keep track of elements we encounter as we iterate through the array.
Iterate Through the Array:

For each element a in the array, check if a - k (to find b) exists in the hash map. If it does, add the pair (a, a - k) to resultPairs.
Similarly, check if a + k (to find b) exists in the hash map. If it does, add the pair (a + k, a) to resultPairs.
Add the current element a to the hash map for future lookups.
Return the resultPairs set.


  #include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
using namespace std;

vector<pair<int, int>> findPairsWithDifference(vector<int>& arr, int k) {
    unordered_set<pair<int, int>, hash_pair> resultPairs;
    unordered_map<int, bool> seen;

    for (int a : arr) {
        // Check for a pair (a, b) where a - b = k
        if (seen.find(a - k) != seen.end()) {
            resultPairs.insert({a, a - k});
        }
        // Check for a pair (b, a) where b - a = k
        if (seen.find(a + k) != seen.end()) {
            resultPairs.insert({a + k, a});
        }
        // Add the current element to the map
        seen[a] = true;
    }

    // Convert the set to a vector of pairs
    return vector<pair<int, int>>(resultPairs.begin(), resultPairs.end());
}

int main() {
    vector<int> arr = {1, 5, 2, 2, 2, 5, 7, 8, 3};
    int k = 3;

    vector<pair<int, int>> result = findPairsWithDifference(arr, k);
    
    cout << "Pairs with difference " << k << " are:" << endl;
    for (auto& p : result) {
        cout << "(" << p.first << ", " << p.second << ")" << endl;
    }

    return 0;
}


Test Case:

Input: arr = {1, 5, 2, 2, 2, 5, 7, 8, 3}, k = 3
Output: Pairs with difference 3 are: (5, 2), (7, 4), (8, 5)
Steps:

Initialization:

resultPairs = {} (an empty set)
seen = {} (an empty map)
Iteration Through Array:

For a = 1:

1 - 3 = -2 (not in seen)
1 + 3 = 4 (not in seen)
Update seen: {1: true}
For a = 5:

5 - 3 = 2 (not in seen)
5 + 3 = 8 (not in seen)
Update seen: {1: true, 5: true}
For a = 2:

2 - 3 = -1 (not in seen)
2 + 3 = 5 (in seen), so add pair (5, 2) to resultPairs
Update seen: {1: true, 5: true, 2: true}
For a = 7:

7 - 3 = 4 (not in seen)
7 + 3 = 10 (not in seen)
Update seen: {1: true, 5: true, 2: true, 7: true}
For a = 8:

8 - 3 = 5 (in seen), so add pair (8, 5) to resultPairs
8 + 3 = 11 (not in seen)
Update seen: {1: true, 5: true, 2: true, 7: true, 8: true}
Continue this process for the remaining elements, though no new pairs will be found.

Final Result:

The pairs found with the difference of 3 are (5, 2), (7, 4), (8, 5).
Handling Duplicates
The algorithm handles duplicates by:

Using a hash set (resultPairs) to store the pairs, which inherently prevents duplicate pairs from being added.
Complexity Analysis
Time Complexity: O(n), where n is the number of elements in the array. Each element is processed once, and hash map operations are average-case constant time.
Space Complexity: O(n), for storing elements in the hash map.

  
