Problem Statement
You are given a string s, and your task is to count the number of palindromic substrings in it. A substring is a contiguous sequence of characters within the string, and a substring is palindromic if it reads the same backward as forward.

Input:

A string s of length n (1 ≤ n ≤ 1000).
Output:

An integer representing the count of palindromic substrings.
Test Case Explanation
Input: "abc"
Output: 3
Explanation: The palindromic substrings are "a", "b", and "c".

Input: "aaa"
Output: 6
Explanation: The palindromic substrings are "a", "a", "a", "aa", "aa", and "aaa".

Intuition
This is a Dynamic Programming (DP) problem because:

It has overlapping subproblems: A substring's palindromic status can depend on smaller substrings.
It has optimal substructure: If the inner substring is palindromic, we can extend it to include matching characters at both ends.
To determine if a substring s[i:j] is a palindrome:

If i == j, it is a single character and thus a palindrome.
If j - i == 1, check if s[i] == s[j].
If j - i > 1, check if s[i] == s[j] and the inner substring s[i+1:j-1] is also a palindrome.
Approach
Use a DP table dp[i][j] where:
dp[i][j] is true if the substring s[i:j+1] is palindromic.
Iterate over all possible substrings in increasing length order.
For each substring, update dp[i][j] based on the rules:
If the substring has length 1, mark it as a palindrome.
If the substring has length 2, check if both characters are equal.
For longer substrings, check if the first and last characters match and the inner substring is palindromic.
Count all substrings where dp[i][j] is true.
Code (in C++)
cpp
Copy code
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int countSubstrings(string s) {
        int n = s.length();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        int count = 0;

        // Fill the DP table
        for (int len = 1; len <= n; len++) { // Length of the substring
            for (int i = 0; i <= n - len; i++) {
                int j = i + len - 1; // End of the substring
                if (len == 1) {
                    dp[i][j] = true; // Single character is always a palindrome
                } else if (len == 2) {
                    dp[i][j] = (s[i] == s[j]); // Two characters are palindromic if they match
                } else {
                    dp[i][j] = (s[i] == s[j] && dp[i + 1][j - 1]);
                }
                if (dp[i][j]) count++;
            }
        }
        return count;
    }
};
Dry Run (Step-by-Step Explanation with Test Case)
Input: "aaa"

Step 1: Initialize a 3x3 DP table filled with false and set count = 0.

arduino
Copy code
dp = [[false, false, false],
      [false, false, false],
      [false, false, false]]
Step 2: Process substrings of length 1.

i = 0, j = 0: Mark dp[0][0] = true, count = 1.
i = 1, j = 1: Mark dp[1][1] = true, count = 2.
i = 2, j = 2: Mark dp[2][2] = true, count = 3.
Updated DP table:

arduino
Copy code
dp = [[true, false, false],
      [false, true, false],
      [false, false, true]]
Step 3: Process substrings of length 2.

i = 0, j = 1: s[0] == s[1], mark dp[0][1] = true, count = 4.
i = 1, j = 2: s[1] == s[2], mark dp[1][2] = true, count = 5.
Updated DP table:

arduino
Copy code
dp = [[true, true, false],
      [false, true, true],
      [false, false, true]]
Step 4: Process substrings of length 3.

i = 0, j = 2: s[0] == s[2] and dp[1][1] = true, mark dp[0][2] = true, count = 6.
Final DP table:

arduino
Copy code
dp = [[true, true, true],
      [false, true, true],
      [false, false, true]]
Output: 6

Code Explanation (Line by Line)
vector<vector<bool>> dp(n, vector<bool>(n, false));: Initialize a 2D table to store whether substrings are palindromic.
int count = 0;: Variable to store the total count of palindromic substrings.
for (int len = 1; len <= n; len++): Loop over all possible substring lengths.
for (int i = 0; i <= n - len; i++): Loop over all starting indices for the current length.
int j = i + len - 1;: Calculate the ending index of the substring.
if (len == 1) dp[i][j] = true;: Single-character substrings are palindromes.
else if (len == 2) dp[i][j] = (s[i] == s[j]);: Two-character substrings are palindromes if both characters match.
else dp[i][j] = (s[i] == s[j] && dp[i + 1][j - 1]);: For longer substrings, check both ends and the inner substring.
if (dp[i][j]) count++;: Increment count if the substring is palindromic.
Complexity Analysis
Time Complexity:

Outer loop over substring lengths: O(n).
Inner loop over starting indices: O(n).
For each substring, checking palindromic status: O(1).
Overall: O(n^2).
Space Complexity:

DP table stores n * n entries.
Overall: O(n^2).
