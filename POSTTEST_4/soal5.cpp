#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

void exchangeHeadAndTail(Node *&head_ref) {
    if (head_ref == nullptr || head_ref->next == head_ref) {
        return;
    }

    Node* head = head_ref;
    Node* tail = head_ref->prev;
    if (head->next == tail) {
        head_ref = tail;
        return;
    }
    Node* head_next = head->next;
    Node* tail_prev = tail->prev;

    head->next = tail;
    head->prev = tail_prev;

    tail->next = head_next;
    tail->prev = head;

    tail_prev->next = head;
    head_next->prev = tail;

    head_ref = tail;
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

void insertEnd(Node *&head_ref, int data)
{
    Node *newNode = new Node{data, nullptr, nullptr};
    if (head_ref == nullptr)
    {
        newNode->next = newNode;
        newNode->prev = newNode;
        head_ref = newNode;
        return;
    }
    Node *tail = head_ref->prev;
    newNode->next = head_ref;
    newNode->prev = tail;
    head_ref->prev = newNode;
    tail->next = newNode;
}

int main()
{
    Node *head = nullptr;
    insertEnd(head, 1);
    insertEnd(head, 2);
    insertEnd(head, 3);
    insertEnd(head, 4);
    insertEnd(head, 5);

    cout << "List sebelum exchange: ";
    printList(head);

    exchangeHeadAndTail(head);

    cout << "List setelah exchange head dan tail: ";
    printList(head);

    return 0;
}

// Jawaban: Circular Doubly Linked List (sebelum exchange): 1 2 3 4 5
// Circular Doubly Linked List (setelah exchange head dan tail): 5 2 3 4 1
// penjelasan:
// Setelah pertukaran, elemen head (1) menjadi tail dan elemen tail (5) menjadi head.
// Urutan elemen di antara head dan tail tetap sama.
// Pointer next dan prev diupdate dengan benar untuk mempertahankan sifat sirkular dan ganda.