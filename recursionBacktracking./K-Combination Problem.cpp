Problem: K-Combination Problem
Problem Statement:

Given an array [1,2,3,4] and an integer k, find all possible combinations of k elements from the array.

Approach:

To solve this problem, we use backtracking to recursively choose elements from the array to form combinations of length k. We'll ensure each combination is unique and of the desired length.

Key Intuition:
Recursive Combination Generation: Use recursion to build combinations. For each element in the array, decide whether to include it in the current combination or not.
Backtracking: After exploring one possible combination, backtrack to explore other possibilities.
Dry Run with Example:
Let's dry run the algorithm with the array [1,2,3,4] and k = 2.

Initial Call: combine([1,2,3,4], 2)

Call to combineHelper([1,2,3,4], 0, [], 2, result)
Dry Run:

Start Index = 0, Current Combination = []
Include element 1: [] → [1]
Recursive Call: combineHelper([1,2,3,4], 1, [1], 1, result)
Start Index = 1, Current Combination = [1]
Include element 2: [1] → [1, 2]
Recursive Call: combineHelper([1,2,3,4], 2, [1, 2], 0, result)
Base Case Reached (k = 0): Add [1, 2] to results.
Backtrack: Remove element 2, restore [1].
Include element 3: [1] → [1, 3]
Recursive Call: combineHelper([1,2,3,4], 3, [1, 3], 0, result)
Base Case Reached (k = 0): Add [1, 3] to results.
Backtrack: Remove element 3, restore [1].
Include element 4: [1] → [1, 4]
Recursive Call: combineHelper([1,2,3,4], 4, [1, 4], 0, result)
Base Case Reached (k = 0): Add [1, 4] to results.
Backtrack: Remove element 4, restore [1].
Backtrack: Remove element 1, restore [].
Include element 2: [] → [2]
Recursive Call: combineHelper([1,2,3,4], 2, [2], 1, result)
Start Index = 2, Current Combination = [2]
Include element 3: [2] → [2, 3]
Recursive Call: combineHelper([1,2,3,4], 3, [2, 3], 0, result)
Base Case Reached (k = 0): Add [2, 3] to results.
Backtrack: Remove element 3, restore [2].
Include element 4: [2] → [2, 4]
Recursive Call: combineHelper([1,2,3,4], 4, [2, 4], 0, result)
Base Case Reached (k = 0): Add [2, 4] to results.
Backtrack: Remove element 4, restore [2].
Backtrack: Remove element 2, restore [].
Include element 3: [] → [3]
Recursive Call: combineHelper([1,2,3,4], 3, [3], 1, result)
Start Index = 3, Current Combination = [3]
Include element 4: [3] → [3, 4]
Recursive Call: combineHelper([1,2,3,4], 4, [3, 4], 0, result)
Base Case Reached (k = 0): Add [3, 4] to results.
Backtrack: Remove element 4, restore [3].
Backtrack: Remove element 3, restore [].
Include element 4: [] → [4]
Recursive Call: combineHelper([1,2,3,4], 4, [4], 1, result)
Start Index = 4, Current Combination = [4]
No more elements to include (end of array).
Backtrack: Remove element 4, restore [].
Final Results:

The combinations generated and added to the results are:
[1, 2]
[1, 3]
[1, 4]
[2, 3]
[2, 4]
[3, 4]
Code in C++:
cpp
Copy code
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // Helper function to generate combinations
    void combineHelper(vector<int>& nums, int start, vector<int>& current, int k, vector<vector<int>>& result) {
        // Base case: if the combination is of the desired length
        if (k == 0) {
            result.push_back(current);
            return;
        }

        // Recursive case: iterate through the array and include elements in the combination
        for (int i = start; i < nums.size(); ++i) {
            current.push_back(nums[i]);            // Include element nums[i]
            combineHelper(nums, i + 1, current, k - 1, result); // Recur with next index
            current.pop_back();                     // Backtrack: remove the last element
        }
    }

    // Main function to find all combinations
    vector<vector<int>> combine(vector<int>& nums, int k) {
        vector<vector<int>> result;
        vector<int> current;
        combineHelper(nums, 0, current, k, result);
        return result;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 3, 4}; // Example input
    int k = 2; // Number of elements in each combination
    vector<vector<int>> result = sol.combine(nums, k);

    cout << "Combinations:\n";
    for (const auto& combination : result) {
        cout << "[ ";
        for (const auto& num : combination) {
            cout << num << " ";
        }
        cout << "]\n";
    }
    return 0;
}
Code Explanation:
combineHelper Function:

Base Case: When k reaches 0, the current combination has the desired length, so add it to result.
Recursive Case: For each index from start to the end of the array, include the element at the current index in the combination, recursively generate combinations with the remaining elements, and then backtrack by removing the last included element.
combine Function:

Initializes the result vector and calls combineHelper to start generating combinations.
Complexity Analysis:
Time Complexity:

Generating combinations involves iterating through the array and building combinations, which is combinatorial in nature.
For n elements and combinations of length k, the number of combinations is C(n, k), where C(n, k) is the binomial coefficient.
Each combination requires O(k) operations to build.
Overall time complexity is O(C(n, k) * k).
Space Complexity:

Storage Complexity: Storing all combinations requires O(C(n, k) * k) space.
Recursion Stack: The depth of recursion is O(k).
