Problem: Check if One String is a Rotation of Another
Problem Statement: Given two strings s1 and s2, check if s2 is a rotation of s1. A rotation of a string means that the string can be obtained by shifting the characters of the original string by any number of positions. For example, "abcde" is a rotation of "cdeab".

Key Idea:
To check if s2 is a rotation of s1, you can concatenate s1 with itself. If s2 is a rotation of s1, then s2 should appear as a substring of the concatenated string s1 + s1.

Approach:
If the lengths of s1 and s2 are not equal, return false as they can't be rotations of each other.
Concatenate s1 with itself (i.e., s1 + s1).
Check if s2 is a substring of s1 + s1.
Dry Run:
Consider the input strings s1 = "abcde" and s2 = "cdeab":

s1 = "abcde"
Concatenate s1 with itself: s1 + s1 = "abcdeabcde"
Check if s2 = "cdeab" is a substring of s1 + s1 = "abcdeabcde".
It is, so the answer is true.
Code in C++:
cpp
Copy code
#include <iostream>
#include <string>
using namespace std;

bool isRotation(string s1, string s2) {
    // If lengths are different, they can't be rotations of each other
    if (s1.length() != s2.length()) {
        return false;
    }

    // Concatenate s1 with itself
    string s1s1 = s1 + s1;

    // Check if s2 is a substring of the concatenated string s1 + s1
    return s1s1.find(s2) != string::npos;
}

int main() {
    string s1 = "abcde";
    string s2 = "cdeab";

    if (isRotation(s1, s2)) {
        cout << "Yes, " << s2 << " is a rotation of " << s1 << endl;
    } else {
        cout << "No, " << s2 << " is not a rotation of " << s1 << endl;
    }

    return 0;
}
Explanation of the Code:
Check Lengths: First, we compare the lengths of s1 and s2. If they are different, we return false because strings of different lengths cannot be rotations of each other.
Concatenate s1 with itself: We create a new string s1s1 = s1 + s1 that contains two copies of s1.
Check Substring: We use find() to check if s2 appears as a substring of s1s1. If find() returns a value other than string::npos, it means s2 is a substring of s1s1, and hence s2 is a rotation of s1.
Time and Space Complexity:
Time Complexity: O(n), where n is the length of the strings. The find() operation on a string takes O(n) time in the worst case, and the concatenation of the string also takes O(n).
Space Complexity: O(n), where n is the length of s1 (since we're concatenating the string with itself, which requires extra space for the new string s1s1).
