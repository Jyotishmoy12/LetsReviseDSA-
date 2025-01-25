Problem Statement in Detail:
In a social network, each user can have multiple friends, forming a graph where each user is a node and each friendship is an edge. Your task is to recommend friends to a given user based on connectivity. The recommendation should be based on how connected the users are to the target user.

Given:

A social network is represented as an undirected graph where each user is a node and an edge between two nodes indicates that the two users are friends.
You are given a specific user, and your goal is to recommend a list of friends for that user. The recommendation should prioritize users who are indirectly connected through common friends.
Objective:

Identify and recommend users who are connected to the target user indirectly (friends of friends), but not directly connected.
Example 1:

Input:

yaml
Copy
Edit
graph = {
    0: [1, 2],
    1: [0, 3, 4],
    2: [0, 4],
    3: [1],
    4: [1, 2]
}
target_user = 0
Output:

less
Copy
Edit
Recommended friends for user 0: [3, 4]
Explanation:

User 0 has direct friends: 1, 2.
Friends of friends:
User 1’s friends are: 0, 3, 4.
User 2’s friends are: 0, 4.
User 0 is already friends with 1 and 2, so the recommended friends are 3 and 4.
Example 2:

Input:

yaml
Copy
Edit
graph = {
    0: [1, 2],
    1: [0, 3, 4],
    2: [0, 4],
    3: [1],
    4: [1, 2]
}
target_user = 1
Output:

less
Copy
Edit
Recommended friends for user 1: [0, 2]
Explanation:

User 1 has direct friends: 0, 3, 4.
Friends of friends:
User 0’s friends are: 1, 2.
User 3’s friends are: 1.
User 4’s friends are: 1, 2.
User 1 is already friends with 0, 3, and 4, so the recommended friend is 2.
Intuition Behind the Problem:
Graph Representation: The social network is represented as an undirected graph, where nodes represent users, and edges represent friendships.
Indirect Connection: The friends of friends of the target user are the ones that should be recommended, excluding those who are already direct friends.
Graph Traversal: This problem involves graph traversal, where we need to explore the connections of the target user’s friends and recommend those who are not already directly connected to the target.
Approach to Solve It Step-by-Step:
Graph Representation: Use an adjacency list to represent the graph. Each key is a user, and the value is a list of friends (adjacent nodes).

Traverse Friends of Friends:

For the given target user, get their direct friends.
For each direct friend, get their friends (friends of friends).
Add the friends of friends to a set to ensure uniqueness.
Exclude the target user and their direct friends from the set of recommended friends.
Recommendation List:

Return the list of recommended friends in increasing order (or any other order as required).
C++ Code Implementation:
cpp
Copy
Edit
#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>

using namespace std;

// Function to recommend friends based on connectivity
vector<int> recommendFriends(const unordered_map<int, vector<int>>& graph, int targetUser) {
    unordered_set<int> directFriends(graph.at(targetUser).begin(), graph.at(targetUser).end());
    unordered_set<int> recommendedFriends;
    
    // Traverse the friends of the target user's direct friends
    for (int friendUser : graph.at(targetUser)) {
        for (int friendOfFriend : graph.at(friendUser)) {
            // Add to recommended friends if not the target user or already a direct friend
            if (friendOfFriend != targetUser && directFriends.find(friendOfFriend) == directFriends.end()) {
                recommendedFriends.insert(friendOfFriend);
            }
        }
    }

    // Convert the set to a vector
    vector<int> result(recommendedFriends.begin(), recommendedFriends.end());
    
    // Sort the result (optional)
    sort(result.begin(), result.end());
    
    return result;
}

int main() {
    // Example 1: Social network graph
    unordered_map<int, vector<int>> graph = {
        {0, {1, 2}},
        {1, {0, 3, 4}},
        {2, {0, 4}},
        {3, {1}},
        {4, {1, 2}}
    };

    int targetUser = 0;
    
    vector<int> recommended = recommendFriends(graph, targetUser);
    
    cout << "Recommended friends for user " << targetUser << ": ";
    for (int user : recommended) {
        cout << user << " ";
    }
    cout << endl;

    return 0;
}
Explanation Line-by-Line:
Graph Representation:

We represent the social network as an unordered_map called graph, where each key-value pair corresponds to a user and their list of friends.
Recommend Friends Function:

First, we store the direct friends of the target user in the directFriends set.
Then, we iterate through each of the target user's direct friends and, for each direct friend, we add their friends to the recommendedFriends set.
We ensure that the target user and their direct friends are not added to the recommendedFriends set by checking if (friendOfFriend != targetUser && directFriends.find(friendOfFriend) == directFriends.end()).
Sorting:

The result is stored in a vector for ease of use and is sorted (optional) to present the recommended friends in increasing order.
Main Function:

We define a sample social network graph and call the recommendFriends function to get the list of recommended friends for the target user.
The recommended friends are then printed out.
Dry Run:
Input:

yaml
Copy
Edit
graph = {
    0: [1, 2],
    1: [0, 3, 4],
    2: [0, 4],
    3: [1],
    4: [1, 2]
}
target_user = 0
Direct Friends of User 0: {1, 2}
Friends of Friends:
For User 1: Friends are {0, 3, 4}. The friends of User 1 (excluding 0) are {3, 4}.
For User 2: Friends are {0, 4}. The friends of User 2 (excluding 0) are {4}.
Thus, the recommended friends are {3, 4}.

Output:

rust
Copy
Edit
Recommended friends for user 0: 3 4
Complexity Analysis:
Time Complexity:
We iterate over each friend of the target user and their friends, so the time complexity is approximately O(F + F^2), where F is the average number of friends per user.
Space Complexity:
We use sets to store direct friends and recommended friends. The space complexity is O(F), where F is the average number of friends per user.
