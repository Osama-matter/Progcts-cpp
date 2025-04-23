#include <iostream>
#include <cstdlib>
#include<stdio.h>
#include <ctime> 
using namespace std;
int randomnumber(int from, int to) 
{
	int randoim = rand() % (to - from + 1) + from;
	return randoim;
}
void Generatematrix( int clo , int row,int maix[3][3] )
{
	int x = 1 ; 

	for (int i = 0;i < clo; i++)
	{
		for (int j = 0;j < row;j++)
		{
			maix[i][j] = x ; // full arry by genarac number . 
			x++ ;
			
			
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
void printmatrix2(int maix[3][3], int clo , int row   )
{
	
	for (int i = 0; i < clo; i++)
	{
		for (int j = 0;j < row;j++)
		{
			printf("%*0d  ", 2, maix[j][i]);
		}
		cout << endl;
	}
	cout << "------------------------\n\n";
}
int main()
{
	srand(time(0));
	cout << "Elemntes in colum\n";
	int row =3, clo=3 , sumr1;
	int maix[3][3];
	Generatematrix(3,3,maix);
	printmatrix(maix,3 , 3 );
	printmatrix2(maix , 3 , 3) ;
	//printsumofrowelements(maix,row ,clo);
	return 0;
}



//nestid for loop to full array ; 
//nested for loop to print full array ; 
//nested for loop to cla sum of elemants in row  ; 