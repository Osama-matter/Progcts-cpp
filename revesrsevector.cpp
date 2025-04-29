
#include <string>
#include <iostream>
#include <vector>
using namespace std;
string ReadString()
{
	string S1;
	cout << "Please Enter Your String?\n";
	getline(cin, S1);
	return S1;
}
void splitfanction(string S1, vector <string >& text, string dime)
{

	short pos = 0;
	string word;
	while ((pos = S1.find(dime)) != std::string::npos)
	{
		word = S1.substr(0, pos);
		if (word != dime)
		{
			text.push_back(word);

		}
		S1.erase(0, pos + dime.length());
	}
	if (S1 != "")
	{
		
		text.push_back(S1);
	}

}
string ReverseVector(vector <string >& text, string S2)
{
	for (int i = text.size()-1; i >= 0;i--)
	{
		S2 += text[i];
		if (i > 0)
			S2 += "";
	}
	return S2;
}
int main()
{

	string S2;
	vector <string > text; 
	string S1 = ReadString();
	splitfanction(S1, text, " ");
	cout << "After \n" << ReverseVector(text, S2) <<endl ;
}
