
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
string lowercharbycomputer(string s1)
{
	for (int i = 0;i < s1.length();i++)
	{
		s1[i] = tolower(s1[i]);

	}
	return s1;
}
void splitfanction(string S1, vector <string >& text, string dime)
{
	int token = 0;
	;
	short pos = 0;
	string word;
	while ((pos = S1.find(dime)) != std::string::npos)
	{
		token++;
		word = S1.substr(0, pos);
		if (word != dime)
		{
			text.push_back(word);

		}
		S1.erase(0, pos + dime.length());
	}
	if (S1 != "")
	{
		token++;
		text.push_back(S1);
	}
}
void Replasefanction( vector <string >& text ,const string &toReplase ,const string &Replaseword)
{
	for (string &word : text)
	{
		if (word == toReplase)
		{
			word = Replaseword;
		}
		else if (lowercharbycomputer(word) == lowercharbycomputer(toReplase))
		{
			word = Replaseword;
		}
		
	}
}
void printresulats(const vector<string> &text)
{
	for (string word : text)
	{
		cout << word << " ";
	}
}
int main()
{
	string S1 = ReadString();
	vector <string > text;
	string toReplase = "osama";
	string Replaseword = "os";
	cout << "String Before Replase . \n" << S1 << endl;
	cout << "String After Reblase . \n";
	splitfanction(S1, text, " ");
	Replasefanction(text, toReplase, Replaseword);
	printresulats(text);
	system("pause>0");
}
