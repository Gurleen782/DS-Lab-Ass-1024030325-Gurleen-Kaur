#include <iostream>
using namespace std;
class node {
public:
    int coef;
    int power;
    node* next;
    node(int c, int p) {
        this->coef = c;
        this->power = p;
        this->next = NULL;
    }
};
void inserttail(node*& head, node*& tail, int c, int p) {
    node* n = new node(c, p);
    if (tail == NULL) {
        head = tail = n;
        return;
    }
    tail->next = n;
    tail = n;
}
void print(node* head) {
    node* temp = head;
    while(temp != NULL) {
        cout << "[" << temp->coef << ", " << temp->power << "]";
        temp = temp->next;
        if(temp != NULL) cout << ", ";
    }
    cout << endl;
}
node* add(node* head1, node* head2) {
    node* HEAD = NULL;
    node* TAIL = NULL;
    node* temp1 = head1;
    node* temp2 = head2;
    while(temp1 != NULL && temp2 != NULL) {
        if(temp1->power > temp2->power) {
            inserttail(HEAD, TAIL, temp1->coef, temp1->power);
            temp1 = temp1->next;
        }
        else if(temp2->power > temp1->power) {
            inserttail(HEAD, TAIL, temp2->coef, temp2->power);
            temp2 = temp2->next;
        }
        else {
            inserttail(HEAD, TAIL, temp1->coef + temp2->coef, temp1->power);
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
    }
    while(temp1 != NULL) {
        inserttail(HEAD, TAIL, temp1->coef, temp1->power);
        temp1 = temp1->next;
    }
    while(temp2 != NULL) {
        inserttail(HEAD, TAIL, temp2->coef, temp2->power);
        temp2 = temp2->next;
    }
    return HEAD;
}
int main() {
    node* poly1 = NULL;
    node* tail1 = NULL;
    node* poly2 = NULL;
    node* tail2 = NULL;
    inserttail(poly1, tail1, 5, 2);
    inserttail(poly1, tail1, 4, 1);
    inserttail(poly1, tail1, 2, 0);
    inserttail(poly2, tail2, 5, 1);
    inserttail(poly2, tail2, 5, 0);
    node* sum = add(poly1, poly2);
    print(sum);
    return 0;
}
