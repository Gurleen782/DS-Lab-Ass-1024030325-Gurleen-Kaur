#include<iostream>
using namespace std;
int main(){
    char a[10]="hello";
    int k;
    for(k=0;k<10;k++){
    if(a[k]=='\0') break;
    }
    int size=k;
    int i=0;
    while(a[i]!='\0'){
        if(a[i]=='a'||a[i]=='e'||a[i]=='i'||a[i]=='o'||a[i]=='u'){
            for(int j=i;j<size-1;j++){
                a[j]=a[j+1];
            }
            size--;
            a[size]='\0';
        }
        else i++; 
    }
    cout<<a; 
}