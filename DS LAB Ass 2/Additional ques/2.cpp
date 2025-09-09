#include <iostream>
#include <string>
using namespace std;
bool canSplit(string s) {
    int n = s.length();
    for (int j = 1; j < n; j++) {
        for (int i = 0; i + j <= n; i++) {
            string sub = s.substr(i, j);
            size_t a = s.find(sub);
            size_t b = s.find(sub, a + 1);
            if (a != string::npos && b != string::npos) {
                return true; 
            }
        }
    }
    return false;
}
int main() {
    string s = "hello";
    if (canSplit(s)) cout << "YES";
    else cout << "NO";
    return 0;
}
