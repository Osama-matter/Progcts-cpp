#include<iostream>
using namespace std; 

bool ISlEEpYear(short &year)
{
	return (year % 4 == 0 && year % 100 != 0 || year % 400 == 0); 
}
short Checkmouth(short year , short mounth)
{
	int arry[] = { 1,3,5,7,8 , 10 , 12 };
	if (ISlEEpYear(year) && mounth == 2)
	{
		return 28;
	}

		
	for (int i = 0; i < 7; i++)
	{
		if (mounth == arry[i])
		{
			return 31;
		}

	}
	return 30; 
	
}
int ClaDay(short year  , short mounth)
{
 
	return Checkmouth(year , mounth);
}

int ClaHours(short year , short mounth)
{
	
	return  (ClaDay( year ,  mounth) *24);
	
}
int ClaMinuts(short year , short mounth)
{
	return (ClaHours(year ,mounth) * 60);
}
int ClaScounds( short year , short mounth)
{
	return (ClaMinuts(year , mounth) * 60);
}


void PrintResulat(short& year, short &mounth )
{

	
	cout << "Number of Day in mounth " << mounth << " is " << ClaDay(year , mounth) << endl;
	cout << "Number of Houer in  mounth " << mounth << " is " << ClaHours(year, mounth) << endl;
	cout << "Number of Minutes in  mounth " << mounth << " is " << ClaMinuts(year,mounth) << endl;
	cout << "Number Of Scounds in  mounth  " << mounth << " is " << ClaScounds(year,mounth) << endl;
	
}
short Getyear()
{
	short year = 0;
	cout << "Enter Year ? \n";
	cin >> year;
	return year;
}
short Getmounth()
{
	short mounth = 0;
	cout << "Enter  mounth ? \n";
	cin >> mounth;
	return mounth;
}
int main()
{
	short year = Getyear();
	short mounth = Getmounth();
	PrintResulat(year , mounth);
}