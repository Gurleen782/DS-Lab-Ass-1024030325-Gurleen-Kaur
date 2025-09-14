#include <iostream>
#include <stack>
using namespace std;
void sort(int arr[], int N){
    for(int i=0; i<N-1; i++){
        for(int j=0; j<N-1-i; j++){
            if(arr[j] > arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
        }
    }
}
bool fun(int A[], int N) {
    int arr[N];
    for (int i = 0; i < N; i++){
        arr[i] = A[i];
    }
    sort(arr, N);  
    stack<int>s;
    int ind = 0;
    for (int i = 0; i < N; i++){
        s.push(A[i]);
        while (!s.empty() && s.top() == arr[ind]){
            s.pop();
            ind++;
        }
    }
    return (ind == N);
}
int main() {
    int N;
    cout << "Number of elements: ";
    cin >> N;
    int A[N];
    cout << "Enter elements: ";
    for(int i = 0; i < N; i++){
        cin >> A[i];
    }
    if(fun(A, N)) cout << "Possible to sort B in ascending order\n";
    else cout << "Not possible to sort B in ascending order\n";
    return 0;
}
