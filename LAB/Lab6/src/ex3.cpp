#include <iostream>
#include <string>

using namespace std;


struct Node {
    int data;
    Node* prev;
    Node* next;
};

struct Deque {
    Node* front;
    Node* back;
};

void initDeque(Deque& dq)
{
    dq.front = dq.back = NULL;
}

bool isEmpty(Deque dq)
{
    return dq.front == NULL;
}

void insertFront(Deque& dq, int x)
{
    Node* p = new Node;
    p->data = x;
    p->prev = NULL;
    p->next = dq.front;

    if (isEmpty(dq))
    {
        dq.front = dq.back = p;
    }
    else
    {
        dq.front->prev = p;
        dq.front = p;
    }
}

void insertBack(Deque& dq, int x)
{
    Node* p = new Node;
    p->data = x;
    p->next = NULL;
    p->prev = dq.back;

    if (isEmpty(dq))
    {
        dq.front = dq.back = p;
    }
    else
    {
        dq.back->next = p;
        dq.back = p;
    }
}

void eraseFront(Deque& dq)
{
    if (isEmpty(dq))
        return;

    Node* temp = dq.front;
    dq.front = dq.front->next;

    if (dq.front == NULL)
        dq.back = NULL;
    else
        dq.front->prev = NULL;

    delete temp;
}

void eraseBack(Deque& dq)
{
    if (isEmpty(dq))
        return;

    Node* temp = dq.back;
    dq.back = dq.back->prev;

    if (dq.back == NULL)
        dq.front = NULL;
    else
        dq.back->next = NULL;

    delete temp;
}

void printFront(Deque dq)
{
    if (isEmpty(dq))
        cout << "EMPTY\n";
    else
        cout << dq.front->data << "\n";
}

void printBack(Deque dq)
{
    if (isEmpty(dq))
        cout << "EMPTY\n";
    else
        cout << dq.back->data << "\n";
}

void printIsEmpty(Deque dq)
{
    if (isEmpty(dq))
        cout << "YES\n";
    else
        cout << "NO\n";
}

int main()
{
    Deque dq;
    initDeque(dq);

    int q;
    cin >> q;

    while (q--)
    {
        string cmd;
        cin >> cmd;

        if (cmd == "insertFront")
        {
            int x;
            cin >> x;
            insertFront(dq, x);
        }
        else if (cmd == "insertBack")
        {
            int x;
            cin >> x;
            insertBack(dq, x);
        }
        else if (cmd == "eraseFront")
        {
            eraseFront(dq);
        }
        else if (cmd == "eraseBack")
        {
            eraseBack(dq);
        }
        else if (cmd == "front")
        {
            printFront(dq);
        }
        else if (cmd == "back")
        {
            printBack(dq);
        }
        else if (cmd == "isEmpty")
        {
            printIsEmpty(dq);
        }
    }

    return 0;
}
