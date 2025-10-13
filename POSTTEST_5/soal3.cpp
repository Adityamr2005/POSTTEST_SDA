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

int findMaxValue(Node* root) {
    if (root == nullptr) {
        return -1;
    }

    Node* current = root;
    while (current->right != nullptr) {
        current = current->right;
    }
    return current->data;
}

int main() {
    Node* root = nullptr;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 80);

    cout << "Nilai terbesar dalam tree adalah: " << findMaxValue(root) << endl;
    return 0;
}

// Jawaban: Nilai terbesar dalam tree adalah: 80
// penjelasan: Nilai terbesar dalam binary search tree dapat ditemukan dengan menavigasi ke node paling kanan.
// Dalam tree yang diberikan, node paling kanan adalah 80, sehingga itu adalah nilai terbesar.
// Fungsi findMaxValue melakukan ini dengan iterasi ke kanan hingga tidak ada lagi node kanan.
// Jadi, outputnya adalah 80.
// Tree yang terbentuk adalah:
//        50
//       /  \
//     30    70
//    /  \     \
//  20    40   80
// Nilai terbesar adalah 80.

