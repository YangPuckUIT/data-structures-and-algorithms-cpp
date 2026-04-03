#include <iostream>

using namespace std;

// NOTE: câu 1 ko làm BST vì câu 8 sẽ có nên chỉ làm 2 cái đầu thôi: array list và linked lít

//                          1 ArrayList (dynamic array) 
struct ArrayListQ1 {
    int* data;
    int capacity;
    int length;
};

void initListQ1(ArrayListQ1 &list, int cap = 100) {
    list.data = new int[cap];
    list.capacity = cap;
    list.length = 0;
}

void insertQ1(ArrayListQ1 &list, int pos, int x) {
    if (pos < 0 || pos > list.length) return;
    if (list.length >= list.capacity) return;
    for (int i = list.length; i > pos; i--) list.data[i] = list.data[i-1];
    list.data[pos] = x;
    list.length++;
}

void removeQ1(ArrayListQ1 &list, int pos) {
    if (pos < 0 || pos >= list.length) return;
    for (int i = pos; i < list.length-1; i++) list.data[i] = list.data[i+1];
    list.length--;
}

int getQ1(ArrayListQ1 &list, int pos) {
    if (pos < 0 || pos >= list.length) return -1;
    return list.data[pos];
}

int sizeQ1(ArrayListQ1 &list) { return list.length; }

void displayQ1(ArrayListQ1 &list) {
    for (int i = 0; i < list.length; i++) cout << list.data[i] << " ";
    cout << "\n";
}

//                           1 Linked List 
struct NodeQ1 {
    int data;
    NodeQ1* next;
};

NodeQ1* createNodeQ1(int x) {
    NodeQ1* p = new NodeQ1;
    p->data = x;
    p->next = nullptr;
    return p;
}

void appendQ1(NodeQ1* &head, int x) {
    NodeQ1* newNode = createNodeQ1(x);
    if (!head) { head = newNode; return; }
    NodeQ1* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = newNode;
}

void insertQ1(NodeQ1* &head, int pos, int x) {
    NodeQ1* newNode = createNodeQ1(x);
    if (pos == 0) {
        newNode->next = head;
        head = newNode;
        return;
    }
    NodeQ1* temp = head;
    for (int i = 0; temp && i < pos-1; i++) temp = temp->next;
    if (!temp) return;
    newNode->next = temp->next;
    temp->next = newNode;
}

void removeQ1(NodeQ1* &head, int pos) {
    if (!head) return;
    if (pos == 0) {
        NodeQ1* tmp = head;
        head = head->next;
        delete tmp;
        return;
    }
    NodeQ1* temp = head;
    for (int i = 0; temp && i < pos-1; i++) temp = temp->next;
    if (!temp || !temp->next) return;
    NodeQ1* tmp = temp->next;
    temp->next = tmp->next;
    delete tmp;
}

int getQ1(NodeQ1* head, int pos) {
    NodeQ1* temp = head;
    for (int i = 0; temp && i < pos; i++) temp = temp->next;
    return temp ? temp->data : -1;
}

void displayQ1(NodeQ1* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << "\n";
}

//                          2: List ADT using dynamic array 
struct ArrayList {
    int* data;
    int capacity;
    int length;
};

void initList(ArrayList &list, int cap = 100) {
    list.data = new int[cap];
    list.capacity = cap;
    list.length = 0;
}

void insert(ArrayList &list, int pos, int x) {
    if (pos < 0 || pos > list.length) {
        cout << "Invalid position\n";
        return;
    }
    if (list.length >= list.capacity) {
        cout << "List full\n";
        return;
    }
    for (int i = list.length; i > pos; i--) list.data[i] = list.data[i - 1];
    list.data[pos] = x;
    list.length++;
}

void remove(ArrayList &list, int pos) {
    if (pos < 0 || pos >= list.length) {
        cout << "Invalid position\n";
        return;
    }
    for (int i = pos; i < list.length - 1; i++) list.data[i] = list.data[i + 1];
    list.length--;
}

int get(ArrayList &list, int pos) {
    if (pos < 0 || pos >= list.length) {
        cout << "Invalid position\n";
        return -1;
    }
    return list.data[pos];
}

int size(ArrayList &list) {
    return list.length;
}

void display(ArrayList &list) {
    for (int i = 0; i < list.length; i++) cout << list.data[i] << " ";
    cout << "\n";
}

//                           3: Merge two sorted singly linked lists 
struct Node {
    int data;
    Node* next;
};

Node* createNode(int x) {
    Node* p = new Node;
    p->data = x;
    p->next = nullptr;
    return p;
}

Node* mergeSortedLists(Node* l1, Node* l2) {
    Node dummy;
    Node* tail = &dummy;
    dummy.next = nullptr;
    while (l1 && l2) {
        if (l1->data < l2->data) {
            tail->next = l1;
            l1 = l1->next;
        } else {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }
    tail->next = l1 ? l1 : l2;
    return dummy.next;
}

void printList(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << "\n";
}

//                           4 & 5: Doubly linked list
struct DNode {
    int data;
    DNode* prev;
    DNode* next;
};

DNode* createDNode(int x) {
    DNode* p = new DNode;
    p->data = x;
    p->prev = p->next = nullptr;
    return p;
}

void append(DNode* &head, int x) {
    DNode* newNode = createDNode(x);
    if (!head) {
        head = newNode;
        return;
    }
    DNode* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
}

void printDList(DNode* head) {
    DNode* temp = head;
    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << "\n";
}

void reverseDList(DNode* &head) {
    DNode* temp = nullptr;
    DNode* current = head;
    while (current) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }
    if (temp) head = temp->prev;
}

//                       6: Singly circular linked list 
struct SCNode {
    int data;
    SCNode* next;
};

SCNode* createSCNode(int x) {
    SCNode* p = new SCNode;
    p->data = x;
    p->next = nullptr;
    return p;
}

void appendSC(SCNode* &head, int x) {
    SCNode* newNode = createSCNode(x);
    if (!head) {
        head = newNode;
        newNode->next = newNode;
        return;
    }
    SCNode* temp = head;
    while (temp->next != head) temp = temp->next;
    temp->next = newNode;
    newNode->next = head;
}

void printSCList(SCNode* head) {
    if (!head) return;
    SCNode* temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << "\n";
}

//                          7: Doubly circular linked list 
struct DCNode {
    int data;
    DCNode* next;
    DCNode* prev;
};

DCNode* createDCNode(int x) {
    DCNode* p = new DCNode;
    p->data = x;
    p->next = p->prev = nullptr;
    return p;
}

void appendDC(DCNode* &head, int x) {
    DCNode* newNode = createDCNode(x);
    if (!head) {
        head = newNode;
        head->next = head->prev = head;
        return;
    }
    DCNode* tail = head->prev;
    tail->next = newNode;
    newNode->prev = tail;
    newNode->next = head;
    head->prev = newNode;
}

void printDCList(DCNode* head) {
    if (!head) return;
    DCNode* temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << "\n";
}

//                      8: BST TREE
struct BSTNode {
    int data;
    BSTNode* left;
    BSTNode* right;
};

// Tạo node mới
BSTNode* createBSTNode(int x) {
    BSTNode* p = new BSTNode;
    p->data = x;
    p->left = p->right = nullptr;
    return p;
}

// BST cơ bản 
BSTNode* insertBST(BSTNode* root, int x) {
    if (!root) return createBSTNode(x);
    if (x < root->data) root->left = insertBST(root->left, x);
    else root->right = insertBST(root->right, x);
    return root;
}

BSTNode* findMin(BSTNode* root) {
    while (root && root->left) root = root->left;
    return root;
}

BSTNode* findMax(BSTNode* root) {
    while (root && root->right) root = root->right;
    return root;
}

BSTNode* searchBST(BSTNode* root, int x) {
    if (!root || root->data == x) return root;
    if (x < root->data) return searchBST(root->left, x);
    return searchBST(root->right, x);
}

BSTNode* deleteBST(BSTNode* root, int x) {
    if (!root) return nullptr;
    if (x < root->data) root->left = deleteBST(root->left, x);
    else if (x > root->data) root->right = deleteBST(root->right, x);
    else {
        if (!root->left) {
            BSTNode* temp = root->right;
            delete root;
            return temp;
        }
        if (!root->right) {
            BSTNode* temp = root->left;
            delete root;
            return temp;
        }
        BSTNode* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteBST(root->right, temp->data);
    }
    return root;
}

// Duyệt cây 
void inorder(BSTNode* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
void preorder(BSTNode* root) {
    if (!root) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}
void postorder(BSTNode* root) {
    if (!root) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

// Successor / Predecessor 
BSTNode* successor(BSTNode* root, BSTNode* node) {
    if (node->right) {
        BSTNode* cur = node->right;
        while (cur->left) cur = cur->left;
        return cur;
    }
    BSTNode* succ = nullptr;
    BSTNode* cur = root;
    while (cur) {
        if (node->data < cur->data) {
            succ = cur;
            cur = cur->left;
        } else if (node->data > cur->data) {
            cur = cur->right;
        } else break;
    }
    return succ;
}

BSTNode* predecessor(BSTNode* root, BSTNode* node) {
    if (node->left) {
        BSTNode* cur = node->left;
        while (cur->right) cur = cur->right;
        return cur;
    }
    BSTNode* pred = nullptr;
    BSTNode* cur = root;
    while (cur) {
        if (node->data > cur->data) {
            pred = cur;
            cur = cur->right;
        } else if (node->data < cur->data) {
            cur = cur->left;
        } else break;
    }
    return pred;
}

// Kiểm tra BST hợp lệ 
bool isBSTUtil(BSTNode* node, int minVal, int maxVal) {
    if (!node) return true;
    if (node->data < minVal || node->data > maxVal) return false;
    return isBSTUtil(node->left, minVal, node->data-1) &&
           isBSTUtil(node->right, node->data+1, maxVal);
}
bool isBST(BSTNode* root) {
    return isBSTUtil(root, INT_MIN, INT_MAX);
}

// Lowest Common Ancestor (LCA) 
BSTNode* LCA(BSTNode* root, int n1, int n2) {
    if (!root) return nullptr;
    if (root->data > n1 && root->data > n2) return LCA(root->left, n1, n2);
    if (root->data < n1 && root->data < n2) return LCA(root->right, n1, n2);
    return root;
}

// Convert sorted array -> balanced BST 
BSTNode* sortedArrayToBST(int arr[], int l, int r) {
    if (l > r) return nullptr;
    int m = l + (r-l)/2;
    BSTNode* node = createBSTNode(arr[m]);
    node->left = sortedArrayToBST(arr, l, m-1);
    node->right = sortedArrayToBST(arr, m+1, r);
    return node;
}

// kth smallest / largest
int kthSmallestUtil(BSTNode* root, int& k) {
    if (!root) return -1;
    int left = kthSmallestUtil(root->left, k);
    if (left != -1) return left;
    k--;
    if (k==0) return root->data;
    return kthSmallestUtil(root->right, k);
}
int kthSmallest(BSTNode* root, int k) {
    return kthSmallestUtil(root, k);
}
int kthLargest(BSTNode* root, int k, int n) {
    return kthSmallest(root, n-k+1);
}

// CHẠY HÀM MAIN
int main() {
    //                  Question 1
    cout << "Question 1:" << endl;
    ArrayListQ1 alist;
    initListQ1(alist);
    insertQ1(alist, 0, 10);
    insertQ1(alist, 1, 20);
    insertQ1(alist, 1, 15);
    
    cout << "ArrayList after inserts: "; 
    displayQ1(alist);
    
    removeQ1(alist, 1);
    cout << "ArrayList after remove pos 1: "; 
    displayQ1(alist);
    cout << "Element at pos 1: " << getQ1(alist,1) << "\n";
    cout << "Size of ArrayList: " << sizeQ1(alist) << "\n";

    NodeQ1* llist = nullptr;
    appendQ1(llist, 10);
    appendQ1(llist, 20);
    insertQ1(llist, 1, 15);
    cout << "Linked List after inserts: "; displayQ1(llist);
    removeQ1(llist, 1);
    cout << "Linked List after remove pos 1: "; displayQ1(llist);
    cout << "Element at pos 1: " << getQ1(llist,1) << "\n";
    cout << endl;
    //                  Quesiton 2
    cout << "Question 2: ArrayList (dynamic array) \n";
    ArrayList list;
    initList(list);
    // insert(pos, x): Thêm phần tử
    insert(list, 0, 10);
    insert(list, 1, 20);
    insert(list, 1, 15);
    cout << "List after inserts: "; display(list);
    // remove(pos): Xóa phần tử
    remove(list, 1);
    cout << "List after remove pos 1: "; display(list);
    // get(pos)
    cout << "Element at pos 1: " << get(list, 1) << "\n";
    // size()
    cout << "Size of list: " << size(list) << "\n";
    cout << endl;

    //                  Question 3
    cout << "Question 3: Merge two sorted singly linked lists\n";
    Node* l1 = createNode(1); l1->next = createNode(3); l1->next->next = createNode(5);
    Node* l2 = createNode(2); l2->next = createNode(4); l2->next->next = createNode(6);
    Node* merged = mergeSortedLists(l1, l2);
    cout << "Merged list: "; printList(merged);
    cout << endl;

    //                  Question 4
    cout << "Question 4: Doubly linked list\n";
    DNode* dlist = nullptr;
    append(dlist, 1); 
    append(dlist, 2); 
    append(dlist, 3);
    cout << "Doubly list: "; 
    printDList(dlist); 
    cout << endl;

    //                  Question 5
    cout << "Question 5: Reverse a doubly linked list\n";
    reverseDList(dlist);
    cout << "Reversed doubly list: "; 
    printDList(dlist);
    cout << endl;

    //                  Question 6
    cout << "Question 6: Singly circular linked list\n";
    SCNode* sclist = nullptr;
    appendSC(sclist, 1);
    appendSC(sclist, 2); 
    appendSC(sclist, 3);
    cout << "Singly circular list: "; 
    printSCList(sclist);
    cout << endl;

    //                  Question 7
    cout << "Question 7: Doubly circular linked list\n";
    DCNode* dclist = nullptr;
    appendDC(dclist, 1); 
    appendDC(dclist, 2); 
    appendDC(dclist, 3);
    cout << "Doubly circular list: "; 
    printDCList(dclist);
    cout << endl;

    //                  Question 8
    cout << "Question 8: BST\n";
    BSTNode* bst = nullptr;
    bst = insertBST(bst, 5); 
    bst = insertBST(bst, 3); 
    bst = insertBST(bst, 7);
    bst = insertBST(bst, 2); 
    bst = insertBST(bst, 4); 
    bst = insertBST(bst, 6); 
    bst = insertBST(bst, 8);
    // Find minimum, maximum
    BSTNode* minNode = findMin(bst);
    BSTNode* maxNode = findMax(bst);
    // minimum
    cout << "Minimum: " << endl;
    if (minNode != nullptr)
    cout << minNode->data << "\n";
    else
    cout << "-1\n";
    // maximum
    cout << "Maximum: " << endl;
    if (maxNode != nullptr)
    cout << maxNode->data << "\n";
    else
    cout << "-1\n";
    // Inorder
    cout << "Inorder: "; 
    inorder(bst); 
    cout << endl;
    // Delete
    bst = deleteBST(bst, 3); 

    cout << "After deleting 3, inorder: "; 
    inorder(bst); 
    cout << endl;
    // Preorder+Postorder
    cout << "Preorder: "; preorder(bst); cout << "\n"; 
    cout << "Postorder: "; postorder(bst); cout << "\n"; 

    BSTNode* node = searchBST(bst, 5); 
    BSTNode* succ = successor(bst, node); 
    BSTNode* pred = predecessor(bst, node); 
    // Successor
    cout << "Successor of 5: ";
    if (succ != nullptr)
    cout << succ->data << "\n";
    else
    cout << "-1\n";
    // Predecessor
    cout << "Predecessor of 5: ";
    if (pred != nullptr)
    cout << pred->data << "\n";
    else
    cout << "-1\n";
    // Is BST?
    cout << "Is BST? ";
    if (isBST(bst))
    cout << "Yes\n";
    else
    cout << "No\n";

    BSTNode* lca = LCA(bst, 2, 4);
    cout << "LCA of 2 and 4: ";
    if (lca != nullptr)
    cout << lca->data << "\n";
    else
    cout << "-1\n";


    int arr[] = {1,2,3,4,5,6,7};
    int n = sizeof(arr)/sizeof(arr[0]);
    BSTNode* balanced = sortedArrayToBST(arr, 0, n-1); 
    cout << "Inorder of balanced BST: "; inorder(balanced); cout << "\n";

    int k = 3;
    cout << "3rd smallest: " << kthSmallest(bst,k) << "\n"; 
    cout << "3rd largest: " << kthLargest(bst,k,7) << "\n"; 
    return 0;
}
