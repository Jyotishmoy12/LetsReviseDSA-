Problem Description: Number of Common Characters
Given two strings, you need to find the number of characters that appear in both strings, including duplicates. For example, if a character appears twice in both strings, it should be counted twice.

Approach and Intuition
The problem is about finding the common characters between two strings, taking into account their frequencies. This can be effectively solved using hash maps (or arrays, since the characters are limited).

Steps to Solve:
Count the Frequency:

Use two arrays (or hash maps) to count the frequency of each character in both strings. Each array will have 26 elements, corresponding to each letter of the alphabet.
Find the Minimum Count:

For each character in the alphabet, find the minimum frequency between the two strings. This minimum represents the number of common characters for that specific character.
Sum the Minimum Counts:

Sum up all the minimum frequencies to get the total number of common characters.
Example Test Cases
Test Case 1:
Input:
s1 = "aabcc"
s2 = "adcaa"
Explanation:
s1 has a:2, b:1, c:2
s2 has a:3, d:1, c:1
Common characters:
a appears in both strings with minimum frequency 2.
c appears in both strings with minimum frequency 1.
So the answer is 2 (from 'a') + 1 (from 'c') = 3.
Output:
3
Test Case 2:
Input:
s1 = "abc"
s2 = "xyz"
Explanation:
s1 has a:1, b:1, c:1
s2 has x:1, y:1, z:1
No characters are common between the two strings.
Output:
0
Test Case 3:
Input:
s1 = "abbccc"
s2 = "bccbb"
Explanation:
s1 has a:1, b:2, c:3
s2 has b:2, c:2
Common characters:
b appears in both strings with minimum frequency 2.
c appears in both strings with minimum frequency 2.
So the answer is 2 (from 'b') + 2 (from 'c') = 4.
Output:
4



  #include <iostream>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

int numberOfCommonCharacters(string s1, string s2) {
    map<char, int> freqMap1;  // Frequency map for s1
    map<char, int> freqMap2;  // Frequency map for s2

    // Count frequencies in s1
    for (char c : s1) {
        freqMap1[c]++;
    }

    // Count frequencies in s2
    for (char c : s2) {
        freqMap2[c]++;
    }

    // Calculate the total number of common characters
    int commonCount = 0;
    for (auto it = freqMap1.begin(); it != freqMap1.end(); ++it) {
        char ch = it->first;
        int countInS1 = it->second;

        if (freqMap2.find(ch) != freqMap2.end()) {
            int countInS2 = freqMap2[ch];
            commonCount += min(countInS1, countInS2);
        }
    }

    return commonCount;
}

int main() {
    // Test cases
    string s1 = "aabcc";
    string s2 = "adcaa";
    cout << "Number of common characters: " << numberOfCommonCharacters(s1, s2) << endl; // Output: 3

    s1 = "abc";
    s2 = "xyz";
    cout << "Number of common characters: " << numberOfCommonCharacters(s1, s2) << endl; // Output: 0

    s1 = "abbccc";
    s2 = "bccbb";
    cout << "Number of common characters: " << numberOfCommonCharacters(s1, s2) << endl; // Output: 4

    return 0;
}



Why Use min?
Consider the problem: you need to find the total number of characters that are common in both strings, including duplicates. If a character appears multiple times in one string and fewer times in the other, the number of common characters for that particular character is limited by the lesser occurrence.

Example to Illustrate:
Let's say we have two strings:

s1 = "abbccc"
s2 = "bccbb"
Frequency Counts:

s1 has:
a: 1
b: 2
c: 3
s2 has:
b: 2
c: 2
Common Characters Calculation:

For character 'b':
s1 has 2 occurrences.
s2 has 2 occurrences.
The number of common 'b's is min(2, 2) = 2.
For character 'c':
s1 has 3 occurrences.
s2 has 2 occurrences.
The number of common 'c's is min(3, 2) = 2.
If we didn't use min, we might mistakenly count more occurrences of a character than actually appear in both strings. For example, 
  if we took the frequency of 'c' from s1 (which is 3) instead of using min, we'd incorrectly assume 3 common 'c's exist when s2 only has 2.
