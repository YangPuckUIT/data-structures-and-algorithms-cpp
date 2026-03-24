#include <iostream>

using namespace std;

void insertion_sort(int arr[], int size) {
    for (int i = 1; i < size; i++) {
        int tmp = arr[i];
        int j = i;
        while (j > 0 && tmp < arr[j-1]) {
            arr[j] = arr[j-1];  // dịch chuyển sang phải
            j--;
        }
        arr[j] = tmp;  // chèn tmp vào vị trí đúng
    }
}
 

int main () {
    int size;
    cout << "Nhap so luong phan tu: ";
    cin >> size;
    int arr[size];
    cout << "Nhap cac gia tri: ";
    for (int i=0; i<size; i++) {
        cin >> arr[i];
    }
    insertion_sort(arr,size);
    cout << "mang da dc sap xep: ";
    for (int i=0; i<size; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}