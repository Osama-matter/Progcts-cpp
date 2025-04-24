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
			maix[i][j] =randomnumber(0, 9);
		}
	}
}
void printmatrix(int maix[3][3], int clo , int row   )
{
	
	for (int i = 0; i < clo; i++)
	{
		for (int j = 0;j < row;j++)
		{
			printf("%d  ", maix[i][j]);
		}
		cout << endl;
	}
	cout << "------------------------\n\n";
}
void  clasumofmatrix(int maix[3][3] , int &zero , int &number )
{

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0;j < 3;j++)
		{
			if (maix[i][j] ==0)
			{
				zero ++ ;
			}
			else
			{
				number++ ;
			}
		}
	}

}
void printresulats(int number  , int zero)
{
	if (zero > number)
	{
		cout << "matrix is Sparse . \n" ;
	}
	else
	{
		cout << "matrix is Not sparse .\n" ;
	}
}

int main()
{
	int maix[3][3];
	int number =0 , zero =0  ;
	Generatematrix(maix);
	printmatrix(maix , 3 , 3 ) ;
	clasumofmatrix(maix , zero ,number );  ;
	printresulats(number , zero) ;
	return 0;
}
