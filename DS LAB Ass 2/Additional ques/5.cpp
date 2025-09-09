#include <iostream>
using namespace std;
void duplicateTwos(int arr[], int n) {
    int twos = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == 2) twos++;
    }
    for (int i = n - 1; i >= 0; i--) {
        if (i + twos < n) {
            arr[i + twos] = arr[i];
        }
        if (arr[i] == 2) { 
            twos--;
            if (i + twos < n) {
                arr[i + twos] = 2;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main() {
    int arr[] = {1, 2, 3, 2, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    duplicateTwos(arr, n);
    return 0;
}
