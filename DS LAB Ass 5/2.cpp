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
    ~node() {
        int value = this->data;
        if (this->next != NULL) {
            delete next;
            this->next = NULL;
        }
        cout << "Memory freed for " << value << endl;
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
int countOccurr(node* head, int key) {
    int count = 0;
    node* curr = head;
    while (curr != NULL) {
        if (curr->data == key)
            count++;
        curr = curr->next;
    }
    return count;
}
void deleteoccurr(node*& head, node*& tail, int key) {
    while (head != NULL && head->data == key) {
        node* temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }
    if (head == NULL) {
        tail = NULL;
        return;
    }
    node* prev = head;
    node* curr = head->next;
    while (curr != NULL) {
        if (curr->data == key) {
            prev->next = curr->next;
            curr->next = NULL;
            delete curr;
            curr = prev->next;
        } 
        else {
            prev = curr;
            curr = curr->next;
        }
    }
    tail = head;
    while (tail != NULL && tail->next != NULL) {
        tail = tail->next;
    }
}
int main() {
    node* n = new node(1);
    node* head = n;
    node* tail = n;
    insert(tail, 2);
    insert(tail, 1);
    insert(tail, 2);
    insert(tail, 1);
    insert(tail, 3);
    insert(tail, 1);
    cout << "Original Linked List: ";
    print(head);
    int key = 1;
    int count = countOccurr(head, key);
    cout << "count: " << count << endl;
    deleteoccurr(head, tail, key);
    cout << "Updated Linked List: ";
    print(head);
    delete head;
    return 0;
}
