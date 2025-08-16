#include <iostream>
using namespace std;
int main() {
    int n=8;
    int arr[8]={1,2,3,3,4,4,5,6};
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;){
            if(arr[i]==arr[j]){
                for(int k=j;k<n-1;k++){
                    arr[k]=arr[k+1];
                }
                n--;
            }
            else j++;
        }
    }
    for(int i=0;i<n;i++){
            cout<<arr[i]<<" ";
    }
    return 0;
}