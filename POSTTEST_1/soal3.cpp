#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Mahasiswa {
    string nama;
    string nim;
    double ipk;
};

void printMahasiswa(const Mahasiswa& m) {

    cout << "  Nama: " << m.nama << endl;
    cout << "  NIM: " << m.nim << endl;
    cout << "  IPK: " << m.ipk << endl;
}

int main() {
    int nim = 101;

    if (nim % 2 == 1) {
        const int numStudents = 5;
        vector<Mahasiswa> mahasiswaArray(numStudents);
        
        cout << "NIM Ganjil (101): Masukkan data 5 mahasiswa" << endl;
        for (int i = 0; i < numStudents; ++i) {
            cout << "\nMahasiswa ke-" << i + 1 << endl;
            cout << "Nama: ";
            cin.ignore(); // Membersihkan buffer input
            getline(cin, mahasiswaArray[i].nama);
            cout << "NIM: ";
            cin >> mahasiswaArray[i].nim;
            cout << "IPK: ";
            cin >> mahasiswaArray[i].ipk;
        }

        Mahasiswa highestIPKStudent = mahasiswaArray[0];
        for (size_t i = 1; i < mahasiswaArray.size(); ++i) {
            if (mahasiswaArray[i].ipk > highestIPKStudent.ipk) {
                highestIPKStudent = mahasiswaArray[i];
            }
        }

        cout << "\n---------------------------------" << endl;
        cout << "Mahasiswa dengan IPK Tertinggi:" << endl;
        printMahasiswa(highestIPKStudent);

    } else {
        const int numStudents = 4;
        vector<Mahasiswa> mahasiswaArray(numStudents);

        cout << "NIM Genap (102): Masukkan data 4 mahasiswa" << endl;
        for (int i = 0; i < numStudents; ++i) {
            cout << "\nMahasiswa ke-" << i + 1 << endl;
            cout << "Nama: ";
            cin.ignore();
            getline(cin, mahasiswaArray[i].nama);
            cout << "NIM: ";
            cin >> mahasiswaArray[i].nim;
            cout << "IPK: ";
            cin >> mahasiswaArray[i].ipk;
        }

        sort(mahasiswaArray.begin(), mahasiswaArray.end(), [](const Mahasiswa& a, const Mahasiswa& b) {
            return a.ipk < b.ipk;
        });

        cout << "\n---------------------------------" << endl;
        cout << "Data Mahasiswa (Diurutkan berdasarkan IPK Ascending):" << endl;
        for (const auto& m : mahasiswaArray) {
            cout << "\n";
            printMahasiswa(m);
        }
    }

    return 0;
}