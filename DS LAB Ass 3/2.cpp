#include <iostream>
using namespace std;
#define size 50
class stack{
    char arr[size];
    int top;
public:
    stack(){ top = -1;}
    bool full(){
        return top == size - 1;
    }
    bool empty(){
        return top == -1;
    }
    void push(char c){
        if(!full()) arr[++top] = c;
    }
    void pop(){
        if (!empty()) top--;
    }
    void display(){
        if(!empty()){
            for (int i = 0; i <= top; i++){
                cout << arr[i];
            }
        }
    }
    char peek(){
        if (!empty())  return arr[top];
        else{
            cout << "Stack is empty" << endl;
            return '\0';
        }
    }
};
int main(){
    string str;
    cout<<"Enter string ";
    getline(cin,str);
    stack s;
    for(int i=0;i<str.length();i++){
        s.push(str[i]);
    }
    stack rev;
    while(!s.empty()){
        rev.push(s.peek());
        s.pop();
    }
    rev.display();
    return 0;
}
