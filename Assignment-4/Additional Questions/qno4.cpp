#include <bits/stdc++.h>
using namespace std;

int countStudents(vector<int>& students, vector<int>& sandwiches) {
    int count0 = 0, count1 = 0;
    for (int s : students) {
        if (s == 0) count0++;
        else count1++;
    }

    for (int sw : sandwiches) {
        if (sw == 0) {
            if (count0 == 0) break; // no student wants circular
            count0--;
        } else {
            if (count1 == 0) break; // no student wants square
            count1--;
        }
    }

    return count0 + count1; // remaining students unable to eat
}

int main() {
    vector<int> students = {1,1,0,0};
    vector<int> sandwiches = {0,1,0,1};
    cout << countStudents(students, sandwiches) << endl; // Output: 0
    return 0;
}
