Problem: Maximize the Confusion of an Exam
Problem Statement: You are given a string answerKey consisting of 'T' (True) and 'F' (False). Your task is to maximize the length of a substring where the number of 'T's and 'F's differs by at most k. In other words, you can flip at most k characters to either 'T' or 'F' to make the substring as long as possible, but the difference in the number of 'T's and 'F's in that substring must not exceed k.

You need to return the maximum possible length of such a substring.

Approach:
We can solve this problem using the sliding window technique. Here's how we can break down the approach:

Sliding Window:

We use two pointers, i and j, to define the window.
We can flip at most k characters. So, we try to maintain a window where the difference between the count of 'T's and 'F's doesn't exceed k.
Tracking the Count of Characters:

For the current window, track how many 'T's and 'F's we have using counters.
If the difference between the counts of 'T' and 'F' exceeds k, shrink the window from the left by moving i.
Expanding the Window:

Expand the window by incrementing j. If the difference in counts is within the limit, continue expanding the window.
Result:

The length of the largest valid window will be our answer.
Algorithm:
Initialize two pointers i and j to 0.
Use a counter to track how many 'T's (or 'F's) are in the current window.
As you expand the window by incrementing j, check if the window is valid.
If the window is invalid (i.e., the difference exceeds k), move i to shrink the window until it becomes valid again.
Keep track of the maximum valid window size.
Code in C++:
cpp
Copy code
class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int i = 0, j = 0;
        int maxLength = 0;
        int countT = 0, countF = 0;

        while (j < answerKey.size()) {
            // Count the characters in the window
            if (answerKey[j] == 'T') countT++;
            else countF++;

            // Check if the window is valid (the difference between countT and countF is <= k)
            while (min(countT, countF) > k) {
                // Shrink the window from the left side if it's invalid
                if (answerKey[i] == 'T') countT--;
                else countF--;
                i++;
            }

            // Update the maximum length of the valid window
            maxLength = max(maxLength, j - i + 1);

            // Expand the window by moving `j` to the right
            j++;
        }

        return maxLength;
    }
};
Explanation:
Sliding Window Expansion:
As j moves from left to right, we expand the window and keep track of how many 'T' and 'F' characters are inside it. We use countT for the count of 'T' characters and countF for 'F' characters.
Validating the Window:
If the difference in the count of 'T's and 'F's exceeds k, we shrink the window from the left side by moving i forward. This ensures that the window always remains valid.
Tracking the Maximum Length:
After processing each window, we update the maxLength to reflect the largest valid window we've encountered so far.
Dry Run:
Let's take an example:

cpp
Copy code
answerKey = "TTFF", k = 2
Initialization:

i = 0, j = 0, maxLength = 0, countT = 0, countF = 0
Step 1: Expand the window (j = 0):

answerKey[j] = 'T' → countT = 1, countF = 0
Window size = 1 ("T"), valid (difference is 1).
Update maxLength = 1.
Move j to 1.
Step 2: Expand the window (j = 1):

answerKey[j] = 'T' → countT = 2, countF = 0
Window size = 2 ("TT"), valid (difference is 2).
Update maxLength = 2.
Move j to 2.
Step 3: Expand the window (j = 2):

answerKey[j] = 'F' → countT = 2, countF = 1
Window size = 3 ("TTF"), valid (difference is 1).
Update maxLength = 3.
Move j to 3.
Step 4: Expand the window (j = 3):

answerKey[j] = 'F' → countT = 2, countF = 2
Window size = 4 ("TTFF"), valid (difference is 2).
Update maxLength = 4.
Move j to 4, but j exceeds the string size, so we stop.
Final Result: maxLength = 4

Time Complexity:
O(n) where n is the length of the answerKey string.
Each index is visited at most twice (once by j and once by i).
Space Complexity:
O(1) as we only use a few variables for counting and storing the result.
