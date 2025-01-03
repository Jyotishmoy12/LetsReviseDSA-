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
This solution works efficiently for typical string lengths and avoids unnecessary complexity.






You said:
4. **String Transforms into Another String**  
   - **Problem**: Check if one string can be transformed into another using a mapping of characters.  
   - **Key Idea**: Use a hash map to record transformations and validate consistency.
ChatGPT said:
ChatGPT
Problem: String Transforms into Another String
Problem Statement: Given two strings s1 and s2, check if s1 can be transformed into s2 using a mapping of characters. That is, there exists a one-to-one character mapping between s1 and s2. Each character in s1 must be mapped to exactly one character in s2 and vice versa.

Key Idea:
To solve this problem, we can use two hash maps to track the mappings between characters in s1 and s2. If a character from s1 maps to multiple characters in s2 or vice versa, then the transformation is not possible. Therefore, we validate the consistency of the mapping between the two strings.

Approach:
If the lengths of s1 and s2 are not equal, return false, as they cannot be transformed into each other.
Create two hash maps:
map1: Maps characters from s1 to characters in s2.
map2: Maps characters from s2 to characters in s1 (to ensure a one-to-one mapping).
Traverse both strings character by character:
For each character c1 from s1 and c2 from s2, check if there is an existing mapping:
If c1 is already mapped to a character in map1, verify if it maps to the same character c2.
Similarly, if c2 is already mapped to a character in map2, verify if it maps to the same character c1.
If the mappings are consistent throughout the strings, return true, otherwise return false.
Dry Run:
Let’s take an example:

s1 = "egg"
s2 = "add"
Check Lengths: Both strings have the same length, so we proceed.
Initial Mappings:
map1 = {} (maps characters from s1 to s2)
map2 = {} (maps characters from s2 to s1)
Traverse Strings:
First iteration (c1 = 'e', c2 = 'a'):
e is not in map1, so we add the mapping map1['e'] = 'a'.
a is not in map2, so we add the mapping map2['a'] = 'e'.
Updated maps: map1 = {'e': 'a'}, map2 = {'a': 'e'}.
Second iteration (c1 = 'g', c2 = 'd'):
g is not in map1, so we add the mapping map1['g'] = 'd'.
d is not in map2, so we add the mapping map2['d'] = 'g'.
Updated maps: map1 = {'e': 'a', 'g': 'd'}, map2 = {'a': 'e', 'd': 'g'}.
Third iteration (c1 = 'g', c2 = 'd'):
g is already in map1 and maps to d, which is consistent.
d is already in map2 and maps to g, which is consistent.
No changes to maps.
Final Mappings:
map1 = {'e': 'a', 'g': 'd'}
map2 = {'a': 'e', 'd': 'g'}
Since all mappings are consistent, the answer is true.

Code in C++:
cpp
Copy code
#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

bool canTransform(string s1, string s2) {
    // If lengths are different, they can't be transformed into each other
    if (s1.length() != s2.length()) {
        return false;
    }

    // Hash maps to track character mappings from s1 to s2 and vice versa
    unordered_map<char, char> map1;
    unordered_map<char, char> map2;

    // Traverse both strings character by character
    for (int i = 0; i < s1.length(); i++) {
        char c1 = s1[i];
        char c2 = s2[i];

        // If c1 has already been mapped, check if it maps to the same character as before
        if (map1.find(c1) != map1.end()) {
            if (map1[c1] != c2) {
                return false;
            }
        } else {
            map1[c1] = c2;
        }

        // If c2 has already been mapped, check if it maps to the same character as before
        if (map2.find(c2) != map2.end()) {
            if (map2[c2] != c1) {
                return false;
            }
        } else {
            map2[c2] = c1;
        }
    }

    return true;
}

int main() {
    string s1 = "egg";
    string s2 = "add";

    if (canTransform(s1, s2)) {
        cout << "Yes, " << s1 << " can be transformed into " << s2 << endl;
    } else {
        cout << "No, " << s1 << " cannot be transformed into " << s2 << endl;
    }

    return 0;
}
Explanation of the Code:
Check Lengths: If s1 and s2 have different lengths, return false.
Create Hash Maps: We create two unordered maps map1 and map2:
map1 is used to track the mapping from characters in s1 to s2.
map2 is used to track the mapping from characters in s2 to s1.
Traverse Strings: For each character pair (c1, c2) from s1 and s2, we check if the mappings are consistent:
If c1 is already mapped, check if it maps to the same c2. If not, return false.
Similarly, if c2 is already mapped, check if it maps to the same c1. If not, return false.
If both mappings are consistent, we add them to the respective maps.
Return True: If we reach the end of the strings without finding any inconsistencies, return true.
Time and Space Complexity:
Time Complexity: O(n), where n is the length of the strings. We traverse each string once, and the hash map operations (insert and lookup) take constant time on average.
Space Complexity: O(n), where n is the length of the strings. We use two hash maps to store the mappings of characters from both strings.
