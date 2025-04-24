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
bool checkifmatrixequlivant(int maix[3][3] )
{
	int check = 0 ;
	for (int i = 0 ; i<3 ; i++)
	{
		for (int j=0 ;j<3 ; j++)
		{
			check = maix[0][0] ;
			if (i == j && maix[i][j] !=check) // if i == j meaing i = 1 j= 1 (1,1 ) this is must be = 1 but in this condation i retrn false if (i ,j) !=0
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
		cout << "matrix is  scalar \n " ;
	}
	else 
	{
		cout << "matrix is Not  scalar \n " ; 
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
	int maix[3][3] =
	{
		{9, 0, 0},
		{0, 9, 0},
		{0, 0, 9}
	};
	

	printmatrix(maix);
	printresulats(maix ) ;
	return 0;
}
