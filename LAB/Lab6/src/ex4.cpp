#include <iostream>
#include <string>

using namespace std;

enum Color { RED, BLACK };

struct Node {
    int key;
    Color color;
    Node *left, *right, *parent;
};

Node* NIL;   
Node* root;  

Node* createNode(int key)
{
    Node* p = new Node;
    p->key = key;
    p->color = RED;
    p->left = p->right = p->parent = NIL;
    return p;
}


void leftRotate(Node* x)
{
    Node* y = x->right;
    x->right = y->left;

    if (y->left != NIL)
        y->left->parent = x;

    y->parent = x->parent;

    if (x->parent == NIL)
        root = y;
    else if (x == x->parent->left)
        x->parent->left = y;
    else
        x->parent->right = y;

    y->left = x;
    x->parent = y;
}

void rightRotate(Node* y)
{
    Node* x = y->left;
    y->left = x->right;

    if (x->right != NIL)
        x->right->parent = y;

    x->parent = y->parent;

    if (y->parent == NIL)
        root = x;
    else if (y == y->parent->right)
        y->parent->right = x;
    else
        y->parent->left = x;

    x->right = y;
    y->parent = x;
}

void insertFix(Node* z)
{
    while (z->parent->color == RED)
    {
        if (z->parent == z->parent->parent->left)
        {
            Node* y = z->parent->parent->right; 
            if (y->color == RED)
            {
                z->parent->color = BLACK;
                y->color = BLACK;
                z->parent->parent->color = RED;
                z = z->parent->parent;
            }
            else
            {
                if (z == z->parent->right)
                {
                    z = z->parent;
                    leftRotate(z);
                }
                z->parent->color = BLACK;
                z->parent->parent->color = RED;
                rightRotate(z->parent->parent);
            }
        }
        else
        {
            Node* y = z->parent->parent->left;
            if (y->color == RED)
            {
                z->parent->color = BLACK;
                y->color = BLACK;
                z->parent->parent->color = RED;
                z = z->parent->parent;
            }
            else
            {
                if (z == z->parent->left)
                {
                    z = z->parent;
                    rightRotate(z);
                }
                z->parent->color = BLACK;
                z->parent->parent->color = RED;
                leftRotate(z->parent->parent);
            }
        }
    }
    root->color = BLACK;
}

void insert(int key)
{
    Node* z = createNode(key);
    Node* y = NIL;
    Node* x = root;

    while (x != NIL)
    {
        y = x;
        if (key < x->key)
            x = x->left;
        else if (key > x->key)
            x = x->right;
        else
            return; 
    }

    z->parent = y;
    if (y == NIL)
        root = z;
    else if (key < y->key)
        y->left = z;
    else
        y->right = z;

    insertFix(z);
}

Node* search(Node* x, int key)
{
    while (x != NIL && key != x->key)
    {
        if (key < x->key)
            x = x->left;
        else
            x = x->right;
    }
    return x;
}

void inorder(Node* x)
{
    if (x == NIL) return;
    inorder(x->left);
    cout << x->key << " ";
    inorder(x->right);
}

void printColor(int key)
{
    Node* x = search(root, key);
    if (x == NIL)
        cout << "Not found\n";
    else
        cout << (x->color == RED ? "RED\n" : "BLACK\n");
}

int main()
{
    NIL = new Node;
    NIL->color = BLACK;
    NIL->left = NIL->right = NIL->parent = NIL;

    root = NIL;

    int q;
    cin >> q;

    while (q--)
    {
        string cmd;
        cin >> cmd;

        if (cmd == "insert")
        {
            int x; cin >> x;
            insert(x);
        }
        else if (cmd == "find")
        {
            int x; cin >> x;
            cout << (search(root, x) != NIL ? "YES\n" : "NO\n");
        }
        else if (cmd == "printInorder")
        {
            inorder(root);
            cout << "\n";
        }
        else if (cmd == "printColor")
        {
            int x; cin >> x;
            printColor(x);
        }
    }

    return 0;
}
