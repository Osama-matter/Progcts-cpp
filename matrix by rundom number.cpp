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
void Generatematrix2(int maix2[3][3])
{
	for (int i = 0;i < 3; i++)
	{
		for (int j = 0;j < 3;j++)
		{
			maix2[i][j] =randomnumber(1, 9);
		}
	}
}
void  clamiltibicataoftowmatrix( int sum[3][3] ,int maix[3][3] , int maix2[3][3] ) 
{
	
	for (int i = 0 ; i<3 ; i++)
	{
		for (int j=0 ; j<3 ;j++)
		{
			sum[i][j] =maix[i][j] * maix2[i][j] ;
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
void printmltibicatematrix(int sum[3][3])
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0;j < 3;j++)
		{
			printf("%*0d  ", 2, sum[i][j]);
		}
		cout << endl;
	}
	cout <<endl <<endl ;
}
int main()
{
	int maix[3][3];
	int maix2 [3][3] ;
	int sum[3][3] ;
	Generatematrix(maix);
	Generatematrix2(maix2) ;
	cout << "\nmatrix one \n\n" ;
	printmatrix(maix);
	cout << "\nmatrix tow \n\n" ;
	printmatrix(maix2) ;
	clamiltibicataoftowmatrix(sum , maix , maix2) ;
	cout << "\nmaltibicatematrx \n\n" ;
	printmltibicatematrix(sum) ;	
	return 0;
}