#include <iostream>
#include <queue>
using namespace std;
class Stackqueue {
private:
     queue<int> q;
     queue<int> q2;
public:
    void push(int x) {
        q2.push(x);
        while (!q.empty()) {
            q2.push(q.front());
            q.pop();
        }
        swap(q, q2);
    }
    int top() {
        if (q.empty()) {
            cout << "Stack is empty\n";
            return 0; 
        }
        return q.front();
    }
    void pop() {
        if (q.empty()) {
            cout << "Stack is empty\n";
            return;
        }
        q.pop();
        cout<<"popped\n";
    }
    bool empty() {
        return q.empty();
    }
};
int main() {
    Stackqueue s;
    s.push(10);
    s.push(15);
    s.push(3);
    cout << "Top element: " << s.top() << endl;
    s.pop();
    cout << (s.empty() ? "empty" : "not empty") << endl;
    return 0;
}
