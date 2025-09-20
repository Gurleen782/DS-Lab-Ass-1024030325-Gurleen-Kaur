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
    cout << endl;
}
node* getmid(node* head) {
    if (head == NULL) return NULL;
    node* slow = head;
    node* fast = head;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
int main() {
    node* n = new node(1);
    node* head = n;
    node* tail = n;
    insert(tail, 2);
    insert(tail, 3);
    insert(tail, 4);
    insert(tail, 5);
    cout << "Original Linked List: ";
    print(head);
    node* mid = getmid(head);
    if(mid != NULL) cout << "Mid = " << mid->data << endl;
    return 0;
}
