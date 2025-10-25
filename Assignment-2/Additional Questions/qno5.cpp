#include <bits/stdc++.h>
using namespace std;

void duplicateZeros(vector<int>& arr) {
    int n = arr.size();
    int zeros = 0;


    for (int i = 0; i < n; i++) {
        if (arr[i] == 0) zeros++;
    }


    for (int i = n - 1; i >= 0; i--) {
        int j = i + zeros;

        if (j < n) arr[j] = arr[i]; // copy element

        if (arr[i] == 0) {
            zeros--; // one zero handled
            if (i + zeros < n) arr[i + zeros] = 0; // duplicate zero
        }
    }
}

int main() {
    vector<int> arr = {1,0,2,3,0,4,5,0};
    duplicateZeros(arr);

    for (int x : arr) cout << x << " ";
    cout << endl;

    return 0;
}
