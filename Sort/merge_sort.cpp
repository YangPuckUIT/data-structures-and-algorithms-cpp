#include <iostream>
using namespace std;

const int MAX_SIZE = 1000; // số phần tử tối đa

void merge(int theArray[], int first, int mid, int last) {
    int tempArray[MAX_SIZE];
    int first1 = first;
    int last1 = mid;
    int first2 = mid + 1;
    int last2 = last;
    int index = first1;
 
    // trộn hai mảng con
    for (; (first1 <= last1) && (first2 <= last2); ++index) {
        if (theArray[first1] < theArray[first2]) {
            tempArray[index] = theArray[first1];
            ++first1;
        } else {
            tempArray[index] = theArray[first2];
            ++first2;
        }
    }

    // copy phần còn lại
    for (; first1 <= last1; ++first1, ++index)
        tempArray[index] = theArray[first1];
    for (; first2 <= last2; ++first2, ++index)
        tempArray[index] = theArray[first2];

    // copy về mảng gốc
    for (index = first; index <= last; ++index)
        theArray[index] = tempArray[index];
}

void mergesort(int theArray[], int first, int last) {
    if (first < last) {
        int mid = (first + last) / 2;
        mergesort(theArray, first, mid);
        mergesort(theArray, mid + 1, last);
        merge(theArray, first, mid, last);
    }
}

int main() {
    int n;
    cout << "Nhap so luong phan tu: ";
    cin >> n;
    int arr[MAX_SIZE];
    cout << "Nhap cac gia tri: ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    mergesort(arr, 0, n - 1);

    cout << "Mang da sap xep: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
    return 0;
}
