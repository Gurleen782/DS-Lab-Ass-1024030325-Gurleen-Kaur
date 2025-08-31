#include<iostream>
using namespace std;
int main(){
int n=4;
int upper[20];
int index=0;
for(int i=0;i<n;i++){
    for(int j=i;j<n;j++){
        cin>>upper[index++];
    }
}
index=0;
for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
        if(i<=j) cout<<upper[index++]<<" ";
        else cout<<"0 ";
    }
    cout<<endl;
}
return 0;
}