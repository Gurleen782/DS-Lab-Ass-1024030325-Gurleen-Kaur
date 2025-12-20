#include <iostream>
#include <unordered_set>
using namespace std;
class node {
public:
    int data;
    node* next;
    node(int d) {
        data = d;
        next = NULL;
    }
};
void insert(node*& head, int d) {
    node* temp = new node(d);
    temp->next = head;
    head = temp;
}
void print(node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
}
void fun(node* head1, node* head2, node*& uhead, node*& ihead) {
    unordered_set<int> s;
    while (head1 != NULL) {
        s.insert(head1->data);
        insert(uhead, head1->data);
        head1 = head1->next;
    }
    while (head2 != NULL) {
        if (s.find(head2->data) != s.end())  insert(ihead, head2->data);
        else insert(uhead, head2->data); 
        head2 = head2->next;
    }
}
int main() {
    node* head1 = NULL;
    node* head2 = NULL;
    insert(head1, 20);
    insert(head1, 4);
    insert(head1, 15);
    insert(head1, 10);
    insert(head2, 10);
    insert(head2, 2);
    insert(head2, 4);
    insert(head2, 8);
    node* uhead = NULL;
    node* ihead = NULL;
    fun(head1, head2, uhead, ihead);
    cout << "Intersection: ";
    print(ihead);
    cout << "\nUnion: ";
    print(uhead);
    return 0;
}
