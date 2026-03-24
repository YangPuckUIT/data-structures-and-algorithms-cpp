#include <iostream>

using namespace std;

void doi (int &ptu1, int &ptu2) {
    int temp=ptu1;
    ptu1=ptu2;
    ptu2=temp;
}

void selection_sort (int arr[], int size) {   //nó lấy gt đầu làm min, và cho j chạy từ phần tử tiếp -> hết và so sánh, nếu gt chạy đến nhỏ hơn min thì đổi chỗ 2 phân tử đó
    for (int i=0; i<size-1; i++) {
        int min=i;
            for (int j=i+1; j<size; j++) {
                if (arr[min] > arr[j]) {
                    min=j;
                }
            }
        doi(arr[i],arr[min]);   // tạo 1 hàm để đổi 2 phần tử
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
    selection_sort(arr,size);
    cout << "mang da dc sap xep: ";
    for (int i=0; i<size; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}