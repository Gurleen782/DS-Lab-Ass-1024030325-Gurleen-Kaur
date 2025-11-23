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
int findind(int inorder[], int start, int end, int key) {
    for (int i = start; i <= end; i++) {
        if (inorder[i] == key) return i;
    }
    return -1;
}
node* buildtree(int preorder[], int inorder[], int start, int end, int &ind) {
    if (start > end) return NULL;
    int d = preorder[ind];
    node* root = new node(d);
    ind++;
    if (start == end) return root;  
    int pos = findind(inorder, start, end, root->data);
    root->left  = buildtree(preorder, inorder, start, pos - 1, ind);
    root->right = buildtree(preorder, inorder, pos + 1, end, ind);
    return root;
}
void inorder(node* root) {
    if (root == NULL) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
int main() {
    int n;
    cout << "Enter number of nodes: ";
    cin >> n;
    int preorderarr[100], inorderarr[100];
    cout << "Enter preorder: ";
    for (int i = 0; i < n; i++){
        cin >> preorderarr[i];
    } 
    cout << "Enter inorder: ";
    for (int i = 0; i < n; i++){
        cin >> inorderarr[i];
    } 
    int ind = 0;
    node* root = buildtree(preorderarr, inorderarr, 0, n - 1, ind);
    cout << "Result tree: ";
    inorder(root);
}
