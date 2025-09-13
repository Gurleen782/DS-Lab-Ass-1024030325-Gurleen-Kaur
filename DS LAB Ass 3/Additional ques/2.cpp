#include <iostream>
#include <stack>
using namespace std;
class stackk{
    stack<int>s;
    int min;
public:
    bool empty(){
        return s.empty();
    }
    void push(int v){
        if(s.empty()){
            s.push(v);
            min=v;
        } 
        else if(v<min){
            s.push(2*v-min);
            min=v;
        } 
        else { s.push(v);}
    }
    void pop(){
        int n=s.top(); 
        s.pop();
        if(n<min){ min=2*min-n;}
    }
    int top(){
        int n = s.top();
        return (n<min)?min:n;
    }
    int getMin(){
        return min;
    }
};
int main() {
    stackk s;
    s.push(2);
    s.push(4);
    s.push(6);
    s.push(1);
    cout<<s.getMin()<<" "; 
    cout<<s.top()<<" "<<endl;     
    s.pop();
    cout<<s.getMin()<<" "<<endl; 
    s.pop();
    cout<<s.top()<<" ";     
    cout<<s.getMin()<<" ";  
}
