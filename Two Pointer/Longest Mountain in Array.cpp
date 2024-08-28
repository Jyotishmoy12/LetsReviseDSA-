Problem:
Given an array of integers, you need to find the length of the longest "mountain." A "mountain" is defined as a subarray of at least three elements that strictly increases to a peak element and then strictly decreases.

Intuition:
To solve this problem, we can use a two-pointer approach. The idea is to identify the peak of the mountain, then extend the pointers outward to find the start and end of the mountain. By tracking the maximum length of all such mountains, we can determine the longest one.

Approach
Identify Peaks:

A peak in the array is an element arr[i] such that arr[i-1] < arr[i] > arr[i+1].
To find the longest mountain, iterate through the array and identify peaks.
Expand Around the Peak:

Once a peak is identified, use two pointers to expand leftward and rightward to determine the boundaries of the mountain.
The mountain starts when the sequence stops increasing on the left and ends when the sequence stops decreasing on the right.
Track Maximum Length:

For each mountain found, calculate its length and update the maximum length if this mountain is longer.


Test Case
Input:
arr = [1, 2, 3, 4, 3, 2, 1, 0, 2, 4, 3, 1, 5, 6, 7, 8, 9, 8, 7, 6]

Explanation:

This array contains mountains at various positions, including the beginning, middle, and end of the array.
The peaks are at indexes where the mountain's increasing and decreasing parts are clearly visible.
Expected Output
The longest mountain is [1, 2, 4, 3, 2, 1], starting at index 6 and ending at index 11, with a length of 6.
Dry Run
Step-by-Step Process:

Initialization:

n = 20 (length of the array).
max_length = 0 (to track the maximum length of the mountain).
Iterate Through the Array:

Iteration 1 (i = 1):

arr[1] = 2, arr[0] < arr[1] < arr[2] — Not a peak.
Iteration 2 (i = 2):

arr[2] = 3, arr[1] < arr[2] < arr[3] — Not a peak.
Iteration 3 (i = 3):

arr[3] = 4, arr[2] < arr[3] > arr[4] — Peak at index 3.
Expand Leftward:
Start at index 2 (arr[2] = 3), continue to arr[1] = 2 and arr[0] = 1 — stop as the sequence is non-increasing.
Left boundary = 0.
Expand Rightward:
Start at index 4 (arr[4] = 3), continue to arr[5] = 2 and arr[6] = 1 — stop as the sequence is non-increasing.
Right boundary = 6.
Length of the mountain: 6 (from index 0 to 6).
Update max_length = 6.
Iteration 4 (i = 4) to Iteration 6 (i = 6):

Continue checking but no new peak found.
Iteration 7 (i = 7):

arr[7] = 0, arr[6] > arr[7] < arr[8] — Not a peak.
Iteration 8 (i = 8):

arr[8] = 2, arr[7] < arr[8] < arr[9] — Not a peak.
Iteration 9 (i = 9):

arr[9] = 4, arr[8] < arr[9] > arr[10] — Peak at index 9.
Expand Leftward:
Start at index 8 (arr[8] = 2), continue to arr[7] = 0 — stop as the sequence is non-increasing.
Left boundary = 7.
Expand Rightward:
Start at index 10 (arr[10] = 3), continue to arr[11] = 1 — stop as the sequence is non-increasing.
Right boundary = 11.
Length of the mountain: 5 (from index 7 to 11).
max_length remains 6.
Iteration 10 (i = 10) to Iteration 12 (i = 12):

Continue checking but no new peak found.
Iteration 13 (i = 13):

arr[13] = 6, arr[12] < arr[13] > arr[14] — Peak at index 13.
Expand Leftward:
Start at index 12 (arr[12] = 5), continue to arr[11] = 1, arr[10] = 3, arr[9] = 4, and arr[8] = 2 — stop as the sequence is non-increasing.
Left boundary = 7.
Expand Rightward:
Start at index 14 (arr[14] = 7), continue to arr[15] = 8, arr[16] = 9, arr[17] = 8, arr[18] = 7, and arr[19] = 6 — stop as the sequence is non-increasing.
Right boundary = 19.
Length of the mountain: 13 (from index 7 to 19).
Update max_length = 13.
Iteration 14 (i = 14) to Iteration 18 (i = 18):

Continue checking but no new peak found.
Final Output:

The longest mountain found is of length 13, from index 7 to 19.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int longestMountain(vector<int>& arr) {
    int n = arr.size();
    int max_length = 0;

    // Iterate through the array to find peaks
    for (int i = 1; i < n - 1; i++) {
        // Check if arr[i] is a peak
        if (arr[i] > arr[i - 1] && arr[i] > arr[i + 1]) {
            // Expand leftward to find the start of the mountain
            int left = i - 1;
            while (left > 0 && arr[left] > arr[left - 1]) {
                left--;
            }

            // Expand rightward to find the end of the mountain
            int right = i + 1;
            while (right < n - 1 && arr[right] > arr[right + 1]) {
                right++;
            }

            // Calculate the length of the mountain
            int length = right - left + 1;
            max_length = max(max_length, length);
        }
    }

    return max_length;
}

int main() {
    vector<int> arr = {2, 1, 4, 7, 3, 2, 5};
    int longest_mountain = longestMountain(arr);
    cout << "Longest mountain length: " << longest_mountain << endl; // Output should be 5

    return 0;
}


Why Start the Left Pointer from i-1:

Definition of a Mountain:

A mountain is defined as a subarray where elements first strictly increase to a peak and then strictly decrease. To find the full extent of this mountain, you need to know how far you can extend the subarray on both sides of the peak.

