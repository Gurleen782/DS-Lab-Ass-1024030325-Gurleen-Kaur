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
bool rec_search(node*root,int d){
	if(root==NULL) return false;
	if(root->data==d) return true;
	else if(root->data > d) return rec_search(root->left,d);
	else return rec_search(root->right,d);
}
bool nonrec_search(node*root,int d){
	if(root==NULL) return false;
	node*temp=root;
	while(temp!=NULL){
		if(temp->data==d) return true;
		else if(temp->data > d) temp=temp->left;
		else temp=temp->right;
	}
	return false;
}
node*max(node*root){
	if(root==NULL) return NULL;
	node*temp=root;
	while(temp!=NULL && temp->right!=NULL){
		temp=temp->right;
	}
	return temp;
}
node*min(node*root){
	if(root==NULL) return NULL;
	node*temp=root;
	while(temp!=NULL && temp->left!=NULL){
		temp=temp->left;
	}
	return temp;
}
node*succ(node*root,int d){
	node*s=NULL;
	while(root!=NULL){
		if(d < root->data){
			s=root;
			root=root->left;
		}
		else if(d > root->data){
			root=root->right;
		}
		else{
			if(root->right!=NULL){
				node*temp=root->right;
				while(temp->left!=NULL){
					temp=temp->left;
				}
				return temp;
			}
			break;
		}
	}
	return s;
}
node*pred(node*root,int d){
	node*p=NULL;
	while(root!=NULL){
		if(d > root->data){
			p=root;
			root=root->right;
		}
		else if(d < root->data){
			root=root->left;
		}
		else{
			if(root->left!=NULL){
				node*temp=root->left;
				while(temp->right!=NULL){
					temp=temp->right;
				}
				return temp;
			}
			break;
		}
	}
	return p;
}
int main(){
	node* root=NULL;
	root=buildtree(root);
	cout<<"\ninorder:";
	inorder(root);
	cout<<"\n\n2(a)\n";
	int d;
	cout<<"enter node to search:";
	cin>>d;
	cout<<"recursive search:";
	if(rec_search(root,d)==true) cout<<"found\n";
	else cout<<"not found\n";
	cout<<"non recursive search:";
	if(nonrec_search(root,d)==true) cout<<"found\n";
	else cout<<"not found\n";
	cout<<"\n2(b)";
	node*m=max(root);
	if(m==NULL) cout<<"\nMaximum element of BST:-1";
	else cout<<"\nMaximum element of BST:"<<m->data;
	cout<<"\n\n2(c)";
	node*n=min(root);
	if(n==NULL) cout<<"\nMinimum element of BST:-1";
	else cout<<"\nMinimum element of BST:"<<n->data;
	cout<<"\n\n2(d)";
	int s;
	cout<<"\nenter node whose successor has to be found:";
	cin>>s;
	cout<<"successor of "<<s<<":";
	node*successor=succ(root,s);
	if(successor==NULL) cout<<"no successor\n";
	else cout<<successor->data;
	cout<<"\n\n2(e)";
	int p;
	cout<<"\nenter node whose predecessor has to be found:";
	cin>>p;
	cout<<"predecessor of "<<p<<":";
	node*predecessor=pred(root,p);
	if(predecessor==NULL) cout<<"no predecessor\n";
	else cout<<predecessor->data;
}
