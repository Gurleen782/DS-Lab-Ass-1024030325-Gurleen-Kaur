#include<iostream>
using namespace std;
int main(){
int n=4;
int sym[20]; 
int index=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            cin>>sym[index++];  
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i>=j) index=i*(i+1)/2+j;
            else index=j*(j+1)/2+i;
            cout<<sym[index]<<" ";
        }
        cout<<endl;
    }
    return 0;
}