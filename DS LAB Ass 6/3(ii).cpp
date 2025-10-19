#include <iostream>
using namespace std;
class node{
    public:
    int data;
    node* next;
    node(int data){
        this->data=data;
        this->next=NULL;
    }
};
void inserttail(node*&tail,int d){
    node*n=new node(d);
    if(tail==NULL){
        tail=n;
        tail->next=n;
        return;
    }
    n->next=tail->next;
    tail->next=n;
    tail=n;
}
void print(node*&head){
    if(head==NULL) return;
    node*n=head;
    do{
        cout<<n->data<<" ";
        n=n->next;
    }while(n!=head);
    cout<<endl;
}
int getlen(node* head){
    int len=0;
    if(head==NULL) return len;
    node*n=head;
    do{
        len++;
        n=n->next;
    }while(n!=head);
    return len;
}
int main() {
    node*n=new node(4);
    node*head=n;
    node*tail=n;
    tail->next=head;
    inserttail(tail,5);
    inserttail(tail,6);
    inserttail(tail,7);
    inserttail(tail,8);
    print(head);
    cout<<"length:"<<getlen(head);
    return 0;
}
