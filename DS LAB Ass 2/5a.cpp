#include<iostream>
using namespace std;
int main(){
int n=4;
int diag[20]; 
    for(int i=0;i<n;i++){
        cin>>diag[i];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==j) cout<<diag[i]<<" ";
            else cout<<"0 ";
        }
        cout<<endl;
    }
    return 0;
}