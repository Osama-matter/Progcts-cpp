#include <iostream>
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
	{
		return IsLeapYear(year) ? 29 : 28;
	}

	for (int i = 0; i < 7; i++)
	{
		if (month == arry[i])
		{
			return 31;
		}
	}

	return 30;
}
struct stData
{
	short year; 
	short month; 
	short day;
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
stData GetAllData()
{
	stData Data; 
	Data.year =  getYear();
	Data.month = getMonth();
	Data.day =  getDay();
	return Data; 
}

int claSumOfDayInYear(short year, short Month, short  Day)
{
	short sum = 0;
	for (int month = 1; month < Month; month++)
	{
		sum += CheckMonth(year, month);
	}
	sum += Day;
	return sum;
}
int claSumOfAllDay(short year, short Month, short  Day)
{
	long double sum = 0;
	for (int Year = 1; Year < year; Year++)
	{
		sum += NUmberofDAy(Year);
	}
	sum += claSumOfDayInYear(year, Month, Day); 

	return sum;
}
int ClaSubstration(stData Data1, stData Data2)
{
	int Substration = claSumOfAllDay(Data1.year, Data1.month, Data1.day) - claSumOfAllDay(Data2.year, Data2.month, Data2.day);

	return Substration; 
}
int main()
{
	stData Data1 = GetAllData(); 
	stData Data2 = GetAllData();
	cout << " \nDiffrent Betwen Tow Year  = " << ClaSubstration(Data1, Data2)-1 <<endl ;
	cout << "Diffrent Betwen Tow Year Plus Cuurant Day  = " << ClaSubstration(Data1, Data2)  << endl;
	
}
