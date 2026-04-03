#include <iostream>

using namespace std;
// tháp hà nội: 3 đinh A, B, C di chuyển hết đĩa từ A sang C (B là trung gian)
// yêu cầu: chỉ di chuyển 1 đĩa, đĩa lớn ko đc xếp trên đĩa nhỏ
/*  A->B
    B->A
    B->C
    C->B
    A->C
    C->A
*/
struct Node 
{
    int Data; // coi data là đĩa 
    Node* pNext;
};

struct Stack 
{
    Node* pTop = nullptr; // khỏi initStack gộp lại cho gọn
};
 
void push (Stack &s, int n) 
{
    Node* p = new Node;
    p->Data = n;
    p->pNext = nullptr;  
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

int pop (Stack &s)
{
    if (s.pTop == nullptr)
    {
        return INT_MIN;
    }
    else
    {
        Node* p = s.pTop;
        int val = p->Data;          // lấy đúng giá trị của node bị pop
        s.pTop = s.pTop->pNext;
        delete p;                   // giải phóng node
        return val;
    }
}

void Move (Stack &From, Stack &To, int &count)
{
    // kiểm tra From rỗng
    if (From.pTop == nullptr)
    {
        cout << "ERROR: Tower 'From' is empty.\n";
        return;
    }
    // kiểm tra luật: không đặt đĩa lớn lên đĩa nhỏ
    if (To.pTop != nullptr && From.pTop->Data > To.pTop->Data)
    {
    cout << "ERROR!" << endl;
    return;
    }
    push(To, pop(From));
    count++;
    return;
}

void Print3Stack (Stack &st, Stack &nd, Stack &rd) // thêm & để chiếu qua, nếu ko có & nó sẽ copy và tốn RAM, có thể thêm const tối ưu hơn
{
    cout << "=========================================" << endl;
    cout << "A Tower " << endl;
    cout << "Stack = Top < ";
    for (Node* p = st.pTop; p != nullptr; p = p->pNext)
    {
        cout << p->Data << " ";
    }
    cout << ">";
    cout << endl;

    cout << "=========================================" << endl;
    cout << "B Tower " << endl;
    cout << "Stack = Top < ";
    for (Node* p = nd.pTop; p != nullptr; p = p->pNext)
    {
        cout << p->Data << " ";
    }
    cout << ">";
    cout << endl;

    cout << "=========================================" << endl;
    cout << "C Tower " << endl;
    cout << "Stack = Top < ";
    for (Node* p = rd.pTop; p != nullptr; p = p->pNext)
    {
        cout << p->Data << " ";
    }
    cout << ">";
    cout << endl;
    cout << "=========================================" << endl;
}

//Điều kiện thắng: Tower A rỗng, Tower B rỗng, Tower C chứa đủ n đĩa
bool isWin(Stack &A, Stack &B, Stack &C, int n)
{
    // A và B phải rỗng
    if (A.pTop != nullptr || B.pTop != nullptr)
        return false;

    // Đếm số đĩa trong C
    int count = 0;
    for (Node* p = C.pTop; p != nullptr; p = p->pNext)
        count++;

    return (count == n);
}


int main () {
    Stack A, B, C;
    int n=0;
    int count = 0;

    cout << "So dia ban muon choi: ";
    cin >> n;
    for (int i = n; i > 0; i--)
    {
        push(A, i);
    }

    while (!isWin(A, B, C, n))   // chạy tới khi win
    {
        cout << "===============DEMO STACK================" << endl;
        cout << "1. A -> B" << endl;
        cout << "2. B -> A" << endl;
        cout << "3. B -> C" << endl;
        cout << "4. C -> B" << endl;
        cout << "5. A -> C" << endl;
        cout << "6. C -> A" << endl;
        cout << "7. All: " /* thuật toán HN*/<< endl;
        Print3Stack(A,B,C);
        cout << "So Lan Di Chuyen: " << count << endl;
        cout << "=========================================" << endl;
        cout <<  "\tPlease Input: ";
        int Chon=-1;
        if (!(cin >> Chon)) break; // giống cin >> Chon nhưng thêm điệu kiện nếu người dùng nhập ký tự ngoài số như chữ, chữ đtặ biệt tránh lặp vô hạn
        cout << endl << endl;
        switch (Chon)
        {
            case 1:
            {
                Move(A,B,count);
                break;
            }
            case 2:
            {
                Move(B,A,count);
                break;
            }
            case 3:
            {
                Move(B,C,count);
                break;
            }
            case 4:
            {
                Move(C,B,count);
                break;
            }
            case 5:
            {
                Move(A,C,count);
                break;
            }
            case 6:
            {
                Move(C,A,count);
                break;
            }
            case 7:
            {
                // hàm đưa ra kết quả nếu người chs ko giải đc, bài toán tháp Hà Nội đệ quy nhưng coder ko bt cách làm 
                break;
            }
            default:
                cout << "Invalid choice.\n";
        }
    }

    cout << "\n================ CHUC MUNG ==================\n";
    cout << "Ban da hoan thanh Thap Ha Noi sau " << count << " lan di chuyen!\n";
    cout << "=============================================\n";

    return 0;
}