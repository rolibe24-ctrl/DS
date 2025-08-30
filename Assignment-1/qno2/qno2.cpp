// 2) Design the logic to remove the duplicate elements from an Array and after the deletion the array should contain the unique elements.

#include <iostream>
using namespace std;

const int max_size = 100;

int main() {
    int array[max_size];
    int size;
    cout << "Enter the size of array: ";
    cin >> size;

    cout << "Enter elements: ";
    for (int i = 0; i < size; i++) {
        cin >> array[i];
    }

    int new_size = 0;


    for (int i = 0; i < size; i++) {
        bool duplicate = false;

        for (int j = 0; j < new_size; j++) {
            if (array[i] == array[j]) {
                duplicate = true;
                break;
            }
        }

        if (!duplicate) {
            array[new_size] = array[i];
            new_size++;
        }
    }

    cout << "Array after removing duplicates: ";
    for (int i = 0; i < new_size; i++) {
        cout << array[i] << " ";
    }
    cout << endl;

    return 0;
}
