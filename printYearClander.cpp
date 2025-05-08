#include <iostream>
#include <iomanip>
using namespace std;

bool IsLeapYear(short year)
{
    return (year % 4 == 0 && year % 100 != 0 || year % 400 == 0);
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

int ClaDay(short year, short month, short day)
{
    int a = (14 - month) / 12;
    int y = year - a;
    int m = month + 12 * a - 2;

    int d = (day + y + y / 4 - y / 100 + y / 400 + (31 * m) / 12) % 7;
    return d;
}

static void GetDataFromUser(short& year)
{
    cout << "Enter Year? ";
    cin >> year;
}

void StartCalendar()
{
    string daysOfWeek[] = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday","Saturday" };
    string months[] = { "", "January", "February", "March", "April", "May", "June",
                        "July", "August", "September", "October", "November", "December" };

    short year;
    GetDataFromUser(year);

    for (short month = 1; month <= 12; month++)
    {
        short numDays = CheckMonth(year, month);
        short firstDay = ClaDay(year, month, 1);

        cout << "\n\n----------------------------- " << months[month] << " " << year << " -----------------------------\n\n";

        for (int i = 0; i < 7; i++)
        {
            cout << setw(10) << daysOfWeek[i];
        }
        cout << endl;

        for (int space = 0; space < firstDay; space++)
        {
            cout << setw(10) << " ";
        }

        for (int day = 1; day <= numDays; day++)
        {
            cout << setw(10) << day;
            if ((day + firstDay) % 7 == 0)
                cout << endl;
        }

        cout << "\n";
    }
}

int main()
{
    StartCalendar();
    return 0;
}
