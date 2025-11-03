#include <iostream>
using namespace std;
class node{
public:
    int data;
    node *next;
    node *prev;
    node(int data){
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};
void correct(node *head){
    node *temp = head;
    while (temp != NULL && temp->next != NULL){
        if (temp->next->prev != temp){
            cout << "corrected link at node " << temp->next->data << endl;
            temp->next->prev = temp;
        }
        temp = temp->next;
    }
}
void print(node *head){
    node *temp = head;
    while (temp != NULL){
        cout << temp->data;
        if (temp->next != NULL)  cout << " ";
        temp = temp->next;
    }
    cout << endl;
}
int main(){
    node *head = new node(1);
    node *temp = head;
    for (int i = 2; i <= 3; i++){
        temp->next = new node(i);
        temp->next->prev = temp;
        temp = temp->next;
    }
    head->next->next->prev = head;
    cout << "Before correcting: ";
    print(head);
    correct(head);
    cout << "After correcting:  ";
    print(head);
    return 0;
}
