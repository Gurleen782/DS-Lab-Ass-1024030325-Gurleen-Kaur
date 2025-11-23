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
node* buildtree(node* root) {
    cout << "Enter data: ";
    int data;
    cin >> data;
    if (data == -1) return NULL;
    root = new node(data);
    cout << "Enter to insert on left of " << data << ": ";
    root->left = buildtree(root->left);
    cout << "Enter to insert on right of " << data << ": ";
    root->right = buildtree(root->right);
    return root;
}
int maxlvl = -1;
int ans[1000];   
int ind = 0;    
void solve(node* root, int lvl) {
    if (root == NULL) return;
    if (lvl > maxlvl) {
        ans[ind++] = root->data;
        maxlvl = lvl;
    }
    solve(root->right, lvl + 1);
    solve(root->left, lvl + 1);
}
int main() {
    node* root = NULL;
    root = buildtree(root);
    solve(root, 0);
    cout << "Right view of tree: ";
    for (int i = 0; i < ind; i++) {
        cout << ans[i] << " ";
    }
    return 0;
}
