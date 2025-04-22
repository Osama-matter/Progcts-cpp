#include <iostream>
#include <string>
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
int sumrowelements(int maix[3][3],   int rownumber , int row)
{
	int sumr1 = 0;                                                   // use for loop to sum element in row ; 
	for (int j = 0; j < row;j++)
	{
		sumr1 += maix[rownumber][j];
	}
	return sumr1; 

}
void printsumofrowelements(int maix[3][3] , int row , int clo  )
{
	cout << "sum of element in row .\n\n";
	for (int j = 0; j < row;j++)
	{
		cout << "Sum elemntes in row [" << j + 1 << "] =" << sumrowelements(maix   , j , clo) << endl;
		//sumr1 = 0;

	}
}
int main()
{
	srand(time(0));
	cout << "Elemntes in row\n";
	int row =3, clo=3 , sumr1;
	int maix[3][3];
	Generatematrix(3,3,maix);
	printmatrix(maix,3 , 3 );
	printsumofrowelements(maix,row ,clo);
	return 0;
}



//nestid for loop to full array ; 
//nested for loop to print full array ; 
//nested for loop to cla sum of elemants in row  ; 