#include <iostream>

using namespace std;

int interpolation (int a[], int n, int value)
{
    int L, R, M;
    L = 0;
    R = n-1;
    while (L <= R)
    {
        M = L + (double)(R - L) * (value - a[L]) / (a[R] - a[L]);// dùng Ct này thay vì M = (L+R)/2
        if (a[M] == value)
            return M;
        if (a[M] > value)
            R = M - 1;
        else
            L = M + 1;
    }
    return -1;
}

int main ()
{
    int n, value;
    cout << "Nhap so luong phan tu: ";
    cin >> n;

    int a[n];
    cout << "Nhap gia tri: " << endl;
    for (int i=0; i<n; i++)
    {
        cin >> a[i];
    }

    cout << "Nhap gia tri can tim: ";
    cin >> value;

    cout << "Gia tri " << value << " tai index: " << interpolation(a, n, value);
    
    return 0;
}