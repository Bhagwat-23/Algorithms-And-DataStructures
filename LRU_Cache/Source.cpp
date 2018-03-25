#include<iostream>
#include<cstdio>
using namespace std;
#define MAX 100
class Queue
{
private:
	int front,rear;
	int Q[MAX];
public:
	void InitializeQueue()
	{
		front=rear=-1;
	}
	bool IsQueueEmpty()
	{
		if(front==-1 || front>rear)
			return true;
		return false;
	}
	void Enqueue(int data)
	{
		if(IsQueueEmpty())
		{
			front=rear=0;
			Q[rear]=data;
		}
		else
		{
			Q[++rear]=data;
		}
	}

	int Dequeue()
	{
		int data;
		if(!IsQueueEmpty())
		{
			data=Q[front++];
		}
		return data;
	}
	int QueueSize()
	{
		if(front==-1 || front>rear)
			return 0;
		return (rear-front+1);
	}
	void PrintQueueData()
	{
		for(int i=front;i<=rear;i++)
			cout<<Q[i]<<" ";
		cout<<endl;
	}
};
struct Frame
{
	int fSize;
	bool Hash[MAX];
	int refPage[MAX];
	char pageType[MAX];
};
void ReferencePage(int page,Queue &q,struct Frame &frame,int &pSize,char &pType)
{
	// If Page Frame is empty..
	if(frame.fSize<pSize)
	{
		q.Enqueue(page);
		frame.Hash[page]=true;
		frame.fSize++;
		pType='F';
	}
	else
	{
		//Request page may present in cache.
		if(frame.Hash[page]==true)
		{
			// Page Hit...
			pType='H';
		}
		else
		{
			//Page Fault...
			if(frame.fSize==pSize)
			{
				int removePage = q.Dequeue();
				frame.Hash[removePage]=false;

				frame.Hash[page]=true;
				q.Enqueue(page);
				pType='F';
			}
		}
	}
}

int main()
{
	//int refPage[]={7, 5, 9, 4, 3, 7, 9, 6, 2, 1};
	//int refPage[]={1,2,3,1,4,5};
	int refPage[]={5,0,1,2,0,3,1,2,5,2};
	Frame frame;
	frame.fSize=0;
	char pType;
	memset(frame.Hash,false,sizeof(frame.Hash));
	int size = sizeof(refPage)/sizeof(refPage[0]);
	int pSize=4;
	Queue q;
	q.InitializeQueue();
	for(int i=0;i<size;i++)
	{
		frame.refPage[i]=refPage[i];
		ReferencePage(refPage[i],q,frame,pSize,pType);
		frame.pageType[i]=pType;
	}

	q.PrintQueueData();
	cout<<endl;
	for(int i=0;i<size;i++)
	{
		cout<<frame.refPage[i]<<"  "<<frame.pageType[i]<<endl;
	}
	return 0;
}