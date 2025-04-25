#include <iostream>
#include <string>
#include<stdio.h>
using namespace std;
int randomnumber(int from, int to)
{
	int randoim = rand() % (to - from + 1) + from;
	return randoim;
}
void Getnumber (int &number )
{
	 
	do
	{
		cout << "Enter the number do you wont to check in matrix ? " ; 
		cin >>number ;
	} while (number <0); 
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
int clasumofmatrix(int maix[3][3] , int number )
{
	int sum = 0 ; 
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0;j < 3;j++)
		{
			if (number == maix[i][j])
			{
				return true  ;
			}
			else
			{
				return false ;
			}
		}
	}
}
void printresulats(int maix[3][3], int number )
{
	if (clasumofmatrix(maix,number))
	{
		cout << "Number is found in marix .\n" ;
	}
	else
	{
		cout <<"number not found in matrix .\n" ;
	}
}
int main()
{
	int maix[3][3];
	int number = 0 ;
	Generatematrix(maix);
	printmatrix(maix , 3 , 3 ) ;
	Getnumber(number) ;
	clasumofmatrix(maix , number) ;
	printresulats(maix  , number) ;
	return 0;
}