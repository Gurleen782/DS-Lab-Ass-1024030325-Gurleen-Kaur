#include<iostream>
using namespace std;
int size(char a[],int n){
    int i;
    for(i=0;i<n;i++){
       if(a[i]=='\0') break; 
    }
    return i;
}
int main(){
    char a[20]="hello ";
    char b[10]="world";
    int i=size(a,20);
    for(int j=0;j<size(b,10);j++){
        a[i]=b[j];
        i++;
    }
    a[i]='\0';
    cout<<a;
}