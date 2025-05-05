#include<iostream>
using namespace std; 

bool ISlEEpYear(int &Year)
{
	return (Year % 4 == 0 && Year % 100 != 0 || Year % 400 == 0); 
}
int main()
{
	while (1 > 0)
	{
		int Year;
		cout << "Enter Year ? \n";
		cin >> Year;
		if (ISlEEpYear(Year))
		{
			cout << "Leep Year  \n";
		}
		else
		{
			cout << "Not leep Year \n";
		}
	}
	return 0;
}