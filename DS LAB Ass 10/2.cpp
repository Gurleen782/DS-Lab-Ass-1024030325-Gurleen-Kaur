#include<iostream>
#include<unordered_set>
using namespace std;
int main () {
    unordered_set<int> s;
    int a[4] = {1, 2, 3, 4};
    int b[4] = {3, 4, 5, 6};
    for (int i = 0; i < 4; i++) {
        s.insert(a[i]);
    }
    for (int i = 0; i < 4; i++) {
        if (s.count(b[i]) != 0) cout << b[i] << " ";
    }
}
