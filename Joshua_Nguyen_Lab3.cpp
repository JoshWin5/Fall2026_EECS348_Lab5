
#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>

using namespace std;

// Displays a matrix(Formats to make sure its all equal)
void displayMatrix(vector<vector<int>> matrix) {
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix.size(); j++) {
            cout << setw(5) << matrix[i][j];
        }
        cout << endl;
    }
}

// Adds two matrices(A+B)
void addMatrices(vector<vector<int>> A, vector<vector<int>> B) {
    int n = A.size();

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << setw(5) << A[i][j] + B[i][j];
        }
        cout << endl;
    }
}

// Multiplies two matrices
void multiplyMatrices(vector<vector<int>> A, vector<vector<int>> B) {
    int n = A.size();

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int sum = 0;

            for (int k = 0; k < n; k++) {
                sum += A[i][k] * B[k][j];
            }

            cout << setw(5) << sum;
        }
        cout << endl;
    }
}

// Calculates diagonal sums
void diagonalSums(vector<vector<int>> A) {
    int n = A.size();
    int mainSum = 0;
    int secondarySum = 0;

    for (int i = 0; i < n; i++) {
        mainSum += A[i][i];
        secondarySum += A[i][n - 1 - i];
    }

    cout << "Main diagonal: " << mainSum << endl;
    cout << "Secondary diagonal: " << secondarySum << endl;
}

// Swaps two rows
void swapRows(vector<vector<int>>& A, int row1, int row2) {
    int n = A.size();

    if (row1 >= 0 && row1 < n && row2 >= 0 && row2 < n) {
        swap(A[row1], A[row2]);
        displayMatrix(A);
    }
    else {
        cout << "Invalid row index." << endl;
    }
}

// Swaps two columns
void swapColumns(vector<vector<int>>& A, int col1, int col2) {
    int n = A.size();

    if (col1 >= 0 && col1 < n && col2 >= 0 && col2 < n) {
        for (int i = 0; i < n; i++) {
            swap(A[i][col1], A[i][col2]);
        }
        displayMatrix(A);
    }
    else {
        cout << "Invalid column index." << endl;
    }
}

// Updates a matrix element
void updateElement(vector<vector<int>>& A, int row, int col, int value) {
    int n = A.size();

    if (row >= 0 && row < n && col >= 0 && col < n) {
        A[row][col] = value;
        displayMatrix(A);
    }
    else {
        cout << "Invalid index." << endl;
    }
}

//Main function allows for file input and user input
int main() {
    string filename;

    cout << "Enter the file name: ";
    cin >> filename;

    ifstream file(filename);

    if (!file.is_open())
    {
        cout << "Error opening file." << endl;
        return 1;
    }

    int n;
    file >> n;

    vector<vector<int>> A(n, vector<int>(n));
    vector<vector<int>> B(n, vector<int>(n));

    // Read Matrix A
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            file >> A[i][j];
        }
    }

    // Read Matrix B
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            file >> B[i][j];
        }
    }

    cout << "Matrix A:" << endl;
    displayMatrix(A);

    cout << "Matrix B:" << endl;
    displayMatrix(B);

    int choice;

    do {
        cout << endl;
        cout << "1. Add matrices" << endl;
        cout << "2. Multiply matrices" << endl;
        cout << "3. Diagonal sums" << endl;
        cout << "4. Swap rows" << endl;
        cout << "5. Swap columns" << endl;
        cout << "6. Update element" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        if (cin.fail()) 
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input." << endl;
            continue;
        }

        if (choice == 1) {
            addMatrices(A, B);
        }
        else if (choice == 2) {
            multiplyMatrices(A, B);
        }
        else if (choice == 3) {
            int matrixChoice;
            cout << "Choose matrix (1 = A, 2 = B): ";
            cin >> matrixChoice;

            if (matrixChoice == 1) {
                diagonalSums(A);
            }
            else if (matrixChoice == 2) {
                diagonalSums(B);
            }
            else {
                cout << "Invalid matrix." << endl;
            }
        }
        else if (choice == 4) {
            int matrixChoice, row1, row2;
            cout << "Choose matrix (1 = A, 2 = B): ";
            cin >> matrixChoice;
            cout << "Enter two row indices: ";
            cin >> row1 >> row2;

            if (matrixChoice == 1) {
                swapRows(A, row1, row2);
            }
            else if (matrixChoice == 2) {
                swapRows(B, row1, row2);
            }
            else {
                cout << "Invalid matrix." << endl;
            }
        }
        else if (choice == 5) {
            int matrixChoice, col1, col2;
            cout << "Choose matrix (1 = A, 2 = B): ";
            cin >> matrixChoice;
            cout << "Enter two column indices: ";
            cin >> col1 >> col2;

            if (matrixChoice == 1) {
                swapColumns(A, col1, col2);
            }
            else if (matrixChoice == 2) {
                swapColumns(B, col1, col2);
            }
            else {
                cout << "Invalid matrix." << endl;
            }
        }
        else if (choice == 6) {
            int matrixChoice, row, col, value;
            cout << "Choose matrix (1 = A, 2 = B): ";
            cin >> matrixChoice;
            cout << "Enter row, column, and new value: ";
            cin >> row >> col >> value;

            if (matrixChoice == 1) {
                updateElement(A, row, col, value);
            }
            else if (matrixChoice == 2) {
                updateElement(B, row, col, value);
            }
            else {
                cout << "Invalid matrix." << endl;
            }
        }

    } while (choice != 0);

    return 0;
}