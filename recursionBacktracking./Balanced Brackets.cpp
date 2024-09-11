Problem: Balanced Brackets
Problem Description:
Given n pairs of brackets ((), [], {}), generate all possible valid combinations of balanced brackets. For example, if n = 2, the output could include combinations like "()[]", "([])", "{}()", etc.

Intuition:
This problem is a generalization of the "Generate Parentheses" problem, where instead of a single type of parentheses (), we have three types of brackets:

Round brackets ()
Square brackets []
Curly brackets {}
The constraints remain the same:

Every opening bracket ((, [, {) must have a corresponding closing bracket (), ], }).
The order of brackets must be valid, meaning no closing bracket should appear before its corresponding opening bracket.
Key Insights:

Similar to the parentheses problem, the recursion will track how many opening and closing brackets are left for each type.
At every step, we can add an opening bracket as long as there are some left to place, and a closing bracket can only be placed if it has a matching opening bracket already in the string.
Approach:
We will use recursion and backtracking:

Base Case: If all types of brackets (round, square, curly) have been placed correctly, we append the result.
Recursive Steps:
Add any type of opening bracket if we still have one left.
Add a closing bracket if the number of closing brackets is greater than the number of opening brackets for that type.
This ensures that only valid sequences are generated.

Dry Run Example for n = 1:
For n = 1, we have one pair of (), [], and {} to use.

Start with an empty string "".
Add any type of opening bracket. For simplicity, let’s say we add (.
Now we need to balance it by adding a closing ).
Similarly, we try adding the other types of brackets, ensuring that no closing bracket is added before its corresponding opening bracket.
Code Explanation:
cpp
Copy code
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
    // Helper function to recursively generate valid combinations
    void solve(int openRound, int closeRound, 
               int openSquare, int closeSquare, 
               int openCurly, int closeCurly, 
               string current, vector<string>& result) {
        // Base case: if no brackets are left to add, the string is complete
        if (openRound == 0 && closeRound == 0 && 
            openSquare == 0 && closeSquare == 0 && 
            openCurly == 0 && closeCurly == 0) {
            result.push_back(current);
            return;
        }

        // Try adding an opening round bracket '('
        if (openRound > 0) {
            solve(openRound - 1, closeRound, openSquare, closeSquare, openCurly, closeCurly, current + '(', result);
        }

        // Try adding a closing round bracket ')'
        if (closeRound > openRound) {
            solve(openRound, closeRound - 1, openSquare, closeSquare, openCurly, closeCurly, current + ')', result);
        }

        // Try adding an opening square bracket '['
        if (openSquare > 0) {
            solve(openRound, closeRound, openSquare - 1, closeSquare, openCurly, closeCurly, current + '[', result);
        }

        // Try adding a closing square bracket ']'
        if (closeSquare > openSquare) {
            solve(openRound, closeRound, openSquare, closeSquare - 1, openCurly, closeCurly, current + ']', result);
        }

        // Try adding an opening curly bracket '{'
        if (openCurly > 0) {
            solve(openRound, closeRound, openSquare, closeSquare, openCurly - 1, closeCurly, current + '{', result);
        }

        // Try adding a closing curly bracket '}'
        if (closeCurly > openCurly) {
            solve(openRound, closeRound, openSquare, closeSquare, openCurly, closeCurly - 1, current + '}', result);
        }
    }

public:
    vector<string> generateBalancedBrackets(int n) {
        vector<string> result;
        // Initially we have n pairs of each type of bracket
        solve(n, n, n, n, n, n, "", result);
        return result;
    }
};

int main() {
    Solution sol;
    int n = 2; // Number of bracket pairs
    vector<string> result = sol.generateBalancedBrackets(n);

    // Print all valid combinations
    for (const string& str : result) {
        cout << str << endl;
    }
    return 0;
}
Code Explanation:
Helper Function (solve):

Parameters:
openRound, closeRound: Number of remaining open and close round brackets ().
openSquare, closeSquare: Number of remaining open and close square brackets [].
openCurly, closeCurly: Number of remaining open and close curly brackets {}.
current: The current string of brackets being formed.
result: Vector that stores all valid combinations of brackets.
Base Case: If all bracket counts are zero, the current string is a valid combination, so we add it to result.
Recursive Cases: For each type of bracket (round, square, curly), try adding an opening or closing bracket if the respective counts allow it. We ensure that we never add a closing bracket without first adding its corresponding opening bracket.
Public Function (generateBalancedBrackets):

Initializes the recursion by calling solve with n pairs of each type of bracket.
Returns the list of valid combinations.
Dry Run:
For n = 1:

Start with an empty string "".
Add an opening round bracket '('. Now openRound = 0, closeRound = 1.
Add a closing round bracket ')'. Now openRound = 0, closeRound = 0.
Add an opening square bracket '['. Now openSquare = 0, closeSquare = 1.
Add a closing square bracket ']'. Now openSquare = 0, closeSquare = 0.
Add an opening curly bracket '{'. Now openCurly = 0, closeCurly = 1.
Add a closing curly bracket '}'. Now openCurly = 0, closeCurly = 0.
Result: "()[]{}"

Complexity Analysis:
Time Complexity:
The total number of valid combinations depends on the number of bracket pairs n. The time complexity is exponential, similar to the "Generate Parentheses" problem.
The number of valid combinations is roughly proportional to O(2^(3n)) since there are 3n positions to fill, and each position can have one of two possible choices: opening or closing.
Space Complexity:
The space complexity is O(3n) due to the recursion depth and the space required to store the current string current. Additionally, the result vector will store all valid combinations, which contributes to the space complexity.
