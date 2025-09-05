#include <iostream>
using namespace std;
void prod(int arr[2][3],int brr[3][2],int a,int b,int c,int d){
    int prod[a][d]={0};
    for(int i=0;i<a;i++){
        for(int j=0;j<d;j++){
            for(int k=0;k<b;k++){
                prod[i][j]+=arr[i][k]*brr[k][j];
            }
        }
    }
    for(int i=0;i<a;i++){
        for(int j=0;j<d;j++){
            cout<<prod[i][j]<<" ";
        }
        cout<<endl;
    }
}
int main(){
    int arr[2][3]={2,1,1,2,1,2};
    int brr[3][2]={1,2,2,1,1,1};
    prod(arr,brr,2,3,3,2);
    return 0;
}
