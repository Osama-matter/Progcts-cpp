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
int clasumofmatrix2(int maix[3][3])
{
	int sum2 = 0 ; 
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0;j < 3;j++)
		{
			sum2 += maix[i][j] ;
		}
	}
	return sum2 ;
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

void printresulats(int maix [3][3] , int maix2[3][3] )
{
	if (clasumofmatrix2(maix ) == clasumofmatrix2(maix2))
	{
		cout << "matrix are equal \n " ;
	}
	else 
	{
		cout << "matrix are Not equal \n " ; 
	}
}

int main()
{
	srand(time(0));
	int maix[3][3];
	int maix2 [3][3] ;
	int sum[3][3] ;
	Generatematrix(maix);
	Generatematrix(maix2) ;
	cout << "\n maitrix one \n" ;
	printmatrix(maix , 3 , 3 ) ;
	cout << "\n maitrix tow \n" ;
	printmatrix(maix2 , 3 , 3) ;
	cout << "sum of matrix one = " <<clasumofmatrix2(maix ) <<endl ;
	cout << "sum of matrix tow = " <<clasumofmatrix2(maix2 ) <<endl ;
	printresulats(maix  , maix2 );
	return 0;
}
