#include <iostream>
#include <string>

using namespace std;

struct Node {
    string document;
    Node* next;
};

void enqueue(Node*& front, Node*& rear, string document) {
    Node* newNode = new Node{document, nullptr};
    if (front == nullptr) {
        front = newNode;
        rear = newNode;
    } 
    else {
        rear->next = newNode;
        rear = newNode;
    }
}

string dequeue(Node*& front, Node*& rear) {
    if (front == nullptr) return "";
    string documentData = front->document;
    Node* temp = front;
    front = front->next;

    if (front == nullptr) {
        rear = nullptr;
    }
    delete temp;
    return documentData;
}

void processAllDocuments(Node*& front, Node*& rear) {
    string currentDocument;
    while (front != nullptr) {
        currentDocument = dequeue(front, rear);
        cout << "Memproses: " << currentDocument << endl;
    }
}

int main() {
    Node* front = nullptr;
    Node* rear = nullptr;
    enqueue(front, rear, "Document1.pdf");
    enqueue(front, rear, "Report.docx");
    enqueue(front, rear, "Presentation.pptx");

    cout << "Memulai pemrosesan antrian printer:" << endl;
    processAllDocuments(front, rear);

    if (front == nullptr) {
        string result = dequeue(front, rear);
    }
    return 0;
}

// Jawaban: Memulai pemrosesan antrian printer:
// Memproses: Document1.pdf
// Memproses: Report.docx
// Memproses: Presentation.pptx
// penjelasan:
// Dokumen diproses sesuai urutan masuk ke antrian (FIFO)
// dequeue setelah antrian kosong mengembalikan string kosong
// Tidak ada output tambahan dari dequeue setelah antrian kosong
