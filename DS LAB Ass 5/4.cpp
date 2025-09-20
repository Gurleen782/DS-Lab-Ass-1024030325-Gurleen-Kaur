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
void insert(node*& tail, int d) {
    node* n = new node(d);
    if (tail == NULL) {
        tail = n;
        return;
    }
    tail->next = n;
    tail = n;
}
void print(node* head) {
    node* n = head;
    while (n != NULL) {
        cout << n->data;
        if (n->next != NULL)
            cout << "->";
        n = n->next;
    }
    cout << "->NULL" << endl;
}
node* rev(node* head) {
    if (head == NULL || head->next == NULL) return head;
    node* prev = NULL;
    node* curr = head;
    node* forward = NULL;
    while (curr != NULL) {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }
    return prev;
}
int main() {
    node* n = new node(1);
    node* head = n;
    node* tail = n;
    insert(tail, 2);
    insert(tail, 3);
    insert(tail, 4);
    cout << "Original : ";
    print(head);
    head = rev(head);
    cout << "Reversed : ";
    print(head);
    return 0;
}
