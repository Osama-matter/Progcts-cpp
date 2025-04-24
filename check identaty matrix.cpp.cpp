// cheak identaty matrix  . 
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
			maix[i][j] =randowmnumber(0,1);
		}
	}
}
bool checkifmatrixequlivant(int maix[3][3] )
{
	for (int i = 0 ; i<3 ; i++)
	{
		for (int j=0 ;j<3 ; j++)
		{
			if (i == j && maix[i][j] != 1) // if i == j meaing i = 1 j= 1 (1,1 ) this is must be = 1 but in this condation i retrn false if (i ,j) !=0
			{
				return false ;
			}
			else if (i!=j && maix[i][j] !=0 ) 
			{
				return false ;  
			}
		}
	}
	return true ;
}
void printresulats(int maix [3][3]  )
{
	if (checkifmatrixequlivant(maix))
	{
		cout << "matrix are identaty \n " ;
	}
	else 
	{
		cout << "matrix are Not identaty \n " ; 
	}
}
void printmatrix(int maix[3][3])
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0;j < 3;j++)
		{
			printf("%d  ", maix[i][j]);
		}
		cout << endl;
	}
	
}
int main()
{
	srand(time(0));
	int maix[3][3];
	Generatematrix(maix);
	printmatrix(maix);
	printresulats(maix ) ;
	return 0;
}