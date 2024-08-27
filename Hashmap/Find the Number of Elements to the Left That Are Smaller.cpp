Problem: Find the Number of Elements to the Left That Are Smaller
Objective: For each element in the array, count how many elements to its left are smaller than it. This problem adds a directional constraint, focusing only on the elements that precede the current one in the array.

Intuition:
The key idea is to iterate through the array and, for each element, count how many elements that come before it are smaller. Since we are only concerned with elements to the left of the current element, this can be done efficiently using various approaches.
Detailed Explanation:
Input: An array of integers.
Output: An array of integers where each element represents the number of elements to the left of it that are smaller.
Steps to Solve:
Brute Force Approach (O(n^2)):

For each element, traverse all elements to its left and count how many of them are smaller.
This approach is simple but inefficient for large arrays.
Efficient Approach Using Binary Indexed Tree (BIT) or Fenwick Tree (O(n log n)):

The idea is to use a data structure that can efficiently handle range queries and updates, like a Binary Indexed Tree.
As we traverse the array, we use the tree to keep track of the counts of elements we've seen so far, and for each new element, we can quickly find out how many of the previous elements are smaller.
Example:
Input: [3, 4, 9, 6, 1]

Output: [0, 1, 2, 2, 0]

Explanation:

For 3: There are no elements to the left, so the count is 0.
For 4: Only 3 is to the left and smaller, so the count is 1.
For 9: Both 3 and 4 are to the left and smaller, so the count is 2.
For 6: Both 3 and 4 are to the left and smaller, so the count is 2.
For 1: There are no elements to the left that are smaller, so the count is 0.


#include <iostream>
#include <vector>

using namespace std;

vector<int> countSmallerToTheLeft(vector<int>& nums) {
    int n = nums.size();
    vector<int> result(n, 0);
    
    // For each element, count the number of smaller elements to the left
    for (int i = 1; i < n; i++) {
        int count = 0;
        for (int j = 0; j < i; j++) {
            if (nums[j] < nums[i]) {
                count++;
            }
        }
        result[i] = count;
    }
    
    return result;
}

int main() {
    vector<int> nums = {3, 4, 9, 6, 1};
    vector<int> result = countSmallerToTheLeft(nums);
    
    for (int count : result) {
        cout << count << " ";
    }
    
    return 0;
}
