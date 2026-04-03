#include <iostream>                 // Nguyễn Dương Phúc 24521386
#include <string>
#include <queue>
#include <algorithm>
#include <climits>
using namespace std;

                        //-----------------build link list (QUESTION 1)
struct Node {
    int data;
    Node* next;
};

Node* createNode(int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;
    return newNode;
}


void insertFront(Node*& head, int value) {
    Node* newNode = createNode(value);
    newNode->next = head;
    head = newNode;
}

// Thêm vào cuối danh sách
void insertBack(Node*& head, int value) {
    Node* newNode = createNode(value);
    if (head == nullptr) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newNode;
}


bool find(Node* head, int value) {
    Node* temp = head;
    while (temp != nullptr) {
        if (temp->data == value)
            return true;
        temp = temp->next;
    }
    return false;
}

// Xóa phần tử
void deleteNode(Node*& head, int value) {
    if (head == nullptr) return;

    // Nếu phần tử đầu là giá trị cần xóa
    if (head->data == value) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    // Duyệt danh sách để tìm phần tử
    Node* prev = head;
    Node* curr = head->next;
    while (curr != nullptr && curr->data != value) {
        prev = curr;
        curr = curr->next;
    }

    if (curr == nullptr) return; // Không tìm thấy

    prev->next = curr->next;
    delete curr;
}

// In danh sách
void printList(Node* head) {
    Node* temp = head;
    cout << "List: ";
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
                    //-----------------build stack (QUESTION 2)
struct Stack {
    Node* top;
};

// Khởi tạo stack
void init(Stack& s) {
    s.top = nullptr;
}

// Kiểm tra rỗng
bool isEmpty(Stack& s) {
    return s.top == nullptr;
}

// Push phần tử vào stack
void push(Stack& s, char value) {
    Node* newNode = createNode(value);
    newNode->next = s.top;
    s.top = newNode;
}

// Pop phần tử ra khỏi stack
void pop(Stack& s) {
    if (isEmpty(s)) return;
    Node* temp = s.top;
    s.top = s.top->next;
    delete temp;
}

// Lấy phần tử trên cùng
char peek(Stack& s) {
    if (isEmpty(s)) return '\0';
    return s.top->data;
}

// kt giá trị
bool isValid(string str) {
    Stack s;
    init(s);

    for (char c : str) {
        if (c == '(' || c == '[' || c == '{') {
            push(s, c);
        } else if (c == ')' || c == ']' || c == '}') {
            if (isEmpty(s)) return false; // không có gì để đóng

            char topChar = peek(s);
            if ((c == ')' && topChar == '(') ||
                (c == ']' && topChar == '[') ||
                (c == '}' && topChar == '{')) {
                pop(s);
            } else {
                return false; // sai thứ tự
            }
        }
    }

    return isEmpty(s); // nếu stack rỗng => hợp lệ
}

                    //-----------------build queue (QUESTION 3)
struct Queue {
    Node* front;
    Node* rear;
};

void initQueue(Queue& q) {
    q.front = q.rear = nullptr;
}

bool isEmptyQueue(Queue& q) {
    return q.front == nullptr;
}

void enqueue(Queue& q, int value) {
    Node* newNode = createNode(value);
    if (isEmptyQueue(q)) {
        q.front = q.rear = newNode;
    } else {
        q.rear->next = newNode;
        q.rear = newNode;
    }
    cout << "Enqueued: " << value << endl;
}

void dequeue(Queue& q) {
    if (isEmptyQueue(q)) {
        cout << "Queue is empty\n";
        return;
    }
    Node* temp = q.front;
    cout << "Dequeued: " << temp->data << endl;
    q.front = q.front->next;
    if (q.front == nullptr) q.rear = nullptr;
    delete temp;
}

int frontQueue(Queue& q) {
    if (isEmptyQueue(q)) {
        cout << "Queue is empty\n";
        return -1;
    }
    return q.front->data;
}

void printQueue(Queue& q) {
    cout << "Queue: ";
    if (isEmptyQueue(q)) {
        cout << "empty";
    } else {
        Node* temp = q.front;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
    cout << endl;
}

                    //------------Binary Search Tree (QUESTION 4)
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
};

TreeNode* createTreeNode(int value) {
    TreeNode* node = new TreeNode;
    node->data = value;
    node->left = node->right = nullptr;
    return node;
}

// Thêm node vào BST
TreeNode* insertBST(TreeNode* root, int value) {
    if (root == nullptr)
        return createTreeNode(value);
    if (value < root->data)
        root->left = insertBST(root->left, value);
    else if (value > root->data)
        root->right = insertBST(root->right, value);
    return root;
}

// Tìm kiếm node trong BST
bool searchBST(TreeNode* root, int x) {
    if (root == nullptr)
        return false;
    if (root->data == x)
        return true;
    else if (x < root->data)
        return searchBST(root->left, x);
    else
        return searchBST(root->right, x);
}

                    //-----------------AVL Tree (QUESTION 5)
struct AVLNode {
    int data;
    AVLNode* left;
    AVLNode* right;
    int height;
};

int getHeight(AVLNode* node) {
    return node ? node->height : 0;
}

int getBalance(AVLNode* node) {
    return node ? getHeight(node->left) - getHeight(node->right) : 0;
}

AVLNode* createAVLNode(int value) {
    AVLNode* node = new AVLNode;
    node->data = value;
    node->left = node->right = nullptr;
    node->height = 1;
    return node;
}

AVLNode* rightRotate(AVLNode* y) {
    AVLNode* x = y->left;
    AVLNode* T2 = x->right;
    x->right = y;
    y->left = T2;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    return x;
}

AVLNode* leftRotate(AVLNode* x) {
    AVLNode* y = x->right;
    AVLNode* T2 = y->left;
    y->left = x;
    x->right = T2;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    return y;
}

AVLNode* insertAVL(AVLNode* node, int value) {
    if (node == nullptr) return createAVLNode(value);

    if (value < node->data)
        node->left = insertAVL(node->left, value);
    else if (value > node->data)
        node->right = insertAVL(node->right, value);
    else
        return node; // no duplicate

    node->height = 1 + max(getHeight(node->left), getHeight(node->right));

    int balance = getBalance(node);

    // Left Left
    if (balance > 1 && value < node->left->data)
        return rightRotate(node);

    // Right Right
    if (balance < -1 && value > node->right->data)
        return leftRotate(node);

    // Left Right
    if (balance > 1 && value > node->left->data) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Right Left
    if (balance < -1 && value < node->right->data) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}
                    //--------------------Red-Black Tree (QUESTION 6)
#define RED 0
#define BLACK 1

struct RBNode {
    int data;
    int color; // 0 = RED, 1 = BLACK
    RBNode* left;
    RBNode* right;
    RBNode* parent;
};

RBNode* createRBNode(int data) {
    RBNode* node = new RBNode;
    node->data = data;
    node->color = RED;
    node->left = node->right = node->parent = nullptr;
    return node;
}

RBNode* leftRotate(RBNode* root, RBNode* x) {
    RBNode* y = x->right;
    x->right = y->left;
    if (y->left) y->left->parent = x;
    y->parent = x->parent;

    if (!x->parent)
        root = y;
    else if (x == x->parent->left)
        x->parent->left = y;
    else
        x->parent->right = y;

    y->left = x;
    x->parent = y;
    return root;
}

RBNode* rightRotate(RBNode* root, RBNode* y) {
    RBNode* x = y->left;
    y->left = x->right;
    if (x->right) x->right->parent = y;
    x->parent = y->parent;

    if (!y->parent)
        root = x;
    else if (y == y->parent->left)
        y->parent->left = x;
    else
        y->parent->right = x;

    x->right = y;
    y->parent = x;
    return root;
}

RBNode* fixInsert(RBNode* root, RBNode* z) {
    while (z->parent && z->parent->color == RED) {
        RBNode* grand = z->parent->parent;
        if (z->parent == grand->left) {
            RBNode* uncle = grand->right;
            if (uncle && uncle->color == RED) {
                z->parent->color = BLACK;
                uncle->color = BLACK;
                grand->color = RED;
                z = grand;
            } else {
                if (z == z->parent->right) {
                    z = z->parent;
                    root = leftRotate(root, z);
                }
                z->parent->color = BLACK;
                grand->color = RED;
                root = rightRotate(root, grand);
            }
        } else {
            RBNode* uncle = grand->left;
            if (uncle && uncle->color == RED) {
                z->parent->color = BLACK;
                uncle->color = BLACK;
                grand->color = RED;
                z = grand;
            } else {
                if (z == z->parent->left) {
                    z = z->parent;
                    root = rightRotate(root, z);
                }
                z->parent->color = BLACK;
                grand->color = RED;
                root = leftRotate(root, grand);
            }
        }
    }
    root->color = BLACK;
    return root;
}

RBNode* insertRB(RBNode* root, int data) {
    RBNode* z = createRBNode(data);
    RBNode* y = nullptr;
    RBNode* x = root;

    while (x) {
        y = x;
        if (z->data < x->data)
            x = x->left;
        else if (z->data > x->data)
            x = x->right;
        else
            return root; // Không chèn trùng
    }

    z->parent = y;
    if (!y)
        root = z;
    else if (z->data < y->data)
        y->left = z;
    else
        y->right = z;

    return fixInsert(root, z);
}

void inorder(RBNode* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->data << "(" << (root->color == RED ? "R" : "B") << ") ";
    inorder(root->right);
}

                    //--------------------Hash Table (Chaining) (QUESTION 7)
const int TABLE_SIZE = 5; // số bucket, có thể đổi

struct HashTable {
    Node* table[TABLE_SIZE];
};

// Hàm băm
int hashFunction(int key) {
    return key % TABLE_SIZE;
}

// Khởi tạo hash table
void initHash(HashTable& h) {
    for (int i = 0; i < TABLE_SIZE; ++i)
        h.table[i] = nullptr;
}

// Thêm phần tử vào hash table
void insertKey(HashTable& h, int key) {
    int index = hashFunction(key);
    Node* newNode = createNode(key);

    // Thêm vào đầu danh sách trong bucket đó
    newNode->next = h.table[index];
    h.table[index] = newNode;

    cout << "Inserted " << key << " into bucket " << index << endl;
}

// Xóa phần tử khỏi hash table
void deleteKey(HashTable& h, int key) {
    int index = hashFunction(key);
    Node* curr = h.table[index];
    Node* prev = nullptr;

    while (curr != nullptr && curr->data != key) {
        prev = curr;
        curr = curr->next;
    }

    if (curr == nullptr) {
        cout << key << " not found\n";
        return;
    }

    if (prev == nullptr)
        h.table[index] = curr->next;
    else
        prev->next = curr->next;

    delete curr;
    cout << "Deleted " << key << " from bucket " << index << endl;
}

// Tìm phần tử trong hash table
bool searchKey(HashTable& h, int key) {
    int index = hashFunction(key);
    Node* curr = h.table[index];
    while (curr != nullptr) {
        if (curr->data == key)
            return true;
        curr = curr->next;
    }
    return false;
}

// In toàn bộ hash table
void printHash(HashTable& h) {
    cout << "\nHash Table contents:\n";
    for (int i = 0; i < TABLE_SIZE; ++i) {
        cout << "[" << i << "]: ";
        Node* curr = h.table[i];
        if (!curr) cout << "empty";
        while (curr != nullptr) {
            cout << curr->data << " -> ";
            curr = curr->next;
        }
        cout << "NULL\n";
    }
}

                    //--------------------Dictionary (Hash Table + Trie) (QUESTION 8)
        //Hash Table
const int DICT_TABLE_SIZE = 10;

// Node cho Hash Table (lưu word và meaning)
struct DictNode {
    string word;
    string meaning;
    DictNode* next;
};

// Hash Table cho từ điển
struct DictHashTable {
    DictNode* table[DICT_TABLE_SIZE];
};

// Hàm băm cho chuỗi
int hashString(const string& key) {
    int hash = 0;
    for (char c : key)
        hash = (hash * 31 + c) % DICT_TABLE_SIZE;
    return hash;
}

// Khởi tạo
void initDict(DictHashTable& dict) {
    for (int i = 0; i < DICT_TABLE_SIZE; ++i)
        dict.table[i] = nullptr;
}

// Thêm từ vào hash table
void insertWord(DictHashTable& dict, const string& word, const string& meaning) {
    int index = hashString(word);
    DictNode* newNode = new DictNode{word, meaning, dict.table[index]};
    dict.table[index] = newNode;
}

// Tìm nghĩa của từ
string findWord(DictHashTable& dict, const string& word) {
    int index = hashString(word);
    DictNode* curr = dict.table[index];
    while (curr) {
        if (curr->word == word)
            return curr->meaning;
        curr = curr->next;
    }
    return "";
}

        //Trie cho gợi ý 

struct TrieNode {
    TrieNode* children[26];
    bool isEnd;
    string word;
    TrieNode() {
        isEnd = false;
        word = "";
        for (int i = 0; i < 26; i++)
            children[i] = nullptr;
    }
};

// Thêm từ vào Trie
void insertTrie(TrieNode* root, const string& word) {
    TrieNode* node = root;
    for (char c : word) {
        int index = c - 'a';
        if (!node->children[index])
            node->children[index] = new TrieNode();
        node = node->children[index];
    }
    node->isEnd = true;
    node->word = word;
}

// Duyệt tất cả gợi ý
void collectSuggestions(TrieNode* node) {
    if (node == nullptr) return;
    if (node->isEnd)
        cout << node->word << " ";
    for (int i = 0; i < 26; i++)
        collectSuggestions(node->children[i]);
}

// Gợi ý từ prefix
void suggestWords(TrieNode* root, const string& prefix) {
    TrieNode* node = root;
    for (char c : prefix) {
        int index = c - 'a';
        if (!node->children[index]) {
            cout << "No suggestions\n";
            return;
        }
        node = node->children[index];
    }

    cout << "Suggestions: ";
    collectSuggestions(node);
    cout << endl;
}

                    //------------------Binary Search Tree (BST) using pointers (QUESTION 9)
void inorderTraversal(TreeNode* root) {
    if (root == nullptr) return;
    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}

                    //------------------Quản lý Binary Tree bằng menu (QUESTION 10)
// Cấu trúc Node 
struct BinaryNode {
    int data;
    BinaryNode* left;
    BinaryNode* right;
};

BinaryNode* createBinaryNode(int value) {
    BinaryNode* node = new BinaryNode;
    node->data = value;
    node->left = node->right = nullptr;
    return node;
}

// Duyệt cây 
void traversePreorder(BinaryNode* root) {
    if (!root) return;
    cout << root->data << " ";
    traversePreorder(root->left);
    traversePreorder(root->right);
}

void traverseInorder(BinaryNode* root) {
    if (!root) return;
    traverseInorder(root->left);
    cout << root->data << " ";
    traverseInorder(root->right);
}

void traversePostorder(BinaryNode* root) {
    if (!root) return;
    traversePostorder(root->left);
    traversePostorder(root->right);
    cout << root->data << " ";
}

// Thêm Node
BinaryNode* insertBinaryTree(BinaryNode* root, int value) {
    BinaryNode* newNode = createBinaryNode(value);
    if (!root) return newNode;

    queue<BinaryNode*> q;
    q.push(root);

    while (!q.empty()) {
        BinaryNode* temp = q.front(); q.pop();
        if (!temp->left) {
            temp->left = newNode;
            break;
        } else q.push(temp->left);

        if (!temp->right) {
            temp->right = newNode;
            break;
        } else q.push(temp->right);
    }
    return root;
}

// Tính chiều cao 
int height(BinaryNode* root) {
    if (!root) return 0;
    return 1 + max(height(root->left), height(root->right));
}

//tìm giá trị lớn nhất 
int findMax(BinaryNode* root) {
    if (!root) return INT_MIN;
    return max(root->data, max(findMax(root->left), findMax(root->right)));
}

// Xóa toàn bộ cây 
void deleteTree(BinaryNode*& root) {
    if (!root) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
    root = nullptr;
}

                    //--------------------Question 1 -> 10

                    //question 1
void question1() {
    cout << "Question 1:" << endl;
    Node* head = nullptr;

    // Ví dụ thao tác
    insertFront(head, 4);
    insertFront(head, 6);
    insertBack(head, 8);
    insertBack(head, 10);

    cout << boolalpha;
    cout << "find(5): " << find(head, 5) << endl; // False
    cout << "find(6): " << find(head, 6) << endl; // True

    deleteNode(head, 6);
    cout << "After delete(6): ";
    printList(head);

    cout << "find(6): " << find(head, 6) << endl; // False

    cout << "Final ";
    printList(head);
    cout << endl;
}
                    //question 2
void question2() {
    cout << "Question 2:" << endl;
    string input = "(())([[{[]}])";
    cout << "Input: " << input << endl;
    cout << "Output: " << boolalpha << isValid(input) << endl;
    cout << endl;
}
                    //question 3
void question3() {
    cout << "Question 3:" << endl;
    Queue q;
    initQueue(q);

    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    enqueue(q, 40);
    printQueue(q);

    dequeue(q);
    printQueue(q);

    cout << "Front element: " << frontQueue(q) << endl;

    enqueue(q, 50);
    printQueue(q);

    dequeue(q);
    printQueue(q);
    cout << endl;
}
                    //question 4
void question4() {
    cout << "Question 4:" << endl;
    int n = 7;
    int arr[] = {55, 34, 87, 3, 99, 33, 21};
    int x = 21;

    TreeNode* root = nullptr;

    for (int i = 0; i < n; i++) {
        root = insertBST(root, arr[i]);
    }

    cout << "Searching for " << x << endl;
    if (searchBST(root, x))
        cout << "Found" << endl;
    else
        cout << "Not found" << endl;
    cout << endl;
}
                    //question 5
void question5() {
    cout << "Question 5:" << endl;
    int n = 7;
    int arr[] = {10, 20, 30, 40, 50, 25, 5};

    AVLNode* root = nullptr;
    for (int i = 0; i < n; ++i) {
        root = insertAVL(root, arr[i]);
        cout << "Inserted " << arr[i] << ", height = " << getHeight(root) << endl;
    }
    cout << endl;
}
                //Question 6
void question6() {
    cout << "Question 6:\n";
    int arr[] = {10, 5, 15, 2, 7, 13};
    int n = sizeof(arr) / sizeof(arr[0]);

    RBNode* root = nullptr;
    for (int i = 0; i < n; ++i)
        root = insertRB(root, arr[i]);

    inorder(root);
    cout << endl;
}
                    //Question 7
void question7() {
    cout << "Question 7:\n";
    HashTable h;
    initHash(h);

    // Thêm phần tử
    insertKey(h, 10);
    insertKey(h, 15);
    insertKey(h, 20);
    insertKey(h, 7);
    insertKey(h, 12);
    insertKey(h, 17);

    printHash(h);

    cout << "\nSearch 15: " << (searchKey(h, 15) ? "Found" : "Not found") << endl;
    cout << "Search 8: " << (searchKey(h, 8) ? "Found" : "Not found") << endl;

    deleteKey(h, 15);
    deleteKey(h, 8);

    printHash(h);
    cout << endl;
}
                    // Question 8
void question8() {
    cout << "Question 8:\n";

    DictHashTable dict;
    initDict(dict);
    TrieNode* root = new TrieNode();

    // Insert dữ liệu
    insertWord(dict, "hello", "xin_chao");
    insertTrie(root, "hello");

    insertWord(dict, "help", "giup_do");
    insertTrie(root, "help");

    insertWord(dict, "hero", "anh_hung");
    insertTrie(root, "hero");

    // find hello
    string meaning = findWord(dict, "hello");
    if (meaning != "")
        cout << "hello -> " << meaning << endl;
    else
        cout << "Not found\n";

    // find hi
    meaning = findWord(dict, "hi");
    if (meaning != "")
        cout << "hi -> " << meaning << endl;
    else
        cout << "Not found\n";

    // suggest he
    suggestWords(root, "he");

    cout << endl;
}
                    //Question 9
void question9() {
    cout << "Question 9:\n";

    int arr[] = {5, 3, 7, 2, 4, 6, 8};
    int n = sizeof(arr) / sizeof(arr[0]);

    TreeNode* root = nullptr;

    // Insert các giá trị
    for (int i = 0; i < n; i++) {
        root = insertBST(root, arr[i]);
    }

    // Inorder traversal (sorted)
    cout << "Inorder (sorted): ";
    inorderTraversal(root);
    cout << endl;

    // Tìm kiếm
    int x;
    cout << "Enter value to search: ";
    cin >> x;

    if (searchBST(root, x))
        cout << "Result: Found node " << x << " in the tree\n";
    else
        cout << "Result: Node " << x << " not found in the tree\n";

    cout << endl;
}
                    // Quesion 10
void question10() {
    cout << "Question 10: Binary Tree Manager\n";

    BinaryNode* root = nullptr;
    int choice;

    while (true) {
        cout << "\n=== MENU ===\n";
        cout << "1. Add new node\n";
        cout << "2. Traverse tree (Pre/In/Post)\n";
        cout << "3. Calculate height\n";
        cout << "4. Find maximum value\n";
        cout << "5. Delete entire tree\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (cin.fail()) { // TH ko nhập số mà nhập chữ thì cho cái này vào ko nó chạy liên tục
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Invalid input, try again.\n";
        continue;
            }

        if (choice == 1) {
            int value;
            cout << "Enter value to add: ";
            cin >> value;
            root = insertBinaryTree(root, value);
            cout << "Node added successfully.\n";
        } 
        else if (choice == 2) {
            if (!root) { cout << "Tree is empty.\n"; continue; }
            cout << "Preorder: "; traversePreorder(root); cout << endl;
            cout << "Inorder: "; traverseInorder(root); cout << endl;
            cout << "Postorder: "; traversePostorder(root); cout << endl;
        }
        else if (choice == 3) {
            cout << "Height of tree: " << height(root) << endl;
        } 
        else if (choice == 4) {
            if (!root) cout << "Tree is empty.\n";
            else cout << "Maximum value in tree: " << findMax(root) << endl;
        }
        else if (choice == 5) {
            deleteTree(root);
            cout << "Tree deleted successfully.\n";
        } 
        else if (choice == 6) {
            deleteTree(root);
            cout << "Exiting program...\n";
            break;
        }
        else {
            cout << "Invalid choice. Try again.\n";
        }
    }
}


int main() {
    question1();
    question2();
    question3();
    question4();
    question5();
    question6();
    question7();
    question8();
    question9();    // cần nhập
    question10();   // cần nhập
    return 0;
}