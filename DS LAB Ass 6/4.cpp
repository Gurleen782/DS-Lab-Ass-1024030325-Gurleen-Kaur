#include <iostream>
using namespace std;
class node {
public:
    char data;
    node* next;
    node* prev;
    node(char data) { 
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};
void inserttail(node*& head, node*& tail, char d) {
    node* n = new node(d);
    if (tail == NULL) {
        tail = n;
        head = n;
        return;
    }
    tail->next = n;
    n->prev = tail;
    tail = n;
}
void print(node*& head) {
    node* n = head;
    while (n != NULL) {
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}
int getlen(node*& head) {
    int len = 0;
    node* n = head;
    while (n != NULL) {
        len++;
        n = n->next;
    }
    return len;
}
bool palindrome(node* head, node* tail) {
    while (head != tail && head->prev != tail) {
        if (head->data != tail->data)
            return false;
        head = head->next;
        tail = tail->prev;
    }
    return true;
}
int main() {
    node* head = NULL;
    node* tail = NULL;
    inserttail(head, tail, 'l');
    inserttail(head, tail, 'e');
    inserttail(head, tail, 'v');
    inserttail(head, tail, 'e');
    inserttail(head, tail, 'l');
    print(head);
    if (palindrome(head, tail))  cout << "true";
    else  cout << "false";
    return 0;
}
