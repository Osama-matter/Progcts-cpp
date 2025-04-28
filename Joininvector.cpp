#include<iostream>
#include <string>
using namespace std;
string DeleatliftSpace(string s1)
{
	for (int i = 0; i < s1.length(); i++)
	{
		if (s1[i] != ' ')
		{
			return s1.substr(i, s1.length()-i);
		}
	}
	return "";
}
string DeleatrightSpace(string s1)
{
	for (int i =s1.length(); i >0 ; i--)
	{
		if (s1[i] != ' ')
		{
			return s1.substr(0 , i+1);
		}
	}
	return "";
}
string DeleateAllspase(string s1)
{
	return DeleatliftSpace(DeleatrightSpace(s1));
}
int main()
{
	string s1 = "        osama Ahmed Matter    ";
	cout << "String : " << s1 << endl;
	cout << "Deleated left term : " << DeleatliftSpace(s1) <<endl ;
	cout << "Deleated right term :" << DeleatrightSpace(s1) << endl;
	cout << "Deleated all spase :" << DeleateAllspase(s1) << endl;

}