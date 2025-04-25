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
	int max = 0 ;
	max = maix[0][0] ; 
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0;j < 3;j++)
		{
			if (maix[i][j] >max)
			{
				max = maix[i][j] ;
				
			}

		}
	}
	return max ;
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
int main()
{
	srand(time(0));
	int maix[3][3];
	int maix2 [3][3] ;
	int sum[3][3] ;
	Generatematrix(maix);

	cout << "\n maitrix one \n" ;
	printmatrix(maix , 3 , 3 ) ;

	cout << "big number in matrix (1) = " <<clasumofmatrix2(maix ) <<endl ;

	
	return 0;
}
