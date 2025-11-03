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
int countparity(int n) {
    int count = 0;
    while (n) {
        count += (n & 1);
        n >>= 1;
    }
    return count;
}
void removeparity(node*& head) {
    if (!head) return;
    node* curr = head;
    while (curr) {
        int parity = countparity(curr->data);
        if (parity % 2 == 0) {  
            node* todel = curr;
            if (curr->prev) curr->prev->next = curr->next;
            else  head = curr->next;  
            if (curr->next)  curr->next->prev = curr->prev;
            curr = curr->next;
            delete todel;
        } 
        else curr = curr->next;
    }
}
void print(node* head) {
    node* temp = head;
    while (temp) {
        cout << temp->data;
        if (temp->next) cout << " ";
        temp = temp->next;
    }
    cout << endl;
}
int main() {
    node* head = NULL;
    node* tail = NULL;
    inserttail(head, tail, 18);
    inserttail(head, tail, 15);
    inserttail(head, tail, 8);
    inserttail(head, tail, 9);
    inserttail(head, tail, 14);
    cout << "Original list: ";
    print(head);
    removeparity(head);
    cout << "After removing: ";
    print(head);
    return 0;
}
