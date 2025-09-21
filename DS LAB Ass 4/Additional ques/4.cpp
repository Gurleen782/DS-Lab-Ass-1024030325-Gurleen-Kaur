#include <iostream>
using namespace std;
class Queue {
    int arr[20];  
    int front;
    int rear;
public:
    Queue() { 
        front = 0; 
        rear = -1; 
    }
    void push(int x) {
        arr[++rear] = x;
    }
    void pop() {
        front++;
    }
    int peek() {
        return arr[front];
    }
    bool empty() {
        return front > rear;
    }
    int size() {
        return rear - front + 1;
    }
};
int count(int students[], int sandwiches[], int n) {
    Queue q;
    for (int i = 0; i < n; i++) {
        q.push(students[i]);
    }
    int top = 0;  
    int count = 0; 
    while (!q.empty() && count < q.size()) {
        if (q.peek() == sandwiches[top]) {
            q.pop();
            top++;
            count = 0;
        } 
        else {
            int temp = q.peek();
            q.pop();
            q.push(temp);
            count++;
        }
    }
    return q.size(); 
}
int main() {
    int students[] = {1, 1, 0, 0};
    int sandwiches[] = {0, 1, 0, 1};
    int n = 4;
    cout << count(students, sandwiches, n) << endl;
    return 0;
}
