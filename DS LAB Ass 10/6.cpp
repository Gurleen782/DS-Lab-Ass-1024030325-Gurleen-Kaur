#include <iostream>
#include <unordered_set>
using namespace std;
class node {
public:
    int data;
    node* left;
    node* right;
    node(int d) {
        data = d;
        left = right = NULL;
    }
};
node* buildtree (node* root) {
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
bool dup (node* root, unordered_set<int>& s) {
    if (root == NULL) return false;
    if (s.count(root->data) != 0) return true;
    s.insert(root->data);
    return dup(root->left, s) || dup(root->right, s);
}
int main () {
    node* root = NULL;
    root = buildtree(root);
    unordered_set<int> s;
    if (dup(root, s)) cout << "Duplicates Found";
    else cout << "No Duplicates";
    return 0;
}
