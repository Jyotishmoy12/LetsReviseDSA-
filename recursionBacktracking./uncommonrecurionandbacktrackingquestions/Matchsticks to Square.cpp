Problem: Matchsticks to Square
Problem Description:
You are given an array of matchsticks, where each matchstick has a positive integer length. You need to determine if you can use all the matchsticks to form a square. Each matchstick must be used exactly once.

Intuition:
At first glance, this problem might seem like a greedy problem where we try to place the largest matchsticks first to form the sides of the square. However, this approach doesn't always lead to a solution because the arrangement of matchsticks can vary, and their lengths might not allow forming equal sides when placed greedily.

The problem is fundamentally about partitioning the array of matchsticks into four subsets (the four sides of the square) where the sum of each subset equals the target side length. This is similar to the subset sum problem, but with the added constraint that there are exactly four subsets, and each must sum to the same value.

This is where recursion and backtracking come into play. We need to explore all possible ways to assign matchsticks to the four sides, backtracking when we find that a particular assignment doesn't lead to a solution.

Key Points:
Target Side Length: The sum of all matchsticks divided by 4 (since a square has four equal sides).
Constraints:
Each side must sum up to the target length.
Each matchstick must be used exactly once.
Approach:
Use recursion to try placing each matchstick on one of the four sides.
Backtrack if a matchstick doesn't fit on a side.
Prune paths that cannot possibly lead to a solution (optimization).
Example:
Let's consider an example to illustrate the approach.

Example:

Input: [1, 1, 2, 2, 2]
Total Length: 1 + 1 + 2 + 2 + 2 = 8
Target Side Length: 8 / 4 = 2
We need to partition the matchsticks into four groups, each summing to 2.

Possible grouping:

Side 1: 1 + 1 = 2
Side 2: 2 = 2
Side 3: 2 = 2
Side 4: 2 = 2
Result: It's possible to form a square with these matchsticks.

Detailed Approach:
Edge Cases:

If there are less than 4 matchsticks, it's impossible to form a square.
If the total length of matchsticks is not divisible by 4, return false.
Sorting:

Sort the matchsticks in descending order to optimize (place longer matchsticks first).
This helps in failing faster when a matchstick doesn't fit, reducing recursion depth.
Recursion and Backtracking:

Use an array sides[4] to keep track of the current length of each side.
Try to place each matchstick on one of the four sides.
At each step, for the current matchstick, try adding it to a side if it doesn't exceed the target length.
If a side reaches the target length, proceed to the next matchstick.
If we reach the end of the matchsticks array and all sides are equal to the target length, return true.
Backtrack when a matchstick cannot be placed on any side without exceeding the target length.
Code Implementation:
cpp
Copy code
#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    bool makesquare(std::vector<int>& matchsticks) {
        int totalLength = 0;
        for (int stick : matchsticks) totalLength += stick;

        if (matchsticks.size() < 4 || totalLength % 4 != 0) return false;

        int sideLength = totalLength / 4;
        std::sort(matchsticks.rbegin(), matchsticks.rend()); // Sort in descending order

        std::vector<int> sides(4, 0);
        return dfs(matchsticks, sides, 0, sideLength);
    }

private:
    bool dfs(const std::vector<int>& matchsticks, std::vector<int>& sides, int index, int target) {
        if (index == matchsticks.size()) {
            // Check if all sides are equal to target
            return sides[0] == target && sides[1] == target &&
                   sides[2] == target && sides[3] == target;
        }

        int stick = matchsticks[index];
        for (int i = 0; i < 4; ++i) {
            // If adding stick to side i doesn't exceed target
            if (sides[i] + stick <= target) {
                sides[i] += stick;
                if (dfs(matchsticks, sides, index + 1, target)) return true;
                sides[i] -= stick; // Backtrack
            }

            // Optimization: If a side is empty or after backtracking, the side length remains the same,
            // we can skip trying other empty sides to avoid duplicate work.
            if (sides[i] == 0 || sides[i] + stick == target) break;
        }

        return false;
    }
};
Code Explanation:
makesquare Function:

Calculates the total length and checks for early termination conditions.
Sorts the matchsticks in descending order for optimization.
Initializes the sides vector to keep track of the current length of each side.
Calls the recursive dfs function starting from index 0.
dfs Function:

Base Case: If we've considered all matchsticks (index == matchsticks.size()), check if all sides are equal to the target length.
Recursive Case:
For each side, try to place the current matchstick if it doesn't exceed the target length.
If successful, recursively call dfs with the next index.
If the recursive call returns true, propagate true upwards.
Backtrack by removing the matchstick from the side (sides[i] -= stick).
Optimization:
If a side is empty (sides[i] == 0), and placing the current stick didn't fit, there's no point in trying to place it on another empty side (since all empty sides are equivalent).
If the side reaches the target length after placing the stick, we can break out of the loop to avoid redundant work.
Dry Run with Code:
Let's dry run the code with the example [1, 1, 2, 2, 2].

Initial Setup:

totalLength = 8
sideLength = 2
matchsticks sorted in descending order: [2, 2, 2, 1, 1]
sides = [0, 0, 0, 0]
Start dfs with index = 0
Recursive Calls:

Index 0 (Stick = 2):

Try adding to side 0:
sides = [2, 0, 0, 0]
Recursive call with index = 1
Index 1 (Stick = 2):

Try adding to side 0:
sides[0] + 2 = 4 (exceeds sideLength), cannot add
Try adding to side 1:
sides = [2, 2, 0, 0]
Recursive call with index = 2
Index 2 (Stick = 2):

Try adding to side 0:
sides[0] + 2 = 4 (exceeds sideLength), cannot add
Try adding to side 1:
sides[1] + 2 = 4 (exceeds sideLength), cannot add
Try adding to side 2:
sides = [2, 2, 2, 0]
Recursive call with index = 3
Index 3 (Stick = 1):

Try adding to side 0:
sides[0] + 1 = 3 (exceeds sideLength), cannot add
Try adding to side 1:
sides[1] + 1 = 3 (exceeds sideLength), cannot add
Try adding to side 2:
sides[2] + 1 = 3 (exceeds sideLength), cannot add
Try adding to side 3:
sides = [2, 2, 2, 1]
Recursive call with index = 4
Index 4 (Stick = 1):

Try adding to side 0:
sides[0] + 1 = 3 (exceeds sideLength), cannot add
Try adding to side 1:
sides[1] + 1 = 3 (exceeds sideLength), cannot add
Try adding to side 2:
sides[2] + 1 = 3 (exceeds sideLength), cannot add
Try adding to side 3:
sides[3] + 1 = 2 (fits)
sides = [2, 2, 2, 2]
Recursive call with index = 5
Index 5:

index == matchsticks.size()
Check if all sides are equal to sideLength:
All sides are 2, which equals sideLength
Return true
The true value propagates back through all recursive calls, leading the initial makesquare function to return true.
Complexity Analysis:
Time Complexity:

The number of recursive calls can be up to 
4
𝑁
4 
N
 , where 
𝑁
N is the number of matchsticks, since at each step we have up to 4 choices (placing the stick on one of the 4 sides).
However, optimizations reduce the number of calls significantly.
Sorting helps by trying larger matchsticks first, which helps in failing faster.
The worst-case time complexity is still exponential, 
𝑂
(
4
𝑁
)
O(4 
N
 ), but in practice, the optimizations make it acceptable for the constraints (typically 
𝑁
≤
15
N≤15).
Space Complexity:

The recursion stack can go up to 
𝑂
(
𝑁
)
O(N) deep.
The sides array uses 
𝑂
(
1
)
O(1) space.
Total space complexity is 
𝑂
(
𝑁
)
O(N).
