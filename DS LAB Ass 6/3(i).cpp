#include <iostream>
using namespace std;
class node{
    public:
    int data;
    node* next;
    node* prev;
    node(int data){
        this->data=data;
        this->next=NULL;
        this->prev=NULL;
    }
};
void inserttail(node*&head,node*&tail,int d){
    node*n=new node(d);
    if(tail==NULL){ 
        tail=n;
        head=n;
        return;
    }
    tail->next=n;
    n->prev=tail;
    tail=n;
}
void print(node*&head){
    node*n=head;
    while(n!=NULL){
        cout<<n->data<<" ";
        n=n->next;
    }
    cout<<endl;
}
int getlen(node*&head){
    int len=0;
    node*n=head;
    while(n!=NULL){
        len++;
        n=n->next;
    }
    return len;
}
int main() {
    node*n=new node(4);
    node*head=n;
    node*tail=n;
    inserttail(head,tail,5);
    inserttail(head,tail,6);
    inserttail(head,tail,7);
    inserttail(head,tail,8);
    print(head);
    cout<<"length:"<<getlen(head)<<endl;
    return 0;
}
