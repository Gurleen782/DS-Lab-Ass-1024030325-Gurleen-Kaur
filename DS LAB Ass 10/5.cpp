#include<iostream>
#include<unordered_set>
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
void hasloop(node* head) {
    unordered_set<node*> vis;
    node* temp = head;
    while (temp != NULL) {
        if (vis.count(temp) != 0) {
            cout << "true";
            return;
        }
        vis.insert(temp); 
        temp = temp->next;
    }
    cout << "false";
}
int main() {
    node* a = new node(1);
    node* b = new node(2);
    node* c = new node(3);
    node* d = new node(4);
    a->next = b;
    b->next = c;
    c->next = d;
    d->next = b;  
    hasloop(a);  
    return 0;
}
