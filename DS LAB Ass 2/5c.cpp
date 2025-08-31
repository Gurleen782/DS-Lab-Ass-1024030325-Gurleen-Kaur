#include<iostream>
using namespace std;
int main(){
int n=4;
int lower[20];
int index=0;
for(int i=0;i<n;i++){
    for(int j=0;j<=i;j++){
        cin>>lower[index++];
    }
}
index=0;
for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
        if(i>=j) cout<<lower[index++]<<" ";
        else cout<<"0 ";
    }
    cout<<endl;
}
return 0;
}