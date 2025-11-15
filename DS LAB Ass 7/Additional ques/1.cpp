#include<iostream>
using namespace std;
void countingsort(int arr[], int n) {
    int max = arr[0];
    for(int i = 1; i < n; i++) {
        if(arr[i] > max)   max = arr[i];
    }
    int count[10000] = {0}; 
    for(int i = 0; i < n; i++) {
        count[arr[i]]++;
    }
    for(int i = 1; i <= max; i++) {
        count[i] += count[i - 1];
    }
    int ans[10000];
    for(int i = n - 1; i >= 0; i--) {
        ans[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }
    for(int i = 0; i < n; i++) {
        arr[i] = ans[i];
    }
}
int main() {
    int n;
    cin >> n;
    int arr[10000];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    countingsort(arr, n);
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    } 
    return 0;
}
