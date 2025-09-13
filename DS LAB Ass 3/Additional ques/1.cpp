#include <iostream>
#include <stack>
using namespace std;
void fun(int arr[], int n, int brr[]) {
    stack<int>s;
    for (int i = 0; i< n; i++) {
        while(!s.empty() && s.top()>=arr[i]) {
            s.pop();
        }
        if(s.empty()) brr[i]=-1;
        else{ brr[i] = s.top();}
        s.push(arr[i]);
    }
}
int main() {
    int arr[] = {2,3,6,9,7,8};
    int n = sizeof(arr) / sizeof(arr[0]);
    int brr[20];
    fun(arr,n,brr);
    cout << "Nearest smaller num: ";
    for (int i = 0; i < n; ++i) {
        cout << brr[i] << " ";
    }
    return 0;
}
