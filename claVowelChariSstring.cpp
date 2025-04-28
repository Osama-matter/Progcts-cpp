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
bool checkcharifvowelornot(char c1)
{
    c1 = tolower(c1);
    return c1 == 'a' || c1 == 'e' || c1 == 'i' || c1 == 'o' || c1 == 'u';
}
void printresulats(string s1)
{
    int count = 0;

    for (int i = 0;i < s1.length(); i++)
    {
        s1[i] = tolower(s1[i]);
        if (s1[i] == 'a' || s1[i] == 'e' || s1[i] == 'i' || s1[i] == 'o' || s1[i] == 'u')
        {
            count++;
        }

    }
    cout << "number of vowel char in text  = " << count << endl;


}
int main()
{

    string s1 = Gettext();
    char c1;
    printresulats(s1);
    system("pause>0");
    return 0;
}
