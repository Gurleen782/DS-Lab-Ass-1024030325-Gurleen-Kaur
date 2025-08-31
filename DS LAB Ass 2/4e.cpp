#include<iostream>
using namespace std;
int main(){
    char a[10]="HEllo";
    int i;
    for(i=0;i<10;i++){
        if(a[i]=='\0') break;
    }
    int size=i;
    for(int i=0;i<size;){
        if(a[i]>='a'&& a[i]<='z')  i++;
        else{
            a[i]=a[i]-'A'+'a'; 
            i++;
        }    
    }
    cout<<a; 
}