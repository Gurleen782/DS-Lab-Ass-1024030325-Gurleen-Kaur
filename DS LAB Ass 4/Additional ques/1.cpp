#include <iostream>
#include <queue>
using namespace std;
void fun(int n) {
    queue<string>q;
    q.push("1"); 
    for (int i = 1; i <= n; i++) {
        string str = q.front();
        q.pop();
        cout << str << " ";
        q.push(str + "0");
        q.push(str + "1");
    }
}
int main() {
    int n = 2;
    fun(n);
    return 0;
}
