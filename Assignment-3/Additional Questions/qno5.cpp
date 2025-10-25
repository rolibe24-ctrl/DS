#include <bits/stdc++.h>
using namespace std;

bool canStackSort(vector<int>& A) {
    stack<int> S;
    int expected = 1;
    int N = A.size();

    for (int i = 0; i < N; i++) {
        // Push current element to stack or move directly to B
        while (!S.empty() && S.top() == expected) {
            S.pop();
            expected++;
        }

        if (A[i] == expected) {
            expected++;
        } else {
            S.push(A[i]);
        }
    }

    // Check remaining stack
    while (!S.empty() && S.top() == expected) {
        S.pop();
        expected++;
    }

    return S.empty();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<int> A(N);
        for (int i = 0; i < N; i++) cin >> A[i];

        cout << (canStackSort(A) ? "YES" : "NO") << "\n";
    }

    return 0;
}
