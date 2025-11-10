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
int summ(node*root){
	if(root==NULL) return 0;
	int sum=0;
	if(root->left && root->left->left==NULL && root->left->right==NULL){
        sum+=root->left->data;
    }
	sum+=summ(root->left);
	sum+=summ(root->right);
	return sum;
} 
int main(){
	node* root=NULL;
	root=buildtree(root);
	cout<<"\ninorder:";
	inorder(root);
	cout<<"\nsum of left leaf nodes:"<<summ(root);
}
