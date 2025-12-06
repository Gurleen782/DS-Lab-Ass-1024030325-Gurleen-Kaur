#include<iostream>
#include<map>
using namespace std;
int main () {
    map<int, int> freq;
    int arr[6] = {2, 3, 2, 4, 3, 2};
    for (int i = 0; i < 6; i++) {
        freq[arr[i]]++;
    }
    for (auto i : freq) {
        cout << i.first << " -> " << i.second << " times" << endl;
    }
}
