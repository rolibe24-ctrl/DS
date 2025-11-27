// 1. Given an integer array, check if it contains any duplicates using hash set.
// Input:
// nums = [1, 2, 3, 1]
// Output:
// true 

#include <bits/stdc++.h>
using namespace std;

bool containsDuplicate(vector<int>& nums) {
    unordered_set<int> st;
    for (int x : nums) {
        if (st.count(x)) return true;
        st.insert(x);
    }
    return false;
}

int main() {
    vector<int> nums = {1, 2, 3, 1};
    cout << (containsDuplicate(nums) ? "true" : "false");
}
