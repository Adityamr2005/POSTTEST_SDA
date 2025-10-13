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

void postOrderTraversal(Node* root) {
    if (root == nullptr) {
        return;
    }
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout << root->data << " ";
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

    cout << "Post-order traversal dari tree adalah: ";
    postOrderTraversal(root);
    cout << endl;
    return 0;
}

// Jawaban: Post-order traversal dari tree adalah: 20 40 30 60 80 70 50
// penjelasan: Post-order traversal mengunjungi node dalam urutan kiri, kanan, root.
// Dalam tree yang diberikan, urutan kunjungan adalah 20, 40, 30, 60, 80, 70, dan akhirnya 50.
// Fungsi postOrderTraversal melakukan ini secara rekursif.
// Jadi, outputnya adalah 20 40 30 60 80 70 50.
// Tree yang terbentuk adalah:
//        50
//       /  \
//     30    70
//    /  \   /  \
//  20    40 60  80
// sehingga urutan post-order adalah: 20, 40, 30, 60, 80, 70, 50.
// Setiap node dikunjungi setelah anak-anaknya, menghasilkan urutan yang diinginkan.
// Urutan kunjungan:
// 1. Kiri dari 50 -> 30
// 2. Kiri dari 30 -> 20 (tidak ada anak, cetak 20)
// 3. Kembali ke 30, kanan dari 30 -> 40 (tidak ada anak, cetak 40)
// 4. Kembali ke 30, cetak 30
// 5. Kembali ke 50, kanan dari 50 -> 70
// 6. Kiri dari 70 -> 60 (tidak ada anak, cetak 60)
// 7. Kembali ke 70, kanan dari 70 -> 80 (tidak ada anak, cetak 80)
// 8. Kembali ke 70, cetak 70
// 9. Kembali ke 50, cetak 50
// Ini menghasilkan urutan post-order: 20, 40, 30, 60, 80, 70, 50.
// Jadi, outputnya adalah 20 40 30 60 80 70 50.