#include <iostream>
#include <vector>

using namespace std;

bool isPrime(int n) {
    if (n <= 1) {
        return false;
    }
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

void reverseArray(int* arr, int size) {
    int* start = arr;
    int* end = arr + size - 1;
    while (start < end) {
        int temp = *start;
        *start = *end;
        *end = temp;

        start++;
        end--;
    }
}

void printArray(const int* arr, int size) {
    cout << "[";
    for (int i = 0; i < size; i++) {
        cout << *(arr + i);
        if (i < size - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;
}

int main() {
    const int size = 7;
    int arr[size];

   
    int primeCount = 0;
    for (int i = 0; i < size; i++) {
        if (i % 2 == 1) {
            arr[i] = (i + 1) * 3;
        } else {
            int currentNumber = 2;
            while (primeCount <= i/2) {
                if (isPrime(currentNumber)) {
                    if (primeCount == i/2) {
                        arr[i] = currentNumber;
                        primeCount++;
                        break;
                    }
                    primeCount++;
                }
                currentNumber++;
            }
        }
    }

    cout << "Array sebelum dibalik: ";
    printArray(arr, size);

    reverseArray(arr, size);

    cout << "Array setelah dibalik: ";
    printArray(arr, size);

    return 0;
}