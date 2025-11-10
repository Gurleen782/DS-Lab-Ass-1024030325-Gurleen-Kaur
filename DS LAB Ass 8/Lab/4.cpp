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
bool isbst(node*root,node*&temp){
	if(root==NULL) return true;
	if(isbst(root->left,temp)==false) return false;
	if(temp!=NULL && root->data<=temp->data) return false;
	temp=root;
	return isbst(root->right,temp);
}
bool isBST(node*root){
	node*temp=NULL;
	return isbst(root,temp);
}
void inorder(node*root){
	if(root==NULL) return;
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}
int main(){
	node* root=NULL;
	root=buildtree(root);
	cout<<"\ninorder:";
	inorder(root);
	if(isBST(root)==true) cout<<"\nit is a bst";
	else cout<<"\nit is not a bst";
}
