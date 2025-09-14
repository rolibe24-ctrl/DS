// Qno 4b) Find the matrix multiplication

#include <iostream>
using namespace std;

int main() {
    int r1, c1, r2, c2;

    // Input dimensions
    cout << "Enter rows and columns for first matrix: ";
    cin >> r1 >> c1;
    cout << "Enter rows and columns for second matrix: ";
    cin >> r2 >> c2;

    // Check if multiplication is possible
    if (c1 != r2) {
        cout << "Matrix multiplication not possible. Columns of first must equal rows of second." << endl;
        return 0;
    }

    // Declare matrices
    int mat1[100][100], mat2[100][100], result[100][100] = {0};

    // Input first matrix
    cout << "Enter elements of first matrix:" << endl;
    for (int i = 0; i < r1; i++)
        for (int j = 0; j < c1; j++)
            cin >> mat1[i][j];

    // Input second matrix
    cout << "Enter elements of second matrix:" << endl;
    for (int i = 0; i < r2; i++)
        for (int j = 0; j < c2; j++)
            cin >> mat2[i][j];

    // Multiply matrices
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            for (int k = 0; k < c1; k++) {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }

    // Display result
    cout << "Resultant Matrix:" << endl;
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
