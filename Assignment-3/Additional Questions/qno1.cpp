#include <bits/stdc++.h>
using namespace std;

vector<int> nearestSmallerToLeft(vector<int>& A) {
    vector<int> G;
    stack<int> s;

    for (int x : A) {
        while (!s.empty() && s.top() >= x)
            s.pop();

        if (s.empty())
            G.push_back(-1);
        else
            G.push_back(s.top());

        s.push(x);
    }

    return G;
}

int main() {
    vector<int> A = {4, 5, 2, 10, 8};
    vector<int> G = nearestSmallerToLeft(A);

    for (int x : G)
        cout << x << " ";
    cout << endl;

    return 0;
}
