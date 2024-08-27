Problem Statement: Given two strings, determine if one is an anagram of the other. Two strings are anagrams if they contain the same characters with the same frequencies but possibly in different orders.

Approach and Intuition
To determine if two strings are anagrams:

Count Character Frequencies:

Use hash maps (or hash tables) to count the frequency of each character in both strings.
Compare Frequency Maps:

Compare the two frequency maps. If they are equal, the strings are anagrams; otherwise, they are not.
Steps to Solve:
Check Lengths:

If the lengths of the two strings are different, they cannot be anagrams.
Create Frequency Maps:

Create two hash maps, one for each string, to count the occurrences of each character.
Compare Frequency Maps:

Compare the two hash maps. If they are identical, the strings are anagrams.
Example Test Cases
Test Case 1:
Input:
s1 = "listen"
s2 = "silent"
Explanation:
s1 contains the characters l, i, s, t, e, n.
s2 contains the characters s, i, l, e, t, n.
Both strings have the same characters with the same frequencies.
Output:
True
Test Case 2:
Input:
s1 = "triangle"
s2 = "integral"
Explanation:
s1 contains the characters t, r, i, a, n, g, l, e.
s2 contains the characters i, n, t, e, g, r, a, l.
Both strings have the same characters with the same frequencies.
Output:
True
Test Case 3:
Input:
s1 = "hello"
s2 = "world"
Explanation:
s1 contains the characters h, e, l, l, o.
s2 contains the characters w, o, r, l, d.
The characters and their frequencies do not match.
Output:
False

#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

// Function to check if two strings are anagrams
bool areAnagrams(const string& s1, const string& s2) {
    if (s1.length() != s2.length()) {
        return false; // Different lengths cannot be anagrams
    }

    unordered_map<char, int> freqMap1;
    unordered_map<char, int> freqMap2;

    // Count frequencies for s1
    for (char c : s1) {
        freqMap1[c]++;
    }

    // Count frequencies for s2
    for (char c : s2) {
        freqMap2[c]++;
    }

    // Compare the two frequency maps
    return freqMap1 == freqMap2;
}

int main() {
    // Test cases
    string s1 = "listen";
    string s2 = "silent";
    cout << "Are \"" << s1 << "\" and \"" << s2 << "\" anagrams? " 
         << (areAnagrams(s1, s2) ? "Yes" : "No") << endl; // Output: Yes

    string s3 = "triangle";
    string s4 = "integral";
    cout << "Are \"" << s3 << "\" and \"" << s4 << "\" anagrams? " 
         << (areAnagrams(s3, s4) ? "Yes" : "No") << endl; // Output: Yes

    string s5 = "hello";
    string s6 = "world";
    cout << "Are \"" << s5 << "\" and \"" << s6 << "\" anagrams? " 
         << (areAnagrams(s5, s6) ? "Yes" : "No") << endl; // Output: No

    return 0;
}




