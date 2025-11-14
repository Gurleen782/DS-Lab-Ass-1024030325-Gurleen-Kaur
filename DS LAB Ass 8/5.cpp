#include<iostream>
using namespace std;
class heap{
    public:
    int arr[100];
    int size;
    heap(){
        arr[0]=-1;
        size=0;
    }
};
//max_heap
void max_heapify(int arr[],int n,int i){
    int largest=i;
    int left=2*i;
    int right=2*i+1;
    if(left<=n && arr[largest]<arr[left]) largest=left;
    if(right<=n && arr[largest]<arr[right]) largest=right;
    if(largest!=i){
        swap(arr[largest],arr[i]);
        max_heapify(arr,n,largest);
    }
}
void inc_heapsort(int arr[],int n){
    while(n>1){
        swap(arr[1],arr[n]);
        n--;
        max_heapify(arr,n,1);
    }
}
void min_heapify(int arr[],int n,int i){
    int smallest=i;
    int left=2*i;
    int right=2*i+1;
    if(left<=n && arr[smallest]>arr[left]) smallest=left;
    if(right<=n && arr[smallest]>arr[right]) smallest=right;
    if(smallest!=i){
        swap(arr[smallest],arr[i]);
        min_heapify(arr,n,smallest);
    }
}
void dec_heapsort(int arr[],int n){
    while(n>1){
        swap(arr[1],arr[n]);
        n--;
        min_heapify(arr,n,1);
    }
}
int main(){
    int arr[6]={-1,1,6,3,2,8};
    int n=5;
    int choice;
    cout<<"Enter 1 for increasing and 2 for decreasing: ";
    cin>>choice;
    if(choice==1){
        for(int i=n/2;i>=1;i--){
            max_heapify(arr,n,i);
        }
        cout<<"\nprinting array after converting to max_heap: ";
        for(int i=1;i<=n;i++){
            cout<<arr[i]<<" ";
        }
        inc_heapsort(arr,n);
        cout<<"\nprinting array after increasing heapsort: ";
        for(int i=1;i<=n;i++){
            cout<<arr[i]<<" ";
        }
    }
    else{
         for(int i=n/2;i>=1;i--){
            min_heapify(arr,n,i);
        }
        cout<<"\nprinting array after converting to min_heap: ";
        for(int i=1;i<=n;i++){
            cout<<arr[i]<<" ";
        }
        dec_heapsort(arr,n);
        cout<<"\nprinting array after decreasing heapsort: ";
        for(int i=1;i<=n;i++){
            cout<<arr[i]<<" ";
        }
    }
}
