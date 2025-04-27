#include <iostream>
#include<string>
using namespace std;
string Getname()
{
    string s1 = " ";
    cout << "Enter youer name ? \n\n";
    getline(cin, s1);
    return s1;

}
void uppercharbyme(string& s1)
{
    char c1 = ' ';
    cout << "\tUppper fanction By me  . \n\n";
    for (int i = 0;i < s1.length();i++)
    {
        if (s1[i] != ' ' && s1[i] <= 122 && s1[i] >= 97)
        {
            c1 = s1[i] - 32;
            cout << c1;

        }
        else
        {
            cout << s1[i];
        }

    }

}
void uppercharbycomputer(string s1)
{
    cout << "\n\tto upper by using computer \n\n";
    for (int i = 0;i < s1.length();i++)
    {
        s1[i] = toupper(s1[i]);
        cout << s1[i];
    }

    cout << endl;
}
void lowercharbyme(string& s1)
{
    char c1 = ' ';
    cout << "\tlower fanction By me  . \n\n";
    for (int i = 0;i < s1.length();i++)
    {
        if (s1[i] != ' ' && s1[i] <= 90 && s1[i] >= 65)
        {
            c1 = s1[i] + 32;
            cout << c1;

        }
        else
        {
            cout << s1[i];
        }

    }

}
void lowercharbycomputer(string s1)
{
    cout << "\n\tto lower by using computer \n\n ";
    for (int i = 0;i < s1.length();i++)
    {
        s1[i] = tolower(s1[i]);
        cout << s1[i];
    }
    cout << endl;
}
int main()
{

    string s1 = Getname();
    uppercharbyme(s1);
    uppercharbycomputer(s1);
    lowercharbyme(s1);
    lowercharbycomputer(s1);

    return 0;
}
// to convert char to upper char - 32 
// (32)  number to upper case + lower case ; 
