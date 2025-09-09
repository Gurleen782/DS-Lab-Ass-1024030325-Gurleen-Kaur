#include <iostream>
using namespace std;
void sort(int arr[],int n){
    int a=0,b=n-1,mid=0;
    while(mid<=b){
        if(arr[mid]==0){
            swap(arr[a],arr[mid]);
            a++;
            mid++;
        }
        else if(arr[mid]==1) mid++;
        else{
            swap(arr[mid],arr[b]);
            b--;
        }
    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
int main() {
    int arr[]={0,1,2,0,1,2};
    int n=sizeof(arr)/sizeof(arr[0]);
    sort(arr,n);
    return 0;
}
