#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int nA, nB;
    int *A, *B;
    int **C;

    // Input A
    cout << "Length of A: ";
    cin >> nA;

    A = new int[nA];
    cout << "Input Array A: ";
    for (int i = 0; i < nA; i++)
        cin >> A[i];

    // Input B
    cout << "Length of B: ";
    cin >> nB;

    B = new int[nB];
    cout << "Input Array B: ";
    for (int i = 0; i < nB; i++)
        cin >> B[i];

    // Allocate 2D array C
    C = new int*[nA];
    for (int i = 0; i < nA; i++)
        C[i] = new int[nB];

    // Calculate C[i][j] = A[i] * B[j]
    for (int i = 0; i < nA; i++) {
        for (int j = 0; j < nB; j++) {
            C[i][j] = A[i] * B[j];
        }
    }

    // Display result
    cout << "\n";
    cout << setw(6) << " ";
    for (int j = 0; j < nB; j++)
        cout << setw(5) << B[j] << " ";
    cout << "\n-----------------------------\n";

    for (int i = 0; i < nA; i++) {
        cout << setw(5) << A[i] << " ";
        for (int j = 0; j < nB; j++)
            cout << setw(5) << C[i][j] << " ";
        cout << "\n";
    }

    // Deallocate memory
    for (int i = 0; i < nA; i++)
        delete[] C[i];
    delete[] C;
    delete[] A;
    delete[] B;

    return 0;
}
