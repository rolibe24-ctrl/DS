// 2. Given two arrays, find the common elements using a hash set.
// Input:
// A = [1, 2, 3, 4]
// B = [3, 4, 5, 6]
// Output:
// 3, 4

#include <bits/stdc++.h>
using namespace std;

vector<int> commonElements(vector<int>& A, vector<int>& B) {
    unordered_set<int> st(A.begin(), A.end());
    vector<int> res;

    for (int x : B)
        if (st.count(x)) res.push_back(x);

    return res;
}

int main() {
    vector<int> A = {1, 2, 3, 4};
    vector<int> B = {3, 4, 5, 6};

    vector<int> ans = commonElements(A, B);

    for (int x : ans) cout << x << " ";
}
