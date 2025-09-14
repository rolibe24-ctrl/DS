#include <iostream>
using namespace std;

int main() {
    int r, c;

    // enter the rows and columns of the matrix
    cout << "enter rows and columns for the matrix: ";
    cin >> r >> c;

    int mat1[100][100], transpose[100][100];

    // entering elements in matrix
    cout << "enter elements in the matrix:" << endl;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> mat1[i][j];
        }
    }

    // Displaying original matrix
    cout << " original matrix:" << endl;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cout << mat1[i][j] << " ";
        }
        cout << endl;
    }

    // finding the transpose
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            transpose[j][i] = mat1[i][j];
        }
    }

    // displaying transpose matrix
    cout << "transpose Matrix:" << endl;
    for (int i = 0; i < c; i++) {
        for (int j = 0; j < r; j++) {
            cout << transpose[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
