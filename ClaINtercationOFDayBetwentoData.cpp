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

bool  CheckIfData1AfterData2(sDate Data1, sDate Data2)
{
	return (Data1.Year > Data2.Year) ? true : (Data1.Month > Data2.Month) ? true : (Data1.Day > Data2.Day) ? true : false; 
}
bool IsDataBefore(sDate Data1, sDate Data2)
{
	return ((Data1.Year < Data2.Year) ? true : (Data1.Year == Data2.Year) ? (Data1.Month < Data2.Month) ? true : ((Data1.Month == Data2.Month) ? ((Data1.Day < Data2.Day) ? true : false) : false) : false);

}
bool CheckIFYearEqual (sDate Data1, sDate Data2)

{
	return (Data1.Year == Data2.Year && (Data1.Month == Data2.Month) && (Data1.Day == Data2.Day)) ? true : false;
}
bool CheckOverlapData(sDate Data1Start, sDate Data1End, sDate Data2Start, sDate Data2End)
{
	if ((IsDataBefore(Data1End, Data2Start) == true) || (IsDataBefore(Data2End , Data1Start)))
	{
		return false;
	}
	else
	{
		return true ;

	}
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
	return (Data1.Day == CheckMonth(Data1.Year, Data1.Month)) ? true : false;
}
int  ClaNUmberOFPeriodData(sDate Data1Start, sDate Data1End, sDate Data2Start, sDate Data2End)
{
	int count = 0; 
	while (IsDataBefore(Data1Start, Data2End))
	{
		while (CheckIFYearEqual(Data1Start, Data2Start))
		{
			while (IsDataBefore(Data1Start, Data1End))
			{
				count++; 
				short MonthDay = CheckMonth(Data1Start.Year, Data1Start.Month);
				if (Data1Start.Day < MonthDay)
				{
					Data1Start.Day++;
				}
				else
				{
					if (IfEndYear(Data1Start))
					{
						Data1Start.Month = 1;
						Data1Start.Year++;
						Data1Start.Day = 1;
					}
					if (IFEndMonth(Data1Start))
					{
						Data1Start.Month++;
						Data1Start.Day = 1;
					}
				}
			}
			break; 
		}
		short MonthDay = CheckMonth(Data1Start.Year, Data1Start.Month);
		if (Data1Start.Day < MonthDay)
		{
			Data1Start.Day++;
		}
		else
		{
			if (IfEndYear(Data1Start))
			{
				Data1Start.Month = 1;
				Data1Start.Year++;
				Data1Start.Day = 1;
			}
			if (IFEndMonth(Data1Start))
			{
				Data1Start.Month++;
				Data1Start.Day = 1;
			}
		}

	}
	return count; 
}
int main()
{
	sDate Data1Start = GetAllData();
	cout << "\nEnter End Period ?\n";
	sDate Data1End = GetAllData(); 
	cout << "\n ------------------------------------------------- \n";
	sDate Data2Start = GetAllData(); 
	cout << "\nEnter End Period ?\n";
	sDate Data2End = GetAllData(); 
	cout << "\n ------------------------------------------------- \n";
	if (CheckOverlapData(Data1Start , Data1End , Data2Start , Data2End) == true ) 
	{
		cout << " \nyes , Period overLop " << endl;

	}

	else
	{
		cout << "\nNo , Period Overlop . \n";
	}
	int count  = ClaNUmberOFPeriodData(Data1Start, Data1End, Data2Start, Data2End); 

	cout << "\n NUmber Of intersation Of Tow Data = " << count <<endl ; 
}
// whille 2  Satr one Bugger than end one  . 
// if (Data start DAta2  Arfet end Data1 tow ) return true  .  