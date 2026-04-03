#include <iostream>

using namespace std;

void Merge(int arr[], int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;

    int* L = new int[n1];
    int* R = new int[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];

    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }

    while (i < n1)
        arr[k++] = L[i++];

    while (j < n2)
        arr[k++] = R[j++];

    delete[] L;
    delete[] R;
}

void MergeSort(int arr[], int l, int r)
{
    if (l < r) {
        int m = l + (r - l) / 2;
        MergeSort(arr, l, m);
        MergeSort(arr, m + 1, r);
        Merge(arr, l, m, r);
    }
}

void QuickSort(int arr[], int l, int r)
{
    if (l >= r) return;

    int pivot = arr[l + (r - l) / 2];
    int i = l, j = r;

    while (i <= j) {
        while (arr[i] < pivot) i++;
        while (arr[j] > pivot) j--;
        if (i <= j) {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }

    if (l < j) QuickSort(arr, l, j);
    if (i < r) QuickSort(arr, i, r);
}

int main() {
    int a[] = {5, 2, 9, 1, 3};
    int b[] = {5, 2, 9, 1, 3};
    int n = 5;
 
    MergeSort(a, 0, n - 1);
    QuickSort(b, 0, n - 1);

    cout << "MergeSort: ";
    for (int i = 0; i < n; i++) cout << a[i] << " ";
    cout << endl;

    cout << "QuickSort: ";
    for (int i = 0; i < n; i++) cout << b[i] << " ";

    return 0;
}