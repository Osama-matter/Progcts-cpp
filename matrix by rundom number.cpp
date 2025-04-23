#include <iostream>
#include <string>
#include<stdio.h>
using namespace std;
int randomnumber(int from, int to)
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
			maix[i][j] =randomnumber(1, 9);
		}
	}
}
void printmatrix(int maix[3][3], int clo , int row   )
{
	
	for (int i = 0; i < clo; i++)
	{
		for (int j = 0;j < row;j++)
		{
			printf("%*0d  ", 2, maix[i][j]);
		}
		cout << endl;
	}
	cout << "------------------------\n\n";
}
int clasumofmatrix(int maix[3][3])
{
	int sum = 0 ; 
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0;j < 3;j++)
		{
			sum += maix[i][j] ;
		}
	}
	return sum ;
}

int main()
{
	int maix[3][3];
	int maix2 [3][3] ;
	int sum[3][3] ;
	Generatematrix(maix);
	printmatrix(maix , 3 , 3 ) ;
	cout << "sum of atrix = " <<clasumofmatrix(maix ) ;
	return 0;
}