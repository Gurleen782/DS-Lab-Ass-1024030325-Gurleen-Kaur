#include <iostream>
#include <stack>
using namespace std;
void fun(int A[], int n, int brr[]) {
    stack<int>s;
    for (int i = 0; i< n; i++) {
        while(!s.empty() && s.top()>=A[i]) {
            s.pop();
        }
        if(s.empty()) brr[i]=-1;
        else{ brr[i] = s.top();}
        s.push(A[i]);
    }
}
int main() {
    int A[] = {2,3,6,9,7,8};
    int n = sizeof(A) / sizeof(A[0]);
    int brr[20];
    fun(A,n,brr);
    cout << "Nearest smaller num: ";
    for (int i = 0; i < n; ++i) {
        cout << brr[i] << " ";
    }
    return 0;
}
