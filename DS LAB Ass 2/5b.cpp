include<iostream>
using namespace std;
int main(){
int n=4;
int t[20]; 
    for(int i=0;i<3*n-2;i++){
        cin>>t[i];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i-j==1) cout<<t[i-1]<<" ";
            else if(i-j==0)  cout<<t[n-1+i]<<" ";
            else if(i-j==-1)  cout<<t[2*n-1+i]<<" ";
            else cout<<"0 ";
        }
        cout<<endl;
    }
    return 0;
}