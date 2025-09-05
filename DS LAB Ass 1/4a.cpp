#include <iostream>
using namespace std;
int main() {
    int n=5;
    int arr[5]={1,2,3,4,5};
    int s=0,e=n-1;
    while(s<e){
        swap(arr[s],arr[e]);
        s++;
        e--;
    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
