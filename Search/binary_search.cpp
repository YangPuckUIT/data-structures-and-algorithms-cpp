#include <iostream>

using namespace std;

int binary_search(int arr[], int size, int value) { //tìm giá trị trên mảng đã sắp xếp, nó lấy mốc ở giữa, nếu GT cần tìm nhỏ hơn mốc thì lấy trái bỏ phải (ngược lại)
    int left, middle, right;
    left = 0;
    right = size - 1;
    while (left <= right) {       
    int middle = (left + right)/2;           
        if (arr[middle] == value)     // TH tìm đc gt
            return middle;
        if (arr[middle] > value) // TH gt cần tìm có thể bên trái
            right = middle - 1;
        else                          // TH gt cần tìm có thể bên phải if (arr[middle] < value) 
            left = middle + 1;
    }
    return -1; // TH ko tìm thấy
}

int main () {
    int size,target;
    cout << "Nhap so luong phan tu: "; //nhập size của mảng
    cin >> size;
    int arr[size];
    cout << "Nhap cac gia tri: "; //nhập các gt
    for (int i=0; i<size; i++) {  //nhập các giá trị của phần tử
        cin >> arr[i];
    }
    cout << "Nhap GT can tim: ";  // số cần tìm
    cin >> target;
    cout << "gia tri " << target << " tai index " << binary_search(arr, size, target);
    return 0;
}