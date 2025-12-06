#include<iostream>
#include<unordered_map>
using namespace std;
int main () {
    unordered_map<int, int> freq;
    int arr[6] = {4, 5, 1, 2, 0, 4};
    for (int i = 0; i < 6; i++) {
        freq[arr[i]]++;
    }
    for (int i = 0; i < 6; i++) {
        if (freq[arr[i]] == 1) {
            cout << arr[i];
            return 0;
        }
    }
}
