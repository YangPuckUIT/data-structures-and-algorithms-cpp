#include <iostream>

using namespace std;

struct SinhVien 
{
    int MaSV;
    string Ten;
    float DiemTB;
    string XepLoai;
};

// ham support cho inout
void InSV (SinhVien sv)
{
    cout << "Thong tin sinh vien: " << endl;
    cout << "\t+ Ma SV: " << sv.MaSV << endl;
    cout << "\t+ Ho Ten: " << sv.Ten << endl;
    cout << "\t+ Diem TB: " << sv.DiemTB << endl;
    cout << "\t+ Xep Loai: " << sv.XepLoai << endl;
}

struct Node
{
    SinhVien Data;
    Node* pNext;
};

Node* initNode(SinhVien value)
{
    Node* p = new Node;
    p->Data = value;
    p->pNext = nullptr;
    return p;
}

struct List
{
    Node* pHead;
    Node* pTail;
};

void initList (List &l)
{
    l.pHead = l.pTail=nullptr;
}


void addHead (List &l, Node* p)
{
    if (l.pHead == nullptr)
    l.pHead = l.pTail = p;
    else {
        p->pNext = l.pHead;
        l.pHead = p;
    }
}


void addTail (List &l, Node* p)
{
    if (l.pHead == nullptr)
    l.pHead = l.pTail = p;
    else {
        l.pTail->pNext = p;
        l.pTail = p;
    }
}

// Data add sv
void initDataListSV (List &dsSV)
{
    SinhVien s1 = {123, "Nguyen Van A", 9.1, ""};
    SinhVien s2 = {124, "Nguyen Van B", 8.9, ""};
    SinhVien s3 = {125, "Nguyen Van C", 7.3, ""};
    SinhVien s4 = {126, "Nguyen Van D", 5.3, ""};
    SinhVien s5 = {127, "Nguyen Van F", 6.4, ""};
    SinhVien s6 = {128, "Nguyen Van G", 8.0, ""};
    SinhVien s7 = {129, "Nguyen Van H", 7.8, ""};

    addHead (dsSV, initNode(s7));
    addHead (dsSV, initNode(s6));
    addHead (dsSV, initNode(s5));
    addHead (dsSV, initNode(s4));
    addHead (dsSV, initNode(s3));
    addHead (dsSV, initNode(s2));
    addHead (dsSV, initNode(s1));

    //thêm sv
    addTail (dsSV, initNode({130, "Nguyen Van I", 10.0, ""}));
}

// ham input
void PrintDSSV (List dsSV) 
{
    if (dsSV.pHead == nullptr)
    {
    cout << "Danh sach rong";
    return;
    }
    for (Node* p = dsSV.pHead; p != nullptr; p = p->pNext)
    {
        InSV(p->Data);
    }
}

// ham xep loai
void XepLoai (List &dsSV)
{
    for (Node* p = dsSV.pHead; p != NULL; p = p->pNext)
    {
        float x = p->Data.DiemTB;
        if (x >= 9 && x <= 10)
        p->Data.XepLoai = "Xuat Sac";
        else if (x >= 8 && x < 9)
        p->Data.XepLoai = "Gioi";
        else if (x >= 6.5 && x < 8)
        p->Data.XepLoai = "Kha";
        else if (x >= 0 && x<6.5)
        p->Data.XepLoai = "Yeu/ hc ngu";
        else
        p->Data.XepLoai = "ERROR!";
    }
}

int main () {
    List dsSV;
    initList(dsSV);

    initDataListSV(dsSV);
    cout << "chua xep loai" << endl;
    PrintDSSV(dsSV);
    
    cout << "Xep loai" << endl;
    XepLoai(dsSV);
    PrintDSSV(dsSV);
    return 0; 
}