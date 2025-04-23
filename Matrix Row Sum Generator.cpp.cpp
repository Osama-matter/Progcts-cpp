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

	for (int i = 0;i < clo; i++)
	{
		for (int j = 0;j < row;j++)
		{
			maix[i][j] = randomnumber(1, 99);
			
			
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
void printmidelrowinmatrix(int maix[3][3], int clo , int row   )
{
	
	
	short middelrow = clo/2 ;
	for (int j = 0;j < row;j++)
	{
		printf("%*0d  ", 2, maix[1][j]);
	}
	cout << endl;
	
	cout << "------------------------\n\n";
}
void printmidelcolumninmatrix(int maix[3][3], int clo , int row   )
{
	int middelrow = row/2 ;
 	for (int i = 0; i < clo; i++)
	{
		printf("%*0d  ", 2, maix[i][1]);
		
	}
	cout << endl;
	cout << "------------------------\n\n";
}
int main()
{
	srand(time(0));
	cout << "Elemntes in row\n";
	int row =3, clo=3 , sumr1;
	int maix[3][3];
	Generatematrix(3,3,maix);
	printmatrix(maix,3 , 3 );
	cout << "\n \t MIddel Row\n" ;
	printmidelrowinmatrix(maix , 3 , 3) ;
	cout << "\n \t MIddel Column\n" ;
	printmidelcolumninmatrix(maix , 3 , 3) ;
	return 0;
}



//nestid for loop to full array ; 
//nested for loop to print full array ; 
//nested for loop to cla sum of elemants in row  ; 