#include <iostream>

using namespace std;

void bubble_sort(int a[], int n) {
    bool sorted = false;
    int last = n - 1;
    for (int i = 0; (i < last) && !sorted; i++) {
        sorted = true;
        for (int j = last; j > i; j--) {
            if (a[j-1] > a[j]) {
                swap(a[j], a[j-1]);
                sorted = false;     // báo hiệu có đổi chỗ
            }
        }
    }
}

int main() {
    int size;
    cout << "Nhap so luong phan tu: ";
    cin >> size;
    int arr[size];

    cout << "Nhap cac gia tri: ";
    for (int i = 0; i < size; i++)
        cin >> arr[i];

    bubble_sort(arr, size);

    cout << "Mang da sap xep: ";
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    return 0;
}
