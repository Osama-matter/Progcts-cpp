#include <iostream>
using namespace std;

static void GetDataFromUser(short& year, short& month, short& day)
{
    cout << "Enter Year? ";
    cin >> year;
    cout << "Enter Month? ";
    cin >> month;
    cout << "Enter Day? ";
    cin >> day;
}
int ClaDay(short year,short month, short day)
{
   
    
    int a = (14 - month) / 12;
    int y = year - a;
    int m = month + 12 * a - 2;

    int d = (day + y + y / 4 - y / 100 + y / 400 + (31 * m) / 12) % 7;
    return d; 
}
int main()
{
  
    string daysOfWeek[] = {  "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday","Saturday" };

    short year, month, day;
    GetDataFromUser(year, month, day);
    int d = ClaDay(year , month , day);

    cout << "Date :" << day << " /" << month << " /" << year << endl;
    cout << "Dat :" << d <<endl ; 
    cout << "Day you were born: " << daysOfWeek[d] << endl;
    

    return 0;
}
