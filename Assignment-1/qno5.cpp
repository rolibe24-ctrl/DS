//Qno 5) Write a program to find sum of every row and every column in a two-dimensional array. 

#include <iostream>
using namespace std;

int main() {
        int rows, col;
        cout << "enter number of rows: ";
        cin >> rows;
        cout << "enter number of columns: ";
        cin >> col;

        int matrix[100][100];

        // Input elements
        cout << "enter elements of the matrix:" << endl;
        for (int i = 0; i < rows; i++) {
                for (int j = 0; j < col; j++) {
                cin >> matrix[i][j];
                }
        }

// Display elements
        cout << "display elements of the matrix:" << endl;
        for (int i = 0; i < rows; i++) {
                for (int j = 0; j < col; j++) {
                cout << matrix[i][j]<<" ";
                }
                cout << endl;
        }


// Sum of each row
        cout << "sum of each row:" << endl;
        for (int i = 0; i < rows; i++) {
                int row_sum = 0;
                for (int j = 0; j < col; j++) {
                row_sum += matrix[i][j];
                }
                cout << "the sum of Row " << i + 1 << "is: " << row_sum << endl;
        }

// Sum of each column
        cout << "sum of each column:" << endl;
        for (int j = 0; j < col; j++) {
                int col_sum = 0;
                for (int i = 0; i < rows; i++) {
                col_sum += matrix[i][j];
                }
                cout << "the sum of column " << j + 1 << "is: " << col_sum << endl;
        }

        return 0;
}
