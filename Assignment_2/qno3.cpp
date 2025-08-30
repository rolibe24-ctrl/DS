// 3) Design the Logic to Find a Missing Number in a Sorted Array.

// 3) Find the Missing Number in a Sorted Array

#include <iostream>
using namespace std;

// Approach 1: Formula Method
int findMissingSum(int arr[], int size) {
    int n=size + 1; // because one number is missing
    int expectedSum = n *(n + 1)/2;
    int actualSum = 0;

    for (int i = 0; i < size; i++) {
        actualSum +=arr[i];
    }

    return expectedSum -actualSum;
}

int main() {
    int arr[] ={1, 2, 3, 4, 6, 7, 8}; // missing 5
    int size=sizeof(arr)/sizeof(arr[0]);

    cout <<"Using Sum Method: Missing number = " 
         <<findMissingSum(arr, size)<<endl;
         
    return 0;
}
