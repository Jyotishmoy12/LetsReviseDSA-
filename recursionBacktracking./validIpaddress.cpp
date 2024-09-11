Problem: Valid IP Addresses
Given a string containing only digits, return all possible valid IP addresses that can be formed by inserting periods at appropriate positions. An IP address consists of four segments, and each segment must be a number between 0 and 255. Additionally, a segment cannot have leading zeros unless it's exactly 0.

Example 1:
Input: "25525511135"
Output: ["255.255.11.135", "255.255.111.35"]
Explanation: The input string can be split to form the valid IP addresses 255.255.11.135 and 255.255.111.35.
Example 2:
Input: "0000"
Output: ["0.0.0.0"]
Explanation: The only valid IP address that can be formed is 0.0.0.0.
Example 3:
Input: "101023"
Output: ["1.0.10.23", "1.0.102.3", "10.1.0.23", "10.10.2.3", "101.0.2.3"]
Constraints:
The string length is between 4 and 12, inclusive.
The string contains only digits.
Approach:
This problem is a backtracking problem where we try placing periods at various positions in the string to form valid IP addresses. To construct valid IPs, we need to break the string into four parts, each of which should be a valid number between 0 and 255, and should not have leading zeros unless it is exactly 0.

Key Conditions:

Each segment of the IP should be a number between 0 and 255.
A segment should not have leading zeros unless it is exactly 0 (e.g., "01" is invalid).
The string should be broken into exactly four parts (since an IP address consists of four segments).
We can use recursion and backtracking to solve this problem:

Recursively try placing periods between different positions of the string.
For each recursive call, we check if the current segment is valid.
If the segment is valid, proceed with the next part of the string; otherwise, backtrack.
Algorithm Steps:
Base Case: If we have placed 4 segments and used up all characters in the string, we check if it forms a valid IP address.
Recursion: For each segment, check if the substring is valid (i.e., between 0 and 255 and has no leading zeros). If valid, recursively place the next period and proceed with the next segment.
Backtracking: If a segment is invalid or we cannot place more than 4 periods, we backtrack and try different placements of periods.
Dry Run:
Let's dry run the algorithm with the input "25525511135".

Start by trying to place the first period:

Segment 1: "2", proceed with 5525511135.
Segment 1: "25", proceed with 525511135.
Segment 1: "255", proceed with 25511135.
Now we try placing the second period:

Segment 2: "2", proceed with 552511135.
Segment 2: "25", proceed with 52511135.
Segment 2: "255", proceed with 11135.
We continue this process recursively, backtracking when an invalid segment is found, until all valid IP addresses are generated.

Code in C++:
cpp
Copy code
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    // Helper function to check if a segment is valid
    bool isValid(const string& s) {
        // If the segment has leading zeroes, it's invalid (except for "0")
        if (s.length() > 1 && s[0] == '0') return false;
        // Convert the string to an integer and check the range [0, 255]
        int num = stoi(s);
        return num >= 0 && num <= 255;
    }

    // Recursive backtracking function to generate IPs
    void backtrack(const string& s, int start, vector<string>& path, vector<string>& result) {
        // Base case: if we have exactly 4 segments and used up the entire string
        if (path.size() == 4 && start == s.length()) {
            // Join the segments to form a valid IP address
            result.push_back(path[0] + "." + path[1] + "." + path[2] + "." + path[3]);
            return;
        }

        // Early termination: If we've already used 4 segments and haven't finished the string
        if (path.size() == 4) return;

        // Try splitting the remaining string into segments of length 1 to 3
        for (int len = 1; len <= 3; ++len) {
            // Ensure we don't exceed the string's length
            if (start + len > s.length()) break;
            // Extract the current segment
            string segment = s.substr(start, len);
            // Check if the segment is valid
            if (isValid(segment)) {
                path.push_back(segment);               // Add the segment to the current path
                backtrack(s, start + len, path, result); // Recur for the remaining string
                path.pop_back();                       // Backtrack by removing the last segment
            }
        }
    }

    vector<string> restoreIpAddresses(string s) {
        vector<string> result;
        vector<string> path;
        backtrack(s, 0, path, result);
        return result;
    }
};

int main() {
    Solution sol;
    string input = "25525511135";  // Example input
    vector<string> result = sol.restoreIpAddresses(input);

    cout << "Valid IP addresses:\n";
    for (const string& ip : result) {
        cout << ip << endl;
    }
    return 0;
}
Code Explanation:
Helper Function (isValid):

This function checks if a given string segment can form a valid IP address component.
It checks for leading zeros (invalid unless the segment is "0").
It converts the string to an integer and ensures it's between 0 and 255.
Recursive Backtracking Function (backtrack):

The function tries to split the string s into valid segments.
It starts at a given index start and tries to form segments of lengths 1, 2, and 3.
For each valid segment, it recursively tries to split the remaining part of the string.
If four valid segments are found and all characters are used, a valid IP address is formed by joining the segments with periods.
Main Function (restoreIpAddresses):

This function initializes the result vector and starts the recursive backtracking process.
Dry Run with Example 25525511135:
Input: "25525511135"

Start with the empty path [].
Try segments of length 1, 2, and 3:
First segment "255" is valid. Move to the next part: "25511135".
Try the next segment:
Second segment "255" is valid. Move to the next part: "11135".
Try the next segment:
Third segment "11" is valid. Move to the next part: "135".
Try the next segment:
Fourth segment "135" is valid. Form the IP address 255.255.11.135.
Backtrack to try other possible splits and form the second valid IP: 255.255.111.35.
Result: ["255.255.11.135", "255.255.111.35"]

Time Complexity:
The time complexity is O(1) because the maximum number of valid IP addresses is limited by the length of the string (a fixed size of up to 12 characters).
For each possible placement of periods, there are a constant number of possibilities, making this a bounded problem.
Space Complexity:
The space complexity is O(1) as well, since we are storing a limited number of IP addresses and each IP address has a fixed length.
