Find All Anagrams in a String problem, explaining the sliding window approach, C++ implementation, and then perform a dry run using a sample test case.

Problem
Objective: Given two strings s and p, return all the start indices of p's anagrams in s.

Approach
Sliding Window: Use a sliding window of size equal to p.length().
Frequency Map: Maintain frequency maps for both p and the current window in s.
As the window slides over s, compare the frequency map of the current window with that of p.
If they match, the current window is an anagram of p, and you add the starting index of the window to the result.
C++ Code
Here's the C++ implementation using a sliding window approach:

cpp
Copy code
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

class Solution {
public:
    std::vector<int> findAnagrams(std::string s, std::string p) {
        std::vector<int> result;
        int s_len = s.size(), p_len = p.size();
        if (s_len < p_len) return result; // If s is smaller than p, no anagrams possible
        
        // Frequency map of characters in p
        std::vector<int> p_freq(26, 0), s_freq(26, 0);

        // Fill the frequency map for string p
        for (char c : p) {
            p_freq[c - 'a']++;
        }

        // Use a sliding window of size p_len
        int i = 0, j = 0;
        
        while (j < s_len) {
            // Add current character in s to the sliding window frequency map
            s_freq[s[j] - 'a']++;

            // If the window size is less than p_len, just move the window forward
            if (j - i + 1 < p_len) {
                j++;
            } 
            // If the window size is equal to p_len
            else if (j - i + 1 == p_len) {
                // Compare the frequency maps of current window and p
                if (s_freq == p_freq) {
                    result.push_back(i); // Add the start index if they match
                }

                // Slide the window: remove the effect of s[i] and move i forward
                s_freq[s[i] - 'a']--;
                i++;
                j++;
            }
        }
        
        return result;
    }
};

int main() {
    Solution solution;
    std::string s = "cbaebabacd";
    std::string p = "abc";
    
    std::vector<int> result = solution.findAnagrams(s, p);
    
    std::cout << "Anagram start indices: ";
    for (int index : result) {
        std::cout << index << " ";
    }
    
    return 0;
}
Dry Run
Let's dry run the code using the example strings s = "cbaebabacd" and p = "abc".

Initial Setup
s_len = 10, p_len = 3

Initialize two frequency maps of size 26 (for characters a-z):

p_freq = [1, 1, 1, 0, ..., 0] (for "abc")
s_freq = [0, 0, 0, 0, ..., 0] (initially all zeros)
Initialize pointers i = 0 and j = 0, and an empty result vector result = [].

Sliding Window Iteration
Step 1: j = 0, character = 'c'

Add 'c' to s_freq: s_freq = [0, 0, 1, 0, ..., 0]
Window size j - i + 1 = 1 < p_len = 3, move j to 1.
Step 2: j = 1, character = 'b'

Add 'b' to s_freq: s_freq = [0, 1, 1, 0, ..., 0]
Window size j - i + 1 = 2 < p_len = 3, move j to 2.
Step 3: j = 2, character = 'a'

Add 'a' to s_freq: s_freq = [1, 1, 1, 0, ..., 0]
Window size j - i + 1 = 3 = p_len = 3
Compare s_freq with p_freq. They are equal, so add i = 0 to result: result = [0]
Slide the window by removing 'c' from s_freq: s_freq = [1, 1, 0, 0, ..., 0]
Move i to 1 and j to 3.
Step 4: j = 3, character = 'e'

Add 'e' to s_freq: s_freq = [1, 1, 0, 0, 1, ..., 0]
Window size j - i + 1 = 3
s_freq does not match p_freq. Slide the window by removing 'b': s_freq = [1, 0, 0, 0, 1, ..., 0]
Move i to 2 and j to 4.
Step 5: j = 4, character = 'b'

Add 'b' to s_freq: s_freq = [1, 1, 0, 0, 1, ..., 0]
Window size j - i + 1 = 3
s_freq does not match p_freq. Slide the window by removing 'a': s_freq = [0, 1, 0, 0, 1, ..., 0]
Move i to 3 and j to 5.
Step 6: j = 5, character = 'a'

Add 'a' to s_freq: s_freq = [1, 1, 0, 0, 1, ..., 0]
Window size j - i + 1 = 3
s_freq does not match p_freq. Slide the window by removing 'e': s_freq = [1, 1, 0, 0, 0, ..., 0]
Move i to 4 and j to 6.
Step 7: j = 6, character = 'b'

Add 'b' to s_freq: s_freq = [1, 2, 0, 0, 0, ..., 0]
Window size j - i + 1 = 3
s_freq does not match p_freq. Slide the window by removing 'b': s_freq = [1, 1, 0, 0, 0, ..., 0]
Move i to 5 and j to 7.
Step 8: j = 7, character = 'a'

Add 'a' to s_freq: s_freq = [2, 1, 0, 0, 0, ..., 0]
Window size j - i + 1 = 3
s_freq does not match p_freq. Slide the window by removing 'a': s_freq = [1, 1, 0, 0, 0, ..., 0]
Move i to 6 and j to 8.
Step 9: j = 8, character = 'c'

Add 'c' to s_freq: s_freq = [1, 1, 1, 0, 0, ..., 0]
Window size j - i + 1 = 3
s_freq matches p_freq, so add i = 6 to result: result = [0, 6]
Slide the window by removing 'b': s_freq = [1, 0, 1, 0, 0, ..., 0]
Move i to 7 and j to 9.
Step 10: j = 9, character = 'd'

Add 'd' to s_freq: s_freq = [1, 0, 1, 1, 0, ..., 0]
Window size j - i + 1 = 3
s_freq does not match p_freq. Slide the window by removing 'a': s_freq = [0, 0, 1, 1, 0, ..., 0]
Move i to 8 and `





Time complexity: O(n), where n is the length of string s. We traverse s once, and comparing frequency maps takes O(1) time since their size is constant (26 for lowercase English letters).
Space complexity: O(1) for the frequency arrays of fixed size 26.
