#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

struct List {
    Node* head = NULL;
    Node* tail = NULL;
};

void addTail(List& l, int x) {
    Node* p = new Node{x, NULL};
    if (!l.head) l.head = l.tail = p;
    else {
        l.tail->next = p;
        l.tail = p;
    }
}

void removeHead(List& l) {
    if (!l.head) return;
    Node* p = l.head;
    l.head = l.head->next;
    if (!l.head) l.tail = NULL;
    delete p;
}
const int SIZE = 5;

struct Node {
    int data;
    Node* next;
};

struct HashTable {
    Node* table[SIZE] = {NULL};
};

int hashFunc(int x) {
    return x % SIZE;
}

void insert(HashTable& h, int x) {
    int i = hashFunc(x);
    Node* p = new Node{x, h.table[i]};
    h.table[i] = p;
}

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* insert(Node* root, int x) {
    if (!root) return new Node{x, NULL, NULL};
    if (x < root->data)
        root->left = insert(root->left, x);
    else if (x > root->data)
        root->right = insert(root->right, x);
    return root;
}

void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

bool find(Node* root, int x) {
    if (!root) return false;
    if (x == root->data) return true;
    if (x < root->data) return find(root->left, x);
    return find(root->right, x);
}
