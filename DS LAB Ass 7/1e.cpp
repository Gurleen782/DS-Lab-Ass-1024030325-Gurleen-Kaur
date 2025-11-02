#include<iostream>
using namespace std;
int part(int A[], int p, int r) {
    int x = A[r];       
    int i = p - 1;      
    for (int j = p; j <= r - 1; j++) {
        if (A[j] <= x) {
            i = i + 1;
            swap(A[i], A[j]);   
        }
    }
    swap(A[i + 1], A[r]);      
    return i + 1;
}
void quicksort(int A[], int p, int r) {
    if (p < r) {
        int q = part(A, p, r);
        quicksort(A, p, q - 1);
        quicksort(A, q + 1, r);
    }
}
int main() {
    int A[5] = {7, 9, 2, 8, 5};
    int n = 5;
    cout << "original array: ";
    for (int i = 0; i < n; i++) {
        cout << A[i] << " ";
    }
    cout << endl;
    quicksort(A, 0, n - 1);  
    cout << "sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << A[i] << " ";
    }
    return 0;
}
