#include<iostream>
#define MAX 100001
using namespace std;
int Arr[MAX]={0};
void Factorial(int number);
void DisplayArray(int Arr[],int len);
void Multiply(int num,int &c);

/*Method for multiplying a big integer(stored in Arr) with the num.
Here c is the length of big integer.*/
void Multiply(int num,int &c)
{
	int x=0;
	int temp=Arr[0]*num;
	while(temp || x<=c)
	{
		Arr[x++]=temp%10;
		temp/=10;
		temp=(Arr[x]*num+temp);
	}
	c=x-1;
}

/*Display Arr in reverse order because factorial
of a number is stored in reverse order*/
void DisplayArray(int Arr[],int len)
{
	for(int i=len;i>=0;i--)
		cout<<Arr[i];
	cout<<endl;
}

//Method for calculating factorial of a number.
void Factorial(int number)
{
	Arr[0]=1;
	int c=0;
	for(int i=1;i<=number;i++)
		Multiply(i,c);
	DisplayArray(Arr,c);
}

int main()
{
	int num=100;
	Factorial(num);
	return 0;
}

