#include <bits/stdc++.h>
using namespace std;

vector<int> dailyTemperatures(vector<int>& temperatures) {
    int n = temperatures.size();
    vector<int> answer(n, 0);
    stack<int> s; // store indices

    for (int i = 0; i < n; i++) {
        while (!s.empty() && temperatures[i] > temperatures[s.top()]) {
            int idx = s.top();
            s.pop();
            answer[idx] = i - idx;
        }
        s.push(i);
    }

    return answer;
}

int main() {
    vector<int> temps = {73,74,75,71,69,72,76,73};
    vector<int> ans = dailyTemperatures(temps);

    for (int x : ans) cout << x << " ";
    cout << endl;

    return 0;
}
