#include<iostream>
using namespace std;
class node{
	public:
		int data;
		node*left;
		node*right;
		node(int data){
			this->data=data;
			this->left=NULL;
			this->right=NULL;
		}
};
node*buildtree(node*root){
	cout<<"Enter num: ";
	int num;
	cin>>num;
	if(num==-1) return NULL;
	root=new node(num);
	cout<<"enter to insert on left of "<<num<<":";
	root->left=buildtree(root->left);
	cout<<"enter to insert on right of "<<num<<":";
	root->right=buildtree(root->right);
	return root;
}
void inorder(node*root){
	if(root==NULL) return;
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}
void preorder(node*root){
	if(root==NULL) return;
	cout<<root->data<<" ";
	preorder(root->left);
	preorder(root->right);
}
void postorder(node*root){
	if(root==NULL) return;
	postorder(root->left);
	postorder(root->right);
	cout<<root->data<<" ";
}
int main(){
	node* root=NULL;
	root=buildtree(root);
	cout<<"\ninorder:";
	inorder(root);
	cout<<"\npreorder:";
	preorder(root);
	cout<<"\npostorder:";
	postorder(root);
}
