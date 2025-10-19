#include <iostream>
using namespace std;
class node {
public:
    int data;
    node* next;
    node(int data) {
        this->data = data;
        this->next = NULL;
    }
};
void inserttail(node*& tail, int d) {
    node* n = new node(d);
    if (tail == NULL) {
        tail = n;
        tail->next = n;
        return;
    }
    n->next = tail->next;
    tail->next = n;
    tail = n;
}
void print(node*& head) {
    if (head == NULL) return;
    node* n = head;
    do {
        cout << n->data << " ";
        n = n->next;
    } while (n != head);
    cout << head->data << endl;
}
int main() {
    node* head = NULL;
    node* tail = NULL;
    inserttail(tail, 20);
    head = tail;
    inserttail(tail, 100);
    inserttail(tail, 40);
    inserttail(tail, 80);
    inserttail(tail, 60);
    print(head);
    return 0;
}
