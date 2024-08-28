Separate Even and Odd Numbers

Problem: Given an unsorted array, separate the even and odd numbers such that all even numbers appear before all odd numbers. The relative order within the even and odd groups does not need to be maintained.
Intuition: Use two pointers, one at the start and one at the end, to swap even numbers to the front and odd numbers to the back.

#include <iostream>
#include <vector>

using namespace std;

void separateEvenOdd(vector<int>& arr) {
    int left = 0;
    int right = arr.size() - 1;

    while (left < right) {
        while (arr[left] % 2 == 0 && left < right) {
            left++;
        }
        while (arr[right] % 2 == 1 && left < right) {
            right--;
        }
        if (left < right) {
            swap(arr[left], arr[right]);
            left++;
            right--;
        }
    }
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    
    separateEvenOdd(arr);
    
    // Output the result
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
    
    return 0;
}


Initial array:
Copyarr = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12]
       ^                                   ^
     left                                right
Step 1:

left (1) is odd, stays
right (12) is even, stays
Swap: [12, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 1]
Move both pointers: left++, right--

Copyarr = [12, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 1]
           ^                              ^
         left                           right
Step 2:

left (2) is even, moves right: left++
right (11) is odd, moves left: right--

Copyarr = [12, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 1]
              ^                   ^
            left                right
Step 3:

left (3) is odd, stays
right (10) is even, stays
Swap: [12, 2, 10, 4, 5, 6, 7, 8, 9, 3, 11, 1]
Move both pointers: left++, right--

Copyarr = [12, 2, 10, 4, 5, 6, 7, 8, 9, 3, 11, 1]
                 ^              ^
               left           right
Step 4:

left (4) is even, moves right: left++
right (9) is odd, moves left: right--

Copyarr = [12, 2, 10, 4, 5, 6, 7, 8, 9, 3, 11, 1]
                    ^        ^
                  left     right
Step 5:

left (5) is odd, stays
right (8) is even, stays
Swap: [12, 2, 10, 4, 8, 6, 7, 5, 9, 3, 11, 1]
Move both pointers: left++, right--

Copyarr = [12, 2, 10, 4, 8, 6, 7, 5, 9, 3, 11, 1]
                       ^  ^
                     left right
Step 6:

left (6) is even, moves right: left++
right (7) is odd, moves left: right--

Copyarr = [12, 2, 10, 4, 8, 6, 7, 5, 9, 3, 11, 1]
                          ^
                       left,right
The algorithm terminates as left is no longer less than right.
Final array:
Copyarr = [12, 2, 10, 4, 8, 6, 7, 5, 9, 3, 11, 1]


