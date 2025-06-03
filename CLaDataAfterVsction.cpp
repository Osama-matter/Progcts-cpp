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
bool IFEndMonth(sDate Data1)
{
	short Dats = CheckMonth(Data1.Year, Data1.Month);
	return (Dats == Data1.Day) ? true : false;
}
bool IfEndYear(sDate Data1)
{
	return(Data1.Month == 12 && IFEndMonth(Data1)) ? true : false;
}
bool IsENdMonth(sDate Data1)
{
	return (Data1.Day ==CheckMonth(Data1.Year ,Data1.Month)) ? true : false;
}
bool ISStartYear(sDate Data1)
{
	return(Data1.Day == 1 && Data1.Month == 1) ? true : false;
}

enum eDays { Saturday = 0, Sunday, Monday, Tuesday, Wednesday, Thursday, Friday };
string eDays[] = { "Saturday"  , "Sunday", "Monday", "Tuesday"," Wednesday", "Thursday", "Friday" };
tm ConvertToTm(sDate Data1)
{
	tm timeStruct = {};
	timeStruct.tm_year = Data1.Year - 1900;
	timeStruct.tm_mon = Data1.Month - 1;
	timeStruct.tm_mday = Data1.Day;
	mktime(&timeStruct);
	return timeStruct;
}

int  CheckDay(sDate Data1)
{
	tm data = ConvertToTm(Data1);
	int adjustedDay = (data.tm_wday + 1) % 7;

	return adjustedDay;
}
void PrintDayName(sDate Data1)
{
	cout << "Day " << eDays[CheckDay(Data1)] << endl << endl;
}

bool   ISEndWeek(sDate Data1)
{
	if (CheckDay(Data1) == Friday)
	{
		return true; 
	}
	else
	{
		return false; 
	}
}
bool  IsWeekEnd(sDate Data1)
{
	if (CheckDay(Data1) == Friday)
	{
		return true;
	}
	else
	{
		return false; 
	}
}
bool  isBussniceDay(sDate Data1)
{
	if (CheckDay(Data1) != Friday && CheckDay(Data1) != Saturday)
	{
		return true; 

	}
	else
	{
		return false; 
	}
}
int GetVactiomData()
{
	int Vacatiom = 0; 
	cout << "Enter Vactiom Data \n"; 
	cin >> Vacatiom; 
	return Vacatiom; 
}
sDate ClaDataAfterVactionData(sDate Data1)
{
	int Day = GetVactiomData(); 
	
	for (int i = 1; i <= Day; i++)
	{
		short MonthDay = CheckMonth(Data1.Year, Data1.Month);
		if (Data1.Day < MonthDay)
		{
			Data1.Day++;
		}
		else
		{
			if (IfEndYear(Data1))
			{
				Data1.Month = 1;
				Data1.Year++;
				Data1.Day = 1;
			}
			if (IFEndMonth(Data1))
			{
				Data1.Month++;
				Data1.Day = 1;
			}


		}
; 
	}
	return Data1; 
}
int main()
{
	sDate Data1;
	Data1 = GetAllData();
	Data1 = ClaDataAfterVactionData(Data1);
	cout << "\n Data After Add Vacation\n";
	cout << Data1.Day << " / " << Data1.Month << " / " << Data1.Year << endl;
}