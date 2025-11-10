#include<iostream>
using namespace std;
class node{
	public:
	node*left;
	node*right;
	int data;
	node(int data){
		this->left=NULL;
		this->right=NULL;
		this->data=data;
	}
};
node* insert(node*root,int d){
	if(root==NULL){
		root=new node(d);
		return root;
	}
	if(d<root->data){
		root->left=insert(root->left,d);
	}
	else if(d>root->data){
		root->right=insert(root->right,d);
	}
	else{
		cout<<"node with same data already present";
	}
	return root;
}
node*min(node*root){
	node*temp=root;
	while(temp!=NULL && temp->left!=NULL){
		temp=temp->left;
	}
	return temp;
}
node*deletee(node*root,int d){
	if(root==NULL) return root;
	if(d<root->data){
		root->left=deletee(root->left,d);
	}
	else if(d>root->data){
		root->right=deletee(root->right,d);
	}
	else{
		if(root->left==NULL){
			node*temp=root->right;
			delete root;
			return temp;
		}
		else if(root->right==NULL){
			node*temp=root->left;
			delete root;
			return temp;
		}
		node*t=min(root);
		root->data=t->data;
		root->right=deletee(root->right,t->data);
	}
	return root;
}
int maxd(node*root){
	if(root==NULL) return 0;
	int l=maxd(root->left);
	int r=maxd(root->right);
	return max(l,r)+1;
}
int mind(node*root){
	if(root==NULL) return 0;
	if(root->left==NULL && root->right==NULL) return 1;
	if(root->left==NULL) return 1 + mind(root->right);
	if(root->right==NULL) return 1 + mind(root->left);
	return 1 + min(mind(root->left),mind(root->right));
}
void inorder(node*root){
	if(root==NULL) return;
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}
int main(){
	node*root=NULL;
	root=insert(root,1);
	insert(root,2);
	insert(root,3);
	insert(root,8);
	insert(root,5);
	insert(root,9);
	insert(root,7);
	cout<<"inorder:";
	inorder(root);
	cout<<"\nEnter node to delete:";
	int n;
	cin>>n;
	cout<<"inorder after deletion:";
	root=deletee(root,n);
	inorder(root);
	cout<<"\nmax depth:"<<maxd(root);
	cout<<"\nmin depth:"<<mind(root);
}
