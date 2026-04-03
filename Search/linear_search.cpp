#include <iostream> 

using namespace std;

int linear(int arr[], int target, int size) {  //Hàm linear search là tìm từng cái từ index 0 đến n
    for (int i=0; i<size; i++) {
        if (arr[i]==target) {
            return i; //i là index và nó trả về vị trí i+1
        }
    } 
return -1; // index =-1 là ko tìm thấy gt
} 

int main () {
    int size,target;
    cout << "Nhap so luong phan tu: "; //nhập size của mảng
    cin >> size;
    cout << "Nhap cac gia tri: " ; // nhập các gt
    int arr[size];
    for (int i=0; i<size; i++) {  //nhập các giá trị của phần tử
        cin >> arr[i];
    }
    cout << "Nhap GT can tim: ";  // số cần tìm
    cin >> target;
    cout << "gia tri " << target << " tai index " << linear(arr, target, size); //gọi hàm tìm kiếm
    return 0;
}