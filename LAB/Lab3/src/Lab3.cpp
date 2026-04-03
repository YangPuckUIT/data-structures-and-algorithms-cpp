#include <iostream>
#include <climits>
using namespace std;
// câu 1
void quicksort(int *arr, int left, int right) {
    if (left >= right) return;
    int pivot = arr[(left + right) / 2];
    int i = left, j = right;
    while (i <= j) {
        while (arr[i] < pivot) i++;
        while (arr[j] > pivot) j--;
        if (i <= j) {
            swap(arr[i], arr[j]);
            i++; j--;
        }
    }
    if (left < j) quicksort(arr, left, j);
    if (i < right) quicksort(arr, i, right);
}
// câu 2
int maxSubArraySum(int *arr, int n) {
    int maxSum = arr[0], currentSum = arr[0];
    for (int i = 1; i < n; i++) {
        currentSum = max(arr[i], currentSum + arr[i]);
        maxSum = max(maxSum, currentSum);
    }
    return maxSum;
}
// câu 3 cấp phát động cho magnr 2 chieuef
int** allocateMatrix(int m, int n) {
    int **mat = new int*[m];
    for (int i = 0; i < m; i++)
        mat[i] = new int[n];
    return mat;
}
// xóa mnagr 2 chiều
void freeMatrix(int **mat, int m) {
    for (int i = 0; i < m; i++)
        delete[] mat[i];
    delete[] mat;
}

void inputMatrix(int **mat, int m, int n) {
    cout << "Matrix elements:\n";
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> mat[i][j];
}

void printMatrix(int **mat, int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++)
            cout << mat[i][j] << " ";
        cout << endl;
    }
}

int diagonalSum(int **mat, int m, int n) {
    int sum = 0;
    int size = (m < n) ? m : n;
    for (int i = 0; i < size; i++)
        sum += mat[i][i];
    return sum;
}

int maxBoundaryElement(int **mat, int m, int n) {
    int maxVal = INT_MIN;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (i == 0 || i == m-1 || j == 0 || j == n-1)
                maxVal = max(maxVal, mat[i][j]);
        }
    }
    return maxVal;
}
// gán ma trận nghịch đảo = ma trận gốc
int** transposeMatrix(int **mat, int m, int n) {
    // tạo ma trận nghịch đảo như tạo ma trận gốc, nhưng n x m thay vì m x n
    int **trans = allocateMatrix(n, m);
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            trans[j][i] = mat[i][j];
    return trans;
}

void nextGreaterElement_N2(int *arr, int n) {
    cout << "Next Greater Elements:\n";
    for (int i = 0; i < n; i++) {
        int next = -1;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] > arr[i]) {
                next = arr[j];
                break; 
            }
        }
        cout << "The next greater element of " << arr[i] << " is " << next << endl;
    }
}


int main() {
    int n;
    cout << "Array size: ";
    cin >> n;

    int *arr = new int[n];
    cout << "Elements of array:" << endl;
    for (int i = 0; i < n; i++) 
    cin >> arr[i];

    quicksort(arr, 0, n - 1);
    cout << "1. Quick sort: ";
    for (int i = 0; i < n; i++) 
    cout << arr[i] << " ";
    cout << endl;

    cout << "2. Maximum subarray sum = " << maxSubArraySum(arr, n) << endl;
    delete[] arr; // xóa mảng dùng cho câu 1 và 2

// tạo mảng 2 chiều mới
    int m, cols;
    cout << "\n3. Matrix size (rows x cols): ";
    cin >> m >> cols;
// cấp phát động cho mảng 2 chiều
    int **matrix = allocateMatrix(m, cols);
// nhập giá trị
    inputMatrix(matrix, m, cols);
// tổng đương chéo chính
    cout << "Sum of main diagonal: " << diagonalSum(matrix, m, cols) << endl;
// giá trị lớn nhất rìa mảng
    cout << "Largest boundary element: " << maxBoundaryElement(matrix, m, cols) << endl;
// tạo ma trận nghịch đảo
    int **transposed = transposeMatrix(matrix, m, cols);
    cout << "\nTransposed matrix:\n";
// in ra ma trận nghịch đảo, hàm đã bị đổi và cột với dòng cũng đổi ngược lại
    printMatrix(transposed, cols, m);
// xóa 2 ma trận để làm bài 5
    freeMatrix(matrix, m);
    freeMatrix(transposed, cols);

    int k;
    cout << "\n5. Array size for Next Greater Element: ";
    cin >> k;

    int *b = new int[k];
    cout << "Elements of array:\n";
    for (int i = 0; i < k; i++) 
    cin >> b[i];

    nextGreaterElement_N2(b, k);

    delete[] b; 
    return 0;
}
