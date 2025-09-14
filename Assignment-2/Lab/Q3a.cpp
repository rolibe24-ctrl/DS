#include <iostream>
using namespace std;
int findMissingLinear(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] != i + 1) {
            return i + 1;
        }
    }
    return n; 
}

int main() {
    int n;
    int arr[100];

    cout << "Enter the size of element: ";
    cin >> n;
    cout << "Enter the element: ";

    for (int i = 0; i < n - 1; i++) {
        cin >> arr[i];
    }
    cout << "Missing number (Linear method): " << findMissingLinear(arr, n) << endl;
    return 0;
}

