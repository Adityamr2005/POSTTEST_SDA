#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

void sortedInsert(Node *&head_ref, int data) {
    Node* newNode = new Node{data, nullptr, nullptr};

    if (head_ref == nullptr) {
        newNode->next = newNode;
        newNode->prev = newNode;
        head_ref = newNode;
        return;
    }

    if (data < head_ref->data) {
        Node* tail = head_ref->prev;
        newNode->next = head_ref;
        head_ref->prev = newNode;
        newNode->prev = tail;
        tail->next = newNode;
        head_ref = newNode;
        return;
    }
    Node* current = head_ref;

    while (current->next != head_ref && current->next->data < data) {
        current = current->next;
    }

    Node* nextNode = current->next;
    newNode->next = nextNode;
    newNode->prev = current;
    current->next = newNode;
    nextNode->prev = newNode;
}

void printList(Node *head_ref)
{
    if (head_ref == nullptr)
    {
        cout << "List kosong" << endl;
        return;
    }
    Node *current = head_ref;
    do
    {
        cout << current->data << " ";
        current = current->next;
    } while (current != head_ref);
    cout << endl;
}

int main()
{
    Node *head = nullptr;
    // Test sorted insert
    sortedInsert(head, 30);
    sortedInsert(head, 10);
    sortedInsert(head, 40);
    sortedInsert(head, 20);
    sortedInsert(head, 10);
    sortedInsert(head, 50);
    sortedInsert(head, 5);

    cout << "Circular Doubly Linked List (sorted): ";
    printList(head);
    return 0;
}

// Jawaban: Circular Doubly Linked List (sorted): 5 10 10 20 30 40 50
// Penjelasan:
// Data disisipkan dalam urutan terurut: 5, 10, 10, 20, 30, 40, 50
// Duplikat 10 disisipkan setelah 10 yang pertama
// 5 disisipkan di awal karena lebih kecil dari semua elemen lainnya
// 50 disisipkan di akhir karena lebih besar dari semua elemen lainnya
// Semua pointer next dan prev diupdate dengan benar untuk mempertahankan sifat sirkular dan ganda