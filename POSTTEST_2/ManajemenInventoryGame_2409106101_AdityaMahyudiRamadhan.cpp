#include <iostream>
#include <string>
using namespace std;

struct Node {
    string namaItem;
    int jumlah;
    string tipe;
    Node* next;
};

Node* createNode(string nama, int jml, string tp) {
    Node* newNode = new Node;
    newNode->namaItem = nama;
    newNode->jumlah = jml;
    newNode->tipe = tp;
    newNode->next = nullptr;
    return newNode;
}

void tambahItemBaru(Node*& head, string nama, string tipe) {
    int jumlahAwal = 67;
    Node* newNode = createNode(nama, jumlahAwal, tipe);
    
    if (head == nullptr) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    cout << "Item '" << nama << "' (Tipe: " << tipe << ", Jumlah: " << jumlahAwal << ") berhasil ditambahkan di akhir inventory!" << endl;
}

void sisipkanItem(Node*& head, string nama, string tipe, int posisi) {
    int jumlahAwal = 67;
    Node* newNode = createNode(nama, jumlahAwal, tipe);
    
    if (posisi <= 1 || head == nullptr) {
        newNode->next = head;
        head = newNode;
        cout << "Item '" << nama << "' (Tipe: " << tipe << ", Jumlah: " << jumlahAwal << ") berhasil disisipkan di posisi " << 1 << "!" << endl;
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
        tambahItemBaru(head, nama, tipe);
        return;
    }
    
    newNode->next = temp->next;
    temp->next = newNode;
    cout << "Item '" << nama << "' (Tipe: " << tipe << ", Jumlah: " << jumlahAwal << ") berhasil disisipkan di posisi " << posisi << "!" << endl;
}

void hapusItemTerakhir(Node*& head) {
    if (head == nullptr) {
        cout << "Inventory kosong! Tidak ada item untuk dihapus." << endl;
        return;
    }
    
    if (head->next == nullptr) {
        cout << "Menghapus item terakhir: '" << head->namaItem << "' (Jumlah: " << head->jumlah << ", Tipe: " << head->tipe << ")" << endl;
        delete head;
        head = nullptr;
        return;
    }
    
    Node* temp = head;
    while (temp->next->next != nullptr) {
        temp = temp->next;
    }
    
    cout << "Menghapus item terakhir: '" << temp->next->namaItem << "' (Jumlah: " << temp->next->jumlah << ", Tipe: " << temp->next->tipe << ")" << endl;
    delete temp->next;
    temp->next = nullptr;
}

void gunakanItem(Node*& head, string namaCari) {
    if (head == nullptr) {
        cout << "Inventory kosong! Tidak ada item untuk digunakan." << endl;
        return;
    }
    
    Node* temp = head;
    Node* prev = nullptr;
    bool found = false;
    
    while (temp != nullptr) {
        if (temp->namaItem == namaCari) {
            found = true;
            temp->jumlah--;
            cout << "Menggunakan 1 unit '" << namaCari << "'. Jumlah tersisa: " << temp->jumlah << endl;
            
            if (temp->jumlah <= 0) {
                if (prev == nullptr) {
                    head = temp->next;
                    cout << "Jumlah '" << namaCari << "' habis. Item dihapus dari inventory." << endl;
                    delete temp;
                } else {
                    prev->next = temp->next;
                    cout << "Jumlah '" << namaCari << "' habis. Item dihapus dari inventory." << endl;
                    delete temp;
                }
            }
            return;
        }
        prev = temp;
        temp = temp->next;
    }
    
    if (!found) {
        cout << "Item '" << namaCari << "' tidak ditemukan di inventory!" << endl;
    }
}

void tampilkanInventory(Node* head) {
    if (head == nullptr) {
        cout << "Inventory kosong!" << endl;
        return;
    }
    
    cout << "\n=== INVENTORY SAAT INI ===" << endl;
    Node* temp = head;
    int index = 1;
    while (temp != nullptr) {
        cout << index << ". Nama: " << temp->namaItem 
             << " | Jumlah: " << temp->jumlah 
             << " | Tipe: " << temp->tipe << endl;
        temp = temp->next;
        index++;
    }
    cout << "==========================" << endl << endl;
}

void clearInventory(Node*& head) {
    Node* current = head;
    while (current != nullptr) {
        Node* next = current->next;
        delete current;
        current = next;
    }
    head = nullptr;
}

int main() {
    Node* head = nullptr;
    string namaUser  = "Adityamr"; 
    string nimUser  = "2409106101"; 
    
    int digitTerakhir = nimUser .back() - '0';
    int posisiSisip = (digitTerakhir == 0) ? 2 : digitTerakhir + 1;
    
    int choice;
    do {
        cout << "\n+----------------------------------------------------------------------+" << endl;
        cout << "|         GAME INVENTORY MANAGEMENT                                   |" << endl;
        cout << "|      " << namaUser  << " - " << nimUser  << "                               |" << endl;
        cout << "+----------------------------------------------------------------------+" << endl;
        cout << "| 1. Tambah Item Baru                                                |" << endl;
        cout << "| 2. Sisipkan Item (Posisi: " << posisiSisip << ")                      |" << endl;
        cout << "| 3. Hapus Item Terakhir                                             |" << endl;
        cout << "| 4. Gunakan Item                                                    |" << endl;
        cout << "| 5. Tampilkan Inventory                                             |" << endl;
        cout << "| 0. Keluar                                                          |" << endl;
        cout << "+----------------------------------------------------------------------+" << endl;
        cout << "Pilih menu: ";
        cin >> choice;
        cin.ignore(); 
        
        switch (choice) {
            case 1: {
                string nama, tipe;
                cout << "Masukkan nama item: ";
                getline(cin, nama);
                cout << "Masukkan tipe item (contoh: Sword, Potion): ";
                getline(cin, tipe);
                tambahItemBaru(head, nama, tipe);
                break;
            }
            case 2: {
                string nama, tipe;
                cout << "Masukkan nama item: ";
                getline(cin, nama);
                cout << "Masukkan tipe item (contoh: Sword, Potion): ";
                getline(cin, tipe);
                sisipkanItem(head, nama, tipe, posisiSisip);
                break;
            }
            case 3: {
                hapusItemTerakhir(head);
                break;
            }
            case 4: {
                string namaCari;
                cout << "Masukkan nama item yang ingin digunakan: ";
                getline(cin, namaCari);
                gunakanItem(head, namaCari);
                break;
            }
            case 5: {
                tampilkanInventory(head);
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
    
    clearInventory(head);
    return 0;
}