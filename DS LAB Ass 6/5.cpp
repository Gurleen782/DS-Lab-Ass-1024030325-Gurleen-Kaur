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
bool iscircular(node* head) {
    if (head == NULL)
        return false; 
    node* temp = head->next;
    while (temp != NULL && temp != head) {
        temp = temp->next;
    }
    return (temp == head); 
}
void print(node*& head) {
    if (head == NULL) return;
    node* n = head;
    do {
        cout << n->data << " ";
        n = n->next;
    } while (n != head);
    cout << endl;
}
int main() {
    node* head = NULL;
    node* tail = NULL;
    inserttail(tail, 2);
    head = tail;
    inserttail(tail, 4);
    inserttail(tail, 6);
    inserttail(tail, 7);
    inserttail(tail, 5);
    print(head);
    if (iscircular(head)) cout << "Yes,circular";
    else cout << "Not circular";
    return 0;
}
