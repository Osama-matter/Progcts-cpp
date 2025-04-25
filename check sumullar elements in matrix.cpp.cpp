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
bool checkelementsfond(int maix[3][3] ,int maix2[3][3] ,int number )
{
	int sum = 0 ; 
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0;j < 3;j++)
		{
	
			if (number == maix2[i][j])
			{
				return true  ;
			}
		}
	}
	return false ;
}
void printresulats(int maix[3][3],int maix2[3][3], int &number )
{
	cout << "Common elements in both matrices:\n";
	for (int i = 0 ; i<3 ;i++)
	{
		for (int j = 0 ; j <3 ; j++)
		{
			number = maix[i][j] ;
			if (checkelementsfond(maix,maix2,number))
			{
				cout << number <<"   " ;
			}

		}

	}

}
int main()
{
	srand(time(0));
	int maix[3][3];
	int maix2[3][3] ;
	int number = 0 ;
	Generatematrix(maix);
	Generatematrix(maix2) ;
	printmatrix(maix , 3 , 3 ) ;
	printmatrix(maix2 , 3 , 3 ) ;
	printresulats(maix  , maix2,number) ;
	return 0;
}
