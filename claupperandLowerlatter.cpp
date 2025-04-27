#include <iostream>
#include<string>
using namespace std;
char Getchar()
{
    char  s1 = ' ';
    cout << "Enter Char  ? \n";
    cin >> s1;
    return s1;

}
void detremanchar(char s1)
{
    if (s1 <= 122 && s1 >= 97)
    {
        s1 = toupper(s1);

        cout << s1 <<endl ;
    }
    else if (s1 <= 90 && s1 >= 65)
    {
        s1 = tolower(s1);
        cout << s1 << endl;
    }
    else
    {
        cout << "Not char  \n"; 
    }
}
char inversecharbyisupper(char s1)
{
    return isupper(s1) ? tolower(s1) : toupper(s1);
}
int main()
{
    char s1 = Getchar();
    cout << "inverse number in Assmole code  \n";
    detremanchar(s1);
    cout << "inverse By to () \n";
    cout << inversecharbyisupper(s1);

    return 0;
}
// to convert char to upper char - 32 
// (32)  number to upper case + lower case ; 
