#include<iostream>
using namespace std;
int main(){
    int a[9]={1,2,4,3,5,7,6,9,8};
    int n=9;
    int count=0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(a[i]>a[j]) count++;
        }
    }
    cout<<"Num of inversions: "<<count;
    return 0;
}