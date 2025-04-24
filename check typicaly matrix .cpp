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
			maix[i][j] =randowmnumber(1, 9);
		}
	}
}
void Generatematrix2(int maix2[3][3])
{
	for (int i = 0;i < 3; i++)
	{
		for (int j = 0;j < 3;j++)
		{
			maix2[i][j] =randowmnumber(1, 9);
		}
	}
}
bool checkifmatrixequlivant(int maix[3][3] , int maix2[3][3])
{
	for (int i = 0 ; i<3 ; i++)
	{
		for (int j=0 ;j<3 ; j++)
		{
			if (maix[i][j] == maix2[i][j])
			{
				return true ;
			}
			else 
			{
				return false ;  
			}
		}
	}
}
void printresulats(int maix [3][3] , int maix2[3][3] )
{
	if (checkifmatrixequlivant(maix , maix2))
	{
		cout << "matrix are equal \n " ;
	}
	else 
	{
		cout << "matrix are Not equal \n " ; 
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
	int maix2[3][3];
	Generatematrix(maix);
	Generatematrix2(maix2);
	printmatrix(maix);
	cout <<"\n matrix tow \n" ; 
	printmatrix(maix2);
	printresulats(maix , maix2) ;
	return 0;
}
