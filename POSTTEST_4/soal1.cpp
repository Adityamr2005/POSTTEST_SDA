#include <iostream>
#include <string>

using namespace std;

struct Node {
    char data;
    Node* next;
};

void push(Node*& top, char data) {
    Node* newNode = new Node{data, top};
    top = newNode;
}

char pop(Node*& top) {
    if (top == nullptr) return '\0';
    Node* temp = top;
    char poppedValue = temp->data;
    top = top->next;
    delete temp;
    return poppedValue;
}

string reverseString(string s) {
    Node* stackTop = nullptr;
    string reversed = "";
    for (char c : s) {
        push(stackTop, c);
    }
    while (stackTop != nullptr) {
        reversed += pop(stackTop);
    }
    return reversed;
}

int main() {
    string text = "Struktur Data";

    cout << "Teks asli: " << text << endl;
    cout << "Teks terbalik: " << reverseString(text) << endl;

    string text2 = "Pemrograman";
    cout << "Teks asli: " << text2 << endl;
    cout << "Teks terbalik: " << reverseString(text2) << endl;

    return 0;
}

// Jawaban: Teks asli: Struktur Data
// Teks terbalik: ataD rutkurtS
// Teks asli: Pemrograman
// Teks terbalik: namargormeP
// penjelasan:
// Stack digunakan untuk membalik urutan karakter dalam string.
// Karakter terakhir yang dimasukkan ke stack akan menjadi yang pertama diambil saat di-pop,
// sehingga menghasilkan string terbalik.