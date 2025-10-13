#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

Node* insert(Node* root, int val) {
    if (root == nullptr) {
        return new Node(val);
    }
    if (val < root->data) {
        root->left = insert(root->left, val);
    } else if (val > root->data) {
        root->right = insert(root->right, val);
    }
    return root;
}

int findMinValue(Node* root) {
    if (root == nullptr) {
        return -1;
    }

    Node* current = root;
    while (current->left != nullptr) {
        current = current->left;
    }
    return current->data;
}

int main() {
    Node* root = nullptr;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);

    cout << "Nilai terkecil dalam tree adalah: " << findMinValue(root) << endl;
    return 0;
}

// Jawaban: Nilai terkecil dalam tree adalah: 20
// penjelasan: Nilai terkecil dalam binary search tree dapat ditemukan dengan menavigasi ke node paling kiri.
// Dalam tree yang diberikan, node paling kiri adalah 20, sehingga itu adalah nilai terkecil.
// Fungsi findMinValue melakukan ini dengan iterasi ke kiri hingga tidak ada lagi node kiri.
// Jadi, outputnya adalah 20.
// Tree yang terbentuk adalah:
//        50
//       /  \
//     30    70
//    /  \
//  20    40
// Nilai terkecil adalah 20.
