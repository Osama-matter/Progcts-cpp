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
bool IFEndMonth(sDate Data1)
{
	short Dats = CheckMonth(Data1.Year, Data1.Month); 
	return (Dats == Data1.Day) ? true : false; 
}
bool IfEndYear(sDate Data1)
{
	return(Data1.Month == 12 && IFEndMonth(Data1)) ? true : false;
}
bool IsStartMonth(sDate Data1 )
{
	return (Data1.Day == 1) ? true : false; 
}
bool ISStartYear(sDate Data1)
{
	return(Data1.Day == 1 && Data1.Month == 1) ? true : false; 
}
sDate GetData( )
{
	sDate Data1;
	cout << "Enter Year ? ";
	cin >> Data1.Year; 
	cout << "Enter Month ? ";
	cin >> Data1.Month;
	cout << "Enter Day ? ";
	cin >> Data1.Day; 
	return Data1; 
}
void GeusertDatafrom(short& nDay, short& Week, short& nmonth, short& nyear, short& Decede, short& Cuntery)
{
	cout << "Enter number of days to Substract ? ";
	cin >> nDay; 
	cout << "Enter NUmber Of Week Do you Wont to Substract  ?";
	cin >> Week;
	cout << "Enter NUmber Of Month Do You Wont To Substract ?";
	cin >> nmonth;
	cout << "Enter NUmber Of Year Do you Wont to Substract  ?";
	cin >> nyear;
	cout << "Enter Number OF Decned Do you Wont to Substract ?";
	cin >> Decede;
	cout << "Enter Number OF Cunter Do you Wont to Substract ?";
	cin >> Cuntery;
}
sDate SubstractionOneDay(sDate Data1 )
{
	if (ISStartYear(Data1))
	{
		Data1.Year--;

		Data1.Month = 12;
		Data1.Day = 31; 
	}
	else if (IsStartMonth(Data1))
	{
		Data1.Month--;
		if (Data1.Month == 0)
		{
			Data1.Year--;
			Data1.Month = 12; 
		}

		Data1.Day = CheckMonth(Data1.Year, Data1.Month); 
	
	}
	else
	{
		Data1.Day--; 
	}
	return Data1; 
}
sDate SubstractionXDay(sDate Data1 ,short  nDAy )
{
	for (int i = 1; i <= nDAy;i++)
	{
		Data1 = SubstractionOneDay(Data1); 
	}
	return Data1; 
}
sDate SubstractWeek(sDate Data1)
{
	for (int i = 1;i <= 7; i++)
	{
		Data1 = SubstractionOneDay(Data1); 
	}
	return Data1; 
}
sDate SubstractXWeek(sDate Data1 ,short Week)
{
	for (int i = 1; i <= Week; i++)
	{
		Data1 = SubstractWeek(Data1); 
	}
	return Data1; 
}
sDate SubstrationOneMnonth(sDate Data1)
{
	if (Data1.Month == 1)
	{
		Data1.Year--; 
		Data1.Month = 12; 

	}
	else
	{
		Data1.Month--; 
	}
	short numMonth = CheckMonth(Data1.Year, Data1.Month); 
	if (numMonth < Data1.Day)
	{
		Data1.Day = numMonth; 
	}
	return Data1;  
}
sDate SubStrationXMonth(sDate Data1 , short nmonth)
{
	for (int i = 1; i <= nmonth; i++)
	{
		Data1 = SubstrationOneMnonth(Data1); 
	}
	return Data1; 
}
sDate SubstrationOneYear(sDate Data1 )
{
	for (int i = 1; i <= 12; i++)
	{
		Data1 = SubstrationOneMnonth(Data1); 
	}
	return Data1; 
}
sDate SubstrationXYear(sDate Data1 , short nyear)
{
	for (int i = 1; i <= nyear; i++)
	{
		Data1 = SubstrationOneYear(Data1); 
	}
	return Data1; 
}
sDate SubstrationONeDecede(sDate Data1 )
{
	for (int i = 1; i <= 10;  i++)
	{
		Data1 = SubstrationOneYear(Data1);
	}
	return Data1;
}
sDate SubstrationXDecede(sDate Data1, short& Decede)
{
	for (int i = 1; i <= Decede; i++)
	{
		Data1 = SubstrationONeDecede(Data1); 
	}
	return Data1; 
}
sDate SubstrationOneCuntery(sDate Data1)
{
	for (int i = 1;i <= 10; i++)
	{
		Data1 = SubstrationONeDecede(Data1); 
	}
	return Data1; 
}
sDate SubstrationXCuntery(sDate Data1  , short Cuntery)
{
	for (int i = 1; i <= Cuntery; i++)
	{
		Data1 = SubstrationOneCuntery(Data1); 
	}
	return Data1; 
}
sDate SubstrationOneMilion(sDate Data1)
{
	for (int i = 1; i <= 10;i++)
	{
		Data1 = SubstrationOneCuntery(Data1); 
	}
	return Data1;
}
int main()
{
	short nDay, Week, nmonth, nyear, Decede, Cuntery; 
	sDate Data1 = GetData();
	GeusertDatafrom(nDay, Week, nmonth, nyear, Decede, Cuntery); 
	Data1 = SubstractionOneDay(Data1); 
	cout << "Data After Substration One Day    :  " << Data1.Day << " / " << Data1.Month << " / " << Data1.Year <<endl; 
	Data1 = SubstractionXDay(Data1, nDay); 
	cout << "Data After Substration X Day      :  " << Data1.Day << " / " << Data1.Month << " / " << Data1.Year << endl;
	Data1 = SubstractWeek(Data1); 
	cout << "Data After Substration One Week   :  " << Data1.Day << " / " << Data1.Month << " / " << Data1.Year << endl;
	Data1 = SubstractXWeek(Data1, Week); 
	cout << "Data After Substration X Week     :  " << Data1.Day << " / " << Data1.Month << " / " << Data1.Year << endl;
	Data1 = SubstrationOneMnonth(Data1); 
	cout << "Data After Substration One Month  :  " << Data1.Day << " / " << Data1.Month << " / " << Data1.Year << endl;
	Data1 = SubStrationXMonth(Data1, nmonth); 
	cout << "Data After Substration X   Month  :  " << Data1.Day << " / " << Data1.Month << " / " << Data1.Year << endl;
	Data1 = SubstrationOneYear(Data1); 
	cout << "Data After Substration One Year   :  " << Data1.Day << " / " << Data1.Month << " / " << Data1.Year << endl;
	Data1 = SubstrationXYear(Data1, nyear); 
	cout << "Data After Substration  X  Year   :  " << Data1.Day << " / " << Data1.Month << " / " << Data1.Year << endl;
	Data1 = SubstrationONeDecede(Data1);
	cout << "Data After Substration One Deceted:  " << Data1.Day << " / " << Data1.Month << " / " << Data1.Year << endl;
	Data1 = SubstrationXDecede(Data1, Decede); 
	cout << "Data After Substration X  Deceted :  " << Data1.Day << " / " << Data1.Month << " / " << Data1.Year << endl;
	Data1 = SubstrationOneCuntery(Data1); 
	cout << "Data After Substration one Cuntery:  " << Data1.Day << " / " << Data1.Month << " / " << Data1.Year << endl;
	Data1 = SubstrationXCuntery(Data1, Cuntery); 
	cout << "Data After Substration X   Cuntery:  " << Data1.Day << " / " << Data1.Month << " / " << Data1.Year << endl;
	Data1 = SubstrationOneMilion(Data1); 
	cout << "Data After Substration One Milion :  " << Data1.Day << " / " << Data1.Month << " / " << Data1.Year << endl;


	return 0; 
	
}
