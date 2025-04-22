#include <iostream>
#include <string>
#include<stdio.h>
using namespace std;
int randowmnumber(int from, int to)
{
	int randoim = rand() % (to - from + 1) + from;
	return randoim;
}
void Generatematrix(int maix[3][3])
{
	for (int i = 0;i < 3; i++)
	{
		for (int j = 0;j < 3;j++)
		{
			maix[i][j] =randowmnumber(1, 99);
		}
	}
}
void printmatrix(int maix[3][3])
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0;j < 3;j++)
		{
			printf("%*0d  ", 2, maix[i][j]);
		}
		cout << endl;
	}
}
int main()
{
	int maix[3][3];
	Generatematrix(maix);
	printmatrix(maix);
	return 0;
}