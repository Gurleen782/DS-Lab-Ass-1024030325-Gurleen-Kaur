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
node* buildtree(int postorder[], int inorder[], int start, int end, int &ind) {
    if (start > end) return NULL;
    int d = postorder[ind];     
    node* root = new node(d);
    ind--;                     
    if (start == end) return root;
    int pos = findind(inorder, start, end, root->data);
    root->right = buildtree(postorder, inorder, pos + 1, end, ind);
    root->left  = buildtree(postorder, inorder, start, pos - 1, ind);
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
    int postorderarr[100], inorderarr[100];
    cout << "Enter postorder: ";
    for (int i = 0; i < n; i++){
        cin >> postorderarr[i];
    }
    cout << "Enter inorder: ";
    for (int i = 0; i < n; i++){
        cin >> inorderarr[i];
    }
    int ind = n - 1; 
    node* root = buildtree(postorderarr, inorderarr, 0, n - 1, ind);
    cout << "Result tree: ";
    inorder(root);
    return 0;
}
