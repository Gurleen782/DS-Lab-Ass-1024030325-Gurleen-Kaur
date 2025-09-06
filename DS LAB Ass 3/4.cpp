#include <iostream>
#include<stack>
#include<string>
using namespace std;
int precedence(char op){
    if(op=='+'||op=='-') return 1;
    if(op=='*'||op=='/') return 2;
    if(op=='^') return 3;
    return 0;
}
bool isoperator(char op){
    return(op=='+'||op=='-'||op=='*'||op=='/'||op=='^');
}
string intopostfix(string infix){
    stack<char>s;
    string postfix="";
    for(char c:infix){
        if(isalnum(c)) postfix+=c;
        else if(c=='(') s.push(c);
        else if(c==')'){
            while(!s.empty()&&s.top()!='('){
                postfix+=s.top();
                s.pop();
            }
            if(!s.empty()) s.pop();
        }
        else if(isoperator(c)){
            while(!s.empty()&&precedence(s.top())>=precedence(c)){
                postfix+=s.top();
                s.pop();
            }
            s.push(c);
        }
    }
    while(!s.empty()){
        postfix+=s.top();
        s.pop();
    }
    return postfix;
}
int main() {
    string infix;
    cout<<"Enter a infix expression ";
    getline(cin,infix);
    string postfix=intopostfix(infix);
    cout<<"Postfix expression:"<<postfix<<endl;
    return 0;
}