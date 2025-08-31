#include<iostream>
using namespace std;
int main(){
    char a[10]="gurleen";
    int i;
    for(i=0;i<10;i++){
    if(a[i]=='\0') break;
    }
    int size=i;
    for(int i=0;i<size-1;i++){
        for(int j=0;j<size-i-1;j++){
            if(a[j]>a[j+1]){
                swap(a[j],a[j+1]);
            }
        }
    }
    cout<<a;
}