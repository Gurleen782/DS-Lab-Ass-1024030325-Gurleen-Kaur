#include <iostream>
using namespace std;
int countPairs(int arr[], int n, int k) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] - arr[j] == k || arr[j] - arr[i] == k) {
                count++;
            }
        }
    }
    return count;
}
int main() {
    int arr[] = {1, 5, 3, 4, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 2;
    cout << "Count: " << countPairs(arr, n, k);
    return 0;
}
