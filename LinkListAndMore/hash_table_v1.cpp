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
    p->pNext = NULL;
    return p;
}

struct Bucket   //giống list khác tên 
{
    Node* pHead;
    Node* pTail;
};

void initBucket (Bucket &bk)
{
    bk.pHead = bk.pTail = NULL;
}

const int Size = 5; // số bucket, tầng
struct HashTable
{
    Bucket bucket[Size];
};

void initHashTable (HashTable &h)
{
    for (int i=0; i<Size; i++)
    {
        initBucket(h.bucket[i]);
    }
}

// c1
int HashFunction(Node* p)
{
    return p->Data % Size;
}
// c2
int HashFunction(int value)
{
    return value % Size;
}

// xài chung cho c1 c2 của add
void push (Bucket &bk, Node* p) //giống addTail trong liên kết đơn
{
    if (bk.pHead == NULL)
    {
        bk.pHead = p;
        bk.pTail = p;
    }
    else
    {
        bk.pTail->pNext = p;
        bk.pTail = p;
    }
}

// cho c1
void add (HashTable &h, Node* p)
{
    int vitri = HashFunction(p); //c1

    push (h.bucket[vitri], p);
}
// cho c2
void add (HashTable &h, int value)
{
    int vitri = HashFunction(value); //c2
    
    push(h.bucket[vitri], initNode(value));
}

void printHashTable (HashTable h)
{
    cout << "Size of HashTable: " << Size << endl;
    for (int i=0; i<Size; i++)
    {
        cout << "Bucket [" << i << "]: ";
        for (Node* p = h.bucket[i].pHead; p != NULL; p = p->pNext)
        {
            cout << p->Data << " ";
        }
        cout << endl;
    }
}

int main ()
{
    HashTable h;
    initHashTable(h);

        // c1: đưa node làm 2 bước
    Node* p1 = initNode(50);
    Node* p2 = initNode(73);
    Node* p3 = initNode(35);
    Node* p4 = initNode(36);
    Node* p5 = initNode(64);
    add(h, p1);
    add(h, p2);
    add(h, p3);
    add(h, p4);
    add(h, p5);
    // hoặc
    add(h, initNode(67));

        //c2: đưa thẳng giá trị, chưa tạo node nên hàm add này phải initNode ở trong
    add(h, 90);
    add(h, 73);
    add(h, 35);
    add(h, 36);
    add(h, 64);

    printHashTable(h);

    return 0;
}