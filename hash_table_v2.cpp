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

// tạo và init bucket lồng ghép vô hashtable luôn
const int Size = 5;
struct HashTable
{
    struct bucket
    {
        Node* pHead;
        Node* pTail;
    };

    bucket bk[Size];
};

void initHashTable (HashTable &h)
{
    for (int i=0; i<Size; i++)
    {
        h.bk[i].pHead = NULL;   // hàm initBucket (mỗi tầng bucket có 2 cái head và tail bằng null)
        h.bk[i].pTail = NULL;
    }
}

// c1
int HashFunction (Node* p)
{
    return p->Data % Size;
}
// c2
int HashFunction (int value)
{
    return value % Size;
}

// ko có push vì ko có bucket nên chỉ có add
// c1
void add (HashTable &h, Node* p)
{
    int vitri = HashFunction (p);

    if (h.bk[vitri].pHead == NULL)
    {
        h.bk[vitri].pHead = p;
        h.bk[vitri].pTail = p;
    }
    else
    {
        h.bk[vitri].pTail->pNext = p;   // thêm giống add tail
        h.bk[vitri].pTail = p;
    }
}
//c2
void add (HashTable &h, int value)
{
    int vitri = HashFunction (value);

    Node* p = initNode (value); // chưa có node nên tạo
    if (h.bk[vitri].pHead == NULL)
    {
        h.bk[vitri].pHead = p;
        h.bk[vitri].pTail = p;
    }
    else
    {
        h.bk[vitri].pTail->pNext = p;   // thêm giống add tail
        h.bk[vitri].pTail = p;
    }
}

void printHashTable (HashTable h)
{
    cout << "Size of HashTable: " << Size << endl;
    for (int i=0; i<Size; i++)
    {
        cout << "Bucket [" << i << "]: ";
        for (Node* p = h.bk[i].pHead; p != NULL; p = p->pNext)
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