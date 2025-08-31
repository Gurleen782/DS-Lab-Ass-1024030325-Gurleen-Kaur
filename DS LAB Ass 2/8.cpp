#include<iostream>
using namespace std;
int main(){
    int arr[8]={1,9,2,5,5,7,7,8};
    int n=8;
    int count=0;
    for(int i=0;i<n;i++){
        bool flag=0;
        for(int j=0;j<i;j++){
            if(arr[i]==arr[j]){
                flag=1;
                break;
            }
        }
        if(!flag)  count++;
    }
    cout<<count;
    return 0;
}