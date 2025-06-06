#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <ctime>
using namespace std;

bool IsLeapYear(short year)
{
	return (year % 4 == 0 && year % 100 != 0 || year % 400 == 0);
}
int NUmberofDAy(short year)
{
	return IsLeapYear(year) ? 366 : 365;
}
short CheckMonth(short year, short month)
{
	int arry[] = { 1, 3, 5, 7, 8, 10, 12 };
	if (month == 2)
		return IsLeapYear(year) ? 29 : 28;

	for (int i = 0; i < 7; i++)
		if (month == arry[i])
			return 31;

	return 30;
}

struct sDate
{
	short Year;
	short Month;
	short Day;
};
short getYear()
{
	short year;
	cout << "Enter Year ? ";
	cin >> year;
	return year;
}
short getMonth()
{
	short Month;
	cout << "Enter Month ? ";
	cin >> Month;
	return Month;
}
short getDay()
{
	short Day;
	cout << "Enter Day ? ";
	cin >> Day;
	return Day;
}
sDate GetAllData()
{
	sDate Data;
	Data.Year = getYear();
	Data.Month = getMonth();
	Data.Day = getDay();
	return Data;
}
bool  checkValedationMonth(sDate Date)
{
	if (Date.Month > 12 || Date.Month ==0 )
	{
		return false;
	}
	else
	{
		return true; 
	}
}
bool CheckNumOFDayInMOnth(sDate Date)
{
	if (Date.Day > CheckMonth(Date.Year, Date.Month))
	{
		return false;
	}
	else
	{
		return true; 
	}
}
int main()
{
	sDate Date = GetAllData(); 
	cout << "\n---------------------------------------\n"; 
	if (checkValedationMonth(Date) == true && CheckNumOFDayInMOnth(Date) == true)
	{
		cout << "Valed Date . \n"; 
	}
	else
	{
		cout << "Un Valed Data .\n"; 
	}
}