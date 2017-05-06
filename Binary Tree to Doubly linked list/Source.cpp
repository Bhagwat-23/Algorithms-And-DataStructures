/*Convert from binary tree to doubly linked list*/

#include<iostream>
#include<malloc.h>
using namespace std;

struct Tree 
{
	int data;
	struct Tree *left;
	struct Tree *right;
};
struct Tree *ConvertToDll(struct Tree *root);
struct Tree *ConvertToDllHelper(struct Tree *root);
struct Tree *addNodes(int data)
{
	struct Tree *node = (struct Tree*)malloc(sizeof(struct Tree));
	node->data=data;
	node->left=node->right=NULL;
	return node;
}
void InOrder(struct Tree *root)
{
	if(root==NULL)return;
	InOrder(root->left);
	cout<<root->data<<" ";
	InOrder(root->right);
}

struct Tree *FindInOrderSucc(struct Tree *root)
{
	if(root==NULL)
		return NULL;
	while(root->left)
		root=root->left;
	return root;
}
struct Tree *FindInorderPred(struct Tree *root)
{
	if(root==NULL)
		return NULL;
	while(root->right)
		root=root->right;
	return root;
}

struct Tree *ConvertToDllHelper(struct Tree *root)
{
	if(root==NULL)
		return NULL;
	ConvertToDllHelper(root->left);
	ConvertToDllHelper(root->right);
	
	struct Tree* succ=NULL,*pred=NULL;
	succ=FindInOrderSucc(root->right);//Succ
	pred=FindInorderPred(root->left);//Pred
	if(root->right && succ)
	{
		root->right=succ;
		succ->left=root;
	}
	if(root->left && pred)
	{
		root->left=pred;
		pred->right=root;
	}
	
	return root;
}
struct Tree* ConvertToDll(struct Tree *root)
{
	if(root==NULL)
		return root;
	root=ConvertToDllHelper(root);
	while(root->left)
		root=root->left;
	return root;
}
void PrintList(struct Tree *root)
{
	struct Tree *temp=root;
	while(temp!=NULL)
	{
		cout<<temp->data<<" ";
		temp=temp->right;
	}
	cout<<endl;
}
int main()
{
	struct Tree *root=addNodes(1);
	root->left=addNodes(2);
	root->right=addNodes(3);
	root->left->left=addNodes(4);
	root->left->right=addNodes(5);
	root->right->left=addNodes(6);
	root->right->right=addNodes(7);
	root->right->left->left=addNodes(8);
	root->right->left->right=addNodes(9);
	
	cout<<"Inorder Traversal: ";
	InOrder(root);
	root=ConvertToDll(root);

	cout<<endl<<"DLL List: ";
	PrintList(root);
	return 0;
}