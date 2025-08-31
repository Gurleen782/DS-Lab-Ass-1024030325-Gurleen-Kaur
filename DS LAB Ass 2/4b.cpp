#include<iostream>
using namespace std;
int main(){
   char a[10]="neelrug";
   int i;
   for(i=0;i<10;i++){
    if(a[i]=='\0') break;
   }
   int size=i; 
   int s=0,e=size-1;
   while(s<e){
    swap(a[s],a[e]);
    s++;
    e--;
   }
   cout<<a;
}