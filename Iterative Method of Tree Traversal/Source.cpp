#include<iostream>
#include<malloc.h>
#include<stack>
#define MAX 1001
using namespace std;
template<class T>

//Generic Stack which can be operated with any data types.
class Stack
{
private:
	int top;
	T S[MAX];
public:
	Stack()
	{
			top=-1;
	}
	void Push(T item)
	{
		if(top!=MAX)
		{
			S[++top]=item;
		}
	}
	T Pop()
	{
		T item=NULL;
		if(!isEmply())
		{
			item = S[top--];
		}
		return item;
	}
	T Peek()
	{
		T item=NULL;
		if(!isEmply())
		{
			item = S[top];
		}
		return item;
	}
	bool isEmply()
	{
		if(top>-1)
			return false;
		return true;
	}
};
struct Tree 
{
	int data;
	struct Tree *left;
	struct Tree *right;
};
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
void PreOrder(struct Tree *root)
{
	if(root==NULL)return;
	cout<<root->data<<" ";
	PreOrder(root->left);
	PreOrder(root->right);
}
void PostOrder(struct Tree *root)
{
	if(root==NULL)return;
	PostOrder(root->left);
	PostOrder(root->right);
	cout<<root->data<<" ";
}

//Iterative method of PreOrder traversal.
void PreOrderIterativeTraversal(struct Tree *root)
{
	//If root is null , that means Tree has no nodes.
	if(root==NULL)
		return;
	bool isCompleted = false;
	Stack<struct Tree *> S;
	struct Tree *temp = root;
	//Push the root node of tree.
	S.Push(temp); 
	while(!isCompleted)
	{
		if(S.isEmply()==true)
		{
			isCompleted=true;
		}
		else
		{
			//Process the popped node.
			temp = S.Pop();
			cout<<temp->data<<" ";
			//Push the right child if any.
			if(temp->right!=NULL)
				S.Push(temp->right);
			//Push the left child if any.
			if(temp->left!=NULL)
				S.Push(temp->left);
		}
	}
}

//Iterative method of Inorder traversal.
void InOrderIterativeTraversal(struct Tree *root)
{
	//If root is null , that means Tree has no nodes.
	if(root==NULL)
		return;
	bool isCompleted = false;
	Stack<struct Tree *> S;
	struct Tree *temp = root;
	while(!isCompleted)
	{
		//Push all the left childrens in the stack
		if(temp!=NULL)
		{
			S.Push(temp);
			temp=temp->left;
		}
		else
		{
			if(S.isEmply()==true)
			{
				isCompleted=true;
			}
			else
			{
				temp = S.Pop();
				//Process the popped node.
				cout<<temp->data<<" ";
				//If Tree node has any right chilren(s) then Push it into the stack.
				temp=temp->right;
			}
		}
	}
}
void PostOrderIterativeTraversal(struct Tree *root)
{
	//If root is null , that means Tree has no nodes.
	if(root==NULL)
		return;
	bool isCompleted = false;
	Stack<struct Tree *> S;
	struct Tree *temp = root;
	struct Tree *curr=NULL;
	while(!isCompleted)
	{
		//Push the Tree right child and then root in the stack.
		while (temp)
		{
			if(temp->right)
				S.Push(temp->right);
			S.Push(temp);
			temp=temp->left;
		}
		if(S.isEmply()==true)
			isCompleted=true;
		else
		{
			//If Tree has any right child , which is not yet processed , 
			//Then push the right child into the stack.
			temp=S.Pop();
			curr=S.Peek();
			if(temp->right && curr==temp->right)
			{
				S.Pop();
				S.Push(temp);
				temp=curr;
			}
			else
			{
				cout<<temp->data<<" ";
				temp=NULL;
			}
		}
	}
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
	cout<<"PreOrder Traversal: ";
	//PreOrder(root);
	PreOrderIterativeTraversal(root);
	cout<<endl;
	cout<<"Inorder Traversal: ";
	//InOrder(root);
	InOrderIterativeTraversal(root);
	cout<<endl;
	cout<<"PostOrder Traversal: ";
	//PostOrder(root);
	PostOrderIterativeTraversal(root);
	return 0;
}