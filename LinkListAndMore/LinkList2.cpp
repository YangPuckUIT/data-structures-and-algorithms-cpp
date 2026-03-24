#include <iostream>

using namespace std;

struct Node 
{
    int data;
    Node* pNext;
};

Node* initNode (int value)
{
    Node* p = new Node;
    p->data = value;
    p->pNext = nullptr;
    return p;
}

struct List 
{
    Node* pHead;
    Node* pTail;
};

void initList (List& l)
{
    l.pHead = l.pTail = nullptr;
}

void addHead (List& l, Node* p) 
{
    if (l.pHead == nullptr)
    {
        l.pHead = p;
        l.pTail = p;
    }
    else
    {
        p->pNext = l.pHead;
        l.pHead = p;
    }
}

void addTail (List& l, Node* p)
{
    if (l.pHead == nullptr)
    {
        l.pHead = p;
        l.pTail = p;
    }
    else
    {
        l.pTail->pNext = p;
        l.pTail = p;
    }
}

void PrintListWhile (List l)
{
    Node* p = l.pHead;
    while (p != nullptr)
    {
        cout << p->data << " ";
        p = p->pNext;
    }
    cout << endl;
}

void PrintListFor (List l)
{
            //start              stop              step
    for (Node* p = l.pHead; p != nullptr; p = p->pNext)
    {
        cout << p->data << " ";
    }
    cout << endl;
}

bool find (List l, int value)
{
    for (Node* p = l.pHead; p != nullptr; p = p->pNext)
    {
        if (p->data == value)
        {
            return true; 
        }
    }
    return false;
}

int main () 
{
    Node* p1 = initNode(10);
    Node* p2 = initNode(67);
    Node* p3 = initNode(36);

    List l;
    initList(l);

    addHead(l, p1);
    addHead(l, p2);
    addTail(l, p3);

    cout << "input for:" <<endl;
    PrintListFor(l);
    cout << "input while:" <<endl;
    PrintListWhile(l);

    cout << "Find 10: " << find(l, 10) << endl; 
    return 0;
}