#include<iostream>
#include<unordered_map>
using namespace std;
int main () {
    unordered_map<int, int> m;
    int arr[4] = {1, 2, 3, 1};
    for (int i = 0; i < 4; i++) {
        if (m.count(arr[i]) == 1) {
            cout << " true ";
            return 0;
        }
        m[arr[i]] = 1;
    }
    cout << "false";
}
