#include <iostream>
#include <queue>
#include <stack>
using namespace std;
bool check(queue<int> que, int n) {
    stack<int> st;
    int var = 1;
    queue<int> outque; 
    while (!que.empty() || !st.empty()) {
        if (!que.empty() && que.front() == var) {
            outque.push(que.front());
            que.pop();
            var++;
        }
        else if (!st.empty() && st.top() == var) {
            outque.push(st.top());
            st.pop();
            var++;
        }
        else if (!que.empty()) {
            st.push(que.front());
            que.pop();
        }
        else {
            break;
        }
    }
    return var == n + 1;  
}
int main() {
    queue<int> q;
    q.push(5);
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    int n = 5;
    if (check(q, n))  cout << "Yes\n";
    else  cout << "No\n";
    return 0;
}
