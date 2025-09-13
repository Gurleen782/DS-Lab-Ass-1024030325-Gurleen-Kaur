#include <iostream>
#include <stack>
using namespace std;
void fun(int arr[],int brr[],int n){
    stack<int>s;
    for(int i=n-1;i>=0;i--) {
        while(!s.empty() && s.top()<=arr[i]){
            s.pop();
        }
        if(!s.empty()) brr[i] = s.top();
        else brr[i]=-1;
        s.push(arr[i]);
    }
}
int main() {
    int n;
    cout<<"array size: ";
    cin>> n;
    int arr[n]; 
    int brr[n];
    cout<<"Enter elements: ";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    fun(arr,brr,n);
    cout<<"greater Elements:\n";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<"->"<<brr[i]<<endl;
    }
    return 0;
}
