#include <iostream>
#include <queue>
using namespace std;
class Stackqueue {
private:
    queue<int> q;
public:
    void push(int x) {
        q.push(x);
        for (int i = 0; i < q.size() - 1; i++) {
            q.push(q.front());
            q.pop();
        }
    }
    void pop() {
        if (q.empty()) {
            cout << "Stack empty\n";
            return;
        }
        q.pop();
        cout << "Popped\n";
    }
    int top() {
        if (q.empty()) {
            cout << "Stack empty\n";
            return 0;
        }
        return q.front();
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
    cout << "Top element after pop: " << s.top() << endl;
    cout << (s.empty() ? "empty" : "not empty") << endl;
    return 0;
}
