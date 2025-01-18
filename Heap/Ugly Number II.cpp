Problem Statement: Ugly Number II
An ugly number is a positive integer whose prime factors are only 2, 3, and 5.
Given an integer n, return the nth ugly number in the sequence.

The sequence of ugly numbers starts as:
1, 2, 3, 4, 5, 6, 8, 9, 10, 12, 15, ...

Intuition
The problem requires us to generate numbers where the only prime factors are 2, 3, or 5. To achieve this, we:

Start with the smallest ugly number, which is 1.
Generate new ugly numbers by multiplying 2, 3, and 5 with previously generated ugly numbers.
Use a min-heap (priority queue) to efficiently keep track of the smallest possible next ugly number.
Use a set to avoid duplicates since multiple combinations can generate the same ugly number (e.g., 
2
×
3
=
6
2×3=6 and 
3
×
2
=
6
3×2=6).
Approach
Initialize the sequence with the first ugly number: 1.
Use a min-heap to maintain the smallest ugly numbers in sorted order.
Use a set to ensure no duplicate numbers are added to the heap.
At each step:
Pop the smallest number from the heap.
Generate new numbers by multiplying it with 2, 3, and 5.
Add the new numbers to the heap if they haven't already been added (check the set).
Repeat until we extract the nth ugly number.
Code in C++
cpp
Copy
Edit
#include <iostream>
#include <queue>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int nthUglyNumber(int n) {
        // Min-heap to store ugly numbers
        priority_queue<long, vector<long>, greater<long>> minHeap;
        // Set to avoid duplicate numbers
        unordered_set<long> seen;
        
        // Push the first ugly number
        minHeap.push(1);
        seen.insert(1);
        
        // Factors for generating new ugly numbers
        int factors[] = {2, 3, 5};
        long currentUgly = 1;
        
        // Generate the first n ugly numbers
        for (int i = 1; i <= n; i++) {
            // Get the smallest ugly number
            currentUgly = minHeap.top();
            minHeap.pop();
            
            // Generate new ugly numbers by multiplying with factors
            for (int factor : factors) {
                long nextUgly = currentUgly * factor;
                // Add to heap and set if it's not a duplicate
                if (seen.find(nextUgly) == seen.end()) {
                    minHeap.push(nextUgly);
                    seen.insert(nextUgly);
                }
            }
        }
        
        return currentUgly;
    }
};

int main() {
    Solution sol;
    int n = 10;
    cout << "The " << n << "th ugly number is: " << sol.nthUglyNumber(n) << endl;
    return 0;
}
Dry Run
Input: 
𝑛
=
10
n=10
Steps:

Start with minHeap = {1}, seen = {1}.
Pop 1 (smallest ugly number), generate new numbers: 1 * 2 = 2, 1 * 3 = 3, 1 * 5 = 5.
Add them to the heap and set: minHeap = {2, 3, 5}, seen = {1, 2, 3, 5}.
Pop 2, generate new numbers: 2 * 2 = 4, 2 * 3 = 6, 2 * 5 = 10.
Add them: minHeap = {3, 5, 4, 6, 10}, seen = {1, 2, 3, 4, 5, 6, 10}.
Pop 3, generate new numbers: 3 * 2 = 6, 3 * 3 = 9, 3 * 5 = 15.
Add them (ignore duplicate 6): minHeap = {4, 5, 10, 6, 9, 15}, seen = {1, 2, 3, 4, 5, 6, 9, 10, 15}.
Repeat this process until the 10th ugly number is reached.
Result: The sequence generated is:
1, 2, 3, 4, 5, 6, 8, 9, 10, 12
Output: 12

Complexity Analysis
Time Complexity:

Each ugly number is pushed and popped from the min-heap exactly once.
Generating new numbers involves 
𝑂
(
log
⁡
𝑛
)
O(logn) for heap operations.
Total complexity: 
𝑂
(
𝑛
log
⁡
𝑛
)
O(nlogn).
Space Complexity:

The min-heap and set store up to 
𝑛
n elements.
Total complexity: 
𝑂
(
𝑛
)
O(n).
