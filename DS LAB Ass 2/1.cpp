#include<iostream>
using namespace std;
void binarysearch(int arr[],int n,int k){
    int s=0,e=n-1;
    while(s<=e){
        int mid=s+(e-s)/2;
        if(arr[mid]==k){
            cout<<"found at index "<<mid;
            return;
        }
        else if(arr[mid]<k) s=mid+1;
        else e=mid-1;
    }
    cout<<"not found";
}
int main(){
    int arr[7]={1,5,8,12,15,20,21};
    int k;
    cout<<"Enter element to search: ";
    cin>>k;
    binarysearch(arr,7,k);
    return 0;
}