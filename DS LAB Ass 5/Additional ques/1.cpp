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
    node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
node* intersectnode(node* head1, node* head2) {
    int len1 = 0, len2 = 0;
    node* temp1 = head1;
    node* temp2 = head2;
    while (temp1 != NULL) {
        len1++;
        temp1 = temp1->next;
    }
    while (temp2 != NULL) {
        len2++;
        temp2 = temp2->next;
    }
    temp1 = head1;
    temp2 = head2;
    if (len1 > len2) {
        int diff = len1 - len2;
        while (diff--) temp1 = temp1->next;
    } 
    else if (len2 > len1) {
        int diff = len2 - len1;
        while (diff--) temp2 = temp2->next;
    }
    while (temp1 != NULL && temp2 != NULL) {
        if (temp1 == temp2) return temp1;
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    return NULL;
}
int main() {
    node* n1 = new node(4);
    node* head1 = n1;
    node* tail1 = n1;
    insert(tail1, 1);
    node* intersect = new node(8);
    tail1->next = intersect;
    tail1 = intersect;
    insert(tail1, 5);
    node* n2 = new node(5);
    node* head2 = n2;
    node* tail2 = n2;
    insert(tail2, 6);
    insert(tail2, 1);
    tail2->next = intersect; 
    cout << "List A: ";
    print(head1);
    cout << "List B: ";
    print(head2);
    node* res = intersectnode(head1, head2);
    if (res != NULL) cout << "Intersection at node: " << res->data << endl;
    else cout << "No intersection" << endl;
    delete head1; 
    return 0;
}
