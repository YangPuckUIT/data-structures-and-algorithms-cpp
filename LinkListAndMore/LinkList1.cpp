#include <iostream>

using namespace std;

struct Node 
{
    int data;
    Node* pNext;
};

struct List 
{
    Node* pHead = nullptr;
    Node* pTail = nullptr;
};

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

int dem (List l)
{
    int count = 0;
    for (Node* p = l.pHead; p != NULL; p = p->pNext)
    {
        if (p->data % 2 == 0) count ++;
    }
    return count;
}

int Max (List l) {
    int max = l.pHead->data;
    for (Node* p = l.pHead->pNext; p!=NULL; p=p->pNext) {
        if (p->data > max) max=p->data;
    }
    return max;
}

int Total (List l) {
    int tong=0;
    for (Node* p = l.pHead; p!=NULL;p=p->pNext) {
        tong += p->data;
    }
    return tong;
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

void RemoveHead (List &l)
{
    if (l.pHead == nullptr) {
        return;
    }
    Node* p = l.pHead;
    l.pHead = l.pHead ->pNext;

    if (l.pHead == nullptr) 
    l.pTail == nullptr;

    delete p;
    return;
}



int main () {
    List l;
    Node* p1 = new Node ({67, NULL});
    Node* p2 = new Node ({11, NULL});
    Node* p3 = new Node ({12, NULL});
    Node* p4 = new Node ({14, NULL});
    Node* p5 = new Node ({15, NULL});
    
    addHead(l, p1);
    addHead(l, p2);
    addTail(l, p3);                 //11 67 12 14 15 
    addTail(l, p4);
    addTail(l, p5);
    cout << "Largest number " << Max(l) << endl;
    cout << "Summary number of list " << Total(l) << endl;
    cout << "List before remove head" << endl; 
    PrintListFor(l);
    cout << "List after remove head" << endl;
    RemoveHead(l);
    PrintListFor(l);
    return 0;
}