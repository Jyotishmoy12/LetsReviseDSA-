Problem
Objective: Given a string s, find the length of the longest substring without repeating characters.

Approach
Initialization:

Use two pointers i and j to represent the current window.
Use a hash set to keep track of characters in the current window.
maxLength will store the length of the longest substring found.
Sliding Window Expansion and Contraction:

Expand the window by moving the j pointer.
If a character at j is already in the window, contract the window by moving the i pointer until the character can be added without repetition.
C++ Code
Here’s how you can use the sliding window template to solve this problem:

cpp
Copy code
#include <iostream>
#include <unordered_set>
#include <string>
#include <algorithm>

class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        int n = s.size();
        int i = 0, j = 0;
        int maxLength = 0;
        std::unordered_set<char> current_chars;

        while (j < n) {
            if (current_chars.find(s[j]) == current_chars.end()) {
                // Character is not in the current window
                current_chars.insert(s[j]);
                maxLength = std::max(maxLength, j - i + 1);
                j++;
            } else {
                // Character is already in the current window, need to move 'i'
                current_chars.erase(s[i]);
                i++;
            }
        }

        return maxLength;
    }
};

int main() {
    Solution solution;
    std::string s = "abcabcbb";
    std::cout << "Length of the longest substring without repeating characters: " 
              << solution.lengthOfLongestSubstring(s) << std::endl;
    return 0;
}
Explanation
Initialization:

i and j are initialized to 0. They represent the start and end of the current window.
maxLength tracks the length of the longest substring found without repeating characters.
current_chars is an unordered set to store characters in the current window.
Sliding Window Logic:

The while loop iterates with j moving from the start to the end of the string.
If the character at j is not in the hash set, it is added to the set and maxLength is updated if the new window length is greater.
If the character at j is already in the hash set, remove the character at i from the set and move i to the right until the duplicate character is removed from the window.

Let's perform a dry run of the lengthOfLongestSubstring function using the string s = "abcabcbb".

Dry Run
Input: s = "abcabcbb"

Objective: Find the length of the longest substring without repeating characters.

Initial Setup
i = 0 (start of the window)
j = 0 (end of the window)
maxLength = 0 (to keep track of the maximum length found)
current_chars = {} (hash set to store characters in the current window)
Iteration Steps
Step 1: j = 0, character = 'a'

'a' is not in current_chars. Add 'a' to current_chars.
current_chars = {'a'}
Update maxLength = max(0, 0 - 0 + 1) = 1
Increment j to 1.
Step 2: j = 1, character = 'b'

'b' is not in current_chars. Add 'b' to current_chars.
current_chars = {'a', 'b'}
Update maxLength = max(1, 1 - 0 + 1) = 2
Increment j to 2.
Step 3: j = 2, character = 'c'

'c' is not in current_chars. Add 'c' to current_chars.
current_chars = {'a', 'b', 'c'}
Update maxLength = max(2, 2 - 0 + 1) = 3
Increment j to 3.
Step 4: j = 3, character = 'a'

'a' is in current_chars. Remove 'a' from current_chars and increment i until the duplicate 'a' is removed.
Remove 'a' from current_chars. Now current_chars = {'b', 'c'}.
Increment i to 1.
Remove 'b' from current_chars and increment i until 'b' is removed.
Remove 'b' from current_chars. Now current_chars = {'c'}.
Increment i to 2.
Add 'a' back to current_chars. Now current_chars = {'c', 'a'}.
maxLength remains 3.
Increment j to 4.
Step 5: j = 4, character = 'b'

'b' is not in current_chars. Add 'b' to current_chars.
current_chars = {'c', 'a', 'b'}
Update maxLength = max(3, 4 - 2 + 1) = 3
Increment j to 5.
Step 6: j = 5, character = 'c'

'c' is in current_chars. Remove 'c' from current_chars and increment i until 'c' is removed.
Remove 'c' from current_chars. Now current_chars = {'a', 'b'}.
Increment i to 3.
Add 'c' back to current_chars. Now current_chars = {'a', 'b', 'c'}.
maxLength remains 3.
Increment j to 6.
Step 7: j = 6, character = 'b'

'b' is in current_chars. Remove 'b' from current_chars and increment i until 'b' is removed.
Remove 'b' from current_chars. Now current_chars = {'a', 'c'}.
Increment i to 4.
Add 'b' back to current_chars. Now current_chars = {'a', 'b', 'c'}.
maxLength remains 3.
Increment j to 7.
Step 8: j = 7, character = 'b'

'b' is in current_chars. Remove 'b' from current_chars and increment i until 'b' is removed.
Remove 'b' from current_chars. Now current_chars = {'a', 'c'}.
Increment i to 5.
Add 'b' back to current_chars. Now current_chars = {'a', 'b', 'c'}.
maxLength remains 3.
Increment j to 8.
At the end of the iterations, j is equal to the length of the string, and maxLength is 3.

Final Result
Length of the longest substring without repeating characters: 3

The longest substrings without repeating characters are "abc".

Complexity Analysis
Time Complexity: 
𝑂
(
𝑛
)
O(n) — Each character is added and removed from the hash set at most once.
Space Complexity: 
𝑂
(
𝑚
𝑖
𝑛
(
𝑛
,
𝑚
)
)
O(min(n,m)) — The hash set stores at most min(n, m) characters, where 
𝑚
m is the size of the character set.
This dry run illustrates how the sliding window approach efficiently finds the longest substring without repeating characters by expanding and contracting the window as needed.
