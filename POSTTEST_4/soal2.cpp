#include <iostream>
#include <string>

using namespace std;

struct Node {
    char data;
    Node* next;
};

void push(Node** stackTop, char data) {
    Node* newNode = new Node;
    if (!newNode) {
        cerr << "Error: Memory allocation failed." << endl;
        return;
    }
    newNode->data = data;
    newNode->next = *stackTop;
    *stackTop = newNode;
}

char pop(Node** stackTop) {
    if (*stackTop == nullptr) {
        return '\0';
    }
    Node* temp = *stackTop;
    char poppedData = temp->data;
    *stackTop = (*stackTop)->next;
    delete temp;
    return poppedData;
}

bool isEmpty(Node* stackTop) {
    return stackTop == nullptr;
}

bool isMatchingPair(char opening, char closing) {
    if (opening == '(' && closing == ')') return true;
    if (opening == '{' && closing == '}') return true;
    if (opening == '[' && closing == ']') return true;
    return false;
}

bool areBracketsBalanced(string expr) {
    Node* stackTop = nullptr;

    for (char c : expr) {
        if (c == '(' || c == '{' || c == '[') {
            push(&stackTop, c);
        }
        else if (c == ')' || c == '}' || c == ']') {
            if (isEmpty(stackTop)) {
                return false;
            }

            char popped_char = pop(&stackTop);
            if (!isMatchingPair(popped_char, c)) {
                return false;
            }
        }
    }
    return isEmpty(stackTop);
}

int main() {
    string expr1 = "{[()]}";
    cout << expr1 << " -> " << (areBracketsBalanced(expr1) ? "Seimbang" : "Tidak Seimbang") << endl;

    string expr2 = "{[(])}";
    cout << expr2 << " -> " << (areBracketsBalanced(expr2) ? "Seimbang" : "Tidak Seimbang") << endl;

    string expr3 = "()";
    cout << expr3 << " -> " << (areBracketsBalanced(expr3) ? "Seimbang" : "Tidak Seimbang") << endl;

    string expr4 = "(((";
    cout << expr4 << " -> " << (areBracketsBalanced(expr4) ? "Seimbang" : "Tidak Seimbang") << endl;

    string expr5 = ")]";
    cout << expr5 << " -> " << (areBracketsBalanced(expr5) ? "Seimbang" : "Tidak Seimbang") << endl;

    return 0;
}

// Jawaban: {[()]} -> Seimbang
// {[(])} -> Tidak Seimbang
// () -> Seimbang
// ((() -> Tidak Seimbang
// )] -> Tidak Seimbang
// penjelasan:
// Pada expr1, semua kurung buka memiliki pasangan kurung tutup yang sesuai dan urutannya benar.
// Pada expr2, kurung tutup ']' tidak sesuai dengan kurung buka '(' yang terakhir dibuka.
// Pada expr3, satu pasang kurung buka dan tutup yang sesuai.
// Pada expr4, ada tiga kurung buka tanpa kurung tutup yang sesuai.
// Pada expr5, ada kurung tutup tanpa kurung buka yang sesuai.
// Tidak ada output tambahan dari fungsi push dan pop.