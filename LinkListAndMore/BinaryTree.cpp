#include <iostream>
using namespace std;

struct Node {
    int Data;
    Node* Left;
    Node* Right;
};

// Tạo node mới
Node* CreateNode(int value) {
    Node* p = new Node;
    p->Data = value;
    p->Left = nullptr;
    p->Right = nullptr;
    return p;
}

// Tìm node theo giá trị (DFS)
Node* Find(Node* root, int value) {
    if (root == nullptr) return nullptr;
    if (root->Data == value) return root;

    Node* leftSearch = Find(root->Left, value);
    if (leftSearch != nullptr) return leftSearch;

    return Find(root->Right, value);
}

int main() {
    // Tạo cây mẫu
    Node* root = CreateNode(1);
    root->Left = CreateNode(2);
    root->Right = CreateNode(3);
    root->Left->Left = CreateNode(4);
    root->Left->Right = CreateNode(5);

    int value;
    cout << "Enter value to find: ";
    cin >> value;

    Node* f = Find(root, value);
    if (f != nullptr) cout << "Found: " << f->Data << endl;
    else cout << "Not found\n";

    return 0;
}
