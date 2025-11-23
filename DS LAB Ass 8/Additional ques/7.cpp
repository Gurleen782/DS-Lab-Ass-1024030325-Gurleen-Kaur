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
node* insertBST(node* root, int data) {
    node* n = new node(data);
    if (root == NULL) return n;
    if (data < root->data)  root->left = insertBST(root->left, data);
    else  root->right = insertBST(root->right, data);
    return root;
}
void bsttodll(node* root, node* &head, node* &prev) {
    if (root == NULL) return;
    bsttodll(root->left, head, prev);
    if (prev == NULL)  head = root;  
    else {
        prev->right = root;
        root->left = prev;
    }
    prev = root;
    bsttodll(root->right, head, prev);
}
node* merge(node* h1, node* h2) {
    node* head = NULL;
    node* tail = NULL;
    while (h1 != NULL && h2 != NULL) {
        node* temp;
        if (h1->data < h2->data) {
            temp = h1;
            h1 = h1->right;
        } 
        else {
            temp = h2;
            h2 = h2->right;
        }
        if (head == NULL) {
            head = temp;
            tail = temp;
        } 
        else {
            tail->right = temp;
            temp->left = tail;
            tail = temp;
        }
    }
    while (h1 != NULL) {
        tail->right = h1;
        h1->left = tail;
        tail = h1;
        h1 = h1->right;
    }
    while (h2 != NULL) {
        tail->right = h2;
        h2->left = tail;
        tail = h2;
        h2 = h2->right;
    }
    return head;
}
void print(node* head) {
    while (head != NULL) {
        cout << head->data << " <-> ";
        head = head->right;
    }
    cout << "NULL";
}
int main() {
    int n1, n2, x;
    cin >> n1;
    node* root1 = NULL;
    for (int i = 0; i < n1; i++) {
        cin >> x;
        root1 = insertBST(root1, x);
    }
    cin >> n2;
    node* root2 = NULL;
    for (int i = 0; i < n2; i++) {
        cin >> x;
        root2 = insertBST(root2, x);
    }
    node* head1 = NULL;
    node* prev1 = NULL;
    bsttodll(root1, head1, prev1);
    node* head2 = NULL;
    node* prev2 = NULL;
    bsttodll(root2, head2, prev2);
    node* ans = merge(head1, head2);
    print(ans);
    return 0;
}
