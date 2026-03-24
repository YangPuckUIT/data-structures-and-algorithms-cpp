#include <iostream>
#include <stack>

using namespace std;

// b1
struct Node
{
    int data;
    Node* pLeft;
    Node* pRight;
};

// b2
Node* initNode (int value)
{
    Node* p = new Node;
    p->data = value;
    p->pLeft = NULL;
    p->pRight = NULL;

    return p;
}

// b3   link-list, hashtable thì quản lý head và tail còn tree thfi chỉ quản lý root
struct Tree
{
    Node* pRoot;
};

// b4
void initTree (Tree &t)
{
    t.pRoot = NULL;
}

    //c1
void addNode (Tree &t, Node* p) // node p là node mới đưa vô cần tìm chỗ để lưu trữ
{
    if (t.pRoot == NULL)
    {
        t.pRoot = p;
    }
    else
    {
        Node* pGoto = t.pRoot; // pGoto là nút đi trc dẫn đường (xét node tiếp có null hay ko để báo cho node sau)
        Node* pLocation = NULL; // Node này để lưu pGoto trc r pGoto mới đi, nếu gặp null thì pGoto ko quay lại đc nên plocation đã giữ 
                                // gt trc đó của pGOto nên pGoto ko quay lại đc cx ko sao
        // tìm vị trí phù hợp cho node p                    
        while (pGoto != NULL)   
        {
            pLocation = pGoto;
            if (p->data < pGoto->data)
                pGoto = pGoto->pLeft;
            else if (p->data > pGoto->data)
                pGoto = pGoto->pRight;
        }
        // gắn p vào pLocation (tìm đc lá rồi(pLocation))
        if (p->data < pLocation->data)
            pLocation->pLeft = p;
        else if (p->data > pLocation->data)
            pLocation->pRight = p;
    }
}
    //c2
void addValue (Tree &t, int value)
{
    Node* p = initNode (value); // giống c1 chỉ thêm đúng dòng này để tạo node p

    if (t.pRoot == NULL)
    {
        t.pRoot = p;
    }
    else
    {
        Node* pGoto = t.pRoot; // pGoto là nút đi trc dẫn đường (xét node tiếp có null hay ko để báo cho node sau)
        Node* pLocation = NULL; // Node này để lưu pGoto trc r pGoto mới đi, nếu gặp null thì pGoto ko quay lại đc nên plocation đã giữ 
                                // gt trc đó của pGOto nên pGoto ko quay lại đc cx ko sao
        // tìm vị trí phù hợp cho node p                    
        while (pGoto != NULL)   
        {
            pLocation = pGoto;
            if (p->data < pGoto->data)
                pGoto = pGoto->pLeft;
            else if (p->data > pGoto->data)
                pGoto = pGoto->pRight;
        }
        // gắn p vào pLocation (tìm đc lá rồi(pLocation))
        if (p->data < pLocation->data)
            pLocation->pLeft = p;
        else if (p->data > pLocation->data)
            pLocation->pRight = p;
    }
}

void printTree (Tree t) // duyệt inorder (tăng dần) left-node-right
{
    stack<Node*> s; // khai báo stack s kiểu Node*
    Node* p = t.pRoot;
    while(p != NULL || s.empty() == false)
    {
        // left
        while (p != NULL)   // làm cho đến khi đến node null (tìm đc lá r, nhưng vẫn gán p là node null để dừng)
        {
            s.push(p);  // nhét vô stack
            p=p->pLeft; // xong qua node khác
        }
        // xứ lý node
        p = s.top();  // do p là null rồi nên gấn lại cho nó là node lá
        s.pop(); // xóa node đầu của stack đi, vì nó đã gán cho p rồi  
        cout << p->data << " ";

        p = p->pRight;  // left và node rồi tiếp theo là right
    }
    cout << endl;
}

void LNR (Node* p) // dùng đệ quy
{
    if (p != NULL)
    {
        LNR(p->pLeft);
        cout << p->data << " ";
        LNR(p->pRight);
    }
}


// tìm kiếm
bool FindValue (Tree &t, int x)
{
    Node* p = t.pRoot;

    while (p != NULL)
    {
        if (x == p->data)
            return true;
        if (x < p->data)
            p = p->pLeft;
        else if (x > p->data)
            p = p->pRight;
    }
    return false;
}

// tính tổng bằng đệ quy
void Sum (Node* p, int &result)
{
    if (p != NULL)
    {
        result = result + p->data;
        
        Sum(p->pLeft, result);
        Sum(p->pRight, result);
    }
}

// tóng tổng ko dùng đệ quy (giống print)
int Sum (Tree t) 
{
    int t = 0;
    stack<Node*> s; 
    Node* p = t.pRoot;
    while(p != NULL || s.empty() == false)
    {
        while (p != NULL)  
        {
            s.push(p);  
            p=p->pLeft; 
        }
        p = s.top(); 
        s.pop(); 

        // chỉ thay dòng này: đếm, trừ,... tìm node lá (L & R đều = NULL)
        t = t + p->data;    // cout << p->data << " "; chỗ này thay cái hành động khác còn lại y chang

        p = p->pRight;  // left và node rồi tiếp theo là right
    }
    return t;
}

int main () 
{
    Tree t;
    initTree(t);    // cây đang rỗng chỉ node ROOT có pLeft,Right bằng NULL chưa có gt 

    // c1: tạo node có gt rồi đưa node vào
    Node* p1 = initNode(50);
    Node* p2 = initNode(26);
    Node* p3 = initNode(73);
    Node* p4 = initNode(66);
    Node* p5 = initNode(88);
    Node* p6 = initNode(61);
    addNode(t, p1);
    addNode(t, p2);
    addNode(t, p3);
    addNode(t, p4);
    addNode(t, p5);
    addNode(t, p6);
    // hoặc
    addNode(t, initNode(79));

    // c2: đưa giá trị vào (ko tạo node ở main thì trong hàm phải tạo node)
    addValue(t, 90); 

    cout << "Print tree (LNR):" << endl;
    printTree(t);

    cout << "Find value: " << endl;
    cout << " find (66) = " << FindValue(t, 66) << endl;
    cout << " find (89) = " << FindValue(t, 89) << endl;

    return 0;
}