#include <iostream>
using namespace std;
    int arr[10];
    int n;
void create(){
    cout<<"Enter num of elements ";
    cin>>n;
    cout<<"Enter elements ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
}
void insert(){
    int ind,k;
    cout<<"Enter index and element ";
    cin>>ind>>k;
    for(int i=n;i>ind;i--){
        arr[i]=arr[i-1];
    }
    arr[ind]=k;
    n++;
}
void dlt(){
    int ind;
    cout<<"Enter index to delete ";
    cin>>ind;
    for(int i=ind;i<n-1;i++){
        arr[i]=arr[i+1];
    }
    n--;
}
void linsearch(){
    int k;
    cout<<"Enter element to search ";
    cin>>k;
    bool check=false;
    for(int i=0;i<n;i++){
        if(arr[i]==k){
            cout<<"element found at index "<<i;  
            check=true;
        }
    }
    if(!check) cout<<"element not found";
}
void display(){
     cout<<"array : ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
void ext(){
    cout<<"program exited";
    exit(0);
}
int main() {
    while(1){
        cout<<endl<<"MENU "<<endl;
        cout<<"1.create\n2.display\n3.insert\n4.delete\n5.linear search\n6.exit\n";
        int f;
        cout<<"Enter a function ";
        cin>>f;
        switch(f){
            case(1): create(); break;
            case(2): display(); break;
            case(3): insert(); break;
            case(4): dlt(); break;
            case(5): linsearch(); break;    
            case(6): ext(); break;
            default: cout<<"invalid function";
        }
    }
    return 0;
}


