Problem Explanation:
You are given a string s and an integer k. The task is to find the length of the longest substring that contains at most k distinct characters.

Intuition:
To solve this problem, we can use the sliding window technique, which is perfect when dealing with contiguous subarrays or substrings.

We maintain a window that can grow by adding characters from the string s.
Each time we add a character, we check if the number of distinct characters exceeds k.
If it does, we shrink the window by moving the left pointer of the window to the right, until the number of distinct characters is within the allowed limit.
We maintain the maximum length of any valid window (with at most k distinct characters) we encounter during this process.
Approach:
Use two pointers, i and j, where i represents the start of the window and j represents the end.
Maintain a frequency map (hash map) to keep track of the number of occurrences of each character in the current window.
As j moves through the string, add characters to the window and increase their count in the map.
If the map has more than k distinct characters, move the start of the window (i) to the right, until the number of distinct characters becomes at most k.
Track the maximum length of a valid substring during the process.

#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    int longestSubstringWithKDistinct(string s, int k) {
        if (k <= 0) return -1; // Handle edge case

        unordered_map<char, int> charCount;
        int i = 0, maxLen = -1;

        for (int j = 0; j < s.size(); ++j) {
            charCount[s[j]]++; // Add current character to the map

            // Shrink the window if there are more than k distinct characters
            while (charCount.size() > k) {
                charCount[s[i]]--;
                if (charCount[s[i]] == 0) {
                    charCount.erase(s[i]); // Remove character if its count is 0
                }
                i++; // Move the start of the window to the right
            }

            // Check if the window has exactly k distinct characters
            if (charCount.size() == k) {
                maxLen = max(maxLen, j - i + 1); // Update maxLen if window is valid
            }
        }

        return maxLen == -1 ? -1 : maxLen; // Return -1 if no valid substring is found
    }
};
Detailed Dry Run
Example: s = "abcba", k = 2

Initialization:

charCount = {} (empty)
i = 0
maxLen = -1
Iteration 1 (j = 0, s[j] = 'a'):

charCount = {'a': 1}
Number of distinct characters = 1 (< k)
No shrinking needed
maxLen = -1
Iteration 2 (j = 1, s[j] = 'b'):

charCount = {'a': 1, 'b': 1}
Number of distinct characters = 2 (= k)
maxLen = 2 (length of substring "ab")
Iteration 3 (j = 2, s[j] = 'c'):

charCount = {'a': 1, 'b': 1, 'c': 1}
Number of distinct characters = 3 (> k)
Shrink window: Remove 'a', i = 1, charCount = {'b': 1, 'c': 1}
Number of distinct characters = 2 (= k)
maxLen = 3 (length of substring "bca")
Iteration 4 (j = 3, s[j] = 'b'):

charCount = {'b': 2, 'c': 1}
Number of distinct characters = 2 (= k)
maxLen = 4 (length of substring "bcba")
Iteration 5 (j = 4, s[j] = 'a'):

charCount = {'b': 2, 'c': 1, 'a': 1}
Number of distinct characters = 3 (> k)
Shrink window: Remove 'b', i = 2, charCount = {'b': 1, 'c': 1, 'a': 1}
Shrink window: Remove 'c', i = 3, charCount = {'b': 1, 'a': 1}
Number of distinct characters = 2 (= k)
maxLen = 4 (length of substring "bbaa")
Edge Cases
Empty String: Return -1 if the string is empty or k is less than or equal to 0.
No Valid Substring: If maxLen remains -1, return -1 to indicate no valid substring found.
Complexity Analysis
Time Complexity: O(n), where n is the length of the string. Each character is processed once in the sliding window.
Space Complexity: O(k), where k is the number of distinct characters in the current window. This space is used by the hash map to store character frequencies.






