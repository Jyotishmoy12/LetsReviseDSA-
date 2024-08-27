#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

// Custom pair hash function if needed
struct hash_pair {
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2>& p) const {
        auto hash1 = hash<T1>{}(p.first);
        auto hash2 = hash<T2>{}(p.second);
        return hash1 ^ hash2;
    }
};

// Generic function to solve a hashing problem
vector<pair<int, int>> findPairs(vector<int>& arr, int k) {
    unordered_map<int, int> freqMap; // To store the frequency of elements
    unordered_set<pair<int, int>, hash_pair> resultSet; // To store unique pairs

    for (int num : arr) {
        // Calculate the required complements or conditions
        int complement1 = num - k;
        int complement2 = num + k;

        // Check for the first condition (e.g., num - k exists)
        if (freqMap.find(complement1) != freqMap.end()) {
            resultSet.insert({min(num, complement1), max(num, complement1)});
        }

        // Check for the second condition (e.g., num + k exists)
        if (freqMap.find(complement2) != freqMap.end()) {
            resultSet.insert({min(num, complement2), max(num, complement2)});
        }

        // Update the map with the current element
        freqMap[num]++;
    }

    // Convert the set to a vector of pairs and return it
    return vector<pair<int, int>>(resultSet.begin(), resultSet.end());
}

int main() {
    vector<int> arr = {1, 5, 2, 2, 5, 7, 8, 3};
    int k = 3;

    vector<pair<int, int>> result = findPairs(arr, k);
    
    cout << "Pairs found:" << endl;
    for (auto& p : result) {
        cout << "(" << p.first << ", " << p.second << ")" << endl;
    }

    return 0;
}
