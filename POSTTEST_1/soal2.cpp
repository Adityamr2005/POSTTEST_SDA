#include <iostream>

using namespace std;

void printMatrix(int mat[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << mat[i][j] << "\t";
        }
        cout << endl;
    }
}

int main() {
    int nim = 101;

    int matrix[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    cout << "Matriks 3x3:" << endl;
    printMatrix(matrix);

    cout << "--------------------" << endl;

    if (nim % 2 == 1) {
        int sumDiagonal = 0;
        int sumMainDiagonal = 0;
        int sumSecondaryDiagonal = 0;

        for (int i = 0; i < 3; i++) {
            sumMainDiagonal += matrix[i][i];
            sumSecondaryDiagonal += matrix[i][2 - i];
        }

        sumDiagonal = sumMainDiagonal + sumSecondaryDiagonal;

        cout << "NIM Ganjil (101):" << endl;
        cout << "Jumlah diagonal utama: " << sumMainDiagonal << endl;
        cout << "Jumlah diagonal sekunder: " << sumSecondaryDiagonal << endl;
        cout << "Jumlah total (diagonal utama + sekunder): " << sumDiagonal << endl;

    } else {
        int sumEvenRows = 0;
        for (int i = 0; i < 3; i += 2) {
            for (int j = 0; j < 3; j++) {
                sumEvenRows += matrix[i][j];
            }
        }
        cout << "NIM Genap (102):" << endl;
        cout << "Jumlah elemen baris genap: " << sumEvenRows << endl;
    }

    return 0;
}