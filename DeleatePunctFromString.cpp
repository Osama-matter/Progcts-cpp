#include<iostream>
#include<string>
#include <cctype>
using namespace std;
string Getstring()
{
	string S1 = "";
	cout << "Enter String \n";
	getline(cin, S1);
	return S1;
}
void DeleatPancatewationmark(string &S1)
{
	for (int i = 0; i < S1.length();i++)
	{
		if (!ispunct(S1[i]))  // Dont use S1[i] != ispunt(S1[i] Becouse this fanction return true Or false Cant Compere this By String .
		{
			cout << S1[i];
		}
	}
}
int main()
{
	string S1 = Getstring();
	cout << "String Before Deleat Punct \n";
	DeleatPancatewationmark(S1);
	return 0;
}
