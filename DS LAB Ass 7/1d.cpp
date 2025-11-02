#include<iostream>
using namespace std;
void merge(int arr[],int p,int q,int r){
    int n1 = q - p + 1;
    int n2 = r - q;
    int L[n1], R[n2];
    for(int i = 0; i < n1; i++){
        L[i] = arr[p + i];
    }
    for(int j = 0; j < n2; j++){
        R[j] = arr[q + 1 + j];
    }
    int i = 0, j = 0, k = p;
    while(i < n1 && j < n2){
        if(L[i] <= R[j]){
            arr[k] = L[i];
            i = i + 1;
        } 
        else{
            arr[k] = R[j];
            j = j + 1;
        }
        k = k + 1;
    }
    while(i < n1){
        arr[k] = L[i];
        i = i + 1;
        k = k + 1;
    }
    while(j < n2){
        arr[k] = R[j];
        j = j + 1;
        k = k + 1;
    }
}
void mergesort(int arr[], int p, int r) {
    if (p < r) {
        int q = (p + r) / 2;
        mergesort(arr, p, q);
        mergesort(arr, q + 1, r);
        merge(arr, p, q, r);
    }
}
int main() {
    int arr[5] = {7,9,2,8,5};
    int n = 5;
    cout << "original array: ";
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    mergesort(arr, 0, n - 1);
    cout << "sorted array: ";
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    return 0;
}
