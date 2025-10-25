#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;
        int n = s.size();
        bool possible = false;

        // Case 1: first and last character same
        if (s[0] == s[n - 1]) {
            possible = true;
        } 
        else {
            // Case 2: any character repeats
            vector<int> freq(26, 0);
            for (char c : s) freq[c - 'a']++;
            for (int f : freq)
                if (f > 1) {
                    possible = true;
                    break;
                }
        }

        cout << (possible ? "YES" : "NO") << endl;
    }
    return 0;
}
