#include <iostream>
using namespace std;
int main() {
    int arr[2][3]={1,2,3,4,5,6};
    int r=2,c=3;
    int rsum,csum;
    for(int i=0;i<r;i++){
        rsum=0;
        for(int j=0;j<c;j++){
            rsum+=arr[i][j];
        }
        cout<<i+1<<"th row sum:"<<rsum<<endl;
    }
    cout<<endl;
    for(int i=0;i<c;i++){
        csum=0;
        for(int j=0;j<r;j++){
            csum+=arr[j][i];
        }
        cout<<i+1<<"th col sum:"<<csum<<endl;
    }
    return 0;
}
