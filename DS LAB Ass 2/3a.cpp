#include<iostream>
using namespace std;
int main(){
    int arr[6]={1,2,4,5,6,7};
    for(int i=0;i<5;){
        if(arr[i+1]==arr[i]+1){
            i++;
        }
        else{
            cout<<arr[i]+1;
            break;
        }
    }
    return 0;
}