#include <iostream>
using namespace std;
class Queue {
    int arr[100];
    int SIZE;
    int front; 
    int rear;
    int cnt;
public:
    Queue(int n = 100) {
        SIZE = n;
        front = 0;
        rear = -1;
        cnt = 0;
    }
    void enqueue(int x) {
        if (cnt == SIZE) return; 
        rear = (rear + 1) % SIZE;
        arr[rear] = x;
        cnt++;
    }
    int dequeue() {
        if (cnt == 0) return -1; 
        int val = arr[front];
        front = (front + 1) % SIZE;
        cnt--;
        return val;
    }
    int peek() {
        if (cnt == 0) return -1;
        return arr[front];
    }
    bool isEmpty() { return cnt == 0; }
    int size() { return cnt; }
    void display() {
        for (int i = 0; i < cnt; i++){
            cout << arr[(front + i) % SIZE] << " ";
        }
        cout << endl;
    }
};
int minIndex(Queue &q, int upto) {
    int sz = q.size();
    int minind = -1;
    int minval = 0;
    bool flag = true;
    for (int i = 0; i < sz; i++) {
        int curr = q.dequeue();
        if (i < upto) {
            if (flag || curr <= minval) {
                minval = curr;
                minind = i;
                flag = false;
            }
        }
        q.enqueue(curr);
    }
    return minind;
}
void move(Queue &q, int min_index) {
    int sz = q.size();
    int minval = 0;
    for (int i = 0; i < sz; i++) {
        int curr = q.dequeue();
        if (i == min_index) {
            minval = curr; 
        } 
        else {
            q.enqueue(curr);
        }
    }
    q.enqueue(minval);
}
void sort(Queue &q) {
    int n = q.size();
    for (int i = 1; i <= n; i++) {
        int minind = minIndex(q, n - i + 1);
        move(q, minind);
    }
}
int main() {
    Queue q(20);
    q.enqueue(11);
    q.enqueue(5);
    q.enqueue(4);
    q.enqueue(21);
    cout << "Original queue: ";
    q.display();
    sort(q);
    cout << "Sorted queue: ";
    q.display();
    return 0;
}
