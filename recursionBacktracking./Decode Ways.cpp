Problem Explanation: Decode Ways
The problem is to determine how many ways a given string of digits can be decoded into letters, where '1' maps to 'A', '2' maps to 'B', ..., and '26' maps to 'Z'. The string contains only numeric characters.

For example:

"12" can be decoded as "AB" (1 → A, 2 → B) or "L" (12 → L), so there are 2 ways to decode it.
"226" can be decoded as "BBF", "VF", or "BZ" (2 → B, 2 → B, 6 → F; 22 → V, 6 → F; 2 → B, 26 → Z), so there are 3 ways to decode it.
Intuition
This problem is well-suited for a recursive approach or dynamic programming. The main idea is to process the string one or two digits at a time:

Consider the first digit (if valid, i.e., non-zero), and recursively process the rest of the string.
Consider the first two digits (if valid, i.e., between 10 and 26), and recursively process the rest of the string.
The base case occurs when we've processed all digits of the string (an empty string means one valid decoding).

Approach (Recursive with Memoization)
The recursive approach has overlapping subproblems, so we can improve its performance by using memoization to store the results of subproblems (avoiding recalculating them).

Dry Run Example: "226"
At position 0: The string is "226"
Take one digit (2 → B) and recurse on "26".
Take two digits (22 → V) and recurse on "6".
At position 1: The string is "26"
Take one digit (2 → B) and recurse on "6".
Take two digits (26 → Z) and recurse on an empty string.
At position 2: The string is "6"
Take one digit (6 → F) and recurse on an empty string.
At position 3: The string is empty, so return 1 (valid decoding).
From this, we can decode "226" in 3 different ways: "BBF", "BZ", and "VF".

C++ Code with Memoization
cpp
Copy code
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int decodeWays(string& s, int index, vector<int>& memo) {
        // Base case: If we've processed the whole string, it's a valid decoding.
        if (index == s.size()) return 1;
        
        // If the string starts with '0', it's not a valid decoding.
        if (s[index] == '0') return 0;
        
        // If we've already computed the result for this index, return it.
        if (memo[index] != -1) return memo[index];
        
        // Decode one digit
        int result = decodeWays(s, index + 1, memo);
        
        // Decode two digits if it's a valid number between 10 and 26
        if (index + 1 < s.size() && (s[index] == '1' || (s[index] == '2' && s[index + 1] <= '6'))) {
            result += decodeWays(s, index + 2, memo);
        }
        
        // Memoize the result
        memo[index] = result;
        return result;
    }

    int numDecodings(string s) {
        if (s.empty()) return 0;
        
        // Memoization table to store results for each index
        vector<int> memo(s.size(), -1);
        
        // Start decoding from index 0
        return decodeWays(s, 0, memo);
    }
};
Code Explanation (Step by Step)
Base Case: If index reaches the size of the string, it means we have decoded the entire string, so we return 1 as one valid decoding is found.
Invalid Case: If the current character is '0', we return 0 because '0' cannot be decoded on its own.
Memoization Check: Before processing the current substring, we check if the result has already been computed for this index. If it has, we return the memoized result to avoid redundant calculations.
Recursive Case (Single Digit): We attempt to decode the current digit (s[index]), which is valid if it's non-zero. We then recursively decode the remaining substring (index + 1).
Recursive Case (Two Digits): If the next two characters form a valid number between 10 and 26, we attempt to decode them as a pair and recursively decode the rest (index + 2).
Memoization: After calculating the result for the current index, we store it in the memoization table (memo[index] = result) and return the result.
Dry Run of "226":
Start at index 0 ("226"):
Decode "2" → Recurse on "26".
Decode "22" → Recurse on "6".
Index 1 ("26"):
Decode "2" → Recurse on "6".
Decode "26" → Recurse on an empty string (valid).
Index 2 ("6"):
Decode "6" → Recurse on an empty string (valid).
Index 3 (""):
Return 1 for both recursions from index 2.
Time Complexity:
Time Complexity: 
𝑂
(
𝑛
)
O(n), where 
𝑛
n is the length of the string s. Each index is visited once, and results are stored in the memo array.
Space Complexity: 
𝑂
(
𝑛
)
O(n) due to the recursion stack and the memoization array memo that stores the results for each index.
Conclusion:
The recursive approach with memoization efficiently solves the problem by breaking it down into subproblems, ensuring that each subproblem is only solved once. This helps avoid redundant computations, leading to a time complexity of 
𝑂
(
𝑛
)
O(n), which is optimal for this type of problem.
