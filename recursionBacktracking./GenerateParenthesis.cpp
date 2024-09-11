Recursive Approach Explained:
To solve this problem, the recursive function solve(int open, int close, string op, vector<string>& v) works as follows:

Base Case: If both open == 0 and close == 0, it means we have used all n opening and n closing brackets. We then add the generated string op to the result vector v.
Recursive Steps:
Adding an opening bracket (:
You can add an opening bracket as long as open > 0. After adding an opening bracket, reduce open by 1 and recursively call the function.
Adding a closing bracket ):
You can add a closing bracket only if close > open. This ensures that a closing bracket is added only when there's a corresponding unmatched opening bracket available.
Key Intuition:
You should never add a closing parenthesis ) if there isn't an unmatched opening parenthesis ( to pair with it.
The function continues branching out by adding either ( or ) until all possibilities are explored.
Dry Run Example:
Let's dry run the code for n = 2 (i.e., we need 2 pairs of parentheses):

Initial Call:

open = 2, close = 2, op = ""
First Recursive Call (Add ():

Add an opening bracket (: op = "("
open = 1, close = 2
Second Recursive Call (Add another ():

Add another opening bracket (: op = "(("
open = 0, close = 2
Third Recursive Call (Add )):

Now we cannot add more ( because open == 0.
Add a closing bracket ): op = "(())"
open = 0, close = 1
Fourth Recursive Call (Add )):

Add another closing bracket ): op = "(())"
open = 0, close = 0
Base case is hit: We add "(())" to the vector.
Backtracking to Second Recursive Call:

After generating "(())", we go back to the second recursive call with op = "(" and try adding a closing bracket ) (because open < close).
Add a closing bracket ): op = "()"
open = 1, close = 1
Continue from here (Add ():

Add another opening bracket (: op = "()("
open = 0, close = 1
Continue from here (Add )):

Add a closing bracket ): op = "()()"
open = 0, close = 0
Base case is hit: We add "()()" to the vector.
The final result is ["(())", "()()"].

Dry Run Table for n = 2:
Recursive Step	open	close	op	Explanation
Start	2	2	""	Initial state
Add (	1	2	"("	Added opening bracket
Add (	0	2	"(("	Added another opening bracket
Add )	0	1	"(()"	Added closing bracket
Add )	0	0	"(())"	Added final closing bracket, base case hit
Backtrack	1	2	"("	Backtrack and add closing bracket
Add )	1	1	"()"	Added closing bracket
Add (	0	1	"()("	Added opening bracket
Add )	0	0	"()()"	Added final closing bracket, base case hit
Final Result:
For n = 2, the valid combinations are:

(())
()()
These are returned by the generateParenthesis(int n) function.

Time Complexity:
The time complexity of this solution is O(2^n), as each valid string is built up one character at a time and there are exponentially many valid combinations of parentheses.

Code Review:
cpp
Copy code
class Solution {
    void solve(int open, int close, string op, vector<string>&v){
        // Base case: if no open and close brackets left, add the generated string to the result
        if(open==0 && close==0){
            v.push_back(op);
            return;
        }
        // Add opening brackets as long as there are open brackets remaining
        if(open != 0){
            string op1 = op; 
            op1.push_back('(');
            solve(open-1, close, op1, v);  // Recur after using an opening bracket
        }
        // Add closing brackets if there are more close brackets remaining than open brackets
        if(open < close){
            string op2 = op;
            op2.push_back(')');
            solve(open, close-1, op2, v);  // Recur after using a closing bracket
        }
        return;
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> v;       // Result vector
        int open = n;           // Number of opening brackets
        int close = n;          // Number of closing brackets
        string op = "";         // Current string being generated
        solve(open, close, op, v);  // Initial call to recursive function
        return v;               // Return the result
    }
};
