// 4. Find the first non-repeating element in an array using a hash map.
// Input:
// [4, 5, 1, 2, 0, 4]
// Output:
// 5


#include <bits/stdc++.h>
using namespace std;

int firstNonRepeating(vector<int>& nums) {
    unordered_map<int,int> freq;
    for (int x : nums) freq[x]++;

    for (int x : nums)
        if (freq[x] == 1) return x;

    return -1; 
}

int main() {
    vector<int> nums = {4, 5, 1, 2, 0, 4};
    cout << firstNonRepeating(nums); 
