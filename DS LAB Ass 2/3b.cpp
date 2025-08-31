#include<iostream>
using namespace std;
int main(){
    int arr[6]={1,2,3,4,5,7};
    int s=0,e=5;
    int mid;
    while(s<=e){
        mid=s+(e-s)/2;
        if(arr[mid]==mid+1){
            s=mid+1;
        }
        else e=mid-1;
    }
    cout<<s+1;
    return 0;
}