/*
Qno 1) Develop a Menu driven program to demonstrate the following operations of Arrays 
——MENU——- 
1.CREATE 
2. DISPLAY 
3. INSERT 
4. DELETE 
5. LINEAR SEARCH 
6. EXIT 
*/

#include <iostream>

const int max_size = 100;
using namespace std;

void display_menu();
void create_array(int array[], int& size);
void display_array(int array[], int& size);
void insert_element(int array[], int& size);
void delete_element(int array[], int& size);
void linear_search(int array[], int& size);

int main() {
        int array[max_size]; 
        int size = 0;     
        int choice;

        do {
                display_menu();
                cout << "Enter your choice: ";
                cin >> choice;

                switch (choice) {
                case 1:
                        create_array(array, size);
                        break;
                case 2:
                        display_array(array, size);
                        break;
                case 3:
                        insert_element(array, size);
                        break;
                case 4:
                        delete_element(array, size);
                        break;
                case 5:
                        linear_search(array, size);
                        break;
                case 6:
                        cout << "exiting program!" << endl;
                        break;
                default:
                        cout << "invalid choice" << endl;
                }
                cout << endl;
        } while (choice != 6);

        return 0;
        }
        // display menu
        void display_menu() {
        cout << "1) CREATE" << endl;
        cout << "2) DISPLAY" << endl;
        cout << "3) INSERT" << endl;
        cout << "4) DELETE" << endl;
        cout << "5) LINEAR SEARCH" << endl;
        cout << "6) EXIT" << endl;
        }
        // create array
        void create_array(int array[], int& size) {
        int new_size;
        cout << "Enter the number of elements to create (max " << max_size << "): ";
        cin >> new_size;

        if (new_size <= 0 || new_size > max_size) {
                cout << "Invalid size" << endl;
                return;
        }
        
        size = new_size;
        cout << "enter " << size << " elements:" << endl;
        for (int i = 0; i < size; i++) {
                cout << "Element " << i + 1 << ":";
                cin >> array[i];
        }
        cout << "array created successfully." << endl;
        }

        // display array
        void display_array(int array[], int& size) {
        if (size == 0) {
                cout << "array is empty " << endl;
                return;
        }
        cout << "the elements of array are: ";
        for (int i = 0; i < size; i++) {
                cout << array[i] << " ";
        }
        cout << endl;
        }
        // insert element
        void insert_element(int array[], int& size) {
        if (size >= max_size) {
                cout << "array is full" << endl;
                return;
        }

        int value, position;
        cout << "enter the value to insert: ";
        cin >> value;
        cout << "enter the index where you want insert: ";
        cin >> position;

        if (position < 0 || position > size) {
                cout << "invalid position" << endl;
        } else {
                for (int i = size; i > position; --i) {
                array[i] = array[i - 1];
                }
                array[position] = value; 
                size++;              
                cout << "element" << value << " inserted at position: " << position << endl;
        }
        }
        // delete element
        void delete_element(int array[], int& size) {
        if (size == 0) {
                cout << "array is empty" << endl;
                return;
        }

        int position;
        cout << "enter the index of the element to delete: ";
        cin >> position;


        if (position < 0 || position >= size) {
                cout << "invalid position" << endl;
        } else {
                int deleted_value = array[position];

                for (int i = position; i < size - 1; ++i) {
                array[i] = array[i + 1];
                }
                size--; 
                cout << "element " << deleted_value << " at position " << position << " deleted" << endl;
        }
        }
        // Linear Search
        void linear_search(int arr[], int& size) {
        if (size == 0) {
                cout << "array is empty" << endl;
                return;
        }

        int search_value;
        cout << "enter the value to search for: ";
        cin >> search_value;

        int found_index = -1;
        for (int i = 0; i < size; ++i) {
                if (arr[i] == search_value) {
                found_index = i;
                break;
                }
        }

        if (found_index != -1) {
                cout << "value " << search_value << " found at index: " << found_index  << endl;
        } else {
                cout << "value " << search_value << " not found in the array" << endl;
        }
}