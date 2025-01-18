Problem Statement: Frequency Stack
Design a data structure that supports the following operations efficiently:

Push(x): Pushes an integer x onto the stack.
Pop(): Removes and returns the most frequent element in the stack.
If there is a tie for frequency, return the element closest to the top of the stack.
Intuition
To implement a frequency stack, we need to:

Track the frequency of each element in the stack.
Be able to retrieve the most frequent element efficiently.
If multiple elements share the same frequency, we need to retrieve the one that was most recently added.
To achieve this:

Use a hash map (freqMap) to store the frequency of each element.
Use another hash map of stacks (groupMap) where the key is the frequency, and the value is a stack of all elements with that frequency.
Maintain a variable maxFreq to keep track of the current maximum frequency.
Approach
Data Structures:

freqMap: A hash map to store the frequency of each element.
groupMap: A hash map where keys are frequencies and values are stacks of elements.
maxFreq: Tracks the maximum frequency in the stack at any given time.
Push Operation:

Increment the frequency of the element in freqMap.
Add the element to the stack in groupMap corresponding to its frequency.
Update maxFreq if the new frequency exceeds the current maxFreq.
Pop Operation:

Retrieve the stack corresponding to maxFreq in groupMap and pop the top element.
Decrease the frequency of the popped element in freqMap.
If the stack for maxFreq becomes empty, decrement maxFreq.
Code in C++
cpp
Copy
Edit
#include <iostream>
#include <unordered_map>
#include <stack>
using namespace std;

class FreqStack {
private:
    unordered_map<int, int> freqMap; // Map to track frequency of elements
    unordered_map<int, stack<int>> groupMap; // Map of stacks grouped by frequency
    int maxFreq = 0; // Tracks the maximum frequency

public:
    // Function to push an element into the frequency stack
    void push(int x) {
        // Increment the frequency of the element
        freqMap[x]++;
        int freq = freqMap[x];
        
        // Update maxFreq if necessary
        maxFreq = max(maxFreq, freq);
        
        // Add the element to the stack corresponding to its frequency
        groupMap[freq].push(x);
    }

    // Function to pop the most frequent element
    int pop() {
        // Get the stack corresponding to the current max frequency
        int x = groupMap[maxFreq].top();
        groupMap[maxFreq].pop();
        
        // Decrease the frequency of the popped element
        freqMap[x]--;
        
        // If the stack for maxFreq becomes empty, reduce maxFreq
        if (groupMap[maxFreq].empty()) {
            maxFreq--;
        }
        
        return x;
    }
};

int main() {
    FreqStack freqStack;

    freqStack.push(5);
    freqStack.push(7);
    freqStack.push(5);
    freqStack.push(7);
    freqStack.push(4);
    freqStack.push(5);

    cout << freqStack.pop() << endl; // 5 (most frequent)
    cout << freqStack.pop() << endl; // 7 (most frequent)
    cout << freqStack.pop() << endl; // 5 (most frequent)
    cout << freqStack.pop() << endl; // 4 (most recent)
    return 0;
}
Dry Run
Input Operations:
Push: 5, 7, 5, 7, 4, 5
Pop: 4 times

After Each Push:
Push 5:

freqMap: {5: 1}
groupMap: {1: [5]}
maxFreq: 1
Push 7:

freqMap: {5: 1, 7: 1}
groupMap: {1: [5, 7]}
maxFreq: 1
Push 5:

freqMap: {5: 2, 7: 1}
groupMap: {1: [5, 7], 2: [5]}
maxFreq: 2
Push 7:

freqMap: {5: 2, 7: 2}
groupMap: {1: [5, 7], 2: [5, 7]}
maxFreq: 2
Push 4:

freqMap: {5: 2, 7: 2, 4: 1}
groupMap: {1: [5, 7, 4], 2: [5, 7]}
maxFreq: 2
Push 5:

freqMap: {5: 3, 7: 2, 4: 1}
groupMap: {1: [5, 7, 4], 2: [5, 7], 3: [5]}
maxFreq: 3
After Each Pop:
Pop:

Pop 5 from groupMap[3]
freqMap: {5: 2, 7: 2, 4: 1}
groupMap: {1: [5, 7, 4], 2: [5, 7], 3: []}
maxFreq: 2
Pop:

Pop 7 from groupMap[2]
freqMap: {5: 2, 7: 1, 4: 1}
groupMap: {1: [5, 7, 4], 2: [5], 3: []}
maxFreq: 2
Pop:

Pop 5 from groupMap[2]
freqMap: {5: 1, 7: 1, 4: 1}
groupMap: {1: [5, 7, 4], 2: [], 3: []}
maxFreq: 1
Pop:

Pop 4 from groupMap[1]
freqMap: {5: 1, 7: 1, 4: 0}
groupMap: {1: [5, 7], 2: [], 3: []}
maxFreq: 1
Complexity Analysis
Push Operation: 
𝑂
(
1
)
O(1)

Updating freqMap and pushing to the stack in groupMap are constant time operations.
Pop Operation: 
𝑂
(
1
)
O(1)

Accessing and popping from the top of the stack in groupMap is constant time.
Space Complexity: 
𝑂
(
𝑛
)
O(n), where 
𝑛
n is the total number of elements pushed.

freqMap and groupMap store all elements and their frequencies.
