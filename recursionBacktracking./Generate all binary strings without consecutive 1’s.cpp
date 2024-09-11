Problem: Binary Strings of Length N with No Consecutive 1s
Problem Description:
Given an integer n, generate all binary strings of length n such that no two consecutive 1s appear.

For example:

For n = 3, valid binary strings include: 000, 001, 010, 100, 101.
Intuition:
The task is to generate binary strings of length n, but with a constraint: no two consecutive 1s can appear. This means we need to carefully decide when to place 1s in the binary string during construction.

Key points:

If the previous character is a 1, we cannot place another 1 immediately after it. So, we must place a 0 in that case.
If the previous character is a 0, we can freely place either a 0 or a 1.
We can use recursion to generate all binary strings, with conditions to ensure no two consecutive 1s appear.

Approach:
Base Case: When the length of the current string reaches n, add it to the result list.
Recursive Steps:
If the last character added was 0, we can add either 0 or 1 to the string.
If the last character added was 1, we can only add 0.
Dry Run with a Bigger Example for n = 4:
For n = 4, valid binary strings include:

yaml
Copy code
0000, 0001, 0010, 0100, 0101, 1000, 1001, 1010
Code Explanation:
cpp
Copy code
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
    // Helper function to generate the binary strings
    void solve(int n, string current, vector<string>& result, char lastChar) {
        // Base case: If the length of the current string is n, add it to the result
        if (current.length() == n) {
            result.push_back(current);
            return;
        }

        // Option 1: Always add '0' because it doesn't violate the constraint
        solve(n, current + '0', result, '0');

        // Option 2: Add '1' only if the last character wasn't '1' to avoid consecutive 1s
        if (lastChar != '1') {
            solve(n, current + '1', result, '1');
        }
    }

public:
    // Function to generate all binary strings of length n with no consecutive 1s
    vector<string> generateBinaryStrings(int n) {
        vector<string> result;
        solve(n, "", result, '0'); // Initial call with empty string
        return result;
    }
};

int main() {
    Solution sol;
    int n = 4; // Example for n = 4
    vector<string> result = sol.generateBinaryStrings(n);

    // Print all valid binary strings
    for (const string& str : result) {
        cout << str << endl;
    }
    return 0;
}
Code Explanation:
Helper Function (solve):

Parameters:
n: Target length of the binary string.
current: The current string being constructed.
result: Vector to store valid binary strings.
lastChar: Keeps track of the last character added to ensure we don’t add consecutive 1s.
Base Case: If the current string reaches the length n, add it to the result.
Recursive Cases:
Add 0: Always a valid option, regardless of what the last character was.
Add 1: Only valid if the last character wasn’t 1 (i.e., no consecutive 1s).
Public Function (generateBinaryStrings):

Initializes the recursion with an empty string and the last character set as 0 (arbitrary starting point).
Returns the list of all valid binary strings.
Dry Run for n = 4:
Let's walk through the recursion step by step for n = 4.

Initial call starts with current = "", lastChar = '0'.
We can add both 0 and 1 since the string is empty:
Add 0 → current = "0"
Add 0 → current = "00"
Add 0 → current = "000"
Add 0 → current = "0000" (Length 4, add to result)
Add 1 → current = "0001" (Length 4, add to result)
Add 1 → current = "001"
Add 0 → current = "0010" (Length 4, add to result)
Add 1 → current = "01"
Add 0 → current = "010"
Add 0 → current = "0100" (Length 4, add to result)
Add 1 → current = "0101" (Length 4, add to result)
Add 1 → current = "1"
Add 0 → current = "10"
Add 0 → current = "100"
Add 0 → current = "1000" (Length 4, add to result)
Add 1 → current = "1001" (Length 4, add to result)
Add 1 → current = "101"
Add 0 → current = "1010" (Length 4, add to result)
Output:
For n = 4, the output will be:

yaml
Copy code
0000
0001
0010
0100
0101
1000
1001
1010
Complexity Analysis:
Time Complexity:

For each position in the string, we have two choices: add 0 or add 1 (with the restriction on consecutive 1s). In the worst case, there are O(2^n) possible combinations of binary strings of length n.
The actual number of valid combinations is fewer than 2^n due to the consecutive 1 restriction, but the time complexity remains exponential: O(2^n).
Space Complexity:

Recursion depth: The maximum depth of the recursion is n, so the recursion stack uses O(n) space.
Result storage: The result vector will store all valid binary strings, which can take up O(2^n) space in the worst case.
