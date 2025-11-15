#include <iostream>
using namespace std;
int getmax(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > max)  max = arr[i];
    return max;
}
void radixsort(int arr[], int n) {
    int max = getmax(arr, n);
    int bin[10][100];   
    int binsize[10];    
    int place = 1;
    while (max / place > 0) {
        for (int i = 0; i < 10; i++){
            binsize[i] = 0;
        }
        for (int i = 0; i < n; i++) {
            int dig = (arr[i] / place) % 10;
            bin[dig][binsize[dig]++] = arr[i];
        }
        int ind = 0;
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < binsize[i]; j++) {
                arr[ind++] = bin[i][j];
            }
        }
        place *= 10;
    }
}
int main() {
    int arr[7] = {70, 45, 75, 9, 24, 2, 6};
    int n=7;
    radixsort(arr, n);
    for (int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    return 0;
}
