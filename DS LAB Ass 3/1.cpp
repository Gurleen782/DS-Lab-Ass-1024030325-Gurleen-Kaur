#include<iostream>
using namespace std;
#define size 5
class stack{
    int arr[size];
    int top;
    public:
    stack() { top=-1;}
    bool empty(){
        return top==-1;
    }
    bool full(){
        return top==size-1;
    }
    void push(int n){
        if(full()) cout<<"overflow.. can't enter"<<n<<endl;
        else{
            arr[++top]=n;
            cout<<"entered "<<n<<endl;
        }
    }
    void pop(){
        if(empty()) cout<<"empty..nothing to pop\n";
        else{
            cout<<arr[top--]<<"popped\n";
        }
    }
    void peek(){
        if(empty()) cout<<"empty..nothing to peek\n";
        else{
            cout<<"top element:"<<arr[top]<<endl;
        }
    }
    void display(){
        if(empty()) cout<<"empty..nothing to peek\n";
        else{
            for(int i=top;i>=0;i--){
                cout<<arr[i]<<" ";
            }
            cout<<endl;
        }
    }
};
int main(){
    stack s;
    int n,choice;
    while(true){
        cout<<"MENU\n1.push\n2.pop\n3.peek\n4.display\n5.check full\n6.check empty\n7.exit\nEnter your choice:";
        cin>>choice;
        switch(choice){
            case 1:
                cout<<"Enter element to push: ";
                cin >> n;
                s.push(n);
                break;
            case 2:
                s.pop();
                break;
            case 3:
                s.peek();
                break;
            case 4:
                s.display();
                break;
            case 5:
                cout<<(s.empty()?"Stack is Empty.":"Stack is not Empty.") << endl;
                break;
            case 6:
                cout<<(s.full()?"Stack is Full.":"Stack is not Full.") << endl;
                break;
            case 7:
                cout << "Exited program" << endl;
                return 0;
            default:
                cout << "Invalid choice" << endl;
        }
    }
}