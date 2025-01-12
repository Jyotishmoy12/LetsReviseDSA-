Problem Statement:
You are given a string s and an integer k. Your task is to rearrange the characters of the string such that no two adjacent characters are the same. Additionally, each character should appear at least k distance apart from its previous occurrence.

You need to return the rearranged string, or if it is not possible, return an empty string.

Example:
Input:

makefile
Copy code
s = "aabbcc", k = 3
Output:

arduino
Copy code
"abcabc"
Explanation:

The characters 'a', 'b', and 'c' appear at least k distance apart, so the string is rearranged successfully.
Input:

makefile
Copy code
s = "aaabc", k = 3
Output:

arduino
Copy code
""
Explanation:

It is not possible to rearrange the string so that no two adjacent characters are the same and they are at least k distance apart.
Intuition:
The problem essentially requires us to maintain a "cooling period" for each character, meaning after placing a character, we need to wait k positions before we can use it again. A greedy strategy will be helpful in this case.

The main idea is to:

Count the frequency of each character: We need to know how many times each character appears.
Use a priority queue: We can pick the character with the highest remaining frequency at each step and place it in the result string.
Cool down the used characters: After using a character, we temporarily "cool it down" by pushing it into a queue until it can be used again.
Approach:
Frequency Count: First, count the frequency of each character in the input string s. We will store the frequencies in a max-heap (priority queue).

Priority Queue: Use a priority queue (max-heap) where characters with the highest frequency are prioritized. This ensures that we always try to use the most frequent character first, which will help in reducing the possibility of characters being adjacent.

Result Construction: Start constructing the output string by:

Extracting the character with the highest frequency from the heap.
Placing it in the result string.
Decreasing its frequency and if the frequency is still non-zero, pushing it into a temporary queue for "cooling down".
Cool Down Queue: Maintain a temporary queue to track characters that need to cool down. After placing a character, store it in the queue with a counter for how long it needs to stay out of the heap.

Final Output: If, after processing, the heap is empty and we've constructed a valid string, return it. Otherwise, return an empty string.

C++ Code:
cpp
Copy code
#include <iostream>
#include <unordered_map>
#include <queue>
#include <vector>
#include <string>
using namespace std;

string rearrangeString(string s, int k) {
    if (k == 0) return s; // If k is 0, no restriction on adjacency
    
    unordered_map<char, int> freqMap;
    
    // Step 1: Count the frequency of each character
    for (char c : s) {
        freqMap[c]++;
    }
    
    // Step 2: Use a priority queue to store the characters by their frequencies
    priority_queue<pair<int, char>> maxHeap;
    for (auto& entry : freqMap) {
        maxHeap.push({entry.second, entry.first});
    }
    
    // Step 3: Construct the result
    string result = "";
    queue<pair<int, char>> coolDownQueue; // Temporary queue for cooling down characters
    
    while (!maxHeap.empty()) {
        auto current = maxHeap.top();
        maxHeap.pop();
        result += current.second;
        
        // Add the character to the cool down queue with reduced frequency
        coolDownQueue.push({current.first - 1, current.second});
        
        // Step 4: Refill the heap after the cooldown period
        if (coolDownQueue.size() >= k) {
            auto front = coolDownQueue.front();
            coolDownQueue.pop();
            if (front.first > 0) {
                maxHeap.push(front); // Push back if the character still has remaining frequency
            }
        }
    }
    
    // Step 5: If the result length matches the original string length, return the result
    return result.size() == s.size() ? result : "";
}

int main() {
    string s = "aabbcc";
    int k = 3;
    cout << "Rearranged String: " << rearrangeString(s, k) << endl;
    return 0;
}
Dry Run:
Let's dry run the above code using the example input s = "aabbcc" and k = 3:

Frequency Count:

css
Copy code
freqMap = {'a': 2, 'b': 2, 'c': 2}
Building the Max-Heap: The heap will store the characters with the highest frequency at the top:

arduino
Copy code
maxHeap = { (2, 'a'), (2, 'b'), (2, 'c') }
Start Constructing the String:

First, we pop (2, 'a') from the heap, append 'a' to the result, and decrement its frequency to 1.
Result = "a"
coolDownQueue = {(1, 'a')}
Then, we pop (2, 'b'), append 'b' to the result, and decrement its frequency to 1.
Result = "ab"
coolDownQueue = {(1, 'a'), (1, 'b')}
Next, we pop (2, 'c'), append 'c' to the result, and decrement its frequency to 1.
Result = "abc"
coolDownQueue = {(1, 'a'), (1, 'b'), (1, 'c')}
Refill the heap after the cool down period:
Cool down queue has 3 characters, so we remove (1, 'a') from the queue and push it back into the heap.
Now the heap looks like: {(1, 'a'), (1, 'b'), (1, 'c')}
Now the process repeats with the same steps:
Result = "abcabc"
Final String: After the heap is empty, the result is "abcabc", which is valid.

Complexity Analysis:
Time Complexity:

The frequency map construction takes O(n) time, where n is the length of the string s.
The heap operations (insert and extract) take O(log m) time, where m is the number of unique characters (at most 26).
The overall time complexity is O(n log m), where n is the length of the string and m is the number of unique characters (constant for lowercase English letters).
Space Complexity:

The space complexity is O(n + m), where n is the length of the string (for the result and queue) and m is the number of unique characters (for the frequency map and heap).
