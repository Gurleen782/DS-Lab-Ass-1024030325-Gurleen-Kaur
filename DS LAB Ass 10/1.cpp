#include<iostream>
#include<unordered_set>
using namespace std;
int main () {
    unordered_set<int> s;
    int arr[4] = {1, 2, 3, 1};
    for (int i = 0; i < 4; i++) {
        if (s.count(arr[i]) != 0) {
            cout << " true ";
            return 0;
        }
        s.insert(arr[i]);
    }
    cout << "false";
}
