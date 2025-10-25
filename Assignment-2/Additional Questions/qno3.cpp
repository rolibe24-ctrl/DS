#include <bits/stdc++.h>
using namespace std;

bool isAnagram(string s1, string s2) {
    if (s1.size() != s2.size()) return false;

    vector<int> freq(26, 0);
    for (char c : s1) freq[c - 'a']++;
    for (char c : s2) freq[c - 'a']--;

    for (int f : freq)
        if (f != 0) return false;

    return true;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        string str1, str2;
        cin >> str1 >> str2;

        cout << (isAnagram(str1, str2) ? "YES" : "NO") << endl;
    }
    return 0;
}
