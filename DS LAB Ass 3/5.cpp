#include <iostream>
#include<stack>
#include<string>
using namespace std;
int operation(int a,int b,char op){
    switch(op){
        case '+': return a+b;
        case '-': return a-b;
        case '*': return a*b;
        case '/': return a/b;
    }
    return 0;
}
int evaluate(string postfix){
    stack<int>s;
    for(char c:postfix){
        if(c>='0'&&c<='9') s.push(c-'0');
        else{
            int b=s.top();
            s.pop();
            int a=s.top();
            s.pop();
            int res=operation(a,b,c);
            s.push(res);
        }
    }
    return s.top();
}
int main() {
    string postfix;
    cout<<"Enter a postfix expression ";
    cin>>postfix;
    int res=evaluate(postfix);
    cout<<"Result:"<<res<<endl;
    return 0;
}