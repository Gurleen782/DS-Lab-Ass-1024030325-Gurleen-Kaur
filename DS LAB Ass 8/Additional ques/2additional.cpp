#include<iostream>
#include<queue>
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
class tree {
public:
    node* arr[1000];
    int size;
    tree() {
        size = 0;
    }
};
tree solve(int start, int end) {
    tree res;
    if(start > end) {
        res.arr[res.size++] = NULL;
        return res;
    }
    for(int r = start; r <= end; r++) {
        tree lefttree  = solve(start, r - 1);
        tree righttree = solve(r + 1, end);
        for(int i = 0; i < lefttree.size; i++) {
            for(int j = 0; j < righttree.size; j++) {
                node* root = new node(r);
                root->left  = lefttree.arr[i];
                root->right = righttree.arr[j];
                res.arr[res.size++] = root;
            }
        }
    }
    return res;
}
void print(node* root) {
    if(root == NULL){
        cout << "NULL";
        return;
    }
    queue<node*> q;
    q.push(root);
    node* arr[1000];
    int ind = 0;
    while(!q.empty()) {
        node* temp = q.front();
        q.pop();
        arr[ind++] = temp;
        if(temp != NULL){
            q.push(temp->left);
            q.push(temp->right);
        }
    }
    int last = ind - 1;
    while(last >= 0 && arr[last] == NULL){
        last--;
    }
    for(int i = 0; i <= last; i++){
        if(arr[i] == NULL) cout << "NULL ";
        else cout << arr[i]->data << " ";
    }
}
int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;
    tree numtrees = solve(1, n);
    cout << "Num of BSTs: " << numtrees.size << "\n";
    for(int i = 0; i < numtrees.size; i++) {
        print(numtrees.arr[i]);
        cout << endl;
    }
    return 0;
}
