Subarray Product Less Than K problem with the sliding window approach.

Intuition
Understanding the Problem:

We are given an array of positive integers nums and an integer k.
The goal is to find the number of contiguous subarrays (continuous sub-segments) where the product of the elements is strictly less than k.
Initial Thoughts:

If we naively calculate the product for every possible subarray, the time complexity would be O(n^2), which is inefficient for large arrays.
However, the problem has a critical observation: the product of elements in a subarray either increases or decreases when we add or remove elements from the subarray.
This observation suggests that we can use a sliding window approach to efficiently maintain and update the product of elements in the current subarray as we expand or contract the window.
Sliding Window Intuition:

Window Expansion: As we move the right pointer (j) through the array, we include more elements in our current window and multiply their values into the running product.
Window Contraction: If the product becomes greater than or equal to k, we need to shrink the window from the left (move i forward) until the product is less than k. We do this by dividing the product by nums[i] and moving the left pointer i to the right.
Every time we have a valid product that is less than k, we count the number of subarrays that end at index j. The number of valid subarrays is (j - i + 1) because all subarrays ending at j with different starting points between i and j are valid.
Why (j - i + 1) Subarrays:

Imagine a valid subarray from index i to j. All the subarrays that start between i and j (inclusive) and end at j are valid because adding any element before i would cause the product to exceed k.
For example, if i = 1 and j = 3, then the subarrays are: [nums[1] to nums[3]], [nums[2] to nums[3]], and [nums[3]]. Thus, there are exactly j - i + 1 subarrays.
Why Use a Product Instead of a Sum:

Unlike sum problems where a sliding window can work by adding or subtracting elements, in this case, we are dealing with products, so we multiply when adding elements and divide when removing them.
The key point is that multiplication and division operations are inverse of each other, which allows us to maintain the product efficiently as we move the window.
Key Observations
Shrinking the Window: When the product of the current subarray exceeds k, shrinking the window from the left ensures that we only count subarrays where the product remains less than k.

Counting Subarrays: For each valid window (where the product is less than k), we can directly calculate the number of valid subarrays ending at that position, reducing the need to recalculate every subarray's product individually.

Code Breakdown
cpp
Copy code
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k <= 1) return 0;  // If k <= 1, no valid subarray exists since all products are >= 1.
        
        int product = 1, count = 0;  // Initialize the product and count.
        int i = 0;  // Left pointer of the sliding window.
        
        for (int j = 0; j < nums.size(); j++) {  // Right pointer traverses the array.
            product *= nums[j];  // Multiply the current element into the product.
            
            // Shrink the window if the product is greater than or equal to k.
            while (product >= k && i <= j) {
                product /= nums[i];  // Remove the element nums[i] from the product.
                i++;  // Move the left pointer forward.
            }
            
            // Add the number of valid subarrays ending at index `j`.
            count += (j - i + 1);
        }
        
        return count;  // Return the total count of valid subarrays.
    }
};
Complexity Analysis
Time Complexity: O(n), where n is the size of the array nums.
Each element is visited at most twice: once when it's added to the product and once when it's removed.
This makes the sliding window approach linear in time.
Space Complexity: O(1), since we're using only a few extra variables (product, count, i, etc.), independent of the input size.
Dry Run Example
Let’s perform a dry run with a sample test case:

Test Case:
nums = [10, 5, 2, 6], k = 100

Step-by-Step Execution:

Initialization:

product = 1, count = 0, i = 0
First Iteration (j = 0):

product *= nums[0] → product = 1 * 10 = 10
product < k → Add (j - i + 1) = (0 - 0 + 1) = 1 subarrays.
count = 1
Second Iteration (j = 1):

product *= nums[1] → product = 10 * 5 = 50
product < k → Add (j - i + 1) = (1 - 0 + 1) = 2 subarrays.
count = 3
Third Iteration (j = 2):

product *= nums[2] → product = 50 * 2 = 100
product >= k, so we shrink the window:
product /= nums[i] → product = 100 / 10 = 10, i = 1
product < k → Add (j - i + 1) = (2 - 1 + 1) = 2 subarrays.
count = 5
Fourth Iteration (j = 3):

product *= nums[3] → product = 10 * 6 = 60
product < k → Add (j - i + 1) = (3 - 1 + 1) = 3 subarrays.
count = 8
At the end of the process, the total number of valid subarrays is 8.

  Time Complexity
Time complexity: O(n), where n is the length of nums. Both i and j move from 0 to n, and every element is processed once.
Space complexity: O(1) since we're only using a few variables to store the product and the count.
