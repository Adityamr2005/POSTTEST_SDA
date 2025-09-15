#include <iostream>

using namespace std;

void swapWithDoublePointer(int** a, int** b) {
    int temp = **a;
    **a = **b;
    **b = temp;
}

void swapWithReference(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

int main() {
    int nim = 101;

    int x = 5, y = 10;

    cout << "Sebelum pertukaran:" << endl;
    cout << "x = " << x << ", y = " << y << endl;

    if (nim % 2 == 1) {

        cout << "\n--- Menggunakan Double Pointer ---" << endl;
        int* ptr_x = &x;
        int* ptr_y = &y;
        swapWithDoublePointer(&ptr_x, &ptr_y);
    } else {

        cout << "\n--- Menggunakan Referensi ---" << endl;
        swapWithReference(x, y);
    }

    cout << "\nSetelah pertukaran:" << endl;
    cout << "x = " << x << ", y = " << y << endl;

    return 0;
}