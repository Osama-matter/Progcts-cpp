#include <iostream>
#include<string>
using namespace std;
string Gettext()
{
    string  s1 = " ";
    cout << "Enter text  ? \n";
    getline(cin, s1);
    return s1;

}
char Getchar()
{
    char  c1 = ' ';
    cout << "Enter char  ? \n";
    cin >> c1;
    c1 = tolower(c1);
    return c1;

}
void sumnumberodlower(string s1)
{
    cout << "length of String =  " << s1.length() <<endl ;
}
void clanumberofcapitallatterorSmall(string s1, char c1)
{
    int count2 = 0;
    for (int i = 0; i < s1.length(); i++)
    {
      
        if (s1[i] == c1)
        {
            count2++;
        }
    }
    cout << "char '" << c1 << "' Count = " << count2 << endl ; 
}
void clanumberofcharintext(string s1, char c1)
{
    int count = 0;
    for (int i = 0; i < s1.length(); i++)
    {
        s1[i] = tolower(s1[i]);
        if (s1[i] == c1)
        {
            count++;
        }
    }
    char c1C = toupper(c1);
    cout << "char '" << c1 << "' OR ' " <<  c1C << "' Count = " << count;
}
int main()
{
    string s1 = Gettext();
    char c1 = Getchar();
    sumnumberodlower(s1);
    clanumberofcapitallatterorSmall(s1 , c1);
    clanumberofcharintext(s1, c1);
    system("pause>0");
    return 0;
}
