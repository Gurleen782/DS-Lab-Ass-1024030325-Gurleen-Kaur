#include <iostream>
#include <unordered_map>
using namespace std;
bool areequal(int a[], int b[], int n) {
    unordered_map<int, int> freq;
    for (int i = 0; i < n; i++) {
        freq[a[i]]++;
    }
    for (int i = 0; i < n; i++) {
        if (freq.find(b[i]) == freq.end()) return false; 
        freq[b[i]]--;
        if (freq[b[i]] < 0) return false;  
    }
    return true;
}
int main() {
    int arr[7] = {1, 2, 5, 4, 0, 2, 1};
    int brr[7] = {2, 4, 5, 0, 1, 1, 2};
    if (areequal(arr, brr, 7)) cout << "true";
    else cout << "false";
    return 0;
}
