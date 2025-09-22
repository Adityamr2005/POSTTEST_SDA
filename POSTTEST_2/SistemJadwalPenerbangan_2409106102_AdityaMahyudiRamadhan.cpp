#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

struct Node {
    string kodePenerbangan;
    string tujuan;
    string status;
    Node* next;
};

int kodeCounter = 0;

string getTigaDigitNIM() {
    return "102";
}

string generateKode() {
    string baseKode = "JT-" + getTigaDigitNIM();
    if (kodeCounter == 0) {
        kodeCounter++;
        return baseKode;
    } else {
        return baseKode + "-" + to_string(kodeCounter++);
    }
}

Node* createNode(string kode, string tujuan, string status) {
    Node* newNode = new Node;
    newNode->kodePenerbangan = kode;
    newNode->tujuan = tujuan;
    newNode->status = status;
    newNode->next = nullptr;
    return newNode;
}

void tambahJadwalBaru(Node*& head, string tujuan, string status) {
    string kode = generateKode();
    Node* newNode = createNode(kode, tujuan, status);
    
    if (head == nullptr) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    cout << "Jadwal penerbangan '" << kode << "' ke " << tujuan 
         << " (Status: " << status << ") berhasil ditambahkan di akhir!" << endl;
}

void sisipkanJadwal(Node*& head, string tujuan, string status, int posisi) {
    string kode = generateKode();
    Node* newNode = createNode(kode, tujuan, status);
    
    if (posisi <= 1 || head == nullptr) {
        newNode->next = head;
        head = newNode;
        cout << "Jadwal penerbangan '" << kode << "' ke " << tujuan 
             << " (Status: " << status << ") berhasil disisipkan di posisi " << 1 << "!" << endl;
        return;
    }
    
    Node* temp = head;
    int currentPos = 1;
    while (temp != nullptr && currentPos < posisi - 1) {
        temp = temp->next;
        currentPos++;
    }
    
    if (temp == nullptr) {
        cout << "Posisi melebihi ukuran list. Menambahkan di akhir." << endl;
        tambahJadwalBaru(head, tujuan, status);
        return;
    }
    
    newNode->next = temp->next;
    temp->next = newNode;
    cout << "Jadwal penerbangan '" << kode << "' ke " << tujuan 
         << " (Status: " << status << ") berhasil disisipkan di posisi " << posisi << "!" << endl;
}

void hapusJadwalAwal(Node*& head) {
    if (head == nullptr) {
        cout << "Tidak ada jadwal penerbangan untuk dihapus!" << endl;
        return;
    }
    
    Node* temp = head;
    cout << "Menghapus jadwal paling awal: '" << temp->kodePenerbangan 
         << "' ke " << temp->tujuan << " (Status: " << temp->status << ")" << endl;
    
    head = head->next;
    delete temp;
}

void updateStatus(Node*& head, string kodeCari) {
    if (head == nullptr) {
        cout << "Daftar jadwal kosong! Tidak ada yang bisa diupdate." << endl;
        return;
    }
    
    Node* temp = head;
    bool found = false;
    
    while (temp != nullptr) {
        if (temp->kodePenerbangan == kodeCari) {
            found = true;
            string statusBaru;
            cout << "Jadwal '" << kodeCari << "' ditemukan. Status saat ini: " << temp->status << endl;
            cout << "Masukkan status baru (contoh: Tepat Waktu, Terlambat, Naik Pesawat): ";
            getline(cin, statusBaru);
            temp->status = statusBaru;
            cout << "Status jadwal '" << kodeCari << "' berhasil diupdate menjadi: " << statusBaru << endl;
            return;
        }
        temp = temp->next;
    }
    
    if (!found) {
        cout << "Jadwal dengan kode '" << kodeCari << "' tidak ditemukan!" << endl;
    }
}

void tampilkanSemuaJadwal(Node* head) {
    if (head == nullptr) {
        cout << "Daftar jadwal kosong!" << endl;
        return;
    }
    
    cout << "\n=== DAFTAR JADWAL PENERBANGAN ===" << endl;
    Node* temp = head;
    int index = 1;
    while (temp != nullptr) {
        cout << index << ". Kode: " << temp->kodePenerbangan 
             << " | Tujuan: " << temp->tujuan 
             << " | Status: " << temp->status << endl;
        temp = temp->next;
        index++;
    }
    cout << "================================" << endl << endl;
}

void clearJadwal(Node*& head) {
    Node* current = head;
    while (current != nullptr) {
        Node* next = current->next;
        delete current;
        current = next;
    }
    head = nullptr;
    kodeCounter = 0;
}

int main() {
    Node* head = nullptr;
    string namaUser  = "Adityamr";
    string nimUser  = "2409106102";
    
    int digitTerakhir = nimUser .back() - '0';
    int posisiSisip = (digitTerakhir == 0) ? 2 : digitTerakhir + 1;
    
    int choice;
    do {
        cout << "\n+------------------------------------------------------------+" << endl;
        cout << "|         FLIGHT SCHEDULE SYSTEM                             |" << endl;
        cout << "|      " << namaUser  << " - " << nimUser  << "                    |" << endl;
        cout << "+------------------------------------------------------------+" << endl;
        cout << "| 1. Tambah Jadwal Penerbangan                               |" << endl;
        cout << "| 2. Sisipkan Jadwal Penerbangan (Posisi: " << posisiSisip << ") |" << endl;
        cout << "| 3. Hapus Jadwal Paling Awal                                |" << endl;
        cout << "| 4. Update Status Penerbangan                               |" << endl;
        cout << "| 5. Tampilkan Semua Jadwal                                  |" << endl;
        cout << "| 0. Keluar                                                  |" << endl;
        cout << "+------------------------------------------------------------+" << endl;
        cout << "Pilih menu: ";
        cin >> choice;
        cin.ignore();
        
        switch (choice) {
            case 1: {
                string tujuan, status;
                cout << "Masukkan tujuan penerbangan: ";
                getline(cin, tujuan);
                cout << "Masukkan status awal (contoh: Tepat Waktu): ";
                getline(cin, status);
                tambahJadwalBaru(head, tujuan, status);
                break;
            }
            case 2: {
                string tujuan, status;
                cout << "Masukkan tujuan penerbangan: ";
                getline(cin, tujuan);
                cout << "Masukkan status awal (contoh: Tepat Waktu): ";
                getline(cin, status);
                sisipkanJadwal(head, tujuan, status, posisiSisip);
                break;
            }
            case 3: {
                hapusJadwalAwal(head);
                break;
            }
            case 4: {
                string kodeCari;
                cout << "Masukkan kode penerbangan yang ingin diupdate: ";
                getline(cin, kodeCari);
                updateStatus(head, kodeCari);
                break;
            }
            case 5: {
                tampilkanSemuaJadwal(head);
                break;
            }
            case 0: {
                cout << "Terima kasih! Keluar dari program." << endl;
                break;
            }
            default: {
                cout << "Pilihan tidak valid! Silakan pilih lagi." << endl;
            }
        }
    } while (choice != 0);
    
    clearJadwal(head);
    return 0;
}