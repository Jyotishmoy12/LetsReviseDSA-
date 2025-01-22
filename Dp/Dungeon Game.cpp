Dungeon Game Solution Following the Template
1. Problem Statement in Detail
You are given a 2D grid (dungeon) where each cell contains an integer:

Positive values represent health gain.
Negative values represent health loss.
Zero indicates no gain or loss.
The knight starts at the top-left corner 
(
0
,
0
)
(0,0) and must reach the bottom-right corner 
(
𝑚
−
1
,
𝑛
−
1
)
(m−1,n−1). At any cell, the knight can only move right or down. The goal is to determine the minimum initial health required to ensure the knight survives until the destination with at least 1 health at every step.

2. Test Case Explanation
Input Dungeon Grid:

dungeon
=
[
−
2
−
3
3
−
5
−
10
1
10
30
−
5
]
dungeon= 
​
  
−2
−5
10
​
  
−3
−10
30
​
  
3
1
−5
​
  
​
 
Output: 7
Explanation:

The knight starts at 
(
0
,
0
)
(0,0) with health 7.
The knight takes the path:
(
0
,
0
)
→
(
1
,
0
)
→
(
2
,
0
)
→
(
2
,
1
)
→
(
2
,
2
)
(0,0)→(1,0)→(2,0)→(2,1)→(2,2).
At every step, the health is sufficient to survive until the destination.
3. Intuition
This is a dynamic programming problem because:

The solution at a cell depends on the solutions of cells to the right and down of it.
We aim to minimize the initial health required by working backwards from the destination.
Why backward traversal?
Starting from the destination, we can calculate the minimum health required at each cell to survive. This avoids recalculating paths multiple times.

4. Approach in Detail (Step by Step)
Define a DP table 
𝑑
𝑝
[
𝑚
]
[
𝑛
]
dp[m][n], where 
𝑑
𝑝
[
𝑖
]
[
𝑗
]
dp[i][j] represents the minimum health needed to survive starting at cell 
(
𝑖
,
𝑗
)
(i,j) to reach the destination.
Base case:
At the destination 
(
𝑚
−
1
,
𝑛
−
1
)
(m−1,n−1):
𝑑
𝑝
[
𝑚
−
1
]
[
𝑛
−
1
]
=
max
⁡
(
1
,
1
−
dungeon
[
𝑚
−
1
]
[
𝑛
−
1
]
)
dp[m−1][n−1]=max(1,1−dungeon[m−1][n−1]).
This ensures the knight survives with at least 1 health.
Recurrence relation for other cells:
From cell 
(
𝑖
,
𝑗
)
(i,j), the knight can move right or down. Hence:
𝑑
𝑝
[
𝑖
]
[
𝑗
]
=
max
⁡
(
1
,
min
⁡
(
𝑑
𝑝
[
𝑖
+
1
]
[
𝑗
]
,
𝑑
𝑝
[
𝑖
]
[
𝑗
+
1
]
)
−
dungeon
[
𝑖
]
[
𝑗
]
)
dp[i][j]=max(1,min(dp[i+1][j],dp[i][j+1])−dungeon[i][j])
𝑑
𝑝
[
𝑖
+
1
]
[
𝑗
]
dp[i+1][j]: Health required moving down.
𝑑
𝑝
[
𝑖
]
[
𝑗
+
1
]
dp[i][j+1]: Health required moving right.
Subtract the value in 
dungeon
[
𝑖
]
[
𝑗
]
dungeon[i][j] because it affects the knight's health.
Take 
max
⁡
(
1
,
…
 
)
max(1,…) to ensure health doesn't drop below 1.
Start filling 
𝑑
𝑝
dp from the bottom-right corner to the top-left.
The answer will be 
𝑑
𝑝
[
0
]
[
0
]
dp[0][0], the minimum initial health needed at the start.
5. Code (C++)
cpp
Copy
Edit
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size();
        int n = dungeon[0].size();

        // DP table to store minimum health needed
        vector<vector<int>> dp(m, vector<int>(n, 0));

        // Base case for bottom-right corner
        dp[m-1][n-1] = max(1, 1 - dungeon[m-1][n-1]);

        // Fill the last row (right to left)
        for (int i = m - 2; i >= 0; --i) {
            dp[i][n-1] = max(1, dp[i+1][n-1] - dungeon[i][n-1]);
        }

        // Fill the last column (bottom to top)
        for (int j = n - 2; j >= 0; --j) {
            dp[m-1][j] = max(1, dp[m-1][j+1] - dungeon[m-1][j]);
        }

        // Fill the rest of the DP table (bottom-right to top-left)
        for (int i = m - 2; i >= 0; --i) {
            for (int j = n - 2; j >= 0; --j) {
                dp[i][j] = max(1, min(dp[i+1][j], dp[i][j+1]) - dungeon[i][j]);
            }
        }

        // Minimum health needed at the start
        return dp[0][0];
    }
};
6. Dry Run (Step by Step)
Input:

dungeon
=
[
−
2
−
3
3
−
5
−
10
1
10
30
−
5
]
dungeon= 
​
  
−2
−5
10
​
  
−3
−10
30
​
  
3
1
−5
​
  
​
 
Step 1: Base Case
𝑑
𝑝
[
2
]
[
2
]
=
max
⁡
(
1
,
1
−
(
−
5
)
)
=
6
dp[2][2]=max(1,1−(−5))=6.

Step 2: Fill Last Row
𝑑
𝑝
[
2
]
[
1
]
=
max
⁡
(
1
,
6
−
30
)
=
1
dp[2][1]=max(1,6−30)=1
𝑑
𝑝
[
2
]
[
0
]
=
max
⁡
(
1
,
1
−
10
)
=
1
dp[2][0]=max(1,1−10)=1

Step 3: Fill Last Column
𝑑
𝑝
[
1
]
[
2
]
=
max
⁡
(
1
,
6
−
1
)
=
5
dp[1][2]=max(1,6−1)=5
𝑑
𝑝
[
0
]
[
2
]
=
max
⁡
(
1
,
5
−
3
)
=
2
dp[0][2]=max(1,5−3)=2

Step 4: Fill Rest of Table
𝑑
𝑝
[
1
]
[
1
]
=
max
⁡
(
1
,
min
⁡
(
1
,
5
)
−
(
−
10
)
)
=
11
dp[1][1]=max(1,min(1,5)−(−10))=11
𝑑
𝑝
[
1
]
[
0
]
=
max
⁡
(
1
,
min
⁡
(
1
,
11
)
−
(
−
5
)
)
=
6
dp[1][0]=max(1,min(1,11)−(−5))=6
𝑑
𝑝
[
0
]
[
1
]
=
max
⁡
(
1
,
min
⁡
(
11
,
2
)
−
(
−
3
)
)
=
5
dp[0][1]=max(1,min(11,2)−(−3))=5
𝑑
𝑝
[
0
]
[
0
]
=
max
⁡
(
1
,
min
⁡
(
6
,
5
)
−
(
−
2
)
)
=
7
dp[0][0]=max(1,min(6,5)−(−2))=7

Final DP Table:

𝑑
𝑝
=
[
7
5
2
6
11
5
1
1
6
]
dp= 
​
  
7
6
1
​
  
5
11
1
​
  
2
5
6
​
  
​
 
Output: 7

7. Code Explanation (Line by Line)
Line 7: Get the dimensions of the dungeon grid.
Line 10: Initialize the DP table with all zeros.
Line 13: Calculate the base case for the bottom-right corner.
Lines 16–18: Fill the last row using the recurrence relation.
Lines 21–23: Fill the last column using the recurrence relation.
Lines 26–29: Fill the rest of the DP table in reverse order using the recurrence relation.
Line 32: Return 
𝑑
𝑝
[
0
]
[
0
]
dp[0][0], the minimum health required at the start.
8. Complexity Analysis
Time Complexity: 
𝑂
(
𝑚
×
𝑛
)
O(m×n), as every cell is computed once.
Space Complexity: 
𝑂
(
𝑚
×
𝑛
)
O(m×n), for the DP table.
Let me know if you'd like further clarification!







You said:
it would be much better if you can show the dp table filling part in more inutitive manner and add some visualizations too if possible
ChatGPT said:
ChatGPT
Let’s make the DP table filling process for the Dungeon Game more intuitive by providing step-by-step explanations and a clear visualization at each stage of the filling. I'll guide you through with a clear representation of how each cell is computed, starting from the destination to the top-left corner.

Dungeon Grid
The input grid:

dungeon
=
[
−
2
−
3
3
−
5
−
10
1
10
30
−
5
]
dungeon= 
​
  
−2
−5
10
​
  
−3
−10
30
​
  
3
1
−5
​
  
​
 
DP Table Initialization
We create a DP table where each cell 
𝑑
𝑝
[
𝑖
]
[
𝑗
]
dp[i][j] represents the minimum health required at cell 
(
𝑖
,
𝑗
)
(i,j) to survive until the destination:

𝑑
𝑝
=
[
_
_
_
_
_
_
_
_
_
]
dp= 
​
  
_
_
_
​
  
_
_
_
​
  
_
_
_
​
  
​
 
Step 1: Base Case
The knight must have at least 1 health to survive at the bottom-right corner, regardless of the cell value.
At 
(
2
,
2
)
(2,2):

𝑑
𝑝
[
2
]
[
2
]
=
max
⁡
(
1
,
1
−
𝑑
𝑢
𝑛
𝑔
𝑒
𝑜
𝑛
[
2
]
[
2
]
)
=
max
⁡
(
1
,
1
−
(
−
5
)
)
=
6
dp[2][2]=max(1,1−dungeon[2][2])=max(1,1−(−5))=6
Updated DP table:

𝑑
𝑝
=
[
_
_
_
_
_
_
_
_
6
]
dp= 
​
  
_
_
_
​
  
_
_
_
​
  
_
_
6
​
  
​
 
Step 2: Fill the Last Row
We move right to left along the last row, calculating the minimum health required for the knight to survive.

At 
(
2
,
1
)
(2,1):
𝑑
𝑝
[
2
]
[
1
]
=
max
⁡
(
1
,
𝑑
𝑝
[
2
]
[
2
]
−
𝑑
𝑢
𝑛
𝑔
𝑒
𝑜
𝑛
[
2
]
[
1
]
)
=
max
⁡
(
1
,
6
−
30
)
=
1
dp[2][1]=max(1,dp[2][2]−dungeon[2][1])=max(1,6−30)=1
At 
(
2
,
0
)
(2,0):
𝑑
𝑝
[
2
]
[
0
]
=
max
⁡
(
1
,
𝑑
𝑝
[
2
]
[
1
]
−
𝑑
𝑢
𝑛
𝑔
𝑒
𝑜
𝑛
[
2
]
[
0
]
)
=
max
⁡
(
1
,
1
−
10
)
=
1
dp[2][0]=max(1,dp[2][1]−dungeon[2][0])=max(1,1−10)=1
Updated DP table:

𝑑
𝑝
=
[
_
_
_
_
_
_
1
1
6
]
dp= 
​
  
_
_
1
​
  
_
_
1
​
  
_
_
6
​
  
​
 
Step 3: Fill the Last Column
We move bottom to top along the last column, calculating the minimum health required for survival.

At 
(
1
,
2
)
(1,2):
𝑑
𝑝
[
1
]
[
2
]
=
max
⁡
(
1
,
𝑑
𝑝
[
2
]
[
2
]
−
𝑑
𝑢
𝑛
𝑔
𝑒
𝑜
𝑛
[
1
]
[
2
]
)
=
max
⁡
(
1
,
6
−
1
)
=
5
dp[1][2]=max(1,dp[2][2]−dungeon[1][2])=max(1,6−1)=5
At 
(
0
,
2
)
(0,2):
𝑑
𝑝
[
0
]
[
2
]
=
max
⁡
(
1
,
𝑑
𝑝
[
1
]
[
2
]
−
𝑑
𝑢
𝑛
𝑔
𝑒
𝑜
𝑛
[
0
]
[
2
]
)
=
max
⁡
(
1
,
5
−
3
)
=
2
dp[0][2]=max(1,dp[1][2]−dungeon[0][2])=max(1,5−3)=2
Updated DP table:

𝑑
𝑝
=
[
_
_
2
_
_
5
1
1
6
]
dp= 
​
  
_
_
1
​
  
_
_
1
​
  
2
5
6
​
  
​
 
Step 4: Fill the Remaining Cells
Now, we fill the rest of the DP table by considering both right and down movements at each cell.

Row 1:
At 
(
1
,
1
)
(1,1):
𝑑
𝑝
[
1
]
[
1
]
=
max
⁡
(
1
,
min
⁡
(
𝑑
𝑝
[
2
]
[
1
]
,
𝑑
𝑝
[
1
]
[
2
]
)
−
𝑑
𝑢
𝑛
𝑔
𝑒
𝑜
𝑛
[
1
]
[
1
]
)
dp[1][1]=max(1,min(dp[2][1],dp[1][2])−dungeon[1][1])
𝑑
𝑝
[
1
]
[
1
]
=
max
⁡
(
1
,
min
⁡
(
1
,
5
)
−
(
−
10
)
)
=
max
⁡
(
1
,
11
)
=
11
dp[1][1]=max(1,min(1,5)−(−10))=max(1,11)=11
At 
(
1
,
0
)
(1,0):
𝑑
𝑝
[
1
]
[
0
]
=
max
⁡
(
1
,
min
⁡
(
𝑑
𝑝
[
2
]
[
0
]
,
𝑑
𝑝
[
1
]
[
1
]
)
−
𝑑
𝑢
𝑛
𝑔
𝑒
𝑜
𝑛
[
1
]
[
0
]
)
dp[1][0]=max(1,min(dp[2][0],dp[1][1])−dungeon[1][0])
𝑑
𝑝
[
1
]
[
0
]
=
max
⁡
(
1
,
min
⁡
(
1
,
11
)
−
(
−
5
)
)
=
max
⁡
(
1
,
6
)
=
6
dp[1][0]=max(1,min(1,11)−(−5))=max(1,6)=6
Updated DP table:

𝑑
𝑝
=
[
_
_
2
6
11
5
1
1
6
]
dp= 
​
  
_
6
1
​
  
_
11
1
​
  
2
5
6
​
  
​
 
Row 0:
At 
(
0
,
1
)
(0,1):
𝑑
𝑝
[
0
]
[
1
]
=
max
⁡
(
1
,
min
⁡
(
𝑑
𝑝
[
1
]
[
1
]
,
𝑑
𝑝
[
0
]
[
2
]
)
−
𝑑
𝑢
𝑛
𝑔
𝑒
𝑜
𝑛
[
0
]
[
1
]
)
dp[0][1]=max(1,min(dp[1][1],dp[0][2])−dungeon[0][1])
𝑑
𝑝
[
0
]
[
1
]
=
max
⁡
(
1
,
min
⁡
(
11
,
2
)
−
(
−
3
)
)
=
max
⁡
(
1
,
5
)
=
5
dp[0][1]=max(1,min(11,2)−(−3))=max(1,5)=5
At 
(
0
,
0
)
(0,0):
𝑑
𝑝
[
0
]
[
0
]
=
max
⁡
(
1
,
min
⁡
(
𝑑
𝑝
[
1
]
[
0
]
,
𝑑
𝑝
[
0
]
[
1
]
)
−
𝑑
𝑢
𝑛
𝑔
𝑒
𝑜
𝑛
[
0
]
[
0
]
)
dp[0][0]=max(1,min(dp[1][0],dp[0][1])−dungeon[0][0])
𝑑
𝑝
[
0
]
[
0
]
=
max
⁡
(
1
,
min
⁡
(
6
,
5
)
−
(
−
2
)
)
=
max
⁡
(
1
,
7
)
=
7
dp[0][0]=max(1,min(6,5)−(−2))=max(1,7)=7
Final DP table:

𝑑
𝑝
=
[
7
5
2
6
11
5
1
1
6
]
dp= 
​
  
7
6
1
​
  
5
11
1
​
  
2
5
6
​
  
​
 
Visualizing the Process
Here’s how the knight’s minimum health changes as we fill the DP table:

1. Base Case:
Start at 
(
2
,
2
)
:
𝑑
𝑝
[
2
]
[
2
]
=
6
Start at (2,2):dp[2][2]=6
2. Last Row:
Moving left along the row:
𝑑
𝑝
[
2
]
[
1
]
=
1
,
 
𝑑
𝑝
[
2
]
[
0
]
=
1
dp[2][1]=1,dp[2][0]=1
3. Last Column:
Moving up along the column:
𝑑
𝑝
[
1
]
[
2
]
=
5
,
 
𝑑
𝑝
[
0
]
[
2
]
=
2
dp[1][2]=5,dp[0][2]=2
4. Fill Remaining:
Calculating each cell using the right and down values ensures the minimum health for survival is always calculated.
Answer
The knight needs a minimum of 7 health points to start at the top-left corner and survive the dungeon.

If you'd like, I can create a visual diagram or animation to explain it further. Let me know!







You said:
explain me the recurrence relations too in detail why minus from only down and all the steps 
ChatGPT said:
ChatGPT
Let me break down the recurrence relations for the Dungeon Game step by step and explain why we subtract only from the down or right cells and how the logic works for every computation.

Recurrence Relation
The general recurrence relation for filling the 
𝑑
𝑝
dp table is:

𝑑
𝑝
[
𝑖
]
[
𝑗
]
=
max
⁡
(
1
,
min
⁡
(
𝑑
𝑝
[
𝑖
+
1
]
[
𝑗
]
,
𝑑
𝑝
[
𝑖
]
[
𝑗
+
1
]
)
−
dungeon
[
𝑖
]
[
𝑗
]
)
dp[i][j]=max(1,min(dp[i+1][j],dp[i][j+1])−dungeon[i][j])
Where:

𝑑
𝑝
[
𝑖
]
[
𝑗
]
dp[i][j]: Minimum health required at cell 
(
𝑖
,
𝑗
)
(i,j) to ensure survival.
𝑑
𝑝
[
𝑖
+
1
]
[
𝑗
]
dp[i+1][j]: Health required at the down cell.
𝑑
𝑝
[
𝑖
]
[
𝑗
+
1
]
dp[i][j+1]: Health required at the right cell.
dungeon
[
𝑖
]
[
𝑗
]
dungeon[i][j]: The value of the dungeon cell at 
(
𝑖
,
𝑗
)
(i,j) (positive means health gain, negative means damage).
Step-by-Step Explanation
Why Subtract dungeon[i][j]?
The value in the dungeon cell affects the knight's health:

If 
dungeon
[
𝑖
]
[
𝑗
]
>
0
dungeon[i][j]>0: The knight gains health, so the required health at this cell is reduced.
If 
dungeon
[
𝑖
]
[
𝑗
]
<
0
dungeon[i][j]<0: The knight loses health, so the required health at this cell increases.
The formula subtracts 
dungeon
[
𝑖
]
[
𝑗
]
dungeon[i][j] to adjust the required health based on whether the cell is harmful or beneficial.

Why Use min(dp[i+1][j], dp[i][j+1])?
The knight can move either right or down. To survive, the knight needs to choose the path that requires the least health. Hence, we take the minimum of the two possible paths.

Why max(1, ...)?
At any cell, the knight needs at least 1 health point to stay alive. This ensures that the health never drops below 1, even if the dungeon cell gives a lot of damage.

How the Formula Works in Practice
Let's work through an example to see how the recurrence relation applies.

Dungeon Grid:
dungeon
=
[
−
2
−
3
3
−
5
−
10
1
10
30
−
5
]
dungeon= 
​
  
−2
−5
10
​
  
−3
−10
30
​
  
3
1
−5
​
  
​
 
Step 1: Base Case at Destination
At the bottom-right corner 
(
2
,
2
)
(2,2), the knight must have at least 1 health to survive:

𝑑
𝑝
[
2
]
[
2
]
=
max
⁡
(
1
,
1
−
dungeon
[
2
]
[
2
]
)
=
max
⁡
(
1
,
1
−
(
−
5
)
)
=
6
dp[2][2]=max(1,1−dungeon[2][2])=max(1,1−(−5))=6
Step 2: Last Row (Moving Right to Left)
At 
(
2
,
1
)
(2,1):

The knight moves right to 
(
2
,
2
)
(2,2), so we use 
𝑑
𝑝
[
2
]
[
2
]
dp[2][2]:
𝑑
𝑝
[
2
]
[
1
]
=
max
⁡
(
1
,
𝑑
𝑝
[
2
]
[
2
]
−
dungeon
[
2
]
[
1
]
)
=
max
⁡
(
1
,
6
−
30
)
=
1
dp[2][1]=max(1,dp[2][2]−dungeon[2][1])=max(1,6−30)=1
At 
(
2
,
0
)
(2,0):

The knight moves right to 
(
2
,
1
)
(2,1), so we use 
𝑑
𝑝
[
2
]
[
1
]
dp[2][1]:
𝑑
𝑝
[
2
]
[
0
]
=
max
⁡
(
1
,
𝑑
𝑝
[
2
]
[
1
]
−
dungeon
[
2
]
[
0
]
)
=
max
⁡
(
1
,
1
−
10
)
=
1
dp[2][0]=max(1,dp[2][1]−dungeon[2][0])=max(1,1−10)=1
Step 3: Last Column (Moving Bottom to Top)
At 
(
1
,
2
)
(1,2):

The knight moves down to 
(
2
,
2
)
(2,2), so we use 
𝑑
𝑝
[
2
]
[
2
]
dp[2][2]:
𝑑
𝑝
[
1
]
[
2
]
=
max
⁡
(
1
,
𝑑
𝑝
[
2
]
[
2
]
−
dungeon
[
1
]
[
2
]
)
=
max
⁡
(
1
,
6
−
1
)
=
5
dp[1][2]=max(1,dp[2][2]−dungeon[1][2])=max(1,6−1)=5
At 
(
0
,
2
)
(0,2):

The knight moves down to 
(
1
,
2
)
(1,2), so we use 
𝑑
𝑝
[
1
]
[
2
]
dp[1][2]:
𝑑
𝑝
[
0
]
[
2
]
=
max
⁡
(
1
,
𝑑
𝑝
[
1
]
[
2
]
−
dungeon
[
0
]
[
2
]
)
=
max
⁡
(
1
,
5
−
3
)
=
2
dp[0][2]=max(1,dp[1][2]−dungeon[0][2])=max(1,5−3)=2
Step 4: Fill Remaining Cells
At 
(
1
,
1
)
(1,1):

The knight can move right to 
(
1
,
2
)
(1,2) or down to 
(
2
,
1
)
(2,1). We take the minimum:
𝑑
𝑝
[
1
]
[
1
]
=
max
⁡
(
1
,
min
⁡
(
𝑑
𝑝
[
1
]
[
2
]
,
𝑑
𝑝
[
2
]
[
1
]
)
−
dungeon
[
1
]
[
1
]
)
dp[1][1]=max(1,min(dp[1][2],dp[2][1])−dungeon[1][1])
𝑑
𝑝
[
1
]
[
1
]
=
max
⁡
(
1
,
min
⁡
(
5
,
1
)
−
(
−
10
)
)
=
max
⁡
(
1
,
11
)
=
11
dp[1][1]=max(1,min(5,1)−(−10))=max(1,11)=11
At 
(
1
,
0
)
(1,0):

The knight can move right to 
(
1
,
1
)
(1,1) or down to 
(
2
,
0
)
(2,0). We take the minimum:
𝑑
𝑝
[
1
]
[
0
]
=
max
⁡
(
1
,
min
⁡
(
𝑑
𝑝
[
1
]
[
1
]
,
𝑑
𝑝
[
2
]
[
0
]
)
−
dungeon
[
1
]
[
0
]
)
dp[1][0]=max(1,min(dp[1][1],dp[2][0])−dungeon[1][0])
𝑑
𝑝
[
1
]
[
0
]
=
max
⁡
(
1
,
min
⁡
(
11
,
1
)
−
(
−
5
)
)
=
max
⁡
(
1
,
6
)
=
6
dp[1][0]=max(1,min(11,1)−(−5))=max(1,6)=6
At 
(
0
,
1
)
(0,1):

The knight can move right to 
(
0
,
2
)
(0,2) or down to 
(
1
,
1
)
(1,1). We take the minimum:
𝑑
𝑝
[
0
]
[
1
]
=
max
⁡
(
1
,
min
⁡
(
𝑑
𝑝
[
0
]
[
2
]
,
𝑑
𝑝
[
1
]
[
1
]
)
−
dungeon
[
0
]
[
1
]
)
dp[0][1]=max(1,min(dp[0][2],dp[1][1])−dungeon[0][1])
𝑑
𝑝
[
0
]
[
1
]
=
max
⁡
(
1
,
min
⁡
(
2
,
11
)
−
(
−
3
)
)
=
max
⁡
(
1
,
5
)
=
5
dp[0][1]=max(1,min(2,11)−(−3))=max(1,5)=5
At 
(
0
,
0
)
(0,0):

The knight can move right to 
(
0
,
1
)
(0,1) or down to 
(
1
,
0
)
(1,0). We take the minimum:
𝑑
𝑝
[
0
]
[
0
]
=
max
⁡
(
1
,
min
⁡
(
𝑑
𝑝
[
0
]
[
1
]
,
𝑑
𝑝
[
1
]
[
0
]
)
−
dungeon
[
0
]
[
0
]
)
dp[0][0]=max(1,min(dp[0][1],dp[1][0])−dungeon[0][0])
𝑑
𝑝
[
0
]
[
0
]
=
max
⁡
(
1
,
min
⁡
(
5
,
6
)
−
(
−
2
)
)
=
max
⁡
(
1
,
7
)
=
7
dp[0][0]=max(1,min(5,6)−(−2))=max(1,7)=7
DP Table (Final)
𝑑
𝑝
=
[
7
5
2
6
11
5
1
1
6
]
dp= 
​
  
7
6
1
​
  
5
11
1
​
  
2
5
6
​
  
​
 
Answer
The knight needs a minimum of 7 health to start at 
(
0
,
0
)
(0,0) and survive the dungeon.

