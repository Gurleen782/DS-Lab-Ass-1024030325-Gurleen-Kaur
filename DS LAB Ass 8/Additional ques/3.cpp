#include<iostream>
using namespace std;
class node {
public:
    int data;
    node* left;
    node* right;
    node(int d) {
        data = d;
        left = NULL;
        right = NULL;
    }
};
node* buildtree(int arr[], int n, int ind) {
    if (ind >= n || arr[ind] == -1)  return NULL;
    int leftind = 2 * ind + 1;
    int rightind = 2 * ind + 2;
    node* root = new node(arr[ind]);
    root->left  = buildtree(arr, n, leftind);
    root->right = buildtree(arr, n, rightind);
    return root;
}
int maxdep(node* root) {
    if (root == NULL) return 0;
    int l = maxdep(root->left);
    int r = maxdep(root->right);
    return max(l, r) + 1;
}
int main() {
    int n;
    cin >> n;     
    int arr[1000];   
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    node* root = buildtree(arr, n, 0);
    cout << maxdep(root);
    return 0;
}
