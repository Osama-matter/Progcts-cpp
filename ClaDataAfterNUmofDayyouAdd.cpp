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
int ClaDay(short year, short month, short day)
{
	int a = (14 - month) / 12;
	int y = year - a;
	int m = month + 12 * a - 2;

	int d = (day + y + y / 4 - y / 100 + y / 400 + (31 * m) / 12) % 7;
	return d;
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

void GetData(short& year, short& Month, short& Day  , int &Add)
{

	cout << "Enter Year ? ";
	cin >> year;
	cout << "Enter Month ? ";
	cin >> Month;
	cout << "Enter Day ? ";
	cin >> Day;
	cout << "Enter NUmber of Day to you wont to Add ? ";
	cin >> Add;
}
int claSumOfDay(short year, short Month, short  Day)
{
	short sum = 0;
	for (int month = 1; month < Month; month++)
	{
		sum += CheckMonth(year, month);
	}
	sum += Day;
	return sum;
}
struct sData
{
	short Year;
	short Day;
	short Month;
};
sData convertToData(short year, short Month, short  Day)
{

	sData Data;
	short Sum = claSumOfDay(year, Month, Day);
	short numofDayinMonth = 0;
	Data.Year = year;
	Data.Month = 1;
	while (true)
	{
		numofDayinMonth = CheckMonth(year, Data.Month);
		if (Sum > numofDayinMonth)
		{
			Sum -= numofDayinMonth;
			Data.Month++;
		}
		else
		{
			Data.Day = Sum;
			break;
		}
	}
	return Data;
}
sData AddDaysToDate(short year, short Month, short Day, int Add)
{
	sData Data;
	Data.Year = year;
	Data.Month = Month;
	Data.Day = Day;
	short Benigiing = 0 ; 
	short MonthDay = ClaDay(year, Month, Day) + Add;
	while (true)
	{
		Benigiing = CheckMonth(year, Data.Month);

		if (MonthDay > Benigiing)
		{
			MonthDay -= Benigiing;
			Data.Month++;
			if (Data.Month > 12)
			{
				Data.Year++;
				Data.Month = 1;
			}
		}
		else
		{
			Data.Day = Benigiing; 
			break; 
		}
	}

	return Data;
}
int main()
{
	sData Data;
	short year, Month, Day;
	int Add; 

	GetData(year, Month, Day, Add);
	cout << Day << " / " << Month << " / " << year << endl;
	short  Begining = claSumOfDay(year, Month, Day);
	cout << "Number OF Day Is Begining in Year = " << Begining << endl;

	Data = convertToData(year, Month, Day);
	cout << Data.Day << " / " << Data.Month << " / " << Data.Year << endl;
	Data = AddDaysToDate(year, Month, Day, Add);
	cout << Data.Day << " / " << Data.Month << " / " << Data.Year << endl;
	
}