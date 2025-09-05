#include <iostream>
using namespace std;
int main(){
    int n=4,m=3;
    int arr[4][3]={1,2,3,4,5,6,7,8,9,1,2,3};
    int brr[m][n];
    for(int i=0;i<n;i++){
         for(int j=0;j<m;j++){
             brr[j][i]=arr[i][j];
         }
    }
    for(int i=0;i<m;i++){
         for(int j=0;j<n;j++){
             cout<<brr[i][j]<<" ";
         }
         cout<<endl;
    }
    return 0;
}


