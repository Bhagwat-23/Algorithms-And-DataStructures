#include<iostream>
#define MAX 6
using namespace std;
void ReplaceSurrounded(char Mat[][MAX], int N);
void ReplaceObyM(char Mat[][MAX], int N);
void FillAjacentBoundaryM(char Mat[][MAX], int i, int j, int N);
void ReplaceMbyX(char Mat[][MAX], int N);
void PrintArray(char Mat[][MAX], int N);
bool IsSafe(int i, int j, int N);

void PrintArray(char Mat[][MAX], int N)
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			printf_s("%c ", Mat[i][j]);
		printf_s("\n");
	}
}
void ReplaceObyM(char Mat[][MAX], int N)
{
	int i, j;
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			if (Mat[i][j] == 'O')
				Mat[i][j] = 'M';
		}
	}
}
bool IsSafe(int i, int j, int N)
{
	if (i < 0 || i>N - 1 || j<0 || j>N - 1)
		return false;
	return true;
}
void FillAjacentBoundaryM(char Mat[][MAX], int i, int j, int N)
{
	if (!IsSafe(i, j, N))
		return;
	if (Mat[i][j] != 'M')
		return;
	if (Mat[i][j] == 'M')
		Mat[i][j] = 'O';
	FillAjacentBoundaryM(Mat, i + 1, j, N);
	FillAjacentBoundaryM(Mat, i - 1, j, N);
	FillAjacentBoundaryM(Mat, i, j + 1, N);
	FillAjacentBoundaryM(Mat, i, j - 1, N);
}
void ReplaceSurrounded(char Mat[][MAX], int N)
{
	int i, j;
	ReplaceObyM(Mat, N);
	for (i = 0; i < N; i++)
	{
		if (Mat[0][i] == 'M')
			FillAjacentBoundaryM(Mat, 0, i, N);
		if (Mat[N - 1][i] == 'M')
			FillAjacentBoundaryM(Mat, N - 1, i, N);
		if (Mat[i][0] == 'M')
			FillAjacentBoundaryM(Mat, i, 0, N);
		if (Mat[N - 1][i] == 'M')
			FillAjacentBoundaryM(Mat, N - 1, 0, N);
	}
}
void ReplaceMbyX(char Mat[][MAX], int N)
{
	for (int i = 0; i < N;i++)
	for (int j = 0; j < N;j++)
	if (Mat[i][j] == 'M')
		Mat[i][j] = 'X';
}
int main()
{
	char Mat[][MAX] = {	{ 'X', 'O', 'X', 'O', 'X', 'X' },
						{ 'X', 'O', 'X', 'X', 'O', 'X' },
						{ 'X', 'X', 'X', 'O', 'X', 'X' },
						{ 'O', 'X', 'X', 'X', 'X', 'X' },
						{ 'X', 'X', 'X', 'O', 'X', 'O' },
						{ 'O', 'O', 'X', 'O', 'O', 'O' },
	};

	ReplaceSurrounded(Mat, 6);
	ReplaceMbyX(Mat, 6);
	PrintArray(Mat, 6);
	return 0;
}