// Qno 4a) Implement the logic to reverse the elements of an array 

#include <iostream>
using namespace std;

int main(){
        int new_size, size = 0;
        int max_size = 100;
        int array[max_size];
        int reverse_array[max_size];

        // To create an array

        cout << "Enter the number of elements to create (max " << max_size << "): ";
        cin >> new_size;

        if (new_size <= 0 || new_size > max_size) {
                cout << "Invalid size" << endl;
        }

        size = new_size;
        cout << "Enter " << size << " elements:" << endl;

        for (int i = 0; i < size; i++) {
        cout << "Element " << i + 1 << ":";
        cin >> array[i];
        }
        cout << "Array created successfully." << endl;

    // to reverse an array.
        int j=0;
        for (int i = new_size-1; i>=0; i--)
        {
                reverse_array[j]=array[i];
                j++;
        }

    // print reversed array.
        cout<<"The reversed array is: ";
        for (int i = 0; i < new_size; i++)
        {
                cout << reverse_array[i] << " ";
        }
}

