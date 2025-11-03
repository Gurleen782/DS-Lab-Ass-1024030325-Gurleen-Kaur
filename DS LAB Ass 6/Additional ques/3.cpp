#include <iostream>
using namespace std;
class node {
public:
    int data;
    node* next;
    node* prev;
    node(int data) {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};
void inserttail(node*& head, node*& tail, int d) {
    node* n = new node(d);
    if (tail == NULL) {
        head = tail = n;
        return;
    }
    tail->next = n;
    n->prev = tail;
    tail = n;
}
void print(node* head) {
    node* n = head;
    while (n != NULL) {
        cout << n->data;
        if (n->next) cout << " ";
        n = n->next;
    }
    cout << " NULL" << endl;
}
node* rev(node* head, int k) {
    if (head==NULL) return NULL;
    node* curr = head;
    node* newhead = NULL;
    node* nextn = NULL;
    node* prevn = NULL;
    int count = 0;
    while (curr != NULL && count < k) {
        nextn = curr->next;
        curr->next = prevn;
        curr->prev = nextn;
        prevn = curr;
        curr = nextn;
        count++;
    }
    if(nextn != NULL)  head->next = rev(nextn, k);
    if(head->next != NULL) head->next->prev = head;
    return prevn;
}
int main() {
    node* head = NULL;
    node* tail = NULL;
    inserttail(head, tail, 1);
    inserttail(head, tail, 2);
    inserttail(head, tail, 3);
    inserttail(head, tail, 4);
    inserttail(head, tail, 5);
    inserttail(head, tail, 6);
    cout << "Original list: ";
    print(head);
    int k = 2; 
    head = rev(head, k);
    cout << "Reversed list: ";
    print(head);
    return 0;
}
