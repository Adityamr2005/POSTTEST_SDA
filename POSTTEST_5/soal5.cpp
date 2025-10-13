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

void preOrderTraversal(Node* root) {
    if (root == nullptr) {
        return;
    }
    cout << root->data << " ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

int main() {
    Node* root = nullptr;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);
    insert(root, 60);
    insert(root, 80);

    cout << "Pre-order traversal dari tree adalah: ";
    preOrderTraversal(root);
    cout << endl;
    return 0;
}

// Jawaban: Pre-order traversal dari tree adalah: 50 30 20 40 70 60 80
// penjelasan: Pre-order traversal mengunjungi node dalam urutan root, kiri, kanan.
// Dalam tree yang diberikan, urutan kunjungan adalah 50, 30, 20, 40, 70, 60, dan akhirnya 80.
// Fungsi preOrderTraversal melakukan ini secara rekursif.
// Jadi, outputnya adalah 50 30 20 40 70 60 80.
// Tree yang terbentuk adalah:
//        50
//       /  \
//     30    70
//    /  \   /  \
//  20    40 60   80
// sehingga urutan pre-order adalah: 50, 30, 20, 40, 70, 60, 80.
// yang dimulai dari root 50, kemudian ke kiri 30, lalu ke kiri lagi 20 (tidak ada anak), kembali ke 30, ke kanan 40 (tidak ada anak), kembali ke 50, ke kanan 70, ke kiri 60 (tidak ada anak), kembali ke 70, dan akhirnya ke kanan 80 (tidak ada anak).