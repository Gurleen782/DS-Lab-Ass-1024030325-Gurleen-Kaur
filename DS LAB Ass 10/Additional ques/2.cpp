#include <iostream>
#include <unordered_set>
using namespace std;
bool haspair(int arr[], int n, int sum) {
    unordered_set<int> s;
    for (int i = 0; i < n; i++) {
        int needed = sum - arr[i];
        if (s.find(needed) != s.end()) return true;
        s.insert(arr[i]);
    }
    return false;
}
int main() {
    int arr[5] = {0, -1, 2, -3, 1};
    int sum = -2;
    if (haspair(arr, 5, sum)) cout << "true";
    else cout << "false";
    return 0;
}
