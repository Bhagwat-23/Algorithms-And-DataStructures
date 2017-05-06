/*Level Order traversal in Spiral form or zig-zag fashion*/
#include<iostream>
#include<malloc.h>
#define MAX 1001
using namespace std;

struct Tree 
{
	int data;
	struct Tree *left;
	struct Tree *right;
};

class Queue
{

private:
	int front,rear;
	struct Tree *Q[MAX];
public:
	Queue(void)
	{
		front=rear=-1;
	}
	bool IsEmptyQueue()
	{
		if(front>rear || front==-1)
			return true;
		return false;
	}
	void Enqueue(struct Tree *node)
	{
		if(rear==-1)
		{
			front=rear=0;
			Q[rear]=node;
		}
		else
		{
			Q[++rear]=node;
		}
	}
	struct Tree *DequeueFront()
	{
		struct Tree *node=NULL;
		if(!IsEmptyQueue())
		{
			node=Q[front++];
		}
		return node;
	}
	struct Tree *DequeueEnd()
	{
		struct Tree *node=NULL;
		if(!IsEmptyQueue())
		{
			node=Q[rear--];
		}
		return node;
	}

	int QueueSize()
	{
		int c=0;
		if(!IsEmptyQueue())
		{
			c=rear-front+1;
		}
		return c;
	}
};


struct Tree *addNewNode(int data)
{
	struct Tree *temp=(struct Tree*)malloc(sizeof(struct Tree));
	temp->data=data;
	temp->left=temp->right=NULL;
	return temp;
}
void PrintSpiralTree(struct Tree *root)
{
	struct Tree *temp=NULL;
	Queue q1;
	Queue q2;
	q1.Enqueue(root);
	int flag=true;
	while(true)
	{
		if(q1.IsEmptyQueue() && q2.IsEmptyQueue())
			break;

		while(q1.QueueSize()>0)
		{
			temp=q1.DequeueEnd();
			cout<<temp->data<<" ";
			if(temp->left!=NULL)	q2.Enqueue(temp->left);
			if(temp->right!=NULL)	q2.Enqueue(temp->right);
		}
		while(q2.QueueSize()>0)
		{
			temp=q2.DequeueEnd();
			cout<<temp->data<<" ";
			if(temp->right!=NULL)	q1.Enqueue(temp->right);
			if(temp->left!=NULL) q1.Enqueue(temp->left);
		}
	}
}
void InOrderTraversal(struct Tree *root)
{
	if(root==NULL)
		return ;
	InOrderTraversal(root->left);
	cout<<root->data<<" ";
	InOrderTraversal(root->right);
}

int main()
{
	struct Tree *root=addNewNode(1);
	root->left=addNewNode(2);
	root->right=addNewNode(3);
	root->left->left=addNewNode(4);
	root->left->right=addNewNode(5);
	root->right->left=addNewNode(6);
	root->right->right=addNewNode(7);
	root->left->left->left=addNewNode(8);
	root->left->left->right=addNewNode(9);
	root->left->right->left=addNewNode(10);
	root->left->right->right=addNewNode(11);
	root->right->left->left=addNewNode(12);
	root->right->left->right=addNewNode(13);
	root->right->right->left=addNewNode(14);
	root->right->right->right=addNewNode(15);
	root->left->left->right->left=addNewNode(16);
	root->left->left->right->right=addNewNode(17);
	root->right->right->left->left=addNewNode(18);
	root->right->right->left->right=addNewNode(19);
	cout<<"InOrder Traversal: ";
	InOrderTraversal(root);
	cout<<endl<<"Spril Tree Traversal: ";
	PrintSpiralTree(root);
	return 0;
}