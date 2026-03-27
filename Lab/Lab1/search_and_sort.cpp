#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;

//  Hàm tiện ích 
void print_array(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void copy_array(int src[], int dest[], int n) {
    for (int i = 0; i < n; i++)
        dest[i] = src[i];
} 

// CÁC THUẬT TOÁN SẮP XẾP

// Selection Sort
void selection_sort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {       //nó lấy gt đầu làm min, và cho j chạy từ phần tử tiếp -> hết và so sánh, nếu gt chạy đến nhỏ hơn min thì đổi chỗ 2 phân tử đó
        int minIdx = i;
        for (int j = i + 1; j < n; j++)
            if (arr[j] < arr[minIdx])
                minIdx = j;
        swap(arr[i], arr[minIdx]);  // tạo 1 hàm để đổi 2 phần tử (vscode nó có hàm rồi, còn ko có tự build hàm swap)
    }
}

// Insertion Sort
void insertion_sort(int arr[], int n) {
    for (int i = 1; i < n; i++) {   // bắt đầu từ phần tử thứ 2
        int key = arr[i];           // lưu giá trị hiện tại
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {        // dịch các phần tử lớn hơn sang phả
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;        // chèn phần tử vào đúng vị trí
    }
}

// Bubble Sort
void bubble_sort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++)             // lặp qua từng phần tử
        for (int j = 0; j < n - i - 1; j++)     // phần tử lớn nhất nổi lên cuối
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);        // hoán đổi nếu sai thứ tự
}

// Quick Sort
void quick_sort(int arr[], int left, int right) {
    int i = left, j = right;
    int pivot = arr[(left + right) / 2];
    while (i <= j) {
        while (arr[i] < pivot) i++;
        while (arr[j] > pivot) j--;
        if (i <= j) swap(arr[i++], arr[j--]);
    }
    if (left < j) quick_sort(arr, left, j);
    if (i < right) quick_sort(arr, i, right);
}
   
// Merge Sort
void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1, n2 = r - m;
    int L[n1], R[n2];
    for (int i = 0; i < n1; i++) L[i] = arr[l + i];     // sao chép mảng trái
    for (int j = 0; j < n2; j++) R[j] = arr[m + 1 + j];// sao chép mảng phải
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2)             // trộn 2 mảng lại theo thứ tự tăng dần
        arr[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];
    while (i < n1) arr[k++] = L[i++];        // thêm phần còn lại của L
    while (j < n2) arr[k++] = R[j++];           // thêm phần còn lại của R
}
// Merge Sort: chia đôi mảng, sắp xếp đệ quy và trộn lại
void merge_sort(int arr[], int l, int r) {
    if (l < r) {
        int m = (l + r) / 2;
        merge_sort(arr, l, m);
        merge_sort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

// Heap Sort
void heapify(int arr[], int n, int i) {     // Hàm hỗ trợ cho Heap Sort: duy trì tính chất max-heap
    int largest = i, l = 2 * i + 1, r = 2 * i + 2;
    if (l < n && arr[l] > arr[largest]) largest = l;
    if (r < n && arr[r] > arr[largest]) largest = r;
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heap_sort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

//  CÁC THUẬT TOÁN TÌM KIẾM 

int linear_search(int arr[], int size, int target) { //Hàm linear search là tìm từng cái từ index 0 đến n
    for (int i = 0; i < size; i++)
        if (arr[i] == target)
            return i;
    return -1;
}

int ordered_linear_search(int arr[], int size, int target) { // mảng đã đc SẮP XẾP nên chạy giống linear search nhưng nếu value < arr[i] thì dừng luôn
    for (int i = 0; i < size; i++) {
        if (arr[i] == target)
            return i;
        else if (arr[i] > target) //nếu GT cần tìm nhỏ hơn phần tử tiếp là dừng
            return -1;
    }
    return -1;
}

int binary_search(int arr[], int left, int right, int target) {         //tìm giá trị trên mảng đã sắp xếp, nó lấy mốc ở giữa, nếu GT cần tìm nhỏ hơn mốc thì lấy trái bỏ phải (ngược lại)
    while (left <= right) {     
        int mid = (left + right) / 2;
        if (arr[mid] == target)      // TH tìm đc gt
            return mid;
        else if (arr[mid] < target)    
            left = mid + 1;     // TH gt cần tìm có thể bên phải, else là đc vì còn đúng 1 biến cố này à
        else
            right = mid - 1;    // TH gt cần tìm có thể bên trái
    }
    return -1;
}

int jump_search(int arr[], int n, int x) {
    int step = sqrt(n);     // Chia mảng thành các khối kích thước sqrt(n)
    int prev = 0;
    while (arr[(step < n ? step : n) - 1] < x) {    // nhảy cho đến khi vượt quá hoặc bằng target
        prev = step;
        step += sqrt(n);
        if (prev >= n)
            return -1;
    }
    while (arr[prev] < x) {      // tìm tuyến tính trong block
        prev++;
        if (prev == (step < n ? step : n))
            return -1;
    }
    return (arr[prev] == x) ? prev : -1;
}

int interpolation_search(int arr[], int n, int x) {     //dự đoán vị trí có thể của phần tử dựa trên tỉ lệ giá trị
    int lo = 0, hi = n - 1;
    while (lo <= hi && x >= arr[lo] && x <= arr[hi]) {
        if (lo == hi)
            return (arr[lo] == x) ? lo : -1;
        int pos = lo + (((double)(hi - lo) / (arr[hi] - arr[lo])) * (x - arr[lo]));
        if (arr[pos] == x)
            return pos;
        if (arr[pos] < x)
            lo = pos + 1;
        else
            hi = pos - 1;
    }
    return -1;
}

int exponential_search(int arr[], int n, int x) {   // Exponential Search: tăng gấp đôi chỉ số cho đến khi vượt quá target, sau đó dùng Binary Search
    if (arr[0] == x)
        return 0;
    int i = 1;
    while (i < n && arr[i] <= x)
        i *= 2;
    return binary_search(arr, i / 2, min(i, n - 1), x);
}

//  HÀM MAIN 
int main() {
    const int size = 8;
    int arr[size] = {34, 7, 23, 32, 5, 62, 36, 14};
    int temp[size];
    int target;

    cout << "Original array: ";  // mảng khi chưa sắp xếp
    print_array(arr, size);

    // Gọi các thuật toán sắp xếp
    cout << "\nSelection Sort: ";
    copy_array(arr, temp, size);
    selection_sort(temp, size);
    print_array(temp, size);

    cout << "Insertion Sort: ";
    copy_array(arr, temp, size);
    insertion_sort(temp, size);
    print_array(temp, size);

    cout << "Bubble Sort: ";
    copy_array(arr, temp, size);
    bubble_sort(temp, size);
    print_array(temp, size);

    cout << "Quick Sort: ";
    copy_array(arr, temp, size);
    quick_sort(temp, 0, size - 1);
    print_array(temp, size);

    cout << "Merge Sort: ";
    copy_array(arr, temp, size);
    merge_sort(temp, 0, size - 1);
    print_array(temp, size);

    cout << "Heap Sort: ";
    copy_array(arr, temp, size);
    heap_sort(temp, size);
    print_array(temp, size);

    // Dùng mảng đã sắp xếp bằng Bubble Sort để chạy tìm kiếm (vì bubble dễ hiểu nhất nên chạy nó)
    bubble_sort(arr, size);
    cout << "\nSorted array for searching: ";
    print_array(arr, size);

    cout << "\nEnter search value: ";
    cin >> target;
    
    // ra -1 là nó không tìm thấy
    cout << "\nLinear Search (unsorted): " << linear_search(arr, size, target) << endl;
    cout << "Ordered Linear Search: " << ordered_linear_search(arr, size, target) << endl;
    cout << "Binary Search: " << binary_search(arr, 0, size - 1, target) << endl;
    cout << "Jump Search: " << jump_search(arr, size, target) << endl;
    cout << "Interpolation Search: " << interpolation_search(arr, size, target) << endl;
    cout << "Exponential Search: " << exponential_search(arr, size, target) << endl;

    return 0;
}
