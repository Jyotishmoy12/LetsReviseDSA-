Problem Statement (More Clearly)
Given an integer array arr[] of size n, find the total number of subarrays whose sum is odd. A subarray is a contiguous portion of the array. The goal is to determine the count efficiently.

Intuition
The sum of a subarray can either be odd or even.
An odd sum results from an odd number of odd elements in the subarray.
To achieve an odd sum at a given endpoint, we need to consider all subarrays ending at that point whose cumulative sum is odd.
Key Insight: Use prefix sums to track whether the cumulative sum up to each index is odd or even. This allows us to count odd sums efficiently.
Track counts of odd and even prefix sums while traversing the array.
Approach
Initialize two variables:

odd_count (tracks the number of odd prefix sums seen so far).
even_count (tracks the number of even prefix sums seen so far).
Initialize even_count to 1 because a prefix sum of 0 is even.
Maintain a running prefix sum (prefix_sum) as you iterate over the array.

If prefix_sum is odd, it means all previous prefix sums that are even will form subarrays with an odd sum (odd - even = odd).
If prefix_sum is even, it means all previous prefix sums that are odd will form subarrays with an odd sum (even - odd = odd).
Add odd_count or even_count to the total count of subarrays with odd sums, depending on the current prefix sum.

Update the counts of odd_count and even_count accordingly.

Return the total count.



#include <iostream>
#include <vector>
using namespace std;

int countOddSumSubarrays(const vector<int>& arr) {
    int odd_count = 0, even_count = 1; // Start with even_count as 1 because prefix_sum = 0 is even
    int prefix_sum = 0, total_odd_subarrays = 0;

    for (int num : arr) {
        // Update the prefix sum
        prefix_sum += num;

        // Check if the prefix sum is odd or even
        if (prefix_sum % 2 == 0) {
            // Add the number of odd prefix sums seen so far
            total_odd_subarrays += odd_count;
            // Increment the even count
            even_count++;
        } else {
            // Add the number of even prefix sums seen so far
            total_odd_subarrays += even_count;
            // Increment the odd count
            odd_count++;
        }
    }

    return total_odd_subarrays;
}

int main() {
    vector<int> arr = {1, 2, 3, 4};
    cout << "Total subarrays with odd sum: " << countOddSumSubarrays(arr) << endl;
    return 0;
}





Key Concepts to Keep in Mind
Prefix Sum:
The prefix sum up to index i is the sum of all elements from the beginning of the array up to i.
If the prefix sum is:

Odd: Adding this prefix sum to another even prefix sum will form an odd sum subarray.
Even: Adding this prefix sum to another odd prefix sum will form an odd sum subarray.
Tracking Counts:

odd_count: Number of prefix sums that are odd so far.
even_count: Number of prefix sums that are even so far.
These counts help us efficiently determine how many subarrays ending at the current index have odd sums.
Step-by-Step Intuition (Dry Run)
Initialization:
Before starting, we assume there is a "prefix sum" of 0 (even) before any elements.

odd_count = 0 (no odd prefix sums yet).
even_count = 1 (we count the "imaginary" even prefix sum 0).
Iteration 1 (Index 0, Element = 1)
Update Prefix Sum:

Add 1 to the previous prefix sum (0):
prefix_sum = 0 + 1 = 1.
Now, the prefix sum is odd.
How Many Odd Subarrays Can End Here?

A subarray ending at this index has a sum equal to:
prefix_sum - (any previous prefix sum).
To make this subarray odd, the difference must be odd.
Odd - Even = Odd.
Therefore, the number of even prefix sums seen so far tells us how many subarrays ending here have odd sums.
Since even_count = 1:
Add 1 to total_odd_subarrays.

Update Counts:

The current prefix_sum is odd, so increment odd_count:
odd_count = 1.
Iteration 2 (Index 1, Element = 2)
Update Prefix Sum:

Add 2 to the previous prefix sum (1):
prefix_sum = 1 + 2 = 3.
Now, the prefix sum is odd.
How Many Odd Subarrays Can End Here?

For subarrays ending here to have an odd sum, we again use even prefix sums seen so far.
Since even_count = 1:
Add 1 to total_odd_subarrays.
Update Counts:

The current prefix_sum is odd, so increment odd_count:
odd_count = 2.
Iteration 3 (Index 2, Element = 3)
Update Prefix Sum:

Add 3 to the previous prefix sum (3):
prefix_sum = 3 + 3 = 6.
Now, the prefix sum is even.
How Many Odd Subarrays Can End Here?

For subarrays ending here to have an odd sum, we use odd prefix sums seen so far.
Since odd_count = 2:
Add 2 to total_odd_subarrays.
Update Counts:

The current prefix_sum is even, so increment even_count:
even_count = 2.
Iteration 4 (Index 3, Element = 4)
Update Prefix Sum:

Add 4 to the previous prefix sum (6):
prefix_sum = 6 + 4 = 10.
Now, the prefix sum is even.
How Many Odd Subarrays Can End Here?

For subarrays ending here to have an odd sum, we use odd prefix sums seen so far.
Since odd_count = 2:
Add 2 to total_odd_subarrays.
Update Counts:

The current prefix_sum is even, so increment even_count:
even_count = 3.
Summary of Actions
Odd Prefix Sum: Contributes to the count of odd subarrays based on even_count.
Even Prefix Sum: Contributes to the count of odd subarrays based on odd_count.
Key Insights from Each Step
Why Use even_count for Odd Prefix Sums?

An odd prefix sum can only form an odd subarray when subtracted from an even prefix sum.
Why Use odd_count for Even Prefix Sums?

An even prefix sum can only form an odd subarray when subtracted from an odd prefix sum.
Base Case (even_count = 1):

This accounts for the imaginary prefix sum of 0 at the start, which is even.
Final Output
After iterating through all elements, the total number of subarrays with odd sums is:
total_odd_subarrays = 6.
