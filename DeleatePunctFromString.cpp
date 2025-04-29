
#include <string>
#include <iostream>
#include <vector>
using namespace std;


string JoinString(const vector <string >& text ,string dime  )
{
	string s1 = "";
	for (const string& word : text)
	{
		s1 =s1 +word + dime ;
	}
	return s1.substr(0, s1.length() - dime.length());
}
string JoinString(string arry[], int lengthofarry, string dime)
{
	string s2 = "";
	for (int i = 0;i < lengthofarry; i++)
	{
		s2 = s2 +arry[i] + dime; 
	}
	return s2.substr(0, s2.length() - dime.length());
}
int main()
{
	string  arry[] = {"osama" , "Ahmed" , "matter"};
	vector <string > text = {"osama" ,"Ahmed" , "Matter"};
	cout << "Join Arry by Vector . \n ";
	cout << JoinString(text ,",") <<endl ;
	cout << "Join Arry by arry .\n";
	cout << JoinString(arry, 3, "**");
	system("pause>0");
}
