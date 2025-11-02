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
void print(node* head) {
    if (head == NULL) return;
    node* temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}
void splitlist(node* head, node*& head1, node*& head2) {
    if (head == NULL) {
        head1 = NULL;
        head2 = NULL;
        return;
    }
    node* slow = head;
    node* fast = head;
    while (fast->next != head && fast->next->next != head) {
        slow = slow->next;
        fast = fast->next->next;
    }
    if (fast->next->next == head) fast = fast->next;
    head1 = head;
    head2 = slow->next;
    slow->next = head1;
    fast->next = head2;
}
int main() {
    node* tail = NULL;
    inserttail(tail, 10);
    inserttail(tail, 4);
    inserttail(tail, 9);
    node* head = tail->next;
    cout << "Circular List: ";
    print(head);
    node* head1 = NULL;
    node* head2 = NULL;
    splitlist(head, head1, head2);
    cout << "First half: ";
    print(head1);
    cout << "Second half: ";
    print(head2);
    return 0;
}
