#include <iostream>

using namespace std;

struct Node
{
    int Data;
    Node* pNext;
};

Node* initNode (int value)
{
    Node* p = new Node;

    p->Data = value;
    p->pNext = nullptr;
    return p;
}

struct Stack
{
    Node* pTop;
};

void initStack (Stack &s)
{
    s.pTop = nullptr;
}

// giong addHead
void push (Stack &s, Node* p)
{
    if (s.pTop == nullptr) 
    {
        s.pTop = p;
    }
    else 
    {
        p->pNext = s.pTop;
        s.pTop = p;
    }   
}

// hàm push nhưng gộp initNode vào đây, để main ghi push (stack,gt) thôi
void push (Stack &s, int value)
{
    Node* p = initNode(value);
    if (s.pTop == nullptr) 
    {
        s.pTop = p;
    }
    else 
    {
        p->pNext = s.pTop;
        s.pTop = p;
    }   
}

// hàm xóa pop
void pop(Stack &s)
{
    if (s.pTop == nullptr)
        return;
    Node* p =s.pTop;
    s.pTop = s.pTop->pNext;
    delete  p;
}

void printStack (Stack s)
{
    if (s.pTop == nullptr)
    {
        cout << "Danh sach rong" << endl;
        return;
    }
    for (Node* p = s.pTop; p != nullptr; p = p->pNext)
    {
        cout << p->Data << " ";
    }
    cout << endl;
}

int GetTop (Stack s)
{
    if (s.pTop == nullptr)
        return INT_MIN;
    return s.pTop->Data;
}

// chuyển thập phân sang nhị phân
void convert10_2 (Stack &s, int n)
{       // start là n rồi nên ko cần
    for (; n != 0; n /= 2)
    {           // n chia lấy dư cho 2 (1/0)
        push(s, n%2);
    }
}

int main () {
    Stack s;
    initStack(s);

    Node* p1 = initNode(10);
    Node* p2 = initNode(20);
    Node* p3 = initNode(30);

    push(s, p1); //push kiểu 1: nếu đề kêu đưa 1 NODE vào stack
    push(s, p2); 
    push(s, p3);
    push(s, 67); // push kiểu 2: nếu đề kêu đưa 1 GIÁ TRỊ vào stack

    printStack(s); 
    pop(s);
    printStack(s); 

    // chuyển thập phân sang nhị phân
    Stack s2;
    initStack (s2);

    convert10_2(s2, 13);
    printStack(s2);
    return 0;
}