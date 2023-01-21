#include<iostream>
#include <bits/stdc++.h>
using namespace std;

class node{
	public:
		int data;
		node*left;
		node*right;
		
		node(int d){
			this->data=d;
			this->left=NULL;
			this->right=NULL;
		}
};
void preoder(node*root){
			if(root==NULL){
				return;
			}
			cout<<"->"<<root->data<<" ";
			preoder(root->left);
			preoder(root->right);
		}
void inorder(node*root){
	if(root==NULL){
		return;
	}
	inorder(root->left);
	cout<<"->"<<root->data<<" ";
	inorder(root->right);
}
void postorder(node*root){
	if(root==NULL){
		return;
	}
	postorder(root->left);
	postorder(root->right);
	cout<<"->"<<root->data<<" ";
}
void Search(node *root, int data)
{
	
	node *temp=root;
	
	while(temp != NULL)
	{
		
		if(temp->data == data)
		{
			cout<<"\nData found : "<<data;
			return;
		}
		
		else if(temp->data > data)
			temp = temp->left
		
		else
			temp = temp->right;
	}
 
	cout<<"\n Data not found";
	return;
}
node * deletenode(node*root,int key){
	if(key<root->data){
		root->left=deletenode(root->left,key);
	}
	else if(key>root->data){
		root->right=deletenode(root->right,key);
		
	}
	else{
		if(root->left==NULL){
			node*temp=root->right;
			free(root);
			return temp;
		}
		else if(root->right==NULL){
				node*temp=root->left;
				free(root);
				return temp;
		}
	}
}

int main(){
	 node*root=new node(1);
	 root->left=new node(2);
	 root->right=new node(3);
	 root->left->left=new node(4);
	 root->right->right=new node(5);
	 
	 cout<<"Preorder traversal Tree is "<<endl;
	 preoder(root);
	 cout<<endl;
	 
//	 cout<<"inorder traversal Tree is "<<endl;
	// inorder(root);
	// cout<<endl;
	 
	// cout<<"postorder traversal Tree is "<<endl;
	// postorder(root);
	// cout<<endl;
	 
	 
	 Search(root,5);
	 cout<<endl;
	 deletenode(root,5);
	preoder(root);
}