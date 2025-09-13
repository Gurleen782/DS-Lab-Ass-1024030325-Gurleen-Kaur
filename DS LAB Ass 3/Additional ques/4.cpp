#include <iostream>
#include <stack>
using namespace std;
void days(int temperatures[],int answer[],int n){
    stack<int>s; 
    for(int i = 0; i < n; i++){
        while(!s.empty() && temperatures[i]>temperatures[s.top()]){
            int j=s.top();
            s.pop();
            answer[j]=i-j;
        }
        s.push(i);
    }
    while(!s.empty()){
        answer[s.top()]=0;
        s.pop();
    }
}
int main() {
    int n;
    cout<<"how many days: ";
    cin>>n;
    int temperatures[n];
    int answer[n];
    cout<<"Enter temperatures: ";
    for(int i = 0; i < n; i++){
        cin>>temperatures[i];
        answer[i]=0;
    }
    days(temperatures,answer,n);
    cout<<"Days to wait: ";
    for(int i = 0; i < n; i++){
        cout<<answer[i]<< " ";
    }
    return 0;
}
