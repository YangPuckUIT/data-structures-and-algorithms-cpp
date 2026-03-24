#include <iostream> 

using namespace std;

int ordered_linear(int arr[], int target, int size) {  // mảng đã đc SẮP XẾP nên chạy giống linear search nhưng nếu value < arr[i] thì dừng luôn
    for (int i=0; i<size; i++) {
    if (target < arr[i]) {     //nếu GT cần tìm nhỏ hơn phần tử tiếp là dừng
        return -1;
        }
    else if (arr[i] == target) {
            return i;
        } 
    }
        return -1; //index=-1 là ko tìm thấy
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
    cout << "gia tri " << target << " tai index " << ordered_linear(arr, target , size);
    return 0;
}